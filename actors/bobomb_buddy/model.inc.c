Lights1 bobomb_buddy_f3dlite_material_002_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

Texture bobomb_buddy_red_bombhei_rgba16[] = {
	#include "actors/bobomb_buddy/bobomb_buddy.rgba16.inc.c"
};

Vtx bobomb_buddy_skl_root_mesh_layer_4_vtx_0[36] = {
	{{{0, 162, -147}, 0, {848, 298}, {0x00, 0x75, 0xCF, 0xFF}}},
	{{{-48, 170, -128}, 0, {912, 394}, {0x00, 0x75, 0xCF, 0xFF}}},
	{{{48, 170, -128}, 0, {912, 234}, {0x00, 0x75, 0xCF, 0xFF}}},
	{{{69, 189, -84}, 0, {1008, 234}, {0x00, 0x75, 0xCF, 0xFF}}},
	{{{-69, 189, -84}, 0, {1008, 394}, {0x00, 0x75, 0xCF, 0xFF}}},
	{{{48, 207, -39}, 0, {1104, 234}, {0x00, 0x75, 0xCF, 0xFF}}},
	{{{-48, 207, -39}, 0, {1104, 394}, {0x00, 0x75, 0xCF, 0xFF}}},
	{{{0, 215, -20}, 0, {1168, 298}, {0x00, 0x75, 0xCF, 0xFF}}},
	{{{-17, 87, 137}, 0, {1232, 1546}, {0xE5, 0x1D, 0x79, 0xFF}}},
	{{{-60, 88, 128}, 0, {784, 1546}, {0xE5, 0x1C, 0x79, 0xFF}}},
	{{{-22, -3, 157}, 0, {1232, 2506}, {0xE4, 0x1C, 0x79, 0xFF}}},
	{{{-66, -3, 147}, 0, {784, 2506}, {0xE3, 0x1C, 0x79, 0xFF}}},
	{{{66, -3, 147}, 0, {784, 2506}, {0x1D, 0x1C, 0x79, 0xFF}}},
	{{{60, 88, 128}, 0, {784, 1546}, {0x1B, 0x1C, 0x79, 0xFF}}},
	{{{22, -3, 157}, 0, {1232, 2506}, {0x1C, 0x1C, 0x79, 0xFF}}},
	{{{17, 87, 137}, 0, {1232, 1546}, {0x1B, 0x1D, 0x79, 0xFF}}},
	{{{48, 170, -128}, 0, {1264, 170}, {0x4D, 0xD8, 0xA3, 0xFF}}},
	{{{0, 110, -124}, 0, {1006, 458}, {0x11, 0xCE, 0x8C, 0xFF}}},
	{{{0, 162, -147}, 0, {1006, 170}, {0xEF, 0xCE, 0x8C, 0xFF}}},
	{{{48, 117, -106}, 0, {1264, 458}, {0x66, 0xE0, 0xBC, 0xFF}}},
	{{{69, 189, -84}, 0, {1488, 170}, {0x7E, 0xF5, 0xF3, 0xFF}}},
	{{{66, 136, -62}, 0, {1488, 458}, {0x7E, 0x02, 0x12, 0xFF}}},
	{{{48, 207, -39}, 0, {1264, 170}, {0x66, 0x1A, 0x47, 0xFF}}},
	{{{48, 154, -18}, 0, {1264, 458}, {0x4E, 0x24, 0x5D, 0xFF}}},
	{{{0, 215, -20}, 0, {1006, 170}, {0x11, 0x2E, 0x75, 0xFF}}},
	{{{0, 162, 1}, 0, {1006, 458}, {0xEF, 0x2E, 0x75, 0xFF}}},
	{{{-48, 207, -39}, 0, {752, 170}, {0xB3, 0x25, 0x5E, 0xFF}}},
	{{{-48, 154, -18}, 0, {752, 458}, {0x9B, 0x1C, 0x48, 0xFF}}},
	{{{-69, 189, -84}, 0, {528, 170}, {0x82, 0x05, 0x11, 0xFF}}},
	{{{-68, 136, -62}, 0, {528, 458}, {0x82, 0xF8, 0xF1, 0xFF}}},
	{{{-48, 170, -128}, 0, {752, 170}, {0x9B, 0xE1, 0xBA, 0xFF}}},
	{{{-48, 117, -106}, 0, {752, 458}, {0xB3, 0xD8, 0xA3, 0xFF}}},
	{{{-15, 220, -116}, 0, {1008, 298}, {0x90, 0xD0, 0xDC, 0xFF}}},
	{{{15, 220, -116}, 0, {1008, 298}, {0x70, 0xD0, 0xDC, 0xFF}}},
	{{{0, 140, -57}, 0, {1008, 298}, {0x00, 0xD4, 0x77, 0xFF}}},
	{{{0, 234, -100}, 0, {1008, 298}, {0x00, 0x35, 0x74, 0xFF}}},
};

