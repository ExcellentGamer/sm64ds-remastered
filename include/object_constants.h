#ifndef OBJECT_CONSTANTS_H
#define OBJECT_CONSTANTS_H

// This file contains macros that provide descriptive names for
// field-specific and object-specific constants, e.g. actions.

/* activeFlags */
#define ACTIVE_FLAG_DEACTIVATED            0         // 0x0000
#define ACTIVE_FLAG_ACTIVE                 (1 <<  0) // 0x0001
#define ACTIVE_FLAG_FAR_AWAY               (1 <<  1) // 0x0002
#define ACTIVE_FLAG_UNK2                   (1 <<  2) // 0x0004
#define ACTIVE_FLAG_IN_DIFFERENT_ROOM      (1 <<  3) // 0x0008
#define ACTIVE_FLAG_UNIMPORTANT            (1 <<  4) // 0x0010
#define ACTIVE_FLAG_INITIATED_TIME_STOP    (1 <<  5) // 0x0020
#define ACTIVE_FLAG_MOVE_THROUGH_GRATE     (1 <<  6) // 0x0040
#define ACTIVE_FLAG_DITHERED_ALPHA         (1 <<  7) // 0x0080
#define ACTIVE_FLAG_ALLOCATED              (1 <<  8) // 0x0100
#define ACTIVE_FLAG_UNK9                   (1 <<  9) // 0x0200
#define ACTIVE_FLAG_UNK10                  (1 << 10) // 0x0400

/* respawnInfo */
#define RESPAWN_INFO_DONT_RESPAWN 0xFF

/* oFlags */
#define OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE         (1 <<  0) // 0x00000001
#define OBJ_FLAG_MOVE_XZ_USING_FVEL               (1 <<  1) // 0x00000002
#define OBJ_FLAG_MOVE_Y_WITH_TERMINAL_VEL         (1 <<  2) // 0x00000004
#define OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW         (1 <<  3) // 0x00000008
#define OBJ_FLAG_SET_FACE_ANGLE_TO_MOVE_ANGLE     (1 <<  4) // 0x00000010
#define OBJ_FLAG_0020                             (1 <<  5) // 0x00000020
#define OBJ_FLAG_COMPUTE_DIST_TO_MARIO            (1 <<  6) // 0x00000040
#define OBJ_FLAG_ACTIVE_FROM_AFAR                 (1 <<  7) // 0x00000080
#define OBJ_FLAG_0100                             (1 <<  8) // 0x00000100
#define OBJ_FLAG_TRANSFORM_RELATIVE_TO_PARENT     (1 <<  9) // 0x00000200
#define OBJ_FLAG_HOLDABLE                         (1 << 10) // 0x00000400
#define OBJ_FLAG_SET_THROW_MATRIX_FROM_TRANSFORM  (1 << 11) // 0x00000800
#define OBJ_FLAG_1000                             (1 << 12) // 0x00001000
#define OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO           (1 << 13) // 0x00002000
#define OBJ_FLAG_PERSISTENT_RESPAWN               (1 << 14) // 0x00004000
#define OBJ_FLAG_VELOCITY_PLATFORM                (1 << 15) // 0x00008000
#define OBJ_FLAG_DONT_CALC_COLL_DIST              (1 << 16) // 0x00010000
#if OBJ_OPACITY_BY_CAM_DIST
#define OBJ_FLAG_OPACITY_FROM_CAMERA_DIST         (1 << 21) // 0x00200000
#else
#define OBJ_FLAG_OPACITY_FROM_CAMERA_DIST         (0 << 0)
#endif
#if PROCESS_ONLY_ON_ROOM_PARENT
#define OBJ_FLAG_ONLY_PROCESS_INSIDE_ROOM         (1 << 23) // 0x00800000
#else
#define OBJ_FLAG_ONLY_PROCESS_INSIDE_ROOM         (0 << 0)
#endif

#define OBJ_FLAG_HITBOX_WAS_SET                   (1 << 30) // 0x40000000

/* oHeldState */
#define HELD_FREE    0
#define HELD_HELD    1
#define HELD_THROWN  2
#define HELD_DROPPED 3

/* oDialogState */
#define DIALOG_STATUS_ENABLE_TIME_STOP  0
#define DIALOG_STATUS_INTERRUPT         1
#define DIALOG_STATUS_START_DIALOG      2
#define DIALOG_STATUS_STOP_DIALOG       3
#define DIALOG_STATUS_DISABLE_TIME_STOP 4

#define DIALOG_FLAG_NONE                0
#define DIALOG_FLAG_TURN_TO_MARIO       (1 << 0) // 0x01 // cutscene only
#define DIALOG_FLAG_TEXT_DEFAULT        (1 << 1) // 0x02
#define DIALOG_FLAG_TEXT_RESPONSE       (1 << 2) // 0x04 // non-cutscene only
#define DIALOG_FLAG_UNK_CAPSWITCH       (1 << 3) // 0x08 // not defined
#define DIALOG_FLAG_TIME_STOP_ENABLED   (1 << 4) // 0x10

/* oMoveFlags */
#define OBJ_MOVE_LANDED                (1 <<  0) // 0x0001
#define OBJ_MOVE_ON_GROUND             (1 <<  1) // 0x0002  // mutually exclusive to OBJ_MOVE_LANDED
#define OBJ_MOVE_LEFT_GROUND           (1 <<  2) // 0x0004
#define OBJ_MOVE_ENTERED_WATER         (1 <<  3) // 0x0008
#define OBJ_MOVE_AT_WATER_SURFACE      (1 <<  4) // 0x0010
#define OBJ_MOVE_UNDERWATER_OFF_GROUND (1 <<  5) // 0x0020
#define OBJ_MOVE_UNDERWATER_ON_GROUND  (1 <<  6) // 0x0040
#define OBJ_MOVE_IN_AIR                (1 <<  7) // 0x0080
#define OBJ_MOVE_OUT_SCOPE             (1 <<  8) // 0x0100
#define OBJ_MOVE_HIT_WALL              (1 <<  9) // 0x0200
#define OBJ_MOVE_HIT_EDGE              (1 << 10) // 0x0400
#define OBJ_MOVE_ABOVE_LAVA            (1 << 11) // 0x0800
#define OBJ_MOVE_LEAVING_WATER         (1 << 12) // 0x1000
#define OBJ_MOVE_BOUNCE                (1 << 13) // 0x2000
#define OBJ_MOVE_ABOVE_DEATH_BARRIER   (1 << 14) // 0x4000

#define OBJ_MOVE_MASK_ON_GROUND (OBJ_MOVE_LANDED | OBJ_MOVE_ON_GROUND)
#define OBJ_MOVE_MASK_IN_WATER ( \
    OBJ_MOVE_ENTERED_WATER | \
    OBJ_MOVE_AT_WATER_SURFACE | \
    OBJ_MOVE_UNDERWATER_OFF_GROUND | \
    OBJ_MOVE_UNDERWATER_ON_GROUND)

/* oActiveParticleFlags */
#define ACTIVE_PARTICLE_DUST                 (1 <<  0) // 0x00000001
#define ACTIVE_PARTICLE_UNUSED_1             (1 <<  1) // 0x00000002
#define ACTIVE_PARTICLE_UNUSED_2             (1 <<  2) // 0x00000004
#define ACTIVE_PARTICLE_SPARKLES             (1 <<  3) // 0x00000008
#define ACTIVE_PARTICLE_H_STAR               (1 <<  4) // 0x00000010
#define ACTIVE_PARTICLE_BUBBLE               (1 <<  5) // 0x00000020
#define ACTIVE_PARTICLE_WATER_SPLASH         (1 <<  6) // 0x00000040
#define ACTIVE_PARTICLE_IDLE_WATER_WAVE      (1 <<  7) // 0x00000080
#define ACTIVE_PARTICLE_SHALLOW_WATER_WAVE   (1 <<  8) // 0x00000100
#define ACTIVE_PARTICLE_PLUNGE_BUBBLE        (1 <<  9) // 0x00000200
#define ACTIVE_PARTICLE_WAVE_TRAIL           (1 << 10) // 0x00000400
#define ACTIVE_PARTICLE_FIRE                 (1 << 11) // 0x00000800
#define ACTIVE_PARTICLE_SHALLOW_WATER_SPLASH (1 << 12) // 0x00001000
#define ACTIVE_PARTICLE_LEAF                 (1 << 13) // 0x00002000
#define ACTIVE_PARTICLE_DIRT                 (1 << 14) // 0x00004000
#define ACTIVE_PARTICLE_MIST_CIRCLE          (1 << 15) // 0x00008000
#define ACTIVE_PARTICLE_SNOW                 (1 << 16) // 0x00010000
#define ACTIVE_PARTICLE_BREATH               (1 << 17) // 0x00020000
#define ACTIVE_PARTICLE_V_STAR               (1 << 18) // 0x00040000
#define ACTIVE_PARTICLE_TRIANGLE             (1 << 19) // 0x00080000

