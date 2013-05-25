/* File modified during XXI century in process of creating UnNetHackPlus */
/* Copyright (c) Steve Creps, 1988.				  */
/* NetHack may be freely redistributed.  See license for details. */

#ifndef EXTERN_H
#define EXTERN_H

#define E extern

/* ### alloc.c ### */

#if 0
E long *FDECL(alloc, (unsigned int));
#endif
E char *FDECL(fmt_ptr, (const genericptr,char *));

/* This next pre-processor directive covers almost the entire file,
 * interrupted only occasionally to pick up specific functions as needed. */
#if !defined(MAKEDEFS_C) && !defined(LEV_LEX_C)

/* ### allmain.c ### */

E void NDECL(moveloop);
E void NDECL(stop_occupation);
E void NDECL(display_gamewindows);
E void NDECL(newgame);
E void FDECL(welcome, (boolean));
#if defined(RECORD_REALTIME) || defined(REALTIME_ON_BOTL)
E time_t NDECL(get_realtime);
#endif

/* ### apply.c ### */

E int NDECL(doapply);
E int NDECL(dorub);
E int NDECL(dojump);
E int FDECL(jump, (int));
E int NDECL(number_leashed);
E void FDECL(o_unleash, (struct obj *));
E void FDECL(m_unleash, (struct monst *,boolean));
E void NDECL(unleash_all);
E boolean NDECL(next_to_u);
E struct obj *FDECL(get_mleash, (struct monst *));
E void FDECL(check_leash, (xchar,xchar));
E boolean FDECL(um_dist, (xchar,xchar,xchar));
E boolean FDECL(snuff_candle, (struct obj *));
E boolean FDECL(snuff_lit, (struct obj *));
E boolean FDECL(catch_lit, (struct obj *));
E void FDECL(fix_attributes_and_properties, (struct obj *, int));
E boolean FDECL(tinnable, (struct obj *));
E void NDECL(reset_trapset);
E void FDECL(fig_transform, (genericptr_t, long));
E int FDECL(unfixable_trouble_count,(boolean));

/* ### artifact.c ### */

E void NDECL(init_artifacts);
E void FDECL(save_artifacts, (int));
E void FDECL(restore_artifacts, (int));
E const char *FDECL(artiname, (int));
E struct obj *FDECL(mk_artifact, (struct obj *,aligntyp));
E const char *FDECL(artifact_name, (const char *,short *));
E boolean FDECL(exist_artifact, (int,const char *));
E void FDECL(artifact_exists, (struct obj *,const char *,boolean));
E int NDECL(nartifact_exist);
E boolean FDECL(spec_ability, (struct obj *,unsigned long));
E boolean FDECL(confers_luck, (struct obj *));
E boolean FDECL(arti_reflects, (struct obj *));
E boolean FDECL(restrict_name, (struct obj *,const char *,boolean));
E boolean FDECL(defends, (int,struct obj *));
E boolean FDECL(protects, (int,struct obj *));
E void FDECL(set_artifact_intrinsic, (struct obj *,boolean,long));
E int FDECL(touch_artifact, (struct obj *,struct monst *));
E int FDECL(spec_abon, (struct obj *,struct monst *));
E int FDECL(spec_dbon, (struct obj *,struct monst *,int));
E void FDECL(discover_artifact, (xchar));
E boolean FDECL(undiscovered_artifact, (xchar));
E int FDECL(disp_artifact_discoveries, (winid));
E boolean FDECL(artifact_hit, (struct monst *,struct monst *,
				struct obj *,int *,int));
E int NDECL(doinvoke);
E void FDECL(arti_speak, (struct obj *));
E boolean FDECL(artifact_light, (struct obj *));
E long FDECL(spec_m2, (struct obj *));
E boolean FDECL(artifact_has_invprop, (struct obj *,uchar));
E long FDECL(arti_cost, (struct obj *));
E boolean FDECL(MATCH_WARN_OF_MON, (struct monst *));
E const char *FDECL(get_warned_of_monster, (struct obj *));

/* ### attrib.c ### */

E boolean FDECL(adjattrib, (int,int,int));
E void FDECL(change_luck, (schar));
E int FDECL(stone_luck, (boolean));
E void NDECL(set_moreluck);
E void FDECL(gainstr, (struct obj *,int));
E void FDECL(losestr, (int));
E void NDECL(restore_attrib);
E void FDECL(exercise, (int,boolean));
E void NDECL(exerchk);
E void NDECL(reset_attribute_clock);
E void FDECL(init_attr, (int));
E void NDECL(redist_attr);
E void FDECL(adjabil, (int,int));
E int NDECL(newhp);
E schar FDECL(acurr, (int));
E schar NDECL(acurrstr);
E void FDECL(adjalign, (int));
E const char * NDECL(beautiful);
E int NDECL(uhp);
E int NDECL(uhpmax);

/* ### ball.c ### */

E void NDECL(ballfall);
E void NDECL(placebc);
E void NDECL(unplacebc);
E void FDECL(set_bc, (int));
E void FDECL(move_bc, (int,int,xchar,xchar,xchar,xchar));
E boolean FDECL(drag_ball, (xchar,xchar,
		int *,xchar *,xchar *,xchar *,xchar *, boolean *,boolean));
E void FDECL(drop_ball, (xchar,xchar));
E void NDECL(drag_down);

/* ### bones.c ### */

E boolean NDECL(can_make_bones);
E void FDECL(savebones, (struct obj *));
E int NDECL(getbones);

/* ### botl.c ### */

E int FDECL(xlev_to_rank, (int));
E int FDECL(title_to_mon, (const char *,int *,int *));
E void NDECL(max_rank_sz);
#ifdef SCORE_ON_BOTL
E long NDECL(botl_score);
#endif
E int FDECL(describe_level, (char *));
E const char *NDECL(rank);
E const char *FDECL(rank_of, (int,short,boolean));
E void NDECL(bot);
#ifdef DUMP_LOG
E void FDECL(bot1str, (char *));
E void FDECL(bot2str, (char *));
#endif

/* ### cmd.c ### */

#ifdef USE_TRAMPOLI
E int NDECL(doextcmd);
E int NDECL(domonability);
E int NDECL(doprev_message);
E int NDECL(timed_occupation);
E int NDECL(wiz_attributes);
E int NDECL(enter_explore_mode);
E int NDECL(wiz_detect);
E int NDECL(wiz_genesis);
E int NDECL(wiz_identify);
E int NDECL(wiz_level_tele);
E int NDECL(wiz_map);
E int NDECL(wiz_where);
E int NDECL(wiz_wish);
#endif /* USE_TRAMPOLI */
E void NDECL(reset_occupations);
E void FDECL(set_occupation, (int (*)(void),const char *,int));
#ifdef REDO
E char NDECL(pgetchar);
E void FDECL(pushch, (char));
E void FDECL(savech, (char));
#endif
E void NDECL(add_debug_extended_commands);
E void FDECL(rhack, (char *));
E int NDECL(doextlist);
E int NDECL(extcmd_via_menu);
E void FDECL(enlightenment, (int,boolean));
E void FDECL(show_conduct, (int,boolean));
E int FDECL(xytod, (schar,schar));
E void FDECL(dtoxy, (coord *,int));
E int FDECL(movecmd, (char));
E int FDECL(getdir, (const char *));
E void NDECL(confdir);
E int FDECL(isok, (int,int));
E int FDECL(get_adjacent_loc, (const char *, const char *, xchar, xchar, coord *));
E const char *FDECL(click_to_cmd, (int,int,int));
E char NDECL(readchar);
E void NDECL(sanity_check);
E char FDECL(yn_function, (const char *, const char *, char));
E char FDECL(paranoid_yn, (const char *, boolean));

/* ### dbridge.c ### */

E boolean FDECL(is_pool, (int,int));
E boolean FDECL(is_lava, (int,int));
E boolean FDECL(is_ice, (int,int));
E boolean FDECL(is_swamp, (int,int));
E int FDECL(is_drawbridge_wall, (int,int));
E boolean FDECL(is_db_wall, (int,int));
E boolean FDECL(find_drawbridge, (int *,int*));
E boolean FDECL(create_drawbridge, (int,int,int,boolean));
E void FDECL(open_drawbridge, (int,int));
E boolean FDECL(close_drawbridge, (int,int));
E void FDECL(destroy_drawbridge, (int,int));

/* ### decl.c ### */

E void NDECL(decl_init);

/* ### detect.c ### */

E struct obj *FDECL(o_in, (struct obj*,char));
E struct obj *FDECL(o_material, (struct obj*,unsigned));
E int FDECL(gold_detect, (struct obj *));
E int FDECL(food_detect, (struct obj *));
E int FDECL(object_detect, (struct obj *,int,boolean));
E int FDECL(monster_detect, (struct obj *,int));
E int FDECL(trap_detect, (struct obj *));
E const char *FDECL(level_distance, (d_level *));
E void FDECL(use_crystal_ball, (struct obj *));
E void NDECL(do_mapping);
E void NDECL(do_vicinity_map);
E void FDECL(cvt_sdoor_to_door, (struct rm *));
#ifdef USE_TRAMPOLI
E void FDECL(findone, (int,int,genericptr_t));
E void FDECL(openone, (int,int,genericptr_t));
#endif
E int NDECL(findit);
E int NDECL(openit);
E void FDECL(find_trap, (struct trap *));
E int FDECL(dosearch0, (int));
E int NDECL(dosearch);
E void NDECL(sokoban_detect);

/* ### dig.c ### */

E boolean NDECL(is_digging);
#ifdef USE_TRAMPOLI
E int NDECL(dig);
#endif
E int NDECL(holetime);
E schar FDECL(fillholetyp, (int, int));
E boolean FDECL(dig_check, (struct monst *, boolean, int, int));
E void FDECL(digactualhole, (int,int,struct monst *,int));
E boolean FDECL(dighole, (boolean));
E int FDECL(use_pick_axe, (struct obj *));
E int FDECL(use_pick_axe2, (struct obj *));
E boolean FDECL(mdig_tunnel, (struct monst *));
E void FDECL(watch_dig, (struct monst *,xchar,xchar,boolean));
E void NDECL(zap_dig);
E struct obj *FDECL(bury_an_obj, (struct obj *));
E void FDECL(bury_objs, (int,int));
E void FDECL(unearth_objs, (int,int));
E void FDECL(rot_organic, (genericptr_t, long));
E void FDECL(rot_corpse, (genericptr_t, long));

/* ### display.c ### */

#ifdef INVISIBLE_OBJECTS
E struct obj * FDECL(vobj_at, (xchar,xchar));
#endif /* INVISIBLE_OBJECTS */
E void FDECL(magic_map_background, (xchar,xchar,int));
E void FDECL(map_background, (xchar,xchar,int));
E void FDECL(map_trap, (struct trap *,int));
E void FDECL(map_object, (struct obj *,int));
E void FDECL(map_invisible, (xchar,xchar));
E void FDECL(unmap_object, (int,int));
E void FDECL(map_location, (int,int,int));
E void FDECL(feel_location, (xchar,xchar));
E void FDECL(newsym, (int,int));
E void FDECL(shieldeff, (xchar,xchar));
E void FDECL(tmp_at, (int,int));
E void FDECL(swallowed, (int));
E void FDECL(under_ground, (int));
E void FDECL(under_water, (int));
E void NDECL(see_monsters);
E void NDECL(set_mimic_blocking);
E void NDECL(see_objects);
E void NDECL(see_traps);
E void NDECL(curs_on_u);
E int NDECL(doredraw);
E void NDECL(docrt);
E void FDECL(show_glyph, (int,int,int));
E void NDECL(clear_glyph_buffer);
E void FDECL(row_refresh, (int,int,int));
E void NDECL(cls);
E void FDECL(flush_screen, (int));
#ifdef DUMP_LOG
E void NDECL(dump_screen);
#endif
E int FDECL(back_to_glyph, (xchar,xchar));
E int FDECL(zapdir_to_glyph, (int,int,int));
E int FDECL(glyph_at, (xchar,xchar));
E void NDECL(set_wall_state);

/* ### do.c ### */

#ifdef USE_TRAMPOLI
E int FDECL(drop, (struct obj *));
E int NDECL(wipeoff);
#endif
E int NDECL(dodrop);
E boolean FDECL(boulder_hits_pool, (struct obj *,int,int,boolean));
E boolean FDECL(flooreffects, (struct obj *,int,int,const char *));
E void FDECL(doaltarobj, (struct obj *));
E boolean FDECL(canletgo, (struct obj *,const char *));
E void FDECL(dropx, (struct obj *));
E void FDECL(dropy, (struct obj *));
E void FDECL(obj_no_longer_held, (struct obj *));
E int NDECL(doddrop);
E int NDECL(dodown);
E int NDECL(doup);
#ifdef INSURANCE
E void NDECL(save_currentstate);
#endif
E void FDECL(goto_level, (d_level *,boolean,boolean,boolean));
E void FDECL(schedule_goto, (d_level *,boolean,boolean,int,
			     const char *,const char *));
E void NDECL(deferred_goto);
E boolean FDECL(revive_corpse, (struct obj *));
E void FDECL(revive_mon, (genericptr_t, long));
E int NDECL(donull);
E int NDECL(dowipe);
E void FDECL(set_wounded_legs, (long,int));
E void NDECL(heal_legs);

/* ### do_name.c ### */

