#include <PR/ultratypes.h>
#include <PR/gbi.h>
#include "audio/external.h"
#include "behavior_data.h"
#include "engine/behavior_script.h"
#include "engine/graph_node.h"
#include "engine/math_util.h"
#include "file_select.h"
#include "gfx_dimensions.h"
#include "game/area.h"
#include "game/game_init.h"
#include "game/ingame_menu.h"
#include "game/object_helpers.h"
#include "game/object_list_processor.h"
#include "game/print.h"
#include "game/rumble_init.h"
#include "game/save_file.h"
#include "game/segment2.h"
#include "game/segment7.h"
#include "game/spawn_object.h"
#include "game/level_update.h"
#include "text_strings.h"
#include "sm64.h"

#ifdef COMMAND_LINE_OPTIONS
#include "pc/cliopts.h"
#endif

#ifdef TARGET_WII_U
#include <vpad/input.h>
#include <math.h>
#include <coreinit/debug.h>
#include <stdint.h>
#include <stdbool.h>
#endif


/**
 * @file file_select.c
 * This file implements how the file select and it's menus render and function.
 * That includes button IDs rendered as object models, strings, hand cursor,
 * special menu messages and phases, button states and button clicked checks.
 */

// Amount of main menu buttons defined in the code called by spawn_object_rel_with_rot.
// See file_select.h for the names in MenuButtonTypes.
static struct Object *sMainMenuButtons[MENU_BUTTON_OPTION_MAX];

// Gets the current cursor position
static s8 cursorLoc = 0;
static s8 subCursorLoc = 0;

// Determines if the input is possible.
static u8 allowInput = 0;

// Checks if you are on the bottom row
static u8 rowBottom = 0;

// Used for text opacifying. If it is below 250, it is constantly incremented.
static u8 sTextBaseAlpha = 0;

// 2D position of the cursor on the screen.
// sCursorPos[0]: X | sCursorPos[1]: Y
static f32 sCursorPos[] = {0, 0};

// 2D position of the arrows on the screen.
static f32 sArrowPosY = 205;

// A timer to determine when the arrow should move
static f32 sArrowTimer = 0;

// Whether to fade out text or not.
static s8 sFadeOutText = FALSE;

// File select timer that keeps counting until it reaches 1000.
// Used to prevent buttons from being clickable as soon as a menu loads.
static s16 sMainMenuTimer = 0;

// Defines the value of the save slot selected in the menu.
// File A: 1 | File B: 2 | File C: 3
static s8 sSelectedFileNum;

#ifdef TARGET_WII_U
static bool sUsingTouchInput = false;
static bool sCursorVisible = false;
static bool sCursorForcedVisible = false;
#endif

static unsigned char textNew[] = { TEXT_NEW };
static unsigned char starIcon[] = { GLYPH_STAR, GLYPH_SPACE };
static unsigned char textSelectFile[] = { TEXT_SELECT_FILE };

/**
 * Menu Buttons Menu Initial Action
 * Aligns menu buttons so they can stay in their original
 * positions when you choose a button.
 */
void bhv_menu_button_init(void) {
    gCurrentObject->oMenuButtonOrigPosX = gCurrentObject->oParentRelativePosX;
    gCurrentObject->oMenuButtonOrigPosY = gCurrentObject->oParentRelativePosY;
}

/**
 * Menu Buttons Menu Loop Action
 * Handles the functions of the button states and
 * object scale for each button.
 */
void bhv_menu_button_loop(void) {
    switch (gCurrentObject->oMenuButtonState) {
        case MENU_BUTTON_STATE_DEFAULT: // Button state
            gCurrentObject->oMenuButtonOrigPosZ = gCurrentObject->oPosZ;
            break;
        case MENU_BUTTON_STATE_FADING: // Switching from button to menu state
            sTextBaseAlpha = 0;
            break;
    }
}

/**
 * Loads a save file selected after it goes into a full screen state
 * retuning sSelectedFileNum to a save value defined in fileNum.
 */
void load_main_menu_save_file(struct Object *fileButton, s32 fileNum) {
    sSelectedFileNum = fileNum;
}

