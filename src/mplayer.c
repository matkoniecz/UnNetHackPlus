/*	SCCS Id: @(#)mplayer.c	3.4	1997/02/04	*/
/*	Copyright (c) Izchak Miller, 1992.			  */
/* NetHack may be freely redistributed.  See license for details. */

#include "hack.h"

STATIC_DCL const char *NDECL(dev_name);
STATIC_DCL void FDECL(get_mplname, (struct monst *, char *));
STATIC_DCL void FDECL(mk_mplayer_armor, (struct monst *, SHORT_P));

/* These are the names of those who
 * contributed to the development of NetHack 3.2/3.3/3.4.
 *
 * Keep in alphabetical order within teams.
 * Same first name is entered once within each team.
 */
static const char *developers[] = {
	/* devteam */
	"Dave", "Dean", "Eric", "Izchak", "Janet", "Jessie",
	"Ken", "Kevin", "Michael", "Mike", "Pat", "Paul", "Steve", "Timo",
	"Warwick",
	/* PC team */
	"Bill", "Eric", "Keizo", "Ken", "Kevin", "Michael", "Mike", "Paul",
	"Stephen", "Steve", "Timo", "Yitzhak",
	/* Amiga team */
	"Andy", "Gregg", "Janne", "Keni", "Mike", "Olaf", "Richard",
	/* Mac team */
	"Andy", "Chris", "Dean", "Jon", "Jonathan", "Kevin", "Wang",
	/* Atari team */
	"Eric", "Marvin", "Warwick",
	/* NT team */
	"Alex", "Dion", "Michael",
	/* OS/2 team */
	"Helge", "Ron", "Timo",
	/* VMS team */
	"Joshua", "Pat",
	/* UnNetHack */
	"Patric",
	/* SporkHack */
	"Derek",
	/* GruntHack */
	"Grunt",
	/* dNetHack */
	"Chris",
	/* patches included in UnNetHackPlus ("L" - Leon Arnott) */
	"Leon",
	""};


/* return a randomly chosen developer name */
STATIC_OVL const char *
dev_name()
{
	register int i, m = 0, n = SIZE(developers);
	register struct monst *mtmp;
	register boolean match;

	do {
	    match = FALSE;
	    i = rn2(n);
	    for (mtmp = fmon; mtmp; mtmp = mtmp->nmon) {
		if(!is_mplayer(mtmp->data)) continue;
		if(!strncmp(developers[i], NAME(mtmp),
			               strlen(developers[i]))) {
		    match = TRUE;
		    break;
	        }
	    }
	    m++;
	} while (match && m < 100); /* m for insurance */

	if (match) return (const char *)0;
	return(developers[i]);
}

STATIC_OVL void
get_mplname(mtmp, nam)
register struct monst *mtmp;
char *nam;
{
	boolean fmlkind = is_female(mtmp->data);
	const char *devnam;

	devnam = dev_name();
	if (!devnam)
	    Strcpy(nam, fmlkind ? "Eve" : "Adam");
	else if (fmlkind && !!strcmp(devnam, "Janet"))
	    Strcpy(nam, rn2(2) ? "Maud" : "Eve");
	else Strcpy(nam, devnam);

	if (fmlkind || !strcmp(nam, "Janet"))
	    mtmp->female = 1;
	else
	    mtmp->female = 0;
	Strcat(nam, " the ");
	Strcat(nam, rank_of((int)mtmp->m_lev,
			    monsndx(mtmp->data),
			    (boolean)mtmp->female));
}

/* return a randomly generated gnome name */
const char *
gnome_name(size_t id, boolean female)
{
	static char buf[30];
	/* gnome name fragments courtesy of http://www.rabbly.net/gnominomicon/namegenerator.html */

	static const char *female_name1[] = {
		"Au", "Be", "Bi", "E", "Ge", "Hali", "Kali", "Ke", "Ki", "Lo", "Lori", "Mara", "Mi", "Mira", "Nara", "Ne", "Nori", "Po", "Ra", "Sa", "Sara", "Sora", "Ste", "Tara", "Ti", "To", "Tori", "Tre", "Tri", "Twi", "Ve", "Wi", "Ama", "Arca", "Beri", "Cami", "Cari", "Cheri", "Emma", "Gina", "Jenna", "Jemma", "Jeri", "Jessa", "Kessa", "Lana", "Lara", "Liba", "Lina", "Lisa", "Liza", "Nena", "Nina", "Mari", "Meri", "Mina", "Teri", "Tina", "Sara", "Shara",
	};
	static const char *female_name2[] = {
		"cki", "ckle", "cky", "dget", "dgit", "ffit", "ffle", "fty", "kka", "lbi", "lby", "lena", "lie", "lli", "lly", "mble", "mma", "mmy", "msy", "ndi", "ndle", "ndy", "nky", "nna", "nnie", "nny", "nsy", "pple", "xie", "xy", "zzle", "belle", "beth", "bink", "bit", "bonk", "bolt", "bolt", "dette", "ka", "la", "lani", "lena", "lia", "lie", "line", "lissa", "ly", "lyn", "nella", "nora", "tink",
	};
	static const char *male_name1[] = {
		"Be", "Bi", "Bo", "Fi", "Ge", "Gi", "Gra", "Ha", "Ja", "Ki", "Lu", "Ma", "Me", "Mi", "Mo", "Ni", "Pe", "Ru", "Sti", "Ti", "To", "Wi", "Za", "Zi", "Amp", "Arc", "Bolt", "El", "Fil", "Fitz", "Fiz", "Flick", "Gil", "Cog", "Gear", "Giz", "Lug", "Mel", "Mod", "Spark", "Sprock", "Tek", "Tog", "Whit", "Wil", "Wiz", "Zap", "Zed", "Zim", "Zod",
	};
	static const char *male_name2[] = {
		"bble", "bert", "bius", "bus", "by", "cco", "ck", "cken", "ckin", "drick", "dwig", "fford", "gli", "gon", "gus", "lbert", "lbin", "lfin", "lius", "lton", "lvin", "mble", "ngle", "njy", "nkus", "nston", "nthony", "nton", "rkle", "shley", "xim", "xwell", "zzo", "bert", "dale", "ford", "holm", "kin", "man", "more", "mort", "nik", "ridge", "smith", "son", "stein", "strom", "ton", "well", "wick", "witz", "wood", "worth", "wright",
	};
	if(female) {
		snprintf(buf, 30, "%s%s",
			female_name1[id % SIZE(female_name1)],
			female_name2[id % SIZE(female_name2)]);
	} else {
		snprintf(buf, 30, "%s%s",
			male_name1[id % SIZE(male_name1)],
			male_name2[id % SIZE(male_name2)]);
	}
	return buf;
}