/* oAction */
#define OBJ_ACT_LAVA_DEATH        100
#define OBJ_ACT_DEATH_PLANE_DEATH 101

#define OBJ_ACT_HORIZONTAL_KNOCKBACK 100
#define OBJ_ACT_VERTICAL_KNOCKBACK   101
#define OBJ_ACT_SQUISHED             102

/* Star Index */
#define STAR_INDEX_ACT_1     0
#define STAR_INDEX_ACT_2     1
#define STAR_INDEX_ACT_3     2
#define STAR_INDEX_ACT_4     3
#define STAR_INDEX_ACT_5     4
#define STAR_INDEX_ACT_6     5
#define STAR_INDEX_ACT_7     6
#define STAR_INDEX_100_COINS 7
#define STAR_INDEX_CANNON    8

/* gTTCSpeedSetting */
#define TTC_SPEED_SLOW    0
#define TTC_SPEED_FAST    1
#define TTC_SPEED_RANDOM  2
#define TTC_SPEED_STOPPED 3

/* King Bob-omb */
    /* oBhvParams2ndByte */
    #define BOBOMB_KING_BP_TYPE_1 0
    #define BOBOMB_KING_BP_TYPE_2 1

/* Bob-omb */
    /* oBhvParams2ndByte */
    #define BOBOMB_BP_STYPE_GENERIC    0
    #define BOBOMB_BP_STYPE_STATIONARY 1

    /* oAction */
    #define BOBOMB_ACT_PATROL            0
    #define BOBOMB_ACT_LAUNCHED          1
    #define BOBOMB_ACT_CHASE_MARIO       2
    #define BOBOMB_ACT_EXPLODE           3
    #define BOBOMB_ACT_LAVA_DEATH        100
    #define BOBOMB_ACT_DEATH_PLANE_DEATH 101

/* Coin Formation */
    /* oAction */
    #define COIN_FORMATION_ACT_SPAWN_COINS   0
    #define COIN_FORMATION_ACT_IDLE          1
    #define COIN_FORMATION_ACT_RESPAWN_COINS 2

    /* oBhvParams2ndByte */
    #define COIN_FORMATION_BP_FLAG_HORIZONTAL (0 << 0)
    #define COIN_FORMATION_BP_FLAG_VERTICAL   (1 << 0)
    #define COIN_FORMATION_BP_FLAG_RING       (1 << 1)
    #define COIN_FORMATION_BP_FLAG_ARROW      (1 << 2)
    #define COIN_FORMATION_BP_FLAG_FLYING     (1 << 4)
    #define COIN_FORMATION_BP_FLAG_MASK       (COIN_FORMATION_BP_FLAG_HORIZONTAL | \
                                               COIN_FORMATION_BP_FLAG_VERTICAL | \
                                               COIN_FORMATION_BP_FLAG_RING | \
                                               COIN_FORMATION_BP_FLAG_ARROW)

    #define COIN_FORMATION_BP_LINE_HORIZONTAL (COIN_FORMATION_BP_FLAG_HORIZONTAL)
    #define COIN_FORMATION_BP_LINE_VERTICAL   (COIN_FORMATION_BP_FLAG_VERTICAL)
    #define COIN_FORMATION_BP_RING_HORIZONTAL (COIN_FORMATION_BP_FLAG_HORIZONTAL | COIN_FORMATION_BP_FLAG_RING)
    #define COIN_FORMATION_BP_RING_VERTICAL   (COIN_FORMATION_BP_FLAG_VERTICAL | COIN_FORMATION_BP_FLAG_RING)
    #define COIN_FORMATION_BP_ARROW           (COIN_FORMATION_BP_FLAG_ARROW)

/* Hidden Blue Coin */
    /* oAction */
    #define HIDDEN_BLUE_COIN_ACT_INACTIVE 0
    #define HIDDEN_BLUE_COIN_ACT_WAITING  1
    #define HIDDEN_BLUE_COIN_ACT_ACTIVE   2

/* Blue Coin Switch */
    /* oAction */
    #define BLUE_COIN_SWITCH_ACT_IDLE      0
    #define BLUE_COIN_SWITCH_ACT_RECEDING  1
    #define BLUE_COIN_SWITCH_ACT_TICKING   2
    #define BLUE_COIN_SWITCH_ACT_EXTENDING 3 // Used in QOL_FEATURES

/* Moving Blue Coin */
    /* oAction */
    #define MOV_BCOIN_ACT_STILL  0
    #define MOV_BCOIN_ACT_MOVING 1

/* Moving Yellow Coin */
    /* oAction */
    #define MOV_YCOIN_ACT_IDLE              0
    #define MOV_YCOIN_ACT_BLINKING          1
    #define MOV_YCOIN_ACT_LAVA_DEATH        100
    #define MOV_YCOIN_ACT_DEATH_PLANE_DEATH 101

/* Bob-omb Buddy */
    /* oBhvParams2ndByte */
    #define BOBOMB_BUDDY_BP_STYPE_GENERIC        0
    #define BOBOMB_BUDDY_BP_STYPE_BOB_GRASS_KBB  1
    #define BOBOMB_BUDDY_BP_STYPE_BOB_CANNON_KBB 2
    #define BOBOMB_BUDDY_BP_STYPE_BOB_GRASS      3

    /* oAction */
    #define BOBOMB_BUDDY_ACT_IDLE         0
    #define BOBOMB_BUDDY_ACT_TURN_TO_TALK 2
    #define BOBOMB_BUDDY_ACT_TALK         3

    /* oBobombBuddyRole */
    #define BOBOMB_BUDDY_ROLE_ADVICE 0
    #define BOBOMB_BUDDY_ROLE_CANNON 1

    /* oBobombBuddyCannonStatus */
    #define BOBOMB_BUDDY_CANNON_UNOPENED     0
    #define BOBOMB_BUDDY_CANNON_OPENING      1
    #define BOBOMB_BUDDY_CANNON_OPENED       2
    #define BOBOMB_BUDDY_CANNON_STOP_TALKING 3

    /* oBobombBuddyHasTalkedToPlayer */
    #define BOBOMB_BUDDY_HAS_NOT_TALKED 0
    #define BOBOMB_BUDDY_HAS_TALKED     2