/**
 * Menu Buttons Menu Manager Initial Action
 * Creates models of the buttons in the menu.
 */
void bhv_menu_button_manager_init(void) {
    // File A
    sMainMenuButtons[MENU_BUTTON_PLAY_FILE_A] = spawn_object_rel_with_rot(gCurrentObject, MODEL_MAIN_MENU_FILE_BUTTON_A, bhvMenuButton, -6400, 2800, 0, 0, 0, 0);
    // File B
    sMainMenuButtons[MENU_BUTTON_PLAY_FILE_B] = spawn_object_rel_with_rot(gCurrentObject, MODEL_MAIN_MENU_FILE_BUTTON_B, bhvMenuButton, 0, 0, 0, 0, 0, 0);
    // File C
    sMainMenuButtons[MENU_BUTTON_PLAY_FILE_C] = spawn_object_rel_with_rot(gCurrentObject, MODEL_MAIN_MENU_FILE_BUTTON_C, bhvMenuButton, 6400, 2800, 0, 0, 0, 0);

    // Options
    sMainMenuButtons[MENU_BUTTON_OPTIONS] = spawn_object_rel_with_rot(gCurrentObject, MODEL_MAIN_MENU_FILE_OPTIONS, bhvMenuButton, -2500, -5000, 0, 0, 0, 0);
    // Return
    sMainMenuButtons[MENU_BUTTON_RETURN] = spawn_object_rel_with_rot(gCurrentObject, MODEL_MAIN_MENU_FILE_RETURN, bhvMenuButton, 6900, -5000, 0, 0, 0, 0);

    sTextBaseAlpha = 0;
}

/**
 * Menu Buttons Menu Manager Loop Action
 * Calls a menu function depending of the button chosen.
 */
void bhv_menu_button_manager_loop(void) {
    if ((gPlayer3Controller->buttonPressed & A_BUTTON) && (sMainMenuTimer > 15) && (rowBottom == 0)) {
        switch (cursorLoc) {
            case 0:
                load_main_menu_save_file(sMainMenuButtons[MENU_BUTTON_PLAY_FILE_A], 1);
                play_sound(SOUND_MENU_STAR_SOUND_OKEY_DOKEY, gGlobalSoundSource);
#ifdef RUMBLE_FEEDBACK
                queue_rumble_data(60, 70);
                queue_rumble_decay(1);
#endif
                break;
            case 1:
                load_main_menu_save_file(sMainMenuButtons[MENU_BUTTON_PLAY_FILE_B], 2);
                play_sound(SOUND_MENU_STAR_SOUND_OKEY_DOKEY, gGlobalSoundSource);
#ifdef RUMBLE_FEEDBACK
                queue_rumble_data(60, 70);
                queue_rumble_decay(1);
#endif
                break;
            case 2:
                load_main_menu_save_file(sMainMenuButtons[MENU_BUTTON_PLAY_FILE_C], 3);
                play_sound(SOUND_MENU_STAR_SOUND_OKEY_DOKEY, gGlobalSoundSource);
#ifdef RUMBLE_FEEDBACK
                queue_rumble_data(60, 70);
                queue_rumble_decay(1);
#endif
                break;
        }
    } else if ((gPlayer3Controller->buttonPressed & A_BUTTON) && (sMainMenuTimer > 15) && (rowBottom == 1)) {
        switch (subCursorLoc) {
            case 0:
                play_sound(SOUND_MENU_PAUSE_OPEN, gGlobalSoundSource);
#ifdef RUMBLE_FEEDBACK
                queue_rumble_data(60, 70);
                queue_rumble_decay(1);
#endif
                break;
            case 1:
                play_sound(SOUND_MENU_PINCH_MARIO_FACE, gGlobalSoundSource);
#ifdef RUMBLE_FEEDBACK
                queue_rumble_data(60, 70);
                queue_rumble_decay(1);
#endif
                break;
        }        
    }
}

/**
 * Cursor function that handles analog stick input and button presses with a function near the end.
 */

