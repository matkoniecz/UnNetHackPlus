/* NetHack may be freely redistributed.  See license for details. */
/* This file contains functions producing bogus text replacement for various things during hallucination (for example - monsters, colors).
 * Significant amount of logic related to displaying stuff on the screen is handled by display code (defines in include\display.h etc)
 * Note that replacements for messages are scattered around code.
 * It is easy to find hallucination related code, just search for Hallucination.
 */

#include "hack.h"

static const char * const bogus_monsters[] = {
	"jumbo shrimp", "giant pigmy", "gnu", "killer penguin",
	"giant cockroach", "giant slug", "maggot", "pterodactyl",
	"tyrannosaurus rex", "basilisk", "beholder", "nightmare",
	"efreeti", "marid", "rot grub", "bookworm", "master lichen",
	"shadow", "hologram", "jester", "attorney", "sleazoid",
	"killer tomato", "amazon", "robot", "battlemech",
	"rhinovirus", "harpy", "lion-dog", "rat-ant", "Y2K bug",
						/* misc. */
	"grue", "Christmas-tree monster", "luck sucker", "paskald",
	"brogmoid", "dornbeast",		/* Quendor (Zork, &c.) */
	"Ancient Multi-Hued Dragon", "Evil Iggy",
						/* Moria */
	"emu", "kestrel", "xeroc", "venus flytrap",
						/* Rogue */
	"creeping coins",			/* Wizardry */
	"hydra", "siren",			/* Greek legend */
	"killer bunny",				/* Monty Python */
	"Smokey the bear",			/* "Only you can prevent forest fires!" */
	"Luggage",				/* Discworld */
	"Ent",					/* Lord of the Rings */
	"tangle tree", "nickelpede", "wiggle",	/* Xanth */
	"white rabbit", "snark",		/* Lewis Carroll */
	"pushmi-pullyu",			/* Dr. Dolittle */
	"smurf",				/* The Smurfs */
	"tribble", "Klingon", "Borg",		/* Star Trek */
	"Ewok",					/* Star Wars */
	"Totoro",				/* Tonari no Totoro */
	"ohmu",					/* Nausicaa */
	"youma",				/* Sailor Moon */
	"nyaasu",				/* Pokemon (Meowth) */
	"Godzilla", "King Kong",		/* monster movies */
	"earthquake beast",			/* old L of SH */
	"Invid",				/* Robotech */
	"Terminator",				/* The Terminator */
	"boomer",				/* Bubblegum Crisis */
	"Dalek",				/* Dr. Who ("Exterminate!") */
	"microscopic space fleet", "Ravenous Bugblatter Beast of Traal",
						/* HGttG */
	"teenage mutant ninja turtle",		/* TMNT */
	"samurai rabbit",			/* Usagi Yojimbo */
	"aardvark",				/* Cerebus */
	"Audrey II",				/* Little Shop of Horrors */
	"witch doctor", "one-eyed one-horned flying purple people eater",
						/* 50's rock 'n' roll */
	"Barney the dinosaur",			/* saccharine kiddy TV */
	"Morgoth",				/* Angband */
	"Vorlon",				/* Babylon 5 */
	"questing beast",			/* King Arthur */
	"Predator",				/* Movie */
	"mother-in-law",			/* common pest */
	
	/* from NAO, added in UnNetHack */
	"one-winged dewinged stab-bat",		/* KoL */
	"praying mantis",
	"arch-pedant",
	"beluga whale",
	"bluebird of happiness",
	"bouncing eye", "floating nose",
	"buffer overflow", "dangling pointer", "walking disk drive",
	"cacodemon", "scrag",
	"cardboard golem", "duct tape golem",
	"chess pawn",
	"chicken",
	"chocolate pudding",
	"coelacanth",
	"corpulent porpoise",
	"Crow T. Robot",
	"diagonally moving grid bug",
	"dropbear",
	"Dudley",
	"El Pollo Diablo",
	"evil overlord",
	"existential angst",
	"figment of your imagination", "flash of insight",
	"flying pig",
	"gazebo",
	"gonzo journalist",
	"gray goo", "magnetic monopole",
	"heisenbug",
	"lag monster",
	"loan shark",
	"Lord British",
	"newsgroup troll",
	"ninja pirate zombie robot",
	"octarine dragon",
	"particle man",
	"possessed waffle iron",
	"poultrygeist",
	"raging nerd",
	"roomba",
	"sea cucumber",
	"spelling bee",
	"Strong Bad",
	"stuffed raccoon puppet",
	"tapeworm",
	"liger",
	"velociraptor",
	"vermicious knid",
	"viking",
	"voluptuous ampersand",
	"wee green blobbie",
	"wereplatypus",
	"zergling",
	"hag of bolding",
	"grind bug",
	"enderman",
	"wight supremacist",
	"Magical Trevor",
	"first category perpetual motion device",
	"ghoti",
	"regex engine",
	"netsplit",
	"peer",
	"pigasus",
	"Semigorgon",
	"meeple",
	"conventioneer",
	"terracotta warrior",
	"large microbat", "small megabat",

	/* soundex and typos of monsters, from NAO, added in UnNetHack */
	"gloating eye",
	"flush golem"
	"martyr orc",
	"mortar orc",
	"acute blob",
	"aria elemental",
	"aliasing priest",
	"aligned parasite",
	"aligned parquet",
	"aligned proctor",
	"baby balky dragon",
	"baby blues dragon",
	"baby caricature",
	"baby crochet",
	"baby grainy dragon",
	"baby bong worm",
	"baby long word",
	"baby parable worm",
	"barfed devil",
	"beer wight",
	"boor wight",
	"brawny mold",
	"rave spider",
	"clue golem",
	"bust vortex",
	"errata elemental",
	"elastic eel",
	"electrocardiogram eel",
	"fir elemental",
	"tire elemental",
	"flamingo sphere",
	"fallacy golem",
	"frizzed centaur",
	"forest centerfold",
	"fierceness sphere",
	"frosted giant",
	"geriatric snake",
	"gnat ant",
	"giant bath",
	"grant beetle",
	"giant mango",
	"glossy golem",
	"gnome laureate",
	"gnome dummy",
	"gooier ooze",
	"green slide",
	"guardian nacho",
	"hell hound pun",
	"high purist",
	"hairnet devil",
	"ice trowel",
	"feather golem",
	"lounge worm",
	"mountain lymph",
	"pager golem",
	"pie fiend",
	"prophylactic worm",
	"sock mole",
	"rogue piercer",
	"seesawing sphere",
	"simile mimic",
	"moldier ant",
	"stain vortex",
	"scone giant",
	"umbrella hulk",
	"vampire mace",
	"verbal jabberwock",
	"water lemon",
	"water melon",
	"winged grizzly",
	"yellow wight",

	/* from http://www.alt.org/nethack/addmsgs/viewmsgs.php added in UnNetHackPlus*/
	"lurker below",
	"worthless yellowish-brown glass golem",
	"writhing mass of primal chaos", /* ADOM */
	"hallucinatory monster",
	"jumping brain",
	"colorless green idea",
	"floating ear",
	"floating tongue",
	"hallucinogen-distorted hallucination",
	"mountain dwarf",
	"were(random beast)",
	"weremindflayer",
	"wereplatypus",
	"Gnome With the Wand of Death",
	"arch-lichen",
	"Baba Yaga",
	"harmless protoplasm",
	"badger",
	"giant dwarf",
	"magically animated Vorpal Blade",
	"Legendary black beast of Arrrgh",

	/* from UnNetHack */
	"apostroph golem", "Bob the angry flower",
	"bonsai-kitten", "Boxxy", "lonelygirl15",
	"tie-thulu", "Domo-kun", "nyan cat",
	"looooooooooooong cat",			/* internet memes */
	"bohrbug", "mandelbug", "schroedinbug", /* bugs */
	"Gerbenok",				/* Monty Python killer rabbit */
	"doenertier",				/* Erkan & Stefan */
	"Invisible Pink Unicorn",
	"Flying Spaghetti Monster",		/* deities */
	"Bluebear", "Professor Abdullah Nightingale",
	"Qwerty Uiop", "troglotroll",		/* Zamonien */
	"wolpertinger", "elwedritsche", "skvader",
	"Nessie", "tatzelwurm", "dahu",		/* european cryptids */
	"three-headed monkey",			/* Monkey Island */
	"little green man",			/* modern folklore */
	"weighted Companion Cube",		/* Portal */
	"/b/tard",				/* /b/ */
	"manbearpig",				/* South Park */
	"ceiling cat", "basement cat",
	"monorail cat",				/* the Internet is made for cat pix */
	"rape golem",				/* schnippi */
	"tridude",				/* POWDER */
	"orcus cosmicus",			/* Radomir Dopieralski */
	"yeek", "quylthulg",
	"Greater Hell Beast",			/* Angband */
	"Vendor of Yizard",			/* Souljazz */
	"Sigmund", "lernaean hydra", "Ijyb",
	"Gloorx Vloq", "Blork the orc",		/* Dungeon Crawl Stone Soup */
	"unicorn pegasus kitten",		/* Wil Wheaton, John Scalzi */
	"dwerga nethackus", "dwerga castrum",	/* Ask ASCII Ponies */

	/* from UnNetHackPlus */
	"King Krakus",               /* Polish folklore */
	"Topielec",                  /* Slavic folklore */
	"pink oliphaunt",            /* Lord of the Rings + silliness */
	"Amphisbaena",               /* Greek mythology */
	"phoenix",                   /* Greek mythology */
	"catoblepas",                /* Greek mythology */
	"phantom kangaroo",          /* urban legend */
	"echinemon",                 /* from medieval literature, "enemy of the dragon" */
	"Ratatoskr",                 /* Norse mythology */
	"Twrch Trwyth",              /* Arthurian legends */
	"Unperson",                  /* Nineteen Eighty-Four */
	"Somebody Else's Problem",   /* Douglas Adams */
	"Armok",                     /* Dwarf Fortress */
	"Dwarf-Eating Carp",         /* Dwarf Fortress */
	"Urist McDwarf",             /* Dwarf Fortress */
	"werecapybara",              /* Dwarf Fortress */
	"werecthulhu",
	"weresomething",
	"Evil Otto",                 /* Berzerk - via GruntHack */
	"P'lod",                     /* Weekly World News */
	"mortgage golem", 
	"dark matter golem", 
	"giant orange brain",        /* Dungeon Crawl Stone Soup */
	"ugly thing",                /* Dungeon Crawl Stone Soup */
	"hellephant",                /* Dungeon Crawl Stone Soup */
	"inept mimic",               /* Dungeon Crawl Stone Soup */
	"hungry ghost",              /* Dungeon Crawl Stone Soup */
	"unborn deep dwarf",         /* Dungeon Crawl Stone Soup */
	"Wandering mushroom",        /* Dungeon Crawl Stone Soup */
	"Vlad the Inhaler",
	"Delaunay tessellation field estimator",
	"unnameable horror from beyond",/* NAO fruit name*/
	"munchkin",
	"shambling horror",          /* SporkHack */
	"Grid Bug Mk. 2",            /* SLAS'EM (nickname of arc bugs) */
	"killer tripe ration",       /* SLAS'EM */
	"yet another D&D monster",
	"kobold mage",
	"hobbyte",
	/* via ProgressQuest */
	"will-o'-the-wisp", 
	"ignis fatuus",
	"triceratops",
	"sylph",
	"stegosaurus",
	"sphinx",
	"spectre",
	"lamassu",
	"su-monster",                /* Dungeons & Dragons */
	"shambling mound",           /* Dungeons & Dragons */
	"sand elemental",            /* Dungeons & Dragons */
	"rubber golem"               /* Dungeons & Dragons */
	"remorhaz",                  /* Dungeons & Dragons */
	"otyugh",                    /* Dungeons & Dragons */
	"bacon elemental",
	"roper",
	"roc",
	"peryton",                   /* Jorge Luis Borges - Book of Imaginary Beings */
	"octopus",
	"beer golem",                /* ProgressQuest */
	"rice giant",                /* ProgressQuest */
	"porn elemental",            /* ProgressQuest */
	"demicanadian",              /* ProgressQuest */
	"gyrognome",                 /* ProgressQuest */
	"cardboard golem",
	"cheese elemental",
	"dervish",
	"dragon turtle",
	"megalosaurus",
	"organist",
	/* end of monsters via ProgressQuest */
	"Lucius Malfoy",             /* Harry Potter */
	"Dumbledore",                /* Harry Potter */
	"Harry Potter",              /* Harry Potter */
	"Crumple-Horned Snorkack",   /* Harry Potter */
#ifndef MAIL
	"mail daemon",               /* with defined MAIL it may be selected as real monster in get_bogus_monster_name */
#endif
	"Vaarsuvius",                /* The Order of the Stick */
	"Durkon Thundershield",      /* The Order of the Stick */
	"Roy Greenhilt",             /* The Order of the Stick */
};