E void FDECL(do_oname, (struct obj *));
E int FDECL(getpos, (coord *,boolean,const char *));
E struct monst *FDECL(christen_monst, (struct monst *,const char *));
E int NDECL(do_mname);
E struct obj *FDECL(oname, (struct obj *,const char *));
E int NDECL(ddocall);
E void FDECL(docall, (struct obj *));
E const char *NDECL(rndghostname);
E char *FDECL(x_monnam, (struct monst *,int,const char *,int,boolean));
E char *FDECL(l_monnam, (struct monst *));
E char *FDECL(mon_nam, (struct monst *));
E char *FDECL(noit_mon_nam, (struct monst *));
E char *FDECL(Monnam, (struct monst *));
E char *FDECL(noit_Monnam, (struct monst *));
E char *FDECL(m_monnam, (struct monst *));
E char *FDECL(y_monnam, (struct monst *));
E char *FDECL(Adjmonnam, (struct monst *,const char *));
E char *FDECL(Amonnam, (struct monst *));
E char *FDECL(a_monnam, (struct monst *));
E char *FDECL(distant_monnam, (struct monst *,int,char *));
E const char *FDECL(hcolor, (const char *));
E const char *NDECL(rndcolor);
E const char *NDECL(roguename);
E struct obj *FDECL(realloc_obj,
		(struct obj *, int, genericptr_t, int, const char *));
E char *FDECL(coyotename, (struct monst *,char *));

/* ### do_wear.c ### */

E int NDECL(get_luck_bonus_for_archeologist_wearing_fedora);
#ifdef USE_TRAMPOLI
E int NDECL(Armor_on);
E int NDECL(Boots_on);
E int NDECL(Gloves_on);
E int NDECL(Helmet_on);
E int FDECL(select_off, (struct obj *));
E int NDECL(take_off);
#endif
E void FDECL(off_msg, (struct obj *));
E void NDECL(set_wear);
E boolean FDECL(donning, (struct obj *));
E void NDECL(cancel_don);
E int NDECL(Armor_off);
E int NDECL(Armor_gone);
E int NDECL(Helmet_off);
E int NDECL(Gloves_off);
E int NDECL(Boots_off);
E int NDECL(Cloak_off);
E int NDECL(Shield_off);
E int NDECL(Shirt_off);
E void NDECL(Amulet_off);
E void FDECL(Ring_on, (struct obj *));
E void FDECL(Ring_off, (struct obj *));
E void FDECL(Ring_gone, (struct obj *));
E void FDECL(Blindf_on, (struct obj *));
E void FDECL(Blindf_off, (struct obj *));
E int NDECL(dotakeoff);
E int NDECL(doremring);
E int FDECL(cursed, (struct obj *));
E int FDECL(armoroff, (struct obj *));
E int FDECL(canwearobj, (struct obj *, long *, boolean));
E int NDECL(dowear);
E int NDECL(doputon);
E void NDECL(find_ac);
E void NDECL(glibr);
E struct obj *FDECL(some_armor,(struct monst *));
E void FDECL(erode_armor, (struct monst *,boolean));
E struct obj *FDECL(stuck_ring, (struct obj *,int));
E struct obj *NDECL(unchanger);
E void NDECL(reset_remarm);
E int NDECL(doddoremarm);
E int FDECL(destroy_arm, (struct obj *));
E void FDECL(adj_abon, (struct obj *,schar));

/* ### dog.c ### */

E void FDECL(initedog, (struct monst *));
E struct monst *FDECL(make_familiar, (struct obj *,xchar,xchar,boolean));
E struct monst *NDECL(makedog);
E void NDECL(update_mlstmv);
E void NDECL(losedogs);
E void FDECL(mon_arrive, (struct monst *,boolean));
E void FDECL(mon_catchup_elapsed_time, (struct monst *,long));
E void FDECL(keepdogs, (boolean));
E void FDECL(migrate_to_level, (struct monst *,xchar,xchar,coord *));
E int FDECL(dogfood, (struct monst *,struct obj *));
E struct monst *FDECL(tamedog, (struct monst *,struct obj *));
E void FDECL(abuse_dog, (struct monst *));
E void FDECL(wary_dog, (struct monst *, boolean));

/* ### dogmove.c ### */

E int FDECL(dog_nutrition, (struct monst *,struct obj *));
E int FDECL(dog_eat, (struct monst *,struct obj *,int,int,boolean));
E int FDECL(dog_move, (struct monst *,int));
#ifdef USE_TRAMPOLI
E void FDECL(wantdoor, (int,int,genericptr_t));
#endif

/* ### dokick.c ### */

E boolean FDECL(ghitm, (struct monst *,struct obj *));
E void FDECL(container_impact_dmg, (struct obj *));
E int NDECL(dokick);
E boolean FDECL(ship_object, (struct obj *,xchar,xchar,boolean));
E void NDECL(obj_delivery);
E schar FDECL(down_gate, (xchar,xchar));
E void FDECL(impact_drop, (struct obj *,xchar,xchar,xchar));

/* ### dothrow.c ### */

E int NDECL(dothrow);
E int NDECL(dofire);
E void FDECL(hitfloor, (struct obj *));
E void FDECL(hurtle, (int,int,int,boolean));
E void FDECL(mhurtle, (struct monst *,int,int,int));
E void FDECL(throwit, (struct obj *,long,boolean));
E int FDECL(omon_adj, (struct monst *,struct obj *,boolean));
E int FDECL(thitmonst, (struct monst *,struct obj *));
E int FDECL(hero_breaks, (struct obj *,xchar,xchar,boolean));
E int FDECL(breaks, (struct obj *,xchar,xchar));
E boolean FDECL(breaktest, (struct obj *));
E boolean FDECL(walk_path, (coord *, coord *, boolean (*)(genericptr_t,int,int), genericptr_t));
E boolean FDECL(hurtle_step, (genericptr_t, int, int));

/* ### drawing.c ### */
#endif /* !MAKEDEFS_C && !LEV_LEX_C */
E int FDECL(def_char_to_objclass, (char));
E int FDECL(def_char_to_monclass, (char));
#if !defined(MAKEDEFS_C) && !defined(LEV_LEX_C)
E void FDECL(assign_graphics, (glyph_t *,int,int,int));
E void FDECL(switch_graphics, (int));
E void FDECL(assign_rogue_graphics, (boolean));
E void FDECL(assign_utf8graphics_symbol, (int, glyph_t));

/* ### dump.c ### */

E void FDECL(dump, (const char *, const char *));
E void NDECL(dump_blockquote_start);
E void NDECL(dump_blockquote_end);
E void FDECL(dump_text, (const char *, const char *));
E void FDECL(dump_header_html, (const char *));
E void FDECL(dump_html, (const char *, const char *));
E void NDECL(dump_init);
E void NDECL(dump_exit);
E void FDECL(dump_object, (const char, const struct obj *, const char *));
E void FDECL(dump_title, (char *));
E void FDECL(dump_subtitle, (const char *));
E void FDECL(dump_line, (const char *, const char *));
E void NDECL(dump_list_start);
E void FDECL(dump_list_item, (const char *));
E void FDECL(dump_list_item_object, (struct obj *));
E void FDECL(dump_list_item_link, (const char *, const char *));
E void NDECL(dump_list_end);
E void NDECL(dump_definition_list_start);
E void FDECL(dump_definition_list_dd, (const char *));
E void FDECL(dump_definition_list_dt, (const char *));
E void NDECL(dump_definition_list_end);
E void FDECL(dump_containerconts, (struct obj *,boolean,boolean,boolean));
E char* FDECL(html_escape_character, (const char));
E char* FDECL(html_link, (const char *, const char *));
#ifdef DUMP_LOG
E int NDECL(dump_screenshot);
E int NDECL(dumpoverview);
#endif

/* ### dungeon.c ### */

E void FDECL(save_dungeon, (int,boolean,boolean));
E void FDECL(restore_dungeon, (int));
E void FDECL(insert_branch, (branch *,boolean));
E void NDECL(init_dungeons);
E s_level *FDECL(find_level, (const char *));
E s_level *FDECL(Is_special, (d_level *));
#ifdef RANDOMIZED_PLANES
E s_level *FDECL(get_next_elemental_plane, (d_level *));
E d_level *NDECL(get_first_elemental_plane);
#endif
E branch *FDECL(Is_branchlev, (d_level *));
E xchar FDECL(ledger_no, (d_level *));
E xchar NDECL(maxledgerno);
E schar FDECL(depth, (d_level *));
E xchar FDECL(dunlev, (d_level *));
E xchar FDECL(dunlevs_in_dungeon, (d_level *));
E xchar FDECL(ledger_to_dnum, (xchar));
E xchar FDECL(ledger_to_dlev, (xchar));
E xchar FDECL(deepest_lev_reached, (boolean));
E boolean FDECL(on_level, (d_level *,d_level *));
E void FDECL(next_level, (boolean));
E void FDECL(prev_level, (boolean));
E void FDECL(u_on_newpos, (int,int));
E void NDECL(u_on_sstairs);
E void NDECL(u_on_upstairs);
E void NDECL(u_on_dnstairs);
E boolean FDECL(On_stairs, (xchar,xchar));
E void FDECL(get_level, (d_level *,int));
E boolean FDECL(Is_botlevel, (d_level *));
E boolean FDECL(Can_fall_thru, (d_level *));
E boolean FDECL(Can_dig_down, (d_level *));
E boolean FDECL(Can_rise_up, (int,int,d_level *));
E boolean FDECL(In_quest, (d_level *));
E boolean FDECL(In_mines, (d_level *));
E branch *FDECL(dungeon_branch, (const char *));
E boolean FDECL(at_dgn_entrance, (const char *));
E boolean FDECL(In_hell, (d_level *));
E boolean FDECL(In_V_tower, (d_level *));
E boolean FDECL(On_W_tower_level, (d_level *));
E boolean FDECL(In_W_tower, (int,int,d_level *));
E void FDECL(find_hell, (d_level *));
E void FDECL(goto_hell, (boolean,boolean));
E void FDECL(assign_level, (d_level *,d_level *));
E void FDECL(assign_rnd_level, (d_level *,d_level *,int));
E int FDECL(induced_align, (int));
E boolean FDECL(Invocation_lev, (d_level *));
E xchar NDECL(level_difficulty);
E schar FDECL(lev_by_name, (const char *));
E schar FDECL(print_dungeon, (boolean,schar *,xchar *));
E int NDECL(donamelevel);
E int NDECL(dooverview);
E void FDECL(forget_mapseen, (int));
E void FDECL(init_mapseen, (d_level *));
E void NDECL(recalc_mapseen);
E void FDECL(recbranch_mapseen, (d_level *, d_level *));
E void FDECL(remdun_mapseen, (int));
E char *FDECL(get_annotation, (d_level *));
E const char *FDECL(get_generic_level_description, (d_level *));

/* ### eat.c ### */

#ifdef USE_TRAMPOLI
E int NDECL(eatmdone);
E int NDECL(eatfood);
E int NDECL(opentin);
E int NDECL(unfaint);
#endif
E char * FDECL(tin_content_text, (struct obj *));
E boolean FDECL(tin_is_labelled, (struct obj *));
E boolean FDECL(is_edible, (struct obj *));
E void NDECL(init_uhunger);
E int NDECL(Hear_again);
E void NDECL(reset_eat);
E int NDECL(doeat);
E void NDECL(gethungry);
E void FDECL(morehungry, (int));
E void FDECL(lesshungry, (int));
E boolean NDECL(is_fainted);
E void NDECL(reset_faint);
E void NDECL(violated_vegetarian);
#if 0
E void NDECL(sync_hunger);
#endif
E void FDECL(newuhs, (boolean));
E struct obj *FDECL(floorfood, (const char *,int));
E void NDECL(vomit);
E int FDECL(eaten_stat, (int,struct obj *));
E void FDECL(food_disappears, (struct obj *));
E void FDECL(food_substitution, (struct obj *,struct obj *));
E boolean FDECL(bite_monster, (struct monst *mon));
E void NDECL(fix_petrification);
E void FDECL(consume_oeaten, (struct obj *,int));
E boolean FDECL(maybe_finished_meal, (boolean));

/* ### end.c ### */

E void FDECL(done1, (int));
E int NDECL(done2);
#ifdef USE_TRAMPOLI
E void FDECL(done_intr, (int));
#endif
E void FDECL(done_in_by, (struct monst *));
#endif /* !MAKEDEFS_C && !LEV_LEX_C */
E void VDECL(panic, (const char *,...)) PRINTF_F(1,2);
#if !defined(MAKEDEFS_C) && !defined(LEV_LEX_C)
E void FDECL(done, (int));
E void FDECL(container_contents, (struct obj *,boolean,boolean,boolean));
E void FDECL(terminate, (int));
E int NDECL(num_genocides);

/* ### engrave.c ### */

E char *FDECL(random_engraving, (char *));
E void FDECL(wipeout_text, (char *,int,unsigned));
E boolean NDECL(can_reach_floor);
E const char *FDECL(surface, (int,int));
E const char *FDECL(ceiling, (int,int));
E struct engr *FDECL(engr_at, (xchar,xchar));
#ifdef ELBERETH
E int FDECL(sengr_at, (const char *,xchar,xchar));
#endif
E void FDECL(u_wipe_engr, (int));
E void FDECL(wipe_engr_at, (xchar,xchar,xchar));
E void FDECL(read_engr_at, (int,int));
E void FDECL(make_engr_at, (int,int,const char *,long,xchar));
E void FDECL(del_engr_at, (int,int));
E int NDECL(freehand);
E int NDECL(doengrave);
E int NDECL(doengrave_elbereth);
E void FDECL(save_engravings, (int,int));
E void FDECL(rest_engravings, (int));
E void FDECL(del_engr, (struct engr *));
E void FDECL(rloc_engr, (struct engr *));
E void FDECL(make_grave, (int,int,const char *));

/* ### exper.c ### */

