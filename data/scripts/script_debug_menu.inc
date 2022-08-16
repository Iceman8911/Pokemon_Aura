DebugMenuScript::
    lockall
    multichoicedefault 0, 0, MULTI_DEBUG_MENU, 8, 1
    switch VAR_RESULT
    case 0, DebugMenu_QuickStart
    case 1, DebugMenu_QuickItems
    case 2, DebugMenu_UtilityScript
    case 3, DebugMenu_Teleportation
    case 4, DebugMenu_ChangeTime
    case 5, DebugMenu_AllBadges
    case 6, DebugMenu_HealParty
    case 7, DebugMenu_CheckSaveFileSize
    release
    end

@@Lets you skip the tutorial
DebugMenu_QuickStart::
    setvar VAR_LITTLEROOT_INTRO_STATE, 7
    setflag FLAG_SET_WALL_CLOCK
	setflag FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_HOUSE_VIGOROTH_1
	setflag FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_HOUSE_VIGOROTH_2
    setvar VAR_BIRCH_LAB_STATE, 5
    setflag FLAG_ADVENTURE_STARTED
	setvar VAR_OLDALE_TOWN_STATE, 1
    setflag FLAG_RESCUED_BIRCH
	setvar VAR_LITTLEROOT_RIVAL_STATE, 4
	setvar VAR_LITTLEROOT_TOWN_STATE, 3
    setflag FLAG_SYS_POKEDEX_GET
    setflag FLAG_SYS_POKEMON_GET
    setflag FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
	setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
	setvar VAR_ROUTE101_STATE, 3
    setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_TRUCK
    setflag FLAG_HIDE_ROUTE_101_ZIGZAGOON
	special SetUnlockedPokedexFlags
    checkplayergender
	call_if_eq VAR_RESULT, MALE, Route101_EventScript_HideMayInBedroom
	call_if_eq VAR_RESULT, FEMALE, Route101_EventScript_HideBrendanInBedroom
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 1
    setvar VAR_LITTLEROOT_TOWN_STATE, 4
    setvar VAR_LITTLEROOT_RIVAL_STATE, 4
    setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK
    setflag FLAG_SYS_B_DASH
    setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 2
    setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 2 
    fadescreen FADE_TO_BLACK
	special StartWallClock
	waitstate
    setvar VAR_TEMP_1, SPECIES_MEWTWO
    givemon SPECIES_MEWTWO, 100, ITEM_TWISTED_SPOON
    warpteleport MAP_LITTLEROOT_TOWN, 255, 8, 8
    waitstate

@@easily get useful items
DebugMenu_QuickItems::
    additem ITEM_FULL_RESTORE, 99
    additem ITEM_MASTER_BALL, 99
    additem ITEM_MAX_REVIVE, 99
    additem ITEM_MAX_ELIXIR, 99
    additem ITEM_RARE_CANDY, 99
    additem ITEM_NUGGET, 99
    additem ITEM_MAX_REPEL, 99
    additem ITEM_HEART_SCALE, 99
    call Debug_Init_GiveAllTMs
    msgbox ItemsAddedMsg
    release
    end

ItemsAddedMsg:
    .string "Items given.$"

Debug_Init_GiveAllTMs::
	setvar VAR_TEMP_2, 289
	goto Debug_GiveAllTMs
	
Debug_GiveAllTMs::
	additem VAR_TEMP_2, 99
	addvar VAR_TEMP_2, 1
	goto Debug_ReturnCallTMs
	
Debug_ReturnCallTMs::
	compare VAR_TEMP_2, 347
	goto_if_eq DebugGiveTMsDone
	goto Debug_GiveAllTMs
	
DebugGiveTMsDone::
	return

Debug_GiveAllTMsBeginMsg:
	.string "Giving all tms...$"

Debug_GiveAllTMsDoneMsg:
    .string "Given all TMs and HMs$"

@@ Put random utility scripts here.
DebugMenu_UtilityScript::
    release
    end

