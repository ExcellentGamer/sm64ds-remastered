#include <PR/ultratypes.h>

#include "sm64.h"
#include "player_actions_object.h"
#include "types.h"
#include "characters.h"
#include "player_step.h"
#include "player.h"
#include "audio/external.h"
#include "interaction.h"
#include "engine/math_util.h"
#include "rumble_init.h"

/**
 * Used by act_punching() to determine Player's forward velocity during each
 * animation frame.
 */
s8 sPunchingForwardVelocities[8] = { 0, 1, 1, 2, 3, 5, 7, 10 };

void animated_stationary_ground_step(struct PlayerState *m, s32 animation, u32 endAction) {
    stationary_ground_step(m);
    set_player_animation(m, animation);
    if (is_anim_at_end(m)) {
        set_player_action(m, endAction, 0);
    }
}

s32 player_update_punch_sequence(struct PlayerState *m) {
    u32 endAction, crouchEndAction;
    s32 animFrame;

    if (m->action & ACT_FLAG_MOVING) {
        endAction = ACT_WALKING, crouchEndAction = ACT_CROUCH_SLIDE;
    } else {
        endAction = ACT_IDLE, crouchEndAction = ACT_CROUCHING;
    }

    if (curChar == 0) {
        // Lick Functionality
        switch (m->actionArg) {
            case 0:
                play_character_sound(m, CHAR_SOUND_PUNCH_YAH);
                m->actionArg = 1;
                break;

            case 1:
                set_player_animation(m, YOSHI_ANIM_EAT);

                if (is_anim_past_end(m)) {
                    m->actionArg = 2;
                    break;
                }

                if (m->playerObj->header.gfx.animInfo.animFrame >= 2) {
                    if (player_check_object_grab(m)) {
                        return TRUE;
                    }
                    m->flags |= PLAYER_PUNCHING;
                }
                break;

            case 2:
                set_player_animation(m, YOSHI_ANIM_EAT_FAIL);

                if (m->playerObj->header.gfx.animInfo.animFrame <= 0) {
                    m->flags |= PLAYER_PUNCHING;
                }

                if (is_anim_at_end(m)) {
                    set_player_action(m, endAction, 0);
                }
                break;
        }
    } else {
        // Punch/Kick Functionality
        switch (m->actionArg) {
            case 0:
                play_sound(SOUND_MARIO_PUNCH_YAH, m->playerObj->header.gfx.cameraToObject);
            case 1:
                set_player_animation(m, CHAR_ANIM_FIRST_PUNCH);
                if (is_anim_past_end(m)) {
                    m->actionArg = 2;
                } else {
                    m->actionArg = 1;
                }

                if (m->playerObj->header.gfx.animInfo.animFrame >= 2) {
                    if (player_check_object_grab(m)) {
                        return TRUE;
                    }

                    m->flags |= PLAYER_PUNCHING;
                }

                if (m->actionArg == 2) {
                    m->playerBodyState->punchState = (0 << 6) | 4;
                }
                break;

            case 2:
                set_player_animation(m, CHAR_ANIM_FIRST_PUNCH_FAST);

                if (m->playerObj->header.gfx.animInfo.animFrame <= 0) {
                    m->flags |= PLAYER_PUNCHING;
                }

                if (m->input & INPUT_B_PRESSED) {
                    m->actionArg = 3;
                }

                if (is_anim_at_end(m)) {
                    set_player_action(m, endAction, 0);
                }
                break;

            case 3:
                play_sound(SOUND_MARIO_PUNCH_WAH, m->playerObj->header.gfx.cameraToObject);
                // fallthrough
            case 4:
                set_player_animation(m, CHAR_ANIM_SECOND_PUNCH);
                if (is_anim_past_end(m)) {
                    m->actionArg = 5;
                } else {
                    m->actionArg = 4;
                }

                if (m->playerObj->header.gfx.animInfo.animFrame > 0) {
                    m->flags |= PLAYER_PUNCHING;
                }

                if (m->actionArg == 5) {
                    m->playerBodyState->punchState = (1 << 6) | 4;
                }
                break;

            case 5:
                set_player_animation(m, CHAR_ANIM_SECOND_PUNCH_FAST);
                if (m->playerObj->header.gfx.animInfo.animFrame <= 0) {
                    m->flags |= PLAYER_PUNCHING;
                }

                if (m->input & INPUT_B_PRESSED) {
                    m->actionArg = 6;
                }

                if (is_anim_at_end(m)) {
                    set_player_action(m, endAction, 0);
                }
                break;

            case 6:
                play_player_action_sound(m, SOUND_MARIO_PUNCH_HOO, 1);
                animFrame = set_player_animation(m, CHAR_ANIM_GROUND_KICK);
                if (animFrame == 0) {
                    m->playerBodyState->punchState = (2 << 6) | 6;
                }

                if (animFrame >= 0 && animFrame < 8) {
                    m->flags |= PLAYER_KICKING;
                }

                if (is_anim_at_end(m)) {
                    set_player_action(m, endAction, 0);
                }
                break;

            case 9:
                play_player_action_sound(m, SOUND_MARIO_PUNCH_HOO, 1);
                set_player_animation(m, CHAR_ANIM_BREAKDANCE);
                animFrame = m->playerObj->header.gfx.animInfo.animFrame;

                if (animFrame >= 2 && animFrame < 8) {
                    m->flags |= PLAYER_TRIPPING;
                }

                if (is_anim_at_end(m)) {
                    set_player_action(m, crouchEndAction, 0);
                }
                break;
        }
    }

    return FALSE;
}

