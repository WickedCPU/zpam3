/*
Text items are aligned to left bottom corner of text

ITEM_ALIGN_LEFT:
				Text location
				+
ITEM_ALIGN_CENTER:
	   Text aligned to center
				+
ITEM_ALIGN_RIGHT:
	 Text location
				 +

doubleclick
*/

#define ITEM_TEXT(textstring, x, y, fontsize, txtalign, fontcolor) \
itemDef \
{ \
	rect			x y 0 0 0 0 \
	type			ITEM_TYPE_TEXT \
	visible			1 \
	forecolor		fontcolor \
	text			textstring \
	textfont		UI_FONT_NORMAL \
	textscale		fontsize \
	textalign		txtalign \
	textstyle		ITEM_TEXTSTYLE_SHADOWED \
	decoration \
}

#define ITEM_TEXT_DVAR(textstring, x, y, fontsize, txtalign, fontcolor, dvartotest, dvarshowhide) \
itemDef \
{ \
	rect			x y 0 0 0 0 \
	type			ITEM_TYPE_TEXT \
	visible			1 \
	forecolor		fontcolor \
	text			textstring \
	textfont		UI_FONT_NORMAL \
	textscale		fontsize \
	textalign		txtalign \
	textstyle		ITEM_TEXTSTYLE_SHADOWED \
	dvartest		dvartotest \
	dvarshowhide \
	decoration \
}

#define ITEM_DVAR(cvar, x, y, fontsize, txtalign, fontcolor) \
itemDef \
{ \
	rect			0 0 200 50 0 0 \
	origin			x y \
	type			ITEM_TYPE_TEXT \
	visible			1 \
	forecolor		fontcolor \
	textfont		UI_FONT_NORMAL \
	textscale		fontsize \
	textalign		txtalign \
	textstyle		ITEM_TEXTSTYLE_SHADOWED \
	dvar			cvar \
	decoration \
}

#define ITEM_DVAR_DVAR(cvar, x, y, fontsize, txtalign, fontcolor, dvartotest, dvarshowhide) \
itemDef \
{ \
	rect			0 0 200 50 0 0 \
	origin			x y \
	type			ITEM_TYPE_TEXT \
	visible			1 \
	forecolor		fontcolor \
	textfont		UI_FONT_NORMAL \
	textscale		fontsize \
	textalign		txtalign \
	textstyle		ITEM_TEXTSTYLE_SHADOWED \
	dvar			cvar \
	dvartest		dvartotest \
	dvarshowhide \
	decoration \
}

#define ITEM_BAR_BOTTOM_BUTTON_DVAR(textstring, x, w, dvartotest, dvarshowhide, actions)  \
itemDef \
{ \
	visible			1 \
	rect			0 0 w 24 0 0 \
	origin			x 438 \
	forecolor		GLOBAL_UNFOCUSED_COLOR \
	type			ITEM_TYPE_BUTTON \
	text			textstring \
	textfont		UI_FONT_NORMAL \
	textscale		0.3 \
	textaligny		18 \
	dvartest		dvartotest \
	dvarshowhide \
	action \
	{ \
		play "mouse_click"; \
		actions ; \
	} \
	onFocus \
	{ \
		play "mouse_over"; \
	} \
}

#define ITEM_BAR_BOTTOM_BUTTON_DVAR_DISABLED(textstring, x, w, dvartotest, dvarshowhide)  \
itemDef \
{ \
	visible			1 \
	rect			0 0 w 24 0 0 \
	origin			x 438 \
	forecolor		GLOBAL_DISABLED_COLOR \
	type			ITEM_TYPE_BUTTON \
	text			textstring \
	textfont		UI_FONT_NORMAL \
	textscale		0.3 \
	textaligny		18 \
	dvartest		dvartotest \
	dvarshowhide \
}

#define ITEM_BAR_BOTTOM_BUTTON(textstring, x, w, actions)  \
itemDef \
{ \
	visible			1 \
	rect			0 0 w 24 0 0 \
	origin			x 438 \
	forecolor		GLOBAL_UNFOCUSED_COLOR \
	type			ITEM_TYPE_BUTTON \
	text			textstring \
	textfont		UI_FONT_NORMAL \
	textscale		0.3 \
	textaligny		18 \
	action \
	{ \
		play "mouse_click"; \
		actions ; \
	} \
	onFocus \
	{ \
		play "mouse_over"; \
	} \
}


#define DRAW_MAP_BACKGROUND_IF_BLACKOUT \
itemDef \
{ \
	rect 			-128 0 896 480 0 0 \
	visible 		1 \
	backcolor 		1 1 1 1 \
	style 			WINDOW_STYLE_FILLED \
	background 		"$levelBriefing" \
	dvartest 		"ui_blackout" \
	showDvar		{ "1" } \
	decoration \
}

//0.149 .227 0.294 .5
#define DRAW_BLUISH_BACKGROUND \
itemDef \
{ \
	style			WINDOW_STYLE_FILLED \
	rect			0 0 640 480 HORIZONTAL_ALIGN_FULLSCREEN VERTICAL_ALIGN_FULLSCREEN \
	backcolor		0.083 .129 0.168 .5 \
	visible			1 \
	decoration \
}

#define	DRAW_GRADIENT_LEFT_TO_RIGHT \
itemDef \
{ \
	style			WINDOW_STYLE_SHADER \
	rect			-128 0 896 480 HORIZONTAL_ALIGN_FULLSCREEN VERTICAL_ALIGN_FULLSCREEN \
	background		"gradient" \
	visible			1 \
	decoration \
}

#define	DRAW_GRADIENT_FOR_SUBMENU(x, y, w, h, alpha) \
itemDef \
{ \
	style			WINDOW_STYLE_FILLED \
	rect			x y w h 0 0 \
	backcolor		0 0 0 alpha \
	visible			1 \
	decoration \
} \
itemDef  \
{ \
	style			WINDOW_STYLE_FILLED \
	rect			x y 1 h 0 0 \
	backcolor		.631 .666 .698 .2 \
	visible			1 \
	decoration \
} \

