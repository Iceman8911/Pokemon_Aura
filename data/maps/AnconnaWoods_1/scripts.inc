AnconnaWoods_1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AnconnaWoods_1_ShowOrHideSpecialPokeballForRiolu_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, AnconnaWoods_1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

AnconnaWoods_1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 FLAG_TEMP_9, 0, AnconnaWoods_1_ShowOrHideSpecialPokeballForRiolu_FRAMETABLE
	.2byte 0


AnconnaWoods_1_ShowOrHideSpecialPokeballForRiolu_TRANSITION::
	goto_if_set RIOLU_ENCOUNTER, AnconnaWoods_1_ShowOrHideSpecialPokeballForRiolu_TRANSITION_1
	return

AnconnaWoods_1_ShowOrHideSpecialPokeballForRiolu_TRANSITION_1:
	removeobject 4
	setflag FLAG_TEMP_9
	return


AnconnaWoods_1_ShowOrHideSpecialPokeballForRiolu_FRAMETABLE::
	addobject 4
	return


AnconnaWoods_1_BugGem::
	lockall
	msgbox AnconnaWoods_1_BugGem_Text_0
	waitmessage
	finditem ITEM_BUG_GEM
	releaseall
	end


AnconnaWoods_1_SpecialPokeBallForRiolu::
	lockall
	finditem ITEM_POKE_BALL
	msgbox AnconnaWoods_1_SpecialPokeBallForRiolu_Text_0
	waitmessage
	releaseall
	return


AnconnaWoods_1_Mushrooms::
	lockall
	finditem ITEM_BIG_MUSHROOM
	finditem ITEM_TINY_MUSHROOM, 2
	msgbox AnconnaWoods_1_Mushrooms_Text_0
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
	walk_left
	step_end

AnconnaWoods_1_NotFoundMushrooms::
	lockall
	goto_if_unset ANCONNA_WOODS_MUSHROOMS, AnconnaWoods_1_NotFoundMushrooms_2
AnconnaWoods_1_NotFoundMushrooms_1:
	releaseall
	return

AnconnaWoods_1_NotFoundMushrooms_2:
	msgbox AnconnaWoods_1_NotFoundMushrooms_Text_0
	waitmessage
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, NotFoundRiolu
	waitmovement 0
	goto AnconnaWoods_1_NotFoundMushrooms_1


AnconnaWoods_1_Found_Riolu::
	lock
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, PlayerConfused
	waitmovement 0
	msgbox AnconnaWoods_1_Found_Riolu_Text_0, , AnconnaWoods_1_Found_Riolu_Text_1
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, PlayerFindsRiolu
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, WalkToRiolu
	waitmovement 0
	delay 60
	msgbox AnconnaWoods_1_Found_Riolu_Text_2, , AnconnaWoods_1_Found_Riolu_Text_1
	waitmessage
	closemessage
	applymovement 3, RioluReacts
	waitmovement 0
	delay 20
	msgbox AnconnaWoods_1_Found_Riolu_Text_3
	msgbox AnconnaWoods_1_Found_Riolu_Text_4
	delay 17
	msgbox AnconnaWoods_1_Found_Riolu_Text_5, , AnconnaWoods_1_Found_Riolu_Text_1
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
	msgbox AnconnaWoods_1_Found_Riolu_Text_6, , AnconnaWoods_1_Found_Riolu_Text_1
	waitmessage
	msgbox AnconnaWoods_1_Found_Riolu_Text_7
	playmoncry SPECIES_RIOLU, CRY_MODE_ENCOUNTER
	waitmoncry
	msgbox AnconnaWoods_1_Found_Riolu_Text_8, , AnconnaWoods_1_Found_Riolu_Text_1
	waitmessage
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, TreatRiolu
	waitmovement 0
	msgbox AnconnaWoods_1_Found_Riolu_Text_9, , AnconnaWoods_1_Found_Riolu_Text_1
	delay 35
	msgbox AnconnaWoods_1_Found_Riolu_Text_10
	playfanfare MUS_HEAL
	waitfanfare
	delay 15
	removeitem ITEM_POTION, 1
	msgbox AnconnaWoods_1_Found_Riolu_Text_11, , AnconnaWoods_1_Found_Riolu_Text_1
	applymovement OBJ_EVENT_ID_PLAYER, StepBackFromRiolu
	msgbox AnconnaWoods_1_Found_Riolu_Text_12
	closemessage
	applymovement 3, RioluTurnsAround
	waitmovement 0
	msgbox AnconnaWoods_1_Found_Riolu_Text_13
	playmoncry SPECIES_RIOLU, CRY_MODE_WEAK
	waitmoncry
	applymovement 3, RioluApproachesYou
	waitmovement 0
	msgbox AnconnaWoods_1_Found_Riolu_Text_14
	applymovement 3, RioluLikesYou
	waitmovement 0
	msgbox AnconnaWoods_1_Found_Riolu_Text_15
	waitmessage
	msgbox AnconnaWoods_1_Found_Riolu_Text_16, , AnconnaWoods_1_Found_Riolu_Text_1
	msgbox AnconnaWoods_1_Found_Riolu_Text_17
	playmoncry SPECIES_RIOLU, CRY_MODE_NORMAL
	waitmoncry
	givecustommon SPECIES_RIOLU, 5, ITEM_FOCUS_SASH, , NATURE_HASTY, 0, , , , , , , , 31, , 31, 31
	msgbox AnconnaWoods_1_Found_Riolu_Text_18
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	removeitem ITEM_POKE_BALL
	setflag FLAG_SYS_POKEMON_GET
	delay 40
	msgbox AnconnaWoods_1_Found_Riolu_Text_19, , AnconnaWoods_1_Found_Riolu_Text_1
	fadescreen FADE_TO_BLACK
	closemessage
	removeobject 3
	delay 50
	applymovement OBJ_EVENT_ID_PLAYER, AnconnaWoods_1You
	waitmovement 0
	fadescreen FADE_FROM_BLACK
	msgbox AnconnaWoods_1_Found_Riolu_Text_20
	setvar ANCONNA_WOODS_FOUND_RIOLU, 1
	addvar GAME_PROGRESS, 1
	release
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
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	face_right
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
	walk_in_place_down
	step_end

