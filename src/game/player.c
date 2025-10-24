#include <PR/ultratypes.h>

#include "sm64.h"
#include "area.h"
#include "audio/external.h"
#include "behavior_actions.h"
#include "behavior_data.h"
#include "camera.h"
#include "engine/graph_node.h"
#include "engine/math_util.h"
#include "engine/surface_collision.h"
#include "game_init.h"
#include "interaction.h"
#include "level_table.h"
#include "level_update.h"
#include "main.h"
#include "characters.h"
#include "player.h"
#include "player_actions_airborne.h"
#include "player_actions_automatic.h"
#include "player_actions_cutscene.h"
#include "player_actions_moving.h"
#include "player_actions_object.h"
#include "player_actions_stationary.h"
#include "player_actions_submerged.h"
#include "player_misc.h"
#include "player_step.h"
#include "memory.h"
#include "object_fields.h"
#include "object_helpers.h"
#include "object_list_processor.h"
#include "print.h"
#include "rumble_init.h"
#include "save_file.h"
#include "sound_init.h"
#include "pc/configfile.h"
#include "extras/cheats.h"

#ifdef EXT_DEBUG_MENU
#include "extras/debug_menu.h"
#endif

u32 unused80339F10;
u8 unused80339F1C[20];

int curChar = 0;

#define YOSHI   0
#define MARIO   1
#define LUIGI   2
#define WARIO   3
#define WALUIGI 4

/**************************************************
 *                    ANIMATIONS                  *
 **************************************************/

/**
 * Checks if Player's animation has reached its end point.
 */
s32 is_anim_at_end(struct PlayerState *m) {
    struct Object *o = m->playerObj;

    return (o->header.gfx.animInfo.animFrame + 1) == o->header.gfx.animInfo.curAnim->loopEnd;
}

/**
 * Checks if Player's animation has surpassed 2 frames before its end point.
 */
s32 is_anim_past_end(struct PlayerState *m) {
    struct Object *o = m->playerObj;

    return o->header.gfx.animInfo.animFrame >= (o->header.gfx.animInfo.curAnim->loopEnd - 2);
}

/**
 * Sets the player's animation without any acceleration, running at its default rate.
 */
s16 set_player_animation(struct PlayerState *m, s32 targetAnimID) {
    struct Object *o = m->playerObj;
    struct Animation *targetAnim = m->animList->bufTarget;

    if (curChar == 0 && (targetAnimID != YOSHI_ANIM_RUN) && (targetAnimID != YOSHI_ANIM_JUMP) && (targetAnimID != YOSHI_ANIM_JUMP_LAND) && (targetAnimID != YOSHI_ANIM_IDLE) && (targetAnimID != YOSHI_ANIM_EAT)) {
        targetAnimID = YOSHI_ANIM_TPOSE;
    } else {
        targetAnimID = targetAnimID;
    }

    if (load_patchable_table(m->animList, targetAnimID)) {
        targetAnim->values = (void *) VIRTUAL_TO_PHYSICAL((u8 *) targetAnim + (uintptr_t) targetAnim->values);
        targetAnim->index = (void *) VIRTUAL_TO_PHYSICAL((u8 *) targetAnim + (uintptr_t) targetAnim->index);
    }

    if (o->header.gfx.animInfo.animID != targetAnimID) {
        o->header.gfx.animInfo.animID = targetAnimID;
        o->header.gfx.animInfo.curAnim = targetAnim;
        o->header.gfx.animInfo.animAccel = 0;
        o->header.gfx.animInfo.animYTrans = m->unkB0;

        if (targetAnim->flags & ANIM_FLAG_2) {
            o->header.gfx.animInfo.animFrame = targetAnim->startFrame;
        } else {
            if (targetAnim->flags & ANIM_FLAG_BACKWARD) {
                o->header.gfx.animInfo.animFrame = targetAnim->startFrame + 1;
            } else {
                o->header.gfx.animInfo.animFrame = targetAnim->startFrame - 1;
            }
        }
    }

    return o->header.gfx.animInfo.animFrame;
}

/**
 * Sets Player's animation where the animation is sped up or
 * slowed down via acceleration.
 */
s16 set_player_anim_with_accel(struct PlayerState *m, s32 targetAnimID, s32 accel) {
    struct Object *o = m->playerObj;
    struct Animation *targetAnim = m->animList->bufTarget;

    if (curChar == 0 && (targetAnimID != YOSHI_ANIM_RUN) && (targetAnimID != YOSHI_ANIM_JUMP) && (targetAnimID != YOSHI_ANIM_JUMP_LAND) && (targetAnimID != YOSHI_ANIM_IDLE) && (targetAnimID != YOSHI_ANIM_EAT)) {
        targetAnimID = YOSHI_ANIM_TPOSE;
    } else {
        targetAnimID = targetAnimID;
    }

    if (load_patchable_table(m->animList, targetAnimID)) {
        targetAnim->values = (void *) VIRTUAL_TO_PHYSICAL((u8 *) targetAnim + (uintptr_t) targetAnim->values);
        targetAnim->index = (void *) VIRTUAL_TO_PHYSICAL((u8 *) targetAnim + (uintptr_t) targetAnim->index);
    }

    if (o->header.gfx.animInfo.animID != targetAnimID) {
        o->header.gfx.animInfo.animID = targetAnimID;
        o->header.gfx.animInfo.curAnim = targetAnim;
        o->header.gfx.animInfo.animYTrans = m->unkB0;

        if (targetAnim->flags & ANIM_FLAG_2) {
            o->header.gfx.animInfo.animFrameAccelAssist = (targetAnim->startFrame << 0x10);
        } else {
            if (targetAnim->flags & ANIM_FLAG_BACKWARD) {
                o->header.gfx.animInfo.animFrameAccelAssist = (targetAnim->startFrame << 0x10) + accel;
            } else {
                o->header.gfx.animInfo.animFrameAccelAssist = (targetAnim->startFrame << 0x10) - accel;
            }
        }

        o->header.gfx.animInfo.animFrame = (o->header.gfx.animInfo.animFrameAccelAssist >> 0x10);
    }

    o->header.gfx.animInfo.animAccel = accel;

    return o->header.gfx.animInfo.animFrame;
}

/**
 * Sets the animation to a specific "next" frame from the frame given.
 */
void set_anim_to_frame(struct PlayerState *m, s16 animFrame) {
    struct AnimInfo *animInfo = &m->playerObj->header.gfx.animInfo;
    struct Animation *curAnim = animInfo->curAnim;

    if (animInfo->animAccel != 0) {
        if (curAnim->flags & ANIM_FLAG_BACKWARD) {
            animInfo->animFrameAccelAssist = (animFrame << 0x10) + animInfo->animAccel;
        } else {
            animInfo->animFrameAccelAssist = (animFrame << 0x10) - animInfo->animAccel;
        }
    } else {
        if (curAnim->flags & ANIM_FLAG_BACKWARD) {
            animInfo->animFrame = animFrame + 1;
        } else {
            animInfo->animFrame = animFrame - 1;
        }
    }
}

s32 is_anim_past_frame(struct PlayerState *m, s16 animFrame) {
    s32 isPastFrame;
    s32 acceleratedFrame = animFrame << 0x10;
    struct AnimInfo *animInfo = &m->playerObj->header.gfx.animInfo;
    struct Animation *curAnim = animInfo->curAnim;

    if (animInfo->animAccel != 0) {
        if (curAnim->flags & ANIM_FLAG_BACKWARD) {
            isPastFrame =
                (animInfo->animFrameAccelAssist > acceleratedFrame)
                && (acceleratedFrame >= (animInfo->animFrameAccelAssist - animInfo->animAccel));
        } else {
            isPastFrame =
                (animInfo->animFrameAccelAssist < acceleratedFrame)
                && (acceleratedFrame <= (animInfo->animFrameAccelAssist + animInfo->animAccel));
        }
    } else {
        if (curAnim->flags & ANIM_FLAG_BACKWARD) {
            isPastFrame = (animInfo->animFrame == (animFrame + 1));
        } else {
            isPastFrame = ((animInfo->animFrame + 1) == animFrame);
        }
    }

    return isPastFrame;
}

/**
 * Rotates the animation's translation into the global coordinate system
 * and returns the animation's flags.
 */
s16 find_player_anim_flags_and_translation(struct Object *obj, s32 yaw, Vec3s translation) {
    f32 dx;
    f32 dz;

    struct Animation *curAnim = (void *) obj->header.gfx.animInfo.curAnim;
    s16 animFrame = geo_update_animation_frame(&obj->header.gfx.animInfo, NULL);
    u16 *animIndex = segmented_to_virtual((void *) curAnim->index);
    s16 *animValues = segmented_to_virtual((void *) curAnim->values);

    f32 s = (f32) sins(yaw);
    f32 c = (f32) coss(yaw);

    dx = *(animValues + (retrieve_animation_index(animFrame, &animIndex))) / 4.0f;
    translation[1] = *(animValues + (retrieve_animation_index(animFrame, &animIndex))) / 4.0f;
    dz = *(animValues + (retrieve_animation_index(animFrame, &animIndex))) / 4.0f;

    translation[0] = (dx * c) + (dz * s);
    translation[2] = (-dx * s) + (dz * c);

    return curAnim->flags;
}

/**
 * Updates Player's position from his animation's translation.
 */