#define DRAW_BARS \
itemDef  \
{ \
	style			WINDOW_STYLE_FILLED \
	rect			-128 0 896 60 0 0 \
	backcolor		0.0045 .005 0.0053 .95 \
	visible			1 \
	decoration \
} \
itemDef  \
{ \
	style			WINDOW_STYLE_FILLED \
	rect			-128 435 896 45 0 0 \
	backcolor		0.0045 .005 0.0053 .95 \
	visible			1 \
	decoration \
} \
itemDef  \
{ \
	style			WINDOW_STYLE_FILLED \
	rect			-128 60 896 1 0 0 \
	backcolor		.631 .666 .698 .2 \
	visible			1 \
	decoration \
} \
itemDef  \
{ \
	style			WINDOW_STYLE_FILLED \
	rect			-128 435 896 1 0 0 \
	backcolor		.631 .666 .698 .2 \
	visible			1 \
	decoration \
}

#define ITEM_TEXT_HEADING(teamname) \
itemDef \
{ \
	type			ITEM_TYPE_TEXT \
	visible			1 \
	origin			40 60 \
	forecolor		1 1 1 1 \
	text			teamname \
	textfont		UI_FONT_NORMAL \
	textscale		GLOBAL_HEADER_SIZE \
	decoration \
}




#define ORIGIN_CHOICE1	60 84
#define ORIGIN_CHOICE2	60 108
#define ORIGIN_CHOICE3	60 132
#define ORIGIN_CHOICE4	60 156
#define ORIGIN_CHOICE5	60 180
#define ORIGIN_CHOICE6	60 204
#define ORIGIN_CHOICE7	60 228
#define ORIGIN_CHOICE8	60 252
#define ORIGIN_CHOICE9	60 276
#define ORIGIN_CHOICE10	60 300
#define ORIGIN_CHOICE11	60 324
#define ORIGIN_CHOICE12	60 348
#define ORIGIN_CHOICE13	60 372

#define ITEM_BUTTON(origin_choice, textstring, dofocus, doaction) \
itemDef  \
{ \
	visible			1 \
	rect			0 0 128 24 0 0 \
	origin			origin_choice \
	forecolor		GLOBAL_UNFOCUSED_COLOR \
	type			ITEM_TYPE_BUTTON \
	text			textstring \
	textfont		UI_FONT_NORMAL \
	textscale		GLOBAL_TEXT_SIZE \
	textstyle		ITEM_TEXTSTYLE_SHADOWED \
	textaligny		20 \
	action \
	{ \
		play "mouse_click"; \
		doaction; \
	} \
	onFocus \
	{ \
		play "mouse_over"; \
		dofocus; \
	} \
}


#define ITEM_BUTTON_ONDVAR(origin_choice, textstring, dvarstring, dvarvisible, dofocus, doaction) \
itemDef  \
{ \
	visible			1 \
	rect			0 0 128 24 0 0 \
	origin			origin_choice \
	forecolor		GLOBAL_UNFOCUSED_COLOR \
	type			ITEM_TYPE_BUTTON \
	text			textstring \
	textfont		UI_FONT_NORMAL \
	textscale		GLOBAL_TEXT_SIZE \
	textstyle		ITEM_TEXTSTYLE_SHADOWED \
	textaligny		20 \
	dvartest		dvarstring \
	dvarvisible \
	action \
	{ \
		play "mouse_click"; \
		doaction; \
	} \
	onFocus \
	{ \
		play "mouse_over"; \
		dofocus; \
	} \
}

#define ITEM_BUTTON_ONDVAR_DISABLED(origin_choice, textstring, dvarstring, dvarvisible, dofocus) \
itemDef  \
{ \
	visible			1 \
	rect			0 0 128 24 0 0 \
	origin			origin_choice \
	forecolor		GLOBAL_DISABLED_COLOR \
	type			ITEM_TYPE_BUTTON \
	text			textstring \
	textfont		UI_FONT_NORMAL \
	textscale		GLOBAL_TEXT_SIZE \
	textstyle		ITEM_TEXTSTYLE_SHADOWED \
	textaligny		20 \
	dvartest		dvarstring \
	dvarvisible \
	onFocus \
	{ \
		play "mouse_over"; \
		dofocus; \
	} \
	decoration \
}






#define ORIGIN_WEAPONIMAGE			310 110
#define ORIGIN_GRENADESLOT1			310 170
#define ORIGIN_GRENADESLOT2			330 170
#define ORIGIN_USEDBY						310 250
#define ORIGIN_USEDBY2					302 263

#define ITEM_WEAPON_SMOKE(originpos, stringname, stringtext, cvartext, weaponimage, focusaction, doaction, grenadeimage, class_usedby) \
ITEM_WEAPON(originpos, stringname, stringtext, cvartext, weaponimage, focusaction, doaction, grenadeimage, class_usedby) \
itemDef \
{ \
	name			weaponimage \
	visible 		0 \
	rect			0 0 32 32 0 0 \
	origin			ORIGIN_GRENADESLOT2 \
	style			WINDOW_STYLE_SHADER \
	background		"hud_us_smokegrenade_C" \
	decoration \
}

