#include "texscroll.h"
#include <ultra64.h>
#ifndef TARGET_N64
#include <stdbool.h>
#endif

#include "sm64.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "audio/external.h"
#include "level_update.h"
#include "game_init.h"
#include "level_update.h"
#include "main.h"
#include "engine/math_util.h"
#include "engine/graph_node.h"
#include "area.h"
#include "save_file.h"
#include "sound_init.h"
#include "player.h"
#include "camera.h"
#include "object_list_processor.h"
#include "ingame_menu.h"
#include "obj_behaviors.h"
#include "save_file.h"
#include "debug_course.h"
#include "interaction.h"
#ifdef VERSION_EU
#include "memory.h"
#include "eu_translation.h"
#include "segment_symbols.h"
#endif
#include "level_table.h"
#include "course_table.h"
#include "rumble_init.h"

#ifndef TARGET_N64
#include "pc/pc_main.h"
#include "pc/configfile.h"
#endif

#ifdef COMMAND_LINE_OPTIONS
#include "pc/cliopts.h"
#endif

// TODO: Make these ifdefs better
const char *credits01[] = { "1GAME DIRECTOR", "SHIGERU MIYAMOTO" };
const char *credits02[] = { "2ASSISTANT DIRECTORS", "YOSHIAKI KOIZUMI", "TAKASHI TEZUKA" };
const char *credits03[] = { "2SYSTEM PROGRAMMERS", "YASUNARI NISHIDA", "YOSHINORI TANIMOTO" };
const char *credits04[] = { "3PROGRAMMERS", "HAJIME YAJIMA", "DAIKI IWAMOTO", "TOSHIO IWAWAKI" };

#if defined(VERSION_SH)

const char *credits05[] = { "1CAMERA PROGRAMMER", "TAKUMI KAWAGOE" };
const char *credits06[] = { "1MARIO FACE PROGRAMMER", "GILES GODDARD" };
const char *credits07[] = { "2COURSE DIRECTORS", "YOICHI YAMADA", "YASUHISA YAMAMURA" };
const char *credits08[] = { "2COURSE DESIGNERS", "KENTA USUI", "NAOKI MORI" };
const char *credits09[] = { "3COURSE DESIGNERS", "YOSHIKI HARUHANA", "MAKOTO MIYANAGA", "KATSUHIKO KANNO" };
const char *credits10[] = { "1SOUND COMPOSER", "KOJI KONDO" };

// Shindou combines sound effects and sound programmer in order to make room for Player voice and Peach voice
const char *credits11[] = { "4SOUND EFFECTS", "SOUND PROGRAMMER", "YOJI INAGAKI", "HIDEAKI SHIMIZU" };
const char *credits12[] = { "23D ANIMATORS", "YOSHIAKI KOIZUMI", "SATORU TAKIZAWA" };
const char *credits13[] = { "1CG DESIGNER", "MASANAO ARIMOTO" };
const char *credits14[] = { "3TECHNICAL SUPPORT", "TAKAO SAWANO", "HIROHITO YOSHIMOTO", "HIROTO YADA" };
const char *credits15[] = { "1TECHNICAL SUPPORT", "SGI. 64PROJECT STAFF" };
const char *credits16[] = { "2PROGRESS MANAGEMENT", "KIMIYOSHI FUKUI", "KEIZO KATO" };

#else // VERSION_US || VERSION_EU
// US and EU combine camera programmer and Player face programmer...
const char *credits05[] = { "4CAMERA PROGRAMMER", "MARIO FACE PROGRAMMER", "TAKUMI KAWAGOE", "GILES GODDARD" };
const char *credits06[] = { "2COURSE DIRECTORS", "YOICHI YAMADA", "YASUHISA YAMAMURA" };
const char *credits07[] = { "2COURSE DESIGNERS", "KENTA USUI", "NAOKI MORI" };
const char *credits08[] = { "3COURSE DESIGNERS", "YOSHIKI HARUHANA", "MAKOTO MIYANAGA", "KATSUHIKO KANNO" };

#ifdef VERSION_US
const char *credits09[] = { "1SOUND COMPOSER", "KOJI KONDO" };
// ...as well as sound effects and sound programmer in order to make room for screen text writer, Player voice, and Peach voice
const char *credits10[] = { "4SOUND EFFECTS", "SOUND PROGRAMMER", "YOJI INAGAKI", "HIDEAKI SHIMIZU" };
const char *credits11[] = { "23-D ANIMATORS", "YOSHIAKI KOIZUMI", "SATORU TAKIZAWA" };
const char *credits12[] = { "1ADDITIONAL GRAPHICS", "MASANAO ARIMOTO" };
const char *credits13[] = { "3TECHNICAL SUPPORT", "TAKAO SAWANO", "HIROHITO YOSHIMOTO", "HIROTO YADA" };
const char *credits14[] = { "1TECHNICAL SUPPORT", "SGI N64 PROJECT STAFF" };
const char *credits15[] = { "2PROGRESS MANAGEMENT", "KIMIYOSHI FUKUI", "KEIZO KATO" };
const char *credits16[] = { "5SCREEN TEXT WRITER", "TRANSLATION", "LESLIE SWAN", "MINA AKINO", "HIRO YAMADA" };
#else // VERSION_EU
// ...as well as sound composer, sound effects, and sound programmer, and...
const char *credits09[] = { "7SOUND COMPOSER", "SOUND EFFECTS", "SOUND PROGRAMMER", "KOJI KONDO", "YOJI INAGAKI", "HIDEAKI SHIMIZU" };
// ...3D animators and additional graphics in order to make room for screen text writer(s), Player voice, and Peach voice
const char *credits10[] = { "63-D ANIMATORS", "ADDITIONAL GRAPHICS", "YOSHIAKI KOIZUMI", "SATORU TAKIZAWA", "MASANAO ARIMOTO" };
const char *credits11[] = { "3TECHNICAL SUPPORT", "TAKAO SAWANO", "HIROHITO YOSHIMOTO", "HIROTO YADA" };
const char *credits12[] = { "1TECHNICAL SUPPORT", "SGI N64 PROJECT STAFF" };
const char *credits13[] = { "2PROGRESS MANAGEMENT", "KIMIYOSHI FUKUI", "KEIZO KATO" };
const char *credits14[] = { "5SCREEN TEXT WRITER", "ENGLISH TRANSLATION", "LESLIE SWAN", "MINA AKINO", "HIRO YAMADA" };
const char *credits15[] = { "4SCREEN TEXT WRITER", "FRENCH TRANSLATION", "JULIEN BARDAKOFF", "KENJI HARAGUCHI" };
const char *credits16[] = { "4SCREEN TEXT WRITER", "GERMAN TRANSLATION", "THOMAS GOERG", "THOMAS SPINDLER" };
#endif

#endif

const char *credits17[] = { "4MARIO VOICE", "PEACH VOICE", "CHARLES MARTINET", "LESLIE SWAN" };

#if defined(VERSION_SH)
const char *credits18[] = { "3SPECIAL THANKS TO", "JYOHO KAIHATUBU", "ALL NINTENDO", "MARIO CLUB STAFF" };
#elif defined(VERSION_US)
const char *credits18[] = { "3SPECIAL THANKS TO", "EAD STAFF", "ALL NINTENDO PERSONNEL", "MARIO CLUB STAFF" };
#else // VERSION_EU
const char *credits18[] = { "3SPECIAL THANKS TO", "EAD STAFF", "ALL NINTENDO PERSONNEL", "SUPER MARIO CLUB STAFF" };
#endif
const char *credits19[] = { "1PRODUCER", "SHIGERU MIYAMOTO" };
const char *credits20[] = { "1EXECUTIVE PRODUCER", "HIROSHI YAMAUCHI" };

