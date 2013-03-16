/*	SCCS Id: @(#)vmsmail.c	3.4	1995/06/01	*/
/* Copyright (c) Robert Patrick Rankin, 1991.			  */
/* NetHack may be freely redistributed.  See license for details. */

#include "config.h"
#include "mail.h"

/* lint supression due to lack of extern.h */
unsigned long NDECL(init_broadcast_trapping);
unsigned long NDECL(enable_broadcast_trapping);
unsigned long NDECL(disable_broadcast_trapping);
struct mail_info *NDECL(parse_next_broadcast);

#ifdef MAIL
#include "wintype.h"
#include "winprocs.h"
#include <ctype.h>
#include <descrip.h>
#include <errno.h>
# ifndef __GNUC__
#include <msgdef.h>
# else
#  define MSG$_TRMHANGUP  6
#  define MSG$_TRMBRDCST 83
# endif /*__GNUC__*/
#include <signal.h>
/* #include <string.h> */
# define vms_ok(sts) ((sts)&1)

static struct mail_info *FDECL(parse_brdcst, (char *));
static void FDECL(filter_brdcst, (char *));
static void NDECL(flush_broadcasts);
static void FDECL(broadcast_ast, (int));
extern char *FDECL(eos, (char *));
extern char *FDECL(strstri, (const char *,const char *));
extern int FDECL(strncmpi, (const char *,const char *,int));

extern size_t FDECL(strspn, (const char *,const char *));
#ifndef __DECC
extern int VDECL(sscanf, (const char *,const char *,...));
#endif
extern unsigned long
	smg$create_pasteboard(),
	smg$get_broadcast_message(),
	smg$set_broadcast_trapping(),
	smg$disable_broadcast_trapping();

extern volatile int broadcasts;		/* defining declaration in mail.c */

static long pasteboard_id = 0;		/* SMG's magic cookie */

/*
 * Mail (et al) overview:
 *
 *	When a broadcast is asynchronously captured, a volatile counter
 * ('broadcasts') is incremented.  Each player turn, ckmailstatus() polls
 * the counter and calls parse_next_broadcast() if it's positive; this
 * returns some display text, object name, and response command, which is
 * passed to newmail().  Routine newmail() generates a mail-daemon monster
 * who approaches the character, "speaks" the display text, and delivers
 * a scroll of mail pre-named to the object name; the response command is
 * initially appended to the name, so that the object is tagged with both
 * of them; a NUL is inserted to terminate the ordinary name and hide the
 * command.  (If the player renames such a scroll, the hidden command will
 * be lost; who cares?)  Unrecognized broadcasts result in the mail-daemon
 * arriving and announcing the display text, but no scroll being created.
 * If SHELL is undefined, then all broadcasts are treated as 'other'; since
 * no subproceses are allowed, there'd be no way to respond to the scroll.
 *
 *	When a scroll of mail is read by the character, readmail() extracts
 * the hidden command string and uses it for the default when prompting the
 * player for a system command to spawn.  The player may enter any command
 * he or she chooses, or just <return> to accept the default or <escape> to
 * avoid executing any command.  If the command is "SPAWN", a regular shell
 * escape to DCL is performed; otherwise, the indicated single command is
 * spawned.  Either way, NetHack resumes play when the subprocess terminates
 * or explicitly reattaches to its parent.
 *
 * Broadcast parsing:
 *
 *	The following broadcast messages are [attempted to be] recognized:
 *    text fragment	      name for scroll	      default command
 *	New mail		VMSmail			MAIL
 *	New ALL-IN-1 MAIL	A1mail			A1M
 *	Software Tools mail	STmail			MSG [+folder]
 *	MM mail			MMmail			MM
 *	WPmail: New mail	WPmail			OFFICE/MAIL
 *	**M400 mail		M400mail		M400
 *	" mail", ^"mail "	unknown mail		SPAWN
 *	" phoning"		Phone call		PHONE ANSWER
 *	talk-daemon...by...foo	Talk request		TALK[/OLD] foo@bar
 *	(node)user -		Bitnet noise		XYZZY user@node
 * Anything else results in just the message text being passed along, no
 * scroll of mail so consequently no command to execute when scroll read.
 * The user can set up ``$ XYZZY :== SEND'' prior to invoking NetHack if
 * vanilla JNET responses to Bitnet messages are prefered.
 *
 *	Static return buffers are used because only one broadcast gets
 * processed at a time, and the essential information in each one is
 * either displayed and discarded or copied into a scroll-of-mail object.
 *
 *	The test driver code below can be used to check out potential new
 * entries without rebuilding NetHack itself.  CC/DEFINE="TEST_DRIVER"
 * Link it with hacklib.obj or nethack.olb/incl=hacklib (not nethack/lib).
 */

