AnconnaTown_SiblingsRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AnconnaTown_SiblingsRoom_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

AnconnaTown_SiblingsRoom_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setflag RIOLU_IS_IN_PLAYER_HOUSE
	return


Anconna_Town_PlayerIsFacingUp::
	setvar VAR_TEMP_8, 1
	setvar VAR_TEMP_9, 1
	setvar VAR_TEMP_2, 0
	return


Anconna_Town_PlayerIsFacingLeft::
	setvar VAR_TEMP_8, 2
	setvar VAR_TEMP_9, 1
	setvar VAR_TEMP_2, 0
	return


Anconna_Town_PlayerIsFacingRight::
	setvar VAR_TEMP_8, 3
	setvar VAR_TEMP_9, 1
	setvar VAR_TEMP_2, 0
	return


ResetVar_Temp_9::
	setvar VAR_TEMP_9, 0
	setvar VAR_TEMP_2, 1
	return


SisterBidoofAtHome::
	lockall
	faceplayer
	applymovement 2, Happy
	playmoncry SPECIES_BIDOOF, CRY_MODE_NORMAL
	waitmoncry
	msgbox SisterBidoofAtHome_Text_0, 2
	releaseall
	return


Anconna_Town_SisterAtHome::
	lock
	switch VAR_TEMP_0
	case 0, Anconna_Town_SisterAtHome_3
	case 1, Anconna_Town_SisterAtHome_4
Anconna_Town_SisterAtHome_1:
	release
	return

Anconna_Town_SisterAtHome_3:
	call Anconna_TownSiblingMainScript
	goto Anconna_Town_SisterAtHome_1

Anconna_Town_SisterAtHome_4:
	call Anconna_Town_SisterLostSomething_1
	goto Anconna_Town_SisterAtHome_1


Anconna_TownSiblingMainScript::
	compare GAME_PROGRESS, 6
	goto_if_lt Anconna_TownSiblingMainScript_2
	compare GAME_PROGRESS, 6
	goto_if_eq Anconna_TownSiblingMainScript_3
	msgbox Anconna_TownSiblingMainScript_Text_22
	waitmessage
Anconna_TownSiblingMainScript_1:
	return

Anconna_TownSiblingMainScript_2:
	msgbox Anconna_TownSiblingMainScript_Text_0
	waitmessage
	msgbox Anconna_TownSiblingMainScript_Text_1
	waitmessage
	addvar VAR_TEMP_0, 1
	goto Anconna_TownSiblingMainScript_1

Anconna_TownSiblingMainScript_3:
	random 2
	faceplayer
	switch VAR_RESULT
	case 0, Anconna_TownSiblingMainScript_9
	case 1, Anconna_TownSiblingMainScript_10
Anconna_TownSiblingMainScript_7:
	bufferdynamicmulti Anconna_TownSiblingMainScript_Text_4, Anconna_TownSiblingMainScript_Text_5
	multichoice 25, 7, MULTI_DYNAMIC_2, 1
	msgbox Anconna_TownSiblingMainScript_Text_6
	waitmessage
	delay 50
	call AnconnaTownSiblingWalksInPlace
	switch VAR_RESULT
	case 0, Anconna_TownSiblingMainScript_12
	case 1, Anconna_TownSiblingMainScript_13
	goto Anconna_TownSiblingMainScript_1

Anconna_TownSiblingMainScript_9:
	msgbox Anconna_TownSiblingMainScript_Text_2
	goto Anconna_TownSiblingMainScript_7

Anconna_TownSiblingMainScript_10:
	msgbox Anconna_TownSiblingMainScript_Text_3
	goto Anconna_TownSiblingMainScript_7

Anconna_TownSiblingMainScript_12:
	compare VAR_RESULT, 7
	goto_if_ne Anconna_TownSiblingMainScript_14
	goto Anconna_TownSiblingMainScript_1

Anconna_TownSiblingMainScript_13:
	msgbox Anconna_TownSiblingMainScript_Text_21, 2
	waitmessage
	goto Anconna_TownSiblingMainScript_1

Anconna_TownSiblingMainScript_14:
	checkitem ITEM_BIDOOF_COMB, 1
	compare VAR_RESULT, 0
	goto_if_ne Anconna_TownSiblingMainScript_17
	msgbox Anconna_TownSiblingMainScript_Text_20, 2
	waitmessage
	goto Anconna_TownSiblingMainScript_1