// Screen top left - Bottom text
#define CREDITS_POS_ONE 0*16
// Screen top right - Bottom text
#define CREDITS_POS_TWO 1*16
// Screen bottom left - Top text
#define CREDITS_POS_THREE 2*16
// Screen bottom right - Top text
#define CREDITS_POS_FOUR 3*16

// ex-alo change
// Changed credits struct so its more understandable
struct CreditsEntry sCreditsSequence[] = {
    { LEVEL_CASTLE_GROUNDS,
        1, CREDITS_POS_ONE, 1, -128, { 0, 8000, 0 }, NULL },
    // Start Level Credits Sequence
    { LEVEL_BOB,   1, CREDITS_POS_ONE,   1, 117, { 713, 3918, -3889 },    credits01 },
    { LEVEL_WF,    1, CREDITS_POS_FOUR,  2,  46, { 347, 5376, 326 },      credits02 },
    { LEVEL_JRB,   1, CREDITS_POS_TWO,   2,  22, { 3800, -4840, 2727 },   credits03 },
    { LEVEL_CCM,   2, CREDITS_POS_THREE, 2,  25, { -5464, 6656, -6575 },  credits04 },
    { LEVEL_BBH,   1, CREDITS_POS_ONE,   1,  60, { 257, 1922, 2580 },     credits05 },
    { LEVEL_HMC,   1, CREDITS_POS_FOUR,  1,  45, { -6469, 1616, -6054 },  credits06 },
    { LEVEL_THI,   3, CREDITS_POS_TWO,   1, -32, { 508, 1024, 1942 },     credits07 },
    { LEVEL_LLL,   2, CREDITS_POS_THREE, 1, 124, { -73, 82, -1467 },      credits08 },
    { LEVEL_SSL,   1, CREDITS_POS_ONE,   1,  98, { -5906, 1024, -2576 },  credits09 },
    { LEVEL_DDD,   1, CREDITS_POS_FOUR,  2,  47, { -4884, -4607, -272 },  credits10 },
    { LEVEL_SL,    1, CREDITS_POS_TWO,   1, -34, { 1925, 3328, 563 },     credits11 },
    { LEVEL_WDW,   1, CREDITS_POS_THREE, 1, 105, { -537, 1850, 1818 },    credits12 },
    { LEVEL_TTM,   1, CREDITS_POS_ONE,   2, -33, { 2613, 313, 1074 },     credits13 },
    { LEVEL_THI,   1, CREDITS_POS_FOUR,  3,  54, { -2609, 512, 856 },     credits14 },
    { LEVEL_TTC,   1, CREDITS_POS_TWO,   1, -72, { -1304, -71, -967 },    credits15 },
    { LEVEL_RR,    1, CREDITS_POS_THREE, 1,  64, { 1565, 1024, -148 },    credits16 },
    { LEVEL_SA,    1, CREDITS_POS_ONE,   1,  24, { -1050, -1330, -1559 }, credits17 },
    { LEVEL_COTMC, 1, CREDITS_POS_FOUR,  1, -16, { -254, 415, -6045 },    credits18 },
    { LEVEL_DDD,   2, CREDITS_POS_TWO,   1, -64, { 3948, 1185, -104 },    credits19 },
    { LEVEL_CCM,   1, CREDITS_POS_THREE, 1,  31, { 3169, -4607, 5240 },   credits20 },
    // End Level Credits Sequence
    { LEVEL_CASTLE_GROUNDS,
        1, CREDITS_POS_ONE, 1, -128, { 0, 906, -1200 }, NULL },
    { LEVEL_NONE,
        0, CREDITS_POS_ONE, 1,    0, { 0, 0, 0 }, NULL },
};

struct PlayerState gPlayerStates[1];
struct HudDisplay gHudDisplay;
s16 sCurrPlayMode;
s16 sTransitionTimer;
void (*sTransitionUpdate)(s16 *);
struct WarpDest sWarpDest;
s16 sSpecialWarpDest;
s16 sDelayedWarpOp;
s16 sDelayedWarpTimer;
s16 sSourceWarpNodeId;
s32 sDelayedWarpArg;
s8 sTimerRunning;
s8 gNeverEnteredCastle;

struct PlayerState *gPlayerState = &gPlayerStates[0];
s8 sWarpCheckpointActive = FALSE;

u16 level_control_timer(s32 timerOp) {
    switch (timerOp) {
        case TIMER_CONTROL_SHOW:
            gHudDisplay.flags |= HUD_DISPLAY_FLAG_TIMER;
            sTimerRunning = FALSE;
            gHudDisplay.timer = 0;
            break;

        case TIMER_CONTROL_START:
            sTimerRunning = TRUE;
            break;

        case TIMER_CONTROL_STOP:
            sTimerRunning = FALSE;
            break;

        case TIMER_CONTROL_HIDE:
            gHudDisplay.flags &= ~HUD_DISPLAY_FLAG_TIMER;
            sTimerRunning = FALSE;
            gHudDisplay.timer = 0;
            break;
    }

    return gHudDisplay.timer;
}

u32 pressed_pause(void) {
    u32 dialogActive = get_dialog_id() >= 0;
    u32 intangible = (gPlayerState->action & ACT_FLAG_INTANGIBLE) != 0;

    if (!intangible && !dialogActive && !gWarpTransition.isActive && sDelayedWarpOp == WARP_OP_NONE
        && (gPlayer1Controller->buttonPressed & START_BUTTON)) {
        return TRUE;
    }

    return FALSE;
}

void set_play_mode(s16 playMode) {
    sCurrPlayMode = playMode;
}

void warp_special(s32 arg) {
    sCurrPlayMode = PLAY_MODE_CHANGE_LEVEL;
    sSpecialWarpDest = arg;
}

void fade_into_special_warp(u32 arg, u32 color) {
    if (color != 0) {
        color = 0xFF;
    }

    fadeout_music(190);
    play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 0x10, color, color, color);
    level_set_transition(30, NULL);

    warp_special(arg);
}

void stub_level_update_1(void) {
}

void load_level_init_text(u32 arg) {
    s32 gotAchievement;
    u32 dialogID = gCurrentArea->dialog[arg];

    switch (dialogID) {
        case DIALOG_129:
            gotAchievement = save_file_get_flags() & SAVE_FLAG_HAVE_VANISH_CAP;
            break;

        case DIALOG_130:
            gotAchievement = save_file_get_flags() & SAVE_FLAG_HAVE_METAL_CAP;
            break;

        case DIALOG_131:
            gotAchievement = save_file_get_flags() & SAVE_FLAG_HAVE_WING_CAP;
            break;

        case (u8)DIALOG_NONE: // 255, cast value to u8 to match (-1)
            gotAchievement = TRUE;
            break;

        default:
            gotAchievement =
                save_file_get_star_flags(gCurrSaveFileNum - 1, COURSE_NUM_TO_INDEX(gCurrCourseNum));
            break;
    }

    if (!gotAchievement) {
        level_set_transition(-1, NULL);
        create_dialog_box(dialogID);
    }
}