/* return a randomly generated fairy name */
const char *
fairy_name(size_t id, boolean female)
{
	if (!female) {
		warning("male fairy name requested, female one will be produced");
	}
	static char buf[30];
	/* fairy name fragments courtesy of http://fantasynamegenerators.com */
	static const char *fairy_name[] = {
		"Abigail", "Acorn", "Alexa", "Alexia", "Ali", "Alina", "Amber", "Amethyst", "Amy", "Anastasia", "Apricot", "April", "Aria", "Arianna", "Ashley", "Autumn", "Barbara", "Bayberry", "Bellflower", "Bethany", "Betsy", "Betty", "Bim", "Bonnie", "Breezy", "Buttercup", "Camellia", "Camille", "Carnation", "Carrie", "Carrot", "Cecile", "Celeste", "Charity", "Charlotte", "Chestnut", "Chickadee", "Chipmunk", "Chloe", "Chocolate", "Cinnamon", "Clover", "Cobweb", "Coconut", "Coriander", "Cornflower", "Crabapple", "Cranberry", "Cricket", "Crystal", "Cupcake", "Cypress", "Daffodil", "Dahlia", "Daisy", "Dalila", "Dandelion", "Daphne", "Dawn", "Daybreak", "Daylily", "Dew", "Dewdrop", "Ebony", "Echo", "Ella", "Elma", "Elva", "Emerald", "Emily", "Emma", "Eve", "Faith", "Fantasia", "Fauna", "Faye", "Fern", "Fiery", "Flax", "Flix", "Flora", "Foxglove", "Frances", "Gardenia", "Ginger", "Ginkgo", "Gloria", "Gloriosa", "Grace", "Happy", "Harmony", "Hazel", "Heather", "Heidi", "Helen", "Hickoy", "Holly", "Honey", "Hope", "Hurricane", "Hyacinth", "Indigo", "Infinity", "Iris", "Isabel", "Isabelle", "Ivy", "Jade", "Jamie", "Jayla", "Jeanie", "Jenny", "Jessamine", "Jillian", "Joy", "Julie", "June", "Juniper", "Karina", "Karma", "Kate", "Kelly", "Kenzie", "Kiki", "Kiwi", "Kobi", "Koko", "Kylee", "Kyra", "Labyrinth", "Lala", "Lark", "Laurel", "Lauren", "Lavender", "Layla", "Leeta", "Lemony", "Lenora", "Libby", "Lila", "Lilac", "Lily", "Liri", "Little", "Lizzy", "Lorella", "Lori", "Lucia", "Lucky", "Lucy", "Lulu", "Luna", "Lynn", "Maddie", "Magenta", "Magnola", "Magpie", "Mahogany", "Margo", "Marigold", "Mary", "May", "Melanie", "Melody", "Mia", "Milkweed", "Minerva", "Miranda", "Misty", "Moptop", "Mudpie", "Mulberry", "Muriel", "Nectarine", "Newt", "Nightfall", "Nightshade", "Nissa", "Nora", "Nutmeg", "Nyra", "Octavia", "Olive", "Olivia", "Onyx", "Opal", "Orchid", "Oregano", "Oriole", "Pandora", "Paprika", "Parsley", "Patchwork", "Peachy", "Peanut", "Pearl", "Pecan", "Penelope", "Persimmon", "Petunia", "Phoebe", "Pineapple", "Pistachio", "Pluma", "Poplar", "Posy", "Primrose", "Prinna", "Prudence", "Pumpkin", "Quicksilver", "Quinn", "Rachel", "Raven", "Rhodie", "Rhonda", "Rhubarb", "Rill", "River", "Robin", "Rosa", "Rose", "Rosemary", "Ruby", "Saffron", "Sahara", "Sally", "Sapphire", "Sassafras", "Savannah", "Scarlet", "Seaweed", "Serena", "Serendipity", "Shanna", "Shelly", "Sienna", "Silver", "Sky", "Sklyer", "Sneezy", "Snowflake", "Sophie", "Sprinkles", "Stargazer", "Stella", "Stormy", "Strawberry", "Sundew", "Sunflower", "Sunrise", "Sunset", "Sunshine", "Tamara", "Tangy", "Tansy", "Tessa", "Tiger", "Tiny", "Toadstool", "Topaz", "Tori", "Trinity", "Tulip", "Turnip", "Twilight", "Tyra", "Valorie", "Vanessa", "Vickie", "Victoria", "Violet", "Wallflower", "Walnut", "Windy", "Winnie", "Wispa", "Xenops", "Yasmine", "Zephyr", "Alaneo", "Avo", "Aphid", "Azalea", "Blaze", "Bud", "Camelia", "Cacti", "Calla", "Carpus", "Cassia", "Creeper", "Flora", "Frangi", "Gerania", "Gerbera", "Grevillea", "Hazel", "Herb", "Hibiscus", "Holly", "Hollyhock", "Honey", "Hydrangea", "Ivy", "Jasmine", "Labivia", "Lantana", "Lilac", "Liatris", "Lichen", "Mango", "Morel", "Mossy", "Nastur", "Plumeria", "Rose", "Oleander", "Olive", "Olivia", "Rebutia", "Rhoda", "Spore", "Sulcore", "Strombo", "Tansy", "Thistle", "Tiger", "Topiary", "Trumpet", "Willow", "Yavia", "Yucca", "Alexandra", "Amber", "Amethyst", "Berline", "Beryl", "Cadmi", "Carnelia", "Chert", "Chlora", "Cintrine", "Crystal", "Diaspor", "Emerald", "Floura", "Garnet", "Gypsum", "Heliodor", "Indigo", "Iridia", "Jade", "Lapis", "Lazuli", "Manga", "Pyro", "Ruby", "Sapphire", "Selenia", "Selene", "Thallia", "Tourmaline", "Yitri", "Abyss", "Adriata", "Albedo", "Amode", "Anemone", "Aqua", "Azore", "Coral", "Cowrie", "Ebbie", "Gullie", "Ionia", "Ivory", "Marin", "Meer", "Meri", "Mora", "Nautila", "Oceana", "Pearl", "Percula", "Sandy", "Shelly", "Starfish", "Tidal", "Urchin", "Wave", "Whirl", "Wrassey", "Aed", "Aodh", "Aeden", "Ash", "Ashley", "Blaze", "Candala", "Coala", "Firo", "Flare", "Flamo", "Feu", "Ignea", "Igni", "Plume", "Pyro", "Smokey", "Spark", "Sparkla", "Albedo", "Angel", "Apogee", "Astro", "Aurora", "Aloha", "Axis", "Bumble", "Chaldera", "Chasma", "Celestia", "Cirrus", "Cirro", "Corona", "Cosmo", "Crator", "Galaxa", "Luna", "Misty", "Raine", "Strata", "Helio", "Helia", "Lumiona", "Magna", "Meridian", "Mercury", "Nebula", "Nimbus", "Novus", "Scorpia", "Solara", "Soleil", "Spectra", "Spirala", "Stella", "Star", "Velocity", "Venus", "Poppy", "Ash", "Lake", "River", "Peach", "April", "Winter", "Snow", "Amantha", "Amaryllis", "Acacia", "Anemone", "Asphodel", "Aven", "Ayanna", "Begonia", "Blanchefleur", "Blathnat", "Blodwedd", "Blodwen", "Blossom", "Bluebell", "Allium", "Alstroemeria", "Anthurium", "Apple", "Cherry", "Dragonfly", "Ruby", "Diamond", "Opal", "Topaz", "Christal", "Jewel", "Gem", "Emerald", "Ivy", "Strawberri", "Paprika", "Basil", "Poison", "Pepper", "Spice", "Hollyann", "Alyssum", "Camellia", "Clover", "Daffodil", "Dahlia", "Fern", "Forsythia", "Freesia", "Gardenia", "Hyacinth", "Iris", "Jessamine", "Magnolia", "Marigold", "Pansy", "Posey", "Primrose", "Sunflower", "Tansy", "Tulip", "Acacia", "Aspen", "Cypress", "Juniper", "Maple", "Sequoia", "Timber", "Cayenne", "Caraway", "Cinnamon", "Saffron", "Apple", "Berry", "Bramble", "Breeze", "Briar", "Briny", "Cloud", "Cricket", "Dew", "East", "Echo", "Ember", "Evening", "Galaxy", "Heaven", "Island", "Isle", "Lake", "Lark", "Light", "Lighting", "Meadow", "Midnight", "Moon", "Moonbeam", "Moonlight", "Nature", "Ocean", "Prairie", "Rain", "Rainbow", "Sea", "Sky", "Skylark", "South", "Spring", "Star", "Sunlight", "Sunrise", "Sunset", "Sunshine", "Swan", "Tempest", "Twilight", "Waterfall", "Wind", "Winter", "Wren", "Tinkerbell", "Snow", "Snowflake", "Sprinkle", "Cookie", "Honey", "Sugar", "Sun", "Sunny", "Ash", "Birch", "Cedar", "Elm", "Grove", "Jarrah", "Leaf", "Oak", "Pine", "Poplar", "Shade", "Spruce", "Tinder", "Woods", "Basil", "Citron", "Sage", "Sorrell", "Tarragon", "Almond", "Badger", "Barley", "Bear", "Bracken", "Breeze", "Canyon", "Chestnut", "Coal", "Comet", "Condor", "Cougar", "Coyote", "Drake", "Dune", "Dusk", "Eagle", "Field", "Finch", "Flame", "Flint", "Fox", "Frost", "Harbor", "Horizon", "Lake", "Mountain", "North", "Planet", "Reef", "Ridge", "River", "Rock", "Star", "Stone", "Storm", "Thicket", "Thunder", "Tiger", "West", "Wolf", "Amethyst", "Marcasite", "Peridot", "Onyx", "Thistle",
	};
	static const char *fairy_surname1[] = {
		"Air", "Almond", "Apple", "Aspen", "Beauty", "Better", "Bitter", "Bright", "Broom", "Bubble", "Bumble", "Candle", "Carrot", "Cedar", "Chilly", "Citrus", "Cloud", "Cloudy", "Cocoa", "Copper", "Cotton", "Cozy", "Cricket", "Crystal", "Cute", "Daisy", "Dapple", "Day", "Dazzle", "Diamond", "Dimple", "Drift", "Elm", "Evening", "Fancy", "Fern", "Fig", "Fire", "Flatter", "Flicker", "Flirty", "Flutter", "Foggy", "Fox", "Frost", "Frosty", "Frozen", "Funny", "Garlic", "Giggle", "Glitter", "Grassy", "Green", "Holly", "Ice", "Island", "Isle", "Jelly", "Jumpy", "Jester", "Jingle", "Lemon", "Light", "Lightning", "Lime", "Little", "Lotus", "Lovely", "Magic", "Mango", "Maple", "Merry", "Misty", "Moon", "Morning", "Moss", "Mossy", "Mountain", "Muddy", "Never", "Night", "Oak", "Olive", "Orange", "Parsley", "Peach", "Pear", "Pepper", "Pine", "Plum", "Pollen", "Pretty", "Pumpkin", "Purple", "Quick", "Rain", "Rainbow", "Rainy", "Rose", "Rumple", "Sandy", "Sea", "Shiny", "Silk", "Snow", "Sour", "Sparkle", "Speedy", "Spider", "Star", "Sugar", "Sun", "Sweet", "Swift", "Tangle", "Thunder", "Tulip", "Tumble", "Twinkle", "Twisty", "Vanilla", "Water", "Whiffle", "Wild", "Windy", "Winter", "Wonder", "Wrinkle", "Yarrow",
	};
	static const char *fairy_surname2[] = {
		"bead", "beam", "bee", "bees", "bell", "belle", "berry", "bloom", "blossom", "boots", "breath", "breeze", "bug", "butter", "button", "cliff", "cloud", "clove", "cup", "curl", "dance", "dash", "dew", "drop", "dust", "feather", "field", "fig", "flame", "flash", "fleck", "flight", "flip", "flower", "fluff", "fly", "foam", "fog", "foot", "forest", "freeze", "fur", "feet", "foot", "fruit", "garden", "gem", "glade", "glimmer", "glow", "gourd", "grace", "grass", "griddle", "gust", "heart", "hop", "horn", "jewel", "lace", "lake", "lashes", "leaf", "lily", "locks", "loop", "meadow", "mello", "mint", "mist", "moon", "muddle", "muse", "newt", "noodles", "pearl", "pebbles", "petal", "plume", "pond", "pool", "puff", "ray", "ripple", "river", "root", "sage", "sand", "shadow", "shimmer", "shine", "sky", "socks", "song", "spark", "sparkle", "speck", "spirit", "splash", "spring", "sprite", "sprout", "stem", "stone", "storm", "stream", "stripe", "swamp", "swirls", "thistle", "thorn", "toad", "toes", "tree", "twill", "twinkle", "twirl", "twirls", "twist", "vale", "valley", "vine", "wax", "weather", "web", "whirl", "whisk", "whisper", "willow", "wind", "wing", "wings", "wink", "wish",
	};
	snprintf(buf, 30, "%s %s%s",
		fairy_name[id % SIZE(fairy_name)],
		fairy_surname1[id % SIZE(fairy_surname1)],
		fairy_surname2[id % SIZE(fairy_surname2)]);

	return buf;
}


