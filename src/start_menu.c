#include "global.h"
#include "battle_pike.h"
#include "battle_pyramid.h"
#include "battle_pyramid_bag.h"
#include "bg.h"
#include "decompress.h"
#include "debug.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "event_object_lock.h"
#include "event_scripts.h"
#include "fieldmap.h"
#include "field_effect.h"
#include "field_player_avatar.h"
#include "field_specials.h"
#include "field_weather.h"
#include "field_screen_effect.h"
#include "frontier_pass.h"
#include "frontier_util.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "item_menu.h"
#include "link.h"
#include "load_save.h"
#include "main.h"
#include "menu.h"
#include "new_game.h"
#include "option_menu.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "pokedex.h"
#include "pokenav.h"
#include "safari_zone.h"
#include "save.h"
#include "scanline_effect.h"
#include "script.h"
#include "sprite.h"
#include "sound.h"
#include "start_menu.h"
#include "strings.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "trainer_card.h"
#include "window.h"
#include "quests.h"
#include "constants/songs.h"
#include "union_room.h"
#include "dexnav.h"
#include "wild_encounter.h"
#include "constants/battle_frontier.h"
#include "constants/rgb.h"
#include "constants/songs.h"

extern u8 DebugMenuScript[];
extern u8 IcemanDebugMenu[];
extern u8 Remember[];

// Menu actions
enum
{
    MENU_ACTION_POKEDEX,
    MENU_ACTION_POKEMON,
    MENU_ACTION_BAG,
    MENU_ACTION_POKENAV,
    MENU_ACTION_PLAYER,
    MENU_ACTION_SAVE,
    MENU_ACTION_OPTION,
    MENU_ACTION_EXIT,
    MENU_ACTION_RETIRE_SAFARI,
    MENU_ACTION_PLAYER_LINK,
    MENU_ACTION_REST_FRONTIER,
    MENU_ACTION_RETIRE_FRONTIER,
    MENU_ACTION_PYRAMID_BAG,
    MENU_ACTION_DEBUG,
    MENU_ACTION_QUEST_MENU,
    MENU_ACTION_REMEMBER,
    MENU_ACTION_DEXNAV
};

// Save status
enum
{
    SAVE_IN_PROGRESS,
    SAVE_SUCCESS,
    SAVE_CANCELED,
    SAVE_ERROR
};

// IWRAM common
bool8 (*gMenuCallback)(void);

// EWRAM
EWRAM_DATA static u8 sSafariBallsWindowId = 0;
EWRAM_DATA static u8 sBattlePyramidFloorWindowId = 0;
EWRAM_DATA static u8 sStartMenuCursorPos = 0;
EWRAM_DATA static u8 sNumStartMenuActions = 0;
EWRAM_DATA static u8 sCurrentStartMenuActions[FINAL_START_MENU_OPTION] = {0}; /* Might revert FINAL_START_MENU_OPTION back to NUM_OF_START_MENU_OPTIONS if there's any problem.
Turns out that using FINAL_START_MENU_OPTION fixes quite a bunch of bugs*/
EWRAM_DATA static u8 sInitStartMenuData[2] = {0};

EWRAM_DATA static u8 (*sSaveDialogCallback)(void) = NULL;
EWRAM_DATA static u8 sSaveDialogTimer = 0;
EWRAM_DATA static bool8 sSavingComplete = FALSE;
EWRAM_DATA static u8 sSaveInfoWindowId = 0;

// For multi start menu
const u8 gText_MenuExitPage[] = _("Exit {RIGHT_ARROW}");   //These 2 texts are used only when IS_MULTI_START_MENU_ENABLED is true
const u8 gText_MenuExitLastPage[] = _("Exit {LEFT_ARROW}");

// Menu action callbacks
static bool8 StartMenuPokedexCallback(void);
static bool8 StartMenuPokemonCallback(void);
static bool8 StartMenuBagCallback(void);
static bool8 StartMenuPokeNavCallback(void);
static bool8 StartMenuPlayerNameCallback(void);
static bool8 StartMenuSaveCallback(void);
static bool8 StartMenuOptionCallback(void);
static bool8 StartMenuExitCallback(void);
static bool8 StartMenuSafariZoneRetireCallback(void);
static bool8 StartMenuLinkModePlayerNameCallback(void);
static bool8 StartMenuBattlePyramidRetireCallback(void);
static bool8 StartMenuBattlePyramidBagCallback(void);
static bool8 StartMenuDebugCallback(void);
static bool8 QuestMenuCallback(void);
static bool8 RememberCallback(void);
static bool8 StartMenuDexNavCallback(void);

// Menu callbacks
static bool8 SaveStartCallback(void);
static bool8 SaveCallback(void);
static bool8 BattlePyramidRetireStartCallback(void);
static bool8 BattlePyramidRetireReturnCallback(void);
static bool8 BattlePyramidRetireCallback(void);
static bool8 HandleStartMenuInput(void);

// Save dialog callbacks
static u8 SaveConfirmSaveCallback(void);
static u8 SaveYesNoCallback(void);
static u8 SaveConfirmInputCallback(void);
static u8 SaveFileExistsCallback(void);
static u8 SaveConfirmOverwriteDefaultNoCallback(void);
static u8 SaveConfirmOverwriteCallback(void);
static u8 SaveOverwriteInputCallback(void);
static u8 SaveSavingMessageCallback(void);
static u8 SaveDoSaveCallback(void);
static u8 SaveSuccessCallback(void);
static u8 SaveReturnSuccessCallback(void);
static u8 SaveErrorCallback(void);
static u8 SaveReturnErrorCallback(void);
static u8 BattlePyramidConfirmRetireCallback(void);
static u8 BattlePyramidRetireYesNoCallback(void);
static u8 BattlePyramidRetireInputCallback(void);

// Task callbacks
static void StartMenuTask(u8 taskId);
static void SaveGameTask(u8 taskId);
static void Task_SaveAfterLinkBattle(u8 taskId);
static void Task_WaitForBattleTowerLinkSave(u8 taskId);
static bool8 FieldCB_ReturnToFieldStartMenu(void);

//
#define spriteTagId 0x3333
#define startMenuIconId  7

static void LoadStartMenuIcon(u8 iconId, u8 position);      // Loads the icon frame at a specified menu option index
static void DynamicallyLoadStartMenuIcon(u8 index);         // Slap in the position, get the accurate icon
static void DeleteAllStartMenuIcons(void);                  // If you run into graphical issues, just run this then run the function right before this line
static void DeleteStartMenuIcon(u8 position);               
static u8 GetIndexOfOptionInsStartMenuItems(u8 index);      // Incase you rearranged smh in your start menu, this gets the right index.
bool8 gIsAStartMenuIconAtPosition(u8 position);

EWRAM_DATA bool8 gAreStartMenuIconsReady = FALSE;
EWRAM_DATA u8 gStartMenuIconPaletteNum = 0;                 // Stores the palette num of the icons
static EWRAM_DATA bool8 sIsStartMenuIconRefreshed = FALSE;
static EWRAM_DATA bool8 sIsStartMenuIconPaletteLoaded = FALSE;

static EWRAM_DATA union AnimCmd *iconFrames = NULL;

static const u32 sStartMenuIconsGfx[] = INCBIN_U32("graphics/interface/start_menu_icons.4bpp");
static const u16 sStartMenuIconsPal[] = INCBIN_U16("graphics/interface/start_menu_icons.gbapal");

// Add any new frames here
static const struct SpriteFrameImage sStartMenuIconFrames[] = {
    overworld_frame(sStartMenuIconsGfx, 4, 4, 0),
    overworld_frame(sStartMenuIconsGfx, 4, 4, 1),
    overworld_frame(sStartMenuIconsGfx, 4, 4, 2),
    overworld_frame(sStartMenuIconsGfx, 4, 4, 3),
    overworld_frame(sStartMenuIconsGfx, 4, 4, 4),
    overworld_frame(sStartMenuIconsGfx, 4, 4, 5),
    overworld_frame(sStartMenuIconsGfx, 4, 4, 6),
    overworld_frame(sStartMenuIconsGfx, 4, 4, 7),
    overworld_frame(sStartMenuIconsGfx, 4, 4, 8),
    overworld_frame(sStartMenuIconsGfx, 4, 4, 9),
    overworld_frame(sStartMenuIconsGfx, 4, 4, 10),
    overworld_frame(sStartMenuIconsGfx, 4, 4, 11),
    overworld_frame(sStartMenuIconsGfx, 4, 4, 12),
    overworld_frame(sStartMenuIconsGfx, 4, 4, 13),
    overworld_frame(sStartMenuIconsGfx, 4, 4, 14),
    overworld_frame(sStartMenuIconsGfx, 4, 4, 15),
};

const struct OamData sObjectEventBaseOam_32x32 = {
    .shape = SPRITE_SHAPE(32x32),
    .size = SPRITE_SIZE(32x32),
    .priority = 0
};

