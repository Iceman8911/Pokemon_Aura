AnconnaTown_PlayerHouse_GroundFloor_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AnconnaTown_PlayerHouse_GroundFloor_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

AnconnaTown_PlayerHouse_GroundFloor_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	return


PlayerCameDownstairsAfterWakingUp::
	lockall
	special SpawnCameraObject
	applymovement 1, MumComesToMeetYouAtTheStairCase
	waitmovement 0
	msgbox PlayerCameDownstairsAfterWakingUp_Text_0
	waitmessage
	closemessage
	applymovement 1, MumTakesYouToTheSofa
	applymovement OBJ_EVENT_ID_PLAYER, YouWalkToTheSofa
	applymovement OBJ_EVENT_ID_CAMERA, YouWalkToTheSofa
	waitmovement 0
	msgbox PlayerCameDownstairsAfterWakingUp_Text_1
	waitmessage
	closemessage
	applymovement 2, DadWalksToYou
	waitmovement 0
	msgbox PlayerCameDownstairsAfterWakingUp_Text_2
	waitmessage
	msgbox PlayerCameDownstairsAfterWakingUp_Text_3
	setflag FLAG_RECEIVED_RUNNING_SHOES
	msgbox PlayerCameDownstairsAfterWakingUp_Text_4
	waitmessage
	msgbox PlayerCameDownstairsAfterWakingUp_Text_5
	waitmessage
	msgbox PlayerCameDownstairsAfterWakingUp_Text_6
	releaseall
	return


MumComesToMeetYouAtTheStairCase:
	emote_exclamation_mark
	delay_16
	delay_16
	walk_left
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

MumTakesYouToTheSofa:
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_down
	step_end

YouWalkToTheSofa:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_down
	step_end

DadWalksToYou:
	walk_right
	walk_up
	walk_right
	walk_right
	walk_right
	face_up
	step_end

AnconnaTown_PlayerHouse_Mum::
	lockall
	msgbox AnconnaTown_PlayerHouse_Mum_Text_0
	releaseall
	return


AnconnaTown_PlayerHouse_TV::
	lockall
	random 5
	switch VAR_RESULT
	case 0, AnconnaTown_PlayerHouse_TV_3
	case 1, AnconnaTown_PlayerHouse_TV_4
	case 2, AnconnaTown_PlayerHouse_TV_5
	case 3, AnconnaTown_PlayerHouse_TV_6
	case 4, AnconnaTown_PlayerHouse_TV_7
AnconnaTown_PlayerHouse_TV_1:
	releaseall
	return

AnconnaTown_PlayerHouse_TV_3:
	msgbox AnconnaTown_PlayerHouse_TV_Text_0
	goto AnconnaTown_PlayerHouse_TV_1

AnconnaTown_PlayerHouse_TV_4:
	msgbox AnconnaTown_PlayerHouse_TV_Text_1
	goto AnconnaTown_PlayerHouse_TV_1

AnconnaTown_PlayerHouse_TV_5:
	msgbox AnconnaTown_PlayerHouse_TV_Text_2
	goto AnconnaTown_PlayerHouse_TV_1

AnconnaTown_PlayerHouse_TV_6:
	msgbox AnconnaTown_PlayerHouse_TV_Text_3
	goto AnconnaTown_PlayerHouse_TV_1

AnconnaTown_PlayerHouse_TV_7:
	msgbox AnconnaTown_PlayerHouse_TV_Text_4
	goto AnconnaTown_PlayerHouse_TV_1


AnconnaTown_PlayerHouse_Dishes::
	lockall
	msgbox AnconnaTown_PlayerHouse_Dishes_Text_0
	releaseall
	return


AnconnaTown_PlayerHouse_Sink::
	lockall
	msgbox AnconnaTown_PlayerHouse_Sink_Text_0
	releaseall
	return


AnconnaTown_PlayerHouse_Fridge::
	lockall
	msgbox AnconnaTown_PlayerHouse_Fridge_Text_0
	waitmessage
	releaseall
	return


AnconnaTown_PlayerHouse_Dustbin::
	lockall
	msgbox AnconnaTown_PlayerHouse_Dustbin_Text_0
	waitmessage
	releaseall
	return


