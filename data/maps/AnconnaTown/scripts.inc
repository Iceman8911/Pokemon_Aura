AnconnaTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AnconnaTown_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, AnconnaTown_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

AnconnaTown_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	compare VAR_TEMP_1, 0
	goto_if_eq AnconnaTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

AnconnaTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	compare GAME_PROGRESS, 7
	goto_if_ne AnconnaTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_4
AnconnaTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_3:
	addvar VAR_TEMP_1, 1
	return

AnconnaTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_4:
	setflag FLAG_TEMP_2
	goto AnconnaTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_3

AnconnaTown_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
	.2byte 0


AnconnaTown_Cannot_Leave_Anconna_Town::
	compare FIRST_LIUM_FIGHT, 0
	goto_if_eq AnconnaTown_Cannot_Leave_Anconna_Town_2
	compare GAME_PROGRESS, 7
	goto_if_eq AnconnaTown_Cannot_Leave_Anconna_Town_3
AnconnaTown_Cannot_Leave_Anconna_Town_1:
	addvar VAR_TEMP_9, 1
	return

AnconnaTown_Cannot_Leave_Anconna_Town_2:
	lockall
	msgbox AnconnaTown_Cannot_Leave_Anconna_Town_Text_0
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Walk_Down
	waitmovement 0
	releaseall
	goto AnconnaTown_Cannot_Leave_Anconna_Town_1

AnconnaTown_Cannot_Leave_Anconna_Town_3:
	call AnconnaTown_ProfessorMaxmilliam1
	goto AnconnaTown_Cannot_Leave_Anconna_Town_1


AnconnaTown_EventScript_Sign::
	lockall
	msgbox AnconnaSign
	releaseall
	end


AnconnaTown_EventScript_Antidote::
	lockall
	finditem ITEM_ANTIDOTE
	releaseall
	end


AnconnaTown_Bidoof::
	lockall
	playmoncry SPECIES_BIDOOF, CRY_MODE_NORMAL
	msgbox AnconnaTown_Bidoof_Text_0, 2
	waitmoncry
	releaseall
	end


AnconnaTown_EventScript_ArceusSign::
	lockall
	msgbox ArceusSign
	releaseall
	end


AnconnaTown_EventScript_ProfessorLabSign::
	lockall
	msgbox AnconnaTown_EventScript_ProfessorLabSign_Text_0
	releaseall
	end


AnconnaTown_EventScript_FatMan::
	lockall
	msgbox AnconnaTown_EventScript_FatMan_Text_0, 2
	waitmessage
	releaseall
	end


AnconnaTown_EventScript_LittleGirl::
	lockall
	compare ANCONNA_TOWN_DISCOVERED_MYSTERIOUS_PEOPLE, 1
	goto_if_eq AnconnaTown_EventScript_LittleGirl_2
	msgbox LittleGirl, 2
	waitmessage
AnconnaTown_EventScript_LittleGirl_1:
	releaseall
	end

AnconnaTown_EventScript_LittleGirl_2:
	msgbox AnconnaTown_EventScript_LittleGirl_Text_0, 2
	waitmessage
	goto AnconnaTown_EventScript_LittleGirl_1


AnconnaTown_Woman::
	lockall
	msgbox AnconnaTown_Woman_Text_0, 2
	waitmessage
	releaseall
	end


