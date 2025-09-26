Lights1 bobomb_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

Texture bobomb_rgba16[] = {
	#include "actors/bobomb/bobomb.rgba16.inc.c"
};

Vtx bobomb_root_mesh_layer_4_vtx_0[36] = {
	{{{0, 215, -20}, 0, {1168, 336}, {0x00, 0x75, 0xCF, 0xFF}}},
	{{{48, 207, -39}, 0, {1104, 400}, {0x00, 0x75, 0xCF, 0xFF}}},
	{{{-48, 207, -39}, 0, {1104, 240}, {0x00, 0x75, 0xCF, 0xFF}}},
	{{{-69, 189, -84}, 0, {1008, 240}, {0x00, 0x75, 0xCF, 0xFF}}},
	{{{69, 189, -84}, 0, {1008, 400}, {0x00, 0x75, 0xCF, 0xFF}}},
	{{{-48, 170, -128}, 0, {912, 240}, {0x00, 0x75, 0xCF, 0xFF}}},
	{{{48, 170, -128}, 0, {912, 400}, {0x00, 0x75, 0xCF, 0xFF}}},
	{{{0, 162, -147}, 0, {848, 336}, {0x00, 0x75, 0xCF, 0xFF}}},
	{{{-17, 87, 137}, 0, {1232, 1552}, {0xE5, 0x1D, 0x79, 0xFF}}},
	{{{-60, 88, 128}, 0, {784, 1552}, {0xE5, 0x1C, 0x79, 0xFF}}},
	{{{-22, -3, 157}, 0, {1232, 2512}, {0xE4, 0x1C, 0x79, 0xFF}}},
	{{{-66, -3, 147}, 0, {784, 2512}, {0xE3, 0x1C, 0x79, 0xFF}}},
	{{{66, -3, 147}, 0, {784, 2512}, {0x1D, 0x1C, 0x79, 0xFF}}},
	{{{60, 88, 128}, 0, {784, 1552}, {0x1B, 0x1C, 0x79, 0xFF}}},
	{{{22, -3, 157}, 0, {1232, 2512}, {0x1C, 0x1C, 0x79, 0xFF}}},
	{{{17, 87, 137}, 0, {1232, 1552}, {0x1B, 0x1D, 0x79, 0xFF}}},
	{{{-48, 207, -39}, 0, {752, 464}, {0xA6, 0x20, 0x54, 0xFF}}},
	{{{0, 162, 1}, 0, {1006, 176}, {0x00, 0x2F, 0x76, 0xFF}}},
	{{{0, 215, -20}, 0, {1006, 464}, {0x00, 0x2F, 0x76, 0xFF}}},
	{{{-48, 154, -18}, 0, {752, 176}, {0xA6, 0x20, 0x54, 0xFF}}},
	{{{-69, 189, -84}, 0, {528, 464}, {0x81, 0xFE, 0x01, 0xFF}}},
	{{{-68, 136, -62}, 0, {528, 176}, {0x81, 0xFE, 0x01, 0xFF}}},
	{{{-48, 170, -128}, 0, {752, 464}, {0xA6, 0xDC, 0xAE, 0xFF}}},
	{{{-48, 117, -106}, 0, {752, 176}, {0xA6, 0xDC, 0xAE, 0xFF}}},
	{{{0, 162, -147}, 0, {1006, 464}, {0x00, 0xCE, 0x8B, 0xFF}}},
	{{{0, 110, -124}, 0, {1006, 176}, {0x00, 0xCE, 0x8B, 0xFF}}},
	{{{48, 170, -128}, 0, {1264, 464}, {0x5A, 0xDC, 0xAE, 0xFF}}},
	{{{48, 117, -106}, 0, {1264, 176}, {0x5B, 0xDB, 0xAF, 0xFF}}},
	{{{69, 189, -84}, 0, {1488, 464}, {0x7F, 0xFC, 0x03, 0xFF}}},
	{{{66, 136, -62}, 0, {1488, 176}, {0x7F, 0xFC, 0x03, 0xFF}}},
	{{{48, 207, -39}, 0, {1264, 464}, {0x5A, 0x1F, 0x54, 0xFF}}},
	{{{48, 154, -18}, 0, {1264, 176}, {0x5B, 0x20, 0x52, 0xFF}}},
	{{{-15, 220, -116}, 0, {1008, 304}, {0x8B, 0xD6, 0xE6, 0xFF}}},
	{{{15, 220, -116}, 0, {1008, 304}, {0x75, 0xD6, 0xE6, 0xFF}}},
	{{{0, 140, -57}, 0, {1008, 304}, {0x00, 0x95, 0x44, 0xFF}}},
	{{{0, 234, -100}, 0, {1008, 304}, {0x00, 0x35, 0x74, 0xFF}}},
};

