/*	SCCS Id: @(#)u_init.c	3.4	2002/10/22	*/
/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1985. */
/* NetHack may be freely redistributed.  See license for details. */

#include "hack.h"

struct trobj {
	short trotyp;
	schar trspe;
	char trclass;
	Bitfield(trquan,6);
	Bitfield(trbless,2);
};

STATIC_DCL void FDECL(add_item,(int));
STATIC_DCL void FDECL(add_item_there_is_no_overloading,(int, int));
STATIC_DCL void FDECL(add_item_there_is_no_overloading_with_charge,(int, int, int));
STATIC_DCL void FDECL(add_item_there_is_no_overloading_full,(int, int, int, int, int));
STATIC_DCL void FDECL(ini_inv, (struct trobj *));
STATIC_DCL void FDECL(knows_object,(int));
STATIC_DCL void FDECL(knows_class,(CHAR_P));
STATIC_DCL boolean FDECL(restricted_spell_discipline, (int));

#define UNDEF_TYP		0
#define UNDEF_SPE		'\177'
#define U_INIT_BUC_UNDEF		2
#define U_INIT_BUC_BLESSED		1
#define U_INIT_BUC_UNCURSED	0

/* race-based substitutions for initial inventory; */
static struct inv_sub { short race_pm, item_otyp, subs_otyp; } inv_subs[] = {
    { PM_ELF,     DAGGER,           ELVEN_DAGGER          },
    { PM_ELF,     SPEAR,            ELVEN_SPEAR           },
    { PM_ELF,     SHORT_SWORD,      ELVEN_SHORT_SWORD     },
    { PM_ELF,     BOW,              ELVEN_BOW             },
    { PM_ELF,     ARROW,            ELVEN_ARROW           },
    { PM_ELF,     HELMET,           ELVEN_LEATHER_HELM    },
 /* { PM_ELF,     SMALL_SHIELD,     ELVEN_SHIELD          },  */
    { PM_ELF,     CRAM_RATION,      LEMBAS_WAFER          },
    { PM_ORC,     DAGGER,           ORCISH_DAGGER         },
    { PM_ORC,     SPEAR,            ORCISH_SPEAR          },
    { PM_ORC,     SHORT_SWORD,      ORCISH_SHORT_SWORD    },
    { PM_ORC,     BOW,              ORCISH_BOW            },
    { PM_ORC,     ARROW,            ORCISH_ARROW          },
    { PM_ORC,     HELMET,           ORCISH_HELM           },
    { PM_ORC,     SMALL_SHIELD,     ORCISH_SHIELD         },
    { PM_ORC,     RING_MAIL,        ORCISH_RING_MAIL      },
    { PM_ORC,     CHAIN_MAIL,       ORCISH_CHAIN_MAIL     },
    { PM_DWARF,   SPEAR,            DWARVISH_SPEAR        },
    { PM_DWARF,   SHORT_SWORD,      DWARVISH_SHORT_SWORD  },
    { PM_DWARF,   HELMET,           DWARVISH_IRON_HELM    },
 /* { PM_DWARF,   SMALL_SHIELD,     DWARVISH_ROUNDSHIELD  },  */
 /* { PM_DWARF,   PICK_AXE,         DWARVISH_MATTOCK      },  */
    { PM_GNOME,   BOW,              CROSSBOW              },
    { PM_GNOME,   ARROW,            CROSSBOW_BOLT         },
    { PM_VAMPIRE, POT_FRUIT_JUICE,  POT_BLOOD             },
    { PM_VAMPIRE, FOOD_RATION,      POT_VAMPIRE_BLOOD     },
    { NON_PM,     STRANGE_OBJECT,   STRANGE_OBJECT        }
};

static const struct def_skill Skill_A[] = {
    { P_DAGGER, P_BASIC },		{ P_KNIFE,  P_BASIC },
    { P_PICK_AXE, P_EXPERT },		{ P_SHORT_SWORD, P_BASIC },
    { P_SCIMITAR, P_SKILLED },		{ P_SABER, P_EXPERT },
    { P_CLUB, P_SKILLED },		{ P_QUARTERSTAFF, P_SKILLED },
    { P_SLING, P_SKILLED },		{ P_DART, P_BASIC },
    { P_BOOMERANG, P_EXPERT },		{ P_WHIP, P_EXPERT },
    { P_UNICORN_HORN, P_SKILLED },
    { P_ATTACK_SPELL, P_BASIC },	{ P_HEALING_SPELL, P_BASIC },
    { P_DIVINATION_SPELL, P_EXPERT},	{ P_MATTER_SPELL, P_BASIC},
    { P_RIDING, P_BASIC },
    { P_TWO_WEAPON_COMBAT, P_BASIC },
    { P_BARE_HANDED_COMBAT, P_EXPERT },
    { P_NONE, 0 }
};

static const struct def_skill Skill_B[] = {
    { P_DAGGER, P_BASIC },		{ P_AXE, P_EXPERT },
    { P_PICK_AXE, P_SKILLED },	{ P_SHORT_SWORD, P_EXPERT },
    { P_BROAD_SWORD, P_SKILLED },	{ P_LONG_SWORD, P_SKILLED },
    { P_TWO_HANDED_SWORD, P_EXPERT },	{ P_SCIMITAR, P_SKILLED },
    { P_SABER, P_BASIC },		{ P_CLUB, P_SKILLED },
    { P_MACE, P_SKILLED },		{ P_MORNING_STAR, P_SKILLED },
    { P_FLAIL, P_BASIC },		{ P_HAMMER, P_EXPERT },
    { P_QUARTERSTAFF, P_BASIC },	{ P_SPEAR, P_SKILLED },
    { P_TRIDENT, P_SKILLED },		{ P_BOW, P_BASIC },
    { P_ATTACK_SPELL, P_SKILLED },
    { P_RIDING, P_BASIC },
    { P_TWO_WEAPON_COMBAT, P_BASIC },
    { P_BARE_HANDED_COMBAT, P_MASTER },
    { P_NONE, 0 }
};