// clamp helper
static float clampf(float v, float lo, float hi) {
    return (v < lo) ? lo : (v > hi) ? hi : v;
}

// How Nintendo does it in sead
/*
        u32 sample_num = sead::Mathu::clamp(1, v_pad_info.last_read_length, mTouchPanelSamplingUseNum);

        VPADTouchData tp_data;

        for (u32 i = 0; i < sample_num; i++)
        {
            const VPADTouchData& tp_sample_data = v_pad_info.status[i].tpNormal;
            if (tp_sample_data.validity == (VPAD_INVALID_X | VPAD_INVALID_Y))
                continue;

            VPADTouchData tp_calibrated_data;
            VPADGetTPCalibratedPoint(VPAD_CHAN_0, &tp_calibrated_data, &tp_sample_data);

            if (!(tp_sample_data.validity & VPAD_INVALID_X))
            {
                tp_data.x = tp_calibrated_data.x;
                tp_valid_x = true;
            }

            if (!(tp_sample_data.validity & VPAD_INVALID_Y))
            {
                tp_data.y = tp_calibrated_data.y;
                tp_valid_y = true;
            }

            if (tp_valid_x && tp_valid_y)
                break;
        }

        bool touched = tp_valid_x && tp_valid_y;
        f32 touch_x = tp_data.x;
        f32 touch_y = tp_data.y;
*/

#ifdef TARGET_WII_U
struct Box { float x1, y1, x2, y2; };

static inline int is_inside(struct Box box, float tx, float ty) {
    float left   = fminf(box.x1, box.x2);
    float right  = fmaxf(box.x1, box.x2);
    float top    = fminf(box.y1, box.y2);
    float bottom = fmaxf(box.y1, box.y2);
    return (tx >= left && tx <= right && ty >= top && ty <= bottom);
}

static void handle_wiiu_touch_input(void) {
    bool tp_valid_x = false;
    bool tp_valid_y = false;

    VPADTouchData tp_data;

    u32 sample_num = clampf(v_pad_info.last_read_length, 1, 3);

    for (u32 i = 0; i < sample_num; i++) {
        const VPADTouchData& tp_sample_data = v_pad_info.status[i].tpNormal;
        if (tp_sample_data.validity == (VPAD_INVALID_X | VPAD_INVALID_Y))
            continue;

        VPADTouchData tp_calibrated_data;
        VPADGetTPCalibratedPoint(VPAD_CHAN_0, &tp_calibrated_data, &tp_sample_data);

        if (!(tp_sample_data.validity & VPAD_INVALID_X)) {
            tp_data.x = tp_calibrated_data.x;
            tp_valid_x = true;
        }

        if (!(tp_sample_data.validity & VPAD_INVALID_Y)) {
            tp_data.y = tp_calibrated_data.y;
            tp_valid_y = true;
        }

        if (tp_valid_x && tp_valid_y)
            break;
    }

    bool touched = tp_valid_x && tp_valid_y;
    f32 touch_x = tp_data.x;
    f32 touch_y = tp_data.y;

    if (touched) {
        OSReport("Touch detected at: (%f, %f)\n", touch_x, touch_y);
    }
}
// Old method
/*
static void handle_wiiu_touch_input(void) {
    static bool wasTouched = false;

    VPADStatus vpad;
    VPADReadError err;
    VPADRead(VPAD_CHAN_0, &vpad, 1, &err);
    if (err != VPAD_READ_SUCCESS) return;

    VPADGetTPCalibratedPoint(VPAD_CHAN_0, &vpad.tpFiltered1, &vpad.tpFiltered1);

    float tx = vpad.tpFiltered1.x;
    float ty = vpad.tpFiltered1.y;

    sUsingTouchInput = vpad.tpFiltered1.touched;

    // Hide cursor immediately when touch starts
    if (sUsingTouchInput && !wasTouched) {
        sCursorVisible = false;
    }

    // Only consider touch release for button logic
    if (wasTouched && !vpad.tpFiltered1.touched) {
        OSReport("Touch released: X = %0.2f, Y = %0.2f\n", tx, ty);

        // Define bounding boxes
        struct Box fileA = { 255.0f,  165.0f, 470.0f, 315.0f };
        struct Box fileB = { 528.0f, 287.0f, 748.0f, 432.0f };
        struct Box fileC = { 810.0f, 165.0f, 1027.0f, 315.0f };
        struct Box fileOptions = { 336.0f, 520.0f, 722.0f, 630.0f };
        struct Box returnToMenu = { 836.0f, 520.0f, 1043.0f, 630.0f };

        if (is_inside(fileA, tx, ty)) {
            load_main_menu_save_file(sMainMenuButtons[MENU_BUTTON_PLAY_FILE_A], 1);
            play_sound(SOUND_MENU_STAR_SOUND_OKEY_DOKEY, gGlobalSoundSource);
        } else if (is_inside(fileB, tx, ty)) {
            load_main_menu_save_file(sMainMenuButtons[MENU_BUTTON_PLAY_FILE_B], 2);
            play_sound(SOUND_MENU_STAR_SOUND_OKEY_DOKEY, gGlobalSoundSource);
        } else if (is_inside(fileC, tx, ty)) {
            load_main_menu_save_file(sMainMenuButtons[MENU_BUTTON_PLAY_FILE_C], 3);
            play_sound(SOUND_MENU_STAR_SOUND_OKEY_DOKEY, gGlobalSoundSource);
        } else if (is_inside(fileOptions, tx, ty)) {
            play_sound(SOUND_MENU_PAUSE_OPEN, gGlobalSoundSource);
        } else if (is_inside(returnToMenu, tx, ty)) {
            play_sound(SOUND_MENU_PINCH_MARIO_FACE, gGlobalSoundSource);
        }
    }
    wasTouched = sUsingTouchInput;
}*/

