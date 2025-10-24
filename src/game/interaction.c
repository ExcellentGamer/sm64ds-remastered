#include <PR/ultratypes.h>

#include "area.h"
#include "actors/common1.h"
#include "audio/external.h"
#include "behavior_actions.h"
#include "behavior_data.h"
#include "camera.h"
#include "course_table.h"
#include "dialog_ids.h"
#include "engine/math_util.h"
#include "engine/surface_collision.h"
#include "game_init.h"
#include "interaction.h"
#include "level_update.h"
#include "characters.h"
#include "player.h"
#include "player_step.h"
#include "memory.h"
#include "obj_behaviors.h"
#include "object_helpers.h"
#include "save_file.h"
#include "seq_ids.h"
#include "sm64.h"
#include "sound_init.h"
#include "rumble_init.h"

#include "extras/cheats.h"

#ifdef EXT_OPTIONS_MENU
#include "pc/configfile.h"
#endif

#define INT_GROUND_POUND_OR_TWIRL (1 << 0) // 0x01
#define INT_PUNCH                 (1 << 1) // 0x02
#define INT_KICK                  (1 << 2) // 0x04
#define INT_TRIP                  (1 << 3) // 0x08
#define INT_SLIDE_KICK            (1 << 4) // 0x10
#define INT_FAST_ATTACK_OR_SHELL  (1 << 5) // 0x20
#define INT_HIT_FROM_ABOVE        (1 << 6) // 0x40
#define INT_HIT_FROM_BELOW        (1 << 7) // 0x80

#define INT_ATTACK_NOT_FROM_BELOW                                                 \
    (INT_GROUND_POUND_OR_TWIRL | INT_PUNCH | INT_KICK | INT_TRIP | INT_SLIDE_KICK \
     | INT_FAST_ATTACK_OR_SHELL | INT_HIT_FROM_ABOVE)

#define INT_ANY_ATTACK                                                            \
    (INT_GROUND_POUND_OR_TWIRL | INT_PUNCH | INT_KICK | INT_TRIP | INT_SLIDE_KICK \
     | INT_FAST_ATTACK_OR_SHELL | INT_HIT_FROM_ABOVE | INT_HIT_FROM_BELOW)

#define INT_ATTACK_NOT_WEAK_FROM_ABOVE                                                \
    (INT_GROUND_POUND_OR_TWIRL | INT_PUNCH | INT_KICK | INT_TRIP | INT_HIT_FROM_BELOW)

u8 sDelayInvincTimer;
s16 sInvulnerable;
u32 interact_coin(struct PlayerState *, u32, struct Object *);
u32 interact_water_ring(struct PlayerState *, u32, struct Object *);
u32 interact_star_or_key(struct PlayerState *, u32, struct Object *);
u32 interact_bbh_entrance(struct PlayerState *, u32, struct Object *);
u32 interact_warp(struct PlayerState *, u32, struct Object *);
u32 interact_warp_door(struct PlayerState *, u32, struct Object *);
u32 interact_door(struct PlayerState *, u32, struct Object *);
u32 interact_cannon_base(struct PlayerState *, u32, struct Object *);
u32 interact_igloo_barrier(struct PlayerState *, u32, struct Object *);
u32 interact_tornado(struct PlayerState *, u32, struct Object *);
u32 interact_whirlpool(struct PlayerState *, u32, struct Object *);
u32 interact_strong_wind(struct PlayerState *, u32, struct Object *);
u32 interact_flame(struct PlayerState *, u32, struct Object *);
u32 interact_snufit_bullet(struct PlayerState *, u32, struct Object *);
u32 interact_clam_or_bubba(struct PlayerState *, u32, struct Object *);
u32 interact_bully(struct PlayerState *, u32, struct Object *);
u32 interact_shock(struct PlayerState *, u32, struct Object *);
u32 interact_mr_blizzard(struct PlayerState *, u32, struct Object *);
u32 interact_hit_from_below(struct PlayerState *, u32, struct Object *);
u32 interact_bounce_top(struct PlayerState *, u32, struct Object *);
u32 interact_unknown_08(struct PlayerState *, u32, struct Object *);
u32 interact_damage(struct PlayerState *, u32, struct Object *);
u32 interact_breakable(struct PlayerState *, u32, struct Object *);
u32 interact_koopa_shell(struct PlayerState *, u32, struct Object *);
u32 interact_pole(struct PlayerState *, u32, struct Object *);
u32 interact_hoot(struct PlayerState *, u32, struct Object *);
u32 interact_cap(struct PlayerState *, u32, struct Object *);
u32 interact_grabbable(struct PlayerState *, u32, struct Object *);
u32 interact_text(struct PlayerState *, u32, struct Object *);

struct InteractionHandler {
    u32 interactType;
    u32 (*handler)(struct PlayerState *, u32, struct Object *);
};

static struct InteractionHandler sInteractionHandlers[] = {
    { INTERACT_COIN,           interact_coin },
    { INTERACT_WATER_RING,     interact_water_ring },
    { INTERACT_STAR_OR_KEY,    interact_star_or_key },
    { INTERACT_BBH_ENTRANCE,   interact_bbh_entrance },
    { INTERACT_WARP,           interact_warp },
    { INTERACT_WARP_DOOR,      interact_warp_door },
    { INTERACT_DOOR,           interact_door },
    { INTERACT_CANNON_BASE,    interact_cannon_base },
    { INTERACT_IGLOO_BARRIER,  interact_igloo_barrier },
    { INTERACT_TORNADO,        interact_tornado },
    { INTERACT_WHIRLPOOL,      interact_whirlpool },
    { INTERACT_STRONG_WIND,    interact_strong_wind },
    { INTERACT_FLAME,          interact_flame },
    { INTERACT_SNUFIT_BULLET,  interact_snufit_bullet },
    { INTERACT_CLAM_OR_BUBBA,  interact_clam_or_bubba },
    { INTERACT_BULLY,          interact_bully },
    { INTERACT_SHOCK,          interact_shock },
    { INTERACT_BOUNCE_TOP2,    interact_bounce_top },
    { INTERACT_MR_BLIZZARD,    interact_mr_blizzard },
    { INTERACT_HIT_FROM_BELOW, interact_hit_from_below },
    { INTERACT_BOUNCE_TOP,     interact_bounce_top },
    { INTERACT_DAMAGE,         interact_damage },
    { INTERACT_POLE,           interact_pole },
    { INTERACT_HOOT,           interact_hoot },
    { INTERACT_BREAKABLE,      interact_breakable },
    { INTERACT_KOOPA,          interact_bounce_top },
    { INTERACT_KOOPA_SHELL,    interact_koopa_shell },
    { INTERACT_UNKNOWN_08,     interact_unknown_08 },
    { INTERACT_CAP,            interact_cap },
    { INTERACT_GRABBABLE,      interact_grabbable },
    { INTERACT_TEXT,           interact_text },
};

static u32 sForwardKnockbackActions[][3] = {
    { ACT_SOFT_FORWARD_GROUND_KB, ACT_FORWARD_GROUND_KB, ACT_HARD_FORWARD_GROUND_KB },
    { ACT_FORWARD_AIR_KB,         ACT_FORWARD_AIR_KB,    ACT_HARD_FORWARD_AIR_KB },
    { ACT_FORWARD_WATER_KB,       ACT_FORWARD_WATER_KB,  ACT_FORWARD_WATER_KB },
};

static u32 sBackwardKnockbackActions[][3] = {
    { ACT_SOFT_BACKWARD_GROUND_KB, ACT_BACKWARD_GROUND_KB, ACT_HARD_BACKWARD_GROUND_KB },
    { ACT_BACKWARD_AIR_KB,         ACT_BACKWARD_AIR_KB,    ACT_HARD_BACKWARD_AIR_KB },
    { ACT_BACKWARD_WATER_KB,       ACT_BACKWARD_WATER_KB,  ACT_BACKWARD_WATER_KB },
};

static u8 sDisplayingDoorText = FALSE;
static u8 sJustTeleported = FALSE;
u8 gPSSSlideStarted = FALSE;

/**
 * Returns the type of cap Player is wearing.
 */
u32 get_player_cap_flag(struct Object *capObject) {
    const BehaviorScript *script = virtual_to_segmented(0x13, capObject->behavior);

    if (script == bhvNormalCap) {
        return PLAYER_NORMAL_CAP;
    } else if (script == bhvMetalCap) {
        return PLAYER_METAL_CAP;
    } else if (script == bhvWingCap) {
        return PLAYER_WING_CAP;
    } else if (script == bhvVanishCap) {
        return PLAYER_VANISH_CAP;
    } else if (script == bhvMarioCap) {
        curChar = 1; // Todo: make this not swap hud or sfx
    } else if (script == bhvLuigiCap) {
        curChar = 2; // Todo: make this not swap hud or sfx
    } else if (script == bhvWarioCap) {
        curChar = 3; // Todo: make this not swap hud or sfx
    } else if (script == bhvPowerFlower) {
        if (curChar == 1) {
            return PLAYER_WING_CAP;
        } else if (curChar == 2) {
            return PLAYER_VANISH_CAP;
        } else if (curChar == 3) {
            return PLAYER_METAL_CAP;
        } else {
            return PLAYER_WING_CAP;
        }
    }

    return 0;
}

/**
 * Returns true if the passed in object has a moving angle yaw
 * in the angular range given towards Player.
 */
u32 object_facing_player(struct PlayerState *m, struct Object *o, s16 angleRange) {
    f32 dx = m->pos[0] - o->oPosX;
    f32 dz = m->pos[2] - o->oPosZ;

    s16 angleToPlayer = atan2s(dz, dx);
    s16 dAngle = angleToPlayer - o->oMoveAngleYaw;

    if (-angleRange <= dAngle && dAngle <= angleRange) {
        return TRUE;
    }

    return FALSE;
}