/* return a randomly generated orc name */
const char *
orc_name(size_t id, boolean female)
{
	static char buf[30];
	/* orc name fragments courtesy of http://fantasynamegenerators.com */
	static const char *male_orc_name[] = {
		"Abghat", "Adgulg", "Aghed", "Agugh", "Aguk", "Almthu", "Alog", "Ambilge", "Apaugh", "Argha", "Argigoth", "Argug", "Arpigig", "Auhgan", "Azhug", "Bagdud", "Baghig", "Bahgigoth", "Bandagh", "Barfu", "Bargulg", "Baugh", "Bidgug", "Bildud", "Bilge", "Bog", "Boghat", "Bogugh", "Borgan", "Borug", "Braugh", "Brougha", "Brugagh", "Bruigig", "Buadagh", "Buggug", "Builge", "Buimghig", "Bulgan", "Bumhug", "Buomaugh", "Buordud", "Burghed", "Buugug", "Cabugbu", "Cagan", "Carguk", "Carthurg", "Clog", "Corgak", "Crothu", "Cubub", "Cukgilug", "Curbag", "Dabub", "Dakgorim", "Dakgu", "Dalthu", "Darfu", "Deakgu", "Dergu", "Derthag", "Digdug", "Diggu", "Dilug", "Ditgurat", "Dorgarag", "Dregu", "Dretkag", "Drigka", "Drikdarok", "Drutha", "Dudagog", "Dugarod", "Dugorim", "Duiltag", "Durbag", "Eagungad", "Eggha", "Eggugat", "Egharod", "Eghuglat", "Eichelberbog", "Ekganit", "Epkagut", "Ergoth", "Ertguth", "Ewkbanok", "Fagdud", "Faghig", "Fandagh", "Farfu", "Farghed", "Fargigoth", "Farod", "Faugh", "Feldgulg", "Fidgug", "Filge", "Fodagog", "Fogugh", "Fozhug", "Frikug", "Frug", "Frukag", "Fubdagog", "Fudhagh", "Fupgugh", "Furbog", "Futgarek", "Gaakt", "Garekk", "Gelub", "Gholug", "Gilaktug", "Ginug", "Gnabadug", "Gnadug", "Gnalurg", "Gnarg", "Gnarlug", "Gnorl", "Gnorth", "Gnoth", "Gnurl", "Golag", "Golub", "Gomatug", "Gomoku", "Gorgu", "Gorlag", "Grikug", "Grug", "Grukag", "Grukk", "Grung", "Gruul", "Guag", "Gubdagog", "Gudhagh", "Gug", "Gujarek", "Gujek", "Gujjab", "Gulm", "Gulrn", "Gunaakt", "Gunag", "Gunug", "Gurukk", "Guthakug", "Guthug", "Gutjja", "Hagob", "Hagu", "Hagub", "Haguk", "Hebub", "Hegug", "Hibub", "Hig", "Hogug", "Hoknath", "Hoknuk", "Hokulk", "Holkurg", "Horknuth", "Hrolkug", "Hugagug", "Hugmug", "Hugolm", "Ig", "Igmut", "Ignatz", "Ignorg", "Igubat", "Igug", "Igurg", "Ikgnath", "Ikkath", "Inkathu", "Inkathurg", "Isagubat", "Jogug", "Jokgagu", "Jolagh", "Jorgagu", "Jregh", "Jreghug", "Jugag", "Jughog", "Jughragh", "Jukha", "Jukkhag", "Julakgh", "Kabugbu", "Kagan", "Kaghed", "Kahigig", "Karfu", "Karguk", "Karrghed", "Karrhig", "Karthurg", "Kebub", "Kegigoth", "Kegth", "Kerghug", "Kertug", "Kilug", "Klapdud", "Klog", "Klughig", "Knagh", "Knaraugh", "Knodagh", "Knorgh", "Knuguk", "Knurigig", "Kodagog", "Kog", "Kogan", "Komarod", "Korgak", "Korgulg", "Koughat", "Kraugug", "Krilge", "Krothu", "Krouthu", "Krugbu", "Krugorim", "Kubub", "Kugbu", "Kukgilug", "Kulgha", "Kupgugh", "Kurbag", "Kurmbag", "Laghed", "Lamgugh", "Mabub", "Magdud", "Malthu", "Marfu", "Margulg", "Mazhug", "Meakgu", "Mergigoth", "Milug", "Mudagog", "Mugarod", "Mughragh", "Mugorim", "Murbag", "Naghat", "Naghig", "Naguk", "Nahgigoth", "Nakgu", "Narfu", "Nargulg", "Narhbub", "Narod", "Neghed", "Nehrakgu", "Nildud", "Nodagog", "Nofhug", "Nogugh", "Nomgulg", "Noogugh", "Nugbu", "Nughilug", "Nulgha", "Numhug", "Nurbag", "Nurghed", "Oagungad", "Oakgu", "Obghat", "Oggha", "Oggugat", "Ogharod", "Oghuglat", "Oguk", "Ohomdud", "Ohulhug", "Oilug", "Okganit", "Olaghig", "Olaugh", "Olmthu", "Olodagh", "Olog", "Omaghed", "Ombilge", "Omegugh", "Omogulg", "Omugug", "Onog", "Onubub", "Onugug", "Oodagh", "Oogorim", "Oogugbu", "Oomigig", "Opathu", "Opaugh", "Opeghat", "Opilge", "Opkagut", "Opoguk", "Oquagan", "Orgha", "Orgoth", "Orgug", "Orpigig", "Ortguth", "Otugbu", "Ougha", "Ougigoth", "Ouhgan", "Owkbanok", "Paghorim", "Pahgigoth", "Pahgorim", "Pakgu", "Parfu", "Pargu", "Parhbub", "Parod", "Peghed", "Pehrakgu", "Pergu", "Perthag", "Pigdug", "Piggu", "Pitgurat", "Podagog", "Pofhug", "Pomgulg", "Poogugh", "Porgarag", "Pregu", "Pretkag", "Prigka", "Prikdarok", "Prutha", "Pughilug", "Puiltag", "Purbag", "Qog", "Quadagh", "Quilge", "Quimghig", "Quomaugh", "Quordud", "Quugug", "Raghat", "Raguk", "Rakgu", "Rarfu", "Rebub", "Rilug", "Rodagog", "Rogan", "Romarod", "Routhu", "Rugbu", "Rugorim", "Rurbag", "Rurigig", "Sabub", "Saghig", "Sahgigoth", "Sahgorim", "Sakgu", "Salthu", "Saraugug", "Sarfu", "Sargulg", "Sarhbub", "Sarod", "Sbghat", "Seakgu", "Sguk", "Shomdud", "Shulhug", "Sildud", "Silge", "Silug", "Sinsbog", "Slaghig", "Slapdud", "Slaugh", "Slodagh", "Slog", "Slughig", "Smaghed", "Smegugh", "Smogulg", "Snog", "Snubub", "Snugug", "Sodagh", "Sog", "Sogorim", "Sogugbu", "Sogugh", "Sombilge", "Somigig", "Sonagh", "Sorgulg", "Sornaraugh", "Soughat", "Spathu", "Speghat", "Spilge", "Spoguk", "Squagan", "Stugbu", "Sudagog", "Sugarod", "Sugbu", "Sugha", "Sugigoth", "Sugorim", "Suhgan", "Sulgha", "Sulmthu", "Sumhug", "Sunodagh", "Sunuguk", "Supaugh", "Supgugh", "Surbag", "Surgha", "Surghed", "Surgug", "Surpigig", "Tagdud", "Taghig", "Tandagh", "Tarfu", "Targhed", "Targigoth", "Tarod", "Taugh", "Teldgulg", "Tidgug", "Tilge", "Todagog", "Tog", "Toghat", "Togugh", "Torgan", "Torug", "Tozhug", "Traugh", "Trilug", "Trougha", "Trugagh", "Truigig", "Tuggug", "Tulgan", "Turbag", "Turge", "Ug", "Ugghra", "Uggug", "Ughat", "Ulgan", "Ulmragha", "Ulmrougha", "Umhra", "Umragig", "Umruigig", "Ungagh", "Unrugagh", "Urag", "Uraugh", "Urg", "Urgan", "Urghat", "Urgran", "Urlgan", "Urmug", "Urug", "Urulg", "Vabugbu", "Vagan", "Vagrungad", "Vagungad", "Vakgar", "Vakgu", "Vakmu", "Valthurg", "Vambag", "Vamugbu", "Varbu", "Varbuk", "Varfu", "Vargan", "Varguk", "Varkgorim", "Varthurg", "Vegum", "Vergu", "Verlgu", "Verthag", "Verthurg", "Vetorkag", "Vidarok", "Vigdolg", "Vigdug", "Viggu", "Viggulm", "Viguka", "Vitgurat", "Vitgut", "Vlog", "Vlorg", "Vorgak", "Vorgarag", "Vothug", "Vregu", "Vretkag", "Vrigka", "Vrikdarok", "Vrogak", "Vrograg", "Vrothu", "Vruhag", "Vrutha", "Vubub", "Vugub", "Vuiltag", "Vukgilug", "Vultog", "Vulug", "Vurbag", "Wakgut", "Wanug", "Wapkagut", "Waruk", "Wauktug", "Wegub", "Welub", "Wholug", "Wilaktug", "Wingloug", "Winug", "Woabadug", "Woggha", "Woggugat", "Wogharod", "Woghuglat", "Woglug", "Wokganit", "Womkug", "Womrikug", "Wonabadug", "Worthag", "Wraog", "Wrug", "Wrukag", "Wrukaog", "Wubdagog", "Wudgh", "Wudhagh", "Wudugog", "Wuglat", "Wumanok", "Wumkbanok", "Wurgoth", "Wurmha", "Wurtguth", "Wurthu", "Wutgarek", "Xaakt", "Xago", "Xagok", "Xagu", "Xaguk", "Xarlug", "Xarpug", "Xegug", "Xepug", "Xig", "Xnath", "Xnaurl", "Xnurl", "Xoknath", "Xokuk", "Xolag", "Xolkug", "Xomath", "Xomkug", "Xomoku", "Xonoth", "Xorag", "Xorakk", "Xoroku", "Xoruk", "Xothkug", "Xruul", "Xuag", "Xug", "Xugaa", "Xugag", "Xugagug", "Xugar", "Xugarf", "Xugha", "Xugor", "Xugug", "Xujarek", "Xuk", "Xulgag", "Xunaakt", "Xunag", "Xunug", "Xurek", "Xurl", "Xurug", "Xurukk", "Xutag", "Xuthakug", "Xutjja", "Yaghed", "Yagnar", "Yagnatz", "Yahg", "Yahigig", "Yakgnath", "Yakha", "Yalakgh", "Yargug", "Yegigoth", "Yegoth", "Yerghug", "Yerug", "Ymafubag", "Yokgagu", "Yokgu", "Yolmar", "Yonkathu", "Yregh", "Yroh", "Ysagubar", "Yughragh", "Yugug", "Yukgnath", "Yukha", "Yulakgh", "Yunkathu", "Zabghat", "Zabub", "Zaghig", "Zahgigoth", "Zahgorim", "Zalthu", "Zaraugug", "Zarfu", "Zargulg", "Zarhbub", "Zarod", "Zeakgu", "Zguk", "Zildud", "Zilge", "Zilug", "Zinsbog", "Zlapdud", "Zlog", "Zlughig", "Zodagh", "Zog", "Zogugbu", "Zogugh", "Zombilge", "Zonagh", "Zorfu", "Zorgulg", "Zorhgigoth", "Zornaraugh", "Zoughat", "Zudagog", "Zugarod", "Zugbu", "Zugorim", "Zuhgan", "Zulgha", "Zulmthu", "Zumhug", "Zunodagh", "Zunuguk", "Zupaugh", "Zupgugh", "Zurbag", "Zurgha", "Zurghed", "Zurgug", "Zurpigig", "Atulg", "Azuk", "Bagamul", "Bakh", "Baronk", "Bashag", "Bazgulub", "Bogakh", "Borug", "Both", "Bugdul", "Bugharz", "Bugrash", "Bugrol", "Bumbub", "Burul", "Dul", "Dular", "Duluk", "Duma", "Dumbuk", "Dumburz", "Dur", "Durbul", "Durgash", "Durz", "Durzol", "Durzub", "Durzum", "Garothmuk", "Garzonk", "Gashna", "Ghamborz", "Ghamonk", "Ghoragdush", "Ghorlorz", "Glush", "Grat", "Guarg", "Gurak", "Khadba", "Khagra", "Khargol", "Koffutto", "Largakh", "Lorbumol", "Lorzub", "Lugdum", "Lugrub", "Lurog", "Mash", "Matuk", "Mauhul", "Mazorn", "Mol", "Morbash", "Mug", "Mugdul", "Muk", "Murag", "Murkub", "Murzol", "Muzgonk", "Nag", "Nar", "Nash", "Ogrul", "Ogrumbu", "Olfin", "Olumba", "Orakh", "Rogdul", "Shakh", "Shamar", "Shamob", "Shargam", "Sharkub", "Shat", "Shulong", "Shura", "Shurkul", "Shuzug", "Snaglak", "Snakha", "Snat", "Ugdumph", "Ughash", "Ulam", "Umug", "Uram", "Urim", "Urul", "Urzog", "Ushamph", "Yadba", "Yagak", "Yak", "Yam", "Yambagorn", "Yambul", "Yargol", "Yashnarz", "Yatur", "Agronak", "Bat", "Bazur", "Brugo", "Bogrum", "Brag", "Brokil", "Bugak", "Buramog", "Burz", "Dubok", "Dul", "Dulfish", "Dumag", "Dulphumph", "Gaturn", "Gogron", "Gorgo", "Graklak", "Graman", "Grommok", "Gul", "Hanz", "Krognak", "Kurdan", "Kurz", "Rugdumph", "Lum", "Lumdum", "Luronk", "Magra", "Magub", "Maknok", "Mug", "Orok", "Shagol", "Shagrol", "Shobob", "Shum", "Ulmug", "Urbul", "Urul", "Ushnar", "Uzul", "Arob", "Balogog", "Borkul", "Burguk", "Dushnamub", "Gat", "Ghamorz", "Ghorbash", "Gradba", "Grogmar", "Grushnag", "Gularzob", "Kharag", "Larek", "Lob", "Lurbuk", "Mahk", "Makhel", "Abbas", "Mauhulakh", "Moth", "Mul", "Mulush", "Nagrub", "Oglub", "Ogol", "Olur", "Ulag", "Umurn", "Urag", "Yamarz", "Yar",
	};
	static const char *female_orc_name[] = {
		"Agrob", "Badbog", "Bashuk", "Bogdub", "Bugdurash", "Bula", "Bulak", "Bulfim", "Bum", "Burzob", "Burub", "Dura", "Durgat", "Durz", "Gashnakh", "Ghob", "Glasha", "Glob", "Gluronk", "Gonk", "Grat", "Grazob", "Gulfim", "Kharzug", "Lagakh", "Lambug", "Lazgar", "Mogak", "Morn", "Murob", "Murzush", "Nargol", "Rolfish", "Orbul", "Ragash", "Rulfim", "Shadbak", "Shagar", "Shagdub", "Sharn", "Sharog", "Shazgob", "Shelur", "Uloth", "Ulumpha", "Urzoth", "Urzul", "Ushat", "Ushug", "Yazgash", "Batul", "Borba", "Bumph", "Homraz", "Rogbut", "Mazoga", "Mog", "Mor", "Oghash", "Rogmesh", "Snak", "Ugak", "Umog", "Arob", "Atub", "Bagrak", "Bolar", "Bor", "Borgakh", "Dulug", "Garakh", "Ghak", "Gharol", "Ghorza", "Gul", "Lash", "Murbol", "Sharamph", "Shel", "Shufharz", "Ugor", "Urog", "Yotul",
	};
	if(female) {
		snprintf(buf, 30, "%s",
			female_orc_name[id % SIZE(female_orc_name)]);
	} else {
		snprintf(buf, 30, "%s",
			male_orc_name[id % SIZE(male_orc_name)]);
	}
	return buf;
}