static const struct def_skill Skill_C[] = {
    { P_DAGGER, P_BASIC },		{ P_KNIFE,  P_SKILLED },
    { P_AXE, P_SKILLED },		{ P_PICK_AXE, P_BASIC },
    { P_CLUB, P_EXPERT },		{ P_MACE, P_EXPERT },
    { P_MORNING_STAR, P_BASIC },	{ P_FLAIL, P_SKILLED },
    { P_HAMMER, P_SKILLED },		{ P_QUARTERSTAFF, P_EXPERT },
    { P_POLEARMS, P_SKILLED },		{ P_SPEAR, P_EXPERT },
    { P_JAVELIN, P_SKILLED },		{ P_TRIDENT, P_SKILLED },
    { P_BOW, P_SKILLED },		{ P_SLING, P_EXPERT },
    { P_ATTACK_SPELL, P_BASIC },	{ P_MATTER_SPELL, P_SKILLED },
    { P_BOOMERANG, P_EXPERT },		{ P_UNICORN_HORN, P_BASIC },
    { P_BARE_HANDED_COMBAT, P_MASTER },
    { P_NONE, 0 }
};

static const struct def_skill Skill_H[] = {
    { P_DAGGER, P_SKILLED },		{ P_KNIFE, P_EXPERT },
    { P_SHORT_SWORD, P_SKILLED },	{ P_SCIMITAR, P_BASIC },
    { P_SABER, P_BASIC },		{ P_CLUB, P_SKILLED },
    { P_MACE, P_BASIC },		{ P_QUARTERSTAFF, P_EXPERT },
    { P_POLEARMS, P_BASIC },		{ P_SPEAR, P_BASIC },
    { P_JAVELIN, P_BASIC },		{ P_TRIDENT, P_BASIC },
    { P_SLING, P_SKILLED },		{ P_DART, P_EXPERT },
    { P_SHURIKEN, P_SKILLED },		{ P_UNICORN_HORN, P_EXPERT },
    { P_HEALING_SPELL, P_EXPERT },
    { P_BARE_HANDED_COMBAT, P_BASIC },
    { P_NONE, 0 }
};

static const struct def_skill Skill_K[] = {
    { P_DAGGER, P_BASIC },		{ P_KNIFE, P_BASIC },
    { P_AXE, P_SKILLED },		{ P_PICK_AXE, P_BASIC },
    { P_SHORT_SWORD, P_SKILLED },	{ P_BROAD_SWORD, P_SKILLED },
    { P_LONG_SWORD, P_EXPERT },	{ P_TWO_HANDED_SWORD, P_SKILLED },
    { P_SCIMITAR, P_BASIC },		{ P_SABER, P_SKILLED },
    { P_CLUB, P_BASIC },		{ P_MACE, P_SKILLED },
    { P_MORNING_STAR, P_SKILLED },	{ P_FLAIL, P_BASIC },
    { P_HAMMER, P_BASIC },		{ P_POLEARMS, P_SKILLED },
    { P_SPEAR, P_SKILLED },		{ P_JAVELIN, P_SKILLED },
    { P_TRIDENT, P_BASIC },		{ P_LANCE, P_EXPERT },
    { P_BOW, P_BASIC },			{ P_CROSSBOW, P_SKILLED },
    { P_ATTACK_SPELL, P_SKILLED },	{ P_HEALING_SPELL, P_SKILLED },
    { P_CLERIC_SPELL, P_SKILLED },
    { P_RIDING, P_EXPERT },
    { P_TWO_WEAPON_COMBAT, P_SKILLED },
    { P_BARE_HANDED_COMBAT, P_EXPERT },
    { P_NONE, 0 }
};

static const struct def_skill Skill_Mon[] = {
    { P_QUARTERSTAFF, P_BASIC },    { P_SPEAR, P_BASIC },
    { P_JAVELIN, P_BASIC },		    { P_CROSSBOW, P_BASIC },
    { P_SHURIKEN, P_BASIC },
    { P_ATTACK_SPELL, P_BASIC },    { P_HEALING_SPELL, P_EXPERT },
    { P_DIVINATION_SPELL, P_BASIC },{ P_ENCHANTMENT_SPELL, P_BASIC },
    { P_CLERIC_SPELL, P_SKILLED },  { P_ESCAPE_SPELL, P_BASIC },
    { P_MATTER_SPELL, P_BASIC },
    { P_MARTIAL_ARTS, P_GRAND_MASTER },
    { P_NONE, 0 }
};

static const struct def_skill Skill_P[] = {
    { P_CLUB, P_EXPERT },		{ P_MACE, P_EXPERT },
    { P_MORNING_STAR, P_EXPERT },	{ P_FLAIL, P_EXPERT },
    { P_HAMMER, P_EXPERT },		{ P_QUARTERSTAFF, P_EXPERT },
    { P_POLEARMS, P_SKILLED },		{ P_SPEAR, P_SKILLED },
    { P_JAVELIN, P_SKILLED },		{ P_TRIDENT, P_SKILLED },
    { P_LANCE, P_BASIC },		{ P_BOW, P_BASIC },
    { P_SLING, P_BASIC },		{ P_CROSSBOW, P_BASIC },
    { P_DART, P_BASIC },		{ P_SHURIKEN, P_BASIC },
    { P_BOOMERANG, P_BASIC },		{ P_UNICORN_HORN, P_SKILLED },
    { P_HEALING_SPELL, P_EXPERT },	{ P_DIVINATION_SPELL, P_EXPERT },
    { P_CLERIC_SPELL, P_EXPERT },
    { P_BARE_HANDED_COMBAT, P_BASIC },
    { P_NONE, 0 }
};

static const struct def_skill Skill_R[] = {
    { P_DAGGER, P_EXPERT },		{ P_KNIFE,  P_EXPERT },
    { P_SHORT_SWORD, P_EXPERT },	{ P_BROAD_SWORD, P_SKILLED },
    { P_LONG_SWORD, P_SKILLED },	{ P_TWO_HANDED_SWORD, P_BASIC },
    { P_SCIMITAR, P_SKILLED },		{ P_SABER, P_SKILLED },
    { P_CLUB, P_SKILLED },		{ P_MACE, P_SKILLED },
    { P_MORNING_STAR, P_BASIC },	{ P_FLAIL, P_BASIC },
    { P_HAMMER, P_BASIC },		{ P_POLEARMS, P_BASIC },
    { P_SPEAR, P_BASIC },		{ P_CROSSBOW, P_EXPERT },
    { P_DART, P_EXPERT },		{ P_SHURIKEN, P_SKILLED },
    { P_DIVINATION_SPELL, P_SKILLED },	{ P_ESCAPE_SPELL, P_SKILLED },
    { P_MATTER_SPELL, P_SKILLED },
    { P_RIDING, P_BASIC },
    { P_TWO_WEAPON_COMBAT, P_EXPERT },
    { P_BARE_HANDED_COMBAT, P_EXPERT },
    { P_NONE, 0 }
};

