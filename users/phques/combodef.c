// ** Taken from [moutis Hands Down QMK implementation](https://github.com/moutis/HandsDown)

// ** Note: this is to be #included in your keymap.c

//
//     Key Position Names for a 34 (-54) key split form factor
//        Should cover Ferris through Atreus-Kyria-Ergodox
//     ╭─────────────────────╮                  ╭─────────────────────╮
// LT5 │ LT4 LT3 LT2 LT1 LT0 │ LTA          RTA │ RT0 RT1 RT2 RT3 RT4 │ RT5
// LM5 │ LM4 LM3 LM2 LM1 LM0 | LMA          RMA | RT0 RM1 RM2 RM3 RM4 │ RM5
// LB5 │ LB4 LB3 LB2 LB1 LB0 │ LBA LBB  RBB RBA │ RB0 RB1 RB2 RB3 RB4 │ RB5
//     ╰───────────╮ LH2 LH1 │ LH0 LHA  RHA RH0 │ RH1 RH2 ╭───────────╯
//     LH5 LH4 LH3 ╰─────────╯                  ╰─────────╯ RH3 RH4 RH5
//
// These definitions based on Hands Down Neu & variations'
// combo keycodes defined in the variation config
//
// Combo definitions defined spatially
// Other variation dependent combos have predetermined
// positions for 34 key boards

const uint16_t PROGMEM HC_cfg_combo[] = {HD_RH1, HD_RH2, COMBO_END}; // keyboard settings/config layer
const uint16_t PROGMEM HC_cfg_combo2[] = {HD_LH1, HD_LH2, COMBO_END}; // keyboard settings/config layer
#ifdef APPMENU_keys
const uint16_t PROGMEM H_menu_combo[] = {APPMENU_keys, COMBO_END}; // AppMENU
#else
const uint16_t PROGMEM H_menu_combo[] = {HD_LB3, HD_LB1, COMBO_END}; // AppMENU // default Appmenu location
#endif
// #ifdef APPMENU_nav_keys
// const uint16_t PROGMEM H_menu_nav_combo[] = {APPMENU_nav_keys, COMBO_END}; // AppMENU on Nav layer
// #else
// const uint16_t PROGMEM H_menu_nav_combo[] = {LV_LT1, LV_LT0, COMBO_END}; // AppMENU on Nav layer
// #endif
const uint16_t PROGMEM H_HDl_num_combo[] = {HD_LH1, HD_RH1, COMBO_END}; // Toggle num layer
// const uint16_t PROGMEM H_LNl_num_combo[] = {LN_LH1, LN_RH1, COMBO_END}; // Toggle num layer

// Spatially arranged on the QWERTY ZXCV locations
//
const uint16_t PROGMEM Htab_combo[] = {HD_tab_keys, COMBO_END};    // tab
const uint16_t PROGMEM Hstab_combo[] = {HD_stab_keys, COMBO_END};  // shift-tab
const uint16_t PROGMEM Hspc_combo[] = {HD_spc_keys, COMBO_END};    // SPACE
const uint16_t PROGMEM Hent_combo[] = {HD_ent_keys, COMBO_END};    // ENTER
const uint16_t PROGMEM Hent2_combo[] = {HD_ent2_keys, COMBO_END};  // hard-ENTER/page break