s16 player_obj_angle_to_object(struct PlayerState *m, struct Object *o) {
    f32 dx = o->oPosX - m->pos[0];
    f32 dz = o->oPosZ - m->pos[2];

    return atan2s(dz, dx);
}

/**
 * Determines Player's interaction with a given object depending on their proximity,
 * action, speed, and position.
 */
u32 determine_interaction(struct PlayerState *m, struct Object *o) {
    u32 interaction = 0;
    u32 action = m->action;

    if (action & ACT_FLAG_ATTACKING) {
        if (action == ACT_PUNCHING || action == ACT_MOVE_PUNCHING || action == ACT_JUMP_KICK) {
            s16 dYawToObject = player_obj_angle_to_object(m, o) - m->faceAngle[1];

            if (m->flags & PLAYER_PUNCHING) {
                // 120 degrees total, or 60 each way
                if (-0x2AAA <= dYawToObject && dYawToObject <= 0x2AAA) {
                    interaction = INT_PUNCH;
                }
            }
            if (m->flags & PLAYER_KICKING) {
                // 120 degrees total, or 60 each way
                if (-0x2AAA <= dYawToObject && dYawToObject <= 0x2AAA) {
                    interaction = INT_KICK;
                }
            }
            if (m->flags & PLAYER_TRIPPING) {
                // 180 degrees total, or 90 each way
                if (-0x4000 <= dYawToObject && dYawToObject <= 0x4000) {
                    interaction = INT_TRIP;
                }
            }
        } else if (action == ACT_GROUND_POUND || action == ACT_TWIRLING) {
            if (m->vel[1] < 0.0f) {
                interaction = INT_GROUND_POUND_OR_TWIRL;
            }
        } else if (action == ACT_GROUND_POUND_LAND || action == ACT_TWIRL_LAND) {
            // Neither ground pounding nor twirling change Player's vertical speed on landing.,
            // so the speed check is nearly always true (perhaps not if you land while going upwards?)
            // Additionally, actionState it set on each first thing in their action, so this is
            // only true prior to the very first frame (i.e. active 1 frame prior to it run).
            if (m->vel[1] < 0.0f && m->actionState == 0) {
                interaction = INT_GROUND_POUND_OR_TWIRL;
            }
        } else if (action == ACT_SLIDE_KICK || action == ACT_SLIDE_KICK_SLIDE) {
            interaction = INT_SLIDE_KICK;
        } else if (action & ACT_FLAG_RIDING_SHELL) {
            interaction = INT_FAST_ATTACK_OR_SHELL;
        } else if (m->forwardVel <= -26.0f || 26.0f <= m->forwardVel) {
            interaction = INT_FAST_ATTACK_OR_SHELL;
        }
    }

    // Prior to this, the interaction type could be overwritten. This requires, however,
    // that the interaction not be set prior. This specifically overrides turning a ground
    // pound into just a bounce.
    if (interaction == 0 && (action & ACT_FLAG_AIR)) {
        if (m->vel[1] < 0.0f) {
            if (m->pos[1] > o->oPosY) {
                interaction = INT_HIT_FROM_ABOVE;
            }
        } else {
            if (m->pos[1] < o->oPosY) {
                interaction = INT_HIT_FROM_BELOW;
            }
        }
    }

    return interaction;
}

/**
 * Sets the interaction types for INT_STATUS_INTERACTED, INT_STATUS_WAS_ATTACKED
 */
u32 attack_object(struct Object *o, s32 interaction) {
    u32 attackType = 0;

    switch (interaction) {
        case INT_GROUND_POUND_OR_TWIRL:
            attackType = ATTACK_GROUND_POUND_OR_TWIRL;
            break;
        case INT_PUNCH:
            attackType = ATTACK_PUNCH;
            break;
        case INT_KICK:
        case INT_TRIP:
            attackType = ATTACK_KICK_OR_TRIP;
            break;
        case INT_SLIDE_KICK:
        case INT_FAST_ATTACK_OR_SHELL:
            attackType = ATTACK_FAST_ATTACK;
            break;
        case INT_HIT_FROM_ABOVE:
            attackType = ATTACK_FROM_ABOVE;
            break;
        case INT_HIT_FROM_BELOW:
            attackType = ATTACK_FROM_BELOW;
            break;
    }

    o->oInteractStatus = attackType + (INT_STATUS_INTERACTED | INT_STATUS_WAS_ATTACKED);
    return attackType;
}

void player_stop_riding_object(struct PlayerState *m) {
    if (m->riddenObj != NULL) {
        m->riddenObj->oInteractStatus = INT_STATUS_STOP_RIDING;
        stop_shell_music();
        m->riddenObj = NULL;
    }
}

void player_grab_used_object(struct PlayerState *m) {
    if (m->heldObj == NULL) {
        m->heldObj = m->usedObj;
        obj_set_held_state(m->heldObj, bhvCarrySomething3);
    }
}

void player_drop_held_object(struct PlayerState *m) {
    if (m->heldObj != NULL) {
        if (m->heldObj->behavior == segmented_to_virtual(bhvKoopaShellUnderwater)) {
            stop_shell_music();
        }

        obj_set_held_state(m->heldObj, bhvCarrySomething4);

        // ! When dropping an object instead of throwing it, it will be put at Player's
        // y-positon instead of the HOLP's y-position. This fact is often exploited when
        // cloning objects.
        m->heldObj->oPosX = m->playerBodyState->heldObjLastPosition[0];
        m->heldObj->oPosY = m->pos[1];
        m->heldObj->oPosZ = m->playerBodyState->heldObjLastPosition[2];

        m->heldObj->oMoveAngleYaw = m->faceAngle[1];

        m->heldObj = NULL;
    }
}

void player_throw_held_object(struct PlayerState *m) {
    if (m->heldObj != NULL) {
        if (m->heldObj->behavior == segmented_to_virtual(bhvKoopaShellUnderwater)) {
            stop_shell_music();
        }

        obj_set_held_state(m->heldObj, bhvCarrySomething5);

        m->heldObj->oPosX = m->playerBodyState->heldObjLastPosition[0] + 32.0f * sins(m->faceAngle[1]);
        m->heldObj->oPosY = m->playerBodyState->heldObjLastPosition[1];
        m->heldObj->oPosZ = m->playerBodyState->heldObjLastPosition[2] + 32.0f * coss(m->faceAngle[1]);

        m->heldObj->oMoveAngleYaw = m->faceAngle[1];

        m->heldObj = NULL;
    }
}

void player_stop_riding_and_holding(struct PlayerState *m) {
    player_drop_held_object(m);
    player_stop_riding_object(m);

    if (m->action == ACT_RIDING_HOOT) {
        m->usedObj->oInteractStatus = FALSE;
        m->usedObj->oHootPlayerReleaseTime = gGlobalTimer;
    }
}

u32 does_player_have_normal_cap_on_head(struct PlayerState *m) {
    return (m->flags & (PLAYER_CAPS | PLAYER_CAP_ON_HEAD)) == (PLAYER_NORMAL_CAP | PLAYER_CAP_ON_HEAD);
}

void player_blow_off_cap(struct PlayerState *m, f32 capSpeed) {
    struct Object *capObject;
    u8 capModel = gCharacters[curChar].capModelId;

    if (does_player_have_normal_cap_on_head(m)) {
        save_file_set_cap_pos(m->pos[0], m->pos[1], m->pos[2]);

        m->flags &= ~(PLAYER_NORMAL_CAP | PLAYER_CAP_ON_HEAD);

        capObject = spawn_object(m->playerObj, capModel, bhvNormalCap);

        capObject->oPosY += (m->action & ACT_FLAG_SHORT_HITBOX) ? 120.0f : 180.0f;
        capObject->oForwardVel = capSpeed;
        capObject->oMoveAngleYaw = (s16)(m->faceAngle[1] + 0x400);

        if (m->forwardVel < 0.0f) {
            capObject->oMoveAngleYaw = (s16)(capObject->oMoveAngleYaw + 0x8000);
        }
    }
}

u32 player_lose_cap_to_enemy(u32 arg) {
    u32 wasWearingCap = FALSE;

    if (does_player_have_normal_cap_on_head(gPlayerState)) {
        save_file_set_flags(arg == 1 ? SAVE_FLAG_CAP_ON_KLEPTO : SAVE_FLAG_CAP_ON_UKIKI);
        gPlayerState->flags &= ~(PLAYER_NORMAL_CAP | PLAYER_CAP_ON_HEAD);
        wasWearingCap = TRUE;
    }

    return wasWearingCap;
}

void player_retrieve_cap(void) {
    player_drop_held_object(gPlayerState);
    save_file_clear_flags(SAVE_FLAG_CAP_ON_KLEPTO | SAVE_FLAG_CAP_ON_UKIKI);
    gPlayerState->flags &= ~PLAYER_CAP_ON_HEAD;
    gPlayerState->flags |= PLAYER_NORMAL_CAP | PLAYER_CAP_IN_HAND;
}

u32 able_to_grab_object(struct PlayerState *m, UNUSED struct Object *o) {
    u32 action = m->action;

    if (action == ACT_DIVE_SLIDE || action == ACT_DIVE) {
        if (!(o->oInteractionSubtype & INT_SUBTYPE_GRABS_PLAYER)) {
            return TRUE;
        }
    } else if (action == ACT_PUNCHING || action == ACT_MOVE_PUNCHING) {
        if (m->actionArg < 2) {
            return TRUE;
        }
    }

    return FALSE;
}

struct Object *player_get_collided_object(struct PlayerState *m, u32 interactType) {
    s32 i;
    struct Object *object;