static const struct def_skill Skill_Ran[] = {
    { P_DAGGER, P_EXPERT },		 { P_KNIFE,  P_SKILLED },
    { P_AXE, P_SKILLED },	 { P_PICK_AXE, P_BASIC },
    { P_SHORT_SWORD, P_BASIC },	 { P_MORNING_STAR, P_BASIC },
    { P_FLAIL, P_SKILLED },	 { P_HAMMER, P_BASIC },
    { P_QUARTERSTAFF, P_BASIC }, { P_POLEARMS, P_SKILLED },
    { P_SPEAR, P_SKILLED },	 { P_JAVELIN, P_EXPERT },
    { P_TRIDENT, P_BASIC },	 { P_BOW, P_EXPERT },
    { P_SLING, P_EXPERT },	 { P_CROSSBOW, P_EXPERT },
    { P_DART, P_EXPERT },	 { P_SHURIKEN, P_SKILLED },
    { P_BOOMERANG, P_EXPERT },	 { P_WHIP, P_BASIC },
    { P_HEALING_SPELL, P_BASIC },
    { P_DIVINATION_SPELL, P_EXPERT },
    { P_ESCAPE_SPELL, P_BASIC },
    { P_RIDING, P_BASIC },
    { P_BARE_HANDED_COMBAT, P_BASIC },
    { P_NONE, 0 }
};

static const struct def_skill Skill_S[] = {
    { P_DAGGER, P_BASIC },		{ P_KNIFE,  P_SKILLED },
    { P_SHORT_SWORD, P_EXPERT },	{ P_BROAD_SWORD, P_SKILLED },
    { P_LONG_SWORD, P_EXPERT },		{ P_TWO_HANDED_SWORD, P_EXPERT },
    { P_SCIMITAR, P_BASIC },		{ P_SABER, P_BASIC },
    { P_FLAIL, P_SKILLED },		{ P_QUARTERSTAFF, P_BASIC },
    { P_POLEARMS, P_SKILLED },		{ P_SPEAR, P_BASIC },
    { P_JAVELIN, P_BASIC },		{ P_LANCE, P_SKILLED },
    { P_BOW, P_EXPERT },		{ P_SHURIKEN, P_EXPERT },
    { P_ATTACK_SPELL, P_SKILLED },	{ P_CLERIC_SPELL, P_SKILLED },
    { P_RIDING, P_SKILLED },
    { P_TWO_WEAPON_COMBAT, P_EXPERT },
    { P_MARTIAL_ARTS, P_MASTER },
    { P_NONE, 0 }
};

static const struct def_skill Skill_T[] = {
    { P_DAGGER, P_EXPERT },		{ P_KNIFE,  P_SKILLED },
    { P_AXE, P_BASIC },			{ P_PICK_AXE, P_BASIC },
    { P_SHORT_SWORD, P_EXPERT },	{ P_BROAD_SWORD, P_BASIC },
    { P_LONG_SWORD, P_BASIC },		{ P_TWO_HANDED_SWORD, P_BASIC },
    { P_SCIMITAR, P_SKILLED },		{ P_SABER, P_SKILLED },
    { P_MACE, P_BASIC },		{ P_MORNING_STAR, P_BASIC },
    { P_FLAIL, P_BASIC },		{ P_HAMMER, P_BASIC },
    { P_QUARTERSTAFF, P_BASIC },	{ P_POLEARMS, P_BASIC },
    { P_SPEAR, P_BASIC },		{ P_JAVELIN, P_BASIC },
    { P_TRIDENT, P_BASIC },		{ P_LANCE, P_BASIC },
    { P_BOW, P_BASIC },			{ P_SLING, P_BASIC },
    { P_CROSSBOW, P_BASIC },		{ P_DART, P_EXPERT },
    { P_SHURIKEN, P_BASIC },		{ P_BOOMERANG, P_BASIC },
    { P_WHIP, P_BASIC },		{ P_UNICORN_HORN, P_SKILLED },
    { P_DIVINATION_SPELL, P_BASIC },	{ P_ENCHANTMENT_SPELL, P_BASIC },
    { P_ESCAPE_SPELL, P_SKILLED },
    { P_RIDING, P_BASIC },
    { P_TWO_WEAPON_COMBAT, P_SKILLED },
    { P_BARE_HANDED_COMBAT, P_SKILLED },
    { P_NONE, 0 }
};

static const struct def_skill Skill_V[] = {
    { P_DAGGER, P_EXPERT },		{ P_AXE, P_EXPERT },
    { P_PICK_AXE, P_SKILLED },		{ P_SHORT_SWORD, P_SKILLED },
    { P_BROAD_SWORD, P_SKILLED },	{ P_LONG_SWORD, P_EXPERT },
    { P_TWO_HANDED_SWORD, P_EXPERT },	{ P_SCIMITAR, P_BASIC },
    { P_SABER, P_BASIC },		{ P_HAMMER, P_EXPERT },
    { P_QUARTERSTAFF, P_BASIC },	{ P_POLEARMS, P_SKILLED },
    { P_SPEAR, P_SKILLED },		{ P_JAVELIN, P_BASIC },
    { P_TRIDENT, P_BASIC },		{ P_LANCE, P_SKILLED },
    { P_SLING, P_BASIC },
    { P_ATTACK_SPELL, P_BASIC },	{ P_ESCAPE_SPELL, P_BASIC },
    { P_RIDING, P_SKILLED },
    { P_TWO_WEAPON_COMBAT, P_SKILLED },
    { P_BARE_HANDED_COMBAT, P_EXPERT },
    { P_NONE, 0 }
};

static const struct def_skill Skill_W[] = {
    { P_DAGGER, P_EXPERT },		{ P_KNIFE,  P_SKILLED },
    { P_AXE, P_SKILLED },		{ P_SHORT_SWORD, P_BASIC },
    { P_CLUB, P_SKILLED },		{ P_MACE, P_BASIC },
    { P_QUARTERSTAFF, P_EXPERT },	{ P_POLEARMS, P_SKILLED },
    { P_SPEAR, P_BASIC },		{ P_JAVELIN, P_BASIC },
    { P_TRIDENT, P_BASIC },		{ P_SLING, P_SKILLED },
    { P_DART, P_EXPERT },		{ P_SHURIKEN, P_BASIC },
    { P_ATTACK_SPELL, P_EXPERT },	{ P_HEALING_SPELL, P_SKILLED },
    { P_DIVINATION_SPELL, P_EXPERT },	{ P_ENCHANTMENT_SPELL, P_SKILLED },
    { P_CLERIC_SPELL, P_SKILLED },	{ P_ESCAPE_SPELL, P_EXPERT },
    { P_MATTER_SPELL, P_EXPERT },
    { P_RIDING, P_BASIC },
    { P_BARE_HANDED_COMBAT, P_BASIC },
    { P_NONE, 0 }
};


