AnconnaLake_MapScripts::
	.byte 0


AnconnaLake_FisherMan1::
	compare VAR_TEMP_0, 0
	goto_if_eq AnconnaLake_FisherMan1_1
	msgbox AnconnaLake_FisherMan1_Text_1, 2
	setvar VAR_TEMP_0, 0
	closemessage
	return

AnconnaLake_FisherMan1_1:
	msgbox AnconnaLake_FisherMan1_Text_0, 2
	setvar VAR_TEMP_0, 1
	closemessage
	return


AnconnaLake_FisherMan2::
	msgbox AnconnaLake_FisherMan2_Text_0, 2
	closemessage
	return


AnconnaLake_FisherMan3::
	lockall
	compare OBTAINED_OLD_ROD, 0
	goto_if_eq AnconnaLake_FisherMan3_2
	msgbox AnconnaLake_FisherMan3_Text_6, 2
AnconnaLake_FisherMan3_1:
	releaseall
	return

AnconnaLake_FisherMan3_2:
	msgbox AnconnaLake_FisherMan3_Text_0, 2
	yesnobox 25, 0
	compare VAR_RESULT, 1
	goto_if_eq AnconnaLake_FisherMan3_5
	msgbox AnconnaLake_FisherMan3_Text_4
	msgbox AnconnaLake_FisherMan3_Text_5
	releaseall
	goto AnconnaLake_FisherMan3_1

AnconnaLake_FisherMan3_5:
	msgbox AnconnaLake_FisherMan3_Text_1
	msgbox AnconnaLake_FisherMan3_Text_2
	giveitem ITEM_OLD_ROD
	setvar OBTAINED_OLD_ROD, 1
	msgbox AnconnaLake_FisherMan3_Text_3
	releaseall
	goto AnconnaLake_FisherMan3_1


AnconnaLake_FisherMan1_Text_0:
	.string "{COLOR BLUE}Today's a great day for fishing isn't it,\n"
	.string "{COLOR GREEN}{PLAYER}.$"

AnconnaLake_FisherMan1_Text_1:
	.string "{COLOR BLUE}So I invited my brothers over. Who\n"
	.string "knows what we'll catch today.$"

AnconnaLake_FisherMan2_Text_0:
	.string "{COLOR BLUE}My Brothers and I,\p"
	.string "We've been fishing together since...\p"
	.string "....\p"
	.string "We've been fishing together for so long,\n"
	.string "I've even forgotten haha.$"

AnconnaLake_FisherMan3_Text_0:
	.string "{COLOR BLUE}Hello there {COLOR BLUE}{PLAYER}, this weather's\n"
	.string "nice for some fishing.\p"
	.string "Say,\p"
	.string "Do you want to give a try?$"

AnconnaLake_FisherMan3_Text_1:
	.string "{COLOR GREEN}{PLAYER}: Sure, it could be fun.$"

AnconnaLake_FisherMan3_Text_2:
	.string "{COLOR BLUE}Thats nice. Infact, here's one of my {COLOR GREEN}Old\n"
	.string "Rods.)$"

AnconnaLake_FisherMan3_Text_3:
	.string "{COLOR BLUE}It's not the best but it's pretty great\n"
	.string "and you can keep it. It's only a spare\l"
	.string "after all.$"

AnconnaLake_FisherMan3_Text_4:
	.string "{COLOR GREEN}{PLAYER}: Um, I'm not sure I might like\n"
	.string "it.$"

AnconnaLake_FisherMan3_Text_5:
	.string "{COLOR BLUE}Oh.\p"
	.string "Well, in that case. I'll be seeing you\n"
	.string "later if you change your mind.$"

AnconnaLake_FisherMan3_Text_6:
	.string "{COLOR BLUE}How are the fish biting, {COLOR GREEN}{PLAYER}?$"