Anconna_Town_Discovered_Mysterious_People::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Exclaim
	waitmovement 0
	delay 30
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, PanToMysteriousPeople
	waitmovement 0
	applymovement 5, TalkRight
	waitmovement 0
	msgbox Anconna_Town_Discovered_Mysterious_People_Text_0
	waitmessage
	applymovement 6, TalkLeft
	waitmovement 0
	msgbox Anconna_Town_Discovered_Mysterious_People_Text_1
	waitmessage
	applymovement 7, TalkLeft
	waitmovement 0
	msgbox Anconna_Town_Discovered_Mysterious_People_Text_2
	applymovement 5, TalkLeft
	waitmovement 0
	msgbox Anconna_Town_Discovered_Mysterious_People_Text_3
	applymovement 5, TalkRight
	waitmovement 0
	msgbox Anconna_Town_Discovered_Mysterious_People_Text_4
	waitmessage
	applymovement 5, TalkRight
	waitmovement 0
	msgbox Anconna_Town_Discovered_Mysterious_People_Text_5
	closemessage
	applymovement 7, LiumIsAshamed
	waitmovement 0
	delay 30
	applymovement 5, TalkLeft
	waitmovement 0
	msgbox Anconna_Town_Discovered_Mysterious_People_Text_6
	waitmessage
	applymovement 7, TalkRight
	waitmovement 0
	msgbox Anconna_Town_Discovered_Mysterious_People_Text_7
	waitmessage
	applymovement 5, TalkLeft
	waitmovement 0
	msgbox Anconna_Town_Discovered_Mysterious_People_Text_8
	closemessage
	applymovement 5, TalkLeft
	delay 45
	removeobject 5
	delay 50
	applymovement 6, TalkRight
	waitmovement 0
	msgbox Anconna_Town_Discovered_Mysterious_People_Text_9
	closemessage
	delay 35
	applymovement 7, TalkLeft
	msgbox Anconna_Town_Discovered_Mysterious_People_Text_10
	applymovement 6, TalkRight
	waitmovement 0
	msgbox Anconna_Town_Discovered_Mysterious_People_Text_11
	closemessage
	applymovement 6, WalkLeft
	waitmovement 0
	delay 35
	removeobject 6
	delay 50
	msgbox Anconna_Town_Discovered_Mysterious_People_Text_12
	closemessage
	applymovement 7, LiumLeaves
	waitmovement 0
	delay 35
	removeobject 7
	delay 50
	applymovement OBJ_EVENT_ID_CAMERA, ReversePan
	waitmovement 0
	special RemoveCameraObject
	msgbox Anconna_Town_Discovered_Mysterious_People_Text_13
	setvar ANCONNA_TOWN_DISCOVERED_MYSTERIOUS_PEOPLE, 1
	releaseall
	return


AnconnaTown_JustCameOutOfForest::
	lockall
	msgbox AnconnaTown_JustCameOutOfForest_Text_0
	applymovement OBJ_EVENT_ID_PLAYER, WalkLeft
	waitmovement 0
	releaseall
	return


AnconnaTown_JustCameOutOfForest1::
	lockall
	msgbox AnconnaTown_JustCameOutOfForest_Text_0
	applymovement OBJ_EVENT_ID_PLAYER, Walk_Up
	waitmovement 0
	releaseall
	return


AnconnaTown_ProfessorMaxmilliam::
	lockall
	faceplayer
	msgbox AnconnaTown_ProfessorMaxmilliam_Text_0
	bufferdynamicmulti AnconnaTown_ProfessorMaxmilliam_Text_1, AnconnaTown_ProfessorMaxmilliam_Text_2
	multichoice 25, 7, MULTI_DYNAMIC_2, 1
	switch VAR_RESULT
	case 0, AnconnaTown_ProfessorMaxmilliam_3
	case 1, AnconnaTown_ProfessorMaxmilliam_4
AnconnaTown_ProfessorMaxmilliam_1:
	getplayerxy VAR_TEMP_2, VAR_TEMP_3
	compare VAR_TEMP_2, 18
	goto_if_eq AnconnaTown_ProfessorMaxmilliam_6
	applymovement 9, AnconnaTown_ProfMaxmilliamWalksBackToLab1
AnconnaTown_ProfessorMaxmilliam_5:
	waitmovement 0
	removeobject 9
	addvar GAME_PROGRESS, 1
	setflag FLAG_TEMP_1
	releaseall
	return

AnconnaTown_ProfessorMaxmilliam_3:
	msgbox AnconnaTown_ProfessorMaxmilliam_Text_3
	giveitem ITEM_POKE_BALL, 10
	msgbox AnconnaTown_ProfessorMaxmilliam_Text_4
	waitmessage
	goto AnconnaTown_ProfessorMaxmilliam_1

AnconnaTown_ProfessorMaxmilliam_4:
	msgbox AnconnaTown_ProfessorMaxmilliam_Text_5
	giveitem ITEM_POKE_BALL, 10
	msgbox AnconnaTown_ProfessorMaxmilliam_Text_4
	waitmessage
	goto AnconnaTown_ProfessorMaxmilliam_1