void update_player_pos_for_anim(struct PlayerState *m) {
    Vec3s translation;
    s16 flags;

    flags = find_player_anim_flags_and_translation(m->playerObj, m->faceAngle[1], translation);

    if (flags & (ANIM_FLAG_HOR_TRANS | ANIM_FLAG_6)) {
        m->pos[0] += (f32) translation[0];
        m->pos[2] += (f32) translation[2];
    }

    if (flags & (ANIM_FLAG_VERT_TRANS | ANIM_FLAG_6)) {
        m->pos[1] += (f32) translation[1];
    }
}

/**
 * Finds the vertical translation from Player's animation.
 */
s16 return_player_anim_y_translation(struct PlayerState *m) {
    Vec3s translation;
    find_player_anim_flags_and_translation(m->playerObj, 0, translation);

    return translation[1];
}

/**************************************************
 *                      AUDIO                     *
 **************************************************/

/**
 * Plays a sound if if Player doesn't have the flag being checked.
 */
void play_sound_if_no_flag(struct PlayerState *m, u32 soundBits, u32 flags) {
    if (!(m->flags & flags)) {
        play_sound(soundBits, m->playerObj->header.gfx.cameraToObject);
        m->flags |= flags;
    }
}

int yahOrWah;
int yahooOrYippe;

/**
 * Plays a jump sound if one has not been played since the last action change.
 */
void play_player_jump_sound(struct PlayerState *m) {
    if (!(m->flags & PLAYER_MARIO_SOUND_PLAYED)) {
        if (m->action == ACT_TRIPLE_JUMP) {
            if (yahOrWah == 0) {
                play_sound(SOUND_MARIO_YAHOO, m->playerObj->header.gfx.cameraToObject);
                yahooOrYippe++;
            } else {
                play_sound((SOUND_MARIO_YAHOO_WAHA_YIPPEE), m->playerObj->header.gfx.cameraToObject);
                yahooOrYippe--;
            }
        } else if ((m->action == ACT_JUMP) || (m->action == ACT_DIVE)) {
            if (yahOrWah == 0) {
                play_sound(SOUND_MARIO_YAH, m->playerObj->header.gfx.cameraToObject);
                yahOrWah++;
            } else {
                play_sound(SOUND_MARIO_WAH, m->playerObj->header.gfx.cameraToObject);
                yahOrWah--;
            }
        } else {
            play_sound(SOUND_MARIO_YAH + ((gAudioRandom % 3) << 16),
                       m->playerObj->header.gfx.cameraToObject);
        }
        m->flags |= PLAYER_MARIO_SOUND_PLAYED;
    }
}

/**
 * Adjusts the volume/pitch of sounds from Player's speed.
 */
void adjust_sound_for_speed(struct PlayerState *m) {
    s32 absForwardVel = (m->forwardVel > 0.0f) ? m->forwardVel : -m->forwardVel;
    set_sound_moving_speed(SOUND_BANK_MOVING, (absForwardVel > 100) ? 100 : absForwardVel);
}

/**
 * Spawns particles if the step sound says to, then either plays a step sound or relevant other sound.
 */
void play_sound_and_spawn_particles(struct PlayerState *m, u32 soundBits, u32 waveParticleType) {
    if (m->terrainSoundAddend == (SOUND_TERRAIN_WATER << 16)) {
        if (waveParticleType != 0) {
            m->particleFlags |= PARTICLE_SHALLOW_WATER_SPLASH;
        } else {
            m->particleFlags |= PARTICLE_SHALLOW_WATER_WAVE;
        }
    } else {
        if (m->terrainSoundAddend == (SOUND_TERRAIN_SAND << 16)) {
            m->particleFlags |= PARTICLE_DIRT;
        } else if (m->terrainSoundAddend == (SOUND_TERRAIN_SNOW << 16)) {
            m->particleFlags |= PARTICLE_SNOW;
        }
    }

    if ((m->flags & PLAYER_METAL_CAP) || soundBits == SOUND_ACTION_UNSTUCK_FROM_GROUND
        || soundBits == SOUND_MARIO_PUNCH_HOO) {
        play_sound(soundBits, m->playerObj->header.gfx.cameraToObject);
    } else {
        play_sound(m->terrainSoundAddend + soundBits, m->playerObj->header.gfx.cameraToObject);
    }
}

/**
 * Plays an environmental sound if one has not been played since the last action change.
 */
void play_player_action_sound(struct PlayerState *m, u32 soundBits, u32 waveParticleType) {
    if (!(m->flags & PLAYER_ACTION_SOUND_PLAYED)) {
        play_sound_and_spawn_particles(m, soundBits, waveParticleType);
        m->flags |= PLAYER_ACTION_SOUND_PLAYED;
    }
}

/**
 * Plays a landing sound, accounting for metal cap.
 */
void play_player_landing_sound(struct PlayerState *m, u32 soundBits) {
    play_sound_and_spawn_particles(
        m, (m->flags & PLAYER_METAL_CAP) ? SOUND_ACTION_METAL_LANDING : soundBits, 1);
}

/**
 * Plays a landing sound, accounting for metal cap. Unlike play_player_landing_sound,
 * this function uses play_player_action_sound, making sure the sound is only
 * played once per action.
 */
void play_player_landing_sound_once(struct PlayerState *m, u32 soundBits) {
    play_player_action_sound(
        m, (m->flags & PLAYER_METAL_CAP) ? SOUND_ACTION_METAL_LANDING : soundBits, 1);
}

/**
 * Plays a heavy landing (ground pound, etc.) sound, accounting for metal cap.
 */
void play_player_heavy_landing_sound(struct PlayerState *m, u32 soundBits) {
    play_sound_and_spawn_particles(
        m, (m->flags & PLAYER_METAL_CAP) ? SOUND_ACTION_METAL_HEAVY_LANDING : soundBits, 1);
}

/**
 * Plays a heavy landing (ground pound, etc.) sound, accounting for metal cap.
 * Unlike play_player_heavy_landing_sound, this function uses play_player_action_sound,
 * making sure the sound is only played once per action.
 */
void play_player_heavy_landing_sound_once(struct PlayerState *m, u32 soundBits) {
    play_player_action_sound(
        m, (m->flags & PLAYER_METAL_CAP) ? SOUND_ACTION_METAL_HEAVY_LANDING : soundBits, 1);
}

/**
 * Plays action and Player sounds relevant to what was passed into the function.
 */
void play_player_sound(struct PlayerState *m, s32 actionSound, s32 playerSound) {
    if (actionSound == SOUND_ACTION_TERRAIN_JUMP) {
        play_player_action_sound(m, (m->flags & PLAYER_METAL_CAP) ? (s32) SOUND_ACTION_METAL_JUMP
                                                                : (s32) SOUND_ACTION_TERRAIN_JUMP, 1);
    } else {
        play_sound_if_no_flag(m, actionSound, PLAYER_ACTION_SOUND_PLAYED);
    }

    if (playerSound == 0) {
        play_player_jump_sound(m);
    }

    if (playerSound != -1) {
        play_sound_if_no_flag(m, playerSound, PLAYER_MARIO_SOUND_PLAYED);
    }
}

/**************************************************
 *                     ACTIONS                    *
 **************************************************/

/**
 * Sets Player's other velocities from his forward speed.
 */
void player_set_forward_vel(struct PlayerState *m, f32 forwardVel) {
    m->forwardVel = forwardVel;

    m->slideVelX = sins(m->faceAngle[1]) * m->forwardVel;
    m->slideVelZ = coss(m->faceAngle[1]) * m->forwardVel;

    m->vel[0] = (f32) m->slideVelX;
    m->vel[2] = (f32) m->slideVelZ;
}

/**
 * Returns the slipperiness class of the player's floor.
 */
s32 player_get_floor_class(struct PlayerState *m) {
    s32 floorClass;
    if (Cheats.EnableCheats && Cheats.WalkOn.Slope) return SURFACE_CLASS_NOT_SLIPPERY;

    // The slide terrain type defaults to slide slipperiness.
    // This doesn't matter too much since normally the slide terrain
    // is checked for anyways.
    if ((m->area->terrainType & TERRAIN_MASK) == TERRAIN_SLIDE) {
        floorClass = SURFACE_CLASS_VERY_SLIPPERY;
    } else {
        floorClass = SURFACE_CLASS_DEFAULT;
    }

    if (m->floor != NULL) {
        switch (m->floor->type) {
            case SURFACE_NOT_SLIPPERY:
            case SURFACE_HARD_NOT_SLIPPERY:
            case SURFACE_SWITCH:
                floorClass = SURFACE_CLASS_NOT_SLIPPERY;
                break;

            case SURFACE_SLIPPERY:
            case SURFACE_NOISE_SLIPPERY:
            case SURFACE_HARD_SLIPPERY:
            case SURFACE_NO_CAM_COL_SLIPPERY:
                floorClass = SURFACE_CLASS_SLIPPERY;
                break;

            case SURFACE_VERY_SLIPPERY:
            case SURFACE_ICE:
            case SURFACE_HARD_VERY_SLIPPERY:
            case SURFACE_NOISE_VERY_SLIPPERY_73:
            case SURFACE_NOISE_VERY_SLIPPERY_74:
            case SURFACE_NOISE_VERY_SLIPPERY:
            case SURFACE_NO_CAM_COL_VERY_SLIPPERY:
                floorClass = SURFACE_CLASS_VERY_SLIPPERY;
                break;
        }
    }

    // Crawling allows the player to not slide on certain steeper surfaces.
    if (m->action == ACT_CRAWLING && m->floor->normal.y > 0.5f && floorClass == SURFACE_CLASS_DEFAULT) {
        floorClass = SURFACE_CLASS_NOT_SLIPPERY;
    }

    return floorClass;
}

