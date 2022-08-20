AnconnaTown_MapScripts::
	.byte 0

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
	msgbox AnconnaTown_Bidoof_Text_0, 2
	waitmessage
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
	walk_left
	walk_left
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
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

AnconnaTown_Bidoof_Text_0:
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Doof?\n"
	.string "Bi Doof?\p"
	.string "Doooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooof!$"

AnconnaTown_EventScript_ProfessorLabSign_Text_0:
	.string "Professor Flora's Lab$"

AnconnaTown_EventScript_FatMan_Text_0:
	.string "{COLOR BLUE}{SHADOW LIGHT_BLUE}The Power Of Science is Astonishing!!!\p"
	.string "{PLAYER}, Do you know that recently,\n"
	.string "'ROM Hackers' have been able to update\l"
	.string "17 year old games with future\l"
	.string "generation expansions to create\l"
	.string "retouched retro games such as the\l"
	.string "'ROM Hack' you're playing right now!\p"
	.string "SCIENCE!!!$"

AnconnaTown_EventScript_LittleGirl_Text_0:
	.string "{COLOR RED}{SHADOW LIGHT_RED}I saw 3 strangers enter the forest. I\n"
	.string "wonder what they're doing there.$"

AnconnaTown_Woman_Text_0:
	.string "{COLOR RED}{SHADOW LIGHT_RED}I love this town!\p"
	.string "It's so simple and peaceful to live in.$"

Anconna_Town_Discovered_Mysterious_People_Text_0:
	.string "???: {COLOR BLUE}{SHADOW LIGHT_BLUE}Erhem.\p"
	.string "Now that we're here, I hope the both of\n"
	.string "you remember the pl...$"

Anconna_Town_Discovered_Mysterious_People_Text_1:
	.string "???: {COLOR RED}{SHADOW LIGHT_RED}Yeah, yeah, yeah. Find the escapee\n"
	.string "Pokémon and return it to our superiors\l"
	.string "ASAP. I know!$"

Anconna_Town_Discovered_Mysterious_People_Text_2:
	.string "???: {COLOR BLUE}{SHADOW LIGHT_BLUE}Me too!$"

Anconna_Town_Discovered_Mysterious_People_Text_3:
	.string "???: {COLOR BLUE}{SHADOW LIGHT_BLUE}Hmph.$"

Anconna_Town_Discovered_Mysterious_People_Text_4:
	.string "???: {COLOR BLUE}{SHADOW LIGHT_BLUE}Just needed to make sure. We can't\n"
	.string "have another slip-up this time, you\l"
	.string "hear?$"

Anconna_Town_Discovered_Mysterious_People_Text_5:
	.string "???: {COLOR BLUE}{SHADOW LIGHT_BLUE}You in the back, especially!$"

Anconna_Town_Discovered_Mysterious_People_Text_6:
	.string "???: {COLOR BLUE}{SHADOW LIGHT_BLUE}This Forest here is a huge maze. I\n"
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
	.string "???: {COLOR BLUE}{SHADOW LIGHT_BLUE}...With that in mind,..\p"
	.string "Lets move out!$"

Anconna_Town_Discovered_Mysterious_People_Text_9:
	.string "???: {COLOR RED}{SHADOW LIGHT_RED}Don't mind him, Lium. That's just\n"
	.string "how he is. Just focus on the mission\l"
	.string "for now, okay?$"

Anconna_Town_Discovered_Mysterious_People_Text_10:
	.string "Lium: {COLOR BLUE}{SHADOW LIGHT_BLUE}...Okay.$"

Anconna_Town_Discovered_Mysterious_People_Text_11:
	.string "???: {COLOR RED}{SHADOW LIGHT_RED}That's right. Cheer up and lets go.$"

Anconna_Town_Discovered_Mysterious_People_Text_12:
	.string "Lium: {COLOR BLUE}{SHADOW LIGHT_BLUE}Deep Breaths.\p"
	.string "I can do this!$"

Anconna_Town_Discovered_Mysterious_People_Text_13:
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}{PLAYER}{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}: Who the heck are they?\p"
	.string "And why are they entering our forest?\p"
	.string ".I haven't seen them around this place\n"
	.string "before.\p"
	.string "Hmm.\p"
	.string "They also seemed to be in a hurry and\n"
	.string "mentioned something about a plan.\l"
	.string "Maybe I should investigate this\l"
	.string "further.$"

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
	.string "{COLOR BLUE}{SHADOW LIGHT_BLUE}The Power Of Science is Astonishing!!!\p"
	.string "{PLAYER}, Do you know that recently,\n"
	.string "'ROM Hackers' have been able to update\l"
	.string "17 year old games with future generation\l"
	.string "expansions to create retouched retro\l"
	.string "games such as the 'ROM Hack' you're\l"
	.string "playing right now!\p"
	.string "SCIENCE!!!$"

LittleGirl::
	.string "{COLOR RED}{SHADOW LIGHT_RED}Oooh, I really want a small cute Pokémon.$"
