AnconnaTown_PlayerRoom_MapScripts::
	.byte 0


AccessPlayerPC::
	lockall
	playse SE_PC_ON
	special BedroomPC
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