/* Return a random monster name, for hallucination.
 * KNOWN BUG: May be a proper name (Godzilla, Barney), may not
 * (the Terminator, a Dalek).  There's no elegant way to deal
 * with this without radically modifying the calling functions.
 */
const char *
get_bogus_monster_name()
{
	int name;

	do {
		name = rn1(SPECIAL_PM + SIZE(bogus_monsters) - LOW_PM, LOW_PM);
	} while (name < SPECIAL_PM && (type_is_pname(&mons[name]) || (mons[name].geno & G_NOGEN)));

	if (name >= SPECIAL_PM) {
		return bogus_monsters[name - SPECIAL_PM];
	}
	return mons[name].mname;
}

static const char * const bogus_items[] = {

	/* Real */
	"arrow",
	"elven arrow",
	"orcish arrow",
	"runed arrow",
	"ruined arrow",
	"crude arrow",
	"vulgar arrow",
	"ya",
	"bamboo arrow",
	"crossbow bolt",
	"dart",
	"shuriken",
	"shurunken",
	"boomerang",
	"elven spear",
	"orcish spear",
	"dwarvish spear",
	"silver spear",
	"sliver spear",
	"javelin",
	"throwing spear",
	"throwing spar",
	"trident",
	"dagger",
	"elven dagger",
	"orcish dagger",
	"silver dagger",
	"athame",
	"scalpel",
	"knife",
	"stiletto",
	"worm tooth",
	"crysknife",
	"axe",
	"battle-axe",
	"short sword",
	"scimitar",
	"curved sword",
	"silver saber",
	"broadsword",
	"long sword",
	"two-handed sword",
	"katana",
	"tsurugi",
	"runesword",
	"partisan",
	"spetum",
	"glaive",
	"ranseur",
	"lance",
	"halberd",
	"bardiche",
	"voulge",
	"dwarvish mattock",
	"fauchard",
	"guisarme",
	"bill-guisarme",
	"lucern hammer",
	"bec de corbin",
	"mace",
	"morning star",
	"club",
	"quarterstaff",
	"iron bar",
	"aklys",
	"thonged club",
	"flail",
	"bullwhip",
	"bow",
	"elven bow",
	"orcish bow",
	"yumi",
	"sling",
	"crossbow",
	"fedora",
	"conical hat",
	"plumed helmet",
	"etched helmet",
	"crested helmet",
	"visored helmet",
	"plate mail",
	"mithril-coat",
	"banded mail",
	"splint mail",
	"chain mail",
	"scale mail",
	"ring mail",
	"studded leather armor",
	"shirt",
	"cloak",
	"robe",
	"small shield",
	"elven shield",
	"shield of reflection",
	"old gloves",
	"padded gloves",
	"riding gloves",
	"fencing gloves",
	"walking shoes",
	"hard shoes",
	"jackboots",
	"combat boots",
	"jungle boots",
	"hiking boots",
	"mud boots",
	"buckled boots",
	"riding boots",

	/* Modern */
	"polo mallet",
	"string vest",
	"applied theology textbook",        /* AFutD */
	"handbag",
	"onion ring",
	"tuxedo",
	"breath mint",
	"potion of antacid",
	"traffic cone",
	"chainsaw",
	"Klein bottle",
	"pair of high-heeled stilettos",    /* the *other* stiletto */
	"intercontinental ballistic missile",
	"doomsday device",
	"potion of Wow-Wow sauce",
	"dyson sphere",
	"Demon Core",
	"zeppelin",
	"Great Attractor",
	"Sloan Great Wall",

	/* injokes */
	"YAFM",                             /* rgrn */
	"YAAP",
	"YASD",
	"Puddingbane",
	"malevolent RNG",
	"pamphlet titled 'How to Raise the Perfect Pudding'",
	"blessed greased +5 silly object of hilarity",
	"The Staff of Misspelling",
	"greased very rotten partly eaten guardian naga hatchling corpse", /* longest possible object name - see objnam.c, line 7 */
	"yet another poorly-differentiated polearm",

	/* Silly */
	"crystall ball bearing",
	"holy hand grenade",                /* Monty Python */
	"decoder ring",
	"amulet of huge gold chains",       /* Foo' */
	"unicron horn",                     /* Transformers */
	"chainmail bikini",
	"first class one-way ticket to Albuquerque", /* Weird Al */
	"yellow spandex dragon scale mail", /* X-Men */
	"Kentucky Fried Basilisk",
	"magic device",
	"kinda lame joke",

	/* Musical Instruments */
	"grand piano",
	"two slightly sampled electric eels", /* Oldfield */
	"kick drum",                        /* 303 */
	"tooled airhorn",

	/* Pop Culture */
	"flux capacitor",                   /* BTTF */
	"Walther PPK",                      /* Bond */
	"hanging chad",                     /* US Election 2000 */
	"99 red balloons",                  /* 80s */
	"pincers of peril",                 /* Goonies */
	"ring of schwartz",                 /* Spaceballs */
	"signed copy of Diaspora",          /* Greg Egan */
	"the missing evidence in the Kelner case", /* Naked Gun */
	"blessed +9 helm of Des Lynam",     /* Bottom */

	/* Culture */
	"The Book of Sand",                 /* Jorge Luis Borges */
	"sonic screwdriver",                /* Doctor Who */
	"lutefisk",

	/* Roguelikes */
	"Orb of Zot",                       /* Dungeon Crawl */
	"head of Morgoth",                  /* Angband, sort of */
	"hand of Vecna",                    /* SLASH'EM */
	"eye of the beholder",              /* SLASH'EM */
	"heavy machine gun",                /* SLASH'EM */
	"gas grenade",                      /* SLASH'EM */
	"gauntlets of swimming",            /* SLASH'EM */
	"amulet versus stone",              /* SLASH'EM */
	"potion of clairvoyance",           /* SLASH'EM */
	"potion of invulnerability",        /* SLASH'EM */
	"spellbook of enchant armor",       /* SLASH'EM */
	"wand of create horde",             /* SLASH'EM */
	"map of The Great Adamantine Space Elevator", /*Dwarf Fortress*/
	"rat blood barrel",                 /* Dwarf Fortress */
	"fly ichor barrel",                 /* Dwarf Fortress */
	"cat tallow roast",                 /* Dwarf Fortress */
	"si",                               /* ADOM, it means "strange item" */
	"Scroll of omnipotence",            /* ADOM */
	"Scroll of vermin control",         /* ADOM */

	/* fruit names from NAO - http://alt.org/nethack/petnames.html */
	"!!+dimple cup stew+!!",            /* fruit name from NAO, inspired by Dwarf Fortress */
	"!!-lignite rock candy-!!",         /* fruit name from NAO, inspired by Dwarf Fortress */
	"!!cat biscuit!!",                  /* fruit name from NAO, inspired by Dwarf Fortress */
	"!!kitten tallow roast!!",          /* fruit name from NAO, inspired by Dwarf Fortress */
	"plump helmet",                     /* fruit name from NAO, inspired by Dwarf Fortress */
	"+7 blessed Happy Meal",
	"ACME Generic Fruit Product",
	"adventurer corpse",
	"AIDS medicine",
	"ambrosia ration",
	"ascension kit",
	"bananananananana",
	"big bowl of sauerkraut",
	"bonesfile",
	"brain of mind flayer",
	"brain",
	"brown percent sign",
	"calculus textbook",
	"chocolate Amulet of Yendor",
	"corpse of a grid bug",
	"eldritch pear",
	"gingerbread Amulet of Yendor",
	"Hand of Vecna",
	"Higgs Boson",
	"human soul",
	"human skull",
	"inevitable failure",
	"lowest unoccupied molecular orbital",
	"mammoth corpse",
	"morsel of existential dread",
	"motor oil",
	"nanobots",
	"nuclear waste",
	"potion of genocide",
	"potion of mana",
	"preserved head",
	"radioactive orb",
	"Recursive RRF Fruit",
	"scroll labeled EAT ME",
	"sentient slime mold",
	"sinister omen of imminent doom",
	"syntax error",
	"thoroughly useless object",

	/* Fantasy */
	"Necronomicon",                     /* Lovecraft */
	"pipe weed",                        /* LOTR */
	"knife missile",                    /* Iain M. Banks */
	"large gem",                        /* Valhalla */
	"monster manual",                   /* D&D */
	"spellbook called Octavo",          /* Discworld */
	"ring of power",                    /* LOTR */
	"lightsaber",
	"pan-galactic gargle blaster",      /* HGttG */
	"Silmaril",                         /* LOTR */
	"pentagram of protection",          /* Quake */
	"horcrux",                          /* HP */
	"Codex of the Infinite Planes",     /* DnD */
	"dragon's claw",

	/* Geekery */
	"AAA chipset",                      /* Amiga */
	"thoroughly used copy of Nethack for Dummies",
	"named pipe",                       /* UNIX */
	"kernel trap",
	"copy of UnNetHackPlus 4.0.0",      /* recursion... */
	"cursed smooth manifold",           /* Topology */
	"vi clone",
	"maximally subsentient emacs mode",
	"bongard diagram",                  /* Intelligence test */
	"git repository",
	"server",

	/* Historical */
	"dead sea scroll",
	"cat o'nine tails",
	"pieces of eight",
	"codpiece",
	"straight-jacket",
	"bayonet",
	"iron maiden",
	"oubliette",
	"pestle and mortar"
	"plowshare",
	"The Book of the All-Virtuous Wisdom of Joshua ben Sira",
	"Holy Grail",                      /* Arthurian legends */
	"cauldron",
	"The Five Books of Moses",         /* aka the Torah */
	"Voynich Manuscript",
	"scythe",

	/* Mashups */
	"scale-reinforced banded-splint mail with chain joints",
	"potion of rebigulation",           /* Simpsons */
	"potion of score doubling",
	"potion of gain divinity",
	"potion of bad breath",
	"scroll labelled ED AWK YACC",      /* the standard scroll */
	"scroll labelled RTFM",
	"scroll labelled KLAATU BARADA NIKTO", /* Evil Dead 3 */
	"scroll of omniscience",
	"scroll of mash keyboard",
	"scroll of plot detection",
	"scroll of RNG taming",
	"scroll of fungicide",
	"scroll of stupidity",
	"spellbook of detect foot",
	"spellbook of detect evil",
	"Spellbook of wishing", /* http://www.alt.org/nethack/addmsgs/viewmsgs.php */
	"heavily obfuscated spellbook",
	"helm of telemetry",
	"blue suede boots of charisma",
	"cubic zirconium",
	"amulet of instadeath",
	"amulet of bad luck",
	"amulet of refraction",
	"O-ring",
	"wand of washing",
	"wand of vaporization",
	"wand of disruption",
	"wand of disintegration",
	"ring named Frost Band",
	"expensive exact replica of the Amulet of Yendor",
	"giant beatle",
	"lodestone",
	"rubber chicken",                   /* c corpse */
	"tin of Player meat",
	"figurine of a god",
	"tin of whoop ass",
	"cursed -3 earring of adornment",
	"wisdom boots",
	"ornamental cape",
	"acid blob skeleton",
	"Lawyerbane",
	"RNG corpse",
	"war hammer",
	"re-curved sword",
	"de-curved sword",
	"circular sword",
	"evening star",
	"peace hammer",
	"heap of wands of wishing", /* Janis Papanagnou on rgrn */
	"size XXXS gray dragon scale mail", /* http://www.nicolaas.net/dudley/index.php?f=20050819 */
	"blessed greased fixed erodeproof disenchanterproof demonpossessionproof vacuumofdeepspaceproof proofremovalproof fully insured 100% all-natural materials completely and utterly intact, undamaged and structurally sound freshly washed and free of the stench of congealed human blood totally bereft of ancient unbreakable curses and absolutely NOT stolen from any nearby easily-angered shopkeepers +3 armor enhancement GRAY DRAGON SCALE MAIL", /* http://www.nicolaas.net/dudley/index.php?f=20050819 */

	/* from tvtropes.org */
	"Sealed Good in a Can",
	"Sealed Evil in a Can ",
	"The Home Handyman's Guide to Building Gates to Hell",
	"The Idiot's Guide to Demonology",
	"tome of Eldritch Lore ",
	"airborne aircraft carrier ",
	"airborne airborne aircraft carrier carrier",
	"MacGuffin",
	"plot device",
	"amulet of dependency",
	"pirate booty",
	/* end of tvtropes.org */

	/* via ProgressQuest */
	"spellbook of animate nightstand",
	"spellbook of astral miasma",
	"spellbook of curse family",
	"spellbook of spectral oyster",
	"spellbook of innoculate",
	"jar of gelatinous cube jam",
	/* end of ProgressQuest */
	"brand new, all time lowest introductory rate special offer",
	"dirty rag"
};

