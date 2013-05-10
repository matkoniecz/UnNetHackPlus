Like other [[NetHack]] [[variant]]s, [[UnNetHackPlus]] has bugs. This page tracks the status of the [[Bugs in NetHack 3.4.3]] in UnNetHackPlus, (new bugs introduced in UnNetHackPlus are tracked at https://github.com/Bulwersator/UnNetHackPlus/issues and [[UnNetHack]] bugs at http://sourceforge.net/apps/trac/unnethack/report/1).

Special thanks to everyone who helped to compile this list.

UnNetHackPlus's developer would appreciate feedback on these bugs, especially the ones marked as "Help" (if anyone knows what these bug reports mean, please [[User talk:Bulwersator/UnNetHackPlus bug tracking|let me know!]]).

Key:

{| class="prettytable striped"
!Status!!Description
|-
|{{/bugstatus|Unknown}}||Status of bug is unknown.
|-
|{{/bugstatus|Fix available}}||The bug has a fix available for it in some other variant, but that fix has not yet been merged into UnNetHackPlus.
|-
|{{/bugstatus|Help}}||It is not clear what the bug description refers to.
|-
|{{/bugstatus|Upstream}}||The bug is fixed in UnNetHack, change waits for porting to UnNetHackPlus.
|-
|{{/bugstatus|Confirmed}}||The bug has been reproduced in UnNetHackPlus.
|-
|{{/bugstatus|Moot}}||The bug's context no longer exists in UnNetHackPlus.
|-
|{{/bugstatus|Not a bug}}||Not a bug, but may be considered as one.
|-
|{{/bugstatus|Useless}}||The bug's description is useless.
|-
|{{/bugstatus|Fixed}}||The bug existed in UnNetHack or UnNetHackPlus and was fixed.
|}

== Core bugs ==
{| class="prettytable sortable striped"
!Name!!Status!!Patch!!Description !! Additional info
|-
|{{va|C341-1}}
|{{/bugstatus|Moot}}|| ||[[Monsters]] affected by [[stinking cloud]] always get angry at the hero even if the hero did not create the cloud. || The bug is actually mostly fixed in NetHack 3.4.3, with one minor exception; the bug will still occur if loading a [[bones file]] from an older game in the 3.4 series.
|-
|{{va|C341-4}}
|{{/bugstatus|Unknown}}|| ||[[opthelp]] does not list [[use_inverse]]
|-
|{{va|C341-5}}
|{{/bugstatus|Help}}|| ||When you see your [[pet]] move, the pet may be referred to as "it".
|What are the circumstances in which this occurs? (clarification request send to DevTeam at 2013-04-24)
|-
|{{va|C341-7}}
|{{/bugstatus|Unknown}}|| ||[[Skilled]] or [[expert]] caster of [[fireball]]/[[cone of cold]] can't target a [[monster]] known only by [[infravision]] or [[ESP]]. ||  Fixed by Grunt. 
|-
|{{va|C341-10}}
|{{/bugstatus|Unknown}}|| ||[[Fruit]] names ending in "us" are incorrectly considered plural. ||  Clearly singular -us words that someone might conceivably use as a slime-mold name include cactus, lotus, fetus, octopus, platypus, torus, walrus; clearly plural ones include caribous, kudzus, marabous, menus, zebus; ones that can be either include asparagus, acanthus; adjectives include citrus, nutritious. Asparagus (the only one that's widely considered a food in the English-speaking world) and lotus (due to famously being eaten in the Odyssey) are the only such words that are even vaguely likely to turn up (unless someone is being deliberately over-the-top silly, in which case they deserve whatever weird message the game gives them). 
|-
|{{va|C341-18}}
|{{/bugstatus|Unknown}}|| ||[[ki-rin]]s and [[couatl]]s can wear (and may have) [[armor]]. || Shields, boots, gloves, and (non-metallic for ki-rin) helmets. Fixed by Grunt. 
|-
|{{va|C342-12}}
|{{/bugstatus|Help}}|| ||There are a number of places that misuse "your".
|What are these places? 
|-
|{{va|C342-13}}
|{{/bugstatus|Unknown}}|| ||[[Hangup]] can cause loss of [[objects]] being moved internally.
|What are the circumstances in which this will occur? 
|-
|{{va|C342-16}}
|{{/bugstatus|Unknown}}|| ||If you self-[[genocide]] while [[polymorph]]ed, the death message makes no sense. ||  "You return to [racial] form. DYWYPI?" GruntHack changes this to "As you return to [racial] form, you die." 
|-
|{{va|C342-19}}
|{{/bugstatus|Unknown}}|| ||Things that can kill you in the future (like [[stoning]]) can cause messages to show up out of order. ||  "You are a statue. Your skin begins to peel away." Fixed in GruntHack. 
|-
|{{va|C342-22}}
|{{/bugstatus|Unknown}}|| ||[[Monsters]] can [[hide]] under [[cockatrice corpse]]s without getting stoned. ||Also: "You [[sit]] on the cockatrice corpse. It is not very comfortable."  GruntHack contains a fix for this. 
|-
|{{va|C342-31}}
|{{/bugstatus|Help}}|| ||You can get a message telling you a [[monster]] wields a [[weapon]] it already was [[wield]]ing.
| It's not clear how to reproduce this.  There's a FIXME at line 616 in weapon.c that could potentially be (indirectly) related. 
|-
|{{va|C342-36}}
|{{/bugstatus|Unknown}}|| ||If unable to see yourself while [[invisible]] and you are bestowed a [[spellbook]], it doesn't show up on the display.
|-
|{{va|C342-46}}
|{{/bugstatus|Unknown}}|| ||Cleric cast [[lightning]] doesn't blind as other lightning does. ||  Refers to the monster cleric spell, CLC_LIGHTNING. GruntHack fixes this. 
|-
|{{va|C342-50}}
|{{/bugstatus|Unknown}}|| ||If you're hiding on the [[ceiling]] and try to [[sit|#sit]], you automatically unhide. ||  #sit, #monster, #sit: "You sit on the helm of brilliance. It's not very comfortable... You are already hiding." 
|-
|{{va|C342-51}}
|{{/bugstatus|Unknown}}|| ||The game thinks [[trapper]]s hide on the [[ceiling]]. ||  In D&D, they apparently hide on the floor. Turns up in two known places: dislodging a trapper with a drum of earthquake, and ambushing a monster while in trapper form. Fixed by Grunt. 
|-
|{{va|C342-54}}
|{{/bugstatus|Fix available}}|| [https://github.com/sgrunt/GruntHack/commit/e6ee39a0e7d5faea374e11ed0eea16db2cd992d3 GruntHack] ||[[Statue]]s of [[unique monsters]] in [[bones file]]s are not handled correctly.
|Unfortunately GruntHack fix depends on extension of structures introduced previously in this variant. Multiple unique monster problem also may be caused by corpses.  If the unique monster in question doesn't normally spawn on that level, and was rather brought there from some other level (in the other game), zapping stone to flesh at it causes a segfault. 
|-
|{{va|C343-1}}
|{{/bugstatus|Fixed}}|| [https://github.com/tung/NitroHack/commit/5d40e9f86486141df827e2afef78e992c4aac01b NitroHack] ||At a [[pit]] the game can give messages with poor grammar.
|Levitate over pit, while blinded, drop something: "The food rations tumble into the pit.", "You hear The amulet of reflection tumbles downwards."
|-
|{{va|C343-2}}
|{{/bugstatus|Unknown}}|| ||[[Wield]]ed [[silver arrow]]s don't cause [[silver damage]] on some silver-haters. || Fixed by Alex Smith.
|-
|{{va|C343-3}}
|{{/bugstatus|Unknown}}|| ||In the [[ranger quest]], [[monsters]] can end up off the map to the left. ||  The special level loader introduces a two column gap to the left of the main maze area; Jonadab thinks the monsters get generated back there. GruntHack fixes this by removing the two column gap in the special level loader. 
|-
|{{va|C343-4}}
|{{/bugstatus|Fix available}}|| [https://github.com/sgrunt/GruntHack/commit/06d2940c0ab51c0917e149c5797c26d8c0dc45c8 GruntHack] ||On the [[Rogue level]], tunnelling through rock doesn't leave a passage.
|-
|{{va|C343-5}}
|{{/bugstatus|Unknown}}|| ||In [[wizard mode]], [[level teleport]] in the [[endgame]] can cause a crash if confused. ||  Fixed by Grunt. 
|-
|{{va|C343-6}}
|{{/bugstatus|Unknown}}|| ||You can [[sit|#sit]] on an [[object]] at the bottom of a [[pit]] that you are not in. ||  Fixed in AceHack and GruntHack. 
|-
|{{va|C343-7}}
|{{/bugstatus|Unknown}}|| ||When a [[steed]] pushes a [[boulder]] into a [[pool]], the message misuses "you". ||  Fixed by Alex Smith. 
|-
|{{va|C343-8}}
|{{/bugstatus|Fixed}}|| UnNetHack ||Plural of [[Nazgul]] is Nazgul - not Nazguls.
|-
|{{va|C343-9}}
|{{/bugstatus|Unknown}}|| ||[[Trap]] messages referring to a named [[steed]] when [[hallucination|hallucinating]] are poorly worded. ||  If riding at the time, e.g. "You lead poor fire giant into a pit!". Fixed in GruntHack, though by a more complicated means than necessary for vanilla / NH4. 
|-
|{{va|C343-10}}
|{{/bugstatus|Unknown}}|| ||If there is a food in a [[pit]], you have to enter the pit to [[pick up|pick it up]] but not to [[eat]] it. ||  Fixed in GruntHack. 
|-
|{{va|C343-11}}
|{{/bugstatus|Unknown}}|| ||If you ask for [[help (in-game)|help]] ('{{kbd|?}}') at a "what direction" prompt, you don't get to enter a direction afterward if the [[cmdassist]] option is set.
|-
|{{va|C343-12}}
|{{/bugstatus|Fixed}}|| UnNetHack ||You can't use '{{kbd|>}}' to enter a [[pit]].
|-
|{{va|C343-13}}
|{{/bugstatus|Unknown}}|| ||On [[polymorph]], you can get the message "It turns into it". ||  According to Grunt, this happens in vanilla if an invisible purple worm swallows a shapechanger. Confirmed in NH4 with an invisible pet w and a chameleon. 
|-
|{{va|C343-14}}
|{{/bugstatus|Fixed}}|| [https://github.com/sgrunt/GruntHack/commit/02a48205328096f50d28e32f527c8df065f86bdc GruntHack] ||The initial and any [[tombstone]] message resulting from eating an identified [[artifact]] is gramatically incorrect.
|-
|{{va|C343-15}}
|{{/bugstatus|Unknown}}|| ||You can get a message that an [[invisible]] [[monster]] looks much better. ||  Fixed by Alex Smith. 
|-
|{{va|C343-16}}
|{{/bugstatus|Fixed}}|| UnNetHack ||Player [[polymorph]]ed as a [[xorn]] can't pick up [[items]] in [[pit]]s. ||You have to fall into a pit, which xorns can't. 
|-
|{{va|C343-17}}
|{{/bugstatus|Fixed}}|| [https://github.com/Bulwersator/UnNetHackPlus/commit/f58badbede0dc6ebcf2a0f4218bfdb0f8423acaa UnNetHackPlus]+[https://github.com/Bulwersator/UnNetHackPlus/commit/18b8cb1c17828e8bf2f7d8b962b94dcc92467ff3] ||After [[polymorph]]ing into a [[xorn]] and returning to [[race|human form]], player can be stuck in a [[pit]] that isn't there. ||After polymorphing into any non-phasing monster, you are reliably stuck in a nonexistant pit.
|-
|{{va|C343-18}}
|{{/bugstatus|Unknown}}|| ||[[Scaring]] a mimicing [[mimic]] gives an incorrect "turns to flee" message. ||Immobile monsters can have the "flee" status, but will not move away from you.  Fixed by Alex Smith. 
|-
|{{va|C343-19}}
|{{/bugstatus|Fixed}}||{{Bilious|340}}||[[Dip]]ping [[potion of acid|acid]] in a [[fountain]] may not destroy the acid.
|-
|{{va|C343-20}}
|{{/bugstatus|Unknown}}|| ||When dying immediately on entering a level, the map may show you dying on the previous level. ||  Notes: Can be reproduced by falling down a trap door with a wielded cockatrice corpse; bones will be saved on the destination level.
|-
|{{va|C343-21}}
|{{/bugstatus|Unknown}}|| ||[[Pets]] can be pulled through closed [[door]]s with a [[leash]].
|-
|{{va|C343-22}}
|{{/bugstatus|Not a bug}}|| ||You can [[untrap]] a [[monster]] in a [[pit]] while [[levitating]]. || Source code comment ("This works when levitating too -- consistent with the ability to hit monsters while levitating.")
|-
|[[C343-23]]
|{{/bugstatus|Fix available}}|| [https://github.com/sgrunt/GruntHack/commit/3775d4069d07a6ec1b1f143c5ddd538c4c488fbc GruntHack] ||[[Dungeon]] collapses after [[vault guard]] fails to lead you out.
| [[C343-23|Instructions to reproduce bug]]
|-
|{{va|C343-24}}
|{{/bugstatus|Unknown}}|| ||Documented default for option "[[null]]" is "off"; default is actually "on".
|-
|{{va|C343-25}}
|{{/bugstatus|Unknown}}|| ||You can [[trip]] over a [[cockatrice corpse]] safely. ||  Wear gauntlets of fumbling and walk around among cockatrice corpses. "You see here a cockatrice corpse. You trip over it. You make a lot of noise!" Fixed in GruntHack, where tripping is unsafe if not wearing boots. 
|-
|{{va|C343-26}}
|{{/bugstatus|Unknown}}|| ||A frozen [[swamp]] may be called a [[moat]]. ||  Go to Juiblex's Swamp and start zapping around with a wand of cold. "The moat is bridged with ice! You hear a cracking sound." Fixed, along with several related misuses of "moat", in GruntHack by greater use of waterbody_name. 
|-
|{{va|C343-27}}
|{{/bugstatus|Unknown}}|| ||Kicked [[objects]] do not slide properly on [[air]] or [[water]] levels. ||  	Fixed by Grunt.
|-
|{{va|C343-28}}
|{{/bugstatus|Unknown}}|| ||There are several places that can't tell the diffence between a "[[hat]]" and a "[[helmet]]." ||  There are some objects which are referred to in their descriptions as "hats" (elven leather helm -> "hat", dwarvish iron helm -> "hard hat", cornuthaum and dunce cap -> "conical hat"; one could argue that this applies to fedoras as well despite not having a separate description, as it's not a helmet). Several places in the code ("Fortunately, you are wearing a hard helmet"; "Your helmet blocks the attack to your head") always refer to the object in your armor slot as a helmet, even when it can't properly be described as a helmet (such as having a fedora block a mind flayer attack). Fixed by Grunt. 
|-
|{{va|C343-29}}
|{{/bugstatus|Unknown}}|| ||When taking things out of a [[bag of holding]], messages may say "lifting" instead of "removing." ||  This happens when you get the confirmation asking if you want to continue (because your encumbrance level would increase and you are over your threshold). Fixed in GruntHack. 
|-
|{{va|C343-30}}
|{{/bugstatus|Fixed}}|| [https://github.com/sgrunt/GruntHack/commit/e7afc1b022dd5e1b39dd2c69db077b533e66f3f4 GruntHack] ||[[Cursed]] [[scroll of destroy armor]] on cursed [[armor]] doesn't always interact correctly.||You can make the stats gain from putting on an enchanted helm of brilliance or gloves of dexterity permanent by cursing the armor and reading cursed destroy armor.
|-
|{{va|C343-31}}
|{{/bugstatus|Unknown}}|| ||If you hit a [[cockatrice]] with a [[weapon]] that breaks, you can be [[stoned]]. ||  Reproduced by wielding a boomerang in melee combat with negative luck. Fixed in GruntHack. 
|-
|{{va|C343-32}}
|{{/bugstatus|Unknown}}|| ||When [[blind]] and [[levitating]], the hero can still discover [[stairs]]. || Use the go down command. "You are floating high above the stairs." Fixed by Grunt
|-
|{{va|C343-33}}
|{{/bugstatus|Unknown}}|| ||Sometimes a [[monster]] may remain hidden under a [[corpse]] that has rotted away. || Fixed by Grunt
|-
|{{va|C343-34}}
|{{/bugstatus|Fix available}}|| [https://github.com/sgrunt/GruntHack/commit/08fe5d10820865adb60e4592bab6e36daf479f00 GruntHack] ||[[Mimic]]s on the [[rogue level]] may try to mimic a closed [[door]]. ||  Fixed by Sean Hunt. 
|-
|{{va|C343-35}}
|{{/bugstatus|Unknown}}|| ||[[Polymorph]]ed or [[Shape_changer|shapechanged]] monsters may get the wrong number of [[hit points]]. ||On polymorph, the ratio HP / max HP is preserved, perhaps this bug refers to rounding errors.
|-
|{{va|C343-36}}
|{{/bugstatus|Fix available}}|| [https://github.com/sgrunt/GruntHack/commit/f2b7b984e20c9a754cc100b8d434abfc1085b0c8 GruntHack] ||Weight of [[corpse]]s on [[special levels]] may not be calculated correctly.||This also goes for statues, e.g. the [[Oracle]] centaur statues.  Fixed by Grunt.
|-
|{{va|C343-37}}
|{{/bugstatus|Not a bug}}|| ||[[Mimic]]s may mimic a [[boulder]] over a [[pit]] or [[hole]].
|-
|{{va|C343-38}}
|{{/bugstatus|Unknown}}|| ||[[mounting|Dismounting]] and kicking a [[monster]] that [[jump]]s may result in landing on the wrong side of a [[wall]].|| Kicking a monster makes them mnexto() you, then tries to flavour the resulting movement. In very confined spaces, mnexto() may not be able to find a space next to you after all. This applies to many monsters with speed >= 12 with a chance of 1/3 or 1/4 depending on how well you kicked, and the bug occurs whether it’s flavoured as “jumps” or “slides” or “floats” or whatever. (A subsidiary bug here: it can also be flavoured as “teleports”, yet trigger on a no-tele level.) Fixed by Grunt.
|-
|{{va|C343-39}}
|{{/bugstatus|Fix available}}|| [https://github.com/sgrunt/GruntHack/commit/704ace1aec92e5ee69c20180ba15c30a07694084 GruntHack] ||Restoring a game where the character is [[wield]]ing [[Sting]] may result in temporary display errors during the restore process.
|-
|{{va|C343-40}}
|{{/bugstatus|Fix available}}|| [https://github.com/sgrunt/GruntHack/commit/ce36a6652958a032a1626a81bdb102374de28d14  GruntHack] ||[[Monster]] thrusting one of multiple wielded [[daggers]] gives misleading message.||The interface isn’t clear that wielding 6 daggers, or whatever, nevertheless means that you only attack with one.
|-
|{{va|C343-41}}
|{{/bugstatus|Unknown}}|| ||A rolling [[boulder]] falling into a [[pit]] you can't see only makes a sound if the hero is [[blind]]. || Fixed by Grunt.
|-
|{{va|C343-42}}
|{{/bugstatus|Fix available}}|| [https://github.com/sgrunt/GruntHack/commit/5577e8d10bb52a3af2e05c628f0f360622310cd3 GruntHack] ||If a [[fire trap]] melts [[ice]], it may trigger twice in the same turn.
|"Reproduced via polyself into a red dragon." ([[Bugs in NetHack 4]]) - whatever it may mean.
|-
|{{va|C343-43}}
|{{/bugstatus|Unknown}}|| ||An [[invisible]] [[troll]] that revives may be shown until it moves.
|-
|{{va|C343-44}}
|{{/bugstatus|Fix available}}|| [https://github.com/sgrunt/GruntHack/commit/7d66e21b935c73cd974a709eeb742abbdefcabe5 GruntHack] ||[[Shopkeeper]]s, [[door]]s, and [[trap]]s interact oddly. ||For example, if you break a wand of digging on the entrance square, the shopkeeper will usually remove only some of the pits.
|-
|{{va|C343-45}}
|{{/bugstatus|Unknown}}|| ||Dropping the [[corpse]] of a [[unique monster]] without a personal [[name]] down the [[stairs]] gives a badly formed response. Fixed by Sean Hunt.
|-
|{{va|C343-46}}
|{{/bugstatus|Help}}|| ||Breaking up a [[boulder]] or [[statue]] can result in pieces that are described incorrectly.
|Described where? The rocks that result don't seem to be the problem. 
|-
|{{va|C343-47}}
|{{/bugstatus|Unknown}}|| ||[[Monster]] and hero have different odds to err when throwing a [[grease]]d [[weapon]].
| Players throwing greased weapons have the same chance of them misfiring as if the object is cursed; monsters throwing projectiles suffer no penalty for throwing greased weapons at all. Fixed by Grunt.
|-
|{{va|C343-48}}
|{{/bugstatus|Unknown}}|| ||Killing your [[pet]] doesn't get you any [[experience]] when it should. || Vanilla: This might refer to the fact you won't break pacifist conduct if you branchport into an already-full level - pets and followers simply disappear. The pacifist page has a few more "safe" ways to kill things.
|-
|{{va|C343-49}}
|{{/bugstatus|Unknown}}|| ||The [[boulder]] does not show up in a [[bones file]] caused by death by rolling boulder.
| Fixed in [[GruntHack]] by allowing the boulder to finish moving before dealing damage to the player (this leaves the trap ready to snare whoever next comes across the bones). Possible alternative solution: place the boulder where the player is before triggering the damage in the current code flow, leaving the boulder on top of the corpse.
|-
|{{va|C343-50}}
|{{/bugstatus|Fix available}}|| AceHack ||A [[sleep]]ing [[steed]] may answer a [[chat|#chat]].
|     dochat (sounds.c) checks to see if you’re talking to a steed before it checks to see if the monster is asleep.
|-
|{{va|C343-51}}
|{{/bugstatus|Unknown}}|| ||[[Luck]]'s effect on random events isn't always as intended.||Several beneficial events are most likely with Luck=7, not maximum Luck. See [[rnl]] for details.
|-
|{{va|C343-52}}
|{{/bugstatus|Upstream}}|| ||[[wear|Worn]] or [[wield]]ed [[objects]] destroyed by dipping into lit [[potion of oil|potions of oil]] are not handled properly; this can result in odd game behavior. || For example, if you dip your (worn) thoroughly burned robe into lit oil until it's destroyed and then try to wear another cloak you can't, because you're already wearing the robe, even though you aren't.
|-
|{{va|C343-53}}
|{{/bugstatus|Unknown}}|| ||If a [[shopkeeper]] is [[trap]]ped adjacent to the [[door]], the game may get confused and issue [[impossible]] or [[panic]] messages.
| TJR says break a wand of digging while standing next to the shopkeeper.
|-
|{{va|C343-54}}
|{{/bugstatus|Confirmed}}|| ||"Ulch" [[cannibalism]] message grammar is poor.||Eating a [[zombie]] of your [[race]]: ''"Ulch - that meat was tainted cannibal!  You feel deathly sick."'' Fixed by Alex Smith.
|-
|{{va|C343-55}}
|{{/bugstatus|Fixed}}|| UnNetHack ||"Ulch" messages have inconsistent capitalization.
|-
|{{va|C343-56}}
|{{/bugstatus|Unknown}}|| ||[[Gas spore]]s can't attack while hero is [[pray]]ing.
|A spurious "starts to attack you, but pulls back" message is displayed, even though gas spores have only passive attacks. Fixed in [[GruntHack]].
|-
|{{va|C343-57}}
|{{/bugstatus|Unknown}}|| ||[[enhance|#enhance]] command descriptions in [[Guidebook]] and game do not match.
|Fixed by Grunt
|-
|{{va|C343-58}}
|{{/bugstatus|Unknown}}|| ||[[conduct|#conduct]] command description grammar is poor
|Fixed by Grunt
|-
|{{va|C343-59}}
|{{/bugstatus|Confirmed}}|| ||[[Engulfing|Engulfer]] [[stoned]] swallowing hero [[polymorph]]ed to [[cockatrice]] causes incorrect screen display.  If hero has [[punishment|ball &amp; chain]], game can [[panic]].
|Reproduced with a hostile trapper.  The t remained on the display in its original location adjacent to the polyselfed hero for several turns, even though there was a statue of a trapper on the tile with the hero. Fixed by Grunt
|-
|{{va|C343-60}}
|{{/bugstatus|Unknown}}|| ||Several messages delivered when hero's [[slippery fingers|fingers are slippery]] have poor grammar.
|Which messages?
|-
|{{va|C343-61}}
|{{/bugstatus|Unknown}}|| ||Using a [[WIZKIT]] including the [[quest artifact]] will crash the game at startup.
|-
|{{va|C343-62}}
|{{/bugstatus|Unknown}}|| ||Riding into a [[magic portal]] gives an extra, useless message.
| You may be told "<steed> is still eating.", but it comes through with you regardless.
|-
|{{va|C343-63}}
|{{/bugstatus|Unknown}}|| ||You can [[quaff|drink]] from a [[sink]], [[fountain]], or while [[underwater]] while [[swallowed]].
| Confirmed in NH4 by quaffing from fountain while engulfed by purple worm.  In a similar vein, #praying on a cross-aligned altar also works. Fixed by Grunt
|-
|{{va|C343-64}}
|{{/bugstatus|Unknown}}|| ||A [[black light]] leaves an [[Hallucination|hallucinated]] [[corpse]] while exploding.
| Fixed by Grunt
|-
|{{va|C343-65}}
|{{/bugstatus|Unknown}}|| ||A [[monster]] that "shrieks in pain" may not awaken others nearby.||This is missing a wake_nearby call in the two relevant locations in potion.c. Fixed by Grunt
|-
|{{va|C343-66}}
|{{/bugstatus|Unknown}}|| ||[[Co-aligned]] [[unicorn]]s in a [[bones file]] may be hostile.
| Happens when the unicorns were also co-aligned for the former player and he angered them before getting himself killed.
|-
|{{va|C343-67}}
|{{/bugstatus|Unknown}}|| ||Finding a [[statue]] when [[search]]ing while [[blind]] doesn't update map.
|-
|{{va|C343-68}}
|{{/bugstatus|Unknown}}|| ||Incorrect message may be given when a [[spellcasting]] [[monster]] summons other monsters.
| may be a pluralization issue if extinction lets only one of the
monsters materialize.
|-
|{{va|C343-69}}
|{{/bugstatus|Unknown}}|| ||Attempting to add more [[candle]]s than needed to a [[candelabrum]] with at least one candle gives an incorrect message.
| bcode says: have six candles already attached, then try to attach more than one. Fixed by Grunt.
|-
|{{va|C343-70}}
|{{/bugstatus|Fix available}}|| [https://github.com/sgrunt/GruntHack/commit/80f94d9d0c7c9ccb67a2220c22cf19f90e8ccdf3 GruntHack] ||[[Experience]] may not be correctly gained for [[monster]]s causing [[nonphysical damage]]. || "Difficult" attacks it possesses make a monster worth more experience, but the way these bonus points are calculated underrates physical damage.
|-
|{{va|C343-71}}
|{{/bugstatus|Unknown}}|| ||When swapping places with a [[pet]] pushes it into a [[trap]], the messages are out of order.
| "A gush of water hits Chmee's right forelimb!  You displaced Chmee."  Fixed by Grunt.
|-
|{{va|C343-72}}
|{{/bugstatus|Fixed}}|| [https://sourceforge.net/apps/trac/unnethack/changeset/958 UnNetHack] ||You get confusing messages when you stop [[levitating]] while on a [[flying]] [[steed]].||"You float gently to the lava." is probably the silliest variant. The messages don't consider the fact that you're flying.
|-
|{{va|C343-73}}
|{{/bugstatus|Unknown}}|| ||Trying to [[kick]] a [[monster]] on a level [[Non-teleport level|forbidding teleport]] may give a bogus "teleports" message.
| "You kick the tengu.  The tengu teleports, easily evading your clumsy kick." Fixed by Grunt.
|-
|{{va|C343-74}}
|{{/bugstatus|Fixed}}|| UnNetHack ||Entering a long running, uninterruptible command (e. g. engraving) after [[stoning]] starts will kill you.
|-
|{{va|C343-75}}
|{{/bugstatus|Unknown}}|| ||Eating [[Medusa]]'s corpse may not work properly.
|-
|{{va|C343-76}}
|{{/bugstatus|Unknown}}|| ||A [[tin]] of [[Medusa]] meat isn't [[food appraisal|warned]] about properly.
| Warned as in from blessed [[scroll of food detection]]; no warning is given about it being "very dangerous", as with other monsters that cause petrification. (Medusa's corpse is also warned about incorrectly, warning about poison instead of petrification.) Fixed in [[GruntHack]].
|-
|{{va|C343-77}}
|{{/bugstatus|Unknown}}|| ||Some messages referring to monsters that look like [[horse]]s refer to [[claws]].||polyself.c lists claws as a horse’s manipulatory appendages. Fixed by Grunt
|-
|{{va|C343-78}}
|{{/bugstatus|Unknown}}|| ||[[Digging]] in an existing [[hole]] charges you for the time it takes to dig the whole hole.
|Fixed by Grunt. To reproduce polymorph into vampire, wish for a pick-axe, apply said pick-axe down repeatedly. Alternatively, trigger a hangup-save after you finish digging and before you fall though.
|-
|{{va|C343-79}}
|{{/bugstatus|Unknown}}|| ||"Mr." or "Ms." may show up in front of names when it should not.||In death messages, all shopkeepers will have an honorific, even if the shopkeeper's name is clearly a given name, not a surname (e.g. Dirk, Lucrezia, Izchak).
|-
|{{va|C343-80}}
|{{/bugstatus|Unknown}}|| ||[[Tame]] monsters with multiple [[monster attacks|attacks]] may allow themselves to be killed through [[passive attacks]].
| "The black unicorn misses the red mold.  The black unicorn is suddenly very hot!  The black unicorn misses the red mold.  The black unicorn is suddenly very hot!  The black unicorn is killed!" Fixed by Grunt.
|-
|{{va|C343-81}}
|{{/bugstatus|Fixed}}|| [https://github.com/Bulwersator/UnNetHackPlus/commit/81699266df94790374668e66ea6fd80b249fea88]+[https://github.com/Bulwersator/UnNetHackPlus/commit/c63f45a72b9117d69f334821472d645fbbb3d82b] ||[[Ghost]]s can be [[slimed]].
|-
|{{va|C343-82}}
|{{/bugstatus|Confirmed}}|| [https://github.com/sgrunt/GruntHack/commit/77c8aa074728b31581642ac6c4475a53b9a4d421 GruntHack] ||[[Land mine]] explosion on a [[drawbridge]] doesn't work right. || Bridge over lava is replaced with a pit. Related to 343-240.
|-
|{{va|C343-83}}
|{{/bugstatus|Not a bug}}|| ||An eating [[pet]] will miss out on [[ascension]].
|-
|{{va|C343-84}}
|{{/bugstatus|Unknown}}|| ||"finally finished" may be displayed when not [[eat]]ing.
| Bug relates to the nomovemsg variable being left set and unmul() being called later for an unrelated reason.  An easy way to trigger it is to eat lizard corpses off the floor with nothing in inventory but worn armor in the presence of several hostile nymphs while your nutrition is between 1500 and 2000.  When it asks if you want to stop eating, say no.  (You'll stop anyway as soon as a nymph seduces you, but saying no causes nomovemsg to remain set.)  Fixed by Grunt.
|-
|{{va|C343-85}}
|{{/bugstatus|Help}}|| ||Sometimes the hero can't move when conscious.
|Very unclear description.
|-
|{{va|C343-86}}
|{{/bugstatus|Unknown}}|| ||Hero can appear to be in the [[wall]] after destroying a [[drawbridge]].
|-
|{{va|C343-87}}
|{{/bugstatus|Unknown}}|| ||Sometimes [[shop]] [[items]] the hero is forced to buy can be sold twice.
|-
|{{va|C343-88}}
|{{/bugstatus|Fix available}}|| [https://github.com/sgrunt/GruntHack/commit/2e7b1f8fc6f3e6ea8df0532baa3cdec3e257ccbc GruntHack] ||[[Polymorph]]ing a [[statue]] into a [[boulder]] can leave an incorrect display.
|-
|{{va|C343-89}}
|{{/bugstatus|Unknown}}|| ||Unpaid [[object]]s [[damage]]d or improved in shops are not accounted for properly.
| If you pick up some armor and are quoted a price then read a scroll of enchant armor before paying, the price does not change UNLESS you drop the armor and pick it up again, in which case it then does.  Enchant weapon works the same way. Fixed by Grunt; ported by Sean Hunt.
|-
|{{va|C343-90}}
|{{/bugstatus|Unknown}}|| ||"{{kbd|I}} {{kbd|u}}" with only one [[item]] unpaid lists the price twice.
| Fixed by Grunt
|-
|{{va|C343-91}}
|{{/bugstatus|Unknown}}|| ||[[Auto-cursing]] [[armor]] does not do so when worn by [[monster]].
| Fixed by Grunt
|-
|{{va|C343-92}}
|{{/bugstatus|Unknown}}|| ||A [[blind]] player may find a [[trap]] which then fails to show up on the map.
|-
|{{va|C343-93}}
|{{/bugstatus|Unknown}}|| ||[[Astral vision]] can confuse the {{kbd|;}} command.
| A monster on the opposite side of a solid maze wall may be said to be seen through normal vision as well as astral vision; in fact, normal vision cannot see it.  At other times no mention is made of how you see something, even though it is only visible through astral vision.
|-
|{{va|C343-94}}
|{{/bugstatus|Fixed}}|| UnNetHack ||[[Probing]] a re-animated [[statue]] may cause a [[panic]].
|-
|{{va|C343-95}}
|{{/bugstatus|Unknown}}|| ||If killed by the [[wish]] from a [[magic lamp]] (or similar situation) and a [[bones file]] is produced, the bones file has the lamp in the wrong state.
| Create bones by using a magic lamp to wish for something that will blast you for more damage than you can survive.  On loading the bones in another game, bless the lamp and rub it.  A percentage of the time, you can get a second wish.
|-
|{{va|C343-96}}
|{{/bugstatus|Unknown}}|| ||If player aborts "In what direction?" question, prompt may remain displayed.
| NH4 says, "What a strange direction!"
|-
|{{va|C343-97}}
|{{/bugstatus|Unknown}}|| ||{{kbd|ctrl|r}} and {{kbd|ctrl|l}} don't work in [[numberpad]] mode
|-
|{{va|C343-98}}
|{{/bugstatus|Unknown}}|| ||[[Chat]]ting with [[quest]] leader brought back from the dead doesn't work.
| Fixed by Grunt
|-
|{{va|C343-99}}
|{{/bugstatus|Help}}|| ||Hero can still see for brief period after being [[blind]]ed by [[potion]] vapors.
| If you kill a monster with a wielded potion of blindness and get blinded in the process, the corpse is shown, but I'm not sure whether this is a bug and also not sure whether this is what the bug description refers to.
|-
|{{va|C343-100}}
|{{/bugstatus|Fixed}}||{{Bilious|341}}||Game may crash if [[throw]]n [[potion]] hits [[iron bars|bars]] before a [[monster]].
|-
|{{va|C343-101}}
|{{/bugstatus|Fix available}}|| [https://github.com/sgrunt/GruntHack/commit/fccd7a44958411219ce79403848b5e6888f7a700 GruntHack] ||The hero can see some things while a[[sleep]].
|-
|{{va|C343-102}}
|{{/bugstatus|Unknown}}|| ||Messages delivered when the [[ceiling]] collapses on a [[swallowed]] hero need revision.
|-
|{{va|C343-103}}
|{{/bugstatus|Unknown}}|| ||The hero is not protected from a [[mind flayer]] during successful [[pray]]er.||Refers to the psychic blast.
|-
|{{va|C343-104}}
|{{/bugstatus|Unknown}}|| ||Message from angry [[shopkeeper]] giving a price when hero picks up an [[object]] has poor spacing and construction.||"For you, scum ; only 534 for this emerald ring." (note the extra space)
|-
|{{va|C343-105}}
|{{/bugstatus|Not a bug}}|| ||Message given when restoring a game refers to original [[gender]] and form, not current.||I am not sure
|-
|{{va|C343-106}}
|{{/bugstatus|Unknown}}|| ||[[Sunsword]] continues to glow after its wielder dies.
See [[Sunsword]]. Fixed by Grunt
|-
|{{va|C343-107}}
|{{/bugstatus|Fix available}}|| [https://github.com/sgrunt/GruntHack/commit/6cf949716263ca5bcd7c8405669f34ea49453db4 GruntHack] ||Killing your own [[steed]] never leaves a [[corpse]].
|-
|{{va|C343-108}}
|{{/bugstatus|Unknown}}|| ||Entering "{{kbd|e}}{{kbd|-}}" does not remove the prompt.
|-
|{{va|C343-109}}
|{{/bugstatus|Fixed}}|| [https://github.com/sgrunt/GruntHack/commit/6da48e6dd87737f1e207a2759e69075d62eb9569 GruntHack] ||There is a grammar error in the [[Tourist]] [[quest|leader]]'s greeting.
|-
|{{va|C343-110}}
|{{/bugstatus|Unknown}}|| ||Game can crash if [[shopkeeper]] dies while character is [[pray]]ing.
| Tried several times with strong pets and failed to reproduce in NH4.
|-
|{{va|C343-111}}
|{{/bugstatus|Unknown}}|| ||Grammar of some [[graveyard]] sounds messages is wrong in some cases.
| Alex Smith
|-
|{{va|C343-112}}
|{{/bugstatus|Help}}|| ||Hero and [[monster]] afflicted with [[lycanthropy]] are treated differently. || How, where?
|-
|{{va|C343-113}}
|{{/bugstatus|Unknown}}|| ||When [[flying]] down a [[hole]] or a [[ladder]], the messages are inaccurate.||Doing this with a ladder while polymorphed actually produces no message at all. The message is most likely related to flying steeds, though; while riding a ki-rin, you climb up ladders, fly down ladders, and jump down holes, which is a clear inconsistency. (It's not clear which of the messages is correct.)
|-
|{{va|C343-114}}
|{{/bugstatus|Unknown}}|| [https://github.com/sgrunt/GruntHack/commit/607b0f5aeafbc36de5723775f454590c6816a470 GruntHack] (fixes part of the problem) ||Removing some but not all the [[boulder]]s from a location confuses the [[vision system]].
| Fixed by Grunt
|-
|{{va|C343-115}}
|{{/bugstatus|Unknown}}|| ||[[Sleeping]] or [[paralyzed]] [[unicorn]]s can catch [[gems]].
| Fixed by Grunt
|-
|{{va|C343-116}}
|{{/bugstatus|Fixed}}|| UnNetHack ||Grammar error in messages related to [[nutrition|choking]] on [[gold]].
|-
|{{va|C343-117}}
|{{/bugstatus|Unknown}}|| ||Gaining and losing [[experience level|level]]s in normal and [[monster]] form do not balance.
| I was an XL7 human tourist, polymorphed into an elf, lost two levels to a vampire, polymorphed back to human, and was XL4. I then polymorphed to elf again, lost one level, polymorphed back to human, and my new form was too weak to survive. 
|-
|{{va|C343-118}}
|{{/bugstatus|Fixed}}|| [https://github.com/Bulwersator/UnNetHackPlus/commit/fc4be56b5a67895a67dd0889160a7e0f93ae6a5b]+[https://github.com/Bulwersator/UnNetHackPlus/commit/5932f14cfa37a4fa594fcd2de46d20afdaa70937] ||Some messages use "[[mirror]]" where they should use "[[looking glass]]."
|-
|{{va|C343-119}}
|{{/bugstatus|Unknown}}|| ||Options [[IBMgraphics]], [[DECgraphics]], and [[MACgraphics]] interact oddly in the [[config file]], resulting in odd listings from the [[options|O command]]. || Workaround: only specify one option in the [[config file]].
|-
|{{va|C343-120}}
|{{/bugstatus|Not a bug}}|| ||There is no [[warning]] when hitting [[floating eye]]s.
|-
|{{va|C343-121}}
|{{/bugstatus|Confirmed}}|| ||[[Eat]]ing various brains which should have special handling, don't. || You may eat brain of ghost and safely eat brains of Medusa and Riders as mind flayer.
|-
|{{va|C343-122}}
|{{/bugstatus|Unknown}}|| ||[[Alignment]] of [[Angel]]s is not handled consistently.
|Fixed by Grunt
|-
|{{va|C343-123}}
|{{/bugstatus|Unknown}}|| ||Plural of "mother-in-law" is incorrect.
| Alex Smith 
|-
|{{va|C343-124}}
|{{/bugstatus|Unknown}}|| ||You can't rub a [[touchstone]] on [[gold]].
| You can, but only if the touchstone is not formally identified. Fixed by Sean Hunt 
|-
|{{va|C343-125}}
|{{/bugstatus|Unknown}}|| ||Killing a [[vault guard]] outside a [[vault]] gives incorrect feedback.
|Fixed by Grunt
|-
|{{va|C343-126}}
|{{/bugstatus|Unknown}}|| ||When [[wield]]ing [[Grayswandir]], feedback from a [[trap]]ped [[chest]] may be wrong.
| If the chest trap is colored gas (which normally stuns and hallucinates), and you are not already stunned, the message is the same whether you have hallucination resistance or not. (However, the message does not specifically say anything about hallucination.) 
|-
|{{va|C343-127}}
|{{/bugstatus|Unknown}}|| ||If a [[vault guard]] leads the hero to [[gold]] in the [[rock]], inappropriate feedback is given.
|Fixed by Grunt
|-
|{{va|C343-128}}
|{{/bugstatus|Fix available}}|| [https://github.com/sgrunt/GruntHack/commit/f5964d4842e84f5e965ab99cc6691f2dc8a7699c GruntHack] ||Feedback for [[gas spore]] explosion when [[hallucinating]] could be improved.
| If you or a monster are caught in the explosion, it is always called "the gas spore's explosion", one of the only situations wherein a monster's correct name is always used while you are hallucinating. Fixed by Grunt; ported by Sean Hunt. 
|-
|{{va|C343-129}}
|{{/bugstatus|Unknown}}|| ||[[Cancel]]ling objects in or near a [[shop]] [[door]]way may make the [[shopkeeper]] think you are a [[Stealing from shops#Consequences of theft|thief]].||The error’s in zap.c, around line 794; it checks to see if you’re in the shop, rather than whether the object is.
|-
|{{va|C343-130}}
|{{/bugstatus|Unknown}}|| ||Sometimes you can't [[rub]] an arbitrary [[object]] on a [[touchstone]].||Perhaps this refers to the fact you cannot check for [[kicking boots]] and [[gauntlets of power]] once the touchstone has been formally identified. Fixed by Sean Hunt. 
|-
|{{va|C343-131}}
|{{/bugstatus|Unknown}}|| ||Message has poor grammar if hero killed when stealing [[cockatrice corpse]] from a monster.
| Death message is "petrified by stolen cockatrice corpse"; it should be "petrified by a stolen cockatrice corpse". 
|-
|{{va|C343-132}}
|{{/bugstatus|Unknown}}|| ||Message when death caused by kicking an [[object]] can be too verbose. ||  Grunt says: I've thought that this refers to "killed by kicking a runed broadsword named Stormbringer" if the artifact was not identified, as opposed to "killed by kicking Stormbringer". The former behaviour has been acknowledged to be a bug to me in response to a related bug report of my own. 
|-
|{{va|C343-133}}
|{{/bugstatus|Useless}}|| ||Effects of varying consuming [[Medusa]] are inconsistent.
| Description does not adequately differentiate this bug from C343-75, C343-76 and C343-121. 
|-
|{{va|C343-134}}
|{{/bugstatus|Fixed}}|| [https://github.com/sgrunt/GruntHack/commit/a65cf627f512c63fbae610e2f94806c86b0fe118 GruntHack] ||Being [[petrified]] by [[Engulfing|swallowing]] a [[cockatrice]] violates [[foodless]] [[conduct]].
|-
|{{va|C343-135}}
|{{/bugstatus|Unknown}}|| ||Several [[quest]] messages are inappropriate if the hero is [[blind]].
| The messages in question are ones issued upon entering certain levels for the first time. Arc, Cav, Tou, Wiz quests have issues that I noticed. 
|-
|{{va|C343-136}}
|{{/bugstatus|Fixed}}|| UnNetHack ||A [[samurai]] [[quest]] guardian message uses "[[ninja]]" where "[[ronin]]" is intended.
|-
|{{va|C343-137}}
|{{/bugstatus|Unknown}}|| ||[[Demon]]s may demand [[money]] from (and get paid by) a [[fainted]] hero. || Fixed by Grunt
|-
|{{va|C343-138}}
|{{/bugstatus|Unknown}}|| ||Some [[spheres]] pick up [[objects]] and some don't. ||  Tame flaming and shocking spheres (at least) pick stuff up. Hostile ones don't, and you cannot if polyselfed into any kind of e, because you can't reach the floor. 
|-
|{{va|C343-139}}
|{{/bugstatus|Unknown}}|| ||There's no feedback when an unseen [[drawbridge]] opens or closes. ||  The first time you play the passtune, you get feedback no matter what. Subsequently, you only get feedback if you can see or if something interesting happens (e.g., a monster gets crushed). 
|-
|{{va|C343-140}}
|{{/bugstatus|Unknown}}|| ||[[Pet]]s may continue [[eat]]ing after being [[paralyzed]] or falling a[[sleep]]. ||  Actually, if you use a stethoscope in wizmode you see that their hunger is changed all at once when they start eating, and I'm pretty sure the corpse is removed at that time too; the only real multi-turn effect of a pet eating is the inability to move, which is redundant with sleep or paralysis. 
|-
|{{va|C343-141}}
|{{/bugstatus|Confirmed}}|| ||[[Run]]ning, [[search]]ing, and [[rest]]ing should stop wnen [[levitation]] ends. ||  Quaff an uncursed potion of levitation and use a numeric prefix to rest for 9999 turns. 
|-
|{{va|C343-142}}
|{{/bugstatus|Unknown}}|| ||[[Shopkeeper]]s can be identified while [[hallucinating]]. || Fixed by Grunt
|-
|{{va|C343-143}}
|{{/bugstatus|Unknown}}|| ||[[Leprechaun]]s stealing [[gold]] from a [[mount]]ed [[hero]] cause oddly worded messages.||See {{sourcecode|steal.c|51}}
|-
|{{va|C343-144}}
|{{/bugstatus|Fix available}}|| [https://github.com/sgrunt/GruntHack/commit/892c15613399b9278798aad4319d73f9518de8bf GruntHack] ||[[Creatures]] that can fit under [[door]]s can't fit through diagonal gaps. ||  Tested with black puddings. Refers to diagonal passages through rock only (they do fit between boulders ok). 
|-
|{{va|C343-145}}
|{{/bugstatus|Fix available}}||  [https://github.com/sgrunt/GruntHack/commit/785f1528e63eb2c0810d04f719bdb9dd024916ae GruntHack] ||[[Dwarvish mattock|Mattock]] is mishandled when [[force|forcing]] [[lock]]s. ||  You bash a lock with a pickaxe (i.e. it is considered blunt), but pry with a mattock (i.e. bladed). Fixed by Sean Hunt. 
|-
|{{va|C343-146}}
|{{/bugstatus|Unknown}}|| ||Unseen [[wand of striking]] becomes known if [[zap]]ped by unseen [[monster]] and it hits a [[door]].|| mbhit calls doorlock, which returns true if anything happens; when doorlock returns true, mbhit calls makeknown without checking cansee 
|-
|{{va|C343-147}}
|{{/bugstatus|Unknown}}|| ||The game [[panic]]s if a [[magic trap]] [[tame]]s a [[monster]] that just expelled the hero.|| per Grunt: mon.c:583 still refers to the old invalid monster (more detail on rgrn). Fixed by Grunt
|-
|{{va|C343-148}}
|{{/bugstatus|Unknown}}|| ||Changing locations while a[[sleep]] lets you see [[object]]s or read [[engraving]]s.||" I didn't reproduce the described bug, but I did discover that upon waking up the display is not properly updated until you move. "
|-
|{{va|C343-149}}
|{{/bugstatus|Unknown}}|| ||[[Polymorph]]ed [[spellbook]]s don't behave as intended.||If the spell wasn't present in the spellcasting {{kbd|Z}} menu when you read the book, it is never blanked, regardless how many times it was already polymorphed. This bug also affects spells forgotten due to a non-blessed scroll of amnesia.
|-
|{{va|C343-150}}
|{{/bugstatus|Unknown}}|| ||[[Gender]] and/or [[size]] of some [[quest]] [[quest leader]]s and [[quest nemesis|nemeses]] are wrong.||By [[user:Jonadab|Jonadab]]: The following do not have a gender specified (in monst.c): The [[Grand Master]], The [[Arch Priest]], The [[Minion of Huhetotl]], [[Ixoth]], [[Master Kaen]], [[Nalzok]], [[Scorpius]], The [[Master Assassin]], and the [[Dark One]]. I'm guessing some of those should have a fixed gender. As for the size, the encyclopedia entries for [[Orion]] and for the [[Norn]] seem to imply they should be larger (currently they are MZ_HUMAN, i.e., medium size).
|-
|{{va|C343-151}}
|{{/bugstatus|Unknown}}|| ||[[Monsters]] can [[teleport]] to or be created outside of legal area in [[special level]]s.||Examples are xorns off the map in Sokoban or ghosts on the edge of the map of the Astral Plane.
|-
|{{va|C343-152}}
|{{/bugstatus|Fix available}}|| [https://github.com/sgrunt/GruntHack/commit/c0fa20504b19cc7946b0d8eda45b67fe2bc1af84  GruntHack] ||Using a [[cursed]] [[lamp]] while [[blind]] may give inappropriate messages.||If it fails to light, even a blind character will observe that it "flickers for a moment".{{refsrc|apply.c|1089}}
|-
|{{va|C343-153}}
|{{/bugstatus|Unknown}}|| ||Player [[polymorph]]ed into [[guardian naga]] spits the wrong kind of [[venom]].|| "Your venom burns the dog!" (I guess this is acid.) However, when a guardian naga attacks me, "The venom blinds you." 
|-
|{{va|C343-154}}
|{{/bugstatus|Unknown}}|| ||[[Candle]]s are [[fireproof]].
|you can create fireproof candles by erodeproofing a wielded pick-axe, then polymorphing it. IIRC you can't wish for fireproof candles directly, and it doesn't make sense for a working candle to be fireproof   Falling into lava does destroy them, but zapping with a wand of fire doesn't seem to (neither when they are in the player's possession nor when they are on the floor), nor falling into a fire trap (while holding them in open inventory). 
|-
|{{va|C343-155}}
|{{/bugstatus|Fix available}}|| [https://github.com/sgrunt/GruntHack/commit/f809ede38f087149d9276a4e46ba91fbeca6a216 GruntHack]||Proper names may be incorrectly preceeded by "the" when [[hallucinating]]. ||  Some of the capitalized entries in bogusmons should (and do) get the article ("The Ravenous Bugblatter Beast of Traal", "the Klingon", etc.), which is all very well, but others very clearly should not and yet currently do ("The Totoro", "The Barney the Dinosaur", "The Morgoth", "The Godzilla", "The Smokey the bear", "The King Kong"). The code needs a way to distinguish these two cases -- either two separate lists, or some kind of flag to indicate which ones that should not use "the". Allegedly fixed by Grunt; fix ported with fixups by Sean Hunt. Still not sure if it catches all cases. 
|-
|{{va|C343-156}}
|{{/bugstatus|Unknown}}|| ||[[Read]]ing [[scrolls]] may give redundant feedback messages.||Read cursed remove curse while confused: "As you read the scroll, it disappears." ... "The scroll disintegrates."
|-
|{{va|C343-157}}
|{{/bugstatus|Unknown}}|| ||[[Worm]]s don't have scales. || Because worms have M1_SLITHY, mbodypart uses snake_parts for them, but it should not. 
|-
|{{va|C343-158}}
|{{/bugstatus|Unknown}}|| ||[[Kraken]]s have tentacles. ||  mbodypart needs to special-case them; it does not. 
|-
|{{va|C343-159}}
|{{/bugstatus|Fix available}}|| [https://github.com/sgrunt/GruntHack/commit/1caa11b3b284df97497a47aba391dd60bb92446b GruntHack] ||[[Stalker]]s have a head.|| mbodypart uses vortex_parts for all v and E, but stalkers should probably get humanoid_parts instead. Fixed by Grunt
|-
|{{va|C343-160}}
|{{/bugstatus|Fixed}}|| ||Name "leather [[spellbook]]" is misleading.
|-
|{{va|C343-161}}
|{{/bugstatus|Fix available}}|| [https://github.com/sgrunt/GruntHack/commit/e4cd5012afebc9fb25f2dc7f9c1d01cd9c33f443 GruntHack] ||A [[scroll of charging]] that has disappeared may still show in the list of things to charge. Fixed by Jared Minch. 
|-
|{{va|C343-162}}
|{{/bugstatus|Fix available}}|| [https://github.com/chasonr/nethack-3.4.3-bugfix/commit/76640726272e795ff0d9af00d5b4cc286aa88cc3 Ray Chason] ||Using [[Magicbane]] may cause an ungrammatical message.||Possibly refers to monster names incorrectly being considered as plural forms, e.g. "Chops are confused." with a monster named "Chops"
|-
|{{va|C343-163}}
|{{/bugstatus|Unknown}}|| ||[[Anthole]]s are mispopulated under some conditions. ||  Fixed by Jared Minch 
|-
|{{va|C343-164}}
|{{/bugstatus|Unknown}}|| ||[[Cancel]]led [[nurse]]s may give inappropriate messages. ||  Believed to be related to #chat, she'll say things like "Take off your shirt, please" even though she can't do use the "attack" around which those messages are flavored. 
|-
|{{va|C343-165}}
|{{/bugstatus|Unknown}}|| ||[[Scroll of mail]] can be abused slightly.|| Perhaps this refers to the fact shopkeepers will eventually start charging for mail if you pick up enough of them. Alternately, may refer to using the mail daemon on Astral to clear a path. 
|-
|{{va|C343-166}}
|{{/bugstatus|Unknown}}|| ||[[Pit]]s dug in [[vault guard]]'s corridor don't get removed. || Fixed by Grunt
|-
|{{va|C343-167}}
|{{/bugstatus|Unknown}}|| ||Length of time [[swallowed]] is sometimes calculated incorrectly.
|-
|{{va|C343-168}}
|{{/bugstatus|Unknown}}|| ||Shattering a [[monster]]'s [[weapon]] doesn't work right if the weapon is part of a stack of more than one. ||  Fixed by Jared Minch 
|-
|{{va|C343-169}}
|{{/bugstatus|Unknown}}|| ||[[Autopickup]] fails during a failed [[untrap]] attempt. ||  Player is involuntarily repositioned onto the trapped tile, but items there are not automatically picked up.
|-
|{{va|C343-170}}
|{{/bugstatus|Unknown}}|| ||[[Silver damage|Damage by silver]] [[weapons]] is sometimes higher than intended when hero is [[polymorph]]ed.||Perhaps this refers to the fact players hit multiple times with the same weapon if polymorphed into a form with several weapon attacks, e. g. [[Aleax]] or [[marilith]].
|-
|{{va|C343-171}}
|{{/bugstatus|Fixed}}|| [https://sourceforge.net/apps/trac/unnethack/changeset/910 UnNetHack] ||[[Silver damage|Silver weapon damage]] message is sometimes missing when hero is [[polymorph]]ed.
|-
|{{va|C343-172}}
|{{/bugstatus|Unknown}}|| ||Crash could occur when [[monster]] uses [[potion]] or [[food]] to cure [[stoning]] or [[confusion]].
|-
|{{va|C343-173}}
|{{/bugstatus|Unknown}}|| ||[[Monster]] [[eat]]ing [[lizard corpse]] is not handled correctly.|| 	jmminch says a monster eating a lizard corpse for confusion lost speed
|-
|{{va|C343-174}}
|{{/bugstatus|Fixed}}|| [https://sourceforge.net/apps/trac/unnethack/changeset/948 UnNetHack] ||[[Drum of earthquake]] gives inappropriate message if hero or [[monster]] is in a [[pit]].
|-
|{{va|C343-175}}
|{{/bugstatus|Fixed}}|| [https://github.com/Bulwersator/UnNetHackPlus/commit/541d0b417bb81df10b4486b895ca78f5bb938247  UnNetHackPlus] ||[[Chat]]ting to hostile [[prisoner]]s may give an inappropriate message.
|There is a bug in description of the bug - it applies to tame prisoners (MS_DJINNI is mostly OK, but tame one - "Sorry, I'm all out of wishes." is weird).
|-
|{{va|C343-176}}
|{{/bugstatus|Fix available}}|| [http://nethackwiki.com/mediawiki/index.php?title=Bugs_in_NetHack_4&curid=20715&diff=84781&oldid=84316] ||[[Disintegration]] breath hitting [[equipment]] carried by [[monster]]s is not handled properly; if the monster [[amulet of life saving|life-saves]] the situation is worse; [[saddle]]s are especially troublesome.||[http://groups.google.com/group/rec.games.roguelike.nethack/browse_thread/thread/28d963518c111e25# Archive of report on rgrn]  "The invisible saddled ki-rin is not saddled." 
|-
|{{va|C343-177}}
|{{/bugstatus|Moot}}|| ||First false [[rumor]] is displayed as gibberish on some platforms.
|I assume here that it affects something obscure like Amiga (UnNetHackPlus supports only windows and linux)
|-
|{{va|C343-178}}
|{{/bugstatus|Unknown}}|| ||[[Wisdom]] is mishandled when [[rumor]]s are used for random [[graffiti]]. ||  getrumor() exercises or abuses wisdom, which doesn't really make sense when it's being used to generate random graffitti on the floor. 
|-
|{{aa|C343-179}}
|{{/bugstatus|Fixed}}||{{Bilious|340}}||If a [[monster]] is killed by a [[drawbridge]] while carrying a [[potion of acid]], the game may [[panic]].
|-
|{{va|C343-180}}
|{{/bugstatus|Help}}|| ||In an obscure case on [[special levels]], [[troll]] corpses may fail to revive and [[lizard corpse]]s may revive.
|-
|{{va|C343-181}}
|{{/bugstatus|Unknown}}|| ||The hero is welcomed to [[Delphi]] even if the [[Oracle]] was previously angered.|| Fixed by Jared Minch 
|-
|{{va|C343-182}}
|{{/bugstatus|Unknown}}|| ||Putting on the [[Eyes of the Overworld]] while [[blind]] gives an ungrammatical message.|| "You are blasted by the pair of lenses' power! You are now wearing an Eyes of the Overworld. You can see!" Also, the possessive form (the Eyes of the Overworld's), which shows up if you are blasted by their power when they are identified, is arguable. 
|-
|{{va|C343-183}}
|{{/bugstatus|Unknown}}|| ||[[Jump]]ing over an already seen [[trap]] may give an ungrammatical message.|| "You pass right over a anti-magic field." The message is also semantically odd for a falling rock trap, due to the word "over". 
|-
|{{va|C343-184}}
|{{/bugstatus|Unknown}}|| ||[[Levitation]] via worn [[equipment]] is not implemented for [[monster]]s.
|-
|{{va|C343-185}}
|{{/bugstatus|Confirmed}}|| ||No message is generated when attempting to [[name]] a [[monster]] that cannot be named by the player. || Confirmed with shopkeepers.
|-
|{{va|C343-186}}
|{{/bugstatus|Unknown}}|| ||Some messages referring to "[[priestess]]" say "[[priest]]." ||  uhitm.c hardcodes "The priest mutters a prayer." 
|-
|{{va|C343-187}}
|{{/bugstatus|Unknown}}|| ||[[Meditating]] [[monsters]] continue meditating when affected by something which wakes [[sleep]]ing monsters. ||  For example, playing a leather drum does not awaken them. 
|-
|{{va|C343-188}}
|{{/bugstatus|Unknown}}|| ||Specifying [[role]] and/or [[race]] and an invalid [[alignment]] in [[options|NETHACKOPTIONS]] or [[config file]] causes a misleading message. ||  "Incompatible alignment." 
|-
|{{va|C343-189}}
|{{/bugstatus|Fixed}}|| UnNetHack ||[[Temple]] [[donation]]s and [[protection]] lost to [[gremlin]] attack interact incorrectly.||Specifically, a gremlin steals only the effectiveness of divine protection, not the amount.
|-
|{{va|C343-190}}
|{{/bugstatus|Unknown}}|| ||[[Monster]]s can hide while [[trap]]ped or holding the hero.
|-
|{{va|C343-191}}
|{{/bugstatus|Unknown}}|| ||When an unseen monster forces a [[polymorph]]ed hero out of hiding, feedback is insufficient.
|-
|{{va|C343-192}}
|{{/bugstatus|Unknown}}|| ||If [[invocation]] is performed while hero is [[trap]]ped, hero remains trapped.
|-
|{{va|C343-193}}
|{{/bugstatus|Unknown}}|| ||[[Polymorph]]ed hero can fall into [[water]] once and crawl out twice.
|-
|{{va|C343-194}}
|{{/bugstatus|Unknown}}|| ||Saving and restoring a game while [[punished]] and [[swallowed]] sometimes loses the [[iron ball|ball]] and [[iron chain|chain]]. ||  I read an uncursed scroll of punishment, tried to pick up ball but it burdened me, so I set it back down, then I got swallowed by a purple worm, saved, restored, and the ball and chain were gone. 
|-
|{{va|C343-195}}
|{{/bugstatus|Unknown}}|| ||[[Glass]] [[wand]] thrown and broken in a [[shop]] is not charged for.
|-
|{{va|C343-196}}
|{{/bugstatus|Unknown}}|| ||Wielded [[light source]] may get missed by [[rust trap]].|| According to Aardvark Joe, your lamp will go out if the water hits your body, but never if the water hits the arm wielding the lamp itself. 
|-
|{{va|C343-197}}
|{{/bugstatus|Unknown}}|| ||Attacking a hidden [[monster]] sensed via ongoing [[monster detection]] is interrupted inapropropriately.|| "Wait! There's a snake hiding under an uncursed pear!" Yeah, I kind of knew that. 
|-
|{{va|C343-198}}
|{{/bugstatus|Fixed}}|| UnNetHack ||Playing in a 20 or 21 line window can cause the game to crash.
|-
|{{va|C343-199}}
|{{/bugstatus|Fixed}}|| UnNetHack ||The database entry for "[[monk]]" has a typo.||There should be a comma after the quotation. Traditional typesetting would do this: "No," replied the monk. Modern style (developed within the last thirty years) might put the comma outside the quote.
|-
|{{va|C343-200}}
|{{/bugstatus|Unknown}}|| ||In the [[quest]], it's possible to accidently skip the locate level||e. g. by falling down a hole several levels.
|-
|{{va|C343-201}}
|{{/bugstatus|Unknown}}|| ||Phrasing of message when one [[monster]] attacks another with stacked weapons is odd.
|-
|{{va|C343-202}}
|{{/bugstatus|Unknown}}|| ||Pushing a [[boulder]] onto a [[level teleporter]] [[trap]] could cause repeated messages.|| Happens about three times out of ten. "You push the boulder and suddenly it disappears! You push the boulder and suddenly it disappears!" May be triggered when the levelport selects the level you and the boulder are currently on, and the code runs again to select a different destination. 
|-
|{{va|C343-203}}
|{{/bugstatus|Unknown}}|| ||Hero arriving on a very crowded level may land on a [[monster]] causing game state corruption and possibly a crash.|| mnexto failed (do.c)? Program in disorder - perhaps you'd better save. rloc(): couldn't relocate monster Program in disorder - perhaps you'd better save. 
|-
|{{va|C343-204}}
|{{/bugstatus|Unknown}}|| ||Hero [[Holding attack|grabbed]] or [[Engulfing|engulfed]] due to [[conflict]] should be released when conflict ends.|| Not only are you not released, but it's not obvious how to get out without harming your pet. 
|-
|{{va|C343-205}}
|{{/bugstatus|Unknown}}|| ||Changes in [[hallucination]] state are not reflected properly when also [[Mimic|mimicing]].|| "Oh wow! Everything feels so cosmic!" ... "You return to human form! Far out! Everything is all cosmic again!" Again? Also, the hiding is not relevant here; this bug can also be reproduced when polyselfing into other blind monsters, e.g., a gelatinous cube. 
|-
|{{va|C343-206}}
|{{/bugstatus|Unknown}}|| ||[[Divine gift]]s resulting from [[offer|#offer]] are [[identification|identified]] when [[blind]].||If [[Stormbringer]] is gifted to a blind character, it will still be described as a "black sword"{{refsrc|pray.c|743}}. "quoting [[Blindness#Object_appearances]]: "The special attacks of the Tsurugi of Muramasa and Vorpal Blade always tell you the artifacts's appearance.[22][23][24][25] The gift you would receive on crowning as neutral or chaotic are made "seen" if you are already holding it."" [http://nethackwiki.com/mediawiki/index.php?title=Talk:Bugs_in_NetHack_4&curid=20755&diff=83570&oldid=78199]
|-
|{{va|C343-207}}
|{{/bugstatus|Unknown}}|| ||Certain [[items]] that should never be created in [[Gehennom]] can be created there.|| Most likely refers to spellbooks, although the circumstances are unknown. Possibly refers to objects generated in boxes/chests? 
|-
|{{va|C343-208}}
|{{/bugstatus|Unknown}}|| ||Hero can be [[blind]]ed while fainted.|| "You faint from lack of food. It explodes! You seem unaffected by it. You regain consciousness." Perhaps the dev team intended it to wake and blind you? 
|-
|{{va|C343-210}}
|{{/bugstatus|Unknown}}|| ||Hero can "[[stun|feel a bit steadier]]" while unconscious.|| Aardvark Joe says, eat a bat corpse, then quaff a potion of sleeping. 
|-
|{{va|C343-211}}
|{{/bugstatus|Fixed}}|| UnNetHack ||[[Engraving]] under water gives a poorly worded message.
|-
|{{va|C343-212}}
|{{/bugstatus|Unknown}}|| ||If the hero is killed by a thrown [[potion of oil|potion of burning oil]], the game will panic.
|-
|{{va|C343-213}}
|{{/bugstatus|Unknown}}|| ||Display of [[scroll of stinking cloud|stinking cloud]] may be incorrect when wearing [[Eyes of the Overworld]].|| Believed to be fixed in GruntHack. 
|-
|{{va|C343-214}}
|{{/bugstatus|Unknown}}|| ||Monster escaping by changing levels in the wizard tower may end up outside the tower too easily.
|poke vlad with magicbane until he's confused and wounded. Assume he's created with a scroll of teleportation. He will read it, and levelport to any random level in the Dungeons of Doom, Gehennom abvoe his tower, and his tower. [http://nethackwiki.com/mediawiki/index.php?title=Talk:Bugs_in_NetHack_4&curid=20755&diff=83570&oldid=78199]
|-
|{{va|C343-215}}
|{{/bugstatus|Unknown}}|| ||[[Elbereth]] is sometimes ignored by monsters.|| Could refer to the need to "mark" the square with an item (an artifact of the effect originally belonging to the scroll of scare monster), or that Kops only respect Elbereth when you're on it. 
|-
|{{va|C343-216}}
|{{/bugstatus|Unknown}}|| ||[[Erodeproof|Fireproof]] containers catch fire in lava.
|-
|{{va|C343-217}}
|{{/bugstatus|Unknown}}|| ||Missile which kills engulfer is temporarily lost when hero is expelled.|| May refer to the missile being placed on the ground after the player is, rather than before, which can be noticed via autopickup. 
|-
|{{va|C343-218}}
|{{/bugstatus|Fixed}}||{{Bilious|342}}||Applying a wielded [[cream pie]] can crash the game. This generalizes to wielded objects being destroyed.
|-
|{{va|C343-219}}
|{{/bugstatus|Unknown}}|| ||Hero can die due to "burned by burning" or "drowned by drowning."||A lot of similar combinations are possible by messing around with delayed_killer by stacking many delayed instadeaths on top of each other.
|-
|{{va|C343-220}}
|{{/bugstatus|Unknown}}|| ||Eating a [[Rider]] corpse doesn't work quite right.||If you start eating it, die as a result, and lifesave, you can finish it safely. (The same thing happens to some other sort of corpses, like rotten ones, but not nearly as obviously.)
|-
|{{va|C343-221}}
|{{/bugstatus|Unknown}}|| ||Jabberwocks do not always wake up when they should.
|-
|{{va|C343-222}}
|{{/bugstatus|Unknown}}|| ||It's possible to end up wielding a [[cockatrice]] corpse when no longer polymorphed. || Quuxplusone 
|-
|{{va|C343-223}}
|{{/bugstatus|Unknown}}|| ||Hidden [[pet]] can follow hero down stairs, remain hiding and show up as hidden monster. Also can happen with a magic whistle. ||  Tested with a tame scorpion hiding under an item. After traversing the stairs it was still hiding for a turn or two, even though there was nothing there to hide under. 
|-
|{{va|C343-224}}
|{{/bugstatus|Not a bug}}|| ||Carrying too many items creates uselessly long prompts.|| Using a WIZKIT allows player to have too large amount of items, what results in prompts with repeated # sign (for example on dropping items). I do not consider it useless.
|-
|{{va|C343-225}}
|{{/bugstatus|Unknown}}|| ||Hero can sometimes carry too many boulders. || Even the number of available inventory slots is no obstacle when polymorphed into a titan. 
|-
|{{va|C343-226}}
|{{/bugstatus|Unknown}}|| ||Inventory display doesn't mention unpaid items in a container the hero owns. ||  The container is listed, but its contents are not even if unpaid. Not sure exactly what the expected behavior would be here. 
|-
|{{va|C343-227}}
|{{/bugstatus|Unknown}}|| ||Container dropped in a shop then moved to an untended shop behaves oddly.
|-
|{{va|C343-228}}
|{{/bugstatus|Unknown}}|| ||Cloak of magic resistance is active when it shouldn't be.
|-
|{{va|C343-229}}
|{{/bugstatus|Unknown}}|| ||Hero can dip or apply grease to a worn item that is covered by another worn item.
|A similar effect applies to monsters getting dressed, while wearing a cursed cloak / body armor.  You can #dip a shirt that's covered by DSM into holy water, but you cannot apply grease to DSM that's covered by a cloak. 
|-
|{{va|C343-230}}
|{{/bugstatus|Unknown}}|| ||Drawbridges act differently depending on which direction they are pointing.
|-
|{{va|C343-231}}
|{{/bugstatus|Fixed}}|| UnNetHack ||Time is distorted while sinking into lava.||Because lava sinking is checked once per player input (inexplicably), as opposed to once per player turn or once per time-consuming action.
|-
|{{va|C343-232}}
|{{/bugstatus|Fix available}}|| [https://github.com/sgrunt/GruntHack/commit/6533efe10d6f33e151352be51247a5420a3fa7a0 GruntHack] ||Hero can be slimed while in lava.
|-
|{{va|C343-233}}
|{{/bugstatus|Confirmed}}|| ||Hero polymorphed into Quantum Mechanic may get erroneous messages about disappearing monsters.
|Moster teleported together with engulfed player: "%s suddenly disappears!". Monster teleported away, without player inside (happens in endgame) - no message. [https://github.com/sgrunt/GruntHack/commit/d55e0310fa32a6053f4acacba765dc6d6d3ffda3 location of buggy code, this patch is not fixing second case]
|-
|{{va|C343-234}}
|{{/bugstatus|Unknown}}|| ||Sacrifice on an [[altar]] can have unintended consequences.||Perhaps this refers to the fact the corpse of a former pet does not vanish.
|-
|{{va|C343-235}}
|{{/bugstatus|Fixed}}|| UnNetHack ||Casting spell of protection gives incorrect message if hero is swallowed or in rock.
|-
|{{va|C343-236}}
|{{/bugstatus|Unknown}}|| ||[[Engraving]] works in places it shouldn't.
|-
|{{va|C343-237}}
|{{/bugstatus|Unknown}}|| ||The relationship between [[crossbow]] use and strength is wrong. ||  This has been altered in SporkHack and debated on rgrn. In Next version, Pat Rankin said, "As far as crossbows go, they were changed some time back to shoot for maximum distance regardless of strength or dexterity, and to require high strength to retain full multi-shot volleys." 
|-
|{{va|C343-238}}
|{{/bugstatus|Unknown}}|| ||(Unix and VMS only) The "Who are you?" prompt does not accept digits in the response. ||  You can include digits in your answer, but if your answer starts with a digit the guard will just reprompt you. 
|-
|{{va|C343-239}}
|{{/bugstatus|Unknown}}|| ||Engravings can transfer between a moat and a [[drawbridge]]. ||  Engrave on the bridge, then step away and play the passtune. 
|-
|{{va|C343-240}}
|{{/bugstatus|Unknown}}|| ||Hero can create a [[pit]] in air. ||  Can be accomplished by setting a land mine and waiting for a monster to trigger it (or I suppose you could trip it yourself). Related to C343-82.
|-
|{{va|C343-241}}
|{{/bugstatus|Fix available}}|| [https://github.com/sgrunt/GruntHack/commit/7704a8f05c0d87da986e55f6d2ca1ec3c8c45117 GruntHack] ||Hero is not charged for breaking the lock on a [[container]] owned by a [[shop]].
|-
|{{va|C343-242}}
|{{/bugstatus|Unknown}}|| ||[[Shopkeeper]]s and priests avoid graves when they should not.
|Priests will pick a random spot next to their altar, and try to go there whithout stepping into your line of attack. Game-play observation implies this "without" part also blocks them from stepping onto a (bones file) grave.

For example, if there's a grave on the tile directly inside the door of a shop, the keeper will not step there, making it easier than it should be for you to get in and out of the shop. You can walk in with a pick-axe in open inventory, for example, or walk out with shop merchandise (although in the latter case you face Kops and striking, and THEN the shopkeeper will finally step on the grave and come after you). I'm not sure exactly how this applies to priests, though. 
|-
|{{va|C343-243}}
|{{/bugstatus|Fixed}}|| [https://github.com/sgrunt/GruntHack/commit/b6416957f7e6dd468d9491be8f7ca3814b1a5622 GruntHack] ||Hero can throw without hands.
|-
|{{va|C343-244}}
|{{/bugstatus|Unknown}}|| ||Sometimes you can eat artifacts you can't touch with your hands.
|-
|{{va|C343-245}}
|{{/bugstatus|Unknown}}|| ||Hero trying to kick beyond map edge is handled improperly. ||  According to Aardvark Joe, "I suspect this bug refers to the fact that the code does not validate the location that you're trying to kick, and can end up accessing memory outside of the map structure, which can cause memory corruption. I'm able to recreate this in NH4 by kicking a location off of the edge of the map, and eventually end up with a segmentation fault." 
|-
|{{va|C343-246}}
|{{/bugstatus|Unknown}}|| ||Engraving with an empty wand handles time wrong.||If you cancel the engraving text prompt or are levitating, no time is spent.
|-
|{{va|C343-247}}
|{{/bugstatus|Unknown}}|| ||A magic portal may be deactivated if the game is saved due to hangup while changing levels. || The official buglist mentions  "Leave the level some other way then return to it." as a workaround.
|-
|{{va|C343-248}}
|{{/bugstatus|Fix available}}||{{bilious|257}}[https://github.com/sgrunt/GruntHack/commit/f67c8478e844ee4d72bd2be832c6d28ea74ae8b5]||You can't put candles in a candelabrum while underwater.
|-
|{{va|C343-249}}
|{{/bugstatus|Unknown}}|| ||There are a number of errors handling vomit; and real rats can't vomit.
|-
|{{va|C343-250}}
|{{/bugstatus|Unknown}}|| ||Rust-causing targets can reveal other information about a weapon.
|-
|{{va|C343-251}}
|{{/bugstatus|Unknown}}|| ||Monsters sleeping due to being hit may wake up at the wrong time.
|-
|{{va|C343-252}}
|{{/bugstatus|Fixed}}|| UnNetHack ||There is a typo in the quote from "The Count of Monte Cristo."
|-
|{{va|C343-253}}
|{{/bugstatus|Unknown}}|| ||Choking on certain food items doesn't work properly.
|-
|{{va|C343-254}}
|{{/bugstatus|Unknown}}|| ||Shapechanger's don't take advantage of being mimics or hiders.
|-
|{{va|C343-255}}
|{{/bugstatus|Unknown}}|| ||Tinning on a full level fails improperly.
|-
|{{va|C343-256}}
|{{/bugstatus|Unknown}}|| ||Very very very long messages can cause a crash. 
|-
|{{va|C343-257}}
|{{/bugstatus|Unknown}}|| ||Cursed corpses wielded by monsters are not handled properly.||Perhaps this refers to the fact wielded items are always dropped when a monster polymorphs.
|-
|{{va|C343-258}}
|{{/bugstatus|Fixed}}|| UnNetHack ||Grammar error in samurai quest: "wakarimasu?" instead of "wakarimasu ka?"
|-
|{{aa|C343-259}}
|{{/bugstatus|Fixed}}|| UnNetHack ||"Dr. Dolittle" is spelled incorrectly.
|-
|{{va|C343-260}}
|{{/bugstatus|Unknown}}|| ||Ridden steeds are sometimes immune to gas traps. ||  Specifically, if the player has intrinsic sleep resistance, it protects the ridden steed as well. 
|-
|{{va|C343-261}}
|{{/bugstatus|Unknown}}|| ||Sleeping steeds can jump. ||  I get "you can't see where to land", no matter how well lit things are. Once the horse wakes back up, I can see to land just fine.

Can you or monsters kick your steed, causing it to jump and evade the kick? 
|-
|{{va|C343-262}}
|{{/bugstatus|Confirmed}}|| ||Polyporph mis-handles a used and wielded leash. ||  Polyself into something that cannot wield (e.g. a hell hound). "You find you must drop your weapon!" This leaves an in-use leash on the ground. Your pet can even pick it up, carry it around, drop it, and it's still listed as "(in use)". 
|-
|{{va|C343-263}}
|{{/bugstatus|Fix available}}|| [https://github.com/sgrunt/GruntHack/commit/7e5bdcac07cc9cc36c19c9b69ccaf0b528594761 GruntHack] ||Probing may miss Schroedinger's cat.||The cat is created only when the container is opened, but should be when it is observed.
|-
|{{va|C343-264}}
|{{/bugstatus|Useless}}|| ||"You must drop your weapon" may appear when it should not. || Assumed to be duplicate of C343-262
|-
|{{va|C343-265}}
|{{/bugstatus|Unknown}}|| ||Force may work when hero can't reach lock being forced.|| For example, while wearing a ring of levitation, you can #force the lock on a chest, but you cannot #loot it. 
|-
|{{va|C343-266}}
|{{/bugstatus|Confirmed}}|| ||Hero on drawbridge when it's destroyed is not handled properly. ||  Destroy a drawbridge by zapping a wand of striking or of digging downward while standing on the bridge. "The drawbridge collapses into the moat" without harming you, leaving you standing on the moat even if you are not properly equipped to stand there. Information has been posted to rgrn about the dev team's fix for this; to find the thread, search for phlebocratic postreticular apodiosis. ("It now calls spoteffects() for the hero or minliquid() for monsters.  If the exposed terrain is water or lava, then the former bridge occupant will fall in (and hero might crawl out of the water); other under-bridge terrain is safe.")
|-
|{{va|C343-267}}
|{{/bugstatus|Unknown}}|| ||Game says monster speed changes even if monster can't move at all. ||  Fixed in AceHack. Reproduced in NH4 by zapping wands of speed and slow monster at a red mold (which is sessile, according to the wiki). 
|-
|{{va|C343-268}}
|{{/bugstatus|Fixed}}||{{Bilious|340}}||Used up potion of acid may end up in bones file.
|-
|{{va|C343-269}}
|{{/bugstatus|Unknown}}|| ||Bones file created after hero dies outside shop may mis-handle items.
|-
|{{va|C343-270}}
|{{/bugstatus|Fixed}}|| UnNetHack ||Dying in a shop while wielding two weapons may cause a warning message.
|-
|{{va|C343-271}}
|{{/bugstatus|Unknown}}|| ||Pet messages at the very end of the game may appear in the wrong place.
|-
|{{va|C343-272}}
|{{/bugstatus|Unknown}}|| ||Corrupted score file can crash the game.
|-
|{{va|C343-273}}
|{{/bugstatus|Unknown}}|| ||Changing alignment and held artifacts interact incorrectly.||E. g. you still enjoy the when-carried benefits of artifacts you could not pick up due to your current alignment.
|-
|{{va|C343-274}}
|{{/bugstatus|Unknown}}|| ||Odd message when attempting to apply a wielded towel. ||  "You cannot use it while you're wearing it!" 
|-
|{{va|C343-275}}
|{{/bugstatus|Fixed}}||{{Bilious|342}}||If a lit, wielded, candle or potion of oil burns out, the game may crash.
|-
|{{va|C343-276}}
|{{/bugstatus|Fixed}}||{{Bilious|342}}||If a figuring auto-transforms while wielded or worn, the game may crash.
|-
|{{va|C343-277}}
|{{/bugstatus|Unknown}}|| ||Wooden weapons don't always burn when they should.
|-
|{{va|C343-278}}
|{{/bugstatus|Unknown}}|| ||Quest leaders are too likely to be affected by traps.
|-
|{{va|C343-279}}
|{{/bugstatus|Unknown}}|| ||Kicked arrows may get wrong bonuses.
|-
|{{va|C343-280}}
|{{/bugstatus|Unknown}}|| ||Ranged polearm attack doesn't always work properly.
|-
|{{va|C343-281}}
|{{/bugstatus|Unknown}}|| ||Kicking shop-owned food is not always accounted for correctly.
|-
|{{va|C343-282}}
|{{/bugstatus|Unknown}}|| ||Damage calculation may be wrong when hero is polymorphed into a pudding.
|-
|{{va|C343-283}}
|{{/bugstatus|Unknown}}|| ||Long walks take a non-optimial path.
|-
|{{va|C343-284}}
|{{/bugstatus|Unknown}}|| ||Activating a shop-owned figurine sometimes don't entail shop charges.||If you pick up and drop a cursed figurine, the timer will stay live. Will this eventually incur charges?
|-
|{{va|C343-285}}
|{{/bugstatus|Unknown}}|| ||Water elementals can be trapped in a bear trap.
|-
|{{va|C343-286}}
|{{/bugstatus|Unknown}}|| ||Polymorph and lycanthropy do not interact properly.
|-
|{{va|C343-287}}
|{{/bugstatus|Unknown}}|| ||Hero polymorphed into monster with kick attack doesn't get bonus from ring of increase damage when kicking.
|-
|{{va|C343-288}}
|{{/bugstatus|Unknown}}|| ||The message "a monster appears" can show up when multiple monsters appear.
|-
|{{va|C343-289}}
|{{/bugstatus|Unknown}}|| ||If magical removal of a steed's saddle is fatal to the hero, the saddle may still be on the steed in a bones file.
|-
|{{va|C343-290}}
|{{/bugstatus|Fix available}}|| [https://github.com/sgrunt/GruntHack/commit/3d133d5407ad4a4ceb8082f16dfe1098a7944163 GruntHack] ||Rings do not show up in the "what do you want to charge?" prompt when they should. ||Applies to oil lamps, too.
|-
|{{va|C343-291}}
|{{/bugstatus|Unknown}}|| ||Backstab bonus interacts incorrectly with thrown weapons and two-weapon mode. || Two-weapon does not get backstab at all while each fired weapon does individually.
|-
|{{va|C343-292}}
|{{/bugstatus|Unknown}}|| ||Touching a pile of objects while blind does not always work correctly.
|-
|{{va|C343-293}}
|{{/bugstatus|Unknown}}|| ||There are a number of errors changing words between singular and plural forms.
|-
|{{va|C343-294}}
|{{/bugstatus|Unknown}}|| ||Orcs and gnomes do not respond to #chat when they should.
|-
|{{va|C343-295}}
|{{/bugstatus|Unknown}}|| ||Casting stone-to-flesh on self while wielding a figurine can cause the game to panic.
|-
|{{va|C343-296}}
|{{/bugstatus|Unknown}}|| ||Sunsword doesn't work as expected against shades.
|-
|{{va|C343-297}}
|{{/bugstatus|Unknown}}|| ||Lit potion may survive hero dying from splattered oil burning on the floor.
|-
|{{va|C343-298}}
|{{/bugstatus|Fixed}}|| UnNetHack ||Kicking at "empty space" uses no time.
|-
|{{va|C343-299}}
|{{/bugstatus|Fixed}}|| [https://github.com/Bulwersator/UnNetHackPlus/commit/342f12c64ca1e6257407b4549d1a9bd87481ed96 UnNetHackPlus] ||Killing tame engulfer from inside gives a warning message.
|-
|{{va|C343-300}}
|{{/bugstatus|Unknown}}|| ||Amulet of strangulation may kill forms that can't be strangled.
|-
|{{va|C343-301}}
|{{/bugstatus|Unknown}}|| ||Nymphs can steal things they can't pick up.||They can steal Rider corpses from gelatinous cubes. The bug might instead refer to nymphs stealing things that they don't naturally pick up, like [[potion]]s.
|-
|{{va|C343-302}}
|{{/bugstatus|Fixed}}|| [https://github.com/Bulwersator/UnNetHackPlus/commit/afc67aca0e59f5a26f0b26baf9dc6399c8b6b644]+[https://github.com/Bulwersator/UnNetHackPlus/commit/1eca66fbdca7c224d45c255ef6729a889832964e] ||Amnesia of object discoveries may forget to forget one thing. || Thanks to [[read.c#line501]] player doesn't forget anything when the "count * percent" is smaller than 50. In other words player that knows identify of single object will never loose memory of it via mind flayer attack. IMHO in addition forget_objects should forget percent% of objects, rather than floor(percent% + 0,5% of objects)
|-
|{{va|C343-303}}
|{{/bugstatus|Unknown}}|| ||Gem probabilities are not reset properly on level revisit.
|-
|{{va|C343-304}}
|{{/bugstatus|Unknown}}|| ||Message given when damaging a closed drawbridge may refer to a wall.
|-
|{{va|C343-305}}
|{{/bugstatus|Fixed}}|| [https://github.com/Bulwersator/UnNetHackPlus/commit/5fe2a65a35bb5006a7b1b54c6ce1032687a4c055 GruntHack] ||Attacking with an applied polearm ignores the "confirm" option.
|-
|{{va|C343-306}}
|{{/bugstatus|Unknown}}|| ||Engulfer under influence of conflict or confusion can swallow a monster and not be affected by water/lava/trap under monster until next turn.
|-
|{{va|C343-307}}
|{{/bugstatus|Moot}}||UH in UNH is unable to restore attributes||Unicorn horn interacts incorrectly with ring of sustain ability. ||Non-cursed restores, but cursed does not decrement attributes.
|-
|{{va|C343-308}}
|{{/bugstatus|Fix available}}|| [https://github.com/sgrunt/GruntHack/commit/4f0b9c2f8204aad9aa92b327a687d23b02cf8b97 GruntHack] ||A hidden, dead monster can revive hidden under its own corpse.
|-
|{{va|C343-309}}
|{{/bugstatus|Unknown}}|| ||Dropping Heart of Ahriman may give odd message sequence.
|-
|{{va|C343-310}}
|{{/bugstatus|Unknown}}|| ||Applying an unpaid stack of potions of oil forces hero to buy all of them.
|-
|{{va|C343-311}}
|{{/bugstatus|Unknown}}|| ||Price of unpack shop items may change when hero is forced to buy. ||For example, hunger status has an effect on food prices.
|-
|{{va|C343-312}}
|{{/bugstatus|Unknown}}|| ||Monster can attack with a polearm it was unable to wield.
|-
|{{va|C343-313}}
|{{/bugstatus|Unknown}}|| ||"You trip over it" may appear even after you know what "it" is.
|-
|{{va|C343-314}}
|{{/bugstatus|Unknown}}|| ||Drowning on the Plane of Water lists cause of death as "drowned in a moat."
|-
|{{va|C343-315}}
|{{/bugstatus|Unknown}}|| ||Small monsters dropping items due to weight use the wrong weights.
|-
|{{va|C343-316}}
|{{/bugstatus|Unknown}}|| ||Monsters who shouldn't will attack the Wizard to get the Amulet. ||See also SC343-19.
|-
|{{va|C343-317}}
|{{/bugstatus|Unknown}}|| ||Bones data can contain odd characters from player's dogname, catname, or fruit options; this can cause odd terminal-dependent behavior.||NetHack fails to sanitise characters taken from options.
|-
|{{va|C343-318}}
|{{/bugstatus|Fixed}}|| UnNetHack ||Opening or closing the castle drawbridge using music takes no time.
|-
|{{va|C343-319}}
|{{/bugstatus|Unknown}}|| ||Grid bugs can be forced to move diagonally, e. g. by displacing a tame one.
|-
|{{va|C343-320}}
|{{/bugstatus|Unknown}}|| ||Reading scroll of mail break illiterate conduct.
|-
|{{va|C343-321}}
|{{/bugstatus|Unknown}}|| ||Hero and monsters can walk through a long worm's tail diagonally.
|-
|{{va|C343-322}}
|{{/bugstatus|Fix available}}|| [https://github.com/sgrunt/GruntHack/commit/3229061bcb0f3fa4495153b2d9dd47fc0f04325c GruntHack] ||Forced attack on a boulder says "you attack thin air."
|-
|{{va|C343-323}}
|{{/bugstatus|Unknown}}|| ||Objects dropped as a monster dies don't interact properly with the environment.|| See also #362.
|-
|{{va|C343-324}}
|{{/bugstatus|Fixed}}||{{Bilious|332}}|| Cutting a long worm in two will crash the game if the cut takes the worm to 1 HP or if long worms had become extinct.
|-
|{{va|C343-325}}
|{{/bugstatus|Unknown}}|| || Hole in ice may be described as a "moat."
|-
|{{va|C343-326}}
|{{/bugstatus|Unknown}}|| || Open and close commands may give inappropriate feedback near a drawbridge.
|-
|{{va|C343-327}}
|{{/bugstatus|Unknown}}|| || Message "suddenly you cannot see the" monster can be displayed when the monster remains visible for some reason.
|-
|{{va|C343-328}}
|{{/bugstatus|Unknown}}|| || Messages when opening a tin may imply implausible timing.
|-
|{{va|C343-329}}
|{{/bugstatus|Unknown}}|| || A just-dead monster may still claim to be fleeing.
|-
|{{va|C343-330}}
|{{/bugstatus|Unknown}}|| || Wrong message may be delivered when seeing a pet eating.
|-
|{{va|C343-331}}
|{{/bugstatus|Confirmed}}|| || Sleeping monster reacts to a mirror.
|-
|{{va|C343-332}}
|{{/bugstatus|Unknown}}|| || The message given when multiple potions of acid explode refers to a single potion. || Refers to stacks of acid exploding when you go for a swim.
|-
|{{va|C343-333}}
|{{/bugstatus|Unknown}}|| || Vault guard asks hero's name while hero is engulfed.
|-
|{{va|C343-334}}
|{{/bugstatus|Unknown}}|| || Defining GOLDOBJ drops a slot from the inventory.
|-
|{{va|C343-335}}
|{{/bugstatus|Unknown}}|| || Cloak of invisibility and blindness do not interact reasonably.
|-
|{{va|C343-336}}
|{{/bugstatus|Unknown}}|| || A shapechanger starting out in changed form gets incorrect inventory items. || They get items appropriate for their polymorphed form.
|-
|{{va|C343-337}}
|{{/bugstatus|Unknown}}|| || It's possible to create an object of 0 gold pieces. || You have to [[larn|drop 4294967296 (MAXUINT+1) gold]]. Doing that twice crashes the game. Fixed on [[NAO]].
|-
|{{va|C343-338}}
|{{/bugstatus|Unknown}}|| || Wizard-mode command sanity_check misses nested containers and migrating monsters.
|-
|{{va|C343-339}}
|{{/bugstatus|Unknown}}|| || Screen and time are not always updated properly when opening or closing doors while blind.
|-
|{{va|C343-340}}
|{{/bugstatus|Unknown}}|| || Secret door detection does not interact properly with features of the Planes of Water and Air. || The [[next version]] promises to make wands of secret door detection find portals even behind clouds (but not update the screen).
|-
|{{va|C343-341}}
|{{/bugstatus|Unknown}}|| || In minetown, it's possible to teleport into a room that requires digging to escape from.
|-
|{{va|C343-342}}
|{{/bugstatus|Unknown}}|| || Potion thrown by monster which hits long worm's tail says it hit its tail.
|-
|{{va|C343-343}}
|{{/bugstatus|Unknown}}|| || Helm of Opposite alignment gives incorrect piety level. || Currently, you retain your [[alignment record]], e. g. it is possible to gain alignment for robbing a shop while chaotic and calming the shopkeeper while lawful.
|-
|{{va|C343-344}}
|{{/bugstatus|Unknown}}|| || NetHack thinks jellyfish have heads.
|-
|{{va|C343-345}}
|{{/bugstatus|Fixed}}|| [https://github.com/Bulwersator/UnNetHackPlus/commit/aba5543d03c5c0d914c51705d3166e8d5a687660 GruntHack] || Attempting to remove cursed lenses gives a message with poor grammar.
|-
|{{va|C343-346}}
|{{/bugstatus|Unknown}}|| || Attempting to put on some items when the item is already wielded or quivered and failing for a variety of reasons gives a message with poor grammar.
|-
|{{va|C343-347}}
|{{/bugstatus|Unknown}}|| || Picking up and wearing an unknown ring while blind sometimes gives out too much information. || [http://groups.google.com/group/rec.games.roguelike.nethack/msg/489eaa84e7e749b2 RGRN discussion]
|-
|{{va|C343-348}}
|{{/bugstatus|Unknown}}|| || Exercise before polymorph may affect polymorphed character.
|-
|{{va|C343-349}}
|{{/bugstatus|Unknown}}|| || An identify scroll is wasted if space is typed and steps off the end of the inventory list.
|-
|{{va|C343-350}}
|{{/bugstatus|Unknown}}|| || Eels don't hide when they are supposed to.
|-
|{{va|C343-351}}
|{{/bugstatus|Fixed}}|| [https://github.com/Bulwersator/UnNetHackPlus/commit/c7351f208f0ad1deb7cbce394d049572d2b61af9 UnNetHackPlus] || Alchemy-caused explosions don't wake nearby monsters.
|-
|{{va|C343-352}}
|{{/bugstatus|Unknown}}|| || Secret doors in lit walls don't always display properly.
|-
|{{va|C343-353}}
|{{/bugstatus|Unknown}}|| || Aborting key or lock pick with escape uses a turn.
|-
|{{va|C343-354}}
|{{/bugstatus|Unknown}}|| || Probing while engulfed ignores the fact that the hero is in the monster.
|-
|{{va|C343-355}}
|{{/bugstatus|Fixed}}|| [https://github.com/sgrunt/GruntHack/commit/ccf75ee3bce3fe3295870c262ad28845e9f0bac8 GruntHack] || Archeologists start out at basic skill level in sling. || This is a side effect of their touchstone, which is considered sling ammunition.
|-
|{{va|C343-356}}
|{{/bugstatus|Unknown}}|| || Wearing an amulet of restful sleep confuses internal sleep state bookkeeping. || Perhaps related is the fact you can cure instrinsic restful sleep (from eating the amulet) by putting on and removing an amulet of restful sleep.
|-
|{{va|C343-357}}
|{{/bugstatus|Unknown}}|| || Rust monsters may chew non-ferrous items.
|-
|{{va|C343-358}}
|{{/bugstatus|Unknown}}|| || If no co-aligned artifacts are available for gifting when required, gifting fails repeatedly. || For example, this can mean trouble for elven priests who have named Sting and Orcrist in hopes of getting Stormbringer as their first sacrifice gift.
|-
|{{va|C343-359}}
|{{/bugstatus|Unknown}}|| || Setting the fruit name fails if the new name is already known but happens to be not at the end of an internal list.
|-
|{{va|C343-360}}
|{{/bugstatus|Unknown}}|| || A monster wearing a suit can still put on a shirt. || But they (correctly) have to take off cloaks first.
|-
|{{va|C343-361}}
|{{/bugstatus|Unknown}}|| || The message "you feel shuddering vibrations" does not always get displayed when it should.
|-
|{{va|C343-362}}
|{{/bugstatus|Unknown}}|| || Objects dropped during polymorph may be incorrectly polymorphed.
|-
|{{va|C343-363}}
|{{/bugstatus|Unknown}}|| || The case of monsters eating green slime corpses is not handled correctly.
|-
|{{va|C343-364}}
|{{/bugstatus|Unknown}}|| || If player's hand slips while naming an object, 'z' is never picked as the new letter. || [[Naming_artifacts]]?
|-
|{{va|C343-365}}
|{{/bugstatus|Unknown}}|| || Hero may remove armor for nymph or succubus while asleep.
|-
|{{va|C343-366}}
|{{/bugstatus|Unknown}}|| || Concealed mimic not always revealed when it should be.
|A [[stethoscope]] will appraise but not uncloak a mimic. See also [[#SC343-17]].
|-
|{{va|C343-367}}
|{{/bugstatus|Unknown}}|| || Fainting with a wielded cockatrice corpse doesn't behave as expected.
|-
|{{va|C343-368}}
|{{/bugstatus|Unknown}}|| || Blinded hero knows too much about a monster summoning insects.
|-
|{{va|C343-369}}
|{{/bugstatus|Unknown}}|| || Mounted hero on life-saved steed gets repeated warning messages until hero dismounts.
|-
|{{va|C343-370}}
|{{/bugstatus|Unknown}}|| || Travel ({{kbd|_}}) command can get stuck trying to plot a path past an interesting dungeon feature, for example, a trap or fountain.
|-
|{{va|C343-371}}
|{{/bugstatus|Unknown}}|| || Stethoscopes can sometimes be used more often than intended. ||If you save and resume, you can use it again for free. On an aside, saving and restoring loses the movement points you gain from speed, and makes your exercise prior to the save worth less.
|-
|{{va|C343-372}}
|{{/bugstatus|Unknown}}|| || A fatal explosion can give the player messages in the wrong order if carried items are destroyed.
|-
|{{va|C343-373}}
|{{/bugstatus|Unknown}}|| || Shopkeepers can polymorph into forms that don't let them do their jobs. || A blue jelly shopkeeper will buy and sell, but it won't move to block or unblock the door.
|-
|{{va|C343-374}}
|{{/bugstatus|Unknown}}|| || When polymorphed into a grid bug, attempting to move in an illegal direction is handled ungracefully.
|-
|{{va|C343-375}}
|{{/bugstatus|Unknown}}|| || A mimic posing as a statue is not handled properly.
|-
|{{va|C343-376}}
|{{/bugstatus|Unknown}}|| || When trying to move down, Hero can be levitating and stuck in the floor at the same time.
|-
|{{va|C343-377}}
|{{/bugstatus|Unknown}}|| || Hero hidden from monster is still treated as a normal target for range attack.
|-
|{{va|C343-378}}
|{{/bugstatus|Unknown}}|| || Hero hiding as a small mimic can end up stuck to a monster after returning to human form.
|-
|{{va|C343-379}}
|{{/bugstatus|Fixed}}|| UnNetHack || Spelling errors "sprit" and "truely" in quest text.
|-
|{{va|C343-380}}
|{{/bugstatus|Unknown}}|| || Mimics pretending to be doors show up on the Rogue level.
|-
|{{va|C343-381}}
|{{/bugstatus|Unknown}}|| || Attacking by applying a polearm doesn't scuff engraving under hero.
|-
|{{va|C343-382}}
|{{/bugstatus|Fix available}}|| [https://github.com/sgrunt/GruntHack/commit/dca24d18e51eea2ca7b71dca2564b266cc73d27d GruntHack] || Auto-wielding a polearm may take no time. ||Does this also apply to pick-axes when you start digging? I am not sure whatever it should take time.
|-
|{{va|C343-383}}
|{{/bugstatus|Unknown}}|| || Applying a bullwhip while hero is at edge of map may cause a panic or crash.
|-
|{{va|C343-384}}
|{{/bugstatus|Fix available}}|| [https://github.com/sgrunt/GruntHack/commit/af978f5ce38cbd92879e32232eb704447b1d6ab2 GruntHack] || Cutting a level 0 long worm in half may lead to a worm with 0 HP, which may cause a crash. ||Fixed on [[NAO]].
|-
|{{va|C343-385}}
|{{/bugstatus|Unknown}}|| || {{kbd|D}} command doesn't handle {{kbd|u}} choice correctly if only unpaid items are inside containers.
|-
|{{va|C343-386}}
|{{/bugstatus|Fixed}}|| UnNetHack || [[Randomized appearance#Rings|Pearl]] [[ring]]s can [[erosion|rust]].
|-
|{{va|C343-387}}
|{{/bugstatus|Unknown}}|| || [[T-shirt]]s can be [[illiterate|read]] when covered.
|-
|{{va|C343-388}}
|{{/bugstatus|Unknown}}|| || [[Spell]] [[damage]] and low [[intelligence]] interact incorrectly.
|-
|{{va|C343-389}}
|{{/bugstatus|Unknown}}|| || [[Dragon]] breath and certain other effects hitting a hidden [[door|secret door]] does not damage it.
|-
|{{va|C343-390}}
|{{/bugstatus|Unknown}}|| || Breaking a [[wand]] which may zap but not damage a door gives an odd message.
|-
|{{va|C343-391}}
|{{/bugstatus|Fix available}}|| [https://github.com/sgrunt/GruntHack/commit/622fe5bfe550863f9098bac8dcb490779497d9a2 GruntHack] || Hero [[polymorph]]ed into a [[mimic]] with {{kbd|<nowiki>#</nowiki>monster|link=0}} and hiding as an object does not unhide when [[polymorphing]] into a non-mimic. ||The same applies to pet mimics [[magic whistle|whistled]] over a [[polytrap]].
|-
|{{va|C343-392}}
|{{/bugstatus|Unknown}}|| || A [[stun]]ned [[monster]] may both walk away from the hero and keep [[Holding_attack|holding]] him.
|-
|{{va|C343-393}}
|{{/bugstatus|Unknown}}|| || The messages produced when [[throw]]ing a [[poison]]ed [[weapon]] which loses its [[poison]] are in a confusing order.
|-
| {{aa|C343-394}}
|{{/bugstatus|Fixed}}|| {{bilious|340}} || [[Throw]]ing a [[potion of acid]] into [[water]] may [[panic]] the game.|| "may" == "will" Related to C343-19, -179 and -268.
|-
|{{va|C343-395}}
|{{/bugstatus|Not a bug}}|| || Spelling errors at the [[genocide]] prompt may have unintended consequences. || Specifically, genociding "[[Monk#Rank_titles|master]] [[mind flayer|mindflayer]]" as a [[monk]] is fatal.
|-
|{{va|C343-396}}
|{{/bugstatus|Unknown}}|| || [[Shopkeeper]] does not charge hero for an unsold [[boulder]] that is destroyed with a [[pick-axe]].
|-
|{{va|C343-397}}
|{{/bugstatus|Unknown}}|| || A badly formed message may be produced if a [[pick-axe]] is applied to a [[boulder]] and the [[boulder]] is removed by a [[monster]].
|-
|{{va|C343-398}}
|{{/bugstatus|Fix available}}|| [http://patch-tag.com/r/ais523/acehack/snapshot/hash/20110103121617-b78f9-a2817657b50d8d12bb5b821aead05b48bdeb9e6d/patch AceHack] || The game may crash if a wielded [[potion of polymorph]] is drunk.
|-
|{{va|C343-399}}
|{{/bugstatus|Unknown}}|| || Messages referring to a named [[vault]] guard have grammatical errors.
|-
|{{va|C343-400}}
|{{/bugstatus|Unknown}}|| || Wearing a [[cloak of displacement]] identifies it even if hero [[blindness|can't see]].
|-
|{{va|C343-401}}
|{{/bugstatus|Unknown}}|| || Wearing an [[elven cloak]] identifies it even if hero is already [[stealth]]y.
|-
|{{va|C343-402}}
|{{/bugstatus|Unknown}}|| || Putting on a [[ring of stealth]] never identifies it. ||A workaround is to check if putting on elven boots gives a message.
|-
|{{va|C343-403}}
|{{/bugstatus|Fix available}}|| [https://github.com/sgrunt/GruntHack/commit/b5609461699664cd2203c0a1c5aa4cc9ca90db9b GruntHack] || Hero can [[magic marker|write]] a [[scroll]] not sufficiently [[identification|identified]]. || You can write any scroll you have named, even if you don't know the "scroll called FOOBIE NO IDEA" is the scroll you are trying to write. (''[[Bugs_in_NetHack_3.4.3/Reports#C343-403|original report]]'')
|-
|{{va|C343-404}}
|{{/bugstatus|Help}}|| || [[Magic marker|Writing]] a [[scroll]] can give a badly phrased message if the [[scroll]] is known by its appearance.
| What is the badly phrased message in question? 
|-
|{{va|C343-405}}
|{{/bugstatus|Unknown}}|| || Some [[quest artifact]]s are too easily affected by [[stone-to-flesh]]. ||The [[Heart of Ahriman]]
|-
|{{va|C343-406}}
| {{/bugstatus|Unknown}} || || One of the [[coyote]] names is spelled wrong. || ''Nemesis ridiculii'' (from ''Soup or Sonic'') is misspelled as ''Nemesis riduclii''.
|-
|{{va|C343-407}}
| {{/bugstatus|Unknown}} || || If reading an unknown [[scroll of teleport]] puts the hero on another [[scroll of teleport]], the second one is still treated as unknown.
|-
|{{va|C343-408}}
| {{/bugstatus|Unknown}} || || Being killed by a [[monster]] with a long name can send the game into an infinite loop.
|-
|{{va|C343-409}}
| {{/bugstatus|Unknown}} || || [[Unlocking tool|Unlocking]] a [[mimic]] pretending to be a [[door]] is not handled properly. || (''[[Bugs_in_NetHack_3.4.3/Reports#C343-409|original report]]'')
|-
|{{va|C343-410}}
| {{/bugstatus|Unknown}} || || Using an [[Unlocking tool|unlocking]] [[tool]] on a [[boulder]] that's really a [[mimic]] and located in a [[door]]way is not handled properly.
|-
|{{va|C343-411}}
| {{/bugstatus|Unknown}} || || A [[purple worm]] can end up in [[wall]] or rock when swallowing a [[ghost]] or [[xorn]].
|-
|{{va|C343-412}}
| {{/bugstatus|Unknown}} || || Unpaid [[shop]] items [[stealing from shops|stolen]] from hero remain on hero's bill.
|-
|{{va|C343-413}}
| {{/bugstatus|Unknown}} || || While [[blindness|blind]], some actions resulting in "Wait! That's a [[monster]]!" for a [[mimic]] posing as a [[door]] do not update the display correctly.
|-
|{{va|C343-414}}
| {{/bugstatus|Unknown}} || || {{kbd|<nowiki>#</nowiki>untrap|link=0}} of a known [[trap]] location with a concealed [[mimic]] gives correct message but does not update the display.
|-
|{{va|C343-415}}
| {{/bugstatus|Unknown}} || || [[Mail daemon]]s can be created when populating [[special level]]s with [[demon]]s. || [[Vlad's Tower]] is such a place.
|-
|{{va|C343-416}}
| {{/bugstatus|Unknown}} || || Being [[disintegration|disintegrated]] by [[prayer|divine wrath]] gives an inappropriate message.
|-
|{{va|C343-417}}
| {{/bugstatus|Unknown}} || || [[Polymorph]]ing into a [[human]] form may give a message with the wrong [[gender]].
|-
|{{va|C343-418}}
| {{/bugstatus|Unknown}} || || [[Weight]] of non-[[BUC|cursed]] [[bag of holding]] is sometimes off by one. 
|Possibly, this refers to multiple stacks of gold in any bag: two stacks of $49 weigh 0, but one stack of $98 weighs 1. This might relate to shop-owned versus hero-owned gold.
|-
|{{va|C343-419}}
| {{/bugstatus|Unknown}} || || With [[options|option]] [[number_pad]] set to 2, {{kbd|M|5}} (or {{kbd|Alt|5}} or {{kbd|Shift|Keypad5}}) does not work as the {{kbd|G}} movement prefix.
|-
|{{va|C343-420}}
| {{/bugstatus|Unknown}} || || [[Keystone Kop|Kops]] may not be dismissed if the [[shopkeeper]] changes levels. || You might want to pacify the shopkeeper on his home level. If necessary, steal a gold piece and pay him off again.
|-
|{{va|C343-421}}
| {{/bugstatus|Unknown}} || || Object [[teleportation|teleport]] in and around the [[Wizard's Tower]] doesn't work as intended. || (''[[Bugs_in_NetHack_3.4.3/Reports#C343-421|original report]]'')
|-
|{{va|C343-422}}
| {{/bugstatus|Unknown}} || || There are inconsistencies in [[erosion|damage]] applied to objects when encountering [[lava]] in different ways.
|-
|{{va|C343-423}}
| {{/bugstatus|Not a bug}} || || Under some circumstances player can tell if [[bones]] file is created. || "Your body rises from the dead as <monster>..." if killed by a slime/W/V/M.
|-
|{{va|C343-424}}
| {{/bugstatus|Unknown}} || || Unlit [[Candelabrum of Invocation|candelabrum]] becomes unlightable if [[candle]]s have exactly one turn of fuel left and it was applied in the wrong location.
|-
|{{va|C343-425}}
| {{/bugstatus|Unknown}} || || If a [[steed]]'s legs are [[wounded legs|wounded]] while being [[riding|ridden]] and the hero dismounts before the legs heal, the hero's [[dexterity]] will stay reduced. || (''[[Bugs_in_NetHack_3.4.3/Reports#C343-425|original report]]'')
|-
|{{va|C343-426}}
| {{/bugstatus|Unknown}} || || A [[polymorph]]ed hero [[hiding]] on the [[ceiling]] may be forced to drop to an inappropriate position. || (''[[Bugs_in_NetHack_3.4.3/Reports#C343-426|original report]]'')
|-
|{{va|C343-427}}
| {{/bugstatus|Unknown}} || || Inappropriate message claiming a [[paralysis|paralyzed]] [[monster]] "turns to [[scare|flee]]" may appear.
|-
|{{va|C343-428}}
| {{/bugstatus|Unknown}} || || [[Statue]]s in a [[cockatrice]] nest are wrong type if the [[score]] file is empty. || (''[[Bugs_in_NetHack_3.4.3/Reports#C343-428|original report]]'')
|-
|{{va|C343-429}}
| {{/bugstatus|Unknown}} || || When using a [[display]] that scrolls the [[dungeon level|map]], [[teleportation|teleporting]] [[player|hero]] may display off the map momentarily.
|-
|{{va|C343-430}}
| {{/bugstatus|Unknown}} || || It's too easy to open [[tin]]s.
|-
|{{va|C343-431}}
| {{/bugstatus|Unknown}} || || Killing a [[vault guard]] results in a message about "dropping minvent."
| How can this message be generated? 
|-
|{{va|C343-432}}
| {{/bugstatus|Unknown}} || || In a [[vault]] corridor: some [[trap]]s could be left lying around.
|-
|{{va|C343-433}}
| {{/bugstatus|Unknown}} || || In a [[vault]] corridor: you can end up with lighted rock.
|-
|{{va|C343-434}}
| {{/bugstatus|Unknown}} || || In a [[vault]] corridor: when [[blind]], you can be stuck and not be told why.
|-
|{{va|C343-435}}
| {{/bugstatus|Unknown}} || || In a [[vault]] corridor: various kinds of problems may result from having an iron ball.
|-
|{{va|C343-436}}
| {{/bugstatus|Unknown}} || || Hero can [[levitate]] and [[fly]] where it makes no sense.
|-
|{{va|C343-437}}
| {{/bugstatus|Unknown}} || || [[Gremlin]]s sometimes don't respond properly to light.
|-
|{{va|C343-438}}
| {{/bugstatus|Fixed}} || [https://github.com/sgrunt/GruntHack/commit/2cce8e189eb4960b22636fa8cc3002ffa55df952 GruntHack] || Typo "[[zorkmid|gold]] piecess" may occur when [[shop|selling]] items in a [[container]].
|-
|{{va|C343-439}}
| {{/bugstatus|Unknown}} || || Running NetHack in a terminal window with more than 255 rows or columns produces display errors.
|-
|{{va|C343-440}}
| {{/bugstatus|Unknown}} || || If the game [[panic]]s with the [[player|hero]] [[moat|underwater]], the hero may be restored on top of the water.
|-
|{{va|C343-441}}
| {{/bugstatus|Unknown}} || || [[Automatic searching|Autosearching]] while [[blindness|blind]] doesn't update the map when it should.
|-
|{{va|C343-442}}
| {{/bugstatus|Unknown}} || || [[Drain life]] shouldn't override [[drain resistance]] of objects.
|}

=== Spoiler core bugs ===
{| class="prettytable sortable striped"
!Name!!Status!!Patch!!Description!!Additional info
|-
|{{va|SC342-3}}
|{{/bugstatus|Unknown}}|| ||[[Hangup]] can be used to cheat.||If you are slowly turning to stone and trigger a hangup after you are already immobile, you will be granted one action on restoring.
|-
|{{va|SC343-1}}
|{{/bugstatus|Confirmed}}|| ||[[Monster]]s that can't blow can still use a [[whistle]]. || (breathless monsters) You can also use whistle with active amulet of strangulation
|-
|{{va|SC343-2}}
|{{/bugstatus|Unknown}}|| ||If you are [[poison resistant]], [[potion of sickness|potions of sickness]] can only kill you if they are [[blessed]].
|-
|{{va|SC343-3}}
|{{/bugstatus|Unknown}}|| ||[[Water walking boots]] are not handled properly on [[lava]].
|-
|{{va|SC343-4}}
|{{/bugstatus|Unknown}}|| ||Reviving [[corpse]]s or reanimating [[statue]]s in a [[shop]] does not get charged correctly.
|-
|{{va|SC343-5}}
|{{/bugstatus|Unknown}}|| ||Breaking [[container]] contents in a [[shop]] doesn't always charge for them.
|-
|{{va|SC343-6}}
|{{/bugstatus|Unknown}}|| ||Stealing a stack of items from a [[shop]] sometimes results in only being charged for one.
|-
|{{va|SC343-7}}
|{{/bugstatus|Unknown}}|| ||[[Zap]]ping an unknown [[wand]] while [[blind]] sometimes gives out too much information.
|-
|{{va|SC343-8}}
|{{/bugstatus|Fixed}}|| UnNetHack ||Re-animating a [[statue]] containing [[gold]] produces too much gold.||Works on former pets, shopkeepers, and other "special" statues. See the [[TAS]] writeup.
|-
|{{va|SC343-9}}
|{{/bugstatus|Help}}|| ||[[Medusa]] corpse from a level file behaves incorrectly. || Maybe it should be deleted from bones?
|-
|[[SC343-10]]
|{{/bugstatus|Unknown}}|| ||Player can raise [[HP]] and [[Pw]] by dancing with [[vampire]]s.||This is the infamous [[polyself bug]].
|-
|[[SC343-11]]
|{{/bugstatus|Fixed}}||{{Bilious|337}}||It's possible to easily find the identity of a [[high priest]] on the [[Astral plane]].||This is the infamous [[Astral call bug]].
|-
|[[SC343-12]]
|{{/bugstatus|Fixed}}||{{Bilious|337}}||Hero using [[telepathy]] can abuse [[Call]] on the [[Astral Plane]].
|-
|{{va|SC343-13}}
|{{/bugstatus|Unknown}}|| ||While [[blind]] and [[levitating]], too much information may be presented. ||Does this refer to messages about monsters scared by an Elbereth engraving? Or typing {{kbd|>}} to identify the stairs?
|-
|{{va|SC343-14}}
|{{/bugstatus|Help}}|| ||[[Shopkeeper]]s and [[priest]]s may be [[teleport]]ed out of their [[shop]] or [[temple]] too easily.
|What's the intended behaviour here? 
|-
|{{va|SC343-15}}
|{{/bugstatus|Unknown}}|| ||[[Nurse]]s are not stoned by hero polymorphed into cockatrice.
|-
|{{va|SC343-16}}
|{{/bugstatus|Unknown}}|| ||Gelatinous cubes can engulf Rider corpses.
|-
|{{va|SC343-17}}
|{{/bugstatus|Help}}|| ||Stethoscope may unhide hidden mimic.||And why its should not work this way?
|-
|{{va|SC343-18}}
|{{/bugstatus|Help}}|| ||Escaping from lava can leave hero outside of time. ||Nobody knows how to exploit this, please don't ask.
|-
|{{va|SC343-19}}
|{{/bugstatus|Unknown}}|| || Monsters seeking the Amulet attack temple priests to get it.
|-
|{{va|SC343-20}}
|{{/bugstatus|Fixed}}|| UnNetHack || Hangup save while picking up gold in a shop may duplicate the gold.
|-
|{{va|SC343-21}}
|{{/bugstatus|Unknown}}|| || Accounting is incorrect for containers dropped in a shop that does not sell them.
|-
|{{va|SC343-22}}
| {{/bugstatus|Unknown}} || || The [[travel]] command allows [[grid bug]]s to move one step diagonally.
|}

== Windows-only bugs ==
{| class="prettytable sortable striped"
!Name!!Status!!Patch!!Description!!Additional info
|-
|{{va|W341-13}}
|{{/bugstatus|Unknown}}|| ||"Lock Windows" menu item has wrong checkmark at startup
|-
|{{va|W341-14}}
|{{/bugstatus|Unknown}}|| ||[[Message window]] does not update properly if resized.
|-
|{{va|W342-6}}
|{{/bugstatus|Not a bug}}|| ||Checkboxes are drawn wrong.
|-
|{{va|W343-1}}
|{{/bugstatus|Unknown}}|| ||Redirecting [[score]] output through a pipe doesn't work.
|-
|{{va|W343-2}}
|{{/bugstatus|Not a bug}}|| ||Windows 98 is unable to load [[tiles]] that are too large.  This is an OS issue.
|-
|{{va|W343-3|[[W343-3]]}}
|{{/bugstatus|Unknown}}||{{Bilious|313}}||Under the Polish version of Windows 2000 SP4, screen output with a raster font shows wrong characters for many [[dungeon features]].
|-
|{{va|W343-4|[[W343-4]]}}
|{{/bugstatus|Unknown}}||{{Bilious|313}}||Keyboard may stop responding after locking or unlocking a door when using altkeyhandler=[[nhraykey.dll]]
|-
|{{va|W343-5}}
|{{/bugstatus|Unknown}}|| ||Error messages early in the game startup sequence may flash by unreadably.
|-
|{{va|W343-6}}
|{{/bugstatus|Unknown}}|| ||Attempting to start NetHack from within a zip utility doesn't work (this is not a bug) and gives a misleading error message <tt>panic Cannot open dungeon description - "dungeon"</tt> (this is the bug).
| Go back to the installation instructions and finish the install.
|-
|{{va|W343-7}}
| {{/bugstatus|Unknown}} || || Using both <tt>nethack.exe</tt> and <tt>nethackW.exe</tt> can cause <tt>nethackW.exe</tt> to display the top scores list in a series of windows.
|}

== X11-only bugs ==
All bugs are moot as support was dropped.

== Linux-only bugs ==
{| class="prettytable sortable striped"
!Name!!Status!!Description
|-
|{{va|L343-1}}
| {{/bugstatus|Unknown}} || Window resize is not supported by default.
|}

== Macintosh-only bugs ==
All bugs are moot as support was dropped.

== Qt-only bugs ==
All bugs are moot as support was dropped.

== Windows-CE-only bugs ==
All bugs are moot as support was dropped.

== Build-from-source bugs ==
{| class="prettytable sortable striped"
!Name!!Status!!Description!!Additional info
|-
|{{va|S343-1}}
|{{/bugstatus|Moot}}||gnome port refers to file t32-1024.xpm for large tiles that doesn't exist||gnome port support was dropped
|-
|{{va|S343-2}}
|{{/bugstatus|Unknown}}||1x1 room in [[special level]] can trigger [[panic]] due to off by one error (does not affect official room set)
|-
|{{va|S343-3}}
|{{/bugstatus|Unknown}}||makedefs may fail to compile if <tt>sizeof(time_t) != sizeof(long)</tt>
|-
|{{va|S343-4}}
|{{/bugstatus|Unknown}}||NetHack does not compile under Microsoft VC2005.
|-
|{{va|S343-5}}
|{{/bugstatus|Unknown}}||The prototype and definition for finish_map don't match properly.
|-
|{{va|S343-6}}
|{{/bugstatus|Unknown}}||Game does not compile under FreeBSD 6.1.
|-
|{{va|S343-7}}
|{{/bugstatus|Unknown}}|| DLB doesn't work under VMS if a file used by NetHack and without a dot in its name matches a VMS logical name.
|-
|{{va|S343-8}}
|{{/bugstatus|Unknown}}|| NetHack does not compile under Microsoft VS2008 Express Edition.
|-
|{{va|S343-9}}
|{{/bugstatus|Unknown}}|| If time_t changes from 32- to 64-bits due to (e.g.) compiler upgrades, save files will not be compatible between old and new builds.
|-
|{{va|S343-10}}
|{{/bugstatus|Unknown}}|| Windows 64-bit mode compile produces warnings in random.c.
|-
|{{va|S343-11}}
|{{/bugstatus|Unknown}}|| Smartphone keyboard does not work. (Possible reference to:  The [http://www.heise.de/mobil/handygalerie/o2/xda-cosmo-1006/ XDA Cosmo] aka [http://forum.xda-developers.com/forumdisplay.php?f=309 HTC S620] is a Windows Mobile smartphone with a keyboard, yet Nethack insists on mapping every command to the twelve keys 0-9*#.)
|-
|{{va|S343-12}}
| {{/bugstatus|Unknown}} || Game may fail to compile or give warnings if <tt>sizeof(char *) != sizeof(int)</tt>.
|}

== Bugs not mentioned on the DevTeam's website ==
{| class="prettytable sortable striped"
!Name!!Status!!Patch!!Description
|-
|C343-204
|{{/bugstatus|Unknown}}
||   || The hero can teleport on a non-teleport level: Get engulfed by a tame engulfer using conflict, end conflict, apply a magic whistle.
|-
| {{anchor|boulderlava}} 
|{{/bugstatus|Unknown}}
||   || The boulder from a [[rolling boulder trap]] can be generated on top of a lava pool. {{refsrc|trap.c|1584}}
|-
| {{anchor|paste}}  
|{{/bugstatus|Unknown}}
||   || It is impossible to paste (e. g. "ElberethElbereth") into the windows tiles build. This works on OS X, however.
|-
| {{anchor|keynoise}}  
|{{/bugstatus|Unknown}}
||   || The game sometimes behaves as if a series of spurious non-attacking movement commands were typed after #looting a container.
|-
|  {{anchor|throneloot}} 
|{{/bugstatus|Unknown}}
||   || Confused #looting a throne does not destroy it.
|-
| {{anchor|hilitepet}}  
|{{/bugstatus|Unknown}}
||   || The "hilite_pet" option does not work on monsters only seen due to the monster detection spell.
|-
| C343-391 ?  
|{{/bugstatus|Unknown}}
||   || Polymorphing a cloaked pet mimic (by whistling it onto a polytrap) does not unhide it, even if it turns into a non-mimic.
|-
| {{anchor|clairvoyance}}  
|{{/bugstatus|Unknown}}
||   || You can reliably trigger [[clairvoyance]] ([[aligned priest|donation]], [[cornuthaum]], [[amulet of yendor|Amulet]]) by far-looking {{kbd|;}} or wall-walking on turns divisible by 15 until your surroundings are mapped.
|-
| {{anchor|boulderpaci}}  
|{{/bugstatus|Unknown}}
||   || Killing a monster with a rolling boulder trap breaks pacifist conduct if and only if the trap was ''not'' known.
|-
| {{anchor|bribe}}
|{{/bugstatus|Fixed}}
|| [https://github.com/Bulwersator/UnNetHackPlus/commit/4d6c28ab0f1b8df7bd1c411a7330e54f04c5db92 UnNetHackPlus] ||You can't bribe the [[watch]].
|-
| {{anchor|jabberwock}}
|{{/bugstatus|Unknown}}
|| ||Jabberwocks can wield things and hit monsters with them, but monsters will not get petrified, take silver damage, etc. ([http://groups.google.com/group/rec.games.roguelike.nethack/browse_thread/thread/d11ced6ca647d34c/9ba52c38dc9c4390#9ba52c38dc9c4390 Report])
|-
| {{anchor|attackprompt}}  
|{{/bugstatus|Unknown}}
||   || Declining to attack a peaceful monster still burns nutrition without using up the turn.
|-
|  {{anchor|kickprompt}} 
|{{/bugstatus|Fix available}}
|| [https://github.com/sgrunt/GruntHack/commit/a2ec6da8310f6bd9b023fb80325cd9e0d989857b GruntHack] || Declining to kick a peaceful monster still uses up a turn and wakes nearby monsters.
|-
| {{anchor|movementpoints}}  
|{{/bugstatus|Unknown}}
||   || Turns do not alternate correctly if the player has 24 movement energy exactly, and a monster has at least 24 movement energy. ([[Bugs in NetHack 3.4.3/Reports#Turn_alternation_failure_with_24_movement_energy|Report]])
|-
| {{anchor|statstealer}}  
|{{/bugstatus|Unknown}}
||   || Having multi-turn armor stolen by a nymph or monkey while you're putting on a helm of brilliance or gauntlets of dexterity can leave your current and maximum stats permanently affected.
|-
| {{anchor|Elberethteleport}}  
|{{/bugstatus|Unknown}}
||   || Lifesaving during slow [[engraving]] causes the engraving to appear on the ground before it should be completed, but (even if an [[Elbereth]]) not be effective at scaring monsters until it would have been completed. ([http://groups.google.com/group/rec.games.roguelike.nethack/msg/6cdc78c171a41545 ''rgrn post'']) Teleportitis while engraving has a similar effect: at the new location, you still work on the engraving on the old spot.
|-
| {{anchor|praycloud}}  
|{{/bugstatus|Fixed}}
|| [https://github.com/sgrunt/GruntHack/commit/3f358cc7401afcd39eb6193184deb9c35aa517d5 GruntHack] || [[Prayer]] does not protect from [[stinking cloud]]. ([http://groups.google.com/group/rec.games.roguelike.nethack/browse_thread/thread/fde6cafb958fdee6# rgrn post by Grunt])
|-
| {{anchor|twoslip}}  
|{{/bugstatus|Unknown}}
||   || While using #twoweapon, if slippery fingers cause both weapons to slip from your hands, on the same turn, the messages can seem rather odd.  ([http://groups.google.com/group/rec.games.roguelike.nethack/browse_thread/thread/b65233b8c38c94b9 rgrn post])
|-
| {{anchor|soundoption}}  
|{{/bugstatus|Unknown}}
||   || [[Pray]]ing{{refsrc|pray.c|1566}} or [[fainting]]{{refsrc|eat.c|1194}} resets the "sound" [[option]] to true.
|-
| {{anchor|corpsestack}}  
|{{/bugstatus|Unknown}}
||   || Freshly slain corpses stack inconsistently: Say there is a stale stack of corpses on your altar. A way of making the fresh corpses created not get 'oldified' by the existing stale stack is to blind yourself when killing the new puddings; somehow this causes the newly generated corpses to be in a different stack.
|-
| {{anchor|mattacks}}  
|{{/bugstatus|Unknown}}
||   || Moving with the {{kbd|m}} or {{kbd|H}}{{kbd|J}}... commands into a [[warning]] symbol attacks (and stones you if applicable) if and only if it does not cover up an {{white|I}} known from previous searching or movement. (see also: [[m]], todo: document at [[cockatrice]], [[warning]], [[stethoscope]].) Things are even more complicated if you are blind, or if there are invisible monsters you can't see.
Testing a blind player with a peaceful shopkeeper: If you apply a stethoscope and it says Akalapi is there, and then "you move into it", without "Pardon me, Alikapi.", and he doesn't get angry.
|-
| {{anchor|statuenaming}}  
|{{/bugstatus|Unknown}}
||   || If you rename the statue or corpse of a unique monster, then reanimate/revive it, the unique monster will keep its new name permanently (and also gain a "the" prefix if its actual name has one).
|-
| {{anchor|blindnesspotion}}  
|{{/bugstatus|Unknown}}
||   || Wielding or alternate-wielding or quivering a potion of blindness will make you resist blindness from yellow lights and archons. [[Bugs_in_NetHack_3.4.3/Reports#Wielding_potions_of_blindness_confers_blindness_resistance|(report)]]
|-
| {{anchor|lifesavehelpless}}  
|{{/bugstatus|Unknown}}
||   || If the player dies and is lifesaved, then the game will leave them [[helpless]] until the next turn, except if they were repeating a command using a numerical prefix and at least one more repeat is left, in which case they are not left helpless and (if they died while performing the action, rather than on a monster turn) the movement energy used to perform the action is refunded.
|-
| {{anchor|pickupburden}}  
|{{/bugstatus|Upstream}}
|| UnNetHack || Picking up gold doesn't honor the setting of [[Pickup burden|pickup_burden]] if the game is compiled without [[Compile-time_options#GOLDOBJ|GOLD_OBJ]] (no prompt when the [[encumbrance]] level is exceeded).
|-
|   
|{{/bugstatus|Unknown}}
||   || {{anchor|foocubus_disparity}}[[Demon#Demons_summoning_demons|Demon gating]] produces somewhat more incubi than succubi, especially on lower dungeon levels. Cause: [[Makemon.c#line1352]]. ([[User:Ilmari Karonen]] computed exact number some time ago.)
|-
| {{anchor|desfile}}  
|{{/bugstatus|Unknown}}
||   || A [[des-file format#SUBROOM|SUBROOM]] with random size and location is always generated at the top or left edge of the parent ROOM.
|-
| {{anchor|impossible}}  
|{{/bugstatus|Upstream}}
|| [http://bilious.alt.org/~paxed/nethack/nh343-impossible.diff Fix from Pat Rankin] [https://sourceforge.net/apps/trac/unnethack/changeset/1282 UnNetHack] || impossible() can mangle the parameter values. 
|-
| {{anchor|jumpingintoportals}} 
|{{/bugstatus|Unknown}}
||   || Jumping into portals with an item immediately before the portal prints messages out of order, and also autopickups the item (despite jumping over items not normally picking them up). ([[Bugs_in_NetHack_3.4.3/Reports#Jumping_into_portals_can_print_messages_out_of_order_or_incorrectly_pick_up_items|report]])
|-
| {{anchor|travelstopsblindly}} 
|{{/bugstatus|Unknown}}
||  || The travel command gets interrupted by engravings, even by dust engravings while blind. In every other respect, the game behaves as if you cannot feel the dust engraving while blind.([http://www.gamefaqs.com/boards/582497-nethack/65706611/738643810 first observed by JoveHack])
|-
| {{anchor|meatballedgolems}} 
|{{/bugstatus|Fixed}} 
| [https://github.com/Bulwersator/UnNetHackPlus/commit/6e49c2972e68cfeb7e1a8d9a60bdf3750848d77a UnNetHackPlus] (note [https://github.com/Bulwersator/UnNetHackPlus/commit/161d691aefdbb8cdd050a9d6de6fcbdb6eaef9fc preceding refactoring]
| Statues/figurines of golems hit with stone-to-flesh spell are [[Trap.c#line423|supposed]] to turn into flesh golems, not meatballs.
|-
| {{anchor|unpolyignoreswaterwalking}} 
| {{/bugstatus|Unknown}} 
|
| A player vampire lord who is wearing water walking boots and polymorphs into a non-flying form, will wet his stuff despite wearing water walking boots. A potion of levitation prevents this. ([http://bilious.alt.org/rgrn/?128317,128319,128321-128323,128336,128337,128339-128343#p128339 original report], [http://bilious.alt.org/rgrn/?128317,128319,128321-128323,128336,128337,128339-128343#p128342 source pointer], see also [[bug#C343-193|C343-193]])
|-
| 
| {{/bugstatus|Fixed}} 
| [https://github.com/Bulwersator/UnNetHackPlus/commit/e451c45ac70c367b56bd39792b6899175d7e3e1a UnNetHackPlus] 
| Stethoscope reports unaligned monsters as chaotic 
|-
|  
| {{/bugstatus|Fixed}} 
| [https://github.com/Bulwersator/UnNetHackPlus/commit/c786ec52c46f7f22bbaee3a1a15748013a1b9806 UnNetHackPlus] 
| Missing foo_on/foo_off calls for objects with strange delay values fixed (this bug was not detectable by players)
|-
|  || {{/bugstatus|Fixed}} || [https://github.com/Bulwersator/UnNetHackPlus/commit/67c167367b8b118c9bc9b7f4e19bdd41bbc3b308 UnNetHackPlus] || Colour of mithril objects is wrong 
|-
|  || {{/bugstatus|Fixed}} || [https://github.com/Bulwersator/UnNetHackPlus/commit/f5b8fe9e5608e531009867907d39dcd5217ea877 UnNetHackPlus] || Four shopkeeper names disappeared in NetHack 2.2a ([https://groups.google.com/forum/?fromgroups=#!topic/rec.games.roguelike.nethack/yFfMPYM_hLU report]).
|-
|  || {{/bugstatus|Fixed}} || [https://github.com/Bulwersator/UnNetHackPlus/commit/0f47db8c229f3e22b8b43c6db2739f565ffc5a7a UnNetHackPlus] || Player polymorphed into gremlin may multiply on fountain during levitation. 
|-
| || {{/bugstatus|Confirmed}} || || Wands of teleportation do not auto-identify when you zap yourself. 
|-
| || {{/bugstatus|Confirmed}} || || Corpse stacking ignores age Easy to test with sacrificing - produce lizard corpse, drop on altar, wait till it is too old for sacrificing, produce new lizard corpse, drop it on altar. Corpses will stack and both will be too old for sacrifice. Now produce next lizard corpse and sacrifice it to confirm that "Nothing happens" is caused by old age of offered corpse.
|-
| || {{/bugstatus|Confirmed}} || || Pick up unpaid oil potion in shop, lit it, pay Fuel Tax, drop and sell it for more than you lost on Fuel Tax
|-
| || {{/bugstatus|Confirmed}} || || Attacking with polearm and dealing no damage will not violate conduct - see [[Apply.c#line2421]] in use_pole function. 
|}

== Bugs mentioned only here ==
{| class="prettytable sortable striped"
!Name!!Status!!Patch!!Description !! Additional info
|-
|  || {{/bugstatus|Fixed}} || [https://github.com/Bulwersator/UnNetHackPlus/commit/a70a6f1d1c112af6a5a3976b6d9a41625ebff870 UnNetHackPlus] || Feeling of amulet draining energy away may be incorrect  ||
|-
|  || {{/bugstatus|Fixed}} || [https://github.com/Bulwersator/CopyOfSporkHack/commit/e187663d121f00337532ec3d9d180268a177d8dd SporkHack] || Bare-hands fail to get bonus ||
|-
|  || {{/bugstatus|Fixed}} || [https://github.com/Bulwersator/UnNetHackPlus/commit/f6613cddae87eccbaeff969a4bf8942421f5ea86 UnNetHackPlus] || Sacrifice that fits many cases (own race + former pet, unicorn + former pet, own race + crossaligned high altar etc) is not handled properly ||
|-
|  || {{/bugstatus|Fixed}} || [https://github.com/Bulwersator/UnNetHackPlus/commit/40dbc7c9b3c6b398802cef30b1f9cc54499ea73b UnNetHackPlus] || Genociding your pet or peaceful monsters is OK ||
<!--
|-
|  || {{/bugstatus|Fixed}} || [ UnNetHackPlus] || lalal ||
|-
|  || {{/bugstatus|Confirmed}} ||  || lalal ||
-->
|-
| [[Dual ring of slow digestion bug]] || {{/bugstatus|Fixed}} || [https://github.com/Bulwersator/UnNetHackPlus/commit/0f73968c0e9a8d79d6f444a8cf89f207af0429c1 UnNetHackPlus] ||  ||
|-
|  || {{/bugstatus|Fixed}} || [https://github.com/Bulwersator/UnNetHackPlus/commit/f58badbede0dc6ebcf2a0f4218bfdb0f8423acaa UnNetHackPlus] || Player polymorphed into Xorn is not trapped by pits but (s)he receives "You fall into a pit!" message||
|-
|  || {{/bugstatus|Fixed}} || [https://github.com/Bulwersator/UnNetHackPlus/commit/5e729d4c0b669584f2ee09019f3750ecdd02c166 UnNetHackPlus] || Weird messages on decayed food for strangevores ||
|-
|  || {{/bugstatus|Confirmed}} ||  || Tame monsters create via #monster command as gremlin and ctrl + G in wizmode ignore hilite pet before their first move. ||
|-
|  || {{/bugstatus|Fixed}} || [https://github.com/Bulwersator/UnNetHackPlus/commit/95c1fc414d7a931174063e847f2d5196289f4591 UnNetHackPlus] (note [https://github.com/Bulwersator/UnNetHackPlus/commit/1da486b858962d35e26f9ff34d5fff1787ffff64 preceding refactoring] ) || speaking silent priest (result of polymorph) - see http://nhqdb.alt.org/?611 ||
|-
|  || {{/bugstatus|Confirmed}} || || Exploding player (ending gas spore polymorph) is affecting only last attacking monster, not all adjacent tiles ||
|-
|  || {{/bugstatus|Confirmed}} || || Player polymorphed into purple worm disappears from screen during engulfing attack ||
|-
|  || {{/bugstatus|Confirmed}} || || Walking into wall is smudging engravings despite not using-up the turn (found via http://gitorious.org/nethack-tas-tools/mainline/blobs/master/turnbyturn.txt#line1657) ||
|}

== References ==
<references/>