/* Bowser */
    /* Tail oAction */
    #define BOWSER_ACT_TAIL_DEFAULT         0
    #define BOWSER_ACT_TAIL_THROWN          1
    #define BOWSER_ACT_TAIL_TOUCHED_MARIO   2

    /* oAction */
    #define BOWSER_ACT_DEFAULT              0
    #define BOWSER_ACT_THROWN               1
    #define BOWSER_ACT_JUMP_ONTO_STAGE      2
    #define BOWSER_ACT_DANCE                3
    #define BOWSER_ACT_DEAD                 4
    #define BOWSER_ACT_WAIT                 5
    #define BOWSER_ACT_INTRO_WALK           6
    #define BOWSER_ACT_CHARGE_MARIO         7
    #define BOWSER_ACT_SPIT_FIRE_INTO_SKY   8
    #define BOWSER_ACT_SPIT_FIRE_ONTO_FLOOR 9
    #define BOWSER_ACT_HIT_EDGE             10
    #define BOWSER_ACT_TURN_FROM_EDGE       11
    #define BOWSER_ACT_HIT_MINE             12
    #define BOWSER_ACT_BIG_JUMP             13
    #define BOWSER_ACT_WALK_TO_MARIO        14
    #define BOWSER_ACT_BREATH_FIRE          15
    #define BOWSER_ACT_TELEPORT             16
    #define BOWSER_ACT_QUICK_JUMP           17
    #define BOWSER_ACT_UNUSED_SLOW_WALK     18
    #define BOWSER_ACT_TILT_LAVA_PLATFORM   19

    /* Animations */
    #define BOWSER_ANIM_STAND_UP            0
    #define BOWSER_ANIM_STAND_UP_UNUSED     1 // slightly different
    #define BOWSER_ANIM_SHAKING             2
    #define BOWSER_ANIM_GRABBED             3
    #define BOWSER_ANIM_BROKEN              4 // broken animation
    #define BOWSER_ANIM_FALL_DOWN           5 // unused
    #define BOWSER_ANIM_BREATH              6
    #define BOWSER_ANIM_JUMP                7 // unused, short jump, replaced by start/stop
    #define BOWSER_ANIM_JUMP_STOP           8
    #define BOWSER_ANIM_JUMP_START          9
    #define BOWSER_ANIM_DANCE               10
    #define BOWSER_ANIM_BREATH_UP           11
    #define BOWSER_ANIM_IDLE                12
    #define BOWSER_ANIM_SLOW_GAIT           13
    #define BOWSER_ANIM_LOOK_DOWN_STOP_WALK 14
    #define BOWSER_ANIM_LOOK_UP_START_WALK  15
    #define BOWSER_ANIM_FLIP_DOWN           16
    #define BOWSER_ANIM_LAY_DOWN            17
    #define BOWSER_ANIM_RUN_START           18
    #define BOWSER_ANIM_RUN                 19
    #define BOWSER_ANIM_RUN_STOP            20
    #define BOWSER_ANIM_RUN_SLIP            21
    #define BOWSER_ANIM_BREATH_QUICK        22
    #define BOWSER_ANIM_EDGE_MOVE           23
    #define BOWSER_ANIM_EDGE_STOP           24
    #define BOWSER_ANIM_FLIP                25
    #define BOWSER_ANIM_STAND_UP_FROM_FLIP  26

    /* oBhvParams2ndByte */
    #define BOWSER_BP_BITDW 0
    #define BOWSER_BP_BITFS 1
    #define BOWSER_BP_BITS  2

    /* oBowserCamAct */
    #define BOWSER_CAM_ACT_IDLE 0
    #define BOWSER_CAM_ACT_WALK 1
    #define BOWSER_CAM_ACT_END  2

    /* oBowserStatus */
    #define BOWSER_STATUS_ANGLE_MARIO   (1 <<  1) // 0x00000002
    #define BOWSER_STATUS_ANGLE_CENTER  (1 <<  2) // 0x00000004
    #define BOWSER_STATUS_DIST_MARIO    (1 <<  3) // 0x00000008
    #define BOWSER_STATUS_DIST_CENTER   (1 <<  4) // 0x00000010
    #define BOWSER_STATUS_BIG_JUMP      (1 << 16) // 0x00010000
    #define BOWSER_STATUS_FIRE_SKY      (1 << 17) // 0x00020000

    /* oBowserGrabbedStatus */
    #define BOWSER_GRAB_STATUS_NONE     0
    #define BOWSER_GRAB_STATUS_GRABBED  1
    #define BOWSER_GRAB_STATUS_HOLDING  2

    /* oSubAction */
    #define BOWSER_SUB_ACT_DEAD_FLY_BACK            0
    #define BOWSER_SUB_ACT_DEAD_BOUNCE              1
    #define BOWSER_SUB_ACT_DEAD_WAIT                2
    #define BOWSER_SUB_ACT_DEAD_DEFAULT_END         3
    #define BOWSER_SUB_ACT_DEAD_DEFAULT_END_OVER    4
    #define BOWSER_SUB_ACT_DEAD_FINAL_END           10
    #define BOWSER_SUB_ACT_DEAD_FINAL_END_OVER      11

    #define BOWSER_SUB_ACT_CHARGE_START             0
    #define BOWSER_SUB_ACT_CHARGE_RUN               1
    #define BOWSER_SUB_ACT_CHARGE_END               2
    #define BOWSER_SUB_ACT_CHARGE_SLIP              3

    #define BOWSER_SUB_ACT_TELEPORT_START           0
    #define BOWSER_SUB_ACT_TELEPORT_MOVE            1
    #define BOWSER_SUB_ACT_TELEPORT_STOP            2

    #define BOWSER_SUB_ACT_HIT_MINE_START           0
    #define BOWSER_SUB_ACT_HIT_MINE_FALL            1
    #define BOWSER_SUB_ACT_HIT_MINE_STOP            2

    #define BOWSER_SUB_ACT_JUMP_ON_STAGE_IDLE       0
    #define BOWSER_SUB_ACT_JUMP_ON_STAGE_START      1
    #define BOWSER_SUB_ACT_JUMP_ON_STAGE_LAND       2
    #define BOWSER_SUB_ACT_JUMP_ON_STAGE_STOP       3

/* Bowser BitS Platform */
    /* oAction */
    #define BOWSER_BITS_PLAT_ACT_START 0
    #define BOWSER_BITS_PLAT_ACT_CHECK 1
    #define BOWSER_BITS_PLAT_ACT_FALL  2

/* Fish Spawer */
    /* oAction */
    #define FISH_SPAWNER_ACT_SPAWN   0
    #define FISH_SPAWNER_ACT_IDLE    1
    #define FISH_SPAWNER_ACT_RESPAWN 2

    /* oBhvParams2ndByte */
    #define FISH_SPAWNER_BP_MANY_BLUE 0
    #define FISH_SPAWNER_BP_FEW_BLUE  1
    #define FISH_SPAWNER_BP_MANY_CYAN 2
    #define FISH_SPAWNER_BP_FEW_CYAN  3

/* Fish */
    /* oAction */
    #define FISH_ACT_INIT 0
    #define FISH_ACT_ROAM 1
    #define FISH_ACT_FLEE 2

/* Blue Fish */
    /* oAction */
    #define BLUE_FISH_ACT_DIVE      0
    #define BLUE_FISH_ACT_TURN      1
    #define BLUE_FISH_ACT_ASCEND    2
    #define BLUE_FISH_ACT_TURN_BACK 3

    /* oAction: bhv_blue_fish_spawn_loop */
    #define BLUE_FISH_ACT_SPAWN     0
    #define BLUE_FISH_ACT_ROOM      1
    #define BLUE_FISH_ACT_DUPLICATE 2

/* Cannon Trap Door */
    /* oAction */
    #define CANNON_TRAP_DOOR_ACT_CLOSED   0
    #define CANNON_TRAP_DOOR_ACT_CAM_ZOOM 1
    #define CANNON_TRAP_DOOR_ACT_OPENING  2
    #define CANNON_TRAP_DOOR_ACT_OPEN     3

/* Homing Amp */
    /* oAction */
    #define HOMING_AMP_ACT_INACTIVE        0
    #define HOMING_AMP_ACT_APPEAR          1
    #define HOMING_AMP_ACT_CHASE           2
    #define HOMING_AMP_ACT_GIVE_UP         3
    #define HOMING_AMP_ACT_ATTACK_COOLDOWN 4

/* Amp */
    /* oBhvParams2ndByte */
    #define AMP_BP_ROT_RADIUS_200 0
    #define AMP_BP_ROT_RADIUS_300 1
    #define AMP_BP_ROT_RADIUS_400 2
    #define AMP_BP_ROT_RADIUS_0   3

    /* oAction */
    #define AMP_ACT_IDLE            2
    #define AMP_ACT_ATTACK_COOLDOWN 4

/* Butterfly */
    /* oAction */
    #define BUTTERFLY_ACT_RESTING      0
    #define BUTTERFLY_ACT_FOLLOW_MARIO 1
    #define BUTTERFLY_ACT_RETURN_HOME  2

/* Hoot */
    /* oHootAvailability */
    #define HOOT_AVAIL_ASLEEP_IN_TREE 0
    #define HOOT_AVAIL_WANTS_TO_TALK  1
    #define HOOT_AVAIL_READY_TO_FLY   2

    /* oAction */
    #define HOOT_ACT_ASCENT 0
    #define HOOT_ACT_CARRY  1
    #define HOOT_ACT_TIRED  2

/* Bully (All variants) */
    /* oBhvParams2ndByte */
    #define BULLY_BP_SIZE_SMALL 0
    #define BULLY_BP_SIZE_BIG   1

    /* oAction */
    #define BULLY_ACT_PATROL            0
    #define BULLY_ACT_CHASE_MARIO       1
    #define BULLY_ACT_KNOCKBACK         2
    #define BULLY_ACT_BACK_UP           3
    #define BULLY_ACT_INACTIVE          4
    #define BULLY_ACT_ACTIVATE_AND_FALL 5
    #define BULLY_ACT_LAVA_DEATH        100
    #define BULLY_ACT_DEATH_PLANE_DEATH 101

    /* oBullySubtype */
    #define BULLY_STYPE_GENERIC 0
    #define BULLY_STYPE_MINION  1
    #define BULLY_STYPE_CHILL   16

/* Water Ring (All variants) */
    /* oAction */
    #define WATER_RING_ACT_NOT_COLLECTED 0
    #define WATER_RING_ACT_COLLECTED     1

/* Jet Stream Water Ring Spawner */
    /* oAction */
    #define JS_RING_SPAWNER_ACT_ACTIVE   0
    #define JS_RING_SPAWNER_ACT_INACTIVE 1

/* Celebration Star */
    /* oAction */
    #define CELEB_STAR_ACT_SPIN_AROUND_MARIO 0
    #define CELEB_STAR_ACT_FACE_CAMERA       1