// clang-format off
s8 sTerrainSounds[7][6] = {
    // default,              hard,                 slippery,
    // very slippery,        noisy default,        noisy slippery
    { SOUND_TERRAIN_DEFAULT, SOUND_TERRAIN_STONE,  SOUND_TERRAIN_GRASS,
      SOUND_TERRAIN_GRASS,   SOUND_TERRAIN_GRASS,  SOUND_TERRAIN_DEFAULT }, // TERRAIN_GRASS
    { SOUND_TERRAIN_STONE,   SOUND_TERRAIN_STONE,  SOUND_TERRAIN_STONE,
      SOUND_TERRAIN_STONE,   SOUND_TERRAIN_GRASS,  SOUND_TERRAIN_GRASS }, // TERRAIN_STONE
    { SOUND_TERRAIN_SNOW,    SOUND_TERRAIN_ICE,    SOUND_TERRAIN_SNOW,
      SOUND_TERRAIN_ICE,     SOUND_TERRAIN_STONE,  SOUND_TERRAIN_STONE }, // TERRAIN_SNOW
    { SOUND_TERRAIN_SAND,    SOUND_TERRAIN_STONE,  SOUND_TERRAIN_SAND,
      SOUND_TERRAIN_SAND,    SOUND_TERRAIN_STONE,  SOUND_TERRAIN_STONE }, // TERRAIN_SAND
    { SOUND_TERRAIN_SPOOKY,  SOUND_TERRAIN_SPOOKY, SOUND_TERRAIN_SPOOKY,
      SOUND_TERRAIN_SPOOKY,  SOUND_TERRAIN_STONE,  SOUND_TERRAIN_STONE }, // TERRAIN_SPOOKY
    { SOUND_TERRAIN_DEFAULT, SOUND_TERRAIN_STONE,  SOUND_TERRAIN_GRASS,
      SOUND_TERRAIN_ICE,     SOUND_TERRAIN_STONE,  SOUND_TERRAIN_ICE }, // TERRAIN_WATER
    { SOUND_TERRAIN_STONE,   SOUND_TERRAIN_STONE,  SOUND_TERRAIN_STONE,
      SOUND_TERRAIN_STONE,   SOUND_TERRAIN_ICE,    SOUND_TERRAIN_ICE }, // TERRAIN_SLIDE
};
// clang-format on

/**
 * Computes a value that should be added to terrain sounds before playing them.
 * This depends on surfaces and terrain.
 */
u32 player_get_terrain_sound_addend(struct PlayerState *m) {
    s16 floorSoundType;
    s16 terrainType = m->area->terrainType & TERRAIN_MASK;
    s32 ret = SOUND_TERRAIN_DEFAULT << 16;
    s32 floorType;

    if (m->floor != NULL) {
        floorType = m->floor->type;

        if ((gCurrLevelNum != LEVEL_LLL) && (m->floorHeight < (m->waterLevel - 10))) {
            // Water terrain sound, excluding LLL since it uses water in the volcano.
            ret = SOUND_TERRAIN_WATER << 16;
        } else if (SURFACE_IS_QUICKSAND(floorType)) {
            ret = SOUND_TERRAIN_SAND << 16;
        } else {
            switch (floorType) {
                default:
                    floorSoundType = 0;
                    break;

                case SURFACE_NOT_SLIPPERY:
                case SURFACE_HARD:
                case SURFACE_HARD_NOT_SLIPPERY:
                case SURFACE_SWITCH:
                    floorSoundType = 1;
                    break;

                case SURFACE_SLIPPERY:
                case SURFACE_HARD_SLIPPERY:
                case SURFACE_NO_CAM_COL_SLIPPERY:
                    floorSoundType = 2;
                    break;

                case SURFACE_VERY_SLIPPERY:
                case SURFACE_ICE:
                case SURFACE_HARD_VERY_SLIPPERY:
                case SURFACE_NOISE_VERY_SLIPPERY_73:
                case SURFACE_NOISE_VERY_SLIPPERY_74:
                case SURFACE_NOISE_VERY_SLIPPERY:
                case SURFACE_NO_CAM_COL_VERY_SLIPPERY:
                    floorSoundType = 3;
                    break;

                case SURFACE_NOISE_DEFAULT:
                    floorSoundType = 4;
                    break;

                case SURFACE_NOISE_SLIPPERY:
                    floorSoundType = 5;
                    break;
            }

            ret = sTerrainSounds[terrainType][floorSoundType] << 16;
        }
    }

    return ret;
}

/**
 * Collides with walls and returns the most recent wall.
 */
struct Surface *resolve_and_return_wall_collisions(Vec3f pos, f32 offset, f32 radius) {
    struct WallCollisionData collisionData;
    struct Surface *wall = NULL;
#if BETTER_RESOLVE_WALL_COLLISION
    int i = 0;
#endif

    collisionData.x = pos[0];
    collisionData.y = pos[1];
    collisionData.z = pos[2];
    collisionData.radius = radius;
    collisionData.offsetY = offset;

    if (find_wall_collisions(&collisionData)) {
#if BETTER_RESOLVE_WALL_COLLISION
        for (i = 0; i < collisionData.numWalls; i++) {
            wall = collisionData.walls[i];
        }
#else
        wall = collisionData.walls[collisionData.numWalls - 1];
#endif
    }

    pos[0] = collisionData.x;
    pos[1] = collisionData.y;
    pos[2] = collisionData.z;

#if BETTER_RESOLVE_WALL_COLLISION
    // Returns the wall the actor is closest to facing
#else
    // This only returns the most recent wall and can also return NULL
    // there are no wall collisions.
#endif
    return wall;
}

#if BETTER_RESOLVE_WALL_COLLISION
void resolve_and_return_wall_collisions_data(Vec3f pos, f32 offset, f32 radius, struct WallCollisionData *collisionData) {
    collisionData->x = pos[0];
    collisionData->y = pos[1];
    collisionData->z = pos[2];
    collisionData->radius = radius;
    collisionData->offsetY = offset;

	find_wall_collisions(collisionData);

    pos[0] = collisionData->x;
    pos[1] = collisionData->y;
    pos[2] = collisionData->z;
}
#endif

/**
 * Finds the ceiling from a vec3f horizontally and a height 
 * (with 80 vertical buffer, 3 with exposed ceilings fix).
 */
f32 vec3f_find_ceil(Vec3f pos, f32 height, struct Surface **ceil) {
#if EXPOSED_CEILINGS_FIX
    return find_ceil(pos[0], MAX(height, pos[1]) + 3.0f, pos[2], ceil);
#else
    return find_ceil(pos[0], height + 80.0f, pos[2], ceil);
#endif
}

/**
 * Determines if Player is facing "downhill."
 */
s32 player_facing_downhill(struct PlayerState *m, s32 turnYaw) {
    s16 faceAngleYaw = m->faceAngle[1];

    // This is never used in practice, as turnYaw is
    // always passed as zero.
    if (turnYaw && m->forwardVel < 0.0f) {
        faceAngleYaw += 0x8000;
    }

    faceAngleYaw = m->floorAngle - faceAngleYaw;

    return (-0x4000 < faceAngleYaw) && (faceAngleYaw < 0x4000);
}

/**
 * Determines if a surface is slippery based on the surface class.
 */
u32 player_floor_is_slippery(struct PlayerState *m) {
    if (Cheats.EnableCheats && Cheats.WalkOn.Slope) return FALSE;

    f32 normY;

    if ((m->area->terrainType & TERRAIN_MASK) == TERRAIN_SLIDE
        && m->floor->normal.y < 0.9998477f //~cos(1 deg)
    ) {
        return TRUE;
    }

    switch (player_get_floor_class(m)) {
        case SURFACE_VERY_SLIPPERY:
            normY = 0.9848077f; //~cos(10 deg)
            break;

        case SURFACE_SLIPPERY:
            normY = 0.9396926f; //~cos(20 deg)
            break;

        default:
            normY = 0.7880108f; //~cos(38 deg)
            break;

        case SURFACE_NOT_SLIPPERY:
            normY = 0.0f;
            break;
    }

    return m->floor->normal.y <= normY;
}

/**
 * Determines if a surface is a slope based on the surface class.
 */
s32 player_floor_is_slope(struct PlayerState *m) {
    f32 normY;

    if ((m->area->terrainType & TERRAIN_MASK) == TERRAIN_SLIDE
        && m->floor->normal.y < 0.9998477f) { // ~cos(1 deg)
        return TRUE;
    }

    switch (player_get_floor_class(m)) {
        case SURFACE_VERY_SLIPPERY:
            normY = 0.9961947f; // ~cos(5 deg)
            break;

        case SURFACE_SLIPPERY:
            normY = 0.9848077f; // ~cos(10 deg)
            break;

        default:
            normY = 0.9659258f; // ~cos(15 deg)
            break;

        case SURFACE_NOT_SLIPPERY:
            normY = 0.9396926f; // ~cos(20 deg)
            break;
    }

    return m->floor->normal.y <= normY;
}

/**
 * Determines if a surface is steep based on the surface class.
 */