Gfx bobomb_buddy_skl_root_mesh_layer_4_tri_0[] = {
	gsSPVertex(bobomb_buddy_skl_root_mesh_layer_4_vtx_0 + 0, 36, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
	gsSP2Triangles(1, 4, 3, 0, 5, 3, 4, 0),
	gsSP2Triangles(4, 6, 5, 0, 7, 5, 6, 0),
	gsSP2Triangles(8, 9, 10, 0, 11, 10, 9, 0),
	gsSP2Triangles(12, 13, 14, 0, 15, 14, 13, 0),
	gsSP2Triangles(16, 17, 18, 0, 17, 16, 19, 0),
	gsSP2Triangles(20, 19, 16, 0, 19, 20, 21, 0),
	gsSP2Triangles(22, 21, 20, 0, 21, 22, 23, 0),
	gsSP2Triangles(24, 23, 22, 0, 23, 24, 25, 0),
	gsSP2Triangles(26, 25, 24, 0, 25, 26, 27, 0),
	gsSP2Triangles(28, 27, 26, 0, 27, 28, 29, 0),
	gsSP2Triangles(30, 29, 28, 0, 29, 30, 31, 0),
	gsSP2Triangles(18, 31, 30, 0, 31, 18, 17, 0),
	gsSP2Triangles(32, 33, 34, 0, 35, 34, 33, 0),
	gsSP1Triangle(34, 35, 32, 0),
	gsSPEndDisplayList(),
};

Vtx bobomb_buddy_body_billboard_mesh_layer_4_vtx_0[4] = {
	{{{0, 62, 0}, 0, {-752, 522}, {0x00, 0x00, 0x7F, 0xFF}}},
	{{{-56, 5, 0}, 0, {720, 522}, {0x00, 0x00, 0x7F, 0xFF}}},
	{{{0, -52, 0}, 0, {720, 1994}, {0x00, 0x00, 0x7F, 0xFF}}},
	{{{57, 5, 0}, 0, {-752, 1994}, {0x00, 0x00, 0x7F, 0xFF}}},
};

Gfx bobomb_buddy_body_billboard_mesh_layer_4_tri_0[] = {
	gsSPVertex(bobomb_buddy_body_billboard_mesh_layer_4_vtx_0 + 0, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSPEndDisplayList(),
};

Vtx bobomb_buddy_foot_l1_mesh_layer_4_vtx_0[26] = {
	{{{-55, -231, 75}, 0, {1200, 714}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{-43, -231, -32}, 0, {1200, 714}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{-35, -231, 117}, 0, {1200, 714}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{1, -231, -69}, 0, {1200, 714}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{1, -231, 126}, 0, {1200, 714}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{35, -231, 112}, 0, {1200, 714}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{42, -231, -34}, 0, {1200, 714}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{53, -231, 70}, 0, {1200, 714}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{-43, -231, -32}, 0, {1082, 746}, {0x99, 0x30, 0xC8, 0xFF}}},
	{{{-55, -231, 75}, 0, {878, 746}, {0x91, 0x3B, 0x11, 0xFF}}},
	{{{-23, -167, 19}, 0, {1012, 526}, {0x99, 0x4A, 0x01, 0xFF}}},
	{{{-22, -179, 81}, 0, {912, 548}, {0xD3, 0x67, 0x3C, 0xFF}}},
	{{{-35, -231, 117}, 0, {826, 746}, {0xBC, 0x48, 0x4F, 0xFF}}},
	{{{1, -231, 126}, 0, {842, 746}, {0x06, 0x4F, 0x63, 0xFF}}},
	{{{20, -178, 78}, 0, {962, 546}, {0x3A, 0x5C, 0x41, 0xFF}}},
	{{{35, -231, 112}, 0, {910, 746}, {0x4C, 0x45, 0x4A, 0xFF}}},
	{{{53, -231, 70}, 0, {1020, 746}, {0x71, 0x38, 0x12, 0xFF}}},
	{{{24, -165, 19}, 0, {1072, 522}, {0x5B, 0x59, 0x06, 0xFF}}},
	{{{42, -231, -34}, 0, {1178, 746}, {0x69, 0x2C, 0xC9, 0xFF}}},
	{{{1, -192, -62}, 0, {1182, 590}, {0xFF, 0x4A, 0x99, 0xFF}}},
	{{{1, -231, -69}, 0, {1194, 746}, {0x01, 0x18, 0x83, 0xFF}}},
	{{{0, -168, -36}, 0, {1136, 522}, {0xFF, 0x4A, 0x99, 0xFF}}},
	{{{-23, -167, 19}, 0, {912, 778}, {0x99, 0x4A, 0x01, 0xFF}}},
	{{{24, -165, 19}, 0, {848, 778}, {0x5B, 0x59, 0x06, 0xFF}}},
	{{{0, -66, 0}, 0, {848, 1610}, {0xFD, 0x76, 0x30, 0xFF}}},
	{{{0, -168, -36}, 0, {784, 778}, {0xFF, 0x4A, 0x99, 0xFF}}},
};

Gfx bobomb_buddy_foot_l1_mesh_layer_4_tri_0[] = {
	gsSPVertex(bobomb_buddy_foot_l1_mesh_layer_4_vtx_0 + 0, 26, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
	gsSP2Triangles(2, 3, 4, 0, 5, 4, 3, 0),
	gsSP2Triangles(3, 6, 5, 0, 7, 5, 6, 0),
	gsSP2Triangles(8, 9, 10, 0, 11, 10, 9, 0),
	gsSP2Triangles(9, 12, 11, 0, 13, 11, 12, 0),
	gsSP2Triangles(11, 13, 14, 0, 15, 14, 13, 0),
	gsSP2Triangles(15, 16, 14, 0, 17, 14, 16, 0),
	gsSP2Triangles(16, 18, 17, 0, 19, 17, 18, 0),
	gsSP2Triangles(18, 20, 19, 0, 20, 8, 19, 0),
	gsSP2Triangles(10, 19, 8, 0, 19, 10, 21, 0),
	gsSP2Triangles(17, 19, 21, 0, 14, 17, 11, 0),
	gsSP2Triangles(10, 11, 17, 0, 22, 23, 24, 0),
	gsSP2Triangles(25, 24, 23, 0, 24, 25, 22, 0),
	gsSPEndDisplayList(),
};

Vtx bobomb_buddy_foot_r1_mesh_layer_4_vtx_0[26] = {
	{{{-53, -231, 70}, 0, {1200, 714}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{-42, -231, -34}, 0, {1200, 714}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{-35, -231, 112}, 0, {1200, 714}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{-1, -231, -69}, 0, {1200, 714}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{-1, -231, 126}, 0, {1200, 714}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{35, -231, 117}, 0, {1200, 714}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{43, -231, -32}, 0, {1200, 714}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{55, -231, 75}, 0, {1200, 714}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{-42, -231, -34}, 0, {1178, 746}, {0x99, 0x30, 0xC8, 0xFF}}},
	{{{-53, -231, 70}, 0, {1020, 746}, {0x91, 0x3B, 0x11, 0xFF}}},
	{{{-24, -165, 19}, 0, {1072, 522}, {0xA5, 0x59, 0x06, 0xFF}}},
	{{{-20, -178, 78}, 0, {962, 546}, {0xC6, 0x5C, 0x41, 0xFF}}},
	{{{-35, -231, 112}, 0, {910, 746}, {0xB4, 0x45, 0x4A, 0xFF}}},
	{{{-1, -231, 126}, 0, {842, 746}, {0xFA, 0x4F, 0x63, 0xFF}}},
	{{{22, -179, 81}, 0, {912, 548}, {0x2D, 0x67, 0x3C, 0xFF}}},
	{{{35, -231, 117}, 0, {826, 746}, {0x44, 0x48, 0x4F, 0xFF}}},
	{{{55, -231, 75}, 0, {878, 746}, {0x71, 0x38, 0x12, 0xFF}}},
	{{{23, -167, 19}, 0, {1012, 526}, {0x67, 0x4A, 0x01, 0xFF}}},
	{{{43, -231, -32}, 0, {1082, 746}, {0x69, 0x2C, 0xC9, 0xFF}}},
	{{{-1, -192, -62}, 0, {1182, 590}, {0xFF, 0x4A, 0x99, 0xFF}}},
	{{{-1, -231, -69}, 0, {1194, 746}, {0x01, 0x18, 0x83, 0xFF}}},
	{{{0, -168, -36}, 0, {1136, 522}, {0xFF, 0x4A, 0x99, 0xFF}}},
	{{{-24, -165, 19}, 0, {848, 778}, {0xA5, 0x59, 0x06, 0xFF}}},
	{{{0, -66, 0}, 0, {848, 1610}, {0xFD, 0x76, 0x30, 0xFF}}},
	{{{0, -168, -36}, 0, {784, 778}, {0xFF, 0x4A, 0x99, 0xFF}}},
	{{{23, -167, 19}, 0, {912, 778}, {0x67, 0x4A, 0x01, 0xFF}}},
};

Gfx bobomb_buddy_foot_r1_mesh_layer_4_tri_0[] = {
	gsSPVertex(bobomb_buddy_foot_r1_mesh_layer_4_vtx_0 + 0, 26, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
	gsSP2Triangles(2, 3, 4, 0, 5, 4, 3, 0),
	gsSP2Triangles(3, 6, 5, 0, 7, 5, 6, 0),
	gsSP2Triangles(8, 9, 10, 0, 11, 10, 9, 0),
	gsSP2Triangles(9, 12, 11, 0, 13, 11, 12, 0),
	gsSP2Triangles(13, 14, 11, 0, 14, 13, 15, 0),
	gsSP2Triangles(15, 16, 14, 0, 16, 17, 14, 0),
	gsSP2Triangles(17, 16, 18, 0, 17, 18, 19, 0),
	gsSP2Triangles(20, 19, 18, 0, 20, 8, 19, 0),
	gsSP2Triangles(10, 19, 8, 0, 19, 10, 21, 0),
	gsSP2Triangles(21, 17, 19, 0, 10, 14, 17, 0),
	gsSP2Triangles(10, 11, 14, 0, 22, 23, 24, 0),
	gsSP2Triangles(23, 22, 25, 0, 25, 24, 23, 0),
	gsSPEndDisplayList(),
};


Gfx mat_bobomb_buddy_f3dlite_material_002[] = {
	gsSPSetLights1(bobomb_buddy_f3dlite_material_002_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, bobomb_buddy_red_bombhei_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 2047, 256),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_WRAP | G_TX_MIRROR, 6, 0, G_TX_WRAP | G_TX_MIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 252),
	gsSPEndDisplayList(),
};

Gfx mat_revert_bobomb_buddy_f3dlite_material_002[] = {
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsSPEndDisplayList(),
};

Gfx bobomb_buddy_skl_root_mesh_layer_4[] = {
	gsSPDisplayList(mat_bobomb_buddy_f3dlite_material_002),
	gsSPDisplayList(bobomb_buddy_skl_root_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_bobomb_buddy_f3dlite_material_002),
	gsSPEndDisplayList(),
};

Gfx bobomb_buddy_body_billboard_mesh_layer_4[] = {
	gsSPDisplayList(mat_bobomb_buddy_f3dlite_material_002),
	gsSPDisplayList(bobomb_buddy_body_billboard_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_bobomb_buddy_f3dlite_material_002),
	gsSPEndDisplayList(),
};

Gfx bobomb_buddy_foot_l1_mesh_layer_4[] = {
	gsSPDisplayList(mat_bobomb_buddy_f3dlite_material_002),
	gsSPDisplayList(bobomb_buddy_foot_l1_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_bobomb_buddy_f3dlite_material_002),
	gsSPEndDisplayList(),
};

Gfx bobomb_buddy_foot_r1_mesh_layer_4[] = {
	gsSPDisplayList(mat_bobomb_buddy_f3dlite_material_002),
	gsSPDisplayList(bobomb_buddy_foot_r1_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_bobomb_buddy_f3dlite_material_002),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