static struct mail_info msg;	/* parse_*()'s return buffer */
static char nam_cmd_buf[63],	/* maximum onamelth, size of ONAME(object) */
	    txt_buf[255+1];	/* same size as used for message buf[] */

/* try to decipher and categorize broadcast message text
*/
static struct mail_info *
parse_brdcst(buf)		/* called by parse_next_broadcast() */
char *buf;			/* input: filtered broadcast text */
{
    int typ;
    char *txt;
    const char *nam, *cmd;

/* arbitrary broadcast: batch job completed, system shutdown imminent, &c */
	typ = MSG_OTHER;
	nam = (char *) 0; /*"captured broadcast message"*/
	cmd = (char *) 0;
	txt = strcat(strcpy(txt_buf, "Message for you: "), buf);
    /* truncate really long messages to prevent verbalize() from blowing up */
    if (txt && strlen(txt) > BUFSZ - 50) txt[BUFSZ - 50] = '\0';

    msg.message_typ  = typ;	/* simple index */
    msg.display_txt  = txt;	/* text for daemon to pline() */
    msg.object_nam   = nam;	/* 'name' for mail scroll */
    msg.response_cmd = cmd;	/* command to spawn when scroll read */
    return &msg;
}

/* filter out non-printable characters and redundant noise
*/
static void
filter_brdcst(buf)		/* called by parse_next_broadcast() */
register char *buf;		/* in: original text; out: filtered text */
{
    register char c, *p, *buf_p;

    /* filter the text; restrict consecutive spaces or dots to just two */
    for (p = buf_p = buf; *buf_p; buf_p++) {
	c = *buf_p & '\177';
	if (c == ' ' || c == '\t' || c == '\n')
	    if (p == buf ||		/* ignore leading whitespace */
		(p >= buf+2 && *(p-1) == ' ' && *(p-2) == ' ')) continue;
	    else c = ' ';
	else if (c == '.' || c < ' ' || c == '\177')
	    if (p == buf ||		/* skip leading beeps & such */
		(p >= buf+2 && *(p-1) == '.' && *(p-2) == '.')) continue;
	    else c = '.';
	else if (c == '%' &&		/* trim %%% OPCOM verbosity %%% */
		p >= buf+2 && *(p-1) == '%' && *(p-2) == '%') continue;
	*p++ = c;
    }
    *p = '\0';			/* terminate, then strip trailing junk */
    while (p > buf && (*--p == ' ' || *p == '.')) *p = '\0';
    return;
}

static char empty_string[] = "";

/* fetch the text of a captured broadcast, then mangle and decipher it
*/
struct mail_info *
parse_next_broadcast()		/* called by ckmailstatus(mail.c) */
{
    short length, msg_type;
    $DESCRIPTOR(message, empty_string);	/* string descriptor for buf[] */
    struct mail_info *result = 0;
    /* messages could actually be longer; let long ones be truncated */
    char buf[255+1];

    message.dsc$a_pointer = buf,  message.dsc$w_length = sizeof buf - 1;
    msg_type = length = 0;
    smg$get_broadcast_message(&pasteboard_id, &message, &length, &msg_type);
    if (msg_type == MSG$_TRMBRDCST) {
	buf[length] = '\0';
	filter_brdcst(buf);		/* mask non-printable characters */
	result = parse_brdcst(buf);	/* do the real work */
    } else if (msg_type == MSG$_TRMHANGUP) {
	(void) gsignal(SIGHUP);
    }
    return result;
}

/* spit out any pending broadcast messages whenever we leave
*/
static void
flush_broadcasts()	/* called from disable_broadcast_trapping() */
{
    if (broadcasts > 0) {
	short len, typ;
	$DESCRIPTOR(msg_dsc, empty_string);
	char buf[512+1];

	msg_dsc.dsc$a_pointer = buf,  msg_dsc.dsc$w_length = sizeof buf - 1;
	raw_print("");		/* print at least one line for wait_synch() */
	do {
	    typ = len = 0;
	    smg$get_broadcast_message(&pasteboard_id, &msg_dsc, &len, &typ);
	    if (typ == MSG$_TRMBRDCST) buf[len] = '\0',  raw_print(buf);
	} while (--broadcasts);
	wait_synch();		/* prompt with "Hit return to continue: " */
    }
}