#define ITEM_WEAPON(originpos, stringname, stringtext, cvartext, weaponimage, focusaction, doaction, grenadeimage, class_usedby) \
itemDef \
{ \
	name			stringname \
	visible			1 \
	rect			0 0 128 24 0 0 \
	origin			originpos \
	forecolor		GLOBAL_UNFOCUSED_COLOR \
	type			ITEM_TYPE_BUTTON \
	text			stringtext \
	textfont		UI_FONT_NORMAL \
	textscale		GLOBAL_TEXT_SIZE \
	textstyle		ITEM_TEXTSTYLE_SHADOWED \
	textaligny		20 \
	dvartest		cvartext \
	showDvar		{ "1" } \
	action \
	{ \
		play "mouse_click"; \
		doaction \
	} \
	onFocus \
	{ \
		HIDE_ALL \
		play "mouse_over"; \
		focusaction \
	} \
} \
itemDef  \
{ \
	name			stringname \
	visible			1 \
	rect			0 0 128 24 0 0 \
	origin			originpos \
	forecolor		GLOBAL_DISABLED_COLOR \
	type			ITEM_TYPE_BUTTON \
	text			"" \
	textfont		UI_FONT_NORMAL \
	textscale		GLOBAL_TEXT_SIZE \
	textstyle		ITEM_TEXTSTYLE_SHADOWED \
	textaligny		20 \
	dvartest		cvartext \
	showDvar		{ "2" } \
	onFocus \
	{ \
		HIDE_ALL \
		focusaction \
	} \
} \
itemDef  \
{ \
	name			stringname \
	visible			1 \
	rect			0 0 128 24 0 0 \
	origin			originpos \
	forecolor		GLOBAL_DISABLED_COLOR \
	type			ITEM_TYPE_BUTTON \
	text			stringtext \
	textfont		UI_FONT_NORMAL \
	textscale		GLOBAL_TEXT_SIZE \
	textstyle		ITEM_TEXTSTYLE_SHADOWED \
	textaligny		20 \
	dvartest		cvartext \
	showDvar		{ "2" } \
	decoration \
} \
 \
itemDef  \
{ \
	name			stringname \
	visible			1 \
	rect			0 0 128 24 0 0 \
	origin			originpos \
	forecolor		.95 .84 .7 1  \
	type			ITEM_TYPE_BUTTON \
	text			stringtext \
	textfont		UI_FONT_NORMAL \
	textscale		GLOBAL_TEXT_SIZE \
	textstyle		ITEM_TEXTSTYLE_SHADOWED \
	textaligny		20 \
	dvartest		cvartext \
	showDvar		{ "3" } \
	action \
	{ \
		play "mouse_click"; \
		doaction \
	} \
	onFocus \
	{ \
		HIDE_ALL \
		play "mouse_over"; \
		focusaction \
	} \
} \
 \
itemDef \
{ \
	name			weaponimage \
	visible 		0 \
	rect			0 0 224 112 0 0 \
	origin			ORIGIN_WEAPONIMAGE \
	style			WINDOW_STYLE_SHADER \
	background		weaponimage \
	decoration \
} \
itemDef \
{ \
	name			weaponimage \
	visible 		0 \
	rect			0 0 32 32 0 0 \
	origin			ORIGIN_GRENADESLOT1 \
	style			WINDOW_STYLE_SHADER \
	background		"gfx/icons/hud@" grenadeimage ".tga" \
	decoration \
} \
itemDef  \
{ \
	name			weaponimage \
	visible			0 \
	origin			ORIGIN_USEDBY \
	forecolor		GLOBAL_UNFOCUSED_COLOR \
	text 			"Used by:" \
	type			ITEM_TYPE_TEXT \
	textfont		UI_FONT_NORMAL \
	textscale		0.3 \
	textstyle		ITEM_TEXTSTYLE_SHADOWED \
	textalign		ITEM_ALIGN_LEFT \
	dvartest		"ui_weapons_" class_usedby "_usedby" \
	hideDvar		{ "" } \
	decoration \
} \
itemDef  \
{ \
	name			weaponimage \
	visible			0 \
	origin			ORIGIN_USEDBY2 \
	forecolor		GLOBAL_UNFOCUSED_COLOR \
	text 			" " \
	type			ITEM_TYPE_EDITFIELD \
	textfont		UI_FONT_NORMAL \
	textscale		0.25 \
	textstyle		ITEM_TEXTSTYLE_SHADOWED \
	textalign		ITEM_ALIGN_LEFT \
	dvar			"ui_weapons_" class_usedby "_usedby"  \
	dvartest		"ui_weapons_" class_usedby "_usedby" \
	hideDvar		{ "" } \
	decoration \
}







#define SERVERINFO_DRAW_OBJECTIVE(objectivetext) \
itemDef \
{ \
	visible			1 \
	rect			0 0 480 75 0 0 \
	origin			60 84 \
	forecolor		1 1 1 1 \
	autowrapped \
	text			objectivetext \
	textfont		UI_FONT_NORMAL \
	textscale		0.3 \
	textstyle		ITEM_TEXTSTYLE_SHADOWED \
	textaligny		16 \
	decoration \
}

#define SERVERINFO_DRAW_PARAMETERS \
itemDef \
{ \
	visible			1 \
	rect			0 0 180 110 0 0 \
	origin			170 180 \
	forecolor		GLOBAL_UNFOCUSED_COLOR \
	dvar			"ui_serverinfo_left1" \
	textfont		UI_FONT_NORMAL \
	textscale		0.3 \
	textstyle		ITEM_TEXTSTYLE_SHADOWED \
	textalign		ITEM_ALIGN_RIGHT \
	autowrapped \
	decoration \
} \
itemDef  \
{ \
	visible			1 \
	rect			0 0 128 110 0 0 \
	origin			185 180 \
	forecolor		GLOBAL_UNFOCUSED_COLOR \
	dvar			"ui_serverinfo_left2" \
	textfont		UI_FONT_NORMAL \
	textscale		0.3 \
	textstyle		ITEM_TEXTSTYLE_SHADOWED \
	textalign		ITEM_ALIGN_LEFT \
	autowrapped \
	decoration \
} \
itemDef \
{ \
	visible			1 \
	rect			0 0 180 110 0 0 \
	origin			390 180 \
	forecolor		GLOBAL_UNFOCUSED_COLOR \
	dvar			"ui_serverinfo_right1" \
	textfont		UI_FONT_NORMAL \
	textscale		0.3 \
	textstyle		ITEM_TEXTSTYLE_SHADOWED \
	textalign		ITEM_ALIGN_RIGHT \
	autowrapped \
	decoration \
} \
itemDef  \
{ \
	visible			1 \
	rect			0 0 128 110 0 0 \
	origin			405 180 \
	forecolor		GLOBAL_UNFOCUSED_COLOR \
	dvar			"ui_serverinfo_right2" \
	textfont		UI_FONT_NORMAL \
	textscale		0.3 \
	textstyle		ITEM_TEXTSTYLE_SHADOWED \
	textalign		ITEM_ALIGN_LEFT \
	autowrapped \
	decoration \
}