Anconna_TownSiblingMainScript_17:
	msgbox Anconna_TownSiblingMainScript_Text_7
	removeitem ITEM_BIDOOF_COMB, 1
	playfanfare MUS_OBTAIN_ITEM
	msgbox Anconna_TownSiblingMainScript_Text_8
	waitmessage
	waitfanfare
	delay 25
	call AnconnaTownSiblingWalksInPlace
	msgbox Anconna_TownSiblingMainScript_Text_9
	call AnconnaTownPlayerWalksInPlace
	msgbox Anconna_TownSiblingMainScript_Text_10
	bufferdynamicmulti Anconna_TownSiblingMainScript_Text_11, Anconna_TownSiblingMainScript_Text_12
	call PlayerTellsSiblingAboutBidoofComb
	call AnconnaTownSiblingWalksInPlace
	msgbox Anconna_TownSiblingMainScript_Text_13
	call AnconnaTownPlayerWalksInPlace
	msgbox Anconna_TownSiblingMainScript_Text_14
	closemessage
	switch VAR_TEMP_8
	case 1, Anconna_TownSiblingMainScript_22
	case 2, Anconna_TownSiblingMainScript_23
	case 3, Anconna_TownSiblingMainScript_24
Anconna_TownSiblingMainScript_20:
	waitmovement 0
	msgbox Anconna_TownSiblingMainScript_Text_15
	fadescreen FADE_TO_WHITE
	call SpawnRioluInSiblingsRoom
	switch VAR_TEMP_8
	case 1, Anconna_TownSiblingMainScript_27
	case 2, Anconna_TownSiblingMainScript_28
	case 3, Anconna_TownSiblingMainScript_29
Anconna_TownSiblingMainScript_25:
	waitmovement 0
	msgbox Anconna_TownSiblingMainScript_Text_16
	waitmessage
	delay 60
	call RioluPunchesSiblingLol
	switch VAR_TEMP_8
	case 1, Anconna_TownSiblingMainScript_32
	case 2, Anconna_TownSiblingMainScript_33
	case 3, Anconna_TownSiblingMainScript_34
Anconna_TownSiblingMainScript_30:
	delay 45
	msgbox Anconna_TownSiblingMainScript_Text_17
	waitmessage
	delay 45
	switch VAR_TEMP_8
	case 1, Anconna_TownSiblingMainScript_37
	case 2, Anconna_TownSiblingMainScript_38
	case 3, Anconna_TownSiblingMainScript_39
Anconna_TownSiblingMainScript_35:
	waitmovement 0
	msgbox Anconna_TownSiblingMainScript_Text_18
	waitmessage
	giveitem ITEM_RARE_CANDY, 1
	msgbox Anconna_TownSiblingMainScript_Text_19
	waitmessage
	fadescreen FADE_TO_BLACK
	removeobject 3
	applymovement 1, FaceUp
	waitmovement 0
	fadescreen FADE_FROM_BLACK
	applymovement OBJ_EVENT_ID_PLAYER, Walk_Down
	waitmovement 0
	completequest QUEST_FIND_BIBBYS_COMB
	addvar GAME_PROGRESS, 1
	goto Anconna_TownSiblingMainScript_1

Anconna_TownSiblingMainScript_22:
	applymovement OBJ_EVENT_ID_PLAYER, FaceLeft
	goto Anconna_TownSiblingMainScript_20

Anconna_TownSiblingMainScript_23:
	applymovement OBJ_EVENT_ID_PLAYER, PlayerMovesRightThenDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, FaceUp
	goto Anconna_TownSiblingMainScript_20

Anconna_TownSiblingMainScript_24:
	applymovement OBJ_EVENT_ID_PLAYER, FaceDown
	goto Anconna_TownSiblingMainScript_20

Anconna_TownSiblingMainScript_27:
	applymovement 1, SiblingIsSurprised1
	goto Anconna_TownSiblingMainScript_25

Anconna_TownSiblingMainScript_28:
	applymovement 1, SiblingIsSurprised2
	goto Anconna_TownSiblingMainScript_25