/* return a randomly generated troll name */
const char *
troll_name(size_t id, boolean female)
{
	static char buf[30];
	/* Troll name fragments courtesy of http://fantasynamegenerators.com */
	static const char *male_troll_name[] = {
		"Alwan", "Anje", "Azibo", "Ajin", "Ekon", "Erasto", "Haijen", "Hamedi", "Hokima", "Jaafan", "Jabir", "Jalai", "Javyn", "Jijel", "Juma", "Jumoke", "Kaijin", "Kazko", "Maalik", "Makas", "Malak", "Nyabingi", "Rahjin", "Rakash", "Rashi", "Razi", "Reji", "Rujabu", "Rujin", "Seji", "Senwe", "Seshi", "Teshi", "Tzane", "Tzuljin", "Voyambi", "Vuzashi", "Vuzembi", "Yamike", "Yavo", "Yawan", "Zaejin", "Zallah", "Zebajin", "Zelaji", "Zevrij", "Zinjo", "Zufem", "Alzim", "Ayagi", "Ayargajin", "Dorkuraz", "Hakalai", "Halasuwa", "Hokajin", "Hoodah", "Hyptu", "Jaryaya", "Jayunya", "Jinjin", "Jojin", "Kelraz", "Kuroji", "Lakjin", "Laojin", "Melkree", "Mezilkree", "Napokue", "Nuenvan", "Paikei", "Rapshider", "Rhazin", "Shaktilar", "Shengis", "Sligo", "Tanjin", "Tazingo", "Tedar", "Trezzahn", "Trolgar", "Ttarmek", "Ugoki", "Vekuzz", "Venjo", "Vulzal", "Wanjin", "Wonjin", "Xukundi", "Yetu", "Zengu", "Zoljin", "Zulabar", "Zulbaljin", "Zulgeteb", "Zulkaz", "Zulkis", "Zulrajas", "Zulyafi", "Zunabar",
	};
	static const char *female_troll_name[] = {
		"Ajia", "Aketa", "Altoa", "Aszea", "Atae", "Azra", "Ecia", "Ejie", "Eleja", "Esha", "Illa", "Kea", "Keja", "Kina", "Kiya", "Kizi", "Moza", "Oyana", "Raca", "Rasha", "Seshia", "Suja", "Suli", "Talisa", "Tasiya", "Tayo", "Teja", "Teza", "Tezzi", "Tizali", "Xia", "Yaci", "Yajdna", "Yashi", "Yera", "Yeree", "Yesha", "Yishi", "Zara", "Zashi", "Zea", "Zelea", "Zesa", "Zeti", "Zola", "Zoti", "Zujia", "Zyra", "Alunja", "Anji", "Arany", "Bajin", "Baliaja", "Benni", "Bie", "Boonoo", "Bunjin", "Csini", "Feylin", "Girisha", "Hailith", "Ithra", "Javilla", "Javinda", "Jezemalu", "Jinthaiya", "Jiranty", "Jozala", "Jubukraa", "Juljin", "Kanjin", "Katanja", "Katzine", "Khelynn", "Khijazi", "Khuwei", "Kululu", "Lujin", "Makali", "Mandula", "Meimei", "Melelea", "Nelina", "Prerrahar", "Pujati", "Rangi", "Renjai", "Renji", "Ronjaty", "Saedmara", "Saonji", "Segawa", "Senzala", "Shadrala", "Shakawatha", "Shaktila", "Shamra", "Sharimara", "Shubre", "Soniya", "Sonja", "Suliya", "Sulynn", "Titamor", "Tsaijo", "Usitutie", "Valja", "Vanjin", "Venmara", "Vinji", "Vinjin", "Vonjai", "Vujii", "Vulzala", "Watu", "Yuhai", "Zalma", "Zalmea", "Zenma", "Zhonya", "Zhoumai", "Ziataaman", "Ziataima", "Ziataja", "Ziatajie", "Ziatakraa", "Zonraja", "Zulja", "Zulja", "Zuljah", "Zuljin", "Zulkraa", "Zulmara", "Zulraja", "Zulrea", "Zulwatha",
	};
	if(female) {
		snprintf(buf, 30, "%s",
			female_troll_name[id % SIZE(female_troll_name)]);
	} else {
		snprintf(buf, 30, "%s",
			male_troll_name[id % SIZE(male_troll_name)]);
	}
	return buf;
}

/* return a randomly generated dragon name */
const char *
dragon_name(size_t id, boolean female)
{
	static char buf[30];
	/* Dragon name fragments courtesy of http://fantasynamegenerators.com */
	static const char *dragon_name[] = {
		"Baliarth", "Bassilth", "Bayorth", "Bazzalth", "Bedelth", "Benarth", "Bessonth", "Bevurth", "Birroth", "Bredolth", "Brynioth", "Cadreinth", "Camroth", "Carinth", "Carith", "Carolth", "Caydranth", "Cennuth", "Cenolth", "Cerioth", "Chelianth", "Chenth", "Cheselth", "Ciamath", "Cinolth", "Colrath", "Cordath", "Cordenth", "Corduth", "Corinth", "Culdranth", "Culdreth", "Daganth", "Dalbinth", "Dallarth", "Dammath", "Darilth", "Darlath", "Darmith", "Dazenth", "Deneth", "Dennenth", "Derolth", "Deventh", "Doranth", "Dulanth", "Emelth", "Feranth", "Ferreth", "Firroth", "Gavarenth", "Ginarth", "Heralth", "Herinth", "Honeth", "Inilth", "Inioth", "Iraneth", "Ith", "Jeruth", "Jevith", "Jevrath", "Jielarth", "Jielith", "Kaleth", "Kalinth", "Kalurth", "Kamirth", "Kayelinth", "Kayerith", "Kelarth", "Keleth", "Kelirth", "Kelorth", "Kementh", "Kemoth", "Kenith", "Kennioth", "Keselth", "Kevalth", "Kilarth", "Kimerth", "Kindralth", "Kisenth", "Kovinth", "Kyloth", "Leneth", "Lennalth", "Liorenth", "Lioth", "Lissoth", "Loganth", "Lusarth", "Lusolth", "Lyrroth", "Lyth", "Malirth", "Malliath", "Marganth", "Maylanth", "Medolth", "Medreth", "Mekarth", "Mersorth", "Mersoth", "Mesanth", "Mesarth", "Meseth", "Mesianth", "Messenth", "Mianth", "Miath", "Milenth", "Milorth", "Mirelth", "Mirroth", "Mirsoth", "Mnerolth", "Mneventh", "Morelth", "Morenth", "Mylanth", "Naloth", "Narolth", "Nelarth", "Nerroth", "Nesenth", "Nessonth", "Nevalth", "Nevith", "Nilanth", "Ninarth", "Niruth", "Norlanth", "Norruth", "Parath", "Parinath", "Peddrenth", "Perenth", "Perrath", "Porath", "Porrelth", "Quenth", "Quinarth", "Quoloth", "Ralarth", "Rallinth", "Rasenth", "Razeth", "Resalth", "Rhodrolth", "Rhosalth", "Rinnenth", "Roluth", "Ronnuth", "Rugarth", "Rumalth", "Rusorth", "Rylarth", "Ryluth", "Salanth", "Seddrinth", "Seralth", "Serelath", "Shalerth", "Shamilth", "Shevorth", "Shorolth", "Shuvirth", "Sirath", "Sivath", "Sonneth", "Soreth", "Sorrilth", "Sorth", "Sorventh", "Stevarth", "Sudreth", "Sunnulth", "Syralth", "Syrilth", "Syrreth", "Syrriolth", "Taenth", "Taevarth", "Talath", "Talurth", "Tamenth", "Tamolth", "Tanulth", "Tavorth", "Tavreth", "Tavrinth", "Tavurth", "Tebinth", "Teminth", "Tenelth", "Teovanth", "Tesselth", "Tessith", "Tezoth", "Tielenth", "Tiemeth", "Tiolth", "Tobalth", "Tuelonth", "Tuesirth", "Tyrath", "Vanlith", "Vellath", "Verath", "Verioth", "Vezoth", "Vinarth", "Visalth", "Vollenth", "Vorlianth", "Zerelth", "Zinnath", "Zoralth", "Jura", "Hirador", "Fundor", "Galzra", "Briam", "Ohen", "Gretiem", "Beroan", "Roslarb", "Saphira", "Raziel", "Daenerys", "Barioth", "Livjatan", "Lagiocrus", "Avrae", "Rhaegos", "Barroth", "Umbaroth", "Ohm", "Hudraer", "Nveryll", "Nveryioth", "Apophis", "Askook", "Ator", "Favnir", "Tulvir", "Franae", "Niadhogr",
	};
	static const char *dragon_title[] = {
		"the Dark One", "the Dark", "the Eternal", "the Firestarter", "the Eternal One", "the Calm", "the Gentle", "the Redeemer", "the Champion", "the Evil One", "the Chosen", "the Great", "the Kind", "the Fierce", "the Strong", "the Tiran", "the Dragonlord", "the Warrior", "the Barbarian", "the Tall", "the Magnificent", "the Clean", "the Adorable", "the Gifted", "the Tender", "the Powerful One", "the Gifted One", "the Powerful", "the Black", "the White", "the White One", "the Careful", "the Clumsy One", "the Grumpy", "the Jealous One", "the Mysterious", "the Mysterious one", "the Scary", "the Scary One", "the Brave", "the Victorious", "the Skinny One", "the Mammoth", "the Puny", "the Quiet", "the Voiceless", "the Loud", "the Voiceless One", "the Fast One", "the Swift", "the Young One", "the Youngling", "the Slow", "the Creep", "the Warm", "Warmheart", "Braveheart", "Gentleheart", "the Strong Minded", "the Stubborn", "Firebreath", "Icebreath", "the Squeeler", "Champion of Dragons", "Eternal Fire", "Gentle Mind", "Longtail", "Redeemer of Men", "Protector of the Weak", "Protector of the Forest", "Protector of the Sky", "Lord of the Skies", "Champion of the Skies", "Champion of Dragon", "Champion of Men", "Lord of Fire", "Lord of Ice", "Lord of the Red", "Lord of the Black", "Lord of the White", "Lord of the Blue", "Lord of the Green", "Lord of the Yellow", "Lord of the Brown", "Champion of the Red", "Champion of the White", "Champion of the Black", "Champion of the Blue", "Champion of the Yellow", "Champion of the Brown", "Champion of the Green", "Protector of Creatures", "Protector of Life", "Giver of Life", "Bringer of Death", "the Deathlord", "the Dead", "Destroyer of Life", "Destroyer of Men", "Eater of Sheep", "Eater of All", "the Hungry", "Eater of Bunnies", "the Bunny Killer", "the Rabbit Slayer", "the Taker of Life", "the Insane",
	};
	if(rn2(3) == 0) {
		snprintf(buf, 30, "%s %s",
			dragon_name[id % SIZE(dragon_name)],
			dragon_title[id % SIZE(dragon_title)]);
	} else {
		snprintf(buf, 30, "%s",
			dragon_name[id % SIZE(dragon_name)]);
	}
	return buf;
}

