AnconnaWoods_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AnconnaWoods_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

AnconnaWoods_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	compare FIRST_LIUM_FIGHT, 0
	goto_if_eq AnconnaWoods_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

AnconnaWoods_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	setflag FLAG_TEMP_1
	return


Hide_Lium::
	return


Anconna_Woods_Sign::
	msgbox Anconna_Woods_Sign_Text_0
	closemessage
	return


Anconna_Woods_RareCandy::
	lock
	msgbox Anconna_Woods_RareCandy_Text_0
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, PlayerThinksAboutFirstLiumEncounter
	waitmovement 0
	delay 110
	applymovement OBJ_EVENT_ID_PLAYER, PlayerStillWantsBushSweet
	waitmovement 0
	msgbox Anconna_Woods_RareCandy_Text_1
	finditem ITEM_RARE_CANDY
	release
	return


AnconnaWoods_PlayerWantsItemBall::
	msgbox AnconnaWoods_PlayerWantsItemBall_Text_0
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, PlayerStillWantsItemBall
	waitmovement 0
	return


AnconnaWoods_PlayerWantsItemBallButCanNotJump::
	msgbox AnconnaWoods_PlayerWantsItemBallButCanNotJump_Text_0
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, PlayerStillWantsItemBall
	waitmovement 0
	return


AnconnaWoods_Not_Found_Riolu::
	lockall
	msgbox AnconnaWoods_Not_Found_Riolu_Text_0
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, NotFoundRiolu1
	waitmovement 0
	releaseall
	return


NotFoundRiolu1:
	walk_right
	step_end

AnconnaWoods_Not_Fought_Lium::
	lockall
	msgbox AnconnaWoods_Not_Fought_Lium_Text_0
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, NotFoughtLium
	waitmovement 0
	releaseall
	return


NotFoughtLium:
	walk_left
	step_end

AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu::
	lockall
	msgbox AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_0
	waitmessage
	msgbox AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_1
	waitmessage
	msgbox AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_2
	waitmessage
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, PlayerHearsSuspiciousPeople
	waitmovement 0
	load_speech_bubble OBJ_EVENT_ID_PLAYER
	msgbox AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_3
	destroy_speech_bubble
	waitmessage
	msgbox AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_4
	waitmessage
	msgbox AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_5
	waitmessage
	msgbox AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_6
	waitmessage
	msgbox AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_7
	closemessage
	delay 100
	msgbox AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_8
	waitmessage
	delay 90
	msgbox AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_9
	waitmessage
	msgbox AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_10
	waitmessage
	msgbox AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_11
	waitmessage
	msgbox AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_12
	delay 80
	applymovement OBJ_EVENT_ID_PLAYER, PlayerHearsSuspiciousPeople
	waitmovement 0
	load_speech_bubble OBJ_EVENT_ID_PLAYER
	msgbox AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_13
	destroy_speech_bubble
	setvar ANCONNA_TOWN_DISCOVERED_MYSTERIOUS_PEOPLE, 2
	releaseall
	return


AnconnaWoods_Lium::
	msgbox AnconnaWoods_Lium_Text_0
	closemessage
	return


Anconna_Woods_First_Lium_Fight::
	compare ANCONNA_WOODS_FOUND_RIOLU, 1
	goto_if_eq Anconna_Woods_First_Lium_Fight_1
	return

