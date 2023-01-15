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
	msgbox Anconna_Woods_RareCandy_Text_0, , Anconna_Woods_RareCandy_Text_1
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, PlayerThinksAboutFirstLiumEncounter
	waitmovement 0
	delay 110
	applymovement OBJ_EVENT_ID_PLAYER, PlayerStillWantsBushSweet
	waitmovement 0
	msgbox Anconna_Woods_RareCandy_Text_2, , Anconna_Woods_RareCandy_Text_1
	finditem ITEM_RARE_CANDY
	release
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
	msgbox AnconnaWoods_Not_Fought_Lium_Text_0, , Anconna_Woods_RareCandy_Text_1
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
	msgbox AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_0, , AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_1
	waitmessage
	msgbox AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_2, , AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_1
	waitmessage
	msgbox AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_3, , AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_1
	waitmessage
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, PlayerHearsSuspiciousPeople
	waitmovement 0
	msgbox AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_4, , Anconna_Woods_RareCandy_Text_1
	waitmessage
	msgbox AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_5
	playmoncry SPECIES_RIOLU, CRY_MODE_NORMAL
	waitmoncry
	msgbox AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_6, , AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_1
	waitmessage
	msgbox AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_7, , AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_1
	waitmessage
	msgbox AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_8, , AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_1
	closemessage
	delay 100
	msgbox AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_9
	waitmessage
	delay 90
	msgbox AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_10
	waitmessage
	msgbox AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_11
	playmoncry SPECIES_RIOLU, CRY_MODE_NORMAL
	waitmoncry
	msgbox AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_12, , AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_13
	waitmessage
	msgbox AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_14, , AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_1
	delay 80
	applymovement OBJ_EVENT_ID_PLAYER, PlayerHearsSuspiciousPeople
	waitmovement 0
	msgbox AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_15, , Anconna_Woods_RareCandy_Text_1
	setvar ANCONNA_TOWN_DISCOVERED_MYSTERIOUS_PEOPLE, 2
	releaseall
	return


AnconnaWoods_Lium::
	msgbox AnconnaWoods_Lium_Text_0, , AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_1
	waitmessage
	msgbox AnconnaWoods_Lium_Text_1, , Anconna_Woods_RareCandy_Text_1
	closemessage
	return


Anconna_Woods_First_Lium_Fight::
	compare ANCONNA_WOODS_FOUND_RIOLU, 1
	goto_if_eq Anconna_Woods_First_Lium_Fight_1
	return

Anconna_Woods_First_Lium_Fight_1:
	lockall
	addobject 1
	msgbox Anconna_Woods_First_Lium_Fight_Text_0, , AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_1
	waitmessage
	closemessage
	applymovement 1, FirstLiumEncounter
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, PlayerTurnsToLium
	waitmovement 0
	msgbox Anconna_Woods_First_Lium_Fight_Text_1, , AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_1
	closemessage
	applymovement 1, LiumRemembersHisMission
	waitmovement 0
	msgbox Anconna_Woods_First_Lium_Fight_Text_2
	closemessage
	msgbox Anconna_Woods_First_Lium_Fight_Text_3, , Anconna_Woods_RareCandy_Text_1
	closemessage
	applymovement 1, LiumisAstonished
	waitmovement 0
	msgbox Anconna_Woods_First_Lium_Fight_Text_4, , Anconna_Woods_First_Lium_Fight_Text_5
	closemessage
	applymovement 1, LiumisAstonishedNot
	waitmovement 0
	msgbox Anconna_Woods_First_Lium_Fight_Text_6
	waitmessage
	msgbox Anconna_Woods_First_Lium_Fight_Text_7, , Anconna_Woods_RareCandy_Text_1
	waitmessage
	msgbox Anconna_Woods_First_Lium_Fight_Text_8, , Anconna_Woods_First_Lium_Fight_Text_5
	cleartrainerflag TRAINER_AQUA_GRUNT_LIUM
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_AQUA_GRUNT_LIUM, 1, PlayerBattleLiumText, Anconna_Woods_First_Lium_Fight_Text_9, Anconna_Woods_First_Lium_Fight_Won
	return


Anconna_Woods_First_Lium_Fight_Won::
	msgbox Anconna_Woods_First_Lium_Fight_Won_Text_0, , Anconna_Woods_First_Lium_Fight_Text_5
	closemessage
	applymovement 1, FirstLiumEncounterEnd
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, PlayerThinksAboutFirstLiumEncounter
	waitmovement 0
	msgbox Anconna_Woods_First_Lium_Fight_Won_Text_1, , Anconna_Woods_RareCandy_Text_1
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

PlayerStillWantsBushSweet:
	walk_in_place_right
	step_end