/* return a randomly generated hobbit name */
const char *
hobbit_name(size_t id, boolean female)
{
	static char buf[30];
	/* Hobbit name fragments courtesy of http://fantasynamegenerators.com */
	static const char *female_hobbit_given_name[] = {
		"Adallinda", "Adaltrude", "Adelheid", "Alpaida", "Alpais", "Ansgard", "Aubirge", "Audofleda", "Baldechildis", "Basina", "Begga", "Berenga", "Bertha", "Bertrada", "Burgundefara", "Clothild", "Eadgithu", "Emma", "Engelberga", "Ermengard", "Ermentrudis", "Fara", "Fastrada", "Foy", "Genofeva", "Gersvinda", "Gisela", "Gudula", "Gudule", "Gundrada", "Herleva", "Hildegard", "Hildegarde", "Hildegund", "Hiltrude", "Hodierna", "Ingeltrude", "Ingeltrudis", "Joveta", "Liobsynde", "Liutgarde", "Madelgarde", "Mechtild", "Moschia", "Nantechildis", "Oda", "Ogiva", "Plectrudis", "Radogund", "Rosamund", "Rothaide", "Rotrude", "Rotrudis", "Ruothilde", "Theodelinda", "Theoderada", "Theutberga", "Waldrada", "Adaltrude", "Adallind", "Adallinda", "Adelhaid", "Adda", "Albofleda", "Alpaide", "Alpais", "Aregund", "Aude", "Audofleda", "Audovera", "Austrechild", "Atula", "Athalia", "Adele", "Baldechildis", "Basina", "Bave", "Berchildis", "Begga", "Beretrude", "Bertha", "Berthe", "Berthefled", "Berthefried", "Berthegund", "Bertoane", "Bertrada", "Bilichildis", "Blesinde", "Brunhild", "Brunhilda", "Fastrada", "Chlodeswinthe", "Chlodosind", "Chlothsinda", "Chrodechildis", "Chrodtrude", "Clotild", "Clotilde", "Chunsina", "Cunegonde", "Kunegund", "Cunegundis", "Cunegund", "Deuteria", "Ealswid", "Ellinrat", "Engelberge", "Ingelburga", "Engeltrude", "Ermenberga", "Ermengarde", "Ermentrudis", "Faileuba", "Fastrada", "Fredegunde", "Galswinth", "Gersvinda", "Gisela", "Gundrada", "Gundradis", "Gomatrudis", "Goiswinth", "Gundrade", "Guntheuc", "Gunza", "Hamesindis", "Hatilde", "Hildeburg", "Hildegarde", "Hiltrude", "Himiltrud", "Ingeltrud", "Ingitrude", "Ingoberg", "Ingunde", "Irmgard", "Irmingard", "Itta", "Lanthechilde", "Leubast", "Leubovera", "Liutgarde", "Luitgarde", "Magnatrude", "Marcatrude", "Marcovefa", "Madelgarde", "Madelgarda", "Merofled", "Merwig", "Nantechildis", "Radegund", "Ragnachilde", "Regintrude", "Regnetrudis", "Rigunth", "Rosamund", "Rotrud", "Ruodhaid", "Ruothild", "Ruothilde", "Rothaide", "Rotrude", "Swanahilde", "Teutberga", "Theoderada", "Theodrada", "Theodelinda", "Theodrade", "Theudechild", "Theudelinde", "Ultrogotha", "Veneranda", "Vuldretrada", "Vulfegundis", "Wisigard", "Adaldrida", "Alfrida", "Amalda", "Amanda", "Amaranth", "Amethyst", "Angelica", "Arabella", "Asphodel", "Belba", "Belinda", "Bellisima", "Bell", "Belladonna", "Bertha", "Berylla", "Camelia", "Cara", "Caramella", "Celendine", "Cora", "Cornelia", "Chica", "Daisy", "Diamanda", "Diamond", "Dina", "Donnamira", "Dora", "Duenna", "Eglantine", "Elanor", "Esmeralda", "Estella", "Fatima", "Gerda", "Gilly", "Gloriana", "Goldilocks", "Grimalda", "Hilda", "Jasmine", "Jemima", "Jessamine", "Lalia", "Laura", "Lavinia", "Lily", "Linda", "Lobelia", "Malva", "Marigold", "Mantissa", "Matilda", "Maxima", "May", "Melba", "Melilot", "Melissa", "Menegilda", "Mentha", "Mimosa", "Mirabella", "Miranda", "Myrtle", "Nina", "Nora", "Pamphila", "Pandora", "Pansy", "Pearl", "Peony", "Pervinca", "Pimpernel", "Poppy", "Prima", "Primrose", "Primula", "Prisca", "Regina", "Rhoda", "Robinia", "Rosa", "Rosamunda", "Rose", "Rowan", "Ruby", "Salvia", "Savanna", "Selina", "Semolina", "Tanta", "Yolanda", "Abigail", "Alexandra", "Alexandria", "Alexis", "Alia", "Alicia", "Allison", "Alura", "Alyssa", "Amanda", "Amber", "Amy", "Andrea", "Angela", "Anna", "Autumn", "Bailey", "Brianna", "Brittany", "Brooke", "Caitlin", "Calamity", "Caroline", "Cassandra ", "Catherine", "Chelsea", "Cheryl", "Cheyenne", "Christina", "Cori", "Courtney", "Danielle", "Darby", "Deirdre", "Delaney", "Destiny", "Devin", "Diana", "Donna", "Elizabeth", "Ellie", "Emily", "Emma", "Erica", "Erin", "Esmee", "Fallon", "Fiona", "Gabrielle", "Ginelle", "Grace", "Haley", "Hannah", "Heather", "Iridian", "Jacqueline", "Jasmine", "Jenna", "Jennifer", "Jessica", "Jordan", "Julia", "Kaitlyn", "Katherine", "Katie", "Kayla", "Keena", "Keira", "Kelsey", "Kestrel", "Kiley", "Kimberly", "Kristen", "Kymma", "Laura", "Lauren", "Leesha", "Lenora", "Lindsey", "Llewella", "Mackenzie", "Madeline", "Madison", "Maria", "Mariah", "Marissa", "Mary", "Megan", "Melissa", "Michelle", "Mindy", "Miranda", "Moira", "Molly", "Monica", "Morgan", "Myrna", "Natalie", "Neela", "Nicole", "Nora", "Olivia", "Paige", "Rachel", "Rebecca", "Roslyn", "Rowan", "Ryan", "Rylee", "Sabrina", "Saffron", "Samantha", "Sarah", "Sarai", "Savannah", "Scarlet", "Sestiva", "Shanna", "Shannon", "Shawna", "Shelby", "Sierra", "Sophie", "Stephanie", "Suri", "Sydney", "Tabitha", "Tara", "Taryn", "Tasha", "Tatiana", "Tavia", "Taylor", "Terri", "Tiffany", "Vanessa", "Victoria",
	};
	static const char *male_hobbit_given_name[] = {
		"Adalard", "Adalbert", "Adalhaid", "Adalolf", "Ageric", "Agilfride", "Agiulf", "Alberic", "Amand", "Andica", "Angilbert", "Engilbert", "Ansegisel", "Ansovald", "Aregisel", "Arnegisel", "Arnold", "Arnulf", "Audovald", "Austregisel", "Badegisel", "Balderic", "Baldrick", "Baudry", "Berengar", "Berenger", "Bernhard", "Bernard", "Bero", "Berthefried", "Bertram", "Burchard", "Carloman", "Chararic", "Charibert", "Childebert", "Childebrand", "Childeric", "Chilperic", "Chlodomer", "Chramnesind", "Clodio", "Chlodion", "Cloud", "Clovis", "Chlodwig", "Conrad", "Corbus", "Dagobert", "Dagaric", "Drogo", "Drogon", "Durand", "Eberhard", "Evrard", "Eberulf", "Ebregisel", "Emmon", "Engelbert", "Egide", "Eracle", "Erard", "Erenfried", "Euric", "Farabert", "Floribert", "Fulcaire", "Gararic", "Garivald", "Gerbert", "Gerold", "Giselbert", "Gilbert", "Godomar", "Gondulph", "Grimald", "Grimoald", "Griffon", "Guido", "Wido", "Gundobad", "Gundovald", "Gunthar", "Guntram", "Hartgard", "Hartmut", "Hartnid", "Heribert", "Hildebald", "Hubert", "Imnachar", "Ingelram", "Enguerrand", "Ingomer", "Ingund", "Lambert", "Leudast", "Leuthard", "Lothar", "Magnachar", "Magneric", "Malaric", "Marachar", "Marcomir", "Meginhard", "Merovech", "Monulph", "Munderic", "Nevelung", "Nibelung", "Nithard", "Notger", "Odilon", "Odo", "Otbert", "Otto", "Otton", "Otker", "Pippin", "Pepin", "Ramnulf", "Rathar", "Rathier", "Ratold", "Reginar", "Reginard", "Remacle", "Ricbodo", "Ricchar", "Richer", "Ricfried", "Rigunth", "Samson", "Sichar", "Siegfried", "Sigefroy", "Sigeric", "Sigibert", "Sigismund", "Sunnegisil", "Sunno", "Tassilo", "Theodard", "Theodebert", "Theodemir", "Theodon", "Theodoric", "Thierry", "Theodore", "Theodwin", "Theudebald", "Theuderic", "Unroch", "Wala", "Waleran", "Walcaud", "Waltgaud", "Wazo", "Werinbert", "Willichar", "Wolbodo", "Wulfhard", "Zwentibold", "Abbo", "Adalbert", "Adaldag", "Adalhard", "Adelard", "Aega", "Agilbert", "Agobard", "Aigulf", "Alberic", "Allowin", "Amalricus", "Amand", "Amator", "Angegisis", "Angilbart", "Angilbert", "Anno", "Ansegisel", "Anskar", "Arbitio", "Arbogast", "Arbogastes", "Arculf", "Arnoul", "Arnulf", "Artaud", "Asselin", "Atacinus", "Audoen", "Audomar", "Audoneus", "Audramnus", "Baugulf", "Bauto", "Bavo", "Benild", "Berchar", "Berengar", "Bernard", "Berno", "Bero", "Bertelis", "Berthaire", "Bertin", "Bertulf", "Besso", "Birinus", "Blutmund", "Boso", "Bovo", "Brice", "Britius", "Brocard", "Bruno", "Burchard", "Butilin", "Carloman", "Cassyon", "Ceufroy", "Charibert", "Charles", "Cheldric", "Childebert", "Childebrand", "Childeric", "Chilperic", "Chlodmer", "Chlodowig", "Chlotar", "Chrodegang", "Clodomir", "Clotaire", "Clothair", "Clovis", "Corbinian", "Cyr", "Cyricus", "Dado", "Dagobert", "Dalfin", "Dodo", "Dreux", "Drogo", "Dudon", "Ebbo", "Ebroin", "Ebrulf", "Einhard", "Emme", "Emmeran", "Engilbert", "Enurchus", "Erchinoald", "Evroul", "Evroult", "Fardulf", "Faro", "Flodoard", "Folcard", "Folmar", "Fredegar", "Fridolin", "Fridugis", "Fulbert", "Fulk", "Fulrad", "Gerbert", "Gereon", "Gerold", "Gifemund", "Giseler", "Giso", "Godobald", "Godun", "Goisfrid", "Goscelin", "Gouzlim", "Gozbert", "Gozolon", "Grifo", "Grimald", "Grimbald", "Gunthar", "Guntramn", "Hagen", "Halinard", "Hartmut", "Helinand", "Helisachar", "Heribert", "Hildebald", "Hildebold", "Hildeprand", "Hilduin", "Hincmar", "Hlodver", "Huebald", "Humbert", "Hunald", "Imbert", "Imninon", "Jocelin", "Lambert", "Lanfranc", "Laudus", "Lebuin", "Ledger", "Leger", "Leodegar", "Letard", "Leufred", "Leufroy", "Leutfrid", "Leuthere", "Liudhard", "Liudolf", "Lo", "Lothar", "Lul", "Lull", "Maiuel", "Maixent", "Majorian", "Mallobaudes", "Mansuetus", "Maraulf", "Marcoul", "Matfrid", "Mauger", "Medard", "Meginhard", "Merobaudes", "Merovech", "Nithard", "Norbert", "Nordbert", "Notker", "Odger", "Odo", "Odulf", "Omer", "Orderic", "Otker", "Ouen", "Ouus", "Pacatian", "Pair", "Pancras", "Panteleon", "Pepin", "Philibert", "Piligrim", "Pippin", "Poppo", "Puvis", "Radigis", "Ragnfred", "Razo", "Reginald", "Reginar", "Remi", "Reolus", "Richomer", "Richomeres", "Riquier", "Rothad", "Samo", "Sergius", "Sicho", "Sigebert", "Sigibert", "Suger", "Suidbert", "Suidger", "Syagrius", "Tassilo", "Taurin", "Tescelin", "Thankmar", "Theodard", "Theodoric", "Theodulf", "Theodulph", "Theudebert", "Theuderic", "Theutgaud", "Thierry", "Thietmar", "Turpin", "Vedast", "Vicelin", "Vigor", "Vulmar", "Waiofar", "Wala", "Walaric", "Waldolanus", "Waltgaud", "Wandregisel", "Wandregisilus", "Wandrille", "Warmann", "Werinbert", "Wibert", "Wichmann", "Willehad", "Willibald", "Willibrord", "Wulfram", "Adelbert", "Adelgrim", "Adelard", "Alaric", "Alberic", "Andwise", "Ansegar", "Arnor", "Athanaric", "Balbo", "Banazir", "Bandobras", "Belisarius", "Bercilac", "Berilac", "Bilba", "Bilbo", "Bilcuzal", "Bildad", "Bildat", "Bingo", "Bladud", "Blanco", "Bucca", "Bob", "Basso", "Bodo", "Bosco", "Bowman", "Briffo", "Bruno", "Brutus", "Bungo", "Caradas", "Caradoc", "Carambo", "Carl", "Cedivar", "Celedor", "Ceredic", "Cerdic", "Columbus", "Conrad", "Cosimo", "Cotman", "Cottar", "Crassus", "Crispus", "Deagol", "Dinodas", "Doderic", "Dodinas", "Drogo", "Dudo", "Elfstan", "Erling", "Everard", "Falco", "Faramir", "Faramond", "Fastred", "Fastolph", "Ferdinand", "Ferumbras", "Filibert", "Flambard", "Flavus", "Folcard", "Folco", "Fortinbras", "Fosco", "Fredegar", "Frodo", "Fulvus", "Gerontius", "Goodwill", "Gorhendad", "Gorbadoc", "Gorbaduc", "Gorbulas", "Gormadoc", "Griffo", "Gringamor", "Grossman", "Gruffo", "Guido", "Gundabald", "Gundahar", "Gundobad", "Gundolpho", "Habaccuc", "Haiduc", "Hal", "Halfred", "Hamfast", "Hamilcar", "Harding", "Hending", "Heribald", "Herugar", "Hildibrand", "Hildigard", "Hildifons", "Hildigrim", "Hob", "Hobson", "Holfast", "Holman", "Hugo", "Ilberic", "Iago", "Inigo", "Iolo", "Isembard", "Isembold", "Isengar", "Isengrim", "Isengrin", "Isumbras", "Jago", "Jo", "Jolly", "Kalimac", "Lamorac", "Largo", "Longo", "Lotho", "Madoc", "Magnus", "Marcho", "Marco", "Marcus", "Marmadoc", "Marmaduc", "Marmaduke", "Marroc", "Matta", "Mattalic", "Maura", "Melampus", "Meneaduc", "Marmadas", "Meriadoc", "Merimac", "Merimas", "Merry", "Milo", "Minto", "Moro", "Mosco", "Mungo", "Nahand", "Nob", "Nibs", "Nicol", "Nick", "Obo", "Odo", "Odovacar", "Olo", "Orgulas", "Orlando", "Otho", "Paladin", "Peregrin", "Pippin", "Polo", "Ponto", "Porro", "Posco", "Priamus", "Prospero", "Ranugad", "Razanur", "Reginard", "Robin", "Robur", "Roderic", "Rollo", "Rorimac", "Rudibert", "Rudigar", "Rudolph", "Rufus", "Sadoc", "Sago", "Samlad", "Samwise", "Sancho", "Sagramor", "Saradas", "Saradoc", "Scudamor", "Seredic", "Sigismond", "Smeagol", "Ted", "Theobald", "Theodoric", "Timba", "Tim", "Timothy", "Tobias", "Tobold", "Togo", "Tolman", "Tomba", "Tomburan", "Tomacca", "Trahand", "Uffo", "Valdemar", "Vigo", "Wilcome", "Wilibald", "Wilimar", "Will", "Wiseman",
	};
	static const char *hobbit_surname[] = {
		"Baggins", "Banks", "Barrowes", "Bilberry", "Boffin", "Bolger", "Bolger-Baggins", "Bophin	", "Boulderhill", "Bottomhill", "Bracegirdle", "Bramblethorn", "Brandagamba", "Brandybuck", "Brandywood", "Brockhouse", "Brown", "Brownlock", "Bunce", "Burrowes", "Burrows", "Butcher", "Button", "Chubb", "Chubb-Baggins", "Clayhanger", "Cotton", "Cutton", "Dewfoot", "Diggle", "Elvellon", "Farfoot", "Fairbairn", "Fairfoot", "Fallohide", "Featherbottom", "Finnagund", "Fleetfoot", "Galbassi", "Galpsi", "Gamgee", "Gammidge", "Gamwich", "Gardner", "Gaukrogers", "Gawkroger", "Gluttonbelly", "Goldworthy", "Goodbody", "Goodchild", "Goodsong", "Goodwort", "Goold", "Greenhand", "Greenhill", "Grubb", "Hairyfoot", "Harfoot", "Hayward", "Headstrong", "Heathertoes", "Hedgehopper", "Hlothran", "Hogpen", "Hopesinger", "Hornblower", "Hornwood", "Knotwise", "Labingi", "Langham", "Leafwalker", "Lightfoot", "Littlefoot", "Longbottom", "Longhole", "Longfoot", "Longriver", "Lothran", "Maggot", "Mugwort", "Noakes", "Noakesburrow", "North-took", "Oakbottom", "Oldbuck", "Pott", "Proudbottom", "Proudfoot", "Proudbody", "Proudmead", "Puddifoot", "Puddlefoot", "Riverhopper", "Roper", "Rumble", "Rumblebelly", "Sackville", "Sackville-Baggins", "Sandheaver", "Sandyman", "Silentfoot", "Silverstring", "Smallburrow", "Stoor", "Stumbletoe", "Swiftfoot", "Thornburrow", "Tinyfoot", "Took", "Took-Brandybuck", "Took-Took", "Townsend", "Tunnelly", "Twofoot", "Underburrow", "Underfoot", "Underhill", "Undertree", "Underlake", "Wanderfoot", "Whitfoot", "Whitbottom", "Zaragamba",
	};
	if(female) {
		snprintf(buf, 30, "%s %s",
			female_hobbit_given_name[id % SIZE(female_hobbit_given_name)],
			hobbit_surname[id % SIZE(hobbit_surname)]);
	} else {
		snprintf(buf, 30, "%s %s",
			male_hobbit_given_name[id % SIZE(male_hobbit_given_name)],
			hobbit_surname[id % SIZE(hobbit_surname)]);
	}
	return buf;
}

