/**
 * Behavior for MIPS (everyone's favorite yellow rabbit).
 */

/**
 * Initializes MIPS' physics parameters and checks if he should be active,
 * hiding him if necessary.
 */
void bhv_mips_init(void) {
    // Retrieve star flags for Castle Secret Stars on current save file.
    u8 starFlags = save_file_get_star_flags(gCurrSaveFileNum - 1, COURSE_NUM_TO_INDEX(COURSE_NONE));

    // If the player has >= 15 stars and hasn't collected first MIPS star...
    if (save_file_get_total_star_count(gCurrSaveFileNum - 1, COURSE_MIN - 1, COURSE_MAX - 1) >= MIPS1_STAR_REQ
        && !(starFlags & SAVE_FLAG_TO_STAR_FLAG(SAVE_FLAG_COLLECTED_MIPS_STAR_1))) {
        o->oBhvParams2ndByte = MIPS_BP_15_STARS;
        o->oMipsForwardVelocity = 40.0f;
    }
    // If the player has >= 50 stars and hasn't collected second MIPS star...
    else if (save_file_get_total_star_count(gCurrSaveFileNum - 1, COURSE_MIN - 1, COURSE_MAX - 1) >= MIPS2_STAR_REQ
             && !(starFlags & SAVE_FLAG_TO_STAR_FLAG(SAVE_FLAG_COLLECTED_MIPS_STAR_2))) {
        o->oBhvParams2ndByte = MIPS_BP_50_STARS;
        o->oMipsForwardVelocity = 45.0f;
    } else {
        // No MIPS stars are available, hide MIPS.
        o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
    }

    o->oInteractionSubtype = INT_SUBTYPE_HOLDABLE_NPC;
    o->oGravity = 15.0f;
    o->oFriction = 0.89f;
    o->oBuoyancy = 1.2f;

    cur_obj_init_animation(0);
}

/**
 * Helper function that finds the waypoint that is both within 800 units of MIPS
 * and furthest from Mario's current location.
 */
s16 bhv_mips_find_furthest_waypoint_to_mario(void) {
    s8 i;
    s16 x, y, z;
    s16 furthestWaypointIndex = -1;
    f32 furthestWaypointDistance = -10000.0f;
    f32 distanceToPlayer;
    struct Waypoint **pathBase = segmented_to_virtual(&inside_castle_seg7_trajectory_mips);

    // For each waypoint in MIPS path...
    for (i = 0; i < 10; i++) {
        struct Waypoint *waypoint = segmented_to_virtual(pathBase[i]);
        x = waypoint->pos[0];
        y = waypoint->pos[1];
        z = waypoint->pos[2];

        // Is the waypoint within 800 units of MIPS?
        if (is_point_close_to_object(o, x, y, z, 800)) {
            // Is this further from Mario than the last waypoint?
            distanceToPlayer =
                sqr(x - gPlayerObject->header.gfx.pos[0]) + sqr(z - gPlayerObject->header.gfx.pos[2]);
            if (furthestWaypointDistance < distanceToPlayer) {
                furthestWaypointIndex = i;
                furthestWaypointDistance = distanceToPlayer;
            }
        }
    }

    // Set MIPS' next waypoint to be the closest waypoint to Mario.
    o->oMipsStartWaypointIndex = furthestWaypointIndex;
    return (s16) o->oMipsStartWaypointIndex;
}

/**
 * Wait until Mario comes close, then resume following our path.
 */
void bhv_mips_act_wait_for_nearby_mario(void) {
    UNUSED s16 collisionFlags = 0;

    o->oForwardVel = 0.0f;
    collisionFlags = object_step();

    // If Mario is within 500 units...
    if (is_point_within_radius_of_player(o->oPosX, o->oPosY, o->oPosZ, 500)) {
        // If we fail to find a suitable waypoint...
        if (bhv_mips_find_furthest_waypoint_to_mario() == -1) {
            // Call it quits.
            o->oAction = MIPS_ACT_WAIT_FOR_ANIMATION_DONE;
        } else {
            // Resume path following.
            cur_obj_init_animation(1);
            o->oAction = MIPS_ACT_FOLLOW_PATH;
        }
    }
}

extern s16 gCurrLevelNum;

/**
 * Continue to follow our path around the basement area.
 */
void bhv_mips_act_follow_path(void) {
    // Retrieve current waypoint.
    struct Waypoint **pathBase = segmented_to_virtual(&inside_castle_seg7_trajectory_mips);
    struct Waypoint *waypoint = segmented_to_virtual(*(pathBase + o->oMipsStartWaypointIndex));

    // Set start waypoint and follow the path from there.
    o->oPathedStartWaypoint = waypoint;
    s32 followStatus = cur_obj_follow_path();

    // Update velocity and angle and do movement.
    o->oForwardVel = o->oMipsForwardVelocity;
    o->oMoveAngleYaw = o->oPathedTargetYaw;
    s16 collisionFlags = object_step();

    // If we are at the end of the path, do idle animation and wait for Mario.
    if (followStatus == PATH_REACHED_END) {
        cur_obj_init_animation(0);
        o->oAction = MIPS_ACT_WAIT_FOR_NEARBY_MARIO;
    }

    // Play sounds during walk animation.
    if (cur_obj_check_if_near_animation_end() == TRUE && (collisionFlags & OBJ_COL_FLAG_UNDERWATER)) {
        cur_obj_play_sound_2(SOUND_OBJ_MIPS_RABBIT_WATER);
        spawn_object(o, MODEL_NONE, bhvShallowWaterSplash);
    } else if (cur_obj_check_if_near_animation_end() == TRUE) {
        cur_obj_play_sound_2(SOUND_OBJ_MIPS_RABBIT);
    }
}