void init_door_warp(struct SpawnInfo *spawnInfo, u32 arg1) {
    if (arg1 & WARP_FLAG_DOOR_FLIP_MARIO) {
        spawnInfo->startAngle[1] += 0x8000;
    }

    spawnInfo->startPos[0] += 300.0f * sins(spawnInfo->startAngle[1]);
    spawnInfo->startPos[2] += 300.0f * coss(spawnInfo->startAngle[1]);
}

void set_player_initial_cap_powerup(struct PlayerState *m) {
    u32 capCourseIndex = gCurrCourseNum - COURSE_CAP_COURSES;

    switch (capCourseIndex) {
        case COURSE_COTMC - COURSE_CAP_COURSES:
            m->flags |= PLAYER_METAL_CAP | MARIO_CAP_ON_HEAD;
            m->capTimer = MC_LEVEL_TIME;
            break;

        case COURSE_TOTWC - COURSE_CAP_COURSES:
            m->flags |= PLAYER_WING_CAP | MARIO_CAP_ON_HEAD;
            m->capTimer = WC_LEVEL_TIME;
            break;

        case COURSE_VCUTM - COURSE_CAP_COURSES:
            m->flags |= PLAYER_VANISH_CAP | MARIO_CAP_ON_HEAD;
            m->capTimer = VC_LEVEL_TIME;
            break;
    }
}

void set_player_initial_action(struct PlayerState *m, u32 spawnType, u32 actionArg) {
    switch (spawnType) {
        case MARIO_SPAWN_DOOR_WARP:
            set_player_action(m, ACT_WARP_DOOR_SPAWN, actionArg);
            break;
        case MARIO_SPAWN_IDLE:
            set_player_action(m, ACT_IDLE, 0);
            break;
        case MARIO_SPAWN_PIPE:
            set_player_action(m, ACT_EMERGE_FROM_PIPE, 0);
            break;
        case MARIO_SPAWN_TELEPORT:
            set_player_action(m, ACT_TELEPORT_FADE_IN, 0);
            break;
        case MARIO_SPAWN_INSTANT_ACTIVE:
            set_player_action(m, ACT_IDLE, 0);
            break;
        case MARIO_SPAWN_AIRBORNE:
            set_player_action(m, ACT_SPAWN_NO_SPIN_AIRBORNE, 0);
            break;
        case MARIO_SPAWN_HARD_AIR_KNOCKBACK:
            set_player_action(m, ACT_HARD_BACKWARD_AIR_KB, 0);
            break;
        case MARIO_SPAWN_SPIN_AIRBORNE_CIRCLE:
            set_player_action(m, ACT_SPAWN_SPIN_AIRBORNE, 0);
            break;
        case MARIO_SPAWN_DEATH:
            set_player_action(m, ACT_FALLING_DEATH_EXIT, 0);
            break;
        case MARIO_SPAWN_SPIN_AIRBORNE:
            set_player_action(m, ACT_SPAWN_SPIN_AIRBORNE, 0);
            break;
        case MARIO_SPAWN_FLYING:
            set_player_action(m, ACT_FLYING, 2);
            break;
        case MARIO_SPAWN_SWIMMING:
            set_player_action(m, ACT_WATER_IDLE, 1);
            break;
        case MARIO_SPAWN_PAINTING_STAR_COLLECT:
            set_player_action(m, ACT_EXIT_AIRBORNE, 0);
            break;
        case MARIO_SPAWN_PAINTING_DEATH:
            set_player_action(m, ACT_DEATH_EXIT, 0);
            break;
        case MARIO_SPAWN_AIRBORNE_STAR_COLLECT:
            set_player_action(m, ACT_FALLING_EXIT_AIRBORNE, 0);
            break;
        case MARIO_SPAWN_AIRBORNE_DEATH:
            set_player_action(m, ACT_UNUSED_DEATH_EXIT, 0);
            break;
        case MARIO_SPAWN_LAUNCH_STAR_COLLECT:
            set_player_action(m, ACT_SPECIAL_EXIT_AIRBORNE, 0);
            break;
        case MARIO_SPAWN_LAUNCH_DEATH:
            set_player_action(m, ACT_SPECIAL_DEATH_EXIT, 0);
            break;
    }

    set_player_initial_cap_powerup(m);
}

// ex-alo change
// Function went through a revision to remove course and warp specific code changes
// Comments were added to clarify what's changed
void init_player_after_warp(void) {
    struct ObjectWarpNode *spawnNode = area_get_warp_node(sWarpDest.nodeId);
    u32 playerSpawnType = get_player_spawn_type(spawnNode->object);

    if (gPlayerState->action != ACT_UNINITIALIZED) {
        gPlayerSpawnInfos[0].startPos[0] = (s16) spawnNode->object->oPosX;
        gPlayerSpawnInfos[0].startPos[1] = (s16) spawnNode->object->oPosY;
        gPlayerSpawnInfos[0].startPos[2] = (s16) spawnNode->object->oPosZ;

        gPlayerSpawnInfos[0].startAngle[0] = 0;
        gPlayerSpawnInfos[0].startAngle[1] = spawnNode->object->oMoveAngleYaw;
        gPlayerSpawnInfos[0].startAngle[2] = 0;

        if (playerSpawnType == MARIO_SPAWN_DOOR_WARP) {
            init_door_warp(&gPlayerSpawnInfos[0], sWarpDest.arg);
        }

        if (sWarpDest.type == WARP_TYPE_CHANGE_LEVEL || sWarpDest.type == WARP_TYPE_CHANGE_AREA) {
            gPlayerSpawnInfos[0].areaIndex = sWarpDest.areaIdx;
            load_player_area();
        }

        // Don't reset Player on the same warp area, preserves cap powerup like in SM64DS
        if (sWarpDest.type != WARP_TYPE_SAME_AREA) {
            init_player();
        } else {
            vec3s_copy(gPlayerState->faceAngle, gPlayerSpawnInfo->startAngle);
            vec3s_to_vec3f(gPlayerState->pos, gPlayerSpawnInfo->startPos);
        }

        set_player_initial_action(gPlayerState, playerSpawnType, sWarpDest.arg);

        gPlayerState->interactObj = spawnNode->object;
        gPlayerState->usedObj = spawnNode->object;
    }

    reset_camera(gCurrentArea->camera);

#if BUGFIX_SAME_AREA_WARP_MUSIC
    // Setting a variable here before it gets set to not warping
    u32 warpSameArea = (sWarpDest.type == WARP_TYPE_SAME_AREA);
#endif

    // Needed to play transitions properly
    sWarpDest.type = WARP_TYPE_NOT_WARPING;
    sDelayedWarpOp = WARP_OP_NONE;

    switch (playerSpawnType) {
        case MARIO_SPAWN_PIPE:
            play_transition(WARP_TRANSITION_FADE_FROM_STAR, 0x10, 0x00, 0x00, 0x00);
            break;
        case MARIO_SPAWN_DOOR_WARP:
            play_transition(WARP_TRANSITION_FADE_FROM_CIRCLE, 0x10, 0x00, 0x00, 0x00);
            break;
        case MARIO_SPAWN_TELEPORT:
            play_transition(WARP_TRANSITION_FADE_FROM_COLOR, 0x14, 0xFF, 0xFF, 0xFF);
            break;
        case MARIO_SPAWN_SPIN_AIRBORNE:
            play_transition(WARP_TRANSITION_FADE_FROM_COLOR, 0x1A, 0xFF, 0xFF, 0xFF);
            break;
        case MARIO_SPAWN_SPIN_AIRBORNE_CIRCLE:
            play_transition(WARP_TRANSITION_FADE_FROM_CIRCLE, 0x10, 0x00, 0x00, 0x00);
            break;
        case MARIO_SPAWN_FADE_FROM_BLACK:
            play_transition(WARP_TRANSITION_FADE_FROM_COLOR, 0x10, 0x00, 0x00, 0x00);
            break;
        default:
            play_transition(WARP_TRANSITION_FADE_FROM_STAR, 0x10, 0x00, 0x00, 0x00);
            break;
    }

    if (gCurrDemoInput == NULL) {
        // Don't try to override music when warping in the same level area
        // Vanilla: This used to have an override to play the Slide racing music
        // but with BUGFIX_SAME_AREA_WARP_MUSIC it's no longer necessary
#if BUGFIX_SAME_AREA_WARP_MUSIC
        if (!warpSameArea)
#endif
        {
            set_background_music(gCurrentArea->musicParam, gCurrentArea->musicParam2, 0);

            if (gPlayerState->flags & PLAYER_METAL_CAP) {
                play_cap_music(SEQUENCE_ARGS(4, SEQ_EVENT_METAL_CAP));
            }

            if (gPlayerState->flags & (PLAYER_VANISH_CAP | PLAYER_WING_CAP)) {
                play_cap_music(SEQUENCE_ARGS(4, SEQ_EVENT_POWERUP));
            }
        }

        // Properly play the castle warp sound exiting on any exit course warp
        // Vanilla: Previous checks used the same node and level ids for exit course
        // but with a warp flag it's no longer necessary
        if (sWarpDest.arg & WARP_FLAG_EXIT_COURSE) {
            play_sound(SOUND_MENU_MARIO_CASTLE_WARP, gGlobalSoundSource);
        }

        // Play castle warp sound on special warp instead of fixed warp ids
        // Vanilla: Previous checks used specific node and level ids but they share
        // the same source warp node and course id, so the conditions are simplified
        if (sSourceWarpNodeId == WARP_NODE_WARP_FLOOR && gCurrCourseNum == COURSE_NONE) {
            play_sound(SOUND_MENU_MARIO_CASTLE_WARP, gGlobalSoundSource);
        }
    }
}