s32 act_punching(struct PlayerState *m) {
    if (m->input & INPUT_STOMPED) {
        return drop_and_set_player_action(m, ACT_SHOCKWAVE_BOUNCE, 0);
    }

    if (m->input & (INPUT_NONZERO_ANALOG | INPUT_A_PRESSED | INPUT_OFF_FLOOR | INPUT_ABOVE_SLIDE)) {
        return check_common_action_exits(m);
    }

    if (m->actionState == 0 && (m->input & INPUT_A_DOWN) && curChar != 0) {
        return set_player_action(m, ACT_JUMP_KICK, 0);
    }

    m->actionState = 1;
    if (m->actionArg == 0) {
        m->actionTimer = 7;
    }

    player_set_forward_vel(m, sPunchingForwardVelocities[m->actionTimer]);
    if (m->actionTimer > 0) {
        m->actionTimer--;
    }

    player_update_punch_sequence(m);
    perform_ground_step(m);
    return FALSE;
}

s32 act_picking_up(struct PlayerState *m) {
    if (m->input & INPUT_STOMPED) {
        return drop_and_set_player_action(m, ACT_SHOCKWAVE_BOUNCE, 0);
    }

    if (m->input & INPUT_OFF_FLOOR) {
        return drop_and_set_player_action(m, ACT_FREEFALL, 0);
    }

    if (m->actionState == 0 && is_anim_at_end(m)) {
        //! While the animation is playing, it is possible for the used object
        // to unload. This allows you to pick up a vacant or newly loaded object
        // slot (cloning via fake object).
        player_grab_used_object(m);
        play_sound_if_no_flag(m, SOUND_MARIO_HRMM, PLAYER_MARIO_SOUND_PLAYED);
        m->actionState = 1;
    }

    if (m->actionState == 1) {
        if (m->heldObj->oInteractionSubtype & INT_SUBTYPE_GRABS_PLAYER) {
            m->playerBodyState->grabPos = GRAB_POS_HEAVY_OBJ;
            set_player_animation(m, CHAR_ANIM_GRAB_HEAVY_OBJECT);
            if (is_anim_at_end(m)) {
                set_player_action(m, ACT_HOLD_HEAVY_IDLE, 0);
            }
        } else {
            m->playerBodyState->grabPos = GRAB_POS_LIGHT_OBJ;
            set_player_animation(m, CHAR_ANIM_PICK_UP_LIGHT_OBJ);
            if (is_anim_at_end(m)) {
                set_player_action(m, ACT_HOLD_IDLE, 0);
            }
        }
    }

    stationary_ground_step(m);
    return FALSE;
}

s32 act_dive_picking_up(struct PlayerState *m) {
    if (m->input & INPUT_STOMPED) {
        return drop_and_set_player_action(m, ACT_SHOCKWAVE_BOUNCE, 0);
    }

    //! Hands-free holding. Landing on a slope or being pushed off a ledge while
    // landing from a dive grab sets the players action to a non-holding action
    // without dropping the object, causing the hands-free holding glitch.
    if (m->input & INPUT_OFF_FLOOR) {
        return set_player_action(m, ACT_FREEFALL, 0);
    }

    if (m->input & INPUT_ABOVE_SLIDE) {
        return set_player_action(m, ACT_BEGIN_SLIDING, 0);
    }

    animated_stationary_ground_step(m, CHAR_ANIM_STOP_SLIDE_LIGHT_OBJ, ACT_HOLD_IDLE);
    return FALSE;
}

