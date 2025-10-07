Lights1 mips_mips_yellow_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

Lights1 mips_mips_orange_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

Lights1 mips_mips_pink_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

Lights1 mips_mips_green_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

Lights1 mips_mips_white_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

Lights1 mips_mips_cyan_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

Texture mips_mips_yellow_rgba16[] = {
	#include "actors/mips/mips_yellow.rgba16.inc.c"
};

Texture mips_mips_orange_rgba16[] = {
	#include "actors/mips/mips_orange.rgba16.inc.c"
};

Texture mips_mips_pink_rgba16[] = {
	#include "actors/mips/mips_pink.rgba16.inc.c"
};

Texture mips_mips_green_rgba16[] = {
	#include "actors/mips/mips_green.rgba16.inc.c"
};

Texture mips_mips_white_rgba16[] = {
	#include "actors/mips/mips_white.rgba16.inc.c"
};

Texture mips_mips_blue_rgba16[] = {
	#include "actors/mips/mips_blue.rgba16.inc.c"
};

Vtx mips_skl_root_mesh_layer_4_vtx_0[17] = {
	{{{98, -40, -21}, 0, {-650, 822}, {0x7C, 0xF7, 0xE5, 0xFF}}},
	{{{117, 4, 0}, 0, {-1254, 1006}, {0x69, 0x48, 0x00, 0xFF}}},
	{{{83, -75, -25}, 0, {-200, 846}, {0x26, 0xA3, 0x4E, 0xFF}}},
	{{{83, -75, 25}, 0, {-200, 846}, {0x26, 0xA3, 0xB2, 0xFF}}},
	{{{98, -40, 21}, 0, {-650, 822}, {0x7C, 0xF7, 0x1B, 0xFF}}},
	{{{32, -108, 0}, 0, {70, 930}, {0x02, 0x81, 0x00, 0xFF}}},
	{{{38, -93, 49}, 0, {116, 946}, {0x05, 0xB0, 0x63, 0xFF}}},
	{{{66, -71, 43}, 0, {0, 806}, {0x07, 0xDD, 0x7A, 0xFF}}},
	{{{-19, -86, 0}, 0, {612, 1006}, {0xB2, 0x9C, 0x00, 0xFF}}},
	{{{38, -93, -49}, 0, {116, 946}, {0x05, 0xB0, 0x9D, 0xFF}}},
	{{{66, -71, -43}, 0, {0, 806}, {0x07, 0xDD, 0x86, 0xFF}}},
	{{{117, 4, 0}, 0, {542, 650}, {0x69, 0x48, 0x00, 0xFF}}},
	{{{78, -21, 44}, 0, {542, 650}, {0x29, 0x36, 0x6C, 0xFF}}},
	{{{98, -40, 21}, 0, {542, 650}, {0x7C, 0xF7, 0x1B, 0xFF}}},
	{{{-3, 20, 0}, 0, {542, 650}, {0xFB, 0x7F, 0x00, 0xFF}}},
	{{{78, -21, -44}, 0, {542, 650}, {0x29, 0x36, 0x94, 0xFF}}},
	{{{98, -40, -21}, 0, {542, 650}, {0x7C, 0xF7, 0xE5, 0xFF}}},
};

