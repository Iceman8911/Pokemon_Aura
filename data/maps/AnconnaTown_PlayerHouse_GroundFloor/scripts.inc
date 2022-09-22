AnconnaTown_PlayerHouse_GroundFloor_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AnconnaTown_PlayerHouse_GroundFloor_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, AnconnaTown_PlayerHouse_GroundFloor_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

AnconnaTown_PlayerHouse_GroundFloor_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	compare GAME_PROGRESS < 4, 0
	goto_if_ne AnconnaTown_PlayerHouse_GroundFloor_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	clearflag RIOLU_IS_IN_PLAYER_HOUSE
	addobject 4
	return

AnconnaTown_PlayerHouse_GroundFloor_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	setflag RIOLU_IS_IN_PLAYER_HOUSE
	return

AnconnaTown_PlayerHouse_GroundFloor_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 GAME_PROGRESS, 1, PlayerCameDownstairsAfterWakingUp
	map_script_2 GAME_PROGRESS, 3, EnterHouseWithRioluForFirstTime
	.2byte 0


EnterHouseWithRioluForFirstTime::
	lockall
	delay 60
	applymovement 1, MumRunsToYouAtHome
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, WalkInPlaceDown
	waitmovement 0
	msgbox EnterHouseWithRioluForFirstTime_Text_0
	waitmessage
	msgbox EnterHouseWithRioluForFirstTime_Text_1
	waitmessage
	msgbox EnterHouseWithRioluForFirstTime_Text_2
	waitmessage
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, PlayerRunsToFather
	waitmovement 0
	msgbox EnterHouseWithRioluForFirstTime_Text_3
	waitmessage
	msgbox EnterHouseWithRioluForFirstTime_Text_4
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	removeitem ITEM_BIG_MUSHROOM, 1
	removeitem ITEM_TINY_MUSHROOM, 2
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, PlayerRunsUpToTheTopOfTable
	waitmovement 0
	msgbox EnterHouseWithRioluForFirstTime_Text_5
	waitmessage
	closemessage
	applymovement 2, FaceUp
	applymovement 1, MomRunsBackToTheTable
	waitmovement 0
	msgbox EnterHouseWithRioluForFirstTime_Text_6
	waitmessage
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, FaceRight
	msgbox EnterHouseWithRioluForFirstTime_Text_7
	waitmessage
	closemessage
	fadescreen FADE_TO_WHITE
	clearflag RIOLU_IS_IN_PLAYER_HOUSE
	addobject 4
	fadescreen FADE_FROM_WHITE
	applymovement 4, RioluSearches
	waitmovement 0
	msgbox EnterHouseWithRioluForFirstTime_Text_8
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, FaceDown
	waitmovement 0
	msgbox EnterHouseWithRioluForFirstTime_Text_9
	applymovement 2, Surprised
	waitmovement 0
	msgbox EnterHouseWithRioluForFirstTime_Text_10
	waitmessage
	closemessage
	applymovement 2, FaceRight
	applymovement 1, FaceLeft
	waitmovement 0
	delay 60
	applymovement 2, FaceUp
	applymovement 1, FaceUp
	waitmovement 0
	msgbox EnterHouseWithRioluForFirstTime_Text_11
	waitmessage
	delay 30
	applymovement 1, MomExclaims
	waitmovement 0
	delay 25
	msgbox EnterHouseWithRioluForFirstTime_Text_12
	waitmessage
	closemessage
	applymovement 1, WalkInPlaceUp
	waitmovement 0
	msgbox EnterHouseWithRioluForFirstTime_Text_13
	waitmessage
	applymovement OBJ_EVENT_ID_PLAYER, WalkInPlaceDown
	waitmovement 0
	msgbox EnterHouseWithRioluForFirstTime_Text_14
	waitmessage
	applymovement OBJ_EVENT_ID_PLAYER, WalkInPlaceDown
	waitmovement 0
	msgbox EnterHouseWithRioluForFirstTime_Text_15
	waitmessage
	applymovement 1, WalkInPlaceUp
	waitmovement 0
	msgbox EnterHouseWithRioluForFirstTime_Text_16
	waitmessage
	applymovement 1, WalkInPlaceUp
	waitmovement 0
	msgbox EnterHouseWithRioluForFirstTime_Text_17
	waitmessage
	closemessage
	delay 50
	applymovement 1, FaceDown
	waitmovement 0
	msgbox EnterHouseWithRioluForFirstTime_Text_18
	waitmessage
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, WalkInPlaceDown
	waitmovement 0
	msgbox EnterHouseWithRioluForFirstTime_Text_19
	waitmessage
	closemessage
	applymovement 1, WalkInPlaceUp
	waitmovement 0
	msgbox EnterHouseWithRioluForFirstTime_Text_20
	waitmessage
	msgbox EnterHouseWithRioluForFirstTime_Text_21
	addvar GAME_PROGRESS, 1
	releaseall
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
	applymovement OBJ_EVENT_ID_PLAYER, FaceRight
	waitmovement 0
	msgbox PlayerCameDownstairsAfterWakingUp_Text_2
	waitmessage
	msgbox PlayerCameDownstairsAfterWakingUp_Text_3
	setflag FLAG_SYS_B_DASH
	setflag FLAG_RECEIVED_RUNNING_SHOES
	applymovement OBJ_EVENT_ID_PLAYER, FaceLeft
	waitmovement 0
	msgbox PlayerCameDownstairsAfterWakingUp_Text_4
	waitmessage
	msgbox PlayerCameDownstairsAfterWakingUp_Text_5
	waitmessage
	msgbox PlayerCameDownstairsAfterWakingUp_Text_6
	waitmessage
	msgbox PlayerCameDownstairsAfterWakingUp_Text_7
	waitmessage
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, FaceRight
	waitmovement 0
	msgbox PlayerCameDownstairsAfterWakingUp_Text_8
	closemessage
	applymovement 1, MumReturnsToSofa
	applymovement 2, DadReturnsToSofa
	waitmovement 0
	delay 90
	msgbox PlayerCameDownstairsAfterWakingUp_Text_9
	waitmessage
	special RemoveCameraObject
	addvar GAME_PROGRESS, 1
	releaseall
	return