static const struct SpriteTemplate sStartMenuIconSpriteTemplate = {
    .tileTag = TAG_NONE,
    .paletteTag = TAG_NONE, //not used by anything here
    .oam = &sObjectEventBaseOam_32x32,
    .anims = NULL, // Would be set later
    .images = sStartMenuIconFrames,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
    .dummyValue = startMenuIconId, // could be any non zero number
};
//

static const struct WindowTemplate sSafariBallsWindowTemplate = {0, 1, 1, 9, 4, 0xF, 8};

static const u8 *const sPyramidFloorNames[FRONTIER_STAGES_PER_CHALLENGE + 1] =
{
    gText_Floor1,
    gText_Floor2,
    gText_Floor3,
    gText_Floor4,
    gText_Floor5,
    gText_Floor6,
    gText_Floor7,
    gText_Peak
};

static const struct WindowTemplate sPyramidFloorWindowTemplate_2 = {0, 1, 1, 0xA, 4, 0xF, 8};
static const struct WindowTemplate sPyramidFloorWindowTemplate_1 = {0, 1, 1, 0xC, 4, 0xF, 8};

static const u8 sText_RememberText[] = _("Hmm..");
static const u8 gText_MenuDebug[] = _("DEBUG");
static const u8 sText_QuestMenu[] = _("Quests");

static const struct MenuAction sStartMenuItems[] =
{
    [MENU_ACTION_POKEDEX]         = {gText_MenuPokedex, {.u8_void = StartMenuPokedexCallback}},
    [MENU_ACTION_POKEMON]         = {gText_MenuPokemon, {.u8_void = StartMenuPokemonCallback}},
    [MENU_ACTION_BAG]             = {gText_MenuBag,     {.u8_void = StartMenuBagCallback}},
    [MENU_ACTION_POKENAV]         = {gText_MenuPokenav, {.u8_void = StartMenuPokeNavCallback}},
    [MENU_ACTION_PLAYER]          = {gText_MenuPlayer,  {.u8_void = StartMenuPlayerNameCallback}},
    [MENU_ACTION_SAVE]            = {gText_MenuSave,    {.u8_void = StartMenuSaveCallback}},
    [MENU_ACTION_OPTION]          = {gText_MenuOption,  {.u8_void = StartMenuOptionCallback}},
    [MENU_ACTION_EXIT]            = {gText_MenuExit,    {.u8_void = StartMenuExitCallback}},
    [MENU_ACTION_RETIRE_SAFARI]   = {gText_MenuRetire,  {.u8_void = StartMenuSafariZoneRetireCallback}},
    [MENU_ACTION_PLAYER_LINK]     = {gText_MenuPlayer,  {.u8_void = StartMenuLinkModePlayerNameCallback}},
    [MENU_ACTION_REST_FRONTIER]   = {gText_MenuRest,    {.u8_void = StartMenuSaveCallback}},
    [MENU_ACTION_RETIRE_FRONTIER] = {gText_MenuRetire,  {.u8_void = StartMenuBattlePyramidRetireCallback}},
    [MENU_ACTION_PYRAMID_BAG]     = {gText_MenuBag,     {.u8_void = StartMenuBattlePyramidBagCallback}},
    [MENU_ACTION_DEBUG]           = {gText_MenuDebug,   {.u8_void = StartMenuDebugCallback}},
    [MENU_ACTION_QUEST_MENU]        = {sText_QuestMenu, {.u8_void = QuestMenuCallback}},
    [MENU_ACTION_REMEMBER]        = {sText_RememberText, {.u8_void = RememberCallback}},
    [MENU_ACTION_DEXNAV]          = {gText_MenuDexNav,  {.u8_void = StartMenuDexNavCallback}},
};

static const struct BgTemplate sBgTemplates_LinkBattleSave[] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    }
};

static const struct WindowTemplate sWindowTemplates_LinkBattleSave[] =
{
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 26,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x194
    },
    DUMMY_WIN_TEMPLATE
};

static const struct WindowTemplate sSaveInfoWindowTemplate = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = 14,
    .height = 10,
    .paletteNum = 15,
    .baseBlock = 8
};

// Local functions
static void BuildStartMenuActions(void);
static void AddStartMenuAction(u8 action);
static void BuildNormalStartMenu(void);
static void BuildDebugStartMenu(void);
static void BuildSafariZoneStartMenu(void);
static void BuildLinkModeStartMenu(void);
static void BuildUnionRoomStartMenu(void);
static void BuildBattlePikeStartMenu(void);
static void BuildBattlePyramidStartMenu(void);
static void BuildMultiPartnerRoomStartMenu(void);
static void ShowSafariBallsWindow(void);
static void ShowPyramidFloorWindow(void);
static void RemoveExtraStartMenuWindows(void);
static bool32 PrintStartMenuActions(s8 *pIndex, u32 count);
static bool32 InitStartMenuStep(void);
static void InitStartMenu(void);
static void CreateStartMenuTask(TaskFunc followupFunc);
static void InitSave(void);
static u8 RunSaveCallback(void);
static void ShowSaveMessage(const u8 *message, u8 (*saveCallback)(void));
static void HideSaveMessageWindow(void);
static void HideSaveInfoWindow(void);
static void SaveStartTimer(void);
static bool8 SaveSuccesTimer(void);
static bool8 SaveErrorTimer(void);
static void InitBattlePyramidRetire(void);
static void VBlankCB_LinkBattleSave(void);
static bool32 InitSaveWindowAfterLinkBattle(u8 *par1);
static void CB2_SaveAfterLinkBattle(void);
static void ShowSaveInfoWindow(void);
static void RemoveSaveInfoWindow(void);
static void HideStartMenuWindow(void);
static void HideStartMenuDebug(void);

void SetDexPokemonPokenavFlags(void) // unused
{
    FlagSet(FLAG_SYS_POKEDEX_GET);
    FlagSet(FLAG_SYS_POKEMON_GET);
    FlagSet(FLAG_SYS_POKENAV_GET);
}

static void BuildStartMenuActions(void)
{
    sNumStartMenuActions = 0;

    if (IsOverworldLinkActive() == TRUE)
    {
        BuildLinkModeStartMenu();
    }
    else if (InUnionRoom() == TRUE)
    {
        BuildUnionRoomStartMenu();
    }
    else if (GetSafariZoneFlag() == TRUE)
    {
        BuildSafariZoneStartMenu();
    }
    else if (InBattlePike())
    {
        BuildBattlePikeStartMenu();
    }
    else if (InBattlePyramid())
    {
        BuildBattlePyramidStartMenu();
    }
    else if (InMultiPartnerRoom())
    {
        BuildMultiPartnerRoomStartMenu();
    }
    else
    {
    #if DEBUG_SYSTEM_ENABLE == TRUE && DEBUG_SYSTEM_IN_MENU == TRUE
        BuildDebugStartMenu();
    #else
        BuildNormalStartMenu();
    #endif
    }
}

static void AddStartMenuAction(u8 action)
{
    AppendToList(sCurrentStartMenuActions, &sNumStartMenuActions, action);
}

/*static bool8 IsStartMenuActionIncluded(u8 action) {   //Helps in making sure I don't repeat a start menu option. CURRENTLY UNUSED
    u8 i;
    
    for (i = (NUM_OF_START_MENU_OPTIONS * sStartMenuPage); i < (NUM_OF_START_MENU_OPTIONS * (sStartMenuPage + 1)); i++) //Checks the current batch for the action
    {
        if (sCurrentStartMenuActions[i] == action) { //This needs a bit of editing. Using i % NUM_OF_START_MENU_OPTIONS doesn't work as intended
            return TRUE;
        }
    }
    return FALSE;
}*/