#define SERVERINFO_DRAW_MOTD \
itemDef \
{ \
	name			"text_motd" \
	visible			1 \
	rect			0 0 480 130 0 0 \
	origin			60 305 \
	forecolor		1 1 1 1 \
	autowrapped \
	dvar			"ui_motd" \
	textfont		UI_FONT_NORMAL \
	textscale		0.3 \
	textstyle		ITEM_TEXTSTYLE_SHADOWED \
	textaligny		16 \
	decoration \
} \
itemDef \
{ \
	name			"text_serverversion" \
	visible			1 \
	rect			0 0 480 130 0 0 \
	origin			60 410 \
	forecolor		1 1 1 .4 \
	dvar			"ui_serverversion" \
	textfont		UI_FONT_NORMAL \
	textscale		0.2 \
	textstyle		ITEM_TEXTSTYLE_SHADOWED \
	textaligny		16 \
	decoration \
}

#define SERVERINFO_DRAW_QUIT \
itemDef \
{ \
	visible 		1 \
	rect			-128 60 896 375 0 0  \
	type 			ITEM_TYPE_BUTTON \
	action \
	{ \
		scriptMenuResponse "close"; \
	} \
}


#define RCON_UPDATE_STATUS execOnDvarStringValue ui_rcon_logged_in 0 "vstr ui_rcon_hash";




#define QUICKMESSAGE_LINE_TEXT(y, textstring, fontcolor)  \
itemDef \
{ \
	name			"window" \
	visible			1 \
	rect			16 y 0 0 0 0 \
	origin			ORIGIN_QUICKMESSAGEWINDOW \
	forecolor		fontcolor \
	textfont		UI_FONT_NORMAL \
	textscale		.24 \
	textaligny		8 \
	textstyle ITEM_TEXTSTYLE_SHADOWED \
	text			textstring \
	decoration \
}

#define QUICKMESSAGE_LINE_TEXT_DVAR(y, textstring, fontcolor, dvarstring, dvarvisible)  \
itemDef \
{ \
	name			"window" \
	visible			1 \
	rect			16 y 0 0 0 0 \
	origin			ORIGIN_QUICKMESSAGEWINDOW \
	forecolor		fontcolor \
	textfont		UI_FONT_NORMAL \
	textscale		.24 \
	textaligny		8 \
	textstyle ITEM_TEXTSTYLE_SHADOWED \
	text			textstring \
	dvartest		dvarstring \
	dvarvisible \
	decoration \
}


#define DVAR_CHECK(textstring, dvartotest, dvarshowhide) \
itemDef \
{ \
	rect 			-128 0 896 480 0 0 \
	visible 		1 \
	backcolor 		1 1 1 1 \
	style 			WINDOW_STYLE_FILLED \
	background 		"$levelBriefing" \
	dvartest		dvartotest \
	dvarshowhide \
	decoration \
} \
itemDef \
{ \
	rect			0 0 200 50 0 0 \
	origin			320 100 \
	type			ITEM_TYPE_TEXT \
	text			textstring \
	visible			1 \
	forecolor		1 0 0 1 \
	textfont		UI_FONT_NORMAL \
	textscale		0.6 \
	textalign		ITEM_ALIGN_CENTER \
	textstyle		ITEM_TEXTSTYLE_SHADOWED \
	dvartest		dvartotest \
	dvarshowhide \
	decoration \
}


#define MATCHINFO_BGCOLOR(xywh, bc, cvartest, showhidedvar) \
itemDef \
{ \
  style			WINDOW_STYLE_FILLED \
  rect			xywh 0 0 \
  backcolor		bc \
  visible		1 \
  dvartest		cvartest \
  showhidedvar \
  decoration \
}

#define MATCHINFO_ICON(xy, bg, cvartest, showhidedvar) \
itemDef \
{ \
	style		WINDOW_STYLE_FILLED \
	rect		xy 12 12 0 0 \
	backcolor	1 1 1 1 \
	visible		1 \
	background	bg \
	dvartest	cvartest \
        showhidedvar \
	decoration \
}






#define SPECTATINGSYSTEM_COLOR_BLUE 0.16 0.28 0.74 .9
#define SPECTATINGSYSTEM_COLOR_RED 0.5 0 0 .9
#define SPECTATINGSYSTEM_COLOR_HIGHLIGHT .9 .9 .9 1
#define SPECTATINGSYSTEM_COLOR_BG .0 .0 .0 .9
#define SPECTATINGSYSTEM_COLOR_BG_DEAD .0 .0 .0 .5