/* LLL Drawbridge */
    /* oAction */
    #define LLL_DRAWBRIDGE_ACT_LOWER 0
    #define LLL_DRAWBRIDGE_ACT_RAISE 1

/* Bomp (Both variants) */
    /* oAction */
    #define BOMP_ACT_WAIT     0
    #define BOMP_ACT_POKE_OUT 1
    #define BOMP_ACT_EXTEND   2
    #define BOMP_ACT_RETRACT  3

/* WF Sliding Brick Platform */
    /* oBhvParams2ndByte */
    #define WF_SLID_BRICK_PTFM_BP_MOV_VEL_10 1
    #define WF_SLID_BRICK_PTFM_BP_MOV_VEL_15 2
    #define WF_SLID_BRICK_PTFM_BP_MOV_VEL_20 3

    /* oAction */
    #define WF_SLID_BRICK_PTFM_ACT_WAIT    0
    #define WF_SLID_BRICK_PTFM_ACT_EXTEND  1
    #define WF_SLID_BRICK_PTFM_ACT_RETRACT 2

/* Fake Moneybag Coin */
    /* oAction */
    #define FAKE_MONEYBAG_COIN_ACT_IDLE      0
    #define FAKE_MONEYBAG_COIN_ACT_TRANSFORM 1

/* Moneybag */
    /* oAction */
    #define MONEYBAG_ACT_APPEAR        0
    #define MONEYBAG_ACT_UNUSED_APPEAR 1
    #define MONEYBAG_ACT_MOVE_AROUND   2
    #define MONEYBAG_ACT_RETURN_HOME   3
    #define MONEYBAG_ACT_DISAPPEAR     4
    #define MONEYBAG_ACT_DEATH         5

    /* oMoneybagJumpState */
    #define MONEYBAG_JUMP_LANDING         0
    #define MONEYBAG_JUMP_PREPARE         1
    #define MONEYBAG_JUMP_JUMP            2
    #define MONEYBAG_JUMP_JUMP_AND_BOUNCE 3
    #define MONEYBAG_JUMP_WALK_AROUND     4
    #define MONEYBAG_JUMP_WALK_HOME       5

/* Bowling Ball */
    /* oAction */
    #define BBALL_ACT_INITIALIZE 0
    #define BBALL_ACT_ROLL       1

/* Bowling Ball + Bowling Ball Spawner (All variants) */
    /* oBhvParams2ndByte */
    #define BBALL_BP_STYPE_BOB_UPPER 0
    #define BBALL_BP_STYPE_TTM       1
    #define BBALL_BP_STYPE_BOB_LOWER 2
    #define BBALL_BP_STYPE_THI_LARGE 3
    #define BBALL_BP_STYPE_THI_SMALL 4

/* Bowling Ball (Free) */
    /* oAction */
    #define FREE_BBALL_ACT_IDLE  0
    #define FREE_BBALL_ACT_ROLL  1
    #define FREE_BBALL_ACT_RESET 2

/* Beta Chest Lid */
    /* oAction */
    #define BETA_CHEST_ACT_IDLE_CLOSED 0
    #define BETA_CHEST_ACT_OPENING     1
    #define BETA_CHEST_ACT_IDLE_OPEN   2

/* BBH Tilting Trap Platform */
    /* oAction */
    // Unused in original Japanese version
    #define BBH_TILTING_TRAP_PLATFORM_ACT_PLAYER_ON  0
    #define BBH_TILTING_TRAP_PLATFORM_ACT_PLAYER_OFF 1

/* Boo */
    /* oBooDeathStatus */
    #define BOO_DEATH_STATUS_ALIVE 0
    #define BOO_DEATH_STATUS_DYING 1
    #define BOO_DEATH_STATUS_DEAD  2

    /* attackStatus */
    #define BOO_NOT_ATTACKED 0
    #define BOO_ATTACKED     1
    #define BOO_BOUNCED_ON   -1

    /* oBhvParams2ndByte */
    #define BOO_BP_GHOST_HUNT     0
    #define BOO_BP_GENERIC        1
    #define BOO_BP_MERRY_GO_ROUND 2

/* Big Boo */
    /* oBhvParams2ndByte */
    #define BIG_BOO_BP_GHOST_HUNT     0
    #define BIG_BOO_BP_MERRY_GO_ROUND 1
    #define BIG_BOO_BP_BALCONY        2

/* Beta Boo Key */
    /* oAction */
    #define BETA_BOO_KEY_ACT_IN_BOO   0
    #define BETA_BOO_KEY_ACT_DROPPING 1
    #define BETA_BOO_KEY_ACT_DROPPED  2

/* Boo Cage */
    /* oAction */
    #define BOO_CAGE_ACT_IN_BOO            0
    #define BOO_CAGE_ACT_FALLING           1
    #define BOO_CAGE_ACT_ON_GROUND         2
    #define BOO_CAGE_ACT_PLAYER_JUMPING_IN 3
    #define BOO_CAGE_ACT_USELESS           4

/* BBH Haunted Bookshelf */
    /* oAction */
    #define HAUNTED_BOOKSHELF_ACT_IDLE   0
    #define HAUNTED_BOOKSHELF_ACT_RECEDE 1

/* BBH Merry-Go-Round */
    /* gPlayerCurrentRoom */
    #define BBH_NEAR_MERRY_GO_ROUND_ROOM 10
    #define BBH_DYNAMIC_SURFACE_ROOM     0
    #define BBH_OUTSIDE_ROOM             13

/* Coffin Spawner */
    /* oAction */
    #define COFFIN_SPAWNER_ACT_COFFINS_UNLOADED 0

/* Coffin */
    /* oAction */
    #define COFFIN_ACT_IDLE     0
    #define COFFIN_ACT_STAND_UP 1

    /* oBhvParams2ndByte */
    #define COFFIN_BP_STATIC 0

/* WDW Arrow Lift */
    /* oAction */
    #define ARROW_LIFT_ACT_IDLE        0
    #define ARROW_LIFT_ACT_MOVING_AWAY 1
    #define ARROW_LIFT_ACT_MOVING_BACK 2

    /* status */
    #define ARROW_LIFT_NOT_DONE_MOVING 0
    #define ARROW_LIFT_DONE_MOVING     1

/* Koopa */
    /* oAction */
    #define KOOPA_UNSHELLED_ACT_RUN     0
    #define KOOPA_UNSHELLED_ACT_DIVE    1
    #define KOOPA_UNSHELLED_ACT_LYING   2
    #define KOOPA_UNSHELLED_ACT_UNUSED3 3

    #define KOOPA_SHELLED_ACT_STOPPED         0
    #define KOOPA_SHELLED_ACT_WALK            1
    #define KOOPA_SHELLED_ACT_RUN_FROM_PLAYER 2
    #define KOOPA_SHELLED_ACT_LYING           3
    #define KOOPA_SHELLED_ACT_DIE             4

    #define KOOPA_THE_QUICK_ACT_WAIT_BEFORE_RACE 0
    #define KOOPA_THE_QUICK_ACT_UNUSED1          1
    #define KOOPA_THE_QUICK_ACT_SHOW_INIT_TEXT   2
    #define KOOPA_THE_QUICK_ACT_RACE             3
    #define KOOPA_THE_QUICK_ACT_DECELERATE       4
    #define KOOPA_THE_QUICK_ACT_STOP             5
    #define KOOPA_THE_QUICK_ACT_AFTER_RACE       6

    /* oSubAction */
    #define KOOPA_SHELLED_SUB_ACT_START_WALK 0
    #define KOOPA_SHELLED_SUB_ACT_WALK       1
    #define KOOPA_SHELLED_SUB_ACT_STOP_WALK  2

    #define KOOPA_THE_QUICK_SUB_ACT_START_RUN 0
    #define KOOPA_THE_QUICK_SUB_ACT_RUN       1
    #define KOOPA_THE_QUICK_SUB_ACT_JUMP      2

    /* oKoopaTheQuickRaceIndex */
    #define KOOPA_THE_QUICK_BOB_INDEX 0
    #define KOOPA_THE_QUICK_THI_INDEX 1

    /* oBhvParams2ndByte */
    #define KOOPA_BP_UNSHELLED            0
    #define KOOPA_BP_NORMAL               1
    #define KOOPA_BP_KOOPA_THE_QUICK_BASE 2
    #define KOOPA_BP_KOOPA_THE_QUICK_BOB  (KOOPA_BP_KOOPA_THE_QUICK_BASE + KOOPA_THE_QUICK_BOB_INDEX)
    #define KOOPA_BP_KOOPA_THE_QUICK_THI  (KOOPA_BP_KOOPA_THE_QUICK_BASE + KOOPA_THE_QUICK_THI_INDEX)
    #define KOOPA_BP_TINY                 4