static void BuildNormalStartMenu(void)
{
    u8 i;

    #ifdef FILL_STARTMENU_PAGE
        u8 sAmountOfOptionsNeeded;                 // The amount of options required to fill the page to (NUM_OF_START_MENU_OPTIONS - 1)
        u8 sAmountOfOptionsToBeLoaded;             // The amount of options remaining in the enum that are yet to be loaded
        static u8 sAmountOfOptionsToSkip;          // It saves the amount of options that are skipped during subsequent iterations
        static u8 sPreviousAmountOfOptionsNeeded;  // For the last page, sAmountOfOptionsNeeded is unreliable so we save the one from the last loop
        
        static bool8 danger;                      // This is just a check/flag to know if I need to adjust some values due to various situations
        static u8 dangerPage;                     // The page that needs special adjustment

        //This is to prevent the first page from messing up since sAmountOfOptionsToSkip changes anytime the function is run
        if (sStartMenuPage != 0)
        {
            if (danger) //Just an extra precaution to a particular bug. Not much to say now but this is not likely to occur
            {
                i = (sAmountOfOptionsToSkip + 1) + (NUM_OF_START_MENU_OPTIONS * sStartMenuPage);

                if (dangerPage != sStartMenuPage)  /*Once the user switched pages, no use keeping the flag
                Incase you are confused, this is check will work when the page we originally saved in dangerPage isn't loaded*/
                    danger = FALSE; // Reset the flag/check
            }
            else // Gets run most of the time
            {
                i = sAmountOfOptionsToSkip + (NUM_OF_START_MENU_OPTIONS * sStartMenuPage);
            }
        } 
        else 
        {
            i = (NUM_OF_START_MENU_OPTIONS * sStartMenuPage);
        }
    #endif

    #ifndef FILL_STARTMENU_PAGE
        i = (NUM_OF_START_MENU_OPTIONS * sStartMenuPage);
    #endif

    sCurrentPageOptionCounter = 0;  //set it to 0 every time its used
    sStartMenuPageTotal = NUM_OF_START_MENUS - 1;

    for (i; i < (NUM_OF_START_MENU_OPTIONS * (sStartMenuPage + 1)); i++) //To keep the loop going without resetting anything and self adjusting itself with each page
    {
        if (i <= FINAL_START_MENU_OPTION) //To make sure it doesn't crash after loading all intended start menu options
        { 
            if(!FlagGet(FLAG_SYS_POKEDEX_GET) && i == MENU_ACTION_POKEDEX) //The loop wants to print the Pokedex option but the flag is not set
            {  
                //skip
            } 
            else if(!FlagGet(FLAG_SYS_POKEMON_GET) && i == MENU_ACTION_POKEMON) //The loop wants to print the Pokemon option but the flag is not set
            {  
                //skip
            }
            else if(!FlagGet(FLAG_SYS_POKENAV_GET) && i == MENU_ACTION_POKENAV) //The loop wants to print the Pokenav option but the flag is not set
            {  
                //skip
            }
            else if(i == MENU_ACTION_EXIT) //Don't print the Exit action normally, to reduce the amount of stuff you need to edit if you shift stuff around in the MENU_ACTION_* enum
            { 
                //skip
            }
            else if (i >= MENU_ACTION_RETIRE_SAFARI && i <= MENU_ACTION_PYRAMID_BAG) //Skip the safari and battle frontier stuff. You can remove this check if you want
            {
                //skip
            }

            //Any custom conditions you want can be added here can be added above like the first 4 //

            else //No other check required so proceed to print as normal
            { 
                AddStartMenuAction(i); 
                sCurrentPageOptionCounter++; /*While i increases evrey time the loop is run,
                sCurrentPageOptionCounter only increases with EACH successful option that was loaded*/
            }
        }
    }

    #ifdef FILL_STARTMENU_PAGE
        sAmountOfOptionsNeeded = (NUM_OF_START_MENU_OPTIONS - 1) - sCurrentPageOptionCounter;
        sAmountOfOptionsToBeLoaded = FINAL_START_MENU_OPTION - i;
        sAmountOfOptionsToSkip = sAmountOfOptionsNeeded; /*Before sAmountOfOptionsNeeded is affected and the options are pulled out from their original pages, 
        save it to sAmountOfOptionsToSkip so that we have a way to adjust incoming options properly */

        if (sStartMenuPage == (sStartMenuPageTotal - 1)) // On the second to last page
        {
            sPreviousAmountOfOptionsNeeded = (NUM_OF_START_MENU_OPTIONS - 1) - sCurrentPageOptionCounter; //save this for now, it is useful in maintaing the last page
        } 

        //After doing the regular iteration, if the page is not almost full (the last slot is for the Exit option) and it is not the last page, then use elements from the next page (if any) to fill it
        if ((sCurrentPageOptionCounter != NUM_OF_START_MENU_OPTIONS - 1) && (sStartMenuPage != sStartMenuPageTotal) && (sAmountOfOptionsToBeLoaded >= sAmountOfOptionsNeeded))
        {
            while(sAmountOfOptionsNeeded != 0)
            { /*As long as the current page isn't almost full,
              continuously decrease sAmountOfOptionsNeeded to 0 which is when the page would have only 1 slot left*/

                if(!FlagGet(FLAG_SYS_POKEDEX_GET) && i == MENU_ACTION_POKEDEX) 
                {  
                    //skip
                } 
                else if(!FlagGet(FLAG_SYS_POKEMON_GET) && i == MENU_ACTION_POKEMON) 
                {  
                    //skip
                }
                else if(!FlagGet(FLAG_SYS_POKENAV_GET) && i == MENU_ACTION_POKENAV) 
                {  
                    //skip
                }
                else if(i == MENU_ACTION_EXIT) 
                { 
                    //skip
                }
                else if (i >= MENU_ACTION_RETIRE_SAFARI && i <= MENU_ACTION_PYRAMID_BAG) 
                {
                    //skip
                }
                
                // You have to add your extra condtions here too if you did above //

                else
                {
                    AddStartMenuAction(i);
                    sAmountOfOptionsNeeded--;
                }

                if (i == NUM_OF_START_MENU_OPTIONS && i == MENU_ACTION_EXIT) /* If i reaches NUM_OF_START_MENU_OPTIONS while being the same as MENU_ACTION_EXIT in this particular loop,
                I noticed that sAmountOfOptionsToSkip needs to be (sAmountOfOptionsToSkip + 1) to load out the options well. */
                // If there are any bugs relating to this, just comment this conditional
                {
                    danger = TRUE;
                    dangerPage = (sStartMenuPage + 1);  // Saves the next page which is where the adjustment needs to be made
                }
                i++;
            }
        } 
        else if (sStartMenuPage == sStartMenuPageTotal) // On the last page.
        {
            sAmountOfOptionsToSkip = sPreviousAmountOfOptionsNeeded; /* Keep the last value generated intact,
            so that returning to and back from the overworld doesn't mess anything up. */
        }
        else
        { //No need to fill the page, so reset variables. I doubt this is even called.
            sAmountOfOptionsToSkip = 0;
        }
    #endif

    //if(!IsStartMenuActionIncluded(MENU_ACTION_EXIT))  //Incase The Exit option wasn't printed, Print it. CURRENTLY UNUSED
        AddStartMenuAction(MENU_ACTION_EXIT);
}

static void BuildDebugStartMenu(void)
{
    AddStartMenuAction(MENU_ACTION_DEBUG);
    if (FlagGet(FLAG_SYS_POKEDEX_GET) == TRUE)
        AddStartMenuAction(MENU_ACTION_POKEDEX);
    if (FlagGet(FLAG_SYS_POKEMON_GET) == TRUE)
        AddStartMenuAction(MENU_ACTION_POKEMON);
    AddStartMenuAction(MENU_ACTION_BAG);
    if (FlagGet(FLAG_SYS_POKENAV_GET) == TRUE)
        AddStartMenuAction(MENU_ACTION_POKENAV);
    AddStartMenuAction(MENU_ACTION_PLAYER);
    AddStartMenuAction(MENU_ACTION_SAVE);
    AddStartMenuAction(MENU_ACTION_OPTION);
}

static void BuildSafariZoneStartMenu(void)
{
    AddStartMenuAction(MENU_ACTION_RETIRE_SAFARI);
    AddStartMenuAction(MENU_ACTION_POKEDEX);
    AddStartMenuAction(MENU_ACTION_POKEMON);
    AddStartMenuAction(MENU_ACTION_BAG);
    AddStartMenuAction(MENU_ACTION_PLAYER);
    AddStartMenuAction(MENU_ACTION_OPTION);
    AddStartMenuAction(MENU_ACTION_EXIT);
}

static void BuildLinkModeStartMenu(void)
{
    AddStartMenuAction(MENU_ACTION_POKEMON);
    AddStartMenuAction(MENU_ACTION_BAG);

    if (FlagGet(FLAG_SYS_POKENAV_GET) == TRUE)
    {
        AddStartMenuAction(MENU_ACTION_POKENAV);
    }

    AddStartMenuAction(MENU_ACTION_PLAYER_LINK);
    AddStartMenuAction(MENU_ACTION_OPTION);
    AddStartMenuAction(MENU_ACTION_EXIT);
}

static void BuildUnionRoomStartMenu(void)
{
    AddStartMenuAction(MENU_ACTION_POKEMON);
    AddStartMenuAction(MENU_ACTION_BAG);

    if (FlagGet(FLAG_SYS_POKENAV_GET) == TRUE)
    {
        AddStartMenuAction(MENU_ACTION_POKENAV);
    }

    AddStartMenuAction(MENU_ACTION_PLAYER);
    AddStartMenuAction(MENU_ACTION_OPTION);
    AddStartMenuAction(MENU_ACTION_EXIT);
}

static void BuildBattlePikeStartMenu(void)
{
    AddStartMenuAction(MENU_ACTION_POKEDEX);
    AddStartMenuAction(MENU_ACTION_POKEMON);
    AddStartMenuAction(MENU_ACTION_PLAYER);
    AddStartMenuAction(MENU_ACTION_OPTION);
    AddStartMenuAction(MENU_ACTION_EXIT);
}

static void BuildBattlePyramidStartMenu(void)
{
    AddStartMenuAction(MENU_ACTION_POKEMON);
    AddStartMenuAction(MENU_ACTION_PYRAMID_BAG);
    AddStartMenuAction(MENU_ACTION_PLAYER);
    AddStartMenuAction(MENU_ACTION_REST_FRONTIER);
    AddStartMenuAction(MENU_ACTION_RETIRE_FRONTIER);
    AddStartMenuAction(MENU_ACTION_OPTION);
    AddStartMenuAction(MENU_ACTION_EXIT);
}