const char *
get_bogus_item_name()
{
	return bogus_items[rn2(SIZE(bogus_items))];
}

static const char * const bogus_classes[] = {
	/* copy of objexplain from drawing.c */
	"strange object",
	"weapon",
	"suit or piece of armor",
	"ring",
	"amulet",
	"useful item (pick-axe, key, lamp...)",
	"piece of food",
	"potion",
	"scroll",
	"spellbook",
	"wand",
	"pile of coins",
	"gem or rock",
	"boulder or statue",
	"iron ball",
	"iron chain",
	"splash of venom",
	/* bogus classes */
	"illegal object",
	"filler",
	"useless object",
	"artifact",
	"ancient artifact",
	"ascension kit item",
	"stave",
	"song",
	"drink",
	"grimoire",
	"gear",
	"cog",
	"bug", 
	"easter egg",
	"tiny monument",
	"junk",
	"foo",
	"spoiler",
	"explosion",
	"MacGuffin",
	"galaxy",
	"quasar",
	"black hole",
	"soul jar",
	"lame joke",
	"artifact of doom",
	"something",
};

const char *
get_bogus_class_name()
{
	return bogus_classes[rn2(SIZE(bogus_classes))];
}

static const char *bogus_bottle_names[] = {
	"jug", "pitcher", "bucket", "thermos", "amphora", "barrel", "ampoule"
};

