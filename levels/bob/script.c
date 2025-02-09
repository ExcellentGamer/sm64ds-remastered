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
#include "levels/bob/header.h"

const LevelScript level_bob_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _bob_segment_7SegmentRomStart, _bob_segment_7SegmentRomEnd), 
	LOAD_MIO0_TEXTURE(0x09, _generic_mio0SegmentRomStart, _generic_mio0SegmentRomEnd), 
	LOAD_MIO0(0x0A, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	LOAD_MIO0(0x05, _group3_mio0SegmentRomStart, _group3_mio0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group3_geoSegmentRomStart, _group3_geoSegmentRomEnd), 
	LOAD_MIO0(0x06, _group14_mio0SegmentRomStart, _group14_mio0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd), 
	LOAD_MIO0(0x08, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, BPARAM4(0x01), bhvPlayer),
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_4), 
	JUMP_LINK(script_func_global_15), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_BUBBLY_TREE, bubbly_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_CHAIN_CHOMP_GATE, bob_geo_000440), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_SEESAW_PLATFORM, bob_seesaw_platform), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_BARS_GRILLS, bob_geo_000470), 

	AREA(1, bob_geo_000488),
		WARP_NODE(WARP_NODE_0A, LEVEL_BOB, 1, WARP_NODE_0A, WARP_NO_CHECKPOINT),
		WARP_NODE(WARP_NODE_0B, LEVEL_BOB, 1, WARP_NODE_0C, WARP_NO_CHECKPOINT),
		WARP_NODE(WARP_NODE_0C, LEVEL_BOB, 1, WARP_NODE_0B, WARP_NO_CHECKPOINT),
		WARP_NODE(WARP_NODE_0D, LEVEL_BOB, 1, WARP_NODE_0E, WARP_NO_CHECKPOINT),
		WARP_NODE(WARP_NODE_0E, LEVEL_BOB, 1, WARP_NODE_0D, WARP_NO_CHECKPOINT),
		WARP_NODE(WARP_NODE_SUCCESS, LEVEL_CASTLE, 1, WARP_NODE_32, WARP_NO_CHECKPOINT),
		WARP_NODE(WARP_NODE_DEATH, LEVEL_CASTLE, 1, WARP_NODE_64, WARP_NO_CHECKPOINT),
		OBJECT_WITH_ACTS(MODEL_DL_CANNON_LID, -5704, 130, 5606, 0, -180, 0, BPARAM2(0x00), bhvCannonClosed, ACT_2 | ACT_3 | ACT_4 | ACT_5 | ACT_6 | ACT_7),
		OBJECT_WITH_ACTS(MODEL_BOB_CHAIN_CHOMP_GATE, 1484, 770, 417, 0, -32, 0, 0, bhvChainChompGate, ACT_1 | ACT_2 | ACT_4 | ACT_5 | ACT_6 | ACT_7),
		OBJECT_WITH_ACTS(MODEL_BOB_CHAIN_CHOMP_GATE, 1484, 770, 417, 0, -32, 0, BPARAM2(STAR_INDEX_ACT_3), bhvChainChompGate, ACT_3),
		OBJECT(MODEL_RED_SWITCH, -2304, 2, -3635, 0, 27, 0, 0, bhvFloorSwitchGrills),
		OBJECT(MODEL_STAR, 1566, 1077, 270, 0, 0, 0, BPARAM1(STAR_INDEX_ACT_7), bhvStar),
		OBJECT(MODEL_NONE, -6219, 1001, 2747, 0, 0, 0, BPARAM1(STAR_INDEX_ACT_6), bhvHiddenRedCoinStar),
		OBJECT_WITH_ACTS(MODEL_NONE, 1512, 3837, -5659, 0, -147, 0, BPARAM2(BBALL_BP_STYPE_BOB_UPPER), bhvBobBowlingBallSpawner, ACT_1 | ACT_2),
		OBJECT_WITH_ACTS(MODEL_NONE, 1512, 3837, -5659, 0, -147, 0, BPARAM2(BBALL_BP_STYPE_BOB_UPPER), bhvTtmBowlingBallSpawner, ACT_3 | ACT_4 | ACT_5 | ACT_6 | ACT_7),
		OBJECT_WITH_ACTS(MODEL_NONE, 433, 2826, -5558, 0, -151, 0, BPARAM2(BBALL_BP_STYPE_BOB_LOWER), bhvBobBowlingBallSpawner, ACT_1 | ACT_2),
		OBJECT_WITH_ACTS(MODEL_NONE, 433, 2826, -5558, 0, -151, 0, BPARAM2(BBALL_BP_STYPE_BOB_LOWER), bhvTtmBowlingBallSpawner, ACT_3 | ACT_4 | ACT_5 | ACT_6 | ACT_7),
		OBJECT(MODEL_BOWLING_BALL, -1345, 811, -3761, 0, 0, 0, 0, bhvPitBowlingBall),
		OBJECT(MODEL_BOWLING_BALL, -101, 821, -3425, 0, 0, 0, 0, bhvPitBowlingBall),
		OBJECT(MODEL_BOB_SEESAW_PLATFORM, -2304, 719, 1024, 0, 45, 0, BPARAM2(0x03), bhvSeesawPlatform),
		OBJECT(MODEL_NONE, -6451, 872, 1075, 0, 0, 0, BPARAM1(STAR_INDEX_ACT_5) | BPARAM2(0x04), bhvHiddenStar),
		OBJECT(MODEL_NONE, -2048, 1, -3069, 0, 25, 0, BPARAM2(OPENABLE_GRILL_BP_BOB), bhvOpenableGrill),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -6131, 904, -6508, 0, 0, 0, 0x00010000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -5793, 1025, -4655, 0, 0, 0, 0x00010000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -1509, 135, 5093, 0, 0, 0, 0x00010000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, 2910, 769, 5916, 0, 0, 0, 0x00010000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, 5427, 872, 6042, 0, 0, 0, 0x00010000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, 4207, 929, 3771, 0, 0, 0, 0x00010000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, 4096, 3074, 1638, 0, 0, 0, 0x00010000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, 6798, 2009, -5588, 0, 0, 0, 0x00010000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, 6032, 2195, -7661, 0, 0, 0, 0x00010000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -6804, 1041, -4867, 0, 0, 0, 0x00010000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -6173, 1026, -431, 0, 0, 0, 0x00010000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -5120, 769, 2048, 0, 0, 0, 0x00010000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -4096, 769, 1535, 0, 0, 0, 0x00010000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -6655, 770, 3584, 0, 0, 0, 0x00010000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -4096, 770, 3072, 0, 0, 0, 0x00010000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -3583, 769, 2559, 0, 0, 0, 0x00010000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -4268, 2, 4767, 0, 0, 0, 0x00010000, bhvTree),
		OBJECT(MODEL_CHECKERBOARD_PLATFORM, 1614, 301, 4611, 0, 0, 0, BPARAM1(0) | BPARAM2(40), bhvCheckerboardElevatorGroup),
		OBJECT(MODEL_NONE, -6374, 1743, 6505, 0, 135, 0, BPARAM2(WARP_NODE_0A), bhvSpinAirborneWarp),
		MARIO_POS(0x01, 135, -6374, 83, 6505),
		OBJECT(MODEL_NONE, 566, 2685, -5392, 0, 0, 0, BPARAM2(WARP_NODE_0B), bhvFadingWarp),
		OBJECT(MODEL_NONE, 1667, 3837, -5475, 0, 0, 0, BPARAM2(WARP_NODE_0C), bhvFadingWarp),
		OBJECT(MODEL_NONE, -6550, 1026, -3506, 0, 0, 0, BPARAM2(WARP_NODE_0D), bhvFadingWarp),
		OBJECT(MODEL_NONE, 1987, 770, 6324, 0, 0, 0, BPARAM2(WARP_NODE_0E), bhvFadingWarp),
		OBJECT_WITH_ACTS(MODEL_BOBOMB_BUDDY, -6093, 2, 6656, 0, 0, 0, BPARAM2(DIALOG_003), bhvBobombBuddy, ACT_2 | ACT_3 | ACT_4 | ACT_5 | ACT_6 | ACT_7),
		OBJECT_WITH_ACTS(MODEL_BOBOMB_BUDDY, -5632, 156, 5939, 0, 0, 0, 0, bhvBobombBuddyOpensCannon, ACT_2 | ACT_3 | ACT_4 | ACT_5 | ACT_6 | ACT_7),
		OBJECT_WITH_ACTS(MODEL_BOBOMB_BUDDY, -4314, 2, 5119, 0, 0, 0, DIALOG_003 << 16, bhvBobombBuddy, ACT_2 | ACT_3 | ACT_4 | ACT_5 | ACT_6 | ACT_7),
		OBJECT_WITH_ACTS(MODEL_GOOMBA, 5326, 1000, 3695, 0, -45, 0, 0, bhvGoomba, ACT_1 | ACT_2 | ACT_3 | ACT_5 | ACT_6 | ACT_7),
		OBJECT_WITH_ACTS(MODEL_GOOMBA, -205, 2, 4321, 0, -90, 0, 0, bhvGoomba, ACT_1 | ACT_2 | ACT_3 | ACT_5 | ACT_6 | ACT_7),
		OBJECT_WITH_ACTS(MODEL_KOOPA_WITH_SHELL, 4098, 769, 6348, 0, 0, 0, BPARAM2(KOOPA_BP_NORMAL), bhvKoopa, ACT_4 | ACT_5 | ACT_6 | ACT_7),
		OBJECT_WITH_ACTS(MODEL_BOBOMB_BUDDY, -6093, 2, 6656, 0, 0, 0, BPARAM2(DIALOG_001), bhvBobombBuddy, ACT_1),
		OBJECT_WITH_ACTS(MODEL_BOBOMB_BUDDY, -5632, 156, 5939, 0, 0, 0, BPARAM2(DIALOG_002), bhvBobombBuddy, ACT_1),
		OBJECT_WITH_ACTS(MODEL_CANNON_BASE, -5695, 130, 5599, 0, 135, 0, BPARAM2(0x01), bhvWaterBombCannon, ACT_1),
		OBJECT_WITH_ACTS(MODEL_KING_BOBOMB, 1537, 4295, -5516, 0, -146, 0, BPARAM1(STAR_INDEX_ACT_1) | BPARAM2(BOBOMB_KING_BP_TYPE_1), bhvKingBobomb, ACT_1),
		OBJECT_WITH_ACTS(MODEL_NONE, 3072, 4295, -4710, 0, 0, 0, 0, bhvKoopaRaceEndpoint, ACT_2),
		OBJECT_WITH_ACTS(MODEL_KOOPA_WITH_SHELL, -3789, 2, 5222, 0, 0, 0, BPARAM1(STAR_INDEX_ACT_2) | BPARAM2(KOOPA_BP_KOOPA_THE_QUICK_BOB), bhvKoopa, ACT_2),
		OBJECT(MODEL_WOODEN_SIGNPOST, -4588, 2, 5435, 0, -90, 0, DIALOG_033, bhvSignOnWall),
    	OBJECT_WITH_ACTS(MODEL_SILVER_STAR, 7014, 1990, -5376, 0, 0, 0, BPARAM2(2), bhvSilverStar, ACT_3),
		OBJECT_WITH_ACTS(MODEL_SILVER_STAR, -4296, 770, 2310, 0, 0, 0, BPARAM2(2), bhvSilverStar, ACT_3),
		OBJECT_WITH_ACTS(MODEL_SILVER_STAR, -1509, 975, 5093, 0, 0, 0, 0, bhvSilverStar, ACT_3),
		OBJECT_WITH_ACTS(MODEL_SILVER_STAR, -6298, 1077, -5274, 0, 0, 0, 0, bhvSilverStar, ACT_3),
		OBJECT_WITH_ACTS(MODEL_SILVER_STAR,  362,  973, 1941, 0, 0, 0, 0, bhvSilverStar, ACT_3),
		OBJECT_WITH_ACTS(MODEL_NONE, -4477, 258, 5637, 0, 0, 0, BPARAM1(STAR_INDEX_ACT_3), bhvStarSwitchSpawnCondition, ACT_3),
		OBJECT_WITH_ACTS(MODEL_BREAKABLE_BOX, -2960, 770, 256, 0, 45, 0, 0, bhvBreakableBox, ACT_4),
		OBJECT_WITH_ACTS(MODEL_BREAKABLE_BOX, -3105, 770, 400, 0, 45, 0, 0, bhvBreakableBox, ACT_4),
		OBJECT_WITH_ACTS(MODEL_BREAKABLE_BOX, -2418, 977, -4801, 0, 27, 0, 0, bhvBreakableBox, ACT_4),
		OBJECT_WITH_ACTS(MODEL_BREAKABLE_BOX, -2511, 977, -4983, 0, 27, 0, 0, bhvBreakableBox, ACT_4),
        OBJECT_WITH_ACTS(MODEL_BREAKABLE_BOX, -4404, 1026, -662, 0, 45, 0, 0, bhvBreakableBox, ACT_4 | ACT_7),
		OBJECT_WITH_ACTS(MODEL_BREAKABLE_BOX, -4961, 1026, -768, 0, 0, 0, 0, bhvBreakableBox, ACT_4 | ACT_7),
		OBJECT_WITH_ACTS(MODEL_CHAIN_CHOMP, 410, 770, 1946, 0, 0, 0, 0, bhvChainChomp, ACT_1 | ACT_2 | ACT_4 | ACT_5 | ACT_6 | ACT_7),
		OBJECT_WITH_ACTS(MODEL_KING_BOBOMB, 3072, 4295, -4710, 0, -146, 0, BPARAM1(STAR_INDEX_ACT_4) | BPARAM2(BOBOMB_KING_BP_TYPE_2), bhvKingBobomb, ACT_4),
		TERRAIN(bob_seg7_collision_level),
		MACRO_OBJECTS(bob_seg7_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		SHOW_DIALOG(0x00, DIALOG_000),
		TERRAIN_TYPE(TERRAIN_GRASS),
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 135, -6374, 83, 6505),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