static void BuildMultiPartnerRoomStartMenu(void)
{
    AddStartMenuAction(MENU_ACTION_POKEMON);
    AddStartMenuAction(MENU_ACTION_PLAYER);
    AddStartMenuAction(MENU_ACTION_OPTION);
    AddStartMenuAction(MENU_ACTION_EXIT);
}

static void ShowSafariBallsWindow(void)
{
    sSafariBallsWindowId = AddWindow(&sSafariBallsWindowTemplate);
    PutWindowTilemap(sSafariBallsWindowId);
    DrawStdWindowFrame(sSafariBallsWindowId, FALSE);
    ConvertIntToDecimalStringN(gStringVar1, gNumSafariBalls, STR_CONV_MODE_RIGHT_ALIGN, 2);
    StringExpandPlaceholders(gSystemStringVar, gText_SafariBallStock);
    AddTextPrinterParameterized(sSafariBallsWindowId, FONT_NORMAL, gSystemStringVar, 0, 1, TEXT_SKIP_DRAW, NULL);
    CopyWindowToVram(sSafariBallsWindowId, COPYWIN_GFX);
}

static void ShowPyramidFloorWindow(void)
{
    if (gSaveBlock2Ptr->frontier.curChallengeBattleNum == FRONTIER_STAGES_PER_CHALLENGE)
        sBattlePyramidFloorWindowId = AddWindow(&sPyramidFloorWindowTemplate_1);
    else
        sBattlePyramidFloorWindowId = AddWindow(&sPyramidFloorWindowTemplate_2);

    PutWindowTilemap(sBattlePyramidFloorWindowId);
    DrawStdWindowFrame(sBattlePyramidFloorWindowId, FALSE);
    StringCopy(gStringVar1, sPyramidFloorNames[gSaveBlock2Ptr->frontier.curChallengeBattleNum]);
    StringExpandPlaceholders(gSystemStringVar, gText_BattlePyramidFloor);
    AddTextPrinterParameterized(sBattlePyramidFloorWindowId, FONT_NORMAL, gSystemStringVar, 0, 1, TEXT_SKIP_DRAW, NULL);
    CopyWindowToVram(sBattlePyramidFloorWindowId, COPYWIN_GFX);
}

static void RemoveExtraStartMenuWindows(void)
{
    if (GetSafariZoneFlag())
    {
        ClearStdWindowAndFrameToTransparent(sSafariBallsWindowId, FALSE);
        CopyWindowToVram(sSafariBallsWindowId, COPYWIN_GFX);
        RemoveWindow(sSafariBallsWindowId);
    }
    if (InBattlePyramid())
    {
        ClearStdWindowAndFrameToTransparent(sBattlePyramidFloorWindowId, FALSE);
        RemoveWindow(sBattlePyramidFloorWindowId);
    }
}

static bool32 PrintStartMenuActions(s8 *pIndex, u32 count) //This function now prints a different Exit text depending on IS_MULTI_START_MENU_ENABLED
{
    s8 index = *pIndex;

    do
    {
        if (sStartMenuItems[sCurrentStartMenuActions[index]].func.u8_void == StartMenuPlayerNameCallback)
        {
            if (gAreStartMenuIconsReady)
                PrintPlayerNameOnWindow(GetStartMenuWindowId(), sStartMenuItems[sCurrentStartMenuActions[index]].text, TEXT_WINDOW_OFFSET, (index << 4) + (index * 3));
            else
                PrintPlayerNameOnWindow(GetStartMenuWindowId(), sStartMenuItems[sCurrentStartMenuActions[index]].text, 8, (index << 4) + 9);
        }
        else 
        {
            if (IS_MULTI_START_MENU_ENABLED && NUM_OF_START_MENUS != 1) //Makes sure the the multi start menu is enabled AND there isn't only 1 page before trying to print out the appropiate text for the Exit option
            {
                if (sStartMenuItems[sCurrentStartMenuActions[index]].func.u8_void != StartMenuExitCallback) //Stops the loop from printing out any option with StartMenuExitCallback (i.e the Exit option)
                {
                    StringExpandPlaceholders(gStringVar4, sStartMenuItems[sCurrentStartMenuActions[index]].text);
                } 
                else if (sStartMenuItems[sCurrentStartMenuActions[index]].func.u8_void == StartMenuExitCallback) //Once the option to be printed is MENU_ACTION_EXIT, then it loads the custom text instead
                {
                    if (sStartMenuPage != sStartMenuPageTotal) 
                    {  //If not on the last page
                        StringExpandPlaceholders(gStringVar4, gText_MenuExitPage); //Print out "Exit {RIGHT_ARROW}"
                    }
                    else
                    { //If on the last page
                        StringExpandPlaceholders(gStringVar4, gText_MenuExitLastPage); //Print out "Exit {LEFT_ARROW}"
                    }
                }
            }
            else //Proceed as normal
            {
                StringExpandPlaceholders(gStringVar4, sStartMenuItems[sCurrentStartMenuActions[index]].text);
            }

            // Set Up Printer and Print
            if (gAreStartMenuIconsReady)
                AddTextPrinterParameterized(GetStartMenuWindowId(), FONT_NORMAL, gStringVar4, TEXT_WINDOW_OFFSET, (index << 4) + (index * 3), TEXT_SKIP_DRAW, NULL); //What actually sets up the printer
            else
                AddTextPrinterParameterized(GetStartMenuWindowId(), FONT_NORMAL, gStringVar4, 8, (index << 4) + 9, TEXT_SKIP_DRAW, NULL); //What actually sets up the printer
        }
        DynamicallyLoadStartMenuIcon(index);

        index++;
        if (index >= sNumStartMenuActions)
        {
            *pIndex = index;
            return TRUE;
        }

        count--;
    }
    while (count != 0);

    *pIndex = index;
    return FALSE;
}

static bool32 InitStartMenuStep(void)
{
    s8 state = sInitStartMenuData[0];

    switch (state)
    {
    case 0:
        sInitStartMenuData[0]++;
        break;
    case 1:
        BuildStartMenuActions();
        sInitStartMenuData[0]++;
        break;
    case 2:
        LoadMessageBoxAndBorderGfx();
        DrawStdWindowFrame(AddStartMenuWindow(sNumStartMenuActions), FALSE);
        sInitStartMenuData[1] = 0;
        sInitStartMenuData[0]++;
        break;
    case 3:
        if (GetSafariZoneFlag())
            ShowSafariBallsWindow();
        if (InBattlePyramid())
            ShowPyramidFloorWindow();
        sInitStartMenuData[0]++;
        break;
    case 4:
        if (PrintStartMenuActions(&sInitStartMenuData[1], 2))
            sInitStartMenuData[0]++;
        break;
    case 5:
        sStartMenuCursorPos = InitMenuNormal(GetStartMenuWindowId(), FONT_NORMAL, 0, 9, 16, sNumStartMenuActions, sStartMenuCursorPos);
        CopyWindowToVram(GetStartMenuWindowId(), COPYWIN_MAP);
        return TRUE;
    }

    return FALSE;
}

static void InitStartMenu(void)
{
    sInitStartMenuData[0] = 0;
    sInitStartMenuData[1] = 0;
    while (!InitStartMenuStep())
        ;
}

static void StartMenuTask(u8 taskId)
{
    if (InitStartMenuStep() == TRUE)
        SwitchTaskToFollowupFunc(taskId);
}

static void CreateStartMenuTask(TaskFunc followupFunc)
{
    u8 taskId;

    sInitStartMenuData[0] = 0;
    sInitStartMenuData[1] = 0;
    taskId = CreateTask(StartMenuTask, 0x50);
    SetTaskFuncWithFollowupFunc(taskId, StartMenuTask, followupFunc);
}

static bool8 FieldCB_ReturnToFieldStartMenu(void)
{//
    struct SpritePalette palSheet;

    if (InitStartMenuStep() == FALSE)
    {
        return FALSE;
    }

    // Fix Palette bugs when returning to the start menu from overworld callbacks
    sIsStartMenuIconPaletteLoaded = FALSE;
    LoadPalette(sStartMenuIconsPal, (gStartMenuIconPaletteNum * 16) + 0x100, 32);
    
    ReturnToFieldOpenStartMenu();
    return TRUE;
}

void ShowReturnToFieldStartMenu(void)
{
    sInitStartMenuData[0] = 0;
    sInitStartMenuData[1] = 0;
    gFieldCallback2 = FieldCB_ReturnToFieldStartMenu;
}

void Task_ShowStartMenu(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch(task->data[0])
    {
    case 0:
        if (InUnionRoom() == TRUE)
            SetUsingUnionRoomStartMenu();
        
        gMenuCallback = HandleStartMenuInput;
        task->data[0]++;
        break;
    case 1:
        if (gMenuCallback() == TRUE)
            DestroyTask(taskId);
        break;
    }
}

void ShowStartMenu(void)
{
    if (!IsOverworldLinkActive())
    {
        FreezeObjectEvents();
        PlayerFreeze();
        StopPlayerAvatar();
    }
    gAreStartMenuIconsReady = TRUE;
    CreateStartMenuTask(Task_ShowStartMenu);
    LockPlayerFieldControls();
}