// SEMANTIC FUNCTIONS  ** using SemKeys **
const uint16_t PROGMEM Hnew_combo[] = {HD_new_keys, COMBO_END};     // new
const uint16_t PROGMEM Hopen_combo[] = {HD_open_keys, COMBO_END};   // open
const uint16_t PROGMEM Hclose_combo[] = {HD_close_keys, COMBO_END}; // close
const uint16_t PROGMEM Hquit_combo[] = {HD_quit_keys, COMBO_END};   // quit
const uint16_t PROGMEM Hfind_combo[] = {HD_find_keys, COMBO_END};   // find selection
const uint16_t PROGMEM Hsall_combo[] = {HD_sall_keys, COMBO_END};   // select all
const uint16_t PROGMEM Hswrd_combo[] = {HD_swrd_keys, COMBO_END};   // select word
const uint16_t PROGMEM Hundo_combo[] = {HD_undo_keys, COMBO_END};   // undo
const uint16_t PROGMEM Hredo_combo[] = {HD_redo_keys, COMBO_END};   // redo
const uint16_t PROGMEM Hcopy_combo[] = {HD_copy_keys, COMBO_END};   // copy (linger/linger for cut)
const uint16_t PROGMEM Hpste_combo[] = {HD_pste_keys, COMBO_END};   // paste (linger/hold for paste-match)




const uint16_t PROGMEM H_Left_combo[] = {HD_LT3, HD_LT2, HD_LT1, COMBO_END}; // TYPE LeftComboTapE
const uint16_t PROGMEM H_Right_combo[] = {HD_RT1, HD_RT2, HD_RT3, COMBO_END}; // some demonstrator macro placeholder

const uint16_t PROGMEM F_KILL_combo[] = {HD_RT3, HD_RT0, COMBO_END}; // KILL = Force quit OR CTRL-ALT-DEL
const uint16_t PROGMEM F_SCAP_combo[] = {HD_LT3, HD_LT2, HD_LT1, HD_LT0, COMBO_END}; //  SCREEN shot SELECTION to file
const uint16_t PROGMEM F_SCLP_combo[] = {HD_LT2, HD_LT1, HD_LT0, COMBO_END}; // SCREEN shot SELECTION to clipboard
const uint16_t PROGMEM F_SRCH_combo[] = {HD_LM2, HD_LM1, HD_LM0, COMBO_END}; // platform search (siri/cortana, etc.)


const uint16_t PROGMEM H_CAPW_combo[] = {HD_RB3, HD_RB4, COMBO_END}; // CAPS WORD (on until word delimiter)
const uint16_t PROGMEM F_CAPS_combo[] = {HD_RB2, HD_RB3, HD_RB4, COMBO_END}; // CAPS LOCK (on until hit again)



// Off map and other letter/symbol thingies typically on keyboard

// RIGHT HAND
// should work for most Neu variations (Gold/Titanium/Rhodium/Vibranium)
// Bronze/Silver/Platinum (C on right hand, H on left/thumb) may need changes...
//
const uint16_t PROGMEM F_ESC_combo[] = {HD_LM4, HD_LM1, COMBO_END}; // ESCape
const uint16_t PROGMEM Hndsh_combo[] = {HD_RB0, HD_RB1, COMBO_END}; // – n dash (hold for m-dash)
const uint16_t PROGMEM Htild_combo[] = {HD_RB0, HD_RB3, COMBO_END}; // ~ tilde (not the deadkey for eñye)
const uint16_t PROGMEM Hunds_combo[] = {HD_RB1, HD_RB3, COMBO_END}; // _ underscore
const uint16_t PROGMEM Hequal_combo[] = {HD_RB2, HD_RB3, COMBO_END}; // = equal (hold for %)


// spatially arranged characters and diacritics
const uint16_t PROGMEM Hscln_combo[] = {HD_RM0, HD_RM1, COMBO_END}; // ; semicolon
const uint16_t PROGMEM Hcoln_combo[] = {HD_RT1, HD_RT3, COMBO_END}; // : colon
const uint16_t PROGMEM Hexlm_combo[] = {HD_RT1, HD_RT2, COMBO_END}; // !
const uint16_t PROGMEM Hques_combo[] = {HD_RT2, HD_RT3, COMBO_END}; // ?
const uint16_t PROGMEM Hdolr_combo[] = {HD_RT2, HD_RT4, COMBO_END}; // " DOUBLE QUOTE  // " hijacked for $
const uint16_t PROGMEM Htic_combo[] = {HD_RT3, HD_RT4, COMBO_END}; // ` tic (not dead key grave)