Anconna_TownSiblingMainScript_29:
	applymovement 1, SiblingIsSurprised3
	goto Anconna_TownSiblingMainScript_25

Anconna_TownSiblingMainScript_32:
	applymovement 3, RioluJumpsAndTriesToPunchesSibling1
	waitmovement 0
	applymovement 1, SiblingFlies1
	waitmovement 0
	goto Anconna_TownSiblingMainScript_30

Anconna_TownSiblingMainScript_33:
	applymovement 3, RioluJumpsAndTriesToPunchesSibling2
	waitmovement 0
	applymovement 1, SiblingFlies2
	waitmovement 0
	goto Anconna_TownSiblingMainScript_30

Anconna_TownSiblingMainScript_34:
	applymovement 3, RioluJumpsAndTriesToPunchesSibling3
	waitmovement 0
	applymovement 1, SiblingFlies3
	waitmovement 0
	goto Anconna_TownSiblingMainScript_30

Anconna_TownSiblingMainScript_37:
	applymovement 1, Anconna_TownSiblingWalksTowardsPlayer1
	goto Anconna_TownSiblingMainScript_35

Anconna_TownSiblingMainScript_38:
	applymovement 1, Walk_Right
	goto Anconna_TownSiblingMainScript_35

Anconna_TownSiblingMainScript_39:
	applymovement 1, Anconna_TownSiblingWalksTowardsPlayer3
	goto Anconna_TownSiblingMainScript_35


Anconna_Town_SisterLostSomething_1::
	msgbox Anconna_Town_SisterLostSomething_1_Text_0
	bufferdynamicmulti Anconna_Town_SisterLostSomething_1_Text_1, Anconna_Town_SisterLostSomething_1_Text_2
	multichoice 25, 7, MULTI_DYNAMIC_2, 1
	switch VAR_TEMP_8
	case 1, Anconna_Town_SisterLostSomething_1_3
	case 2, Anconna_Town_SisterLostSomething_1_4
	case 3, Anconna_Town_SisterLostSomething_1_5
Anconna_Town_SisterLostSomething_1_1:
	msgbox Anconna_Town_SisterLostSomething_1_Text_3
	waitmessage
	applymovement 1, Surprised
	waitmovement 0
	msgbox Anconna_Town_SisterLostSomething_1_Text_4
	waitmessage
	closemessage
	applymovement 1, FaceDown
	applymovement OBJ_EVENT_ID_PLAYER, FaceDown
	waitmovement 0
	delay 70
	applymovement 2, AnconnaTown_BibbyTurnsAround
	waitmovement 0
	msgbox Anconna_Town_SisterLostSomething_1_Text_5
	call AnconnaTownPlayerWalksInPlace
	waitmovement 0
	msgbox Anconna_Town_SisterLostSomething_1_Text_6
	waitmessage
	closemessage
	delay 30
	applymovement 1, FaceUp
	waitmovement 0
	delay 30
	msgbox Anconna_Town_SisterLostSomething_1_Text_7
	waitmessage
	delay 60
	msgbox Anconna_Town_SisterLostSomething_1_Text_8
	switch VAR_TEMP_8
	case 1, Anconna_Town_SisterLostSomething_1_8
	case 2, Anconna_Town_SisterLostSomething_1_9
	case 3, Anconna_Town_SisterLostSomething_1_10
Anconna_Town_SisterLostSomething_1_6:
	waitmovement 0
	msgbox Anconna_Town_SisterLostSomething_1_Text_10
	waitmessage
	closemessage
	applymovement 1, FaceUp
	waitmovement 0
	delay 30
	switch VAR_TEMP_8
	case 1, Anconna_Town_SisterLostSomething_1_13
	case 3, Anconna_Town_SisterLostSomething_1_13
	case 2, Anconna_Town_SisterLostSomething_1_14
Anconna_Town_SisterLostSomething_1_11:
	delay 30
	msgbox Anconna_Town_SisterLostSomething_1_Text_11
	setflag FLAG_SYS_QUEST_MENU_GET
	call FindBibbyCombQuest
	addvar GAME_PROGRESS, 2
	setvar VAR_TEMP_0, 0
	return

Anconna_Town_SisterLostSomething_1_3:
	applymovement 1, FaceDown
	waitmovement 0
	goto Anconna_Town_SisterLostSomething_1_1

