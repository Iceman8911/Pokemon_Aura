#ifndef GUARD_START_MENU_H
#define GUARD_START_MENU_H

//For multi start menus
//ROUND_UP_DIVISION_RESULT is used to appropriately get the value of NUM_OF_START_MENUS and round it up if needed
#define ROUND_UP_DIVISION_RESULT(number, divisor) (number % divisor == 0 ? number / divisor : (number + (divisor - (number % divisor))) / divisor)

#define NUM_OF_START_MENUS                ROUND_UP_DIVISION_RESULT(FINAL_START_MENU_OPTION, NUM_OF_START_MENU_OPTIONS)     //For more/less start menus, the macro "multistartmenu" sets this to 2 by default but can be specified
#define NUM_OF_START_MENU_OPTIONS         8                                                                                //Max number of options per menu. (Best to leave it as 8)
#define FINAL_START_MENU_OPTION           MENU_ACTION_DEXNAV                                                                 //Set this to the last startmenu option you want to print out
//#define IS_MULTI_START_MENU_ENABLED       FlagGet(FLAG_IS_MULTI_START_MENU_ENABLED)                                        //The macro "multistartmenu" lets you turn this on or off if you want the multi menu
#define IS_MULTI_START_MENU_ENABLED       TRUE
//#define FILL_STARTMENU_PAGE               TRUE                                                                              //Determines if the pages should be filled if possible or can be loaded with an incomplete amount of options



extern bool8 (*gMenuCallback)(void);

void ShowReturnToFieldStartMenu(void);
void Task_ShowStartMenu(u8 taskId);
void ShowStartMenu(void);
void ShowBattlePyramidStartMenu(void);
void SaveGame(void);
void CB2_SetUpSaveAfterLinkBattle(void);
void SaveForBattleTowerLink(void);
void HideStartMenu(void);
void AppendToList(u8 *list, u8 *pos, u8 newEntry);

//For multi start menus
//The both of these have to be declared as static else it doesn't work
static u8 sStartMenuPage;                       //This stores the page the start menu is currently on
static u8 sStartMenuPageTotal;                  //This stores the number of the possible amount of start menu pages (starting at 0). Not actually useful since it just represents (NUM_OF_START_MENUS - 1)
static u8 sCurrentPageOptionCounter;            //This keeps track on the amount of options that get loaded into a page


#endif // GUARD_START_MENU_H
