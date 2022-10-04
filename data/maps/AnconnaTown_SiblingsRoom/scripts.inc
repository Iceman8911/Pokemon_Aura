AnconnaTown_SiblingsRoom_MapScripts::
	.byte 0


SisterBidoofAtHome::
	lockall
	faceplayer
	applymovement 2, Happy
	playmoncry SPECIES_RIOLU, CRY_MODE_NORMAL
	waitmoncry
	msgbox SisterBidoofAtHome_Text_0, 2
	releaseall
	return


Anconna_Town_SisterAtHome::
	lockall
	switch VAR_TEMP_0
	case 0, Anconna_Town_SisterAtHome_3
	case 1, Anconna_Town_SisterAtHome_4
Anconna_Town_SisterAtHome_1:
	releaseall
	return

Anconna_Town_SisterAtHome_3:
	call Anconna_Town_SisterLostSomething_1
	goto Anconna_Town_SisterAtHome_1

Anconna_Town_SisterAtHome_4:
	call Anconna_Town_SisterLostSomething_2
	goto Anconna_Town_SisterAtHome_1


Anconna_Town_SisterLostSomething_1::
	compare GAME_PROGRESS, 6
	goto_if_lt Anconna_Town_SisterLostSomething_1_2
	random 2
	switch VAR_RESULT
	case 0, Anconna_Town_SisterLostSomething_1_7
	case 1, Anconna_Town_SisterLostSomething_1_8
Anconna_Town_SisterLostSomething_1_5:
	bufferdynamicmulti Anconna_Town_SisterLostSomething_1_Text_5, Anconna_Town_SisterLostSomething_1_Text_6
	multichoice 25, 7, MULTI_DYNAMIC_2, 1
	msgbox Anconna_Town_SisterLostSomething_1_Text_7
	waitmessage
	delay 70
	switch VAR_RESULT
	case 0, Anconna_Town_SisterLostSomething_1_10
	case 1, Anconna_Town_SisterLostSomething_1_11
Anconna_Town_SisterLostSomething_1_1:
	return

Anconna_Town_SisterLostSomething_1_2:
	msgbox Anconna_Town_SisterLostSomething_1_Text_0
	msgbox Anconna_Town_SisterLostSomething_1_Text_1
	waitmessage
	msgbox Anconna_Town_SisterLostSomething_1_Text_2
	waitmessage
	addvar VAR_TEMP_0, 1
	goto Anconna_Town_SisterLostSomething_1_1

Anconna_Town_SisterLostSomething_1_7:
	msgbox Anconna_Town_SisterLostSomething_1_Text_3, 2
	goto Anconna_Town_SisterLostSomething_1_5

Anconna_Town_SisterLostSomething_1_8:
	msgbox Anconna_Town_SisterLostSomething_1_Text_4, 2
	goto Anconna_Town_SisterLostSomething_1_5

Anconna_Town_SisterLostSomething_1_10:
	compare VAR_RESULT, 7
	goto_if_ne Anconna_Town_SisterLostSomething_1_12
	goto Anconna_Town_SisterLostSomething_1_1

Anconna_Town_SisterLostSomething_1_11:
	msgbox Anconna_Town_SisterLostSomething_1_Text_9, 2
	waitmessage
	goto Anconna_Town_SisterLostSomething_1_1

Anconna_Town_SisterLostSomething_1_12:
	msgbox Anconna_Town_SisterLostSomething_1_Text_8, 2
	goto Anconna_Town_SisterLostSomething_1_1