Anconna_Town_SisterLostSomething_1_4:
	applymovement 1, FaceRight
	waitmovement 0
	goto Anconna_Town_SisterLostSomething_1_1

Anconna_Town_SisterLostSomething_1_5:
	applymovement 1, FaceLeft
	waitmovement 0
	goto Anconna_Town_SisterLostSomething_1_1

Anconna_Town_SisterLostSomething_1_8:
	applymovement OBJ_EVENT_ID_PLAYER, WalkInPlaceUp
	waitmovement 0
	msgbox Anconna_Town_SisterLostSomething_1_Text_9
	waitmessage
	applymovement 1, Surprised
	waitmovement 0
	applymovement 1, FaceDown
	goto Anconna_Town_SisterLostSomething_1_6

Anconna_Town_SisterLostSomething_1_9:
	applymovement OBJ_EVENT_ID_PLAYER, WalkInPlaceLeft
	waitmovement 0
	msgbox Anconna_Town_SisterLostSomething_1_Text_9
	waitmessage
	applymovement 1, Surprised
	waitmovement 0
	applymovement 1, FaceRight
	goto Anconna_Town_SisterLostSomething_1_6

Anconna_Town_SisterLostSomething_1_10:
	applymovement OBJ_EVENT_ID_PLAYER, WalkInPlaceRight
	waitmovement 0
	msgbox Anconna_Town_SisterLostSomething_1_Text_9
	waitmessage
	applymovement 1, Surprised
	waitmovement 0
	applymovement 1, FaceLeft
	goto Anconna_Town_SisterLostSomething_1_6

Anconna_Town_SisterLostSomething_1_13:
	applymovement OBJ_EVENT_ID_PLAYER, Walk_Down
	goto Anconna_Town_SisterLostSomething_1_11

Anconna_Town_SisterLostSomething_1_14:
	applymovement OBJ_EVENT_ID_PLAYER, Walk_Right
	goto Anconna_Town_SisterLostSomething_1_11


FindBibbyCombQuest::
	delay 25
	playfanfare MUS_OBTAIN_BADGE
	msgbox FindBibbyCombQuest_Text_0
	waitfanfare
	questmenu QUEST_MENU_SET_ACTIVE, QUEST_FIND_BIBBYS_COMB
	return


AnconnaTownPlayerWalksInPlace::
	switch VAR_TEMP_8
	case 1, AnconnaTownPlayerWalksInPlace_3
	case 2, AnconnaTownPlayerWalksInPlace_4
	case 3, AnconnaTownPlayerWalksInPlace_5
AnconnaTownPlayerWalksInPlace_1:
	return

AnconnaTownPlayerWalksInPlace_3:
	applymovement OBJ_EVENT_ID_PLAYER, WalkInPlaceUp
	waitmovement 0
	goto AnconnaTownPlayerWalksInPlace_1

AnconnaTownPlayerWalksInPlace_4:
	applymovement OBJ_EVENT_ID_PLAYER, WalkInPlaceLeft
	waitmovement 0
	goto AnconnaTownPlayerWalksInPlace_1

AnconnaTownPlayerWalksInPlace_5:
	applymovement OBJ_EVENT_ID_PLAYER, WalkInPlaceRight
	waitmovement 0
	goto AnconnaTownPlayerWalksInPlace_1


AnconnaTownSiblingWalksInPlace::
	switch VAR_TEMP_8
	case 1, AnconnaTownSiblingWalksInPlace_3
	case 2, AnconnaTownSiblingWalksInPlace_4
	case 3, AnconnaTownSiblingWalksInPlace_5
AnconnaTownSiblingWalksInPlace_1:
	return

AnconnaTownSiblingWalksInPlace_3:
	applymovement 1, WalkInPlaceDown
	waitmovement 0
	goto AnconnaTownSiblingWalksInPlace_1

AnconnaTownSiblingWalksInPlace_4:
	applymovement 1, WalkInPlaceRight
	waitmovement 0
	goto AnconnaTownSiblingWalksInPlace_1

AnconnaTownSiblingWalksInPlace_5:
	applymovement 1, WalkInPlaceLeft
	waitmovement 0
	goto AnconnaTownSiblingWalksInPlace_1