#endif

void handle_controller_cursor_input(void) {
    s16 rawStickX = gPlayer3Controller->rawStickX;
    s16 rawStickY = gPlayer3Controller->rawStickY;
    s16 dPadL = gPlayer1Controller->buttonPressed & L_JPAD;
    s16 dPadR = gPlayer1Controller->buttonPressed & R_JPAD;
    s16 dPadU = gPlayer1Controller->buttonPressed & U_JPAD;
    s16 dPadD = gPlayer1Controller->buttonPressed & D_JPAD;

#ifdef TARGET_WII_U
    // Show cursor when stick moved or D-Pad pressed, but only if touch isn't active
    if (!sUsingTouchInput) {
        if ((rawStickX > 2 || rawStickX < -2 || rawStickY > 2 || rawStickY < -2 || dPadL || dPadR || dPadU || dPadD) 
            && !sCursorForcedVisible) {
            sCursorVisible = true;
            sCursorForcedVisible = true;
        }
    }
#endif

    // Handle deadzone
    if (rawStickY > -2 && rawStickY < 2) {
        rawStickY = 0;
    }
    if (rawStickX > -2 && rawStickX < 2) {
        rawStickX = 0;
    }

    // Move cursor
    if ((rawStickX > 60) || (dPadR)) {
        if (allowInput > 1) {
            if (rowBottom == 0) {
                switch (cursorLoc) {
                    case 0:
                        sCursorPos[0] = -11.5f;
                        sCursorPos[1] = 24.0f;
                        cursorLoc = 1;
                        break;
                    case 1:
                        sCursorPos[0] = 81.0f;
                        sCursorPos[1] = 65.0f;
                        cursorLoc = 2;
                        break;
                    case 2:
                        sCursorPos[0] = -104.5f;
                        sCursorPos[1] = 65.0f;
                        cursorLoc = 0;
                        break;
                }
            } else {
                sCursorPos[0] = 90.0f;
                sCursorPos[1] = -57.5f;
                subCursorLoc = 1;
            }
            allowInput = 0;
            play_sound(SOUND_MENU_CHANGE_SELECT, gGlobalSoundSource);
        }
    } else if ((rawStickX < -60) || (dPadL)) {
        if (allowInput > 1) {
            if (rowBottom == 0) {
                switch (cursorLoc) {
                    case 2:
                        sCursorPos[0] = -11.5f;
                        sCursorPos[1] = 24.0f;
                        cursorLoc = 1;
                        break;
                    case 1:
                        sCursorPos[0] = -104.5f;
                        sCursorPos[1] = 65.0f;
                        cursorLoc = 0;
                        break;
                    case 0:
                        sCursorPos[0] = 81.0f;
                        sCursorPos[1] = 65.0f;
                        cursorLoc = 2;
                        break;
                }
            } else {
                sCursorPos[0] = -47.5f;
                sCursorPos[1] = -57.5f;
                subCursorLoc = 0;
            }
            allowInput = 0;
            play_sound(SOUND_MENU_CHANGE_SELECT, gGlobalSoundSource);
        }
    } else if (((rawStickY > 60) || (dPadU)) && (rowBottom == 1)) {
        if (subCursorLoc == 0) {
            if (cursorLoc == 0) {
                // Move to File A
                sCursorPos[0] = -104.5f;
                sCursorPos[1] = 65.0f;
            } else {
                // Move to file B
                sCursorPos[0] = -11.5f;
                sCursorPos[1] = 24.0f;
            }
        } else {
            // Move to File C
            sCursorPos[0] = 81.0f;
            sCursorPos[1] = 65.0f;
            cursorLoc = 2;
        }
        rowBottom = 0;
        play_sound(SOUND_MENU_CHANGE_SELECT, gGlobalSoundSource);
    } else if (((rawStickY < -60) || (dPadD)) && (rowBottom == 0)) {
        if (cursorLoc < 2) {
            // Move to file options
            sCursorPos[0] = -47.5f;
            sCursorPos[1] = -57.5f;
            subCursorLoc = 0;
        } else {
            sCursorPos[0] = 90.0f;
            sCursorPos[1] = -57.5f;
            subCursorLoc = 1;
        }
        rowBottom = 1;
        play_sound(SOUND_MENU_CHANGE_SELECT, gGlobalSoundSource);
    } else {
        allowInput++;
    }

    sArrowTimer++;
    if (sArrowTimer <= 8) {
        sArrowPosY--;
    } else if (sArrowTimer >= 15) {
        if (sArrowPosY >= 205) {
            if (sArrowTimer >= 28) {
                sArrowTimer = 0;
            }
        } else {
            sArrowPosY++;
        }
    }
}