static bool8 HandleStartMenuInput(void)
{
    bool8 (*callback)(void);
    callback = sStartMenuItems[sCurrentStartMenuActions[sStartMenuCursorPos]].func.u8_void;
    // All options with icons must be added to this conditional using their callbacks
    // There's prolly a shorter way for this though. Eh
    if (callback == StartMenuPokedexCallback
    ||  callback == StartMenuPokemonCallback
    ||  callback == StartMenuBagCallback
    ||  callback == StartMenuPlayerNameCallback
    ||  callback == StartMenuSaveCallback
    ||  callback == StartMenuOptionCallback
    ||  callback == StartMenuExitCallback
    ||  callback == QuestMenuCallback)
    {
        if (gAreStartMenuIconsReady && !sIsStartMenuIconRefreshed)
        {
            // This deals with reloading the current icon
            DeleteStartMenuIcon(sStartMenuCursorPos);
            DynamicallyLoadStartMenuIcon(sStartMenuCursorPos);
            sIsStartMenuIconRefreshed = TRUE; /* This function runs every frame once the start menu is loaded 
            so this should stop it from infinitely printing */
        }
    }
    if (JOY_NEW(DPAD_UP))
    {
        PlaySE(SE_SELECT);
        sStartMenuCursorPos = Menu_MoveCursor(-1);
        // Same thing here like before
        if (callback == StartMenuPokedexCallback
        ||  callback == StartMenuPokemonCallback
        ||  callback == StartMenuBagCallback
        ||  callback == StartMenuPlayerNameCallback
        ||  callback == StartMenuSaveCallback
        ||  callback == StartMenuOptionCallback
        ||  callback == StartMenuExitCallback
        ||  callback == QuestMenuCallback)
        {
            if (sStartMenuCursorPos != (sNumStartMenuActions - 1)) // Not at bottom of start menu
            {
                // This deals with reloading the last icon
                DeleteStartMenuIcon(sStartMenuCursorPos + 1); // Previous option
                DynamicallyLoadStartMenuIcon(sStartMenuCursorPos + 1);   // Previous option
            }
            else // Cursor snapped to bottom of list
            {
                DeleteStartMenuIcon(0);
                DynamicallyLoadStartMenuIcon(0);
            }
        }
        sIsStartMenuIconRefreshed = FALSE;
    }

    if (JOY_NEW(DPAD_DOWN))
    {
        PlaySE(SE_SELECT);
        sStartMenuCursorPos = Menu_MoveCursor(1);
        // Yup, still the same here too
        if (callback == StartMenuPokedexCallback
        ||  callback == StartMenuPokemonCallback
        ||  callback == StartMenuBagCallback
        ||  callback == StartMenuPlayerNameCallback
        ||  callback == StartMenuSaveCallback
        ||  callback == StartMenuOptionCallback
        ||  callback == StartMenuExitCallback
        ||  callback == QuestMenuCallback)
        {
            if (sStartMenuCursorPos != 0)
            {
                // This deals with reloading the previous icon
                DeleteStartMenuIcon(sStartMenuCursorPos - 1); // Previous option
                DynamicallyLoadStartMenuIcon(sStartMenuCursorPos - 1);   // Previous option
            }
            else // Cursor snapped back to top of list
            {
                DeleteStartMenuIcon(sNumStartMenuActions - 1);
                DynamicallyLoadStartMenuIcon(sNumStartMenuActions - 1);
            }
        }
        sIsStartMenuIconRefreshed = FALSE;
    }

    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        if (sStartMenuItems[sCurrentStartMenuActions[sStartMenuCursorPos]].func.u8_void == StartMenuPokedexCallback)
        {
            if (GetNationalPokedexCount(FLAG_GET_SEEN) == 0)
                return FALSE;
        }
        if (sCurrentStartMenuActions[sStartMenuCursorPos] == MENU_ACTION_DEXNAV
          && MapHasNoEncounterData())   //This apparently prevents the player from accessing the Dexnav in a map without enounters
            return FALSE;
        
        gMenuCallback = sStartMenuItems[sCurrentStartMenuActions[sStartMenuCursorPos]].func.u8_void;

        if (gMenuCallback != StartMenuSaveCallback
            && gMenuCallback != StartMenuExitCallback
            && gMenuCallback != StartMenuDebugCallback
            && gMenuCallback != StartMenuSafariZoneRetireCallback
            && gMenuCallback != StartMenuBattlePyramidRetireCallback
            && gMenuCallback != RememberCallback)
        {
           FadeScreen(FADE_TO_BLACK, 0);
        }

        return FALSE;
    }

    if (JOY_NEW(SELECT_BUTTON))
    {
        HideStartMenu();
        ScriptContext_Enable();
        ScriptContext_SetupScript(DebugMenuScript);
        return TRUE;
    }

    if (JOY_NEW(L_BUTTON))  //My Debug Menu :)
    {
        HideStartMenu();
        ScriptContext_Enable();
        ScriptContext_SetupScript(IcemanDebugMenu);
        return TRUE;
    }

    if (JOY_NEW(START_BUTTON | B_BUTTON))
    {
        RemoveExtraStartMenuWindows();
        HideStartMenu();
        return TRUE;
    }

    if (IS_MULTI_START_MENU_ENABLED && NUM_OF_START_MENUS != 1)  //Must be enabled to use the multi menu and there musn't be just 1 menu
    {
        if (JOY_NEW(DPAD_RIGHT)) //Scrolls to the next start menu page
        {
            sIsStartMenuIconRefreshed = FALSE;
            RemoveExtraStartMenuWindows();
            HideStartMenu();
            if(sStartMenuPage < sStartMenuPageTotal) { 
                sStartMenuPage++;
            } else { //If at the last page, it will jump back to the first one
                sStartMenuPage = 0;
            }
            ShowStartMenu();
            return TRUE;
        }

        if (JOY_NEW(DPAD_LEFT)) //Scrolls to the previous start menu page
        {
            sIsStartMenuIconRefreshed = FALSE;
            RemoveExtraStartMenuWindows();
            HideStartMenu();
            if(sStartMenuPage > 0) { 
                sStartMenuPage--;
            } else { //If at the first page, it will jump to the last one
                sStartMenuPage = sStartMenuPageTotal;
            }
            ShowStartMenu();
            return TRUE;
        }
    }

    return FALSE;
}

bool8 StartMenuPokedexCallback(void)
{
    if (!gPaletteFade.active)
    {
        IncrementGameStat(GAME_STAT_CHECKED_POKEDEX);
        PlayRainStoppingSoundEffect();
        RemoveExtraStartMenuWindows();
        CleanupOverworldWindowsAndTilemaps();
        SetMainCallback2(CB2_OpenPokedex);

        return TRUE;
    }

    return FALSE;
}

static bool8 StartMenuPokemonCallback(void)
{
    if (!gPaletteFade.active)
    {
        PlayRainStoppingSoundEffect();
        RemoveExtraStartMenuWindows();
        CleanupOverworldWindowsAndTilemaps();
        SetMainCallback2(CB2_PartyMenuFromStartMenu); // Display party menu

        return TRUE;
    }

    return FALSE;
}

static bool8 StartMenuBagCallback(void)
{
    if (!gPaletteFade.active)
    {
        PlayRainStoppingSoundEffect();
        RemoveExtraStartMenuWindows();
        CleanupOverworldWindowsAndTilemaps();
        SetMainCallback2(CB2_BagMenuFromStartMenu); // Display bag menu

        return TRUE;
    }

    return FALSE;
}

static bool8 StartMenuPokeNavCallback(void)
{
    if (!gPaletteFade.active)
    {
        PlayRainStoppingSoundEffect();
        RemoveExtraStartMenuWindows();
        CleanupOverworldWindowsAndTilemaps();
        SetMainCallback2(CB2_InitPokeNav);  // Display PokeNav

        return TRUE;
    }

    return FALSE;
}

static bool8 StartMenuPlayerNameCallback(void)
{
    if (!gPaletteFade.active)
    {
        PlayRainStoppingSoundEffect();
        RemoveExtraStartMenuWindows();
        CleanupOverworldWindowsAndTilemaps();

        if (IsOverworldLinkActive() || InUnionRoom())
            ShowPlayerTrainerCard(CB2_ReturnToFieldWithOpenMenu); // Display trainer card
        else if (FlagGet(FLAG_SYS_FRONTIER_PASS))
            ShowFrontierPass(CB2_ReturnToFieldWithOpenMenu); // Display frontier pass
        else
            ShowPlayerTrainerCard(CB2_ReturnToFieldWithOpenMenu); // Display trainer card

        return TRUE;
    }

    return FALSE;
}

static bool8 StartMenuSaveCallback(void)
{
    if (InBattlePyramid())
        RemoveExtraStartMenuWindows();

    gMenuCallback = SaveStartCallback; // Display save menu

    return FALSE;
}