Anconna_Woods_First_Lium_Fight_1:
	lockall
	addobject 1
	msgbox Anconna_Woods_First_Lium_Fight_Text_0
	waitmessage
	closemessage
	applymovement 1, FirstLiumEncounter
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, PlayerTurnsToLium
	waitmovement 0
	load_speech_bubble 1
	msgbox Anconna_Woods_First_Lium_Fight_Text_1
	destroy_speech_bubble
	closemessage
	applymovement 1, LiumRemembersHisMission
	waitmovement 0
	load_speech_bubble 1
	msgbox Anconna_Woods_First_Lium_Fight_Text_2
	destroy_speech_bubble
	closemessage
	load_speech_bubble OBJ_EVENT_ID_PLAYER
	msgbox Anconna_Woods_First_Lium_Fight_Text_3
	destroy_speech_bubble
	closemessage
	applymovement 1, LiumisAstonished
	waitmovement 0
	load_speech_bubble 1
	msgbox Anconna_Woods_First_Lium_Fight_Text_4
	destroy_speech_bubble
	closemessage
	applymovement 1, LiumisAstonishedNot
	waitmovement 0
	load_speech_bubble 1
	msgbox Anconna_Woods_First_Lium_Fight_Text_5
	destroy_speech_bubble
	cleartrainerflag TRAINER_AQUA_GRUNT_LIUM
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_AQUA_GRUNT_LIUM, 1, PlayerBattleLiumText, Anconna_Woods_First_Lium_Fight_Text_6, Anconna_Woods_First_Lium_Fight_Won
	return


Anconna_Woods_First_Lium_Fight_Won::
	load_speech_bubble 1
	msgbox Anconna_Woods_First_Lium_Fight_Won_Text_0
	destroy_speech_bubble
	closemessage
	applymovement 1, FirstLiumEncounterEnd
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, PlayerThinksAboutFirstLiumEncounter
	waitmovement 0
	msgbox Anconna_Woods_First_Lium_Fight_Won_Text_1
	closemessage
	removeobject 1
	setvar FIRST_LIUM_FIGHT, 1
	releaseall
	return


PlayerHearsSuspiciousPeople:
	walk_in_place_right
	step_end

FirstLiumEncounter:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

PlayerTurnsToLium:
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_up
	lock_facing_direction
	step_end

LiumRemembersHisMission:
	face_up
	delay_16
	delay_16
	delay_16
	emote_exclamation_mark
	face_down
	step_end

LiumisAstonished:
	lock_facing_direction
	jump_up
	delay_16
	delay_16
	delay_16
	step_end

LiumisAstonishedNot:
	walk_down
	step_end

FirstLiumEncounterEnd:
	unlock_facing_direction
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	delay_16
	delay_16
	delay_16
	step_end

PlayerThinksAboutFirstLiumEncounter:
	face_down
	step_end

PlayerStillWantsItemBall:
	walk_up
	step_end

PlayerStillWantsBushSweet:
	walk_in_place_right
	step_end

AnconnaWoods_BugCatcher1::
	load_speech_bubble 2
	trainerbattle_single BUG_CATCHER_1, AnconnaWoods_BugCatcher1_Text_0, AnconnaWoods_BugCatcher1_Text_1
	msgbox AnconnaWoods_BugCatcher1_Text_2, 2
	destroy_speech_bubble
	closemessage
	return


AnconnaWoods_BugCatcher2::
	load_speech_bubble 3
	trainerbattle_single BUG_CATCHER_2, AnconnaWoods_BugCatcher2_Text_0, AnconnaWoods_BugCatcher2_Text_1
	msgbox AnconnaWoods_BugCatcher2_Text_2
	destroy_speech_bubble
	closemessage
	return


AnconnaWoods_BugCatcher3::
	load_speech_bubble 4
	trainerbattle_single BUG_CATCHER_3, AnconnaWoods_BugCatcher3_Text_0, AnconnaWoods_BugCatcher3_Text_1
	msgbox AnconnaWoods_BugCatcher3_Text_2
	destroy_speech_bubble
	closemessage
	return


Anconna_Woods_Sign_Text_0:
	.string "Anconna Woods\p"
	.string "{RIGHT_ARROW} Anconna Town$"

Anconna_Woods_RareCandy_Text_0:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: Huh,\p"
	.string "It was just a piece of bush candy.\p"
	.string "Garbage!$"

Anconna_Woods_RareCandy_Text_1:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: But still,\p"
	.string "It wouldn't hurt to have it....$"

