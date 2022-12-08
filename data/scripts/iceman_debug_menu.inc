IcemanDebugMenu::
	lockall
	msgbox IcemanDebugMenu_Text_0
	msgbox IcemanDebugMenu_Text_1
	bufferdynamicmulti IcemanDebugMenu_Text_2, IcemanDebugMenu_Text_3, IcemanDebugMenu_Text_4, IcemanDebugMenu_Text_5
	multichoice 25, 5, MULTI_DYNAMIC_4, 0
	call IcemanDebugSwitch
	releaseall
	return


IcemanDebugSwitch::
	switch VAR_RESULT
	case 0, IcemanDebugSwitch_3
	case 1, IcemanDebugSwitch_4
	case 2, IcemanDebugSwitch_5
	case 3, IcemanDebugSwitch_6
IcemanDebugSwitch_1:
	return

IcemanDebugSwitch_3:
	bufferdynamicmulti IcemanDebugSwitch_Text_0, IcemanDebugSwitch_Text_1
	multichoice 25, 7, MULTI_DYNAMIC_2, 0
	switch VAR_RESULT
	case 0, IcemanDebugSwitch_8
	case 1, IcemanDebugSwitch_9
	goto IcemanDebugSwitch_1

IcemanDebugSwitch_4:
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_SYS_POKEDEX_GET
	setflag FLAG_SYS_B_DASH
	setflag FLAG_SYS_DEXNAV_GET
	setflag RIOLU_ENCOUNTER
	setflag FIRST_LIUM_ENCOUNTER
	setflag ANCONNA_TOWN_MYSTERIOUS_PEOPLE
	setflag RIOLU_IS_IN_PLAYER_HOUSE
	setvar ANCONNA_WOODS_FOUND_RIOLU, 1
	setvar FIRST_LIUM_FIGHT, 1
	setvar ANCONNA_TOWN_DISCOVERED_MYSTERIOUS_PEOPLE, 1
	setvar GAME_PROGRESS, 7
	goto IcemanDebugSwitch_1

IcemanDebugSwitch_5:
	givecustommon SPECIES_RIOLU, 5, ITEM_FOCUS_SASH, , NATURE_HASTY, 0, , , , , , , , 31, , 31, 31
	setflag FLAG_SYS_POKEMON_GET
	goto IcemanDebugSwitch_1

IcemanDebugSwitch_6:
	bufferdynamicmulti IcemanDebugSwitch_Text_15, IcemanDebugSwitch_Text_16, IcemanDebugSwitch_Text_17, IcemanDebugSwitch_Text_18, IcemanDebugSwitch_Text_19, IcemanDebugSwitch_Text_20
	multichoice 25, 5, MULTI_DYNAMIC_6, 0
	switch VAR_RESULT
	case 0, IcemanDebugSwitch_11
	case 1, IcemanDebugSwitch_12
	case 2, IcemanDebugSwitch_13
	case 3, IcemanDebugSwitch_14
	goto IcemanDebugSwitch_1

IcemanDebugSwitch_8:
	bufferdynamicmulti IcemanDebugSwitch_Text_2, IcemanDebugSwitch_Text_3
	multichoice 25, 7, MULTI_DYNAMIC_2, 0
	switch VAR_RESULT
	case 0, IcemanDebugSwitch_16
	case 1, IcemanDebugSwitch_17
	goto IcemanDebugSwitch_1

IcemanDebugSwitch_9:
	bufferdynamicmulti IcemanDebugSwitch_Text_13, IcemanDebugSwitch_Text_14
	multichoice 25, 3, MULTI_DYNAMIC_2, 0
	switch VAR_RESULT
	case 0, IcemanDebugSwitch_19
	case 1, IcemanDebugSwitch_20
	goto IcemanDebugSwitch_1

IcemanDebugSwitch_11:
	special NameSibling
	waitstate
	msgbox IcemanDebugSwitch_Text_21
	waitmessage
	goto IcemanDebugSwitch_1

IcemanDebugSwitch_12:
	buffernumberstring STR_VAR_1, VAR_0x8000
	buffernumberstring STR_VAR_2, VAR_0x8001
	buffernumberstring STR_VAR_3, VAR_0x8002
	msgbox IcemanDebugSwitch_Text_22
	buffernumberstring STR_VAR_1, VAR_0x8003
	msgbox IcemanDebugSwitch_Text_23
	goto IcemanDebugSwitch_1

IcemanDebugSwitch_13:
	buffernumberstring STR_VAR_1, VAR_0x8000
	buffernumberstring STR_VAR_2, VAR_0x8001
	buffernumberstring STR_VAR_3, VAR_0x8002
	msgbox IcemanDebugSwitch_Text_22
	buffernumberstring STR_VAR_1, VAR_0x8003
	msgbox IcemanDebugSwitch_Text_23
	goto IcemanDebugSwitch_1

IcemanDebugSwitch_14:
	msgbox IcemanDebugSwitch_Text_24, , IcemanDebugSwitch_Text_25
	waitmessage
	multichoice 25, 7, MULTI_DYNAMIC_2, 0
	msgbox IcemanDebugSwitch_Text_26, , IcemanDebugSwitch_Text_25
	waitmessage
	goto IcemanDebugSwitch_1