static bool8 StartMenuOptionCallback(void)
{
    if (!gPaletteFade.active)
    {
        PlayRainStoppingSoundEffect();
        RemoveExtraStartMenuWindows();
        CleanupOverworldWindowsAndTilemaps();
        SetMainCallback2(CB2_InitOptionMenu); // Display option menu
        gMain.savedCallback = CB2_ReturnToFieldWithOpenMenu;

        return TRUE;
    }

    return FALSE;
}

static bool8 StartMenuExitCallback(void)
{
    RemoveExtraStartMenuWindows();
    HideStartMenu(); // Hide start menu

    return TRUE;
}

static bool8 StartMenuDebugCallback(void)
{
    RemoveExtraStartMenuWindows();
    HideStartMenuDebug(); // Hide start menu without enabling movement

#if DEBUG_SYSTEM_ENABLE == TRUE
    FreezeObjectEvents();
    Debug_ShowMainMenu();
#endif

return TRUE;
}

static bool8 StartMenuSafariZoneRetireCallback(void)
{
    RemoveExtraStartMenuWindows();
    HideStartMenu();
    SafariZoneRetirePrompt();

    return TRUE;
}

static bool8 RememberCallback(void)
{
    RemoveExtraStartMenuWindows();
    HideStartMenu();
    ScriptContext_SetupScript(Remember);

    return TRUE;
}

static void HideStartMenuDebug(void)
{
    PlaySE(SE_SELECT);
    ClearStdWindowAndFrame(GetStartMenuWindowId(), TRUE);
    RemoveStartMenuWindow();
}

static bool8 StartMenuLinkModePlayerNameCallback(void)
{
    if (!gPaletteFade.active)
    {
        PlayRainStoppingSoundEffect();
        CleanupOverworldWindowsAndTilemaps();
        ShowTrainerCardInLink(gLocalLinkPlayerId, CB2_ReturnToFieldWithOpenMenu);

        return TRUE;
    }

    return FALSE;
}

static bool8 StartMenuBattlePyramidRetireCallback(void)
{
    gMenuCallback = BattlePyramidRetireStartCallback; // Confirm retire

    return FALSE;
}

// Functionally unused
void ShowBattlePyramidStartMenu(void)
{
    ClearDialogWindowAndFrameToTransparent(0, FALSE);
    ScriptUnfreezeObjectEvents();
    CreateStartMenuTask(Task_ShowStartMenu);
    LockPlayerFieldControls();
}

static bool8 StartMenuBattlePyramidBagCallback(void)
{
    if (!gPaletteFade.active)
    {
        PlayRainStoppingSoundEffect();
        RemoveExtraStartMenuWindows();
        CleanupOverworldWindowsAndTilemaps();
        SetMainCallback2(CB2_PyramidBagMenuFromStartMenu);

        return TRUE;
    }

    return FALSE;
}

static bool8 SaveStartCallback(void)
{
    DeleteAllStartMenuIcons();
    gAreStartMenuIconsReady = TRUE;
    InitSave();
    gMenuCallback = SaveCallback;

    return FALSE;
}

static bool8 SaveCallback(void)
{
    switch (RunSaveCallback())
    {
    case SAVE_IN_PROGRESS:
        return FALSE;
    case SAVE_CANCELED: // Back to start menu
        ClearDialogWindowAndFrameToTransparent(0, FALSE);
        InitStartMenu();
        gMenuCallback = HandleStartMenuInput;
        return FALSE;
    case SAVE_SUCCESS:
    case SAVE_ERROR:    // Close start menu
        ClearDialogWindowAndFrameToTransparent(0, TRUE);
        ScriptUnfreezeObjectEvents();
        UnlockPlayerFieldControls();
        SoftResetInBattlePyramid();
        return TRUE;
    }

    return FALSE;
}

static bool8 BattlePyramidRetireStartCallback(void)
{
    InitBattlePyramidRetire();
    gMenuCallback = BattlePyramidRetireCallback;

    return FALSE;
}

static bool8 BattlePyramidRetireReturnCallback(void)
{
    InitStartMenu();
    gMenuCallback = HandleStartMenuInput;

    return FALSE;
}

static bool8 BattlePyramidRetireCallback(void)
{
    switch (RunSaveCallback())
    {
    case SAVE_SUCCESS: // No (Stay in battle pyramid)
        RemoveExtraStartMenuWindows();
        gMenuCallback = BattlePyramidRetireReturnCallback;
        return FALSE;
    case SAVE_IN_PROGRESS:
        return FALSE;
    case SAVE_CANCELED: // Yes (Retire from battle pyramid)
        ClearDialogWindowAndFrameToTransparent(0, TRUE);
        ScriptUnfreezeObjectEvents();
        UnlockPlayerFieldControls();
        ScriptContext_SetupScript(BattlePyramid_Retire);
        return TRUE;
    }

    return FALSE;
}

static void InitSave(void)
{
    SaveMapView();
    sSaveDialogCallback = SaveConfirmSaveCallback;
    sSavingComplete = FALSE;
}

static u8 RunSaveCallback(void)
{
    // True if text is still printing
    if (RunTextPrintersAndIsPrinter0Active() == TRUE)
    {
        return SAVE_IN_PROGRESS;
    }

    sSavingComplete = FALSE;
    return sSaveDialogCallback();
}

void SaveGame(void)
{
    InitSave();
    CreateTask(SaveGameTask, 0x50);
}

static void ShowSaveMessage(const u8 *message, u8 (*saveCallback)(void))
{
    StringExpandPlaceholders(gSystemStringVar, message);
    LoadMessageBoxAndFrameGfx(0, TRUE);
    AddTextPrinterForMessage_2(TRUE);
    sSavingComplete = TRUE;
    sSaveDialogCallback = saveCallback;
}

static void SaveGameTask(u8 taskId)
{
    u8 status = RunSaveCallback();

    switch (status)
    {
    case SAVE_CANCELED:
    case SAVE_ERROR:
        gSpecialVar_Result = 0;
        break;
    case SAVE_SUCCESS:
        gSpecialVar_Result = status;
        break;
    case SAVE_IN_PROGRESS:
        return;
    }

    DestroyTask(taskId);
    ScriptContext_Enable();
}

static void HideSaveMessageWindow(void)
{
    ClearDialogWindowAndFrame(0, TRUE);
}

static void HideSaveInfoWindow(void)
{
    RemoveSaveInfoWindow();
}

static void SaveStartTimer(void)
{
    sSaveDialogTimer = 60;
}

static bool8 SaveSuccesTimer(void)
{
    sSaveDialogTimer--;

    if (JOY_HELD(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        return TRUE;
    }
    if (sSaveDialogTimer == 0)
    {
        return TRUE;
    }

    return FALSE;
}

static bool8 SaveErrorTimer(void)
{
    if (sSaveDialogTimer != 0)
    {
        sSaveDialogTimer--;
    }
    else if (JOY_HELD(A_BUTTON))
    {
        return TRUE;
    }

    return FALSE;
}

static u8 SaveConfirmSaveCallback(void)
{
    ClearStdWindowAndFrame(GetStartMenuWindowId(), FALSE);
    RemoveStartMenuWindow();
    ShowSaveInfoWindow();

    if (InBattlePyramid())
    {
        ShowSaveMessage(gText_BattlePyramidConfirmRest, SaveYesNoCallback);
    }
    else
    {
        ShowSaveMessage(gText_ConfirmSave, SaveYesNoCallback);
    }

    return SAVE_IN_PROGRESS;
}

static u8 SaveYesNoCallback(void)
{
    DisplayYesNoMenuDefaultYes(); // Show Yes/No menu
    sSaveDialogCallback = SaveConfirmInputCallback;
    return SAVE_IN_PROGRESS;
}

static u8 SaveConfirmInputCallback(void)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case 0: // Yes
        switch (gSaveFileStatus)
        {
        case SAVE_STATUS_EMPTY:
        case SAVE_STATUS_CORRUPT:
            if (gDifferentSaveFile == FALSE)
            {
                sSaveDialogCallback = SaveFileExistsCallback;
                return SAVE_IN_PROGRESS;
            }

            sSaveDialogCallback = SaveSavingMessageCallback;
            return SAVE_IN_PROGRESS;
        default:
            sSaveDialogCallback = SaveFileExistsCallback;
            return SAVE_IN_PROGRESS;
        }
    case -1: // B Button
    case 1: // No
        HideSaveInfoWindow();
        HideSaveMessageWindow();
        return SAVE_CANCELED;
    }

    return SAVE_IN_PROGRESS;
}

// A different save file exists
static u8 SaveFileExistsCallback(void)
{
    if (gDifferentSaveFile == TRUE)
    {
        ShowSaveMessage(gText_DifferentSaveFile, SaveConfirmOverwriteDefaultNoCallback);
    }
    else
    {
        ShowSaveMessage(gText_AlreadySavedFile, SaveConfirmOverwriteCallback);
    }

    return SAVE_IN_PROGRESS;
}

static u8 SaveConfirmOverwriteDefaultNoCallback(void)
{
    DisplayYesNoMenuWithDefault(1); // Show Yes/No menu (No selected as default)
    sSaveDialogCallback = SaveOverwriteInputCallback;
    return SAVE_IN_PROGRESS;
}