Anconna_Town_SisterLostSomething_2::
	msgbox Anconna_Town_SisterLostSomething_2_Text_0
	bufferdynamicmulti Anconna_Town_SisterLostSomething_2_Text_1, Anconna_Town_SisterLostSomething_2_Text_2
	multichoice 25, 7, MULTI_DYNAMIC_2, 1
	msgbox Anconna_Town_SisterLostSomething_2_Text_3
	waitmessage
	applymovement 1, Surprised
	waitmovement 0
	applymovement 1, FaceDown
	waitmovement 0
	msgbox Anconna_Town_SisterLostSomething_2_Text_4
	applymovement OBJ_EVENT_ID_PLAYER, FaceDown
	waitmovement 0
	delay 70
	applymovement OBJ_EVENT_ID_PLAYER, WalkInPlaceUp
	waitmovement 0
	msgbox Anconna_Town_SisterLostSomething_2_Text_5
	applymovement 1, WalkInPlaceDown
	waitmovement 0
	msgbox Anconna_Town_SisterLostSomething_2_Text_6
	waitmessage
	delay 30
	applymovement 1, FaceUp
	waitmovement 0
	delay 30
	msgbox Anconna_Town_SisterLostSomething_2_Text_7
	waitmessage
	delay 30
	msgbox Anconna_Town_SisterLostSomething_2_Text_8
	applymovement OBJ_EVENT_ID_PLAYER, WalkInPlaceUp
	waitmovement 0
	msgbox Anconna_Town_SisterLostSomething_2_Text_9
	waitmessage
	applymovement 1, Surprised
	waitmovement 0
	applymovement 1, FaceDown
	waitmovement 0
	msgbox Anconna_Town_SisterLostSomething_2_Text_10
	waitmessage
	applymovement 1, FaceUp
	waitmovement 0
	delay 50
	msgbox Anconna_Town_SisterLostSomething_2_Text_11
	setflag FLAG_SYS_QUEST_MENU_GET
	addvar GAME_PROGRESS, 1
	setvar VAR_TEMP_0, 0
	return


SisterBidoofAtHome_Text_0:
	.string "{COLOR GREEN}Bibby: Bi Dooooff...\p"
	.string "{COLOR DARK_GRAY}(Bidoof looks very snug and happy)$"

Anconna_Town_SisterLostSomething_1_Text_0:
	.string "i literally don't have a good name atm...\n"
	.string ":/$"

Anconna_Town_SisterLostSomething_1_Text_1:
	.string "Sis:{COLOR RED} Where is it?\p"
	.string "...\p"
	.string "WHERE THE HECK COULD THIS THING BE?$"

Anconna_Town_SisterLostSomething_1_Text_2:
	.string "(It does't seem like she noticed me,\n"
	.string "maybe I should try calling her again...)$"

Anconna_Town_SisterLostSomething_1_Text_3:
	.string "Sis:{COLOR RED} Did you find it yet?$"

Anconna_Town_SisterLostSomething_1_Text_4:
	.string "Sis:{COLOR RED} Have you found it yet?$"

Anconna_Town_SisterLostSomething_1_Text_5:
	.string "Yeah$"

Anconna_Town_SisterLostSomething_1_Text_6:
	.string "Not yet..$"

Anconna_Town_SisterLostSomething_1_Text_7:
	.string ".....$"

Anconna_Town_SisterLostSomething_1_Text_8:
	.string "Sis:{COLOR RED} If you didn't find it, why did you\n"
	.string "still say yes?$"

Anconna_Town_SisterLostSomething_1_Text_9:
	.string "Sis:{COLOR RED} Try checking {COLOR GREEN}everywhere{COLOR RED}. Who knows\n"
	.string "where it might be...$"

Anconna_Town_SisterLostSomething_2_Text_0:
	.string "(How should I call her...)$"

Anconna_Town_SisterLostSomething_2_Text_1:
	.string "SIS!$"

Anconna_Town_SisterLostSomething_2_Text_2:
	.string "HELLO?!$"

Anconna_Town_SisterLostSomething_2_Text_3:
	.string "Sis:{COLOR RED} WHAT DO YOU WANT?!!$"

Anconna_Town_SisterLostSomething_2_Text_4:
	.string "Sis:{COLOR RED} Oh\p"
	.string "I'm sorry about that. Its just that I'm\n"
	.string "in an awful mood now.\p"
	.string "I lost Bibby's new hair brush and I can't\n"
	.string "bare to tell him because it'll crush his\l"
	.string "little heart.\p"
	.string "Just look at how happy he is now.$"

Anconna_Town_SisterLostSomething_2_Text_5:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: Um, he looks norm-$"

Anconna_Town_SisterLostSomething_2_Text_6:
	.string "Sis:{COLOR RED} He might look like normal now but\n"
	.string "once he finds out...$"

Anconna_Town_SisterLostSomething_2_Text_7:
	.string "{COLOR RED}Sob sob...$"

Anconna_Town_SisterLostSomething_2_Text_8:
	.string "Sigh..$"

Anconna_Town_SisterLostSomething_2_Text_9:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: How about I search\n"
	.string "downstai-$"

Anconna_Town_SisterLostSomething_2_Text_10:
	.string "Sis:{COLOR RED} Thanks :D\p"
	.string "I'll keep on looking upstairs while you\n"
	.string "look downstairs.$"

Anconna_Town_SisterLostSomething_2_Text_11:
	.string "Why do I feel like I've been set up\n"
	.string "again..$"
