// king_bobomb.inc.c

// Copy of geo_update_projectile_pos_from_parent
Gfx *geo_update_held_player_pos(s32 run, UNUSED struct GraphNode *node, Mat4 mtx) {
    if (run == TRUE) {
        Mat4 sp20;
        struct Object *obj = (struct Object *) gCurGraphNodeObject;
        if (obj->prevObj != NULL) {
            create_transformation_from_matrices(sp20, mtx, *gCurGraphNodeCamera->matrixPtr);
            obj_update_pos_from_parent_transformation(sp20, obj->prevObj);
            obj_set_gfx_pos_from_pos(obj->prevObj);
        }
    }

    return NULL;
}

void bhv_bobomb_anchor_player_loop(void) {
    common_anchor_player_behavior(50.0f, 50.0f, INT_STATUS_MARIO_UNK6);
}

void king_bobomb_act_0(void) {
    s16 dialogID;

    o->oForwardVel = 0.0f;
    o->oVelY = 0.0f;

    if (o->oBhvParams2ndByte == BOBOMB_KING_BP_TYPE_1) {
        dialogID = DIALOG_017;
    } else {
        dialogID = DIALOG_174;
    }

    if (o->oSubAction == 0) {
        cur_obj_become_intangible();
        gSecondCameraFocus = o;
        cur_obj_init_animation_with_sound(5);
        cur_obj_set_pos_to_home();
        o->oHealth = KING_BOMB_HEALTH;

        if (cur_obj_can_mario_activate_textbox_2(500.0f, 100.0f)) {
            o->oSubAction++;
            seq_player_lower_volume(SEQ_PLAYER_LEVEL, 60, 40);
        }
    } else if (cur_obj_update_dialog_with_cutscene(MARIO_DIALOG_LOOK_UP,
        DIALOG_FLAG_TURN_TO_MARIO, CUTSCENE_DIALOG, dialogID)) {
        o->oAction = 2;
        o->oFlags |= OBJ_FLAG_HOLDABLE;
    }
}

s32 player_is_far_below_object(f32 arg0) {
    if (arg0 < o->oPosY - gPlayerObject->oPosY) {
        return TRUE;
    } else {
        return FALSE;
    }
}

void king_bobomb_act_2(void) {
    cur_obj_become_tangible();

    if (o->oPosY - o->oHomeY < -100.0f) { // Thrown off hill
        o->oAction = 5;
        cur_obj_become_intangible();
    }

    if (o->oKingBobombUnk100 == 0) {
        if (cur_obj_check_anim_frame(15)) {
            cur_obj_shake_screen(SHAKE_POS_SMALL);
        }

        if (cur_obj_init_animation_and_check_if_near_end(4)) {
            o->oKingBobombUnk100++;
        }
    } else {
        if (o->oKingBobombUnk100 == 1) {
            cur_obj_init_animation_and_anim_frame(11, 7);
            o->oKingBobombUnk100 = 2;
        } else {
            cur_obj_init_animation_with_sound(11);
        }

        if (o->oKingBobombUnk108 == 0) {
            o->oForwardVel = KING_BOMB_FVEL;
            cur_obj_rotate_yaw_toward(o->oAngleToPlayer, KING_BOMB_YAWVEL);
        } else {
            o->oForwardVel = 0.0f;
            o->oKingBobombUnk108--;
        }
    }

    if (cur_obj_check_grabbed_mario()) {
        o->oAction = 3;
    }

    if (player_is_far_below_object(1200.0f)) {
        o->oAction = 0;
        stop_background_music(SEQUENCE_ARGS(4, SEQ_EVENT_BOSS));
    }
}

void king_bobomb_act_3(void) {
    if (o->oSubAction == 0) {
        o->oForwardVel = 0.0f;
        o->oKingBobombHitCount = 0;
        o->oKingBobombUnkFC = 0;

        if (o->oTimer == 0) {
            cur_obj_play_sound_2(SOUND_OBJ_GRAB_MARIO);
        }

        if (cur_obj_init_animation_and_check_if_near_end(0)) {
            o->oSubAction++;
            cur_obj_init_animation_and_anim_frame(1, 0);
        }
    } else if (o->oSubAction == 1) {
        cur_obj_init_animation_with_sound(1);
        o->oKingBobombUnkFC += player_performed_grab_escape_action();

        print_debug_bottom_up("%d", o->oKingBobombUnkFC);

        if (o->oKingBobombUnkFC > 10) {
            o->oKingBobombUnk88 = 3;
            o->oAction = 2;
            o->oKingBobombUnk108 = 35;
            o->oInteractStatus &= ~INT_STATUS_GRABBED_MARIO;
        } else {
            o->oForwardVel = 3.0f;

            if (o->oKingBobombHitCount > 20 && cur_obj_rotate_yaw_toward(0, 0x400)) {
                o->oSubAction++;
                cur_obj_init_animation_and_anim_frame(9, 22);
            }
        }

        o->oKingBobombHitCount++;
    } else {
        cur_obj_init_animation_with_sound(9);

        if (cur_obj_check_anim_frame(31)) {
            o->oKingBobombUnk88 = 2;
            cur_obj_play_sound_2(SOUND_OBJ_RELEASE_MARIO);
        } else if (cur_obj_check_if_near_animation_end()) {
            o->oAction = 1;
            o->oInteractStatus &= ~INT_STATUS_GRABBED_MARIO;
        }
    }
}