s32 player_floor_is_steep(struct PlayerState *m) {
    f32 normY;
#if FIX_JUMP_KICK_NOT_SLIPPERY
    if (m->floor->type == SURFACE_NOT_SLIPPERY) {
        return FALSE;
    }
#endif
    // Interestingly, this function does not check for the
    // slide terrain type. This means that steep behavior persists for
    // non-slippery and slippery surfaces.
    // This does not matter in vanilla game practice.
    if (!player_facing_downhill(m, FALSE)) {
        switch (player_get_floor_class(m)) {
            case SURFACE_VERY_SLIPPERY:
                normY = 0.9659258f; // ~cos(15 deg)
                break;

            case SURFACE_SLIPPERY:
                normY = 0.9396926f; // ~cos(20 deg)
                break;

            default:
                normY = 0.8660254f; // ~cos(30 deg)
                break;
#if !FIX_JUMP_KICK_NOT_SLIPPERY
            case SURFACE_NOT_SLIPPERY:
                normY = 0.8660254f; // ~cos(30 deg)
                break;
#endif
        }

        return (m->floor->normal.y <= normY);
    }

    return FALSE;
}

/**
 * Finds the floor height relative from Player given polar displacement.
 */
f32 find_floor_height_relative_polar(struct PlayerState *m, s16 angleFromPlayer, f32 distFromPlayer) {
    struct Surface *floor;
    f32 floorY;

    f32 y = sins(m->faceAngle[1] + angleFromPlayer) * distFromPlayer;
    f32 x = coss(m->faceAngle[1] + angleFromPlayer) * distFromPlayer;

    floorY = find_floor(m->pos[0] + y, m->pos[1] + 100.0f, m->pos[2] + x, &floor);

    return floorY;
}

#if FIX_FLOOR_SLOPE_OOB
#define CHECK(set)    set
#else
#define CHECK(set)
#endif

/**
 * Returns the slope of the floor based off points around Player.
 */
s16 find_floor_slope(struct PlayerState *m, s16 yawOffset) {
    struct Surface *floor = m->floor;
    f32 forwardFloorY, backwardFloorY;
    f32 forwardYDelta, backwardYDelta;
    s16 result;

    f32 x = sins(m->faceAngle[1] + yawOffset) * 5.0f;
    f32 z = coss(m->faceAngle[1] + yawOffset) * 5.0f;

#if FAST_FLOOR_ALIGN
    if (absf(m->forwardVel) > FAST_FLOOR_ALIGN_VALUE) {
        forwardFloorY  = get_surface_height_at_pos((m->pos[0] + x), (m->pos[2] + z), floor);
        backwardFloorY = get_surface_height_at_pos((m->pos[0] - x), (m->pos[2] - z), floor);
    } else
#endif
    {
        forwardFloorY = find_floor(m->pos[0] + x, m->pos[1] + 100.0f, m->pos[2] + z, &floor);
        CHECK(if (floor == NULL) forwardFloorY = m->floorHeight); // handle OOB slopes
        backwardFloorY = find_floor(m->pos[0] - x, m->pos[1] + 100.0f, m->pos[2] - z, &floor);
        CHECK(if (floor == NULL) backwardFloorY = m->floorHeight); // handle OOB slopes
    }

    //! If the player is near OOB, these floorY's can sometimes be -11000.
    //  This will cause these to be off and give improper slopes.
    //  FIX_FLOOR_SLOPE_OOB fixes it
    forwardYDelta = forwardFloorY - m->pos[1];
    backwardYDelta = m->pos[1] - backwardFloorY;

    if (forwardYDelta * forwardYDelta < backwardYDelta * backwardYDelta) {
        result = atan2s(5.0f, forwardYDelta);
    } else {
        result = atan2s(5.0f, backwardYDelta);
    }

    return result;
}

#undef CHECK

/**
 * Adjusts Player's camera and sound based on his action status.
 */
void update_player_sound_and_camera(struct PlayerState *m) {
    u32 action = m->action;
    s32 camPreset = m->area->camera->mode;

    if (action == ACT_FIRST_PERSON) {
        raise_background_noise(2);
        gCameraMovementFlags &= ~CAM_MOVE_C_UP_MODE;
        // Go back to the last camera mode
        set_camera_mode(m->area->camera, -1, 1);
    } else if (action == ACT_SLEEPING) {
        raise_background_noise(2);
    }

    if (!(action & (ACT_FLAG_SWIMMING | ACT_FLAG_METAL_WATER))) {
        if (camPreset == CAMERA_MODE_BEHIND_MARIO || camPreset == CAMERA_MODE_WATER_SURFACE) {
            set_camera_mode(m->area->camera, m->area->camera->defMode, 1);
        }
    }
}

/**
 * Transitions Player to a steep jump action.
 */
void set_steep_jump_action(struct PlayerState *m) {
    m->playerObj->oPlayerSteepJumpYaw = m->faceAngle[1];

    if (m->forwardVel > 0.0f) {
        //! ((s16)0x8000) has undefined behavior. Therefore, this downcast has
        // undefined behavior if m->floorAngle >= 0.
        s16 angleTemp = m->floorAngle + 0x8000;
        s16 faceAngleTemp = m->faceAngle[1] - angleTemp;

        f32 y = sins(faceAngleTemp) * m->forwardVel;
        f32 x = coss(faceAngleTemp) * m->forwardVel * 0.75f;

        m->forwardVel = sqrtf(y * y + x * x);
        m->faceAngle[1] = atan2s(x, y) + angleTemp;
    }

    drop_and_set_player_action(m, ACT_STEEP_JUMP, 0);
}

/**
 * Sets Player's vertical speed from his forward speed.
 */
static void set_player_y_vel_based_on_fspeed(struct PlayerState *m, f32 initialVelY, f32 multiplier) {
    // get_additive_y_vel_for_jumps is always 0 and a stubbed function.
    // It was likely trampoline related based on code location.
    m->vel[1] = initialVelY + get_additive_y_vel_for_jumps() + m->forwardVel * multiplier;

    if (m->squishTimer != 0 || m->quicksandDepth > 1.0f) {
        m->vel[1] *= 0.5f;
    }
}

/**
 * Transitions for a variety of airborne actions.
 */
static u32 set_player_action_airborne(struct PlayerState *m, u32 action, u32 actionArg) {
    f32 forwardVel;

    if ((m->squishTimer != 0 || m->quicksandDepth >= 1.0f)
        && (action == ACT_DOUBLE_JUMP || action == ACT_TWIRLING)) {
        action = ACT_JUMP;
    }

    switch (action) {
        case ACT_DOUBLE_JUMP:
            set_player_y_vel_based_on_fspeed(m, 52.0f, 0.25f);
            m->forwardVel *= 0.8f;
            break;

        case ACT_BACKFLIP:
            m->playerObj->header.gfx.animInfo.animID = -1;
            m->forwardVel = -16.0f;
            set_player_y_vel_based_on_fspeed(m, 62.0f, 0.0f);
            break;

        case ACT_TRIPLE_JUMP:
            set_player_y_vel_based_on_fspeed(m, 69.0f, 0.0f);
            m->forwardVel *= 0.8f;
            break;

        case ACT_FLYING_TRIPLE_JUMP:
            set_player_y_vel_based_on_fspeed(m, 82.0f, 0.0f);
            break;

        case ACT_WATER_JUMP:
        case ACT_HOLD_WATER_JUMP:
            if (actionArg == 0) {
                set_player_y_vel_based_on_fspeed(m, 42.0f, 0.0f);
            }
            break;

        case ACT_BURNING_JUMP:
            m->vel[1] = 31.5f;
            m->forwardVel = 8.0f;
            break;

        case ACT_RIDING_SHELL_JUMP:
            set_player_y_vel_based_on_fspeed(m, 42.0f, 0.25f);
            break;

        case ACT_JUMP:
        case ACT_HOLD_JUMP:
            m->playerObj->header.gfx.animInfo.animID = -1;
            set_player_y_vel_based_on_fspeed(m, 42.0f, 0.25f);
            m->forwardVel *= 0.8f;
            break;

        case ACT_WALL_KICK_AIR:
        case ACT_TOP_OF_POLE_JUMP:
            set_player_y_vel_based_on_fspeed(m, 62.0f, 0.0f);
            if (m->forwardVel < 24.0f) {
                m->forwardVel = 24.0f;
            }
            m->wallKickTimer = 0;
            break;

        case ACT_SIDE_FLIP:
            set_player_y_vel_based_on_fspeed(m, 62.0f, 0.0f);
            m->forwardVel = 8.0f;
            m->faceAngle[1] = m->intendedYaw;
            break;

        case ACT_STEEP_JUMP:
            m->playerObj->header.gfx.animInfo.animID = -1;
            set_player_y_vel_based_on_fspeed(m, 42.0f, 0.25f);
            m->faceAngle[0] = -0x2000;
            break;

        case ACT_LAVA_BOOST:
            m->vel[1] = 84.0f;
            if (actionArg == 0) {
                m->forwardVel = 0.0f;
            }
            break;

        case ACT_DIVE:
            if ((forwardVel = m->forwardVel + 15.0f) > 48.0f) {
                forwardVel = 48.0f;
            }
            player_set_forward_vel(m, forwardVel);
            break;

        case ACT_LONG_JUMP:
            m->playerObj->header.gfx.animInfo.animID = -1;
            set_player_y_vel_based_on_fspeed(m, 30.0f, 0.0f);
            m->playerObj->oPlayerLongJumpIsSlow = m->forwardVel > 16.0f ? FALSE : TRUE;

            //! (BLJ's) This properly handles long jumps from getting forward speed with
            //  too much velocity, but misses backwards longs allowing high negative speeds.
            if ((m->forwardVel *= 1.5f) > 48.0f) {
                m->forwardVel = 48.0f;
            }
            break;

        case ACT_SLIDE_KICK:
            m->vel[1] = 12.0f;
            if (m->forwardVel < 32.0f) {
                m->forwardVel = 32.0f;
            }
            break;

        case ACT_JUMP_KICK:
            m->vel[1] = 20.0f;
            break;
    }

    m->peakHeight = m->pos[1];
    m->flags |= PLAYER_UNKNOWN_08;

    return action;
}