s32 act_placing_down(struct PlayerState *m) {
    if (m->input & INPUT_STOMPED) {
        return drop_and_set_player_action(m, ACT_SHOCKWAVE_BOUNCE, 0);
    }

    if (m->input & INPUT_OFF_FLOOR) {
        return drop_and_set_player_action(m, ACT_FREEFALL, 0);
    }

    if (++m->actionTimer == 8) {
        player_drop_held_object(m);
    }

    animated_stationary_ground_step(m, CHAR_ANIM_PLACE_LIGHT_OBJ, ACT_IDLE);
    return FALSE;
}

s32 act_throwing(struct PlayerState *m) {
    if (m->heldObj && (m->heldObj->oInteractionSubtype & INT_SUBTYPE_HOLDABLE_NPC)) {
        return set_player_action(m, ACT_PLACING_DOWN, 0);
    }

    if (m->input & INPUT_STOMPED) {
        return drop_and_set_player_action(m, ACT_SHOCKWAVE_BOUNCE, 0);
    }

    if (m->input & INPUT_OFF_FLOOR) {
        return drop_and_set_player_action(m, ACT_FREEFALL, 0);
    }

    if (++m->actionTimer == 7) {
        player_throw_held_object(m);
        play_sound_if_no_flag(m, SOUND_MARIO_WAH2, PLAYER_MARIO_SOUND_PLAYED);
        play_sound_if_no_flag(m, SOUND_ACTION_THROW, PLAYER_ACTION_SOUND_PLAYED);
#ifdef RUMBLE_FEEDBACK
        queue_rumble_data(3, 50);
#endif
    }

    animated_stationary_ground_step(m, CHAR_ANIM_GROUND_THROW, ACT_IDLE);
    return FALSE;
}

s32 act_heavy_throw(struct PlayerState *m) {
    if (m->input & INPUT_STOMPED) {
        return drop_and_set_player_action(m, ACT_SHOCKWAVE_BOUNCE, 0);
    }

    if (m->input & INPUT_OFF_FLOOR) {
        return drop_and_set_player_action(m, ACT_FREEFALL, 0);
    }

    if (++m->actionTimer == 13) {
        player_drop_held_object(m);
        play_sound_if_no_flag(m, SOUND_MARIO_WAH2, PLAYER_MARIO_SOUND_PLAYED);
        play_sound_if_no_flag(m, SOUND_ACTION_THROW, PLAYER_ACTION_SOUND_PLAYED);
#ifdef RUMBLE_FEEDBACK
        queue_rumble_data(3, 50);
#endif
    }

    animated_stationary_ground_step(m, CHAR_ANIM_HEAVY_THROW, ACT_IDLE);
    return FALSE;
}

s32 act_stomach_slide_stop(struct PlayerState *m) {
    if (m->input & INPUT_STOMPED) {
        return set_player_action(m, ACT_SHOCKWAVE_BOUNCE, 0);
    }

    if (m->input & INPUT_OFF_FLOOR) {
        return set_player_action(m, ACT_FREEFALL, 0);
    }

    if (m->input & INPUT_ABOVE_SLIDE) {
        return set_player_action(m, ACT_BEGIN_SLIDING, 0);
    }

    animated_stationary_ground_step(m, CHAR_ANIM_SLOW_LAND_FROM_DIVE, ACT_IDLE);
    return FALSE;
}

s32 act_picking_up_bowser(struct PlayerState *m) {
    if (m->actionState == 0) {
        m->actionState = 1;
        m->angleVel[1] = 0;
        m->playerBodyState->grabPos = GRAB_POS_BOWSER;
        player_grab_used_object(m);
#ifdef RUMBLE_FEEDBACK
        queue_rumble_data(5, 80);
#endif
        play_sound(SOUND_MARIO_HRMM, m->playerObj->header.gfx.cameraToObject);
    }

    set_player_animation(m, CHAR_ANIM_GRAB_BOWSER);
    if (is_anim_at_end(m)) {
        set_player_action(m, ACT_HOLDING_BOWSER, 0);
    }

    stationary_ground_step(m);
    return FALSE;
}