const uint16_t PROGMEM Hhash_combo[] = {HD_RT0, HD_RT2, COMBO_END}; // # HASH hijacked for §
const uint16_t PROGMEM Hat_combo[] = {HD_RT0, HD_RT1, COMBO_END}; // @

// spatially arranged diacritics
const uint16_t PROGMEM Hdier_combo[] = {HD_RB1, HD_RB2, COMBO_END}; // ¨ dieresis (dead key)
const uint16_t PROGMEM Henye_combo[] = {HD_LT4, HD_LT0, COMBO_END}; // ˜ enye (dead key) (ñ only?)
const uint16_t PROGMEM Hacut_combo[] = {HD_RM1, HD_RM2, COMBO_END}; // ´ acute (dead key)é
const uint16_t PROGMEM Hgrv_combo[] = {HD_RM2, HD_RM3, COMBO_END}; // ` grave (dead key)
const uint16_t PROGMEM Hcirc_combo[] = {HD_RM1, HD_RM3, COMBO_END}; // ˆ circumflex (dead key)
const uint16_t PROGMEM Hmacr_combo[] = {HD_RM2, HD_RM4, COMBO_END}; // - macron (dead key)
const uint16_t PROGMEM Hring_combo[] = {HD_RM1, HD_RM4, COMBO_END}; // ˚ ring (dead key)
const uint16_t PROGMEM Hcedi_combo[] = {HD_LM4, HD_LM2, COMBO_END}; // ¸ cedille (dead key)
//const uint16_t PROGMEM Hoslsh_combo[] = {HD_RB2, HD_LB0, COMBO_END}; // ø/Ø or Wh

// Precomposed letters with diacritics (uses expanded Semantic Keys)
// This could be a very large numper of comboos, as many as 35 for vowels
// áàâåäā éèêe̊ëē íìîīï óòôo̊ōü úùûůūü
// two handed combos with home-row [p, r, m, i, l] + vowel
// and many more for frequently used consonants
// two handed combos top/bottom row vowel hand?


// TEXT ENTRY - off map standard alphas (also on Layer L_SYM @ J & G respectively)byby=
const uint16_t PROGMEM H_Q_combo[] = {HD_Qu_keys, COMBO_END}; // TYPE "q" (Qu & Linger deletes u)
const uint16_t PROGMEM H_L1_combo[] = {HD_L1_keys, COMBO_END}; // ex. TYPE "z"
//const uint16_t PROGMEM H_L2_combo[] = {HD_L2_keys, COMBO_END}; // ex. TYPE "x"
//const uint16_t PROGMEM H_L3_combo[] = {HD_L3_keys, COMBO_END}; // ex. TYPE "j"

// H digraph combos (ideally, these are phonetically/mnemonically arranged

const uint16_t PROGMEM H_Th_combo[] = {HD_Th_keys, COMBO_END}; // TYPE "th"
const uint16_t PROGMEM H_Ch_combo[] = {HD_Ch_keys, COMBO_END}; // TYPE "ch"
const uint16_t PROGMEM H_Wh_combo[] = {HD_Wh_keys, COMBO_END}; // TYPE "wh"
const uint16_t PROGMEM H_Sh_combo[] = {HD_Sh_keys, COMBO_END}; // TYPE "sh"
const uint16_t PROGMEM H_Ph_combo[] = {HD_Ph_keys, COMBO_END}; // TYPE "ph"
const uint16_t PROGMEM H_Gh_combo[] = {HD_Gh_keys, COMBO_END}; // TYPE "gh"
const uint16_t PROGMEM H_Sch_combo[] = {HD_Sch_keys, COMBO_END}; // TYPE "Sch"

// TEXT ENTRY - (ANY ROW/ MIXED ROWS)

const uint16_t PROGMEM HOE_lig_combo[] = {HD_OE_lig_keys, COMBO_END}; // Œ
const uint16_t PROGMEM HAE_lig_combo[] = {HD_AE_lig_keys, COMBO_END}; // Æ