Gfx bobomb_root_mesh_layer_4_tri_0[] = {
	gsSPVertex(bobomb_root_mesh_layer_4_vtx_0 + 0, 36, 0),
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

Vtx bobomb_body_billboard_mesh_layer_4_vtx_0[4] = {
	{{{0, 62, 0}, 0, {-752, 528}, {0x00, 0x00, 0x7F, 0xFF}}},
	{{{-57, 5, 0}, 0, {720, 528}, {0x00, 0x00, 0x7F, 0xFF}}},
	{{{0, -52, 0}, 0, {720, 2000}, {0x00, 0x00, 0x7F, 0xFF}}},
	{{{57, 5, 0}, 0, {-752, 2000}, {0x00, 0x00, 0x7F, 0xFF}}},
};

Gfx bobomb_body_billboard_mesh_layer_4_tri_0[] = {
	gsSPVertex(bobomb_body_billboard_mesh_layer_4_vtx_0 + 0, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSPEndDisplayList(),
};

Vtx bobomb_foot_l1_skinned_mesh_layer_4_vtx_0[1] = {
	{{{66, -66, 0}, 0, {1040, 1392}, {0xFF, 0x7F, 0x00, 0xFF}}},
};

Gfx bobomb_foot_l1_skinned_mesh_layer_4_tri_0[] = {
	gsSPVertex(bobomb_foot_l1_skinned_mesh_layer_4_vtx_0 + 0, 1, 0),
	gsSPEndDisplayList(),
};

Vtx bobomb_foot_l1_mesh_layer_4_vtx_0[3] = {
	{{{0, -171, -28}, 0, {816, 1488}, {0xFB, 0x56, 0xA3, 0xFF}}},
	{{{20, -168, 15}, 0, {784, 1392}, {0x5D, 0x55, 0x11, 0xFF}}},
	{{{-19, -174, 14}, 0, {816, 1296}, {0x9C, 0x4E, 0x09, 0xFF}}},
};

Gfx bobomb_foot_l1_mesh_layer_4_tri_0[] = {
	gsSPVertex(bobomb_foot_l1_mesh_layer_4_vtx_0 + 0, 3, 1),
	gsSP2Triangles(1, 0, 2, 0, 0, 1, 3, 0),
	gsSP1Triangle(3, 2, 0, 0),
	gsSPEndDisplayList(),
};

Vtx bobomb_foot_l1_mesh_layer_4_vtx_1[20] = {
	{{{0, -196, -57}, 0, {1008, 1232}, {0xFC, 0x40, 0x92, 0xFF}}},
	{{{0, -171, -28}, 0, {1008, 1200}, {0xFB, 0x56, 0xA3, 0xFF}}},
	{{{41, -231, -31}, 0, {784, 1200}, {0x65, 0xC6, 0xCE, 0xFF}}},
	{{{-37, -231, -29}, 0, {1232, 1200}, {0x9B, 0xC3, 0xD1, 0xFF}}},
	{{{-19, -174, 14}, 0, {1136, 1104}, {0x9C, 0x4E, 0x09, 0xFF}}},
	{{{-46, -220, 79}, 0, {1232, 656}, {0x86, 0xF1, 0x20, 0xFF}}},
	{{{-25, -185, 83}, 0, {1136, 720}, {0xC0, 0x60, 0x35, 0xFF}}},
	{{{0, -215, 119}, 0, {1008, 528}, {0x00, 0x0F, 0x7E, 0xFF}}},
	{{{25, -184, 83}, 0, {880, 720}, {0x3E, 0x5F, 0x38, 0xFF}}},
	{{{46, -220, 79}, 0, {784, 656}, {0x79, 0xF1, 0x23, 0xFF}}},
	{{{20, -168, 15}, 0, {880, 1104}, {0x5D, 0x55, 0x11, 0xFF}}},
	{{{0, -196, -57}, 0, {816, 1200}, {0xFC, 0x40, 0x92, 0xFF}}},
	{{{0, -231, -59}, 0, {816, 1200}, {0xFC, 0xB8, 0x98, 0xFF}}},
	{{{-37, -231, -29}, 0, {816, 1200}, {0x9B, 0xC3, 0xD1, 0xFF}}},
	{{{41, -231, -31}, 0, {816, 1200}, {0x65, 0xC6, 0xCE, 0xFF}}},
	{{{29, -231, 105}, 0, {816, 1200}, {0x4A, 0xC2, 0x53, 0xFF}}},
	{{{46, -220, 79}, 0, {816, 1200}, {0x79, 0xF1, 0x23, 0xFF}}},
	{{{0, -215, 119}, 0, {816, 1200}, {0x00, 0x0F, 0x7E, 0xFF}}},
	{{{-29, -231, 105}, 0, {816, 1200}, {0xB6, 0xC2, 0x52, 0xFF}}},
	{{{-46, -220, 79}, 0, {816, 1200}, {0x86, 0xF1, 0x20, 0xFF}}},
};

Gfx bobomb_foot_l1_mesh_layer_4_tri_1[] = {
	gsSPVertex(bobomb_foot_l1_mesh_layer_4_vtx_1 + 0, 20, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(4, 1, 3, 0, 5, 4, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 7, 6, 5, 0),
	gsSP2Triangles(6, 7, 8, 0, 9, 8, 7, 0),
	gsSP2Triangles(8, 9, 10, 0, 2, 10, 9, 0),
	gsSP2Triangles(10, 2, 1, 0, 8, 10, 6, 0),
	gsSP2Triangles(4, 6, 10, 0, 11, 12, 13, 0),
	gsSP2Triangles(12, 11, 14, 0, 14, 15, 12, 0),
	gsSP2Triangles(15, 14, 16, 0, 16, 17, 15, 0),
	gsSP2Triangles(18, 15, 17, 0, 17, 19, 18, 0),
	gsSP2Triangles(13, 18, 19, 0, 18, 13, 12, 0),
	gsSP1Triangle(18, 12, 15, 0),
	gsSPEndDisplayList(),
};

Vtx bobomb_foot_r1_skinned_mesh_layer_4_vtx_0[1] = {
	{{{-66, -66, 0}, 0, {1040, 1392}, {0x01, 0x7F, 0x00, 0xFF}}},
};

Gfx bobomb_foot_r1_skinned_mesh_layer_4_tri_0[] = {
	gsSPVertex(bobomb_foot_r1_skinned_mesh_layer_4_vtx_0 + 0, 1, 0),
	gsSPEndDisplayList(),
};

Vtx bobomb_foot_r1_mesh_layer_4_vtx_0[3] = {
	{{{0, -171, -28}, 0, {816, 1488}, {0x05, 0x56, 0xA3, 0xFF}}},
	{{{19, -174, 14}, 0, {816, 1296}, {0x64, 0x4E, 0x09, 0xFF}}},
	{{{-20, -168, 15}, 0, {784, 1392}, {0xA3, 0x55, 0x11, 0xFF}}},
};

Gfx bobomb_foot_r1_mesh_layer_4_tri_0[] = {
	gsSPVertex(bobomb_foot_r1_mesh_layer_4_vtx_0 + 0, 3, 1),
	gsSP2Triangles(1, 0, 2, 0, 0, 1, 3, 0),
	gsSP1Triangle(3, 2, 0, 0),
	gsSPEndDisplayList(),
};

Vtx bobomb_foot_r1_mesh_layer_4_vtx_1[20] = {
	{{{0, -196, -57}, 0, {1008, 1232}, {0x04, 0x40, 0x92, 0xFF}}},
	{{{0, -171, -28}, 0, {1008, 1200}, {0x05, 0x56, 0xA3, 0xFF}}},
	{{{37, -231, -29}, 0, {1232, 1200}, {0x65, 0xC3, 0xD1, 0xFF}}},
	{{{-41, -231, -31}, 0, {784, 1200}, {0x9B, 0xC6, 0xCE, 0xFF}}},
	{{{-20, -168, 15}, 0, {880, 1104}, {0xA3, 0x55, 0x11, 0xFF}}},
	{{{-46, -220, 79}, 0, {784, 656}, {0x87, 0xF1, 0x23, 0xFF}}},
	{{{-25, -184, 83}, 0, {880, 720}, {0xC2, 0x5F, 0x38, 0xFF}}},
	{{{0, -215, 119}, 0, {1008, 528}, {0x00, 0x0F, 0x7E, 0xFF}}},
	{{{25, -185, 83}, 0, {1136, 720}, {0x40, 0x60, 0x35, 0xFF}}},
	{{{46, -220, 79}, 0, {1232, 656}, {0x7A, 0xF1, 0x20, 0xFF}}},
	{{{19, -174, 14}, 0, {1136, 1104}, {0x64, 0x4E, 0x09, 0xFF}}},
	{{{0, -196, -57}, 0, {816, 1200}, {0x04, 0x40, 0x92, 0xFF}}},
	{{{37, -231, -29}, 0, {816, 1200}, {0x65, 0xC3, 0xD1, 0xFF}}},
	{{{0, -231, -59}, 0, {816, 1200}, {0x04, 0xB8, 0x98, 0xFF}}},
	{{{29, -231, 105}, 0, {816, 1200}, {0x4A, 0xC2, 0x52, 0xFF}}},
	{{{46, -220, 79}, 0, {816, 1200}, {0x7A, 0xF1, 0x20, 0xFF}}},
	{{{0, -215, 119}, 0, {816, 1200}, {0x00, 0x0F, 0x7E, 0xFF}}},
	{{{-29, -231, 105}, 0, {816, 1200}, {0xB6, 0xC2, 0x53, 0xFF}}},
	{{{-46, -220, 79}, 0, {816, 1200}, {0x87, 0xF1, 0x23, 0xFF}}},
	{{{-41, -231, -31}, 0, {816, 1200}, {0x9B, 0xC6, 0xCE, 0xFF}}},
};

Gfx bobomb_foot_r1_mesh_layer_4_tri_1[] = {
	gsSPVertex(bobomb_foot_r1_mesh_layer_4_vtx_1 + 0, 20, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
	gsSP2Triangles(1, 3, 4, 0, 5, 4, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 7, 6, 5, 0),
	gsSP2Triangles(6, 7, 8, 0, 9, 8, 7, 0),
	gsSP2Triangles(8, 9, 10, 0, 2, 10, 9, 0),
	gsSP2Triangles(10, 2, 1, 0, 10, 4, 8, 0),
	gsSP2Triangles(6, 8, 4, 0, 11, 12, 13, 0),
	gsSP2Triangles(14, 13, 12, 0, 12, 15, 14, 0),
	gsSP2Triangles(16, 14, 15, 0, 16, 17, 14, 0),
	gsSP2Triangles(17, 16, 18, 0, 19, 17, 18, 0),
	gsSP2Triangles(17, 19, 13, 0, 11, 13, 19, 0),
	gsSP1Triangle(13, 14, 17, 0),
	gsSPEndDisplayList(),
};

Vtx bobomb_spring_mesh_layer_4_vtx_0[13] = {
	{{{0, 1, -292}, 0, {2512, 464}, {0x81, 0x00, 0x00, 0xFF}}},
	{{{0, 1, -175}, 0, {1552, 464}, {0x81, 0x00, 0x00, 0xFF}}},
	{{{0, 117, -292}, 0, {2512, -496}, {0x81, 0x00, 0x00, 0xFF}}},
	{{{0, 117, -175}, 0, {1552, -496}, {0x81, 0x00, 0x00, 0xFF}}},
	{{{0, 1, -292}, 0, {2512, -496}, {0x81, 0x00, 0x00, 0xFF}}},
	{{{0, -116, -292}, 0, {2512, 464}, {0x81, 0x00, 0x00, 0xFF}}},
	{{{0, 1, -175}, 0, {1552, -496}, {0x81, 0x00, 0x00, 0xFF}}},
	{{{0, -116, -175}, 0, {1552, 464}, {0x81, 0x00, 0x00, 0xFF}}},
	{{{0, 23, -301}, 0, {528, -144}, {0x00, 0x7F, 0x09, 0xFF}}},
	{{{-22, 0, -301}, 0, {528, -16}, {0x81, 0x00, 0x09, 0xFF}}},
	{{{0, 0, 0}, 0, {1136, -16}, {0x00, 0x00, 0x7F, 0xFF}}},
	{{{0, -22, -301}, 0, {528, 112}, {0x00, 0x81, 0x09, 0xFF}}},
	{{{22, 0, -301}, 0, {528, -16}, {0x7F, 0x00, 0x09, 0xFF}}},
};

Gfx bobomb_spring_mesh_layer_4_tri_0[] = {
	gsSPVertex(bobomb_spring_mesh_layer_4_vtx_0 + 0, 13, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
	gsSP2Triangles(4, 5, 6, 0, 7, 6, 5, 0),
	gsSP2Triangles(8, 9, 10, 0, 11, 10, 9, 0),
	gsSP2Triangles(10, 11, 12, 0, 10, 12, 8, 0),
	gsSPEndDisplayList(),
};


Gfx bobomb_material[] = {
	gsSPClearGeometryMode(G_CULL_BACK),
	gsSPSetLights1(bobomb_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, bobomb_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 2047, 256),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_WRAP | G_TX_MIRROR, 6, 0, G_TX_WRAP | G_TX_MIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 252),
	gsSPEndDisplayList(),
};

Gfx mat_revert_bobomb_f3dlite_material_001[] = {
	gsSPSetGeometryMode(G_CULL_BACK),
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsSPEndDisplayList(),
};

// Black Bobomb

Gfx bobomb_root[] = {
	gsSPDisplayList(bobomb_material),
	gsSPDisplayList(bobomb_root_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_bobomb_f3dlite_material_001),
	gsSPEndDisplayList(),
};

Gfx bobomb_body_billboard[] = {
	gsSPDisplayList(bobomb_material),
	gsSPDisplayList(bobomb_body_billboard_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_bobomb_f3dlite_material_001),
	gsSPEndDisplayList(),
};

Gfx bobomb_foot_l1_skinned[] = {
	gsSPDisplayList(bobomb_material),
	gsSPDisplayList(bobomb_foot_l1_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_bobomb_f3dlite_material_001),
	gsSPEndDisplayList(),
};

Gfx bobomb_foot_l1[] = {
	gsSPDisplayList(bobomb_material),
	gsSPDisplayList(bobomb_foot_l1_mesh_layer_4_tri_0),
	gsSPDisplayList(bobomb_foot_l1_mesh_layer_4_tri_1),
	gsSPDisplayList(mat_revert_bobomb_f3dlite_material_001),
	gsSPEndDisplayList(),
};

Gfx bobomb_foot_r1_skinned[] = {
	gsSPDisplayList(bobomb_material),
	gsSPDisplayList(bobomb_foot_r1_skinned_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_bobomb_f3dlite_material_001),
	gsSPEndDisplayList(),
};

Gfx bobomb_foot_r1[] = {
	gsSPDisplayList(bobomb_material),
	gsSPDisplayList(bobomb_foot_r1_mesh_layer_4_tri_0),
	gsSPDisplayList(bobomb_foot_r1_mesh_layer_4_tri_1),
	gsSPDisplayList(mat_revert_bobomb_f3dlite_material_001),
	gsSPEndDisplayList(),
};

Gfx bobomb_wind_up[] = {
	gsSPDisplayList(bobomb_material),
	gsSPDisplayList(bobomb_spring_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_bobomb_f3dlite_material_001),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};
