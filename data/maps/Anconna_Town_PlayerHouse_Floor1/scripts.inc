Anconna_Town_PlayerHouse_Floor1_MapScripts::
	.byte 0


PlayerHouse_Sibling_Room::
	lockall
	msgbox PlayerHouse_Sibling_Room_Text_0
	applymovement OBJ_EVENT_ID_PLAYER, PlayerHouse_PlayerMoveUp
	waitmovement 0
	releaseall
	return


PlayerHouse_PlayerMoveUp:
	walk_up
	step_end

PlayerHouse_Sibling_Room_Text_0:
	.string "Um,\p"
	.string "I don't think I should go in there...$"