E int FDECL(experience, (struct monst *,int));
E void FDECL(more_experienced, (int,int,int));
E void FDECL(losexp, (const char *));
E void NDECL(newexplevel);
E void FDECL(pluslvl, (boolean));
E long FDECL(rndexp, (boolean));

/* ### explode.c ### */

E void FDECL(explode, (int,int,int,int,char,int));
E long FDECL(scatter, (int, int, int, unsigned int, struct obj *));
E void FDECL(splatter_burning_oil, (int, int));

/* ### extralev.c ### */

E void NDECL(makeroguerooms);
E void FDECL(corr, (int,int));
E void NDECL(makerogueghost);

/* ### files.c ### */

E char *FDECL(fname_encode, (const char *, char, char *, char *, int));
E char *FDECL(fname_decode, (char, char *, char *, int));
E const char *FDECL(fqname, (const char *, int, int));
#ifndef FILE_AREAS
E FILE *FDECL(fopen_datafile, (const char *,const char *,int));
#endif
E boolean FDECL(uptodate, (int,const char *));
E void FDECL(store_version, (int));
#ifdef MFLOPPY
E void NDECL(set_lock_and_bones);
#endif
E void FDECL(set_levelfile_name, (char *,int));
E int FDECL(create_levelfile, (int,char *));
E int FDECL(open_levelfile, (int,char *));
E void FDECL(delete_levelfile, (int));
E void NDECL(clearlocks);
E int FDECL(create_bonesfile, (d_level*,char **, char *));
#ifdef MFLOPPY
E void NDECL(cancel_bonesfile);
#endif
E void FDECL(commit_bonesfile, (d_level *));
E int FDECL(open_bonesfile, (d_level*,char **));
E int FDECL(delete_bonesfile, (d_level*));
E void NDECL(compress_bonesfile);
E void NDECL(set_savefile_name);
#ifdef INSURANCE
E void FDECL(save_savefile_name, (int));
#endif
#if !defined(MICRO)
E void NDECL(set_error_savefile);
#endif
E int NDECL(create_savefile);
E int NDECL(open_savefile);
E int NDECL(delete_savefile);
E int NDECL(restore_saved_game);
E void FDECL(compress, (const char *));
E void FDECL(uncompress, (const char *));
E void FDECL(compress_area, (const char *, const char *));
E void FDECL(uncompress_area, (const char *, const char *));
#ifndef FILE_AREAS
E boolean FDECL(lock_file, (const char *,int,int));
E void FDECL(unlock_file, (const char *));
#endif
#ifdef USER_SOUNDS
E boolean FDECL(can_read_file, (const char *));
#endif
E void FDECL(read_config_file, (const char *));
E void FDECL(check_recordfile, (const char *));
E void NDECL(read_wizkit);
E void FDECL(paniclog, (const char *, const char *));
E int FDECL(validate_prefix_locations, (char *));
E char** NDECL(get_saved_games);
E void FDECL(free_saved_games, (char**));
#ifdef SELF_RECOVER
E boolean NDECL(recover_savefile);
#endif
#ifdef HOLD_LOCKFILE_OPEN
E void NDECL(really_close);
#endif
#ifdef WHEREIS_FILE
E void NDECL(touch_whereis);
E void NDECL(delete_whereis);
E void FDECL(signal_whereis, (int));
#endif

/* ### fountain.c ### */

E void FDECL(floating_above, (const char *));
E void FDECL(dogushforth, (int));
# ifdef USE_TRAMPOLI
E void FDECL(gush, (int,int,genericptr_t));
# endif
E void FDECL(dryup, (xchar,xchar, boolean));
E void NDECL(drinkfountain);
E void FDECL(dipfountain, (struct obj *));
#ifdef SINKS
E void FDECL(breaksink, (int,int));
E void NDECL(drinksink);
#endif

/* ### hack.c ### */

E void FDECL(catchup_dgn_growths, (int));
E void FDECL(dgn_growths, (boolean,boolean));
E boolean FDECL(revive_nasty, (int,int,const char*));
E void FDECL(movobj, (struct obj *,xchar,xchar));
E boolean FDECL(may_dig, (xchar,xchar));
E boolean FDECL(may_passwall, (xchar,xchar));
E boolean FDECL(bad_rock, (struct permonst *,xchar,xchar));
E boolean FDECL(invocation_pos, (xchar,xchar));
E boolean FDECL(test_move, (int, int, int, int, int));
E void NDECL(domove);
E void NDECL(invocation_message);
E void FDECL(spoteffects, (boolean));
E char *FDECL(in_rooms, (xchar,xchar,int));
E boolean FDECL(in_town, (int,int));
E void FDECL(check_special_room, (boolean));
E int NDECL(dopickup);
E void NDECL(lookaround);
E int NDECL(monster_nearby);
E void FDECL(nomul, (int, const char *));
E void FDECL(unmul, (const char *));
E void FDECL(showdmg, (int, boolean));
E void FDECL(losehp, (int,const char *,boolean));
E void FDECL(losehp_how, (int,const char *,boolean,int));
E int NDECL(weight_cap);
E int NDECL(inv_weight);
E int NDECL(near_capacity);
E int FDECL(calc_capacity, (int));
E int NDECL(max_capacity);
E boolean FDECL(check_capacity, (const char *));
E int NDECL(inv_cnt);
#ifdef GOLDOBJ
E long FDECL(money_cnt, (struct obj *));
#endif
E boolean NDECL(is_player_slimeable);
E boolean FDECL(is_monster_slimeable, (struct permonst *));

/* ### hacklib.c ### */

E boolean FDECL(digit, (char));
E boolean FDECL(letter, (char));
E char FDECL(highc, (char));
E char FDECL(lowc, (char));
E char *FDECL(lcase, (char *));
E char *FDECL(upstart, (char *));
E char *FDECL(mungspaces, (char *));
E char *FDECL(eos, (char *));
E char *FDECL(strkitten, (char *,char));
E char *FDECL(s_suffix, (const char *));
E char *FDECL(xcrypt, (const char *,char *));
E boolean FDECL(onlyspace, (const char *));
E char *FDECL(tabexpand, (char *));
E char *FDECL(visctrl, (char));
E const char *FDECL(ordin, (int));
E char *FDECL(sitoa, (int));
E int FDECL(sgn, (int));
E int FDECL(rounddiv, (long,int));
E int FDECL(dist2, (int,int,int,int));
E int FDECL(distmin, (int,int,int,int));
E boolean FDECL(online2, (int,int,int,int));
E boolean FDECL(pmatch, (const char *,const char *));
#ifndef STRNCMPI
E int FDECL(strncmpi, (const char *,const char *,int));
#endif
#ifndef STRSTRI
E char *FDECL(strstri, (const char *,const char *));
#endif
E boolean FDECL(fuzzymatch, (const char *,const char *,const char *,boolean));
E void NDECL(setrandom);
E int NDECL(getyear);
E int NDECL(getmonth);
E int NDECL(getmday);
E long FDECL(yyyymmdd, (time_t));
E int NDECL(phase_of_the_moon);
E boolean NDECL(friday_13th);
E boolean NDECL(towelday);
E boolean NDECL(pirateday);
E int NDECL(night);
E int NDECL(midnight);
E boolean NDECL(piday);
E boolean NDECL(aprilfoolsday);
E boolean NDECL(discordian_holiday);
E char *FDECL(iso8601, (time_t));
E char *FDECL(iso8601_duration, (long));
E char *FDECL(get_formatted_time, (time_t, const char *));
E time_t NDECL(current_epoch);

/* ### hallucination.c ### */
E const char *NDECL(get_bogus_monster_name);
E const char *NDECL(get_bogus_item_name);
E const char *NDECL(get_bogus_class_name);
E const char *NDECL(get_bogus_bottle_name);
E const char *NDECL(get_bogus_color_name);
E const char *NDECL(get_bogus_sound);
E const char *FDECL(get_bogus_god_name, (int));

/* ### invent.c ### */

E void FDECL(assigninvlet, (struct obj *));
E struct obj *FDECL(merge_choice, (struct obj *,struct obj *));
E int FDECL(merged, (struct obj **,struct obj **));
#ifdef USE_TRAMPOLI
E int FDECL(ckunpaid, (struct obj *));
#endif
E void FDECL(addinv_core1, (struct obj *));
E void FDECL(addinv_core2, (struct obj *));
E struct obj *FDECL(addinv, (struct obj *));
E struct obj *FDECL(hold_another_object,
			(struct obj *,const char *,const char *,const char *));
E void FDECL(useupall, (struct obj *));
E void FDECL(useup, (struct obj *));
E void FDECL(consume_obj_charge, (struct obj *,boolean));
E void FDECL(freeinv_core, (struct obj *));
E void FDECL(freeinv, (struct obj *));
E void FDECL(delallobj, (int,int));
E void FDECL(delobj, (struct obj *));
E struct obj *FDECL(sobj_at, (int,int,int));
E struct obj *FDECL(carrying, (int));
E boolean NDECL(have_lizard);
E struct obj *FDECL(o_on, (unsigned int,struct obj *));
E boolean FDECL(obj_here, (struct obj *,int,int));
E boolean NDECL(wearing_armor);
E boolean FDECL(is_worn, (struct obj *));
E struct obj *FDECL(g_at, (int,int));
E struct obj *FDECL(mkgoldobj, (long));
E struct obj *FDECL(getobj, (const char *,const char *));
E int FDECL(ggetobj, (const char *,int (*)(struct obj*),int,boolean,unsigned *));
E void FDECL(fully_identify_obj, (struct obj *));
E int FDECL(identify, (struct obj *));
E void FDECL(identify_pack, (int));
E int FDECL(askchain, (struct obj **,const char *,int,int (*)(struct obj*),
			int (*)(struct obj*),int,const char *));
E void FDECL(prinv, (const char *,struct obj *,long));
E char *FDECL(xprname, (struct obj *,const char *,char,boolean,long,long));
E int NDECL(ddoinv);
E char FDECL(display_inventory, (const char *,boolean));
E char FDECL(dump_inventory, (const char *,boolean,boolean));
E int FDECL(display_binventory, (int,int,boolean));
E struct obj *FDECL(display_cinventory,(struct obj *));
E struct obj *FDECL(display_minventory,(struct monst *,int,char *));
E int NDECL(dotypeinv);
E const char *FDECL(dfeature_at, (int,int,char *));
E int FDECL(look_here, (int,boolean));
E int NDECL(dolook);
E boolean FDECL(will_feel_cockatrice, (struct obj *,boolean));
E void FDECL(feel_cockatrice, (struct obj *,boolean));
E void FDECL(stackobj, (struct obj *));
E int NDECL(doprgold);
E int NDECL(doprwep);
E int NDECL(doprarm);
E int NDECL(doprring);
E int NDECL(dopramulet);
E int NDECL(doprtool);
E int NDECL(doprinuse);
E void FDECL(useupf, (struct obj *,long));
E char *FDECL(let_to_name, (char,boolean));
E void NDECL(free_invbuf);
E void NDECL(reassign);
E int NDECL(doorganize);
E int FDECL(count_objects, (struct obj *));
E int FDECL(count_unidentified, (struct obj *));
E int FDECL(count_unpaid, (struct obj *));
E int FDECL(count_buc, (struct obj *,int));
E void FDECL(carry_obj_effects, (struct obj *));
E const char *FDECL(currency, (long));
E void FDECL(silly_thing, (const char *,struct obj *));
E struct obj *NDECL(getnextgetobj);
#ifdef SORTLOOT
E int FDECL(sortloot_cmp, (struct obj *, struct obj *));
#endif
E boolean FDECL(is_racial_armor, (struct obj *));
E boolean FDECL(is_racial_weapon, (struct obj *));

/* ### ioctl.c ### */

#if defined(UNIX) || defined(__BEOS__)
E void NDECL(getwindowsz);
E void NDECL(getioctls);
E void NDECL(setioctls);
# ifdef SUSPEND
E int NDECL(dosuspend);
# endif /* SUSPEND */
#endif /* UNIX || __BEOS__ */

/* ### light.c ### */

E void FDECL(new_light_source, (xchar, xchar, int, int, genericptr_t));
E void FDECL(del_light_source, (int, genericptr_t));
E void FDECL(do_light_sources, (char **));
E struct monst *FDECL(find_mid, (unsigned, unsigned));
E void FDECL(save_light_sources, (int, int, int));
E void FDECL(restore_light_sources, (int));
E void FDECL(relink_light_sources, (boolean));
E void FDECL(obj_move_light_source, (struct obj *, struct obj *));
E boolean NDECL(any_light_source);
E void FDECL(snuff_light_source, (int, int));
E boolean FDECL(obj_sheds_light, (struct obj *));
E boolean FDECL(obj_is_burning, (struct obj *));
E void FDECL(obj_split_light_source, (struct obj *, struct obj *));
E void FDECL(obj_merge_light_sources, (struct obj *,struct obj *));
E int FDECL(candle_light_range, (struct obj *));
E int NDECL(wiz_light_sources);

/* ### lock.c ### */

#ifdef USE_TRAMPOLI
E int NDECL(forcelock);
E int NDECL(picklock);
#endif
E boolean FDECL(picking_lock, (int *,int *));
E boolean FDECL(picking_at, (int,int));
E void NDECL(reset_pick);
E int FDECL(pick_lock, (struct obj *,int,int,boolean));
E int NDECL(doforce);
E boolean FDECL(boxlock, (struct obj *,struct obj *));
E boolean FDECL(doorlock, (struct obj *,int,int));
E int NDECL(doopen);
E int NDECL(doclose);
E int FDECL(doopen_indir,(int,int));

#ifdef MAC
/* These declarations are here because the main code calls them. */

/* ### macfile.c ### */

