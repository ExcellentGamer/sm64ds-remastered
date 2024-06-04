#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "game/level_update.h"

#include "levels/scripts.h"

#include "actors/common1.h"

#include "make_const_nonconst.h"
#include "levels/castle_grounds/header.h"

const LevelScript level_castle_grounds_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _castle_grounds_segment_7SegmentRomStart, _castle_grounds_segment_7SegmentRomEnd),
    LOAD_MIO0(0x0A, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd),
    LOAD_MIO0_TEXTURE(0x09, _outside_mio0SegmentRomStart, _outside_mio0SegmentRomEnd),
    LOAD_MIO0(0x05, _group10_mio0SegmentRomStart, _group10_mio0SegmentRomEnd),
    LOAD_RAW(0x0C, _group10_geoSegmentRomStart,  _group10_geoSegmentRomEnd),
    LOAD_MIO0(0x06, _group15_mio0SegmentRomStart, _group15_mio0SegmentRomEnd),
    LOAD_RAW(0x0D, _group15_geoSegmentRomStart,  _group15_geoSegmentRomEnd),
    LOAD_MIO0(0x08, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd),
    LOAD_RAW(0x0F, _common0_geoSegmentRomStart,  _common0_geoSegmentRomEnd),
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, BPARAM4(0x01), bhvPlayer),
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_11), 
	JUMP_LINK(script_func_global_16), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_03, castle_grounds_geo_0006F4),
    LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_BUBBLY_TREE, bubbly_tree_geo),
    LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_WARP_PIPE, warp_pipe_geo),
    LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_CASTLE_DOOR, castle_door_geo),
    LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_METAL_DOOR, metal_door_geo),
    LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_VCUTM_GRILL, castle_grounds_geo_00070C),
    LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_FLAG, castle_grounds_geo_000660),
    LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_CANNON_GRILL, castle_grounds_geo_000724),
    LOAD_MODEL_FROM_GEO(MODEL_CASTLE_KEY_DOOR, key_door_geo),

	AREA(1, castle_grounds_area_1),
		WARP_NODE(WARP_NODE_DEATH, LEVEL_CASTLE_GROUNDS, 1, WARP_NODE_03, WARP_NO_CHECKPOINT),
		WARP_NODE(WARP_NODE_00, LEVEL_CASTLE, 1, WARP_NODE_00, WARP_NO_CHECKPOINT),
    	WARP_NODE(WARP_NODE_01, LEVEL_CASTLE, 1, WARP_NODE_01, WARP_NO_CHECKPOINT),
    	WARP_NODE(WARP_NODE_02, LEVEL_CASTLE, 3, WARP_NODE_02, WARP_NO_CHECKPOINT),
		WARP_NODE(WARP_NODE_03, LEVEL_CASTLE_GROUNDS, 1, WARP_NODE_03, WARP_NO_CHECKPOINT),
		WARP_NODE(WARP_NODE_04, LEVEL_CASTLE_GROUNDS, 1, WARP_NODE_04, WARP_NO_CHECKPOINT),
		WARP_NODE(WARP_NODE_05, LEVEL_VCUTM, 1, WARP_NODE_0A, WARP_NO_CHECKPOINT),
    	WARP_NODE(WARP_NODE_06, LEVEL_CASTLE_GROUNDS, 1, WARP_NODE_06, WARP_NO_CHECKPOINT),
    	WARP_NODE(WARP_NODE_07, LEVEL_CASTLE_GROUNDS, 1, WARP_NODE_07, WARP_NO_CHECKPOINT),
    	WARP_NODE(WARP_NODE_08, LEVEL_CASTLE_GROUNDS, 1, WARP_NODE_08, WARP_NO_CHECKPOINT),
		WARP_NODE(WARP_NODE_0A, LEVEL_CASTLE_GROUNDS, 1, WARP_NODE_0A, WARP_NO_CHECKPOINT),
		WARP_NODE(WARP_NODE_14, LEVEL_CASTLE_GROUNDS, 1, WARP_NODE_14, WARP_NO_CHECKPOINT),
		WARP_NODE(WARP_NODE_1E, LEVEL_CASTLE_GROUNDS, 1, WARP_NODE_1E, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 6201, -2277, 6320, 0, 0, 0, 0x00000000, bhvBlueFish),
		OBJECT(MODEL_NONE, -4035, -1979, -2617, 0, 0, 0, 0x00000000, bhvBlueFish),
		OBJECT(MODEL_NONE, -7152, 2169, -2973, 0, 0, 0, 0x00000000, bhvWaterfallSoundLoop),
		OBJECT(MODEL_NONE, 7040, 1563, -6707, 0, 0, 0, 0x00000000, bhvBirdsSoundLoop),
		OBJECT(MODEL_NONE, -6560, -485, 6264, 0, 0, 0, 0x00000000, bhvBirdsSoundLoop),
		OBJECT(MODEL_NONE, 6929, -2277, 7373, 0, 0, 0, 0x00000000, bhvBirdsSoundLoop),
		OBJECT(MODEL_NONE, -7999, 1070, -3926, 0, 0, 0, 0x00000000, bhvAmbientSounds),
		OBJECT(MODEL_BUTTERFLY, -4771, -630, 2807, 0, 0, 0, 0x00000000, bhvButterfly),
		OBJECT(MODEL_BUTTERFLY, -4737, -605, 2879, 0, 0, 0, 0x00000000, bhvButterfly),
		OBJECT(MODEL_BUTTERFLY, -4991, -588, 2790, 0, 0, 0, 0x00000000, bhvButterfly),
		OBJECT(MODEL_BUTTERFLY, 5702, -231, -3203, 0, 0, 0, 0x00000000, bhvButterfly),
		OBJECT(MODEL_BUTTERFLY, 5737, -206, -3132, 0, 0, 0, 0x00000000, bhvButterfly),
		OBJECT(MODEL_BUTTERFLY, 5483, -258, -3220, 0, 0, 0, 0x00000000, bhvButterfly),
		OBJECT(MODEL_CASTLE_GROUNDS_FLAG, -3103, 2121, -927, 0, 0, 0, 0x00000000, bhvCastleFlagWaving),
		OBJECT(MODEL_CASTLE_GROUNDS_FLAG, 3120, 2121, -927, 0, 0, 0, 0x00000000, bhvCastleFlagWaving),
		OBJECT(MODEL_CASTLE_GROUNDS_FLAG, -3679, 2702, -5593, 0, 0, 0, 0x00000000, bhvCastleFlagWaving),
		OBJECT(MODEL_CASTLE_GROUNDS_FLAG, 3679, 2702, -5593, 0, 0, 0, 0x00000000, bhvCastleFlagWaving),
		OBJECT(MODEL_CASTLE_GROUNDS_BUBBLY_TREE, -6158, -674, -746, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_CASTLE_GROUNDS_BUBBLY_TREE, -61, -445, 5254, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_CASTLE_GROUNDS_BUBBLY_TREE, 664, -401, 4701, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_CASTLE_GROUNDS_BUBBLY_TREE, 1315, -710, 4909, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_CASTLE_GROUNDS_BUBBLY_TREE, 1482, -734, 3836, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_CASTLE_GROUNDS_BUBBLY_TREE, 1848, -727, 3116, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_CASTLE_GROUNDS_BUBBLY_TREE, 2550, -756, 2628, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_CASTLE_GROUNDS_BUBBLY_TREE, 5737, -639, 738, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_CASTLE_GROUNDS_BUBBLY_TREE, 6351, -563, 295, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_CASTLE_GROUNDS_BUBBLY_TREE, 6094, -474, -1021, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_CASTLE_GROUNDS_BUBBLY_TREE, 5459, -520, -1213, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_CASTLE_GROUNDS_BUBBLY_TREE, -5652, -664, -132, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_CASTLE_GROUNDS_BUBBLY_TREE, 5671, -390, -2133, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_CASTLE_GROUNDS_BUBBLY_TREE, 6215, -276, -2973, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_CASTLE_GROUNDS_BUBBLY_TREE, -5759, -692, 759, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_CASTLE_GROUNDS_BUBBLY_TREE, -4513, -684, 2224, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_CASTLE_GROUNDS_BUBBLY_TREE, -5281, -738, 2541, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_CASTLE_GROUNDS_BUBBLY_TREE, -2749, -484, 3985, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_CASTLE_GROUNDS_BUBBLY_TREE, -1615, -324, 3951, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_CASTLE_GROUNDS_BUBBLY_TREE, -2533, -548, 4642, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_CASTLE_GROUNDS_BUBBLY_TREE, -1904, -588, 4856, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_CASTLE_KEY_DOOR, -79, -245, -1075, 0, 0, 0, BPARAM1(0x03) | BPARAM2(0), bhvDoorWarp),
		OBJECT(MODEL_CASTLE_KEY_DOOR, 79, -245, -1075, 0, 180, 0, BPARAM1(0x03) | BPARAM2(1), bhvDoorWarp),
		OBJECT(MODEL_CASTLE_GROUNDS_METAL_DOOR, 3252, -1559, -932, 0, 225, 0, BPARAM1(0x03) | BPARAM2(2), bhvDoorWarp),
		OBJECT(MODEL_NONE, -3379, -1812, 24, 0, 0, 0, BPARAM1(60) | BPARAM2(WARP_NODE_05), bhvWarp),
		OBJECT(MODEL_NONE, -1229, -788, 6963, 0, -90, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, -90, -1229, -788, 6963),
		TERRAIN(castle_grounds_area_1_collision),
		MACRO_OBJECTS(castle_grounds_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_SOUND_PLAYER),
		TERRAIN_TYPE(TERRAIN_GRASS),
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 90, -1229, -788, 6963),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