    for (i = 0; i < m->playerObj->numCollidedObjs; i++) {
        object = m->playerObj->collidedObjs[i];

        if (object->oInteractType == interactType) {
            return object;
        }
    }

    return NULL;
}

u32 player_check_object_grab(struct PlayerState *m) {
    u32 result = FALSE;
    const BehaviorScript *script;

    if (m->input & INPUT_INTERACT_OBJ_GRABBABLE) {
        script = virtual_to_segmented(0x13, m->interactObj->behavior);

        if (script == bhvBowser) {
            s16 facingDYaw = m->faceAngle[1] - m->interactObj->oMoveAngleYaw;
            if (facingDYaw >= -0x5555 && facingDYaw <= 0x5555) {
                m->faceAngle[1] = m->interactObj->oMoveAngleYaw;
                m->usedObj = m->interactObj;
                result = set_player_action(m, ACT_PICKING_UP_BOWSER, 0);
            }
        } else {
            s16 facingDYaw = player_obj_angle_to_object(m, m->interactObj) - m->faceAngle[1];
            if (facingDYaw >= -0x2AAA && facingDYaw <= 0x2AAA) {
                m->usedObj = m->interactObj;

                if (!(m->action & ACT_FLAG_AIR)) {
                    set_player_action(
                        m, (m->action & ACT_FLAG_DIVING) ? ACT_DIVE_PICKING_UP : ACT_PICKING_UP, 0);
                }

                result = TRUE;
            }
        }
    }

    return result;
}

u32 bully_knock_back_player(struct PlayerState *player) {
    struct BullyCollisionData playerData;
    struct BullyCollisionData bullyData;
    s16 newPlayerYaw;
    s16 newBullyYaw;
    s16 playerDYaw;
    UNUSED s16 bullyDYaw;

    u32 bonkAction = 0;

    struct Object *bully = player->interactObj;

    //! Conversion ratios multiply to more than 1 (could allow unbounded speed
    // with bonk cancel - but this isn't important for regular bully battery)
    f32 bullyToPlayerRatio = bully->hitboxRadius * 3 / 53;
    f32 playerToBullyRatio = 53.0f / bully->hitboxRadius;

    init_bully_collision_data(&playerData, player->pos[0], player->pos[2], player->forwardVel,
                              player->faceAngle[1], bullyToPlayerRatio, 52.0f);

    init_bully_collision_data(&bullyData, bully->oPosX, bully->oPosZ, bully->oForwardVel,
                              bully->oMoveAngleYaw, playerToBullyRatio, bully->hitboxRadius + 2.0f);

    if (player->forwardVel != 0.0f) {
        transfer_bully_speed(&playerData, &bullyData);
    } else {
        transfer_bully_speed(&bullyData, &playerData);
    }

    newPlayerYaw = atan2s(playerData.velZ, playerData.velX);
    newBullyYaw = atan2s(bullyData.velZ, bullyData.velX);

    playerDYaw = newPlayerYaw - player->faceAngle[1];
    bullyDYaw = newBullyYaw - bully->oMoveAngleYaw;

    player->faceAngle[1] = newPlayerYaw;
    player->forwardVel = sqrtf(playerData.velX * playerData.velX + playerData.velZ * playerData.velZ);
    player->pos[0] = playerData.posX;
    player->pos[2] = playerData.posZ;

    bully->oMoveAngleYaw = newBullyYaw;
    bully->oForwardVel = sqrtf(bullyData.velX * bullyData.velX + bullyData.velZ * bullyData.velZ);
    bully->oPosX = bullyData.posX;
    bully->oPosZ = bullyData.posZ;

    if (playerDYaw < -0x4000 || playerDYaw > 0x4000) {
        player->faceAngle[1] += 0x8000;
        player->forwardVel *= -1.0f;

        if (player->action & ACT_FLAG_AIR) {
            bonkAction = ACT_BACKWARD_AIR_KB;
        } else {
            bonkAction = ACT_SOFT_BACKWARD_GROUND_KB;
        }
    } else {
        if (player->action & ACT_FLAG_AIR) {
            bonkAction = ACT_FORWARD_AIR_KB;
        } else {
            bonkAction = ACT_SOFT_FORWARD_GROUND_KB;
        }
    }

    return bonkAction;
}

void bounce_off_object(struct PlayerState *m, struct Object *o, f32 velY) {
    m->pos[1] = o->oPosY + o->hitboxHeight;
    m->vel[1] = velY;

    m->flags &= ~PLAYER_UNKNOWN_08;

    play_sound(SOUND_ACTION_BOUNCE_OFF_OBJECT, m->playerObj->header.gfx.cameraToObject);
}

void hit_object_from_below(struct PlayerState *m, UNUSED struct Object *o) {
    m->vel[1] = 0.0f;
    set_camera_shake_from_hit(SHAKE_HIT_FROM_BELOW);
}

UNUSED static u32 unused_determine_knockback_action(struct PlayerState *m) {
    u32 bonkAction;
    s16 angleToObject = player_obj_angle_to_object(m, m->interactObj);
    s16 facingDYaw = angleToObject - m->faceAngle[1];

    if (m->forwardVel < 16.0f) {
        m->forwardVel = 16.0f;
    }

    m->faceAngle[1] = angleToObject;

    if (facingDYaw >= -0x4000 && facingDYaw <= 0x4000) {
        m->forwardVel *= -1.0f;
        if (m->action & (ACT_FLAG_AIR | ACT_FLAG_ON_POLE | ACT_FLAG_HANGING)) {
            bonkAction = ACT_BACKWARD_AIR_KB;
        } else {
            bonkAction = ACT_SOFT_BACKWARD_GROUND_KB;
        }
    } else {
        m->faceAngle[1] += 0x8000;
        if (m->action & (ACT_FLAG_AIR | ACT_FLAG_ON_POLE | ACT_FLAG_HANGING)) {
            bonkAction = ACT_FORWARD_AIR_KB;
        } else {
            bonkAction = ACT_SOFT_FORWARD_GROUND_KB;
        }
    }

    return bonkAction;
}

u32 determine_knockback_action(struct PlayerState *m, UNUSED s32 arg) {
    u32 bonkAction;

    s16 terrainIndex = 0; // 1 = air, 2 = water, 0 = default
    s16 strengthIndex = 0;

    s16 angleToObject = player_obj_angle_to_object(m, m->interactObj);
    s16 facingDYaw = angleToObject - m->faceAngle[1];
    s16 remainingHealth = m->health - 0x40 * m->hurtCounter;

    if (m->action & (ACT_FLAG_SWIMMING | ACT_FLAG_METAL_WATER)) {
        terrainIndex = 2;
    } else if (m->action & (ACT_FLAG_AIR | ACT_FLAG_ON_POLE | ACT_FLAG_HANGING)) {
        terrainIndex = 1;
    }

    if (remainingHealth < 0x100) {
        strengthIndex = 2;
    } else if (m->interactObj->oDamageOrCoinValue >= 4) {
        strengthIndex = 2;
    } else if (m->interactObj->oDamageOrCoinValue >= 2) {
        strengthIndex = 1;
    }

    m->faceAngle[1] = angleToObject;

    if (terrainIndex == 2) {
        if (m->forwardVel < 28.0f) {
            player_set_forward_vel(m, 28.0f);
        }

        if (m->pos[1] >= m->interactObj->oPosY) {
            if (m->vel[1] < 20.0f) {
                m->vel[1] = 20.0f;
            }
        } else {
            if (m->vel[1] > 0.0f) {
                m->vel[1] = 0.0f;
            }
        }
    } else {
        if (m->forwardVel < 16.0f) {
            player_set_forward_vel(m, 16.0f);
        }
    }

    if (-0x4000 <= facingDYaw && facingDYaw <= 0x4000) {
        m->forwardVel *= -1.0f;
        bonkAction = sBackwardKnockbackActions[terrainIndex][strengthIndex];
    } else {
        m->faceAngle[1] += 0x8000;
        bonkAction = sForwardKnockbackActions[terrainIndex][strengthIndex];
    }

    return bonkAction;
}

void push_player_out_of_object(struct PlayerState *m, struct Object *o, f32 padding) {
    f32 minDistance = o->hitboxRadius + m->playerObj->hitboxRadius + padding;

    f32 offsetX = m->pos[0] - o->oPosX;
    f32 offsetZ = m->pos[2] - o->oPosZ;
    f32 distance = sqrtf(offsetX * offsetX + offsetZ * offsetZ);

    if (distance < minDistance) {
        struct Surface *floor;
        s16 pushAngle;
        f32 newPlayerX;
        f32 newPlayerZ;

        if (distance == 0.0f) {
            pushAngle = m->faceAngle[1];
        } else {
            pushAngle = atan2s(offsetZ, offsetX);
        }

        newPlayerX = o->oPosX + minDistance * sins(pushAngle);
        newPlayerZ = o->oPosZ + minDistance * coss(pushAngle);

        f32_find_wall_collision(&newPlayerX, &m->pos[1], &newPlayerZ, 60.0f, 50.0f);

#if FIX_PUSH_MARIO_OUT_OF_OBJECT_FLOOR
        f32 floorHeight =
#endif
        find_floor(newPlayerX, m->pos[1], newPlayerZ, &floor);
        if (floor != NULL) {
            //! Doesn't update Player's referenced floor (allows oob death when
            // an object pushes you into a steep slope while in a ground action)
            m->pos[0] = newPlayerX;
            m->pos[2] = newPlayerZ;
#if FIX_PUSH_MARIO_OUT_OF_OBJECT_FLOOR
            m->floor       = floor;
            m->floorHeight = floorHeight;
#endif
        }
    }
}

