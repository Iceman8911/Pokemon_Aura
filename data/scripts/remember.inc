Remember::
	lockall
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, WalkInPlaceDown
	waitmovement 0
	delay 30
	buffernumberstring 0, GAME_PROGRESS
	msgbox Remember_Text_0
	switch GAME_PROGRESS
	case 0, Remember_3
	case 1, Remember_3
	case 2, Remember_4
	case 3, Remember_5
	case 4, Remember_6
	case 5, Remember_7
	case 6, Remember_8
	case 7, Remember_9
	case 8, Remember_10
	case 9, Remember_10
Remember_1:
	waitmessage
	releaseall
	return

Remember_3:
	msgbox Remember_Text_1
	goto Remember_1

Remember_4:
	msgbox Remember_Text_2
	goto Remember_1

Remember_5:
	msgbox Remember_Text_3
	goto Remember_1

Remember_6:
	msgbox Remember_Text_4
	goto Remember_1

Remember_7:
	msgbox Remember_Text_5
	goto Remember_1

Remember_8:
	checkitem ITEM_BIDOOF_COMB, 1
	switch VAR_RESULT
	case 0, Remember_12
	case 1, Remember_13
	goto Remember_1

Remember_9:
	msgbox Remember_Text_8
	goto Remember_1

Remember_10:
	msgbox Remember_Text_9
	goto Remember_1

Remember_12:
	msgbox Remember_Text_6
	goto Remember_1

Remember_13:
	msgbox Remember_Text_7
	goto Remember_1


Remember_Text_0:
	.string "The Value Of Game_Progress is {STR_VAR_1}.  $"

Remember_Text_1:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: Time to start the day!$"

Remember_Text_2:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: Sigh..only the good\n"
	.string "mushrooms can be found in the deep\l"
	.string "parts of {COLOR GREEN}Anconna Forest{COLOR DARK_GRAY}...$"

Remember_Text_3:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: This was unexpected...\p"
	.string "I probably need to show my parents\n"
	.string "this...$"

Remember_Text_4:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: I'd better check up on\n"
	.string "little sister then....$"

Remember_Text_5:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: Time to go then....\p"
	.string "{COLOR GREEN}Riolu{COLOR DARK_GRAY}, are you with me?\p"
	.string "....\p"
	.string "{COLOR GREEN}Riol Rioluuuu!!{COLOR DARK_GRAY}$"

Remember_Text_6:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: Where could that {COLOR GREEN}Bidoof's\n"
	.string "comb{COLOR DARK_GRAY} be...$"

Remember_Text_7:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: Gotta return this to her..$"

Remember_Text_8:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: I'd better get going now..$"

Remember_Text_9:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: {COLOR GREEN}Scandi City{COLOR DARK_GRAY} is just beyond\n"
	.string "{COLOR GREEN}Route 01{COLOR DARK_GRAY} and {COLOR GREEN}Murky Grove{COLOR DARK_GRAY}, right?$"