STATIC_OVL void
knows_object(int obj)
{
	discover_object(obj,TRUE,FALSE);
	objects[obj].oc_pre_discovered = 1;	/* not a "discovery" */
}

/* Know ordinary (non-magical) objects of a certain class,
 * like all gems except the loadstone and luckstone.
 */
STATIC_OVL void
knows_class(char sym)
{
	int ct;
	for (ct = 1; ct < NUM_OBJECTS; ct++) {
		if (objects[ct].oc_class == sym && !objects[ct].oc_magic && !Is_dragon_armor(ct)) {
			knows_object(ct);
		}
	}
}

void
u_init()
{
	int i;

	flags.female = flags.initgend;
	flags.beginner = 1;

	/* zero u, including pointer values --
	 * necessary when aborting from a failed restore */
	(void) memset((genericptr_t)&u, 0, sizeof(u));
	u.ustuck = (struct monst *)0;

#if 0	/* documentation of more zero values as desirable */
	u.usick_cause[0] = 0;
	u.uluck  = u.moreluck = 0;
	uarmu = 0;
	uarm = uarmc = uarmh = uarms = uarmg = uarmf = 0;
	uwep = uball = uchain = uleft = uright = 0;
	uswapwep = uquiver = 0;
	u.twoweap = 0;
	u.ublessed = 0;				/* not worthy yet */
	u.ugangr   = 0;				/* gods not angry */
	u.ugifts   = 0;				/* no divine gifts bestowed */
# ifdef ELBERETH
	u.uevent.uhand_of_elbereth = 0;
# endif
	u.uevent.uheard_tune = 0;
	u.uevent.uopened_dbridge = 0;
	u.uevent.udemigod = 0;		/* not a demi-god yet... */
	u.udg_cnt = 0;
	u.mh = u.mhmax = u.mtimedone = 0;
	u.uz.dnum = u.uz0.dnum = 0;
	u.utotype = 0;
#endif	/* 0 */

	u.uz.dlevel = 1;
	u.uz0.dlevel = 0;
	u.utolev = u.uz;

	u.umoved = FALSE;
	u.umortality = 0;
	u.ugrave_arise = NON_PM;

	u.umonnum = u.umonster = (flags.female &&
			urole.femalenum != NON_PM) ? urole.femalenum :
			urole.malenum;
	init_uasmon();

	u.ulevel = 0;	/* set up some of the initial attributes */
	u.uhp = u.uhpmax = newhp();
	u.uenmax = urole.enadv.infix + urace.enadv.infix;
	if (urole.enadv.inrnd > 0) {
		u.uenmax += rnd(urole.enadv.inrnd);
	}
	if (urace.enadv.inrnd > 0) {
		u.uenmax += rnd(urace.enadv.inrnd);
	}
	u.uen = u.uenmax;
	u.uspellprot = 0;
	adjabil(0,1);
	u.ulevel = u.ulevelmax = 1;

	/*
	 * u.roleplay should be treated similar to gender and alignment
	 *   - it gets set at character creation
	 *   - it's hard to change in-game
	 *     (e.g. a special NPC could teach literacy somewhere)
	 * the initialisation has to be in front of food, alignment
	 * and inventory.
	 */
	u.roleplay.ascet       = flags.ascet;
	u.roleplay.atheist     = flags.atheist;
	u.roleplay.blindfolded = flags.blindfolded;
	u.roleplay.illiterate  = flags.illiterate;
	u.roleplay.pacifist    = flags.pacifist;
	u.roleplay.nudist      = flags.nudist;
	u.roleplay.vegan       = flags.vegan;
	u.roleplay.vegetarian  = flags.vegetarian;

	init_uhunger();
	for (i = 0; i <= MAXSPELL; i++) {
		spl_book[i].sp_id = NO_SPELL;
	}
	u.ublesscnt = 300; /* no prayers just yet */
	u.ualignbase[A_CURRENT] = u.ualignbase[A_ORIGINAL] = u.ualign.type = aligns[flags.initalign].value;
	u.ulycn = NON_PM;

#if defined(BSD) && !defined(POSIX_TYPES)
	(void) time((long *)&u.ubirthday);
#else
	(void) time(&u.ubirthday);
#endif

	/*
	 *  For now, everyone starts out with a night vision range of 1 and
	 *  their xray range disabled.
	 */
	u.nv_range   =  1;
	u.xray_range = -1;

	/* Everyone knows what the scroll of identify is. */
	knows_object(SCR_IDENTIFY);

	/*** Role-specific initializations ***/
	switch (Role_switch) {
	/* rn2(100) > 50 necessary for some choices because some
	 * random number generators are bad enough to seriously
	 * skew the results if we use rn2(2)...  --KAA
	 */
	case PM_ARCHEOLOGIST:
		/* if adventure has a name...  idea from tan@uvm-gen */
		add_item_there_is_no_overloading_with_charge(BULLWHIP, 1, 2);
		add_item(LEATHER_JACKET);
		add_item(FEDORA);
		add_item_there_is_no_overloading(FOOD_RATION, 3);
		add_item(PICK_AXE);
		add_item(TINNING_KIT);
		add_item(TOUCHSTONE);
		add_item(SACK);
		add_item_there_is_no_overloading(POT_OBJECT_DETECTION, rn2(3));
		add_item_there_is_no_overloading(SCR_GOLD_DETECTION, rn2(3));
		if(!rn2(10)) add_item(TIN_OPENER);
		if(!rn2(4)) add_item(OIL_LAMP);
		if(!rn2(20)) add_item(MAGIC_MARKER);
		add_item(SKELETON_KEY);
		knows_object(SACK);
		knows_object(TOUCHSTONE);
		skill_init(Skill_A);
		break;
	case PM_BARBARIAN:
		if (rn2(100) >= 50) {	/* see above comment */
			add_item(TWO_HANDED_SWORD);
			add_item(AXE);
		} else {
			add_item(BATTLE_AXE);
			add_item(SHORT_SWORD);
		}
		add_item(RING_MAIL);
		add_item(FOOD_RATION);
		if(!rn2(6)) add_item(OIL_LAMP);
		knows_class(WEAPON_CLASS);
		knows_class(ARMOR_CLASS);
		skill_init(Skill_B);
		break;
	case PM_CAVEMAN:
		add_item_there_is_no_overloading_with_charge(CLUB, 1, +1);
		add_item_there_is_no_overloading_with_charge(SLING, 1, +2);
		add_item_there_is_no_overloading(FLINT, rn1(11, 10)); /* 10..20 */
		add_item_there_is_no_overloading(ROCK, 3); /* yields 18..33 */
		add_item(LEATHER_ARMOR);
		skill_init(Skill_C);
		break;
	case PM_HEALER:
#ifndef GOLDOBJ
		u.ugold = u.ugold0 = rn1(1000, 1001);
#else
		u.umoney0 = rn1(1000, 1001);
#endif
		add_item(SCALPEL);
		add_item_there_is_no_overloading_with_charge(LEATHER_GLOVES, 1, +1);
		add_item(STETHOSCOPE);
		add_item_there_is_no_overloading(POT_HEALING, 4);
		add_item_there_is_no_overloading(POT_EXTRA_HEALING, 4);
		add_item(WAN_SLEEP);
		/* always blessed, so it's guaranteed readable */
		add_item_there_is_no_overloading_full(SPE_HEALING, 1, 0, SPBOOK_CLASS, U_INIT_BUC_BLESSED);
		add_item_there_is_no_overloading_full(SPE_EXTRA_HEALING, 1, 0, SPBOOK_CLASS, U_INIT_BUC_BLESSED);
		add_item_there_is_no_overloading_full(SPE_STONE_TO_FLESH, 1, 0, SPBOOK_CLASS, U_INIT_BUC_BLESSED);
		add_item_there_is_no_overloading(APPLE, 5);
		if(!rn2(25)) add_item(OIL_LAMP);
		knows_object(POT_FULL_HEALING);
		skill_init(Skill_H);
		break;
	case PM_KNIGHT:
		add_item_there_is_no_overloading_with_charge(LONG_SWORD, 1, +1);
		add_item_there_is_no_overloading_with_charge(LANCE, 1, +1);
		add_item_there_is_no_overloading_with_charge(RING_MAIL, 1, +1);
		add_item(HELMET);
		add_item(SMALL_SHIELD);
		add_item(LEATHER_GLOVES);
		add_item_there_is_no_overloading(APPLE, 10);
		add_item_there_is_no_overloading(CARROT, 10);
		knows_class(WEAPON_CLASS);
		knows_class(ARMOR_CLASS);
		/* give knights chess-like mobility
		 * -- idea from wooledge@skybridge.scl.cwru.edu */
		HJumping |= FROMOUTSIDE;
		skill_init(Skill_K);
		break;
	case PM_MONK:
		add_item_there_is_no_overloading_with_charge(LEATHER_GLOVES, 1, +2);
		add_item_there_is_no_overloading_with_charge(ROBE, 1, +1);
		int spellbook_type;
		switch (rn2(90) / 30) {
			case 0: spellbook_type = SPE_HEALING; break;
			case 1: spellbook_type = SPE_PROTECTION; break;
			case 2: spellbook_type = SPE_SLEEP; break;
			default: impossible("bad switch in u_init, PM_MONK"); break;
		}
		add_item_there_is_no_overloading_full(spellbook_type, 1, UNDEF_SPE, SPBOOK_CLASS, U_INIT_BUC_BLESSED);
		add_item_there_is_no_overloading_full(UNDEF_TYP, 1, UNDEF_SPE, SCROLL_CLASS, U_INIT_BUC_UNDEF);
		add_item_there_is_no_overloading(POT_HEALING, 3);
		add_item_there_is_no_overloading(FOOD_RATION, 3);
		add_item_there_is_no_overloading(APPLE, 5);
		add_item_there_is_no_overloading(ORANGE, 5);
		/* Yes, we know fortune cookies aren't really from China.  They were
		 * invented by George Jung in Los Angeles, California, USA in 1916.
		 */
		add_item_there_is_no_overloading(FORTUNE_COOKIE, 3);
		if (!rn2(5)) {
			add_item(MAGIC_MARKER);
		} else if(!rn2(10)) {
			add_item(OIL_LAMP);
		}
		knows_class(ARMOR_CLASS);
		skill_init(Skill_Mon);
		break;
	case PM_PRIEST:
		add_item_there_is_no_overloading_full(MACE, 1, +1, WEAPON_CLASS, U_INIT_BUC_BLESSED);
		add_item(ROBE);
		add_item(SMALL_SHIELD);
		add_item_there_is_no_overloading_full(POT_WATER, 4, 0, POTION_CLASS, U_INIT_BUC_BLESSED); /* holy water */
		add_item(CLOVE_OF_GARLIC);
		add_item(SPRIG_OF_WOLFSBANE);
		add_item_there_is_no_overloading_full(UNDEF_TYP, 2, 0, SPBOOK_CLASS, U_INIT_BUC_UNDEF);
		if (!rn2(10)) {
			add_item(MAGIC_MARKER);
		} else if(!rn2(10)) {
			add_item(OIL_LAMP);
		}
		knows_object(POT_WATER);
		skill_init(Skill_P);
		/* KMH, conduct --
		 * Some may claim that this isn't agnostic, since they
		 * are literally "priests" and they have holy water.
		 * But we don't count it as such.  Purists can always
		 * avoid playing priests and/or confirm another player's
		 * role in their YAAP.
		 */
		break;
	case PM_RANGER:
		add_item_there_is_no_overloading_with_charge(DAGGER, 1, +1);
		add_item_there_is_no_overloading_with_charge(BOW, 1, +1);
		add_item_there_is_no_overloading_with_charge(ARROW, rn1(10, 50), +2);
		add_item_there_is_no_overloading_with_charge(ARROW, rn1(10, 30), +0);
		if(urace.malenum == PM_ELF) {
			add_item_there_is_no_overloading_with_charge(ELVEN_CLOAK, 1, +2); //they shoot better
		} else {
			add_item_there_is_no_overloading_with_charge(CLOAK_OF_DISPLACEMENT, 1, +2);
		}
		add_item_there_is_no_overloading(CRAM_RATION, 4);
		skill_init(Skill_Ran);
		break;
	case PM_ROGUE:
#ifndef GOLDOBJ
		u.ugold = u.ugold0 = 0;
#else
		u.umoney0 = 0;
#endif
		add_item(SHORT_SWORD);
		add_item_there_is_no_overloading(DAGGER, rn1(10, 6));
		add_item_there_is_no_overloading_with_charge(LEATHER_ARMOR, 1, +1);
		add_item(POT_SICKNESS);
		add_item(LOCK_PICK);
		add_item(SACK);
		if(!rn2(5)) {
			add_item(BLINDFOLD);
		}
		knows_object(SACK);
		skill_init(Skill_R);
		break;
	case PM_SAMURAI:
		add_item_there_is_no_overloading(YA, rn1(20, 26));
		add_item(KATANA);
		add_item(YUMI);
		add_item(SHORT_SWORD); /* wakizashi */
		add_item(SPLINT_MAIL);
		if(!rn2(5)) {
			add_item(BLINDFOLD);
		}
		knows_class(WEAPON_CLASS);
		knows_class(ARMOR_CLASS);
		skill_init(Skill_S);
		break;
	case PM_TOURIST:
#ifndef GOLDOBJ
		u.ugold = u.ugold0 = rnd(1000);
#else
		u.umoney0 = rnd(1000);
#endif
		add_item_there_is_no_overloading_with_charge(DART, rn1(20, 21), +2);
		add_item_there_is_no_overloading_full(UNDEF_TYP, 10, UNDEF_SPE, FOOD_CLASS, U_INIT_BUC_UNCURSED);
		add_item_there_is_no_overloading(POT_EXTRA_HEALING, 2);
		add_item_there_is_no_overloading(SCR_MAGIC_MAPPING, 4);
		add_item(HAWAIIAN_SHIRT);
		add_item(EXPENSIVE_CAMERA);
		add_item(CREDIT_CARD);
		if(!rn2(25)) {
			add_item(TIN_OPENER);
		} else if(!rn2(25)) {
			add_item(LEASH);
		} else if(!rn2(25) && !towelday()) {
			add_item(TOWEL);
		} else if(!rn2(25)) {
			add_item(MAGIC_MARKER);
		}
		skill_init(Skill_T);
		break;
	case PM_VALKYRIE:
		add_item_there_is_no_overloading_with_charge(LONG_SWORD, 1, +1);
		add_item(DAGGER);
		add_item_there_is_no_overloading_with_charge(SMALL_SHIELD, 1, +3);
		add_item(FOOD_RATION);
		if(!rn2(6)) {
			add_item(OIL_LAMP);
		}
		knows_class(WEAPON_CLASS);
		knows_class(ARMOR_CLASS);
		skill_init(Skill_V);
		break;
	case PM_WIZARD:
		add_item_there_is_no_overloading_full(QUARTERSTAFF, 1, +1, WEAPON_CLASS, U_INIT_BUC_BLESSED);
		int cloak = CLOAK_OF_MAGIC_RESISTANCE;
		if(!rn2(12)) {
			cloak = ALCHEMY_SMOCK;
		}
		if(!rn2(12)) {
			cloak = ROBE;
		}
		if(!rn2(12)) {
			cloak = CLOAK_OF_DISPLACEMENT;
		}
		if(!rn2(12)) {
			cloak = CLOAK_OF_INVISIBILITY;
		}
		if(!rn2(12)) {
			cloak = OILSKIN_CLOAK;
		}
		if(!rn2(12)) {
			cloak = CLOAK_OF_PROTECTION;
		}
		add_item(cloak);
		add_item_there_is_no_overloading_full(UNDEF_TYP, 1, UNDEF_SPE, WAND_CLASS, U_INIT_BUC_UNDEF);
		add_item_there_is_no_overloading_full(UNDEF_TYP, 2, UNDEF_SPE, RING_CLASS, U_INIT_BUC_UNDEF);
		add_item_there_is_no_overloading_full(UNDEF_TYP, 3, UNDEF_SPE, POTION_CLASS, U_INIT_BUC_UNDEF);
		add_item_there_is_no_overloading_full(UNDEF_TYP, 3, UNDEF_SPE, SCROLL_CLASS, U_INIT_BUC_UNDEF);
		add_item_there_is_no_overloading_full(SPE_FORCE_BOLT, 1, UNDEF_SPE, SPBOOK_CLASS, U_INIT_BUC_BLESSED);
		add_item_there_is_no_overloading_full(UNDEF_TYP, 1, UNDEF_SPE, SPBOOK_CLASS, U_INIT_BUC_UNDEF); /* after SPE_FORCE_BOLT to avoid generating duplicate*/
		if(!rn2(5)) {
			add_item(MAGIC_MARKER);
		}
		if(!rn2(5)) {
			add_item(BLINDFOLD);
		}
		skill_init(Skill_W);
		break;

	default:	/* impossible */
		warning("u_init: unknown role %d", Role_switch);
		break;
	}


	/*** Race-specific initializations ***/
	switch (Race_switch) {
	case PM_HUMAN:
		/* Nothing special */
		break;

	case PM_ELF:
		/*
		 * Elves are people of music and song, or they are warriors.
		 * Non-warriors get an instrument.  We use a kludge to
		 * get only non-magic instruments.
		 */
		if (Role_if(PM_PRIEST) || Role_if(PM_WIZARD)) {
			static int trotyp[] = {
				WOODEN_FLUTE, TOOLED_HORN, WOODEN_HARP, BELL, BUGLE, LEATHER_DRUM
			};
			add_item(trotyp[rn2(SIZE(trotyp))]);
		}
		/* Elves can recognize all elvish objects */
		knows_object(ELVEN_SHORT_SWORD);
		knows_object(ELVEN_ARROW);
		knows_object(ELVEN_BOW);
		knows_object(ELVEN_SPEAR);
		knows_object(ELVEN_DAGGER);
		knows_object(ELVEN_BROADSWORD);
		knows_object(ELVEN_MITHRIL_COAT);
		knows_object(ELVEN_LEATHER_HELM);
		knows_object(ELVEN_SHIELD);
		knows_object(ELVEN_BOOTS);
		knows_object(ELVEN_CLOAK);
		break;

	case PM_DWARF:
		/* Dwarves can recognize all dwarvish objects */
		knows_object(DWARVISH_SPEAR);
		knows_object(DWARVISH_SHORT_SWORD);
		knows_object(DWARVISH_MATTOCK);
		knows_object(DWARVISH_IRON_HELM);
		knows_object(DWARVISH_MITHRIL_COAT);
		knows_object(DWARVISH_CLOAK);
		knows_object(DWARVISH_ROUNDSHIELD);
		if (!rn2(4) && !Role_if(PM_ARCHEOLOGIST)) {
			/* Wise dwarves bring their toy to the dungeons. */
			add_item(PICK_AXE);
		}
		break;

	case PM_GNOME:
		if (!rn2(15)) {
			add_item(TALLOW_CANDLE);
		}
		break;

	case PM_ORC:
		/* compensate for generally inferior equipment */
		if (!Role_if(PM_WIZARD)) {
			add_item_there_is_no_overloading_full(UNDEF_TYP, 2, UNDEF_SPE, FOOD_CLASS, U_INIT_BUC_UNCURSED);
		}
		/* Orcs are naughty and carry poison */
		add_item(POT_SICKNESS);
		/* Orcs can recognize all orcish objects */
		knows_object(ORCISH_SHORT_SWORD);
		knows_object(ORCISH_ARROW);
		knows_object(ORCISH_BOW);
		knows_object(ORCISH_SPEAR);
		knows_object(ORCISH_DAGGER);
		knows_object(ORCISH_CHAIN_MAIL);
		knows_object(ORCISH_RING_MAIL);
		knows_object(ORCISH_HELM);
		knows_object(ORCISH_SHIELD);
		knows_object(URUK_HAI_SHIELD);
		knows_object(ORCISH_CLOAK);
		break;

	case PM_VAMPIRE:
		/* Vampires start off with gods not as pleased, luck penalty */
		adjalign(-5); 
		change_luck(-1);
		break;

	default:	/* impossible */
		warning("u_init: unknown race %d", Race_switch);
		break;
	}

	/* Towel Day: In Memoriam Douglas Adams */
	if (towelday()) {
		add_item(TOWEL);
	}

	/*** Conduct specific initialisation ***/

	if (u.roleplay.blindfolded) {
		if(!ublindf) add_item(BLINDFOLD);
	} else {
		violated(CONDUCT_BLINDFOLDED);
	}
	if (u.roleplay.atheist) {
		u.ugangr++;
	}

	if (discover) {
		add_item_there_is_no_overloading_with_charge(WAN_WISHING, 1, 3);
	}
#ifdef WIZARD
	if (wizard) {
		read_wizkit();
	}
#endif

#ifndef GOLDOBJ
	u.ugold0 += hidden_gold();	/* in case sack has gold in it */
#else
	if (u.umoney0) {
		add_item_there_is_no_overloading_full(GOLD_PIECE, 1, 0, COIN_CLASS, U_INIT_BUC_UNCURSED)
	}
	u.umoney0 += hidden_gold();	/* in case sack has gold in it */
#endif

	find_ac();			/* get initial ac value */
	init_attr(75);			/* init attribute values */
	max_rank_sz();			/* set max str size for class ranks */
/*
 *	Do we really need this?
 */
	for(i = 0; i < A_MAX; i++) {
		if(!rn2(20)) {
			int xd = rn2(7) - 2;	/* biased variation */
			(void) adjattrib(i, xd, TRUE);
			if (ABASE(i) < AMAX(i)) {
				AMAX(i) = ABASE(i);
			}
		}
	}

	/* make sure you can carry all you have - especially for Tourists */
	while (inv_weight() > 0) {
		if (adjattrib(A_STR, 1, TRUE)) {
			continue;
		}
		if (adjattrib(A_CON, 1, TRUE)) {
			continue;
		}
		/* only get here when didn't boost strength or constitution */
		break;
	}

	return;
}