Riolu::
	lockall
	faceplayer
	applymovement 4, Happy
	waitmovement 0
	msgbox Riolu_Text_0
	waitmessage
	msgbox Riolu_Text_1
	waitmessage
	releaseall
	return


AnconnaTown_PlayerHouse_Mum::
	lockall
	goto_if_unset ANCONNA_WOODS_MUSHROOMS, AnconnaTown_PlayerHouse_Mum_2
	compare GAME_PROGRESS, 4
	goto_if_eq AnconnaTown_PlayerHouse_Mum_3
	random 2
	switch VAR_RESULT
	case 0, AnconnaTown_PlayerHouse_Mum_8
	case 1, AnconnaTown_PlayerHouse_Mum_9
AnconnaTown_PlayerHouse_Mum_1:
	releaseall
	return

AnconnaTown_PlayerHouse_Mum_2:
	msgbox AnconnaTown_PlayerHouse_Mum_Text_0, 2
	waitmessage
	msgbox AnconnaTown_PlayerHouse_Mum_Text_1, 2
	waitmessage
	msgbox AnconnaTown_PlayerHouse_Mum_Text_2, 2
	waitmessage
	closemessage
	goto AnconnaTown_PlayerHouse_Mum_1

AnconnaTown_PlayerHouse_Mum_3:
	msgbox AnconnaTown_PlayerHouse_Mum_Text_3, 2
	waitmessage
	goto AnconnaTown_PlayerHouse_Mum_1

AnconnaTown_PlayerHouse_Mum_8:
	msgbox AnconnaTown_PlayerHouse_Mum_Text_4, 2
	goto AnconnaTown_PlayerHouse_Mum_1

AnconnaTown_PlayerHouse_Mum_9:
	msgbox AnconnaTown_PlayerHouse_Mum_Text_5, 2
	goto AnconnaTown_PlayerHouse_Mum_1


AnconnaTown_PlayerHouse_Dad::
	lockall
	goto_if_unset ANCONNA_WOODS_MUSHROOMS, AnconnaTown_PlayerHouse_Dad_1
	compare GAME_PROGRESS, 4
	goto_if_eq AnconnaTown_PlayerHouse_Dad_2
	random 2
	switch VAR_RESULT
	case 0, AnconnaTown_PlayerHouse_Dad_8
	case 1, AnconnaTown_PlayerHouse_Dad_9
