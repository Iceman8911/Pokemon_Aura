AnconnaTown_SiblingsRoom_MapScripts::
	.byte 0


SisterBidoofAtHome::
	lockall
	faceplayer
	applymovement 2, Happy
	msgbox SisterBidoofAtHome_Text_0, 2
	playmoncry SPECIES_RIOLU, CRY_MODE_NORMAL
	waitmoncry
	releaseall
	return


Anconna_Town_SisterAtHome::
	lockall
	msgbox Anconna_Town_SisterAtHome_Text_0
	msgbox Anconna_Town_SisterAtHome_Text_1
	waitmessage
	msgbox Anconna_Town_SisterAtHome_Text_2
	addvar VAR_TEMP_0, 1
	setflag FLAG_SYS_QUEST_MENU_GET
	addvar GAME_PROGRESS, 1
	releaseall
	return


SisterBidoofAtHome_Text_0:
	.string "{COLOR GREEN}Bi Dooooff...\p"
	.string "{COLOR DARK_GRAY}(Bidoof looks very snug and happy)$"

Anconna_Town_SisterAtHome_Text_0:
	.string "i literally don't have a good name atm...\n"
	.string ":/$"

Anconna_Town_SisterAtHome_Text_1:
	.string "Sis:{COLOR RED} Where is it?\p"
	.string "...\p"
	.string "WHERE THE HECK COULD THIS THIG E?$"

Anconna_Town_SisterAtHome_Text_2:
	.string "(It does't seem like she oticed me, maye\n"
	.string "I should try callig her agai...)$"
