#ifndef CURSDIAL_H
#define CURSDIAL_H

#ifdef MENU_COLOR
# ifdef MENU_COLOR_REGEX
#  include <regex.h>
# endif
#endif


/* Global declarations */

void curses_line_input_dialog(const char *prompt, char *answer, int buffer);

int curses_character_input_dialog(const char *prompt, const char *choices, char def);

int curses_ext_cmd(void);

void curses_create_nhmenu(winid wid);

void curses_add_nhmenu_item(winid wid, const ANY_P *identifier,
 char accelerator, char group_accel, int attr, const char *str,
 boolean presel);

void curses_finalize_nhmenu(winid wid, const char *prompt);

int curses_display_nhmenu(winid wid, int how, MENU_ITEM_P **_selected);

boolean curses_menu_exists(winid wid);

void curses_del_menu(winid wid);



#endif  /* CURSDIAL_H */