AnconnaTown_PlayerHouse_Dad_6:
	releaseall
	return

AnconnaTown_PlayerHouse_Dad_1:
	msgbox AnconnaTown_PlayerHouse_Dad_Text_0, 2
	waitmessage
	msgbox AnconnaTown_PlayerHouse_Mum_Text_1, 2
	waitmessage
	msgbox AnconnaTown_PlayerHouse_Dad_Text_1, 2
	waitmessage
	closemessage
	return

AnconnaTown_PlayerHouse_Dad_2:
	msgbox AnconnaTown_PlayerHouse_Dad_Text_2, 2
	waitmessage
	closemessage
	return

AnconnaTown_PlayerHouse_Dad_8:
	msgbox AnconnaTown_PlayerHouse_Dad_Text_3, 2
	applymovement 2, FaceLeft
	delay 45
	msgbox AnconnaTown_PlayerHouse_Dad_Text_4
	goto AnconnaTown_PlayerHouse_Dad_6

AnconnaTown_PlayerHouse_Dad_9:
	msgbox AnconnaTown_PlayerHouse_Dad_Text_5, 2
	goto AnconnaTown_PlayerHouse_Dad_6


AnconnaTown_PlayerHouse_Blissey::
	lockall
	msgbox AnconnaTown_PlayerHouse_Blissey_Text_0, 2
	waitmessage
	msgbox AnconnaTown_PlayerHouse_Blissey_Text_1, 2
	goto_if_set FLAG_SYS_POKEMON_GET, AnconnaTown_PlayerHouse_Blissey_2
AnconnaTown_PlayerHouse_Blissey_1:
	releaseall
	return

AnconnaTown_PlayerHouse_Blissey_2:
	call Common_EventScript_OutOfCenterPartyHeal
	goto AnconnaTown_PlayerHouse_Blissey_1


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


MumComesToMeetYouAtTheStairCase:
	emote_exclamation_mark
	delay_16
	delay_16
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
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
	face_right
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
	step_end

DadWalksToYou:
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_left
	step_end

MumReturnsToSofa:
	walk_left
	walk_left
	walk_down
	face_right
	step_end

DadReturnsToSofa:
	walk_right
	walk_down
	face_left
	step_end

FaceRight:
	face_right
	step_end

PlayerRunsToFather:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	step_end

PlayerRunsUpToTheTopOfTable:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	face_down
	step_end

RioluSearches:
	face_up
	delay_16
	face_left
	delay_16
	face_right
	delay_16
	face_down
	delay_16
	emote_exclamation_mark
	step_end

Surprised:
	emote_exclamation_mark
	step_end

FaceUp:
	face_up
	step_end

WalkInPlaceUp:
	walk_in_place_up
	step_end

FaceDown:
	face_down
	step_end

MomRunsBackToTheTable:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_left
	face_up
	step_end

MomExclaims:
	emote_exclamation_mark
	jump_in_place_up
	step_end

Happy:
	emote_heart
	step_end

EnterHouseWithRioluForFirstTime_Text_0:
	.string "Mum: {COLOR RED}Waaah!!!$"

EnterHouseWithRioluForFirstTime_Text_1:
	.string "{COLOR RED}I heard awful loud noises coming from\n"
	.string "that forest and I was just about to\l"
	.string "rush there to get you.\p"
	.string "What happened in there?$"

EnterHouseWithRioluForFirstTime_Text_2:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: About that.....$"

EnterHouseWithRioluForFirstTime_Text_3:
	.string "Here are the mushrooms you requested...$"

EnterHouseWithRioluForFirstTime_Text_4:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY} gave the mushrooms!$"

EnterHouseWithRioluForFirstTime_Text_5:
	.string "Erhem...$"