static u8 SaveConfirmOverwriteCallback(void)
{
    DisplayYesNoMenuDefaultYes(); // Show Yes/No menu
    sSaveDialogCallback = SaveOverwriteInputCallback;
    return SAVE_IN_PROGRESS;
}

static u8 SaveOverwriteInputCallback(void)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case 0: // Yes
        sSaveDialogCallback = SaveSavingMessageCallback;
        return SAVE_IN_PROGRESS;
    case -1: // B Button
    case 1: // No
        HideSaveInfoWindow();
        HideSaveMessageWindow();
        return SAVE_CANCELED;
    }

    return SAVE_IN_PROGRESS;
}

static u8 SaveSavingMessageCallback(void)
{
    ShowSaveMessage(gText_SavingDontTurnOff, SaveDoSaveCallback);
    return SAVE_IN_PROGRESS;
}

static u8 SaveDoSaveCallback(void)
{
    u8 saveStatus;

    IncrementGameStat(GAME_STAT_SAVED_GAME);
    PausePyramidChallenge();

    if (gDifferentSaveFile == TRUE)
    {
        saveStatus = TrySavingData(SAVE_OVERWRITE_DIFFERENT_FILE);
        gDifferentSaveFile = FALSE;
    }
    else
    {
        saveStatus = TrySavingData(SAVE_NORMAL);
    }

    if (saveStatus == SAVE_STATUS_OK)
        ShowSaveMessage(gText_PlayerSavedGame, SaveSuccessCallback);
    else
        ShowSaveMessage(gText_SaveError, SaveErrorCallback);

    SaveStartTimer();
    return SAVE_IN_PROGRESS;
}

static u8 SaveSuccessCallback(void)
{
    if (!IsTextPrinterActive(0))
    {
        PlaySE(SE_SAVE);
        sSaveDialogCallback = SaveReturnSuccessCallback;
    }

    return SAVE_IN_PROGRESS;
}

static u8 SaveReturnSuccessCallback(void)
{
    if (!IsSEPlaying() && SaveSuccesTimer())
    {
        HideSaveInfoWindow();
        return SAVE_SUCCESS;
    }
    else
    {
        return SAVE_IN_PROGRESS;
    }
}

static u8 SaveErrorCallback(void)
{
    if (!IsTextPrinterActive(0))
    {
        PlaySE(SE_BOO);
        sSaveDialogCallback = SaveReturnErrorCallback;
    }

    return SAVE_IN_PROGRESS;
}

static u8 SaveReturnErrorCallback(void)
{
    if (!SaveErrorTimer())
    {
        return SAVE_IN_PROGRESS;
    }
    else
    {
        HideSaveInfoWindow();
        return SAVE_ERROR;
    }
}

static void InitBattlePyramidRetire(void)
{
    sSaveDialogCallback = BattlePyramidConfirmRetireCallback;
    sSavingComplete = FALSE;
}

static u8 BattlePyramidConfirmRetireCallback(void)
{
    ClearStdWindowAndFrame(GetStartMenuWindowId(), FALSE);
    RemoveStartMenuWindow();
    ShowSaveMessage(gText_BattlePyramidConfirmRetire, BattlePyramidRetireYesNoCallback);

    return SAVE_IN_PROGRESS;
}

static u8 BattlePyramidRetireYesNoCallback(void)
{
    DisplayYesNoMenuWithDefault(1); // Show Yes/No menu (No selected as default)
    sSaveDialogCallback = BattlePyramidRetireInputCallback;

    return SAVE_IN_PROGRESS;
}

static u8 BattlePyramidRetireInputCallback(void)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case 0: // Yes
        return SAVE_CANCELED;
    case -1: // B Button
    case 1: // No
        HideSaveMessageWindow();
        return SAVE_SUCCESS;
    }

    return SAVE_IN_PROGRESS;
}

static void VBlankCB_LinkBattleSave(void)
{
    TransferPlttBuffer();
}

static bool32 InitSaveWindowAfterLinkBattle(u8 *state)
{
    switch (*state)
    {
    case 0:
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0);
        SetVBlankCallback(NULL);
        ScanlineEffect_Stop();
        DmaClear16(3, PLTT, PLTT_SIZE);
        DmaFillLarge16(3, 0, (void *)VRAM, VRAM_SIZE, 0x1000);
        break;
    case 1:
        ResetSpriteData();
        ResetTasks();
        ResetPaletteFade();
        ScanlineEffect_Clear();
        break;
    case 2:
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sBgTemplates_LinkBattleSave, ARRAY_COUNT(sBgTemplates_LinkBattleSave));
        InitWindows(sWindowTemplates_LinkBattleSave);
        LoadUserWindowBorderGfx_(0, 8, 224);
        Menu_LoadStdPalAt(240);
        break;
    case 3:
        ShowBg(0);
        BlendPalettes(PALETTES_ALL, 16, RGB_BLACK);
        SetVBlankCallback(VBlankCB_LinkBattleSave);
        EnableInterrupts(1);
        break;
    case 4:
        return TRUE;
    }

    (*state)++;
    return FALSE;
}

void CB2_SetUpSaveAfterLinkBattle(void)
{
    if (InitSaveWindowAfterLinkBattle(&gMain.state))
    {
        CreateTask(Task_SaveAfterLinkBattle, 0x50);
        SetMainCallback2(CB2_SaveAfterLinkBattle);
    }
}

static void CB2_SaveAfterLinkBattle(void)
{
    RunTasks();
    UpdatePaletteFade();
}

static void Task_SaveAfterLinkBattle(u8 taskId)
{
    s16 *state = gTasks[taskId].data;

    if (!gPaletteFade.active)
    {
        switch (*state)
        {
        case 0:
            FillWindowPixelBuffer(0, PIXEL_FILL(1));
            AddTextPrinterParameterized2(0,
                                        FONT_NORMAL,
                                        gText_SavingDontTurnOffPower,
                                        TEXT_SKIP_DRAW,
                                        NULL,
                                        TEXT_COLOR_DARK_GRAY,
                                        TEXT_COLOR_WHITE,
                                        TEXT_COLOR_LIGHT_GRAY);
            DrawTextBorderOuter(0, 8, 14);
            PutWindowTilemap(0);
            CopyWindowToVram(0, COPYWIN_FULL);
            BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);

            if (gWirelessCommType != 0 && InUnionRoom())
            {
                if (Link_AnyPartnersPlayingFRLG_JP())
                {
                    *state = 1;
                }
                else
                {
                    *state = 5;
                }
            }
            else
            {
                gSoftResetDisabled = TRUE;
                *state = 1;
            }
            break;
        case 1:
            SetContinueGameWarpStatusToDynamicWarp();
            WriteSaveBlock2();
            *state = 2;
            break;
        case 2:
            if (WriteSaveBlock1Sector())
            {
                ClearContinueGameWarpStatus2();
                *state = 3;
                gSoftResetDisabled = FALSE;
            }
            break;
        case 3:
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
            *state = 4;
            break;
        case 4:
            FreeAllWindowBuffers();
            SetMainCallback2(gMain.savedCallback);
            DestroyTask(taskId);
            break;
        case 5:
            CreateTask(Task_LinkFullSave, 5);
            *state = 6;
            break;
        case 6:
            if (!FuncIsActiveTask(Task_LinkFullSave))
            {
                *state = 3;
            }
            break;
        }
    }
}