E int FDECL(maccreat, (const char *,long));
E int FDECL(macopen, (const char *,int,long));
E int FDECL(macclose, (int));
E int FDECL(macread, (int,void *,unsigned));
E int FDECL(macwrite, (int,void *,unsigned));
E long FDECL(macseek, (int,long,short));
E int FDECL(macunlink, (const char *));

/* ### macsnd.c ### */

E void FDECL(mac_speaker, (struct obj *,char *));

/* ### macunix.c ### */

E void FDECL(regularize, (char *));
E void NDECL(getlock);

/* ### macwin.c ### */

E void FDECL(lock_mouse_cursor, (Boolean));
E int NDECL(SanePositions);

/* ### mttymain.c ### */

E void FDECL(getreturn, (char *));
E void VDECL(msmsg, (const char *,...));
E void NDECL(gettty);
E void NDECL(setftty);
E void FDECL(settty, (const char *));
E int NDECL(tgetch);
E void FDECL(cmov, (int x, int y));
E void FDECL(nocmov, (int x, int y));

#endif /* MAC */

/* ### mail.c ### */

#ifdef MAIL
# ifdef UNIX
E void NDECL(getmailstatus);
# endif
E void NDECL(ckmailstatus);
E void FDECL(read_hint, (struct obj *));
E void FDECL(readmail, (struct obj *));
#endif /* MAIL */

/* ### makemon.c ### */

E boolean FDECL(is_home_elemental, (struct permonst *));
E struct monst *FDECL(clone_mon, (struct monst *,xchar,xchar));
E struct monst *FDECL(makemon, (struct permonst *,int,int,int));
E boolean FDECL(create_critters, (int,struct permonst *));
E struct permonst *NDECL(rndmonst);
E void FDECL(reset_rndmonst, (int));
E struct permonst *FDECL(mkclass, (char,int));
E int FDECL(adj_lev, (struct permonst *));
E struct permonst *FDECL(grow_up, (struct monst *,struct monst *));
E int FDECL(mongets, (struct monst *,int));
E int FDECL(golemhp, (int));
E boolean FDECL(peace_minded, (struct permonst *));
E void FDECL(set_malign, (struct monst *));
E void FDECL(set_mimic_sym, (struct monst *));
E int FDECL(mbirth_limit, (int));
#ifdef GOLDOBJ
E void FDECL(mkmonmoney, (struct monst *, long));
#endif
E int FDECL(bagotricks, (struct obj *));
E boolean FDECL(propagate, (int, boolean,boolean));
E void FDECL(create_camera_demon, (struct obj *,int,int));
E int NDECL(min_monster_difficulty);
E int NDECL(max_monster_difficulty);

/* ### mapglyph.c ### */

E void FDECL(mapglyph, (int, glyph_t *, int *, unsigned *, int, int));

/* ### mcastu.c ### */

E int FDECL(castmu, (struct monst *,struct attack *,boolean,boolean));
E int FDECL(buzzmu, (struct monst *,struct attack *));

/* ### mhitm.c ### */

E int FDECL(fightm, (struct monst *));
E int FDECL(mattackm, (struct monst *,struct monst *));
E int FDECL(noattacks, (struct permonst *));
E int FDECL(sleep_monst, (struct monst *,int,int));
E void FDECL(slept_monst, (struct monst *));
E long FDECL(attk_protection, (int));

/* ### mhitu.c ### */

E const char *FDECL(mpoisons_subj, (struct monst *,struct attack *));
E void NDECL(u_slow_down);
E struct monst *NDECL(cloneu);
E void FDECL(expels, (struct monst *,struct permonst *,boolean));
E struct attack *FDECL(getmattk, (struct permonst *,int,int *,struct attack *));
E int FDECL(mattacku, (struct monst *));
E int FDECL(magic_negation, (struct monst *));
E int FDECL(gazemu, (struct monst *,struct attack *));
E void FDECL(mdamageu, (struct monst *,int));
E int FDECL(could_seduce, (struct monst *,struct monst *,struct attack *));
E int FDECL(doseduce, (struct monst *));

/* ### minion.c ### */

E void FDECL(msummon, (struct monst *));
E void FDECL(summon_minion, (aligntyp,boolean));
E int FDECL(demon_talk, (struct monst *));
E long FDECL(bribe, (struct monst *));
E int FDECL(dprince, (aligntyp));
E int FDECL(dlord, (aligntyp));
E int NDECL(llord);
E int FDECL(ndemon, (aligntyp));
E int NDECL(lminion);

/* ### mklev.c ### */

#ifdef USE_TRAMPOLI
E int FDECL(do_comp, (genericptr_t,genericptr_t));
#endif
E void NDECL(sort_rooms);
E void FDECL(add_room, (int,int,int,int,boolean,schar,boolean));
E void FDECL(add_subroom, (struct mkroom *,int,int,int,int,
			   boolean,schar,boolean));
E void FDECL(makecorridors, (int));
E void FDECL(add_door, (int,int,struct mkroom *));
E void NDECL(mkpoolroom);
E void NDECL(mklev);
#ifdef SPECIALIZATION
E void FDECL(topologize, (struct mkroom *,boolean));
#else
E void FDECL(topologize, (struct mkroom *));
#endif
E void FDECL(place_branch, (branch *,xchar,xchar));
E boolean FDECL(occupied, (xchar,xchar));
E int FDECL(okdoor, (xchar,xchar));
E void FDECL(dodoor, (int,int,struct mkroom *));
E void FDECL(mktrap, (int,int,struct mkroom *,coord*));
E void FDECL(mkstairs, (xchar,xchar,char,struct mkroom *));
E void NDECL(mkinvokearea);
E void FDECL(wallwalk_right, (xchar,xchar,schar,schar,schar,int));

/* ### mkmap.c ### */

void FDECL(flood_fill_rm, (int,int,int,boolean,boolean));
void FDECL(remove_rooms, (int,int,int,int));

/* ### mkmaze.c ### */

E void FDECL(wallification, (int,int,int,int));
E void FDECL(wall_extends, (int,int,int,int));
E void FDECL(walkfrom, (int,int, schar));
E void FDECL(makemaz, (const char *));
E void FDECL(mazexy, (coord *));
E void NDECL(bound_digging);
E void FDECL(mkportal, (xchar,xchar,xchar,xchar));
E boolean FDECL(bad_location, (xchar,xchar,xchar,xchar,xchar,xchar));
E void FDECL(place_lregion, (xchar,xchar,xchar,xchar,
			     xchar,xchar,xchar,xchar,
			     xchar,d_level *));
E void NDECL(movebubbles);
E void NDECL(water_friction);
E void FDECL(save_waterlevel, (int,int));
E void FDECL(restore_waterlevel, (int));
E const char *FDECL(waterbody_name, (xchar,xchar));

/* ### mkobj.c ### */

E struct obj *FDECL(mkobj_at, (char,int,int,boolean));
E struct obj *FDECL(mksobj_at, (int,int,int,boolean,boolean));
E struct obj *FDECL(mkobj, (char,boolean));
E int NDECL(rndmonnum);
E struct obj *FDECL(splitobj, (struct obj *,long));
E void FDECL(replace_object, (struct obj *,struct obj *));
E void FDECL(bill_dummy_object, (struct obj *));
E struct obj *FDECL(mksobj, (int,boolean,boolean));
E int FDECL(bcsign, (struct obj *));
E int FDECL(weight, (struct obj *));
E struct obj *FDECL(mkgold, (long,int,int));
E struct obj *FDECL(mkcorpstat,(int,struct monst *,struct permonst *,int,int,boolean));
E struct obj *FDECL(obj_attach_mid, (struct obj *, unsigned));
E struct monst *FDECL(get_mtraits, (struct obj *, boolean));
E struct obj *FDECL(mk_tt_object, (int,int,int));
E struct obj *FDECL(mk_player_statue_on_Medusa_island, (int, int));
E struct obj *FDECL(mk_monster_statue_on_Medusa_island, (int, int));
E struct obj *FDECL(mk_named_object, (int,struct permonst *,int,int,const char *));
E struct obj *FDECL(rnd_treefruit_at, (int, int));
E void FDECL(rnd_treesticks_at, (int, int));
E void FDECL(start_corpse_timeout, (struct obj *));
E void FDECL(bless, (struct obj *));
E void FDECL(unbless, (struct obj *));
E void FDECL(curse, (struct obj *));
E void FDECL(uncurse, (struct obj *));
E void FDECL(blessorcurse, (struct obj *,int));
E boolean FDECL(is_flammable, (struct obj *));
E boolean FDECL(is_rottable, (struct obj *));
E void FDECL(place_object, (struct obj *,int,int));
E void FDECL(remove_object, (struct obj *));
E void FDECL(discard_minvent, (struct monst *));
E void FDECL(obj_extract_self, (struct obj *));
E void FDECL(extract_nobj, (struct obj *, struct obj **));
E void FDECL(extract_nexthere, (struct obj *, struct obj **));
E int FDECL(add_to_minv, (struct monst *, struct obj *));
E struct obj *FDECL(add_to_container, (struct obj *, struct obj *));
E void FDECL(add_to_migration, (struct obj *));
E void FDECL(add_to_buried, (struct obj *));
E void FDECL(dealloc_obj, (struct obj *));
E void FDECL(obj_ice_effects, (int, int, boolean));
E long FDECL(peek_at_iced_corpse_age, (struct obj *));
E void NDECL(obj_sanity_check);

/* ### mkroom.c ### */

E struct mkroom * FDECL(pick_room,(boolean));
E void FDECL(mkroom, (int));
E void FDECL(fill_zoo, (struct mkroom *));
E boolean FDECL(nexttodoor, (int,int));
E boolean FDECL(has_dnstairs, (struct mkroom *));
E boolean FDECL(has_upstairs, (struct mkroom *));
E int FDECL(somex, (struct mkroom *));
E int FDECL(somey, (struct mkroom *));
E boolean FDECL(inside_room, (struct mkroom *,xchar,xchar));
E boolean FDECL(somexy, (struct mkroom *,coord *));
E void FDECL(mkundead, (coord *,boolean,int));
E struct permonst *NDECL(courtmon);
E void FDECL(save_rooms, (int));
E void FDECL(rest_rooms, (int));
E struct mkroom *FDECL(search_special, (schar));

/* ### mon.c ### */

E void FDECL(remove_monster, (int, int));
E int FDECL(undead_to_corpse, (int));
E int FDECL(genus, (int,int));
E int FDECL(pm_to_cham, (int));
E int FDECL(minliquid, (struct monst *));
E int NDECL(movemon);
E int FDECL(meatmetal, (struct monst *));
E int FDECL(meatobj, (struct monst *));
E void FDECL(mpickgold, (struct monst *));
E boolean FDECL(mpickstuff, (struct monst *,const char *));
E void FDECL(mpickup_obj, (struct monst *, struct obj *));
E int FDECL(curr_mon_load, (struct monst *));
E int FDECL(max_mon_load, (struct monst *));
E boolean FDECL(can_carry, (struct monst *,struct obj *));
E int FDECL(mfndpos, (struct monst *,coord *,long *,long));
E boolean FDECL(monnear, (struct monst *,int,int));
E void NDECL(dmonsfree);
E int FDECL(mcalcmove, (struct monst*));
E void NDECL(mcalcdistress);
E void FDECL(replmon, (struct monst *,struct monst *));
E void FDECL(relmon, (struct monst *));
E struct obj *FDECL(mlifesaver, (struct monst *));
E boolean FDECL(corpse_chance,(struct monst *,struct monst *,boolean));
E void FDECL(mondead_helper, (struct monst *, uchar));
E void FDECL(mondead, (struct monst *));
E void FDECL(mondied, (struct monst *));
E void FDECL(mongone, (struct monst *));
E void FDECL(monstone, (struct monst *));
E void FDECL(monkilled, (struct monst *,const char *,int));
E void FDECL(unstuck, (struct monst *));
E void FDECL(killed, (struct monst *));
E void FDECL(xkilled, (struct monst *,int));
E void FDECL(mon_to_stone, (struct monst*));
E void FDECL(mnexto, (struct monst *));
E boolean FDECL(mnearto, (struct monst *,xchar,xchar,boolean));
E void FDECL(poisontell, (int));
E void FDECL(poisoned, (const char *,int,const char *,int));
E void FDECL(m_respond, (struct monst *));
E void FDECL(setmangry, (struct monst *));
E void FDECL(wakeup, (struct monst *));
E void NDECL(wake_nearby);
E void FDECL(wake_nearto, (int,int,int));
E void FDECL(seemimic, (struct monst *));
E void NDECL(rescham);
E void NDECL(restartcham);
E void FDECL(restore_cham, (struct monst *));
E void FDECL(mon_animal_list, (boolean));
E int FDECL(newcham, (struct monst *,struct permonst *,boolean,boolean));
E int FDECL(can_be_hatched, (int));
E int FDECL(egg_type_from_parent, (int,boolean));
E boolean FDECL(dead_species, (int,boolean));
E void NDECL(kill_genocided_monsters);
E void FDECL(kill_monster_on_level, (int));
E void FDECL(golemeffects, (struct monst *,int,int));
E boolean FDECL(angry_guards, (boolean));
E void NDECL(pacify_guards);
E void FDECL(mimic_hit_msg, (struct monst *, short));

/* ### mondata.c ### */