/* return a randomly generated dwarven name */
const char *
dwarf_name(size_t id, boolean female)
{
	static char buf[30];
	/* Dwarf name fragments courtesy of http://fantasynamegenerators.com */
	static const char *dwarf_syllable1[] = {
		"A", "Ara", "Alfo", "Bari", "Be", "Bo", "Bha", "Bu", "Ba", "Bra", "Bro", "Brou", "Bru", "Da", "Dalo", "Dare", "De", "Dhu", "Dho", "Do", "Dora", "Dwo", "Dou", "Duri", "Du", "El", "Eri", "Fi", "Fo", "Fo", "Ga", "Gi", "Gla", "Glori", "Go", "Gra", "Gro", "Groo", "Gru", "Grou", "Ha", "Ha", "He", "He", "Ho", "Hou", "Hu", "Ja", "Jo", "Ka", "Khe", "Khu", "Khou", "Ko", "Ku", "Ki", "Kra", "Kro", "Lo", "Lu", "Lo", "Ma", "Mo", "Mu", "Na", "No", "Nu", "Nora", "Nura", "Ne", "No", "O", "Ori", "Rei", "Ra", "Ru", "Sa", "Si", "Sna", "Sko", "Ska", "Stro", "The", "Thi", "Tho", "Thra", "Tha", "Tore", "Tha", "Thra", "Thro", "Thu", "Tu", "U", "Umi", "Va", "Vo", "Whu", "We", "Wera", "Yu", "Yo", "Ya",
	};
	static const char *male_dwarf_syllable2[] = {
		"b", "br", "dd", "d", "dr", "dm", "dgr", "f", "fr", "gr", "gg", "gh", "gn", "k", "kh", "kgr", "kdr", "kk", "kh", "kr", "l", "lg", "lgr", "ldr", "lm", "md", "mn", "m", "mm", "mr", "n", "nd", "ndr", "ngr", "nm", "r", "rr", "rgr", "rdr", "rb", "rg", "rn", "rh", "rd", "rm", "rs", "rf", "s", "ss", "sdr", "sgr", "st", "str", "t", "tr", "tm", "th", "tdr", "tgr", "v", "vr", "z", "zm", "zn", "zz",
	};
	static const char *female_dwarf_syllable2[] = {
		"b", "br", "dd", "d", "dr", "dm", "dgr", "dw", "f", "fr", "gr", "gg", "gh", "gn", "k", "kh", "kgr", "kdr", "kk", "kw", "kh", "kr", "l", "lg", "lgr", "ldr", "lm", "md", "mw", "mn", "m", "mm", "mr", "n", "nd", "ndr", "nw", "ngr", "nm", "r", "rr", "rgr", "rdr", "rb", "rg", "rn", "rh", "rd", "rm", "rs", "rf", "s", "ss", "sdr", "sgr", "st", "str", "t", "tr", "tm", "th", "tdr", "tgr", "v", "vr", "w", "z", "zm", "zn", "zz",
	};
	static const char *male_dwarf_syllable3[] = {
		"ac", "aic", "aec", "ec", "eac", "ic", "oc", "oic", "ouc", "ack", "aeck", "eck", "eack", "ick", "ock", "oick", "ouck", "uck", "uc", "ad", "aed", "ed", "ead", "id", "od", "oid", "oud", "ud", "uid", "ag", "aeg", "eg", "eag", "ig", "og", "oug", "ug", "ak", "aek", "ek", "eak", "ik", "ok", "oki", "uk", "uik", "ouk", "uki", "al", "ael", "el", "eal", "il", "ol", "oli", "olin", "olim", "olir", "oul", "ul", "uli", "ulim", "ulir", "uil", "am", "ami", "amli", "amri", "aem", "em", "eam", "im", "om", "omli", "omri", "omi", "oum", "um", "umi", "umir", "umin", "umli", "umlir", "umlin", "umri", "an", "aen", "en", "ean", "in", "on", "onlim", "onlir", "oun", "un", "unli", "unri", "ar", "arlum", "arlun", "arlug", "arlig", "aer", "er", "erlum", "erlun", "erlug", "erlig", "ear", "ir", "irlum", "irlun", "or", "orli", "orlim", "orlum", "orlun", "orlig", "orlug", "oir", "our", "ur", "uri", "urim", "urum", "us", "as", "ous", "aes", "eas", "at", "atir", "atum", "atin", "aet", "et", "eat", "it", "ot", "otir", "atin", "otum", "out", "ut", "ath", "aeth", "eth", "eath", "ith", "oth", "outh", "uth",
	};
	static const char *female_dwarf_syllable3[] = {
		"abelle", "aebelle", "ebelle", "ibelle", "obelle", "ubelle", "alyn", "aelyn", "elyn", "ealyn", "ilyn", "olyn", "oulyn", "ulyn", "uilyn", "alynn", "aelynn", "elynn", "ealynn", "ilynn", "olynn", "oulynn", "ulynn", "uilynn", "abelyn", "aebelyn", "ebelyn", "eabelyn", "ibelyn", "obelyn", "oubelyn", "ubelyn", "uibelyn", "abelynn", "aebelynn", "ebelynn", "eabelynn", "ibelynn", "obelynn", "oubelynn", "ubelynn", "uibelyn", "anelyn", "aenelyn", "enelyn", "eanelyn", "inelyn", "onelyn", "ounelyn", "unelyn", "uinelyn", "anelynn", "aenelynn", "enelynn", "eanelynn", "inelynn", "onelynn", "ounelynn", "unelynn", "uinelynn", "agit", "aegit", "egit", "eagit", "igit", "ogit", "ugit", "uigit", "agith", "aegith", "egith", "eagith", "igith", "ogith", "ugith", "uigith", "irgit", "irgith", "uirgit", "uirgith", "airgit", "airgith", "arika", "aerika", "erika", "earika", "irika", "orika", "urika", "atain", "aetain", "etain", "eatain", "itain", "otain", "utain", "ataine", "aetaine", "etaine", "eataine", "itaine", "otaine", "utaine", "ahilda", "aehilda", "ehilda", "eahilda", "ohilda", "ihilda", "uhilda", "ahulda", "aehulda", "ehulda", "eahulda", "ohulda", "ihulda", "uhulda", "agar", "aegar", "egar", "eagar", "igar", "ogar", "ugar", "agaer", "egaer", "igaer", "ogaer", "ugaer", "atrud", "aetrud", "etrud", "eatrud", "itrud", "otrud", "utrud", "atrude", "aetrude", "etrude", "eatrude", "itrude", "otrude", "utrude", "ada", "aeda", "eda", "eada", "ida", "oda", "uda", "alda", "aelda", "elda", "ealda", "ilda", "olda", "oulda", "ulda", "alin", "aelin", "elin", "ealin", "ilin", "olin", "oulin", "ulin", "aline", "aeline", "eline", "ealine", "iline", "oline", "ouline", "uline", "atalin", "aetalin", "etalin", "eatalin", "italin", "otalin", "outalin", "utalin", "atalyn", "aetalyn", "etalyn", "eatalyn", "italyn", "otalyn", "outalyn", "utalyn", "atelin", "aetelin", "etelin", "eatelin", "itelin", "otelin", "outelin", "utelin", "atelyn", "aetelyn", "etelyn", "eatelyn", "itelyn", "otelyn", "outelyn", "utelyn", "angrid", "aengrid", "engrid", "eangrid", "ingrid", "ongrid", "oungrid", "ungrid", "ani", "aeni", "eni", "eani", "ini", "oni", "ouni", "uni", "ana", "aena", "ena", "eana", "ina", "ona", "ouna", "una", "alsia", "aelsia", "elsia", "ealsia", "ilsia", "olsia", "oulsia", "ulsia", "ala", "aela", "ela", "eala", "ila", "ola", "oula", "ula", "abella", "aebella", "ebella", "eabella", "ibella", "obella", "oubella", "ubella", "abela", "aebela", "ebela", "eabela", "ibela", "obela", "oubela", "ubela", "astr", "aestr", "estr", "eastr", "istr", "ostr", "oustr", "ustr", "abo", "aebo", "ebo", "eabo", "ibo", "obo", "oubo", "ubo", "abena", "aebena", "ebena", "eabena", "ibena", "obena", "oubena", "ubena", "abera", "aebera", "ebera", "eabera", "ibera", "obera", "oubera", "ubera", "adeth", "aedeth", "edeth", "eadeth", "ideth", "odeth", "oudeth", "udeth", "adrid", "aedrid", "edrid", "eadrid", "idrid", "odrid", "oudrid", "udrid", "abyrn", "aebyrn", "ebyrn", "eabyrn", "ibyrn", "obyrn", "oubyrn", "ubyrn", "agrett", "aegrett", "egrett", "eagrett", "igrett", "ogrett", "ougrett", "ugrett", "agret", "aegret", "egret", "eagret", "igret", "ogret", "ougret", "ugret", "asli", "aesli", "esli", "easli", "isli", "osli", "ousli", "usli", "ahilda", "aehilda", "ehilda", "eahilda", "ihilda", "ohilda", "ouhilda", "uhilda", "ahilde", "aehilde", "ehilde", "eahilde", "ihilde", "ohilde", "ouhilde", "uhilde", "aginn", "aeginn", "eginn", "eaginn", "iginn", "oginn", "ouginn", "uginn", "amora", "aemora", "emora", "eamora", "imora", "omora", "oumora", "umora", "alydd", "aelydd", "elydd", "ealydd", "ilydd", "olydd", "oulydd", "ulydd", "akara", "aekara", "ekara", "eakara", "ikara", "okara", "oukara", "ukara", "aren", "aeren", "eren", "earen", "iren", "oren", "ouren", "uren", "arra", "aerra", "erra", "earra", "irra", "orra", "ourra", "urra", "are", "aere", "ere", "eare", "ire", "ore", "oure", "ure", "awynn", "aewynn", "ewynn", "eawynn", "iwynn", "owynn", "ouwynn", "uwynn", "atryd", "aetryd", "etryd", "eatryd", "itryd", "otryd", "outryd", "utryd", "athra", "aethra", "ethra", "eathra", "ithra", "othra", "outhra", "uthra", "aserd", "aeserd", "eserd", "easerd", "iserd", "oserd", "ouserd", "userd", "tryd",
	};
	static const char *dwarf_syllable4[] = {
		"Ale", "Amber", "Anvil", "Ash", "Axe", "Barbed", "Barrel", "Battle", "Beast", "Bone", "Beryl", "Bitter", "Black", "Blazing", "Blessed", "Blood", "Blunt", "Bone", "Bottle", "Boulder", "Brew", "Brick", "Bright", "Bristle", "Broad", "Bronze", "Brown", "Cave", "Cask", "Chain", "Crag", "Chaos", "Coal", "Coin", "Copper", "Dark", "Deep", "Dim", "Dragon", "Drake", "Dusk", "Earth", "Ember", "Fiery", "Flint", "Flask", "Flint", "Flat", "Forge", "Frost", "Giant", "Gold", "Golden", "Granite", "Gravel", "Gray", "Great", "Grey", "Grim", "Grumble", "Hammer", "Hard", "Heavy", "Hill", "Honor", "Horn", "Ice", "Ingot", "Iron", "Jade", "Keg", "Kobold", "Krag", "Lead", "Large", "Lava", "Leather", "Light", "Long", "Marble", "Magma", "Merry", "Metal", "Mithril", "Mine", "Mountain", "Mud", "Night", "Noble", "Oak", "Oaken", "Onyx", "Opal", "Ore", "Orc", "Plate", "Pebble", "Red", "Rune", "Ruby", "Sapphire", "Shadow", "Shatter", "Smelt", "Silver", "Snow", "Steel", "Storm", "Strong", "Troll", "Thunder", "Twilight", "Treasure", "Under", "War", "Warm", "Whit", "Wind", "Wold", "Wraith", "Wyvern",
	};
	static const char *dwarf_syllable5[] = {
		"arm", "armour", "axe", "back", "bane", "beard", "basher", "belly", "belt", "bender", "blade", "born", "bow", "braid", "braids", "branch", "brand", "breaker", "brew", "brewer", "bringer", "brow", "buckle", "buster", "chest", "chin", "cloak", "coat", "delver", "digger", "foot", "fall", "fury", "finger", "flayer", "feet", "forge", "forged", "grog", "grip", "guard", "gut", "granite", "hand", "head", "heart", "helm", "hide", "hood", "horn", "jaw", "mace", "mail", "maker", "mantle", "mane", "master", "maul", "miner", "pike", "rock", "river", "shield", "shaper", "sword", "shoulder", "stone", "spine", "sunder", "thane", "toe", "tank", "view",
	};
	if(female) {
		snprintf(buf, 30, "%s%s%s %s%s",
			dwarf_syllable1[id % SIZE(dwarf_syllable1)],
			female_dwarf_syllable2[id % SIZE(female_dwarf_syllable2)],
			female_dwarf_syllable3[id % SIZE(female_dwarf_syllable3)],
			dwarf_syllable4[id % SIZE(dwarf_syllable4)],
			dwarf_syllable5[id % SIZE(dwarf_syllable5)]);
	} else {
		snprintf(buf, 30, "%s%s%s %s%s",
			dwarf_syllable1[id % SIZE(dwarf_syllable1)],
			male_dwarf_syllable2[id % SIZE(male_dwarf_syllable2)],
			male_dwarf_syllable3[id % SIZE(male_dwarf_syllable3)],
			dwarf_syllable4[id % SIZE(dwarf_syllable4)],
			dwarf_syllable5[id % SIZE(dwarf_syllable5)]);
	}
	return buf;
}