AnconnaTown_ProfessorMaxmilliam_6:
	applymovement 9, AnconnaTown_ProfMaxmilliamWalksBackToLab2
	goto AnconnaTown_ProfessorMaxmilliam_5


AnconnaTown_ProfessorMaxmilliam1::
	lockall
	msgbox AnconnaTown_ProfessorMaxmilliam1_Text_0
	waitmessage
	closemessage
	getplayerxy VAR_TEMP_2, VAR_TEMP_3
	compare VAR_TEMP_2, 17
	goto_if_eq AnconnaTown_ProfessorMaxmilliam1_2
	applymovement 9, AnconnaTown_ProfMaxMilliamRunsToPlayer_2
AnconnaTown_ProfessorMaxmilliam1_1:
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Surprised
	applymovement OBJ_EVENT_ID_PLAYER, FaceDown
	waitmovement 0
	msgbox AnconnaTown_ProfessorMaxmilliam1_Text_1
	bufferdynamicmulti AnconnaTown_ProfessorMaxmilliam_Text_1, AnconnaTown_ProfessorMaxmilliam_Text_2
	multichoice 25, 7, MULTI_DYNAMIC_2, 1
	switch VAR_RESULT
	case 0, AnconnaTown_ProfessorMaxmilliam1_7
	case 1, AnconnaTown_ProfessorMaxmilliam1_8
AnconnaTown_ProfessorMaxmilliam1_5:
	compare VAR_TEMP_2, 17
	goto_if_eq AnconnaTown_ProfessorMaxmilliam1_10
	applymovement 9, AnconnaTown_ProfMaxmilliamWalksBackToLabAfterRunningToPlayer2
AnconnaTown_ProfessorMaxmilliam1_9:
	waitmovement 0
	removeobject 9
	addvar GAME_PROGRESS, 1
	setflag FLAG_TEMP_1
	releaseall
	return

AnconnaTown_ProfessorMaxmilliam1_2:
	applymovement 9, AnconnaTown_ProfMaxMilliamRunsToPlayer_1
	goto AnconnaTown_ProfessorMaxmilliam1_1

AnconnaTown_ProfessorMaxmilliam1_7:
	msgbox AnconnaTown_ProfessorMaxmilliam_Text_3
	giveitem ITEM_POKE_BALL, 10
	msgbox AnconnaTown_ProfessorMaxmilliam_Text_4
	waitmessage
	goto AnconnaTown_ProfessorMaxmilliam1_5

AnconnaTown_ProfessorMaxmilliam1_8:
	msgbox AnconnaTown_ProfessorMaxmilliam_Text_5
	giveitem ITEM_POKE_BALL, 10
	msgbox AnconnaTown_ProfessorMaxmilliam_Text_4
	waitmessage
	closemessage
	goto AnconnaTown_ProfessorMaxmilliam1_5

AnconnaTown_ProfessorMaxmilliam1_10:
	applymovement 9, AnconnaTown_ProfMaxmilliamWalksBackToLabAfterRunningToPlayer1
	goto AnconnaTown_ProfessorMaxmilliam1_9


Exclaim:
	emote_exclamation_mark
	step_end

TalkRight:
	walk_in_place_slow_right
	step_end

TalkLeft:
	walk_in_place_slow_left
	step_end

FaceLeft:
	unlock_facing_direction
	face_left
	step_end

WalkLeft:
	unlock_facing_direction
	walk_fast_left
	step_end

PanToMysteriousPeople:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

LiumIsAshamed:
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	unlock_facing_direction
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_right
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

LiumLeaves:
	unlock_facing_direction
	walk_fast_left
	walk_fast_left
	step_end

ReversePan:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

Walk_Down:
	walk_down
	step_end

Walk_Up:
	walk_up
	step_end

MumRunsToYouAtHome:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

AnconnaTown_ProfMaxMilliamRunsToPlayer_1:
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_right
	walk_right
	walk_up
	face_player
	step_end

AnconnaTown_ProfMaxMilliamRunsToPlayer_2:
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_right
	walk_right
	walk_right
	walk_up
	face_player
	step_end