#define ITEM_SPECTATINGSYSTEM_LINE(cvarprefix, x_offset, y_offset, horizontal_align) \
itemDef \
{ \
	style		WINDOW_STYLE_FILLED \
	rect		x_offset y_offset 130 25 horizontal_align 0 \
	origin		-1 -1 \
	backcolor	SPECTATINGSYSTEM_COLOR_HIGHLIGHT \
	visible		1 \
	dvartest	cvarprefix "_health" \
	showDvar	{ "0_";  "10_blue_";"10_red_";  "50_blue_";"50_red_";  "80_blue_"; "80_red_";  "100_blue_";"100_red_" } \
	decoration \
} \
itemDef \
{ \
	style		WINDOW_STYLE_FILLED \
	rect		x_offset y_offset 128 23 horizontal_align 0 \
	backcolor	SPECTATINGSYSTEM_COLOR_BG \
	visible		1 \
	dvartest	cvarprefix "_health" \
	hideDvar	{ ""; "0"; "0_" } \
	decoration \
} \
itemDef \
{ \
	style		WINDOW_STYLE_FILLED \
	rect		x_offset y_offset 128 23 horizontal_align 0 \
	backcolor	SPECTATINGSYSTEM_COLOR_BG_DEAD \
	visible		1 \
	dvartest	cvarprefix "_health" \
	showDvar	{ "0"; "0_" } \
	decoration \
} \
\
itemDef \
{ \
	style		WINDOW_STYLE_FILLED \
	rect		x_offset y_offset 128 12 horizontal_align 0 \
	backcolor	SPECTATINGSYSTEM_COLOR_BLUE \
	visible		1 \
	dvartest	cvarprefix "_health" \
	showDvar	{ "100_blue"; "100_blue_" } \
	decoration \
} \
itemDef \
{ \
	style		WINDOW_STYLE_FILLED \
	rect		x_offset y_offset 128 12 horizontal_align 0 \
	backcolor	SPECTATINGSYSTEM_COLOR_RED \
	visible		1 \
	dvartest	cvarprefix "_health" \
	showDvar	{ "100_red"; "100_red_" } \
	decoration \
} \
\
\
itemDef \
{ \
	style		WINDOW_STYLE_FILLED \
	rect		x_offset y_offset 104 12 horizontal_align 0 \
	backcolor	SPECTATINGSYSTEM_COLOR_BLUE \
	visible		1 \
	dvartest	cvarprefix "_health" \
	showDvar	{ "80_blue"; "80_blue_" } \
	decoration \
} \
itemDef \
{ \
	style		WINDOW_STYLE_FILLED \
	rect		x_offset y_offset 104 12 horizontal_align 0 \
	backcolor	SPECTATINGSYSTEM_COLOR_RED \
	visible		1 \
	dvartest	cvarprefix "_health" \
	showDvar	{ "80_red"; "80_red_" } \
	decoration \
} \
\
\
itemDef \
{ \
	style		WINDOW_STYLE_FILLED \
	rect		x_offset y_offset 65 12 horizontal_align 0 \
	backcolor	SPECTATINGSYSTEM_COLOR_BLUE \
	visible		1 \
	dvartest	cvarprefix "_health" \
	showDvar	{ "50_blue"; "50_blue_" } \
	decoration \
} \
itemDef \
{ \
	style		WINDOW_STYLE_FILLED \
	rect		x_offset y_offset 65 12 horizontal_align 0 \
	backcolor	SPECTATINGSYSTEM_COLOR_RED \
	visible		1 \
	dvartest	cvarprefix "_health" \
	showDvar	{ "50_red"; "50_red_" } \
	decoration \
} \
\
\
itemDef \
{ \
	style		WINDOW_STYLE_FILLED \
	rect		x_offset y_offset 10 12 horizontal_align 0 \
	backcolor	SPECTATINGSYSTEM_COLOR_BLUE \
	visible		1 \
	dvartest	cvarprefix "_health" \
	showDvar	{ "10_blue"; "10_blue_" } \
	decoration \
} \
itemDef \
{ \
	style		WINDOW_STYLE_FILLED \
	rect		x_offset y_offset 10 12 horizontal_align 0 \
	backcolor	SPECTATINGSYSTEM_COLOR_RED \
	visible		1 \
	dvartest	cvarprefix "_health" \
	showDvar	{ "10_red"; "10_red_" } \
	decoration \
} \
\
\
itemDef \
{ \
	style		WINDOW_STYLE_FILLED \
	rect		x_offset y_offset 10 9 horizontal_align 0 \
	backcolor	1 1 1 .5 \
	origin		116 13 \
	visible		1 \
	background	"gfx/icons/hud@us_grenade.tga" \
	dvartest	cvarprefix "_icons" \
	showDvar	{ "grenade"; "grenade_smoke"; "grenade2_smoke"; "grenade2"; } \
	decoration \
} \
itemDef \
{ \
	style		WINDOW_STYLE_FILLED \
	rect		x_offset y_offset 10 9 horizontal_align 0 \
	backcolor	1 1 1 .5 \
	origin		113 13 \
	visible		1 \
	background	"gfx/icons/hud@us_grenade.tga" \
	dvartest	cvarprefix "_icons" \
	showDvar	{ "grenade2"; "grenade2_smoke"; } \
	decoration \
} \
itemDef \
{ \
	style		WINDOW_STYLE_FILLED \
	rect		x_offset y_offset 10 9 horizontal_align 0 \
	backcolor	1 1 1 .5 \
	origin		107 13 \
	visible		1 \
	background	"hud_us_smokegrenade" \
	dvartest	cvarprefix "_icons" \
	showDvar	{ "smoke"; "grenade_smoke"; "grenade2_smoke";  } \
	decoration \
} \
itemDef \
{ \
	style		WINDOW_STYLE_FILLED \
	rect		x_offset y_offset 15 15 horizontal_align 0 \
	backcolor	1 1 1 .5 \
	origin		112 4 \
	visible		1 \
	background	"gfx/hud/death_suicide.tga" \
	dvartest	cvarprefix "_health" \
	showDvar	{ "0"; "0_";  } \
	decoration \
} \
itemDef \
{ \
	style		WINDOW_STYLE_FILLED \
	rect		x_offset y_offset 12 10 horizontal_align 0 \
	origin		132 3 \
	backcolor	1 1 1 .9 \
	visible		1 \
	background	"ui/assets/scrollbar_arrow_left.tga" \
	dvartest	cvarprefix "_health" \
	showDvar	{ "0_";  "10_blue_";"10_red_";  "50_blue_";"50_red_";  "80_blue_"; "80_red_";  "100_blue_";"100_red_" } \
	decoration \
} \
itemDef \
{ \
	style		WINDOW_STYLE_FILLED \
	rect		x_offset y_offset 12 10 horizontal_align 0 \
	origin		-14 3 \
	backcolor	1 1 1 .9 \
	visible		1 \
	background	"ui/assets/scrollbar_arrow_right.tga" \
	dvartest	cvarprefix "_health" \
	showDvar	{ "0_";  "10_blue_";"10_red_";  "50_blue_";"50_red_";  "80_blue_"; "80_red_";  "100_blue_";"100_red_" } \
	decoration \
} \
itemDef \
{ \
	rect			x_offset y_offset 0 0 horizontal_align 0 \
	origin			5 0 \
	type			ITEM_TYPE_TEXT \
	visible			1 \
	forecolor		1 1 1 1 \
	textfont		UI_FONT_NORMAL \
	textscale		.18 \
	textalign		ITEM_ALIGN_LEFT \
	textaligny		11 \
	textstyle		ITEM_TEXTSTYLE_SHADOWED \
	dvar			cvarprefix "_text" \
	dvartest		cvarprefix "_health" \
	hideDvar		{ ""; "0"; "0_" } \
	decoration \
} \
itemDef \
{ \
	rect			x_offset y_offset 0 0 horizontal_align 0 \
	origin			5 0 \
	type			ITEM_TYPE_TEXT \
	visible			1 \
	forecolor		1 1 1 .5 \
	textfont		UI_FONT_NORMAL \
	textscale		.18 \
	textalign		ITEM_ALIGN_LEFT \
	textaligny		11 \
	textstyle		ITEM_TEXTSTYLE_SHADOWED \
	dvar			cvarprefix "_text" \
	dvartest		cvarprefix "_health" \
	showDvar		{ "0"; "0_" } \
	decoration \
} \
itemDef \
{ \
	rect			x_offset y_offset 0 0 horizontal_align 0 \
	origin			5 10 \
	type			ITEM_TYPE_TEXT \
	visible			1 \
	forecolor		1 1 1 .8 \
	textfont		UI_FONT_NORMAL \
	textscale		.16 \
	textalign		ITEM_ALIGN_LEFT \
	textaligny		12 \
	textstyle		ITEM_TEXTSTYLE_SHADOWED \
	dvar			cvarprefix "_info" \
	dvartest		cvarprefix "_health" \
	hideDvar		{ ""; "0"; "0_" } \
	decoration \
} \
itemDef \
{ \
	rect			x_offset y_offset 0 0 horizontal_align 0 \
	origin			5 10 \
	type			ITEM_TYPE_TEXT \
	visible			1 \
	forecolor		1 1 1 .5 \
	textfont		UI_FONT_NORMAL \
	textscale		.16 \
	textalign		ITEM_ALIGN_LEFT \
	textaligny		12 \
	textstyle		ITEM_TEXTSTYLE_SHADOWED \
	dvar			cvarprefix "_info" \
	dvartest		cvarprefix "_health" \
	showDvar		{ "0"; "0_" } \
	decoration \
}