const char *
get_bogus_bottle_name()
{
	return bogus_bottle_names[rn2(SIZE(bogus_bottle_names))];
}

static const char * const bogus_colors[] = {
	"ultraviolet", "infrared", "bluish-orange",
	"reddish-green", "dark white", "light black", "sky blue-pink",
	"salty", "sweet", "sour", "bitter", "umami",
	"striped", "spiral", "swirly", "plaid", "checkered", "argyle",
	"paisley", "blotchy", "guernsey-spotted", "polka-dotted",
	"square", "round", "triangular",
	"cabernet", "sangria", "fuchsia", "wisteria",
	"lemon-lime", "strawberry-banana", "peppermint",
	"romantic", "incandescent"
};

const char *
get_bogus_color_name()
{
	return bogus_colors[rn2(SIZE(bogus_colors))];
}

static const char * const bogus_sounds[] = {
	"beep", "boing", "sing", "belche", "creak", "cough", "rattle",
	"ululate", "pop", "jingle", "sniffle", "tinkle", "eep",
	"clatter", "hum", "sizzle", "twitter", "wheeze", "rustle",
	"honk", "lisp", "yodel", "coo", "burp", "moo", "boom",
	"murmur", "oink", "quack", "rumble", "twang", "bellow",
	"toot", "gargle", "hoot", "warble"
};