PlayerTellsSiblingAboutBidoofComb::
	multichoice 25, 7, MULTI_DYNAMIC_2, 1
	switch VAR_RESULT
	case 0, PlayerTellsSiblingAboutBidoofComb_3
	case 1, PlayerTellsSiblingAboutBidoofComb_4
PlayerTellsSiblingAboutBidoofComb_1:
	return

PlayerTellsSiblingAboutBidoofComb_3:
	msgbox PlayerTellsSiblingAboutBidoofComb_Text_0
	goto PlayerTellsSiblingAboutBidoofComb_1

PlayerTellsSiblingAboutBidoofComb_4:
	msgbox PlayerTellsSiblingAboutBidoofComb_Text_1
	call PlayerTellsSiblingAboutBidoofComb
	goto PlayerTellsSiblingAboutBidoofComb_1


SpawnRioluInSiblingsRoom::
	clearflag RIOLU_IS_IN_PLAYER_HOUSE
	addobject 3
	switch VAR_TEMP_8
	case 0, SpawnRioluInSiblingsRoom_3
	case 1, SpawnRioluInSiblingsRoom_3
	case 2, SpawnRioluInSiblingsRoom_4
	case 3, SpawnRioluInSiblingsRoom_5
SpawnRioluInSiblingsRoom_1:
	waitmovement 0
	playmoncry SPECIES_RIOLU, CRY_MODE_NORMAL
	msgbox SpawnRioluInSiblingsRoom_Text_0
	waitmoncry
	return

SpawnRioluInSiblingsRoom_3:
	setobjectxy 3, 9, 7
	fadescreen FADE_FROM_WHITE
	applymovement OBJ_EVENT_ID_PLAYER, FaceUp
	applymovement 3, WalkInPlaceUp
	goto SpawnRioluInSiblingsRoom_1

SpawnRioluInSiblingsRoom_4:
	setobjectxy 3, 11, 6
	fadescreen FADE_FROM_WHITE
	applymovement OBJ_EVENT_ID_PLAYER, FaceLeft
	applymovement 3, WalkInPlaceLeft
	goto SpawnRioluInSiblingsRoom_1

SpawnRioluInSiblingsRoom_5:
	setobjectxy 3, 9, 7
	fadescreen FADE_FROM_WHITE
	applymovement OBJ_EVENT_ID_PLAYER, FaceRight
	applymovement 3, WalkInPlaceRight
	goto SpawnRioluInSiblingsRoom_1


RioluPunchesSiblingLol::
	switch VAR_TEMP_8
	case 0, RioluPunchesSiblingLol_2
	case 1, RioluPunchesSiblingLol_2
	case 2, RioluPunchesSiblingLol_3
	case 3, RioluPunchesSiblingLol_4
	return

RioluPunchesSiblingLol_2:
	applymovement 1, WalkLeftThenFaceDown
	waitmovement 0
	delay 60
	msgbox RioluPunchesSiblingLol_Text_0
	waitmessage
	playmoncry SPECIES_RIOLU, CRY_MODE_NORMAL
	msgbox RioluPunchesSiblingLol_Text_1
	waitmoncry
	return

RioluPunchesSiblingLol_3:
	msgbox RioluPunchesSiblingLol_Text_0
	waitmessage
	playmoncry SPECIES_RIOLU, CRY_MODE_NORMAL
	msgbox RioluPunchesSiblingLol_Text_1
	waitmoncry
	return

RioluPunchesSiblingLol_4:
	applymovement 1, WalkDownThenFaceLeft
	waitmovement 0
	msgbox RioluPunchesSiblingLol_Text_0
	waitmessage
	playmoncry SPECIES_RIOLU, CRY_MODE_NORMAL
	msgbox RioluPunchesSiblingLol_Text_1
	waitmoncry
	return


WalkInPlaceLeft:
	walk_in_place_left
	step_end

WalkInPlaceRight:
	walk_in_place_right
	step_end

AnconnaTown_BibbyTurnsAround:
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	face_right
	delay_16
	face_left
	delay_16
	face_right
	step_end

Walk_Right:
	walk_right
	step_end

PlayerMovesRightThenDown:
	walk_right
	walk_down
	step_end