AnconnaWoods_PlayerWantsItemBall_Text_0:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: I would like to know what\n"
	.string "that item ball contains but wild\l"
	.string "Pokémon may jump out from that bush\l"
	.string "beside it.$"

AnconnaWoods_PlayerWantsItemBallButCanNotJump_Text_0:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: Even if I wanted that item\n"
	.string "ball, I couldn't jump from here.$"

AnconnaWoods_Not_Found_Riolu_Text_0:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: I can't go into bushes yet.\n"
	.string "Wild Pokémon may jump out at me.\p"
	.string "There has to be another way.$"

AnconnaWoods_Not_Fought_Lium_Text_0:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: There's a shorter path to\n"
	.string "my home,\p"
	.string "Lemme search further.$"

AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_0:
	.string "???: {COLOR RED}LIUM! LIUM!! WHERE ARE YOU LIUM!!!$"

AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_1:
	.string "???: {COLOR BLUE}I told you. Bringing fresh recruits\n"
	.string "to important missions is always a bad\l"
	.string "idea. Look at what that boy has done,\l"
	.string "he's messed everything up AGAIN. It's\l"
	.string "better we leave him here, serves him\l"
	.string "right.$"

AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_2:
	.string "???: {COLOR RED}HOW COULD YOU SAY THAT NOW!\p"
	.string "Lium is MISSING and we have no idea\n"
	.string "where he is now. We can't leave him\l"
	.string "behind. No matter the cost, we must\l"
	.string "find him. I promised his mothe...$"

AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_3:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: Yup, that's them.\p"
	.string "......\p"
	.string "So one of them is missing and that is\n"
	.string "halting their 'plan', whatever that may\l"
	.string "be...$"

AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_4:
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Rioluuuuuuuuuuuu!$"

AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_5:
	.string "???: {COLOR BLUE}Forget Lium. That was the cry of\n"
	.string "the Pokémon we've been looking for, at\l"
	.string "least today wouldn't be a complete\l"
	.string "failure.\p"
	.string "You can keep looking for him, I'll go for\n"
	.string "something more reasonable.$"

AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_6:
	.string "???: {COLOR RED}I KNOW YOU'VE NEVER LIKED HIM.\p"
	.string "BUT HE'S ONE OF US!\p"
	.string "We can't abandon him here, he's too\n"
	.string "young to survive here alone.$"

AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_7:
	.string "???: {COLOR BLUE}You've made your choice, Alicia.\n"
	.string "Now, its time for me to claim my prize.$"

AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_8:
	.string "{COLOR BLUE}.........\p"
	.string ".....\p"
	.string "Drat, where's my pokeball.\p"
	.string "I'm sure I brought it with me.$"

AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_9:
	.string "{COLOR BLUE}Oh no, he must have took it. When I get\n"
	.string "my hands on him, he's gonna be sorry.$"

AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_10:
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Ri rio riolu riolu!$"

AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_11:
	.string "Alicia: {COLOR RED}Now, I guess you have no other\n"
	.string "option than to help me find him since\l"
	.string "the Pokémon escaped us.$"

AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_12:
	.string "???: (inaudible mumbling)$"

AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_13:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: So they've given up on\n"
	.string "getting that Pokémon, I doubt that\l"
	.string "their original plans were any good\l"
	.string "since that Pokémon ran away from them.\p"
	.string "I think I should find it and bring it to\n"
	.string "Professor Flora before they change\l"
	.string "their mind.$"

AnconnaWoods_Lium_Text_0:
	.string "???: {COLOR BLUE}Deep Breaths.\p"
	.string "Take in Deep Breaths.\n"
	.string "I'll make it up.\p"
	.string "I can do this!$"

Anconna_Woods_First_Lium_Fight_Text_0:
	.string "???: {COLOR BLUE}Um, Hold IT RIGHT THERE!!!$"