AnconnaWoods_BugCatcher1::
	trainerbattle_single BUG_CATCHER_1, AnconnaWoods_BugCatcher1_Text_0, AnconnaWoods_BugCatcher1_Text_1
	msgbox AnconnaWoods_BugCatcher1_Text_2, 2
	closemessage
	return


AnconnaWoods_BugCatcher2::
	trainerbattle_single BUG_CATCHER_2, AnconnaWoods_BugCatcher2_Text_0, AnconnaWoods_BugCatcher2_Text_1
	msgbox AnconnaWoods_BugCatcher2_Text_2
	closemessage
	return


AnconnaWoods_BugCatcher3::
	trainerbattle_single BUG_CATCHER_3, AnconnaWoods_BugCatcher3_Text_0, AnconnaWoods_BugCatcher3_Text_1
	msgbox AnconnaWoods_BugCatcher3_Text_2
	closemessage
	return


Anconna_Woods_Sign_Text_0:
	.string "Anconna Woods\p"
	.string "{RIGHT_ARROW} Anconna Town$"

Anconna_Woods_RareCandy_Text_0:
	.string "Huh..\p"
	.string "It's just a piece of bush candy.\p"
	.string "Garbage!$"

Anconna_Woods_RareCandy_Text_1:
	.string "{COLOR GREEN}{PLAYER}$"

Anconna_Woods_RareCandy_Text_2:
	.string "But still..\p"
	.string "It wouldn't hurt to have it....$"

AnconnaWoods_Not_Found_Riolu_Text_0:
	.string "Although its just bugs, it isn't safe to\n"
	.string "go into the bushes.\p"
	.string "There has to be another way.$"

AnconnaWoods_Not_Fought_Lium_Text_0:
	.string "I'm sure that there's a shorter path\n"
	.string "back home.\p"
	.string "I should search somewhere else.$"

AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_0:
	.string "{COLOR RED}LIUM! LIUM!! WHERE ARE YOU LIUM!!!$"

AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_1:
	.string "???$"

AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_2:
	.string "{COLOR BLUE}I told you. Bringing fresh recruits to\n"
	.string "important missions is always a bad\l"
	.string "idea. Look at what that boy has done,\l"
	.string "he's messed everything up AGAIN. I\l"
	.string "couldn't care less about fodder like\l"
	.string "him, serves him right.$"

AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_3:
	.string "{COLOR RED}HOW COULD YOU BE SO SELFISH!\p"
	.string "Lium is MISSING and we have no idea\n"
	.string "where he is now. We can't leave him\l"
	.string "behind. Regardless of what happened,\l"
	.string "we must find him. He's still a child\l"
	.string "after all...$"

AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_4:
	.string "I think that's them.\p"
	.string "......\p"
	.string "Sounds like one of them is missing?....\p"
	.string "And they don't seem to be moving\n"
	.string "forward...$"

AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_5:
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Rioluuuuuuuuuuuu!$"

AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_6:
	.string "{COLOR BLUE}Forget Lium. That was the cry of the\n"
	.string "Pokémon we've been looking for, at\l"
	.string "least today wouldn't be a complete\l"
	.string "failure.\p"
	.string "You can keep looking for him, I'll go for\n"
	.string "something more reasonable.$"

AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_7:
	.string "{COLOR RED}I know you've never like him\p"
	.string "BUT HOW CAN YOU BE THIS HEARTLESS!\p"
	.string "We can't abandon him here. What will\n"
	.string "happen if the residents in this town\l"
	.string "find him here?$"

AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_8:
	.string "{COLOR BLUE}You've made your choice, Alicia. But now,\n"
	.string "its time for me to claim my prize.$"

AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_9:
	.string "{COLOR BLUE}.........\p"
	.string ".....\p"
	.string "Drat, where's my pokeball?\p"
	.string "I'm sure I brought it with me.$"

AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_10:
	.string "{COLOR BLUE}Oh no no no no no no..\p"
	.string "He must have took it! When I get my\n"
	.string "hands on him, he's gonna be very sorry.$"

AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_11:
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Ri rio riolu riolu!$"

AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_12:
	.string "{COLOR RED}Hehe..\p"
	.string "Since that Pokémon escaped us, I guess\n"
	.string "you have no other option than to help\l"
	.string "me find him, do you?$"

AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_13:
	.string "Alicia$"

AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_14:
	.string "(inaudible mumbling)$"

AnconnaWoods_HeardYellsFromMysteriousPeopleAndRiolu_Text_15:
	.string "It sounds like they've given up on\n"
	.string "getting that Pokémon, I doubt that\l"
	.string "their original plans were any good\l"
	.string "since it ran away from them. I wonder\l"
	.string "where it might be now...$"