SiblingIsSurprised1:
	emote_exclamation_mark
	delay_16
	delay_16
	jump_in_place_down
	step_end

SiblingIsSurprised2:
	emote_exclamation_mark
	delay_16
	delay_16
	jump_in_place_right
	step_end

SiblingIsSurprised3:
	emote_exclamation_mark
	delay_16
	delay_16
	jump_in_place_left
	step_end

WalkLeftThenFaceDown:
	walk_left
	face_down
	step_end

WalkDownThenFaceLeft:
	walk_down
	face_left
	step_end

RioluJumpsAndTriesToPunchesSibling1:
	jump_in_place_up
	delay_16
	step_end

RioluJumpsAndTriesToPunchesSibling2:
	jump_in_place_left
	delay_16
	step_end

RioluJumpsAndTriesToPunchesSibling3:
	jump_in_place_right
	delay_16
	step_end

SiblingFlies1:
	lock_facing_direction
	jump_up
	unlock_facing_direction
	step_end

SiblingFlies2:
	lock_facing_direction
	jump_left
	unlock_facing_direction
	step_end

SiblingFlies3:
	lock_facing_direction
	jump_right
	unlock_facing_direction
	step_end

Anconna_TownSiblingWalksTowardsPlayer1:
	walk_down
	walk_right
	face_player
	step_end

Anconna_TownSiblingWalksTowardsPlayer2:
	walk_up
	walk_left
	face_player
	step_end

Anconna_TownSiblingWalksTowardsPlayer3:
	walk_up
	walk_left
	face_player
	step_end

SisterBidoofAtHome_Text_0:
	.string "{COLOR GREEN}Bibby: Bi Dooooff...\p"
	.string "{COLOR DARK_GRAY}(Bidoof looks very snug and happy)$"

Anconna_TownSiblingMainScript_Text_0:
	.string "{SIBLING}:{COLOR RED} Where is it?\p"
	.string "...\p"
	.string "WHERE THE HECK COULD THIS THING BE?$"

Anconna_TownSiblingMainScript_Text_1:
	.string "(It does't seem like she noticed me,\n"
	.string "maybe I should try calling her again...)$"

Anconna_TownSiblingMainScript_Text_2:
	.string "{SIBLING}:{COLOR RED} Did you find it yet?$"

Anconna_TownSiblingMainScript_Text_3:
	.string "{SIBLING}:{COLOR RED} Have you found it yet?$"

Anconna_TownSiblingMainScript_Text_4:
	.string "Yeah$"

Anconna_TownSiblingMainScript_Text_5:
	.string "Not yet..$"

Anconna_TownSiblingMainScript_Text_6:
	.string ".....$"

Anconna_TownSiblingMainScript_Text_7:
	.string "{SIBLING}:{COLOR RED} Yay :D!!!\n"
	.string "You found it!$"

Anconna_TownSiblingMainScript_Text_8:
	.string "You returned the Ugly Comb!$"

Anconna_TownSiblingMainScript_Text_9:
	.string "{SIBLING}:{COLOR RED} By the way, where did you\n"
	.string "find it?\p"
	.string "It was a secret gift I made for {COLOR GREEN}Bibby{COLOR RED} so\n"
	.string "I have no idea how it got lost...$"

Anconna_TownSiblingMainScript_Text_10:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: Well...$"

Anconna_TownSiblingMainScript_Text_11:
	.string "It was somewhere near the staircase..$"

Anconna_TownSiblingMainScript_Text_12:
	.string "It was in the trash bin..$"

Anconna_TownSiblingMainScript_Text_13:
	.string "{SIBLING}:{COLOR RED} Anyways, I believe you\n"
	.string "wanted to show me something since you\l"
	.string "came here in the first place.$"

Anconna_TownSiblingMainScript_Text_14:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: Yeah, about that..$"

Anconna_TownSiblingMainScript_Text_15:
	.string "You can come out now, Riolu.$"

Anconna_TownSiblingMainScript_Text_16:
	.string "{SIBLING}:{COLOR RED} Eeek!\p"
	.string "You got yourself a Pokemon! And its\n"
	.string "really cute :3\p"
	.string "Aww, lemme hug it!$"