// used for warps inside one level
void warp_area(void) {
    if (sWarpDest.type != WARP_TYPE_NOT_WARPING) {
        if (sWarpDest.type == WARP_TYPE_CHANGE_AREA) {
            level_control_timer(TIMER_CONTROL_HIDE);
            unload_player_area();
            load_area(sWarpDest.areaIdx);
        }

        init_player_after_warp();
    }
}

// used for warps between levels
void warp_level(void) {
    gCurrLevelNum = sWarpDest.levelNum;

    level_control_timer(TIMER_CONTROL_HIDE);

    load_area(sWarpDest.areaIdx);
    init_player_after_warp();
}

void warp_credits(void) {
    s32 playerAction = ACT_UNINITIALIZED;

    switch (sWarpDest.nodeId) {
        case WARP_NODE_CREDITS_START:
            playerAction = ACT_END_PEACH_CUTSCENE;
            break;

        case WARP_NODE_CREDITS_NEXT:
            playerAction = ACT_CREDITS_CUTSCENE;
            break;

        case WARP_NODE_CREDITS_END:
            playerAction = ACT_END_WAVING_CUTSCENE;
            break;
    }

    gCurrLevelNum = sWarpDest.levelNum;

    load_area(sWarpDest.areaIdx);

    vec3s_set(gPlayerSpawnInfos[0].startPos, gCurrCreditsEntry->playerPos[0],
              gCurrCreditsEntry->playerPos[1], gCurrCreditsEntry->playerPos[2]);

    vec3s_set(gPlayerSpawnInfos[0].startAngle, 0, 0x100 * gCurrCreditsEntry->playerAngle, 0);

    gPlayerSpawnInfos[0].areaIndex = sWarpDest.areaIdx;

    load_player_area();
    init_player();

    set_player_action(gPlayerState, playerAction, 0);

    reset_camera(gCurrentArea->camera);

    sWarpDest.type = WARP_TYPE_NOT_WARPING;
    sDelayedWarpOp = WARP_OP_NONE;

    play_transition(WARP_TRANSITION_FADE_FROM_COLOR, 0x14, 0x00, 0x00, 0x00);

    if (gCurrCreditsEntry == NULL || gCurrCreditsEntry == sCreditsSequence) {
        set_background_music(gCurrentArea->musicParam, gCurrentArea->musicParam2, 0);
    }
}

void check_instant_warp(void) {
    s16 cameraAngle;
    struct Surface *floor;

    if (gCurrLevelNum == LEVEL_CASTLE
        && save_file_get_total_star_count(gCurrSaveFileNum - 1, COURSE_MIN - 1, COURSE_MAX - 1) >= 70) {
        return;
    }

    if ((floor = gPlayerState->floor) != NULL) {
        s32 index = floor->type - SURFACE_INSTANT_WARP_1B;
        if (index >= INSTANT_WARP_INDEX_START && index < INSTANT_WARP_INDEX_STOP
            && gCurrentArea->instantWarps != NULL) {
            struct InstantWarp *warp = &gCurrentArea->instantWarps[index];

            if (warp->id != 0) {
                gPlayerState->pos[0] += warp->displacement[0];
                gPlayerState->pos[1] += warp->displacement[1];
                gPlayerState->pos[2] += warp->displacement[2];

                gPlayerState->playerObj->oPosX = gPlayerState->pos[0];
                gPlayerState->playerObj->oPosY = gPlayerState->pos[1];
                gPlayerState->playerObj->oPosZ = gPlayerState->pos[2];

            #if QOL_FIX_INSTANT_WARP_OFFSET
                gPlayerObject->header.gfx.pos[0] = gPlayerState->pos[0];
                gPlayerObject->header.gfx.pos[1] = gPlayerState->pos[1];
                gPlayerObject->header.gfx.pos[2] = gPlayerState->pos[2];
            #endif

                cameraAngle = gPlayerState->area->camera->yaw;

                change_area(warp->area);
                gPlayerState->area = gCurrentArea;

                warp_camera(warp->displacement[0], warp->displacement[1], warp->displacement[2]);

                gPlayerState->area->camera->yaw = cameraAngle;
            }
        }
    }
}

s16 music_unchanged_through_warp(s16 arg) {
    struct ObjectWarpNode *warpNode = area_get_warp_node(arg);
    s16 levelNum = warpNode->node.destLevel & 0x7F;
    s16 destArea = warpNode->node.destArea;
    s16 unchanged = TRUE;
    s16 currBgMusic = get_current_background_music();
#if BUGFIX_SAME_AREA_WARP_MUSIC
    // Racing music and cap powerup music have priority 4, so on warps music is unchanged
    s16 prioMusic = (currBgMusic & 0xFF00) >> 8;

    // level and area conditions were added with the prioMusic so it doesn't override it
    if (prioMusic < 4 || levelNum != gCurrLevelNum || destArea != gCurrAreaIndex)
#endif
    {
        u16 destParam1 = gAreas[destArea].musicParam;
        u16 destParam2 = gAreas[destArea].musicParam2;

        unchanged = levelNum == gCurrLevelNum && destParam1 == gCurrentArea->musicParam
               && destParam2 == gCurrentArea->musicParam2;
        if (currBgMusic != destParam2) {
            unchanged = FALSE;
        }
    }

    return unchanged;
}