EnterHouseWithRioluForFirstTime_Text_6:
	.string "Just outside our house, I overheard a\n"
	.string "group of {COLOR GREEN}three{COLOR DARK_GRAY} strange looking people\l"
	.string "talking about getting a particular\l"
	.string "Pokemon from the forest just before\l"
	.string "they entered it. I trailed them since\l"
	.string "they looked suspicious and eventually\l"
	.string "I heard two voices shouting about\l"
	.string "someone going missing. Deeper into the\l"
	.string "forest where I was to get the\l"
	.string "mushrooms, I found....\p"
	.string "Well, its better to show it.$"

EnterHouseWithRioluForFirstTime_Text_7:
	.string "You can come out now, Riolu.$"

EnterHouseWithRioluForFirstTime_Text_8:
	.string "{COLOR GREEN}Riiolu?$"

EnterHouseWithRioluForFirstTime_Text_9:
	.string "I found it lost at the edge of the\n"
	.string "forest and one of those people tried\l"
	.string "to take it from me so we battled.$"

EnterHouseWithRioluForFirstTime_Text_10:
	.string "Dad:{COLOR BLUE} Wait, could it be...?!$"

EnterHouseWithRioluForFirstTime_Text_11:
	.string "{COLOR BLUE}Nah, it couldn't be....$"

EnterHouseWithRioluForFirstTime_Text_12:
	.string "Mom:{COLOR RED} It was VERY risky trying to go\n"
	.string "after them. What were you thinking?$"

EnterHouseWithRioluForFirstTime_Text_13:
	.string "{COLOR RED}However, you managed to save this\n"
	.string "Pokemon so at least it wasn't all in\l"
	.string "vain...\p"
	.string "....\p"
	.string "Do you remember that I was a scientist?$"

EnterHouseWithRioluForFirstTime_Text_14:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: Yeah, but how does that\n"
	.string "relate to this. Shouldn't we call the\l"
	.string "police or something?\p"
	.string "Mom:{COLOR RED} We will inform the authorities but\n"
	.string "in the mean time, your Father and I\l"
	.string "think it would be best if you meet up\l"
	.string "with an old colleague of mine in {COLOR GREEN}Scandi\l"
	.string "City{COLOR RED}. The fact that you now have a\l"
	.string "Riolu who trusts you and some\l"
	.string "proficiency in battling means that you\l"
	.string "should have little difficulty getting\l"
	.string "there.$"

EnterHouseWithRioluForFirstTime_Text_15:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: Are you sure that Riolu\n"
	.string "trusts me? It still looks a bit\l"
	.string "uncomfortable here.$"

EnterHouseWithRioluForFirstTime_Text_16:
	.string "Mom:{COLOR RED} I'm positive because Riolu are\n"
	.string "normally very distrusting Pokemon but\l"
	.string "this one followed you willingly.\p"
	.string "Well, I'd better call her now. Her name's\n"
	.string "{COLOR GREEN}Professor Flora{COLOR RED} by the way.$"

EnterHouseWithRioluForFirstTime_Text_17:
	.string "{COLOR RED}I doubt you'd remember her since you\n"
	.string "were very young the first time you met\l"
	.string "so you might need to ask around.$"

EnterHouseWithRioluForFirstTime_Text_18:
	.string "{COLOR RED}Sniff..sniff...\n"
	.string "My little boy's leaving me alone now.$"

EnterHouseWithRioluForFirstTime_Text_19:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: Y'know that I'm not a kid\n"
	.string "anymore.$"

EnterHouseWithRioluForFirstTime_Text_20:
	.string "{COLOR RED}I know but we planned on giving you a\n"
	.string "starter Pokemon today so you won't be\l"
	.string "too lonely but seeing you leaving for\l"
	.string "now with this Riolu....it makes me tear\l"
	.string "up.$"

EnterHouseWithRioluForFirstTime_Text_21:
	.string "{COLOR RED}Well,\p"
	.string "The earlier you go, the earlier you come\n"
	.string "back.\p"
	.string "Goodluck {COLOR GREEN}{PLAYER}{COLOR RED}!$"

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
	.string "Mum: {COLOR RED}This will make all your work faster\n"
	.string "but please don't use run around in the\l"
	.string "house. It took a lot of work to make it\l"
	.string "this clean.$"

PlayerCameDownstairsAfterWakingUp_Text_5:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: .....\p"
	.string "So this is just a way of telling me to do\n"
	.string "more work.$"