E void FDECL(set_mon_data, (struct monst *,struct permonst *,int));
E struct attack *FDECL(attacktype_fordmg, (struct permonst *,int,int));
E boolean FDECL(attacktype, (struct permonst *,int));
E int FDECL(get_potential_stoned_form_of_monster, (int));
E boolean FDECL(poly_when_stoned, (struct permonst *));
E boolean NDECL(polymorph_player_instead_stoning);
E boolean FDECL(resists_drli, (struct monst *));
E boolean FDECL(resists_magm, (struct monst *));
E boolean FDECL(resists_blnd, (struct monst *));
E boolean FDECL(can_blnd, (struct monst *,struct monst *,uchar,struct obj *));
E boolean FDECL(ranged_attk, (struct permonst *));
E boolean FDECL(hates_silver, (struct permonst *));
E boolean FDECL(passes_bars, (struct permonst *));
E boolean FDECL(can_track, (struct permonst *));
E boolean FDECL(breakarm, (struct permonst *));
E boolean FDECL(sliparm, (struct permonst *));
E boolean FDECL(sticks, (struct permonst *));
E int FDECL(num_horns, (struct permonst *));
/* E boolean FDECL(canseemon, (struct monst *)); */
E struct attack *FDECL(dmgtype_fromattack, (struct permonst *,int,int));
E boolean FDECL(dmgtype, (struct permonst *,int));
E int FDECL(max_passive_dmg, (struct monst *,struct monst *));
E int FDECL(monsndx, (struct permonst *));
E int FDECL(name_to_mon, (const char *));
E int FDECL(gender, (struct monst *));
E int FDECL(pronoun_gender, (struct monst *));
E boolean FDECL(levl_follower, (struct monst *));
E int FDECL(little_to_big, (int));
E int FDECL(big_to_little, (int));
E const char *FDECL(locomotion, (const struct permonst *,const char *));
E const char *FDECL(stagger, (const struct permonst *,const char *));
E const char *FDECL(on_fire, (struct permonst *,struct attack *));
E const struct permonst *FDECL(raceptr, (struct monst *));
E struct permonst *FDECL(get_monster_index_after_stone_to_flesh, (struct permonst *));
E boolean FDECL(has_two_heads, (struct permonst *));
E boolean FDECL(is_adult_dragon, (struct permonst *));
E boolean FDECL(ignores_elbereth_and_scare_monster_scroll, (struct permonst *));

/* ### monmove.c ### */

E boolean FDECL(itsstuck, (struct monst *));
E boolean FDECL(mb_trapped, (struct monst *));
E void FDECL(mon_regen, (struct monst *,boolean));
E int FDECL(dochugw, (struct monst *));
E boolean FDECL(onscary, (int,int,struct monst *));
E void FDECL(monflee, (struct monst *, int, boolean, boolean));
E int FDECL(dochug, (struct monst *));
E int FDECL(m_move, (struct monst *,int));
E boolean FDECL(closed_door, (int,int));
E boolean FDECL(accessible, (int,int));
E void FDECL(set_apparxy, (struct monst *));
E boolean FDECL(can_ooze, (struct monst *));

/* ### monst.c ### */

E void NDECL(monst_init);

/* ### monstr.c ### */

E void NDECL(monstr_init);

/* ### mplayer.c ### */

E const char *FDECL(elf_name, (size_t));
E struct monst *FDECL(mk_mplayer, (struct permonst *,xchar,
				   xchar,boolean));
E int NDECL(get_random_player_monster);
E void FDECL(create_mplayers, (int,boolean));
E int FDECL(hostile_mplayer_talk, (struct monst *));

#if defined(MICRO) || defined(WIN32)

/* ### msdos.c,os2.c,tos.c,winnt.c ### */

#  ifndef WIN32
E int NDECL(tgetch);
#  endif
#  ifndef TOS
E char NDECL(switchar);
#  endif
# ifndef __GO32__
E long FDECL(freediskspace, (char *));
#  ifdef MSDOS
E int FDECL(findfirst_file, (char *));
E int NDECL(findnext_file);
E long FDECL(filesize_nh, (char *));
#  else
E int FDECL(findfirst, (char *));
E int NDECL(findnext);
E long FDECL(filesize, (char *));
#  endif /* MSDOS */
E char *NDECL(foundfile_buffer);
# endif /* __GO32__ */
E void FDECL(chdrive, (char *));
# ifndef TOS
E void NDECL(disable_ctrlP);
E void NDECL(enable_ctrlP);
# endif
# if defined(MICRO) && !defined(WINNT)
E void NDECL(get_scr_size);
#  ifndef TOS
E void FDECL(gotoxy, (int,int));
#  endif
# endif
# ifdef TOS
E int FDECL(_copyfile, (char *,char *));
E int NDECL(kbhit);
E void NDECL(set_colors);
E void NDECL(restore_colors);
#  ifdef SUSPEND
E int NDECL(dosuspend);
#  endif
# endif /* TOS */
# ifdef WIN32
E char *FDECL(get_username, (int *));
E void FDECL(nt_regularize, (char *));
E int NDECL((*nt_kbhit));
E void FDECL(Delay, (int));
# endif /* WIN32 */
#endif /* MICRO || WIN32 */

/* ### mthrowu.c ### */

E int FDECL(thitu, (int,int,struct obj *,const char *));
E int FDECL(ohitmon, (struct monst *,struct obj *,int,boolean));
E void FDECL(thrwmu, (struct monst *));
E int FDECL(spitmu, (struct monst *,struct attack *));
E int FDECL(breamu, (struct monst *,struct attack *));
E boolean FDECL(linedup, (xchar,xchar,xchar,xchar));
E boolean FDECL(lined_up, (struct monst *));
E struct obj *FDECL(m_carrying, (struct monst *,int));
E void FDECL(m_useup, (struct monst *,struct obj *));
E void FDECL(m_throw, (struct monst *,int,int,int,int,int,struct obj *));
E boolean FDECL(hits_bars, (struct obj **,int,int,int,int));

/* ### muse.c ### */

E boolean FDECL(find_defensive, (struct monst *));
E int FDECL(use_defensive, (struct monst *));
E int FDECL(rnd_defensive_item, (struct monst *));
E boolean FDECL(find_offensive, (struct monst *));
#ifdef USE_TRAMPOLI
E int FDECL(mbhitm, (struct monst *,struct obj *));
#endif
E int FDECL(use_offensive, (struct monst *));
E int FDECL(rnd_offensive_item, (struct monst *));
E boolean FDECL(find_misc, (struct monst *));
E int FDECL(use_misc, (struct monst *));
E int FDECL(rnd_misc_item, (struct monst *));
E boolean FDECL(searches_for_item, (struct monst *,struct obj *));
E boolean FDECL(mon_reflects, (struct monst *,const char *));
E boolean FDECL(ureflects, (const char *,const char *));
E boolean FDECL(munstone, (struct monst *,boolean));

/* ### music.c ### */

E void NDECL(awaken_soldiers);
E int FDECL(do_play_instrument, (struct obj *));

/* ### nhlan.c ### */
#ifdef LAN_FEATURES
E void NDECL(init_lan_features);
E char *NDECL(lan_username);
# ifdef LAN_MAIL
E boolean NDECL(lan_mail_check);
E void FDECL(lan_mail_read, (struct obj *));
E void NDECL(lan_mail_init);
E void NDECL(lan_mail_finish);
E void NDECL(lan_mail_terminate);
# endif
#endif

/* ### nttty.c ### */

#ifdef WIN32CON
E void NDECL(get_scr_size);
E int NDECL(nttty_kbhit);
E void NDECL(nttty_open);
E void NDECL(nttty_rubout);
E int NDECL(tgetch);
E int FDECL(ntposkey,(int *, int *, int *));
E void FDECL(set_output_mode, (int));
E void NDECL(synch_cursor);
#endif

/* ### o_init.c ### */

E int NDECL(get_random_color);
E void NDECL(init_objects);
E int NDECL(find_skates);
E void NDECL(oinit);
E void FDECL(savenames, (int,int));
E void FDECL(restnames, (int));
E void FDECL(discover_object, (int,boolean,boolean));
E void FDECL(undiscover_object, (int));
E int NDECL(dodiscovered);
E void NDECL(dragons_init);

/* ### objects.c ### */

E void NDECL(objects_init);

/* ### objnam.c ### */

E char *FDECL(obj_typename, (int));
E char *FDECL(simple_typename, (int));
E char *FDECL(dump_typename, (int));
E boolean FDECL(obj_is_pname, (struct obj *));
E char *FDECL(distant_name, (struct obj *,char *(*)(struct obj*)));
E char *FDECL(fruitname, (boolean));
E char *FDECL(xname, (struct obj *));
E char *FDECL(mshot_xname, (struct obj *));
E boolean FDECL(the_unique_obj, (struct obj *obj));
E char *FDECL(doname, (struct obj *));
E char *FDECL(doname_with_price, (struct obj *));
E boolean FDECL(not_fully_identified, (struct obj *));
E char *FDECL(corpse_xname, (struct obj *,boolean));
E char *FDECL(cxname, (struct obj *));
#ifdef SORTLOOT
E char *FDECL(cxname2, (struct obj *));
#endif
E char *FDECL(killer_xname, (struct obj *));
E const char *FDECL(singular, (struct obj *,char *(*)(struct obj*)));
E char *FDECL(an, (const char *));
E char *FDECL(An, (const char *));
E char *FDECL(The, (const char *));
E char *FDECL(the, (const char *));
E char *FDECL(aobjnam, (struct obj *,const char *));
E char *FDECL(Tobjnam, (struct obj *,const char *));
E char *FDECL(otense, (struct obj *,const char *));
E char *FDECL(vtense, (const char *,const char *));
E char *FDECL(Doname2, (struct obj *));
E char *FDECL(yname, (struct obj *));
E char *FDECL(Yname2, (struct obj *));
E char *FDECL(ysimple_name, (struct obj *));
E char *FDECL(Ysimple_name2, (struct obj *));
E char *FDECL(makeplural, (const char *));
E char *FDECL(makesingular, (const char *));
E struct obj *FDECL(readobjnam, (char *,struct obj *,boolean));
E int FDECL(rnd_class, (int,int));
E const char *FDECL(cloak_simple_name, (struct obj *));
E const char *FDECL(mimic_obj_name, (struct monst *));

/* ### options.c ### */

E boolean FDECL(match_optname, (const char *,const char *,int,boolean));
E void NDECL(initoptions);
E void FDECL(parseoptions, (char *,boolean,boolean));
E boolean FDECL(parse_monster_color, (char *));
E boolean FDECL(parse_symbol, (const char *));
E int NDECL(doset);
E int NDECL(dotogglepickup);
E void NDECL(option_help);
E void FDECL(next_opt, (winid,const char *));
E int FDECL(fruitadd, (char *));
E int FDECL(choose_classes_menu, (const char *,int,boolean,char *,char *));
E void FDECL(add_menu_cmd_alias, (char, char));
E char FDECL(map_menu_cmd, (char));
E void FDECL(assign_warnings, (uchar *));
E char *FDECL(nh_getenv, (const char *));
E void FDECL(set_duplicate_opt_detection, (int));
E void FDECL(set_wc_option_mod_status, (unsigned long, int));
E void FDECL(set_wc2_option_mod_status, (unsigned long, int));
E void FDECL(set_option_mod_status, (const char *,int));
#ifdef AUTOPICKUP_EXCEPTIONS
E int FDECL(add_autopickup_exception, (const char *));
E void NDECL(free_autopickup_exceptions);
#endif /* AUTOPICKUP_EXCEPTIONS */
#ifdef MENU_COLOR
E boolean FDECL(add_menu_coloring, (char *));
#endif /* MENU_COLOR */

/* ### pager.c ### */

E int NDECL(dowhatis);
E int NDECL(doquickwhatis);
E int NDECL(doidtrap);
E int NDECL(dowhatdoes);
E char *FDECL(dowhatdoes_core,(char, char *));
E int NDECL(dohelp);
E int NDECL(dohistory);
E void FDECL(checkfile, (char *,struct permonst *,boolean,boolean));

/* ### pcmain.c ### */

#if defined(MICRO) || defined(WIN32)
# ifdef CHDIR
E void FDECL(chdirx, (char *,boolean));
# endif /* CHDIR */
#endif /* MICRO || WIN32 */

/* ### pcsys.c ### */

#if defined(MICRO) || defined(WIN32)
E void NDECL(flushout);
E int NDECL(dosh);
# ifdef MFLOPPY
E void FDECL(eraseall, (const char *,const char *));
E void FDECL(copybones, (int));
E void NDECL(playwoRAMdisk);
E int FDECL(saveDiskPrompt, (int));
E void NDECL(gameDiskPrompt);
# endif
E void FDECL(append_slash, (char *));
E void FDECL(getreturn, (const char *));
E void VDECL(msmsg, (const char *,...));
E FILE *FDECL(fopenp, (const char *,const char *));
#endif /* MICRO || WIN32 */

/* ### pctty.c ### */

#if defined(MICRO) || defined(WIN32)
E void NDECL(gettty);
E void FDECL(settty, (const char *));
E void NDECL(setftty);
E void VDECL(error, (const char *,...));
#if defined(TIMED_DELAY) && defined(_MSC_VER)
E void FDECL(msleep, (unsigned));
#endif
#endif /* MICRO || WIN32 */

/* ### pcunix.c ### */

#if defined(MICRO)
E void FDECL(regularize, (char *));
#endif /* MICRO */
#if defined(PC_LOCKING)
E void NDECL(getlock);
#endif

/* ### pickup.c ### */

#ifdef GOLDOBJ
E int FDECL(collect_obj_classes,
	(char *,struct obj *,boolean,boolean FDECL((*),(struct obj*)), int *));
#else
E int FDECL(collect_obj_classes,
	(char *,struct obj *,boolean,boolean,boolean FDECL((*),(struct obj*)), int *));