Anconna_Woods_First_Lium_Fight_Text_1:
	.string "???: {COLOR BLUE}Huff-Puff\p"
	.string "(I'll never run like that again!\p"
	.string "Hmm, I didn't think that'll actually stop\n"
	.string "him. What do I do now?)$"

Anconna_Woods_First_Lium_Fight_Text_2:
	.string "???: {COLOR BLUE}Yeah, that's right. I ,uh, saw you in\n"
	.string "Anconna Woods with that rare Pokémon\l"
	.string "we've been looking for and ,uh, the boss\l"
	.string "said its my job to get that Pokémon\l"
	.string "back from you so hand it over.$"

Anconna_Woods_First_Lium_Fight_Text_3:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: So you're 'Lium'.\p"
	.string "Hmm.\p"
	.string "How about,\p"
	.string "NO!$"

Anconna_Woods_First_Lium_Fight_Text_4:
	.string "Lium: {COLOR BLUE}Uh?\p"
	.string "How do you know my name?$"

Anconna_Woods_First_Lium_Fight_Text_5:
	.string "{COLOR BLUE}Nevermind, it doesn't matter.\p"
	.string "I ask again: Surrender that Pokémon\n"
	.string "now.\p"
	.string "If you don't give it willingly, I'll have\n"
	.string "to take it by force.$"

Anconna_Woods_First_Lium_Fight_Text_6:
	.string "Poochyena, NOOOOO!$"

Anconna_Woods_First_Lium_Fight_Won_Text_0:
	.string "Lium: {COLOR BLUE}What have you done! You hurt my\n"
	.string "first Pokémon and I have no way of\l"
	.string "getting back safe now.\p"
	.string "No.\p"
	.string "No.\p"
	.string "No.\p"
	.string "No.\p"
	.string "NOOO!\p"
	.string "I really messed up this time. I need to\n"
	.string "get out of here!$"

Anconna_Woods_First_Lium_Fight_Won_Text_1:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: What was all that about?\p"
	.string "That guy was an obvious noob but\n"
	.string "suspicious. Maybe I should tell mom and\l"
	.string "Professor Flora about him soon.\p"
	.string "Anyways, Let's get you healed, Riolu.$"

AnconnaWoods_BugCatcher1_Text_0:
	.string "{COLOR BLUE}I just started raising Bug Pokemon.\p"
	.string "Can you help me train them?$"

AnconnaWoods_BugCatcher1_Text_1:
	.string "That loss doesn't count.\p"
	.string "They're still grubs after all.$"

AnconnaWoods_BugCatcher1_Text_2:
	.string "{COLOR BLUE}Almost Every Bug Type starts off as a\n"
	.string "larvae.$"

AnconnaWoods_BugCatcher2_Text_0:
	.string "{COLOR BLUE}Bug Types grow pretty fast, but until\n"
	.string "they've reached their power spike.\p"
	.string "They're pretty.....\p"
	.string "Weak.$"

AnconnaWoods_BugCatcher2_Text_1:
	.string "I knew this would happen.$"

AnconnaWoods_BugCatcher2_Text_2:
	.string "{COLOR BLUE}Don't ask me why I have a full team of\n"
	.string "cocoons.\p"
	.string "Its.....\p"
	.string "Private.$"

AnconnaWoods_BugCatcher3_Text_0:
	.string "{COLOR BLUE}Bugs are Great.\p"
	.string "They grow fast and become powerful\n"
	.string "quickly.\p"
	.string "Lemme show you a taste of what I mean.$"

AnconnaWoods_BugCatcher3_Text_1:
	.string "But.....\p"
	.string "Bugs are supposed to dominate\n"
	.string "early-game.$"

AnconnaWoods_BugCatcher3_Text_2:
	.string "{COLOR BLUE}Maybe I should've evolved all my bugs.\p"
	.string "I'm sure I would've won then.$"

PlayerBattleLiumText::
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: You're not taking Riolu\n"
	.string "from me!\p"
	.string "Lium: {COLOR BLUE}We'll see about that.$"