/* return a randomly generated elven name */
const char *
elf_name(id)
size_t id;
{
    static char buf[30];
    /* Elf name fragments courtesy of ToME */
    static const char *elf_syllable1[] = {
	"Al", "An", "Bal", "Bel", "Cal", "Cel", "El", "Elr", "Elv", "Eow",
	"Ear", "F", "Fal", "Fel", "Fin", "G", "Gal", "Gel", "Gl", "Is", "Lan",
	"Leg", "Lom", "N", "Nal","Nel", "S", "Sal", "Sel", "T", "Tal", "Tel",
	"Thr", "Tin",
    };
    static const char *elf_syllable2[] = {
	"a", "adrie", "ara", "e", "ebri", "ele", "ere", "i", "io", "ithra",
	"ilma", "il-Ga", "ili", "o", "orfi", "u", "y",
    };
    static const char *elf_syllable3[] = {
	"l", "las", "lad", "ldor", "ldur", "linde", "lith", "mir", "n", "nd",
	"ndel", "ndil", "ndir", "nduil", "ng", "mbor", "r", "rith", "ril",
	"riand", "rion", "s", "thien", "viel", "wen", "wyn",
    };
    snprintf(buf, 30, "%s%s%s",
	     elf_syllable1[id % SIZE(elf_syllable1)],
	     elf_syllable2[id % SIZE(elf_syllable2)],
	     elf_syllable3[id % SIZE(elf_syllable3)]);
    return buf;
}

