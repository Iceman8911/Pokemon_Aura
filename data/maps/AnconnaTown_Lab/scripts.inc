AnconnaTown_Lab_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, AnconnaTown_Lab_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

AnconnaTown_Lab_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 GAME_PROGRESS, 7, AnconnaLab_RecievePokedexFromMaxilliamCutscene
	.2byte 0


AnconnaLab_CannotGoUpstairs::
	lockall
	msgbox AnconnaLab_CannotGoUpstairs_Text_0
	waitmessage
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, WalkLeft
	waitmovement 0
	releaseall
	return


AnconnaLab_ProfMaxmilliam::
	lockall
	msgbox AnconnaLab_ProfMaxmilliam_Text_0, 2, AnconnaLab_ProfMaxmilliam_Text_1
	waitmessage
	releaseall
	return


AnconnaLab_Professor1::
	lockall
	msgbox AnconnaLab_Professor1_Text_0
	waitmessage
	releaseall
	return


AnconnaLab_Professor2::
	lockall
	msgbox AnconnaLab_Professor2_Text_0, 2
	waitmessage
	releaseall
	return


AnconnaLab_Professor3::
	lockall
	msgbox AnconnaLab_Professor3_Text_0, 2
	waitmessage
	applymovement 4, FaceUp
	waitmovement 0
	releaseall
	return


AnconnaLab_RecievePokedexFromMaxilliamCutscene::
	lockall
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, PlayerWalksUpToMaxmilliamToRecievePokedex
	applymovement OBJ_EVENT_ID_PLAYER, PlayerWalksUpToMaxmilliamToRecievePokedex
	waitmovement 0
	applymovement 1, WalkInPlaceDown
	waitmovement 0
	msgbox AnconnaLab_RecievePokedexFromMaxilliamCutscene_Text_0, , AnconnaLab_RecievePokedexFromMaxilliamCutscene_Text_1
	waitmessage
	closemessage
	playfanfare MUS_OBTAIN_ITEM
	msgbox AnconnaLab_RecievePokedexFromMaxilliamCutscene_Text_2
	setflag FLAG_SYS_POKEDEX_GET
	setflag FLAG_SYS_NATIONAL_DEX
	waitfanfare
	msgbox AnconnaLab_RecievePokedexFromMaxilliamCutscene_Text_3, , AnconnaLab_RecievePokedexFromMaxilliamCutscene_Text_1
	waitmessage
	special RemoveCameraObject
	addvar GAME_PROGRESS, 1
	releaseall
	return


PlayerWalksUpToMaxmilliamToRecievePokedex:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	face_up
	step_end

AnconnaLab_CannotGoUpstairs_Text_0:
	.string "This should probably lead to somewhere\n"
	.string "private so I won't go there$"

AnconnaLab_ProfMaxmilliam_Text_0:
	.string "{COLOR BLUE}Don't worry about what happened, I'll\n"
	.string "make sure its resolved quickly.$"

AnconnaLab_ProfMaxmilliam_Text_1:
	.string "Prof. Max$"

AnconnaLab_Professor1_Text_0:
	.string "{COLOR BLUE}So much to do in such little time..\p"
	.string "Sigh..$"

AnconnaLab_Professor2_Text_0:
	.string "{COLOR BLUE}We're researching on the variety of wild\n"
	.string "pokemon here and its pretty\l"
	.string "interesting.$"

AnconnaLab_Professor3_Text_0:
	.string "{COLOR BLUE}My job is to keep tabs on all the\n"
	.string "results we get from our experiments.$"

AnconnaLab_RecievePokedexFromMaxilliamCutscene_Text_0:
	.string "{COLOR BLUE} Ahh, here it is.\n"
	.string "The Custom {COLOR GREEN}PokeDex{COLOR BLUE}.\p"
	.string "Make sure to return it once you're done.$"

AnconnaLab_RecievePokedexFromMaxilliamCutscene_Text_1:
	.string "Prof. Maxmilliam$"

AnconnaLab_RecievePokedexFromMaxilliamCutscene_Text_2:
	.string "{PLAYER} has received a Pokedex!$"

AnconnaLab_RecievePokedexFromMaxilliamCutscene_Text_3:
	.string "{COLOR BLUE}Now that you're well equipped, goodluck.\n"
	.string "Don't worry about what happened in the\l"
	.string "forest, I'll make sure its resolved\l"
	.string "quickly.$"