/**
 * Set the current warp type and destination level/area/node.
 */
void initiate_warp(s16 destLevel, s16 destArea, s16 destWarpNode, s32 warpFlags) {
    if (destWarpNode >= WARP_NODE_CREDITS_MIN) {
        sWarpDest.type = WARP_TYPE_CHANGE_LEVEL;
    } else if (warpFlags & WARP_FLAG_EXIT_COURSE) { // fixes exit course on same exit course
        sWarpDest.type = WARP_TYPE_CHANGE_LEVEL;
    } else if (destLevel != gCurrLevelNum) {
        sWarpDest.type = WARP_TYPE_CHANGE_LEVEL;
    } else if (destArea != gCurrentArea->index) {
        sWarpDest.type = WARP_TYPE_CHANGE_AREA;
    } else {
        sWarpDest.type = WARP_TYPE_SAME_AREA;
    }

    sWarpDest.levelNum = destLevel;
    sWarpDest.areaIdx = destArea;
    sWarpDest.nodeId = destWarpNode;
    sWarpDest.arg = warpFlags;
}

// From Surface 0xD3 to 0xFC
#define PAINTING_WARP_INDEX_START 0x00 // Value greater than or equal to Surface 0xD3
#define PAINTING_WARP_INDEX_FA 0x2A    // THI Huge Painting index left
#define PAINTING_WARP_INDEX_END 0x2D   // Value less than Surface 0xFD

/**
 * Check if Player is above and close to a painting warp floor, and return the
 * corresponding warp node.
 */
struct WarpNode *get_painting_warp_node(void) {
    struct WarpNode *warpNode = NULL;
    s32 paintingIndex = gPlayerState->floor->type - SURFACE_PAINTING_WARP_D3;

    if (paintingIndex >= PAINTING_WARP_INDEX_START && paintingIndex < PAINTING_WARP_INDEX_END) {
        if (paintingIndex < PAINTING_WARP_INDEX_FA
            || gPlayerState->pos[1] - gPlayerState->floorHeight < 80.0f) {
            warpNode = &gCurrentArea->paintingWarpNodes[paintingIndex];
        }
    }

    return warpNode;
}

/**
 * Check is Player has entered a painting, and if so, initiate a warp.
 */
void initiate_painting_warp(void) {
    if (gCurrentArea->paintingWarpNodes != NULL && gPlayerState->floor != NULL) {
        struct WarpNode warpNode;
        struct WarpNode *pWarpNode = get_painting_warp_node();

        if (pWarpNode != NULL) {
            if (gPlayerState->action & ACT_FLAG_INTANGIBLE) {
                play_painting_eject_sound();
            } else if (pWarpNode->id != 0) {
                warpNode = *pWarpNode;

                if (!(warpNode.destLevel & 0x80)) {
                    sWarpCheckpointActive = check_warp_checkpoint(&warpNode);
                }

                initiate_warp(warpNode.destLevel & 0x7F, warpNode.destArea, warpNode.destNode, WARP_FLAGS_NONE);
                check_if_should_set_warp_checkpoint(&warpNode);

                play_transition_after_delay(WARP_TRANSITION_FADE_INTO_COLOR, 30, 255, 255, 255, 45);
                level_set_transition(74, basic_update);

                set_player_action(gPlayerState, ACT_DISAPPEARED, 0);

                gPlayerState->playerObj->header.gfx.node.flags &= ~GRAPH_RENDER_ACTIVE;

                play_sound(SOUND_MENU_STAR_SOUND, gGlobalSoundSource);
                fadeout_music(398);
#ifdef RUMBLE_FEEDBACK
                queue_rumble_data(80, 70);
                queue_rumble_decay(1);
#endif
            }
        }
    }
}

/**
 * If there is not already a delayed warp, schedule one. The source node is
 * based on the warp operation and sometimes Player's used object.
 * Return the time left until the delayed warp is initiated.
 */
s16 level_trigger_warp(struct PlayerState *m, s32 warpOp) {
    s32 fadeMusic = TRUE;

    if (sDelayedWarpOp == WARP_OP_NONE) {
        m->invincTimer = -1;
        sDelayedWarpArg = WARP_FLAGS_NONE;
        sDelayedWarpOp = warpOp;

        switch (warpOp) {
            case WARP_OP_DEMO_NEXT:
            case WARP_OP_DEMO_END: sDelayedWarpTimer = 20; // Must be one line to match on -O2
                sSourceWarpNodeId = WARP_NODE_SUCCESS;
                gSavedCourseNum = COURSE_NONE;
                fadeMusic = FALSE;
                play_transition(WARP_TRANSITION_FADE_INTO_STAR, 0x14, 0x00, 0x00, 0x00);
                break;

            case WARP_OP_CREDITS_END:
                sDelayedWarpTimer = 60;
                sSourceWarpNodeId = WARP_NODE_SUCCESS;
                fadeMusic = FALSE;
                gSavedCourseNum = COURSE_NONE;
                play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 0x3C, 0x00, 0x00, 0x00);
                break;

            case WARP_OP_STAR_EXIT:
                sDelayedWarpTimer = 32;
                sSourceWarpNodeId = WARP_NODE_SUCCESS;
                gSavedCourseNum = COURSE_NONE;
                play_transition(WARP_TRANSITION_FADE_INTO_MARIO, 0x20, 0x00, 0x00, 0x00);
                break;

            case WARP_OP_DEATH:
                #if !DISABLE_LIVES
                if (m->numLives == 0) {
                    sDelayedWarpOp = WARP_OP_GAME_OVER;
                }
                #endif
                sDelayedWarpTimer = 48;
                sSourceWarpNodeId = WARP_NODE_DEATH;
                play_transition(WARP_TRANSITION_FADE_INTO_BOWSER, 0x30, 0x00, 0x00, 0x00);
                play_sound(SOUND_MENU_BOWSER_LAUGH, gGlobalSoundSource);
                break;

            case WARP_OP_WARP_FLOOR:
                sSourceWarpNodeId = WARP_NODE_WARP_FLOOR;
                if (area_get_warp_node(sSourceWarpNodeId) == NULL) {
                    #if !DISABLE_LIVES
                    if (m->numLives == 0) {
                        sDelayedWarpOp = WARP_OP_GAME_OVER;
                    } else {
                        sSourceWarpNodeId = WARP_NODE_DEATH;
                    }
                    #else
                    sSourceWarpNodeId = WARP_NODE_DEATH;
                    #endif
                }
                sDelayedWarpTimer = 20;
                play_transition(WARP_TRANSITION_FADE_INTO_CIRCLE, 0x14, 0x00, 0x00, 0x00);
                break;

            case WARP_OP_LOOK_UP: // enter TotWC
                sDelayedWarpTimer = 30;
                sSourceWarpNodeId = WARP_NODE_TOTWC;
                play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 0x1E, 0xFF, 0xFF, 0xFF);
                play_sound(SOUND_MENU_STAR_SOUND, gGlobalSoundSource);
                break;

            case WARP_OP_SPIN_SHRINK: // enter BBH
                sDelayedWarpTimer = 30;
                sSourceWarpNodeId = (m->usedObj->oBhvParams & 0x00FF0000) >> 16;
                play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 0x1E, 0xFF, 0xFF, 0xFF);
                break;

            case WARP_OP_TELEPORT:
                sDelayedWarpTimer = 20;
                sSourceWarpNodeId = (m->usedObj->oBhvParams & 0x00FF0000) >> 16;
                fadeMusic = !music_unchanged_through_warp(sSourceWarpNodeId);
                play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 0x14, 0xFF, 0xFF, 0xFF);
                break;

            case WARP_OP_WARP_DOOR:
                sDelayedWarpTimer = 20;
                sDelayedWarpArg = m->actionArg;
                sSourceWarpNodeId = (m->usedObj->oBhvParams & 0x00FF0000) >> 16;
                fadeMusic = !music_unchanged_through_warp(sSourceWarpNodeId);
                play_transition(WARP_TRANSITION_FADE_INTO_CIRCLE, 0x14, 0x00, 0x00, 0x00);
                break;

            case WARP_OP_WARP_OBJECT:
                sDelayedWarpTimer = 20;
                sSourceWarpNodeId = (m->usedObj->oBhvParams & 0x00FF0000) >> 16;
                fadeMusic = !music_unchanged_through_warp(sSourceWarpNodeId);
                play_transition(WARP_TRANSITION_FADE_INTO_STAR, 0x14, 0x00, 0x00, 0x00);
                break;

            case WARP_OP_CREDITS_START:
                sDelayedWarpTimer = 30;
                play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 0x1E, 0x00, 0x00, 0x00);
                break;

            case WARP_OP_CREDITS_NEXT:
                if (gCurrCreditsEntry == &sCreditsSequence[0]) {
                    sDelayedWarpTimer = 60;
                    play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 0x3C, 0x00, 0x00, 0x00);
                } else {
                    sDelayedWarpTimer = 20;
                    play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 0x14, 0x00, 0x00, 0x00);
                }
                fadeMusic = FALSE;
                break;
        }

        if (fadeMusic && gCurrDemoInput == NULL) {
            fadeout_music((3 * sDelayedWarpTimer / 2) * 8 - 2);
        }
    }

    return sDelayedWarpTimer;
}

