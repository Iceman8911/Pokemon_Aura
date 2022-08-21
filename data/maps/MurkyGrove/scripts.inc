MurkyGrove_MapScripts::
	.byte 0


MurkyGrove_PoisonGem::
	lock
	finditem ITEM_POISON_GEM
	release
	return


MurkyGrove_BalmMushroom::
	lock
	finditem ITEM_BALM_MUSHROOM
	release
	return


MurkyGrove_Sign::
	lockall
	msgbox MurkyGrove_Sign_Text_0
	releaseall
	return


MurkyGrove_BugManiac::
	trainerbattle_single BUG_MANIAC_BRENT, MurkyGrove_BugManiac_Text_0, MurkyGrove_BugManiac_Text_1
	switch VAR_TEMP_0
	case 0, MurkyGrove_BugManiac_2
	case 1, MurkyGrove_BugManiac_3
	case 2, MurkyGrove_BugManiac_4
	case 3, MurkyGrove_BugManiac_5
	return

MurkyGrove_BugManiac_2:
	msgbox MurkyGrove_BugManiac_Text_2, 2
	closemessage
	addvar VAR_TEMP_0, 1
	return

MurkyGrove_BugManiac_3:
	msgbox MurkyGrove_BugManiac_Text_3, 2
	closemessage
	addvar VAR_TEMP_0, 1
	return

MurkyGrove_BugManiac_4:
	msgbox MurkyGrove_BugManiac_Text_4, 2
	closemessage
	addvar VAR_TEMP_0, 1
	return

MurkyGrove_BugManiac_5:
	compare VAR_TEMP_1, 0
	goto_if_eq MurkyGrove_BugManiac_6
	msgbox MurkyGrove_BugManiac_Text_8, 2
	closemessage
	return

MurkyGrove_BugManiac_6:
	msgbox MurkyGrove_BugManiac_Text_5, 2
	waitmessage
	msgbox MurkyGrove_BugManiac_Text_6, 2
	waitmessage
	msgbox MurkyGrove_BugManiac_Text_7, 2
	closemessage
	addvar VAR_TEMP_1, 1
	return


MurkyGrove_AromaLady::
	trainerbattle_single AROMA_LADY_DAISY, MurkyGrove_AromaLady_Text_0, MurkyGrove_AromaLady_Text_1
	msgbox MurkyGrove_AromaLady_Text_2, 2
	closemessage
	return


MurkyGrove_SchoolKid::
	trainerbattle_single SCHOOL_KID_M_TED, MurkyGrove_SchoolKid_Text_0, MurkyGrove_SchoolKid_Text_1
	msgbox MurkyGrove_SchoolKid_Text_2, 2
	waitmessage
	msgbox MurkyGrove_SchoolKid_Text_3, 2
	waitmessage
	msgbox MurkyGrove_SchoolKid_Text_4, 2
	waitmessage
	msgbox MurkyGrove_SchoolKid_Text_5
	closemessage
	return


MurkyGrove_YoungGirl::
	msgbox MurkyGrove_YoungGirl_Text_0, 2
	closemessage
	return


MurkyGrove_Sign_Text_0:
	.string "Murky Grove\p"
	.string "{LEFT_ARROW} Route 01\p"
	.string "{RIGHT_ARROW} Scandi Town$"

MurkyGrove_BugManiac_Text_0:
	.string "{COLOR BLUE}There are four mushrooms in this grove\n"
	.string "that grow {COLOR GREEN}Tiny Mushrooms{COLOR BLUE} very quickly.\p"
	.string "If you defeat me, I'll tell you where\n"
	.string "they are.$"

MurkyGrove_BugManiac_Text_1:
	.string "Almost had it there!$"

MurkyGrove_BugManiac_Text_2:
	.string "{COLOR BLUE}Well,\p"
	.string "A deal's a deal.$"

MurkyGrove_BugManiac_Text_3:
	.string "{COLOR BLUE}Just south of here are two mushrooms\n"
	.string "side-by-side.\p"
	.string "One of them has a {COLOR GREEN}Tiny Mushroom{COLOR BLUE}.$"

MurkyGrove_BugManiac_Text_4:
	.string "{COLOR BLUE}A bit beyond that is a {COLOR GREEN}Tiny Mushroom{COLOR BLUE}\n"
	.string "near a ledge and small light brown log.$"

MurkyGrove_BugManiac_Text_5:
	.string "{COLOR BLUE}You can find two more {COLOR GREEN}Tiny Mushrooms{COLOR BLUE} if\n"
	.string "you choose to follow the other way out\l"
	.string "of this place, which is to your far\l"
	.string "right.\p"
	.string "The two mushrooms are close to the\n"
	.string "first light brown log you can jump over.$"

MurkyGrove_BugManiac_Text_6:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: Thanks man,\p"
	.string "You're really saving A LOT of trouble\n"
	.string "looking for them.$"

MurkyGrove_BugManiac_Text_7:
	.string "{COLOR BLUE}Your Welcome.\n"
	.string "Since you appreciate my advice, I'll\l"
	.string "throw in a bonus.\p"
	.string "If you want extra loot, use the south\n"
	.string "path to get out of here and choose the\l"
	.string "path off the ledge that's closer to the\l"
	.string "pond.$"

MurkyGrove_BugManiac_Text_8:
	.string "{COLOR BLUE}If you want extra loot, use the south\n"
	.string "path to get out of here and choose the\l"
	.string "path off the ledge that's closer to the\l"
	.string "pond.\p"
	.string "That'll take you to a {COLOR GREEN}Balm Mushroom{COLOR BLUE}and\n"
	.string "a {COLOR GREEN}Poison Gem{COLOR BLUE}.$"

MurkyGrove_AromaLady_Text_0:
	.string "{COLOR RED}I normally wouldn't be in a place like\n"
	.string "this but there are some nice {COLOR GREEN}Balm\l"
	.string "Mushrooms{COLOR RED} here.$"

MurkyGrove_AromaLady_Text_1:
	.string "This better be worth it.$"

MurkyGrove_AromaLady_Text_2:
	.string "{COLOR RED}I really want to get out of this place\n"
	.string "but I want a {COLOR GREEN}Balm Mushroom{COLOR RED} more.$"

MurkyGrove_SchoolKid_Text_0:
	.string "{COLOR BLUE}My classmates said that {COLOR GREEN}Grimer{COLOR BLUE} live\n"
	.string "here.\p"
	.string "Is that true?$"

MurkyGrove_SchoolKid_Text_1:
	.string "Gotta get that Grimer!$"

MurkyGrove_SchoolKid_Text_2:
	.string "{COLOR BLUE}I'm pretty sure that {COLOR GREEN}Grimer{COLOR BLUE} live here.\n"
	.string "I'll keep looking.$"

MurkyGrove_SchoolKid_Text_3:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: Why do you want a {COLOR GREEN}Grimer{COLOR DARK_GRAY} so\n"
	.string "badly?$"

MurkyGrove_SchoolKid_Text_4:
	.string "{COLOR BLUE}Well..,\p"
	.string "Its because {COLOR GREEN}Grimer{COLOR BLUE} evolves into {COLOR GREEN}Muk{COLOR BLUE} and\n"
	.string "{COLOR GREEN}Muk{COLOR BLUE} backwards is....$"

MurkyGrove_SchoolKid_Text_5:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GRAY}: Nope.\p"
	.string "Bye.$"

MurkyGrove_YoungGirl_Text_0:
	.string "{COLOR RED}The ground here is so mucky, I bet you\n"
	.string "can't even run or bike in it.$"