const char *
get_bogus_sound()
{
	return bogus_sounds[rn2(SIZE(bogus_sounds))];
}

static const char* bogus_god_names[] = {
	"Svetovid", /* Slavic deity */
	"Radegast", /* Slavic deity */
	"Kupala", /* Slavic deity */
	"Dziewanna", /* Slavic deity (unclear status, maybe made up by Jan Długosz) */
	"Weles", /* Slavic deity */
	"Żywie", /* Slavic deity */
	"Zeus", /* Greek mythology */
	"Aphrodite", /* Greek mythology */
	"Ares", /* Greek mythology */
	"Atropos", /* Greek mythology */
	"Eris", /* Greek mythology */
	"Helios", /* Greek mythology */
	"the Invisible Pink Unicorn",
	"the Flying Spaghetti Monster", /* Church of the FSM */
	"the Martians", /* every science fiction ever */
	"Xom", /* Crawl */
	"AnDoR dRaKoN", /* ADOM */
	"the Central Bank of Yendor", /* economics */
	"Tooth Fairy", /* real world(?) */
	"Om", /* Discworld */
	"Yawgmoth", /* Magic: the Gathering */
	"Morgoth", /* Silmarilion */
	"Ulmo", /* Silmarilion */
	"Mandos", /* Silmarilion */
	"Tulkas", /* Silmarilion */
	"Yavanna", /* Silmarilion */
	"Varda", /* Silmarilion */
	"Cthulhu", /* Lovecraft */
	"the Ori", /* Stargate */
	"destiny", /* why not? */
	"the Doctor", /* Doctor Who */
	"Aslan", /* Narnia */
	"Tash", /* Narnia */
	"Emperor of Mankind", /* Warhammer 40K */
	"Nurgle", /* Warhammer 40K */
	"Slaanesh", /* Warhammer 40K */
	"Armok", /* Dwarf Fortress */
	"the Iron General", /* Jacek Dukaj */
	"the RNG",
	"the gnome with the wand of death",
	"bhaak",
	"Bulwersator",
};

/* select a random god based on role if provided */
const char *
get_bogus_god_name(int role)
{
	const char *gnam;
	int which;

	/* select random role if valid role not supplied */
	which = (validrole(role)) ? role : randrole();
	int choice = rn2(12);
	switch (choice) {
		case 0:	gnam = roles[which].lgod; break;
		case 1:	gnam = roles[which].ngod; break;
		case 2:	gnam = roles[which].cgod; break;
		case 3:	gnam = "Moloch"; break;
		default:	gnam = bogus_god_names[rn2(SIZE(bogus_god_names))]; break;
	}
	if (!gnam) {
		//for example priests have no predefined names in roles array
		gnam = "Moloch";
	}
	if (*gnam == '_') { /* God names use a leading underscore to flag goddesses, see role.c */
		++gnam;
	}
	return gnam;
}