/**
 * If a delayed warp is ready, initiate it.
 */
void initiate_delayed_warp(void) {
    struct ObjectWarpNode *warpNode;
    s32 destWarpNode;

    if (sDelayedWarpOp != WARP_OP_NONE && --sDelayedWarpTimer == 0) {
        reset_dialog_render_state();

        if (gDebugLevelSelect && (sDelayedWarpOp & WARP_OP_TRIGGERS_LEVEL_SELECT)) {
            warp_special(-9);
        } else if (gCurrDemoInput != NULL) {
            if (sDelayedWarpOp == WARP_OP_DEMO_END) {
                warp_special(-8);
            } else {
                warp_special(-2);
            }
        } else {
            switch (sDelayedWarpOp) {
                case WARP_OP_GAME_OVER:
                    save_file_reload();
                    warp_special(-3);
                    break;

                case WARP_OP_CREDITS_END:
                    warp_special(-1);
                    sound_banks_enable(SEQ_PLAYER_SFX,
                                       SOUND_BANKS_ALL & ~SOUND_BANKS_DISABLED_AFTER_CREDITS);
                    break;

                case WARP_OP_DEMO_NEXT:
                    warp_special(-2);
                    break;

                case WARP_OP_CREDITS_START:
                    gCurrCreditsEntry = &sCreditsSequence[0];
                    initiate_warp(gCurrCreditsEntry->levelNum, gCurrCreditsEntry->areaIndex,
                                  WARP_NODE_CREDITS_START, WARP_FLAGS_NONE);
                    break;

                case WARP_OP_CREDITS_NEXT:
                    sound_banks_disable(SEQ_PLAYER_SFX, SOUND_BANKS_ALL);

                    gCurrCreditsEntry++;
                    gCurrActNum = gCurrCreditsEntry->actNum;

                    if ((gCurrCreditsEntry + 1)->levelNum == LEVEL_NONE) {
                        destWarpNode = WARP_NODE_CREDITS_END;
                    } else {
                        destWarpNode = WARP_NODE_CREDITS_NEXT;
                    }

                    initiate_warp(gCurrCreditsEntry->levelNum, gCurrCreditsEntry->areaIndex,
                                  destWarpNode, WARP_FLAGS_NONE);
                    break;

                default:
                    warpNode = area_get_warp_node(sSourceWarpNodeId);

                    initiate_warp(warpNode->node.destLevel & 0x7F, warpNode->node.destArea,
                                  warpNode->node.destNode, sDelayedWarpArg);

                    check_if_should_set_warp_checkpoint(&warpNode->node);
                    if (sWarpDest.type != WARP_TYPE_CHANGE_LEVEL) {
                        level_set_transition(2, NULL);
                    }
                    break;
            }
        }
    }
}

void update_hud_values(void) {
    if (gCurrCreditsEntry == NULL) {
        s16 numHealthWedges = gPlayerState->health > 0 ? gPlayerState->health >> 8 : 0;

        if (gCurrCourseNum >= COURSE_MIN) {
            gHudDisplay.flags |= HUD_DISPLAY_FLAG_COIN_COUNT;
        } else {
            gHudDisplay.flags &= ~HUD_DISPLAY_FLAG_COIN_COUNT;
        }

        if (gHudDisplay.coins < gPlayerState->numCoins) {
            if (gGlobalTimer & 1) {
                u32 coinSound;
                if (gPlayerState->action & (ACT_FLAG_SWIMMING | ACT_FLAG_METAL_WATER)) {
                    coinSound = SOUND_GENERAL_COIN_WATER;
                } else {
                    coinSound = SOUND_GENERAL_COIN;
                }

                gHudDisplay.coins++;
                play_sound(coinSound, gPlayerState->playerObj->header.gfx.cameraToObject);
            }
        }

        if (gPlayerState->numLives > 100) {
            gPlayerState->numLives = 100;
        }

#if BUGFIX_MAX_LIVES
        if (gPlayerState->numCoins > 999) {
            gPlayerState->numCoins = 999;
        }

        if (gHudDisplay.coins > 999) {
            gHudDisplay.coins = 999;
        }
#else
        if (gPlayerState->numCoins > 999) {
            gPlayerState->numLives = (s8) 999; //! Wrong variable
        }
#endif

        gHudDisplay.stars = gPlayerState->numStars;
        gHudDisplay.lives = gPlayerState->numLives;
        gHudDisplay.keys = gPlayerState->numKeys;

        if (numHealthWedges > gHudDisplay.wedges) {
            play_sound(SOUND_MENU_POWER_METER, gGlobalSoundSource);
        }
        gHudDisplay.wedges = numHealthWedges;

        if (gPlayerState->hurtCounter > 0) {
            gHudDisplay.flags |= HUD_DISPLAY_FLAG_EMPHASIZE_POWER;
        } else {
            gHudDisplay.flags &= ~HUD_DISPLAY_FLAG_EMPHASIZE_POWER;
        }
    }
}

/**
 * Update objects, HUD, and camera. This update function excludes things like
 * endless staircase, warps, pausing, etc. This is used when entering a painting,
 * presumably to allow painting and camera updating while avoiding triggering the
 * warp twice.
 */
