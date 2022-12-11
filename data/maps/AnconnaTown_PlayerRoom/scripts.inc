AnconnaTown_PlayerRoom_MapScripts::
	.byte 0


PlayerRoom_ReadjustMetatileOnBed::
	setmetatile 10, 8, 0x124, FALSE
	setmetatile 12, 8, 0x125, FALSE
	special DrawWholeMapView
	setvar VAR_TEMP_1, 1
	return


PlayerRoom_ReadjustMetatileOnBedLeftEdge::
	setmetatile 10, 8, 0x130, FALSE
	setmetatile 11, 7, 0x129, TRUE
	setmetatile 11, 8, 0x131, FALSE
	special DrawWholeMapView
	setvar VAR_TEMP_1, 1
	return


PlayerRoom_ReadjustMetatileOnBedRightEdge::
	setmetatile 12, 8, 0x132, FALSE
	setmetatile 11, 7, 0x129, TRUE
	setmetatile 11, 8, 0x131, FALSE
	special DrawWholeMapView
	setvar VAR_TEMP_1, 1
	return


PlayerRoom_ReadjustMetatileOnBedLeftEdgeUpperPole::
	setmetatile 11, 7, 0x121, FALSE
	setmetatile 11, 8, 0x131, TRUE
	special DrawWholeMapView
	setvar VAR_TEMP_1, 1
	return


PlayerRoom_ReadjustMetatileOnBedRightEdgeUpperPole::
	setmetatile 11, 7, 0x121, FALSE
	setmetatile 11, 8, 0x131, TRUE
	special DrawWholeMapView
	setvar VAR_TEMP_1, 1
	return


PlayerRoom_ReadjustMetatileAboveBed::
	setmetatile 11, 7, 0x121, FALSE
	setmetatile 11, 8, 0x131, TRUE
	special DrawWholeMapView
	setvar VAR_TEMP_1, 1
	return


AccessPlayerPC::
	lockall
	playse SE_PC_ON
	special PlayerPC
	waitstate
	releaseall
	return


Quests::
	lockall
	setflag FLAG_SYS_QUEST_MENU_GET
	msgbox Quests_Text_0
	closemessage
	releaseall
	return


CheckIfPlayerTookPotionOutOfBedroomPC::
	lockall
	checkitem ITEM_POTION, 1
	compare VAR_RESULT, 0
	goto_if_eq CheckIfPlayerTookPotionOutOfBedroomPC_2
	applymovement OBJ_EVENT_ID_PLAYER, WalkInPlaceDown
	waitmovement 0
	delay 30
	msgbox CheckIfPlayerTookPotionOutOfBedroomPC_Text_1
	addvar GAME_PROGRESS, 1
CheckIfPlayerTookPotionOutOfBedroomPC_1:
	releaseall
	return

CheckIfPlayerTookPotionOutOfBedroomPC_2:
	applymovement OBJ_EVENT_ID_PLAYER, WalkInPlaceDown
	waitmovement 0
	delay 30
	msgbox CheckIfPlayerTookPotionOutOfBedroomPC_Text_0
	applymovement OBJ_EVENT_ID_PLAYER, Walk_Down
	waitmovement 0
	goto CheckIfPlayerTookPotionOutOfBedroomPC_1


WalkInPlaceDown:
	walk_in_place_faster_down
	step_end

Quests_Text_0:
	.string "Quests unlocked$"

CheckIfPlayerTookPotionOutOfBedroomPC_Text_0:
	.string "I feel like I'm missing something. Maybe\n"
	.string "I should check my PC.$"

CheckIfPlayerTookPotionOutOfBedroomPC_Text_1:
	.string "That should be it.\p"
	.string "Well, Time to start the day.$"