/**
 * Seems to wait until the current animation is done, then go idle.
 */
void bhv_mips_act_wait_for_animation_done(void) {
    if (cur_obj_check_if_near_animation_end() == TRUE) {
        cur_obj_init_animation(0);
        o->oAction = MIPS_ACT_IDLE;
    }
}

/**
 * Handles MIPS falling down after being thrown.
 */
void bhv_mips_act_fall_down(void) {
    s16 collisionFlags = 0;

    collisionFlags = object_step();
    o->header.gfx.animInfo.animFrame = 0;

    if ((collisionFlags & OBJ_COL_FLAG_GROUNDED) == OBJ_COL_FLAG_GROUNDED) {
        o->oAction = MIPS_ACT_WAIT_FOR_ANIMATION_DONE;

        o->oFlags |= OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW;
        o->oMoveAngleYaw = o->oFaceAngleYaw;

        if (collisionFlags & OBJ_COL_FLAG_UNDERWATER) {
            spawn_object(o, MODEL_NONE, bhvShallowWaterSplash);
        }
    }
}

/**
 * Idle loop, after you catch MIPS and put him down.
 */
void bhv_mips_act_idle(void) {
    UNUSED s16 collisionFlags = 0;

    o->oForwardVel = 0.0f;
    collisionFlags = object_step();

    // Spawn a star if he was just picked up for the first time.
    if ((o->oMipsStarStatus == MIPS_STAR_STATUS_SHOULD_SPAWN_STAR)) {
        bhv_spawn_star_no_level_exit(STAR_INDEX_ACT_4 + o->oBhvParams2ndByte);
        o->oMipsStarStatus = MIPS_STAR_STATUS_ALREADY_SPAWNED_STAR;
    }
}

/**
 * Handles all the actions MIPS does when he is not held.
 */
void bhv_mips_free(void) {
    switch (o->oAction) {
        case MIPS_ACT_WAIT_FOR_NEARBY_MARIO:
            bhv_mips_act_wait_for_nearby_mario();
            break;

        case MIPS_ACT_FOLLOW_PATH:
            bhv_mips_act_follow_path();
            break;

        case MIPS_ACT_WAIT_FOR_ANIMATION_DONE:
            bhv_mips_act_wait_for_animation_done();
            break;

        case MIPS_ACT_FALL_DOWN:
            bhv_mips_act_fall_down();
            break;

        case MIPS_ACT_IDLE:
            bhv_mips_act_idle();
            break;
    }
}

/**
 * Handles MIPS being held by Mario.
 */
void bhv_mips_held(void) {
    s16 dialogID;

    o->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
    cur_obj_init_animation(4); // Held animation.
    cur_obj_set_pos_relative(gPlayerObject, 0, 60.0f, 100.0f);
    cur_obj_become_intangible();

    // If MIPS hasn't spawned his star yet...
    if (o->oMipsStarStatus == MIPS_STAR_STATUS_HAVENT_SPAWNED_STAR) {
        // Choose dialog based on which MIPS encounter this is.
        if (o->oBhvParams2ndByte == MIPS_BP_15_STARS) {
            dialogID = DIALOG_084;
        } else { // MIPS_BP_50_STARS
            dialogID = DIALOG_162;
        }

        if (set_player_npc_dialog(MARIO_DIALOG_LOOK_FRONT) == MARIO_DIALOG_STATUS_SPEAK) {
            o->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
            if (cutscene_object_with_dialog(CUTSCENE_DIALOG, o, dialogID) != 0) {
                o->oInteractionSubtype |= INT_SUBTYPE_DROP_IMMEDIATELY;
                o->activeFlags &= ~ACTIVE_FLAG_INITIATED_TIME_STOP;
                o->oMipsStarStatus = MIPS_STAR_STATUS_SHOULD_SPAWN_STAR;
                set_player_npc_dialog(MARIO_DIALOG_STOP);
            }
        }
    }
}

/**
 * Handles MIPS being dropped by Mario.
 */
void bhv_mips_dropped(void) {
    cur_obj_get_dropped();
    o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
    cur_obj_init_animation(0);
    o->oHeldState = HELD_FREE;
    cur_obj_become_tangible();
    o->oForwardVel = 3.0f;
    o->oAction = MIPS_ACT_IDLE;
}

/**
 * Handles MIPS being thrown by Mario.
 */
void bhv_mips_thrown(void) {
    cur_obj_enable_rendering_2();
    o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
    o->oHeldState = HELD_FREE;
    o->oFlags &= ~OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW;
    cur_obj_init_animation(2);
    cur_obj_become_tangible();
    o->oForwardVel = 25.0f;
    o->oVelY = 20.0f;
    o->oAction = MIPS_ACT_FALL_DOWN;
}

/**
 * MIPS' main loop.
 */
void bhv_mips_loop(void) {
    // Determine what to do based on MIPS' held status.
    switch (o->oHeldState) {
        case HELD_FREE:
            bhv_mips_free();
            break;

        case HELD_HELD:
            bhv_mips_held();
            break;

        case HELD_THROWN:
            bhv_mips_thrown();
            break;

        case HELD_DROPPED:
            bhv_mips_dropped();
            break;
    }
}