#endif
E void FDECL(add_valid_menu_class, (int));
E boolean FDECL(allow_all, (struct obj *));
E boolean FDECL(allow_category, (struct obj *));
E boolean FDECL(is_worn_by_type, (struct obj *));
#ifdef USE_TRAMPOLI
E int FDECL(ck_bag, (struct obj *));
E int FDECL(in_container, (struct obj *));
E int FDECL(out_container, (struct obj *));
#endif
E int FDECL(pickup, (int));
E int FDECL(pickup_object, (struct obj *, long, boolean));
E int FDECL(query_category, (const char *, struct obj *, int,
				menu_item **, int));
E int FDECL(query_objlist, (const char *, struct obj *, int,
				menu_item **, int, boolean (*)(struct obj*)));
E struct obj *FDECL(pick_obj, (struct obj *));
E int NDECL(encumber_msg);
E int NDECL(doloot);
E int FDECL(use_container, (struct obj *,int));
E int FDECL(loot_mon, (struct monst *,int *,boolean *));
E const char *FDECL(safe_qbuf, (const char *,unsigned,
				const char *,const char *,const char *));
E boolean FDECL(is_autopickup_exception, (struct obj *, boolean));

/* ### pline.c ### */

E void FDECL(msgpline_add, (int, char *));
E void NDECL(msgpline_free);
E void VDECL(pline, (const char *,...)) PRINTF_F(1,2);
E void VDECL(Norep, (const char *,...)) PRINTF_F(1,2);
E void NDECL(free_youbuf);
E void VDECL(You, (const char *,...)) PRINTF_F(1,2);
E void VDECL(Your, (const char *,...)) PRINTF_F(1,2);
E void VDECL(You_feel, (const char *,...)) PRINTF_F(1,2);
E void VDECL(You_cant, (const char *,...)) PRINTF_F(1,2);
E void VDECL(You_hear, (const char *,...)) PRINTF_F(1,2);
E void VDECL(pline_The, (const char *,...)) PRINTF_F(1,2);
E void VDECL(There, (const char *,...)) PRINTF_F(1,2);
E void VDECL(verbalize, (const char *,...)) PRINTF_F(1,2);
E void VDECL(raw_printf, (const char *,...)) PRINTF_F(1,2);
E void VDECL(impossible, (const char *,...)) PRINTF_F(1,2);
E void VDECL(warning, (const char *,...)) PRINTF_F(1,2);
E const char *FDECL(align_str, (aligntyp));
E void FDECL(mstatusline, (struct monst *));
E void NDECL(ustatusline);
E void NDECL(self_invis_message);

/* ### polyself.c ### */

E void NDECL(init_uasmon);
E void NDECL(set_uasmon);
E void NDECL(change_sex);
E void FDECL(polyself, (boolean));
E int FDECL(polymon, (int));
E void NDECL(rehumanize);
E int NDECL(dobreathe);
E int NDECL(dospit);
E int NDECL(doremove);
E int NDECL(dospinweb);
E int NDECL(dosummon);
E int NDECL(dogaze);
E int NDECL(dohide);
E int NDECL(domindblast);
E void FDECL(skinback, (boolean));
E const char *FDECL(mbodypart, (struct monst *,int));
E const char *FDECL(body_part, (int));
E int NDECL(poly_gender);
E void FDECL(ugolemeffects, (int,int));
E boolean NDECL(is_playermon_genocided);

/* ### potion.c ### */

E void FDECL(set_itimeout, (long *,long));
E void FDECL(incr_itimeout, (long *,int));
E void FDECL(make_confused, (long,boolean));
E void FDECL(make_stunned, (long,boolean));
E void FDECL(make_blinded, (long,boolean));
E void FDECL(make_sick, (long, const char *, boolean,int));
E void FDECL(make_vomiting, (long,boolean));
E boolean FDECL(make_hallucinated, (long,boolean,long));
E int NDECL(dodrink);
E int FDECL(dopotion, (struct obj *));
E int FDECL(peffects, (struct obj *));
E void FDECL(healup, (int,int,boolean,boolean,boolean));
E void FDECL(strange_feeling, (struct obj *,const char *));
E void FDECL(potionhit, (struct monst *,struct obj *,boolean));
E void FDECL(potionbreathe, (struct obj *));
E boolean FDECL(get_wet, (struct obj *));
E int NDECL(dodip);
E void FDECL(djinni_from_bottle, (struct obj *));
E struct monst *FDECL(split_mon, (struct monst *,struct monst *));
E const char *NDECL(bottlename);

/* ### pray.c ### */

#ifdef USE_TRAMPOLI
E int NDECL(prayer_done);
#endif
E int NDECL(dosacrifice);
E boolean FDECL(can_pray, (boolean));
E int NDECL(dopray);
E const char *NDECL(u_gname);
E int NDECL(doturn);
E const char *NDECL(a_gname);
E const char *FDECL(a_gname_at, (xchar x,xchar y));
E const char *FDECL(align_gname, (aligntyp));
E const char *FDECL(halu_gname, (aligntyp));
E const char *FDECL(align_gtitle, (aligntyp));
E void FDECL(altar_wrath, (int,int));
#ifdef ASTRAL_ESCAPE
E int FDECL(invoke_amulet, (struct obj *));
#endif
E int NDECL(in_trouble);


/* ### priest.c ### */

E int FDECL(move_special, (struct monst *,boolean,schar,boolean,boolean,
			   xchar,xchar,xchar,xchar));
E char FDECL(temple_occupied, (char *));
E int FDECL(pri_move, (struct monst *));
E void FDECL(priestini, (d_level *,struct mkroom *,int,int,boolean));
E char *FDECL(priestname, (struct monst *,char *));
E boolean FDECL(p_coaligned, (struct monst *));
E struct monst *FDECL(findpriest, (char));
E void FDECL(intemple, (int));
E void FDECL(priest_talk, (struct monst *));
E struct monst *FDECL(mk_roamer, (struct permonst *,aligntyp,
				  xchar,xchar,boolean));
E void FDECL(reset_hostility, (struct monst *));
E boolean FDECL(in_your_sanctuary, (struct monst *,xchar,xchar));
E void FDECL(ghod_hitsu, (struct monst *));
E void NDECL(angry_priest);
E void NDECL(clearpriests);
E void FDECL(restpriest, (struct monst *,boolean));

/* ### quest.c ### */

E void NDECL(onquest);
E void NDECL(nemdead);
E void NDECL(artitouch);
E boolean NDECL(ok_to_quest);
E void FDECL(leader_speaks, (struct monst *));
E void NDECL(nemesis_speaks);
E void FDECL(quest_chat, (struct monst *));
E void FDECL(quest_talk, (struct monst *));
E void FDECL(quest_stat_check, (struct monst *));
E void FDECL(finish_quest, (struct obj *));

/* ### questpgr.c ### */

E void NDECL(load_qtlist);
E void NDECL(unload_qtlist);
E short FDECL(quest_info, (int));
E const char *NDECL(ldrname);
E boolean FDECL(is_quest_artifact, (struct obj*));
E void FDECL(com_pager, (int));
E void FDECL(qt_pager, (int));
E char *FDECL(string_subst, (char *));
E void FDECL(qt_com_firstline, (int, char*));

/* ### random.c ### */

#if defined(RANDOM) && !defined(__GO32__) /* djgpp has its own random */
E void FDECL(srandom, (unsigned));
E char *FDECL(initstate, (unsigned,char *,int));
E char *FDECL(setstate, (char *));
E long NDECL(random);
#endif /* RANDOM */

/* ### read.c ### */

E int NDECL(doread);
E boolean FDECL(is_chargeable, (struct obj *));
E void FDECL(recharge, (struct obj *,int));
E void FDECL(forget_objects, (int));
E void FDECL(forget_levels, (int));
E void NDECL(forget_traps);
E void FDECL(forget_map, (boolean));
E int FDECL(seffects, (struct obj *));
#ifdef USE_TRAMPOLI
E void FDECL(set_lit, (int,int,genericptr_t));
#endif
E void FDECL(litroom, (boolean,struct obj *));
E void FDECL(do_genocide, (int,boolean));
E void FDECL(punish, (struct obj *));
E void NDECL(unpunish);
E boolean FDECL(cant_create, (int *, boolean));
E boolean NDECL(create_particular);
E void FDECL(drop_boulder_on_player, (boolean, boolean, boolean, boolean));
E int  FDECL(drop_boulder_on_monster, (int, int, boolean, boolean));

/* ### rect.c ### */

E void NDECL(init_rect);
E NhRect *FDECL(get_rect, (NhRect *));
E NhRect *NDECL(rnd_rect);
E void FDECL(remove_rect, (NhRect *));
E void FDECL(add_rect, (NhRect *));
E void FDECL(split_rects, (NhRect *,NhRect *));

/* ## region.c ### */
E void NDECL(clear_regions);
E void NDECL(run_regions);
E boolean FDECL(in_out_region, (xchar,xchar));
E boolean FDECL(m_in_out_region, (struct monst *,xchar,xchar));
E void NDECL(update_player_regions);
E void FDECL(update_monster_region, (struct monst *));
E NhRegion *FDECL(visible_region_at, (xchar,xchar));
E void FDECL(show_region, (NhRegion*, xchar, xchar));
E void FDECL(save_regions, (int,int));
E void FDECL(rest_regions, (int,boolean));
E NhRegion* FDECL(create_gas_cloud, (xchar, xchar, int, size_t, int));
E NhRegion* FDECL(create_cthulhu_death_cloud, (xchar, xchar, int, size_t, int));

/* ### restore.c ### */

E void FDECL(inven_inuse, (boolean));
E int FDECL(dorecover, (int));
E void FDECL(trickery, (char *));
E void FDECL(getlev, (int,int,xchar,boolean));
E void NDECL(minit);
E boolean FDECL(lookup_id_mapping, (unsigned, unsigned *));
#ifdef ZEROCOMP
E int FDECL(mread, (int,genericptr_t,unsigned int));
#else
E void FDECL(mread, (int,genericptr_t,unsigned int));
#endif

/* ### rip.c ### */

E void FDECL(genl_outrip, (winid,int));

/* ### rnd.c ### */

E int FDECL(rn2, (int));
E int FDECL(rnl, (int));
E int FDECL(rnd, (int));
E int FDECL(d, (int,int));
E int FDECL(rne, (int));
E int FDECL(rnz, (int));
E int FDECL(rnf, (int, int));

/* ### role.c ### */

E boolean FDECL(validrole, (int));
E boolean FDECL(validrace, (int, int));
E boolean FDECL(validgend, (int, int, int));
E boolean FDECL(validalign, (int, int, int));
E int NDECL(randrole);
E int FDECL(randrace, (int));
E int FDECL(randgend, (int, int));
E int FDECL(randalign, (int, int));
E int FDECL(str2role, (char *));
E int FDECL(str2race, (char *));
E int FDECL(str2gend, (char *));
E int FDECL(str2align, (char *));
E boolean FDECL(ok_role, (int, int, int, int));
E int FDECL(pick_role, (int, int, int, int));
E boolean FDECL(ok_race, (int, int, int, int));
E int FDECL(pick_race, (int, int, int, int));
E boolean FDECL(ok_gend, (int, int, int, int));
E int FDECL(pick_gend, (int, int, int, int));
E boolean FDECL(ok_align, (int, int, int, int));
E int FDECL(pick_align, (int, int, int, int));
E void NDECL(role_init);
E void NDECL(rigid_role_checks);
E void NDECL(plnamesuffix);
E const char *FDECL(Hello, (struct monst *));
E const char *NDECL(Goodbye);
E char *FDECL(build_plselection_prompt, (char *, int, int, int, int, int));
E char *FDECL(root_plselection_prompt, (char *, int, int, int, int, int));
E void FDECL(violated, (int));
E boolean FDECL(successful_cdt, (int));
E boolean FDECL(intended_cdt, (int));
E boolean FDECL(superfluous_cdt, (int));
E boolean FDECL(failed_cdt, (int));

/* ### rumors.c ### */

E char *FDECL(getrumor, (int,char *, boolean));
E void FDECL(outrumor, (int,int));
E void FDECL(outoracle, (boolean, boolean));
E void FDECL(save_oracles, (int,int));
E void FDECL(restore_oracles, (int));
E int FDECL(doconsult, (struct monst *));

/* ### save.c ### */

E char *NDECL(get_goodbye_message);
E int NDECL(dosave);
#if defined(UNIX) || defined(VMS) || defined(WIN32)
E void FDECL(hangup, (int));
#endif
E int NDECL(dosave0);
#ifdef INSURANCE
E void NDECL(savestateinlock);
#endif
#ifdef MFLOPPY
E boolean FDECL(savelev, (int,xchar,int));
E boolean FDECL(swapin_file, (int));
E void NDECL(co_false);
#else
E void FDECL(savelev, (int,xchar,int));
#endif
E void FDECL(bufon, (int));
E void FDECL(bufoff, (int));
E void FDECL(bflush, (int));
E void FDECL(bwrite, (int,genericptr_t,unsigned int));
E void FDECL(bclose, (int));
E void FDECL(savefruitchn, (int,int));
E void NDECL(free_dungeons);
E void NDECL(freedynamicdata);

/* ### shk.c ### */