void bounce_back_from_attack(struct PlayerState *m, u32 interaction) {
    if (interaction & (INT_PUNCH | INT_KICK | INT_TRIP)) {
        if (m->action == ACT_PUNCHING) {
            m->action = ACT_MOVE_PUNCHING;
        }

        if (m->action & ACT_FLAG_AIR) {
            player_set_forward_vel(m, -16.0f);
        } else {
            player_set_forward_vel(m, -48.0f);
        }

        set_camera_shake_from_hit(SHAKE_ATTACK);
        m->particleFlags |= PARTICLE_TRIANGLE;
    }

    if (interaction & (INT_PUNCH | INT_KICK | INT_TRIP | INT_FAST_ATTACK_OR_SHELL)) {
        play_sound(SOUND_ACTION_HIT_2, m->playerObj->header.gfx.cameraToObject);
    }
}

u32 should_push_or_pull_door(struct PlayerState *m, struct Object *obj) {
    f32 dx = obj->oPosX - m->pos[0];
    f32 dz = obj->oPosZ - m->pos[2];

    s16 dYaw = abs_angle_diff(obj->oMoveAngleYaw, atan2s(dz, dx));

    return (dYaw <= 0x4000) ? WARP_FLAG_DOOR_PULLED : WARP_FLAG_DOOR_FLIP_MARIO;
}

u32 take_damage_from_interact_object(struct PlayerState *m) {
    s32 shake;
    s32 damage = m->interactObj->oDamageOrCoinValue;

    if (damage >= 4) {
        shake = SHAKE_LARGE_DAMAGE;
    } else if (damage >= 2) {
        shake = SHAKE_MED_DAMAGE;
    } else {
        shake = SHAKE_SMALL_DAMAGE;
    }

    if (!(m->flags & PLAYER_CAP_ON_HEAD)) {
        damage += (damage + 1) / 2;
    }

    if (m->flags & PLAYER_METAL_CAP) {
        damage = 0;
    }

    m->hurtCounter += 4 * damage;
#ifdef RUMBLE_FEEDBACK
    queue_rumble_data(5, 80);
#endif    
    set_camera_shake_from_hit(shake);

    return damage;
}

u32 take_damage_and_knock_back(struct PlayerState *m, struct Object *o) {
    u32 damage;

    if (!sInvulnerable && !(m->flags & PLAYER_VANISH_CAP)
        && !(o->oInteractionSubtype & INT_SUBTYPE_DELAY_INVINCIBILITY)) {
        o->oInteractStatus = INT_STATUS_INTERACTED | INT_STATUS_ATTACKED_PLAYER;
        m->interactObj = o;

        damage = take_damage_from_interact_object(m);

        if (o->oInteractionSubtype & INT_SUBTYPE_BIG_KNOCKBACK) {
            m->forwardVel = 40.0f;
        }

        if (o->oDamageOrCoinValue > 0) {
            play_character_sound(m, CHAR_SOUND_ATTACKED);
        }

        update_player_sound_and_camera(m);
        return drop_and_set_player_action(m, determine_knockback_action(m, o->oDamageOrCoinValue),
                                         damage);
    }

    return FALSE;
}

void reset_player_pitch(struct PlayerState *m) {
    if (m->action == ACT_WATER_JUMP || m->action == ACT_SHOT_FROM_CANNON || m->action == ACT_FLYING) {
        set_camera_mode(m->area->camera, m->area->camera->defMode, 1);
        m->faceAngle[0] = 0;
    }
}

u32 interact_coin(struct PlayerState *m, UNUSED u32 interactType, struct Object *o) {
    m->numCoins += o->oDamageOrCoinValue;
    m->healCounter += 4 * o->oDamageOrCoinValue;

    o->oInteractStatus = INT_STATUS_INTERACTED;

    if (COURSE_IS_MAIN_COURSE(gCurrCourseNum)
        && m->numCoins - o->oDamageOrCoinValue < COINS_REQ_COINSTAR && m->numCoins >= COINS_REQ_COINSTAR) {
        bhv_spawn_star_no_level_exit(STAR_INDEX_100_COINS);
    }

#ifdef RUMBLE_FEEDBACK
    if (o->oDamageOrCoinValue >= 2) {
        queue_rumble_data(5, 80);
    }
#endif
    return FALSE;
}

u32 interact_water_ring(struct PlayerState *m, UNUSED u32 interactType, struct Object *o) {
    m->healCounter += 4 * o->oDamageOrCoinValue;
    o->oInteractStatus = INT_STATUS_INTERACTED;
    return FALSE;
}

u32 interact_star_or_key(struct PlayerState *m, UNUSED u32 interactType, struct Object *o) {
    u32 starIndex;
    u32 starGrabAction = ACT_STAR_DANCE_EXIT;
    u32 noExit = (o->oInteractionSubtype & INT_SUBTYPE_NO_EXIT) != 0;
    u32 grandStar = (o->oInteractionSubtype & INT_SUBTYPE_GRAND_STAR) != 0;

    if (m->health >= 0x100) {
        player_stop_riding_and_holding(m);
#ifdef RUMBLE_FEEDBACK
        queue_rumble_data(5, 80);
#endif
        if (!noExit) {
            m->hurtCounter = 0;
            m->healCounter = 0;
            if (m->capTimer > 1) {
                m->capTimer = 1;
            }
        } else {
            starGrabAction = ACT_STAR_DANCE_NO_EXIT;
        }

        if (m->action & ACT_FLAG_SWIMMING) {
            starGrabAction = ACT_STAR_DANCE_WATER;
        }

        if (m->action & ACT_FLAG_METAL_WATER) {
            starGrabAction = ACT_STAR_DANCE_WATER;
        }

        if (m->action & ACT_FLAG_AIR) {
            starGrabAction = ACT_FALL_AFTER_STAR_GRAB;
        }

        spawn_object(o, MODEL_NONE, bhvStarKeyCollectionPuffSpawner);

        o->oInteractStatus = INT_STATUS_INTERACTED;
        m->interactObj = o;
        m->usedObj = o;

        starIndex = (o->oBhvParams >> 24) & 0x1F;
        save_file_collect_star_or_key(m->numCoins, starIndex);

        m->numStars =
            save_file_get_total_star_count(gCurrSaveFileNum - 1, COURSE_MIN - 1, COURSE_MAX - 1);

        if (!noExit) {
            drop_queued_background_music();
            fadeout_level_music(126);
        }

        play_sound(SOUND_MENU_STAR_SOUND, m->playerObj->header.gfx.cameraToObject);
        update_player_sound_and_camera(m);

        if (grandStar) {
            return set_player_action(m, ACT_JUMBO_STAR_CUTSCENE, 0);
        }

        return set_player_action(m, starGrabAction, noExit + 2 * grandStar);
    }

    return FALSE;
}

u32 interact_bbh_entrance(struct PlayerState *m, UNUSED u32 interactType, struct Object *o) {
    if (m->action != ACT_BBH_ENTER_SPIN && m->action != ACT_BBH_ENTER_JUMP) {
        player_stop_riding_and_holding(m);

        o->oInteractStatus = INT_STATUS_INTERACTED;
        m->interactObj = o;
        m->usedObj = o;

        if (m->action & ACT_FLAG_AIR) {
            return set_player_action(m, ACT_BBH_ENTER_SPIN, 0);
        }

        return set_player_action(m, ACT_BBH_ENTER_JUMP, 0);
    }

    return FALSE;
}

u32 interact_warp(struct PlayerState *m, UNUSED u32 interactType, struct Object *o) {
    u32 action;

    if (o->oInteractionSubtype & INT_SUBTYPE_FADING_WARP) {
        action = m->action;

        if (action == ACT_TELEPORT_FADE_IN) {
            sJustTeleported = TRUE;

        } else if (!sJustTeleported) {
            if (action == ACT_IDLE || action == ACT_PANTING || action == ACT_STANDING_AGAINST_WALL
                || action == ACT_CROUCHING) {
                m->interactObj = o;
                m->usedObj = o;

                sJustTeleported = TRUE;
                return set_player_action(m, ACT_TELEPORT_FADE_OUT, 0);
            }
        }
    } else {
        if (m->action != ACT_EMERGE_FROM_PIPE) {
            o->oInteractStatus = INT_STATUS_INTERACTED;
            m->interactObj = o;
            m->usedObj = o;

            // ex-alo change
            // replaces check to behavior so collision can be freely replaced
            // without changing pipe sound effect
            u32 isWarpPipe = obj_has_behavior(o, bhvWarpPipe);
            play_sound(isWarpPipe ? SOUND_MENU_ENTER_PIPE : SOUND_MENU_ENTER_HOLE, m->playerObj->header.gfx.cameraToObject);
#ifdef RUMBLE_FEEDBACK           
            queue_rumble_data(isWarpPipe ? 15 : 12, 80);
#endif

            player_stop_riding_object(m);
            return set_player_action(m, ACT_DISAPPEARED, (WARP_OP_WARP_OBJECT << 16) + 2);
        }
    }

    return FALSE;
}

