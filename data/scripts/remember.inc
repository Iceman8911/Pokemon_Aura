Remember::
	lockall
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, WalkInPlaceDown
	waitmovement 0
	delay 30
	switch GAME_PROGRESS
	case 0, Remember_3
	case 1, Remember_4
	case 2, Remember_5
	case 3, Remember_6
	case 4, Remember_7
	case 5, Remember_8
Remember_1:
	releaseall
	return

Remember_3:
	msgbox Remember_Text_0
	goto Remember_1

Remember_4:
	msgbox Remember_Text_0
	goto Remember_1

Remember_5:
	msgbox Remember_Text_1
	goto Remember_1

Remember_6:
	msgbox Remember_Text_2
	goto Remember_1

Remember_7:
	msgbox Remember_Text_3
	goto Remember_1

Remember_8:
	msgbox Remember_Text_4
	goto Remember_1


Remember_Text_0:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: Time to start the day!$"

Remember_Text_1:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: Sigh..only the good\n"
	.string "mushrooms can be found in the deep\l"
	.string "parts of {COLOR GREEN}Anconna Forest{COLOR DARK_GRAY}...$"

Remember_Text_2:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: This was unexpected...\p"
	.string "I probably need to show my parents\n"
	.string "this...$"

Remember_Text_3:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: I'd better check up on\n"
	.string "little sister then....$"

Remember_Text_4:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: Time to go then....\p"
	.string "{COLOR GREEN}Riolu{COLOR DARK_GRAY}, are you with me?\p"
	.string "....\p"
	.string "{COLOR GREEN}Riol Rioluuuu!!{COLOR DARK_GRAY}$"