IcemanDebugSwitch_16:
	bufferdynamicmulti IcemanDebugSwitch_Text_4, IcemanDebugSwitch_Text_5, IcemanDebugSwitch_Text_6, IcemanDebugSwitch_Text_7, IcemanDebugSwitch_Text_8, IcemanDebugSwitch_Text_9
	multichoice 25, 3, MULTI_DYNAMIC_6, 0
	switch VAR_RESULT
	case 0, IcemanDebugSwitch_22
	case 1, IcemanDebugSwitch_23
	case 2, IcemanDebugSwitch_24
	case 3, IcemanDebugSwitch_25
	case 4, IcemanDebugSwitch_26
	case 5, IcemanDebugSwitch_27
	goto IcemanDebugSwitch_1

IcemanDebugSwitch_17:
	bufferdynamicmulti IcemanDebugSwitch_Text_10, IcemanDebugSwitch_Text_11, IcemanDebugSwitch_Text_12
	multichoice 25, 3, MULTI_DYNAMIC_3, 0
	switch VAR_RESULT
	case 0, IcemanDebugSwitch_29
	case 1, IcemanDebugSwitch_30
	case 2, IcemanDebugSwitch_31
	goto IcemanDebugSwitch_1

IcemanDebugSwitch_19:
	warp MAP_ROUTE02, 0
	goto IcemanDebugSwitch_1

IcemanDebugSwitch_20:
	warp MAP_SCANDI_CITY, 0
	goto IcemanDebugSwitch_1

IcemanDebugSwitch_22:
	warp MAP_ANCONNA_TOWN, 0
	goto IcemanDebugSwitch_1

IcemanDebugSwitch_23:
	warp MAP_ANCONNA_WOODS, 0
	goto IcemanDebugSwitch_1

IcemanDebugSwitch_24:
	warp MAP_ANCONNA_WOODS_1, 0
	goto IcemanDebugSwitch_1

IcemanDebugSwitch_25:
	warp MAP_ROUTE01, 0
	goto IcemanDebugSwitch_1

IcemanDebugSwitch_26:
	warp MAP_ANCONNA_LAKE, 25, 4
	goto IcemanDebugSwitch_1

IcemanDebugSwitch_27:
	warp MAP_MURKY_GROVE, 0
	goto IcemanDebugSwitch_1

IcemanDebugSwitch_29:
	warp MAP_ANCONNA_TOWN_PLAYER_HOUSE, 0
	goto IcemanDebugSwitch_1

IcemanDebugSwitch_30:
	warp MAP_ANCONNA_TOWN_LAB, 0
	goto IcemanDebugSwitch_1

IcemanDebugSwitch_31:
	warp MAP_ANCONNA_TOWN_LAB1ST_FLOOR, 0
	goto IcemanDebugSwitch_1


IcemanDebugMenu_Text_0:
	.string "Loading Debug Menu....$"

IcemanDebugMenu_Text_1:
	.string "What do you want to do?$"

IcemanDebugMenu_Text_2:
	.string "Teleport$"

IcemanDebugMenu_Text_3:
	.string "Set Flags And Vars$"

IcemanDebugMenu_Text_4:
	.string "Give Mon$"

IcemanDebugMenu_Text_5:
	.string "Custom Script$"

IcemanDebugSwitch_Text_0:
	.string "Anconna$"

IcemanDebugSwitch_Text_1:
	.string "Scandi$"

IcemanDebugSwitch_Text_2:
	.string "Outdoors$"

IcemanDebugSwitch_Text_3:
	.string "Indoors$"

IcemanDebugSwitch_Text_4:
	.string "Anconna Town$"

IcemanDebugSwitch_Text_5:
	.string "Anconna Woods$"

IcemanDebugSwitch_Text_6:
	.string "Anconna Woods_1$"

IcemanDebugSwitch_Text_7:
	.string "Route 01$"

IcemanDebugSwitch_Text_8:
	.string "Anconna Lake$"

IcemanDebugSwitch_Text_9:
	.string "Murky Grove$"

IcemanDebugSwitch_Text_10:
	.string "{PLAYER}'s House$"

IcemanDebugSwitch_Text_11:
	.string "Anconna Lab$"

IcemanDebugSwitch_Text_12:
	.string "Anconna Lab 1$"

IcemanDebugSwitch_Text_13:
	.string "Route 02$"

IcemanDebugSwitch_Text_14:
	.string "Scandi City$"

IcemanDebugSwitch_Text_15:
	.string "Name Sibling$"

IcemanDebugSwitch_Text_16:
	.string "Test Script 1$"

IcemanDebugSwitch_Text_17:
	.string "Test Script 2$"

IcemanDebugSwitch_Text_18:
	.string "Text Box$"

IcemanDebugSwitch_Text_19:
	.string "5$"

IcemanDebugSwitch_Text_20:
	.string "6$"

IcemanDebugSwitch_Text_21:
	.string "Your Sibling's Name is {SIBLING}$"

IcemanDebugSwitch_Text_22:
	.string "The Player's Elevation is\n"
	.string "{STR_VAR_1} and subpriority is\l"
	.string "{STR_VAR_3} while the Follower's\l"
	.string "Elevation is {STR_VAR_2}.$"

IcemanDebugSwitch_Text_23:
	.string "Follower Subpriority = {STR_VAR_1}$"

IcemanDebugSwitch_Text_24:
	.string "fieeeeshhh$"

IcemanDebugSwitch_Text_25:
	.string "Icecram$"

IcemanDebugSwitch_Text_26:
	.string "fieeeeshhh2$"