// Todo, rewrite this to work just like ds
u32 interact_warp_door(struct PlayerState *m, UNUSED u32 interactType, struct Object *o) {
    u32 doorAction = 0;
    u32 saveFlags = save_file_get_flags();
    s16 warpDoorId = o->oBhvParams >> 24;
    u32 actionArg;

    if (m->action == ACT_WALKING || m->action == ACT_DECELERATING) {
        if (warpDoorId == 1 && !(saveFlags & SAVE_FLAG_UNLOCKED_UPSTAIRS_DOOR)) {
            if (!(saveFlags & SAVE_FLAG_HAVE_KEY_2)) {
                if (!sDisplayingDoorText) {
                    set_player_action(m, ACT_READING_AUTOMATIC_DIALOG,
                                     (saveFlags & SAVE_FLAG_HAVE_KEY_1) ? DIALOG_023 : DIALOG_022);
                }
                sDisplayingDoorText = TRUE;

                return FALSE;
            }

            doorAction = ACT_UNLOCKING_KEY_DOOR;
        }

        if (warpDoorId == 2 && !(saveFlags & SAVE_FLAG_UNLOCKED_BASEMENT_DOOR)) {
            if (!(saveFlags & SAVE_FLAG_HAVE_KEY_1)) {
                if (!sDisplayingDoorText) {
                    // Moat door skip was intended confirmed
                    set_player_action(m, ACT_READING_AUTOMATIC_DIALOG,
                                     (saveFlags & SAVE_FLAG_HAVE_KEY_2) ? DIALOG_023 : DIALOG_022);
                }
                sDisplayingDoorText = TRUE;

                return FALSE;
            }

            doorAction = ACT_UNLOCKING_KEY_DOOR;
        }

        if (warpDoorId == 3 && !(saveFlags & SAVE_FLAG_UNLOCKED_CASTLE_DOOR)) {
            if (!(saveFlags & SAVE_FLAG_HAVE_KEY_BUNNY)) {
                if (!sDisplayingDoorText) {
                    set_player_action(m, ACT_READING_AUTOMATIC_DIALOG, (saveFlags & SAVE_FLAG_HAVE_KEY_2) ? DIALOG_170 : DIALOG_170);
                }
                sDisplayingDoorText = TRUE;

                return FALSE;
            }

            doorAction = ACT_UNLOCKING_KEY_DOOR;
        }

        if (m->action == ACT_WALKING || m->action == ACT_DECELERATING) {
            actionArg = should_push_or_pull_door(m, o) + WARP_FLAG_DOOR_IS_WARP;

            if (doorAction == 0) {
                if (actionArg & WARP_FLAG_DOOR_PULLED) {
                    doorAction = ACT_PULLING_DOOR;
                } else {
                    doorAction = ACT_PUSHING_DOOR;
                }
            }

            m->interactObj = o;
            m->usedObj = o;
            return set_player_action(m, doorAction, actionArg);
        }
    }

    return FALSE;
}

u32 get_door_save_file_flag(struct Object *door) {
    u32 saveFileFlag = 0;
    s16 requiredNumStars = door->oBhvParams >> 24;

    s16 isCCMDoor = door->oPosX < 0.0f;
    s16 isPSSDoor = door->oPosY > 500.0f;

    switch (requiredNumStars) {
        case 1:
            if (isPSSDoor) {
                saveFileFlag = SAVE_FLAG_UNLOCKED_PSS_DOOR;
            } else {
                saveFileFlag = SAVE_FLAG_UNLOCKED_WF_DOOR;
            }
            break;

        case 3:
            if (isCCMDoor) {
                saveFileFlag = SAVE_FLAG_UNLOCKED_CCM_DOOR;
            } else {
                saveFileFlag = SAVE_FLAG_UNLOCKED_JRB_DOOR;
            }
            break;

        case 8:
            saveFileFlag = SAVE_FLAG_UNLOCKED_BITDW_DOOR;
            break;

        case 30:
            saveFileFlag = SAVE_FLAG_UNLOCKED_BITFS_DOOR;
            break;

        case 50:
            saveFileFlag = SAVE_FLAG_UNLOCKED_50_STAR_DOOR;
            break;
    }

    return saveFileFlag;
}

u32 interact_door(struct PlayerState *m, UNUSED u32 interactType, struct Object *o) {
    s16 requiredNumStars = o->oBhvParams >> 24;
    s16 numStars = save_file_get_total_star_count(gCurrSaveFileNum - 1, COURSE_MIN - 1, COURSE_MAX - 1);

    if (m->action == ACT_WALKING || m->action == ACT_DECELERATING) {
        if (numStars >= requiredNumStars) {
            u32 actionArg = should_push_or_pull_door(m, o);
            u32 enterDoorAction;
            u32 doorSaveFileFlag;

            if (actionArg & WARP_FLAG_DOOR_PULLED) {
                enterDoorAction = ACT_PULLING_DOOR;
            } else {
                enterDoorAction = ACT_PUSHING_DOOR;
            }

            doorSaveFileFlag = get_door_save_file_flag(o);
            m->interactObj = o;
            m->usedObj = o;

            if (o->oInteractionSubtype & INT_SUBTYPE_STAR_DOOR) {
                enterDoorAction = ACT_ENTERING_STAR_DOOR;
            }

            if (doorSaveFileFlag != 0 && !(save_file_get_flags() & doorSaveFileFlag)) {
                enterDoorAction = ACT_UNLOCKING_STAR_DOOR;
            }

            return set_player_action(m, enterDoorAction, actionArg);
        } else if (!sDisplayingDoorText) {
            u32 text = DIALOG_022 << 16;

            switch (requiredNumStars) {
                case 1:
                    text = DIALOG_024 << 16;
                    break;
                case 3:
                    text = DIALOG_025 << 16;
                    break;
                case 8:
                    text = DIALOG_026 << 16;
                    break;
                case 30:
                    text = DIALOG_027 << 16;
                    break;
                case 50:
                    text = DIALOG_028 << 16;
                    break;
                case 70:
                    text = DIALOG_029 << 16;
                    break;
            }

            text += requiredNumStars - numStars;

            sDisplayingDoorText = TRUE;
            return set_player_action(m, ACT_READING_AUTOMATIC_DIALOG, text);
        }
    } else if (m->action == ACT_IDLE && sDisplayingDoorText == TRUE && requiredNumStars == 70) {
        m->interactObj = o;
        m->usedObj = o;
        return set_player_action(m, ACT_ENTERING_STAR_DOOR, should_push_or_pull_door(m, o));
    }

    return FALSE;
}

u32 interact_cannon_base(struct PlayerState *m, UNUSED u32 interactType, struct Object *o) {
    if (m->action != ACT_IN_CANNON) {
        player_stop_riding_and_holding(m);
        o->oInteractStatus = INT_STATUS_INTERACTED;
        m->interactObj = o;
        m->usedObj = o;
        return set_player_action(m, ACT_IN_CANNON, 0);
    }

    return FALSE;
}

u32 interact_igloo_barrier(struct PlayerState *m, UNUSED u32 interactType, struct Object *o) {
    //! Sets used object without changing action (LOTS of interesting glitches,
    // but unfortunately the igloo barrier is the only object with this interaction
    // type)
    m->interactObj = o;
    m->usedObj = o;
    push_player_out_of_object(m, o, 5.0f);
    return FALSE;
}

u32 interact_tornado(struct PlayerState *m, UNUSED u32 interactType, struct Object *o) {
    struct Object *playerObj = m->playerObj;

    if (m->action != ACT_TORNADO_TWIRLING && m->action != ACT_SQUISHED) {
        player_stop_riding_and_holding(m);
        player_set_forward_vel(m, 0.0f);
        update_player_sound_and_camera(m);

        o->oInteractStatus = INT_STATUS_INTERACTED;
        m->interactObj = o;
        m->usedObj = o;

        playerObj->oPlayerTornadoYawVel = 0x400;
        playerObj->oPlayerTornadoPosY = m->pos[1] - o->oPosY;

        play_character_sound(m, CHAR_SOUND_WAAAOOOW);
#ifdef RUMBLE_FEEDBACK  
        queue_rumble_data(30, 60);
#endif
        
        return set_player_action(m, ACT_TORNADO_TWIRLING, m->action == ACT_TWIRLING);
    }

    return FALSE;
}

u32 interact_whirlpool(struct PlayerState *m, UNUSED u32 interactType, struct Object *o) {
    struct Object *playerObj = m->playerObj;

    if (m->action != ACT_CAUGHT_IN_WHIRLPOOL) {
        player_stop_riding_and_holding(m);
        o->oInteractStatus = INT_STATUS_INTERACTED;
        m->interactObj = o;
        m->usedObj = o;

        m->forwardVel = 0.0f;

        playerObj->oPlayerWhirlpoolPosY = m->pos[1] - o->oPosY;

        play_character_sound(m, CHAR_SOUND_WAAAOOOW);
#ifdef RUMBLE_FEEDBACK  
        queue_rumble_data(30, 60);
#endif
        
        return set_player_action(m, ACT_CAUGHT_IN_WHIRLPOOL, 0);
    }

    return FALSE;
}

u32 interact_strong_wind(struct PlayerState *m, UNUSED u32 interactType, struct Object *o) {
    UNUSED struct Object *playerObj = m->playerObj;

    if (m->action != ACT_GETTING_BLOWN) {
        player_stop_riding_and_holding(m);
        o->oInteractStatus = INT_STATUS_INTERACTED;
        m->interactObj = o;
        m->usedObj = o;

        m->faceAngle[1] = o->oMoveAngleYaw + 0x8000;
        m->gettingBlownGravity = 0.4f;
        m->forwardVel = -24.0f;
        m->vel[1] = 12.0f;

        play_character_sound(m, CHAR_SOUND_WAAAOOOW);
        update_player_sound_and_camera(m);
        return set_player_action(m, ACT_GETTING_BLOWN, 0);
    }

    return FALSE;
}

