AnconnaTown_SiblingsRoom_MapScripts::
	.byte 0


SisterBidoofAtHome::
	lockall
	faceplayer
	applymovement 2, Happy
	msgbox SisterBidoofAtHome_Text_0, 2
	waitmessage
	releaseall
	return


Anconna_Town_SisterAtHome::
	lockall
	msgbox Anconna_Town_SisterAtHome_Text_0
	msgbox Anconna_Town_SisterAtHome_Text_1
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
	.string "Sis:{COLOR RED}Where is it?$"
