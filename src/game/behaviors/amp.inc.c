
/**
 * Behavior for bhvHomingAmp and bhvCirclingAmp.
 * These are distinct objects; one chases (homes in on) Player,
 * while the other circles around a fixed location with a radius
 * of 200, 300, 400, or 0 (stationary).
 */

static struct ObjectHitbox sAmpHitbox = {
    /* interactType:      */ INTERACT_SHOCK,
    /* downOffset:        */ 40,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 40,
    /* height:            */ 50,
    /* hurtboxRadius:     */ 50,
    /* hurtboxHeight:     */ 60,
};

/**
 * Homing amp initialization function.
 */
void bhv_homing_amp_init(void) {
    o->oHomeX = o->oPosX;
    o->oHomeY = o->oPosY;
    o->oHomeZ = o->oPosZ;
    o->oGravity = 0.0f;
    o->oFriction = 1.0f;
    o->oBuoyancy = 1.0f;
    o->oHomingAmpAvgY = o->oHomeY;

    // Homing amps start at 1/10th their normal size.
    // They grow when they "appear" to Player.
    cur_obj_scale(0.1f);

    // Hide the amp (until Player gets near).
    o->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
}

/**
 * Amps' attack handler, shared by both types of amp.
 */
static void check_amp_attack(void) {
    // Strange placement for this call. The hitbox is never cleared.
    // For perspective, this code is run every frame of bhv_circling_amp_loop
    // and every frame of a homing amp's HOMING_AMP_ACT_CHASE action.
    obj_set_hitbox(o, &sAmpHitbox);

    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        // Unnecessary if statement, maybe caused by a macro for
        //     if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        //         o->oAction = X;
        //     }
        // ?
        if (o->oInteractStatus & INT_STATUS_INTERACTED) {
            // This function is used for both normal amps and homing amps,
            // AMP_ACT_ATTACK_COOLDOWN == HOMING_AMP_ACT_ATTACK_COOLDOWN
            o->oAction = AMP_ACT_ATTACK_COOLDOWN;
        }

        // Clear interact status
        o->oInteractStatus = 0;
    }
}

/**
 * Unhide the amp and grow until normal size, then begin chasing Player.
 */
static void homing_amp_appear_loop(void) {
    // gLakituState.goalPos is the position lakitu is moving towards.
    // In Lakitu and Player cam, it is usually very close to the current camera position.
    // In Fixed cam, it is the point behind Player the camera will go to when transitioning
    // to Lakitu cam. Homing amps will point themselves towards this point when appearing.
    f32 relativeTargetX = gLakituState.goalPos[0] - o->oPosX;
    f32 relativeTargetZ = gLakituState.goalPos[2] - o->oPosZ;
    s16 targetYaw = atan2s(relativeTargetZ, relativeTargetX);

    o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, targetYaw, 0x1000);

    // For 30 frames, make the amp "appear" by increasing its size by 0.03 each frame,
    // except for the first frame (when oTimer == 0) because the expression in cur_obj_scale
    // evaluates to 0.1, which is the same as it was before. After 30 frames, it ends at
    // a scale factor of 0.97. The amp remains at 97% of its real height for 60 more frames.
    if (o->oTimer < 30) {
        cur_obj_scale(0.1 + 0.9 * (f32)(o->oTimer / 30.0f));
    } else {
        o->oAnimState = 1;
    }

    // Once the timer becomes greater than 90, i.e. 91 frames have passed,
    // reset the amp's size and start chasing Player.
    if (o->oTimer > 90) {
        cur_obj_scale(1.0f);
        o->oAction = HOMING_AMP_ACT_CHASE;
        o->oAmpYPhase = 0;
    }
}

/**
 * Chase Player.
 */