u32 interact_flame(struct PlayerState *m, UNUSED u32 interactType, struct Object *o) {
    u32 burningAction = ACT_BURNING_JUMP;

    if (!sInvulnerable && !(m->flags & PLAYER_METAL_CAP) && !(m->flags & PLAYER_VANISH_CAP)
        && !(o->oInteractionSubtype & INT_SUBTYPE_DELAY_INVINCIBILITY)) {
#ifdef RUMBLE_FEEDBACK
        queue_rumble_data(5, 80);
#endif
        o->oInteractStatus = INT_STATUS_INTERACTED;
        m->interactObj = o;

        if ((m->action & (ACT_FLAG_SWIMMING | ACT_FLAG_METAL_WATER))
            || m->waterLevel - m->pos[1] > 50.0f) {
            play_sound(SOUND_GENERAL_FLAME_OUT, m->playerObj->header.gfx.cameraToObject);
        } else {
            m->playerObj->oPlayerBurnTimer = 0;
            update_player_sound_and_camera(m);
            play_sound(SOUND_MARIO_ON_FIRE, m->playerObj->header.gfx.cameraToObject);

            if ((m->action & ACT_FLAG_AIR) && m->vel[1] <= 0.0f) {
                burningAction = ACT_BURNING_FALL;
            }

            return drop_and_set_player_action(m, burningAction, 1);
        }
    }

    return FALSE;
}

u32 interact_snufit_bullet(struct PlayerState *m, UNUSED u32 interactType, struct Object *o) {
    if (!sInvulnerable && !(m->flags & PLAYER_VANISH_CAP)) {
        if (m->flags & PLAYER_METAL_CAP) {
            o->oInteractStatus = INT_STATUS_INTERACTED | INT_STATUS_WAS_ATTACKED;
            play_sound(SOUND_ACTION_SNUFFIT_BULLET_HIT_METAL, m->playerObj->header.gfx.cameraToObject);
        } else {
            o->oInteractStatus = INT_STATUS_INTERACTED | INT_STATUS_ATTACKED_PLAYER;
            m->interactObj = o;
            take_damage_from_interact_object(m);

            play_sound(SOUND_MARIO_ATTACKED, m->playerObj->header.gfx.cameraToObject);
            update_player_sound_and_camera(m);

            return drop_and_set_player_action(m, determine_knockback_action(m, o->oDamageOrCoinValue),
                                             o->oDamageOrCoinValue);
        }
    }

    if (!(o->oInteractionSubtype & INT_SUBTYPE_DELAY_INVINCIBILITY)) {
        sDelayInvincTimer = TRUE;
    }

    return FALSE;
}

u32 interact_clam_or_bubba(struct PlayerState *m, UNUSED u32 interactType, struct Object *o) {
    if (o->oInteractionSubtype & INT_SUBTYPE_EATS_PLAYER) {
        o->oInteractStatus = INT_STATUS_INTERACTED;
        m->interactObj = o;
        return set_player_action(m, ACT_EATEN_BY_BUBBA, 0);
    } else if (take_damage_and_knock_back(m, o)) {
        return TRUE;
    }

    if (!(o->oInteractionSubtype & INT_SUBTYPE_DELAY_INVINCIBILITY)) {
        sDelayInvincTimer = TRUE;
    }

    return TRUE;
}

u32 interact_bully(struct PlayerState *m, UNUSED u32 interactType, struct Object *o) {
    UNUSED u8 filler[4];

    u32 interaction;
    if (m->flags & PLAYER_METAL_CAP) {
        interaction = INT_FAST_ATTACK_OR_SHELL;
    } else {
        interaction = determine_interaction(m, o);
    }

    m->interactObj = o;

    if (interaction & INT_ATTACK_NOT_FROM_BELOW) {
#ifdef RUMBLE_FEEDBACK
        queue_rumble_data(5, 80);
#endif
        push_player_out_of_object(m, o, 5.0f);

        m->forwardVel = -16.0f;
        o->oMoveAngleYaw = m->faceAngle[1];
        o->oForwardVel = 3392.0f / o->hitboxRadius;

        attack_object(o, interaction);
        bounce_back_from_attack(m, interaction);
        return TRUE;
    }

    else if (!sInvulnerable && !(m->flags & PLAYER_VANISH_CAP)
             && !(o->oInteractionSubtype & INT_SUBTYPE_DELAY_INVINCIBILITY)) {
        o->oInteractStatus = INT_STATUS_INTERACTED;
        m->invincTimer = 2;

        update_player_sound_and_camera(m);
        play_sound(SOUND_MARIO_EEUH, m->playerObj->header.gfx.cameraToObject);
        play_sound(SOUND_OBJ_BULLY_METAL, m->playerObj->header.gfx.cameraToObject);

        push_player_out_of_object(m, o, 5.0f);
        drop_and_set_player_action(m, bully_knock_back_player(m), 0);
#ifdef RUMBLE_FEEDBACK
        queue_rumble_data(5, 80);
#endif
        return TRUE;
    }

    return FALSE;
}

u32 interact_shock(struct PlayerState *m, UNUSED u32 interactType, struct Object *o) {
    if (!sInvulnerable && !(m->flags & PLAYER_VANISH_CAP)
        && !(o->oInteractionSubtype & INT_SUBTYPE_DELAY_INVINCIBILITY)) {
        u32 actionArg = (m->action & (ACT_FLAG_AIR | ACT_FLAG_ON_POLE | ACT_FLAG_HANGING)) == 0;

        o->oInteractStatus = INT_STATUS_INTERACTED | INT_STATUS_ATTACKED_PLAYER;
        m->interactObj = o;

        take_damage_from_interact_object(m);
        play_sound(SOUND_MARIO_ATTACKED, m->playerObj->header.gfx.cameraToObject);
#ifdef RUMBLE_FEEDBACK
        queue_rumble_data(70, 60);
#endif
        if (m->action & (ACT_FLAG_SWIMMING | ACT_FLAG_METAL_WATER)) {
            return drop_and_set_player_action(m, ACT_WATER_SHOCKED, 0);
        } else {
            update_player_sound_and_camera(m);
            return drop_and_set_player_action(m, ACT_SHOCKED, actionArg);
        }
    }

    if (!(o->oInteractionSubtype & INT_SUBTYPE_DELAY_INVINCIBILITY)) {
        sDelayInvincTimer = TRUE;
    }

    return FALSE;
}

UNUSED static u32 interact_stub(UNUSED struct PlayerState *m, UNUSED u32 interactType, struct Object *o) {
    if (!(o->oInteractionSubtype & INT_SUBTYPE_DELAY_INVINCIBILITY)) {
        sDelayInvincTimer = TRUE;
    }
    return FALSE;
}

u32 interact_mr_blizzard(struct PlayerState *m, UNUSED u32 interactType, struct Object *o) {
    if (take_damage_and_knock_back(m, o)) {
        return TRUE;
    }

    if (!(o->oInteractionSubtype & INT_SUBTYPE_DELAY_INVINCIBILITY)) {
        sDelayInvincTimer = TRUE;
    }

    return FALSE;
}

#if TWIRL_WITH_OBJECT
#define SET_MARIO_ACT(m, a, v) set_player_action(m, a, v)
#else
#define SET_MARIO_ACT(m, a, v) drop_and_set_player_action(m, a, v)
#endif

#if JUMP_ENEMY_BOUNCE_BOOST
#define BOOST(c, t, f) ((c) ? t : f)
#else
#define BOOST(c, t, f) f
#endif
u32 interact_hit_from_below(struct PlayerState *m, UNUSED u32 interactType, struct Object *o) {
    u32 interaction;
    if (m->flags & PLAYER_METAL_CAP) {
        interaction = INT_FAST_ATTACK_OR_SHELL;
    } else {
        interaction = determine_interaction(m, o);
    }

    if (interaction & INT_ANY_ATTACK) {
#ifdef RUMBLE_FEEDBACK
        queue_rumble_data(5, 80);
#endif
        attack_object(o, interaction);
        bounce_back_from_attack(m, interaction);

        if (interaction & INT_HIT_FROM_BELOW) {
            hit_object_from_below(m, o);
        }

        if (interaction & INT_HIT_FROM_ABOVE) {
            if (o->oInteractionSubtype & INT_SUBTYPE_TWIRL_BOUNCE) {
                bounce_off_object(m, o, 80.0f);
                reset_player_pitch(m);
                play_sound(SOUND_MARIO_TWIRL_BOUNCE, m->playerObj->header.gfx.cameraToObject);
                return SET_MARIO_ACT(m, ACT_TWIRLING, 0);
            } else {
                bounce_off_object(m, o, BOOST(m->input & INPUT_A_DOWN, 50.0f, 30.0f));
            }
        }
    } else if (take_damage_and_knock_back(m, o)) {
        return TRUE;
    }

    if (!(o->oInteractionSubtype & INT_SUBTYPE_DELAY_INVINCIBILITY)) {
        sDelayInvincTimer = TRUE;
    }

    return FALSE;
}

u32 interact_bounce_top(struct PlayerState *m, UNUSED u32 interactType, struct Object *o) {
    u32 interaction;
    if (m->flags & PLAYER_METAL_CAP) {
        interaction = INT_FAST_ATTACK_OR_SHELL;
    } else {
        interaction = determine_interaction(m, o);
    }

    if (interaction & INT_ATTACK_NOT_FROM_BELOW) {
#ifdef RUMBLE_FEEDBACK
        queue_rumble_data(5, 80);
#endif
        attack_object(o, interaction);
        bounce_back_from_attack(m, interaction);

        if (interaction & INT_HIT_FROM_ABOVE) {
            if (o->oInteractionSubtype & INT_SUBTYPE_TWIRL_BOUNCE) {
                bounce_off_object(m, o, 80.0f);
                reset_player_pitch(m);
                play_sound(SOUND_MARIO_TWIRL_BOUNCE, m->playerObj->header.gfx.cameraToObject);
                return SET_MARIO_ACT(m, ACT_TWIRLING, 0);
            } else {
                bounce_off_object(m, o, BOOST(m->input & INPUT_A_DOWN, 50.0f, 30.0f));
            }
        }
    } else if (take_damage_and_knock_back(m, o)) {
        return TRUE;
    }

    if (!(o->oInteractionSubtype & INT_SUBTYPE_DELAY_INVINCIBILITY)) {
        sDelayInvincTimer = TRUE;
    }

    return FALSE;
}
#undef SET_MARIO_ACT
#undef BOOST