#define ITEM_SPECTATINGSYSTEM_KEY(textstring, x, y, fontSize, horizontal_align, cvar) \
itemDef \
{ \
	visible			1 \
	rect			0 0 1 1 horizontal_align 0 \
	origin			x y \
	forecolor		GLOBAL_UNFOCUSED_COLOR \
	type			ITEM_TYPE_TEXT \
	text			textstring \
	textfont		UI_FONT_NORMAL \
	textscale		fontSize \
	dvartest		cvar \
	showDvar		{ "1"; } \
	decoration \
}


#define ITEM_SPECTATINGSYSTEM_DVAR(x, y, fontsize, cvar, horizontal_align) \
itemDef \
{ \
	visible			1 \
	rect			0 0 0 0 horizontal_align 0 \
	origin			x y \
	forecolor		GLOBAL_UNFOCUSED_COLOR \
	type			ITEM_TYPE_TEXT \
	textfont		UI_FONT_NORMAL \
	textscale		fontsize \
	textstyle		ITEM_TEXTSTYLE_SHADOWED \
	dvar			cvar \
	decoration \
}






#define SCOREBOARD_TEXT_ALIGNY 10
#define SCOREBOARD_HEADING_ALIGNY 25

// Text headings of columns
#define SCOREBOARD_SCORE_TEXT_X 174
#define SCOREBOARD_KILLS_TEXT_X 210
#define SCOREBOARD_DEATHS_TEXT_X 228
#define SCOREBOARD_ASSISTS_TEXT_X 264
#define SCOREBOARD_DAMAGE_TEXT_X 294
#define SCOREBOARD_GRENADES_TEXT_X 324
#define SCOREBOARD_PLANTS_TEXT_X 354
#define SCOREBOARD_DEFUSES_TEXT_X 388
#define SCOREBOARD_DEFUSES_TEXT_X_LINE 384	// last one is aligned right

// Columns
#define SCOREBOARD_HEADING_X 15
#define SCOREBOARD_NAME_X 33

#define SCOREBOARD_SCORE_X 167
#define SCOREBOARD_KILLS_X 209
#define SCOREBOARD_DEATHS_X 226
#define SCOREBOARD_ASSISTS_X 262
#define SCOREBOARD_DAMAGE_X 288
#define SCOREBOARD_GRENADES_X 322
#define SCOREBOARD_PLANTS_X 352
#define SCOREBOARD_DEFUSES_X 382
#define SCOREBOARD_PING_X 420



#define SCOREBOARD_LINE_1_Y  30
#define SCOREBOARD_LINE_2_Y  40
#define SCOREBOARD_LINE_3_Y  50
#define SCOREBOARD_LINE_4_Y  59
#define SCOREBOARD_LINE_5_Y  69
#define SCOREBOARD_LINE_6_Y  79
#define SCOREBOARD_LINE_7_Y  88
#define SCOREBOARD_LINE_8_Y  98
#define SCOREBOARD_LINE_9_Y  108
#define SCOREBOARD_LINE_10_Y 117
#define SCOREBOARD_LINE_11_Y 127
#define SCOREBOARD_LINE_12_Y 137
#define SCOREBOARD_LINE_13_Y 146
#define SCOREBOARD_LINE_14_Y 156
#define SCOREBOARD_LINE_15_Y 166
#define SCOREBOARD_LINE_16_Y 175
#define SCOREBOARD_LINE_17_Y 185
#define SCOREBOARD_LINE_18_Y 195
#define SCOREBOARD_LINE_19_Y 204
#define SCOREBOARD_LINE_20_Y 214
#define SCOREBOARD_LINE_21_Y 224
#define SCOREBOARD_LINE_22_Y 233
#define SCOREBOARD_LINE_23_Y 243
#define SCOREBOARD_LINE_24_Y 253
#define SCOREBOARD_LINE_25_Y 263
#define SCOREBOARD_LINE_26_Y 273