@@teleport menu
DebugMenu_Teleportation::
	lockall
    setflag FLAG_VISITED_LITTLEROOT_TOWN
	setflag FLAG_VISITED_OLDALE_TOWN
	setflag FLAG_VISITED_DEWFORD_TOWN
	setflag FLAG_VISITED_LAVARIDGE_TOWN
	setflag FLAG_VISITED_FALLARBOR_TOWN
	setflag FLAG_VISITED_VERDANTURF_TOWN
	setflag FLAG_VISITED_PACIFIDLOG_TOWN
	setflag FLAG_VISITED_PETALBURG_CITY
	setflag FLAG_VISITED_SLATEPORT_CITY
	setflag FLAG_VISITED_MAUVILLE_CITY
	setflag FLAG_VISITED_RUSTBORO_CITY
	setflag FLAG_VISITED_FORTREE_CITY
	setflag FLAG_VISITED_LILYCOVE_CITY
	setflag FLAG_VISITED_MOSSDEEP_CITY
	setflag FLAG_VISITED_SOOTOPOLIS_CITY
	setflag FLAG_VISITED_EVER_GRANDE_CITY
	setflag FLAG_LANDMARK_BATTLE_FRONTIER
	setflag FLAG_LANDMARK_POKEMON_LEAGUE
	multichoicegrid 0, 0, MULTI_TELEPORT_MAIN_MENU, 3, 0
	switch VAR_RESULT
	case 0, RT_Littleroot
	case 1, RT_Oldale
	case 2, RT_Petalburg
	case 3, RT_Rustboro
	case 4, RT_Verdanturf
	case 5, RT_Slateport
	case 6, RT_Dewford
	case 7, RT_Pacifidlog
	case 8, RT_Lavaridge
	case 9, RT_Fallarbor
	case 10, RT_Fortree
	case 11, RT_Mauville
	case 12, RT_Lilycove
	case 13, RT_Sootopolis
	case 14, RT_Mossdeep
	case 15, RT_Evergrande
	case 16, RT_BattleFrontier
	case 17, RT_Exit
	case 127, RT_Exit
	closemessage
	release
	end

RT_Littleroot::
    warpteleport MAP_LITTLEROOT_TOWN, 255, 8, 8
    waitstate

MSG_Teleport:
	.string "Teleport to where?$"
	
RT_Oldale::
	goto_if_unset FLAG_VISITED_OLDALE_TOWN, RT_NoFlag
	warpteleport MAP_OLDALE_TOWN, 255, 10, 9
	waitstate
	
RT_Petalburg::
    goto_if_unset FLAG_VISITED_PETALBURG_CITY, RT_NoFlag
	warpteleport MAP_PETALBURG_CITY, 255, 16, 16
	waitstate
	
RT_Rustboro::
    goto_if_unset FLAG_VISITED_RUSTBORO_CITY, RT_NoFlag
	warpteleport MAP_RUSTBORO_CITY, 255, 20, 49
	waitstate
	
RT_Verdanturf::
    goto_if_unset FLAG_VISITED_VERDANTURF_TOWN, RT_NoFlag
	warpteleport MAP_VERDANTURF_TOWN, 255, 13, 25
	waitstate
	
RT_Slateport::
    goto_if_unset FLAG_VISITED_SLATEPORT_CITY, RT_NoFlag
	warpteleport MAP_SLATEPORT_CITY, 255, 17, 22
	waitstate
	
RT_Dewford::
    goto_if_unset FLAG_VISITED_DEWFORD_TOWN, RT_NoFlag
	warpteleport MAP_DEWFORD_TOWN, 255, 29, 10
	waitstate
	
RT_Pacifidlog::
    goto_if_unset FLAG_VISITED_PACIFIDLOG_TOWN, RT_NoFlag
	warpteleport MAP_PACIFIDLOG_TOWN, 255, 8, 16
	waitstate
	
RT_Lavaridge::
    goto_if_unset FLAG_VISITED_LAVARIDGE_TOWN, RT_NoFlag
	warpteleport MAP_LAVARIDGE_TOWN, 255, 12, 8
	waitstate
	
RT_Fallarbor::
    goto_if_unset FLAG_VISITED_FALLARBOR_TOWN, RT_NoFlag
	warpteleport MAP_FALLARBOR_TOWN, 255, 9, 11
	waitstate
	
RT_Fortree::
    goto_if_unset FLAG_VISITED_FORTREE_CITY, RT_NoFlag
	warpteleport MAP_FORTREE_CITY, 255, 5, 9
	waitstate
	
RT_Mauville::
    goto_if_unset FLAG_VISITED_MAUVILLE_CITY, RT_NoFlag
	warpteleport MAP_MAUVILLE_CITY, 255, 18, 7
	waitstate
	
RT_Lilycove::
    goto_if_unset FLAG_VISITED_LILYCOVE_CITY, RT_NoFlag
	warpteleport MAP_LILYCOVE_CITY, 255, 22, 17
	waitstate

RT_Sootopolis::
    goto_if_unset FLAG_VISITED_SOOTOPOLIS_CITY, RT_NoFlag
	warpteleport MAP_SOOTOPOLIS_CITY, 255, 42, 37
	waitstate
	
RT_Mossdeep::
    goto_if_unset FLAG_VISITED_MOSSDEEP_CITY, RT_NoFlag
	warpteleport MAP_MOSSDEEP_CITY, 255, 25, 17
	waitstate
	
RT_Evergrande::
	goto_if_set FLAG_LANDMARK_POKEMON_LEAGUE, RT_PokemonLeague
	goto_if_unset FLAG_VISITED_EVER_GRANDE_CITY, RT_NoFlag
	warpteleport MAP_EVER_GRANDE_CITY, 255, 27, 49
	waitstate
	