/* Pokey */
    /* oAction */
    #define POKEY_ACT_UNINITIALIZED 0
    #define POKEY_ACT_WANDER        1
    #define POKEY_ACT_UNLOAD_PARTS  2

/* Swoop */
    /* oAction */
    #define SWOOP_ACT_IDLE 0
    #define SWOOP_ACT_MOVE 1

/* Fly Guy */
    /* oAction */
    #define FLY_GUY_ACT_IDLE           0
    #define FLY_GUY_ACT_APPROACH_MARIO 1
    #define FLY_GUY_ACT_LUNGE          2
    #define FLY_GUY_ACT_SHOOT_FIRE     3

    /* oBhvParams2ndByte */
    #define FLY_GUY_BP_GENERIC 0
    #define FLY_GUY_BP_FIRE    1

/* Goomba */
    /* oAction */
    #define GOOMBA_ACT_WALK           0
    #define GOOMBA_ACT_ATTACKED_MARIO 1
    #define GOOMBA_ACT_JUMP           2

    /* oBhvParams2ndByte */
    #define GOOMBA_SIZE_REGULAR                 0
    #define GOOMBA_SIZE_HUGE                    1
    #define GOOMBA_SIZE_TINY                    2
    #define GOOMBA_BP_SIZE_MASK                 (GOOMBA_SIZE_REGULAR | GOOMBA_SIZE_HUGE | GOOMBA_SIZE_TINY)
    #define GOOMBA_BP_TRIPLET_RESPAWN_FLAG_MASK (0x000000FF & ~GOOMBA_BP_SIZE_MASK)

/* Goomba Triplet Spawner */
    /* oAction */
    #define GOOMBA_TRIPLET_SPAWNER_ACT_UNLOADED 0
    #define GOOMBA_TRIPLET_SPAWNER_ACT_LOADED   1

    /* oBhvParams2ndByte */
    #define GOOMBA_TRIPLET_SPAWNER_BP_EXTRA_GOOMBAS_MASK (0x000000FF & ~GOOMBA_BP_SIZE_MASK)
    #define GOOMBA_TRIPLET_SPAWNER_BP_EXTRA_GOOMBAS(num) ((num) << 2)

/* Chain Chomp */
    /* oAction */
    #define CHAIN_CHOMP_ACT_UNINITIALIZED 0
    #define CHAIN_CHOMP_ACT_MOVE          1
    #define CHAIN_CHOMP_ACT_UNLOAD_CHAIN  2

    /* oSubAction */
    #define CHAIN_CHOMP_SUB_ACT_TURN  0
    #define CHAIN_CHOMP_SUB_ACT_LUNGE 1

    /* oChainChompReleaseStatus */
    #define CHAIN_CHOMP_NOT_RELEASED              0
    #define CHAIN_CHOMP_RELEASED_TRIGGER_CUTSCENE 1
    #define CHAIN_CHOMP_RELEASED_LUNGE_AROUND     2
    #define CHAIN_CHOMP_RELEASED_BREAK_GATE       3
    #define CHAIN_CHOMP_RELEASED_JUMP_AWAY        4
    #define CHAIN_CHOMP_RELEASED_END_CUTSCENE     5

/* Chain Chomp Chain Part */
    /* oBhvParams2ndByte */
    #define CHAIN_CHOMP_CHAIN_PART_BP_PIVOT 0

/* Wiggler */
    /* oAction */
    #define WIGGLER_ACT_UNINITIALIZED      0
    #define WIGGLER_ACT_WALK               1
    #define WIGGLER_ACT_KNOCKBACK          2
    #define WIGGLER_ACT_JUMPED_ON          3
    #define WIGGLER_ACT_SHRINK             4
    #define WIGGLER_ACT_FALL_THROUGH_FLOOR 5

    /* oWigglerTextStatus */
    #define WIGGLER_TEXT_STATUS_AWAIT_DIALOG     0
    #define WIGGLER_TEXT_STATUS_SHOWING_DIALOG   1
    #define WIGGLER_TEXT_STATUS_COMPLETED_DIALOG 2

/* Spiny */
    /* oAction */
    #define SPINY_ACT_WALK             0
    #define SPINY_ACT_HELD_BY_LAKITU   1
    #define SPINY_ACT_THROWN_BY_LAKITU 2
    #define SPINY_ACT_ATTACKED_MARIO   3

/* Evil Lakitu */
    /* oAction */
    #define ENEMY_LAKITU_ACT_UNINITIALIZED 0
    #define ENEMY_LAKITU_ACT_MAIN          1

    /* oSubAction */
    #define ENEMY_LAKITU_SUB_ACT_NO_SPINY    0
    #define ENEMY_LAKITU_SUB_ACT_HOLD_SPINY  1
    #define ENEMY_LAKITU_SUB_ACT_THROW_SPINY 2

/* Cloud */
    /* oAction */
    #define CLOUD_ACT_SPAWN_PARTS   0
    #define CLOUD_ACT_MAIN          1
    #define CLOUD_ACT_UNLOAD        2
    #define CLOUD_ACT_FWOOSH_HIDDEN 3

    /* oBhvParams2ndByte */
    #define CLOUD_BP_FWOOSH       0
    #define CLOUD_BP_LAKITU_CLOUD 1

/* Camera Lakitu */
    /* oAction */
    #define CAMERA_LAKITU_INTRO_ACT_TRIGGER_CUTSCENE 0
    #define CAMERA_LAKITU_INTRO_ACT_SPAWN_CLOUD      1
    #define CAMERA_LAKITU_INTRO_ACT_UNK2             2

    /* oBhvParams2ndByte */
    #define CAMERA_LAKITU_BP_FOLLOW_CAMERA 0
    #define CAMERA_LAKITU_BP_INTRO         1

/* Manta Ray */
    /* oAction */
    #define MANTA_ACT_SPAWN_RINGS 0
    #define MANTA_ACT_NO_RINGS    1

/* Monty Mole */
    /* oAction */
    #define MONTY_MOLE_ACT_SELECT_HOLE          0
    #define MONTY_MOLE_ACT_RISE_FROM_HOLE       1
    #define MONTY_MOLE_ACT_SPAWN_ROCK           2
    #define MONTY_MOLE_ACT_BEGIN_JUMP_INTO_HOLE 3
    #define MONTY_MOLE_ACT_THROW_ROCK           4
    #define MONTY_MOLE_ACT_JUMP_INTO_HOLE       5
    #define MONTY_MOLE_ACT_HIDE                 6
    #define MONTY_MOLE_ACT_JUMP_OUT_OF_HOLE     7

    /* oBhvParams2ndByte */
    #define MONTY_MOLE_BP_NO_ROCK 0
    #define MONTY_MOLE_BP_GENERIC 1

/* Monty Mole Rock */
    /* oAction */
    #define MONTY_MOLE_ROCK_ACT_HELD 0
    #define MONTY_MOLE_ROCK_ACT_MOVE 1

