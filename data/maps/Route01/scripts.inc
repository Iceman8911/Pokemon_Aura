Route01_MapScripts::
	.byte 0

Route01_ProfessorMaxmilliamCutscence_1::
	return


Route01_Sign::
	msgbox Route01_Sign_Text_0
	closemessage
	return


Route01_SignEnd::
	msgbox Route01_SignEnd_Text_0
	closemessage
	return


Route01_MiracleSeed::
	lockall
	finditem ITEM_MIRACLE_SEED
	releaseall
	return


Route01_SharpBeak::
	lockall
	finditem ITEM_SHARP_BEAK
	releaseall
	return


Route01_Rindo_Berry::
	lockall
	msgbox Route01_Rindo_Berry_Text_0
	waitmessage
	finditem ITEM_RINDO_BERRY
	releaseall
	return


Route01_Youngster_Jimmy::
	trainerbattle_single YOUNGSTER_JIMMY, Route01_Youngster_Jimmy_Text_0, Route01_Youngster_Jimmy_Text_1
	checktrainerflag YOUNGSTER_JOEY
	goto_if 1, Route01_Youngster_Jimmy_2
	msgbox Route01_Youngster_Jimmy_Text_3
Route01_Youngster_Jimmy_1:
	closemessage
	return

Route01_Youngster_Jimmy_2:
	msgbox Route01_Youngster_Jimmy_Text_2
	goto Route01_Youngster_Jimmy_1


Route01_Youngster_John::
	trainerbattle_single YOUNGSTER_JOHN, Route01_Youngster_John_Text_0, Route01_Youngster_John_Text_1
	checktrainerflag YOUNGSTER_JOEY
	goto_if 1, Route01_Youngster_John_2
	msgbox Route01_Youngster_John_Text_3
Route01_Youngster_John_1:
	closemessage
	return

Route01_Youngster_John_2:
	msgbox Route01_Youngster_John_Text_2
	goto Route01_Youngster_John_1


Route01_Youngster_Joey::
	trainerbattle_single YOUNGSTER_JOEY, Route01_Youngster_Joey_Text_0, Route01_Youngster_Joey_Text_1
	msgbox Route01_Youngster_Joey_Text_2
	closemessage
	return


Route01_Lady::
	trainerbattle_single LADY_LIA, Route01_Lady_Text_0, Route01_Lady_Text_1
	goto_if_unset ROUTE01_RINDO_BERRY, Route01_Lady_2
	msgbox Route01_Lady_Text_3
Route01_Lady_1:
	closemessage
	return

Route01_Lady_2:
	msgbox Route01_Lady_Text_2
	goto Route01_Lady_1


Route01_Georgia::
	trainerbattle_single SCHOOL_KID_F_GEORGIA, Route01_Georgia_Text_0, Route01_Georgia_Text_1
	msgbox Route01_Georgia_Text_2
	closemessage
	return


Route01_FlowerBed_Sign::
	msgbox Route01_FlowerBed_Sign_Text_0
	closemessage
	return


Route01_Sign_Text_0:
	.string "Route 01\p"
	.string "{UP_ARROW} Murky Grove\n"
	.string "{DOWN_ARROW} AnconnaTown$"

Route01_SignEnd_Text_0:
	.string "Route 01\p"
	.string "{RIGHT_ARROW} Murky Grove\n"
	.string "{DOWN_ARROW} AnconnaTown$"

Route01_Rindo_Berry_Text_0:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: I'm sure nobody would\n"
	.string "notice if I...$"

Route01_Youngster_Jimmy_Text_0:
	.string "{COLOR BLUE}So you've come to our Route, eh.\p"
	.string "Only the Toughest of Trainers are\n"
	.string "allowed to pass.\p"
	.string "If you wanna go through here, gimme\n"
	.string "your all.$"

Route01_Youngster_Jimmy_Text_1:
	.string "Waah, I want my mommy!$"

Route01_Youngster_Jimmy_Text_2:
	.string "{COLOR BLUE}Even after this loss,\p"
	.string "We are still the ROUTE 01 BOIS!\p"
	.string "Better watch out, cus we're all gonna\n"
	.string "get stronger!$"

Route01_Youngster_Jimmy_Text_3:
	.string "{COLOR BLUE}My brothers will not stand for this\n"
	.string "loss!\p"
	.string "After all, we are the ROUTE 01 BOIS!$"

Route01_Youngster_John_Text_0:
	.string "{COLOR BLUE}If you managed to beat my brother, then\n"
	.string "you're pretty strong.\p"
	.string "But I doubt you're stronger than me,\n"
	.string "I'll have no problem beating you.$"

Route01_Youngster_John_Text_1:
	.string "How....did you beat me?$"

Route01_Youngster_John_Text_2:
	.string "{COLOR BLUE}You even beat Joey.\p"
	.string "You're really are a great trainer.$"

Route01_Youngster_John_Text_3:
	.string "{COLOR BLUE}You might have beaten me but there's no\n"
	.string "way you can beat Joey.$"

Route01_Youngster_Joey_Text_0:
	.string "{COLOR BLUE}You beat my brothers.\p"
	.string "Finally, someone worthy of my power.\p"
	.string "Don't go soft on me because I'm six.\n"
	.string "Let's see how you fare against my\l"
	.string "top-percentage {COLOR GREEN}Rattata!$"

Route01_Youngster_Joey_Text_1:
	.string "That was AWESOME!!!$"

Route01_Youngster_Joey_Text_2:
	.string "{COLOR BLUE}That was a great fight.\p"
	.string "You managed to win my full 31IV\n"
	.string "{COLOR GREEN}Rattata{COLOR BLUE}. You've got some real skill\l"
	.string "there.\p"
	.string "Don't think I'll take this sitting down\n"
	.string "though, I'm gonna train with {COLOR GREEN}Rattata{COLOR BLUE}\l"
	.string "and become the strongest trainer EVER.$"

Route01_Lady_Text_0:
	.string "{COLOR RED}Goodday to you, Sir.\n"
	.string "The weather is so lovely today. Would\l"
	.string "you care for a battle?$"

Route01_Lady_Text_1:
	.string "What a lovely battle.$"

Route01_Lady_Text_2:
	.string "{COLOR RED}The flowers here are lovely as ever\n"
	.string "today. Although, I don't know why a\l"
	.string "Pokeball is in that other fenced patch.\l"
	.string "I'm sure it can be removed though.$"

Route01_Lady_Text_3:
	.string "{COLOR RED}The flowers in this route are as lovely\n"
	.string "as ever.$"

Route01_Georgia_Text_0:
	.string "{COLOR RED}Hello.\p"
	.string "Can you help me with a school project?$"

Route01_Georgia_Text_1:
	.string "I need to train more if I'm gonna pass.$"

Route01_Georgia_Text_2:
	.string "{COLOR RED}I found my {COLOR GREEN}Shroomish{COLOR RED} in {COLOR GREEN}Murky Grove.$"

Route01_FlowerBed_Sign_Text_0:
	.string "PRIVATE PROPERTY\n"
	.string "No Trespassing!$"