void king_bobomb_act_1(void) {
    o->oForwardVel = 0.0f;
    o->oVelY = 0.0f;

    cur_obj_init_animation_with_sound(11);

    o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToPlayer, 0x200);

    if (o->oDistanceToPlayer < 2500.0f) {
        o->oAction = 2;
    }

    if (player_is_far_below_object(1200.0f)) {
        o->oAction = 0;
        stop_background_music(SEQUENCE_ARGS(4, SEQ_EVENT_BOSS));
    }
}

void king_bobomb_act_6(void) {
    if (o->oSubAction == 0) {
        if (o->oTimer == 0) {
            o->oKingBobombHitCount = 0;

            cur_obj_play_sound_2(SOUND_OBJ_KING_BOBOMB);
            cur_obj_play_sound_2(SOUND_OBJ2_KING_BOBOMB_DAMAGE);
            cur_obj_shake_screen(SHAKE_POS_SMALL);
            spawn_mist_particles_variable(0, 0, 100.0f);

            o->oInteractType = INTERACT_DAMAGE;

            cur_obj_become_tangible();
        }

        if (cur_obj_init_animation_and_check_if_near_end(2)) {
            o->oKingBobombHitCount++;
        }

        if (o->oKingBobombHitCount > 3) {
            o->oSubAction++;
        }
    } else if (o->oSubAction == 1) {
        if (cur_obj_init_animation_and_check_if_near_end(10)) {
            o->oSubAction++;
            o->oInteractType = INTERACT_GRABBABLE;

            cur_obj_become_intangible();
        }
    } else {
        cur_obj_init_animation_with_sound(11);

        if (cur_obj_rotate_yaw_toward(o->oAngleToPlayer, 0x800) == TRUE) {
            o->oAction = 2;
        }
    }
}

#if FIX_MARIO_LOOK_HEAD_BOSSES
#define MARIO_DIALOG_LOOK_BOSS MARIO_DIALOG_LOOK_FRONT
#else
#define MARIO_DIALOG_LOOK_BOSS MARIO_DIALOG_LOOK_UP
#endif

void king_bobomb_act_7(void) {
    cur_obj_init_animation_with_sound(2);
    if (cur_obj_update_dialog_with_cutscene(MARIO_DIALOG_LOOK_BOSS,
        DIALOG_FLAG_TEXT_DEFAULT, CUTSCENE_DIALOG, DIALOG_116)) {
        create_sound_spawner(SOUND_OBJ_KING_WHOMP_DEATH);
        cur_obj_hide();
        cur_obj_become_intangible();
        spawn_mist_particles_variable(0, 0, 200.0f);
        spawn_triangle_break_particles(20, MODEL_DIRT_ANIMATION, 3.0f, 4);
        cur_obj_shake_screen(SHAKE_POS_SMALL);
        cur_obj_spawn_star_at_y_offset(2000.0f, 4500.0f, -4500.0f, 200.0f);
        o->oAction = 8;
    }
}

#undef MARIO_DIALOG_LOOK_BOSS

void king_bobomb_act_8(void) {
    if (o->oTimer == 60) {
        stop_background_music(SEQUENCE_ARGS(4, SEQ_EVENT_BOSS));
    }
}

void king_bobomb_act_4(void) { // bobomb been thrown
    if (o->oPosY - o->oHomeY > -100.0f) { // not thrown off hill
        if (o->oMoveFlags & OBJ_MOVE_LANDED) {
            o->oHealth--;

            o->oForwardVel = 0.0f;
            o->oVelY = 0.0f;

            cur_obj_play_sound_2(SOUND_OBJ_KING_BOBOMB);

            if (o->oHealth != 0) {
                o->oAction = 6;
            } else {
                o->oAction = 7;
            }
        }
    } else if (o->oSubAction == 0) {
        if (o->oMoveFlags & OBJ_MOVE_ON_GROUND) {
            o->oForwardVel = 0.0f;
            o->oVelY = 0.0f;

            o->oSubAction++;
        } else if (o->oMoveFlags & OBJ_MOVE_LANDED) {
            cur_obj_play_sound_2(SOUND_OBJ_KING_BOBOMB);
        }
    } else {
        if (cur_obj_init_animation_and_check_if_near_end(10)) {
            o->oAction = 5; // Go back to top of hill
        }

        o->oSubAction++;

#if FIX_KING_BOBOMB_MUSIC_THROWN_OFF
        if (o->oDistanceToPlayer > 2000.0f) {
            stop_background_music(SEQUENCE_ARGS(4, SEQ_EVENT_BOSS));
        }
#endif
    }
}