// Fast 4grams

// PRONOUNS Fast 4-7grams
#ifdef HD_Icap_keys
const uint16_t PROGMEM H_Icap_combo[] = {HD_Icap_keys, COMBO_END}; // TYPE "I"
#endif
#ifdef HD_Id_keys
const uint16_t PROGMEM H_Id_combo[] = {HD_Id_keys, COMBO_END}; // TYPE "I'd"+"'ve "
#endif
#ifdef HD_Ill_keys
const uint16_t PROGMEM H_Ill_combo[] = {HD_Ill_keys, COMBO_END}; // TYPE "I'll"+"'ve "
#endif
#ifdef HD_Im_keys
const uint16_t PROGMEM H_Im_combo[] = {HD_Im_keys, COMBO_END}; // TYPE "I'm "
#endif
#ifdef HD_Iv_keys
const uint16_t PROGMEM H_Iv_combo[] = {HD_Iv_keys, COMBO_END}; // TYPE "I've "
#endif

#ifdef HD_youd_keys
const uint16_t PROGMEM H_youd_combo[] = {HD_youd_keys, COMBO_END}; // TYPE "you'd" + 've
#endif
#ifdef HD_youll_keys
const uint16_t PROGMEM H_youll_combo[] = {HD_youll_keys, COMBO_END}; // TYPE "you'll" + 've
#endif
#ifdef HD_youre_keys
const uint16_t PROGMEM H_youre_combo[] = {HD_youre_keys, COMBO_END}; // TYPE "you're"
#endif
#ifdef HD_youve_keys
const uint16_t PROGMEM H_youve_combo[] = {HD_youve_keys, COMBO_END}; // TYPE "you've"
#endif
#ifdef HD_your_keys
const uint16_t PROGMEM H_your_combo[] = {HD_your_keys, COMBO_END}; // TYPE "your" "P" for "possessive" case
#endif
#ifdef HD_their_keys
const uint16_t PROGMEM H_their_combo[] = {HD_their_keys, COMBO_END}; // TYPE "their" #6
#endif
#ifdef HD_they_keys
const uint16_t PROGMEM H_they_combo[] = {HD_they_keys, COMBO_END}; // "they" #23 + 've
#endif
#ifdef HD_theyd_keys
const uint16_t PROGMEM H_theyd_combo[] = {HD_theyd_keys, COMBO_END}; // "they'd" #23 + 've
#endif
#ifdef HD_theyll_keys
const uint16_t PROGMEM H_theyll_combo[] = {HD_theyll_keys, COMBO_END}; // "they'll" #23 + 've
#endif
#ifdef HD_theyre_keys
const uint16_t PROGMEM H_theyre_combo[] = {HD_theyre_keys, COMBO_END}; // "they're"
#endif

#ifdef HD_there_keys
const uint16_t PROGMEM H_there_combo[] = {HD_there_keys, COMBO_END}; // TYPE "there" #7 + 's
#endif
#ifdef HD_here_keys
const uint16_t PROGMEM H_here_combo[] = {HD_here_keys, COMBO_END}; // TYPE "here" #5 + 's
#endif

#ifdef HD_where_keys
const uint16_t PROGMEM H_where_combo[] = {HD_where_keys, COMBO_END}; // "where" + 's
#endif
#ifdef HD_were_keys
const uint16_t PROGMEM H_were_combo[] = {HD_were_keys, COMBO_END}; // TYPE "we're"
#endif
#ifdef HD_wed_keys
const uint16_t PROGMEM H_wed_combo[] = {HD_wed_keys, COMBO_END}; // TYPE "we'd" + 've
#endif
#ifdef HD_well_keys
const uint16_t PROGMEM H_well_combo[] = {HD_well_keys, COMBO_END}; // TYPE "we'll" + 've
#endif
#ifdef HD_weve_keys
const uint16_t PROGMEM H_weve_combo[] = {HD_weve_keys, COMBO_END}; // TYPE "we've"
#endif

