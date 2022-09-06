AnconnaWoods_1_MapScripts::
	.byte 0


AnconnaWoods_1_BugGem::
	lockall
	msgbox AnconnaWoods_1_BugGem_Text_0
	waitmessage
	finditem ITEM_BUG_GEM
	releaseall
	end


AnconnaWoods_1_Mushrooms::
	lockall
	msgbox MushroomText_1
	waitmessage
	finditem ITEM_BIG_MUSHROOM
	finditem ITEM_TINY_MUSHROOM, 2
	msgbox MushroomText_2
	waitmessage
	releaseall
	end


AnconnaWoods_1_Not_Found_Riolu::
	lockall
	msgbox AnconnaWoods_1_Not_Found_Riolu_Text_0
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, NotFoundRiolu
	waitmovement 0
	releaseall
	return


NotFoundRiolu:
	walk_up
	step_end

AnconnaWoods_1_Found_Riolu::
	lockall
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, PlayerConfused
	waitmovement 0
	msgbox AnconnaWoods_1_Found_Riolu_Text_0
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, PlayerFindsRiolu
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, WalkToRiolu
	waitmovement 0
	delay 60
	msgbox AnconnaWoods_1_Found_Riolu_Text_1
	waitmessage
	closemessage
	applymovement 3, RioluReacts
	waitmovement 0
	delay 20
	msgbox AnconnaWoods_1_Found_Riolu_Text_2
	msgbox AnconnaWoods_1_Found_Riolu_Text_3
	delay 17
	msgbox AnconnaWoods_1_Found_Riolu_Text_4
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, DodgeRiolu
	waitmovement 0
	applymovement 3, RioluRamsIntoYou
	waitmovement 0
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 5
	special ShakeCamera
	waitstate
	msgbox AnconnaWoods_1_Found_Riolu_Text_5
	waitmessage
	msgbox AnconnaWoods_1_Found_Riolu_Text_6
	waitmessage
	msgbox AnconnaWoods_1_Found_Riolu_Text_7
	waitmessage
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, TreatRiolu
	waitmovement 0
	msgbox AnconnaWoods_1_Found_Riolu_Text_8
	delay 35
	msgbox AnconnaWoods_1_Found_Riolu_Text_9
	playfanfare MUS_HEAL
	waitfanfare
	delay 15
	msgbox AnconnaWoods_1_Found_Riolu_Text_10
	applymovement OBJ_EVENT_ID_PLAYER, StepBackFromRiolu
	msgbox AnconnaWoods_1_Found_Riolu_Text_11
	closemessage
	applymovement 3, RioluTurnsAround
	waitmovement 0
	msgbox AnconnaWoods_1_Found_Riolu_Text_12
	closemessage
	applymovement 3, RioluApproachesYou
	waitmovement 0
	msgbox AnconnaWoods_1_Found_Riolu_Text_13
	applymovement 3, RioluLikesYou
	waitmovement 0
	msgbox AnconnaWoods_1_Found_Riolu_Text_14
	waitmessage
	msgbox AnconnaWoods_1_Found_Riolu_Text_15
	msgbox AnconnaWoods_1_Found_Riolu_Text_16
	waitmessage
	givecustommon SPECIES_RIOLU, 5, ITEM_FOCUS_SASH, , NATURE_HASTY, 0, , , , , , , , 31, , 31, 31
	msgbox AnconnaWoods_1_Found_Riolu_Text_17
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	delay 40
	msgbox AnconnaWoods_1_Found_Riolu_Text_18
	fadescreen FADE_TO_BLACK
	closemessage
	removeobject 3
	delay 50
	applymovement OBJ_EVENT_ID_PLAYER, AnconnaWoods_1You
	waitmovement 0
	fadescreen FADE_FROM_BLACK
	msgbox AnconnaWoods_1_Found_Riolu_Text_19
	setvar ANCONNA_WOODS_FOUND_RIOLU, 1
	releaseall
	return


AnconnaWoods_1You:
	walk_in_place_slow_right
	step_end

PlayerConfused:
	emote_exclamation_mark
	delay_16
	step_end

