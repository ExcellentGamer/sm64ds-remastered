#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "game/level_update.h"

#include "levels/scripts.h"

#include "actors/common1.h"

#include "make_const_nonconst.h"
#include "levels/si/header.h"

const LevelScript level_si_entry[] = {
    INIT_LEVEL(),
    LOAD_MIO0(0x07, _sa_segment_7SegmentRomStart, _sa_segment_7SegmentRomEnd),
    LOAD_MIO0_TEXTURE(0x09, _inside_mio0SegmentRomStart, _inside_mio0SegmentRomEnd),
    LOAD_MIO0(0x0A, _cloud_floor_skybox_mio0SegmentRomStart, _cloud_floor_skybox_mio0SegmentRomEnd),
    LOAD_MIO0(0x0B, _effect_mio0SegmentRomStart, _effect_mio0SegmentRomEnd),
    LOAD_MIO0(0x05, _group5_mio0SegmentRomStart, _group5_mio0SegmentRomEnd),
    LOAD_RAW (0x0C, _group5_geoSegmentRomStart, _group5_geoSegmentRomEnd),
    ALLOC_LEVEL_POOL(),
    MARIO(MODEL_MARIO, BPARAM4(1), bhvPlayer),
    JUMP_LINK(script_func_global_6),

    AREA(1, si_area_1),
        OBJECT(MODEL_NONE, 3277, 102, 819, 0, -90, 0, BPARAM2(WARP_NODE_0A), bhvAirborneWarp),
        WARP_NODE(WARP_NODE_0A, LEVEL_SA, 1, WARP_NODE_0A, WARP_NO_CHECKPOINT),
        WARP_NODE(WARP_NODE_SUCCESS, LEVEL_CASTLE, 1, WARP_NODE_27, WARP_NO_CHECKPOINT),
        WARP_NODE(WARP_NODE_DEATH, LEVEL_CASTLE, 1, WARP_NODE_28, WARP_NO_CHECKPOINT),
        OBJECT(MODEL_KLEPTO, 1126, 307, 1229, 0, 0, 0, BPARAM2(0x00), bhvKlepto),
        OBJECT(MODEL_SILVER_STAR, -870, 102, -2355, 0, 0, 0, 0, bhvSilverStar),
		OBJECT(MODEL_SILVER_STAR, -2765, 410, 2150, 0, 0, 0, 0, bhvSilverStar),
		OBJECT(MODEL_SILVER_STAR, -2519, 1382, -2898, 0, 0, 0, 0, bhvSilverStar),
		OBJECT(MODEL_SILVER_STAR, -641, 1229, -1999, 0, 0, 0, 0, bhvSilverStar),
		OBJECT(MODEL_NONE, 3626, 358, 206, 0, 0, 0, BPARAM1(STAR_INDEX_ACT_1), bhvStarSwitchSpawnCondition),
		OBJECT(MODEL_NONE, -847, 1141, -2221, 0, 0, 0, BPARAM2(95), bhvPoleGrabbing),
		OBJECT(MODEL_NONE, -2519, 420, -2898, 0, 0, 0, BPARAM2(95), bhvPoleGrabbing),
		OBJECT(MODEL_NONE, 246, 102, 3502, 0, 0, 0, BPARAM2(95), bhvPoleGrabbing),
		OBJECT(MODEL_NONE, 3649, 102, 632, 0, 0, 0, BPARAM2(95), bhvPoleGrabbing),
		OBJECT(MODEL_NONE, 3564, 102, -287, 0, 0, 0, BPARAM2(95), bhvPoleGrabbing),
        TERRAIN(si_area_1_collision),
        MACRO_OBJECTS(si_area_1_macro_objs),
        SET_BACKGROUND_MUSIC(0, SEQ_SOUND_PLAYER),
        TERRAIN_TYPE(TERRAIN_GRASS),
    END_AREA(),

    FREE_LEVEL_POOL(),
    MARIO_POS(1, -90, 3277, 102, 819),
    CALL(0, lvl_init_or_update),
    CALL_LOOP(1, lvl_init_or_update),
    CLEAR_LEVEL(),
    SLEEP_BEFORE_EXIT(1),
    EXIT(),
};
