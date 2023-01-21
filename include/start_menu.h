#ifndef GUARD_START_MENU_H
#define GUARD_START_MENU_H

// For Start Menu Icons
#define ICON_WINDOW_OFFSET               2         // The extra space allocated to fit icons
#define TEXT_WINDOW_OFFSET               22        // The gap added to shift the text
#define COLOR_ICON_OFFSET                7         // In "start_menu_icons.png", its the number of 32x32 blocks till the colored likewise sprite


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

// For Start Menu Icons
extern bool8 gAreStartMenuIconsReady;
bool8 gIsAStartMenuIconAtPosition(u8 position);

#endif // GUARD_START_MENU_H