/**
 * Prints the cursor (Player Hand, different to the one in the Player screen)
 * and loads it's controller inputs in handle_controller_cursor_input
 * to be usable on the file select.
 */
void print_menu_cursor(void) {
#ifdef TARGET_WII_U
    handle_wiiu_touch_input();
#endif
    handle_controller_cursor_input();

#ifdef TARGET_WII_U
    if (!sUsingTouchInput && sCursorVisible) {
#endif
    create_dl_translation_matrix(MENU_MTX_PUSH, sCursorPos[0] + 160.0f - 5.0, sCursorPos[1] + 120.0f - 25.0, 0.0f);
    gSPDisplayList(gDisplayListHead++, dl_menu_cursor);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
#ifdef TARGET_WII_U
    }
#endif

    create_dl_translation_matrix(MENU_MTX_PUSH, 20, sArrowPosY, 0.0f);
    gSPDisplayList(gDisplayListHead++, dl_file_select_arrow);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);

    create_dl_translation_matrix(MENU_MTX_PUSH, 270, sArrowPosY, 0.0f);
    gSPDisplayList(gDisplayListHead++, dl_file_select_arrow);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
}

/**
 * Prints the amount of stars of a save file.
 * If a save doesn't exist, print "NEW" instead.
 */
void print_save_file_star_count(s8 fileIndex, s16 x, s16 y) {
    u8 starCountText[4];
    s8 offset = 0;
    s16 starCount;

    if (save_file_exists(fileIndex) == TRUE) {
        starCount = save_file_get_total_star_count(fileIndex, COURSE_MIN - 1, COURSE_MAX - 1);
    
        // Print star icon
        if (starCount > 100) {
            offset = 0;
        } else if (starCount < 10) {
            offset = 18;
        } else {
            offset = 10;
        }
        print_hud_lut_string(HUD_LUT_GLOBAL, x + offset, y, starIcon);
    
        // Print star count
        int_to_str(starCount, starCountText);
        print_hud_lut_string(HUD_LUT_ORANGE, x + 16 + offset, y, starCountText);
    }
}