/* Ukiki */
    /* oAction */
    #define UKIKI_ACT_IDLE            0
    #define UKIKI_ACT_RUN             1
    #define UKIKI_ACT_TURN_TO_MARIO   2
    #define UKIKI_ACT_JUMP            3
    #define UKIKI_ACT_GO_TO_CAGE      4
    #define UKIKI_ACT_WAIT_TO_RESPAWN 5
    #define UKIKI_ACT_UNUSED_TURN     6
    #define UKIKI_ACT_RETURN_HOME     7

    /* oSubAction */
    #define UKIKI_SUB_ACT_TAUNT_NONE       0
    #define UKIKI_SUB_ACT_TAUNT_ITCH       1
    #define UKIKI_SUB_ACT_TAUNT_SCREECH    2
    #define UKIKI_SUB_ACT_TAUNT_JUMP_CLAP  3
    #define UKIKI_SUB_ACT_TAUNT_HANDSTAND  4

    #define UKIKI_SUB_ACT_CAGE_RUN_TO_CAGE    0
    #define UKIKI_SUB_ACT_CAGE_WAIT_FOR_MARIO 1
    #define UKIKI_SUB_ACT_CAGE_TALK_TO_MARIO  2
    #define UKIKI_SUB_ACT_CAGE_TURN_TO_CAGE   3
    #define UKIKI_SUB_ACT_CAGE_JUMP_TO_CAGE   4
    #define UKIKI_SUB_ACT_CAGE_LAND_ON_CAGE   5
    #define UKIKI_SUB_ACT_CAGE_SPIN_ON_CAGE   6
    #define UKIKI_SUB_ACT_CAGE_DESPAWN        7

    /* oUkikiTextState */
    #define UKIKI_TEXT_DEFAULT       0
    #define UKIKI_TEXT_CAGE_TEXTBOX  1
    #define UKIKI_TEXT_GO_TO_CAGE    2
    #define UKIKI_TEXT_STOLE_CAP     3
    #define UKIKI_TEXT_HAS_CAP       4
    #define UKIKI_TEXT_GAVE_CAP_BACK 5
    #define UKIKI_TEXT_DO_NOT_LET_GO 6
    #define UKIKI_TEXT_STEAL_CAP     7

    /* oBhvParams2ndByte */
    #define UKIKI_BP_CAGE 0
    #define UKIKI_BP_CAP  1

    /* Animations */
    #define UKIKI_ANIM_RUN          0
    #define UKIKI_ANIM_UNUSED_WALK  1
    #define UKIKI_ANIM_UNUSED_APOSE 2
    #define UKIKI_ANIM_UNUSED_DEATH 3
    #define UKIKI_ANIM_SCREECH      4
    #define UKIKI_ANIM_JUMP_CLAP    5
    #define UKIKI_ANIM_UNUSED_HOP   6
    #define UKIKI_ANIM_LAND         7
    #define UKIKI_ANIM_JUMP         8
    #define UKIKI_ANIM_ITCH         9
    #define UKIKI_ANIM_HANDSTAND    10
    #define UKIKI_ANIM_TURN         11
    #define UKIKI_ANIM_HELD         12

    /* oAnimState */
    #define UKIKI_ANIM_STATE_DEFAULT           0
    #define UKIKI_ANIM_STATE_EYE_CLOSED        1
    #define UKIKI_ANIM_STATE_CAP_ON            2
    #define UKIKI_ANIM_STATE_CAP_ON_EYE_CLOSED 3

/* Ukiki Cage Star */
    /* oAction */
    #define UKIKI_CAGE_STAR_ACT_IN_CAGE    0
    #define UKIKI_CAGE_STAR_ACT_SPAWN_STAR 1

/* Ukiki Cage */
    /* oAction */
    #define UKIKI_CAGE_ACT_WAIT_FOR_UKIKI 0
    #define UKIKI_CAGE_ACT_SPIN           1
    #define UKIKI_CAGE_ACT_FALL           2
    #define UKIKI_CAGE_ACT_HIDE           3

/* Piranha Plant */
    /* oAction */
    #define PIRANHA_PLANT_ACT_IDLE            0
    #define PIRANHA_PLANT_ACT_SLEEPING        1
    #define PIRANHA_PLANT_ACT_BITING          2
    #define PIRANHA_PLANT_ACT_WOKEN_UP        3
    #define PIRANHA_PLANT_ACT_STOPPED_BITING  4
    #define PIRANHA_PLANT_ACT_ATTACKED        5
    #define PIRANHA_PLANT_ACT_SHRINK_AND_DIE  6
    #define PIRANHA_PLANT_ACT_WAIT_TO_RESPAWN 7
    #define PIRANHA_PLANT_ACT_RESPAWN         8

    /* oPiranhaPlantSleepMusicState */
    #define PIRANHA_PLANT_SLEEP_MUSIC_PLAYING 0

/* Piranha Plant Bubble */
    /* oAction */
    #define PIRANHA_PLANT_BUBBLE_ACT_IDLE             0
    #define PIRANHA_PLANT_BUBBLE_ACT_GROW_SHRINK_LOOP 1
    #define PIRANHA_PLANT_BUBBLE_ACT_BURST            2

/* Platform on Track */
    /* oAction */
    #define PLATFORM_ON_TRACK_ACT_INIT             0
    #define PLATFORM_ON_TRACK_ACT_WAIT_FOR_MARIO   1
    #define PLATFORM_ON_TRACK_ACT_MOVE_ALONG_TRACK 2
    #define PLATFORM_ON_TRACK_ACT_PAUSE_BRIEFLY    3
    #define PLATFORM_ON_TRACK_ACT_FALL             4

    /* oBhvParams >> 16 */
    #define PLATFORM_ON_TRACK_BP_MASK_PATH       0x000F
    #define PLATFORM_ON_TRACK_BP_MASK_TYPE       0x0070
    #define PLATFORM_ON_TRACK_BP_RETURN_TO_START (1 <<  8)
    #define PLATFORM_ON_TRACK_BP_DONT_DISAPPEAR  (1 <<  9)
    #define PLATFORM_ON_TRACK_BP_DONT_TURN_YAW   (1 << 10)
    #define PLATFORM_ON_TRACK_BP_DONT_TURN_ROLL  (1 << 11)

    #define PLATFORM_ON_TRACK_TYPE_CARPET    0
    #define PLATFORM_ON_TRACK_TYPE_SKI_LIFT  1
    #define PLATFORM_ON_TRACK_TYPE_CHECKERED 2
    #define PLATFORM_ON_TRACK_TYPE_GRATE     3

/* Floor Switches */
    /* oAction */
    #define SWITCH_ACT_IDLE                      0
    #define SWITCH_ACT_PRESSED                   1
    #define SWITCH_ACT_TICKING                   2
    #define SWITCH_ACT_UNPRESSED                 3
    #define SWITCH_ACT_WAIT_FOR_MARIO_TO_GET_OFF 4

/* Pyramid Elevator */
    /* oAction */
    #define PYRAMID_ELEVATOR_ACT_IDLE              0
    #define PYRAMID_ELEVATOR_ACT_START_MOVING      1
    #define PYRAMID_ELEVATOR_ACT_CONSTANT_VELOCITY 2
    #define PYRAMID_ELEVATOR_ACT_AT_BOTTOM         3

/* Pyramid Top */
    /* oAction */
    #define PYRAMID_TOP_ACT_CHECK_IF_SOLVED 0
    #define PYRAMID_TOP_ACT_SPINNING        1
    #define PYRAMID_TOP_ACT_EXPLODE         2

/* Pyramid Wall */
    /* oAction */
    #define PYRAMID_WALL_ACT_MOVING_DOWN 0
    #define PYRAMID_WALL_ACT_MOVING_UP   1

    /* oBhvParams2ndByte */
    #define PYRAMID_WALL_BP_POSITION_HIGH   0
    #define PYRAMID_WALL_BP_POSITION_MIDDLE 1
    #define PYRAMID_WALL_BP_POSITION_LOW    2

/* Penguins (General) */
    /* Walking sounds */
    #define PENGUIN_WALK_BABY 0
    #define PENGUIN_WALK_BIG  1

    /* Animations */
    #define PENGUIN_ANIM_WALK 0
    #define PENGUIN_ANIM_IDLE 3

/* Racing Penguin */
    /* oAction */
    #define RACING_PENGUIN_ACT_WAIT_FOR_MARIO   0
    #define RACING_PENGUIN_ACT_SHOW_INIT_TEXT   1
    #define RACING_PENGUIN_ACT_PREPARE_FOR_RACE 2
    #define RACING_PENGUIN_ACT_RACE             3
    #define RACING_PENGUIN_ACT_FINISH_RACE      4
    #define RACING_PENGUIN_ACT_SHOW_FINAL_TEXT  5

    /* oBhvParams2ndByte */
    #define RACING_PENGUIN_BP_THIN 0
    #define RACING_PENGUIN_BP_FAT  1

/* SL Walking Penguin */
    /* oAction */
    #define SL_WALKING_PENGUIN_ACT_MOVING_FORWARDS  0
    #define SL_WALKING_PENGUIN_ACT_TURNING_BACK     1
    #define SL_WALKING_PENGUIN_ACT_RETURNING        2
    #define SL_WALKING_PENGUIN_ACT_TURNING_FORWARDS 3

/* Snowman Wind */
    /* oSubAction */
    #define SL_SNOWMAN_WIND_ACT_IDLE    0
    #define SL_SNOWMAN_WIND_ACT_TALKING 1
    #define SL_SNOWMAN_WIND_ACT_BLOWING 2

/* Water Bomb */
    /* oAction */
    #define WATER_BOMB_ACT_SHOT_FROM_CANNON 0
    #define WATER_BOMB_ACT_INIT             1
    #define WATER_BOMB_ACT_DROP             2
    #define WATER_BOMB_ACT_EXPLODE          3

/* TTC Rotating Solid */
    /* oBhvParams2ndByte */
    #define TTC_ROTATING_SOLID_BP_CUBE             0
    #define TTC_ROTATING_SOLID_BP_TRIANGULAR_PRISM 1