static void homing_amp_chase_loop(void) {
    // Lock on to Player if he ever goes within 11.25 degrees of the amp's line of sight
    if ((o->oAngleToPlayer - 0x400 < o->oMoveAngleYaw)
        && (o->oMoveAngleYaw < o->oAngleToPlayer + 0x400)) {
        o->oHomingAmpLockedOn = TRUE;
        o->oTimer = 0;
    }

    // If the amp is locked on to Player, start "chasing" him by moving
    // in a straight line at 15 units/second for 32 frames.
    if (o->oHomingAmpLockedOn == TRUE) {
        o->oForwardVel = 15.0f;

        // Move the amp's average Y (the Y value it oscillates around) to align with
        // Player's head. Player's graphics' Y + 150 is around the top of his head.
        // Note that the average Y will slowly go down to approach his head if the amp
        // is above his head, but if the amp is below it will instantly snap up.
        if (o->oHomingAmpAvgY > gPlayerObject->header.gfx.pos[1] + 150.0f) {
            o->oHomingAmpAvgY -= 10.0f;
        } else {
            o->oHomingAmpAvgY = gPlayerObject->header.gfx.pos[1] + 150.0f;
        }

        if (o->oTimer > 30) {
            o->oHomingAmpLockedOn = FALSE;
        }
    } else {
        // If the amp is not locked on to Player, move forward at 10 units/second
        // while curving towards him.
        o->oForwardVel = 10.0f;

        obj_turn_toward_object(o, gPlayerObject, 16, 0x400);

        // The amp's average Y will approach Player's graphical Y position + 250
        // at a rate of 10 units per frame. Interestingly, this is different from
        // the + 150 used while chasing him. Could this be a typo?
        if (o->oHomingAmpAvgY < gPlayerObject->header.gfx.pos[1] + 250.0f) {
            o->oHomingAmpAvgY += 10.0f;
        }
    }

    // The amp's position will sinusoidally oscillate 40 units around its average Y.
    o->oPosY = o->oHomingAmpAvgY + sins(o->oAmpYPhase * 0x400) * 20.0f;

    // Handle attacks
    check_amp_attack();

    // Give up if Player goes further than 1500 units from the amp's original position
    if (!is_point_within_radius_of_player(o->oHomeX, o->oHomeY, o->oHomeZ, 1500)) {
        o->oAction = HOMING_AMP_ACT_GIVE_UP;
    }
}

/**
 * Give up on chasing Player.
 */
static void homing_amp_give_up_loop(void) {
    UNUSED u8 filler[8];

    // Move forward for 152 frames
    o->oForwardVel = 15.0f;

    if (o->oTimer > 150) {
        // Hide the amp and reset it back to its inactive state
        o->oPosX = o->oHomeX;
        o->oPosY = o->oHomeY;
        o->oPosZ = o->oHomeZ;
        o->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
        o->oAction = HOMING_AMP_ACT_INACTIVE;
        o->oAnimState = 0;
        o->oForwardVel = 0.0f;
        o->oHomingAmpAvgY = o->oHomeY;
    }
}

/**
 * Cool down after a successful attack, shared by both types of amp.
 */
static void amp_attack_cooldown_loop(void) {
    // Turn intangible and wait for 90 frames before chasing Player again after hitting him.
    o->header.gfx.animInfo.animFrame += 2;
    o->oForwardVel = 0.0f;

    cur_obj_become_intangible();

    if (o->oTimer > 30) {
        o->oAnimState = 0;
    }

    if (o->oTimer > 90) {
        o->oAnimState = 1;
        cur_obj_become_tangible();
        o->oAction = HOMING_AMP_ACT_CHASE;
    }
}

/**
 * Homing amp update function.
 */
void bhv_homing_amp_loop(void) {
    switch (o->oAction) {
        case HOMING_AMP_ACT_INACTIVE:
            if (is_point_within_radius_of_player(o->oHomeX, o->oHomeY, o->oHomeZ, 800) == TRUE) {
                // Make the amp start to appear, and un-hide it.
                o->oAction = HOMING_AMP_ACT_APPEAR;
                o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
            }
            break;

        case HOMING_AMP_ACT_APPEAR:
            homing_amp_appear_loop();
            break;

        case HOMING_AMP_ACT_CHASE:
            homing_amp_chase_loop();
            cur_obj_play_sound_1(SOUND_AIR_AMP_BUZZ);
            break;

        case HOMING_AMP_ACT_GIVE_UP:
            homing_amp_give_up_loop();
            break;

        case HOMING_AMP_ACT_ATTACK_COOLDOWN:
            amp_attack_cooldown_loop();
            break;
    }

    object_step();

    // Oscillate
    o->oAmpYPhase++;
}

/**
 * Circling amp initialization function.
 */