/**
 * Transitions for a variety of moving actions.
 */
static u32 set_player_action_moving(struct PlayerState *m, u32 action, UNUSED u32 actionArg) {
    s16 floorClass = player_get_floor_class(m);
    f32 forwardVel = m->forwardVel;
    f32 mag = MIN(m->intendedMag, 8.0f);

    switch (action) {
        case ACT_WALKING:
            if (floorClass != SURFACE_CLASS_VERY_SLIPPERY) {
                if (0.0f <= forwardVel && forwardVel < mag) {
                    m->forwardVel = mag;
                }
            }

            m->playerObj->oPlayerWalkingPitch = 0;
            break;

        case ACT_HOLD_WALKING:
            if (0.0f <= forwardVel && forwardVel < mag / 2.0f) {
                m->forwardVel = mag / 2.0f;
            }
            break;

        case ACT_BEGIN_SLIDING:
            if (player_facing_downhill(m, FALSE)) {
                action = ACT_BUTT_SLIDE;
            } else {
                action = ACT_STOMACH_SLIDE;
            }
            break;

        case ACT_HOLD_BEGIN_SLIDING:
            if (player_facing_downhill(m, FALSE)) {
                action = ACT_HOLD_BUTT_SLIDE;
            } else {
                action = ACT_HOLD_STOMACH_SLIDE;
            }
            break;
    }

    return action;
}

/**
 * Transition for certain submerged actions, which is actually just the metal jump actions.
 */
static u32 set_player_action_submerged(struct PlayerState *m, u32 action, UNUSED u32 actionArg) {
    if (action == ACT_METAL_WATER_JUMP || action == ACT_HOLD_METAL_WATER_JUMP) {
        m->vel[1] = 32.0f;
    }

    return action;
}

/**
 * Transitions for a variety of cutscene actions.
 */
static u32 set_player_action_cutscene(struct PlayerState *m, u32 action, UNUSED u32 actionArg) {
    switch (action) {
        case ACT_EMERGE_FROM_PIPE:
            m->vel[1] = 52.0f;
            break;

        case ACT_FALL_AFTER_STAR_GRAB:
            player_set_forward_vel(m, 0.0f);
            break;

        case ACT_SPAWN_SPIN_AIRBORNE:
            player_set_forward_vel(m, 2.0f);
            break;

        case ACT_SPECIAL_EXIT_AIRBORNE:
        case ACT_SPECIAL_DEATH_EXIT:
            m->vel[1] = 64.0f;
            break;
    }

    return action;
}

/**
 * Puts Player into a given action, putting Player through the appropriate
 * specific function if needed.
 */
u32 set_player_action(struct PlayerState *m, u32 action, u32 actionArg) {
    switch (action & ACT_GROUP_MASK) {
        case ACT_GROUP_MOVING:
            action = set_player_action_moving(m, action, actionArg);
            break;

        case ACT_GROUP_AIRBORNE:
            action = set_player_action_airborne(m, action, actionArg);
            break;

        case ACT_GROUP_SUBMERGED:
            action = set_player_action_submerged(m, action, actionArg);
            break;

        case ACT_GROUP_CUTSCENE:
            action = set_player_action_cutscene(m, action, actionArg);
            break;
    }

    // Resets the sound played flags, meaning the player can play those sound types again.
    m->flags &= ~(PLAYER_ACTION_SOUND_PLAYED | PLAYER_MARIO_SOUND_PLAYED);

    if (!(m->action & ACT_FLAG_AIR)) {
        m->flags &= ~PLAYER_UNKNOWN_18;
    }

    // Initialize the action information.
    m->prevAction = m->action;
    m->action = action;
    m->actionArg = actionArg;
    m->actionState = 0;
    m->actionTimer = 0;

    return TRUE;
}

/**
 * Puts Player into a specific jumping action from a landing action.
 */
s32 set_jump_from_landing(struct PlayerState *m) {
    if (m->quicksandDepth >= 11.0f) {
        if (m->heldObj == NULL) {
            return set_player_action(m, ACT_QUICKSAND_JUMP_LAND, 0);
        } else {
            return set_player_action(m, ACT_HOLD_QUICKSAND_JUMP_LAND, 0);
        }
    }

    if (player_floor_is_steep(m)) {
        set_steep_jump_action(m);
    } else {
        if ((m->doubleJumpTimer == 0) || (m->squishTimer != 0)) {
            set_player_action(m, ACT_JUMP, 0);
        } else {
            switch (m->prevAction) {
                case ACT_JUMP_LAND:
                    set_player_action(m, ACT_DOUBLE_JUMP, 0);
                    break;

                case ACT_FREEFALL_LAND:
                    set_player_action(m, ACT_DOUBLE_JUMP, 0);
                    break;

                case ACT_SIDE_FLIP_LAND_STOP:
                    set_player_action(m, ACT_DOUBLE_JUMP, 0);
                    break;

                case ACT_DOUBLE_JUMP_LAND:
                    // If the player has a wing cap, they ignore the typical speed
                    // requirement for a triple jump.
                    if (m->flags & PLAYER_WING_CAP) {
                        set_player_action(m, ACT_FLYING_TRIPLE_JUMP, 0);
                    } else if (m->forwardVel > 20.0f) {
                        set_player_action(m, ACT_TRIPLE_JUMP, 0);
                    } else {
                        set_player_action(m, ACT_JUMP, 0);
                    }
                    break;

                default:
                    set_player_action(m, ACT_JUMP, 0);
                    break;
            }
        }
    }

    m->doubleJumpTimer = 0;

    return TRUE;
}

/**
 * Puts Player in a given action, as long as it is not overruled by
 * either a quicksand or steep jump.
 */
s32 set_jumping_action(struct PlayerState *m, u32 action, u32 actionArg) {
    UNUSED u32 currAction = m->action;

    if (m->quicksandDepth >= 11.0f) {
        // Checks whether the player is holding an object or not.
        if (m->heldObj == NULL) {
            return set_player_action(m, ACT_QUICKSAND_JUMP_LAND, 0);
        } else {
            return set_player_action(m, ACT_HOLD_QUICKSAND_JUMP_LAND, 0);
        }
    }

    if (player_floor_is_steep(m)) {
        set_steep_jump_action(m);
    } else {
        set_player_action(m, action, actionArg);
    }

    return TRUE;
}

/**
 * Drop anything Player is holding and set a new action.
 */
s32 drop_and_set_player_action(struct PlayerState *m, u32 action, u32 actionArg) {
    player_stop_riding_and_holding(m);

    return set_player_action(m, action, actionArg);
}

/**
 * Increment Player's hurt counter and set a new action.
 */
s32 hurt_and_set_player_action(struct PlayerState *m, u32 action, u32 actionArg, s16 hurtCounter) {
    m->hurtCounter = hurtCounter;

    return set_player_action(m, action, actionArg);
}

/**
 * Checks a variety of inputs for common transitions between many different
 * actions. A common variant of the below function.
 */
s32 check_common_action_exits(struct PlayerState *m) {
    if (m->input & INPUT_A_PRESSED) {
        return set_player_action(m, ACT_JUMP, 0);
    }
    if (m->input & INPUT_OFF_FLOOR) {
        return set_player_action(m, ACT_FREEFALL, 0);
    }
    if (m->input & INPUT_NONZERO_ANALOG) {
        return set_player_action(m, ACT_WALKING, 0);
    }
    if (m->input & INPUT_ABOVE_SLIDE) {
        return set_player_action(m, ACT_BEGIN_SLIDING, 0);
    }

    return FALSE;
}

/**
 * Checks a variety of inputs for common transitions between many different
 * object holding actions. A holding variant of the above function.
 */
s32 check_common_hold_action_exits(struct PlayerState *m) {
    if (m->input & INPUT_A_PRESSED) {
        return set_player_action(m, ACT_HOLD_JUMP, 0);
    }
    if (m->input & INPUT_OFF_FLOOR) {
        return set_player_action(m, ACT_HOLD_FREEFALL, 0);
    }
    if (m->input & INPUT_NONZERO_ANALOG) {
        return set_player_action(m, ACT_HOLD_WALKING, 0);
    }
    if (m->input & INPUT_ABOVE_SLIDE) {
        return set_player_action(m, ACT_HOLD_BEGIN_SLIDING, 0);
    }

    return FALSE;
}

/**
 * Transitions Player from a submerged action to a walking action.
 */
s32 transition_submerged_to_walking(struct PlayerState *m) {
    set_camera_mode(m->area->camera, m->area->camera->defMode, 1);

    vec3s_set(m->angleVel, 0, 0, 0);

    if (m->heldObj == NULL) {
        return set_player_action(m, ACT_WALKING, 0);
    } else {
        return set_player_action(m, ACT_HOLD_WALKING, 0);
    }
}

#if FIX_WATER_PLUNGE_UPWARP
/**
 * Transitions Player from a submerged action to an airborne action.
 * You may want to change these actions to fit your hack
 */
s32 transition_submerged_to_airborne(struct PlayerState *m) {
    set_camera_mode(m->area->camera, m->area->camera->defMode, 1);

    vec3_zero(m->angleVel);

    if (m->heldObj == NULL) {
        if (m->input & INPUT_A_DOWN) return set_player_action(m, ACT_DIVE, 0);
        else return set_player_action(m, ACT_FREEFALL, 0);
    } else {
        if (m->input & INPUT_A_DOWN) return set_player_action(m, ACT_HOLD_JUMP, 0);
        else return set_player_action(m, ACT_HOLD_FREEFALL, 0);
    }
}
#endif