/* skills aren't initialized, so we use the role-specific skill lists */
STATIC_OVL boolean
restricted_spell_discipline(int otyp)
{
	const struct def_skill *skills;
	int this_skill = spell_skilltype(otyp);

	switch (Role_switch) {
		case PM_ARCHEOLOGIST:	skills = Skill_A; break;
		case PM_BARBARIAN:		skills = Skill_B; break;
		case PM_CAVEMAN:		skills = Skill_C; break;
		case PM_HEALER:		skills = Skill_H; break;
		case PM_KNIGHT:		skills = Skill_K; break;
		case PM_MONK:		skills = Skill_Mon; break;
		case PM_PRIEST:		skills = Skill_P; break;
		case PM_RANGER:		skills = Skill_Ran; break;
		case PM_ROGUE:		skills = Skill_R; break;
		case PM_SAMURAI:		skills = Skill_S; break;
		case PM_TOURIST:		skills = Skill_T; break;
		case PM_VALKYRIE:		skills = Skill_V; break;
		case PM_WIZARD:		skills = Skill_W; break;
		default:			impossible("Role_switch failure in restricted_spell_discipline"); skills = 0; break;
	}

	while (skills->skill != P_NONE) {
		if (skills->skill == this_skill) {
			return FALSE;
		}
		skills++;
	}
	return TRUE;
}