#define SCOREBOARD_LINE_BACKGROUND_COLOR 			            .0 .0 .0 .1
#define SCOREBOARD_LINE_BACKGROUND_COLOR_HIGHLIGHTED 			.2 .2 .2 .7

/*
type
0 = nothink
1 = player line - odd
2 = player line - even
3 = player line - highlighted

added _ means that line can be clicked

*/

#define ITEM_SCOREBOARD_LINE(line_id, x, y, y_offset) \
itemDef  \
{ \
	style			WINDOW_STYLE_FILLED \
	rect			10 y_offset 380 10 0 0 \
	origin			x y \
	backcolor		SCOREBOARD_LINE_BACKGROUND_COLOR \
	visible			1 \
	dvartest		"ui_scoreboard_line_" line_id \
	showDvar		{ "2";"2_" } \
	decoration \
} \
itemDef  \
{ \
	style			WINDOW_STYLE_FILLED \
	rect			10 y_offset 380 10 0 0 \
	origin			x y \
	backcolor		SCOREBOARD_LINE_BACKGROUND_COLOR_HIGHLIGHTED \
	visible			1 \
	dvartest		"ui_scoreboard_line_" line_id \
	showDvar		{ "3";"3_" } \
	decoration \
}		 \
itemDef \
{ \
	rect			SCOREBOARD_HEADING_X y_offset 1 1 0 0 \
	origin			x y \
	dvar 			"ui_scoreboard_line_" line_id \
	textfont		UI_FONT_BIG \
	textscale		0.32 \
	textstyle		ITEM_TEXTSTYLE_SHADOWED \
	textaligny		SCOREBOARD_HEADING_ALIGNY \
	visible			1 \
	dvartest		"ui_scoreboard_line_" line_id \
	hideDvar		{ ""; "0"; "1"; "2"; "3"; "0_"; "1_"; "2_"; "3_"; } \
	decoration \
} \
\
itemDef  \
{ \
	style			WINDOW_STYLE_FILLED \
	rect			10 y_offset 16 10 0 0 \
        origin			x y \
	backcolor		0 0 0 0.7 \
	visible			1 \
	dvartest		"ui_scoreboard_line_" line_id \
        showDvar		{ "0_"; "1_"; "2_"; "3_"; } \
	decoration \
}  \
itemDef \
{ \
	rect			0 y_offset 390 10 0 0 \
        origin			x y \
	type			ITEM_TYPE_BUTTON \
	visible			1 \
	forecolor		1 1 1 1 \
	text			"Set" \
	textfont		UI_FONT_NORMAL \
	textscale		0.18 \
	textalign		ITEM_ALIGN_LEFT \
	textalignx		13 \
	textaligny		8 \
	textstyle		ITEM_TEXTSTYLE_SHADOWED \
	dvartest		"ui_scoreboard_line_" line_id \
        showDvar		{ "0_"; "1_"; "2_"; "3_"; } \
	action \
	{ \
		play "mouse_click"; \
		exec "openscriptmenu ingame scoreboard_setPlayer" line_id \
	} \
	onFocus \
	{ \
		play "mouse_over"; \
	} \
}

#define ITEM_SCOREBOARD_HEADING(x, y, textstring, x_offset, y_offset, fontsize, txtalign, line_x, line_y, line_height) \
itemDef \
{ \
	rect			x_offset y_offset 1 1 0 0 \
	origin			x y \
	type			ITEM_TYPE_TEXT \
	visible			1 \
	forecolor		1 1 1 1 \
	text			textstring \
	textfont		UI_FONT_NORMAL \
	textscale		fontsize \
	textalign		txtalign \
	textstyle		ITEM_TEXTSTYLE_SHADOWED \
	dvartest		"ui_scoreboard_visible" \
	showDvar		{ "1"; } \
	decoration \
}  \
itemDef \
{ \
	style			WINDOW_STYLE_FILLED \
	rect			line_x line_y 0.75 line_height 0 0 \
        origin			x y \
	backcolor		1 1 1 .1 \
	visible			1 \
	dvartest		"ui_scoreboard_visible" \
	showDvar		{ "1"; } \
	decoration \
}


#define ITEM_SCOREBOARD_COLUMN(x, y, cvar, x_offset, y_offset, fontsize, txtalign) \
itemDef \
{ \
	rect			x_offset y_offset 200 50 0 0 \
	origin			x y \
	type			ITEM_TYPE_TEXT \
	visible			1 \
	forecolor		1 1 1 1 \
	textfont		UI_FONT_NORMAL \
	textscale		fontsize \
	textalign		txtalign \
	textstyle		ITEM_TEXTSTYLE_SHADOWED \
	dvar			cvar \
	decoration \
}


#define ITEM_SCOREBOARD(x, y) \
\
	ITEM_SCOREBOARD_HEADING(x, y, "Score",    SCOREBOARD_SCORE_TEXT_X,   	23, .21, ITEM_ALIGN_CENTER, 	SCOREBOARD_SCORE_TEXT_X, 	25, 	30) \
	ITEM_SCOREBOARD_HEADING(x, y, "Kills",    SCOREBOARD_KILLS_TEXT_X,   	23, .21, ITEM_ALIGN_CENTER, 	SCOREBOARD_KILLS_TEXT_X, 	25, 	30) \
	ITEM_SCOREBOARD_HEADING(x, y, "Deaths",   SCOREBOARD_DEATHS_TEXT_X,  	33, .21, ITEM_ALIGN_CENTER, 	SCOREBOARD_DEATHS_TEXT_X, 	35, 	20) \
	ITEM_SCOREBOARD_HEADING(x, y, "Assists",  SCOREBOARD_ASSISTS_TEXT_X, 	23, .21, ITEM_ALIGN_CENTER, 	SCOREBOARD_ASSISTS_TEXT_X, 	25, 	30) \
	ITEM_SCOREBOARD_HEADING(x, y, "Hits",     SCOREBOARD_DAMAGE_TEXT_X,  	33, .21, ITEM_ALIGN_CENTER, 	SCOREBOARD_DAMAGE_TEXT_X, 	35, 	20) \
	ITEM_SCOREBOARD_HEADING(x, y, "Grenades", SCOREBOARD_GRENADES_TEXT_X,	23, .21, ITEM_ALIGN_CENTER, 	SCOREBOARD_GRENADES_TEXT_X, 	25, 	30) \
	ITEM_SCOREBOARD_HEADING(x, y, "Plants",   SCOREBOARD_PLANTS_TEXT_X,  	33, .21, ITEM_ALIGN_CENTER, 	SCOREBOARD_PLANTS_TEXT_X, 	35, 	20) \
	ITEM_SCOREBOARD_HEADING(x, y, "Defuses",  SCOREBOARD_DEFUSES_TEXT_X, 	23, .21, ITEM_ALIGN_RIGHT,  	SCOREBOARD_DEFUSES_TEXT_X_LINE, 25, 	30) \
