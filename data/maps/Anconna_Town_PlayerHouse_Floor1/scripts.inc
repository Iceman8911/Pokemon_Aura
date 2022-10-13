Anconna_Town_PlayerHouse_Floor1_MapScripts::
	.byte 0


PlayerHouse_Sibling_Room::
	lockall
	compare GAME_PROGRESS, 4
	goto_if_lt PlayerHouse_Sibling_Room_2
	compare GAME_PROGRESS, 4
	goto_if_ge PlayerHouse_Sibling_Room_4
PlayerHouse_Sibling_Room_1:
	releaseall
	return

PlayerHouse_Sibling_Room_2:
	msgbox PlayerHouse_Sibling_Room_Text_0
	applymovement OBJ_EVENT_ID_PLAYER, PlayerHouse_PlayerMoveUp
	waitmovement 0
	goto PlayerHouse_Sibling_Room_1

PlayerHouse_Sibling_Room_3:
	addvar VAR_TEMP_0, 1
	goto PlayerHouse_Sibling_Room_1

PlayerHouse_Sibling_Room_4:
	compare GAME_PROGRESS, 8
	goto_if_lt PlayerHouse_Sibling_Room_3
	goto PlayerHouse_Sibling_Room_1


PlayerHouse_PlayerLooksAtStaircaseBin::
	lockall
	compare GAME_PROGRESS, 6
	goto_if_eq PlayerHouse_PlayerLooksAtStaircaseBin_2
PlayerHouse_PlayerLooksAtStaircaseBin_1:
	releaseall
	return

PlayerHouse_PlayerLooksAtStaircaseBin_2:
	compare VAR_COUNTER, 11
	goto_if_le PlayerHouse_PlayerLooksAtStaircaseBin_4
	compare VAR_COUNTER, 2000
	goto_if_lt PlayerHouse_PlayerLooksAtStaircaseBin_5
	msgbox PlayerHouse_PlayerLooksAtStaircaseBin_Text_0
	goto PlayerHouse_PlayerLooksAtStaircaseBin_1

PlayerHouse_PlayerLooksAtStaircaseBin_4:
	msgbox PlayerHouse_PlayerLooksAtStaircaseBin_Text_0
	waitmessage
	goto PlayerHouse_PlayerLooksAtStaircaseBin_1

PlayerHouse_PlayerLooksAtStaircaseBin_5:
	msgbox PlayerHouse_PlayerLooksAtStaircaseBin_Text_1
	waitmessage
	giveitem ITEM_BIDOOF_COMB, 1
	addvar VAR_COUNTER, 2000
	goto PlayerHouse_PlayerLooksAtStaircaseBin_1


PlayerHouse_PlayerMoveUp:
	walk_up
	step_end

PlayerHouse_Sibling_Room_Text_0:
	.string "Um,\p"
	.string "I don't think I should go in there...$"

PlayerHouse_PlayerLooksAtStaircaseBin_Text_0:
	.string "Nothing here...$"

PlayerHouse_PlayerLooksAtStaircaseBin_Text_1:
	.string "Nothing here...\p"
	.string "Wait!\p"
	.string "I don't remember this being here.$"