AnconnaTown_ProfMaxmilliamWalksBackToLab1:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

AnconnaTown_ProfMaxmilliamWalksBackToLab2:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

AnconnaTown_ProfMaxmilliamWalksBackToLabAfterRunningToPlayer1:
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

AnconnaTown_ProfMaxmilliamWalksBackToLabAfterRunningToPlayer2:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

AnconnaTown_Cannot_Leave_Anconna_Town_Text_0:
	.string "Should I really ignore what just\n"
	.string "happened now?$"

AnconnaTown_Bidoof_Text_0:
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Doof?\n"
	.string "Bi Doof?\p"
	.string "Dooooooooooooooooooooooooooooo\p"
	.string "oooooooooooooooooooooooooooooooooo\p"
	.string "oooooooooooooooooooooooooooooo\p"
	.string "ooooooooooooooooooooooooooooooof!$"

AnconnaTown_EventScript_ProfessorLabSign_Text_0:
	.string "Professor Maxilliam's Lab$"

AnconnaTown_EventScript_FatMan_Text_0:
	.string "{COLOR BLUE}The Power Of Science is Astonishing!!!\p"
	.string "{COLOR GREEN}{PLAYER}{COLOR BLUE}, Do you know that recently,\n"
	.string "'ROM Hackers' have been able to update\l"
	.string "17 year old games with future\l"
	.string "generation expansions to create\l"
	.string "retouched retro games such as the\l"
	.string "'ROM Hack' you're playing right now!\p"
	.string "SCIENCE!!!$"

AnconnaTown_EventScript_LittleGirl_Text_0:
	.string "{COLOR RED}I saw three strangers enter the forest.\n"
	.string "I wonder what they're doing there.$"

AnconnaTown_Woman_Text_0:
	.string "{COLOR RED}I love this town!\p"
	.string "It's so simple and peaceful to live in.$"

Anconna_Town_Discovered_Mysterious_People_Text_0:
	.string "???: {COLOR BLUE}Erhem.\p"
	.string "Now that we're here, I hope the both of\n"
	.string "you remember the pl...$"

Anconna_Town_Discovered_Mysterious_People_Text_1:
	.string "???: {COLOR RED}Yeah, yeah, yeah. Find the escapee\n"
	.string "Pokémon and return it to our superiors\l"
	.string "ASAP. I know!$"

Anconna_Town_Discovered_Mysterious_People_Text_2:
	.string "???: {COLOR BLUE}Me too!$"

Anconna_Town_Discovered_Mysterious_People_Text_3:
	.string "???: {COLOR BLUE}Hmph.$"

Anconna_Town_Discovered_Mysterious_People_Text_4:
	.string "???: {COLOR BLUE}Just needed to make sure. We can't\n"
	.string "have another slip-up this time, you\l"
	.string "hear?$"

Anconna_Town_Discovered_Mysterious_People_Text_5:
	.string "???: {COLOR BLUE}You in the back, especially!$"

Anconna_Town_Discovered_Mysterious_People_Text_6:
	.string "???: {COLOR BLUE}This Forest here is a huge maze. I\n"
	.string "say we should stick together. It might\l"
	.string "take longer but at least we wouldn't\l"
	.string "get lost.$"

Anconna_Town_Discovered_Mysterious_People_Text_7:
	.string "(If we all go together, we would never\n"
	.string "find that Pokémon in time. I'll have to\l"
	.string "divert in order to speed things up.\p"
	.string "Also, if I find the Pokémon by myself,\n"
	.string "he'll finally stop treating me like\l"
	.string "trash.$"

Anconna_Town_Discovered_Mysterious_People_Text_8:
	.string "???: {COLOR BLUE}...With that in mind,..\p"
	.string "Lets move out!$"

Anconna_Town_Discovered_Mysterious_People_Text_9:
	.string "???: {COLOR RED}Don't mind him, Lium. That's just\n"
	.string "how he is. Just focus on the mission\l"
	.string "for now, okay?$"

Anconna_Town_Discovered_Mysterious_People_Text_10:
	.string "Lium: {COLOR BLUE}...Okay.$"

Anconna_Town_Discovered_Mysterious_People_Text_11:
	.string "???: {COLOR RED}That's right. Cheer up and lets go.$"