boolean
is_forbidden_random_object(int otyp)
{
	/*
	 * For random objects, do not create certain overly powerful
	 * items: wand of wishing, ring of levitation, or the
	 * polymorph/polymorph control combination.  Specific objects,
	 * i.e. the discovery wishing, are still OK.
	 * Also, don't get a couple of really useless items.  (Note:
	 * punishment isn't "useless".  Some players who start out with
	 * one will immediately read it and use the iron ball as a
	 * weapon.)
	 */
	if (otyp == WAN_WISHING) {
		return TRUE;
	} else if ((objects[otyp].oc_class == RING_CLASS || objects[otyp].oc_class == SPBOOK_CLASS) && carrying(otyp)) {
		return TRUE;
	} else if ((otyp == RIN_POLYMORPH_CONTROL) && (carrying(RIN_POLYMORPH) || carrying(SPE_POLYMORPH) || carrying(POT_POLYMORPH) || carrying(WAN_POLYMORPH))) {
		return TRUE;
	} else if ((otyp == RIN_POLYMORPH) && (carrying(RIN_POLYMORPH_CONTROL))) {
		return TRUE;
	} else if ((otyp == SPE_POLYMORPH) && (carrying(RIN_POLYMORPH_CONTROL))) {
		return TRUE;
	} else if ((otyp == POT_POLYMORPH) && (carrying(RIN_POLYMORPH_CONTROL))) {
		return TRUE;
	} else if ((otyp == WAN_POLYMORPH) && (carrying(RIN_POLYMORPH_CONTROL))) {
		return TRUE;
#ifdef ELBERETH
	} else if (otyp == RIN_LEVITATION) {
		return TRUE;
#endif
				/* 'useless' items */
	} else if (otyp == POT_HALLUCINATION) {
		return TRUE;
	} else if (otyp == POT_ACID) {
		return TRUE;
	} else if (otyp == SCR_FLOOD) {
		return TRUE;
	} else if (otyp == SCR_FIRE) {
		return TRUE;
	} else if (otyp == SCR_BLANK_PAPER) {
		return TRUE;
	} else if (otyp == SPE_BLANK_PAPER) {
		return TRUE;
	} else if (otyp == RIN_AGGRAVATE_MONSTER) {
		return TRUE;
	} else if (otyp == RIN_HUNGER) {
		return TRUE;
	} else if (otyp == WAN_NOTHING) {
		return TRUE;
	}
	
	/* Monks don't use weapons */
	if (otyp == SCR_ENCHANT_WEAPON && Role_if(PM_MONK)) {
		return TRUE;
	}

	/* powerful spells are either useless to
	 * low level players or unbalancing; also
	 * spells in restricted skill categories 
	 */
	if (objects[otyp].oc_class == SPBOOK_CLASS && (objects[otyp].oc_level > 3 || restricted_spell_discipline(otyp))) {
		return TRUE;
	}

	return FALSE;
}