/* TTC Treadmill */
    /* oBhvParams2ndByte */
    #define TTC_TREADMILL_BP_FLAG_LARGE (0 << 0)
    #define TTC_TREADMILL_BP_FLAG_SMALL (1 << 0)
    #define TTC_TREADMILL_BP_FLAG_MASK  (TTC_TREADMILL_BP_FLAG_LARGE | TTC_TREADMILL_BP_FLAG_SMALL)
    #define TTC_TREADMILL_BP_LARGE_1    ((0 << 1) | TTC_TREADMILL_BP_FLAG_LARGE)
    #define TTC_TREADMILL_BP_SMALL_1    ((0 << 1) | TTC_TREADMILL_BP_FLAG_SMALL)
    #define TTC_TREADMILL_BP_LARGE_2    ((1 << 1) | TTC_TREADMILL_BP_FLAG_LARGE)
    #define TTC_TREADMILL_BP_SMALL_2    ((1 << 1) | TTC_TREADMILL_BP_FLAG_SMALL)

/* TTC Moving Bar */
    /* oAction */
    #define TTC_MOVING_BAR_ACT_WAIT      0
    #define TTC_MOVING_BAR_ACT_PULL_BACK 1
    #define TTC_MOVING_BAR_ACT_EXTEND    2
    #define TTC_MOVING_BAR_ACT_RETRACT   3

/* TTC Cog */
    /* oBhvParams2ndByte */
    #define TTC_COG_BP_SHAPE_HEXAGON  (0 << 1)
    #define TTC_COG_BP_SHAPE_TRIANGLE (1 << 1)
    #define TTC_COG_BP_SHAPE_MASK     (TTC_COG_BP_SHAPE_HEXAGON | TTC_COG_BP_SHAPE_TRIANGLE)
    #define TTC_COG_BP_DIR_CCW        (0 << 0) // TODO: Check these
    #define TTC_COG_BP_DIR_CW         (1 << 0)
    #define TTC_COG_BP_DIR_MASK       (TTC_COG_BP_DIR_CCW | TTC_COG_BP_DIR_CW)

/* TTC 2D Rotator */
    /* oBhvParams2ndByte */
    #define TTC_2D_ROTATOR_BP_HAND   0
    #define TTC_2D_ROTATOR_BP_2D_COG 1

/* Activated Back-and-Forth Platform */
    #define ACTIVATED_BF_PLAT_TYPE_BITS_ARROW_PLAT 0
    #define ACTIVATED_BF_PLAT_TYPE_BITFS_MESH_PLAT 1
    #define ACTIVATED_BF_PLAT_TYPE_BITFS_ELEVATOR  2

    /* oBhvParams >> 16 */
    #define ACTIVATED_BF_PLAT_BP_MASK_TYPE ((ACTIVATED_BF_PLAT_TYPE_BITS_ARROW_PLAT | \
                                             ACTIVATED_BF_PLAT_TYPE_BITFS_MESH_PLAT | \
                                             ACTIVATED_BF_PLAT_TYPE_BITFS_ELEVATOR) << 8)

/* Dorrie */
    /* oAction */
    #define DORRIE_ACT_MOVE       0
    #define DORRIE_ACT_LOWER_HEAD 1
    #define DORRIE_ACT_RAISE_HEAD 2

/* Mad Piano */
    /* oAction */
    #define MAD_PIANO_ACT_WAIT   0
    #define MAD_PIANO_ACT_ATTACK 1

/* Fire Piranha Plant */
    /* oAction */
    #define FIRE_PIRANHA_PLANT_ACT_HIDE 0
    #define FIRE_PIRANHA_PLANT_ACT_GROW 1

/* Fire Spitter */
    /* oAction */
    #define FIRE_SPITTER_ACT_IDLE      0
    #define FIRE_SPITTER_ACT_SPIT_FIRE 1

/* Eyerok Boss */
    /* oAction */
    #define EYEROK_BOSS_ACT_SLEEP           0
    #define EYEROK_BOSS_ACT_WAKE_UP         1
    #define EYEROK_BOSS_ACT_SHOW_INTRO_TEXT 2
    #define EYEROK_BOSS_ACT_FIGHT           3
    #define EYEROK_BOSS_ACT_DIE             4

/* Eyerok Hand */
    /* oAction */
    #define EYEROK_HAND_ACT_SLEEP              0
    #define EYEROK_HAND_ACT_IDLE               1
    #define EYEROK_HAND_ACT_OPEN               2
    #define EYEROK_HAND_ACT_SHOW_EYE           3
    #define EYEROK_HAND_ACT_CLOSE              4
    #define EYEROK_HAND_ACT_RETREAT            5
    #define EYEROK_HAND_ACT_TARGET_MARIO       6
    #define EYEROK_HAND_ACT_SMASH              7
    #define EYEROK_HAND_ACT_FIST_PUSH          8
    #define EYEROK_HAND_ACT_FIST_SWEEP         9
    #define EYEROK_HAND_ACT_BEGIN_DOUBLE_POUND 10 // raising for double smash
    #define EYEROK_HAND_ACT_DOUBLE_POUND       11 // double smashing
    #define EYEROK_HAND_ACT_ATTACKED           12
    #define EYEROK_HAND_ACT_RECOVER            13
    #define EYEROK_HAND_ACT_BECOME_ACTIVE      14
    #define EYEROK_HAND_ACT_DIE                15

/* Klepto */
    /* oAction */
    #define KLEPTO_ACT_CIRCLE_TARGET_HOLDING   0
    #define KLEPTO_ACT_APPROACH_TARGET_HOLDING 1
    #define KLEPTO_ACT_WAIT_FOR_MARIO          2
    #define KLEPTO_ACT_TURN_TOWARD_MARIO       3
    #define KLEPTO_ACT_DIVE_AT_MARIO           4
    #define KLEPTO_ACT_RESET_POSITION          5
    #define KLEPTO_ACT_STRUCK_BY_MARIO         6
    #define KLEPTO_ACT_RETREAT                 7

    /* oAnimState */
    #define KLEPTO_ANIM_STATE_HOLDING_NOTHING          0
    #define KLEPTO_ANIM_STATE_HOLDING_CAP              1
    #define KLEPTO_ANIM_STATE_HOLDING_STAR             2
    #define KLEPTO_ANIM_STATE_HOLDING_TRANSPARENT_STAR 3

/* Bird */
    /* oAction */
    #define BIRD_ACT_INACTIVE 0
    #define BIRD_ACT_FLY      1

    /* oBhvParams2ndByte */
    #define BIRD_BP_SPAWNED 0
    #define BIRD_BP_SPAWNER 1

/* Skeeter */
    /* oAction */
    #define SKEETER_ACT_IDLE  0
    #define SKEETER_ACT_LUNGE 1
    #define SKEETER_ACT_WALK  2

/* Snufit */
    /* oAction */
    #define SNUFIT_ACT_IDLE  0
    #define SNUFIT_ACT_SHOOT 1

/* Tweester */
    /* oAction */
    #define TWEESTER_ACT_IDLE  0
    #define TWEESTER_ACT_CHASE 1
    #define TWEESTER_ACT_HIDE  2

    /* oSubAction */
    #define TWEESTER_SUB_ACT_WAIT  0

    #define TWEESTER_SUB_ACT_CHASE 0

/* Triplet Butterfly */
    /* oAction */
    #define TRIPLET_BUTTERFLY_ACT_INIT     0
    #define TRIPLET_BUTTERFLY_ACT_WANDER   1
    #define TRIPLET_BUTTERFLY_ACT_ACTIVATE 2
    #define TRIPLET_BUTTERFLY_ACT_EXPLODE  3

    /* oBhvParams2ndByte */
    #define TRIPLET_BUTTERFLY_BP_SPAWN_TYPE_SPAWNER   (0 << 0)
    #define TRIPLET_BUTTERFLY_BP_SPAWN_TYPE_SPAWNED_1 (1 << 0)
    #define TRIPLET_BUTTERFLY_BP_SPAWN_TYPE_SPAWNED_2 (1 << 1)
    #define TRIPLET_BUTTERFLY_BP_SPAWN_TYPE_MASK      (TRIPLET_BUTTERFLY_BP_SPAWN_TYPE_SPAWNER | \
                                                       TRIPLET_BUTTERFLY_BP_SPAWN_TYPE_SPAWNED_1 | \
                                                       TRIPLET_BUTTERFLY_BP_SPAWN_TYPE_SPAWNED_2)
    #define TRIPLET_BUTTERFLY_BP_NO_BOMBS             (1 << 2)

    /* oTripletButterflyType */
    #define TRIPLET_BUTTERFLY_TYPE_NORMAL    -1
    #define TRIPLET_BUTTERFLY_TYPE_EXPLODES  0
    #define TRIPLET_BUTTERFLY_TYPE_SPAWN_1UP 1