Anconna_Town_Discovered_Mysterious_People_Text_12:
	.string "Lium: {COLOR BLUE}Deep Breaths.\p"
	.string "I can do this!$"

Anconna_Town_Discovered_Mysterious_People_Text_13:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: Who the heck are they?\p"
	.string "And why are they entering our forest?\p"
	.string "I haven't seen them around this place\n"
	.string "before.\p"
	.string "Hmm.\p"
	.string "They also seemed to be in a hurry and\n"
	.string "mentioned something about a plan.\p"
	.string "What could that possibly mean?$"

AnconnaTown_JustCameOutOfForest_Text_0:
	.string "(I still have to give the mushrooms back\n"
	.string "to my parents, right?)$"

AnconnaTown_ProfessorMaxmilliam_Text_0:
	.string "???:{COLOR BLUE} Goodday, {COLOR GREEN}{PLAYER}{COLOR BLUE}. I am the\n"
	.string "current Field Researcher here,\l"
	.string "{COLOR GREEN}Professor Maxmilliam{COLOR BLUE}.\p"
	.string "I heard quite a ruckus coming from that\n"
	.string "forest and I saw you coming out of it.\n"
	.string "Would you care to explain?$"

AnconnaTown_ProfessorMaxmilliam_Text_1:
	.string "I saw three people...$"

AnconnaTown_ProfessorMaxmilliam_Text_2:
	.string "I didn't see anything...$"

AnconnaTown_ProfessorMaxmilliam_Text_3:
	.string "Prof. Maxmilliam:{COLOR BLUE} I did see some\n"
	.string "suspicious people enter the forest\l"
	.string "earlier today. Nevertheless, I doubt\l"
	.string "you know anything about it.\p"
	.string "Since I took some of your time and it\n"
	.string "looks like you're heading out, take this\l"
	.string "as a compensation.$"

AnconnaTown_ProfessorMaxmilliam_Text_4:
	.string "{COLOR BLUE}Don't bother yourself with this\n"
	.string "situation, I'll make sure this is\l"
	.string "handled well.$"

AnconnaTown_ProfessorMaxmilliam_Text_5:
	.string "Prof. Maxmilliam:{COLOR BLUE} Sigh..\p"
	.string "Well, I saw three strange-looking\n"
	.string "people enter the forest earlier today.\l"
	.string "Nevertheless, I doubt you know\l"
	.string "anything about it.\p"
	.string "Since I took some of your time and it\n"
	.string "looks like you're heading out, take this\l"
	.string "as a compensation.$"

AnconnaTown_ProfessorMaxmilliam1_Text_0:
	.string "???:{COLOR BLUE} WAIT!!!$"

AnconnaTown_ProfessorMaxmilliam1_Text_1:
	.string "???:{COLOR BLUE} Huff-puff...\p"
	.string "Erhem..\p"
	.string "Goodday, {COLOR GREEN}{PLAYER}{COLOR BLUE}. I am the current\n"
	.string "Field Researcher here, {COLOR GREEN}Professor\l"
	.string "Maxmilliam{COLOR BLUE}.\p"
	.string "I heard quite a ruckus coming from that\n"
	.string "forest and I saw you coming out of it.\n"
	.string "Would you care to explain?$"

AnconnaSign::
	.string "Anconna Town\n"
	.string "'Shades Of Green Ever Lie'\p"
	.string "{DOWN_ARROW} Anconna Lake$"

ArceusSign::
	.string "ARCEUS\p"
	.string "It is said to be the very first Pokémon\n"
	.string "in existence and the Creator Of the\l"
	.string "Very Universe.$"

FatMan::
	.string "{COLOR BLUE}The Power Of Science is Astonishing!!!\p"
	.string "{PLAYER}, Do you know that recently,\n"
	.string "'ROM Hackers' have been able to update\l"
	.string "17 year old games with future generation\l"
	.string "expansions to create retouched retro\l"
	.string "games such as the 'ROM Hack' you're\l"
	.string "playing right now!\p"
	.string "SCIENCE!!!$"

LittleGirl::
	.string "{COLOR RED}Oooh, I really want a small cute Pokémon.$"