void
add_item(int otyp)
{
	add_item_there_is_no_overloading(otyp, 1);
}

void
add_item_there_is_no_overloading(int otyp, int count)
{
	int charge = 0;
	if(objects[otyp].oc_charged) {
		charge = UNDEF_SPE;
	}
	add_item_there_is_no_overloading_with_charge(otyp, count, charge);
}

void
add_item_there_is_no_overloading_with_charge(int otyp, int count, int charge)
{
	add_item_there_is_no_overloading_full(otyp, count, charge, objects[otyp].oc_class, U_INIT_BUC_UNDEF);
}

void
add_item_there_is_no_overloading_full(int otyp, int count, int charge, int class, int BUC_status)
{
	struct trobj new[] = {
		{ otyp, charge, class, count, BUC_status},
	};
	ini_inv(new);
}

void
ini_inv(struct trobj *trop)
{
	struct obj *obj;
	int otyp, i;

	while (trop->trquan > 0) {
		if (trop->trotyp != UNDEF_TYP) {
			otyp = (int)trop->trotyp;
			if (urace.malenum != PM_HUMAN) {
				/* substitute specific items for generic ones */
				for (i = 0; inv_subs[i].race_pm != NON_PM; ++i) {
					if (inv_subs[i].race_pm == urace.malenum && otyp == inv_subs[i].item_otyp) {
						otyp = inv_subs[i].subs_otyp;
						break;
					}
				}
			}
			obj = mksobj(otyp, TRUE, FALSE);
		} else {	/* UNDEF_TYP */
			obj = mkobj(trop->trclass, FALSE);
			otyp = obj->otyp;
			while (is_forbidden_random_object(otyp)) {
				dealloc_obj(obj);
				obj = mkobj(trop->trclass, FALSE);
				otyp = obj->otyp;
			}
			/* Don't start with +0 or negative rings */
			if (objects[otyp].oc_charged && obj->spe <= 0) {
				obj->spe = rne(3);
			}
		}

#ifdef GOLDOBJ
		if (trop->trclass == COIN_CLASS) {
			/* no "blessed" or "identified" money */
			obj->quan = u.umoney0;
		} else {
#endif
			obj->dknown = obj->bknown = obj->rknown = 1;
			if (objects[otyp].oc_uses_known) {
				obj->known = 1;
			}
			obj->oeroded = 0;
			obj->cursed = 0;
			if (obj->opoisoned && u.ualign.type != A_CHAOTIC) {
				obj->opoisoned = 0;
			}
			if (obj->oclass == WEAPON_CLASS || obj->oclass == TOOL_CLASS) {
				obj->quan = (long) trop->trquan;
				trop->trquan = 1;
			} else if (obj->oclass == GEM_CLASS && is_graystone(obj) && obj->otyp != FLINT) {
				obj->quan = 1L;
			}
			if (trop->trspe != UNDEF_SPE) {
				obj->spe = trop->trspe;
			}
			if (trop->trbless != U_INIT_BUC_UNDEF) {
				obj->blessed = trop->trbless;
			}
#ifdef GOLDOBJ
		}
#endif
		/* defined after setting otyp+quan + blessedness */
		obj->owt = weight(obj);
		obj = addinv(obj);

		/* Make the type known if necessary */
		if (OBJ_DESCR(objects[otyp]) && obj->known) {
			discover_object(otyp, TRUE, FALSE);
		}
		discover_object(POT_OIL, TRUE, FALSE); //trivial to identify, in the name of reducing tedium it is autoidentified
		if((obj->oclass == ARMOR_CLASS && !u.roleplay.nudist)) {
			if (is_shield(obj) && !uarms) {
				setworn(obj, W_ARMS);
				if (uswapwep) {
					setuswapwep((struct obj *) 0);
				}
			} else if (is_helmet(obj) && !uarmh) {
				setworn(obj, W_ARMH);
			} else if (is_gloves(obj) && !uarmg) {
				setworn(obj, W_ARMG);
			} else if (is_shirt(obj) && !uarmu) {
				setworn(obj, W_ARMU);
			} else if (is_cloak(obj) && !uarmc) {
				setworn(obj, W_ARMC);
			} else if (is_boots(obj) && !uarmf) {
				setworn(obj, W_ARMF);
			} else if (is_suit(obj) && !uarm) {
				setworn(obj, W_ARM);
			}
		}

		if (obj->oclass == WEAPON_CLASS || is_weptool(obj) || otyp == TIN_OPENER || otyp == FLINT || otyp == ROCK) {
			if (is_ammo(obj) || is_missile(obj)) {
				if (!uquiver) setuqwep(obj);
			} else if ((!uwep) && !u.roleplay.pacifist) {
				setuwep(obj);
			} else if (!uswapwep) {
				setuswapwep(obj);
			}
		}
		if (obj->oclass == SPBOOK_CLASS && obj->otyp != SPE_BLANK_PAPER) {
			initialspell(obj);
		}

		if ((obj->otyp == BLINDFOLD) && u.roleplay.blindfolded) {
			setworn(obj, W_TOOL);
		}

		trop->trquan -= 1;
	}
}

/*u_init.c*/