static void ShowSaveInfoWindow(void)
{
    struct WindowTemplate saveInfoWindow = sSaveInfoWindowTemplate;
    u8 gender;
    u8 color;
    u32 xOffset;
    u32 yOffset;

    if (!FlagGet(FLAG_SYS_POKEDEX_GET))
    {
        saveInfoWindow.height -= 2;
    }

    sSaveInfoWindowId = AddWindow(&saveInfoWindow);
    DrawStdWindowFrame(sSaveInfoWindowId, FALSE);

    gender = gSaveBlock2Ptr->playerGender;
    color = TEXT_COLOR_RED;  // Red when female, blue when male.

    if (gender == MALE)
    {
        color = TEXT_COLOR_BLUE;
    }

    // Print region name
    yOffset = 1;
    BufferSaveMenuText(SAVE_MENU_LOCATION, gSystemStringVar, TEXT_COLOR_GREEN);
    AddTextPrinterParameterized(sSaveInfoWindowId, FONT_NORMAL, gSystemStringVar, 0, yOffset, TEXT_SKIP_DRAW, NULL);

    // Print player name
    yOffset += 16;
    AddTextPrinterParameterized(sSaveInfoWindowId, FONT_NORMAL, gText_SavingPlayer, 0, yOffset, TEXT_SKIP_DRAW, NULL);
    BufferSaveMenuText(SAVE_MENU_NAME, gSystemStringVar, color);
    xOffset = GetStringRightAlignXOffset(FONT_NORMAL, gSystemStringVar, 0x70);
    PrintPlayerNameOnWindow(sSaveInfoWindowId, gSystemStringVar, xOffset, yOffset);

    // Print badge count
    yOffset += 16;
    AddTextPrinterParameterized(sSaveInfoWindowId, FONT_NORMAL, gText_SavingBadges, 0, yOffset, TEXT_SKIP_DRAW, NULL);
    BufferSaveMenuText(SAVE_MENU_BADGES, gSystemStringVar, color);
    xOffset = GetStringRightAlignXOffset(FONT_NORMAL, gSystemStringVar, 0x70);
    AddTextPrinterParameterized(sSaveInfoWindowId, FONT_NORMAL, gSystemStringVar, xOffset, yOffset, TEXT_SKIP_DRAW, NULL);

    if (FlagGet(FLAG_SYS_POKEDEX_GET) == TRUE)
    {
        // Print pokedex count
        yOffset += 16;
        AddTextPrinterParameterized(sSaveInfoWindowId, FONT_NORMAL, gText_SavingPokedex, 0, yOffset, TEXT_SKIP_DRAW, NULL);
        BufferSaveMenuText(SAVE_MENU_CAUGHT, gSystemStringVar, color);
        xOffset = GetStringRightAlignXOffset(FONT_NORMAL, gSystemStringVar, 0x70);
        AddTextPrinterParameterized(sSaveInfoWindowId, FONT_NORMAL, gSystemStringVar, xOffset, yOffset, TEXT_SKIP_DRAW, NULL);
    }

    // Print play time
    yOffset += 16;
    AddTextPrinterParameterized(sSaveInfoWindowId, FONT_NORMAL, gText_SavingTime, 0, yOffset, TEXT_SKIP_DRAW, NULL);
    BufferSaveMenuText(SAVE_MENU_PLAY_TIME, gSystemStringVar, color);
    xOffset = GetStringRightAlignXOffset(FONT_NORMAL, gSystemStringVar, 0x70);
    AddTextPrinterParameterized(sSaveInfoWindowId, FONT_NORMAL, gSystemStringVar, xOffset, yOffset, TEXT_SKIP_DRAW, NULL);

    CopyWindowToVram(sSaveInfoWindowId, COPYWIN_GFX);
}

static void RemoveSaveInfoWindow(void)
{
    ClearStdWindowAndFrame(sSaveInfoWindowId, FALSE);
    RemoveWindow(sSaveInfoWindowId);
}

static void Task_WaitForBattleTowerLinkSave(u8 taskId)
{
    if (!FuncIsActiveTask(Task_LinkFullSave))
    {
        DestroyTask(taskId);
        ScriptContext_Enable();
    }
}

#define tInBattleTower data[2]

void SaveForBattleTowerLink(void)
{
    u8 taskId = CreateTask(Task_LinkFullSave, 5);
    gTasks[taskId].tInBattleTower = TRUE;
    gTasks[CreateTask(Task_WaitForBattleTowerLinkSave, 6)].data[1] = taskId;
}

#undef tInBattleTower

static void HideStartMenuWindow(void)
{
    DeleteAllStartMenuIcons();
    ClearStdWindowAndFrame(GetStartMenuWindowId(), TRUE);
    RemoveStartMenuWindow();
    ScriptUnfreezeObjectEvents();
    UnlockPlayerFieldControls();
}

void HideStartMenu(void)
{
    PlaySE(SE_SELECT);
    HideStartMenuWindow();
}

void AppendToList(u8 *list, u8 *pos, u8 newEntry)
{
    list[*pos] = newEntry;
    (*pos)++;
}

static bool8 QuestMenuCallback(void)
{
    CreateTask(Task_QuestMenu_OpenFromStartMenu, 0);
    return TRUE;
}


static bool8 StartMenuDexNavCallback(void)
{
    CreateTask(Task_OpenDexNavFromStartMenu, 0);
    return TRUE;
}

//
#include "malloc.h"
void LoadStartMenuIcon(u8 iconId, u8 position)
{
    u8 internalSpriteNum; // Just stores the index of the sprite
    struct SpritePalette palSheet;
    struct OamData oam = {0};
    struct SpriteTemplate spriteTemplate = sStartMenuIconSpriteTemplate;

    // Both of these are finetuned for this exact start menu size. If your is different, you might need to tweak this
    u8 x = (gWindows[GetStartMenuWindowId()].window.tilemapLeft * 8) + 8;
    u8 y = (gWindows[GetStartMenuWindowId()].window.tilemapTop + 15) + ((position) << 4) + (position * 3);

    // Keeping this on the stack is way to much so stuff it on the heap
    iconFrames = Alloc(sizeof(union AnimCmd) * 2);

    // This is what will set the particular frame needed
    if (sStartMenuCursorPos == position)                                // If the current option is selected
        iconFrames[0].frame.imageValue = iconId + COLOR_ICON_OFFSET;    // Load in the colored icon
    else
        iconFrames[0].frame.imageValue = iconId;                        // Load in the grayscale icon
    
    iconFrames[0].frame.duration = 30;  // Not sure this has a use here since its a static frame we need
    iconFrames[0].frame.vFlip = FALSE;  // These 2 prevent it from occasionally inverting
    iconFrames[0].frame.hFlip = FALSE;

    iconFrames[1].type = -1;            // Same as ANIMCMD_END(0)

    // Prepare the Sprite Palette
    palSheet.tag = spriteTagId;  // This tag could be anything really
    palSheet.data = sStartMenuIconsPal;

    oam = *spriteTemplate.oam;                       // Copy over original oam
    if (!sIsStartMenuIconPaletteLoaded)
    {
        oam.paletteNum = LoadSpritePalette(&palSheet);   // Load palette and set appropriate palNum
        gStartMenuIconPaletteNum = oam.paletteNum;       // Copy the paletteNum of the Icon Palette
        sIsStartMenuIconPaletteLoaded = TRUE;
    }
    else
    {
        // Palette already loaded, no need to load a new sprite palette so pull it from gStartMenuIconPaletteNum
        oam.paletteNum = gStartMenuIconPaletteNum;
    }

    spriteTemplate.oam = &oam; // Back to Sender

    spriteTemplate.anims = (const union AnimCmd *const *)&iconFrames;   // Attach the edited "animation"
    //spriteTemplate.soloSpriteId = iconId;
    
    // Create the sprite and load the appropriate frame
    internalSpriteNum = CreateSpriteAtEnd(&spriteTemplate, x, y, 0);
    AnimateSprite(&gSprites[internalSpriteNum]);

    Free((void *)iconFrames);
}

static void DeleteAllStartMenuIcons(void)
{
    u32 i;

    for (i = 0; i <= MAX_SPRITES; i++)
    {
        if (gSprites[i].dummyValue == startMenuIconId) // Sprite is an icon for the start menu
        {
            DestroySpriteAndFreeResources(&gSprites[i]);
        }
    }

    sIsStartMenuIconPaletteLoaded = FALSE;
    gAreStartMenuIconsReady = FALSE;
}

static void DeleteStartMenuIcon(u8 position)
{
    u32 i;

    for (i = 0; i < MAX_SPRITES; i++)
    {
        if (gSprites[i].y == (gWindows[GetStartMenuWindowId()].window.tilemapTop + 15) + ((position) << 4) + (position * 3) && gSprites[i].dummyValue == startMenuIconId) // Sprite is an icon for the start menu
        {
            DestroySpriteAndFreeResources(&gSprites[i]);
            break;
        }
    }
}

static u8 GetIndexOfOptionInsStartMenuItems(u8 index)
{
    s32 i;

    for (i = 0; i < ARRAY_COUNT(sStartMenuItems); i++)
    {
        if (sStartMenuItems[i].func.u8_void == sStartMenuItems[sCurrentStartMenuActions[index]].func.u8_void)
        {
            break;
        }
    }

    if (i == ARRAY_COUNT(sStartMenuItems))
    // index is not in sStartMenuItems
    {
        return FALSE;
    }

    return i;
}

static void DynamicallyLoadStartMenuIcon(u8 index)
{
    // Add any new options with icons here
    switch (GetIndexOfOptionInsStartMenuItems(index))
    {
    case MENU_ACTION_POKEDEX:
        LoadStartMenuIcon(0, index);
        break;
    case MENU_ACTION_POKEMON:
        LoadStartMenuIcon(1, index);
        break;
    case MENU_ACTION_BAG:
        LoadStartMenuIcon(2, index);
        break;
    case MENU_ACTION_PLAYER:
        LoadStartMenuIcon(3, index);
        break;
    case MENU_ACTION_SAVE:
        LoadStartMenuIcon(4, index);
        break;
    case MENU_ACTION_OPTION:
        LoadStartMenuIcon(5, index);
        break;
    case MENU_ACTION_EXIT:
        LoadStartMenuIcon(6, index);
        break;
    case MENU_ACTION_QUEST_MENU:
        LoadStartMenuIcon(7, index);
        break;
    default:
        break;
    }
}

bool8 gIsAStartMenuIconAtPosition(u8 position)
{
    u32 i;

    for (i = 0; i < MAX_SPRITES; i++)
    {
        if (gSprites[i].y == (gWindows[GetStartMenuWindowId()].window.tilemapTop + 15) + ((position) << 4) + (position * 3) && gSprites[i].dummyValue == startMenuIconId) // Sprite is an icon for the start menu
        {
            return TRUE;
        }
    }

    return FALSE;
}