AnconnaTown_PlayerHouse_Plant::
	lockall
	msgbox AnconnaTown_PlayerHouse_Plant_Text_0
	waitmessage
	releaseall
	return


AnconnaTown_PlayerHouse_Window::
	lockall
	msgbox AnconnaTown_PlayerHouse_Window_Text_0
	waitmessage
	releaseall
	return


AnconnaTown_PlayerHouse_BookShelve::
	lockall
	msgbox AnconnaTown_PlayerHouse_BookShelve_Text_0
	waitmessage
	releaseall
	return


AnconnaTown_PlayerHouse_NES::
	lockall
	msgbox AnconnaTown_PlayerHouse_NES_Text_0
	waitmessage
	releaseall
	return


AnconnaTown_PlayerHouse_Drawer::
	lockall
	msgbox AnconnaTown_PlayerHouse_Drawer_Text_0
	waitmessage
	releaseall
	return


PlayerCameDownstairsAfterWakingUp_Text_0:
	.string "Mum: {COLOR RED}Good Morning, {COLOR GREEN}{PLAYER}{COLOR RED}.\n"
	.string "How was your night?\p"
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: Yawn...\n"
	.string "A bit rough to be honest.\p"
	.string "Mum: {COLOR RED}Then I'm sure this will cheer you\n"
	.string "up!$"

PlayerCameDownstairsAfterWakingUp_Text_1:
	.string "Mum: {COLOR RED}Your Father and I have something\n"
	.string "special to give you!$"

PlayerCameDownstairsAfterWakingUp_Text_2:
	.string "Dad: {COLOR BLUE}That's right!.\n"
	.string "Here you go.$"

PlayerCameDownstairsAfterWakingUp_Text_3:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY} recieved a pair of Running\n"
	.string "Shoes!$"

PlayerCameDownstairsAfterWakingUp_Text_4:
	.string "Mum: {COLOR RED}This will make all your work faster!$"

PlayerCameDownstairsAfterWakingUp_Text_5:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: .....\p"
	.string "So this is just a way of telling me to do\n"
	.string "more work.$"

PlayerCameDownstairsAfterWakingUp_Text_6:
	.string "Mum: {COLOR RED}:D\p"
	.string ".....\p"
	.string "Maybe....$"

AnconnaTown_PlayerHouse_Mum_Text_0:
	.string "This is a Placeholder. Tell my Creator\n"
	.string "what you want me to say.$"

AnconnaTown_PlayerHouse_TV_Text_0:
	.string "Placeholder 1$"

AnconnaTown_PlayerHouse_TV_Text_1:
	.string "Placeholder 2$"

AnconnaTown_PlayerHouse_TV_Text_2:
	.string "Placeholder 3$"

AnconnaTown_PlayerHouse_TV_Text_3:
	.string "Placeholder 4$"

AnconnaTown_PlayerHouse_TV_Text_4:
	.string "Placeholder 5$"

AnconnaTown_PlayerHouse_Dishes_Text_0:
	.string "Clean plates are arranged nicely on its\n"
	.string "shelves.$"

AnconnaTown_PlayerHouse_Sink_Text_0:
	.string "Something smells really delicious here.$"

AnconnaTown_PlayerHouse_Fridge_Text_0:
	.string "This should have cold drinks and\n"
	.string "beverages in it.\p"
	.string "Too bad I can't have any.$"

AnconnaTown_PlayerHouse_Dustbin_Text_0:
	.string "Huh, there's literally nothing here.\p"
	.string "......\p"
	.string "What am I even looking for in a dustbin?$"

AnconnaTown_PlayerHouse_Plant_Text_0:
	.string "Its a potted plant.$"

AnconnaTown_PlayerHouse_Window_Text_0:
	.string "It looks sunny outside.$"

AnconnaTown_PlayerHouse_BookShelve_Text_0:
	.string "Books covering a variety of subjects\n"
	.string "are arranged neatly on the shelf.$"

AnconnaTown_PlayerHouse_NES_Text_0:
	.string "My Old NES.\p"
	.string ".....\p"
	.string "I've had some good times with this.$"

AnconnaTown_PlayerHouse_Drawer_Text_0:
	.string "Placeholder$"
