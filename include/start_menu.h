#ifndef GUARD_START_MENU_H
#define GUARD_START_MENU_H

//For multi start menus
#define NUM_OF_START_MENUS                2                                             //For more/less start menus, the macro "multistartmenu" sets this to 2 by default but can be specified
#define NUM_OF_START_MENU_OPTIONS         8                                             //For more/less options per menu (Best to leave it as 8)
#define FINAL_START_MENU_OPTION           MENU_ACTION_EXIT                              //Set this to the last startmenu option you want to print out
#define IS_MULTI_STARTMENU_ENABLED        FlagGet(FLAG_IS_MULTI_STARTMENU_ENABLED)      //The macro "multistartmenu" lets you turn this on or off if you want the multi menu


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
//The both of these have to be declared as static else it doesn't work. Strange
static u8 sStartMenuPage;   //This var states the page the start menu is currently on
static u8 sStartMenuPageTotal;  //This stores the number of the possible amount of start menu pages


#endif // GUARD_START_MENU_H