void basic_update(UNUSED s16 *arg) {
    area_update_objects();
    update_hud_values();

    if (gCurrentArea != NULL) {
        update_camera(gCurrentArea->camera);
    }
}

s32 play_mode_normal(void) {
    if (gCurrDemoInput != NULL) {
        print_intro_text();
        if (gPlayer1Controller->buttonPressed & END_DEMO) {
            level_trigger_warp(gPlayerState,
                               gCurrLevelNum == LEVEL_PSS ? WARP_OP_DEMO_END : WARP_OP_DEMO_NEXT);
        } else if (!gWarpTransition.isActive && sDelayedWarpOp == WARP_OP_NONE
                   && (gPlayer1Controller->buttonPressed & START_BUTTON)) {
            level_trigger_warp(gPlayerState, WARP_OP_DEMO_NEXT);
        }
    }

    warp_area();
    check_instant_warp();

    // 30 frames * 60 seconds (1 minute) * 10 minutes (max) - 1 (to set limit to 9:59)
    if (sTimerRunning && gHudDisplay.timer < 10*60*30-1) {
        gHudDisplay.timer++;
    }

    area_update_objects();
    update_hud_values();

    if (gCurrentArea != NULL) {
        update_camera(gCurrentArea->camera);
    }

    initiate_painting_warp();
    initiate_delayed_warp();

    // If either initiate_painting_warp or initiate_delayed_warp initiated a
    // warp, change play mode accordingly.
    if (sCurrPlayMode == PLAY_MODE_NORMAL) {
        if (sWarpDest.type == WARP_TYPE_CHANGE_LEVEL) {
            set_play_mode(PLAY_MODE_CHANGE_LEVEL);
        } else if (sTransitionTimer != 0) {
            set_play_mode(PLAY_MODE_CHANGE_AREA);
        } else if (pressed_pause()) {
            lower_background_noise(1);
#ifdef RUMBLE_FEEDBACK
            cancel_rumble();
#endif
#if CAMERA_MOVE_WHEN_PAUSE
            gCameraMovementFlags |= CAM_MOVE_PAUSE_SCREEN;
#endif
            set_play_mode(PLAY_MODE_PAUSED);
        }
    }

    return 0;
}

s32 play_mode_paused(void) {
    if (gMenuOptSelectIndex == MENU_OPT_NONE) {
        set_menu_mode(MENU_MODE_RENDER_PAUSE_SCREEN);
    } else if (gMenuOptSelectIndex == MENU_OPT_DEFAULT) {
        raise_background_noise(1);
        gCameraMovementFlags &= ~CAM_MOVE_PAUSE_SCREEN;
        set_play_mode(PLAY_MODE_NORMAL);
    } else { // MENU_OPT_EXIT_COURSE
        if (gDebugLevelSelect) {
            fade_into_special_warp(-9, 1);
        } else {
            // Set exit course warp an unique warp flag
            initiate_warp(EXIT_COURSE, WARP_FLAG_EXIT_COURSE);
            fade_into_special_warp(0, 0);
            gSavedCourseNum = COURSE_NONE;
        }

        gCameraMovementFlags &= ~CAM_MOVE_PAUSE_SCREEN;
    }

    return 0;
}

/**
 * Debug mode that lets you frame advance by pressing D-pad down. Unfortunately
 * it uses the pause camera, making it basically unusable in most levels.
 */
s32 play_mode_frame_advance(void) {
    if (gPlayer1Controller->buttonPressed & D_JPAD) {
        gCameraMovementFlags &= ~CAM_MOVE_PAUSE_SCREEN;
        play_mode_normal();
    } else if (gPlayer1Controller->buttonPressed & START_BUTTON) {
        gCameraMovementFlags &= ~CAM_MOVE_PAUSE_SCREEN;
        raise_background_noise(1);
        set_play_mode(PLAY_MODE_NORMAL);
    } else {
        gCameraMovementFlags |= CAM_MOVE_PAUSE_SCREEN;
    }

    return 0;
}

/**
 * Set the transition, which is a period of time after the warp is initiated
 * but before it actually occurs. If updateFunction is not NULL, it will be
 * called each frame during the transition.
 */
void level_set_transition(s16 length, void (*updateFunction)(s16 *)) {
    sTransitionTimer = length;
    sTransitionUpdate = updateFunction;
}

/**
 * Play the transition and then return to normal play mode.
 */
s32 play_mode_change_area(void) {
    // ex-alo change
    // Change function to have similar change_level defines
    if (sTransitionUpdate != NULL) {
        sTransitionUpdate(&sTransitionTimer);
    }

    if (--sTransitionTimer == -1) {
        if (gCurrentArea != NULL) {
            update_camera(gCurrentArea->camera);
        }

        sTransitionTimer = 0;
        sTransitionUpdate = NULL;
        set_play_mode(PLAY_MODE_NORMAL);
    }

    return 0;
}

/**
 * Play the transition and then return to normal play mode.
 */
s32 play_mode_change_level(void) {
    if (sTransitionUpdate != NULL) {
        sTransitionUpdate(&sTransitionTimer);
    }

    if (--sTransitionTimer == -1) {
        gHudDisplay.flags = HUD_DISPLAY_NONE;
        sTransitionTimer = 0;
        sTransitionUpdate = NULL;

        if (sWarpDest.type != WARP_TYPE_NOT_WARPING) {
            return sWarpDest.levelNum;
        } else {
            return sSpecialWarpDest;
        }
    }

    return 0;
}

/**
 * Unused play mode. Doesn't call transition update and doesn't reset transition at the end.
 */
#if !QOL_FIX_UNUSED_PLAY_MODE
UNUSED
#endif
static s32 play_mode_unused(void) {
    if (--sTransitionTimer == -1) {
        gHudDisplay.flags = HUD_DISPLAY_NONE;

        if (sWarpDest.type != WARP_TYPE_NOT_WARPING) {
            return sWarpDest.levelNum;
        } else {
            return sSpecialWarpDest;
        }
    }

    return 0;
}

// ex-alo change
// Checks for peach intro skip
u8 should_intro_be_skipped(void) {
    return save_file_exists(gCurrSaveFileNum - 1) || gDebugLevelSelect || (gGlobalGameSkips & GAME_SKIP_INTRO_SCENE)
#ifndef TARGET_N64
    || configSkipIntro == TRUE
#endif
    ;
}

// ex-alo change
// Merge misc reset values into one function
void reset_misc_level_object_values(void) {
    gCCMEnteredSlide = 0;
    reset_red_coins_collected();
#if QOL_FIX_RESET_PSS_SLIDE_STARTED
    gPSSSlideStarted = FALSE;
#endif
}

s32 update_level(void) {
    s32 changeLevel;

    switch (sCurrPlayMode) {
        case PLAY_MODE_NORMAL:
            changeLevel = play_mode_normal(); scroll_textures();
            break;
        case PLAY_MODE_PAUSED:
            changeLevel = play_mode_paused();
            break;
        case PLAY_MODE_CHANGE_AREA:
            changeLevel = play_mode_change_area();
            break;
        case PLAY_MODE_CHANGE_LEVEL:
            changeLevel = play_mode_change_level();
            break;
        case PLAY_MODE_FRAME_ADVANCE:
            changeLevel = play_mode_frame_advance();
            break;
#if QOL_FIX_UNUSED_PLAY_MODE
        default:
            changeLevel = play_mode_unused();
            break;
#endif
    }

    if (changeLevel) {
        reset_volume();
        enable_background_sound();
    }

    return changeLevel;
}