/**
 * This is the transition function typically for entering a submerged action for a
 * non-submerged action. This also applies the water surface camera preset.
 */
s32 set_water_plunge_action(struct PlayerState *m) {
    m->forwardVel = m->forwardVel / 4.0f;
    m->vel[1] = m->vel[1] / 2.0f;

#if !FIX_WATER_PLUNGE_UPWARP
    //! Causes waterbox upwarp
    m->pos[1] = m->waterLevel - 100;
#endif

    m->faceAngle[2] = 0;

    vec3s_set(m->angleVel, 0, 0, 0);

    if (!(m->action & ACT_FLAG_DIVING)) {
        m->faceAngle[0] = 0;
    }

    if (m->area->camera->mode != CAMERA_MODE_WATER_SURFACE) {
        set_camera_mode(m->area->camera, CAMERA_MODE_WATER_SURFACE, 1);
    }

    return set_player_action(m, ACT_WATER_PLUNGE, 0);
}

/**
 * These are the scaling values for the x and z axis for Player
 * when he is close to unsquishing.
 */
u8 sSquishScaleOverTime[16] = { 0x46, 0x32, 0x32, 0x3C, 0x46, 0x50, 0x50, 0x3C,
                                0x28, 0x14, 0x14, 0x1E, 0x32, 0x3C, 0x3C, 0x28 };

/**
 * Applies the squish to Player's model via scaling.
 */
void squish_player_model(struct PlayerState *m) {
    if (m->squishTimer != 0xFF) {
        // If no longer squished, scale back to default.
        // Also handles the Tiny Player and Huge Player cheats.
        if (m->squishTimer == 0) {
            cheats_player_size(m);
        }
        // If timer is less than 16, rubber-band the player's size scale up and down.
        else if (m->squishTimer <= 16) {
            m->squishTimer -= 1;

            m->playerObj->header.gfx.scale[1] =
                1.0f - ((sSquishScaleOverTime[15 - m->squishTimer] * 0.6f) / 100.0f);
            m->playerObj->header.gfx.scale[0] =
                ((sSquishScaleOverTime[15 - m->squishTimer] * 0.4f) / 100.0f) + 1.0f;

            m->playerObj->header.gfx.scale[2] = m->playerObj->header.gfx.scale[0];
        } else {
            m->squishTimer -= 1;

            vec3f_set(m->playerObj->header.gfx.scale, 1.4f, 0.4f, 1.4f);
        }
    }
}

/**
 * Debug function that prints floor normal, velocity, and action information.
 */
void debug_print_speed_action_normal(struct PlayerState *m) {
    f32 steepness;
    f32 floor_nY;

    if (gShowDebugText) {
        steepness = sqrtf(
            ((m->floor->normal.x * m->floor->normal.x) + (m->floor->normal.z * m->floor->normal.z)));
        floor_nY = m->floor->normal.y;

        print_text_fmt_int(210, 88, "ANG %d", (atan2s(floor_nY, steepness) * 180.0f) / 32768.0f);

        print_text_fmt_int(210, 72, "SPD %d", m->forwardVel);

        // STA short for "status," the official action name via SMS map.
        print_text_fmt_int(210, 56, "STA %x", (m->action & ACT_ID_MASK));
    }
}

/**
 * Update the button inputs for Player.
 */
void update_player_button_inputs(struct PlayerState *m) {
    if (m->controller->buttonPressed & A_BUTTON) {
        m->input |= INPUT_A_PRESSED;
    }

    if (m->controller->buttonDown & A_BUTTON) {
        m->input |= INPUT_A_DOWN;
    }

    // Don't update for these buttons if squished.
    if (m->squishTimer == 0) {
        if (m->controller->buttonPressed & B_BUTTON) {
            m->input |= INPUT_B_PRESSED;
        }

        if (m->controller->buttonDown & (ZL_TRIG | ZR_TRIG)) {
            m->input |= INPUT_Z_DOWN;
        }

        if (m->controller->buttonPressed & (ZL_TRIG | ZR_TRIG)) {
            m->input |= INPUT_Z_PRESSED;
        }
    }

    if (m->controller->buttonPressed & L_TRIG) {
        if (curChar > 2) {
            curChar = -1;
        }
        curChar = curChar + 1;
    }

    m->playerObj->header.gfx.sharedChild = gLoadedGraphNodes[gCharacters[curChar].modelId];
 
    if (m->input & INPUT_A_PRESSED) {
        m->framesSinceA = 0;
    } else if (m->framesSinceA < 0xFF) {
        m->framesSinceA++;
    }

    if (m->input & INPUT_B_PRESSED) {
        m->framesSinceB = 0;
    } else if (m->framesSinceB < 0xFF) {
        m->framesSinceB++;
    }
}

/**
 * Updates the joystick intended magnitude.
 */
void update_player_joystick_inputs(struct PlayerState *m) {
    struct Controller *controller = m->controller;
    f32 mag = ((controller->stickMag / 64.0f) * (controller->stickMag / 64.0f)) * 64.0f;

    if (m->squishTimer == 0) {
        m->intendedMag = mag / 2.0f;
    } else {
        m->intendedMag = mag / 8.0f;
    }

    if (m->intendedMag > 0.0f) {
        m->intendedYaw = atan2s(-controller->stickY, controller->stickX) + m->area->camera->yaw;
        m->input |= INPUT_NONZERO_ANALOG;
    } else {
        m->intendedYaw = m->faceAngle[1];
    }
}

/**
 * Resolves wall collisions, and updates a variety of inputs.
 */
void update_mario_geometry_inputs(struct PlayerState *m) {
    f32 gasLevel;
    f32 ceilToFloorDist;

    f32_find_wall_collision(&m->pos[0], &m->pos[1], &m->pos[2], 60.0f, 50.0f);
    f32_find_wall_collision(&m->pos[0], &m->pos[1], &m->pos[2], 30.0f, 24.0f);

    m->floorHeight = find_floor(m->pos[0], m->pos[1], m->pos[2], &m->floor);

    // If the player is OOB, move their position to their graphical position (which was not updated)
    // and check for the floor there.
    // This can cause errant behavior when combined with astral projection,
    // since the graphical position was not the players previous location.
    if (m->floor == NULL) {
        vec3f_copy(m->pos, m->playerObj->header.gfx.pos);
        m->floorHeight = find_floor(m->pos[0], m->pos[1], m->pos[2], &m->floor);
    }

    m->ceilHeight = vec3f_find_ceil(m->pos, m->floorHeight, &m->ceil);
    gasLevel = find_poison_gas_level(m->pos[0], m->pos[2]);
    m->waterLevel = find_water_level(m->pos[0], m->pos[2]);

    if (m->floor != NULL) {
        m->floorAngle = atan2s(m->floor->normal.z, m->floor->normal.x);
        m->terrainSoundAddend = player_get_terrain_sound_addend(m);

        if ((m->pos[1] > m->waterLevel - 40) && player_floor_is_slippery(m)) {
            m->input |= INPUT_ABOVE_SLIDE;
        }

        if ((m->floor->flags & SURFACE_FLAG_DYNAMIC)
            || (m->ceil && m->ceil->flags & SURFACE_FLAG_DYNAMIC)) {
            ceilToFloorDist = m->ceilHeight - m->floorHeight;

            if ((0.0f <= ceilToFloorDist) && (ceilToFloorDist <= 150.0f)) {
                m->input |= INPUT_SQUISHED;
            }
        }

        if (m->pos[1] > m->floorHeight + 100.0f) {
            m->input |= INPUT_OFF_FLOOR;
        }

        if (m->pos[1] < (m->waterLevel - 10)) {
            m->input |= INPUT_IN_WATER;
        }

        if (m->pos[1] < (gasLevel - 100.0f)) {
            m->input |= INPUT_IN_POISON_GAS;
        }

    } else {
        level_trigger_warp(m, WARP_OP_DEATH);
    }
}

/**
 * Handles Player's input flags as well as a couple timers.
 */
void update_player_inputs(struct PlayerState *m) {
    m->particleFlags = 0;
    m->input = 0;
    m->collidedObjInteractTypes = m->playerObj->collidedObjInteractTypes;
    m->flags &= 0xFFFFFF;

    update_player_button_inputs(m);
    update_player_joystick_inputs(m);
    update_mario_geometry_inputs(m);

    debug_print_speed_action_normal(m);

#ifdef DEV
    print_text_fmt_int(210, 92, "1 %d", m->playerObj->oPosX);
    print_text_fmt_int(210, 72, "2 %d", m->playerObj->oPosY);
    print_text_fmt_int(210, 52, "3 %d", m->playerObj->oPosZ);
    print_text_fmt_int(210, 120, "Jump Sound - %d", yahOrWah);
#endif
    cheats_player_inputs(m);

    if (gCameraMovementFlags & CAM_MOVE_C_UP_MODE) {
        if (m->action & ACT_FLAG_ALLOW_FIRST_PERSON) {
            m->input |= INPUT_FIRST_PERSON;
        } else {
            gCameraMovementFlags &= ~CAM_MOVE_C_UP_MODE;
        }
    }

    if (!(m->input & (INPUT_NONZERO_ANALOG | INPUT_A_PRESSED))) {
        m->input |= INPUT_UNKNOWN_5;
    }

    // These 3 flags are defined by Bowser stomping attacks
    if (m->playerObj->oInteractStatus
        & (INT_STATUS_PLAYER_STUNNED | INT_STATUS_PLAYER_KNOCKBACK_DMG | INT_STATUS_PLAYER_SHOCKWAVE)) {
        m->input |= INPUT_STOMPED;
    }

    // This function is located near other unused trampoline functions,
    // perhaps logically grouped here with the timers.
    stub_player_step_1(m);

    if (m->wallKickTimer > 0) {
        m->wallKickTimer--;
    }

    if (m->doubleJumpTimer > 0) {
        m->doubleJumpTimer--;
    }
}