#ifdef GOLDOBJ
E long FDECL(money2mon, (struct monst *, long));
E void FDECL(money2u, (struct monst *, long));
#endif
E char *FDECL(shkname, (struct monst *));
E void FDECL(shkgone, (struct monst *));
E void FDECL(set_residency, (struct monst *,boolean));
E void FDECL(replshk, (struct monst *,struct monst *));
E void FDECL(restshk, (struct monst *,boolean));
E char FDECL(inside_shop, (xchar,xchar));
E void FDECL(u_left_shop, (char *,boolean));
E void FDECL(remote_burglary, (xchar,xchar));
E void FDECL(u_entered_shop, (char *));
E boolean FDECL(same_price, (struct obj *,struct obj *));
E void NDECL(shopper_financial_report);
E int FDECL(inhishop, (struct monst *));
E struct monst *FDECL(shop_keeper, (char));
E boolean FDECL(tended_shop, (struct mkroom *));
E void FDECL(delete_contents, (struct obj *));
E void FDECL(obfree, (struct obj *,struct obj *));
E void FDECL(home_shk, (struct monst *,boolean));
E void FDECL(make_happy_shk, (struct monst *,boolean));
E void FDECL(hot_pursuit, (struct monst *));
E void FDECL(make_angry_shk, (struct monst *,xchar,xchar));
E int NDECL(dopay);
E boolean FDECL(paybill, (int));
E void NDECL(finish_paybill);
E struct obj *FDECL(find_oid, (unsigned));
E long FDECL(contained_cost, (struct obj *,struct monst *,long,boolean, boolean));
E long FDECL(contained_gold, (struct obj *));
E void FDECL(picked_container, (struct obj *));
E long FDECL(unpaid_cost, (struct obj *));
E void FDECL(addtobill, (struct obj *,boolean,boolean,boolean));
E void FDECL(splitbill, (struct obj *,struct obj *));
E void FDECL(subfrombill, (struct obj *,struct monst *));
E long FDECL(stolen_value, (struct obj *,xchar,xchar,boolean,boolean));
E void FDECL(sellobj_state, (int));
E void FDECL(sellobj, (struct obj *,xchar,xchar));
E int FDECL(doinvbill, (int));
E struct monst *FDECL(shkcatch, (struct obj *,xchar,xchar));
E void FDECL(add_damage, (xchar,xchar,long));
E int FDECL(repair_damage, (struct monst *,struct damage *,boolean));
E int FDECL(shk_move, (struct monst *));
E void FDECL(after_shk_move, (struct monst *));
E boolean FDECL(is_following_shopkeeper, (struct monst *));
E void FDECL(shopdig, (int));
E void FDECL(pay_for_damage, (const char *,boolean));
E boolean FDECL(costly_spot, (xchar,xchar));
E struct obj *FDECL(shop_object, (xchar,xchar));
E void FDECL(price_quote, (struct obj *));
E void FDECL(shk_chat, (struct monst *));
E void FDECL(check_unpaid_usage, (struct obj *,boolean));
E void FDECL(check_unpaid, (struct obj *));
E void FDECL(costly_gold, (xchar,xchar,long));
E long FDECL(get_cost_of_shop_item, (struct obj *));
E boolean FDECL(block_door, (xchar,xchar));
E boolean FDECL(block_entry, (xchar,xchar));
E void FDECL(blkmar_guards, (struct monst *));
E void NDECL(set_black_marketeer_angry);
E char *FDECL(shk_your, (char *,struct obj *));
E char *FDECL(Shk_Your, (char *,struct obj *));
E void FDECL(shk_holler, (struct monst*));

/* ### shknam.c ### */

E void FDECL(stock_room, (int,struct mkroom *));
E boolean FDECL(saleable, (struct monst *,struct obj *));
E int FDECL(get_shop_item, (int));
E void NDECL(shop_selection_init);

/* ### sit.c ### */

E void NDECL(take_gold);
E int NDECL(dosit);
E void NDECL(rndcurse);
E void NDECL(attrcurse);

/* ### sounds.c ### */

E void NDECL(dosounds);
E const char *FDECL(growl_sound, (struct monst *));
E void FDECL(growl, (struct monst *));
E void FDECL(yelp, (struct monst *));
E void FDECL(whimper, (struct monst *));
E void FDECL(beg, (struct monst *));
E int NDECL(dotalk);
#ifdef USER_SOUNDS
E int FDECL(add_sound_mapping, (const char *));
E void FDECL(play_sound_for_message, (const char *));
#endif

/* ### sys/msdos/sound.c ### */

#ifdef MSDOS
E int FDECL(assign_soundcard, (char *));
#endif

/* ### sp_lev.c ### */

E boolean FDECL(check_room, (xchar *,xchar *,xchar *,xchar *,boolean));
E boolean FDECL(create_room, (xchar,xchar,xchar,xchar,
			      xchar,xchar,xchar,xchar));
E void FDECL(create_secret_door, (struct mkroom *,xchar));
E boolean FDECL(dig_corridor, (coord *,coord *,boolean,schar,schar));
E void FDECL(fill_room, (struct mkroom *,boolean));
E boolean FDECL(load_special, (const char *));

/* ### spell.c ### */

#ifdef USE_TRAMPOLI
E int NDECL(learn);
#endif
E int FDECL(study_book, (struct obj *));
E void FDECL(book_disappears, (struct obj *));
E void FDECL(book_substitution, (struct obj *,struct obj *));
E void NDECL(age_spells);
E int NDECL(docast);
E int FDECL(spell_skilltype, (int));
E int FDECL(spelleffects, (int,boolean));
E void NDECL(forget_spells);
E int NDECL(dovspell);
E void FDECL(initialspell, (struct obj *));
E void NDECL(dump_spells);
E boolean FDECL(parse_spellorder, (char *));

/* ### steal.c ### */

#ifdef USE_TRAMPOLI
E int NDECL(stealarm);
#endif
#ifdef GOLDOBJ
E long FDECL(somegold, (long));
#else
E long NDECL(somegold);
#endif
E void FDECL(stealgold, (struct monst *));
E void FDECL(remove_worn_item, (struct obj *,boolean));
E int FDECL(steal, (struct monst *, char *));
E int FDECL(mpickobj, (struct monst *,struct obj *));
E void FDECL(stealamulet, (struct monst *));
E void FDECL(mdrop_special_objs, (struct monst *));
E void FDECL(relobj, (struct monst *,int,boolean));
#ifdef GOLDOBJ
E struct obj *FDECL(findgold, (struct obj *));
#endif

/* ### steed.c ### */

E void NDECL(rider_cant_reach);
E boolean FDECL(can_saddle, (struct monst *));
E int FDECL(use_saddle, (struct obj *));
E boolean FDECL(can_ride, (struct monst *));
E int NDECL(doride);
E boolean FDECL(mount_steed, (struct monst *, boolean));
E void NDECL(exercise_steed);
E void NDECL(kick_steed);
E void FDECL(dismount_steed, (int));
E void FDECL(place_monster, (struct monst *,int,int));

/* ### teleport.c ### */

E boolean FDECL(goodpos, (int,int,struct monst *,unsigned));
E boolean FDECL(enexto, (coord *,xchar,xchar,struct permonst *));
E boolean FDECL(enexto_core, (coord *,xchar,xchar,struct permonst *,unsigned));
E boolean FDECL(enexto_core_range, (coord *,xchar,xchar,struct permonst *,unsigned,int));
E int FDECL(epathto, (coord *,int,xchar,xchar,struct permonst *));
E void FDECL(teleds, (int,int,boolean));
E boolean FDECL(safe_teleds, (boolean));
E boolean FDECL(teleport_pet, (struct monst *,boolean));
E void NDECL(tele);
E int NDECL(dotele);
E void NDECL(level_tele);
E void FDECL(domagicportal, (struct trap *));
E void FDECL(tele_trap, (struct trap *));
E void FDECL(level_tele_trap, (struct trap *));
E void FDECL(rloc_to, (struct monst *,int,int));
E boolean FDECL(rloc, (struct monst *, boolean));
E boolean FDECL(tele_restrict, (struct monst *));
E void FDECL(mtele_trap, (struct monst *, struct trap *,int));
E int FDECL(mlevel_tele_trap, (struct monst *, struct trap *,boolean,int));
E void FDECL(rloco, (struct obj *));
E int NDECL(random_teleport_level);
E boolean FDECL(u_teleport_mon, (struct monst *,boolean));

/* ### termcap.c ### */
E void FDECL(term_start_color, (int));
E void NDECL(term_end_color);
E void FDECL(term_start_attr, (int));
E void FDECL(term_end_attr, (int));

/* ### tile.c ### */
#ifdef USE_TILES
E void FDECL(substitute_tiles, (d_level *));
#endif

/* ### timeout.c ### */

E void NDECL(burn_away_slime);
E void NDECL(nh_timeout);
E void FDECL(fall_asleep, (int, boolean));
E void FDECL(attach_egg_hatch_timeout, (struct obj *));
E void FDECL(attach_fig_transform_timeout, (struct obj *));
E void FDECL(kill_egg, (struct obj *));
E void FDECL(hatch_egg, (genericptr_t, long));
E void FDECL(learn_egg_type, (int));
E void FDECL(burn_object, (genericptr_t, long));
E void FDECL(begin_burn, (struct obj *, boolean));
E void FDECL(end_burn, (struct obj *, boolean));
E void NDECL(do_storms);
E boolean FDECL(start_timer, (long, short, short, genericptr_t));
E long FDECL(stop_timer, (short, genericptr_t));
E void NDECL(run_timers);
E void FDECL(obj_move_timers, (struct obj *, struct obj *));
E void FDECL(obj_split_timers, (struct obj *, struct obj *));
E void FDECL(obj_stop_timers, (struct obj *));
E boolean FDECL(obj_is_local, (struct obj *));
E void FDECL(save_timers, (int,int,int));
E void FDECL(restore_timers, (int,int,boolean,long));
E void FDECL(relink_timers, (boolean));
E int NDECL(wiz_timeout_queue);
E void NDECL(timer_sanity_check);

/* ### topten.c ### */

#ifdef RECORD_CONDUCT
E long FDECL(encodeconduct, (void));
#endif
E void FDECL(topten, (int));
E void FDECL(prscore, (int,char **));
E struct obj *FDECL(tt_oname, (struct obj *));

/* ### track.c ### */

E void NDECL(initrack);
E void NDECL(settrack);
E coord *FDECL(gettrack, (int,int));

/* ### trap.c ### */

E boolean FDECL(burnarmor,(struct monst *));
E boolean FDECL(rust_dmg, (struct obj *,const char *,int,boolean,struct monst *));
E void FDECL(grease_protect, (struct obj *,const char *,struct monst *));
E struct trap *FDECL(maketrap, (int,int,int));
E void FDECL(fall_through, (boolean));
E struct monst *FDECL(animate_statue, (struct obj *,xchar,xchar,int,int *));
E struct monst *FDECL(activate_statue_trap,
			(struct trap *,xchar,xchar,boolean));
E void FDECL(dotrap, (struct trap *, unsigned));
E void FDECL(seetrap, (struct trap *));
E int FDECL(mintrap, (struct monst *));
E void FDECL(instapetrify, (const char *));
E void FDECL(minstapetrify, (struct monst *,boolean));
E int FDECL(instadisintegrate, (const char *));
E int FDECL(minstadisintegrate, (struct monst *));
E void FDECL(selftouch, (const char *));
E void FDECL(mselftouch, (struct monst *,const char *,boolean));
E void NDECL(float_up);
E void FDECL(fill_pit, (int,int));
E int FDECL(float_down, (long, long));
E int FDECL(fire_damage, (struct obj *,boolean,boolean,xchar,xchar));
E boolean FDECL(water_damage, (struct obj *,boolean,boolean));
E boolean NDECL(drown);
E void FDECL(drain_en, (int));
E int NDECL(dountrap);
E int FDECL(untrap, (boolean));
E void FDECL(reward_untrap, (struct trap *, struct monst *));
E boolean FDECL(chest_trap, (struct obj *,int,boolean));
E void FDECL(deltrap, (struct trap *));
E boolean FDECL(delfloortrap, (struct trap *));
E struct trap *FDECL(t_at, (int,int));
E void FDECL(b_trapped, (const char *,int));
E boolean NDECL(unconscious);
E boolean NDECL(lava_effects);
E boolean NDECL(swamp_effects);
E void FDECL(blow_up_landmine, (struct trap *));
E int FDECL(launch_obj,(short,int,int,int,int,int));

/* ### u_init.c ### */

E void NDECL(u_init);

/* ### uhitm.c ### */

E void FDECL(hurtmarmor,(struct monst *,int));
E boolean FDECL(attack_checks, (struct monst *,struct obj *));
E void FDECL(check_caitiff, (struct monst *));
E schar FDECL(find_roll_to_hit, (struct monst *));
E boolean FDECL(attack, (struct monst *));
E boolean FDECL(hmon, (struct monst *,struct obj *,int));
E int FDECL(damageum, (struct monst *,struct attack *));
E void FDECL(missum, (struct monst *,struct attack *));
E int FDECL(passive, (struct monst *,boolean,int,uchar));
E void FDECL(passive_obj, (struct monst *,struct obj *,struct attack *));
E void FDECL(stumble_onto_mimic, (struct monst *));
E int FDECL(flash_hits_mon, (struct monst *,struct obj *));

/* ### unixmain.c ### */

#ifdef UNIX
# ifdef PORT_HELP
E void NDECL(port_help);
# endif
#endif /* UNIX */


/* ### unixtty.c ### */

#if defined(UNIX) || defined(__BEOS__)
E void NDECL(gettty);
E void FDECL(settty, (const char *));
E void NDECL(setftty);
E void NDECL(intron);
E void NDECL(introff);
E void VDECL(error, (const char *,...)) PRINTF_F(1,2);
#endif /* UNIX || __BEOS__ */

/* ### unixunix.c ### */

#ifdef UNIX
E void NDECL(getlock);
E void FDECL(regularize, (char *));
# if defined(TIMED_DELAY) && !defined(msleep) && defined(SYSV)
E void FDECL(msleep, (unsigned));
# endif
# if defined(DEF_PAGER) || defined(DEF_MAILREADER)
E int FDECL(child, (int));
# endif
#ifdef FILE_AREAS
E char *FDECL(make_file_name, (const char *, const char *));
E FILE *FDECL(fopen_datafile_area, (const char *,const char *,const char *,
				boolean));