Gfx mips_skl_root_mesh_layer_4_tri_0[] = {
	gsSPVertex(mips_skl_root_mesh_layer_4_vtx_0 + 0, 17, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
	gsSP2Triangles(4, 3, 1, 0, 2, 3, 5, 0),
	gsSP2Triangles(6, 5, 3, 0, 3, 7, 6, 0),
	gsSP2Triangles(5, 6, 8, 0, 8, 9, 5, 0),
	gsSP2Triangles(2, 5, 9, 0, 2, 9, 10, 0),
	gsSP2Triangles(11, 12, 13, 0, 12, 11, 14, 0),
	gsSP2Triangles(15, 14, 11, 0, 11, 16, 15, 0),
	gsSPEndDisplayList(),
};

Vtx mips_arm_l1_skinned_mesh_layer_4_vtx_0[4] = {
	{{{78, -21, -44}, 0, {542, 650}, {0x29, 0x36, 0x94, 0xFF}}},
	{{{98, -40, -21}, 0, {542, 650}, {0x7C, 0xF7, 0xE5, 0xFF}}},
	{{{66, -71, -43}, 0, {542, 650}, {0x07, 0xDD, 0x86, 0xFF}}},
	{{{83, -75, -25}, 0, {542, 650}, {0x26, 0xA3, 0x4E, 0xFF}}},
};

Gfx mips_arm_l1_skinned_mesh_layer_4_tri_0[] = {
	gsSPVertex(mips_arm_l1_skinned_mesh_layer_4_vtx_0 + 0, 4, 0),
	gsSPEndDisplayList(),
};

Vtx mips_arm_l1_mesh_layer_4_vtx_0[3] = {
	{{{22, 26, -15}, 0, {542, 650}, {0xFE, 0x52, 0x9F, 0xFF}}},
	{{{27, -3, 0}, 0, {542, 650}, {0x13, 0x85, 0x1A, 0xFF}}},
	{{{23, 29, 10}, 0, {542, 650}, {0x08, 0x64, 0x4E, 0xFF}}},
};

Gfx mips_arm_l1_mesh_layer_4_tri_0[] = {
	gsSPVertex(mips_arm_l1_mesh_layer_4_vtx_0 + 0, 3, 4),
	gsSP2Triangles(4, 0, 1, 0, 0, 4, 2, 0),
	gsSP2Triangles(5, 2, 4, 0, 2, 5, 3, 0),
	gsSP2Triangles(6, 3, 5, 0, 3, 6, 1, 0),
	gsSP1Triangle(4, 1, 6, 0),
	gsSPEndDisplayList(),
};

Vtx mips_arm_l1_mesh_layer_4_vtx_1[11] = {
	{{{77, 5, 20}, 0, {558, 972}, {0x5C, 0x0C, 0x57, 0xFF}}},
	{{{22, 26, -15}, 0, {810, 738}, {0xFE, 0x52, 0x9F, 0xFF}}},
	{{{23, 29, 10}, 0, {620, 744}, {0x08, 0x64, 0x4E, 0xFF}}},
	{{{73, -1, -22}, 0, {860, 972}, {0x51, 0xF8, 0x9F, 0xFF}}},
	{{{47, -20, -1}, 0, {716, 754}, {0xE4, 0x84, 0x07, 0xFF}}},
	{{{73, -1, -22}, 0, {-464, 688}, {0x51, 0xF8, 0x9F, 0xFF}}},
	{{{47, -20, -1}, 0, {-464, 688}, {0xE4, 0x84, 0x07, 0xFF}}},
	{{{22, 26, -15}, 0, {-464, 688}, {0xFE, 0x52, 0x9F, 0xFF}}},
	{{{27, -3, 0}, 0, {-464, 688}, {0x13, 0x85, 0x1A, 0xFF}}},
	{{{23, 29, 10}, 0, {-464, 688}, {0x08, 0x64, 0x4E, 0xFF}}},
	{{{77, 5, 20}, 0, {-464, 688}, {0x5C, 0x0C, 0x57, 0xFF}}},
};

Gfx mips_arm_l1_mesh_layer_4_tri_1[] = {
	gsSPVertex(mips_arm_l1_mesh_layer_4_vtx_1 + 0, 11, 0),
	gsSP2Triangles(0, 1, 2, 0, 1, 0, 3, 0),
	gsSP2Triangles(4, 3, 0, 0, 5, 6, 7, 0),
	gsSP2Triangles(8, 7, 6, 0, 8, 6, 9, 0),
	gsSP1Triangle(10, 9, 6, 0),
	gsSPEndDisplayList(),
};

Vtx mips_arm_r1_skinned_mesh_layer_4_vtx_0[4] = {
	{{{78, -21, 44}, 0, {542, 650}, {0x29, 0x36, 0x6C, 0xFF}}},
	{{{66, -71, 43}, 0, {542, 650}, {0x07, 0xDD, 0x7A, 0xFF}}},
	{{{98, -40, 21}, 0, {542, 650}, {0x7C, 0xF7, 0x1B, 0xFF}}},
	{{{83, -75, 25}, 0, {542, 650}, {0x26, 0xA3, 0xB2, 0xFF}}},
};

Gfx mips_arm_r1_skinned_mesh_layer_4_tri_0[] = {
	gsSPVertex(mips_arm_r1_skinned_mesh_layer_4_vtx_0 + 0, 4, 0),
	gsSPEndDisplayList(),
};

Vtx mips_arm_r1_mesh_layer_4_vtx_0[3] = {
	{{{27, -3, 0}, 0, {542, 650}, {0x13, 0x85, 0xE6, 0xFF}}},
	{{{22, 26, 15}, 0, {542, 650}, {0xFE, 0x52, 0x61, 0xFF}}},
	{{{23, 29, -10}, 0, {542, 650}, {0x08, 0x64, 0xB2, 0xFF}}},
};

Gfx mips_arm_r1_mesh_layer_4_tri_0[] = {
	gsSPVertex(mips_arm_r1_mesh_layer_4_vtx_0 + 0, 3, 4),
	gsSP2Triangles(4, 5, 1, 0, 0, 1, 5, 0),
	gsSP2Triangles(5, 2, 0, 0, 5, 6, 2, 0),
	gsSP2Triangles(3, 2, 6, 0, 6, 4, 3, 0),
	gsSP1Triangle(1, 3, 4, 0),
	gsSPEndDisplayList(),
};

Vtx mips_arm_r1_mesh_layer_4_vtx_1[11] = {
	{{{73, -1, 22}, 0, {-464, 688}, {0x51, 0xF8, 0x61, 0xFF}}},
	{{{22, 26, 15}, 0, {-464, 688}, {0xFE, 0x52, 0x61, 0xFF}}},
	{{{47, -20, 1}, 0, {-464, 688}, {0xE4, 0x84, 0xF9, 0xFF}}},
	{{{27, -3, 0}, 0, {-464, 688}, {0x13, 0x85, 0xE6, 0xFF}}},
	{{{23, 29, -10}, 0, {-464, 688}, {0x08, 0x64, 0xB2, 0xFF}}},
	{{{77, 5, -20}, 0, {-464, 688}, {0x5C, 0x0C, 0xA9, 0xFF}}},
	{{{22, 26, 15}, 0, {810, 738}, {0xFE, 0x52, 0x61, 0xFF}}},
	{{{77, 5, -20}, 0, {558, 972}, {0x5C, 0x0C, 0xA9, 0xFF}}},
	{{{23, 29, -10}, 0, {620, 744}, {0x08, 0x64, 0xB2, 0xFF}}},
	{{{73, -1, 22}, 0, {860, 972}, {0x51, 0xF8, 0x61, 0xFF}}},
	{{{47, -20, 1}, 0, {716, 754}, {0xE4, 0x84, 0xF9, 0xFF}}},
};

Gfx mips_arm_r1_mesh_layer_4_tri_1[] = {
	gsSPVertex(mips_arm_r1_mesh_layer_4_vtx_1 + 0, 11, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
	gsSP2Triangles(2, 3, 4, 0, 5, 2, 4, 0),
	gsSP2Triangles(6, 7, 8, 0, 6, 9, 7, 0),
	gsSP1Triangle(10, 7, 9, 0),
	gsSPEndDisplayList(),
};

Vtx mips_head1_mesh_layer_4_vtx_0[83] = {
	{{{61, 2, 111}, 0, {2020, 198}, {0x72, 0xF8, 0x38, 0xFF}}},
	{{{103, 27, 28}, 0, {1848, 1014}, {0x72, 0xF8, 0x38, 0xFF}}},
	{{{52, 74, 140}, 0, {1564, 124}, {0x72, 0xF8, 0x38, 0xFF}}},
	{{{61, 2, -111}, 0, {2020, 198}, {0x72, 0xF8, 0xC8, 0xFF}}},
	{{{52, 74, -140}, 0, {1564, 124}, {0x72, 0xF8, 0xC8, 0xFF}}},
	{{{103, 27, -28}, 0, {1848, 1014}, {0x72, 0xF8, 0xC8, 0xFF}}},
	{{{113, -18, 0}, 0, {1670, 700}, {0x7F, 0x03, 0x00, 0xFF}}},
	{{{111, 28, -15}, 0, {1648, 1062}, {0x7F, 0x03, 0x00, 0xFF}}},
	{{{111, 28, 15}, 0, {1700, 1060}, {0x7F, 0x03, 0x00, 0xFF}}},
	{{{82, 33, 69}, 0, {1470, 60}, {0x44, 0x09, 0x6B, 0xFF}}},
	{{{32, -2, 65}, 0, {1526, 140}, {0xF5, 0xA0, 0x52, 0xFF}}},
	{{{111, 15, 16}, 0, {1356, 58}, {0x62, 0xC0, 0x31, 0xFF}}},
	{{{106, 0, 0}, 0, {1328, 16}, {0x57, 0xA4, 0x00, 0xFF}}},
	{{{110, 23, 0}, 0, {1306, 28}, {0x7D, 0xEB, 0x00, 0xFF}}},
	{{{111, 15, -16}, 0, {1356, 58}, {0x62, 0xC0, 0xCF, 0xFF}}},
	{{{32, -2, -65}, 0, {1526, 140}, {0xF5, 0xA0, 0xAE, 0xFF}}},
	{{{82, 33, -69}, 0, {1470, 60}, {0x44, 0x09, 0x95, 0xFF}}},
	{{{23, 34, 80}, 0, {688, 562}, {0xE9, 0x03, 0x7D, 0xFF}}},
	{{{32, -2, 65}, 0, {628, 704}, {0xF5, 0xA0, 0x52, 0xFF}}},
	{{{82, 33, 69}, 0, {936, 672}, {0x44, 0x09, 0x6B, 0xFF}}},
	{{{72, 52, 53}, 0, {944, 586}, {0x3C, 0x44, 0x59, 0xFF}}},
	{{{27, 59, 65}, 0, {776, 482}, {0x04, 0x30, 0x75, 0xFF}}},
	{{{103, 53, 0}, 0, {768, 0}, {0x62, 0x51, 0x00, 0xFF}}},
	{{{82, 33, -69}, 0, {912, 550}, {0x44, 0x09, 0x95, 0xFF}}},
	{{{72, 52, -53}, 0, {760, 338}, {0x3C, 0x44, 0xA7, 0xFF}}},
	{{{124, 49, 0}, 0, {884, 24}, {0x70, 0x3B, 0x00, 0xFF}}},
	{{{72, 52, 53}, 0, {760, 338}, {0x3C, 0x44, 0x59, 0xFF}}},
	{{{82, 33, 69}, 0, {912, 550}, {0x44, 0x09, 0x6B, 0xFF}}},
	{{{111, 15, 16}, 0, {1346, 194}, {0x62, 0xC0, 0x31, 0xFF}}},
	{{{125, 22, 0}, 0, {1284, -4}, {0x74, 0xCD, 0x00, 0xFF}}},
	{{{106, 12, 8}, 0, {1326, 42}, {0x2B, 0x8D, 0xE1, 0xFF}}},
	{{{111, 15, -16}, 0, {1346, 194}, {0x62, 0xC0, 0xCF, 0xFF}}},
	{{{106, 12, -8}, 0, {1326, 42}, {0x2B, 0x8D, 0x1F, 0xFF}}},
	{{{72, 52, -53}, 0, {1004, 502}, {0x3C, 0x44, 0xA7, 0xFF}}},
	{{{27, 59, -65}, 0, {1002, 502}, {0x04, 0x30, 0x8B, 0xFF}}},
	{{{66, 98, -46}, 0, {1004, 504}, {0x40, 0x3E, 0xA5, 0xFF}}},
	{{{12, 111, -50}, 0, {1002, 504}, {0xDC, 0x53, 0xA6, 0xFF}}},
	{{{-15, 71, -47}, 0, {1002, 504}, {0xA7, 0x22, 0xAC, 0xFF}}},
	{{{38, 124, -25}, 0, {1002, 506}, {0x0E, 0x79, 0xDE, 0xFF}}},
	{{{98, 100, 0}, 0, {1006, 504}, {0x6C, 0x42, 0x00, 0xFF}}},
	{{{38, 124, 25}, 0, {1002, 506}, {0x0E, 0x79, 0x22, 0xFF}}},
	{{{-19, 111, 0}, 0, {1010, 504}, {0xA5, 0x59, 0x00, 0xFF}}},
	{{{12, 111, -50}, 0, {1008, 504}, {0xDC, 0x53, 0xA6, 0xFF}}},
	{{{-15, 71, -47}, 0, {1014, 504}, {0xA7, 0x22, 0xAC, 0xFF}}},
	{{{-39, 57, 0}, 0, {1014, 502}, {0x81, 0x06, 0x00, 0xFF}}},
	{{{-20, 30, -46}, 0, {1014, 502}, {0x9C, 0xDB, 0xBB, 0xFF}}},
	{{{-19, 3, 0}, 0, {1014, 500}, {0xA8, 0xA5, 0x00, 0xFF}}},
	{{{-20, 30, 46}, 0, {1014, 502}, {0x9C, 0xDB, 0x45, 0xFF}}},
	{{{-15, 71, 47}, 0, {1014, 504}, {0xA7, 0x22, 0x54, 0xFF}}},
	{{{12, 111, 50}, 0, {1008, 504}, {0xDC, 0x53, 0x5A, 0xFF}}},
	{{{66, 98, 46}, 0, {1004, 504}, {0x40, 0x3E, 0x5B, 0xFF}}},
	{{{12, 111, 50}, 0, {1002, 504}, {0xDC, 0x53, 0x5A, 0xFF}}},
	{{{27, 59, 65}, 0, {1002, 502}, {0x04, 0x30, 0x75, 0xFF}}},
	{{{-15, 71, 47}, 0, {1002, 504}, {0xA7, 0x22, 0x54, 0xFF}}},
	{{{23, 34, 80}, 0, {1002, 502}, {0xE9, 0x03, 0x7D, 0xFF}}},
	{{{-20, 30, 46}, 0, {1002, 502}, {0x9C, 0xDB, 0x45, 0xFF}}},
	{{{32, -2, 65}, 0, {1004, 500}, {0xF5, 0xA0, 0x52, 0xFF}}},
	{{{-19, 3, 0}, 0, {1002, 500}, {0xA8, 0xA5, 0x00, 0xFF}}},
	{{{46, -20, 0}, 0, {1008, 500}, {0x04, 0x81, 0x00, 0xFF}}},
	{{{32, -2, -65}, 0, {1004, 500}, {0xF5, 0xA0, 0xAE, 0xFF}}},
	{{{-20, 30, -46}, 0, {1002, 502}, {0x9C, 0xDB, 0xBB, 0xFF}}},
	{{{72, 52, 53}, 0, {1004, 502}, {0x3C, 0x44, 0x59, 0xFF}}},
	{{{66, 98, -46}, 0, {160, 38}, {0x40, 0x3E, 0xA5, 0xFF}}},
	{{{98, 100, 0}, 0, {70, 650}, {0x6C, 0x42, 0x00, 0xFF}}},
	{{{72, 52, -53}, 0, {726, 12}, {0x3C, 0x44, 0xA7, 0xFF}}},
	{{{103, 53, 0}, 0, {682, 642}, {0x62, 0x51, 0x00, 0xFF}}},
	{{{72, 52, 53}, 0, {726, 12}, {0x3C, 0x44, 0x59, 0xFF}}},
	{{{66, 98, 46}, 0, {160, 38}, {0x40, 0x3E, 0x5B, 0xFF}}},
	{{{32, -2, 65}, 0, {1526, 140}, {0xF5, 0xA0, 0x52, 0xFF}}},
	{{{46, -20, 0}, 0, {1516, 40}, {0x04, 0x81, 0x00, 0xFF}}},
	{{{106, 0, 0}, 0, {1330, 16}, {0x57, 0xA4, 0x00, 0xFF}}},
	{{{32, -2, -65}, 0, {1526, 140}, {0xF5, 0xA0, 0xAE, 0xFF}}},
	{{{106, 12, -8}, 0, {1298, -14}, {0x2B, 0x8D, 0x1F, 0xFF}}},
	{{{125, 22, 0}, 0, {1284, -4}, {0x74, 0xCD, 0x00, 0xFF}}},
	{{{112, 22, 0}, 0, {1266, -14}, {0xFB, 0x81, 0x00, 0xFF}}},
	{{{106, 12, 8}, 0, {1298, -14}, {0x2B, 0x8D, 0xE1, 0xFF}}},
	{{{72, 52, -53}, 0, {970, 694}, {0x3C, 0x44, 0xA7, 0xFF}}},
	{{{23, 34, -80}, 0, {792, 608}, {0xE9, 0x03, 0x83, 0xFF}}},
	{{{27, 59, -65}, 0, {836, 698}, {0x04, 0x30, 0x8B, 0xFF}}},
	{{{82, 33, -69}, 0, {1014, 652}, {0x44, 0x09, 0x95, 0xFF}}},
	{{{32, -2, -65}, 0, {896, 490}, {0xF5, 0xA0, 0xAE, 0xFF}}},
	{{{-20, 30, -46}, 0, {722, 526}, {0x9C, 0xDB, 0xBB, 0xFF}}},
	{{{-15, 71, -47}, 0, {706, 686}, {0xA7, 0x22, 0xAC, 0xFF}}},
};

Gfx mips_head1_mesh_layer_4_tri_0[] = {
	gsSPVertex(mips_head1_mesh_layer_4_vtx_0 + 0, 62, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
	gsSP2Triangles(12, 11, 10, 0, 11, 12, 13, 0),
	gsSP2Triangles(14, 13, 12, 0, 12, 15, 14, 0),
	gsSP2Triangles(16, 14, 15, 0, 17, 18, 19, 0),
	gsSP2Triangles(19, 20, 17, 0, 21, 17, 20, 0),
	gsSP2Triangles(22, 23, 24, 0, 22, 25, 23, 0),
	gsSP2Triangles(26, 25, 22, 0, 26, 27, 25, 0),
	gsSP2Triangles(27, 28, 25, 0, 29, 25, 28, 0),
	gsSP2Triangles(30, 29, 28, 0, 25, 29, 31, 0),
	gsSP2Triangles(32, 31, 29, 0, 25, 31, 23, 0),
	gsSP2Triangles(33, 34, 35, 0, 36, 35, 34, 0),
	gsSP2Triangles(37, 36, 34, 0, 35, 36, 38, 0),
	gsSP2Triangles(35, 38, 39, 0, 40, 39, 38, 0),
	gsSP2Triangles(40, 38, 41, 0, 42, 41, 38, 0),
	gsSP2Triangles(41, 42, 43, 0, 41, 43, 44, 0),
	gsSP2Triangles(45, 44, 43, 0, 44, 45, 46, 0),
	gsSP2Triangles(46, 47, 44, 0, 48, 44, 47, 0),
	gsSP2Triangles(44, 48, 41, 0, 48, 49, 41, 0),
	gsSP2Triangles(40, 41, 49, 0, 39, 40, 50, 0),
	gsSP2Triangles(51, 50, 40, 0, 50, 51, 52, 0),
	gsSP2Triangles(53, 52, 51, 0, 52, 53, 54, 0),
	gsSP2Triangles(55, 54, 53, 0, 54, 55, 56, 0),
	gsSP2Triangles(57, 56, 55, 0, 56, 57, 58, 0),
	gsSP2Triangles(59, 58, 57, 0, 57, 60, 59, 0),
	gsSP1Triangle(61, 50, 52, 0),
	gsSPVertex(mips_head1_mesh_layer_4_vtx_0 + 62, 21, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
	gsSP2Triangles(3, 1, 4, 0, 5, 4, 1, 0),
	gsSP2Triangles(6, 7, 8, 0, 9, 8, 7, 0),
	gsSP2Triangles(10, 11, 12, 0, 13, 12, 11, 0),
	gsSP2Triangles(14, 15, 16, 0, 15, 14, 17, 0),
	gsSP2Triangles(17, 18, 15, 0, 19, 15, 18, 0),
	gsSP2Triangles(15, 19, 20, 0, 20, 16, 15, 0),
	gsSPEndDisplayList(),
};

Vtx mips_ear_l1_mesh_layer_4_vtx_0[8] = {
	{{{-78, -5, 1}, 0, {426, 648}, {0xF6, 0x59, 0x5A, 0xFF}}},
	{{{70, -10, 24}, 0, {382, 676}, {0x30, 0x29, 0x6E, 0xFF}}},
	{{{83, 21, -6}, 0, {316, 642}, {0x38, 0x71, 0xF2, 0xFF}}},
	{{{-78, -5, 1}, 0, {658, 994}, {0xF9, 0x82, 0x10, 0xFF}}},
	{{{62, -16, -29}, 0, {216, 1290}, {0xF4, 0x0B, 0x82, 0xFF}}},
	{{{70, -10, 24}, 0, {250, 710}, {0x94, 0xC1, 0x18, 0xFF}}},
	{{{62, -16, -29}, 0, {390, 608}, {0xF4, 0x0B, 0x82, 0xFF}}},
	{{{-78, -5, 1}, 0, {426, 648}, {0xF0, 0x4A, 0x9A, 0xFF}}},
};

Gfx mips_ear_l1_mesh_layer_4_tri_0[] = {
	gsSPVertex(mips_ear_l1_mesh_layer_4_vtx_0 + 0, 8, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP1Triangle(6, 7, 2, 0),
	gsSPEndDisplayList(),
};

Vtx mips_ear_l2_skinned_mesh_layer_4_vtx_0[7] = {
	{{{83, 21, -6}, 0, {316, 642}, {0x38, 0x71, 0xF2, 0xFF}}},
	{{{70, -10, 24}, 0, {382, 676}, {0x30, 0x29, 0x6E, 0xFF}}},
	{{{62, -16, -29}, 0, {390, 608}, {0xF4, 0x0B, 0x82, 0xFF}}},
	{{{70, -10, 24}, 0, {656, 652}, {0x30, 0x29, 0x6E, 0xFF}}},
	{{{62, -16, -29}, 0, {216, 1290}, {0xF4, 0x0B, 0x82, 0xFF}}},
	{{{70, -10, 24}, 0, {250, 710}, {0x94, 0xC1, 0x18, 0xFF}}},
	{{{70, -10, 24}, 0, {250, 710}, {0x30, 0x29, 0x6E, 0xFF}}},
};

Gfx mips_ear_l2_skinned_mesh_layer_4_tri_0[] = {
	gsSPVertex(mips_ear_l2_skinned_mesh_layer_4_vtx_0 + 0, 7, 0),
	gsSPEndDisplayList(),
};

Vtx mips_ear_l2_mesh_layer_4_vtx_0[8] = {
	{{{172, 3, 33}, 0, {-412, 726}, {0x46, 0xF7, 0x6A, 0xFF}}},
	{{{198, -5, -5}, 0, {-672, 1060}, {0x7A, 0xE3, 0xE9, 0xFF}}},
	{{{0, 20, -3}, 0, {366, 642}, {0xB9, 0x69, 0xFB, 0xFF}}},
	{{{134, 9, -38}, 0, {616, 586}, {0x1E, 0x0D, 0x85, 0xFF}}},
	{{{134, 9, -38}, 0, {-476, 1356}, {0x1E, 0x0D, 0x85, 0xFF}}},
	{{{126, 34, 7}, 0, {808, 630}, {0x0C, 0x7C, 0x18, 0xFF}}},
	{{{0, 20, -3}, 0, {646, 560}, {0xB9, 0x69, 0xFB, 0xFF}}},
	{{{172, 3, 33}, 0, {890, 658}, {0x46, 0xF7, 0x6A, 0xFF}}},
};

Gfx mips_ear_l2_mesh_layer_4_tri_0[] = {
	gsSPVertex(mips_ear_l2_mesh_layer_4_vtx_0 + 0, 8, 7),
	gsSP2Triangles(7, 6, 8, 0, 9, 0, 1, 0),
	gsSP2Triangles(0, 9, 2, 0, 10, 2, 9, 0),
	gsSP2Triangles(11, 8, 4, 0, 8, 5, 4, 0),
	gsSP2Triangles(3, 12, 13, 0, 3, 14, 12, 0),
	gsSPEndDisplayList(),
};

Vtx mips_ear_l2_mesh_layer_4_vtx_1[5] = {
	{{{134, 9, -38}, 0, {854, 518}, {0x1E, 0x0D, 0x85, 0xFF}}},
	{{{0, 20, -3}, 0, {646, 560}, {0xB9, 0x69, 0xFB, 0xFF}}},
	{{{126, 34, 7}, 0, {808, 630}, {0x0C, 0x7C, 0x18, 0xFF}}},
	{{{198, -5, -5}, 0, {974, 580}, {0x7A, 0xE3, 0xE9, 0xFF}}},
	{{{172, 3, 33}, 0, {890, 658}, {0x46, 0xF7, 0x6A, 0xFF}}},
};

Gfx mips_ear_l2_mesh_layer_4_tri_1[] = {
	gsSPVertex(mips_ear_l2_mesh_layer_4_vtx_1 + 0, 5, 0),
	gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
	gsSP1Triangle(3, 2, 4, 0),
	gsSPEndDisplayList(),
};

Vtx mips_ear_r1_mesh_layer_4_vtx_0[8] = {
	{{{-78, -5, -1}, 0, {426, 648}, {0xF0, 0x4A, 0x66, 0xFF}}},
	{{{62, -16, 29}, 0, {390, 608}, {0xF4, 0x0B, 0x7E, 0xFF}}},
	{{{83, 21, 6}, 0, {316, 642}, {0x38, 0x71, 0x0E, 0xFF}}},
	{{{-78, -5, -1}, 0, {658, 994}, {0xF9, 0x82, 0xF0, 0xFF}}},
	{{{70, -10, -24}, 0, {250, 710}, {0x94, 0xC1, 0xE8, 0xFF}}},
	{{{62, -16, 29}, 0, {216, 1290}, {0xF4, 0x0B, 0x7E, 0xFF}}},
	{{{-78, -5, -1}, 0, {426, 648}, {0xF6, 0x59, 0xA6, 0xFF}}},
	{{{70, -10, -24}, 0, {382, 676}, {0x30, 0x29, 0x92, 0xFF}}},
};

Gfx mips_ear_r1_mesh_layer_4_tri_0[] = {
	gsSPVertex(mips_ear_r1_mesh_layer_4_vtx_0 + 0, 8, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP1Triangle(6, 2, 7, 0),
	gsSPEndDisplayList(),
};

Vtx mips_ear_r2_skinned_mesh_layer_4_vtx_0[7] = {
	{{{83, 21, 6}, 0, {316, 642}, {0x38, 0x71, 0x0E, 0xFF}}},
	{{{62, -16, 29}, 0, {390, 608}, {0xF4, 0x0B, 0x7E, 0xFF}}},
	{{{70, -10, -24}, 0, {382, 676}, {0x30, 0x29, 0x92, 0xFF}}},
	{{{70, -10, -24}, 0, {656, 652}, {0x30, 0x29, 0x92, 0xFF}}},
	{{{62, -16, 29}, 0, {216, 1290}, {0xF4, 0x0B, 0x7E, 0xFF}}},
	{{{70, -10, -24}, 0, {250, 710}, {0x94, 0xC1, 0xE8, 0xFF}}},
	{{{70, -10, -24}, 0, {250, 710}, {0x30, 0x29, 0x92, 0xFF}}},
};

Gfx mips_ear_r2_skinned_mesh_layer_4_tri_0[] = {
	gsSPVertex(mips_ear_r2_skinned_mesh_layer_4_vtx_0 + 0, 7, 0),
	gsSPEndDisplayList(),
};

Vtx mips_ear_r2_mesh_layer_4_vtx_0[8] = {
	{{{172, 3, -33}, 0, {-412, 726}, {0x46, 0xF7, 0x96, 0xFF}}},
	{{{198, -5, 5}, 0, {-672, 1060}, {0x7A, 0xE3, 0x17, 0xFF}}},
	{{{0, 20, 3}, 0, {366, 642}, {0xB9, 0x69, 0x05, 0xFF}}},
	{{{134, 9, 38}, 0, {616, 586}, {0x1E, 0x0D, 0x7B, 0xFF}}},
	{{{134, 9, 38}, 0, {-476, 1356}, {0x1E, 0x0D, 0x7B, 0xFF}}},
	{{{0, 20, 3}, 0, {646, 560}, {0xB9, 0x69, 0x05, 0xFF}}},
	{{{126, 34, -7}, 0, {808, 630}, {0x0C, 0x7C, 0xE8, 0xFF}}},
	{{{172, 3, -33}, 0, {890, 658}, {0x46, 0xF7, 0x96, 0xFF}}},
};

Gfx mips_ear_r2_mesh_layer_4_tri_0[] = {
	gsSPVertex(mips_ear_r2_mesh_layer_4_vtx_0 + 0, 8, 7),
	gsSP2Triangles(7, 8, 6, 0, 0, 9, 2, 0),
	gsSP2Triangles(9, 0, 1, 0, 9, 1, 10, 0),
	gsSP2Triangles(8, 4, 5, 0, 4, 8, 11, 0),
	gsSP2Triangles(12, 13, 3, 0, 14, 3, 13, 0),
	gsSPEndDisplayList(),
};

Vtx mips_ear_r2_mesh_layer_4_vtx_1[5] = {
	{{{0, 20, 3}, 0, {646, 560}, {0xB9, 0x69, 0x05, 0xFF}}},
	{{{134, 9, 38}, 0, {854, 518}, {0x1E, 0x0D, 0x7B, 0xFF}}},
	{{{126, 34, -7}, 0, {808, 630}, {0x0C, 0x7C, 0xE8, 0xFF}}},
	{{{198, -5, 5}, 0, {974, 580}, {0x7A, 0xE3, 0x17, 0xFF}}},
	{{{172, 3, -33}, 0, {890, 658}, {0x46, 0xF7, 0x96, 0xFF}}},
};

Gfx mips_ear_r2_mesh_layer_4_tri_1[] = {
	gsSPVertex(mips_ear_r2_mesh_layer_4_vtx_1 + 0, 5, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
	gsSP1Triangle(2, 3, 4, 0),
	gsSPEndDisplayList(),
};

Vtx mips_leg_l1_skinned_mesh_layer_4_vtx_0[11] = {
	{{{-48, -35, 0}, 0, {542, 650}, {0x83, 0xE8, 0x00, 0xFF}}},
	{{{-42, 5, 0}, 0, {542, 650}, {0xA4, 0x58, 0x00, 0xFF}}},
	{{{-19, -86, 0}, 0, {542, 650}, {0xB2, 0x9C, 0x00, 0xFF}}},
	{{{-42, 5, 0}, 0, {966, 630}, {0xA4, 0x58, 0x00, 0xFF}}},
	{{{-19, -86, 0}, 0, {612, 1006}, {0xB2, 0x9C, 0x00, 0xFF}}},
	{{{38, -93, -49}, 0, {116, 946}, {0x05, 0xB0, 0x9D, 0xFF}}},
	{{{-3, 20, 0}, 0, {542, 650}, {0xFB, 0x7F, 0x00, 0xFF}}},
	{{{78, -21, -44}, 0, {542, 650}, {0x29, 0x36, 0x94, 0xFF}}},
	{{{66, -71, -43}, 0, {542, 650}, {0x07, 0xDD, 0x86, 0xFF}}},
	{{{66, -71, -43}, 0, {0, 806}, {0x07, 0xDD, 0x86, 0xFF}}},
	{{{-3, 20, 0}, 0, {940, 522}, {0xFB, 0x7F, 0x00, 0xFF}}},
};

Gfx mips_leg_l1_skinned_mesh_layer_4_tri_0[] = {
	gsSPVertex(mips_leg_l1_skinned_mesh_layer_4_vtx_0 + 0, 11, 0),
	gsSPEndDisplayList(),
};

Vtx mips_leg_l1_mesh_layer_4_vtx_0[8] = {
	{{{37, -14, 14}, 0, {642, 794}, {0x4C, 0xA3, 0x28, 0xFF}}},
	{{{6, 54, 1}, 0, {594, 582}, {0xD1, 0x37, 0x97, 0xFF}}},
	{{{6, 54, 1}, 0, {542, 650}, {0xD1, 0x37, 0x97, 0xFF}}},
	{{{-7, -35, 11}, 0, {542, 650}, {0xE3, 0x8E, 0xD1, 0xFF}}},
	{{{37, -14, 14}, 0, {542, 650}, {0x4C, 0xA3, 0x28, 0xFF}}},
	{{{-24, 15, -12}, 0, {876, 600}, {0xA6, 0x0E, 0xA7, 0xFF}}},
	{{{-7, -35, 11}, 0, {946, 732}, {0xE3, 0x8E, 0xD1, 0xFF}}},
	{{{6, 54, 1}, 0, {694, 520}, {0xD1, 0x37, 0x97, 0xFF}}},
};

Gfx mips_leg_l1_mesh_layer_4_tri_0[] = {
	gsSPVertex(mips_leg_l1_mesh_layer_4_vtx_0 + 0, 8, 11),
	gsSP2Triangles(4, 11, 5, 0, 12, 5, 11, 0),
	gsSP2Triangles(5, 12, 9, 0, 6, 7, 13, 0),
	gsSP2Triangles(8, 13, 7, 0, 14, 0, 1, 0),
	gsSP2Triangles(14, 2, 0, 0, 2, 14, 15, 0),
	gsSP2Triangles(3, 16, 17, 0, 3, 10, 16, 0),
	gsSP1Triangle(18, 16, 10, 0),
	gsSPEndDisplayList(),
};

Vtx mips_leg_l1_mesh_layer_4_vtx_1[3] = {
	{{{6, 54, 1}, 0, {694, 520}, {0xD1, 0x37, 0x97, 0xFF}}},
	{{{48, 30, -35}, 0, {592, 654}, {0x25, 0x4F, 0xA3, 0xFF}}},
	{{{-24, 15, -12}, 0, {876, 600}, {0xA6, 0x0E, 0xA7, 0xFF}}},
};

Gfx mips_leg_l1_mesh_layer_4_tri_1[] = {
	gsSPVertex(mips_leg_l1_mesh_layer_4_vtx_1 + 0, 3, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSPEndDisplayList(),
};

Vtx mips_leg_l2_skinned_mesh_layer_4_vtx_0[8] = {
	{{{6, 54, 1}, 0, {528, 656}, {0xD1, 0x37, 0x97, 0xFF}}},
	{{{48, 30, -35}, 0, {528, 656}, {0x25, 0x4F, 0xA3, 0xFF}}},
	{{{6, 54, 1}, 0, {542, 650}, {0xD1, 0x37, 0x97, 0xFF}}},
	{{{37, -14, 14}, 0, {542, 650}, {0x4C, 0xA3, 0x28, 0xFF}}},
	{{{-7, -35, 11}, 0, {542, 650}, {0xE3, 0x8E, 0xD1, 0xFF}}},
	{{{-24, 15, -12}, 0, {876, 600}, {0xA6, 0x0E, 0xA7, 0xFF}}},
	{{{48, 30, -35}, 0, {592, 654}, {0x25, 0x4F, 0xA3, 0xFF}}},
	{{{-7, -35, 11}, 0, {946, 732}, {0xE3, 0x8E, 0xD1, 0xFF}}},
};

Gfx mips_leg_l2_skinned_mesh_layer_4_tri_0[] = {
	gsSPVertex(mips_leg_l2_skinned_mesh_layer_4_vtx_0 + 0, 8, 0),
	gsSPEndDisplayList(),
};

Vtx mips_leg_l2_mesh_layer_4_vtx_0[7] = {
	{{{-22, 16, -1}, 0, {528, 656}, {0xAD, 0x57, 0x29, 0xFF}}},
	{{{-6, 5, -36}, 0, {528, 656}, {0xE9, 0x47, 0x99, 0xFF}}},
	{{{28, -11, -30}, 0, {528, 656}, {0x3A, 0x04, 0x8F, 0xFF}}},
	{{{24, 0, 14}, 0, {542, 650}, {0x0E, 0x0F, 0x7D, 0xFF}}},
	{{{60, -10, -1}, 0, {542, 650}, {0x2B, 0x89, 0x07, 0xFF}}},
	{{{28, -11, -30}, 0, {542, 650}, {0x3A, 0x04, 0x8F, 0xFF}}},
	{{{28, -11, -30}, 0, {744, 738}, {0x3A, 0x04, 0x8F, 0xFF}}},
};

Gfx mips_leg_l2_mesh_layer_4_tri_0[] = {
	gsSPVertex(mips_leg_l2_mesh_layer_4_vtx_0 + 0, 7, 8),
	gsSP2Triangles(0, 8, 1, 0, 9, 1, 8, 0),
	gsSP2Triangles(1, 9, 10, 0, 2, 3, 8, 0),
	gsSP2Triangles(11, 8, 3, 0, 12, 11, 3, 0),
	gsSP2Triangles(13, 12, 3, 0, 13, 3, 4, 0),
	gsSP2Triangles(14, 5, 6, 0, 5, 14, 7, 0),
	gsSPEndDisplayList(),
};

Vtx mips_ankle_l1_skinned_mesh_layer_4_vtx_0[5] = {
	{{{28, -11, -30}, 0, {528, 656}, {0x3A, 0x04, 0x8F, 0xFF}}},
	{{{-6, 5, -36}, 0, {528, 656}, {0xE9, 0x47, 0x99, 0xFF}}},
	{{{60, -10, -1}, 0, {542, 650}, {0x2B, 0x89, 0x07, 0xFF}}},
	{{{-22, 16, -1}, 0, {528, 656}, {0xAD, 0x57, 0x29, 0xFF}}},
	{{{24, 0, 14}, 0, {542, 650}, {0x0E, 0x0F, 0x7D, 0xFF}}},
};

Gfx mips_ankle_l1_skinned_mesh_layer_4_tri_0[] = {
	gsSPVertex(mips_ankle_l1_skinned_mesh_layer_4_vtx_0 + 0, 5, 0),
	gsSPEndDisplayList(),
};

Vtx mips_ankle_l1_mesh_layer_4_vtx_0[4] = {
	{{{28, 6, -15}, 0, {528, 656}, {0xE4, 0xFB, 0x84, 0xFF}}},
	{{{-1, -13, -15}, 0, {542, 650}, {0xAD, 0xCA, 0xB0, 0xFF}}},
	{{{-4, -13, 13}, 0, {542, 650}, {0xA6, 0xCE, 0x4B, 0xFF}}},
	{{{28, 6, 11}, 0, {542, 650}, {0xEE, 0x25, 0x78, 0xFF}}},
};

Gfx mips_ankle_l1_mesh_layer_4_tri_0[] = {
	gsSPVertex(mips_ankle_l1_mesh_layer_4_vtx_0 + 0, 4, 5),
	gsSP2Triangles(5, 0, 1, 0, 0, 5, 2, 0),
	gsSP2Triangles(6, 2, 5, 0, 2, 6, 7, 0),
	gsSP2Triangles(2, 7, 8, 0, 8, 4, 2, 0),
	gsSP2Triangles(8, 3, 4, 0, 8, 5, 3, 0),
	gsSP1Triangle(1, 3, 5, 0),
	gsSPEndDisplayList(),
};

Vtx mips_ankle_l2_skinned_mesh_layer_4_vtx_0[8] = {
	{{{28, 6, 11}, 0, {622, 738}, {0xEE, 0x25, 0x78, 0xFF}}},
	{{{28, 6, 11}, 0, {542, 650}, {0xEE, 0x25, 0x78, 0xFF}}},
	{{{-4, -13, 13}, 0, {542, 650}, {0xA6, 0xCE, 0x4B, 0xFF}}},
	{{{-4, -13, 13}, 0, {532, 804}, {0xA6, 0xCE, 0x4B, 0xFF}}},
	{{{-1, -13, -15}, 0, {514, 1210}, {0xAD, 0xCA, 0xB0, 0xFF}}},
	{{{28, 6, -15}, 0, {866, 736}, {0xE4, 0xFB, 0x84, 0xFF}}},
	{{{28, 6, -15}, 0, {528, 656}, {0xE4, 0xFB, 0x84, 0xFF}}},
	{{{-1, -13, -15}, 0, {864, 760}, {0xAD, 0xCA, 0xB0, 0xFF}}},
};

Gfx mips_ankle_l2_skinned_mesh_layer_4_tri_0[] = {
	gsSPVertex(mips_ankle_l2_skinned_mesh_layer_4_vtx_0 + 0, 8, 0),
	gsSPEndDisplayList(),
};

Vtx mips_ankle_l2_mesh_layer_4_vtx_0[7] = {
	{{{11, -13, 29}, 0, {542, 650}, {0x5D, 0xE7, 0x53, 0xFF}}},
	{{{-22, 14, -1}, 0, {542, 650}, {0x1C, 0x7C, 0xFF, 0xFF}}},
	{{{11, -13, 29}, 0, {570, 1000}, {0x5D, 0xE7, 0x53, 0xFF}}},
	{{{-22, 14, -1}, 0, {726, 894}, {0x1C, 0x7C, 0xFF, 0xFF}}},
	{{{11, -13, 29}, 0, {-682, 570}, {0x5D, 0xE7, 0x53, 0xFF}}},
	{{{3, -13, -31}, 0, {-638, 1436}, {0x51, 0xE3, 0xA2, 0xFF}}},
	{{{3, -13, -31}, 0, {866, 1000}, {0x51, 0xE3, 0xA2, 0xFF}}},
};

Gfx mips_ankle_l2_mesh_layer_4_tri_0[] = {
	gsSPVertex(mips_ankle_l2_mesh_layer_4_vtx_0 + 0, 7, 8),
	gsSP2Triangles(8, 1, 2, 0, 6, 1, 9, 0),
	gsSP2Triangles(0, 10, 11, 0, 3, 4, 12, 0),
	gsSP2Triangles(13, 12, 4, 0, 7, 5, 14, 0),
	gsSP1Triangle(11, 14, 5, 0),
	gsSPEndDisplayList(),
};

Vtx mips_ankle_l2_mesh_layer_4_vtx_1[3] = {
	{{{3, -13, -31}, 0, {866, 1000}, {0x51, 0xE3, 0xA2, 0xFF}}},
	{{{-22, 14, -1}, 0, {726, 894}, {0x1C, 0x7C, 0xFF, 0xFF}}},
	{{{11, -13, 29}, 0, {570, 1000}, {0x5D, 0xE7, 0x53, 0xFF}}},
};

Gfx mips_ankle_l2_mesh_layer_4_tri_1[] = {
	gsSPVertex(mips_ankle_l2_mesh_layer_4_vtx_1 + 0, 3, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSPEndDisplayList(),
};

Vtx mips_leg_r1_skinned_mesh_layer_4_vtx_0[9] = {
	{{{-42, 5, 0}, 0, {542, 650}, {0xA4, 0x58, 0x00, 0xFF}}},
	{{{-19, -86, 0}, 0, {542, 650}, {0xB2, 0x9C, 0x00, 0xFF}}},
	{{{-48, -35, 0}, 0, {542, 650}, {0x83, 0xE8, 0x00, 0xFF}}},
	{{{-3, 20, 0}, 0, {542, 650}, {0xFB, 0x7F, 0x00, 0xFF}}},
	{{{-19, -86, 0}, 0, {612, 1006}, {0xB2, 0x9C, 0x00, 0xFF}}},
	{{{38, -93, 49}, 0, {116, 946}, {0x05, 0xB0, 0x63, 0xFF}}},
	{{{78, -21, 44}, 0, {542, 650}, {0x29, 0x36, 0x6C, 0xFF}}},
	{{{66, -71, 43}, 0, {542, 650}, {0x07, 0xDD, 0x7A, 0xFF}}},
	{{{66, -71, 43}, 0, {0, 806}, {0x07, 0xDD, 0x7A, 0xFF}}},
};

Gfx mips_leg_r1_skinned_mesh_layer_4_tri_0[] = {
	gsSPVertex(mips_leg_r1_skinned_mesh_layer_4_vtx_0 + 0, 9, 0),
	gsSPEndDisplayList(),
};

Vtx mips_leg_r1_mesh_layer_4_vtx_0[6] = {
	{{{37, -14, -14}, 0, {642, 794}, {0x4C, 0xA3, 0xD8, 0xFF}}},
	{{{6, 54, -1}, 0, {594, 582}, {0xD1, 0x37, 0x69, 0xFF}}},
	{{{6, 54, -1}, 0, {542, 650}, {0xD1, 0x37, 0x69, 0xFF}}},
	{{{-24, 15, 12}, 0, {542, 650}, {0xA6, 0x0E, 0x59, 0xFF}}},
	{{{-7, -35, -11}, 0, {542, 650}, {0xE3, 0x8E, 0x2F, 0xFF}}},
	{{{37, -14, -14}, 0, {542, 650}, {0x4C, 0xA3, 0xD8, 0xFF}}},
};

Gfx mips_leg_r1_mesh_layer_4_tri_0[] = {
	gsSPVertex(mips_leg_r1_mesh_layer_4_vtx_0 + 0, 6, 9),
	gsSP2Triangles(9, 4, 5, 0, 5, 10, 9, 0),
	gsSP2Triangles(10, 5, 8, 0, 7, 6, 11, 0),
	gsSP2Triangles(3, 11, 6, 0, 11, 3, 12, 0),
	gsSP2Triangles(0, 12, 3, 0, 12, 0, 13, 0),
	gsSP2Triangles(0, 2, 13, 0, 2, 1, 13, 0),
	gsSP1Triangle(14, 13, 1, 0),
	gsSPEndDisplayList(),
};

Vtx mips_leg_r1_mesh_layer_4_vtx_1[3] = {
	{{{-24, 15, 12}, 0, {768, 684}, {0xA6, 0x0E, 0x59, 0xFF}}},
	{{{48, 30, 35}, 0, {776, 528}, {0x25, 0x4F, 0x5D, 0xFF}}},
	{{{6, 54, -1}, 0, {620, 534}, {0xD1, 0x37, 0x69, 0xFF}}},
};

Gfx mips_leg_r1_mesh_layer_4_tri_1[] = {
	gsSPVertex(mips_leg_r1_mesh_layer_4_vtx_1 + 0, 3, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSPEndDisplayList(),
};

Vtx mips_leg_r2_skinned_mesh_layer_4_vtx_0[7] = {
	{{{37, -14, -14}, 0, {542, 650}, {0x4C, 0xA3, 0xD8, 0xFF}}},
	{{{6, 54, -1}, 0, {620, 534}, {0xD1, 0x37, 0x69, 0xFF}}},
	{{{48, 30, 35}, 0, {776, 528}, {0x25, 0x4F, 0x5D, 0xFF}}},
	{{{6, 54, -1}, 0, {542, 650}, {0xD1, 0x37, 0x69, 0xFF}}},
	{{{-7, -35, -11}, 0, {542, 650}, {0xE3, 0x8E, 0x2F, 0xFF}}},
	{{{-24, 15, 12}, 0, {768, 684}, {0xA6, 0x0E, 0x59, 0xFF}}},
	{{{-24, 15, 12}, 0, {542, 650}, {0xA6, 0x0E, 0x59, 0xFF}}},
};

Gfx mips_leg_r2_skinned_mesh_layer_4_tri_0[] = {
	gsSPVertex(mips_leg_r2_skinned_mesh_layer_4_vtx_0 + 0, 7, 0),
	gsSPEndDisplayList(),
};

Vtx mips_leg_r2_mesh_layer_4_vtx_0[7] = {
	{{{-22, 16, 1}, 0, {884, 464}, {0xAD, 0x57, 0xD7, 0xFF}}},
	{{{-6, 5, 36}, 0, {910, 530}, {0xE9, 0x47, 0x67, 0xFF}}},
	{{{28, -11, 30}, 0, {900, 590}, {0x3A, 0x04, 0x71, 0xFF}}},
	{{{-22, 16, 1}, 0, {542, 650}, {0xAD, 0x57, 0xD7, 0xFF}}},
	{{{24, 0, -14}, 0, {542, 650}, {0x0E, 0x0F, 0x83, 0xFF}}},
	{{{60, -10, 1}, 0, {542, 650}, {0x2B, 0x89, 0xF9, 0xFF}}},
	{{{28, -11, 30}, 0, {542, 650}, {0x3A, 0x04, 0x71, 0xFF}}},
};

Gfx mips_leg_r2_mesh_layer_4_tri_0[] = {
	gsSPVertex(mips_leg_r2_mesh_layer_4_vtx_0 + 0, 7, 7),
	gsSP2Triangles(7, 1, 2, 0, 7, 2, 8, 0),
	gsSP2Triangles(9, 8, 2, 0, 2, 5, 9, 0),
	gsSP2Triangles(3, 10, 0, 0, 10, 11, 0, 0),
	gsSP2Triangles(11, 12, 0, 0, 12, 13, 0, 0),
	gsSP2Triangles(4, 0, 13, 0, 6, 4, 13, 0),
	gsSPEndDisplayList(),
};

Vtx mips_ankle_r1_skinned_mesh_layer_4_vtx_0[5] = {
	{{{28, -11, 30}, 0, {542, 650}, {0x3A, 0x04, 0x71, 0xFF}}},
	{{{60, -10, 1}, 0, {542, 650}, {0x2B, 0x89, 0xF9, 0xFF}}},
	{{{-22, 16, 1}, 0, {542, 650}, {0xAD, 0x57, 0xD7, 0xFF}}},
	{{{-6, 5, 36}, 0, {542, 650}, {0xE9, 0x47, 0x67, 0xFF}}},
	{{{24, 0, -14}, 0, {542, 650}, {0x0E, 0x0F, 0x83, 0xFF}}},
};

Gfx mips_ankle_r1_skinned_mesh_layer_4_tri_0[] = {
	gsSPVertex(mips_ankle_r1_skinned_mesh_layer_4_vtx_0 + 0, 5, 0),
	gsSPEndDisplayList(),
};

Vtx mips_ankle_r1_mesh_layer_4_vtx_0[4] = {
	{{{28, 6, 15}, 0, {542, 650}, {0xE4, 0xFB, 0x7C, 0xFF}}},
	{{{-1, -13, 15}, 0, {542, 650}, {0xAD, 0xCA, 0x50, 0xFF}}},
	{{{-4, -13, -13}, 0, {542, 650}, {0xA6, 0xCE, 0xB5, 0xFF}}},
	{{{28, 6, -11}, 0, {542, 650}, {0xEE, 0x25, 0x88, 0xFF}}},
};

Gfx mips_ankle_r1_mesh_layer_4_tri_0[] = {
	gsSPVertex(mips_ankle_r1_mesh_layer_4_vtx_0 + 0, 4, 5),
	gsSP2Triangles(0, 1, 5, 0, 6, 5, 1, 0),
	gsSP2Triangles(6, 1, 7, 0, 1, 8, 7, 0),
	gsSP2Triangles(8, 1, 4, 0, 8, 4, 2, 0),
	gsSP2Triangles(2, 5, 8, 0, 5, 2, 3, 0),
	gsSP1Triangle(5, 3, 0, 0),
	gsSPEndDisplayList(),
};

Vtx mips_ankle_r1_mesh_layer_4_vtx_1[15] = {
	{{{123, 14, 1}, 0, {542, 650}, {0x1C, 0x7C, 0x01, 0xFF}}},
	{{{28, 6, -11}, 0, {542, 650}, {0xEE, 0x25, 0x88, 0xFF}}},
	{{{28, 6, 15}, 0, {542, 650}, {0xE4, 0xFB, 0x7C, 0xFF}}},
	{{{156, -13, -29}, 0, {542, 650}, {0x5D, 0xE7, 0xAD, 0xFF}}},
	{{{-4, -13, -13}, 0, {542, 650}, {0xA6, 0xCE, 0xB5, 0xFF}}},
	{{{-1, -13, 15}, 0, {864, 760}, {0xAD, 0xCA, 0x50, 0xFF}}},
	{{{147, -13, 31}, 0, {866, 1000}, {0x51, 0xE3, 0x5E, 0xFF}}},
	{{{28, 6, 15}, 0, {866, 736}, {0xE4, 0xFB, 0x7C, 0xFF}}},
	{{{123, 14, 1}, 0, {726, 894}, {0x1C, 0x7C, 0x01, 0xFF}}},
	{{{156, -13, -29}, 0, {570, 1000}, {0x5D, 0xE7, 0xAD, 0xFF}}},
	{{{28, 6, -11}, 0, {622, 738}, {0xEE, 0x25, 0x88, 0xFF}}},
	{{{-4, -13, -13}, 0, {532, 804}, {0xA6, 0xCE, 0xB5, 0xFF}}},
	{{{156, -13, -29}, 0, {-682, 570}, {0x5D, 0xE7, 0xAD, 0xFF}}},
	{{{-1, -13, 15}, 0, {514, 1210}, {0xAD, 0xCA, 0x50, 0xFF}}},
	{{{147, -13, 31}, 0, {-638, 1436}, {0x51, 0xE3, 0x5E, 0xFF}}},
};

Gfx mips_ankle_r1_mesh_layer_4_tri_1[] = {
	gsSPVertex(mips_ankle_r1_mesh_layer_4_vtx_1 + 0, 15, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 1, 0),
	gsSP2Triangles(5, 6, 7, 0, 8, 7, 6, 0),
	gsSP2Triangles(6, 9, 8, 0, 10, 8, 9, 0),
	gsSP2Triangles(11, 12, 13, 0, 14, 13, 12, 0),
	gsSPEndDisplayList(),
};

Vtx mips_tail_mesh_layer_4_vtx_0[4] = {
	{{{-34, 32, 0}, 0, {1584, 480}, {0x00, 0x00, 0x7F, 0xFF}}},
	{{{-34, -35, 0}, 0, {1064, 480}, {0x00, 0x00, 0x7F, 0xFF}}},
	{{{33, -35, 0}, 0, {1064, 996}, {0x00, 0x00, 0x7F, 0xFF}}},
	{{{33, 32, 0}, 0, {1584, 996}, {0x00, 0x00, 0x7F, 0xFF}}},
};

Gfx mips_tail_mesh_layer_4_tri_0[] = {
	gsSPVertex(mips_tail_mesh_layer_4_vtx_0 + 0, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSPEndDisplayList(),
};


Gfx mat_mips_mips_yellow[] = {
	gsSPClearGeometryMode(G_CULL_BACK),
	gsSPSetLights1(mips_mips_yellow_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, mips_mips_yellow_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 2047, 128),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 0, 0, 0, G_TX_WRAP | G_TX_MIRROR, 5, 0, G_TX_WRAP | G_TX_MIRROR, 6, 0),
	gsDPSetTileSize(0, 0, 0, 252, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_mips_mips_yellow[] = {
	gsSPSetGeometryMode(G_CULL_BACK),
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsSPEndDisplayList(),
};

Gfx mat_mips_mips_orange[] = {
	gsSPClearGeometryMode(G_CULL_BACK),
	gsSPSetLights1(mips_mips_orange_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, mips_mips_orange_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 2047, 128),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 0, 0, 0, G_TX_WRAP | G_TX_MIRROR, 5, 0, G_TX_WRAP | G_TX_MIRROR, 6, 0),
	gsDPSetTileSize(0, 0, 0, 252, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_mips_mips_orange[] = {
	gsSPSetGeometryMode(G_CULL_BACK),
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsSPEndDisplayList(),
};

Gfx mat_mips_mips_pink[] = {
	gsSPClearGeometryMode(G_CULL_BACK),
	gsSPSetLights1(mips_mips_pink_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, mips_mips_pink_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 2047, 128),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 0, 0, 0, G_TX_WRAP | G_TX_MIRROR, 5, 0, G_TX_WRAP | G_TX_MIRROR, 6, 0),
	gsDPSetTileSize(0, 0, 0, 252, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_mips_mips_pink[] = {
	gsSPSetGeometryMode(G_CULL_BACK),
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsSPEndDisplayList(),
};

Gfx mat_mips_mips_green[] = {
	gsSPClearGeometryMode(G_CULL_BACK),
	gsSPSetLights1(mips_mips_green_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, mips_mips_green_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 2047, 128),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 0, 0, 0, G_TX_WRAP | G_TX_MIRROR, 5, 0, G_TX_WRAP | G_TX_MIRROR, 6, 0),
	gsDPSetTileSize(0, 0, 0, 252, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_mips_mips_green[] = {
	gsSPSetGeometryMode(G_CULL_BACK),
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsSPEndDisplayList(),
};

Gfx mat_mips_mips_white[] = {
	gsSPClearGeometryMode(G_CULL_BACK),
	gsSPSetLights1(mips_mips_white_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, mips_mips_white_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 2047, 128),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 0, 0, 0, G_TX_WRAP | G_TX_MIRROR, 5, 0, G_TX_WRAP | G_TX_MIRROR, 6, 0),
	gsDPSetTileSize(0, 0, 0, 252, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_mips_mips_white[] = {
	gsSPSetGeometryMode(G_CULL_BACK),
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsSPEndDisplayList(),
};

Gfx mat_mips_mips_cyan[] = {
	gsSPClearGeometryMode(G_CULL_BACK),
	gsSPSetLights1(mips_mips_cyan_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, mips_mips_blue_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 2047, 128),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 0, 0, 0, G_TX_WRAP | G_TX_MIRROR, 5, 0, G_TX_WRAP | G_TX_MIRROR, 6, 0),
	gsDPSetTileSize(0, 0, 0, 252, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_mips_mips_cyan[] = {
	gsSPSetGeometryMode(G_CULL_BACK),
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsSPEndDisplayList(),
};

Gfx mips_skl_root_mesh_layer_4[] = {
	gsSPDisplayList(mat_mips_mips_yellow),
	gsSPDisplayList(mips_skl_root_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_yellow),
	gsSPEndDisplayList(),
};

Gfx mips_skl_root_mesh_layer_4_mat_override_mips_orange_0[] = {
	gsSPDisplayList(mat_mips_mips_orange),
	gsSPDisplayList(mips_skl_root_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_orange),
	gsSPEndDisplayList(),
};

Gfx mips_skl_root_mesh_layer_4_mat_override_mips_pink_1[] = {
	gsSPDisplayList(mat_mips_mips_pink),
	gsSPDisplayList(mips_skl_root_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_pink),
	gsSPEndDisplayList(),
};

Gfx mips_skl_root_mesh_layer_4_mat_override_mips_green_2[] = {
	gsSPDisplayList(mat_mips_mips_green),
	gsSPDisplayList(mips_skl_root_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_green),
	gsSPEndDisplayList(),
};

Gfx mips_skl_root_mesh_layer_4_mat_override_mips_white_3[] = {
	gsSPDisplayList(mat_mips_mips_white),
	gsSPDisplayList(mips_skl_root_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_white),
	gsSPEndDisplayList(),
};

Gfx mips_skl_root_mesh_layer_4_mat_override_mips_cyan_4[] = {
	gsSPDisplayList(mat_mips_mips_cyan),
	gsSPDisplayList(mips_skl_root_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_cyan),
	gsSPEndDisplayList(),
};

Gfx mips_arm_l1_skinned_mesh_layer_4[] = {
	gsSPDisplayList(mat_mips_mips_yellow),
	gsSPDisplayList(mips_arm_l1_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_yellow),
	gsSPEndDisplayList(),
};

Gfx mips_arm_l1_skinned_mesh_layer_4_mat_override_mips_orange_0[] = {
	gsSPDisplayList(mat_mips_mips_orange),
	gsSPDisplayList(mips_arm_l1_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_orange),
	gsSPEndDisplayList(),
};

Gfx mips_arm_l1_skinned_mesh_layer_4_mat_override_mips_pink_1[] = {
	gsSPDisplayList(mat_mips_mips_pink),
	gsSPDisplayList(mips_arm_l1_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_pink),
	gsSPEndDisplayList(),
};

Gfx mips_arm_l1_skinned_mesh_layer_4_mat_override_mips_green_2[] = {
	gsSPDisplayList(mat_mips_mips_green),
	gsSPDisplayList(mips_arm_l1_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_green),
	gsSPEndDisplayList(),
};

Gfx mips_arm_l1_skinned_mesh_layer_4_mat_override_mips_white_3[] = {
	gsSPDisplayList(mat_mips_mips_white),
	gsSPDisplayList(mips_arm_l1_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_white),
	gsSPEndDisplayList(),
};

Gfx mips_arm_l1_skinned_mesh_layer_4_mat_override_mips_cyan_4[] = {
	gsSPDisplayList(mat_mips_mips_cyan),
	gsSPDisplayList(mips_arm_l1_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_cyan),
	gsSPEndDisplayList(),
};

Gfx mips_arm_l1_mesh_layer_4[] = {
	gsSPDisplayList(mat_mips_mips_yellow),
	gsSPDisplayList(mips_arm_l1_mesh_layer_4_tri_0),
	gsSPDisplayList(mips_arm_l1_mesh_layer_4_tri_1),
	gsSPDisplayList(mat_revert_mips_mips_yellow),
	gsSPEndDisplayList(),
};

Gfx mips_arm_l1_mesh_layer_4_mat_override_mips_orange_0[] = {
	gsSPDisplayList(mat_mips_mips_orange),
	gsSPDisplayList(mips_arm_l1_mesh_layer_4_tri_0),
	gsSPDisplayList(mips_arm_l1_mesh_layer_4_tri_1),
	gsSPDisplayList(mat_revert_mips_mips_orange),
	gsSPEndDisplayList(),
};

Gfx mips_arm_l1_mesh_layer_4_mat_override_mips_pink_1[] = {
	gsSPDisplayList(mat_mips_mips_pink),
	gsSPDisplayList(mips_arm_l1_mesh_layer_4_tri_0),
	gsSPDisplayList(mips_arm_l1_mesh_layer_4_tri_1),
	gsSPDisplayList(mat_revert_mips_mips_pink),
	gsSPEndDisplayList(),
};

Gfx mips_arm_l1_mesh_layer_4_mat_override_mips_green_2[] = {
	gsSPDisplayList(mat_mips_mips_green),
	gsSPDisplayList(mips_arm_l1_mesh_layer_4_tri_0),
	gsSPDisplayList(mips_arm_l1_mesh_layer_4_tri_1),
	gsSPDisplayList(mat_revert_mips_mips_green),
	gsSPEndDisplayList(),
};

Gfx mips_arm_l1_mesh_layer_4_mat_override_mips_white_3[] = {
	gsSPDisplayList(mat_mips_mips_white),
	gsSPDisplayList(mips_arm_l1_mesh_layer_4_tri_0),
	gsSPDisplayList(mips_arm_l1_mesh_layer_4_tri_1),
	gsSPDisplayList(mat_revert_mips_mips_white),
	gsSPEndDisplayList(),
};

Gfx mips_arm_l1_mesh_layer_4_mat_override_mips_cyan_4[] = {
	gsSPDisplayList(mat_mips_mips_cyan),
	gsSPDisplayList(mips_arm_l1_mesh_layer_4_tri_0),
	gsSPDisplayList(mips_arm_l1_mesh_layer_4_tri_1),
	gsSPDisplayList(mat_revert_mips_mips_cyan),
	gsSPEndDisplayList(),
};

Gfx mips_arm_r1_skinned_mesh_layer_4[] = {
	gsSPDisplayList(mat_mips_mips_yellow),
	gsSPDisplayList(mips_arm_r1_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_yellow),
	gsSPEndDisplayList(),
};

Gfx mips_arm_r1_skinned_mesh_layer_4_mat_override_mips_orange_0[] = {
	gsSPDisplayList(mat_mips_mips_orange),
	gsSPDisplayList(mips_arm_r1_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_orange),
	gsSPEndDisplayList(),
};

Gfx mips_arm_r1_skinned_mesh_layer_4_mat_override_mips_pink_1[] = {
	gsSPDisplayList(mat_mips_mips_pink),
	gsSPDisplayList(mips_arm_r1_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_pink),
	gsSPEndDisplayList(),
};

Gfx mips_arm_r1_skinned_mesh_layer_4_mat_override_mips_green_2[] = {
	gsSPDisplayList(mat_mips_mips_green),
	gsSPDisplayList(mips_arm_r1_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_green),
	gsSPEndDisplayList(),
};

Gfx mips_arm_r1_skinned_mesh_layer_4_mat_override_mips_white_3[] = {
	gsSPDisplayList(mat_mips_mips_white),
	gsSPDisplayList(mips_arm_r1_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_white),
	gsSPEndDisplayList(),
};

Gfx mips_arm_r1_skinned_mesh_layer_4_mat_override_mips_cyan_4[] = {
	gsSPDisplayList(mat_mips_mips_cyan),
	gsSPDisplayList(mips_arm_r1_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_cyan),
	gsSPEndDisplayList(),
};

Gfx mips_arm_r1_mesh_layer_4[] = {
	gsSPDisplayList(mat_mips_mips_yellow),
	gsSPDisplayList(mips_arm_r1_mesh_layer_4_tri_0),
	gsSPDisplayList(mips_arm_r1_mesh_layer_4_tri_1),
	gsSPDisplayList(mat_revert_mips_mips_yellow),
	gsSPEndDisplayList(),
};

Gfx mips_arm_r1_mesh_layer_4_mat_override_mips_orange_0[] = {
	gsSPDisplayList(mat_mips_mips_orange),
	gsSPDisplayList(mips_arm_r1_mesh_layer_4_tri_0),
	gsSPDisplayList(mips_arm_r1_mesh_layer_4_tri_1),
	gsSPDisplayList(mat_revert_mips_mips_orange),
	gsSPEndDisplayList(),
};

Gfx mips_arm_r1_mesh_layer_4_mat_override_mips_pink_1[] = {
	gsSPDisplayList(mat_mips_mips_pink),
	gsSPDisplayList(mips_arm_r1_mesh_layer_4_tri_0),
	gsSPDisplayList(mips_arm_r1_mesh_layer_4_tri_1),
	gsSPDisplayList(mat_revert_mips_mips_pink),
	gsSPEndDisplayList(),
};

Gfx mips_arm_r1_mesh_layer_4_mat_override_mips_green_2[] = {
	gsSPDisplayList(mat_mips_mips_green),
	gsSPDisplayList(mips_arm_r1_mesh_layer_4_tri_0),
	gsSPDisplayList(mips_arm_r1_mesh_layer_4_tri_1),
	gsSPDisplayList(mat_revert_mips_mips_green),
	gsSPEndDisplayList(),
};

Gfx mips_arm_r1_mesh_layer_4_mat_override_mips_white_3[] = {
	gsSPDisplayList(mat_mips_mips_white),
	gsSPDisplayList(mips_arm_r1_mesh_layer_4_tri_0),
	gsSPDisplayList(mips_arm_r1_mesh_layer_4_tri_1),
	gsSPDisplayList(mat_revert_mips_mips_white),
	gsSPEndDisplayList(),
};

Gfx mips_arm_r1_mesh_layer_4_mat_override_mips_cyan_4[] = {
	gsSPDisplayList(mat_mips_mips_cyan),
	gsSPDisplayList(mips_arm_r1_mesh_layer_4_tri_0),
	gsSPDisplayList(mips_arm_r1_mesh_layer_4_tri_1),
	gsSPDisplayList(mat_revert_mips_mips_cyan),
	gsSPEndDisplayList(),
};

Gfx mips_head1_mesh_layer_4[] = {
	gsSPDisplayList(mat_mips_mips_yellow),
	gsSPDisplayList(mips_head1_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_yellow),
	gsSPEndDisplayList(),
};

Gfx mips_head1_mesh_layer_4_mat_override_mips_orange_0[] = {
	gsSPDisplayList(mat_mips_mips_orange),
	gsSPDisplayList(mips_head1_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_orange),
	gsSPEndDisplayList(),
};

Gfx mips_head1_mesh_layer_4_mat_override_mips_pink_1[] = {
	gsSPDisplayList(mat_mips_mips_pink),
	gsSPDisplayList(mips_head1_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_pink),
	gsSPEndDisplayList(),
};

Gfx mips_head1_mesh_layer_4_mat_override_mips_green_2[] = {
	gsSPDisplayList(mat_mips_mips_green),
	gsSPDisplayList(mips_head1_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_green),
	gsSPEndDisplayList(),
};

Gfx mips_head1_mesh_layer_4_mat_override_mips_white_3[] = {
	gsSPDisplayList(mat_mips_mips_white),
	gsSPDisplayList(mips_head1_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_white),
	gsSPEndDisplayList(),
};

Gfx mips_head1_mesh_layer_4_mat_override_mips_cyan_4[] = {
	gsSPDisplayList(mat_mips_mips_cyan),
	gsSPDisplayList(mips_head1_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_cyan),
	gsSPEndDisplayList(),
};

Gfx mips_ear_l1_mesh_layer_4[] = {
	gsSPDisplayList(mat_mips_mips_yellow),
	gsSPDisplayList(mips_ear_l1_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_yellow),
	gsSPEndDisplayList(),
};

Gfx mips_ear_l1_mesh_layer_4_mat_override_mips_orange_0[] = {
	gsSPDisplayList(mat_mips_mips_orange),
	gsSPDisplayList(mips_ear_l1_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_orange),
	gsSPEndDisplayList(),
};

Gfx mips_ear_l1_mesh_layer_4_mat_override_mips_pink_1[] = {
	gsSPDisplayList(mat_mips_mips_pink),
	gsSPDisplayList(mips_ear_l1_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_pink),
	gsSPEndDisplayList(),
};

Gfx mips_ear_l1_mesh_layer_4_mat_override_mips_green_2[] = {
	gsSPDisplayList(mat_mips_mips_green),
	gsSPDisplayList(mips_ear_l1_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_green),
	gsSPEndDisplayList(),
};

Gfx mips_ear_l1_mesh_layer_4_mat_override_mips_white_3[] = {
	gsSPDisplayList(mat_mips_mips_white),
	gsSPDisplayList(mips_ear_l1_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_white),
	gsSPEndDisplayList(),
};

Gfx mips_ear_l1_mesh_layer_4_mat_override_mips_cyan_4[] = {
	gsSPDisplayList(mat_mips_mips_cyan),
	gsSPDisplayList(mips_ear_l1_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_cyan),
	gsSPEndDisplayList(),
};

Gfx mips_ear_l2_skinned_mesh_layer_4[] = {
	gsSPDisplayList(mat_mips_mips_yellow),
	gsSPDisplayList(mips_ear_l2_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_yellow),
	gsSPEndDisplayList(),
};

Gfx mips_ear_l2_skinned_mesh_layer_4_mat_override_mips_orange_0[] = {
	gsSPDisplayList(mat_mips_mips_orange),
	gsSPDisplayList(mips_ear_l2_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_orange),
	gsSPEndDisplayList(),
};

Gfx mips_ear_l2_skinned_mesh_layer_4_mat_override_mips_pink_1[] = {
	gsSPDisplayList(mat_mips_mips_pink),
	gsSPDisplayList(mips_ear_l2_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_pink),
	gsSPEndDisplayList(),
};

Gfx mips_ear_l2_skinned_mesh_layer_4_mat_override_mips_green_2[] = {
	gsSPDisplayList(mat_mips_mips_green),
	gsSPDisplayList(mips_ear_l2_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_green),
	gsSPEndDisplayList(),
};

Gfx mips_ear_l2_skinned_mesh_layer_4_mat_override_mips_white_3[] = {
	gsSPDisplayList(mat_mips_mips_white),
	gsSPDisplayList(mips_ear_l2_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_white),
	gsSPEndDisplayList(),
};

Gfx mips_ear_l2_skinned_mesh_layer_4_mat_override_mips_cyan_4[] = {
	gsSPDisplayList(mat_mips_mips_cyan),
	gsSPDisplayList(mips_ear_l2_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_cyan),
	gsSPEndDisplayList(),
};

Gfx mips_ear_l2_mesh_layer_4[] = {
	gsSPDisplayList(mat_mips_mips_yellow),
	gsSPDisplayList(mips_ear_l2_mesh_layer_4_tri_0),
	gsSPDisplayList(mips_ear_l2_mesh_layer_4_tri_1),
	gsSPDisplayList(mat_revert_mips_mips_yellow),
	gsSPEndDisplayList(),
};

Gfx mips_ear_l2_mesh_layer_4_mat_override_mips_orange_0[] = {
	gsSPDisplayList(mat_mips_mips_orange),
	gsSPDisplayList(mips_ear_l2_mesh_layer_4_tri_0),
	gsSPDisplayList(mips_ear_l2_mesh_layer_4_tri_1),
	gsSPDisplayList(mat_revert_mips_mips_orange),
	gsSPEndDisplayList(),
};

Gfx mips_ear_l2_mesh_layer_4_mat_override_mips_pink_1[] = {
	gsSPDisplayList(mat_mips_mips_pink),
	gsSPDisplayList(mips_ear_l2_mesh_layer_4_tri_0),
	gsSPDisplayList(mips_ear_l2_mesh_layer_4_tri_1),
	gsSPDisplayList(mat_revert_mips_mips_pink),
	gsSPEndDisplayList(),
};

Gfx mips_ear_l2_mesh_layer_4_mat_override_mips_green_2[] = {
	gsSPDisplayList(mat_mips_mips_green),
	gsSPDisplayList(mips_ear_l2_mesh_layer_4_tri_0),
	gsSPDisplayList(mips_ear_l2_mesh_layer_4_tri_1),
	gsSPDisplayList(mat_revert_mips_mips_green),
	gsSPEndDisplayList(),
};

Gfx mips_ear_l2_mesh_layer_4_mat_override_mips_white_3[] = {
	gsSPDisplayList(mat_mips_mips_white),
	gsSPDisplayList(mips_ear_l2_mesh_layer_4_tri_0),
	gsSPDisplayList(mips_ear_l2_mesh_layer_4_tri_1),
	gsSPDisplayList(mat_revert_mips_mips_white),
	gsSPEndDisplayList(),
};

Gfx mips_ear_l2_mesh_layer_4_mat_override_mips_cyan_4[] = {
	gsSPDisplayList(mat_mips_mips_cyan),
	gsSPDisplayList(mips_ear_l2_mesh_layer_4_tri_0),
	gsSPDisplayList(mips_ear_l2_mesh_layer_4_tri_1),
	gsSPDisplayList(mat_revert_mips_mips_cyan),
	gsSPEndDisplayList(),
};

Gfx mips_ear_r1_mesh_layer_4[] = {
	gsSPDisplayList(mat_mips_mips_yellow),
	gsSPDisplayList(mips_ear_r1_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_yellow),
	gsSPEndDisplayList(),
};

Gfx mips_ear_r1_mesh_layer_4_mat_override_mips_orange_0[] = {
	gsSPDisplayList(mat_mips_mips_orange),
	gsSPDisplayList(mips_ear_r1_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_orange),
	gsSPEndDisplayList(),
};

Gfx mips_ear_r1_mesh_layer_4_mat_override_mips_pink_1[] = {
	gsSPDisplayList(mat_mips_mips_pink),
	gsSPDisplayList(mips_ear_r1_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_pink),
	gsSPEndDisplayList(),
};

Gfx mips_ear_r1_mesh_layer_4_mat_override_mips_green_2[] = {
	gsSPDisplayList(mat_mips_mips_green),
	gsSPDisplayList(mips_ear_r1_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_green),
	gsSPEndDisplayList(),
};

Gfx mips_ear_r1_mesh_layer_4_mat_override_mips_white_3[] = {
	gsSPDisplayList(mat_mips_mips_white),
	gsSPDisplayList(mips_ear_r1_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_white),
	gsSPEndDisplayList(),
};

Gfx mips_ear_r1_mesh_layer_4_mat_override_mips_cyan_4[] = {
	gsSPDisplayList(mat_mips_mips_cyan),
	gsSPDisplayList(mips_ear_r1_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_cyan),
	gsSPEndDisplayList(),
};

Gfx mips_ear_r2_skinned_mesh_layer_4[] = {
	gsSPDisplayList(mat_mips_mips_yellow),
	gsSPDisplayList(mips_ear_r2_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_yellow),
	gsSPEndDisplayList(),
};

Gfx mips_ear_r2_skinned_mesh_layer_4_mat_override_mips_orange_0[] = {
	gsSPDisplayList(mat_mips_mips_orange),
	gsSPDisplayList(mips_ear_r2_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_orange),
	gsSPEndDisplayList(),
};

Gfx mips_ear_r2_skinned_mesh_layer_4_mat_override_mips_pink_1[] = {
	gsSPDisplayList(mat_mips_mips_pink),
	gsSPDisplayList(mips_ear_r2_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_pink),
	gsSPEndDisplayList(),
};

Gfx mips_ear_r2_skinned_mesh_layer_4_mat_override_mips_green_2[] = {
	gsSPDisplayList(mat_mips_mips_green),
	gsSPDisplayList(mips_ear_r2_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_green),
	gsSPEndDisplayList(),
};

Gfx mips_ear_r2_skinned_mesh_layer_4_mat_override_mips_white_3[] = {
	gsSPDisplayList(mat_mips_mips_white),
	gsSPDisplayList(mips_ear_r2_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_white),
	gsSPEndDisplayList(),
};

Gfx mips_ear_r2_skinned_mesh_layer_4_mat_override_mips_cyan_4[] = {
	gsSPDisplayList(mat_mips_mips_cyan),
	gsSPDisplayList(mips_ear_r2_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_cyan),
	gsSPEndDisplayList(),
};

Gfx mips_ear_r2_mesh_layer_4[] = {
	gsSPDisplayList(mat_mips_mips_yellow),
	gsSPDisplayList(mips_ear_r2_mesh_layer_4_tri_0),
	gsSPDisplayList(mips_ear_r2_mesh_layer_4_tri_1),
	gsSPDisplayList(mat_revert_mips_mips_yellow),
	gsSPEndDisplayList(),
};

Gfx mips_ear_r2_mesh_layer_4_mat_override_mips_orange_0[] = {
	gsSPDisplayList(mat_mips_mips_orange),
	gsSPDisplayList(mips_ear_r2_mesh_layer_4_tri_0),
	gsSPDisplayList(mips_ear_r2_mesh_layer_4_tri_1),
	gsSPDisplayList(mat_revert_mips_mips_orange),
	gsSPEndDisplayList(),
};

Gfx mips_ear_r2_mesh_layer_4_mat_override_mips_pink_1[] = {
	gsSPDisplayList(mat_mips_mips_pink),
	gsSPDisplayList(mips_ear_r2_mesh_layer_4_tri_0),
	gsSPDisplayList(mips_ear_r2_mesh_layer_4_tri_1),
	gsSPDisplayList(mat_revert_mips_mips_pink),
	gsSPEndDisplayList(),
};

Gfx mips_ear_r2_mesh_layer_4_mat_override_mips_green_2[] = {
	gsSPDisplayList(mat_mips_mips_green),
	gsSPDisplayList(mips_ear_r2_mesh_layer_4_tri_0),
	gsSPDisplayList(mips_ear_r2_mesh_layer_4_tri_1),
	gsSPDisplayList(mat_revert_mips_mips_green),
	gsSPEndDisplayList(),
};

Gfx mips_ear_r2_mesh_layer_4_mat_override_mips_white_3[] = {
	gsSPDisplayList(mat_mips_mips_white),
	gsSPDisplayList(mips_ear_r2_mesh_layer_4_tri_0),
	gsSPDisplayList(mips_ear_r2_mesh_layer_4_tri_1),
	gsSPDisplayList(mat_revert_mips_mips_white),
	gsSPEndDisplayList(),
};

Gfx mips_ear_r2_mesh_layer_4_mat_override_mips_cyan_4[] = {
	gsSPDisplayList(mat_mips_mips_cyan),
	gsSPDisplayList(mips_ear_r2_mesh_layer_4_tri_0),
	gsSPDisplayList(mips_ear_r2_mesh_layer_4_tri_1),
	gsSPDisplayList(mat_revert_mips_mips_cyan),
	gsSPEndDisplayList(),
};

Gfx mips_leg_l1_skinned_mesh_layer_4[] = {
	gsSPDisplayList(mat_mips_mips_yellow),
	gsSPDisplayList(mips_leg_l1_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_yellow),
	gsSPEndDisplayList(),
};

Gfx mips_leg_l1_skinned_mesh_layer_4_mat_override_mips_orange_0[] = {
	gsSPDisplayList(mat_mips_mips_orange),
	gsSPDisplayList(mips_leg_l1_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_orange),
	gsSPEndDisplayList(),
};

Gfx mips_leg_l1_skinned_mesh_layer_4_mat_override_mips_pink_1[] = {
	gsSPDisplayList(mat_mips_mips_pink),
	gsSPDisplayList(mips_leg_l1_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_pink),
	gsSPEndDisplayList(),
};

Gfx mips_leg_l1_skinned_mesh_layer_4_mat_override_mips_green_2[] = {
	gsSPDisplayList(mat_mips_mips_green),
	gsSPDisplayList(mips_leg_l1_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_green),
	gsSPEndDisplayList(),
};

Gfx mips_leg_l1_skinned_mesh_layer_4_mat_override_mips_white_3[] = {
	gsSPDisplayList(mat_mips_mips_white),
	gsSPDisplayList(mips_leg_l1_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_white),
	gsSPEndDisplayList(),
};

Gfx mips_leg_l1_skinned_mesh_layer_4_mat_override_mips_cyan_4[] = {
	gsSPDisplayList(mat_mips_mips_cyan),
	gsSPDisplayList(mips_leg_l1_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_cyan),
	gsSPEndDisplayList(),
};

Gfx mips_leg_l1_mesh_layer_4[] = {
	gsSPDisplayList(mat_mips_mips_yellow),
	gsSPDisplayList(mips_leg_l1_mesh_layer_4_tri_0),
	gsSPDisplayList(mips_leg_l1_mesh_layer_4_tri_1),
	gsSPDisplayList(mat_revert_mips_mips_yellow),
	gsSPEndDisplayList(),
};

Gfx mips_leg_l1_mesh_layer_4_mat_override_mips_orange_0[] = {
	gsSPDisplayList(mat_mips_mips_orange),
	gsSPDisplayList(mips_leg_l1_mesh_layer_4_tri_0),
	gsSPDisplayList(mips_leg_l1_mesh_layer_4_tri_1),
	gsSPDisplayList(mat_revert_mips_mips_orange),
	gsSPEndDisplayList(),
};

Gfx mips_leg_l1_mesh_layer_4_mat_override_mips_pink_1[] = {
	gsSPDisplayList(mat_mips_mips_pink),
	gsSPDisplayList(mips_leg_l1_mesh_layer_4_tri_0),
	gsSPDisplayList(mips_leg_l1_mesh_layer_4_tri_1),
	gsSPDisplayList(mat_revert_mips_mips_pink),
	gsSPEndDisplayList(),
};

Gfx mips_leg_l1_mesh_layer_4_mat_override_mips_green_2[] = {
	gsSPDisplayList(mat_mips_mips_green),
	gsSPDisplayList(mips_leg_l1_mesh_layer_4_tri_0),
	gsSPDisplayList(mips_leg_l1_mesh_layer_4_tri_1),
	gsSPDisplayList(mat_revert_mips_mips_green),
	gsSPEndDisplayList(),
};

Gfx mips_leg_l1_mesh_layer_4_mat_override_mips_white_3[] = {
	gsSPDisplayList(mat_mips_mips_white),
	gsSPDisplayList(mips_leg_l1_mesh_layer_4_tri_0),
	gsSPDisplayList(mips_leg_l1_mesh_layer_4_tri_1),
	gsSPDisplayList(mat_revert_mips_mips_white),
	gsSPEndDisplayList(),
};

Gfx mips_leg_l1_mesh_layer_4_mat_override_mips_cyan_4[] = {
	gsSPDisplayList(mat_mips_mips_cyan),
	gsSPDisplayList(mips_leg_l1_mesh_layer_4_tri_0),
	gsSPDisplayList(mips_leg_l1_mesh_layer_4_tri_1),
	gsSPDisplayList(mat_revert_mips_mips_cyan),
	gsSPEndDisplayList(),
};

Gfx mips_leg_l2_skinned_mesh_layer_4[] = {
	gsSPDisplayList(mat_mips_mips_yellow),
	gsSPDisplayList(mips_leg_l2_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_yellow),
	gsSPEndDisplayList(),
};

Gfx mips_leg_l2_skinned_mesh_layer_4_mat_override_mips_orange_0[] = {
	gsSPDisplayList(mat_mips_mips_orange),
	gsSPDisplayList(mips_leg_l2_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_orange),
	gsSPEndDisplayList(),
};

Gfx mips_leg_l2_skinned_mesh_layer_4_mat_override_mips_pink_1[] = {
	gsSPDisplayList(mat_mips_mips_pink),
	gsSPDisplayList(mips_leg_l2_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_pink),
	gsSPEndDisplayList(),
};

Gfx mips_leg_l2_skinned_mesh_layer_4_mat_override_mips_green_2[] = {
	gsSPDisplayList(mat_mips_mips_green),
	gsSPDisplayList(mips_leg_l2_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_green),
	gsSPEndDisplayList(),
};

Gfx mips_leg_l2_skinned_mesh_layer_4_mat_override_mips_white_3[] = {
	gsSPDisplayList(mat_mips_mips_white),
	gsSPDisplayList(mips_leg_l2_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_white),
	gsSPEndDisplayList(),
};

Gfx mips_leg_l2_skinned_mesh_layer_4_mat_override_mips_cyan_4[] = {
	gsSPDisplayList(mat_mips_mips_cyan),
	gsSPDisplayList(mips_leg_l2_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_cyan),
	gsSPEndDisplayList(),
};

Gfx mips_leg_l2_mesh_layer_4[] = {
	gsSPDisplayList(mat_mips_mips_yellow),
	gsSPDisplayList(mips_leg_l2_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_yellow),
	gsSPEndDisplayList(),
};

Gfx mips_leg_l2_mesh_layer_4_mat_override_mips_orange_0[] = {
	gsSPDisplayList(mat_mips_mips_orange),
	gsSPDisplayList(mips_leg_l2_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_orange),
	gsSPEndDisplayList(),
};

Gfx mips_leg_l2_mesh_layer_4_mat_override_mips_pink_1[] = {
	gsSPDisplayList(mat_mips_mips_pink),
	gsSPDisplayList(mips_leg_l2_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_pink),
	gsSPEndDisplayList(),
};

Gfx mips_leg_l2_mesh_layer_4_mat_override_mips_green_2[] = {
	gsSPDisplayList(mat_mips_mips_green),
	gsSPDisplayList(mips_leg_l2_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_green),
	gsSPEndDisplayList(),
};

Gfx mips_leg_l2_mesh_layer_4_mat_override_mips_white_3[] = {
	gsSPDisplayList(mat_mips_mips_white),
	gsSPDisplayList(mips_leg_l2_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_white),
	gsSPEndDisplayList(),
};

Gfx mips_leg_l2_mesh_layer_4_mat_override_mips_cyan_4[] = {
	gsSPDisplayList(mat_mips_mips_cyan),
	gsSPDisplayList(mips_leg_l2_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_cyan),
	gsSPEndDisplayList(),
};

Gfx mips_ankle_l1_skinned_mesh_layer_4[] = {
	gsSPDisplayList(mat_mips_mips_yellow),
	gsSPDisplayList(mips_ankle_l1_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_yellow),
	gsSPEndDisplayList(),
};

Gfx mips_ankle_l1_skinned_mesh_layer_4_mat_override_mips_orange_0[] = {
	gsSPDisplayList(mat_mips_mips_orange),
	gsSPDisplayList(mips_ankle_l1_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_orange),
	gsSPEndDisplayList(),
};

Gfx mips_ankle_l1_skinned_mesh_layer_4_mat_override_mips_pink_1[] = {
	gsSPDisplayList(mat_mips_mips_pink),
	gsSPDisplayList(mips_ankle_l1_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_pink),
	gsSPEndDisplayList(),
};

Gfx mips_ankle_l1_skinned_mesh_layer_4_mat_override_mips_green_2[] = {
	gsSPDisplayList(mat_mips_mips_green),
	gsSPDisplayList(mips_ankle_l1_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_green),
	gsSPEndDisplayList(),
};

Gfx mips_ankle_l1_skinned_mesh_layer_4_mat_override_mips_white_3[] = {
	gsSPDisplayList(mat_mips_mips_white),
	gsSPDisplayList(mips_ankle_l1_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_white),
	gsSPEndDisplayList(),
};

Gfx mips_ankle_l1_skinned_mesh_layer_4_mat_override_mips_cyan_4[] = {
	gsSPDisplayList(mat_mips_mips_cyan),
	gsSPDisplayList(mips_ankle_l1_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_cyan),
	gsSPEndDisplayList(),
};

Gfx mips_ankle_l1_mesh_layer_4[] = {
	gsSPDisplayList(mat_mips_mips_yellow),
	gsSPDisplayList(mips_ankle_l1_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_yellow),
	gsSPEndDisplayList(),
};

Gfx mips_ankle_l1_mesh_layer_4_mat_override_mips_orange_0[] = {
	gsSPDisplayList(mat_mips_mips_orange),
	gsSPDisplayList(mips_ankle_l1_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_orange),
	gsSPEndDisplayList(),
};

Gfx mips_ankle_l1_mesh_layer_4_mat_override_mips_pink_1[] = {
	gsSPDisplayList(mat_mips_mips_pink),
	gsSPDisplayList(mips_ankle_l1_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_pink),
	gsSPEndDisplayList(),
};

Gfx mips_ankle_l1_mesh_layer_4_mat_override_mips_green_2[] = {
	gsSPDisplayList(mat_mips_mips_green),
	gsSPDisplayList(mips_ankle_l1_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_green),
	gsSPEndDisplayList(),
};

Gfx mips_ankle_l1_mesh_layer_4_mat_override_mips_white_3[] = {
	gsSPDisplayList(mat_mips_mips_white),
	gsSPDisplayList(mips_ankle_l1_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_white),
	gsSPEndDisplayList(),
};

Gfx mips_ankle_l1_mesh_layer_4_mat_override_mips_cyan_4[] = {
	gsSPDisplayList(mat_mips_mips_cyan),
	gsSPDisplayList(mips_ankle_l1_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_cyan),
	gsSPEndDisplayList(),
};

Gfx mips_ankle_l2_skinned_mesh_layer_4[] = {
	gsSPDisplayList(mat_mips_mips_yellow),
	gsSPDisplayList(mips_ankle_l2_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_yellow),
	gsSPEndDisplayList(),
};

Gfx mips_ankle_l2_skinned_mesh_layer_4_mat_override_mips_orange_0[] = {
	gsSPDisplayList(mat_mips_mips_orange),
	gsSPDisplayList(mips_ankle_l2_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_orange),
	gsSPEndDisplayList(),
};

Gfx mips_ankle_l2_skinned_mesh_layer_4_mat_override_mips_pink_1[] = {
	gsSPDisplayList(mat_mips_mips_pink),
	gsSPDisplayList(mips_ankle_l2_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_pink),
	gsSPEndDisplayList(),
};

Gfx mips_ankle_l2_skinned_mesh_layer_4_mat_override_mips_green_2[] = {
	gsSPDisplayList(mat_mips_mips_green),
	gsSPDisplayList(mips_ankle_l2_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_green),
	gsSPEndDisplayList(),
};

Gfx mips_ankle_l2_skinned_mesh_layer_4_mat_override_mips_white_3[] = {
	gsSPDisplayList(mat_mips_mips_white),
	gsSPDisplayList(mips_ankle_l2_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_white),
	gsSPEndDisplayList(),
};

Gfx mips_ankle_l2_skinned_mesh_layer_4_mat_override_mips_cyan_4[] = {
	gsSPDisplayList(mat_mips_mips_cyan),
	gsSPDisplayList(mips_ankle_l2_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_cyan),
	gsSPEndDisplayList(),
};

Gfx mips_ankle_l2_mesh_layer_4[] = {
	gsSPDisplayList(mat_mips_mips_yellow),
	gsSPDisplayList(mips_ankle_l2_mesh_layer_4_tri_0),
	gsSPDisplayList(mips_ankle_l2_mesh_layer_4_tri_1),
	gsSPDisplayList(mat_revert_mips_mips_yellow),
	gsSPEndDisplayList(),
};

Gfx mips_ankle_l2_mesh_layer_4_mat_override_mips_orange_0[] = {
	gsSPDisplayList(mat_mips_mips_orange),
	gsSPDisplayList(mips_ankle_l2_mesh_layer_4_tri_0),
	gsSPDisplayList(mips_ankle_l2_mesh_layer_4_tri_1),
	gsSPDisplayList(mat_revert_mips_mips_orange),
	gsSPEndDisplayList(),
};

Gfx mips_ankle_l2_mesh_layer_4_mat_override_mips_pink_1[] = {
	gsSPDisplayList(mat_mips_mips_pink),
	gsSPDisplayList(mips_ankle_l2_mesh_layer_4_tri_0),
	gsSPDisplayList(mips_ankle_l2_mesh_layer_4_tri_1),
	gsSPDisplayList(mat_revert_mips_mips_pink),
	gsSPEndDisplayList(),
};

Gfx mips_ankle_l2_mesh_layer_4_mat_override_mips_green_2[] = {
	gsSPDisplayList(mat_mips_mips_green),
	gsSPDisplayList(mips_ankle_l2_mesh_layer_4_tri_0),
	gsSPDisplayList(mips_ankle_l2_mesh_layer_4_tri_1),
	gsSPDisplayList(mat_revert_mips_mips_green),
	gsSPEndDisplayList(),
};

Gfx mips_ankle_l2_mesh_layer_4_mat_override_mips_white_3[] = {
	gsSPDisplayList(mat_mips_mips_white),
	gsSPDisplayList(mips_ankle_l2_mesh_layer_4_tri_0),
	gsSPDisplayList(mips_ankle_l2_mesh_layer_4_tri_1),
	gsSPDisplayList(mat_revert_mips_mips_white),
	gsSPEndDisplayList(),
};

Gfx mips_ankle_l2_mesh_layer_4_mat_override_mips_cyan_4[] = {
	gsSPDisplayList(mat_mips_mips_cyan),
	gsSPDisplayList(mips_ankle_l2_mesh_layer_4_tri_0),
	gsSPDisplayList(mips_ankle_l2_mesh_layer_4_tri_1),
	gsSPDisplayList(mat_revert_mips_mips_cyan),
	gsSPEndDisplayList(),
};

Gfx mips_leg_r1_skinned_mesh_layer_4[] = {
	gsSPDisplayList(mat_mips_mips_yellow),
	gsSPDisplayList(mips_leg_r1_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_yellow),
	gsSPEndDisplayList(),
};

Gfx mips_leg_r1_skinned_mesh_layer_4_mat_override_mips_orange_0[] = {
	gsSPDisplayList(mat_mips_mips_orange),
	gsSPDisplayList(mips_leg_r1_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_orange),
	gsSPEndDisplayList(),
};

Gfx mips_leg_r1_skinned_mesh_layer_4_mat_override_mips_pink_1[] = {
	gsSPDisplayList(mat_mips_mips_pink),
	gsSPDisplayList(mips_leg_r1_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_pink),
	gsSPEndDisplayList(),
};

Gfx mips_leg_r1_skinned_mesh_layer_4_mat_override_mips_green_2[] = {
	gsSPDisplayList(mat_mips_mips_green),
	gsSPDisplayList(mips_leg_r1_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_green),
	gsSPEndDisplayList(),
};

Gfx mips_leg_r1_skinned_mesh_layer_4_mat_override_mips_white_3[] = {
	gsSPDisplayList(mat_mips_mips_white),
	gsSPDisplayList(mips_leg_r1_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_white),
	gsSPEndDisplayList(),
};

Gfx mips_leg_r1_skinned_mesh_layer_4_mat_override_mips_cyan_4[] = {
	gsSPDisplayList(mat_mips_mips_cyan),
	gsSPDisplayList(mips_leg_r1_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_cyan),
	gsSPEndDisplayList(),
};

Gfx mips_leg_r1_mesh_layer_4[] = {
	gsSPDisplayList(mat_mips_mips_yellow),
	gsSPDisplayList(mips_leg_r1_mesh_layer_4_tri_0),
	gsSPDisplayList(mips_leg_r1_mesh_layer_4_tri_1),
	gsSPDisplayList(mat_revert_mips_mips_yellow),
	gsSPEndDisplayList(),
};

Gfx mips_leg_r1_mesh_layer_4_mat_override_mips_orange_0[] = {
	gsSPDisplayList(mat_mips_mips_orange),
	gsSPDisplayList(mips_leg_r1_mesh_layer_4_tri_0),
	gsSPDisplayList(mips_leg_r1_mesh_layer_4_tri_1),
	gsSPDisplayList(mat_revert_mips_mips_orange),
	gsSPEndDisplayList(),
};

Gfx mips_leg_r1_mesh_layer_4_mat_override_mips_pink_1[] = {
	gsSPDisplayList(mat_mips_mips_pink),
	gsSPDisplayList(mips_leg_r1_mesh_layer_4_tri_0),
	gsSPDisplayList(mips_leg_r1_mesh_layer_4_tri_1),
	gsSPDisplayList(mat_revert_mips_mips_pink),
	gsSPEndDisplayList(),
};

Gfx mips_leg_r1_mesh_layer_4_mat_override_mips_green_2[] = {
	gsSPDisplayList(mat_mips_mips_green),
	gsSPDisplayList(mips_leg_r1_mesh_layer_4_tri_0),
	gsSPDisplayList(mips_leg_r1_mesh_layer_4_tri_1),
	gsSPDisplayList(mat_revert_mips_mips_green),
	gsSPEndDisplayList(),
};

Gfx mips_leg_r1_mesh_layer_4_mat_override_mips_white_3[] = {
	gsSPDisplayList(mat_mips_mips_white),
	gsSPDisplayList(mips_leg_r1_mesh_layer_4_tri_0),
	gsSPDisplayList(mips_leg_r1_mesh_layer_4_tri_1),
	gsSPDisplayList(mat_revert_mips_mips_white),
	gsSPEndDisplayList(),
};

Gfx mips_leg_r1_mesh_layer_4_mat_override_mips_cyan_4[] = {
	gsSPDisplayList(mat_mips_mips_cyan),
	gsSPDisplayList(mips_leg_r1_mesh_layer_4_tri_0),
	gsSPDisplayList(mips_leg_r1_mesh_layer_4_tri_1),
	gsSPDisplayList(mat_revert_mips_mips_cyan),
	gsSPEndDisplayList(),
};

Gfx mips_leg_r2_skinned_mesh_layer_4[] = {
	gsSPDisplayList(mat_mips_mips_yellow),
	gsSPDisplayList(mips_leg_r2_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_yellow),
	gsSPEndDisplayList(),
};

Gfx mips_leg_r2_skinned_mesh_layer_4_mat_override_mips_orange_0[] = {
	gsSPDisplayList(mat_mips_mips_orange),
	gsSPDisplayList(mips_leg_r2_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_orange),
	gsSPEndDisplayList(),
};

Gfx mips_leg_r2_skinned_mesh_layer_4_mat_override_mips_pink_1[] = {
	gsSPDisplayList(mat_mips_mips_pink),
	gsSPDisplayList(mips_leg_r2_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_pink),
	gsSPEndDisplayList(),
};

Gfx mips_leg_r2_skinned_mesh_layer_4_mat_override_mips_green_2[] = {
	gsSPDisplayList(mat_mips_mips_green),
	gsSPDisplayList(mips_leg_r2_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_green),
	gsSPEndDisplayList(),
};

Gfx mips_leg_r2_skinned_mesh_layer_4_mat_override_mips_white_3[] = {
	gsSPDisplayList(mat_mips_mips_white),
	gsSPDisplayList(mips_leg_r2_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_white),
	gsSPEndDisplayList(),
};

Gfx mips_leg_r2_skinned_mesh_layer_4_mat_override_mips_cyan_4[] = {
	gsSPDisplayList(mat_mips_mips_cyan),
	gsSPDisplayList(mips_leg_r2_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_cyan),
	gsSPEndDisplayList(),
};

Gfx mips_leg_r2_mesh_layer_4[] = {
	gsSPDisplayList(mat_mips_mips_yellow),
	gsSPDisplayList(mips_leg_r2_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_yellow),
	gsSPEndDisplayList(),
};

Gfx mips_leg_r2_mesh_layer_4_mat_override_mips_orange_0[] = {
	gsSPDisplayList(mat_mips_mips_orange),
	gsSPDisplayList(mips_leg_r2_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_orange),
	gsSPEndDisplayList(),
};

Gfx mips_leg_r2_mesh_layer_4_mat_override_mips_pink_1[] = {
	gsSPDisplayList(mat_mips_mips_pink),
	gsSPDisplayList(mips_leg_r2_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_pink),
	gsSPEndDisplayList(),
};

Gfx mips_leg_r2_mesh_layer_4_mat_override_mips_green_2[] = {
	gsSPDisplayList(mat_mips_mips_green),
	gsSPDisplayList(mips_leg_r2_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_green),
	gsSPEndDisplayList(),
};

Gfx mips_leg_r2_mesh_layer_4_mat_override_mips_white_3[] = {
	gsSPDisplayList(mat_mips_mips_white),
	gsSPDisplayList(mips_leg_r2_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_white),
	gsSPEndDisplayList(),
};

Gfx mips_leg_r2_mesh_layer_4_mat_override_mips_cyan_4[] = {
	gsSPDisplayList(mat_mips_mips_cyan),
	gsSPDisplayList(mips_leg_r2_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_cyan),
	gsSPEndDisplayList(),
};

Gfx mips_ankle_r1_skinned_mesh_layer_4[] = {
	gsSPDisplayList(mat_mips_mips_yellow),
	gsSPDisplayList(mips_ankle_r1_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_yellow),
	gsSPEndDisplayList(),
};

Gfx mips_ankle_r1_skinned_mesh_layer_4_mat_override_mips_orange_0[] = {
	gsSPDisplayList(mat_mips_mips_orange),
	gsSPDisplayList(mips_ankle_r1_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_orange),
	gsSPEndDisplayList(),
};

Gfx mips_ankle_r1_skinned_mesh_layer_4_mat_override_mips_pink_1[] = {
	gsSPDisplayList(mat_mips_mips_pink),
	gsSPDisplayList(mips_ankle_r1_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_pink),
	gsSPEndDisplayList(),
};

Gfx mips_ankle_r1_skinned_mesh_layer_4_mat_override_mips_green_2[] = {
	gsSPDisplayList(mat_mips_mips_green),
	gsSPDisplayList(mips_ankle_r1_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_green),
	gsSPEndDisplayList(),
};

Gfx mips_ankle_r1_skinned_mesh_layer_4_mat_override_mips_white_3[] = {
	gsSPDisplayList(mat_mips_mips_white),
	gsSPDisplayList(mips_ankle_r1_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_white),
	gsSPEndDisplayList(),
};

Gfx mips_ankle_r1_skinned_mesh_layer_4_mat_override_mips_cyan_4[] = {
	gsSPDisplayList(mat_mips_mips_cyan),
	gsSPDisplayList(mips_ankle_r1_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_cyan),
	gsSPEndDisplayList(),
};

Gfx mips_ankle_r1_mesh_layer_4[] = {
	gsSPDisplayList(mat_mips_mips_yellow),
	gsSPDisplayList(mips_ankle_r1_mesh_layer_4_tri_0),
	gsSPDisplayList(mips_ankle_r1_mesh_layer_4_tri_1),
	gsSPDisplayList(mat_revert_mips_mips_yellow),
	gsSPEndDisplayList(),
};

Gfx mips_ankle_r1_mesh_layer_4_mat_override_mips_orange_0[] = {
	gsSPDisplayList(mat_mips_mips_orange),
	gsSPDisplayList(mips_ankle_r1_mesh_layer_4_tri_0),
	gsSPDisplayList(mips_ankle_r1_mesh_layer_4_tri_1),
	gsSPDisplayList(mat_revert_mips_mips_orange),
	gsSPEndDisplayList(),
};

Gfx mips_ankle_r1_mesh_layer_4_mat_override_mips_pink_1[] = {
	gsSPDisplayList(mat_mips_mips_pink),
	gsSPDisplayList(mips_ankle_r1_mesh_layer_4_tri_0),
	gsSPDisplayList(mips_ankle_r1_mesh_layer_4_tri_1),
	gsSPDisplayList(mat_revert_mips_mips_pink),
	gsSPEndDisplayList(),
};

Gfx mips_ankle_r1_mesh_layer_4_mat_override_mips_green_2[] = {
	gsSPDisplayList(mat_mips_mips_green),
	gsSPDisplayList(mips_ankle_r1_mesh_layer_4_tri_0),
	gsSPDisplayList(mips_ankle_r1_mesh_layer_4_tri_1),
	gsSPDisplayList(mat_revert_mips_mips_green),
	gsSPEndDisplayList(),
};

Gfx mips_ankle_r1_mesh_layer_4_mat_override_mips_white_3[] = {
	gsSPDisplayList(mat_mips_mips_white),
	gsSPDisplayList(mips_ankle_r1_mesh_layer_4_tri_0),
	gsSPDisplayList(mips_ankle_r1_mesh_layer_4_tri_1),
	gsSPDisplayList(mat_revert_mips_mips_white),
	gsSPEndDisplayList(),
};

Gfx mips_ankle_r1_mesh_layer_4_mat_override_mips_cyan_4[] = {
	gsSPDisplayList(mat_mips_mips_cyan),
	gsSPDisplayList(mips_ankle_r1_mesh_layer_4_tri_0),
	gsSPDisplayList(mips_ankle_r1_mesh_layer_4_tri_1),
	gsSPDisplayList(mat_revert_mips_mips_cyan),
	gsSPEndDisplayList(),
};

Gfx mips_tail_mesh_layer_4[] = {
	gsSPDisplayList(mat_mips_mips_yellow),
	gsSPDisplayList(mips_tail_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_yellow),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

Gfx mips_tail_mesh_layer_4_mat_override_mips_orange_0[] = {
	gsSPDisplayList(mat_mips_mips_orange),
	gsSPDisplayList(mips_tail_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_orange),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

Gfx mips_tail_mesh_layer_4_mat_override_mips_pink_1[] = {
	gsSPDisplayList(mat_mips_mips_pink),
	gsSPDisplayList(mips_tail_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_pink),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

Gfx mips_tail_mesh_layer_4_mat_override_mips_green_2[] = {
	gsSPDisplayList(mat_mips_mips_green),
	gsSPDisplayList(mips_tail_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_green),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

Gfx mips_tail_mesh_layer_4_mat_override_mips_white_3[] = {
	gsSPDisplayList(mat_mips_mips_white),
	gsSPDisplayList(mips_tail_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_white),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

Gfx mips_tail_mesh_layer_4_mat_override_mips_cyan_4[] = {
	gsSPDisplayList(mat_mips_mips_cyan),
	gsSPDisplayList(mips_tail_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_mips_mips_cyan),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