u32 interact_unknown_08(struct PlayerState *m, UNUSED u32 interactType, struct Object *o) {
    u32 interaction = determine_interaction(m, o);

    if (interaction & INT_PUNCH) {
        o->oInteractStatus = INT_STATUS_INTERACTED | INT_STATUS_WAS_ATTACKED | ATTACK_PUNCH;
        bounce_back_from_attack(m, interaction);
    } else if (take_damage_and_knock_back(m, o)) {
        return TRUE;
    }

    if (!(o->oInteractionSubtype & INT_SUBTYPE_DELAY_INVINCIBILITY)) {
        sDelayInvincTimer = TRUE;
    }

    return FALSE;
}

u32 interact_damage(struct PlayerState *m, UNUSED u32 interactType, struct Object *o) {
    if (take_damage_and_knock_back(m, o)) {
        return TRUE;
    }

    if (!(o->oInteractionSubtype & INT_SUBTYPE_DELAY_INVINCIBILITY)) {
        sDelayInvincTimer = TRUE;
    }

    return FALSE;
}

u32 interact_breakable(struct PlayerState *m, UNUSED u32 interactType, struct Object *o) {
    u32 interaction = determine_interaction(m, o);

    if (interaction & INT_ATTACK_NOT_WEAK_FROM_ABOVE) {
        attack_object(o, interaction);
        bounce_back_from_attack(m, interaction);

        m->interactObj = o;

        switch (interaction) {
            case INT_HIT_FROM_ABOVE:
                bounce_off_object(m, o, 30.0f); //! Not in the 0x8F mask
                break;

            case INT_HIT_FROM_BELOW:
                hit_object_from_below(m, o);
                break;
        }

        return TRUE;
    }

    return FALSE;
}

u32 interact_koopa_shell(struct PlayerState *m, UNUSED u32 interactType, struct Object *o) {
    if (!(m->action & ACT_FLAG_RIDING_SHELL)) {
        u32 interaction = determine_interaction(m, o);

        if (interaction == INT_HIT_FROM_ABOVE || m->action == ACT_WALKING
            || m->action == ACT_HOLD_WALKING) {
            m->interactObj = o;
            m->usedObj = o;
            m->riddenObj = o;

            attack_object(o, interaction);
            update_player_sound_and_camera(m);
            play_shell_music();
            player_drop_held_object(m);

#if FIX_MARIO_KOOPA_SHELL_ACTION
            return set_player_action(m, (m->action & ACT_FLAG_AIR) ? ACT_RIDING_SHELL_FALL : ACT_RIDING_SHELL_GROUND, 0);
#else            
            //! Puts Player in ground action even when in air, making it easy to
            // escape air actions into crouch slide (shell cancel)
            return set_player_action(m, ACT_RIDING_SHELL_GROUND, 0);
#endif
        }

        push_player_out_of_object(m, o, 2.0f);
    }

    return FALSE;
}

u32 check_object_grab_player(struct PlayerState *m, UNUSED u32 interactType, struct Object *o) {
    if ((!(m->action & (ACT_FLAG_AIR | ACT_FLAG_INVULNERABLE | ACT_FLAG_ATTACKING)) || !sInvulnerable)
        && (o->oInteractionSubtype & INT_SUBTYPE_GRABS_PLAYER)) {
        if (object_facing_player(m, o, 0x2AAA)) {
            player_stop_riding_and_holding(m);
            o->oInteractStatus = INT_STATUS_INTERACTED | INT_STATUS_GRABBED_PLAYER;

            m->faceAngle[1] = o->oMoveAngleYaw;
            m->interactObj = o;
            m->usedObj = o;

            update_player_sound_and_camera(m);
            play_sound(SOUND_MARIO_OOOF, m->playerObj->header.gfx.cameraToObject);
#ifdef RUMBLE_FEEDBACK
            queue_rumble_data(5, 80);
#endif
            return set_player_action(m, ACT_GRABBED, 0);
        }
    }

    push_player_out_of_object(m, o, -5.0f);
    return FALSE;
}

u32 interact_pole(struct PlayerState *m, UNUSED u32 interactType, struct Object *o) {
    s32 actionId = m->action & ACT_ID_MASK;
    if (actionId >= 0x080 && actionId < 0x0A0) {
        if (!(m->prevAction & ACT_FLAG_ON_POLE) || m->usedObj != o) {
            u32 lowSpeed = (m->forwardVel <= 10.0f);

            //! @bug Using m->forwardVel here is assumed to be 0.0f due to the set from earlier.
            //       This is fixed in the Shindou version. 
#if BUGFIX_PRESERVE_VEL_POLE
            m->playerObj->oPlayerPoleYawVel = (s32)(m->forwardVel * 0x100 + 0x1000);
#else
            m->playerObj->oPlayerPoleYawVel = 0x1000;
#endif

            player_stop_riding_and_holding(m);

            m->interactObj = o;
            m->usedObj = o;
            m->vel[1] = 0.0f;
            m->forwardVel = 0.0f;

#if FIX_POLE_BOTTOM_GRAB
            // Check for a floor on the pole.
            f32 height = find_floor(o->oPosX, m->pos[1], o->oPosZ, &o->oFloor);
            o->oFloorHeight = height;
            // Player's original Y position when grabbing the pole, above the floor.
            height = MAX(m->pos[1], height);
            if (height < o->oPosY) {
                // If Player is beneath the pole, clamp player's position to the relative pole bottom (pole fix).
                m->playerObj->oPlayerPolePos = -o->hitboxDownOffset - 100.0f;
            } else {
                // Otherwise, use the relative height on the pole.
                m->playerObj->oPlayerPolePos = height - o->oPosY;
            }
#else
            m->playerObj->oPlayerPoleUnk108 = 0;
            m->playerObj->oPlayerPoleYawVel = 0;
            m->playerObj->oPlayerPolePos = m->pos[1] - o->oPosY;
#endif

            if (lowSpeed) {
                return set_player_action(m, ACT_GRAB_POLE_SLOW, 0);
            }

            reset_player_pitch(m);
#ifdef RUMBLE_FEEDBACK
            queue_rumble_data(5, 80);
#endif
            return set_player_action(m, ACT_GRAB_POLE_FAST, 0);
        }
    }

    return FALSE;
}

u32 interact_hoot(struct PlayerState *m, UNUSED u32 interactType, struct Object *o) {
    s32 actionId = m->action & ACT_ID_MASK;

    //! Can pause to advance the global timer without falling too far, allowing
    // you to regrab after letting go.
    if (actionId >= 0x080 && actionId < 0x098
        && (gGlobalTimer - m->usedObj->oHootPlayerReleaseTime > 30)) {
        player_stop_riding_and_holding(m);

        o->oInteractStatus = TRUE; //! Note: Not a flag, treated as a TRUE/FALSE statement
        m->interactObj = o;
        m->usedObj = o;
#ifdef RUMBLE_FEEDBACK
        queue_rumble_data(5, 80);
#endif
        update_player_sound_and_camera(m);
        return set_player_action(m, ACT_RIDING_HOOT, 0);
    }

    return FALSE;
}

extern void cutscene_put_cap_on(struct PlayerState *m);

u32 interact_cap(struct PlayerState *m, UNUSED u32 interactType, struct Object *o) {
    u32 capFlag = get_player_cap_flag(o);
    u16 capMusic = 0;
    u16 capTime = 0;

    if (m->action != ACT_GETTING_BLOWN && capFlag != 0) {
        m->interactObj = o;
        o->oInteractStatus = INT_STATUS_INTERACTED;

        m->flags &= ~PLAYER_CAP_ON_HEAD & ~PLAYER_CAP_IN_HAND;
        m->flags |= capFlag;

        switch (capFlag) {
            case PLAYER_VANISH_CAP:
                capTime = VC_TIME;
                capMusic = SEQUENCE_ARGS(4, SEQ_EVENT_POWERUP);
                break;

            case PLAYER_METAL_CAP:
                capTime = MC_TIME;
                capMusic = SEQUENCE_ARGS(4, SEQ_EVENT_METAL_CAP);
                break;

            case PLAYER_WING_CAP:
                capTime = WC_TIME;
                capMusic = SEQUENCE_ARGS(4, SEQ_EVENT_POWERUP);
                break;
        }

        if (capTime > m->capTimer) {
            m->capTimer = capTime;
        }

        if ((m->action & ACT_FLAG_IDLE) || m->action == ACT_WALKING) {
            m->flags |= PLAYER_CAP_IN_HAND;
            if (configGlobalCapBlocks) {
                set_player_action(m, ACT_PUTTING_ON_CAP, 0);
            } else {
                cutscene_put_cap_on(m);
            }
        } else {
            m->flags |= PLAYER_CAP_ON_HEAD;
        }

        play_sound(SOUND_MENU_STAR_SOUND, m->playerObj->header.gfx.cameraToObject);
        play_sound(SOUND_MARIO_HERE_WE_GO, m->playerObj->header.gfx.cameraToObject);

        if (capMusic != 0) {
            play_cap_music(capMusic);
        }

        return TRUE;
    }

    return FALSE;
}