Anconna_TownSiblingMainScript_Text_17:
	.string "{SIBLING}:{COLOR RED} Ouch :(\p"
	.string "I just wanted to hug it.$"

Anconna_TownSiblingMainScript_Text_18:
	.string "{SIBLING}:{COLOR RED} Its really strong though so\n"
	.string "take care of the little guy.\p"
	.string "Since {COLOR GREEN}Bibby{COLOR RED} and I don't train much, I'd\n"
	.string "like you both to have this. Take it as a\l"
	.string "reward for helping me earlier.$"

Anconna_TownSiblingMainScript_Text_19:
	.string "{SIBLING}:{COLOR RED} Thanks again for helping me\n"
	.string "find {COLOR GREEN}Bibby's{COLOR RED} comb. Now I can make him\l"
	.string "look all pretty again.$"

Anconna_TownSiblingMainScript_Text_20:
	.string "{SIBLING}:{COLOR RED} If you didn't find it, why\n"
	.string "did you still say yes?$"

Anconna_TownSiblingMainScript_Text_21:
	.string "{SIBLING}:{COLOR RED} Try checking {COLOR GREEN}everywhere{COLOR RED}\n"
	.string "again. Who knows where it might be...$"

Anconna_TownSiblingMainScript_Text_22:
	.string "{SIBLING}:{COLOR RED} Hmm, what should {COLOR GREEN}Bibby{COLOR RED} and\n"
	.string "I do...$"

Anconna_Town_SisterLostSomething_1_Text_0:
	.string "(How should I call her...)$"

Anconna_Town_SisterLostSomething_1_Text_1:
	.string "{SIBLING}!$"

Anconna_Town_SisterLostSomething_1_Text_2:
	.string "HELLO?!$"

Anconna_Town_SisterLostSomething_1_Text_3:
	.string "{SIBLING}:{COLOR RED} WHAT DO YOU WANT?!!$"

Anconna_Town_SisterLostSomething_1_Text_4:
	.string "{SIBLING}:{COLOR RED} Oh\p"
	.string "I'm sorry about that. Its just that I'm\n"
	.string "in an awful mood now.\p"
	.string "I lost {COLOR GREEN}Bibby's{COLOR RED} new hair brush and I can't\n"
	.string "bare to tell him because it'll crush his\l"
	.string "little heart.\p"
	.string "Just look at how happy he is now.$"

Anconna_Town_SisterLostSomething_1_Text_5:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: Um, he looks norm-$"

Anconna_Town_SisterLostSomething_1_Text_6:
	.string "{SIBLING}:{COLOR RED} He might look like normal\n"
	.string "now but once he finds out...$"

Anconna_Town_SisterLostSomething_1_Text_7:
	.string "{COLOR RED}Sob sob...$"

Anconna_Town_SisterLostSomething_1_Text_8:
	.string "Sigh..$"

Anconna_Town_SisterLostSomething_1_Text_9:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: How about I search\n"
	.string "downstai-$"

Anconna_Town_SisterLostSomething_1_Text_10:
	.string "{SIBLING}:{COLOR RED} Thanks :D\p"
	.string "I'll keep on looking upstairs while you\n"
	.string "look downstairs.$"

Anconna_Town_SisterLostSomething_1_Text_11:
	.string "Why do I feel like I've been set up\n"
	.string "again..$"

FindBibbyCombQuest_Text_0:
	.string "You have unlocked a New Quest!\p"
	.string "You can check it out in the Quests\n"
	.string "Section in the menu.$"

PlayerTellsSiblingAboutBidoofComb_Text_0:
	.string "{SIBLING}:{COLOR RED} Huh, I have no idea how it\n"
	.string "got there.$"

PlayerTellsSiblingAboutBidoofComb_Text_1:
	.string "{SIBLING}:{COLOR RED} ......\p"
	.string "Pffffft! That's impossible!\n"
	.string "Be serious, where did you actually find\l"
	.string "it?$"

SpawnRioluInSiblingsRoom_Text_0:
	.string "{COLOR GREEN}Rioluuuuuuu$"

RioluPunchesSiblingLol_Text_0:
	.string "{SIBLING}:{COLOR RED} So warm...$"

RioluPunchesSiblingLol_Text_1:
	.string "{COLOR GREEN}Riooluuuu!$"
