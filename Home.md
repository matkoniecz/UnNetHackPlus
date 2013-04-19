Plans for UnNetHackPlus

* http://bilious.alt.org/?224

roast
u.umonnum == PM_WOOD_GOLEM || u.umonnum == PM_LEATHER_GOLEM
u.umonnum == PM_IRON_GOLEM

										
						/* this condition must match the one in sounds.c for MS_NURSE */

pull flags.botl to functions like make_sick - would require "change_hp"

int monnum (PM_STONE_GOLEM) - A

struct permonst * - B

A -> B &mons[A]
B -> A monsndx(A)
* searches_for_item, munstone - collect slimes for !is_monster_slimeable
* Introduction http://nethackwiki.com/wiki/File:Vultures-eye-intro.gif
* nice artifact but at cost of permahallu
* ACEHACK CODED THINGS START
* The Vibrating Square is now visible from a distance; it will always be
marked if it's ever been in the player's LOS and is not covered by a
monster or object, due to it now giving off a visible glow.
* The entrances to all branches and the dlvl 1 upstairs are now ladders,
rather than stairs; additionally, stairs in the Mines have become
ladders.  This is both for flavour, and to help the player distinguish
normal stairs from branch entrances. (AceHack - maybe better than hardcoded yellow?)
* Travel now handles traps more sensibly: it will go slightly out of its
way to avoid walking through a trap, but if it's necessary to go
through a trap, it will travel to just before the trap and then stop,
allowing the player to choose to walk through it or continue.
(Credits: Suggestion for the change by nht.)
* It's no longer possible to fail to choose a direction for a spell;
NetHack 3.4.3 just repeats the last direction (perhaps killing the
player arbitrarily), AceHack 3.6.0 will keep prompting until a
direction is given.  Similar fixes apply to all other direction
prompts, which will keep prompting repeatedly until explicitly
cancelled (as spellcasting always requires a direction, it'll keep
prompting until one is given even /if/ explicitly cancelled).
Targeting prompts are also a little more explicit in what input they
want now, too.
*The player is now prompted upon attempting to eat something that the
character would know is dangerous even without magical aid (such as an
old or poisonous corpse).
*Instead of using engravings of the word "Elbereth" to protect against
hostile monsters, instead a special engraving type, the "magic
heptagram", is provided, which does the same thing and has the same
properties, but is easier on the interface.  (To draw it, use E-h, or
simply press .).  Unlike writing Elbereth, heptagrams do not exercise
wisdom.
*Cursed light-sources become marked as cursed when they fail to light
as a result.  (Patch credits: patch by rawrmage).
*Formally identifying light sources, or seeing them flicker, now makes
their remaining burn time visible (much like charges on formally
identified wands).
*Monsters now have their background color changed to show various
aspects of the monster (blue=tame, brown=peaceful, magenta=detected).
*(more http://patch-tag.com/r/ais523/acehack/snapshot/current/content/raw/doc/fixes36.0)
*underlined monsters
* ACEHACK CODED THINGS END
* Ace hack code - http://patch-tag.com/r/ais523/acehack/snapshots/all/history
* make #untrap less in need of repetition/spamming
* blanking sickness should formally ID it and fruit juice (?)
* a1 to light just one of a stack of candles
* removing armour while wearing a cloak should give a better message than “You can’t take that off.”
* you should also get YAFMs for throwing ring of levitation upwards
* various appropriate YAFMs when you kill Vlad with a non-weapon object (GreyKnight is supposedly writing a patch for this)
* occasionally substitute a “3.4.3 level” or “crawl level” for the rogue level
* Eating an orange while fumbling or with greasy hands: “Segmentation fault.”
* ID kicking boots when they make things reel
* option to stop autoexplore with unexplored objects in LOS
* name levels you aren’t on
* list wishes in dumplog etc
* warn on self-zaps of known dangerous wands
* ID base types of wished-for items
* attacking with polearms is utterly broken at interface level
* player polymorphed in monsters that is neither herbivorous nor carnivorous may eat corpses and tins
*  Have Medusa's passive gaze interact with monsters as it does with the player. (For fun, try bringing Medusa to bigroom for a lovely demonstration of this behaviour.) https://github.com/sgrunt/GruntHack/commit/ca041a03fed8e775f00daa1a78c8b60db490cee0 + https://github.com/sgrunt/GruntHack/commit/9ee62a54b5f99c36f1109bd6a3f37bc6e94f621b
* https://github.com/sgrunt/GruntHack/commit/aa718d95b38d6cab5dc80aed1ff7ccbc9fcfda90  Don't merge objects with different materials that are otherwise identical.
* http://www.reddit.com/r/roguelikes/comments/187k8d/dcss_dungeon_crawl_tetris/ - tetris
* random X turns of invulnerability - from god? From certain artefacts?
* If you ever have a gameplay mechanic that's such a no brainer that it can be automated, it should be cut. http://www.gamasutra.com/view/feature/6490/radical_rethink_how_100_rogues_.php?print=1
* [[dumping grounds]]
* http://www.reddit.com/r/roguelikedev/comments/kmf2r/100_rogues_developer_talks_about_roguelike_design/c2v8rbd
* http://www.reddit.com/r/roguelikedev/comments/16dva9/dungeon_generation_not_done_yet_but_a_start/
* A CONSTRAINED GROWTH METHOD FOR PROCEDURAL FLOOR PLAN GENERATION - http://graphics.tudelft.nl/~rval/papers/lopes.GAMEON10.pdf
* demon name generator - http://dorophone.blogspot.com/2012/02/almost-pure-random-demon-name-generator.html
* http://www.gruesomegames.com/blog/?p=198:
* Auto stairs use
* visual feedback instead of A misses X
* remove all containers from game (??)
* Restart Same Character / restart random character / new character
* http://nethackwiki.com/wiki/Autopickup_exception
* Sprintf(qbuf, "Which %s%s, Right or Left?", |||||preferred ring option
* Levitation + flying - https://sourceforge.net/apps/trac/unnethack/ticket/55
* Double rooms (Sporkhack) https://sourceforge.net/apps/trac/unnethack/ticket/80
* failing rock piercers - what about custom cause of dead description https://sourceforge.net/apps/trac/unnethack/ticket/132
* " "you crawl to the edge of the pit" it is rather not suitable for vampires" https://sourceforge.net/apps/trac/unnethack/ticket/58
* option to show also colours of identified potions in inventory - https://sourceforge.net/apps/trac/unnethack/ticket/126
* add #call - https://sourceforge.net/apps/trac/unnethack/ticket/71
* Repeat count for messages. In the example, all those lines about the cloak from the first turn could be condensed to "Your cloak of magic resistance is not affected (4x)." The hero cannot intervene anyway. - idea from https://sourceforge.net/apps/trac/unnethack/ticket/46
* #testarmorforAC
* autodetect enchantment of non-magical armor and weapon for knights and when polymorphed into mercenary
*  save and bones files accepted from versions
* http://nethackwiki.com/wiki/Key#Breakage
* http://www.darkshire.net/jhkim/rpg/lordoftherings/names.pdf
* "It's time for you to die again." 
* use 'spooky' flag
* Baruk Khazad! Khazad Ai-Menu!
* Today is a good day for someone else to die!
* "Prepare to be eviscerated! FOOL!" <^V http://tvtropes.org/pmwiki/pmwiki.php/Main/BattleCry
* "Remember Tunnel Seventeen!" 
* "I WILL CHOP YOUR HEAD OFF!" 
http://tvtropes.org/pmwiki/pmwiki.php/Main/WrittenRoar
http://tvtropes.org/pmwiki/pmwiki.php/Main/HorrorTropes
http://tvtropes.org/pmwiki/pmwiki.php/Main/ThisIndexIsCursed
http://tvtropes.org/pmwiki/pmwiki.php/Main/AppliedPhlebotinum
http://tvtropes.org/pmwiki/pmwiki.php/Main/PlotDevice
http://tvtropes.org/pmwiki/pmwiki.php/Main/TomeOfEldritchLore

* investigate SCORE_ON_BOTL
* "checking whether to enable" in configure + autoconf.h + autoconf.hin
* kill paging in guidebook
* bars for timeout of levitation, speed, protection, confuse monster on melee attack
* search for "YAFM needed", "performance", "optimization"
* exploded ring of levitation -> you float gently
* reduce u.ugold +hidden_gold
* https://github.com/sgrunt/GruntHack/commit/00fac16b796e33189b8f542160fd49d9ff8d790c - magical items generated more frequently at deeper dungeon levels
* kicking unidentified secret door
* http://bilious.alt.org/?440
* Allow looking at dungeon overview during level teleport prompt - from http://nethackwiki.com/wiki/Bugs_in_NetHack_4
* revamp https://github.com/Bulwersator/UnNetHackPlus/blob/master/README.configure (z windowsem z msdna)
* kill this 18/something strength
* http://nhqdb.alt.org/?168 http://nhqdb.alt.org/?663 http://nhqdb.alt.org/?686 http://nhqdb.alt.org/?8   http://nhqdb.alt.org/?311 http://nhqdb.alt.org/?71 http://nhqdb.alt.org/?85 http://nhqdb.alt.org/?49 http://nhqdb.alt.org/?354 http://nhqdb.alt.org/?448 http://nhqdb.alt.org/?448 http://nhqdb.alt.org/?314 http://nhqdb.alt.org/?245 http://nhqdb.alt.org/?259 http://nhqdb.alt.org/?235 http://nhqdb.alt.org/?236 http://nhqdb.alt.org/?611 
* http://nhqdb.alt.org/?latest
* http://nethackwiki.com/wiki/Talk:Cthulhu
* object icons appearing in menus, like on linux 
* list created monster without kills
* kill MAIL Removal possibility of enabling MAIL fixed following bugs: C343-165, C343-320, C343-415.
* enable SHOW_EXTINCT SHOW_BORN
* cleanup configure https://github.com/Bulwersator/CopyOfUnNetHack/commits/master/trunk/configure http://www.gnu.org/software/autoconf/manual/autoconf.html#Making-configure-Scripts http://www.gnu.org/software/autoconf/manual/autoconf.html#autoreconf-Invocation http://www.edwardrosten.com/code/autoconf/index.html
* esc on gen
* [[DFlike statues]]
* king names
* read state after spellbook name
* success state as colour for wizards (symbol?)
* http://doryen.eptalys.net/articles/bsp-dungeon-generation/
* http://doryen.eptalys.net/data/libtcod/doc/1.5.1/html2/namegen_file_4.html?c=false&cpp=false&cs=false&py=false&lua=false (king names)
* introduce and use full unicode support (see http://doryen.eptalys.net/forum/index.php?topic=1473.0 for potential)
* foocubi - A new challenge (celibacy) [from SLASH'EM] / all effects are bad / penalty for monk/knight.
* http://fantasynamegenerators.com/demon_names.php
* magic draining attack (cancellation???) - magic destroyer - yellow R (peaceful NPCish???)? - yellow V?
* monsters are not getting poison resistance from worn dragon scale mail
* merge uhitm, mhitm, mhitu etc
* amulet versus poison searches_for_item
mon_reflects
m_dowear_type
* https://github.com/tung/NitroHack/commit/206f8427deefee0e87110c6f93f1df49fa31e9e3
* https://github.com/Chris-plus-alphanumericgibberish/dnethack/commit/310da13976ab30e9db08f73e94aafab96ff1ac41
* http://bilious.alt.org/?151
* autotravel and stopping for engravings
* monster with tele= resist \ of tele
* https://github.com/tung/NitroHack/wiki - UnNetHack bug fixes (not already in UnNetHack)
* wishing for unidentified dragon mail by power is not supposed to work (UnH)
* fast travel should not stop on graves
* save vibrating square in dungeon overwiev
* autotravel, traps (squaky, pits) and pernament levitation
* https://github.com/Bulwersator/CopyOfSporkHack/commit/5832f415db395a31c23ac37c7e954185e2b0425c  - stun happening during travel
* switch sleeping for cold attack for nazgul (maybe)
* death texts by quest nemesis are not case devteam thinks about everything, as they may be killed is some other way (also: picking up quest artifact with alive nemesis)
* gold <-> trap detection
* Ixoth will have reflection from the Magic Mirror, so there's no point in using attack wands or spells. In vanilla, he will have magic resistance instead of reflection, so those items and abilities might actually be worthwhile.
* yellow dragon scale mail provides immunity to stunning and confusion
* intrinsic_possible fully_identify_obj
* [[encyclopedia]]
* https://github.com/Bulwersator/CopyOfSporkHack/commit/68be37ef17c95024eb28e25820b7534d43478166
* MAGIC_MARKER as gift (type in object generator), later TRUE to initialize and TRUE to make artifact one :) http://nethackwiki.com/wiki/Source:Ref/mksobj#mksobj
* http://nethackwiki.com/wiki/Source:Polyself.c#line629
* fix cannibalism among sentient pets (BTW, scroll of taming affecting sentient creatures is quite disturbing) 
* http://bilious.alt.org/?288 Confused Magic Whistle
* mark E-square
* http://nethackwiki.com/wiki/Pet#Armor_and_extrinsics http://nethackwiki.com/wiki/Armor#Monsters_.28pets.29_and_armor
* I wouldn't beef up the Kops themselves, since they are supposed to be wimpy.  But do I like the idea of them calling in the guard when they are up against an overwhelming erm, well, an opponent. http://bilious.alt.org/rgrn/?126678,126685,126686,126690,126691,126692,126694,126695,126696,126697,126698,126703,126704,126705,126709,126710,126713,126714,126724,127665
* Incidentally, there's a way to pacify the Minetown Watch in most cases. First, get a stack of blessed teleport scrolls. Teleport from the staircase to the inside of a shop, pick up an item, and then teleport right outside the entrance of that shop (but not in a line from the door!). As soon as the shopkeeper comes out to kill you, pay him for the thing you stole. The Watch will decide that since you are no longer a thief, it follows that you are no longer a criminal.
* Most of the item-type-specific commands like "quaff" or "read" have been merged into a single "use" command http://te4.org/news
* http://nethackwiki.com/wiki/User:Ion_frigate#Add_a_little_spice_to_the_game http://crawl.chaosforge.org/Crawl_Wiki
* cap HP regenaration at normal maxHP value (external regeneration, spells and potions still work) - see maxHP cap in spork
* confused/stunned magic mapping causes you to forget current level (useful during search for vibrating square)
* topten.c tt_oname - use names from NAO (?)
* nethack.alt.org, there is an option (hilite_hidden_stairs) http://bilious.alt.org/?433
* new level generator (moria, see newsgroup, http://imgur.com/d6NWagD)
* the alignment system  a complete overhaul 
* make stupid water noticeable different from stupid fountains
* http://nethackwiki.com/wiki/W343-3
* https://github.com/Bulwersator/CopyOfSporkHack/commit/21de56b16793ec139ea0859cbec29c40c4072309 Non-mindless monsters will no longer blindly walk into traps they've seen
* https://github.com/Bulwersator/CopyOfSporkHack/commit/b66820f04b9b8f98a822e8b1df719fd55ee07726  RANDOM_CORRIDORS now takes an optional parameter. 
* https://github.com/Bulwersator/CopyOfSporkHack/commit/4c434e30415c3cd1d5efeeab1ae2c1dc903aa034  Use any style random corridors 10% of the time. 
* https://github.com/Bulwersator/CopyOfSporkHack/commit/71bff8cb89b7e7f91f6478ea9c89f9f88195b174  Wand of nothing shall ask for direction when zapped in some games. 
* http://bilious.alt.org/?265  http://bilious.alt.org/?81 http://bilious.alt.org/?227 http://bilious.alt.org/?234 http://bilious.alt.org/?238 http://bilious.alt.org/?221
* http://i295.photobucket.com/albums/mm153/Kobold_Lord/Sporkhack%208/T23231.jpg
* spork - "A number of game breakers, like the rubber chicken and the E-square, have been reigned in."
* spork - "Two-weapon fighting is no longer your automatic only choice regardless of role. Two-handed weapons and sword-and-board have meaningful advantages."
* In Spork, two-handed weapons double your effective strength bonus to damage. This makes them actually worth using.
* https://github.com/Bulwersator/CopyOfSporkHack/commit/edd6a79da80913f8c9ccd6a90dc891357371d64c  Add potential for hostile priests to summon "associates". 
* https://github.com/Bulwersator/CopyOfSporkHack/commit/7fbd5b30b90f35f1af745c77fe7fe93504ae1f16  The circular bigroom may have a river. 
* do_wear.c dotakeoff function - merge RT
* [[threats]]
* turn throne in perks for gold object
* see Linley's Dungeon Crawl on nethackwiki
* vaults - see crawl and https://github.com/Bulwersator/CopyOfSporkHack/commit/cd21033f22b5e9e7ef318ea1a1b9dd76c8351bfa
* Stun_resistance from spork - see https://github.com/Bulwersator/UnNetHackPlus/commit/b2b61283f6040af63e454a880129a3c4c22e84a5
* nethackwiki.com/wiki/Stunned#cite_note-1 - wtf?
* http://l.j-factor.com/nethack/wounds.diff
* http://l.j-factor.com/nethack/wallcorr.diff
* http://l.j-factor.com/nethack/construct.diff
* https://github.com/Bulwersator/CopyOfSporkHack/commit/161eec3c4e0e06cab3f70b28e34b95a37f368918 -  Major alignment changes.
* I, and a few others, think magic resistance is too general an
attribute, covering too many scenarios. I reckon it should be split up
into mana/magic missile resistance (which gray DSM would confer), spell
resistance, and death resistance. While spell resistance would remain a
high priority, the others would be precautionary measures (much like
acid resistance is now.) https://groups.google.com/forum/?fromgroups=#!topic/rec.games.roguelike.nethack/TrtHf-9b8SU 
* https://github.com/Bulwersator/CopyOfSporkHack/commit/a7a1de62a901e7f4521a5bdd2bf4474320315d2a (? - add modified code???)
* https://github.com/Bulwersator/CopyOfSporkHack/commit/70941c87feb74c63d0d4ca9bbd925ff909722117 -  Death's touch should hurt monsters/pets 
* https://github.com/Bulwersator/CopyOfSporkHack/commit/8bd8d8b90a6f95344e3c4798a9f0ae802b6a35eb with https://github.com/Bulwersator/CopyOfSporkHack/commit/1f8b526808eeae0ed6472b2b3408743822e814d1
* https://github.com/Bulwersator/CopyOfSporkHack/commit/c0872effd197e43286b0447289688c94f6bccf16 (restore frontier)
* https://github.com/Bulwersator/CopyOfSporkHack/commit/904e29f56a2a8dd2a15b97cd4d96780f9021b24b - more balanced bones
* https://github.com/Bulwersator/CopyOfSporkHack/commit/dfb47e58a21a9e50a60245309f1c91ec53310457 -  Scared covetous monsters should actually 'flee' to someplace not near the player.  Note that this doesn't include STRAT_HEAL, only magical sources of fear.
* https://groups.google.com/forum/?fromgroups=#!msg/rec.games.roguelike.nethack/vspJEm0wwJ0/QDWJeqjn1HQJ
* http://web.archive.org/web/20080309115104/http://www.csh.rit.edu/~topher/nethack/
* https://github.com/DanielT/NitroHack/commits/master
* http://nethackwiki.com/wiki/NetHack_4
* atop looting from asking infuriating ynq, skip for single container, show list for multiple ones (the same for eating)
* read everything! (http://en.wikipedia.org/wiki/List_of_S-phrases and http://en.wikipedia.org/wiki/GHS_hazard_statement for wands/!)
fix completely broken alignment, maybe also better gods
* Eliminate tedious things
* ban selling
* Minetown non-diggable (to stop stupid dwarfs)
* redraw resistant hallu
* gradual hallu
* G, h in gnomish mines shouldn't walk into their own ^
* stinking cloud should be cyan something
* http://i295.photobucket.com/albums/mm153/Kobold_Lord/Sporkhack%202/T29316.jpg
* devastating Wand of Death, which would shave hit points off of Mouse's MAXIMUM every time it hits him even if his amulet reflects the killing charge
* Beware the Minetown bones file where the altar has been converted. The priest present may be peaceful, but he or she will go hostile if you #chat.
*  Gems the unicorn keeps are worth +2 luck, and the unicorn doesn't care if they're diamonds or turquoise. If it becomes convenient later, you can bring a strong pet to withdraw your deposit from the Bank of Uni, but I don't always bother. (make only alive unicorns bring luck)
* http://i295.photobucket.com/albums/mm153/Kobold_Lord/Sporkhack%202/T554883.jpg The Master of Assassins hasn't died yet (telewand)
* http://i295.photobucket.com/albums/mm153/Kobold_Lord/Sporkhack%202/T63823.jpg
* verbalize("Get %s, you fools, or I'll have your figgin on a stick!",uhim());
* taunts
* http://i295.photobucket.com/albums/mm153/Kobold_Lord/Sporkhack%202/T645341.jpg http://i295.photobucket.com/albums/mm153/Kobold_Lord/Sporkhack%202/T645342.jpg This message is caused by a new divine monster spell. The hill giant shaman has just inflicted the cold vulnerability intrinsic on Mouse. It eventually wears off, but until then Mouse will take heavy damage from cold attacks even though he has 100% cold resistance. You REALLY do not want to get hit by cold attacks if you have cold vulnerability and 0% cold resistance.
*  This is the ideal place to settle in when clearing the Zoo at Fort Ludios. Doors have the interesting property that even when they are opened, you can only go through them straight on. The monsters have to single file through three tiles, and in the last of the three they'll stop to fight Spelunky. Until she kills the monster she faces, the others will get jammed behind it. None of them can line up to zap a wand, either, until they're already in melee with Spelunky. http://i295.photobucket.com/albums/mm153/Kobold_Lord/Sporkhack%203/T28982.jpg
*  Formally identifying the Amulet of Yendor now. Wouldn't do to pick up one of the Wizard's fakes. In vanilla, there's an easy test: try putting it in your bag. The Amulet of Yendor will refuse to enter a container, but the fakes go in easily. That's been changed in Sporkhack, so bring a means of identification just in case. The #name trick still works.
*  Angels are MUCH more dangerous in Sporkhack than in vanilla. Their most damaging attack in either version is a powerful stream of magic missiles. In vanilla, all magic missile attacks are completely nullified by either reflection or magic resistance, leaving the angels with only fairly ordinary attacks and magic. In Sporkhack, reflection and magic resistance only cut magic missile damage in half! So Spelunky will still take partial damage from all the angels pelting her from every angle, even as she faces Pestilence! The half spell damage from the Orb of Detection will still help, though… She will take 1/8 the normal damage of the attack each time. Most other roles will have a much tougher time keeping the angels away, since magic resistance and reflection combined is still 1/4 of a whole lot of damage.
*  Oh, if you're wondering why nobody else came in, Spelunky locked the door. Angels and aligned priests almost never carry keys, and even if they did, Spelunky could change plans and run for the altar.
* Dark One knows many different arcane spells. While nowhere near the hardest of the quest nemeses, the Dark One still demands respect! Mind you, he demands respect a whole lot more effectively in Slash'EM, where he knows Summon Nasties and Touch of Death. Sporkhack hasn't really done much to make him more hardcore.
* wizard quest flavor text - Um, what? Weren't you dying without that thing, or something? Maybe the Dark One was specifically doing something to the Eye of the Aethiopica that put Neferet the Green at risk? Well, swapping out the regular amulet of power for the Eye. Deciding not to worry about the fanwank explanation
*  In Sporkhack, there's a small chance a polymorph trap will disappear each time a monster uses it, so if you get something good you want to stop right there. Gyrfalcon had some mediocre forms, but now he's stuck as an imp until I can find another polytrap. In vanilla, of course, I can keep going until I like what I see or I end up with a pet gray dragon (which is a good pet anyway).
* randomised valley from spork
*  Got it! Giantslayer is an artifact sling. It does more damage than normal slings and provides warning against giants, but since slings suck that part is meaningless noise. The important feature of Giantslayer is that it provides near-giant strength when wielded… OR when it is set up as an alternate weapon. So as long as you're not planning to dual-wield (and monks like me clearly are not) you get an effect almost equivalent to slotless gauntlets of power. And unlike the gauntlets, Giantslayer does not interfere with spellcasting!
* give levitation/teleport control to Sam with random chance (1/3?) to stop trivial ways to kill him
* force player to stay in polymorphed form rather than kill 
* http://forum.rpg.net/showthread.php?466187-(Let-s-Play!)-Sporkhack/page81
* split room from spork
*  Mars grants Nefarious with the gift of Dragonbane, an artifact spear. As I've said before, vanilla bane artifacts are uniformly crap, but in Sporkhack Dragonbane in particular is startlingly good, especially early on. Wielding it grants fire, cold, poison, shock, sleep, acid, and disintegration resistance. No, that isn't a typo. You get all of them, and at 100%. Fantastic weapon for conducts. It also has the usual anti-dragon properties, like all bane weapons.
* remove pet apport
* identify projectiles - for Rangers http://nh.gmuf.com/ranger_ammo-343.diff
* nerf speed boots
* https://github.com/Bulwersator/CopyOfSporkHack/commit/b6bf67e56332fe1e4852cfad2b926da2f216559a
* https://github.com/Bulwersator/CopyOfSporkHack/commit/dbb7e37a081c6280d50d75cfd7b2e2e801a8354b 
* https://github.com/Bulwersator/CopyOfSporkHack/commit/586f1855f856437d4cfa725d6ea164ee4d93a09c (fix to one of above)
* https://github.com/Bulwersator/CopyOfSporkHack/commit/05b6dbfc2247fb0194bc58df6c04c278c4149fa0
* https://github.com/Bulwersator/CopyOfSporkHack/commit/03be90768097959dcd3e062d46c9a9afc89f77fe
* https://github.com/Bulwersator/CopyOfSporkHack/commit/cd21033f22b5e9e7ef318ea1a1b9dd76c8351bfa
* water damage to flaming spheres (losehp(dam, "drenching", KILLED_BY); in https://github.com/Chris-plus-alphanumericgibberish/dnethack/blob/f167bb7bd5568288c1e54f7581ae34499d7945fd/dnethack-3.4.3/src/trap.c)
* When I found the black market (the portal was on the nymphs level), I 
had a few thousand zorkmids prepared. I wanted to buy a magic whistle. 
But all whistles in the shop were tin ones. I was somewhat desperate, 
until I realized that I could have solved my problem much earlier. I did 
have a tin whistle even from mine town (tried whether using it would 
train my pets to come to the stairs, but could not see any effect). I 
also had a potion of gain level. And now I remembered (didn't I say my 
game skills were rusty?) that you can use potions of gain level to 
upgrade objects. I dipped the tin whistle into the potion and was the 
proud owner of a magic whistle.
* unflee zombies on low HP
* Dragons will never breath in melee combat.
* Only your quest Nemeses will deliberately steal your quest artifact, other monsters may steal the amulet and invocation items. The quest artifact may of course be randomly stolen by nymphs and the like.  -Makes QA a dependable source of extrinsics, deepening differences between classes. -dnethack
* oversight: you can #chat while being choked by a rope golem ("strangulation seem to be handled okay)
* wounded legs, healing
#savebreaking?
* http://bilious.alt.org/?63
* remove grinding spells (create monster, polymorph, cancellation(?)) and introduce something interesting - see http://www.reddit.com/r/roguelikes/comments/18msat/is_there_a_roguelike_with_interesting_spells/ 
* TRAPROOM from spork
* https://github.com/Bulwersator/CopyOfSporkHack/commit/d5f208b70d606071a5829526e4806dab0e87832a  Increase missile weapon range from properly fired missiles. 
* http://bilious.alt.org/?271
* fly monster spell - https://github.com/Bulwersator/CopyOfSporkHack/commit/d6ae5c1cba40bd5f04f11c2e6e6205ad1486992f + https://github.com/Bulwersator/CopyOfSporkHack/commit/cd5b178b692e2c34276486aa11032107263ca167

#savebreaking
* reduce amount of polearms
* depaladinise knight - replace the Mirror with artifact lance/shield/saddle
* http://www.statslab.cam.ac.uk/~eva/slashem/wands.html
** http://nethackwiki.com/wiki/Wand_of_fireball
* spellbook of repair armor (spork?)
* new randomized appearances - see https://github.com/Bulwersator/UnNetHackPlus/compare/master...new-randomized-appearances
* https://github.com/Bulwersator/CopyOfSporkHack/commit/aee3b3d35defc3ec60611337450c071340359217 (??)
* https://github.com/Bulwersator/CopyOfSporkHack/commit/c89f6e57eb16e81bd37920096c6f64dfed725b03 (+later fix)
* https://github.com/Bulwersator/CopyOfSporkHack/commit/5d10dd556b1d511b248e67f5882b0d2ffaff580d (range for telepathy)
* silver boots + https://github.com/Chris-plus-alphanumericgibberish/dnethack/commit/f167bb7bd5568288c1e54f7581ae34499d7945fd (dokick edit)
* https://github.com/Bulwersator/CopyOfSporkHack/commit/4bf67bd1aea2d321b8c90b3de0de5f4c269a2500
* investigate helm of clarity from spork
* save last enlightenment status
* nets and/or "web" spell
* https://github.com/Bulwersator/CopyOfSporkHack/commit/5ab7c1816e7cfbc0dbddc84eedc0a39664569bc4 + https://github.com/Bulwersator/CopyOfSporkHack/commit/ceb3cf0a3407a7decc28fc1aea77718621a6151e + https://github.com/Bulwersator/CopyOfSporkHack/commit/852de1ae27cef0a74d54bd763741bd50deb76d0e + https://github.com/Bulwersator/CopyOfSporkHack/commit/304054d8c3c85fa7c8256391a3236d3c8ec78326 Add shambling horror; a creature with random stats each game. 
* https://github.com/Bulwersator/CopyOfSporkHack/commit/4514f5a8d55ea4464a1ec9f49240b471fe552e8b  To differentiate wood nymphs, let them walk through trees. 
* https://github.com/Bulwersator/CopyOfSporkHack/commit/1ab79a0cc9400051cdf77a1a161c1af463bdfe09 -  Leaving bones behind may also leave your skull. 
* https://github.com/Bulwersator/CopyOfSporkHack/commit/5e28bfdf1cf777b81baecc261bfd26f26bbf204b - interesting Juiblex + https://github.com/Bulwersator/CopyOfSporkHack/commit/b543698d53aed8ce7031ee6620ac631005894960
* http://bilious.alt.org/?309
* http://bilious.alt.org/?200 add-on to above, savefriendly
* http://bilious.alt.org/?359 
* http://l.j-factor.com/nethack/quaff.diff
* http://l.j-factor.com/nethack/monring.diff (savebreaking)
* http://l.j-factor.com/nethack/shuffled.diff
* braziers from spork?

# redigest?
* http://l.j-factor.com/nethack/colour.diff
* http://bilious.alt.org/?352

# too complicated
* http://bilious.alt.org/?183
* http://bilious.alt.org/?165
* http://bilious.alt.org/?212
* http://bilious.alt.org/?307
* http://bilious.alt.org/?77
* http://bilious.alt.org/?312
* http://bilious.alt.org/?13 - unhappy about "Eggsucker" and "Bushwacker", samurai untested
* http://bilious.alt.org/?241 (what about sokoban, rogue quest etc?)
* http://bilious.alt.org/?211
* http://bilious.alt.org/?222
* http://bilious.alt.org/?297
* http://bilious.alt.org/?37
* http://bilious.alt.org/?248 - save/load not persistent, not loading from settings...
* http://bilious.alt.org/?99
* http://bilious.alt.org/?259
* move bogus name generators to separate file
* http://bilious.alt.org/?275
* http://bilious.alt.org/?181 
* http://bilious.alt.org/?92 http://bilious.alt.org/?184 http://bilious.alt.org/?259
* http://bilious.alt.org/?433
* http://bilious.alt.org/?194
* http://l.j-factor.com/nethack/sphere.diff -     Flaming, freezing and shocking spheres now make nine-square explosions when they attack.     Blessed scrolls of fire do not harm the reader, and do more damage.     The source code for explode.c is substantially improved.
* slash fungus growth
* https://github.com/Bulwersator/CopyOfSporkHack/commit/58ff6cbb1a8b9af427353d5e17d862100ca92cae and https://github.com/Bulwersator/CopyOfSporkHack/commit/8d7660680d447251a6eb5fe1160c83c514bfad2f - rusty tools can break
* in dothrow.c consume food in "not tmiss(), which angers non-tame monsters" case with proper message
* https://github.com/Bulwersator/CopyOfSporkHack/commit/2a248d08bfe4bd0a38350ffd8b1efd0240df71b2 - improve monster AI
* http://l.j-factor.com/nethack/aleax.diff
* http://l.j-factor.com/nethack/mirrorfix.diff
* https://github.com/Bulwersator/CopyOfSporkHack/commit/ea5d0c8094e0577f7054ab24447c7ae2990d49c2 - fighting makes noise - it should be done also for mhitm, mhitu + https://github.com/Bulwersator/CopyOfSporkHack/commit/0c4c2c84ea79972e28eb02979ac863dff79abdaf 
* from angry_priest() - priests should try to reconvert altar back- in the middle of spaghetti code - see  http://bilious.alt.org/?38
* https://github.com/Bulwersator/CopyOfSporkHack/commit/dea61cde17b8758091e3f3cef95c2d651d11cb3e - When attacking a peaceful monster, make other peaceful monsters react.  - in the middle of spaghetti code
* on savegame mismatch game eats the save

# no playtesting
*  Ixoth's stats are somewhat higher than they are in vanilla. In vanilla, Ixoth is physically substantially weaker than other dragons.
* http://www.reddit.com/r/roguelikes/comments/1bt3ip/i_would_welcome_help_in_increasing_variation_of/c9aafv2
* https://github.com/Bulwersator/CopyOfSporkHack/commit/cdb0add92fed422e61860b7c88711b347cd17b5f + https://github.com/Bulwersator/CopyOfSporkHack/commit/d25452bdea84850ada1674a7fefa343f66a9264c - time increases monster generation
* https://github.com/Bulwersator/CopyOfSporkHack/commit/cbc86197bf6a8d63532069fa153a946bbb5b946c
* https://github.com/Bulwersator/CopyOfSporkHack/commit/cece069f9d1465ebb7d388d4b2fae572bd8e0e48
* https://github.com/Bulwersator/CopyOfSporkHack/commit/5d866cb42f695a0df8a1e0266bd4e7f38ce2c227  Change covetous monster behavior -- when pursuing you, follow in slightly random shorter jumps, no more than about 6-7 squares
* https://github.com/Bulwersator/CopyOfSporkHack/commit/71dfbdb54ccbc800cc86ccdb7ed762f45658c90a - reduce amount of gold
* https://github.com/Bulwersator/CopyOfSporkHack/commit/b1bfbb10c01b5a699f7310b5f54589731c480e26
* https://github.com/Bulwersator/CopyOfSporkHack/commit/5810788cb6be40e7bed05eff6f263bb9d9f227ae
* https://github.com/Bulwersator/CopyOfSporkHack/commit/d941e6280fcaefeaf063bdf76caae6db5130d453
* https://github.com/Bulwersator/CopyOfSporkHack/commit/6aad5972e03d2edc7e678f71c0159e62374d561c
* nethackwiki.com/wiki/Minion - ++
* https://github.com/Bulwersator/CopyOfSporkHack/commit/a8ed6b03fcd3787e64bd6a0741f8a9934095a953 -  Goblins now small-group monsters. (makes start worse)
* https://github.com/Bulwersator/CopyOfSporkHack/commit/cfd432185d2598d2caed18128ee0e3ba8a188723 Hot/cold game with the Amulet no longer requires you to wield/wear it, just carry it.
* http://bilious.alt.org/?178
* http://bilious.alt.org/?151
* https://github.com/Bulwersator/CopyOfSporkHack/commit/570505fe436ae9f29bfbd8a7d99c64dfc4ac74f5
* https://github.com/Bulwersator/CopyOfSporkHack/commit/b45d6547809b891a1b30533581f43520b32666eb (caveman gruntubugfix)
* https://github.com/Bulwersator/CopyOfSporkHack/commit/72c10822290cb4f1e6dac1230da0ebe5935455d0 - nerf Elbereth
* https://github.com/Bulwersator/CopyOfSporkHack/commit/dabb85b77535dff9825d56f77ffbc1d19494dcb3 -  MC3 reduced to 90% 
* https://github.com/Bulwersator/CopyOfSporkHack/commit/73b66b0217a8015ff1cbbce6813253b881f61009 - nerf Antimagic, power up Angels
* https://github.com/Bulwersator/CopyOfSporkHack/commit/92ea2514c68e84f30da79d471f2b5e3751471bd6 -  Make caveman quest levels have some more variance 
* https://github.com/Bulwersator/CopyOfSporkHack/commit/11dec2a485b7319773840e6a0d76d239e0f0e1ab - nerf reflection
* https://github.com/Bulwersator/CopyOfSporkHack/commit/6d08cf5c7272d95b838fc3aefb616a773af24829 - more flee messages (wtf)
* https://github.com/Bulwersator/CopyOfSporkHack/commit/fd39d6e162d7c9d5e8024df3301c5ff5e4c28634 -  Poly traps may go away as monsters (and your pet) use them. 
* http://l.j-factor.com/nethack/spells.diff
* http://l.j-factor.com/nethack/deathdrop.diff
* https://github.com/sgrunt/GruntHack/commit/a06d2f7e3c734768f608df8d5a873fd583dfb394
* https://github.com/Bulwersator/CopyOfSporkHack/commit/794cc90b031ee1d5bfa71dca209797492441d927  Significantly upgrade the chance of a footrice's hissing attack starting the stoning process -- if it hits, of course.

#na playtesting and savegame breaking
* Sporkhack has added some racial equipment for gnomes to wear.

#unable to test
* https://github.com/Bulwersator/CopyOfSporkHack/commit/4a6337948eb34e2c0dbf4ec2609316d6dafcf234
 
#un synchronisation
* switch punisher to red (?)
* UnNH - (update through 1052 means enabling locust in data.base)
* after Un.1242 .des - possibility to make drawbridge status random, see https://github.com/Bulwersator/CopyOfSporkHack/commit/1032af2e5b88947b828cdc89a062adb1178fbe5a
* weeping angels - blinking effect - long, rare move (what about blindness? Should it be instant YASD?) pschysical attacks, trap autoturned into statue trap
* mark "Picking up gold doesn't honor the setting of pickup_burden if the game is compiled without GOLD_OBJ (no prompt when the encumbrance level is exceeded)." and "impossible() can mangle the parameter values." in http://nethackwiki.com/wiki/User:Bulwersator/UnNetHackPlus_bug_tracking as fixed
* deep orc color (black? white uruk-hai?)

#recheck
* [[petfruitnames]] http://alt.org/nethack/petnames.html
* [[alt.org - NetHack Addi(c)tion: Current Random Messages]] http://www.alt.org/nethack/addmsgs/viewmsgs.php
* https://gitorious.org/nitrohack/ais523/commits/nicehack
* http://alt.org/nethack/naonh.php graves checked out 9 I - new hallucinatory monster names, random engravings, gravestones and T-shirt messages
* https://github.com/Chris-plus-alphanumericgibberish/dnethack/commits/master (2 II)
* sporkhack (AFAIK, it is dead - but checking will not hurt)
* Medusa petrifications: NAO: http://www.reddit.com/r/bulwersator/comments/17keai/tesyst/c86alx9 Un http://un.nethack.nu/cause/petrified+by+Medusa

#texts
* Juiblex the Lord of the Slime Pit, Demon Lord of Oozes and All Things Most Foul.
* I dunno, I often hear this about Roguelikes and other really hard games, and to the extent that it's true at all, it assumes that the player has read and memorized every single spoiler and knows that (say) Blue-Footed Foozles can be defeated by harsh language but will explode with 40-kiloton yield if struck by any spell or weapon.
* There's a few mimics in the shop, too; they're cunningly disguised as ], which represents 'strange object or mimic' and is used for no purpose in the game other than representing poorly-disguised mimics.

#help!
* Gargoyle weirdness (There are animated statues so it is logical that they are stone resistant. On the other hand their flesh is edible. I want to turn them into statue leaving monster like stone golem - but what should happen with stone monster hit by stone to flesh spell? Turn into meatball as for statues of monsters without corpses? Resist as their stone is also body? Do nothing? Eat significant part of HP (body of foo decays into twisted flesh)? Something else? )

#make patches
* pray.c
* generate eroded items (latest: https://github.com/Bulwersator/UnNetHackPlus/commit/c771fadad677e8baaf34478f3961aae888a33685)
* hallu
* read/eat tins
* encyclopedia
* https://github.com/Bulwersator/UnNetHackPlus/commit/b84a4ea14b454c1f0bd6f4aef3e604166d7fc759 + https://github.com/Bulwersator/UnNetHackPlus/commit/171d80a650da06c947e32c2cfc3499907693ba8a -  player statues near Medusa based on real events 
* sporky ToD, destroy armor
* reduce sparkling - https://github.com/Bulwersator/UnNetHackPlus/commit/e3ea95833de16c3dfecc44f3c69058866961d32c
* more maledictions - https://github.com/Bulwersator/UnNetHackPlus/commit/f0a4d9ec0471da9514909a6d565a30eee0c35408
* https://github.com/Bulwersator/UnNetHackPlus/commit/a638a9d477800409998e1c9ec8a5b8c92ce95876  Nerf The Eye of the Aethiopica energy production 
* https://github.com/Bulwersator/UnNetHackPlus/commit/1d9ff4a8f2b7c3c8da062d8e974a9f4f684607d9  Add the gnome king and wizard defending cellar 
*  src/u_init.c 
* autoidentify wands - https://github.com/Bulwersator/UnNetHackPlus/commit/46c2ddcb606a38d3d1e2c54de57a1c38f8a1eb1c

#thanks
* KoboldLord for http://forum.rpg.net/showthread.php?466187-%28Let-s-Play!%29-Sporkhack/page1
* nethack, unnethack, sporkhack (Derek Ray), dnethack (Chris), grunthack (SGrunt) developers
* paxed, unserver keeper (medusa deaths)
* authors of patches ("L" - Leon Arnott)
* bhaak for help
* http://www.reddit.com/r/roguelikes/comments/1b3o9f/a_directory_of_directories_of_random_generators_a/

#spam
* http://www.tt-forums.net/viewtopic.php?f=2&t=19187
* rgrn
* /r/nethack
* /r/roguelikes