u32 interact_grabbable(struct PlayerState *m, u32 interactType, struct Object *o) {
    const BehaviorScript *script = virtual_to_segmented(0x13, o->behavior);

    if (o->oInteractionSubtype & INT_SUBTYPE_KICKABLE) {
        u32 interaction = determine_interaction(m, o);
        if (interaction & (INT_KICK | INT_TRIP)) {
            attack_object(o, interaction);
            bounce_back_from_attack(m, interaction);
            return FALSE;
        }
    }

    if ((o->oInteractionSubtype & INT_SUBTYPE_GRABS_PLAYER)) {
        if (check_object_grab_player(m, interactType, o)) {
            return TRUE;
        }
    }

    if (able_to_grab_object(m, o)) {
        if (!(o->oInteractionSubtype & INT_SUBTYPE_NOT_GRABBABLE)) {
            m->interactObj = o;
            m->input |= INPUT_INTERACT_OBJ_GRABBABLE;
            return TRUE;
        }
    }

    if (script != bhvBowser) {
        push_player_out_of_object(m, o, -5.0f);
    }

    return FALSE;
}

u32 player_can_talk(struct PlayerState *m, u32 arg) {
    s16 val6;

    if ((m->action & ACT_FLAG_IDLE) != 0x00000000) {
        return TRUE;
    }

    if (m->action == ACT_WALKING) {
        if (arg) {
            return TRUE;
        }

        val6 = m->playerObj->header.gfx.animInfo.animID;

        if (val6 == 0x0080 || val6 == 0x007F || val6 == 0x006C) {
            return TRUE;
        }
    }

    return FALSE;
}

#if FIX_INTERACT_READING_BUTTON
#define READ_MASK (INPUT_B_PRESSED)
#else
#define READ_MASK (INPUT_B_PRESSED | INPUT_A_PRESSED)
#endif

#define SIGN_RANGE 0x4000

u32 check_read_sign(struct PlayerState *m, struct Object *o) {
    if ((m->input & READ_MASK) && player_can_talk(m, 0) && object_facing_player(m, o, SIGN_RANGE)) {
        s16 facingDYaw = (s16)(o->oMoveAngleYaw + 0x8000) - m->faceAngle[1];
        if (facingDYaw >= -SIGN_RANGE && facingDYaw <= SIGN_RANGE) {
            f32 targetX = o->oPosX + 105.0f * sins(o->oMoveAngleYaw);
            f32 targetZ = o->oPosZ + 105.0f * coss(o->oMoveAngleYaw);

            m->playerObj->oPlayerReadingSignDYaw = facingDYaw;
            m->playerObj->oPlayerReadingSignDPosX = targetX - m->pos[0];
            m->playerObj->oPlayerReadingSignDPosZ = targetZ - m->pos[2];

            m->interactObj = o;
            m->usedObj = o;
            return set_player_action(m, ACT_READING_SIGN, 0);
        }
    }

    return FALSE;
}

u32 check_npc_talk(struct PlayerState *m, struct Object *o) {
    if ((m->input & READ_MASK) && player_can_talk(m, 1)) {
        s16 facingDYaw = player_obj_angle_to_object(m, o) - m->faceAngle[1];
        if (facingDYaw >= -0x4000 && facingDYaw <= 0x4000) {
            o->oInteractStatus = INT_STATUS_INTERACTED;

            m->interactObj = o;
            m->usedObj = o;

            push_player_out_of_object(m, o, -10.0f);
            return set_player_action(m, ACT_WAITING_FOR_DIALOG, 0);
        }
    }

    push_player_out_of_object(m, o, -10.0f);
    return FALSE;
}

u32 interact_text(struct PlayerState *m, UNUSED u32 interactType, struct Object *o) {
    u32 interact = FALSE;

    if (o->oInteractionSubtype & INT_SUBTYPE_SIGN) {
        interact = check_read_sign(m, o);
    } else if (o->oInteractionSubtype & INT_SUBTYPE_NPC) {
        interact = check_npc_talk(m, o);
    } else {
        push_player_out_of_object(m, o, 2.0f);
    }

    return interact;
}

void check_kick_or_punch_wall(struct PlayerState *m) {
    if (m->flags & (PLAYER_PUNCHING | PLAYER_KICKING | PLAYER_TRIPPING)) {
        Vec3f detector;
        detector[0] = m->pos[0] + 50.0f * sins(m->faceAngle[1]);
        detector[2] = m->pos[2] + 50.0f * coss(m->faceAngle[1]);
        detector[1] = m->pos[1];

        if (resolve_and_return_wall_collisions(detector, 80.0f, 5.0f) != NULL) {
            if (m->action != ACT_MOVE_PUNCHING || m->forwardVel >= 0.0f) {
                if (m->action == ACT_PUNCHING) {
                    m->action = ACT_MOVE_PUNCHING;
                }

                player_set_forward_vel(m, -48.0f);
                play_sound(SOUND_ACTION_HIT_2, m->playerObj->header.gfx.cameraToObject);
                m->particleFlags |= PARTICLE_TRIANGLE;
            } else if (m->action & ACT_FLAG_AIR) {
                player_set_forward_vel(m, -16.0f);
                play_sound(SOUND_ACTION_HIT_2, m->playerObj->header.gfx.cameraToObject);
                m->particleFlags |= PARTICLE_TRIANGLE;
            }
        }
    }
}

void player_process_interactions(struct PlayerState *m) {
    sDelayInvincTimer = FALSE;
    sInvulnerable = (m->action & ACT_FLAG_INVULNERABLE) || m->invincTimer != 0;

    if (!(m->action & ACT_FLAG_INTANGIBLE) && m->collidedObjInteractTypes != 0) {
        s32 i;
        for (i = 0; i < ARRAY_COUNT(sInteractionHandlers); i++) {
            u32 interactType = sInteractionHandlers[i].interactType;
            if (m->collidedObjInteractTypes & interactType) {
                struct Object *object = player_get_collided_object(m, interactType);

                m->collidedObjInteractTypes &= ~interactType;

                if (!(object->oInteractStatus & INT_STATUS_INTERACTED)) {
                    if (sInteractionHandlers[i].handler(m, interactType, object)) {
                        break;
                    }
                }
            }
        }
    }

    if (m->invincTimer > 0 && !sDelayInvincTimer) {
        m->invincTimer--;
    }

    //! If the kick/punch flags are set and an object collision changes Player's
    // action, he will get the kick/punch wall speed anyway.
    check_kick_or_punch_wall(m);
    m->flags &= ~PLAYER_PUNCHING & ~PLAYER_KICKING & ~PLAYER_TRIPPING;

    if (!(m->playerObj->collidedObjInteractTypes & (INTERACT_WARP_DOOR | INTERACT_DOOR))) {
        sDisplayingDoorText = FALSE;
    }
    if (!(m->playerObj->collidedObjInteractTypes & INTERACT_WARP)) {
        sJustTeleported = FALSE;
    }
}

void check_death_barrier(struct PlayerState *m) {
    if (Cheats.EnableCheats && Cheats.WalkOn.DeathBarrier) return;
    if (m->pos[1] < m->floorHeight + 2048.0f) {
        if (level_trigger_warp(m, WARP_OP_WARP_FLOOR) == 20 && !(m->flags & PLAYER_UNKNOWN_18)) {
            play_sound(SOUND_MARIO_WAAAOOOW, m->playerObj->header.gfx.cameraToObject);
        }
    }
}

#if FIX_LAVA_INTERACTION
#define ACT_FLAG_GROUP_NO_LAVA_BOOST (ACT_FLAG_SWIMMING | ACT_FLAG_RIDING_SHELL)
#else
#define ACT_FLAG_GROUP_NO_LAVA_BOOST (ACT_FLAG_AIR | ACT_FLAG_SWIMMING | ACT_FLAG_RIDING_SHELL)
#endif

void check_lava_boost(struct PlayerState *m) {
    if (Cheats.EnableCheats && Cheats.WalkOn.Lava) return;
    if (!(m->action & ACT_FLAG_GROUP_NO_LAVA_BOOST) && m->pos[1] < m->floorHeight + 10.0f) {
        if (!(m->flags & PLAYER_METAL_CAP)) {
            m->hurtCounter += (m->flags & PLAYER_CAP_ON_HEAD) ? 12 : 18;
        }
        
        update_player_sound_and_camera(m);
        drop_and_set_player_action(m, ACT_LAVA_BOOST, 0);
    }
}

#undef ACT_FLAG_GROUP_NO_LAVA_BOOST

void pss_begin_slide(UNUSED struct PlayerState *m) {
    if (!(gHudDisplay.flags & HUD_DISPLAY_FLAG_TIMER)) {
        level_control_timer(TIMER_CONTROL_SHOW);
        level_control_timer(TIMER_CONTROL_START);
        gPSSSlideStarted = TRUE;
    }
}

void pss_end_slide(struct PlayerState *m) {
    //! This value isn't set on death or level entry, allowing double star spawn
    //  Fixed with QOL_FIX_RESET_PSS_SLIDE_STARTED
    if (gPSSSlideStarted) {
        u16 slideTime = level_control_timer(TIMER_CONTROL_STOP);
        if (slideTime < SLIDE_TIME) {
            m->playerObj->oBhvParams = (STAR_INDEX_ACT_2 << 24);
            spawn_default_star(-6358.0f, -4300.0f, 4700.0f);
        }
        gPSSSlideStarted = FALSE;
    }
}

void player_handle_special_floors(struct PlayerState *m) {
    if ((m->action & ACT_GROUP_MASK) == ACT_GROUP_CUTSCENE) {
        return;
    }

    if (m->floor != NULL) {
        s32 floorType = m->floor->type;

        switch (floorType) {
            case SURFACE_DEATH_PLANE:
            case SURFACE_VERTICAL_WIND:
                check_death_barrier(m);
                break;

            case SURFACE_WARP:
                level_trigger_warp(m, WARP_OP_WARP_FLOOR);
                break;

            case SURFACE_TIMER_START:
                pss_begin_slide(m);
                break;

            case SURFACE_TIMER_END:
                pss_end_slide(m);
                break;

            // ex-alo change
            // Cleans up Player lava action checks
            case SURFACE_BURNING:
                check_lava_boost(m);
                break;
        }
    }
}