RT_BattleFrontier::
    goto_if_unset FLAG_LANDMARK_BATTLE_FRONTIER, RT_NoBfFlag
	multichoicedefault 3, 0, MULTI_TELEPORT_MENU_FRONTIER, 0, 0
	switch VAR_RESULT
	case 0, RT_BF_GATE
	case 1, RT_BF_BT@tower
	case 2, RT_BF_BP@pike
	case 3, RT_BF_BP2@palace
	case 4, RT_BF_BP3@pyramid
	case 5, RT_BF_BF@factory
	case 6, RT_BF_BA@arena
	case 7, RT_BF_BD@dome
	case 8, RT_BF_CB@go back to main teleport menu
	case 127, DebugMenu_Teleportation@also go back to teleport menu
	release
	end

RT_Empty::
    msgbox RT_EmptyOption
    closemessage
    goto DebugMenu_Teleportation

RT_EmptyOption:
    .string "This option is empty.\pReturning to main menu.$"

RT_LCCDEPT::
	warpteleport MAP_LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP, 255, 4, 5
	waitstate
	
RT_BF_GATE::
	warpteleport MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 255, 26, 50
	waitstate
	
RT_BF_BT::
	warpteleport MAP_BATTLE_FRONTIER_BATTLE_TOWER_LOBBY, 255, 12, 6
	waitstate
	
RT_BF_BP::
	warpteleport MAP_BATTLE_FRONTIER_BATTLE_PIKE_LOBBY, 255, 5, 7
	waitstate
	
RT_BF_BP2::
	warpteleport MAP_BATTLE_FRONTIER_BATTLE_PALACE_LOBBY, 255, 12, 10
	waitstate
	
RT_BF_BP3::
	warpteleport MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_LOBBY, 255, 7, 14
	waitstate
	
RT_BF_BF::
	warpteleport MAP_BATTLE_FRONTIER_BATTLE_FACTORY_LOBBY, 255, 9, 10
	waitstate
	
RT_BF_BA::
	warpteleport MAP_BATTLE_FRONTIER_BATTLE_ARENA_LOBBY, 255, 7, 10
	waitstate
	
RT_BF_BD::
	warpteleport MAP_BATTLE_FRONTIER_BATTLE_DOME_LOBBY, 255, 11, 11
	waitstate
	
RT_BF_CB::
	goto DebugMenu_Teleportation
	
RT_NoBfFlag::
	msgbox MSG_RT_NOFLAGBT MSGBOX_DEFAULT
	closemessage
	goto DebugMenu_Teleportation
	
RT_NoFlag::
	msgbox RT_NOFLAGMSG MSGBOX_DEFAULT
	goto DebugMenu_Teleportation
	
MSG_RT_NOFLAGBT:
	.string "You haven't been to the Frontier yet.$"
	
RT_NOFLAGMSG:
	.string "You haven't been here yet.$"
	
RT_PokemonLeague::
	setvar VAR_ELITE_4_STATE, 0
	warpteleport MAP_EVER_GRANDE_CITY_POKEMON_LEAGUE_1F, 255, 9, 6
	release
	end
	
RT_Exit::
	closemessage
	release
	end

@@time debug
DebugMenu_ChangeTime::
    gettime
	buffernumberstring 0, VAR_0x8000
	buffernumberstring 1, VAR_0x8001
	buffernumberstring 2, VAR_0x8002
    msgbox DebugCurrentTime, MSGBOX_YESNO
    compare VAR_RESULT, 1
    goto_if_eq DebugMenu_DoTimeSet
    release
    end

DebugCurrentTime:
    .string "The Current time is {STR_VAR_1}:{STR_VAR_2}:{STR_VAR_3}.\nWould you like to change it?$"

DebugMenu_DoTimeSet::
    fadescreen FADE_TO_BLACK
	special StartWallClock
	waitstate
    release
    end

@@badges debug
DebugMenu_AllBadges::
    setflag FLAG_BADGE01_GET
	setflag FLAG_BADGE02_GET
	setflag FLAG_BADGE03_GET
	setflag FLAG_BADGE04_GET
	setflag FLAG_BADGE05_GET
	setflag FLAG_BADGE06_GET
	setflag FLAG_BADGE07_GET
	setflag FLAG_BADGE08_GET
    release
    end

@@heal anywhere
DebugMenu_HealParty::
    special HealPlayerParty
    msgbox partyHealedMsg
    release
    end

partyHealedMsg:
    .string "Party healed.$"

@@check used save file space
DebugMenu_CheckSaveFileSize::
    callnative BufferSaveFileSize
    msgbox SaveFileSizeMsg
    release
    end

SaveFileSizeMsg:
    .string "SaveBlock1 size is {STR_VAR_1}/15872 bytes.\nSaveBlock2 size is {STR_VAR_2}/3968 bytes.$"