/* Water Level Diamond */
    /* oAction */
    // Loading
    #define WATER_LEVEL_DIAMOND_ACT_INIT               0
    // Idling when Mario isn't inside its hitbox
    #define WATER_LEVEL_DIAMOND_ACT_IDLE               1
    // While the water level is changing
    #define WATER_LEVEL_DIAMOND_ACT_CHANGE_WATER_LEVEL 2
    // After the water level has changed but Mario hasn't left its hitbox yet
    #define WATER_LEVEL_DIAMOND_ACT_IDLE_SPINNING      3

/* Mips */
    /* oAction */
    #define MIPS_ACT_WAIT_FOR_NEARBY_MARIO   0
    #define MIPS_ACT_FOLLOW_PATH             1
    #define MIPS_ACT_WAIT_FOR_ANIMATION_DONE 2
    #define MIPS_ACT_FALL_DOWN               3
    #define MIPS_ACT_IDLE                    4

    /* oMipsStarStatus */
    #define MIPS_STAR_STATUS_HAVENT_SPAWNED_STAR  0
    #define MIPS_STAR_STATUS_SHOULD_SPAWN_STAR    1
    #define MIPS_STAR_STATUS_ALREADY_SPAWNED_STAR 2

    /* oBhvParams2ndByte */
    #define MIPS_BP_15_STARS   0
    #define MIPS_BP_50_STARS   1

/* Falling Pillar */
    /* oAction */
    #define FALLING_PILLAR_ACT_IDLE    0
    #define FALLING_PILLAR_ACT_TURNING 1
    #define FALLING_PILLAR_ACT_FALLING 2

/* Bowser Puzzle */
    /* oAction */
    #define BOWSER_PUZZLE_ACT_SPAWN_PIECES      0
    #define BOWSER_PUZZLE_ACT_WAIT_FOR_COMPLETE 1
    #define BOWSER_PUZZLE_ACT_DONE              2

/* Mr Blizzard */
    /* oAction */
    #define MR_BLIZZARD_ACT_SPAWN_SNOWBALL   0
    #define MR_BLIZZARD_ACT_HIDE_UNHIDE      1
    #define MR_BLIZZARD_ACT_RISE_FROM_GROUND 2
    #define MR_BLIZZARD_ACT_ROTATE           3
    #define MR_BLIZZARD_ACT_THROW_SNOWBALL   4
    #define MR_BLIZZARD_ACT_BURROW           5
    #define MR_BLIZZARD_ACT_DEATH            6
    #define MR_BLIZZARD_ACT_JUMP             7

    /* oBhvParams2ndByte */
    #define MR_BLIZZARD_STYPE_GENERIC 0
    #define MR_BLIZZARD_STYPE_JUMPING 1
    #define MR_BLIZZARD_STYPE_CAP     2

/* Whomp */
    /* oBhvParams2ndByte */
    #define WHOMP_BP_SMALL 0
    #define WHOMP_BP_KING  1

/* 1-Up Mushroom */
    /* oBhvParams2ndByte */
    #define ONE_UP_BP_GENERIC           0
    #define ONE_UP_BP_BEAT_BITDW_BOWSER 1
    #define ONE_UP_BP_BEAT_BITFS_BOWSER 2

/* Breakable Box */
    /* oBhvParams2ndByte */
    #define BREAKABLE_BOX_BP_NO_COINS 0
    #define BREAKABLE_BOX_BP_3_COINS  1
    #define BREAKABLE_BOX_BP_5_COINS  2
    #define BREAKABLE_BOX_BP_GIANT    3

/* Hidden Object */
    /* oAction */
    #define HIDDEN_OBJECT_ACT_INACTIVE 0
    #define HIDDEN_OBJECT_ACT_ACTIVE   1
    #define HIDDEN_OBJECT_ACT_BROKEN   2

    /* oBhvParams2ndByte */
    #define HIDDEN_OBJECT_BP_BREAKABLE_BOX            0
    #define HIDDEN_OBJECT_BP_WDW_PLATFORM             1
    #define HIDDEN_OBJECT_BP_UNBREAKABLE_BOX_UNUSED_1 1
    #define HIDDEN_OBJECT_BP_UNBREAKABLE_BOX_UNUSED_2 2

/* Cap Box */
    /* oAnimState */
    #define CAP_BOX_ANIM_STATE_WING_CAP   0
    #define CAP_BOX_ANIM_STATE_METAL_CAP  1
    #define CAP_BOX_ANIM_STATE_VANISH_CAP 2
    #define CAP_BOX_ANIM_STATE_DEFAULT    3

    /* oBhvParams2ndByte */
    #define CAP_BOX_BP_WING_CAP         0
    #define CAP_BOX_BP_METAL_CAP        1
    #define CAP_BOX_BP_VANISH_CAP       2
    #define CAP_BOX_BP_KOOPA_SHELL      3
    #define CAP_BOX_BP_SPECIAL_CAP_END  CAP_BOX_BP_VANISH_CAP

#if KOOPA_SHELL_BOXES_RESPAWN
    #define CAP_BOX_BP_RESPAWN_END      CAP_BOX_BP_KOOPA_SHELL
#else
    #define CAP_BOX_BP_RESPAWN_END      CAP_BOX_BP_VANISH_CAP
#endif

    #define CAP_BOX_BP_ONE_COIN         4
    #define CAP_BOX_BP_THREE_COINS      5
    #define CAP_BOX_BP_TEN_COINS        6
    #define CAP_BOX_BP_1UP_WALKING      7
    #define CAP_BOX_BP_STAR_ACT_1       8
    #define CAP_BOX_BP_1UP_RUNNING_AWAY 9
    #define CAP_BOX_BP_STAR_ACT_2       10
    #define CAP_BOX_BP_STAR_ACT_3       11
    #define CAP_BOX_BP_STAR_ACT_4       12
    #define CAP_BOX_BP_STAR_ACT_5       13
    #define CAP_BOX_BP_STAR_ACT_6       14
    #define CAP_BOX_BP_POWER_FLOWER     15
    #define CAP_BOX_BP_END              99

/* Cap Switch */
    /* oBhvParams2ndByte */
    #define CAP_SWITCH_BP_RED    0
    #define CAP_SWITCH_BP_GREEN  1
    #define CAP_SWITCH_BP_BLUE   2
    #define CAP_SWITCH_BP_YELLOW 3

/* Openable Grill */
    /* oBhvParams2ndByte */
    #define OPENABLE_GRILL_BP_BOB 0
    #define OPENABLE_GRILL_BP_HMC 1

/* WF Rotating Wooden Platform */
    /* oAction */
    #define WF_ROTATING_WOODEN_PLATFORM_ACT_IDLE     0
    #define WF_ROTATING_WOODEN_PLATFORM_ACT_ROTATING 1

/* Rotating Platform */
    /* oBhvParams2ndByte */
    #define ROTATING_PLATFORM_BP_WF  0
    #define ROTATING_PLATFORM_BP_WDW 1

/* Tumbling Bridge */
    /* oBhvParams2ndByte */
    #define TUMBLING_BRIDGE_BP_WF    0
    #define TUMBLING_BRIDGE_BP_BBH   1
    #define TUMBLING_BRIDGE_BP_LLL   2
    #define TUMBLING_BRIDGE_BP_BITFS 3

/* Grindel or Thwomp */
    /* oAction */
    #define GRINDEL_THWOMP_ACT_RAISE          0
    #define GRINDEL_THWOMP_ACT_IDLE_AT_TOP    1
    #define GRINDEL_THWOMP_ACT_LOWER          2
    #define GRINDEL_THWOMP_ACT_LAND           3
    #define GRINDEL_THWOMP_ACT_IDLE_AT_BOTTOM 4

/* Tox Box */
    /* oAction */
    #define TOX_BOX_ACT_INIT          0
    #define TOX_BOX_ACT_ROLL_LAND     1
    #define TOX_BOX_ACT_IDLE          2
    #define TOX_BOX_ACT_UNUSED_IDLE   3
    #define TOX_BOX_ACT_ROLL_FORWARD  4
    #define TOX_BOX_ACT_ROLL_BACKWARD 5
    #define TOX_BOX_ACT_ROLL_RIGHT    6
    #define TOX_BOX_ACT_ROLL_LEFT     7
    #define TOX_BOX_ACT_TABLE_END     -1

    /* oBhvParams2ndByte */
    #define TOX_BOX_BP_MOVEMENT_PATTERN_1 0
    #define TOX_BOX_BP_MOVEMENT_PATTERN_2 1
    #define TOX_BOX_BP_MOVEMENT_PATTERN_3 2

#endif // OBJECT_CONSTANTS_H