/**
 * Set's the camera preset for submerged action behaviors.
 */
void set_submerged_cam_preset_and_spawn_bubbles(struct PlayerState *m) {
    f32 heightBelowWater;
    s16 camPreset;

    if ((m->action & ACT_GROUP_MASK) == ACT_GROUP_SUBMERGED) {
        heightBelowWater = (f32)(m->waterLevel - 80) - m->pos[1];
        camPreset = m->area->camera->mode;

        if (m->action & ACT_FLAG_METAL_WATER) {
            if (camPreset != CAMERA_MODE_CLOSE) {
                set_camera_mode(m->area->camera, CAMERA_MODE_CLOSE, 1);
            }
        } else {
            if ((heightBelowWater > 800.0f) && (camPreset != CAMERA_MODE_BEHIND_MARIO)) {
                set_camera_mode(m->area->camera, CAMERA_MODE_BEHIND_MARIO, 1);
            }

            if ((heightBelowWater < 400.0f) && (camPreset != CAMERA_MODE_WATER_SURFACE)) {
                set_camera_mode(m->area->camera, CAMERA_MODE_WATER_SURFACE, 1);
            }

            // As long as the player isn't drowning or at the top
            // of the water with their head out, spawn bubbles.
            if (!(m->action & ACT_FLAG_INTANGIBLE)) {
                if ((m->pos[1] < (f32)(m->waterLevel - 160)) || (m->faceAngle[0] < -0x800)) {
                    m->particleFlags |= PARTICLE_BUBBLE;
                }
            }
        }
    }
}

/**
 * Both increments and decrements Player's HP.
 */
void update_player_health(struct PlayerState *m) {
    s32 terrainIsSnow;

    if (m->health >= 0x100) {
        // When already healing or hurting the player, the players HP is not changed any more here.
        if (((u32) m->healCounter | (u32) m->hurtCounter) == 0) {
            if ((m->input & INPUT_IN_POISON_GAS) && !(m->action & ACT_FLAG_INTANGIBLE)) {
                if (!(m->flags & PLAYER_METAL_CAP) && !gDebugLevelSelect) {
                    m->health -= 4;
                }
            } else {
                if ((m->action & ACT_FLAG_SWIMMING) && !(m->action & ACT_FLAG_INTANGIBLE)) {
                    terrainIsSnow = (m->area->terrainType & TERRAIN_MASK) == TERRAIN_SNOW;

                    // When the player is near the water surface, recover health (unless in snow),
                    // when in snow terrains lose 3 health.
                    // If using the debug level select, do not lose any HP to water.
                    if ((m->pos[1] >= (m->waterLevel - 140)) && !terrainIsSnow) {
                        m->health += 0x1A;
                    } else if (!gDebugLevelSelect) {
                        m->health -= (terrainIsSnow ? 3 : 1);
                    }
                }
            }
        }

        if (m->healCounter > 0) {
            m->health += 0x40;
            m->healCounter--;
        }
        if (m->hurtCounter > 0) {
            m->health -= 0x40;
            m->hurtCounter--;
        }

        if (m->health > 0x880) {
            m->health = 0x880;
        }
        if (m->health < 0x100) {
            m->health = 0xFF;
        }

        // Play a noise to alert the player when the player is close to drowning.

        if (((m->action & ACT_GROUP_MASK) == ACT_GROUP_SUBMERGED) && (m->health < 0x300)) {
            play_sound(SOUND_MOVING_ALMOST_DROWNING, gGlobalSoundSource);
#ifdef RUMBLE_FEEDBACK
            if (gRumblePakTimer == 0) {
                gRumblePakTimer = 36;
                if (is_rumble_finished_and_queue_empty()) {
                    queue_rumble_data(3, 30);

                }
            }
        } else {
            gRumblePakTimer = 0;
#endif
        }
    }
}

/**
 * Updates some basic info for camera usage.
 */
void update_player_info_for_cam(struct PlayerState *m) {
    m->playerBodyState->action = m->action;
    m->statusForCamera->action = m->action;

    vec3s_copy(m->statusForCamera->faceAngle, m->faceAngle);

    if (!(m->flags & PLAYER_UNKNOWN_25)) {
        vec3f_copy(m->statusForCamera->pos, m->pos);
    }
}

/**
 * Resets Player's model, done every time an action is executed.
 */
void player_reset_bodystate(struct PlayerState *m) {
    struct PlayerBodyState *bodyState = m->playerBodyState;

    bodyState->capState = PLAYER_HAS_DEFAULT_CAP_OFF;
    bodyState->eyeState = PLAYER_EYES_BLINK;
    bodyState->handState = PLAYER_HAND_FISTS;
    bodyState->modelState = 0;
    bodyState->wingFlutter = FALSE;

    m->flags &= ~PLAYER_METAL_SHOCK;
}

/**
 * Adjusts Player's graphical height for quicksand.
 */
void sink_player_in_quicksand(struct PlayerState *m) {
    struct Object *o = m->playerObj;

    if (o->header.gfx.throwMatrix) {
        (*o->header.gfx.throwMatrix)[3][1] -= m->quicksandDepth;
    }

    o->header.gfx.pos[1] -= m->quicksandDepth;
}

/**
 * Is a binary representation of the frames to flicker Player's cap when the timer
 * is running out.
 *
 * Equals [1000]^5 . [100]^8 . [10]^9 . [1] in binary, which is
 * 100010001000100010001001001001001001001001001010101010101010101.
 */
u64 sCapFlickerFrames = 0x4444449249255555;

/**
 * Updates the cap flags mainly based on the cap timer.
 */
u32 update_and_return_cap_flags(struct PlayerState *m) {
    u32 flags = m->flags;
    u32 action;

    if (m->capTimer > 0) {
        action = m->action;

        if ((m->capTimer <= 60)
            || ((action != ACT_READING_AUTOMATIC_DIALOG) && (action != ACT_READING_NPC_DIALOG)
                && (action != ACT_READING_SIGN) && (action != ACT_IN_CANNON))) {
            m->capTimer -= 1;
        }

        if (m->capTimer == 0) {
            stop_cap_music();

            m->flags &= ~PLAYER_SPECIAL_CAPS;
            if (!(m->flags & PLAYER_CAPS)) {
                m->flags &= ~PLAYER_CAP_ON_HEAD;
            }
        }

        if (m->capTimer == 60) {
            fadeout_cap_music();
        }

        // This code flickers the cap through a long binary string, increasing in how
        // common it flickers near the end.
        if ((m->capTimer < 64) && ((1ULL << m->capTimer) & sCapFlickerFrames)) {
            flags &= ~PLAYER_SPECIAL_CAPS;
            if (!(flags & PLAYER_CAPS)) {
                flags &= ~PLAYER_CAP_ON_HEAD;
            }
        }
    }

    return flags;
}

#if FIX_SHORT_HITBOX_SLIDE_ACTS
#define ACT_FLAG_HEIGHT_MASK (ACT_FLAG_SHORT_HITBOX | ACT_FLAG_BUTT_OR_STOMACH_SLIDE)
#else
#define ACT_FLAG_HEIGHT_MASK ACT_FLAG_SHORT_HITBOX
#endif

/**
 * Updates the Player's cap, rendering, and hitbox.
 */
void player_update_hitbox_and_cap_model(struct PlayerState *m) {
    struct PlayerBodyState *bodyState = m->playerBodyState;
    s32 flags = update_and_return_cap_flags(m);

    if (flags & PLAYER_VANISH_CAP) {
        //bodyState->modelState = MODEL_STATE_NOISE_ALPHA;
    }

    if (flags & PLAYER_METAL_CAP) {
        bodyState->modelState |= MODEL_STATE_METAL;
    }

    if (flags & PLAYER_METAL_SHOCK) {
        bodyState->modelState |= MODEL_STATE_METAL;
    }

    //! (Pause buffered hitstun) Since the global timer increments while paused,
    //  this can be paused through to give continual invisibility. This leads to
    //  no interaction with objects.
    if ((m->invincTimer >= 3) && (gGlobalTimer & 1)) {
        gPlayerState->playerObj->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
    }

    if (flags & PLAYER_CAP_IN_HAND) {
        if (flags & PLAYER_WING_CAP) {
            bodyState->handState = PLAYER_HAND_HOLDING_WING_CAP;
        } else {
            bodyState->handState = PLAYER_HAND_HOLDING_CAP;
        }
    }

    if (flags & PLAYER_CAP_ON_HEAD) {
        if (flags & PLAYER_WING_CAP) {
            bodyState->capState = PLAYER_HAS_WING_CAP_ON;
        } else {
            bodyState->capState = PLAYER_HAS_DEFAULT_CAP_ON;
        }
    }

    // Short hitbox for crouching/crawling/etc.
    if (m->action & ACT_FLAG_HEIGHT_MASK) {
        m->playerObj->hitboxHeight = 100.0f;
    } else {
        m->playerObj->hitboxHeight = 160.0f;
    }

    if ((m->flags & PLAYER_TELEPORTING) && (m->fadeWarpOpacity != 0xFF)) {
        bodyState->modelState &= ~0xFF;
        bodyState->modelState |= (0x100 | m->fadeWarpOpacity);
    }
}