STATIC_OVL void
mk_mplayer_armor(mon, typ)
struct monst *mon;
short typ;
{
	struct obj *obj;

	if (typ == STRANGE_OBJECT) return;
	obj = mksobj(typ, FALSE, FALSE);
	if (!rn2(3)) set_erodeproof(obj);
	if (!rn2(3)) curse(obj);
	if (!rn2(3)) bless(obj);
	/* Most players who get to the endgame who have cursed equipment
	 * have it because the wizard or other monsters cursed it, so its
	 * chances of having plusses is the same as usual....
	 */
	obj->spe = rn2(10) ? (rn2(3) ? rn2(5) : rn1(4,4)) : -rnd(3);
	(void) mpickobj(mon, obj);
}

struct monst *
mk_mplayer(ptr, x, y, special)
register struct permonst *ptr;
xchar x, y;
register boolean special;
{
	register struct monst *mtmp;
	char nam[PL_NSIZ];

	if(!is_mplayer(ptr))
		return((struct monst *)0);

	if(MON_AT(x, y))
		(void) rloc(m_at(x, y), FALSE); /* insurance */

	if(!In_endgame(&u.uz)) special = FALSE;

	if ((mtmp = makemon(ptr, x, y, NO_MM_FLAGS)) != 0) {
	    short weapon = rn2(2) ? LONG_SWORD : rnd_class(SPEAR, BULLWHIP);
	    short armor = rnd_class(GRAY_DRAGON_SCALE_MAIL, YELLOW_DRAGON_SCALE_MAIL);
	    short cloak = !rn2(8) ? STRANGE_OBJECT :
	    		rnd_class(OILSKIN_CLOAK, CLOAK_OF_DISPLACEMENT);
	    short helm = !rn2(8) ? STRANGE_OBJECT :
	    		rnd_class(ELVEN_LEATHER_HELM, HELM_OF_TELEPATHY);
	    short shield = !rn2(8) ? STRANGE_OBJECT :
	    		rnd_class(ELVEN_SHIELD, SHIELD_OF_REFLECTION);
	    int quan;
	    struct obj *otmp;

	    mtmp->m_lev = (special ? rn1(16,15) : rnd(16));
	    mtmp->mhp = mtmp->mhpmax = d((int)mtmp->m_lev,10) +
					(special ? (30 + rnd(30)) : 30);
	    if(special) {
	        get_mplname(mtmp, nam);
	        mtmp = christen_monst(mtmp, nam);
		/* that's why they are "stuck" in the endgame :-) */
		(void)mongets(mtmp, FAKE_AMULET_OF_YENDOR);
	    }
	    mtmp->mpeaceful = 0;
	    set_malign(mtmp); /* peaceful may have changed again */

	    switch(monsndx(ptr)) {
		case PM_ARCHEOLOGIST:
		    if (rn2(2)) weapon = BULLWHIP;
		    break;
		case PM_BARBARIAN:
		    if (rn2(2)) {
		    	weapon = rn2(2) ? TWO_HANDED_SWORD : BATTLE_AXE;
		    	shield = STRANGE_OBJECT;
		    }
		    if (rn2(2)) armor = rnd_class(PLATE_MAIL, CHAIN_MAIL);
		    if (helm == HELM_OF_BRILLIANCE) helm = STRANGE_OBJECT;
		    break;
		case PM_CAVEMAN:
		case PM_CAVEWOMAN:
		    if (rn2(4)) weapon = MACE;
		    else if (rn2(2)) weapon = CLUB;
		    if (helm == HELM_OF_BRILLIANCE) helm = STRANGE_OBJECT;
		    break;
		case PM_HEALER:
		    if (rn2(4)) weapon = QUARTERSTAFF;
		    else if (rn2(2)) weapon = rn2(2) ? UNICORN_HORN : SCALPEL;
		    if (rn2(4)) helm = rn2(2) ? HELM_OF_BRILLIANCE : HELM_OF_TELEPATHY;
		    if (rn2(2)) shield = STRANGE_OBJECT;
		    break;
		case PM_KNIGHT:
		    if (rn2(4)) weapon = LONG_SWORD;
		    if (rn2(2)) armor = rnd_class(PLATE_MAIL, CHAIN_MAIL);
		    break;
		case PM_MONK:
		    weapon = STRANGE_OBJECT;
		    armor = STRANGE_OBJECT;
		    cloak = ROBE;
		    if (rn2(2)) shield = STRANGE_OBJECT;
		    break;
		case PM_PRIEST:
		case PM_PRIESTESS:
		    if (rn2(2)) weapon = MACE;
		    if (rn2(2)) armor = rnd_class(PLATE_MAIL, CHAIN_MAIL);
		    if (rn2(4)) cloak = ROBE;
		    if (rn2(4)) helm = rn2(2) ? HELM_OF_BRILLIANCE : HELM_OF_TELEPATHY;
		    if (rn2(2)) shield = STRANGE_OBJECT;
		    break;
		case PM_RANGER:
		    if (rn2(2)) weapon = ELVEN_DAGGER;
		    break;
		case PM_ROGUE:
		    if (rn2(2)) weapon = SHORT_SWORD;
		    break;
		case PM_SAMURAI:
		    if (rn2(2)) weapon = KATANA;
		    break;
#ifdef TOURIST
		case PM_TOURIST:
		    /* Defaults are just fine */
		    break;
#endif
		case PM_VALKYRIE:
		    if (rn2(2)) weapon = WAR_HAMMER;
		    if (rn2(2)) armor = rnd_class(PLATE_MAIL, CHAIN_MAIL);
		    break;
		case PM_WIZARD:
		    if (rn2(4)) weapon = rn2(2) ? QUARTERSTAFF : ATHAME;
		    if (rn2(2)) {
		    	armor = rn2(2) ? BLACK_DRAGON_SCALE_MAIL :
		    			SILVER_DRAGON_SCALE_MAIL;
		    	cloak = CLOAK_OF_MAGIC_RESISTANCE;
		    }
		    if (rn2(4)) helm = HELM_OF_BRILLIANCE;
		    shield = STRANGE_OBJECT;
		    break;
		default: warning("bad mplayer monster");
		    weapon = 0;
		    break;
	    }

	    if (weapon != STRANGE_OBJECT) {
		otmp = mksobj(weapon, TRUE, FALSE);
		otmp->spe = (special ? rn1(5,4) : rn2(4));
		if (!rn2(3)) { set_erodeproof(otmp); }
		else if (!rn2(2)) otmp->greased = 1;
		if (special && rn2(2))
		    otmp = mk_artifact(otmp, A_NONE);
		/* mplayers knew better than to overenchant Magicbane */
		if (otmp->oartifact == ART_MAGICBANE)
		    otmp->spe = rnd(4);
		(void) mpickobj(mtmp, otmp);
	    }

	    if(special) {
		if (!rn2(10))
		    (void) mongets(mtmp, rn2(3) ? LUCKSTONE : LOADSTONE);
		mk_mplayer_armor(mtmp, armor);
		mk_mplayer_armor(mtmp, cloak);
		mk_mplayer_armor(mtmp, helm);
		mk_mplayer_armor(mtmp, shield);
		if (rn2(8))
		    mk_mplayer_armor(mtmp, rnd_class(LEATHER_GLOVES,
					       GAUNTLETS_OF_DEXTERITY));
		if (rn2(8))
		    mk_mplayer_armor(mtmp, rnd_class(LOW_BOOTS, LEVITATION_BOOTS));
		m_dowear(mtmp, TRUE);

		quan = rn2(3) ? rn2(3) : rn2(16);
		while(quan--)
		    (void)mongets(mtmp, rnd_class(DILITHIUM_CRYSTAL, JADE));
		/* To get the gold "right" would mean a player can double his */
		/* gold supply by killing one mplayer.  Not good. */
#ifndef GOLDOBJ
		mtmp->mgold = rn2(1000);
#else
		mkmonmoney(mtmp, rn2(1000));
#endif
		quan = rn2(10);
		while(quan--)
		    (void) mpickobj(mtmp, mkobj(RANDOM_CLASS, FALSE));
	    }
	    quan = rnd(3);
	    while(quan--)
		(void)mongets(mtmp, rnd_offensive_item(mtmp));
	    quan = rnd(3);
	    while(quan--)
		(void)mongets(mtmp, rnd_defensive_item(mtmp));
	    quan = rnd(3);
	    while(quan--)
		(void)mongets(mtmp, rnd_misc_item(mtmp));
	}

	return(mtmp);
}

int
get_random_role()
{
	return PM_ARCHEOLOGIST + rn2(PM_WIZARD - PM_ARCHEOLOGIST + 1);
}

/* create the indicated number (num) of monster-players,
 * randomly chosen, and in randomly chosen (free) locations
 * on the level.  If "special", the size of num should not
 * be bigger than the number of _non-repeated_ names in the
 * developers array, otherwise a bunch of Adams and Eves will
 * fill up the overflow.
 */
void
create_mplayers(num, special)
register int num;
boolean special;
{
	int pm, x, y;
	struct monst fakemon;

	while(num) {
		int tryct = 0;

		/* roll for character class */
		pm = get_random_role();
		fakemon.data = &mons[pm];

		/* roll for an available location */
		do {
		    x = rn1(COLNO-4, 2);
		    y = rnd(ROWNO-2);
		} while(!goodpos(x, y, &fakemon, 0) && tryct++ <= 50);

		/* if pos not found in 50 tries, don't bother to continue */
		if(tryct > 50) return;

		(void) mk_mplayer(&mons[pm], (xchar)x, (xchar)y, special);
		num--;
	}
}

void
mplayer_talk(mtmp)
register struct monst *mtmp;
{
	static const char *same_class_msg[3] = {
		"I can't win, and neither will you!",
		"You don't deserve to win!",
		"Mine should be the honor, not yours!",
	},		  *other_class_msg[3] = {
		"The low-life wants to talk, eh?",
		"Fight, scum!",
		"Here is what I have to say!",
	};

	if(mtmp->mpeaceful) return; /* will drop to humanoid talk */

	pline("Talk? -- %s",
		(mtmp->data == &mons[urole.malenum] ||
		mtmp->data == &mons[urole.femalenum]) ?
		same_class_msg[rn2(3)] : other_class_msg[rn2(3)]);
}

/*mplayer.c*/