AnconnaWoods_Lium_Text_0:
	.string "{COLOR BLUE}Deep Breaths.\p"
	.string "Take in Deep Breaths.\n"
	.string "I'll make it up.\p"
	.string "I can do this!$"

AnconnaWoods_Lium_Text_1:
	.string "(This guy is probably deep in thought\n"
	.string "but he looks familiar...\p"
	.string "Wait!...)$"

Anconna_Woods_First_Lium_Fight_Text_0:
	.string "{COLOR BLUE}Um...\p"
	.string "Hold IT RIGHT THERE!!!$"

Anconna_Woods_First_Lium_Fight_Text_1:
	.string "{COLOR BLUE}Huff-puff...\p"
	.string "(Wait, he actually stopped. I didn't\n"
	.string "think it'll work, what do I do now?)$"

Anconna_Woods_First_Lium_Fight_Text_2:
	.string "{COLOR BLUE}Yeah, that's right! I saw you in Anconna\n"
	.string "Woods with that rare Pokémon we've\l"
	.string "been looking for and the boss said its\l"
	.string "my job to get it back from you so hand\l"
	.string "it over.$"

Anconna_Woods_First_Lium_Fight_Text_3:
	.string "So you're 'Lium'.\p"
	.string "Hmm...\p"
	.string "How about, NO!$"

Anconna_Woods_First_Lium_Fight_Text_4:
	.string "{COLOR BLUE}Uh?\p"
	.string "H-how do you know my name?$"

Anconna_Woods_First_Lium_Fight_Text_5:
	.string "Lium$"

Anconna_Woods_First_Lium_Fight_Text_6:
	.string "{COLOR BLUE}Nevermind, it doesn't matter.\p"
	.string "I'll ask again: Surrender that Pokémon\n"
	.string "now.\p"
	.string "If you don't give it willingly, I'll have\n"
	.string "to take it by force.$"

Anconna_Woods_First_Lium_Fight_Text_7:
	.string "Although I dislike battles, you're not\n"
	.string "taking Riolu away!$"

Anconna_Woods_First_Lium_Fight_Text_8:
	.string "You're pretty confident you can win.$"

Anconna_Woods_First_Lium_Fight_Text_9:
	.string "Poochyena, NOOOOO!$"

Anconna_Woods_First_Lium_Fight_Won_Text_0:
	.string "{COLOR BLUE}What have you done! My Pokémon's and I\n"
	.string "have no way of getting back safely\l"
	.string "now.\p"
	.string "No.\p"
	.string "No.\p"
	.string "No.\p"
	.string "No.\p"
	.string "NOOO!\p"
	.string "I really messed up this time. I need to\n"
	.string "get out of here!$"

Anconna_Woods_First_Lium_Fight_Won_Text_1:
	.string "What was all that about?\p"
	.string "That guy was obviously inexperienced\n"
	.string "but suspicious and probably the guy\l"
	.string "those other people were looking for.\p"
	.string "Anyways, Let's get you healed, Riolu.$"

AnconnaWoods_BugCatcher1_Text_0:
	.string "{COLOR BLUE}I just started raising Bug Pokemon.\p"
	.string "Can you help me train them?$"

AnconnaWoods_BugCatcher1_Text_1:
	.string "That loss doesn't count.\p"
	.string "They're still grubs after all.$"

AnconnaWoods_BugCatcher1_Text_2:
	.string "{COLOR BLUE}Almost every bug type starts off as a\n"
	.string "larvae.$"

AnconnaWoods_BugCatcher2_Text_0:
	.string "{COLOR BLUE}Bug types grow pretty fast, but until\n"
	.string "they've reached their power spike.\p"
	.string "They're pretty.....\p"
	.string "weak...$"

AnconnaWoods_BugCatcher2_Text_1:
	.string "I knew this would happen.$"

AnconnaWoods_BugCatcher2_Text_2:
	.string "{COLOR BLUE}Don't ask me why I have a full team of\n"
	.string "cocoons.\p"
	.string "Its.....\p"
	.string "private...$"

AnconnaWoods_BugCatcher3_Text_0:
	.string "{COLOR BLUE}Bugs are great.\p"
	.string "They grow fast and become powerful\n"
	.string "quickly.\p"
	.string "Lemme show you a taste of what I mean.$"

AnconnaWoods_BugCatcher3_Text_1:
	.string "But.....\p"
	.string "Bugs are supposed to dominate at early\n"
	.string "levels.$"

AnconnaWoods_BugCatcher3_Text_2:
	.string "{COLOR BLUE}Maybe I should've evolved all my bugs.\p"
	.string "I'm sure I would've won then.$"

PlayerBattleLiumText::
	.string "{COLOR BLUE}We'll see about that.$"
