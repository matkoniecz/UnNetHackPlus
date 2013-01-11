{
	struct obj *singlepotion;
	const char *tmp;
	short mixture;
	char Your_buf[BUFSZ];

	potion->in_use = TRUE;		/* assume it will be used up */
	if(potion->otyp == POT_WATER) {
		boolean useeit = !Blind;
		if (useeit) (void) Shk_Your(Your_buf, obj);
		if (potion->blessed) {
			if (obj->cursed) {
				if (useeit){
					pline("%s %s %s.",
					  Your_buf,
					  aobjnam(obj, "softly glow"),
					  hcolor(NH_AMBER));
				}
				uncurse(obj);
				obj->bknown=1;
				poof(potion);
				return(1);
			} else if(!obj->blessed) {
				if (useeit) {
					tmp = hcolor(NH_LIGHT_BLUE);
					pline("%s %s with a%s %s aura.",
					  Your_buf,
					  aobjnam(obj, "softly glow"),
					  index(vowels, *tmp) ? "n" : "", tmp);
				}
				bless(obj);
				obj->bknown=1;
				poof(potion);
				return(1);
			}
		} else if (potion->cursed) {
			if (obj->blessed) {
				if (useeit)
					pline("%s %s %s.",
					  Your_buf,
					  aobjnam(obj, "glow"),
					  hcolor((const char *)"brown"));
				unbless(obj);
				obj->bknown=1;
				poof(potion);
				return(1);
			} else if(!obj->cursed) {
				if (useeit) {
					tmp = hcolor(NH_BLACK);
					pline("%s %s with a%s %s aura.",
					  Your_buf,
					  aobjnam(obj, "glow"),
					  index(vowels, *tmp) ? "n" : "", tmp);
				}
				curse(obj);
				obj->bknown=1;
				poof(potion);
				return(1);
			}
		} else
			if (get_wet(obj)) {
				poof(potion);
				return(1);
			}
	} else 
if (obj->otyp == POT_POLYMORPH || potion->otyp == POT_POLYMORPH) {
		/* some objects can't be polymorphed */
		if (obj->otyp == potion->otyp ||	/* both POT_POLY */
		    is_unpolymorphable(obj) ||
		    obj_resists(obj->otyp == POT_POLYMORPH ?
				potion : obj, 5, 95)) {
			pline(nothing_happens);
		} else {
			boolean was_wep = FALSE, was_swapwep = FALSE, was_quiver = FALSE;
			short save_otyp = obj->otyp;
			/* KMH, conduct */
			u.uconduct.polypiles++;

			if (obj == uwep) was_wep = TRUE;
			else if (obj == uswapwep) was_swapwep = TRUE;
			else if (obj == uquiver) was_quiver = TRUE;

			obj = poly_obj(obj, STRANGE_OBJECT);

			if (was_wep) setuwep(obj);
			else if (was_swapwep) setuswapwep(obj);
			else if (was_quiver) setuqwep(obj);

			if (obj->otyp != save_otyp) {
				makeknown(POT_POLYMORPH);
				useup(potion);
				prinv((char *)0, obj, 0L);
				return 1;
			} else {
				pline("Nothing seems to happen.");
				poof(potion);
				return(1);
			}
		}
		potion->in_use = FALSE;	/* didn't go poof */
		return(1);
	} else if(obj->oclass == POTION_CLASS && obj->otyp != potion->otyp) {
		/* Mixing potions is dangerous... */
		/* Give a clue to what's going on ... */
		if(potion->dknown && obj->dknown) {
			You("mix the %s potion with the %s one ...", 
				OBJ_DESCR(objects[potion->otyp]),
				OBJ_DESCR(objects[obj->otyp]));
		} else
			pline_The("potions mix...");
		/* KMH, balance patch -- acid is particularly unstable */
		if (obj->cursed || obj->otyp == POT_ACID || potion->otyp == POT_ACID || !rn2(10)) {
			pline("BOOM!  They explode!");
			exercise(A_STR, FALSE);
			if (!breathless(youmonst.data) || haseyes(youmonst.data)) {
				potionbreathe(obj);
			}
			useup(obj);
			useup(potion);
			losehp(Acid_resistance ? rnd(5) : rnd(10),
			       "alchemic blast", KILLED_BY_AN);
			return(1);
		}

		obj->blessed = obj->cursed = obj->bknown = 0;
		if (Blind || Hallucination) obj->dknown = 0;

		if ((mixture = mixtype(obj, potion)) != 0) {
			obj->otyp = mixture;
		} else {
		    switch (obj->odiluted ? 1 : rnd(8)) {
			case 1:
				obj->otyp = POT_WATER;
				break;
			case 2:
			case 3:
				obj->otyp = POT_SICKNESS;
				break;
			case 4:
				{
				  struct obj *otmp;
				  otmp = mkobj(POTION_CLASS,FALSE);
				  obj->otyp = otmp->otyp;
				  obfree(otmp, (struct obj *)0);
				}
				break;
			default:
				if (!Blind) {
					pline_The("mixture glows brightly and evaporates.");
				}
				useup(obj);
				useup(potion);
				return(1);
		    }
		}

		obj->odiluted = (obj->otyp != POT_WATER);

		if (OBJ_NAME(objects[obj->otyp]) == 0) {
			panic("dipping created an inexistant potion (%d)", obj->otyp);
		}

		if (obj->otyp == POT_WATER && !Hallucination) {
			pline_The("mixture bubbles%s.", Blind ? "" : ", then clears");
		} else if (!Blind) {
			pline_The("mixture looks %s.", hcolor(OBJ_DESCR(objects[obj->otyp])));
		}

		useup(potion);
		return(1);
	}

#ifdef INVISIBLE_OBJECTS
	if (potion->otyp == POT_INVISIBILITY && !obj->oinvis) {
		obj->oinvis = TRUE;
		if (!Blind) {
			if (!See_invisible) pline("Where did %s go?", the(xname(obj)));
			else You("notice a little haziness around %s.", the(xname(obj)));
		}
		poof(potion);
		return(1);
	} else if (potion->otyp == POT_SEE_INVISIBLE && obj->oinvis) {
		obj->oinvis = FALSE;
		if (!Blind) {
			if (!See_invisible) pline("So that's where %s went!", the(xname(obj)));
			else pline_The("haziness around %s disappears.", the(xname(obj)));
		}
		poof(potion);
		return(1);
	}
#endif
	if (potion->otyp == POT_ACID && obj->otyp == CORPSE && obj->corpsenm == PM_LICHEN && !Blind) {
		pline("%s %s %s around the edges.", The(cxname(obj)),
		  otense(obj, "turn"),
		  potion->odiluted ? hcolor(NH_ORANGE) : hcolor(NH_RED));
		potion->in_use = FALSE;	/* didn't go poof */
		return(1);
	}

	if(is_poisonable(obj)) {
		if(potion->otyp == POT_SICKNESS && !obj->opoisoned) {
			char buf[BUFSZ];
			if (potion->quan > 1L) {
				Sprintf(buf, "One of %s", the(xname(potion)));
			}
			else {
				Strcpy(buf, The(xname(potion)));
			}
			pline("%s forms a coating on %s.", buf, the(xname(obj)));
			obj->opoisoned = TRUE;
			poof(potion);
			return(1);
		} else if(obj->opoisoned &&
		  (potion->otyp == POT_HEALING ||
		  potion->otyp == POT_EXTRA_HEALING ||
		  potion->otyp == POT_FULL_HEALING)) {
			pline("A coating wears off %s.", the(xname(obj)));
			obj->opoisoned = 0;
			poof(potion);
			return(1);
		}
	}

	if (potion->otyp == POT_GAIN_ABILITY && obj->oclass == WAND_CLASS) {
		if (potion->cursed && obj->otyp != WAN_NOTHING) {
			pline_The("%s glows %s for a moment.", xname(obj), hcolor(NH_BLACK));
			obj = poly_obj(obj, WAN_NOTHING); 
			poof(potion);
			return(1);
		}
		else if (obj->otyp == WAN_NOTHING) {
			int i, prob = rnd(1000);
			pline_The("%s glows %s for a moment.", xname(obj), hcolor(NH_BLUE));
			//shamelessly borrowed from mkobj
			i = bases[WAND_CLASS];
			while((prob -= objects[i].oc_prob) > 0) i++;
			obj = poly_obj(obj, i); 
			poof(potion);
			return(1);
		}
	}

	if (potion->otyp == POT_OIL) {
		boolean wisx = FALSE;
		if (potion->lamplit) {	/* burning */
			int omat = objects[obj->otyp].oc_material;
			/* the code here should be merged with fire_damage */
			if (catch_lit(obj)) {
				/* catch_lit does all the work if true */
			} else if (obj->oerodeproof || obj_resists(obj, 5, 95) || !is_flammable(obj) || obj->oclass == FOOD_CLASS) {
				pline("%s %s to burn for a moment.", Yname2(obj), otense(obj, "seem"));
			} else {
				if ((omat == PLASTIC || omat == PAPER) && !obj->oartifact) {
					obj->oeroded = MAX_ERODE;
				}
				pline_The("burning oil %s %s.",
				  obj->oeroded == MAX_ERODE ? "destroys" : "damages",
				  yname(obj));
				if (obj->oeroded == MAX_ERODE) {
					obj_extract_self(obj);
					obfree(obj, (struct obj *)0);
					obj = (struct obj *) 0;
				} else {
					/* we know it's carried */
					if (obj->unpaid) {
						/* create a dummy duplicate to put on bill */
						verbalize("You burnt it, you bought it!");
						bill_dummy_object(obj);
					}
				obj->oeroded++;
				}
			}
		} else if (potion->cursed) {
			pline_The("potion spills and covers your %s with oil.", makeplural(body_part(FINGER)));
			incr_itimeout(&Glib, d(2,10));
		} else if (obj->oclass != WEAPON_CLASS && !is_weptool(obj)) {
			/* the following cases apply only to weapons */
			goto more_dips;
			/* Oil removes rust and corrosion, but doesn't unburn.
			* Arrows, etc are classed as metallic due to arrowhead
			* material, but dipping in oil shouldn't repair them.
			*/
		} else if ((!is_rustprone(obj) && !is_corrodeable(obj)) || is_ammo(obj) || (!obj->oeroded && !obj->oeroded2)) {
			/* uses up potion, doesn't set obj->greased */
			pline("%s %s with an oily sheen.", Yname2(obj), otense(obj, "gleam"));
		} else {
			pline("%s %s less %s.",
			  Yname2(obj), otense(obj, "are"),
			  (obj->oeroded && obj->oeroded2) ? "corroded and rusty" :
			  obj->oeroded ? "rusty" : "corroded");
			if (obj->oeroded > 0) {
				obj->oeroded--;
			}
			if (obj->oeroded2 > 0) {
				obj->oeroded2--;
			}
			wisx = TRUE;
		}
		exercise(A_WIS, wisx);
		makeknown(potion->otyp);
		useup(potion);
		return 1;
	}
	more_dips:

	/* Allow filling of MAGIC_LAMPs to prevent identification by player */
	if ((obj->otyp == OIL_LAMP || obj->otyp == MAGIC_LAMP) && (potion->otyp == POT_OIL)) {
		/* Turn off engine before fueling, turn off fuel too :-)  */
		if (obj->lamplit || potion->lamplit) {
			useup(potion);
			explode(u.ux, u.uy, 11, d(6,6), 0, EXPL_FIERY);
			exercise(A_WIS, FALSE);
			return 1;
		}
		/* Adding oil to an empty magic lamp renders it into an oil lamp */
		if ((obj->otyp == MAGIC_LAMP) && obj->spe == 0) {
			obj->otyp = OIL_LAMP;
			obj->age = 0;
		}
		if (obj->age > 1000L) {
			pline("%s %s full.", Yname2(obj), otense(obj, "are"));
			potion->in_use = FALSE;	/* didn't go poof */
		} else {
			You("fill %s with oil.", yname(obj));
			check_unpaid(potion);	/* Yendorian Fuel Tax */
			obj->age += 2*potion->age;	/* burns more efficiently */
			if (obj->age > 1500L) obj->age = 1500L;
			useup(potion);
			exercise(A_WIS, TRUE);
		}
		makeknown(POT_OIL);
		obj->spe = 1;
		update_inventory();
		return 1;
	}

	potion->in_use = FALSE;		/* didn't go poof */
	if ((obj->otyp == UNICORN_HORN || obj->otyp == AMETHYST) && (mixture = mixtype(obj, potion)) != 0) {
		char oldbuf[BUFSZ], newbuf[BUFSZ];
		short old_otyp = potion->otyp;
		boolean old_dknown = FALSE;
		boolean more_than_one = potion->quan > 1;

		oldbuf[0] = '\0';
		if (potion->dknown) {
			old_dknown = TRUE;
			Sprintf(oldbuf, "%s ", hcolor(OBJ_DESCR(objects[potion->otyp])));
		}
		/* with multiple merged potions, split off one and
		   just clear it */
		if (potion->quan > 1L) {
			singlepotion = splitobj(potion, 1L);
		} else {
			singlepotion = potion;
		}
		if(singlepotion->unpaid && costly_spot(u.ux, u.uy)) {
			You("use it, you pay for it.");
			bill_dummy_object(singlepotion);
		}
		singlepotion->otyp = mixture;
		singlepotion->blessed = 0;
		if (mixture == POT_WATER) {
			singlepotion->cursed = singlepotion->odiluted = 0;
		} else {
			singlepotion->cursed = obj->cursed;  /* odiluted left as-is */
		}
		singlepotion->bknown = FALSE;
		if (Blind) {
			singlepotion->dknown = FALSE;
		} else {
			singlepotion->dknown = !Hallucination;
			if (mixture == POT_WATER && singlepotion->dknown) {
				Sprintf(newbuf, "clears");
			} else {
				Sprintf(newbuf, "turns %s", hcolor(OBJ_DESCR(objects[mixture])));
			}
			pline_The("%spotion%s %s.", oldbuf,
			  more_than_one ? " that you dipped into" : "",
			  newbuf);
			if(!objects[old_otyp].oc_uname && !objects[old_otyp].oc_name_known && old_dknown) {
				struct obj fakeobj;
				fakeobj = zeroobj;
				fakeobj.dknown = 1;
				fakeobj.otyp = old_otyp;
				fakeobj.oclass = POTION_CLASS;
				docall(&fakeobj);
			}
		}
		obj_extract_self(singlepotion);
		singlepotion = hold_another_object(singlepotion,
				"You juggle and drop %s!",
				doname(singlepotion), (const char *)0);
		update_inventory();
		return(1);
	}
	pline("Interesting...");
	return(1);
}