// TWO HANDS

//## crashing, try with no combos
// combo_t key_combos[] = {
// };

combo_t key_combos[] = {
    // These simple combos trigger on press, repeat. HC_cfg_combo
    [HC_CFG] = COMBO(HC_cfg_combo, MO(L_CFG)), // keyboard/media settings/config layer
    [HC_CFG2] = COMBO(HC_cfg_combo2, MO(L_CFG)), // keyboard/media settings/config layer
    //PQ use semkey for this: gui-tab / alt-tab :
    // [HC_APP] = COMBO(H_menu_combo, KC_APP), // app menu moutis
    // [HC_APPNAV] = COMBO(H_menu_nav_combo, KC_APP), // app menu moutis
    // [HC_HDl_num] = COMBO(H_HDl_num_combo, TG(L_NUM)), // toggle num layer
    // [HC_LNl_num] = COMBO(H_LNl_num_combo, TG(L_NUM)), // toggle num layer
    [HC_SCLN] = COMBO(Hscln_combo, KC_SCLN), // ;
    [HC_COLN] = COMBO_ACTION(Hcoln_combo), // :  (hold for elipsis)
    [HC_UNDS] = COMBO(Hunds_combo, S(KC_UNDS)), // _ underscore
    [HC_TILD] = COMBO(Htild_combo, KC_TILD),  // ~ or SK_TILD?
    [HC_TIC] = COMBO(Htic_combo, KC_GRAVE),  // ` (not dead)
    [HC_EXLM] = COMBO(Hexlm_combo, KC_EXLM), // !
    [HC_QUES] = COMBO(Hques_combo, KC_QUES), // ?
    [HC_DOLR] = COMBO(Hdolr_combo, KC_DLR), // $
    [HC_HASH] = COMBO(Hhash_combo, SK_SECT), // # hijacked for §
    [HC_AT] = COMBO_ACTION(Hat_combo), // @ (hold for alanreiser.com)
    [HC_TAB] = COMBO(Htab_combo, KC_TAB),
    [HC_STAB] = COMBO(Hstab_combo, S(KC_TAB)),

    [HC_Q] = COMBO_ACTION(H_Q_combo),
    [HC_L1] = COMBO(H_L1_combo, HD_L1),
//    [HC_L2] = COMBO(H_L2_combo, HD_L2),
//    [HC_L3] = COMBO(H_L3_combo, HD_L3),
#ifdef EN_HDIGRAPH_COMBOS
    [HC_Ch] = COMBO_ACTION(H_Ch_combo),
    [HC_Sch] = COMBO_ACTION(H_Sch_combo),
    [HC_Gh] = COMBO_ACTION(H_Gh_combo),
    [HC_Ph] = COMBO_ACTION(H_Ph_combo),
    [HC_Th] = COMBO_ACTION(H_Th_combo),
    [HC_Sh] = COMBO_ACTION(H_Sh_combo),
    [HC_Wh] = COMBO_ACTION(H_Wh_combo),
#endif
    [HC_OE] = COMBO_ACTION(HOE_lig_combo),  // Œ
    [HC_AE] = COMBO_ACTION(HAE_lig_combo),  // Æ

    // action combos below
    // This group have custom actions on trigger (no hold-delay), repeat if held

    // this block should be contiguous,
    // Delayed action (COMBO_HOLD threshold). No repeat if held (tap_code)
    // should send the underlying combo keys if COMBO_HOLD is not met.

    [FC_ESC] = COMBO(F_ESC_combo, KC_ESC),    // ESCape
    [FC_KILL] = COMBO(F_KILL_combo, SK_KILL), // Force quit
    [FC_SCAP] = COMBO(F_SCAP_combo, SK_SCAP), // SCREEN CAPTURE SELECTION
    [FC_SCLP] = COMBO(F_SCLP_combo, SK_SCLP), // SCREEN CAPTURE SELECTION to clipboard
    [FC_SRCH] = COMBO(F_SRCH_combo, SK_SRCH), // platform search (siri/cortana, etc.)
    [FC_CAPS] = COMBO(F_CAPS_combo, KC_CAPS), // CAPS LOCK
    // [HC_CAPW] = COMBO_ACTION(H_CAPW_combo),   // CAPS_WORD, moutis
    [HC_CAPW] = COMBO(H_CAPW_combo, CW_TOGG),   // CAPS_WORD, QMK

    [HC_NDSH] = COMBO_ACTION(Hndsh_combo), // – N-DASH (hold for M-dash)

// Dead keys (Mac only, for now)
    [HC_ACUT] = COMBO_ACTION(Hacut_combo), // ´ acute
    [HC_GRV] = COMBO_ACTION(Hgrv_combo), // ` grave
    [HC_CIRC] = COMBO_ACTION(Hcirc_combo), // ˆ circumflex
    [HC_MACR] = COMBO_ACTION(Hmacr_combo), // - macron
    [HC_DIER] = COMBO_ACTION(Hdier_combo), // ¨ dieresis
    [HC_RING] = COMBO_ACTION(Hring_combo), // ˚ ring
    [HC_CEDILLE] = COMBO_ACTION(Hcedi_combo), // ¸ cedille
    [HC_ENYE] = COMBO_ACTION(Henye_combo), // ˜ tilde (dead)
//    [HC_OSLSH] = COMBO_ACTION(Hoslsh_combo), // ø/Ø or Wh

//    [HC_ENYE] = COMBO(Henye_combo, SK_ENYE), // ñ/Ñ enye
//    [HC_ELIP] = COMBO_ACTION(Helip_combo),  // …


// Fast entry 4grams

// PRONOUNS Fast entry 4-7gram PRONOUNS (an English quirk)
 #ifdef HD_Icap_keys
    [HC_I] = COMBO_ACTION(H_Icap_combo),// TYPE "I"+"'ve "
#endif
#ifdef HD_Id_keys
    [HC_Id] = COMBO_ACTION(H_Id_combo),// TYPE "I'd "
#endif
#ifdef HD_Ill_keys
    [HC_Ill] = COMBO_ACTION(H_Ill_combo),// TYPE "I'll "
#endif
#ifdef HD_Im_keys
    [HC_Im] = COMBO_ACTION(H_Im_combo),// TYPE "I'm  "
#endif
#ifdef HD_Iv_keys
    [HC_Iv] = COMBO_ACTION(H_Iv_combo),// TYPE "I've  "
#endif

#ifdef HD_wed_keys
    [HC_wed_4gram] = COMBO_ACTION(H_wed_combo),// TYPE "we'd"
#endif
#ifdef HD_well_keys
    [HC_well_5gram] = COMBO_ACTION(H_well_combo),// TYPE "we'll"
#endif
#ifdef HD_were_keys
    [HC_were_5gram] = COMBO_ACTION(H_were_combo),// TYPE "we're"
#endif
#ifdef HD_weve_keys
    [HC_weve_5gram] = COMBO_ACTION(H_weve_combo),// TYPE "we've"
#endif
#ifdef HD_where_keys
    [HC_where_5gram] = COMBO_ACTION(H_where_combo), // TYPE "where"
#endif

#ifdef HD_youd_keys
   [HC_youd_5gram] = COMBO_ACTION(H_youd_combo),// TYPE "you'd"
#endif
#ifdef HD_youll_keys
    [HC_youll_6gram] = COMBO_ACTION(H_youll_combo),// TYPE "you'll"
#endif
#ifdef HD_youre_keys
    [HC_youre_6gram] = COMBO_ACTION(H_youre_combo),// TYPE "you're"
#endif
#ifdef HD_youve_keys
    [HC_youve_6gram] = COMBO_ACTION(H_youve_combo),// TYPE "you've"
#endif
#ifdef HD_your_keys
    [HC_your_4gram] = COMBO_ACTION(H_your_combo),// TYPE "your"
#endif
#ifdef HD_they_keys
    [HC_they_4gram] = COMBO_ACTION(H_they_combo), // TYPE "they" #23
#endif
#ifdef HD_their_keys
    [HC_their_5gram] = COMBO_ACTION(H_their_combo), // TYPE "their" #6
#endif
#ifdef HD_theyre_keys
    [HC_theyre_7gram] = COMBO_ACTION(H_theyre_combo), // TYPE "they're"
#endif
#ifdef HD_theyll_keys
    [HC_theyll_7gram] = COMBO_ACTION(H_theyll_combo), // TYPE "they'll" #23 + 've
#endif
#ifdef HD_theyd_keys
    [HC_theyd_6gram] = COMBO_ACTION(H_theyd_combo), // TYPE "they'd" #23 + 've
#endif

#ifdef HD_there_keys
    [HC_there_5gram] = COMBO_ACTION(H_there_combo), // TYPE "there" #7
#endif
#ifdef HD_here_keys
    [HC_here_4gram] = COMBO_ACTION(H_here_combo), // TYPE "here" #9
#endif

#ifdef LeftComboTapE
    [HC_TYPE_LEFTCOMBO] = COMBO_ACTION(H_Left_combo), // a personally useful 5-8gram!
#endif
#ifdef RightComboTapE
   [HC_TYPE_RIGHTCOMBO] = COMBO_ACTION(H_Right_combo), // a demonstrator, how long autotypes can be!
#endif

#ifdef HD_spc_keys
    [HC_SPC] = COMBO(Hspc_combo, KC_SPC), // SPACE
#endif
#ifdef HD_ent_keys
    [HC_ENT] = COMBO(Hent_combo, KC_ENT), // ENTER
#endif
#ifdef HD_ent2_keys
    [HC_ENT2] = COMBO(Hent2_combo, SK_HENT), // hard-ENTER
#endif

/* These all use SemKeys, even as simple combos (handled by process_semkey from process_record_user) */
#ifdef HD_new_keys
    [HC_NEW] = COMBO(Hnew_combo, SK_NEW),
#endif
#ifdef HD_open_keys
    [HC_OPEN] = COMBO(Hopen_combo, SK_OPEN),
#endif
#ifdef HD_close_keys
   [HC_CLOZ] = COMBO(Hclose_combo, SK_CLOZ),
#endif
#ifdef HD_quit_keys
   [HC_QUIT] = COMBO(Hquit_combo, SK_QUIT),
#endif
#ifdef HD_find_keys
    [HC_FIND] = COMBO_ACTION(Hfind_combo), // application find (in app/doc)
#endif
#ifdef HD_sall_keys
    [HC_SALL] = COMBO(Hsall_combo, SK_SALL),
#endif
#ifdef HD_swrd_keys
    [HC_SWRD] = COMBO(Hswrd_combo, SK_SWRD),
#endif
#ifdef HD_undo_keys
    [HC_UNDO] = COMBO(Hundo_combo, SK_UNDO),
#endif
#ifdef HD_redo_keys
    [HC_REDO] = COMBO(Hredo_combo, SK_REDO),
#endif
#ifdef HD_cut_keys
    [HC_CUT] = COMBO(Hcut_combo, SK_CUT), // also hold copy (no longer used?)
#endif
#ifdef HD_copy_keys
    [HC_COPY] = COMBO_ACTION(Hcopy_combo), // using hold for cut
#endif
#ifdef HD_pstm_keys
    [HC_PSTM] = COMBO(Hpstm_combo, SK_PSTM),  // also hold paste (no longer used?)
#endif
#ifdef HD_pste_keys
    [HC_PSTE] = COMBO_ACTION(Hpste_combo) // using hold for paste-match
#endif

};
