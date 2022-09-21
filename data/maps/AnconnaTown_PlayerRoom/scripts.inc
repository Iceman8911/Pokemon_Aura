AnconnaTown_PlayerRoom_MapScripts::
	.byte 0


AccessPlayerPC::
	lockall
	playse SE_PC_ON
	special BedroomPC
	waitstate
	releaseall
	return


CheckIfPlayerTookPotionOutOfBedroomPC::
	lockall
	checkitem ITEM_POTION, 1
	compare VAR_RESULT, 0
	goto_if_eq CheckIfPlayerTookPotionOutOfBedroomPC_2
	addvar GAME_PROGRESS, 1
CheckIfPlayerTookPotionOutOfBedroomPC_1:
	releaseall
	return

CheckIfPlayerTookPotionOutOfBedroomPC_2:
	msgbox CheckIfPlayerTookPotionOutOfBedroomPC_Text_0
	applymovement OBJ_EVENT_ID_PLAYER, Walk_Down
	goto CheckIfPlayerTookPotionOutOfBedroomPC_1


CheckIfPlayerTookPotionOutOfBedroomPC_Text_0:
	.string "I feel like I'm missing something. Maybe\n"
	.string "I should check my PC.$"
