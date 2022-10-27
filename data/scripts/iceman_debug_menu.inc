IcemanDebugMenu::
	lockall
	msgbox IcemanDebugMenu_Text_0
	msgbox IcemanDebugMenu_Text_1
	bufferdynamicmulti IcemanDebugMenu_Text_2, IcemanDebugMenu_Text_3, IcemanDebugMenu_Text_4, IcemanDebugMenu_Text_5
	multichoice 25, 5, MULTI_DYNAMIC_3, 0
	call IcemanDebugSwitch
	releaseall
	return


IcemanDebugSwitch::
	switch VAR_RESULT
	case 0, IcemanDebugSwitch_3
	case 1, IcemanDebugSwitch_4
	case 2, IcemanDebugSwitch_5
IcemanDebugSwitch_1:
	return

IcemanDebugSwitch_3:
	bufferdynamicmulti IcemanDebugSwitch_Text_0, IcemanDebugSwitch_Text_1
	multichoice 25, 7, MULTI_DYNAMIC_2, 0
	switch VAR_RESULT
	case 0, IcemanDebugSwitch_7
	case 1, IcemanDebugSwitch_8
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

IcemanDebugSwitch_7:
	bufferdynamicmulti IcemanDebugSwitch_Text_2, IcemanDebugSwitch_Text_3, IcemanDebugSwitch_Text_4, IcemanDebugSwitch_Text_5, IcemanDebugSwitch_Text_6, IcemanDebugSwitch_Text_7
	multichoice 25, 3, MULTI_DYNAMIC_6, 0
	switch VAR_RESULT
	case 0, IcemanDebugSwitch_10
	case 1, IcemanDebugSwitch_11
	case 2, IcemanDebugSwitch_12
	case 3, IcemanDebugSwitch_13
	case 4, IcemanDebugSwitch_14
	case 5, IcemanDebugSwitch_15
	goto IcemanDebugSwitch_1

IcemanDebugSwitch_8:
	bufferdynamicmulti IcemanDebugSwitch_Text_8, IcemanDebugSwitch_Text_9
	multichoice 25, 3, MULTI_DYNAMIC_2, 0
	switch VAR_RESULT
	case 0, IcemanDebugSwitch_17
	case 1, IcemanDebugSwitch_18
	goto IcemanDebugSwitch_1

IcemanDebugSwitch_10:
	warp MAP_ANCONNA_TOWN, 0
	goto IcemanDebugSwitch_1

IcemanDebugSwitch_11:
	warp MAP_ANCONNA_WOODS, 0
	goto IcemanDebugSwitch_1

IcemanDebugSwitch_12:
	warp MAP_ANCONNA_WOODS_1, 0
	goto IcemanDebugSwitch_1

IcemanDebugSwitch_13:
	warp MAP_ROUTE01, 0
	goto IcemanDebugSwitch_1

IcemanDebugSwitch_14:
	warp MAP_ANCONNA_LAKE, 25, 4
	goto IcemanDebugSwitch_1

IcemanDebugSwitch_15:
	warp MAP_MURKY_GROVE, 0
	goto IcemanDebugSwitch_1

IcemanDebugSwitch_17:
	warp MAP_ROUTE02, 0
	goto IcemanDebugSwitch_1

IcemanDebugSwitch_18:
	warp MAP_SCANDI_CITY, 0
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
	.string "Rare Candies?$"

IcemanDebugSwitch_Text_0:
	.string "Anconna$"

IcemanDebugSwitch_Text_1:
	.string "Scandi$"

IcemanDebugSwitch_Text_2:
	.string "Anconna Town$"

IcemanDebugSwitch_Text_3:
	.string "Anconna Woods$"

IcemanDebugSwitch_Text_4:
	.string "Anconna Woods_1$"

IcemanDebugSwitch_Text_5:
	.string "Route 01$"

IcemanDebugSwitch_Text_6:
	.string "Anconna Lake$"

IcemanDebugSwitch_Text_7:
	.string "Murky Grove$"

IcemanDebugSwitch_Text_8:
	.string "Route 02$"

IcemanDebugSwitch_Text_9:
	.string "Scandi City$"