void bhv_circling_amp_init(void) {
    o->oHomeX = o->oPosX;
    o->oHomeY = o->oPosY;
    o->oHomeZ = o->oPosZ;
    o->oAnimState = 1;

    // Determine the radius of the circling amp's circle
    switch (o->oBhvParams2ndByte) {
        case AMP_BP_ROT_RADIUS_200:
            o->oAmpRadiusOfRotation = 200.0f;
            break;

        case AMP_BP_ROT_RADIUS_300:
            o->oAmpRadiusOfRotation = 300.0f;
            break;

        case AMP_BP_ROT_RADIUS_400:
            o->oAmpRadiusOfRotation = 400.0f;
            break;

        case AMP_BP_ROT_RADIUS_0:
            break;
    }

    // Choose a random point along the amp's circle.
    // The amp's move angle represents its angle along the circle.
    o->oMoveAngleYaw = random_u16();

    o->oAction = AMP_ACT_IDLE;
}

/**
 * Main update function for fixed amps.
 * Fixed amps are a sub-species of circling amps, with circle radius 0.
 */
static void fixed_circling_amp_idle_loop(void) {
    // Turn towards Player, in both yaw and pitch.
    f32 xToPlayer = gPlayerObject->header.gfx.pos[0] - o->oPosX;
    f32 yToPlayer = gPlayerObject->header.gfx.pos[1] + 120.0f - o->oPosY;
    f32 zToPlayer = gPlayerObject->header.gfx.pos[2] - o->oPosZ;
    s16 vAngleToPlayer = atan2s(sqrtf(xToPlayer * xToPlayer + zToPlayer * zToPlayer), -yToPlayer);

    obj_turn_toward_object(o, gPlayerObject, 19, 0x1000);
    o->oFaceAnglePitch = approach_s16_symmetric(o->oFaceAnglePitch, vAngleToPlayer, 0x1000);

    // Oscillate 40 units up and down.
    // Interestingly, 0x458 (1112 in decimal) is a magic number with no apparent significance.
    // It is slightly larger than the 0x400 figure used for homing amps, which makes
    // fixed amps oscillate slightly quicker.
    // Also, this uses the cosine, which starts at 1 instead of 0.
    o->oPosY = o->oHomeY + coss(o->oAmpYPhase * 0x458) * 20.0f;

    // Handle attacks
    check_amp_attack();

    // Oscillate
    o->oAmpYPhase++;

    // Where there is a cur_obj_play_sound_1 call in the main circling amp update function,
    // there is nothing here. Fixed amps are the only amps that never play
    // the "amp buzzing" sound.
}

/**
 * Main update function for regular circling amps.
 */
static void circling_amp_idle_loop(void) {
    // Move in a circle.
    // The Y oscillation uses the magic number 0x8B0 (2224), which is
    // twice that of the fixed amp. In other words, circling amps will
    // oscillate twice as fast. Also, unlike all other amps, circling
    // amps oscillate 60 units around their average Y instead of 40.
    o->oPosX = o->oHomeX + sins(o->oMoveAngleYaw) * o->oAmpRadiusOfRotation;
    o->oPosZ = o->oHomeZ + coss(o->oMoveAngleYaw) * o->oAmpRadiusOfRotation;
    o->oPosY = o->oHomeY + coss(o->oAmpYPhase * 0x8B0) * 30.0f;
    o->oMoveAngleYaw += 0x400;
    o->oFaceAngleYaw = o->oMoveAngleYaw + 0x4000;

    // Handle attacks
    check_amp_attack();

    // Oscillate
    o->oAmpYPhase++;

    cur_obj_play_sound_1(SOUND_AIR_AMP_BUZZ);
}

/**
 * Circling amp update function.
 * This calls the main update functions for both types of circling amps,
 * and calls the common amp cooldown function when the amp is cooling down.
 */
void bhv_circling_amp_loop(void) {
    switch (o->oAction) {
        case AMP_ACT_IDLE:
            if (o->oBhvParams2ndByte == AMP_BP_ROT_RADIUS_0) {
                fixed_circling_amp_idle_loop();
            } else {
                circling_amp_idle_loop();
            }
            break;

        case AMP_ACT_ATTACK_COOLDOWN:
            amp_attack_cooldown_loop();
            break;
    }
}