/**
 * Prints main menu strings that shows on the yellow background menu screen.
 */
void print_main_menu_strings(void) {
    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);

    // Print the "select a file" text
    print_hud_lut_string(HUD_LUT_RED, 70, 20, textSelectFile);

    // Print file star counts
    print_save_file_star_count(SAVE_FILE_A, 85 - 50, 80);
    print_save_file_star_count(SAVE_FILE_B, 85 + 44, 120);
    print_save_file_star_count(SAVE_FILE_C, 197 + 23, 80);

    // Print "New" text if there is no save
    if (save_file_exists(SAVE_FILE_A) == FALSE) {
        print_hud_lut_string(HUD_LUT_ORANGE, 85 - 40, 80, textNew);
    }
    if (save_file_exists(SAVE_FILE_B) == FALSE) {
        print_hud_lut_string(HUD_LUT_ORANGE, 85 + 52.5f, 122, textNew);
    }
    if (save_file_exists(SAVE_FILE_C) == FALSE) {
        print_hud_lut_string(HUD_LUT_ORANGE, 209 + 20, 80, textNew);
    }

    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_end);
}

/**
 * Prints file select strings depending on the menu selected.
 * Also checks if all saves exists and defines text and main menu timers.
 */
static void print_file_select_strings(void) {
    UNUSED u8 filler[8];

    create_dl_ortho_matrix();
    print_main_menu_strings();

    // Timers for menu alpha text and the main menu itself
    if (sTextBaseAlpha < 250) {
        sTextBaseAlpha += 10;
    }
    if (sMainMenuTimer < 1000) {
        sMainMenuTimer++;
    }
}

/**
 * Geo function that prints file select strings and the cursor.
 */
Gfx *geo_file_select_strings_and_menu_cursor(s32 callContext, UNUSED struct GraphNode *node, UNUSED Mat4 mtx) {
    if (callContext == GEO_CONTEXT_RENDER) {
#ifdef TARGET_N3DS
        gDPForceFlush(gDisplayListHead++);
        gDPSet2d(gDisplayListHead++, 1);
        gDPSetIod(gDisplayListHead++, iodFileSelect);
#endif
        print_file_select_strings();
        print_menu_cursor();
#ifdef TARGET_N3DS
        gDPForceFlush(gDisplayListHead++);
        gDPSet2d(gDisplayListHead++, 0);
#endif
    }
    return NULL;
}

/**
 * Initiates file select values after Player Screen.
 * Relocates cursor position of the last save if the game goes back to the Player Screen
 * either completing a course choosing "SAVE & QUIT" or having a game over.
 */
s32 lvl_init_menu_values_and_cursor_pos(UNUSED s32 arg, UNUSED s32 unused) {
    sTextBaseAlpha = 0;
    // Place the cursor over the save file that was being played.
    // gCurrSaveFileNum is 1 by default when the game boots, as such
    // the cursor will point on Player A save file.
    switch (gCurrSaveFileNum) {
        case 1: // File A
            sCursorPos[0] = -104.5f;
            sCursorPos[1] = 65.0f;
            break;
        case 2: // File C
            sCursorPos[0] = -11.5f;
            sCursorPos[1] = 24.0f;
            break;
        case 3: // File B
            sCursorPos[0] = 81.0f;
            sCursorPos[1] = 65.0f;
            break;
    }
    sSelectedFileNum = 0;
    sFadeOutText = FALSE;
    sMainMenuTimer = 0;

    return 0;
}

/**
 * Updates file select menu button objects so they can be interacted.
 * When a save file is selected, it returns fileNum value
 * defined in load_main_menu_save_file.
 */
s32 lvl_update_obj_and_load_file_selected(UNUSED s32 arg, UNUSED s32 unused) {
    area_update_objects();
    return sSelectedFileNum;
}