void king_bobomb_act_5(void) { // bobomb returns home
    switch (o->oSubAction) {
        case 0:
            if (o->oTimer == 0) {
                cur_obj_play_sound_2(SOUND_OBJ_KING_BOBOMB_JUMP);
            }

            o->oKingBobombUnkF8 = 1;

            cur_obj_init_animation_and_extend_if_at_end(8);
            o->oMoveAngleYaw =  cur_obj_angle_to_home();

            if (o->oPosY < o->oHomeY) {
                o->oVelY = 100.0f;
            } else {
                arc_to_goal_pos(&o->oHomeX, &o->oPosX, 100.0f, -4.0f);
                o->oSubAction++;
            }
            break;

        case 1:
            cur_obj_init_animation_and_extend_if_at_end(8);

            if (o->oVelY < 0 && o->oPosY < o->oHomeY) {
                o->oPosY = o->oHomeY;
                o->oVelY = 0;
                o->oForwardVel = 0;
                o->oGravity = -4.0f;

                o->oKingBobombUnkF8 = 0;

                cur_obj_init_animation_with_sound(7);
                cur_obj_play_sound_2(SOUND_OBJ_KING_BOBOMB);
                cur_obj_shake_screen(SHAKE_POS_SMALL);

                o->oSubAction++;
            }
            break;

        case 2:
            if (cur_obj_init_animation_and_check_if_near_end(7)) {
                o->oSubAction++;
            }
            break;

        case 3:
#if FIX_KING_BOBOMB_MUSIC_THROWN_OFF
            if (o->oDistanceToPlayer > 2000.0f)
#else
            if (player_is_far_below_object(1200.0f))
#endif
            {
                o->oAction = 0;
                stop_background_music(SEQUENCE_ARGS(4, SEQ_EVENT_BOSS));
            }
            if (cur_obj_can_mario_activate_textbox_2(500.0f, 100.0f)) {
                o->oSubAction++;
            }
            break;

        case 4:
            if (cur_obj_update_dialog_with_cutscene(MARIO_DIALOG_LOOK_UP,
                DIALOG_FLAG_TURN_TO_MARIO, CUTSCENE_DIALOG, DIALOG_128)) {
                o->oAction = 2;
            }
            break;
    }
}

void (*sKingBobombActions[])(void) = {
    king_bobomb_act_0,
    king_bobomb_act_1,
    king_bobomb_act_2,
    king_bobomb_act_3,
    king_bobomb_act_4,
    king_bobomb_act_5,
    king_bobomb_act_6,
    king_bobomb_act_7,
    king_bobomb_act_8,
};
struct SoundState sKingBobombSoundStates[] = {
    { 0, 0, 0, NO_SOUND },
    { 1, 1, 20, SOUND_OBJ_KING_BOBOMB_POUNDING1_HIGHPRIO },
    { 0, 0, 0, NO_SOUND },
    { 0, 0, 0, NO_SOUND },
    { 1, 15, -1, SOUND_OBJ_KING_BOBOMB_POUNDING1_HIGHPRIO },
    { 0, 0, 0, NO_SOUND },
    { 0, 0, 0, NO_SOUND },
    { 0, 0, 0, NO_SOUND },
    { 0, 0, 0, NO_SOUND },
    { 1, 33, -1, SOUND_OBJ_KING_BOBOMB_POUNDING1_HIGHPRIO },
    { 0, 0, 0, NO_SOUND },
    { 1, 1, 15, SOUND_OBJ_KING_BOBOMB_POUNDING1_HIGHPRIO },
};

void king_bobomb_move(void) {
    cur_obj_update_floor_and_walls();

    if (o->oKingBobombUnkF8 == 0) {
        cur_obj_move_standard(-78);
    } else {
        cur_obj_move_using_fvel_and_gravity();
    }

    cur_obj_call_action_function(sKingBobombActions);
    exec_anim_sound_state(sKingBobombSoundStates);
#ifndef NODRAWINGDISTANCE
    if (o->oDistanceToPlayer < 5000.0f) {
#endif
        cur_obj_enable_rendering();
#ifndef NODRAWINGDISTANCE
    } else {
        cur_obj_disable_rendering();
    }
#endif
}

void bhv_king_bobomb_loop(void) {
    f32 sp34 = 20.0f;
    f32 sp30 = 50.0f;
    UNUSED u8 filler[8];

    o->oInteractionSubtype |= INT_SUBTYPE_GRABS_MARIO;

    switch (o->oHeldState) {
        case HELD_FREE:
            king_bobomb_move();
            break;
        case HELD_HELD:
            cur_obj_unrender_set_action_and_anim(6, 1);
            break;
        case HELD_THROWN:
        case HELD_DROPPED:
            cur_obj_get_thrown_or_placed(sp34, sp30, 4);
            cur_obj_become_intangible();
            o->oPosY += 20.0f;
            break;
    }

#if KING_BOBOMB_BLINK_EYES
    curr_obj_random_blink(&o->oKingBobombBlinkTimer);
#endif

    o->oInteractStatus = 0;
}