PlayerCameDownstairsAfterWakingUp_Text_6:
	.string "Mum: {COLOR RED}:D\p"
	.string ".....\p"
	.string "Maybe....$"

PlayerCameDownstairsAfterWakingUp_Text_7:
	.string "Dad: {COLOR BLUE}Um, I remember now!$"

PlayerCameDownstairsAfterWakingUp_Text_8:
	.string "{COLOR BLUE}Your Mother and I need you to fetch a\n"
	.string "{COLOR GREEN}Big Mushroom{COLOR BLUE} and two {COLOR GREEN}Tiny Mushrooms{COLOR BLUE}\l"
	.string "from {COLOR GREEN}Anconna Woods{COLOR BLUE}. Remember to watch\l"
	.string "out for the fallen logs there too!$"

PlayerCameDownstairsAfterWakingUp_Text_9:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: Sigh...\p"
	.string "I guess I'd better get going then.$"

Riolu_Text_0:
	.string "{COLOR GREEN}Rioooluu$"

Riolu_Text_1:
	.string "(It seems that Riolu feels safer with\n"
	.string "you around)$"

AnconnaTown_PlayerHouse_Mum_Text_0:
	.string "Mum: {COLOR RED}Don't forget to bring the\n"
	.string "{COLOR GREEN}mushrooms{COLOR RED}.$"

AnconnaTown_PlayerHouse_Mum_Text_1:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: Sigh...$"

AnconnaTown_PlayerHouse_Mum_Text_2:
	.string "Mum: {COLOR RED}Tehee...$"

AnconnaTown_PlayerHouse_Mum_Text_3:
	.string "Mum: {COLOR RED}If you ever need to heal up your\n"
	.string "Pokemon, my {COLOR GREEN}Blissey{COLOR RED} would gladly help.\p"
	.string "Don't worry, we'll tell your sister that\n"
	.string "you're leaving for now.$"

AnconnaTown_PlayerHouse_Mum_Text_4:
	.string "Mum: {COLOR RED}Its nice seeing you with Pokemon\n"
	.string "again sniff...sniff..$"

AnconnaTown_PlayerHouse_Mum_Text_5:
	.string "Mum: {COLOR RED}Your going on your own journey now\n"
	.string "but remember that your Father and I\l"
	.string "will always be there for you.$"

AnconnaTown_PlayerHouse_Dad_Text_0:
	.string "Dad: {COLOR BLUE}Don't forget to bring the\n"
	.string "{COLOR GREEN}mushrooms{COLOR BLUE}.$"

AnconnaTown_PlayerHouse_Dad_Text_1:
	.string "Dad: {COLOR BLUE}Don't sigh, son. It's all for a good\n"
	.string "cause :)$"

AnconnaTown_PlayerHouse_Dad_Text_2:
	.string "Dad: {COLOR BLUE}Well, your mother has said it all. If\n"
	.string "you ever forget how to {COLOR GREEN}Scandi City{COLOR BLUE}, you\l"
	.string "just need to pass through {COLOR GREEN}Route 01{COLOR BLUE}\l"
	.string "which is north of here and follow the\l"
	.string "path into {COLOR GREEN}Murky Grove{COLOR BLUE} then a short\l"
	.string "walk through {COLOR GREEN}Route 02{COLOR BLUE}. Goodluck!$"

AnconnaTown_PlayerHouse_Dad_Text_3:
	.string "Dad: {COLOR BLUE}I guess you don't need your old\n"
	.string "man anymore.$"

AnconnaTown_PlayerHouse_Dad_Text_4:
	.string "{COLOR BLUE}They grow up so fast...sniff...sniff..$"

AnconnaTown_PlayerHouse_Dad_Text_5:
	.string "Dad: {COLOR BLUE}You might be on your own journey\n"
	.string "but I'll always be with you by the\l"
	.string "sidelines chipping in every step of the\l"
	.string "way.$"

AnconnaTown_PlayerHouse_Blissey_Text_0:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: Morning, Blissey.$"

AnconnaTown_PlayerHouse_Blissey_Text_1:
	.string "{COLOR GREEN}Bliisseyyy!$"

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