PlayerFindsRiolu:
	face_right
	step_end

WalkToRiolu:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	step_end

RioluReacts:
	face_left
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_up
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_left
	emote_exclamation_mark
	step_end

DodgeRiolu:
	walk_fast_up
	step_end

RioluRamsIntoYou:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

TreatRiolu:
	walk_fast_down
	walk_fast_left
	step_end

StepBackFromRiolu:
	walk_right
	face_left
	step_end

RioluTurnsAround:
	face_right
	step_end

RioluApproachesYou:
	walk_right
	step_end

RioluLikesYou:
	emote_question_mark
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	emote_heart
	step_end

AnconnaWoods_1_BugGem_Text_0:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: Why would anyone drop this\n"
	.string "here?\p"
	.string "Well, Their Loss!$"

AnconnaWoods_1_Not_Found_Riolu_Text_0:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: I can't go into bushes yet.\n"
	.string "Wild Pokémon may jump out at me.\p"
	.string "There has to be another way.$"

AnconnaWoods_1_Found_Riolu_Text_0:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: Huh?\p"
	.string "What is that?$"

AnconnaWoods_1_Found_Riolu_Text_1:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: Um?\p"
	.string "(What's a little Pokémon like this doing\n"
	.string "in a bug forest?\p"
	.string "Oh, it must be that Pokémon those\n"
	.string "people were looking for.)$"

AnconnaWoods_1_Found_Riolu_Text_2:
	.string "(It looks really scared of me..\p"
	.string "Maybe because of the strange people in\n"
	.string "the woods)\p"
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: How did you get he...$"

AnconnaWoods_1_Found_Riolu_Text_3:
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Rio Rioo..\p"
	.string "Rioluuu!!!$"

AnconnaWoods_1_Found_Riolu_Text_4:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: Wait!!!$"

AnconnaWoods_1_Found_Riolu_Text_5:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: Woah!\p"
	.string "(Why'd it try to attack me?)$"

AnconnaWoods_1_Found_Riolu_Text_6:
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Rio lu...$"

AnconnaWoods_1_Found_Riolu_Text_7:
	.string "{COLOR DARK_GRAY}(It looks like it injured itself though.)\p"
	.string "(I'd better help it quickly with my\n"
	.string "Potion.)$"

AnconnaWoods_1_Found_Riolu_Text_8:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: Easy does it!$"

AnconnaWoods_1_Found_Riolu_Text_9:
	.string "{PLAYER} used a Potion on the Injured\n"
	.string "Pokémon!$"

AnconnaWoods_1_Found_Riolu_Text_10:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: Done!$"

AnconnaWoods_1_Found_Riolu_Text_11:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: Doesn't that feel much\n"
	.string "better?$"

AnconnaWoods_1_Found_Riolu_Text_12:
	.string "{COLOR GREEN}Rio..\p"
	.string "Riolu?$"

AnconnaWoods_1_Found_Riolu_Text_13:
	.string "{COLOR DARK_GRAY}(It's coming closer again..)$"

AnconnaWoods_1_Found_Riolu_Text_14:
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Riolu Riolu!!$"

AnconnaWoods_1_Found_Riolu_Text_15:
	.string "(Could it be that..)\p"
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: Do you wanna come with me..\n"
	.string "'Riolu'?$"

AnconnaWoods_1_Found_Riolu_Text_16:
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Riolu Riolu Riolu!!!$"

AnconnaWoods_1_Found_Riolu_Text_17:
	.string "{COLOR DARK_GRAY}Riolu has joined your team!$"

AnconnaWoods_1_Found_Riolu_Text_18:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: I'll take that as a yes.\p"
	.string "Lets go to my house, Riolu.$"

AnconnaWoods_1_Found_Riolu_Text_19:
	.string "(The poor little thing is lost, probably\n"
	.string "because of those people from before.\p"
	.string "Lets see if there's anyway I can help.)$"

FoundBugGem::
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: Why would anyone drop this here?\p"
	.string "Well, Their Loss!$"

MushroomText_1::
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: Hmm, Some Mushrooms.$"

MushroomText_2::
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: Guess these could be handy.$"
