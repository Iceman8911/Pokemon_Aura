AnconnaTown_PlayerHouse_GroundFloor_MapScripts::
	.byte 0


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