\
	ITEM_SCOREBOARD_LINE("1", x, y, SCOREBOARD_LINE_1_Y) \
\
	ITEM_SCOREBOARD_LINE("4", x, y, SCOREBOARD_LINE_4_Y) \
	ITEM_SCOREBOARD_LINE("5", x, y, SCOREBOARD_LINE_5_Y) \
	ITEM_SCOREBOARD_LINE("6", x, y, SCOREBOARD_LINE_6_Y) \
	ITEM_SCOREBOARD_LINE("7", x, y, SCOREBOARD_LINE_7_Y) \
	ITEM_SCOREBOARD_LINE("8", x, y, SCOREBOARD_LINE_8_Y) \
	ITEM_SCOREBOARD_LINE("9", x, y, SCOREBOARD_LINE_9_Y) \
	ITEM_SCOREBOARD_LINE("10", x, y, SCOREBOARD_LINE_10_Y) \
	ITEM_SCOREBOARD_LINE("11", x, y, SCOREBOARD_LINE_11_Y) \
	ITEM_SCOREBOARD_LINE("12", x, y, SCOREBOARD_LINE_12_Y) \
	ITEM_SCOREBOARD_LINE("13", x, y, SCOREBOARD_LINE_13_Y) \
	ITEM_SCOREBOARD_LINE("14", x, y, SCOREBOARD_LINE_14_Y) \
	ITEM_SCOREBOARD_LINE("15", x, y, SCOREBOARD_LINE_15_Y) \
	ITEM_SCOREBOARD_LINE("16", x, y, SCOREBOARD_LINE_16_Y) \
	ITEM_SCOREBOARD_LINE("17", x, y, SCOREBOARD_LINE_17_Y) \
	ITEM_SCOREBOARD_LINE("18", x, y, SCOREBOARD_LINE_18_Y) \
	ITEM_SCOREBOARD_LINE("19", x, y, SCOREBOARD_LINE_19_Y) \
	ITEM_SCOREBOARD_LINE("20", x, y, SCOREBOARD_LINE_20_Y) \
	ITEM_SCOREBOARD_LINE("21", x, y, SCOREBOARD_LINE_21_Y) \
	ITEM_SCOREBOARD_LINE("22", x, y, SCOREBOARD_LINE_22_Y) \
	ITEM_SCOREBOARD_LINE("23", x, y, SCOREBOARD_LINE_23_Y) \
	ITEM_SCOREBOARD_LINE("24", x, y, SCOREBOARD_LINE_24_Y) \
	ITEM_SCOREBOARD_LINE("25", x, y, SCOREBOARD_LINE_25_Y) \
	ITEM_SCOREBOARD_LINE("26", x, y, SCOREBOARD_LINE_26_Y) \
\
	ITEM_SCOREBOARD_COLUMN(x, y, "ui_scoreboard_names",    SCOREBOARD_NAME_X,     40, .2, ITEM_ALIGN_LEFT) \
	ITEM_SCOREBOARD_COLUMN(x, y, "ui_scoreboard_scores",   SCOREBOARD_SCORE_X,    40, .2, ITEM_ALIGN_LEFT) \
	ITEM_SCOREBOARD_COLUMN(x, y, "ui_scoreboard_kills",    SCOREBOARD_KILLS_X,    40, .2, ITEM_ALIGN_LEFT) \
	ITEM_SCOREBOARD_COLUMN(x, y, "ui_scoreboard_deaths",   SCOREBOARD_DEATHS_X,   40, .2, ITEM_ALIGN_LEFT) \
	ITEM_SCOREBOARD_COLUMN(x, y, "ui_scoreboard_assists",  SCOREBOARD_ASSISTS_X,  40, .2, ITEM_ALIGN_LEFT) \
	ITEM_SCOREBOARD_COLUMN(x, y, "ui_scoreboard_damages",  SCOREBOARD_DAMAGE_X,   40, .2, ITEM_ALIGN_LEFT) \
	ITEM_SCOREBOARD_COLUMN(x, y, "ui_scoreboard_grenades", SCOREBOARD_GRENADES_X, 40, .2, ITEM_ALIGN_LEFT) \
	ITEM_SCOREBOARD_COLUMN(x, y, "ui_scoreboard_plants",   SCOREBOARD_PLANTS_X,   40, .2, ITEM_ALIGN_LEFT) \
	ITEM_SCOREBOARD_COLUMN(x, y, "ui_scoreboard_defuses",  SCOREBOARD_DEFUSES_X,  40, .2, ITEM_ALIGN_LEFT) \
	ITEM_SCOREBOARD_COLUMN(x, y, "ui_scoreboard_ping",     SCOREBOARD_PING_X,     40, .2, ITEM_ALIGN_LEFT)








// All sub-menus that can be possibly opened at the same time
#define CLOSE_SUBMENUS close ingame_keys; close team_britishgerman_keys; close team_americangerman_keys; close team_russiangerman_keys; close ingame_scoreboard_sd; close rcon_map; close rcon_map_maps; close rcon_map_pams; close rcon_map_other; close rcon_map_apply; close rcon_settings; close rcon_settings_shared; close rcon_settings_gametypes; close rcon_settings_focus; close rcon_kick; close aboutpam; close pammodes;
#define CLOSE_ALL CLOSE_SUBMENUS close ingame; close team_britishgerman; close team_americangerman; close team_russiangerman;
