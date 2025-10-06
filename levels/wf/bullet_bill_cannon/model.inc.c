Lights1 bullet_bill_cannon_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

Texture bullet_bill_cannon_cannon_rgba16[] = {
	#include "levels/wf/bullet_bill_cannon_front.rgba16.inc.c"
};

Texture bullet_bill_cannon_ganseki01_rgba16[] = {
	#include "levels/wf/bullet_bill_cannon_sides.rgba16.inc.c"
};

Vtx bullet_bill_cannon_cannon_mesh_layer_1_vtx_cull[8] = {
	{{{-167, 0, -167}, 0, {0, 0}, {0x00, 0x00, 0x00, 0x00}}},
	{{{-167, 0, 177}, 0, {0, 0}, {0x00, 0x00, 0x00, 0x00}}},
	{{{-167, 334, 177}, 0, {0, 0}, {0x00, 0x00, 0x00, 0x00}}},
	{{{-167, 334, -167}, 0, {0, 0}, {0x00, 0x00, 0x00, 0x00}}},
	{{{167, 0, -167}, 0, {0, 0}, {0x00, 0x00, 0x00, 0x00}}},
	{{{167, 0, 177}, 0, {0, 0}, {0x00, 0x00, 0x00, 0x00}}},
	{{{167, 334, 177}, 0, {0, 0}, {0x00, 0x00, 0x00, 0x00}}},
	{{{167, 334, -167}, 0, {0, 0}, {0x00, 0x00, 0x00, 0x00}}},
};

Vtx bullet_bill_cannon_cannon_mesh_layer_1_vtx_0[4] = {
	{{{-167, 0, 177}, 0, {-16, -16}, {0xB7, 0xB7, 0x49, 0xFF}}},
	{{{167, 0, 177}, 0, {1008, -16}, {0x49, 0xB7, 0x49, 0xFF}}},
	{{{-167, 334, 177}, 0, {-16, 1008}, {0xB7, 0x49, 0x49, 0xFF}}},
	{{{167, 334, 177}, 0, {1008, 1008}, {0x49, 0x49, 0x49, 0xFF}}},
};

Gfx bullet_bill_cannon_cannon_mesh_layer_1_tri_0[] = {
	gsSPVertex(bullet_bill_cannon_cannon_mesh_layer_1_vtx_0 + 0, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
	gsSPEndDisplayList(),
};

Vtx bullet_bill_cannon_cannon_mesh_layer_1_vtx_1[19] = {
	{{{167, 0, -167}, 0, {1008, -16}, {0x49, 0xB7, 0xB7, 0xFF}}},
	{{{167, 334, 177}, 0, {-16, 1008}, {0x49, 0x49, 0x49, 0xFF}}},
	{{{167, 0, 177}, 0, {-16, -16}, {0x49, 0xB7, 0x49, 0xFF}}},
	{{{167, 0, -167}, 0, {1008, -2}, {0x49, 0xB7, 0xB7, 0xFF}}},
	{{{167, 334, -167}, 0, {1008, 1008}, {0x49, 0x49, 0xB7, 0xFF}}},
	{{{167, 0, 177}, 0, {-16, 1008}, {0x49, 0xB7, 0x49, 0xFF}}},
	{{{-167, 0, 177}, 0, {-16, -16}, {0xB7, 0xB7, 0x49, 0xFF}}},
	{{{167, 0, -167}, 0, {1008, 1008}, {0x49, 0xB7, 0xB7, 0xFF}}},
	{{{-167, 0, -167}, 0, {1008, -16}, {0xB7, 0xB7, 0xB7, 0xFF}}},
	{{{167, 0, -167}, 0, {-16, -16}, {0x49, 0xB7, 0xB7, 0xFF}}},
	{{{167, 334, -167}, 0, {-16, 1008}, {0x49, 0x49, 0xB7, 0xFF}}},
	{{{-167, 334, -167}, 0, {1008, 1008}, {0xB7, 0x49, 0xB7, 0xFF}}},
	{{{-167, 334, 177}, 0, {-16, 1008}, {0xB7, 0x49, 0x49, 0xFF}}},
	{{{167, 334, 177}, 0, {-16, -16}, {0x49, 0x49, 0x49, 0xFF}}},
	{{{167, 334, -167}, 0, {1008, -16}, {0x49, 0x49, 0xB7, 0xFF}}},
	{{{-167, 0, -167}, 0, {-16, -16}, {0xB7, 0xB7, 0xB7, 0xFF}}},
	{{{-167, 0, 177}, 0, {1008, -16}, {0xB7, 0xB7, 0x49, 0xFF}}},
	{{{-167, 334, -167}, 0, {-16, 1006}, {0xB7, 0x49, 0xB7, 0xFF}}},
	{{{-167, 334, 177}, 0, {1008, 1006}, {0xB7, 0x49, 0x49, 0xFF}}},
};

Gfx bullet_bill_cannon_cannon_mesh_layer_1_tri_1[] = {
	gsSPVertex(bullet_bill_cannon_cannon_mesh_layer_1_vtx_1 + 0, 19, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 1, 0),
	gsSP2Triangles(5, 6, 7, 0, 8, 7, 6, 0),
	gsSP2Triangles(9, 8, 10, 0, 11, 10, 8, 0),
	gsSP2Triangles(12, 13, 11, 0, 14, 11, 13, 0),
	gsSP2Triangles(15, 16, 17, 0, 18, 17, 16, 0),
	gsSPEndDisplayList(),
};


Gfx mat_bullet_bill_cannon_f3dlite_material_004[] = {
	gsSPClearGeometryMode(G_SHADING_SMOOTH),
	gsSPSetLights1(bullet_bill_cannon_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, SHADE, TEXEL0, 0, SHADE, 0, 0, 0, 0, SHADE),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, bullet_bill_cannon_cannon_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_bullet_bill_cannon_f3dlite_material_004[] = {
	gsSPSetGeometryMode(G_SHADING_SMOOTH),
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsSPEndDisplayList(),
};

Gfx mat_bullet_bill_cannon_f3dlite_material_005[] = {
	gsSPClearGeometryMode(G_SHADING_SMOOTH),
	gsSPSetLights1(bullet_bill_cannon_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, SHADE, TEXEL0, 0, SHADE, 0, 0, 0, 0, SHADE),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, bullet_bill_cannon_ganseki01_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_bullet_bill_cannon_f3dlite_material_005[] = {
	gsSPSetGeometryMode(G_SHADING_SMOOTH),
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsSPEndDisplayList(),
};

Gfx bullet_bill_cannon_cannon_mesh_layer_1[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(bullet_bill_cannon_cannon_mesh_layer_1_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_bullet_bill_cannon_f3dlite_material_004),
	gsSPDisplayList(bullet_bill_cannon_cannon_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_bullet_bill_cannon_f3dlite_material_004),
	gsSPDisplayList(mat_bullet_bill_cannon_f3dlite_material_005),
	gsSPDisplayList(bullet_bill_cannon_cannon_mesh_layer_1_tri_1),
	gsSPDisplayList(mat_revert_bullet_bill_cannon_f3dlite_material_005),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