void set_wind_floor_properties(struct PlayerState *m) {
#if FIX_SURFACE_WIND_DETECTION
    if (!(m->action & ACT_FLAG_INTANGIBLE))
#endif
    {
        // Both of the wind handling portions play wind audio only in
        // non-Japanese releases.
        if (m->floor->type == SURFACE_HORIZONTAL_WIND) {
            spawn_wind_particles(0, (m->floor->force << 8));
            play_sound(SOUND_ENV_WIND2, m->playerObj->header.gfx.cameraToObject);
        }

        if (m->floor->type == SURFACE_VERTICAL_WIND) {
            spawn_wind_particles(1, 0);
            play_sound(SOUND_ENV_WIND2, m->playerObj->header.gfx.cameraToObject);
        }
    }
}
        
/**
 * An unused and possibly a debug function. Z + another button input
 * sets Player with a different cap.
 */
void debug_update_player_cap(u16 button, s32 flags, u16 capTimer, u16 capMusic) {
    if ((gPlayer1Controller->buttonDown & (ZL_TRIG | ZR_TRIG)) && (gPlayer1Controller->buttonPressed & button)
        && !(gPlayerState->flags & flags)) {
        gPlayerState->flags |= (flags + PLAYER_CAP_ON_HEAD);

        if (capTimer > gPlayerState->capTimer) {
            gPlayerState->capTimer = capTimer;
        }

        play_cap_music(capMusic);
    }
}

#ifdef RUMBLE_FEEDBACK
void queue_rumble_particles(void) {
    if (gPlayerState->particleFlags & PARTICLE_HORIZONTAL_STAR) {
        queue_rumble_data(5, 80);
    } else if (gPlayerState->particleFlags & PARTICLE_VERTICAL_STAR) {
        queue_rumble_data(5, 80);
    } else if (gPlayerState->particleFlags & PARTICLE_TRIANGLE) {
        queue_rumble_data(5, 80);
    }
    if (gPlayerState->heldObj && gPlayerState->heldObj->behavior == segmented_to_virtual(bhvBobomb)) {
        reset_rumble_timers_slip();
    }
}
#endif

/**
 * Main function for executing Player's behavior.
 */
s32 execute_player_action(UNUSED struct Object *o) {
    s32 inLoop = TRUE;
    cheats_player_action(gPlayerState);

#ifdef EXT_DEBUG_MENU
    set_debug_player_action(gPlayerState);
#endif

    if (gPlayerState->action) {
        gPlayerState->playerObj->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
        player_reset_bodystate(gPlayerState);
        update_player_inputs(gPlayerState);
        player_handle_special_floors(gPlayerState);
        player_process_interactions(gPlayerState);

        // If the player is OOB, stop executing actions.
        if (gPlayerState->floor == NULL) {
            return 0;
        }

        // The function can loop through many action shifts in one frame,
        // which can lead to unexpected sub-frame behavior. Could potentially hang
        // if a loop of actions were found, but there has not been a situation found.
        while (inLoop) {
            switch (gPlayerState->action & ACT_GROUP_MASK) {
                case ACT_GROUP_STATIONARY:
                    inLoop = player_execute_stationary_action(gPlayerState);
                    break;

                case ACT_GROUP_MOVING:
                    inLoop = player_execute_moving_action(gPlayerState);
                    break;

                case ACT_GROUP_AIRBORNE:
                    inLoop = player_execute_airborne_action(gPlayerState);
                    break;

                case ACT_GROUP_SUBMERGED:
                    inLoop = player_execute_submerged_action(gPlayerState);
                    break;

                case ACT_GROUP_CUTSCENE:
                    inLoop = player_execute_cutscene_action(gPlayerState);
                    break;

                case ACT_GROUP_AUTOMATIC:
                    inLoop = player_execute_automatic_action(gPlayerState);
                    break;

                case ACT_GROUP_OBJECT:
                    inLoop = player_execute_object_action(gPlayerState);
                    break;
            }
        }

        sink_player_in_quicksand(gPlayerState);
        squish_player_model(gPlayerState);
        set_submerged_cam_preset_and_spawn_bubbles(gPlayerState);
        update_player_health(gPlayerState);
        update_player_info_for_cam(gPlayerState);
        player_update_hitbox_and_cap_model(gPlayerState);
        set_wind_floor_properties(gPlayerState);
        play_infinite_stairs_music();

        gPlayerState->playerObj->oInteractStatus = 0;
#ifdef RUMBLE_FEEDBACK
        queue_rumble_particles();
#endif
        return gPlayerState->particleFlags;
    }

    return 0;
}

/**************************************************
 *                  INITIALIZATION                *
 **************************************************/

void init_player(void) {
    unused80339F10 = 0;

    gPlayerState->actionTimer = 0;
    gPlayerState->framesSinceA = 0xFF;
    gPlayerState->framesSinceB = 0xFF;

    gPlayerState->invincTimer = 0;

    if (save_file_get_flags()
        & (SAVE_FLAG_CAP_ON_GROUND | SAVE_FLAG_CAP_ON_KLEPTO | SAVE_FLAG_CAP_ON_UKIKI
           | SAVE_FLAG_CAP_ON_MR_BLIZZARD)) {
        gPlayerState->flags = 0;
    } else {
        gPlayerState->flags = (PLAYER_NORMAL_CAP | PLAYER_CAP_ON_HEAD);
    }

    gPlayerState->forwardVel = 0.0f;
    gPlayerState->squishTimer = 0;

    gPlayerState->hurtCounter = 0;
    gPlayerState->healCounter = 0;

    gPlayerState->capTimer = 0;
    gPlayerState->quicksandDepth = 0.0f;

    gPlayerState->heldObj = NULL;
    gPlayerState->riddenObj = NULL;
    gPlayerState->usedObj = NULL;

    gPlayerState->waterLevel =
        find_water_level(gPlayerSpawnInfo->startPos[0], gPlayerSpawnInfo->startPos[2]);

    gPlayerState->area = gCurrentArea;
    gPlayerState->playerObj = gPlayerObject;
    gPlayerState->playerObj->header.gfx.animInfo.animID = -1;
    vec3s_copy(gPlayerState->faceAngle, gPlayerSpawnInfo->startAngle);
    vec3s_set(gPlayerState->angleVel, 0, 0, 0);
    vec3s_to_vec3f(gPlayerState->pos, gPlayerSpawnInfo->startPos);
    vec3f_set(gPlayerState->vel, 0, 0, 0);
    gPlayerState->floorHeight =
        find_floor(gPlayerState->pos[0], gPlayerState->pos[1], gPlayerState->pos[2], &gPlayerState->floor);

    if (gPlayerState->pos[1] < gPlayerState->floorHeight) {
        gPlayerState->pos[1] = gPlayerState->floorHeight;
    }

    gPlayerState->playerObj->header.gfx.pos[1] = gPlayerState->pos[1];

    gPlayerState->action =
        (gPlayerState->pos[1] <= (gPlayerState->waterLevel - 100)) ? ACT_WATER_IDLE : ACT_IDLE;

    player_reset_bodystate(gPlayerState);
    update_player_info_for_cam(gPlayerState);
    gPlayerState->playerBodyState->punchState = 0;

    gPlayerState->playerObj->oPosX = gPlayerState->pos[0];
    gPlayerState->playerObj->oPosY = gPlayerState->pos[1];
    gPlayerState->playerObj->oPosZ = gPlayerState->pos[2];

    gPlayerState->playerObj->oMoveAnglePitch = gPlayerState->faceAngle[0];
    gPlayerState->playerObj->oMoveAngleYaw = gPlayerState->faceAngle[1];
    gPlayerState->playerObj->oMoveAngleRoll = gPlayerState->faceAngle[2];

    vec3f_copy(gPlayerState->playerObj->header.gfx.pos, gPlayerState->pos);
    vec3s_set(gPlayerState->playerObj->header.gfx.angle, 0, gPlayerState->faceAngle[1], 0);

    Vec3s capPos;
    if (save_file_get_cap_pos(capPos)
#if FIX_HAT_CLONE_FADE
    && (count_objects_with_behavior(bhvNormalCap) < 1)
#endif
    ) {
        struct Object *capObject = spawn_object(gPlayerState->playerObj, MODEL_MARIOS_CAP, bhvNormalCap);

        capObject->oPosX = capPos[0];
        capObject->oPosY = capPos[1];
        capObject->oPosZ = capPos[2];

        capObject->oForwardVelS32 = 0;

        capObject->oMoveAngleYaw = 0;
    }
}

void init_player_from_save_file(void) {
    gPlayerState->unk00 = 0;
    gPlayerState->flags = 0;
    gPlayerState->action = 0;
    gPlayerState->spawnInfo = &gPlayerSpawnInfos[0];
    gPlayerState->statusForCamera = &gPlayerCameraState[0];
    gPlayerState->playerBodyState = &gBodyStates[0];
    gPlayerState->controller = &gControllers[0];
    gPlayerState->animList = &gPlayerAnimsBuf;

    gPlayerState->numCoins = 0;
    gPlayerState->numStars =
        save_file_get_total_star_count(gCurrSaveFileNum - 1, COURSE_MIN - 1, COURSE_MAX - 1);

    gPlayerState->numLives = MARIO_START_LIVES;
    gPlayerState->health = 0x880;

    gPlayerState->prevNumStarsForDialog = gPlayerState->numStars;
    gPlayerState->unkB0 = 0xBD;

    gHudDisplay.coins = 0;
    gHudDisplay.wedges = 8;
}