E FILE *FDECL(freopen_area, (const char *,const char *,const char *, FILE *));
E int FDECL(chmod_area, (const char *, const char *, int));
E int FDECL(open_area, (const char *, const char *, int, int));
E int FDECL(creat_area, (const char *, const char *, int));
E boolean FDECL(lock_file_area, (const char *, const char *,int));
E void FDECL(unlock_file_area, (const char *, const char *));
E int FDECL(rename_area, (const char *, const char *, const char *));
E int FDECL(remove_area, (const char *, const char *));
#endif
#endif /* UNIX */

/* ### unixres.c ### */

#ifdef UNIX
# ifdef GNOME_GRAPHICS 
E int FDECL(hide_privileges, (boolean));
# endif
#endif /* UNIX */

/* ### vault.c ### */

E boolean FDECL(grddead, (struct monst *));
E char FDECL(vault_occupied, (char *));
E void NDECL(invault);
E int FDECL(gd_move, (struct monst *));
E void NDECL(paygd);
E long NDECL(hidden_gold);
E boolean NDECL(gd_sound);

/* ### version.c ### */

E char *FDECL(version_string, (char *));
E char *FDECL(getversionstring, (char *));
E int NDECL(doversion);
E int NDECL(doextversion);
#ifdef MICRO
E boolean FDECL(comp_times, (long));
#endif
E boolean FDECL(check_version, (struct version_info *,
				const char *,boolean));
E unsigned long FDECL(get_feature_notice_ver, (char *));
E unsigned long NDECL(get_current_feature_ver);
#ifdef RUNTIME_PORT_ID
E void FDECL(append_port_id, (char *));
#endif

/* ### video.c ### */

#ifdef MSDOS
E int FDECL(assign_video, (char *));
# ifdef NO_TERMS
E void NDECL(gr_init);
E void NDECL(gr_finish);
# endif
E void FDECL(tileview,(boolean));
#endif
#ifdef VIDEOSHADES
E int FDECL(assign_videoshades, (char *));
E int FDECL(assign_videocolors, (char *));
#endif

/* ### vision.c ### */

E void NDECL(vision_init);
E int FDECL(does_block, (int,int,struct rm*));
E void NDECL(vision_reset);
E void FDECL(vision_recalc, (int));
E void FDECL(block_point, (int,int));
E void FDECL(unblock_point, (int,int));
E boolean FDECL(clear_path, (int,int,int,int));
E void FDECL(do_clear_area, (int,int,int,
			     void (*)(int,int,genericptr_t),genericptr_t));

#ifdef VMS

/* ### vmsfiles.c ### */

E int FDECL(vms_link, (const char *,const char *));
E int FDECL(vms_unlink, (const char *));
E int FDECL(vms_creat, (const char *,unsigned int));
E int FDECL(vms_open, (const char *,int,unsigned int));
E boolean FDECL(same_dir, (const char *,const char *));
E int FDECL(c__translate, (int));
E char *FDECL(vms_basename, (const char *));

/* ### vmsmail.c ### */

E unsigned long NDECL(init_broadcast_trapping);
E unsigned long NDECL(enable_broadcast_trapping);
E unsigned long NDECL(disable_broadcast_trapping);
# if 0
E struct mail_info *NDECL(parse_next_broadcast);
# endif /*0*/

/* ### vmsmain.c ### */

E int FDECL(main, (int, char **));
# ifdef CHDIR
E void FDECL(chdirx, (const char *,boolean));
# endif /* CHDIR */

/* ### vmsmisc.c ### */

E void NDECL(vms_abort);
E void FDECL(vms_exit, (int));

/* ### vmstty.c ### */

E int NDECL(vms_getchar);
E void NDECL(gettty);
E void FDECL(settty, (const char *));
E void FDECL(shuttty, (const char *));
E void NDECL(setftty);
E void NDECL(intron);
E void NDECL(introff);
E void VDECL(error, (const char *,...)) PRINTF_F(1,2);
#ifdef TIMED_DELAY
E void FDECL(msleep, (unsigned));
#endif

/* ### vmsunix.c ### */

E void NDECL(getlock);
E void FDECL(regularize, (char *));
E int NDECL(vms_getuid);
E boolean FDECL(file_is_stmlf, (int));
E int FDECL(vms_define, (const char *,const char *,int));
E int FDECL(vms_putenv, (const char *));
E char *NDECL(verify_termcap);
# if defined(CHDIR) || defined(SECURE)
E void NDECL(privoff);
E void NDECL(privon);
# endif
# if defined(MAIL)
E int FDECL(vms_doshell, (const char *,boolean));
# endif
# ifdef SUSPEND
E int NDECL(dosuspend);
# endif

#endif /* VMS */

/* ### weapon.c ### */

E int FDECL(hitval, (struct obj *,struct monst *));
E int FDECL(dmgval, (struct obj *,struct monst *));
E struct obj *FDECL(select_rwep, (struct monst *));
E struct obj *FDECL(select_hwep, (struct monst *));
E void FDECL(possibly_unwield, (struct monst *,boolean));
E int FDECL(mon_wield_item, (struct monst *));
E int NDECL(abon);
E int NDECL(dbon);
E int NDECL(enhance_weapon_skill);
#ifdef DUMP_LOG
E void NDECL(dump_weapon_skill);
#endif
E void FDECL(unrestrict_weapon_skill, (int));
E void NDECL(forget_skills);
E void FDECL(lose_skill, (int));
E void FDECL(use_skill, (int,int));
E void FDECL(add_skill_slot, (int));
E void FDECL(lose_skill_slot, (int));
E int FDECL(weapon_type, (struct obj *));
E int NDECL(uwep_skill_type);
E int FDECL(weapon_hit_bonus, (struct obj *));
E int FDECL(weapon_dam_bonus, (struct obj *));
E void FDECL(skill_init, (const struct def_skill *));
E boolean NDECL(can_advance_something);

/* ### were.c ### */

E void FDECL(were_change, (struct monst *));
E void FDECL(new_were, (struct monst *));
E int FDECL(were_summon, (struct permonst *,boolean,int *,char *));
E void NDECL(you_were);
E void FDECL(you_unwere, (boolean));

/* ### wield.c ### */

E void FDECL(setuwep, (struct obj *));
E void FDECL(setuqwep, (struct obj *));
E void FDECL(setuswapwep, (struct obj *));
E int NDECL(dowield);
E int NDECL(doswapweapon);
E int NDECL(dowieldquiver);
E boolean FDECL(wield_tool, (struct obj *,const char *));
E int NDECL(can_twoweapon);
E void NDECL(drop_uswapwep);
E int NDECL(dotwoweapon);
E void NDECL(uwepgone);
E void NDECL(uswapwepgone);
E void NDECL(uqwepgone);
E void NDECL(untwoweapon);
E boolean FDECL(erode_obj, (struct obj *,int));
E int FDECL(chwepon, (struct obj *,int));
E int FDECL(welded, (struct obj *));
E void FDECL(weldmsg, (struct obj *));
E void FDECL(setmnotwielded, (struct monst *,struct obj *));
E void NDECL(unwield_weapons_silently);

/* ### windows.c ### */

E void FDECL(choose_windows, (const char *));
E char FDECL(genl_message_menu, (char,int,const char *));
E void FDECL(genl_preference_update, (const char *));

/* ### wizard.c ### */

E void NDECL(amulet);
E int FDECL(mon_has_amulet, (struct monst *));
E int FDECL(mon_has_special, (struct monst *));
E int FDECL(tactics, (struct monst *));
E void NDECL(aggravate);
E void NDECL(clonewiz);
E int NDECL(pick_nasty);
E int FDECL(nasty, (struct monst*));
E void NDECL(resurrect);
E void NDECL(intervene);
E void NDECL(wizdead);
E void FDECL(cuss, (struct monst *));

/* ### worm.c ### */

E int NDECL(get_wormno);
E void FDECL(initworm, (struct monst *,int));
E void FDECL(worm_move, (struct monst *));
E void FDECL(worm_nomove, (struct monst *));
E void FDECL(wormgone, (struct monst *));
E void FDECL(wormhitu, (struct monst *));
E void FDECL(cutworm, (struct monst *,xchar,xchar,struct obj *));
E void FDECL(see_wsegs, (struct monst *));
E void FDECL(detect_wsegs, (struct monst *,boolean));
E void FDECL(save_worm, (int,int));
E void FDECL(rest_worm, (int));
E void FDECL(place_wsegs, (struct monst *));
E void FDECL(remove_worm, (struct monst *));
E void FDECL(place_worm_tail_randomly, (struct monst *,xchar,xchar));
E int FDECL(count_wsegs, (struct monst *));
E boolean FDECL(worm_known, (struct monst *));
E void FDECL(flip_worm_segs_vertical, (struct monst *, int));
E void FDECL(flip_worm_segs_horizontal, (struct monst *, int));

/* ### worn.c ### */

E void FDECL(setworn, (struct obj *,long));
E void FDECL(setnotworn, (struct obj *));
E void FDECL(mon_set_minvis, (struct monst *));
E void FDECL(mon_adjust_speed, (struct monst *,int,struct obj *));
E void FDECL(update_mon_intrinsics,
		(struct monst *,struct obj *,boolean,boolean));
E int FDECL(find_mac, (struct monst *));
E void FDECL(m_dowear, (struct monst *,boolean));
E struct obj *FDECL(which_armor, (struct monst *,long));
E void FDECL(mon_break_armor, (struct monst *,boolean));
E void FDECL(bypass_obj, (struct obj *));
E void NDECL(clear_bypasses);
E int FDECL(racial_exception, (struct monst *, struct obj *));

/* ### write.c ### */

E int FDECL(dowrite, (struct obj *));

/* ### zap.c ### */

E int FDECL(bhitm, (struct monst *,struct obj *));
E void FDECL(probe_monster, (struct monst *));
E boolean FDECL(get_obj_location, (struct obj *,xchar *,xchar *,int));
E boolean FDECL(get_mon_location, (struct monst *,xchar *,xchar *,int));
E struct monst *FDECL(get_container_location, (struct obj *obj, int *, int *));
E struct monst *FDECL(montraits, (struct obj *,coord *));
E struct monst *FDECL(revive, (struct obj *));
E int FDECL(unturn_dead, (struct monst *));
E void FDECL(cancel_item, (struct obj *));
E boolean FDECL(drain_item, (struct obj *));
E struct obj *FDECL(poly_obj, (struct obj *, int));
E boolean FDECL(obj_resists, (struct obj *,int,int));
E boolean FDECL(obj_shudders, (struct obj *));
E void FDECL(do_osshock, (struct obj *));
E int FDECL(bhito, (struct obj *,struct obj *));
E int FDECL(bhitpile, (struct obj *,int (*)(struct obj*,struct obj*),int,int));
E int FDECL(zappable, (struct obj *));
E void FDECL(zapnodir, (struct obj *));
E int NDECL(dozap);
E int FDECL(zapyourself, (struct obj *,boolean));
E boolean FDECL(cancel_monst, (struct monst *,struct obj *,
			       boolean,boolean,boolean));
E void FDECL(weffects, (struct obj *));
E int NDECL(spell_damage_bonus);
E const char *FDECL(exclam, (int force));
E void FDECL(hit, (const char *,struct monst *,const char *));
E void FDECL(miss, (const char *,struct monst *));
E struct monst *FDECL(bhit, (int,int,int,int,int (*)(struct monst*,struct obj*),
			     int (*)(struct obj*,struct obj*),struct obj *, boolean *));
E struct monst *FDECL(boomhit, (int,int));
E int FDECL(burn_floor_paper, (int,int,boolean,boolean));
E void FDECL(buzz, (int,int,xchar,xchar,int,int));
E void FDECL(melt_ice, (xchar,xchar));
E int FDECL(zap_over_floor, (xchar,xchar,int,boolean *));
E void FDECL(fracture_rock, (struct obj *));
E boolean FDECL(break_statue, (struct obj *));
E void FDECL(destroy_item, (int,int));
E int FDECL(destroy_mitem, (struct monst *,int,int));
E int FDECL(resist, (struct monst *,char,int,int));
E void FDECL(makewish, (boolean));

/* ### livelog.c ### */
#ifdef LIVELOGFILE
E boolean NDECL(livelog_start);
E void NDECL(livelog_achieve_update);
E void FDECL(livelog_wish, (char*));
#ifdef LIVELOG_SHOUT
E int NDECL(doshout);
#endif
E void FDECL(livelog_shoplifting, (const char*, const char*, long));
#endif
E void FDECL(livelog_game_started, (const char*, const char*, const char*, const char*));
E void FDECL(livelog_game_action, (const char*));
E void FDECL(livelog_generic, (const char*, const char*));
E void FDECL(livelog_genocide, (const char*, int));

#endif /* !MAKEDEFS_C && !LEV_LEX_C */

/* ### tutorial.c ### */
E boolean FDECL(check_tutorial_message, (int));
E void NDECL(maybe_tutorial);
E int NDECL(tutorial_redisplay);
E void NDECL(tutorial_redisplay_message);
E void FDECL(check_tutorial_farlook, (int, int));
E void FDECL(check_tutorial_command, (char));
E int FDECL(check_tutorial_location, (int, int, boolean));
E int FDECL(check_tutorial_oclass, (int));

/* ### unicode.c ### */
E glyph_t FDECL(get_unicode_codepoint, (int));
E int FDECL(pututf8char, (glyph_t));

#undef E

#endif /* EXTERN_H */