s32 init_level(void) {
    s32 fadeFromColor = FALSE;

    set_play_mode(PLAY_MODE_NORMAL);

#ifdef TARGET_N3DS
    gDPSetIod(gDisplayListHead++, iodNormal);
#endif

    // ex-alo change
    // Merge misc reset values into one function
    reset_misc_level_object_values();

    sDelayedWarpOp = WARP_OP_NONE;
    sTransitionTimer = 0;
    sSpecialWarpDest = 0;

#ifdef COMMAND_LINE_OPTIONS
    if (gCLIOpts.LevelNumOverride) {
        gGlobalGameSkips &= ~GAME_SKIP_GENERAL;
        gCLIOpts.LevelNumOverride = 0;
        if (gCLIOpts.LevelActOverride) {
            gGlobalGameSkips &= ~GAME_SKIP_STAR_SELECT;
            gCLIOpts.LevelActOverride = 0;
        }
    }
#endif

    if (gCurrCreditsEntry == NULL) {
        gHudDisplay.flags = HUD_DISPLAY_DEFAULT;
    } else {
        gHudDisplay.flags = HUD_DISPLAY_NONE;
    }

    sTimerRunning = FALSE;

    if (sWarpDest.type != WARP_TYPE_NOT_WARPING) {
        if (sWarpDest.nodeId >= WARP_NODE_CREDITS_MIN) {
            warp_credits();
        } else {
            warp_level();
        }
    } else {
        if (gPlayerSpawnInfos[0].areaIndex >= 0) {
            load_player_area();
            init_player();
        }

        if (gCurrentArea != NULL) {
            reset_camera(gCurrentArea->camera);

            if (gCurrDemoInput != NULL) {
                set_player_action(gPlayerState, ACT_IDLE, 0);
            } else if (!gDebugLevelSelect) {
                if (gPlayerState->action != ACT_UNINITIALIZED) {
                    // ex-alo change
                    // Checks for peach intro skip
                    if (should_intro_be_skipped()) {
                        set_player_action(gPlayerState, ACT_IDLE, 0);
                    } else {
                        set_player_action(gPlayerState, ACT_INTRO_CUTSCENE, 0);
                        fadeFromColor = TRUE;
                    }
                }
            }
        }


        if (fadeFromColor) {
            play_transition(WARP_TRANSITION_FADE_FROM_COLOR, 0x5A, 0xFF, 0xFF, 0xFF);
        } else {
            play_transition(WARP_TRANSITION_FADE_FROM_STAR, 0x10, 0xFF, 0xFF, 0xFF);
        }

        if (gCurrDemoInput == NULL) {
            set_background_music(gCurrentArea->musicParam, gCurrentArea->musicParam2, 0);
        }
    }
#ifdef RUMBLE_FEEDBACK
    if (gCurrDemoInput == NULL) {
        cancel_rumble();
    }
#endif
    if (gPlayerState->action == ACT_INTRO_CUTSCENE) {
        sound_banks_disable(SEQ_PLAYER_SFX, SOUND_BANKS_DISABLED_DURING_INTRO_CUTSCENE);
    }

    return 1;
}

/**
 * Initialize the current level if initOrUpdate is 0, or update the level if it is 1.
 */
s32 lvl_init_or_update(s16 initOrUpdate, UNUSED s32 unused) {
    s32 result = 0;

    switch (initOrUpdate) {
        case 0:
            result = init_level();
            break;
        case 1:
            result = update_level();
            break;
    }

    return result;
}

s32 lvl_init_from_save_file(UNUSED s16 arg0, s32 levelNum) {
#ifdef VERSION_EU
    s16 language = eu_get_language();
    switch (language) {
        case LANGUAGE_ENGLISH:
            load_segment_decompress(0x19, _translation_en_mio0SegmentRomStart,
                                    _translation_en_mio0SegmentRomEnd);
            break;
        case LANGUAGE_FRENCH:
            load_segment_decompress(0x19, _translation_fr_mio0SegmentRomStart,
                                    _translation_fr_mio0SegmentRomEnd);
            break;
        case LANGUAGE_GERMAN:
            load_segment_decompress(0x19, _translation_de_mio0SegmentRomStart,
                                    _translation_de_mio0SegmentRomEnd);
            break;
    }
#endif
    sWarpDest.type = WARP_TYPE_NOT_WARPING;
    sDelayedWarpOp = WARP_OP_NONE;
    // ex-alo change
    // Checks for peach intro skip
    gNeverEnteredCastle = !should_intro_be_skipped();

    gCurrLevelNum = levelNum;
    gCurrCourseNum = COURSE_NONE;
    gSavedCourseNum = COURSE_NONE;
    gCurrCreditsEntry = NULL;
    gSpecialTripleJump = FALSE;

    init_player_from_save_file();
    disable_warp_checkpoint();
    save_file_move_cap_to_default_location();
    select_player_cam_mode();

#ifdef COMMAND_LINE_OPTIONS
    if (gCLIOpts.LevelNumOverride) {
        levelNum = gCLIOpts.LevelNumOverride;
        if (gCLIOpts.LevelActOverride) {
            gCurrActNum = gCLIOpts.LevelActOverride;
        }
    }
#endif

    return levelNum;
}

s32 lvl_set_current_level(UNUSED s16 arg0, s32 levelNum) {
    s32 warpCheckpointActive = sWarpCheckpointActive;

    sWarpCheckpointActive = FALSE;
    gCurrLevelNum = levelNum;
    gCurrCourseNum = gLevelToCourseNumTable[levelNum - 1];
	if (gCurrLevelNum == LEVEL_CASTLE_COURTYARD) return 0;
	if (gCurrLevelNum == LEVEL_BITDW) return 0;
	if (gCurrLevelNum == LEVEL_CASTLE_GROUNDS) return 0;

    if (gCurrDemoInput != NULL || gCurrCreditsEntry != NULL || gCurrCourseNum == COURSE_NONE) {
        return 0;
    }

    if (gCurrLevelNum != LEVEL_BOWSER_1 && gCurrLevelNum != LEVEL_BOWSER_2
        && gCurrLevelNum != LEVEL_BOWSER_3) {
        gPlayerState->numCoins = 0;
        gHudDisplay.coins = 0;
        gCurrCourseStarFlags =
            save_file_get_star_flags(gCurrSaveFileNum - 1, COURSE_NUM_TO_INDEX(gCurrCourseNum));
    }

    if (gSavedCourseNum != gCurrCourseNum) {
        gSavedCourseNum = gCurrCourseNum;
        nop_change_course();
        disable_warp_checkpoint();
    }

    if (gCurrCourseNum > COURSE_STAGES_MAX || warpCheckpointActive) {
        return 0;
    }

    if (gDebugLevelSelect) {
        return 0;
    }

    return 1;
}

/**
 * Play the "thank you so much for to playing my game" sound.
 */
s32 lvl_play_the_end_screen_sound(UNUSED s16 arg0, UNUSED s32 arg1) {
    play_sound(SOUND_MENU_THANK_YOU_PLAYING_MY_GAME, gGlobalSoundSource);
    return 1;
}

s32 lvl_end_screen_start_button_reset(UNUSED s16 arg0, UNUSED s32 arg1) {
    if (gPlayer1Controller->buttonPressed & START_BUTTON) {
        return 1;
    }
    return 0;
}