/* AST routine called when the terminal's associated mailbox receives a message
*/
/*ARGSUSED*/
static void
broadcast_ast(dummy)		/* called asynchronously by terminal driver */
int dummy;	/* not used */
{
    broadcasts++;
}

/* initialize the broadcast manipulation code; SMG makes this easy
*/
unsigned long init_broadcast_trapping()   /* called by setftty() [once only] */
{
    unsigned long sts, preserve_screen_flag = 1;

    /* we need a pasteboard to pass to the broadcast setup/teardown routines */
    sts = smg$create_pasteboard(&pasteboard_id, 0, 0, 0, &preserve_screen_flag);
    if (!vms_ok(sts)) {
	errno = EVMSERR,  vaxc$errno = sts;
	raw_print("");
	perror("?can't create SMG pasteboard for broadcast trapping");
	wait_synch();
	broadcasts = -1;	/* flag that trapping is currently broken */
    }
    return sts;
}

/* set up the terminal driver to deliver $brkthru data to a mailbox device
*/
unsigned long enable_broadcast_trapping()	/* called by setftty() */
{
    unsigned long sts = 1;

    if (broadcasts >= 0) {	/* (-1 => no pasteboard, so don't even try) */
	/* register callback routine to be triggered when broadcasts arrive */
	/* Note side effect:  also intercepts hangup notification. */
	/* Another note:  TMPMBX privilege is required. */
	sts = smg$set_broadcast_trapping(&pasteboard_id, broadcast_ast, 0);
	if (!vms_ok(sts)) {
	    errno = EVMSERR,  vaxc$errno = sts;
	    raw_print("");
	    perror("?can't enable broadcast trapping");
	    wait_synch();
	}
    }
    return sts;
}

/* return to 'normal'; $brkthru data goes straight to the terminal
*/
unsigned long disable_broadcast_trapping()	/* called by settty() */
{
    unsigned long sts = 1;

    if (broadcasts >= 0) {
	/* disable trapping; releases associated MBX so that SPAWN can work */
	sts = smg$disable_broadcast_trapping(&pasteboard_id);
	if (!vms_ok(sts)) errno = EVMSERR,  vaxc$errno = sts;
	flush_broadcasts();	/* don't hold on to any buffered ones */
    }
    return sts;
}
#else	/* MAIL */
	/* simple stubs for non-mail configuration */
unsigned long init_broadcast_trapping() { return 1; }
unsigned long enable_broadcast_trapping() { return 1; }
unsigned long disable_broadcast_trapping() { return 1; }
struct mail_info *parse_next_broadcast() { return 0; }
#endif	/* MAIL */

/*----------------------------------------------------------------------*/

#ifdef TEST_DRIVER
	/* (Take parse_next_broadcast for a spin. :-) */

volatile int broadcasts = 0;

void newmail(foo)
struct mail_info *foo;
{
# define STRING(s) ((s) ? (s) : "<null>")
    printf("\n\
  message type = %d\n\
  display text = \"%s\"\n\
  object name  = \"%.*s\"\n\
  response cmd = \"%s\"\n\
",      foo->message_typ, STRING(foo->display_txt),
	(foo->object_nam && foo->response_cmd) ?
		(foo->response_cmd - foo->object_nam - 1) :
		strlen(STRING(foo->object_nam)),
	STRING(foo->object_nam), STRING(foo->response_cmd));
# undef STRING
}

void ckmailstatus()
{
    struct mail_info *brdcst, *parse_next_broadcast();

    while (broadcasts > 0) {	/* process all trapped broadcasts [until] */
	broadcasts--;
	if ((brdcst = parse_next_broadcast()) != 0) {
	    newmail(brdcst);
	    break;		/* only handle one real message at a time */
	} else
	    printf("\n--< non-broadcast encountered >--\n");
    }
}

int main()
{
    char dummy[BUFSIZ];

    init_broadcast_trapping();
    enable_broadcast_trapping();
    for (;;) {
	ckmailstatus();
	printf("> "), fflush(stdout);	/* issue a prompt */
	if (!gets(dummy)) break;	/* wait for a response */
    }
    disable_broadcast_trapping();
    return 1;
}

void panic(s) char *s; { raw_print(s); exit(EXIT_FAILURE); }

void raw_print(s) char *s; { puts(s); fflush(stdout); }

void wait_synch() { char dummy[BUFSIZ];
  printf("\nPress <return> to continue: "); fflush(stdout); (void) gets(dummy);
}
#endif	/* TEST_DRIVER */

/*vmsmail.c*/
