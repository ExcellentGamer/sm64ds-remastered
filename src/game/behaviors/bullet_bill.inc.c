// DS Remastered Bullet Bill Behavior (bhvBulletBill and bhvWhitePuffSmoke)
// Bullet Bills are spawned from cannons and fly towards the player.
// If they hit the play or a wall, they will explode into smoke.
// White puff smoke is spawned by the bullet bill and other objects

// file: bullet_bill.inc.c

// White Puff Smoke Initialization Function
void bhv_white_puff_smoke_init(void) {
    cur_obj_scale(random_float() * 2 + 2.0);
}

// Bullet Bill Initialization Function
void bhv_bullet_bill_init(void) {
    o->oBulletBillInitialMoveYaw = o->oMoveAngleYaw;
    o->oHomeY = o->oHomeY + 100.0f; // Spawn's the bullet bill higher to account for the difference in DS/N64's positioning
}

// Bullet Bill Act 0: Set up initial state
void bullet_bill_act_0(void) {
    cur_obj_become_tangible();
    o->oForwardVel = 0.0f;
    o->oMoveAngleYaw = o->oBulletBillInitialMoveYaw;
    o->oFaceAnglePitch = 0;
    o->oFaceAngleRoll = 0;
    o->oMoveFlags = 0;
    cur_obj_set_pos_to_home();
    o->oAction = 1;
}

// Bullet Bill Act 1: Wait until player is in front of it, then start moving
void bullet_bill_act_1(void) {
    s16 sp1E = abs_angle_diff(o->oAngleToPlayer, o->oMoveAngleYaw);
    if (sp1E < 0x2000 && 400.0f < o->oDistanceToPlayer && o->oDistanceToPlayer < 1500.0f) {
        o->oAction = 2;
    }
}

// Bullet Bill Act 2: Move towards player, then explode after a while or if it hits a wall
void bullet_bill_act_2(void) {
    if (o->oTimer < 40) {
        o->oForwardVel = 3.0f;
    } else if (o->oTimer < 50) {
        if (o->oTimer % 2) {
            o->oForwardVel = 3.0f;
        } else {
            o->oForwardVel = -3.0f;
        }
    } else {
        if (o->oTimer > 70) {
            cur_obj_update_floor_and_walls();
        }

        spawn_object(o, MODEL_SMOKE, bhvWhitePuffSmoke);
        o->oForwardVel = 30.0f;

        if (o->oDistanceToPlayer > 300.0f) {
            cur_obj_rotate_yaw_toward(o->oAngleToPlayer, 0x100);
        }

        if (o->oTimer == 50) {
            cur_obj_play_sound_2(SOUND_OBJ_POUNDING_CANNON);
            cur_obj_shake_screen(SHAKE_POS_SMALL);
        }

        if (o->oTimer > 150 || o->oMoveFlags & OBJ_MOVE_HIT_WALL) {
            o->oAction = 3;
            spawn_mist_particles();
        }
    }
}

// Bullet Bill Act 3: Reset to initial state (could also be used for deletion)
void bullet_bill_act_3(void) {
    o->oAction = 0;
}

// Bullet Bill Act 4: Explosion animation and deletion
void bullet_bill_act_4(void) {
    if (o->oTimer == 0) {
        o->oForwardVel = -30.0f;
        cur_obj_become_intangible();
    }

    o->oFaceAnglePitch += 0x1000;
    o->oFaceAngleRoll += 0x1000;
    o->oPosY += 20.0f;

    if (o->oTimer > 90) {
        o->oAction = 0;
    }
}

void (*sBulletBillActions[])(void) = {
    bullet_bill_act_0,
    bullet_bill_act_1,
    bullet_bill_act_2,
    bullet_bill_act_3,
    bullet_bill_act_4,
};

void bhv_bullet_bill_loop(void) {
    cur_obj_call_action_function(sBulletBillActions);
    if (cur_obj_check_interacted()) {
        o->oAction = 4;
    }
}