RioluRamsIntoYou:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

TreatRiolu:
	walk_fast_right
	walk_fast_down
	face_left
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
	.string "Why would anyone drop this here?\p"
	.string "Well, Their Loss!$"

AnconnaWoods_1_SpecialPokeBallForRiolu_Text_0:
	.string "A pokeball...\n"
	.string "Could be useful..$"

AnconnaWoods_1_Mushrooms_Text_0:
	.string "Now that I've found them, I can finally\n"
	.string "leave.$"

AnconnaWoods_1_Not_Found_Riolu_Text_0:
	.string "I can't go into bushes yet. Wild Pokémon\n"
	.string "may jump out at me.\p"
	.string "There has to be another way.$"

AnconnaWoods_1_NotFoundMushrooms_Text_0:
	.string "I'm sure those Mushrooms are around\n"
	.string "here somewhere.$"

AnconnaWoods_1_Found_Riolu_Text_0:
	.string "Huh?\p"
	.string "What is that?$"

AnconnaWoods_1_Found_Riolu_Text_1:
	.string "{COLOR GREEN}{PLAYER}$"

AnconnaWoods_1_Found_Riolu_Text_2:
	.string "Um?\p"
	.string "(What's a little Pokémon like this doing\n"
	.string "in a bug forest?\p"
	.string "Oh, it must be that Pokémon those\n"
	.string "people were looking for.)$"

AnconnaWoods_1_Found_Riolu_Text_3:
	.string "(It looks really scared of me..\p"
	.string "Maybe because of the strange people in\n"
	.string "the woods)\p"
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: How did you get he...$"

AnconnaWoods_1_Found_Riolu_Text_4:
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Rio Rioo..\p"
	.string "Rioluuu!!!$"

AnconnaWoods_1_Found_Riolu_Text_5:
	.string "Wait!!!$"

AnconnaWoods_1_Found_Riolu_Text_6:
	.string "Woah!\p"
	.string "(Why'd it try to attack me?)$"

AnconnaWoods_1_Found_Riolu_Text_7:
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Rio lu...$"

AnconnaWoods_1_Found_Riolu_Text_8:
	.string "(It looks like it injured itself though.\p"
	.string "I'd better help it quickly with the\n"
	.string "potion I brought.)$"

AnconnaWoods_1_Found_Riolu_Text_9:
	.string "Easy does it!$"

AnconnaWoods_1_Found_Riolu_Text_10:
	.string "{PLAYER} used a Potion on the Injured\n"
	.string "Pokémon!$"

AnconnaWoods_1_Found_Riolu_Text_11:
	.string "Done!$"

AnconnaWoods_1_Found_Riolu_Text_12:
	.string "Doesn't that feel much better?$"

AnconnaWoods_1_Found_Riolu_Text_13:
	.string "{COLOR GREEN}Rio..\p"
	.string "Riolu?$"

AnconnaWoods_1_Found_Riolu_Text_14:
	.string "(It's coming closer again..)$"

AnconnaWoods_1_Found_Riolu_Text_15:
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Riolu Riolu!!$"

AnconnaWoods_1_Found_Riolu_Text_16:
	.string "(Could it be that..)\p"
	.string "Do you wanna come with me.. 'Riolu'?$"

AnconnaWoods_1_Found_Riolu_Text_17:
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Riolu Riolu Riolu!!!$"

AnconnaWoods_1_Found_Riolu_Text_18:
	.string "Riolu has joined your team!$"

AnconnaWoods_1_Found_Riolu_Text_19:
	.string "I'll take that as a yes.\p"
	.string "Lets go to my house, Riolu.$"

AnconnaWoods_1_Found_Riolu_Text_20:
	.string "(The poor little thing is lost, probably\n"
	.string "because of those people from before.\p"
	.string "Lets see if there's anyway I can help.)$"