s32 act_holding_bowser(struct PlayerState *m) {
    s16 spin;

    if (m->input & INPUT_B_PRESSED) {
        if (m->angleVel[1] <= -0xE00 || m->angleVel[1] >= 0xE00) {
            play_sound(SOUND_MARIO_SO_LONGA_BOWSER, m->playerObj->header.gfx.cameraToObject);
        } else {
            play_sound(SOUND_MARIO_HERE_WE_GO, m->playerObj->header.gfx.cameraToObject);
        }
        return set_player_action(m, ACT_RELEASING_BOWSER, 0);
    }

    if (m->angleVel[1] == 0) {
        if (m->actionTimer++ > 120) {
            return set_player_action(m, ACT_RELEASING_BOWSER, 1);
        }

        set_player_animation(m, CHAR_ANIM_HOLDING_BOWSER);
    } else {
        m->actionTimer = 0;
        set_player_animation(m, CHAR_ANIM_SWINGING_BOWSER);
    }

    if (m->intendedMag > 20.0f) {
        if (m->actionArg == 0) {
            m->actionArg = 1;
            m->twirlYaw = m->intendedYaw;
        } else {
            // spin = acceleration
            spin = (s16)(m->intendedYaw - m->twirlYaw) / 0x80;

            if (spin < -0x80) {
                spin = -0x80;
            }
            if (spin > 0x80) {
                spin = 0x80;
            }

            m->twirlYaw = m->intendedYaw;
            m->angleVel[1] += spin;

            if (m->angleVel[1] > 0x1000) {
                m->angleVel[1] = 0x1000;
            }
            if (m->angleVel[1] < -0x1000) {
                m->angleVel[1] = -0x1000;
            }
        }
    } else {
        m->actionArg = 0;
        m->angleVel[1] = approach_s32(m->angleVel[1], 0, 64, 64);
    }

    // spin = starting yaw
    spin = m->faceAngle[1];
    m->faceAngle[1] += m->angleVel[1];

    // play sound on overflow
    if (m->angleVel[1] <= -0x100 && spin < m->faceAngle[1]) {
#ifdef RUMBLE_FEEDBACK
        queue_rumble_data(4, 20);
#endif
        play_sound(SOUND_OBJ_BOWSER_SPINNING, m->playerObj->header.gfx.cameraToObject);
    }
    if (m->angleVel[1] >= 0x100 && spin > m->faceAngle[1]) {
#ifdef RUMBLE_FEEDBACK
        queue_rumble_data(4, 20);
#endif
        play_sound(SOUND_OBJ_BOWSER_SPINNING, m->playerObj->header.gfx.cameraToObject);
    }

    stationary_ground_step(m);
    if (m->angleVel[1] >= 0) {
        m->playerObj->header.gfx.angle[0] = -m->angleVel[1];
    } else {
        m->playerObj->header.gfx.angle[0] = m->angleVel[1];
    }

    return FALSE;
}

s32 act_releasing_bowser(struct PlayerState *m) {
    if (++m->actionTimer == 1) {
        if (m->actionArg == 0) {
#ifdef RUMBLE_FEEDBACK
            queue_rumble_data(5, 50);
#endif
            player_throw_held_object(m);
        } else {
#ifdef RUMBLE_FEEDBACK
            queue_rumble_data(4, 50);
#endif
            player_drop_held_object(m);
        }
    }

    m->angleVel[1] = 0;
    animated_stationary_ground_step(m, CHAR_ANIM_RELEASE_BOWSER, ACT_IDLE);
    return FALSE;
}

s32 check_common_object_cancels(struct PlayerState *m) {
    f32 waterSurface = m->waterLevel - 100;
    if (m->pos[1] < waterSurface) {
        return set_water_plunge_action(m);
    }

    if (m->input & INPUT_SQUISHED) {
        return drop_and_set_player_action(m, ACT_SQUISHED, 0);
    }

    if (m->health < 0x100) {
        return drop_and_set_player_action(m, ACT_STANDING_DEATH, 0);
    }

    return FALSE;
}

s32 player_execute_object_action(struct PlayerState *m) {
    s32 cancel = FALSE;

    if (check_common_object_cancels(m)) {
        return TRUE;
    }

    if (player_update_quicksand(m, 0.5f)) {
        return TRUE;
    }

    /* clang-format off */
    switch (m->action) {
        case ACT_PUNCHING:           cancel = act_punching(m);           break;
        case ACT_PICKING_UP:         cancel = act_picking_up(m);         break;
        case ACT_DIVE_PICKING_UP:    cancel = act_dive_picking_up(m);    break;
        case ACT_STOMACH_SLIDE_STOP: cancel = act_stomach_slide_stop(m); break;
        case ACT_PLACING_DOWN:       cancel = act_placing_down(m);       break;
        case ACT_THROWING:           cancel = act_throwing(m);           break;
        case ACT_HEAVY_THROW:        cancel = act_heavy_throw(m);        break;
        case ACT_PICKING_UP_BOWSER:  cancel = act_picking_up_bowser(m);  break;
        case ACT_HOLDING_BOWSER:     cancel = act_holding_bowser(m);     break;
        case ACT_RELEASING_BOWSER:   cancel = act_releasing_bowser(m);   break;
    }
    /* clang-format on */

    if (!cancel && (m->input & INPUT_IN_WATER)) {
        m->particleFlags |= PARTICLE_IDLE_WATER_WAVE;
    }

    return cancel;
}
