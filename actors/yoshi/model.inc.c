Lights1 yoshi_yoshi_3_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

Lights1 yoshi_yoshi_1_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

Lights1 yoshi_yoshi_4_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

Lights1 yoshi_yoshi_2_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

Lights1 yoshi_yoshi_eyes_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

Texture yoshi_yoshi_1_rgba16[] = {
	#include "actors/yoshi/yoshi_1.rgba16.inc.c"
};

Texture yoshi_yoshi_2_rgba16[] = {
	#include "actors/yoshi/yoshi_2.rgba16.inc.c"
};

Texture yoshi_yoshi_3_rgba16[] = {
	#include "actors/yoshi/yoshi_3.rgba16.inc.c"
};

Texture yoshi_yoshi_4_rgba16[] = {
	#include "actors/yoshi/yoshi_4.rgba16.inc.c"
};

Texture yoshi_metal_shade_rgba16[] = {
	#include "actors/yoshi/metal_shade.rgba16.inc.c"
};

Texture yoshi_yoshi_eye_rgba16[] = {
	#include "actors/yoshi/yoshi_eye.rgba16.inc.c"
};

Vtx yoshi_skl_root_mesh_layer_1_vtx_0[14] = {
	{{{-5, 6, -33}, 0, {1097, 354}, {0x09, 0x08, 0x82, 0xFF}}},
	{{{24, -12, -20}, 0, {1201, 536}, {0x44, 0xCB, 0xA3, 0xFF}}},
	{{{-11, -21, -28}, 0, {811, 498}, {0xEA, 0xAC, 0xA4, 0xFF}}},
	{{{-5, 6, 33}, 0, {1097, 354}, {0x08, 0x09, 0x7E, 0xFF}}},
	{{{-11, -21, 28}, 0, {811, 498}, {0xEA, 0xAC, 0x5C, 0xFF}}},
	{{{26, -12, 20}, 0, {1201, 536}, {0x46, 0xD0, 0x5E, 0xFF}}},
	{{{40, 1, -10}, 0, {790, 7}, {0x23, 0x2D, 0x8F, 0xFF}}},
	{{{55, 14, 0}, 0, {879, 248}, {0x58, 0x5B, 0x04, 0xFF}}},
	{{{38, -15, 1}, 0, {183, 3}, {0x59, 0xA5, 0x00, 0xFF}}},
	{{{40, 1, 10}, 0, {790, 7}, {0x5E, 0xCF, 0x46, 0xFF}}},
	{{{-1, -30, 0}, 0, {725, 874}, {0x0B, 0x81, 0x00, 0xFF}}},
	{{{-11, -21, 28}, 0, {975, 804}, {0xEA, 0xAC, 0x5C, 0xFF}}},
	{{{-31, -21, 0}, 0, {633, 588}, {0xA2, 0xAB, 0x00, 0xFF}}},
	{{{-11, -21, -28}, 0, {975, 804}, {0xEA, 0xAC, 0xA4, 0xFF}}},
};

Gfx yoshi_skl_root_mesh_layer_1_tri_0[] = {
	gsSPVertex(yoshi_skl_root_mesh_layer_1_vtx_0 + 0, 14, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(6, 7, 8, 0, 9, 8, 7, 0),
	gsSP2Triangles(10, 11, 12, 0, 12, 13, 10, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_skl_root_mesh_layer_1_vtx_1[9] = {
	{{{38, -15, 1}, 0, {207, 1017}, {0x59, 0xA5, 0x00, 0xFF}}},
	{{{40, 1, 10}, 0, {814, 1021}, {0x5E, 0xCF, 0x46, 0xFF}}},
	{{{26, -12, 20}, 0, {719, 762}, {0x46, 0xD0, 0x5E, 0xFF}}},
	{{{24, -12, -20}, 0, {719, 762}, {0x44, 0xCB, 0xA3, 0xFF}}},
	{{{40, 1, -10}, 0, {814, 1021}, {0x23, 0x2D, 0x8F, 0xFF}}},
	{{{-11, -21, -28}, 0, {719, 698}, {0xEA, 0xAC, 0xA4, 0xFF}}},
	{{{-1, -30, 0}, 0, {-49, 698}, {0x0B, 0x81, 0x00, 0xFF}}},
	{{{38, -15, 1}, 0, {207, 986}, {0x59, 0xA5, 0x00, 0xFF}}},
	{{{-11, -21, 28}, 0, {719, 698}, {0xEA, 0xAC, 0x5C, 0xFF}}},
};

Gfx yoshi_skl_root_mesh_layer_1_tri_1[] = {
	gsSPVertex(yoshi_skl_root_mesh_layer_1_vtx_1 + 0, 9, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 4, 0),
	gsSP2Triangles(5, 3, 6, 0, 7, 6, 3, 0),
	gsSP2Triangles(7, 2, 6, 0, 8, 6, 2, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_skl_root_mesh_layer_1_vtx_2[13] = {
	{{{-5, 6, 33}, 0, {713, 897}, {0x08, 0x09, 0x7E, 0xFF}}},
	{{{26, -12, 20}, 0, {713, 897}, {0x46, 0xD0, 0x5E, 0xFF}}},
	{{{12, 8, 26}, 0, {713, 897}, {0x3F, 0x1A, 0x6B, 0xFF}}},
	{{{-5, 6, -33}, 0, {713, 897}, {0x09, 0x08, 0x82, 0xFF}}},
	{{{12, 8, -26}, 0, {713, 897}, {0x40, 0x17, 0x95, 0xFF}}},
	{{{24, -12, -20}, 0, {713, 897}, {0x44, 0xCB, 0xA3, 0xFF}}},
	{{{55, 14, 0}, 0, {1271, 383}, {0x58, 0x5B, 0x04, 0xFF}}},
	{{{40, 1, -10}, 0, {1249, 461}, {0x23, 0x2D, 0x8F, 0xFF}}},
	{{{39, 6, 0}, 0, {1007, 387}, {0x0B, 0x7E, 0x00, 0xFF}}},
	{{{24, -12, -20}, 0, {1225, 545}, {0x44, 0xCB, 0xA3, 0xFF}}},
	{{{12, 8, -26}, 0, {617, 513}, {0x40, 0x17, 0x95, 0xFF}}},
	{{{26, -12, 20}, 0, {1225, 545}, {0x46, 0xD0, 0x5E, 0xFF}}},
	{{{12, 8, 26}, 0, {617, 513}, {0x3F, 0x1A, 0x6B, 0xFF}}},
};

Gfx yoshi_skl_root_mesh_layer_1_tri_2[] = {
	gsSPVertex(yoshi_skl_root_mesh_layer_1_vtx_2 + 0, 13, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(6, 7, 8, 0, 8, 7, 9, 0),
	gsSP2Triangles(10, 8, 9, 0, 6, 8, 11, 0),
	gsSP1Triangle(12, 11, 8, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_leg_l1_mesh_layer_1_vtx_0[8] = {
	{{{-15, -5, 9}, 0, {905, 961}, {0x8B, 0x0F, 0x30, 0xFF}}},
	{{{-12, 8, 3}, 0, {905, 961}, {0xA5, 0x43, 0xC6, 0xFF}}},
	{{{-16, -7, -8}, 0, {905, 961}, {0x9C, 0x1A, 0xB7, 0xFF}}},
	{{{0, 14, 0}, 0, {905, 961}, {0x02, 0x54, 0xA1, 0xFF}}},
	{{{0, 0, -12}, 0, {905, 961}, {0x15, 0x33, 0x8E, 0xFF}}},
	{{{11, 6, 3}, 0, {905, 961}, {0x6F, 0x2C, 0xD5, 0xFF}}},
	{{{14, -14, 0}, 0, {905, 961}, {0x7F, 0xF6, 0xFA, 0xFF}}},
	{{{0, -12, -13}, 0, {905, 961}, {0x1E, 0xFA, 0x85, 0xFF}}},
};

Gfx yoshi_leg_l1_mesh_layer_1_tri_0[] = {
	gsSPVertex(yoshi_leg_l1_mesh_layer_1_vtx_0 + 0, 8, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
	gsSP2Triangles(2, 3, 4, 0, 5, 4, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 6, 7, 4, 0),
	gsSP1Triangle(2, 4, 7, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_leg_l2_skinned_mesh_layer_1_vtx_0[5] = {
	{{{14, -14, 0}, 0, {905, 961}, {0x7F, 0xF6, 0xFA, 0xFF}}},
	{{{11, 6, 3}, 0, {905, 961}, {0x6F, 0x2C, 0xD5, 0xFF}}},
	{{{-15, -5, 9}, 0, {361, 673}, {0x8B, 0x0F, 0x30, 0xFF}}},
	{{{-16, -7, -8}, 0, {361, 673}, {0x9C, 0x1A, 0xB7, 0xFF}}},
	{{{0, -12, -13}, 0, {19, 695}, {0x1E, 0xFA, 0x85, 0xFF}}},
};

Gfx yoshi_leg_l2_skinned_mesh_layer_1_tri_0[] = {
	gsSPVertex(yoshi_leg_l2_skinned_mesh_layer_1_vtx_0 + 0, 5, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_leg_l2_skinned_mesh_layer_1_vtx_1[2] = {
	{{{14, -14, 0}, 0, {1779, 654}, {0x7F, 0xF6, 0xFA, 0xFF}}},
	{{{0, -12, -13}, 0, {2049, 698}, {0x1E, 0xFA, 0x85, 0xFF}}},
};

Gfx yoshi_leg_l2_skinned_mesh_layer_1_tri_1[] = {
	gsSPVertex(yoshi_leg_l2_skinned_mesh_layer_1_vtx_1 + 0, 2, 5),
	gsSPEndDisplayList(),
};

Vtx yoshi_leg_l2_mesh_layer_1_vtx_0[5] = {
	{{{0, 8, -14}, 0, {905, 961}, {0xD7, 0xEF, 0x89, 0xFF}}},
	{{{15, 0, -10}, 0, {361, 673}, {0x60, 0xE5, 0xB2, 0xFF}}},
	{{{0, 8, -14}, 0, {19, 693}, {0xD7, 0xEF, 0x89, 0xFF}}},
	{{{15, 0, 8}, 0, {361, 673}, {0x60, 0xE3, 0x4F, 0xFF}}},
	{{{2, -11, 8}, 0, {19, 1009}, {0xED, 0xCF, 0x74, 0xFF}}},
};

Gfx yoshi_leg_l2_mesh_layer_1_tri_0[] = {
	gsSPVertex(yoshi_leg_l2_mesh_layer_1_vtx_0 + 0, 5, 7),
	gsSP2Triangles(7, 0, 1, 0, 8, 9, 2, 0),
	gsSP2Triangles(2, 3, 8, 0, 10, 8, 3, 0),
	gsSP2Triangles(3, 4, 10, 0, 11, 10, 4, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_leg_l2_mesh_layer_1_vtx_1[3] = {
	{{{0, 8, -14}, 0, {2049, 696}, {0xD7, 0xEF, 0x89, 0xFF}}},
	{{{-14, 5, 0}, 0, {1801, 762}, {0x87, 0xDB, 0x04, 0xFF}}},
	{{{2, -11, 8}, 0, {2049, 1012}, {0xED, 0xCF, 0x74, 0xFF}}},
};

Gfx yoshi_leg_l2_mesh_layer_1_tri_1[] = {
	gsSPVertex(yoshi_leg_l2_mesh_layer_1_vtx_1 + 0, 3, 7),
	gsSP2Triangles(7, 8, 5, 0, 6, 5, 8, 0),
	gsSP1Triangle(6, 8, 9, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_leg_l2_mesh_layer_1_vtx_2[5] = {
	{{{1, -11, -10}, 0, {2049, 1012}, {0xE8, 0xD0, 0x8D, 0xFF}}},
	{{{-8, -11, -1}, 0, {1911, 1012}, {0x89, 0xD4, 0xFD, 0xFF}}},
	{{{0, 8, -14}, 0, {2049, 696}, {0xD7, 0xEF, 0x89, 0xFF}}},
	{{{-14, 5, 0}, 0, {1801, 762}, {0x87, 0xDB, 0x04, 0xFF}}},
	{{{2, -11, 8}, 0, {2049, 1012}, {0xED, 0xCF, 0x74, 0xFF}}},
};

Gfx yoshi_leg_l2_mesh_layer_1_tri_2[] = {
	gsSPVertex(yoshi_leg_l2_mesh_layer_1_vtx_2 + 0, 5, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
	gsSP1Triangle(1, 4, 3, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_leg_l2_mesh_layer_1_vtx_3[6] = {
	{{{0, 8, -14}, 0, {19, 693}, {0xD7, 0xEF, 0x89, 0xFF}}},
	{{{15, 0, -10}, 0, {361, 673}, {0x60, 0xE5, 0xB2, 0xFF}}},
	{{{1, -11, -10}, 0, {19, 1009}, {0xE8, 0xD0, 0x8D, 0xFF}}},
	{{{14, -11, -1}, 0, {307, 1009}, {0x69, 0xB9, 0x02, 0xFF}}},
	{{{15, 0, 8}, 0, {361, 673}, {0x60, 0xE3, 0x4F, 0xFF}}},
	{{{2, -11, 8}, 0, {19, 1009}, {0xED, 0xCF, 0x74, 0xFF}}},
};

Gfx yoshi_leg_l2_mesh_layer_1_tri_3[] = {
	gsSPVertex(yoshi_leg_l2_mesh_layer_1_vtx_3 + 0, 6, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
	gsSP2Triangles(1, 4, 3, 0, 5, 3, 4, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_ankle_l1_mesh_layer_1_vtx_0[27] = {
	{{{26, -14, 17}, 0, {1449, 737}, {0x29, 0xB5, 0x5D, 0xFF}}},
	{{{26, -14, -16}, 0, {1449, 993}, {0x2A, 0xB5, 0xA2, 0xFF}}},
	{{{38, -14, 0}, 0, {1355, 859}, {0x6A, 0xBA, 0x00, 0xFF}}},
	{{{-19, -14, -14}, 0, {1865, 993}, {0xAF, 0xC8, 0xB0, 0xFF}}},
	{{{-19, -14, 14}, 0, {1865, 737}, {0xAE, 0xC8, 0x4F, 0xFF}}},
	{{{-17, 6, 0}, 0, {1885, 477}, {0x92, 0xC1, 0x00, 0xFF}}},
	{{{-22, 13, 0}, 0, {1905, 381}, {0x8D, 0x35, 0x00, 0xFF}}},
	{{{-7, 13, -17}, 0, {1609, 381}, {0xF6, 0x31, 0x8B, 0xFF}}},
	{{{-7, 6, 15}, 0, {1617, 477}, {0xF1, 0xC3, 0x6E, 0xFF}}},
	{{{-7, 13, 18}, 0, {1609, 381}, {0xF6, 0x31, 0x75, 0xFF}}},
	{{{12, 6, 0}, 0, {1419, 477}, {0x6F, 0xC2, 0x00, 0xFF}}},
	{{{15, 13, 0}, 0, {1369, 381}, {0x76, 0x2E, 0x00, 0xFF}}},
	{{{-7, 6, -14}, 0, {1617, 477}, {0xF1, 0xC3, 0x92, 0xFF}}},
	{{{-17, 6, 0}, 0, {1831, 511}, {0x87, 0x26, 0x00, 0xFF}}},
	{{{-7, 6, -14}, 0, {1671, 507}, {0xED, 0xF4, 0x83, 0xFF}}},
	{{{-7, -4, -13}, 0, {1645, 559}, {0xEA, 0x22, 0x88, 0xFF}}},
	{{{12, 6, 0}, 0, {1539, 505}, {0x0C, 0x7E, 0x00, 0xFF}}},
	{{{35, 7, 0}, 0, {1389, 531}, {0x50, 0x63, 0x00, 0xFF}}},
	{{{-7, -4, 14}, 0, {1645, 559}, {0xEA, 0x21, 0x79, 0xFF}}},
	{{{-7, 6, 15}, 0, {1671, 507}, {0xED, 0xF4, 0x7D, 0xFF}}},
	{{{-19, -14, 14}, 0, {1871, 665}, {0xAE, 0xC8, 0x4F, 0xFF}}},
	{{{-19, -14, -14}, 0, {1871, 665}, {0xAF, 0xC8, 0xB0, 0xFF}}},
	{{{26, -14, -16}, 0, {1437, 665}, {0x2A, 0xB5, 0xA2, 0xFF}}},
	{{{27, 0, -15}, 0, {1431, 569}, {0x2A, 0x40, 0x9B, 0xFF}}},
	{{{38, -14, 0}, 0, {1377, 665}, {0x6A, 0xBA, 0x00, 0xFF}}},
	{{{27, 0, 16}, 0, {1431, 569}, {0x2A, 0x40, 0x65, 0xFF}}},
	{{{26, -14, 17}, 0, {1437, 665}, {0x29, 0xB5, 0x5D, 0xFF}}},
};

Gfx yoshi_ankle_l1_mesh_layer_1_tri_0[] = {
	gsSPVertex(yoshi_ankle_l1_mesh_layer_1_vtx_0 + 0, 27, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(0, 4, 3, 0, 5, 6, 7, 0),
	gsSP2Triangles(8, 6, 5, 0, 8, 9, 6, 0),
	gsSP2Triangles(10, 9, 8, 0, 10, 11, 9, 0),
	gsSP2Triangles(12, 11, 10, 0, 12, 7, 11, 0),
	gsSP2Triangles(5, 7, 12, 0, 13, 14, 15, 0),
	gsSP2Triangles(16, 15, 14, 0, 15, 16, 17, 0),
	gsSP2Triangles(16, 18, 17, 0, 18, 16, 19, 0),
	gsSP2Triangles(19, 13, 18, 0, 20, 18, 13, 0),
	gsSP2Triangles(20, 13, 21, 0, 15, 21, 13, 0),
	gsSP2Triangles(15, 22, 21, 0, 15, 23, 22, 0),
	gsSP2Triangles(15, 17, 23, 0, 24, 23, 17, 0),
	gsSP2Triangles(17, 25, 24, 0, 25, 17, 18, 0),
	gsSP2Triangles(26, 25, 18, 0, 26, 18, 20, 0),
	gsSP2Triangles(26, 24, 25, 0, 23, 24, 22, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_ankle_l1_mesh_layer_1_vtx_1[4] = {
	{{{-22, 13, 0}, 0, {959, 414}, {0x8D, 0x35, 0x00, 0xFF}}},
	{{{-7, 13, 18}, 0, {737, 530}, {0xF6, 0x31, 0x75, 0xFF}}},
	{{{-7, 13, -17}, 0, {1169, 530}, {0xF6, 0x31, 0x8B, 0xFF}}},
	{{{15, 13, 0}, 0, {953, 594}, {0x76, 0x2E, 0x00, 0xFF}}},
};

Gfx yoshi_ankle_l1_mesh_layer_1_tri_1[] = {
	gsSPVertex(yoshi_ankle_l1_mesh_layer_1_vtx_1 + 0, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_leg_r1_mesh_layer_1_vtx_0[8] = {
	{{{-15, -5, -9}, 0, {905, 961}, {0x8B, 0x0F, 0xD0, 0xFF}}},
	{{{-16, -7, 8}, 0, {905, 961}, {0x9C, 0x1A, 0x49, 0xFF}}},
	{{{-12, 8, -3}, 0, {905, 961}, {0xA5, 0x43, 0x3A, 0xFF}}},
	{{{0, 14, 0}, 0, {905, 961}, {0x02, 0x54, 0x5F, 0xFF}}},
	{{{0, 0, 12}, 0, {905, 961}, {0x15, 0x33, 0x72, 0xFF}}},
	{{{0, -12, 13}, 0, {905, 961}, {0x1E, 0xFA, 0x7B, 0xFF}}},
	{{{14, -14, 0}, 0, {905, 961}, {0x7F, 0xF6, 0x06, 0xFF}}},
	{{{11, 6, -3}, 0, {905, 961}, {0x6F, 0x2C, 0x2B, 0xFF}}},
};

Gfx yoshi_leg_r1_mesh_layer_1_tri_0[] = {
	gsSPVertex(yoshi_leg_r1_mesh_layer_1_vtx_0 + 0, 8, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
	gsSP2Triangles(1, 4, 3, 0, 1, 5, 4, 0),
	gsSP2Triangles(6, 4, 5, 0, 4, 6, 7, 0),
	gsSP1Triangle(7, 3, 4, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_leg_r2_skinned_mesh_layer_1_vtx_0[5] = {
	{{{-15, -5, -9}, 0, {361, 673}, {0x8B, 0x0F, 0xD0, 0xFF}}},
	{{{-16, -7, 8}, 0, {361, 673}, {0x9C, 0x1A, 0x49, 0xFF}}},
	{{{0, -12, 13}, 0, {19, 695}, {0x1E, 0xFA, 0x7B, 0xFF}}},
	{{{11, 6, -3}, 0, {905, 961}, {0x6F, 0x2C, 0x2B, 0xFF}}},
	{{{14, -14, 0}, 0, {905, 961}, {0x7F, 0xF6, 0x06, 0xFF}}},
};

Gfx yoshi_leg_r2_skinned_mesh_layer_1_tri_0[] = {
	gsSPVertex(yoshi_leg_r2_skinned_mesh_layer_1_vtx_0 + 0, 5, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_leg_r2_skinned_mesh_layer_1_vtx_1[2] = {
	{{{0, -12, 13}, 0, {2049, 698}, {0x1E, 0xFA, 0x7B, 0xFF}}},
	{{{14, -14, 0}, 0, {1779, 654}, {0x7F, 0xF6, 0x06, 0xFF}}},
};

Gfx yoshi_leg_r2_skinned_mesh_layer_1_tri_1[] = {
	gsSPVertex(yoshi_leg_r2_skinned_mesh_layer_1_vtx_1 + 0, 2, 5),
	gsSPEndDisplayList(),
};

Vtx yoshi_leg_r2_mesh_layer_1_vtx_0[5] = {
	{{{0, 8, 14}, 0, {905, 961}, {0xD7, 0xEF, 0x77, 0xFF}}},
	{{{15, 0, 10}, 0, {361, 673}, {0x60, 0xE5, 0x4E, 0xFF}}},
	{{{0, 8, 14}, 0, {19, 693}, {0xD7, 0xEF, 0x77, 0xFF}}},
	{{{15, 0, -8}, 0, {361, 673}, {0x60, 0xE3, 0xB1, 0xFF}}},
	{{{2, -11, -8}, 0, {19, 1009}, {0xED, 0xCF, 0x8C, 0xFF}}},
};

Gfx yoshi_leg_r2_mesh_layer_1_tri_0[] = {
	gsSPVertex(yoshi_leg_r2_mesh_layer_1_vtx_0 + 0, 5, 7),
	gsSP2Triangles(7, 3, 4, 0, 0, 8, 1, 0),
	gsSP2Triangles(9, 8, 0, 0, 10, 1, 8, 0),
	gsSP2Triangles(1, 10, 2, 0, 11, 2, 10, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_leg_r2_mesh_layer_1_vtx_1[3] = {
	{{{2, -11, -8}, 0, {2049, 1012}, {0xED, 0xCF, 0x8C, 0xFF}}},
	{{{-14, 5, 0}, 0, {1801, 762}, {0x87, 0xDB, 0xFC, 0xFF}}},
	{{{0, 8, 14}, 0, {2049, 696}, {0xD7, 0xEF, 0x77, 0xFF}}},
};

Gfx yoshi_leg_r2_mesh_layer_1_tri_1[] = {
	gsSPVertex(yoshi_leg_r2_mesh_layer_1_vtx_1 + 0, 3, 7),
	gsSP2Triangles(5, 7, 8, 0, 5, 8, 6, 0),
	gsSP1Triangle(9, 6, 8, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_leg_r2_mesh_layer_1_vtx_2[6] = {
	{{{0, 8, 14}, 0, {19, 693}, {0xD7, 0xEF, 0x77, 0xFF}}},
	{{{1, -11, 10}, 0, {19, 1009}, {0xE8, 0xD0, 0x73, 0xFF}}},
	{{{15, 0, 10}, 0, {361, 673}, {0x60, 0xE5, 0x4E, 0xFF}}},
	{{{14, -11, 1}, 0, {307, 1009}, {0x69, 0xB9, 0xFE, 0xFF}}},
	{{{15, 0, -8}, 0, {361, 673}, {0x60, 0xE3, 0xB1, 0xFF}}},
	{{{2, -11, -8}, 0, {19, 1009}, {0xED, 0xCF, 0x8C, 0xFF}}},
};

Gfx yoshi_leg_r2_mesh_layer_1_tri_2[] = {
	gsSPVertex(yoshi_leg_r2_mesh_layer_1_vtx_2 + 0, 6, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
	gsSP2Triangles(2, 3, 4, 0, 5, 4, 3, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_leg_r2_mesh_layer_1_vtx_3[5] = {
	{{{-8, -11, 1}, 0, {1911, 1012}, {0x89, 0xD4, 0x03, 0xFF}}},
	{{{-14, 5, 0}, 0, {1801, 762}, {0x87, 0xDB, 0xFC, 0xFF}}},
	{{{2, -11, -8}, 0, {2049, 1012}, {0xED, 0xCF, 0x8C, 0xFF}}},
	{{{0, 8, 14}, 0, {2049, 696}, {0xD7, 0xEF, 0x77, 0xFF}}},
	{{{1, -11, 10}, 0, {2049, 1012}, {0xE8, 0xD0, 0x73, 0xFF}}},
};

Gfx yoshi_leg_r2_mesh_layer_1_tri_3[] = {
	gsSPVertex(yoshi_leg_r2_mesh_layer_1_vtx_3 + 0, 5, 0),
	gsSP2Triangles(0, 1, 2, 0, 1, 0, 3, 0),
	gsSP1Triangle(4, 3, 0, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_ankle_r1_mesh_layer_1_vtx_0[27] = {
	{{{26, -14, -17}, 0, {1449, 993}, {0x29, 0xB5, 0xA3, 0xFF}}},
	{{{-19, -14, 14}, 0, {1865, 737}, {0xAF, 0xC8, 0x50, 0xFF}}},
	{{{-19, -14, -14}, 0, {1865, 993}, {0xAE, 0xC8, 0xB1, 0xFF}}},
	{{{26, -14, 16}, 0, {1449, 737}, {0x2A, 0xB5, 0x5E, 0xFF}}},
	{{{38, -14, 0}, 0, {1355, 857}, {0x6A, 0xBA, 0x00, 0xFF}}},
	{{{-7, 6, -15}, 0, {1617, 477}, {0xF1, 0xC3, 0x92, 0xFF}}},
	{{{-7, 13, -18}, 0, {1609, 381}, {0xF6, 0x31, 0x8B, 0xFF}}},
	{{{15, 13, 0}, 0, {1369, 381}, {0x76, 0x2E, 0x00, 0xFF}}},
	{{{-17, 6, 0}, 0, {1885, 477}, {0x92, 0xC1, 0x00, 0xFF}}},
	{{{-22, 13, 0}, 0, {1905, 381}, {0x8D, 0x35, 0x00, 0xFF}}},
	{{{-7, 6, 14}, 0, {1617, 477}, {0xF1, 0xC3, 0x6E, 0xFF}}},
	{{{-7, 13, 17}, 0, {1609, 381}, {0xF6, 0x31, 0x75, 0xFF}}},
	{{{12, 6, 0}, 0, {1419, 477}, {0x6F, 0xC2, 0x00, 0xFF}}},
	{{{12, 6, 0}, 0, {1539, 505}, {0x0C, 0x7E, 0x00, 0xFF}}},
	{{{-7, -4, -14}, 0, {1645, 559}, {0xEA, 0x21, 0x87, 0xFF}}},
	{{{-7, 6, -15}, 0, {1671, 507}, {0xED, 0xF4, 0x83, 0xFF}}},
	{{{35, 7, 0}, 0, {1389, 531}, {0x50, 0x63, 0x00, 0xFF}}},
	{{{-7, -4, 13}, 0, {1645, 559}, {0xEA, 0x22, 0x78, 0xFF}}},
	{{{-7, 6, 14}, 0, {1671, 507}, {0xED, 0xF4, 0x7D, 0xFF}}},
	{{{-17, 6, 0}, 0, {1831, 511}, {0x87, 0x26, 0x00, 0xFF}}},
	{{{-19, -14, 14}, 0, {1871, 669}, {0xAF, 0xC8, 0x50, 0xFF}}},
	{{{-19, -14, -14}, 0, {1871, 669}, {0xAE, 0xC8, 0xB1, 0xFF}}},
	{{{26, -14, -17}, 0, {1437, 669}, {0x29, 0xB5, 0xA3, 0xFF}}},
	{{{27, 0, -16}, 0, {1431, 569}, {0x2A, 0x40, 0x9B, 0xFF}}},
	{{{38, -14, 0}, 0, {1377, 669}, {0x6A, 0xBA, 0x00, 0xFF}}},
	{{{27, 0, 15}, 0, {1431, 569}, {0x2A, 0x40, 0x65, 0xFF}}},
	{{{26, -14, 16}, 0, {1437, 669}, {0x2A, 0xB5, 0x5E, 0xFF}}},
};

Gfx yoshi_ankle_r1_mesh_layer_1_tri_0[] = {
	gsSPVertex(yoshi_ankle_r1_mesh_layer_1_vtx_0 + 0, 27, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(0, 4, 3, 0, 5, 6, 7, 0),
	gsSP2Triangles(8, 6, 5, 0, 8, 9, 6, 0),
	gsSP2Triangles(10, 9, 8, 0, 10, 11, 9, 0),
	gsSP2Triangles(12, 11, 10, 0, 12, 7, 11, 0),
	gsSP2Triangles(5, 7, 12, 0, 13, 14, 15, 0),
	gsSP2Triangles(13, 16, 14, 0, 16, 13, 17, 0),
	gsSP2Triangles(18, 17, 13, 0, 17, 18, 19, 0),
	gsSP2Triangles(17, 19, 20, 0, 21, 20, 19, 0),
	gsSP2Triangles(19, 14, 21, 0, 19, 15, 14, 0),
	gsSP2Triangles(22, 21, 14, 0, 22, 14, 23, 0),
	gsSP2Triangles(23, 14, 16, 0, 16, 24, 23, 0),
	gsSP2Triangles(24, 16, 25, 0, 17, 25, 16, 0),
	gsSP2Triangles(17, 26, 25, 0, 17, 20, 26, 0),
	gsSP2Triangles(25, 26, 24, 0, 22, 23, 24, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_ankle_r1_mesh_layer_1_vtx_1[4] = {
	{{{-22, 13, 0}, 0, {959, 414}, {0x8D, 0x35, 0x00, 0xFF}}},
	{{{-7, 13, 17}, 0, {1169, 530}, {0xF6, 0x31, 0x75, 0xFF}}},
	{{{-7, 13, -18}, 0, {737, 530}, {0xF6, 0x31, 0x8B, 0xFF}}},
	{{{15, 13, 0}, 0, {953, 594}, {0x76, 0x2E, 0x00, 0xFF}}},
};

Gfx yoshi_ankle_r1_mesh_layer_1_tri_1[] = {
	gsSPVertex(yoshi_ankle_r1_mesh_layer_1_vtx_1 + 0, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_spin_skinned_mesh_layer_1_vtx_0[8] = {
	{{{-5, 6, -33}, 0, {1491, 500}, {0x09, 0x08, 0x82, 0xFF}}},
	{{{-39, 6, 0}, 0, {505, 276}, {0x81, 0xF6, 0x00, 0xFF}}},
	{{{-11, -21, -28}, 0, {929, 816}, {0xEA, 0xAC, 0xA4, 0xFF}}},
	{{{-31, -21, 0}, 0, {633, 588}, {0xA2, 0xAB, 0x00, 0xFF}}},
	{{{-11, -21, -28}, 0, {975, 804}, {0xEA, 0xAC, 0xA4, 0xFF}}},
	{{{-11, -21, 28}, 0, {975, 804}, {0xEA, 0xAC, 0x5C, 0xFF}}},
	{{{-5, 6, 33}, 0, {1491, 500}, {0x08, 0x09, 0x7E, 0xFF}}},
	{{{-11, -21, 28}, 0, {929, 816}, {0xEA, 0xAC, 0x5C, 0xFF}}},
};

Gfx yoshi_spin_skinned_mesh_layer_1_tri_0[] = {
	gsSPVertex(yoshi_spin_skinned_mesh_layer_1_vtx_0 + 0, 8, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_spin_skinned_mesh_layer_1_vtx_1[5] = {
	{{{-5, 6, -33}, 0, {617, 513}, {0x09, 0x08, 0x82, 0xFF}}},
	{{{12, 8, -26}, 0, {617, 513}, {0x40, 0x17, 0x95, 0xFF}}},
	{{{12, 8, 26}, 0, {617, 513}, {0x3F, 0x1A, 0x6B, 0xFF}}},
	{{{39, 6, 0}, 0, {1007, 387}, {0x0B, 0x7E, 0x00, 0xFF}}},
	{{{-5, 6, 33}, 0, {617, 513}, {0x08, 0x09, 0x7E, 0xFF}}},
};

Gfx yoshi_spin_skinned_mesh_layer_1_tri_1[] = {
	gsSPVertex(yoshi_spin_skinned_mesh_layer_1_vtx_1 + 0, 5, 8),
	gsSPEndDisplayList(),
};

Vtx yoshi_spin_skinned_mesh_layer_1_vtx_2[1] = {
	{{{39, 6, 0}, 0, {271, 122}, {0x0B, 0x7E, 0x00, 0xFF}}},
};

Gfx yoshi_spin_skinned_mesh_layer_1_tri_2[] = {
	gsSPVertex(yoshi_spin_skinned_mesh_layer_1_vtx_2 + 0, 1, 13),
	gsSPEndDisplayList(),
};

Vtx yoshi_spin_mesh_layer_1_vtx_0[8] = {
	{{{-37, 16, 0}, 0, {532, 241}, {0x8B, 0x31, 0x00, 0xFF}}},
	{{{-28, -4, -27}, 0, {563, 428}, {0xAC, 0xF9, 0xA1, 0xFF}}},
	{{{-28, -4, 27}, 0, {563, 428}, {0xAC, 0xF9, 0x5F, 0xFF}}},
	{{{-37, 16, 0}, 0, {487, 24}, {0x8B, 0x31, 0x00, 0xFF}}},
	{{{-27, 15, -23}, 0, {473, 94}, {0xB4, 0x32, 0xA8, 0xFF}}},
	{{{-6, 19, -26}, 0, {1239, 13}, {0x01, 0xFB, 0x81, 0xFF}}},
	{{{-27, 15, 23}, 0, {473, 94}, {0xB4, 0x32, 0x58, 0xFF}}},
	{{{-6, 19, 26}, 0, {1239, 13}, {0x01, 0xFB, 0x7F, 0xFF}}},
};

Gfx yoshi_spin_mesh_layer_1_tri_0[] = {
	gsSPVertex(yoshi_spin_mesh_layer_1_vtx_0 + 0, 8, 14),
	gsSP2Triangles(1, 14, 15, 0, 1, 15, 3, 0),
	gsSP2Triangles(4, 3, 15, 0, 3, 16, 1, 0),
	gsSP2Triangles(16, 3, 5, 0, 17, 1, 16, 0),
	gsSP2Triangles(2, 15, 0, 0, 18, 0, 15, 0),
	gsSP2Triangles(0, 18, 19, 0, 7, 6, 16, 0),
	gsSP2Triangles(6, 20, 16, 0, 20, 6, 21, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_spin_mesh_layer_1_vtx_1[5] = {
	{{{-6, 19, 26}, 0, {617, 513}, {0x01, 0xFB, 0x7F, 0xFF}}},
	{{{-6, 19, -26}, 0, {617, 513}, {0x01, 0xFB, 0x81, 0xFF}}},
	{{{3, 33, -18}, 0, {617, 513}, {0x60, 0x48, 0xD6, 0xFF}}},
	{{{-6, 19, 26}, 0, {605, 319}, {0x01, 0xFB, 0x7F, 0xFF}}},
	{{{3, 33, 18}, 0, {617, 513}, {0x60, 0x48, 0x2A, 0xFF}}},
};

Gfx yoshi_spin_mesh_layer_1_tri_1[] = {
	gsSPVertex(yoshi_spin_mesh_layer_1_vtx_1 + 0, 5, 14),
	gsSP2Triangles(14, 12, 10, 0, 8, 15, 9, 0),
	gsSP2Triangles(16, 9, 15, 0, 9, 16, 11, 0),
	gsSP2Triangles(17, 10, 18, 0, 11, 18, 10, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_spin_mesh_layer_1_vtx_2[3] = {
	{{{3, 33, 18}, 0, {271, 122}, {0x60, 0x48, 0x2A, 0xFF}}},
	{{{3, 40, 0}, 0, {663, 122}, {0x3E, 0x6F, 0x00, 0xFF}}},
	{{{3, 33, -18}, 0, {271, 122}, {0x60, 0x48, 0xD6, 0xFF}}},
};

Gfx yoshi_spin_mesh_layer_1_tri_2[] = {
	gsSPVertex(yoshi_spin_mesh_layer_1_vtx_2 + 0, 3, 14),
	gsSP2Triangles(14, 13, 15, 0, 16, 15, 13, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_spin_mesh_layer_1_vtx_3[17] = {
	{{{3, 33, 18}, 0, {271, 122}, {0x60, 0x48, 0x2A, 0xFF}}},
	{{{3, 40, 0}, 0, {663, 122}, {0x3E, 0x6F, 0x00, 0xFF}}},
	{{{-6, 38, 18}, 0, {335, 346}, {0xFF, 0x7D, 0x18, 0xFF}}},
	{{{-14, 42, 0}, 0, {663, 416}, {0xD0, 0x76, 0x00, 0xFF}}},
	{{{-6, 38, -18}, 0, {335, 346}, {0xFF, 0x7D, 0xE8, 0xFF}}},
	{{{3, 33, -18}, 0, {271, 122}, {0x60, 0x48, 0xD6, 0xFF}}},
	{{{-15, 33, -14}, 0, {399, 570}, {0xAA, 0x4D, 0xCB, 0xFF}}},
	{{{-23, 34, 0}, 0, {663, 570}, {0xA2, 0x55, 0x00, 0xFF}}},
	{{{-15, 33, 14}, 0, {399, 570}, {0xAA, 0x4D, 0x35, 0xFF}}},
	{{{-15, 33, -14}, 0, {687, 890}, {0xAA, 0x4D, 0xCB, 0xFF}}},
	{{{-6, 19, -26}, 0, {1263, 1026}, {0x01, 0xFB, 0x81, 0xFF}}},
	{{{-23, 21, -20}, 0, {563, 1033}, {0xC2, 0x4E, 0xB1, 0xFF}}},
	{{{-37, 16, 0}, 0, {205, 1033}, {0x8B, 0x31, 0x00, 0xFF}}},
	{{{-23, 34, 0}, 0, {207, 986}, {0xA2, 0x55, 0x00, 0xFF}}},
	{{{-15, 33, 14}, 0, {687, 890}, {0xAA, 0x4D, 0x35, 0xFF}}},
	{{{-23, 21, 20}, 0, {563, 1033}, {0xC2, 0x4E, 0x4F, 0xFF}}},
	{{{-6, 19, 26}, 0, {1263, 1026}, {0x01, 0xFB, 0x7F, 0xFF}}},
};

Gfx yoshi_spin_mesh_layer_1_tri_3[] = {
	gsSPVertex(yoshi_spin_mesh_layer_1_vtx_3 + 0, 17, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
	gsSP2Triangles(3, 1, 4, 0, 5, 4, 1, 0),
	gsSP2Triangles(4, 6, 3, 0, 7, 3, 6, 0),
	gsSP2Triangles(7, 8, 3, 0, 2, 3, 8, 0),
	gsSP2Triangles(9, 10, 11, 0, 11, 12, 9, 0),
	gsSP2Triangles(13, 9, 12, 0, 13, 12, 14, 0),
	gsSP2Triangles(15, 14, 12, 0, 14, 15, 16, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_spin_mesh_layer_1_vtx_4[12] = {
	{{{-27, 15, -23}, 0, {412, 306}, {0xB4, 0x32, 0xA8, 0xFF}}},
	{{{-28, -4, -27}, 0, {563, 428}, {0xAC, 0xF9, 0xA1, 0xFF}}},
	{{{-37, 16, 0}, 0, {426, 236}, {0x8B, 0x31, 0x00, 0xFF}}},
	{{{-37, 16, 0}, 0, {487, 24}, {0x8B, 0x31, 0x00, 0xFF}}},
	{{{-28, -4, 27}, 0, {563, 428}, {0xAC, 0xF9, 0x5F, 0xFF}}},
	{{{-27, 15, 23}, 0, {473, 94}, {0xB4, 0x32, 0x58, 0xFF}}},
	{{{-27, 15, -23}, 0, {473, 94}, {0xB4, 0x32, 0xA8, 0xFF}}},
	{{{-37, 16, 0}, 0, {181, 19}, {0x8B, 0x31, 0x00, 0xFF}}},
	{{{-23, 21, -20}, 0, {539, 19}, {0xC2, 0x4E, 0xB1, 0xFF}}},
	{{{-6, 19, -26}, 0, {1239, 13}, {0x01, 0xFB, 0x81, 0xFF}}},
	{{{-23, 21, 20}, 0, {539, 19}, {0xC2, 0x4E, 0x4F, 0xFF}}},
	{{{-6, 19, 26}, 0, {1239, 13}, {0x01, 0xFB, 0x7F, 0xFF}}},
};

Gfx yoshi_spin_mesh_layer_1_tri_4[] = {
	gsSPVertex(yoshi_spin_mesh_layer_1_vtx_4 + 0, 12, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(6, 7, 8, 0, 8, 9, 6, 0),
	gsSP2Triangles(5, 10, 7, 0, 10, 5, 11, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_spin_mesh_layer_1_vtx_5[24] = {
	{{{15, 17, -21}, 0, {1183, 792}, {0xE6, 0x01, 0x84, 0xFF}}},
	{{{28, 3, -15}, 0, {1183, 896}, {0x26, 0xB5, 0xA1, 0xFF}}},
	{{{-4, 1, 0}, 0, {977, 810}, {0xE1, 0x85, 0x00, 0xFF}}},
	{{{38, -1, 0}, 0, {977, 952}, {0x56, 0xA3, 0x00, 0xFF}}},
	{{{28, 3, 15}, 0, {771, 898}, {0x26, 0xB5, 0x5F, 0xFF}}},
	{{{15, 17, 21}, 0, {771, 794}, {0xE6, 0x01, 0x7C, 0xFF}}},
	{{{-4, 1, 0}, 0, {977, 810}, {0x85, 0x1F, 0x00, 0xFF}}},
	{{{10, 31, -13}, 0, {1183, 688}, {0xC9, 0x50, 0xAE, 0xFF}}},
	{{{9, 36, 0}, 0, {977, 644}, {0xC0, 0x6E, 0x00, 0xFF}}},
	{{{10, 31, 13}, 0, {771, 690}, {0xC9, 0x50, 0x51, 0xFF}}},
	{{{28, 3, 15}, 0, {1973, 228}, {0x26, 0xB5, 0x5F, 0xFF}}},
	{{{38, -1, 0}, 0, {2037, 196}, {0x56, 0xA3, 0x00, 0xFF}}},
	{{{42, 14, 0}, 0, {1301, 196}, {0x7F, 0xFE, 0x00, 0xFF}}},
	{{{28, 3, -15}, 0, {1973, 228}, {0x26, 0xB5, 0xA1, 0xFF}}},
	{{{33, 26, -11}, 0, {1301, 196}, {0x4A, 0x39, 0xAB, 0xFF}}},
	{{{15, 17, -21}, 0, {1973, 196}, {0xE6, 0x01, 0x84, 0xFF}}},
	{{{10, 31, -13}, 0, {1973, 144}, {0xC9, 0x50, 0xAE, 0xFF}}},
	{{{26, 36, 0}, 0, {1301, 196}, {0x29, 0x78, 0x01, 0xFF}}},
	{{{9, 36, 0}, 0, {2037, 196}, {0xC0, 0x6E, 0x00, 0xFF}}},
	{{{10, 31, 13}, 0, {1973, 144}, {0xC9, 0x50, 0x51, 0xFF}}},
	{{{33, 26, 11}, 0, {1301, 196}, {0x4B, 0x39, 0x55, 0xFF}}},
	{{{15, 17, 21}, 0, {1973, 196}, {0xE6, 0x01, 0x7C, 0xFF}}},
	{{{38, 27, 0}, 0, {1301, 196}, {0x79, 0x27, 0x00, 0xFF}}},
	{{{38, 27, 0}, 0, {1301, 196}, {0x4E, 0x64, 0x00, 0xFF}}},
};

Gfx yoshi_spin_mesh_layer_1_tri_5[] = {
	gsSPVertex(yoshi_spin_mesh_layer_1_vtx_5 + 0, 24, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
	gsSP2Triangles(3, 4, 2, 0, 5, 2, 4, 0),
	gsSP2Triangles(0, 6, 7, 0, 8, 7, 6, 0),
	gsSP2Triangles(8, 6, 9, 0, 5, 9, 6, 0),
	gsSP2Triangles(10, 11, 12, 0, 13, 12, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 15, 14, 13, 0),
	gsSP2Triangles(14, 15, 16, 0, 17, 14, 16, 0),
	gsSP2Triangles(16, 18, 17, 0, 19, 17, 18, 0),
	gsSP2Triangles(17, 19, 20, 0, 21, 20, 19, 0),
	gsSP2Triangles(21, 10, 20, 0, 12, 20, 10, 0),
	gsSP2Triangles(20, 12, 22, 0, 14, 22, 12, 0),
	gsSP2Triangles(20, 23, 17, 0, 14, 17, 23, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_arm_l1_skinned_mesh_layer_1_vtx_0[4] = {
	{{{-6, 19, 26}, 0, {617, 513}, {0x01, 0xFB, 0x7F, 0xFF}}},
	{{{-15, 33, 14}, 0, {617, 513}, {0xAA, 0x4D, 0x35, 0xFF}}},
	{{{-6, 38, 18}, 0, {617, 513}, {0xFF, 0x7D, 0x18, 0xFF}}},
	{{{3, 33, 18}, 0, {617, 513}, {0x60, 0x48, 0x2A, 0xFF}}},
};

Gfx yoshi_arm_l1_skinned_mesh_layer_1_tri_0[] = {
	gsSPVertex(yoshi_arm_l1_skinned_mesh_layer_1_vtx_0 + 0, 4, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_arm_l1_mesh_layer_1_vtx_0[4] = {
	{{{20, -7, 0}, 0, {617, 513}, {0x08, 0x82, 0x0C, 0xFF}}},
	{{{20, 2, -10}, 0, {617, 513}, {0x09, 0x0F, 0x82, 0xFF}}},
	{{{19, 8, 0}, 0, {617, 513}, {0x04, 0x7F, 0xF9, 0xFF}}},
	{{{19, 2, 9}, 0, {617, 513}, {0x03, 0x12, 0x7E, 0xFF}}},
};

Gfx yoshi_arm_l1_mesh_layer_1_tri_0[] = {
	gsSPVertex(yoshi_arm_l1_mesh_layer_1_vtx_0 + 0, 4, 4),
	gsSP2Triangles(0, 4, 1, 0, 4, 0, 5, 0),
	gsSP2Triangles(3, 5, 0, 0, 5, 3, 6, 0),
	gsSP2Triangles(2, 6, 3, 0, 6, 2, 7, 0),
	gsSP2Triangles(1, 7, 2, 0, 7, 1, 4, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_arm_l2_skinned_mesh_layer_1_vtx_0[4] = {
	{{{19, 8, 0}, 0, {617, 513}, {0x04, 0x7F, 0xF9, 0xFF}}},
	{{{20, -7, 0}, 0, {617, 513}, {0x08, 0x82, 0x0C, 0xFF}}},
	{{{20, 2, -10}, 0, {617, 513}, {0x09, 0x0F, 0x82, 0xFF}}},
	{{{19, 2, 9}, 0, {617, 513}, {0x03, 0x12, 0x7E, 0xFF}}},
};

Gfx yoshi_arm_l2_skinned_mesh_layer_1_tri_0[] = {
	gsSPVertex(yoshi_arm_l2_skinned_mesh_layer_1_vtx_0 + 0, 4, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_arm_l2_mesh_layer_1_vtx_0[4] = {
	{{{2, 1, -10}, 0, {617, 513}, {0x01, 0x03, 0x81, 0xFF}}},
	{{{18, 8, 0}, 0, {617, 513}, {0xFF, 0x7F, 0xFD, 0xFF}}},
	{{{21, 1, 11}, 0, {617, 513}, {0xCB, 0x1D, 0x70, 0xFF}}},
	{{{21, -7, -1}, 0, {617, 513}, {0xCA, 0x8F, 0xED, 0xFF}}},
};

Gfx yoshi_arm_l2_mesh_layer_1_tri_0[] = {
	gsSPVertex(yoshi_arm_l2_mesh_layer_1_vtx_0 + 0, 4, 4),
	gsSP2Triangles(2, 4, 1, 0, 4, 2, 0, 0),
	gsSP2Triangles(0, 5, 4, 0, 5, 0, 6, 0),
	gsSP2Triangles(3, 6, 0, 0, 6, 3, 7, 0),
	gsSP2Triangles(1, 7, 3, 0, 7, 1, 4, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_arm_l2_mesh_layer_1_vtx_1[4] = {
	{{{2, 1, -10}, 0, {617, 513}, {0x01, 0x03, 0x81, 0xFF}}},
	{{{21, 1, -11}, 0, {617, 513}, {0xDB, 0x0D, 0x87, 0xFF}}},
	{{{21, -7, -1}, 0, {617, 513}, {0xCA, 0x8F, 0xED, 0xFF}}},
	{{{18, 8, 0}, 0, {617, 513}, {0xFF, 0x7F, 0xFD, 0xFF}}},
};

Gfx yoshi_arm_l2_mesh_layer_1_tri_1[] = {
	gsSPVertex(yoshi_arm_l2_mesh_layer_1_vtx_1 + 0, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 1, 0, 3, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_arm_l2_mesh_layer_1_vtx_2[4] = {
	{{{37, -8, -13}, 0, {2042, 563}, {0xD2, 0xC6, 0x99, 0xFF}}},
	{{{21, -7, -1}, 0, {2042, 620}, {0xCA, 0x8F, 0xED, 0xFF}}},
	{{{21, 1, -11}, 0, {1763, 564}, {0xDB, 0x0D, 0x87, 0xFF}}},
	{{{33, 2, -14}, 0, {1891, 507}, {0xE1, 0x35, 0x91, 0xFF}}},
};

Gfx yoshi_arm_l2_mesh_layer_1_tri_2[] = {
	gsSPVertex(yoshi_arm_l2_mesh_layer_1_vtx_2 + 0, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_wrist_l1_skinned_mesh_layer_1_vtx_0[6] = {
	{{{21, -7, -1}, 0, {12, 617}, {0xCA, 0x8F, 0xED, 0xFF}}},
	{{{37, -8, -13}, 0, {12, 559}, {0xD2, 0xC6, 0x99, 0xFF}}},
	{{{21, -7, -1}, 0, {395, 177}, {0xCA, 0x8F, 0xED, 0xFF}}},
	{{{21, 1, 11}, 0, {617, 513}, {0xCB, 0x1D, 0x70, 0xFF}}},
	{{{18, 8, 0}, 0, {617, 513}, {0xFF, 0x7F, 0xFD, 0xFF}}},
	{{{21, 1, -11}, 0, {617, 513}, {0xDB, 0x0D, 0x87, 0xFF}}},
};

Gfx yoshi_wrist_l1_skinned_mesh_layer_1_tri_0[] = {
	gsSPVertex(yoshi_wrist_l1_skinned_mesh_layer_1_vtx_0 + 0, 6, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_wrist_l1_skinned_mesh_layer_1_vtx_1[7] = {
	{{{34, 3, 15}, 0, {1683, 5}, {0xDE, 0x40, 0x68, 0xFF}}},
	{{{34, 3, 15}, 0, {1954, 503}, {0xDE, 0x40, 0x68, 0xFF}}},
	{{{33, 2, -14}, 0, {1886, 4}, {0xE1, 0x35, 0x91, 0xFF}}},
	{{{37, -8, -13}, 0, {2042, 563}, {0xD2, 0xC6, 0x99, 0xFF}}},
	{{{33, 2, -14}, 0, {1891, 507}, {0xE1, 0x35, 0x91, 0xFF}}},
	{{{21, -7, -1}, 0, {1971, 602}, {0xCA, 0x8F, 0xED, 0xFF}}},
	{{{21, 1, 11}, 0, {1879, 536}, {0xCB, 0x1D, 0x70, 0xFF}}},
};

Gfx yoshi_wrist_l1_skinned_mesh_layer_1_tri_1[] = {
	gsSPVertex(yoshi_wrist_l1_skinned_mesh_layer_1_vtx_1 + 0, 7, 6),
	gsSPEndDisplayList(),
};

Vtx yoshi_wrist_l1_skinned_mesh_layer_1_vtx_2[4] = {
	{{{21, 1, 11}, 0, {1721, 990}, {0xCB, 0x1D, 0x70, 0xFF}}},
	{{{33, 2, -14}, 0, {1910, 1018}, {0xE1, 0x35, 0x91, 0xFF}}},
	{{{21, 1, -11}, 0, {1889, 970}, {0xDB, 0x0D, 0x87, 0xFF}}},
	{{{34, 3, 15}, 0, {1707, 1018}, {0xDE, 0x40, 0x68, 0xFF}}},
};

Gfx yoshi_wrist_l1_skinned_mesh_layer_1_tri_2[] = {
	gsSPVertex(yoshi_wrist_l1_skinned_mesh_layer_1_vtx_2 + 0, 4, 13),
	gsSPEndDisplayList(),
};

Vtx yoshi_wrist_l1_mesh_layer_1_vtx_0[5] = {
	{{{26, -12, -15}, 0, {151, 559}, {0x09, 0xA5, 0xA8, 0xFF}}},
	{{{29, 3, -18}, 0, {12, 437}, {0x2F, 0x45, 0xA1, 0xFF}}},
	{{{26, -12, -15}, 0, {87, 51}, {0x09, 0xA5, 0xA8, 0xFF}}},
	{{{13, -19, 14}, 0, {299, 301}, {0xD0, 0x9E, 0x41, 0xFF}}},
	{{{3, 8, 0}, 0, {617, 513}, {0xF9, 0x7F, 0xFD, 0xFF}}},
};

Gfx yoshi_wrist_l1_mesh_layer_1_tri_0[] = {
	gsSPVertex(yoshi_wrist_l1_mesh_layer_1_vtx_0 + 0, 5, 17),
	gsSP2Triangles(0, 1, 17, 0, 18, 17, 1, 0),
	gsSP2Triangles(2, 19, 20, 0, 3, 21, 4, 0),
	gsSP1Triangle(5, 4, 21, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_wrist_l1_mesh_layer_1_vtx_1[7] = {
	{{{29, 3, -18}, 0, {2042, 440}, {0x2F, 0x45, 0xA1, 0xFF}}},
	{{{31, 5, 19}, 0, {1665, 40}, {0x38, 0x48, 0x58, 0xFF}}},
	{{{19, 6, 11}, 0, {1717, 4}, {0xFA, 0x7C, 0x1C, 0xFF}}},
	{{{31, 5, 19}, 0, {2049, 460}, {0x38, 0x48, 0x58, 0xFF}}},
	{{{13, -19, 14}, 0, {2049, 654}, {0xD0, 0x9E, 0x41, 0xFF}}},
	{{{15, 6, -8}, 0, {1845, 5}, {0xFC, 0x79, 0xDB, 0xFF}}},
	{{{29, 3, -18}, 0, {1911, 60}, {0x2F, 0x45, 0xA1, 0xFF}}},
};

Gfx yoshi_wrist_l1_mesh_layer_1_tri_1[] = {
	gsSPVertex(yoshi_wrist_l1_mesh_layer_1_vtx_1 + 0, 7, 17),
	gsSP2Triangles(9, 10, 17, 0, 6, 18, 19, 0),
	gsSP2Triangles(20, 7, 21, 0, 7, 12, 21, 0),
	gsSP2Triangles(11, 21, 12, 0, 22, 23, 8, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_wrist_l1_mesh_layer_1_vtx_2[3] = {
	{{{3, 8, 0}, 0, {1811, 970}, {0xF9, 0x7F, 0xFD, 0xFF}}},
	{{{15, 6, -8}, 0, {1869, 1018}, {0xFC, 0x79, 0xDB, 0xFF}}},
	{{{19, 6, 11}, 0, {1742, 1018}, {0xFA, 0x7C, 0x1C, 0xFF}}},
};

Gfx yoshi_wrist_l1_mesh_layer_1_tri_2[] = {
	gsSPVertex(yoshi_wrist_l1_mesh_layer_1_vtx_2 + 0, 3, 17),
	gsSP2Triangles(17, 14, 15, 0, 17, 18, 14, 0),
	gsSP2Triangles(13, 16, 19, 0, 13, 19, 17, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_wrist_l1_mesh_layer_1_vtx_3[12] = {
	{{{26, -12, -15}, 0, {151, 559}, {0x09, 0xA5, 0xA8, 0xFF}}},
	{{{29, 3, -18}, 0, {19, 437}, {0x2F, 0x45, 0xA1, 0xFF}}},
	{{{35, -7, -14}, 0, {211, 449}, {0x6A, 0xE0, 0xC2, 0xFF}}},
	{{{25, -18, 15}, 0, {121, 267}, {0x29, 0x9E, 0x46, 0xFF}}},
	{{{13, -19, 14}, 0, {299, 301}, {0xD0, 0x9E, 0x41, 0xFF}}},
	{{{26, -12, -15}, 0, {87, 51}, {0x09, 0xA5, 0xA8, 0xFF}}},
	{{{35, -7, -14}, 0, {19, 57}, {0x6A, 0xE0, 0xC2, 0xFF}}},
	{{{36, -7, 11}, 0, {19, 275}, {0x78, 0xE9, 0x22, 0xFF}}},
	{{{36, -7, 11}, 0, {201, 483}, {0x78, 0xE9, 0x22, 0xFF}}},
	{{{31, 5, 19}, 0, {19, 457}, {0x38, 0x48, 0x58, 0xFF}}},
	{{{25, -18, 15}, 0, {129, 593}, {0x29, 0x9E, 0x46, 0xFF}}},
	{{{13, -19, 14}, 0, {19, 651}, {0xD0, 0x9E, 0x41, 0xFF}}},
};

Gfx yoshi_wrist_l1_mesh_layer_1_tri_3[] = {
	gsSPVertex(yoshi_wrist_l1_mesh_layer_1_vtx_3 + 0, 12, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(5, 6, 3, 0, 7, 3, 6, 0),
	gsSP2Triangles(8, 9, 10, 0, 11, 10, 9, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_wrist_l1_mesh_layer_1_vtx_4[8] = {
	{{{29, 3, -18}, 0, {1749, 36}, {0x2F, 0x45, 0xA1, 0xFF}}},
	{{{31, 5, 19}, 0, {1809, 348}, {0x38, 0x48, 0x58, 0xFF}}},
	{{{36, -7, 11}, 0, {2033, 286}, {0x78, 0xE9, 0x22, 0xFF}}},
	{{{35, -7, -14}, 0, {2013, 64}, {0x6A, 0xE0, 0xC2, 0xFF}}},
	{{{29, 3, -18}, 0, {1911, 60}, {0x2F, 0x45, 0xA1, 0xFF}}},
	{{{19, 6, 11}, 0, {1717, 4}, {0xFA, 0x7C, 0x1C, 0xFF}}},
	{{{31, 5, 19}, 0, {1665, 40}, {0x38, 0x48, 0x58, 0xFF}}},
	{{{15, 6, -8}, 0, {1845, 5}, {0xFC, 0x79, 0xDB, 0xFF}}},
};

Gfx yoshi_wrist_l1_mesh_layer_1_tri_4[] = {
	gsSPVertex(yoshi_wrist_l1_mesh_layer_1_vtx_4 + 0, 8, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 7, 5, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_wrist_l1_mesh_layer_1_vtx_5[3] = {
	{{{15, 6, -8}, 0, {1869, 1018}, {0xFC, 0x79, 0xDB, 0xFF}}},
	{{{3, 8, 0}, 0, {1811, 970}, {0xF9, 0x7F, 0xFD, 0xFF}}},
	{{{19, 6, 11}, 0, {1742, 1018}, {0xFA, 0x7C, 0x1C, 0xFF}}},
};

Gfx yoshi_wrist_l1_mesh_layer_1_tri_5[] = {
	gsSPVertex(yoshi_wrist_l1_mesh_layer_1_vtx_5 + 0, 3, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_arm_r1_skinned_mesh_layer_1_vtx_0[4] = {
	{{{-15, 33, -14}, 0, {617, 513}, {0xAA, 0x4D, 0xCB, 0xFF}}},
	{{{-6, 19, -26}, 0, {617, 513}, {0x01, 0xFB, 0x81, 0xFF}}},
	{{{-6, 38, -18}, 0, {617, 513}, {0xFF, 0x7D, 0xE8, 0xFF}}},
	{{{3, 33, -18}, 0, {617, 513}, {0x60, 0x48, 0xD6, 0xFF}}},
};

Gfx yoshi_arm_r1_skinned_mesh_layer_1_tri_0[] = {
	gsSPVertex(yoshi_arm_r1_skinned_mesh_layer_1_vtx_0 + 0, 4, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_arm_r1_mesh_layer_1_vtx_0[4] = {
	{{{20, -7, 0}, 0, {617, 513}, {0x08, 0x82, 0xF4, 0xFF}}},
	{{{19, 2, -9}, 0, {617, 513}, {0x03, 0x12, 0x82, 0xFF}}},
	{{{19, 8, 0}, 0, {617, 513}, {0x04, 0x7F, 0x07, 0xFF}}},
	{{{20, 2, 10}, 0, {617, 513}, {0x09, 0x0F, 0x7E, 0xFF}}},
};

Gfx yoshi_arm_r1_mesh_layer_1_tri_0[] = {
	gsSPVertex(yoshi_arm_r1_mesh_layer_1_vtx_0 + 0, 4, 4),
	gsSP2Triangles(0, 4, 1, 0, 0, 5, 4, 0),
	gsSP2Triangles(5, 0, 2, 0, 5, 2, 6, 0),
	gsSP2Triangles(3, 6, 2, 0, 6, 3, 7, 0),
	gsSP2Triangles(1, 7, 3, 0, 7, 1, 4, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_arm_r2_skinned_mesh_layer_1_vtx_0[4] = {
	{{{19, 8, 0}, 0, {617, 513}, {0x04, 0x7F, 0x07, 0xFF}}},
	{{{20, -7, 0}, 0, {617, 513}, {0x08, 0x82, 0xF4, 0xFF}}},
	{{{20, 2, 10}, 0, {617, 513}, {0x09, 0x0F, 0x7E, 0xFF}}},
	{{{19, 2, -9}, 0, {617, 513}, {0x03, 0x12, 0x82, 0xFF}}},
};

Gfx yoshi_arm_r2_skinned_mesh_layer_1_tri_0[] = {
	gsSPVertex(yoshi_arm_r2_skinned_mesh_layer_1_vtx_0 + 0, 4, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_arm_r2_mesh_layer_1_vtx_0[4] = {
	{{{2, 1, 10}, 0, {617, 513}, {0x01, 0x03, 0x7F, 0xFF}}},
	{{{21, -7, 1}, 0, {617, 513}, {0xCA, 0x8F, 0x13, 0xFF}}},
	{{{21, 1, -11}, 0, {617, 513}, {0xCB, 0x1D, 0x90, 0xFF}}},
	{{{18, 8, 0}, 0, {617, 513}, {0xFF, 0x7F, 0x03, 0xFF}}},
};

Gfx yoshi_arm_r2_mesh_layer_1_tri_0[] = {
	gsSPVertex(yoshi_arm_r2_mesh_layer_1_vtx_0 + 0, 4, 4),
	gsSP2Triangles(2, 4, 0, 0, 4, 2, 1, 0),
	gsSP2Triangles(1, 5, 4, 0, 5, 1, 3, 0),
	gsSP2Triangles(5, 3, 6, 0, 0, 6, 3, 0),
	gsSP2Triangles(0, 7, 6, 0, 7, 0, 4, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_arm_r2_mesh_layer_1_vtx_1[4] = {
	{{{21, 1, 11}, 0, {617, 513}, {0xDB, 0x0D, 0x79, 0xFF}}},
	{{{2, 1, 10}, 0, {617, 513}, {0x01, 0x03, 0x7F, 0xFF}}},
	{{{21, -7, 1}, 0, {617, 513}, {0xCA, 0x8F, 0x13, 0xFF}}},
	{{{18, 8, 0}, 0, {617, 513}, {0xFF, 0x7F, 0x03, 0xFF}}},
};

Gfx yoshi_arm_r2_mesh_layer_1_tri_1[] = {
	gsSPVertex(yoshi_arm_r2_mesh_layer_1_vtx_1 + 0, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 1, 0, 3, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_arm_r2_mesh_layer_1_vtx_2[3] = {
	{{{21, -7, 1}, 0, {2042, 620}, {0xCA, 0x8F, 0x13, 0xFF}}},
	{{{37, -8, 13}, 0, {2042, 563}, {0xD2, 0xC6, 0x67, 0xFF}}},
	{{{21, 1, 11}, 0, {1763, 564}, {0xDB, 0x0D, 0x79, 0xFF}}},
};

Gfx yoshi_arm_r2_mesh_layer_1_tri_2[] = {
	gsSPVertex(yoshi_arm_r2_mesh_layer_1_vtx_2 + 0, 3, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_wrist_r1_skinned_mesh_layer_1_vtx_0[6] = {
	{{{21, -7, 1}, 0, {395, 177}, {0xCA, 0x8F, 0x13, 0xFF}}},
	{{{37, -8, 13}, 0, {12, 559}, {0xD2, 0xC6, 0x67, 0xFF}}},
	{{{21, -7, 1}, 0, {12, 617}, {0xCA, 0x8F, 0x13, 0xFF}}},
	{{{18, 8, 0}, 0, {617, 513}, {0xFF, 0x7F, 0x03, 0xFF}}},
	{{{21, 1, 11}, 0, {617, 513}, {0xDB, 0x0D, 0x79, 0xFF}}},
	{{{21, 1, -11}, 0, {617, 513}, {0xCB, 0x1D, 0x90, 0xFF}}},
};

Gfx yoshi_wrist_r1_skinned_mesh_layer_1_tri_0[] = {
	gsSPVertex(yoshi_wrist_r1_skinned_mesh_layer_1_vtx_0 + 0, 6, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_wrist_r1_skinned_mesh_layer_1_vtx_1[6] = {
	{{{21, 1, -11}, 0, {1879, 536}, {0xCB, 0x1D, 0x90, 0xFF}}},
	{{{21, -7, 1}, 0, {1971, 602}, {0xCA, 0x8F, 0x13, 0xFF}}},
	{{{21, 1, 11}, 0, {1763, 564}, {0xDB, 0x0D, 0x79, 0xFF}}},
	{{{37, -8, 13}, 0, {2042, 563}, {0xD2, 0xC6, 0x67, 0xFF}}},
	{{{33, 2, 14}, 0, {1886, 4}, {0xE7, 0x6B, 0x40, 0xFF}}},
	{{{34, 3, -15}, 0, {1683, 5}, {0xE3, 0x6D, 0xC5, 0xFF}}},
};

Gfx yoshi_wrist_r1_skinned_mesh_layer_1_tri_1[] = {
	gsSPVertex(yoshi_wrist_r1_skinned_mesh_layer_1_vtx_1 + 0, 6, 6),
	gsSPEndDisplayList(),
};

Vtx yoshi_wrist_r1_skinned_mesh_layer_1_vtx_2[4] = {
	{{{21, 1, -11}, 0, {1721, 990}, {0xCB, 0x1D, 0x90, 0xFF}}},
	{{{21, 1, 11}, 0, {1889, 970}, {0xDB, 0x0D, 0x79, 0xFF}}},
	{{{33, 2, 14}, 0, {1910, 1018}, {0xE7, 0x6B, 0x40, 0xFF}}},
	{{{34, 3, -15}, 0, {1707, 1018}, {0xE3, 0x6D, 0xC5, 0xFF}}},
};

Gfx yoshi_wrist_r1_skinned_mesh_layer_1_tri_2[] = {
	gsSPVertex(yoshi_wrist_r1_skinned_mesh_layer_1_vtx_2 + 0, 4, 12),
	gsSPEndDisplayList(),
};

Vtx yoshi_wrist_r1_mesh_layer_1_vtx_0[5] = {
	{{{13, -19, -14}, 0, {299, 301}, {0xD1, 0x9E, 0xBF, 0xFF}}},
	{{{26, -12, 15}, 0, {87, 51}, {0x07, 0xA5, 0x58, 0xFF}}},
	{{{26, -12, 15}, 0, {151, 559}, {0x07, 0xA5, 0x58, 0xFF}}},
	{{{29, 3, 18}, 0, {12, 437}, {0x2E, 0x46, 0x60, 0xFF}}},
	{{{3, 8, 0}, 0, {617, 513}, {0xF8, 0x7F, 0x03, 0xFF}}},
};

Gfx yoshi_wrist_r1_mesh_layer_1_tri_0[] = {
	gsSPVertex(yoshi_wrist_r1_mesh_layer_1_vtx_0 + 0, 5, 16),
	gsSP2Triangles(0, 16, 17, 0, 18, 1, 2, 0),
	gsSP2Triangles(19, 1, 18, 0, 20, 3, 4, 0),
	gsSP1Triangle(20, 5, 3, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_wrist_r1_mesh_layer_1_vtx_1[7] = {
	{{{29, 3, 18}, 0, {2042, 440}, {0x2E, 0x46, 0x60, 0xFF}}},
	{{{31, 5, -18}, 0, {2049, 460}, {0x3A, 0x48, 0xA9, 0xFF}}},
	{{{13, -19, -14}, 0, {2049, 654}, {0xD1, 0x9E, 0xBF, 0xFF}}},
	{{{15, 6, 8}, 0, {1845, 5}, {0xFB, 0x79, 0x25, 0xFF}}},
	{{{29, 3, 18}, 0, {1911, 60}, {0x2E, 0x46, 0x60, 0xFF}}},
	{{{19, 6, -10}, 0, {1717, 4}, {0xFA, 0x7C, 0xE4, 0xFF}}},
	{{{31, 5, -18}, 0, {1665, 40}, {0x3A, 0x48, 0xA9, 0xFF}}},
};

Gfx yoshi_wrist_r1_mesh_layer_1_tri_1[] = {
	gsSPVertex(yoshi_wrist_r1_mesh_layer_1_vtx_1 + 0, 7, 16),
	gsSP2Triangles(8, 9, 16, 0, 17, 18, 6, 0),
	gsSP2Triangles(7, 6, 18, 0, 19, 10, 20, 0),
	gsSP1Triangle(11, 21, 22, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_wrist_r1_mesh_layer_1_vtx_2[3] = {
	{{{3, 8, 0}, 0, {1811, 970}, {0xF8, 0x7F, 0x03, 0xFF}}},
	{{{15, 6, 8}, 0, {1869, 1018}, {0xFB, 0x79, 0x25, 0xFF}}},
	{{{19, 6, -10}, 0, {1742, 1018}, {0xFA, 0x7C, 0xE4, 0xFF}}},
};

Gfx yoshi_wrist_r1_mesh_layer_1_tri_2[] = {
	gsSPVertex(yoshi_wrist_r1_mesh_layer_1_vtx_2 + 0, 3, 16),
	gsSP2Triangles(16, 13, 14, 0, 16, 14, 17, 0),
	gsSP2Triangles(12, 18, 15, 0, 12, 16, 18, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_wrist_r1_mesh_layer_1_vtx_3[12] = {
	{{{34, -7, 14}, 0, {211, 449}, {0x69, 0xE0, 0x3F, 0xFF}}},
	{{{29, 3, 18}, 0, {19, 437}, {0x2E, 0x46, 0x60, 0xFF}}},
	{{{26, -12, 15}, 0, {151, 559}, {0x07, 0xA5, 0x58, 0xFF}}},
	{{{36, -7, -11}, 0, {19, 275}, {0x79, 0xE9, 0xDF, 0xFF}}},
	{{{34, -7, 14}, 0, {19, 57}, {0x69, 0xE0, 0x3F, 0xFF}}},
	{{{26, -18, -15}, 0, {121, 267}, {0x2A, 0x9E, 0xBB, 0xFF}}},
	{{{26, -12, 15}, 0, {87, 51}, {0x07, 0xA5, 0x58, 0xFF}}},
	{{{13, -19, -14}, 0, {299, 301}, {0xD1, 0x9E, 0xBF, 0xFF}}},
	{{{36, -7, -11}, 0, {201, 483}, {0x79, 0xE9, 0xDF, 0xFF}}},
	{{{26, -18, -15}, 0, {129, 593}, {0x2A, 0x9E, 0xBB, 0xFF}}},
	{{{31, 5, -18}, 0, {19, 457}, {0x3A, 0x48, 0xA9, 0xFF}}},
	{{{13, -19, -14}, 0, {19, 651}, {0xD1, 0x9E, 0xBF, 0xFF}}},
};

Gfx yoshi_wrist_r1_mesh_layer_1_tri_3[] = {
	gsSPVertex(yoshi_wrist_r1_mesh_layer_1_vtx_3 + 0, 12, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(6, 5, 4, 0, 5, 6, 7, 0),
	gsSP2Triangles(8, 9, 10, 0, 11, 10, 9, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_wrist_r1_mesh_layer_1_vtx_4[8] = {
	{{{29, 3, 18}, 0, {1749, 36}, {0x2E, 0x46, 0x60, 0xFF}}},
	{{{34, -7, 14}, 0, {2013, 64}, {0x69, 0xE0, 0x3F, 0xFF}}},
	{{{36, -7, -11}, 0, {2033, 286}, {0x79, 0xE9, 0xDF, 0xFF}}},
	{{{31, 5, -18}, 0, {1809, 348}, {0x3A, 0x48, 0xA9, 0xFF}}},
	{{{29, 3, 18}, 0, {1911, 60}, {0x2E, 0x46, 0x60, 0xFF}}},
	{{{31, 5, -18}, 0, {1665, 40}, {0x3A, 0x48, 0xA9, 0xFF}}},
	{{{19, 6, -10}, 0, {1717, 4}, {0xFA, 0x7C, 0xE4, 0xFF}}},
	{{{15, 6, 8}, 0, {1845, 5}, {0xFB, 0x79, 0x25, 0xFF}}},
};

Gfx yoshi_wrist_r1_mesh_layer_1_tri_4[] = {
	gsSPVertex(yoshi_wrist_r1_mesh_layer_1_vtx_4 + 0, 8, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_wrist_r1_mesh_layer_1_vtx_5[3] = {
	{{{15, 6, 8}, 0, {1869, 1018}, {0xFB, 0x79, 0x25, 0xFF}}},
	{{{19, 6, -10}, 0, {1742, 1018}, {0xFA, 0x7C, 0xE4, 0xFF}}},
	{{{3, 8, 0}, 0, {1811, 970}, {0xF8, 0x7F, 0x03, 0xFF}}},
};

Gfx yoshi_wrist_r1_mesh_layer_1_tri_5[] = {
	gsSPVertex(yoshi_wrist_r1_mesh_layer_1_vtx_5 + 0, 3, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_face_1_mesh_layer_1_vtx_0[71] = {
	{{{-26, 15, -1}, 0, {1081, 88}, {0xC8, 0x8E, 0xFD, 0xFF}}},
	{{{-31, 24, -17}, 0, {1419, 2}, {0xE4, 0xCE, 0x8F, 0xFF}}},
	{{{-22, 9, -1}, 0, {1081, 2}, {0x83, 0x17, 0xFF, 0xFF}}},
	{{{-32, 24, 18}, 0, {631, 960}, {0xDB, 0xD3, 0x71, 0xFF}}},
	{{{-51, 27, 29}, 0, {607, 954}, {0x00, 0xD0, 0x76, 0xFF}}},
	{{{-50, 8, 12}, 0, {611, 976}, {0xFE, 0x8E, 0x37, 0xFF}}},
	{{{-72, 29, 20}, 0, {577, 946}, {0xAB, 0xD5, 0x54, 0xFF}}},
	{{{-51, 45, 31}, 0, {605, 942}, {0x04, 0x0F, 0x7E, 0xFF}}},
	{{{-32, 24, 18}, 0, {631, 958}, {0xDB, 0xD3, 0x71, 0xFF}}},
	{{{-73, 55, 20}, 0, {573, 928}, {0xAC, 0x2E, 0x53, 0xFF}}},
	{{{-51, 67, 20}, 0, {603, 930}, {0x01, 0x60, 0x53, 0xFF}}},
	{{{-22, 52, 16}, 0, {637, 930}, {0x0B, 0x44, 0x6A, 0xFF}}},
	{{{-32, 24, 18}, 0, {631, 956}, {0xDB, 0xD3, 0x71, 0xFF}}},
	{{{-34, 70, -1}, 0, {625, 914}, {0x3E, 0x6F, 0x01, 0xFF}}},
	{{{-21, 56, -1}, 0, {647, 924}, {0x5C, 0x58, 0x02, 0xFF}}},
	{{{-21, 52, -17}, 0, {637, 930}, {0x4C, 0x38, 0xAB, 0xFF}}},
	{{{-50, 67, -23}, 0, {603, 930}, {0x05, 0x5F, 0xAC, 0xFF}}},
	{{{-49, 45, -34}, 0, {605, 942}, {0x0C, 0x0C, 0x82, 0xFF}}},
	{{{-50, 27, -31}, 0, {607, 954}, {0x0C, 0xCD, 0x8C, 0xFF}}},
	{{{-31, 24, -17}, 0, {631, 958}, {0xE4, 0xCE, 0x8F, 0xFF}}},
	{{{-71, 29, -24}, 0, {577, 946}, {0xB1, 0xD4, 0xA7, 0xFF}}},
	{{{-49, 8, -15}, 0, {611, 976}, {0x04, 0x8F, 0xC6, 0xFF}}},
	{{{-31, 24, -17}, 0, {631, 960}, {0xE4, 0xCE, 0x8F, 0xFF}}},
	{{{-72, 14, -2}, 0, {583, 970}, {0xAA, 0xA2, 0xFE, 0xFF}}},
	{{{-26, 15, -1}, 0, {633, 968}, {0xC8, 0x8E, 0xFD, 0xFF}}},
	{{{-31, 24, -17}, 0, {633, 960}, {0xE4, 0xCE, 0x8F, 0xFF}}},
	{{{-32, 24, 18}, 0, {633, 960}, {0xDB, 0xD3, 0x71, 0xFF}}},
	{{{-84, 39, -2}, 0, {561, 948}, {0x81, 0xF9, 0xFD, 0xFF}}},
	{{{-72, 55, -24}, 0, {573, 928}, {0xB0, 0x2E, 0xA9, 0xFF}}},
	{{{-53, 75, -2}, 0, {597, 912}, {0xF9, 0x7F, 0x00, 0xFF}}},
	{{{5, 58, -13}, 0, {683, 920}, {0x4A, 0x59, 0xCC, 0xFF}}},
	{{{2, 60, 0}, 0, {679, 918}, {0x4A, 0x67, 0x02, 0xFF}}},
	{{{15, 50, 0}, 0, {695, 922}, {0x65, 0x4D, 0x03, 0xFF}}},
	{{{4, 58, 13}, 0, {683, 920}, {0x48, 0x59, 0x38, 0xFF}}},
	{{{-10, 77, -24}, 0, {657, 900}, {0xED, 0x32, 0x8D, 0xFF}}},
	{{{-11, 88, -11}, 0, {655, 894}, {0xEA, 0x7D, 0xF9, 0xFF}}},
	{{{1, 76, -22}, 0, {673, 908}, {0x43, 0x26, 0x9B, 0xFF}}},
	{{{2, 84, -8}, 0, {673, 896}, {0x51, 0x5E, 0x19, 0xFF}}},
	{{{-9, 80, 0}, 0, {659, 900}, {0xFE, 0x59, 0x5A, 0xFF}}},
	{{{1, 73, 0}, 0, {673, 906}, {0x64, 0x21, 0x47, 0xFF}}},
	{{{7, 71, -13}, 0, {683, 908}, {0x7D, 0x0C, 0xEE, 0xFF}}},
	{{{2, 60, 0}, 0, {679, 918}, {0x78, 0xFF, 0x29, 0xFF}}},
	{{{5, 58, -13}, 0, {683, 920}, {0x70, 0xE1, 0xCC, 0xFF}}},
	{{{-10, 77, -24}, 0, {37, 710}, {0xED, 0x32, 0x8D, 0xFF}}},
	{{{1, 76, -22}, 0, {443, 444}, {0x43, 0x26, 0x9B, 0xFF}}},
	{{{-13, 54, -22}, 0, {187, 802}, {0xE7, 0xF3, 0x84, 0xFF}}},
	{{{3, 58, -14}, 0, {583, 579}, {0x3A, 0xD9, 0x96, 0xFF}}},
	{{{5, 58, -13}, 0, {615, 560}, {0x70, 0xE1, 0xCC, 0xFF}}},
	{{{-11, 77, 23}, 0, {657, 900}, {0xE7, 0x32, 0x72, 0xFF}}},
	{{{0, 76, 22}, 0, {673, 908}, {0x3E, 0x27, 0x68, 0xFF}}},
	{{{-11, 88, 10}, 0, {655, 894}, {0xE9, 0x7D, 0x05, 0xFF}}},
	{{{1, 84, 8}, 0, {673, 896}, {0x52, 0x5E, 0xEB, 0xFF}}},
	{{{6, 71, 14}, 0, {683, 908}, {0x7C, 0x0C, 0x19, 0xFF}}},
	{{{4, 58, 13}, 0, {683, 920}, {0x6D, 0xE1, 0x3A, 0xFF}}},
	{{{2, 60, 0}, 0, {679, 918}, {0x7A, 0xFF, 0xDD, 0xFF}}},
	{{{1, 73, 0}, 0, {673, 906}, {0x68, 0x20, 0xBF, 0xFF}}},
	{{{-9, 80, 0}, 0, {659, 900}, {0x02, 0x59, 0xA6, 0xFF}}},
	{{{-11, 77, 23}, 0, {37, 710}, {0xE7, 0x32, 0x72, 0xFF}}},
	{{{-15, 54, 21}, 0, {179, 802}, {0xE1, 0xF4, 0x7B, 0xFF}}},
	{{{0, 76, 22}, 0, {443, 444}, {0x3E, 0x27, 0x68, 0xFF}}},
	{{{2, 58, 14}, 0, {589, 729}, {0x35, 0xD9, 0x6D, 0xFF}}},
	{{{-26, 15, -1}, 0, {1081, 2}, {0xC8, 0x8E, 0xFD, 0xFF}}},
	{{{-22, 9, -1}, 0, {1081, 88}, {0x83, 0x17, 0xFF, 0xFF}}},
	{{{-32, 24, 18}, 0, {1419, 0}, {0xDB, 0xD3, 0x71, 0xFF}}},
	{{{-84, 39, -2}, 0, {829, 988}, {0x81, 0xF9, 0xFD, 0xFF}}},
	{{{-74, 67, -2}, 0, {829, 700}, {0xA9, 0x5D, 0xFE, 0xFF}}},
	{{{-72, 55, -24}, 0, {1149, 860}, {0xB0, 0x2E, 0xA9, 0xFF}}},
	{{{-73, 55, 20}, 0, {1149, 860}, {0xAC, 0x2E, 0x53, 0xFF}}},
	{{{-51, 67, 20}, 0, {1149, 572}, {0x01, 0x60, 0x53, 0xFF}}},
	{{{-53, 75, -2}, 0, {829, 476}, {0xF9, 0x7F, 0x00, 0xFF}}},
	{{{-50, 67, -23}, 0, {1149, 572}, {0x05, 0x5F, 0xAC, 0xFF}}},
};

Gfx yoshi_face_1_mesh_layer_1_tri_0[] = {
	gsSPVertex(yoshi_face_1_mesh_layer_1_vtx_0 + 0, 64, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(6, 5, 4, 0, 6, 4, 7, 0),
	gsSP2Triangles(8, 7, 4, 0, 7, 9, 6, 0),
	gsSP2Triangles(9, 7, 10, 0, 11, 10, 7, 0),
	gsSP2Triangles(7, 12, 11, 0, 10, 11, 13, 0),
	gsSP2Triangles(11, 14, 13, 0, 15, 13, 14, 0),
	gsSP2Triangles(13, 15, 16, 0, 17, 16, 15, 0),
	gsSP2Triangles(18, 17, 15, 0, 18, 15, 19, 0),
	gsSP2Triangles(17, 18, 20, 0, 21, 20, 18, 0),
	gsSP2Triangles(22, 21, 18, 0, 20, 21, 23, 0),
	gsSP2Triangles(5, 23, 21, 0, 21, 24, 5, 0),
	gsSP2Triangles(24, 21, 25, 0, 26, 5, 24, 0),
	gsSP2Triangles(5, 6, 23, 0, 27, 23, 6, 0),
	gsSP2Triangles(27, 6, 9, 0, 23, 27, 20, 0),
	gsSP2Triangles(28, 20, 27, 0, 20, 28, 17, 0),
	gsSP2Triangles(16, 17, 28, 0, 16, 29, 13, 0),
	gsSP2Triangles(10, 13, 29, 0, 30, 31, 32, 0),
	gsSP2Triangles(33, 32, 31, 0, 34, 35, 36, 0),
	gsSP2Triangles(37, 36, 35, 0, 35, 38, 37, 0),
	gsSP2Triangles(39, 37, 38, 0, 39, 40, 37, 0),
	gsSP2Triangles(40, 39, 41, 0, 41, 42, 40, 0),
	gsSP2Triangles(36, 40, 42, 0, 36, 37, 40, 0),
	gsSP2Triangles(43, 44, 45, 0, 46, 45, 44, 0),
	gsSP2Triangles(47, 46, 44, 0, 48, 49, 50, 0),
	gsSP2Triangles(51, 50, 49, 0, 51, 49, 52, 0),
	gsSP2Triangles(53, 52, 49, 0, 52, 53, 54, 0),
	gsSP2Triangles(54, 55, 52, 0, 51, 52, 55, 0),
	gsSP2Triangles(55, 56, 51, 0, 50, 51, 56, 0),
	gsSP2Triangles(57, 58, 59, 0, 59, 58, 60, 0),
	gsSP2Triangles(59, 60, 53, 0, 61, 62, 63, 0),
	gsSPVertex(yoshi_face_1_mesh_layer_1_vtx_0 + 64, 7, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(4, 1, 3, 0, 1, 4, 5, 0),
	gsSP2Triangles(6, 1, 5, 0, 6, 2, 1, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_face_1_mesh_layer_1_vtx_1[20] = {
	{{{-21, 56, -1}, 0, {512, 896}, {0x83, 0xFF, 0xE8, 0xFF}}},
	{{{-22, 52, 16}, 0, {860, 1014}, {0x91, 0xFF, 0x3E, 0xFF}}},
	{{{-23, 68, 7}, 0, {660, 582}, {0x82, 0x11, 0xF8, 0xFF}}},
	{{{-19, 76, 18}, 0, {956, 300}, {0x9F, 0x2B, 0x45, 0xFF}}},
	{{{-15, 54, 21}, 0, {1016, 790}, {0xE1, 0xF4, 0x7B, 0xFF}}},
	{{{-11, 77, 23}, 0, {1124, 172}, {0xE7, 0x32, 0x72, 0xFF}}},
	{{{-11, 88, 10}, 0, {664, 10}, {0xE9, 0x7D, 0x05, 0xFF}}},
	{{{-19, 81, 6}, 0, {604, 212}, {0xA1, 0x4E, 0xDF, 0xFF}}},
	{{{-9, 80, 0}, 0, {512, 198}, {0x02, 0x59, 0xA6, 0xFF}}},
	{{{-18, 75, -1}, 0, {512, 320}, {0xA4, 0x33, 0xB9, 0xFF}}},
	{{{-21, 52, -17}, 0, {164, 1014}, {0x95, 0xFF, 0xBC, 0xFF}}},
	{{{-21, 56, -1}, 0, {512, 896}, {0x82, 0xFF, 0x11, 0xFF}}},
	{{{-22, 68, -9}, 0, {364, 582}, {0x82, 0x11, 0x01, 0xFF}}},
	{{{-18, 75, -1}, 0, {512, 320}, {0xA0, 0x34, 0x42, 0xFF}}},
	{{{-19, 81, -7}, 0, {420, 212}, {0xA0, 0x4E, 0x1C, 0xFF}}},
	{{{-9, 80, 0}, 0, {512, 198}, {0xFE, 0x59, 0x5A, 0xFF}}},
	{{{-11, 88, -11}, 0, {360, 10}, {0xEA, 0x7D, 0xF9, 0xFF}}},
	{{{-18, 76, -19}, 0, {68, 300}, {0xA3, 0x2B, 0xB6, 0xFF}}},
	{{{-10, 77, -24}, 0, {-100, 172}, {0xED, 0x32, 0x8D, 0xFF}}},
	{{{-13, 54, -22}, 0, {8, 790}, {0xE7, 0xF3, 0x84, 0xFF}}},
};

Gfx yoshi_face_1_mesh_layer_1_tri_1[] = {
	gsSPVertex(yoshi_face_1_mesh_layer_1_vtx_1 + 0, 20, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
	gsSP2Triangles(1, 4, 3, 0, 5, 3, 4, 0),
	gsSP2Triangles(3, 5, 6, 0, 6, 7, 3, 0),
	gsSP2Triangles(7, 6, 8, 0, 8, 9, 7, 0),
	gsSP2Triangles(2, 7, 9, 0, 0, 2, 9, 0),
	gsSP2Triangles(2, 3, 7, 0, 10, 11, 12, 0),
	gsSP2Triangles(13, 12, 11, 0, 13, 14, 12, 0),
	gsSP2Triangles(14, 13, 15, 0, 15, 16, 14, 0),
	gsSP2Triangles(17, 14, 16, 0, 16, 18, 17, 0),
	gsSP2Triangles(19, 17, 18, 0, 19, 10, 17, 0),
	gsSP2Triangles(12, 17, 10, 0, 17, 12, 14, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_face_1_mesh_layer_1_vtx_2[36] = {
	{{{15, 50, 0}, 0, {611, 160}, {0x65, 0x4D, 0x03, 0xFF}}},
	{{{10, 40, -28}, 0, {43, 386}, {0x4A, 0x38, 0xA9, 0xFF}}},
	{{{5, 58, -13}, 0, {43, 42}, {0x4A, 0x59, 0xCC, 0xFF}}},
	{{{26, 31, 1}, 0, {605, 402}, {0x7D, 0x15, 0x03, 0xFF}}},
	{{{9, 40, 29}, 0, {43, 386}, {0x45, 0x38, 0x5B, 0xFF}}},
	{{{4, 58, 13}, 0, {43, 42}, {0x48, 0x59, 0x38, 0xFF}}},
	{{{19, 22, 21}, 0, {363, 624}, {0x6D, 0xE9, 0x3C, 0xFF}}},
	{{{20, 10, 1}, 0, {681, 752}, {0x69, 0xB9, 0x03, 0xFF}}},
	{{{20, 22, -20}, 0, {363, 624}, {0x70, 0xE9, 0xCA, 0xFF}}},
	{{{9, 40, 29}, 0, {43, 386}, {0x45, 0x38, 0x5B, 0xFF}}},
	{{{2, 58, 14}, 0, {15, 44}, {0x13, 0x54, 0x5D, 0xFF}}},
	{{{7, 41, 28}, 0, {15, 362}, {0x10, 0x51, 0x60, 0xFF}}},
	{{{10, 40, -28}, 0, {43, 386}, {0x4A, 0x38, 0xA9, 0xFF}}},
	{{{3, 58, -14}, 0, {15, 44}, {0x18, 0x54, 0xA3, 0xFF}}},
	{{{8, 41, -28}, 0, {15, 362}, {0x16, 0x51, 0xA1, 0xFF}}},
	{{{14, 8, 4}, 0, {1386, 237}, {0x05, 0xED, 0x7D, 0xFF}}},
	{{{2, 0, 0}, 0, {1354, 77}, {0xDC, 0x86, 0xFF, 0xFF}}},
	{{{17, -4, 0}, 0, {1418, 109}, {0xFB, 0x81, 0x00, 0xFF}}},
	{{{14, 8, -4}, 0, {1386, 237}, {0x0C, 0xEC, 0x83, 0xFF}}},
	{{{30, -2, 1}, 0, {1418, 237}, {0x5D, 0xAA, 0x03, 0xFF}}},
	{{{31, 10, 1}, 0, {1418, 397}, {0x79, 0x25, 0x03, 0xFF}}},
	{{{22, 18, 1}, 0, {1354, 461}, {0x54, 0x5F, 0x02, 0xFF}}},
	{{{22, 32, 5}, 0, {1386, 237}, {0x13, 0x06, 0x7D, 0xFF}}},
	{{{22, 18, 1}, 0, {1354, 461}, {0x2F, 0x8A, 0x01, 0xFF}}},
	{{{35, 23, 1}, 0, {1418, 397}, {0x5E, 0xAB, 0x03, 0xFF}}},
	{{{23, 32, -4}, 0, {1386, 237}, {0x19, 0x05, 0x84, 0xFF}}},
	{{{39, 36, 1}, 0, {1418, 237}, {0x7A, 0x23, 0x03, 0xFF}}},
	{{{30, 43, 1}, 0, {1418, 109}, {0x32, 0x75, 0x01, 0xFF}}},
	{{{18, 44, 0}, 0, {1354, 77}, {0x0D, 0x7E, 0x00, 0xFF}}},
	{{{12, 50, 5}, 0, {1386, 237}, {0x0F, 0x06, 0x7E, 0xFF}}},
	{{{18, 44, 0}, 0, {1354, 77}, {0x58, 0xA5, 0xF8, 0xFF}}},
	{{{26, 52, 1}, 0, {1418, 109}, {0x78, 0xD7, 0x01, 0xFF}}},
	{{{11, 50, -5}, 0, {1386, 237}, {0x11, 0x0A, 0x83, 0xFF}}},
	{{{27, 64, 1}, 0, {1418, 237}, {0x66, 0x4B, 0x02, 0xFF}}},
	{{{17, 67, 0}, 0, {1418, 397}, {0xFF, 0x7F, 0x00, 0xFF}}},
	{{{2, 59, 0}, 0, {1354, 461}, {0xC6, 0x71, 0xF7, 0xFF}}},
};

Gfx yoshi_face_1_mesh_layer_1_tri_2[] = {
	gsSPVertex(yoshi_face_1_mesh_layer_1_vtx_2 + 0, 36, 0),
	gsSP2Triangles(0, 1, 2, 0, 1, 0, 3, 0),
	gsSP2Triangles(4, 3, 0, 0, 0, 5, 4, 0),
	gsSP2Triangles(3, 4, 6, 0, 7, 3, 6, 0),
	gsSP2Triangles(7, 8, 3, 0, 1, 3, 8, 0),
	gsSP2Triangles(9, 5, 10, 0, 11, 9, 10, 0),
	gsSP2Triangles(12, 13, 2, 0, 14, 13, 12, 0),
	gsSP2Triangles(15, 16, 17, 0, 18, 17, 16, 0),
	gsSP2Triangles(17, 18, 19, 0, 20, 19, 18, 0),
	gsSP2Triangles(20, 18, 21, 0, 21, 15, 20, 0),
	gsSP2Triangles(19, 20, 15, 0, 15, 17, 19, 0),
	gsSP2Triangles(22, 23, 24, 0, 25, 24, 23, 0),
	gsSP2Triangles(24, 25, 26, 0, 27, 26, 25, 0),
	gsSP2Triangles(27, 25, 28, 0, 28, 22, 27, 0),
	gsSP2Triangles(26, 27, 22, 0, 24, 26, 22, 0),
	gsSP2Triangles(29, 30, 31, 0, 32, 31, 30, 0),
	gsSP2Triangles(31, 32, 33, 0, 34, 33, 32, 0),
	gsSP2Triangles(34, 32, 35, 0, 35, 29, 34, 0),
	gsSP2Triangles(33, 34, 29, 0, 31, 33, 29, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_face_1_mesh_layer_1_vtx_3[49] = {
	{{{3, -1, -13}, 0, {1826, 340}, {0x2B, 0x94, 0xCE, 0xFF}}},
	{{{20, 22, -20}, 0, {1408, 422}, {0x70, 0xE9, 0xCA, 0xFF}}},
	{{{20, 10, 1}, 0, {1478, 66}, {0x69, 0xB9, 0x03, 0xFF}}},
	{{{3, -1, 13}, 0, {1826, 340}, {0x29, 0x94, 0x34, 0xFF}}},
	{{{19, 22, 21}, 0, {1408, 422}, {0x6D, 0xE9, 0x3C, 0xFF}}},
	{{{-7, 32, 37}, 0, {1414, 732}, {0xF5, 0x19, 0x7C, 0xFF}}},
	{{{11, 19, 31}, 0, {1416, 728}, {0x47, 0xD9, 0x62, 0xFF}}},
	{{{9, 40, 29}, 0, {2049, 386}, {0x45, 0x38, 0x5B, 0xFF}}},
	{{{7, 41, 28}, 0, {2048, 362}, {0x10, 0x51, 0x60, 0xFF}}},
	{{{-15, 54, 21}, 0, {1710, 68}, {0xDF, 0x45, 0x65, 0xFF}}},
	{{{2, 58, 14}, 0, {2048, 43}, {0x13, 0x54, 0x5D, 0xFF}}},
	{{{-25, 40, 20}, 0, {1458, 390}, {0x9F, 0x2C, 0x45, 0xFF}}},
	{{{-22, 19, 31}, 0, {1320, 602}, {0xBA, 0xE4, 0x66, 0xFF}}},
	{{{-32, 24, 18}, 0, {1866, 478}, {0xDB, 0xD3, 0x71, 0xFF}}},
	{{{-22, 52, 16}, 0, {1412, 160}, {0x0B, 0x44, 0x6A, 0xFF}}},
	{{{-32, 24, 18}, 0, {1870, 456}, {0xDB, 0xD3, 0x71, 0xFF}}},
	{{{19, 22, 21}, 0, {2049, 659}, {0x6D, 0xE9, 0x3C, 0xFF}}},
	{{{9, 40, 29}, 0, {2049, 386}, {0x45, 0x38, 0x5B, 0xFF}}},
	{{{3, -1, 13}, 0, {2049, 898}, {0x29, 0x94, 0x34, 0xFF}}},
	{{{11, 19, 31}, 0, {162, 975}, {0x47, 0xD9, 0x62, 0xFF}}},
	{{{-7, 32, 37}, 0, {162, 975}, {0xF5, 0x19, 0x7C, 0xFF}}},
	{{{-7, 10, 30}, 0, {162, 975}, {0xFF, 0xB1, 0x63, 0xFF}}},
	{{{-22, 19, 31}, 0, {162, 975}, {0xBA, 0xE4, 0x66, 0xFF}}},
	{{{-7, 10, 30}, 0, {1257, 561}, {0xFF, 0xB1, 0x63, 0xFF}}},
	{{{3, -1, 13}, 0, {1257, 561}, {0x29, 0x94, 0x34, 0xFF}}},
	{{{11, 19, 31}, 0, {1257, 561}, {0x47, 0xD9, 0x62, 0xFF}}},
	{{{-5, 32, -37}, 0, {1414, 732}, {0xFA, 0x18, 0x83, 0xFF}}},
	{{{10, 40, -28}, 0, {2049, 386}, {0x4A, 0x38, 0xA9, 0xFF}}},
	{{{12, 19, -30}, 0, {1416, 728}, {0x4D, 0xD9, 0xA2, 0xFF}}},
	{{{-13, 54, -22}, 0, {1710, 68}, {0xE5, 0x44, 0x99, 0xFF}}},
	{{{-24, 40, -21}, 0, {1458, 390}, {0xA1, 0x2A, 0xB7, 0xFF}}},
	{{{-21, 18, -31}, 0, {1320, 602}, {0xBC, 0xE4, 0x98, 0xFF}}},
	{{{-31, 24, -17}, 0, {1866, 478}, {0xE4, 0xCE, 0x8F, 0xFF}}},
	{{{-21, 52, -17}, 0, {1412, 160}, {0xB2, 0x31, 0xA8, 0xFF}}},
	{{{-31, 24, -17}, 0, {1870, 456}, {0xE4, 0xCE, 0x8F, 0xFF}}},
	{{{20, 22, -20}, 0, {2049, 659}, {0x70, 0xE9, 0xCA, 0xFF}}},
	{{{10, 40, -28}, 0, {2049, 386}, {0x4A, 0x38, 0xA9, 0xFF}}},
	{{{3, -1, -13}, 0, {2049, 898}, {0x2B, 0x94, 0xCE, 0xFF}}},
	{{{3, 58, -14}, 0, {2048, 43}, {0x18, 0x54, 0xA3, 0xFF}}},
	{{{8, 41, -28}, 0, {2048, 362}, {0x16, 0x51, 0xA1, 0xFF}}},
	{{{-5, 32, -37}, 0, {162, 975}, {0xFA, 0x18, 0x83, 0xFF}}},
	{{{12, 19, -30}, 0, {162, 975}, {0x4D, 0xD9, 0xA2, 0xFF}}},
	{{{-5, 10, -31}, 0, {162, 975}, {0x03, 0xB1, 0x9D, 0xFF}}},
	{{{3, -1, -13}, 0, {162, 975}, {0x2B, 0x94, 0xCE, 0xFF}}},
	{{{-21, 18, -31}, 0, {162, 975}, {0xBC, 0xE4, 0x98, 0xFF}}},
	{{{3, -1, -13}, 0, {1828, 338}, {0x2B, 0x94, 0xCE, 0xFF}}},
	{{{6, -2, 0}, 0, {1478, 66}, {0x39, 0x8F, 0x02, 0xFF}}},
	{{{3, -1, 13}, 0, {1828, 338}, {0x29, 0x94, 0x34, 0xFF}}},
	{{{-12, -5, 0}, 0, {918, 252}, {0x0C, 0x82, 0x00, 0xFF}}},
};

Gfx yoshi_face_1_mesh_layer_1_tri_3[] = {
	gsSPVertex(yoshi_face_1_mesh_layer_1_vtx_3 + 0, 49, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 2, 4, 0),
	gsSP2Triangles(5, 6, 7, 0, 7, 8, 5, 0),
	gsSP2Triangles(8, 9, 5, 0, 9, 8, 10, 0),
	gsSP2Triangles(11, 5, 9, 0, 5, 11, 12, 0),
	gsSP2Triangles(13, 12, 11, 0, 9, 14, 11, 0),
	gsSP2Triangles(15, 11, 14, 0, 16, 17, 6, 0),
	gsSP2Triangles(6, 18, 16, 0, 19, 20, 21, 0),
	gsSP2Triangles(22, 21, 20, 0, 23, 24, 25, 0),
	gsSP2Triangles(26, 27, 28, 0, 27, 26, 29, 0),
	gsSP2Triangles(30, 29, 26, 0, 26, 31, 30, 0),
	gsSP2Triangles(32, 30, 31, 0, 29, 30, 33, 0),
	gsSP2Triangles(34, 33, 30, 0, 35, 28, 36, 0),
	gsSP2Triangles(28, 35, 37, 0, 29, 38, 39, 0),
	gsSP2Triangles(27, 29, 39, 0, 40, 41, 42, 0),
	gsSP2Triangles(43, 42, 41, 0, 40, 42, 44, 0),
	gsSP2Triangles(45, 2, 46, 0, 47, 46, 2, 0),
	gsSP2Triangles(48, 46, 47, 0, 48, 45, 46, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_mouth_skinned_mesh_layer_1_vtx_0[3] = {
	{{{-22, 9, -1}, 0, {1081, 88}, {0x83, 0x17, 0xFF, 0xFF}}},
	{{{-32, 24, 18}, 0, {1419, 0}, {0xDB, 0xD3, 0x71, 0xFF}}},
	{{{-31, 24, -17}, 0, {1419, 2}, {0xE4, 0xCE, 0x8F, 0xFF}}},
};

Gfx yoshi_mouth_skinned_mesh_layer_1_tri_0[] = {
	gsSPVertex(yoshi_mouth_skinned_mesh_layer_1_vtx_0 + 0, 3, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_mouth_skinned_mesh_layer_1_vtx_1[17] = {
	{{{-12, -5, 0}, 0, {162, 975}, {0x0C, 0x82, 0x00, 0xFF}}},
	{{{-22, 19, 31}, 0, {191, 757}, {0xBA, 0xE4, 0x66, 0xFF}}},
	{{{-32, 24, 18}, 0, {261, 755}, {0xDB, 0xD3, 0x71, 0xFF}}},
	{{{-22, 19, 31}, 0, {224, 712}, {0xBA, 0xE4, 0x66, 0xFF}}},
	{{{-7, 10, 30}, 0, {162, 975}, {0xFF, 0xB1, 0x63, 0xFF}}},
	{{{-22, 19, 31}, 0, {162, 975}, {0xBA, 0xE4, 0x66, 0xFF}}},
	{{{-12, -5, 0}, 0, {1980, 705}, {0x0C, 0x82, 0x00, 0xFF}}},
	{{{3, -1, 13}, 0, {2000, 697}, {0x29, 0x94, 0x34, 0xFF}}},
	{{{3, -1, 13}, 0, {1257, 561}, {0x29, 0x94, 0x34, 0xFF}}},
	{{{-7, 10, 30}, 0, {1257, 561}, {0xFF, 0xB1, 0x63, 0xFF}}},
	{{{-5, 10, -31}, 0, {162, 975}, {0x03, 0xB1, 0x9D, 0xFF}}},
	{{{3, -1, -13}, 0, {162, 975}, {0x2B, 0x94, 0xCE, 0xFF}}},
	{{{-21, 18, -31}, 0, {162, 975}, {0xBC, 0xE4, 0x98, 0xFF}}},
	{{{-21, 18, -31}, 0, {281, 757}, {0xBC, 0xE4, 0x98, 0xFF}}},
	{{{3, -1, -13}, 0, {2000, 697}, {0x2B, 0x94, 0xCE, 0xFF}}},
	{{{-31, 24, -17}, 0, {197, 755}, {0xE4, 0xCE, 0x8F, 0xFF}}},
	{{{-21, 18, -31}, 0, {278, 757}, {0xBC, 0xE4, 0x98, 0xFF}}},
};

Gfx yoshi_mouth_skinned_mesh_layer_1_tri_1[] = {
	gsSPVertex(yoshi_mouth_skinned_mesh_layer_1_vtx_1 + 0, 17, 3),
	gsSPEndDisplayList(),
};

Vtx yoshi_mouth_mesh_layer_1_vtx_0[3] = {
	{{{24, 5, 14}, 0, {1443, 92}, {0x74, 0x24, 0x24, 0xFF}}},
	{{{29, 16, 1}, 0, {1255, 280}, {0x79, 0x26, 0x03, 0xFF}}},
	{{{24, 5, -14}, 0, {1443, 92}, {0x72, 0x28, 0xD9, 0xFF}}},
};

Gfx yoshi_mouth_mesh_layer_1_tri_0[] = {
	gsSPVertex(yoshi_mouth_mesh_layer_1_vtx_0 + 0, 3, 20),
	gsSP2Triangles(20, 1, 0, 0, 0, 21, 20, 0),
	gsSP2Triangles(21, 0, 22, 0, 2, 22, 0, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_mouth_mesh_layer_1_vtx_1[13] = {
	{{{24, 5, 14}, 0, {245, 717}, {0x74, 0x24, 0x24, 0xFF}}},
	{{{24, 5, 14}, 0, {195, 755}, {0x74, 0x24, 0x24, 0xFF}}},
	{{{11, 9, 16}, 0, {230, 757}, {0x19, 0x64, 0x4A, 0xFF}}},
	{{{11, 9, 16}, 0, {162, 975}, {0x19, 0x64, 0x4A, 0xFF}}},
	{{{11, 9, 16}, 0, {1980, 705}, {0x19, 0x64, 0x4A, 0xFF}}},
	{{{11, 9, 16}, 0, {1257, 561}, {0x19, 0x64, 0x4A, 0xFF}}},
	{{{24, 5, -14}, 0, {218, 749}, {0x72, 0x28, 0xD9, 0xFF}}},
	{{{11, 9, -16}, 0, {235, 740}, {0x19, 0x64, 0xB6, 0xFF}}},
	{{{11, 9, -16}, 0, {1980, 705}, {0x19, 0x64, 0xB6, 0xFF}}},
	{{{24, 5, -14}, 0, {221, 717}, {0x72, 0x28, 0xD9, 0xFF}}},
	{{{11, 9, -16}, 0, {162, 975}, {0x19, 0x64, 0xB6, 0xFF}}},
	{{{22, 21, 0}, 0, {176, 908}, {0x25, 0x79, 0xFE, 0xFF}}},
	{{{11, 9, -16}, 0, {309, 842}, {0x19, 0x64, 0xB6, 0xFF}}},
};

Gfx yoshi_mouth_mesh_layer_1_tri_1[] = {
	gsSPVertex(yoshi_mouth_mesh_layer_1_vtx_1 + 0, 13, 20),
	gsSP2Triangles(4, 5, 20, 0, 21, 22, 6, 0),
	gsSP2Triangles(7, 8, 23, 0, 24, 9, 10, 0),
	gsSP2Triangles(25, 11, 12, 0, 26, 16, 27, 0),
	gsSP2Triangles(28, 17, 9, 0, 18, 19, 29, 0),
	gsSP2Triangles(13, 14, 30, 0, 30, 15, 13, 0),
	gsSP2Triangles(3, 31, 32, 0, 31, 3, 23, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_mouth_mesh_layer_1_vtx_2[11] = {
	{{{29, 16, 1}, 0, {177, 919}, {0x79, 0x26, 0x03, 0xFF}}},
	{{{11, 9, -16}, 0, {309, 842}, {0x19, 0x64, 0xB6, 0xFF}}},
	{{{22, 21, 0}, 0, {176, 908}, {0x25, 0x79, 0xFE, 0xFF}}},
	{{{24, 5, 14}, 0, {206, 740}, {0x74, 0x24, 0x24, 0xFF}}},
	{{{29, 16, 1}, 0, {191, 755}, {0x79, 0x26, 0x03, 0xFF}}},
	{{{11, 9, 16}, 0, {294, 757}, {0x19, 0x64, 0x4A, 0xFF}}},
	{{{24, 5, -14}, 0, {269, 782}, {0x72, 0x28, 0xD9, 0xFF}}},
	{{{11, 9, -16}, 0, {271, 765}, {0x19, 0x64, 0xB6, 0xFF}}},
	{{{29, 16, 1}, 0, {118, 758}, {0x79, 0x26, 0x03, 0xFF}}},
	{{{11, 9, 16}, 0, {162, 975}, {0x19, 0x64, 0x4A, 0xFF}}},
	{{{29, 16, 1}, 0, {178, 897}, {0x79, 0x26, 0x03, 0xFF}}},
};

Gfx yoshi_mouth_mesh_layer_1_tri_2[] = {
	gsSPVertex(yoshi_mouth_mesh_layer_1_vtx_2 + 0, 11, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(6, 7, 8, 0, 9, 10, 2, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_tongue_tip_skinned_mesh_layer_1_vtx_0[8] = {
	{{{0, 0, 6}, 0, {1835, 80}, {0x15, 0xA5, 0x56, 0xFF}}},
	{{{1, -5, 0}, 0, {1871, 80}, {0x15, 0xA5, 0x56, 0xFF}}},
	{{{1, -5, 0}, 0, {1727, 80}, {0x15, 0xA5, 0xAA, 0xFF}}},
	{{{-1, 5, 0}, 0, {1799, 80}, {0xE9, 0x5B, 0x56, 0xFF}}},
	{{{0, 0, 6}, 0, {1835, 80}, {0xE9, 0x5B, 0x56, 0xFF}}},
	{{{0, 0, -6}, 0, {1763, 80}, {0xE9, 0x5B, 0xAA, 0xFF}}},
	{{{-1, 5, 0}, 0, {1799, 80}, {0xE9, 0x5B, 0xAA, 0xFF}}},
	{{{0, 0, -6}, 0, {1763, 80}, {0x15, 0xA5, 0xAA, 0xFF}}},
};

Gfx yoshi_tongue_tip_skinned_mesh_layer_1_tri_0[] = {
	gsSPVertex(yoshi_tongue_tip_skinned_mesh_layer_1_vtx_0 + 0, 8, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_tongue_tip_mesh_layer_1_vtx_0[5] = {
	{{{0, -11, 16}, 0, {1871, 80}, {0xFF, 0x81, 0xF8, 0xFF}}},
	{{{8, -4, 17}, 0, {1835, 80}, {0x7E, 0xFA, 0x12, 0xFF}}},
	{{{1, 3, 19}, 0, {1799, 80}, {0x02, 0x75, 0x32, 0xFF}}},
	{{{-7, -4, 18}, 0, {1763, 80}, {0x84, 0xFB, 0x1A, 0xFF}}},
	{{{0, -11, 16}, 0, {1727, 80}, {0xFF, 0x81, 0xF8, 0xFF}}},
};

Gfx yoshi_tongue_tip_mesh_layer_1_tri_0[] = {
	gsSPVertex(yoshi_tongue_tip_mesh_layer_1_vtx_0 + 0, 5, 8),
	gsSP2Triangles(0, 1, 8, 0, 0, 8, 9, 0),
	gsSP2Triangles(3, 4, 9, 0, 3, 9, 10, 0),
	gsSP2Triangles(5, 6, 10, 0, 5, 10, 11, 0),
	gsSP2Triangles(11, 2, 7, 0, 11, 12, 2, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_tongue_tip_mesh_layer_1_vtx_1[16] = {
	{{{8, -4, 17}, 0, {1835, 80}, {0x7E, 0xFA, 0x12, 0xFF}}},
	{{{0, -11, 16}, 0, {1871, 80}, {0xFF, 0x81, 0xF8, 0xFF}}},
	{{{0, -13, -11}, 0, {1871, 38}, {0xFF, 0x86, 0xDB, 0xFF}}},
	{{{16, 2, -8}, 0, {1835, 38}, {0x7F, 0x01, 0xF5, 0xFF}}},
	{{{-1, -5, -21}, 0, {1871, 26}, {0xFD, 0xB1, 0x9D, 0xFF}}},
	{{{9, 5, -19}, 0, {1835, 26}, {0x62, 0x12, 0xB1, 0xFF}}},
	{{{-1, 6, -25}, 0, {1799, 17}, {0xFC, 0x1E, 0x85, 0xFF}}},
	{{{0, 14, -16}, 0, {1799, 26}, {0xFF, 0x74, 0xCC, 0xFF}}},
	{{{-11, 5, -19}, 0, {1763, 26}, {0x9A, 0x13, 0xB7, 0xFF}}},
	{{{-1, -5, -21}, 0, {1727, 26}, {0xFD, 0xB1, 0x9D, 0xFF}}},
	{{{0, -13, -11}, 0, {1727, 38}, {0xFF, 0x86, 0xDB, 0xFF}}},
	{{{-16, 2, -7}, 0, {1763, 38}, {0x81, 0x02, 0xFD, 0xFF}}},
	{{{0, -11, 16}, 0, {1727, 80}, {0xFF, 0x81, 0xF8, 0xFF}}},
	{{{-7, -4, 18}, 0, {1763, 80}, {0x84, 0xFB, 0x1A, 0xFF}}},
	{{{0, 17, -4}, 0, {1799, 38}, {0x01, 0x7D, 0x17, 0xFF}}},
	{{{1, 3, 19}, 0, {1799, 80}, {0x02, 0x75, 0x32, 0xFF}}},
};

Gfx yoshi_tongue_tip_mesh_layer_1_tri_1[] = {
	gsSPVertex(yoshi_tongue_tip_mesh_layer_1_vtx_1 + 0, 16, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(3, 2, 4, 0, 3, 4, 5, 0),
	gsSP2Triangles(4, 6, 5, 0, 7, 5, 6, 0),
	gsSP2Triangles(7, 6, 8, 0, 9, 8, 6, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
	gsSP2Triangles(11, 10, 12, 0, 11, 12, 13, 0),
	gsSP2Triangles(13, 14, 11, 0, 13, 15, 14, 0),
	gsSP2Triangles(15, 3, 14, 0, 15, 0, 3, 0),
	gsSP2Triangles(14, 3, 5, 0, 14, 5, 7, 0),
	gsSP2Triangles(11, 14, 7, 0, 11, 7, 8, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_switch_option_yoshi_head_fill_mesh_layer_1_vtx_0[179] = {
	{{{47, -14, 34}, 0, {266, 792}, {0x77, 0x2A, 0x0E, 0xFF}}},
	{{{39, -24, 27}, 0, {317, 792}, {0x54, 0x58, 0x24, 0xFF}}},
	{{{46, -12, 15}, 0, {304, 762}, {0x71, 0xC6, 0xF6, 0xFF}}},
	{{{39, -24, 27}, 0, {1876, 426}, {0x54, 0x58, 0x24, 0xFF}}},
	{{{48, -45, 29}, 0, {1482, 352}, {0x67, 0xC9, 0xCE, 0xFF}}},
	{{{16, -51, 17}, 0, {1418, 130}, {0xD4, 0x8E, 0x21, 0xFF}}},
	{{{48, -45, 29}, 0, {1478, 376}, {0x67, 0xC9, 0xCE, 0xFF}}},
	{{{39, -24, 27}, 0, {1872, 448}, {0x54, 0x58, 0x24, 0xFF}}},
	{{{47, -14, 34}, 0, {1362, 556}, {0x77, 0x2A, 0x0E, 0xFF}}},
	{{{-2, -53, 47}, 0, {1792, 516}, {0xC6, 0xA5, 0x43, 0xFF}}},
	{{{-21, -44, 23}, 0, {2242, 474}, {0x93, 0xC6, 0x1D, 0xFF}}},
	{{{-10, -54, 27}, 0, {2047, 356}, {0xB6, 0x9A, 0x10, 0xFF}}},
	{{{-17, -33, 47}, 0, {215, 841}, {0x9E, 0xFB, 0x50, 0xFF}}},
	{{{-2, -53, 47}, 0, {230, 833}, {0xC6, 0xA5, 0x43, 0xFF}}},
	{{{7, -41, 59}, 0, {349, 895}, {0xF2, 0xE0, 0x7A, 0xFF}}},
	{{{-17, -33, 47}, 0, {1478, 678}, {0x9E, 0xFB, 0x50, 0xFF}}},
	{{{-2, -53, 47}, 0, {1762, 532}, {0xC6, 0xA5, 0x43, 0xFF}}},
	{{{7, -41, 59}, 0, {357, 898}, {0xF2, 0xE0, 0x7A, 0xFF}}},
	{{{-2, -53, 47}, 0, {238, 836}, {0xC6, 0xA5, 0x43, 0xFF}}},
	{{{28, -55, 48}, 0, {356, 898}, {0x28, 0xA6, 0x50, 0xFF}}},
	{{{-17, -33, 47}, 0, {1512, 682}, {0x9E, 0xFB, 0x50, 0xFF}}},
	{{{-25, -23, 17}, 0, {2402, 594}, {0x8A, 0x20, 0x23, 0xFF}}},
	{{{-2, -53, -47}, 0, {1792, 516}, {0xC7, 0xA5, 0xBD, 0xFF}}},
	{{{-10, -54, -27}, 0, {2047, 356}, {0xB4, 0x9B, 0xF3, 0xFF}}},
	{{{-21, -44, -23}, 0, {2242, 474}, {0x93, 0xC6, 0xE3, 0xFF}}},
	{{{24, -52, -17}, 0, {1418, 130}, {0xD1, 0x95, 0xCE, 0xFF}}},
	{{{8, -61, -21}, 0, {1716, 38}, {0x04, 0x84, 0x1B, 0xFF}}},
	{{{48, -45, -26}, 0, {1474, 332}, {0x66, 0xC4, 0x2E, 0xFF}}},
	{{{39, -24, -27}, 0, {266, 792}, {0x49, 0x63, 0xE1, 0xFF}}},
	{{{47, -14, -33}, 0, {325, 792}, {0x77, 0x2B, 0xF6, 0xFF}}},
	{{{46, -12, -15}, 0, {285, 762}, {0x71, 0xC7, 0x0C, 0xFF}}},
	{{{39, -24, -27}, 0, {1876, 426}, {0x49, 0x63, 0xE1, 0xFF}}},
	{{{48, -45, -26}, 0, {1482, 352}, {0x66, 0xC4, 0x2E, 0xFF}}},
	{{{48, -45, -26}, 0, {1478, 376}, {0x66, 0xC4, 0x2E, 0xFF}}},
	{{{47, -14, -33}, 0, {1362, 556}, {0x77, 0x2B, 0xF6, 0xFF}}},
	{{{39, -24, -27}, 0, {1872, 448}, {0x49, 0x63, 0xE1, 0xFF}}},
	{{{37, -32, 52}, 0, {391, 939}, {0x47, 0x05, 0x69, 0xFF}}},
	{{{48, -45, 29}, 0, {238, 858}, {0x67, 0xC9, 0xCE, 0xFF}}},
	{{{47, -14, 34}, 0, {392, 939}, {0x77, 0x2A, 0x0E, 0xFF}}},
	{{{48, -45, 29}, 0, {1474, 332}, {0x67, 0xC9, 0xCE, 0xFF}}},
	{{{8, -61, 21}, 0, {1716, 38}, {0x04, 0x87, 0xDA, 0xFF}}},
	{{{28, -55, 48}, 0, {236, 875}, {0x28, 0xA6, 0x50, 0xFF}}},
	{{{48, -45, 29}, 0, {229, 854}, {0x67, 0xC9, 0xCE, 0xFF}}},
	{{{37, -32, 52}, 0, {383, 935}, {0x47, 0x05, 0x69, 0xFF}}},
	{{{29, -61, 32}, 0, {1568, 424}, {0x2D, 0x89, 0xFA, 0xFF}}},
	{{{48, -45, 29}, 0, {1468, 378}, {0x67, 0xC9, 0xCE, 0xFF}}},
	{{{28, -55, 48}, 0, {1438, 640}, {0x28, 0xA6, 0x50, 0xFF}}},
	{{{-17, -32, -47}, 0, {1512, 682}, {0x9E, 0xFB, 0xAF, 0xFF}}},
	{{{-24, -23, -17}, 0, {2402, 594}, {0x8B, 0x21, 0xDC, 0xFF}}},
	{{{-17, -32, -47}, 0, {1496, 698}, {0x9E, 0xFB, 0xAF, 0xFF}}},
	{{{-12, -7, -38}, 0, {2272, 782}, {0xB6, 0x54, 0xC3, 0xFF}}},
	{{{-17, -32, -47}, 0, {1478, 678}, {0x9E, 0xFB, 0xAF, 0xFF}}},
	{{{-2, -53, -47}, 0, {1762, 532}, {0xC7, 0xA5, 0xBD, 0xFF}}},
	{{{-17, -32, -47}, 0, {356, 898}, {0x9E, 0xFB, 0xAF, 0xFF}}},
	{{{7, -41, -59}, 0, {357, 898}, {0xF3, 0xE0, 0x86, 0xFF}}},
	{{{-2, -53, -47}, 0, {238, 836}, {0xC7, 0xA5, 0xBD, 0xFF}}},
	{{{-8, 1, -18}, 0, {1794, 300}, {0xC4, 0x6B, 0xE0, 0xFF}}},
	{{{-24, -23, -17}, 0, {1414, 392}, {0x8B, 0x21, 0xDC, 0xFF}}},
	{{{-25, -9, 0}, 0, {1484, 36}, {0x96, 0x45, 0x00, 0xFF}}},
	{{{-8, 1, 18}, 0, {1832, 310}, {0xC4, 0x6B, 0x20, 0xFF}}},
	{{{-25, -23, 17}, 0, {1414, 392}, {0x8A, 0x20, 0x23, 0xFF}}},
	{{{-17, -33, 47}, 0, {1496, 698}, {0x9E, 0xFB, 0x50, 0xFF}}},
	{{{-12, -7, 38}, 0, {2272, 782}, {0xB6, 0x54, 0x3D, 0xFF}}},
	{{{29, -61, -32}, 0, {1568, 424}, {0x2C, 0x89, 0x04, 0xFF}}},
	{{{29, -55, -48}, 0, {1438, 640}, {0x2A, 0xA6, 0xB0, 0xFF}}},
	{{{48, -45, -26}, 0, {1468, 378}, {0x66, 0xC4, 0x2E, 0xFF}}},
	{{{48, -45, -26}, 0, {229, 854}, {0x66, 0xC4, 0x2E, 0xFF}}},
	{{{37, -32, -52}, 0, {383, 934}, {0x49, 0x05, 0x99, 0xFF}}},
	{{{47, -14, -33}, 0, {222, 865}, {0x77, 0x2B, 0xF6, 0xFF}}},
	{{{29, -55, -48}, 0, {384, 934}, {0x2A, 0xA6, 0xB0, 0xFF}}},
	{{{37, -32, -52}, 0, {391, 939}, {0x49, 0x05, 0x99, 0xFF}}},
	{{{48, -45, -26}, 0, {238, 858}, {0x66, 0xC4, 0x2E, 0xFF}}},
	{{{-2, -53, -47}, 0, {230, 833}, {0xC7, 0xA5, 0xBD, 0xFF}}},
	{{{7, -41, -59}, 0, {350, 895}, {0xF3, 0xE0, 0x86, 0xFF}}},
	{{{29, -55, -48}, 0, {217, 840}, {0x2A, 0xA6, 0xB0, 0xFF}}},
	{{{-8, 1, -18}, 0, {228, 836}, {0xC4, 0x6B, 0xE0, 0xFF}}},
	{{{8, 6, 0}, 0, {406, 931}, {0xF7, 0x7F, 0x00, 0xFF}}},
	{{{25, -4, -44}, 0, {406, 932}, {0x1D, 0x6D, 0xC5, 0xFF}}},
	{{{8, 6, 0}, 0, {188, 846}, {0xF7, 0x7F, 0x00, 0xFF}}},
	{{{24, -4, 44}, 0, {204, 839}, {0x1B, 0x6D, 0x3C, 0xFF}}},
	{{{31, 2, 0}, 0, {290, 880}, {0x27, 0x79, 0x00, 0xFF}}},
	{{{31, 2, 0}, 0, {301, 884}, {0x27, 0x79, 0x00, 0xFF}}},
	{{{24, -4, 44}, 0, {214, 844}, {0x1B, 0x6D, 0x3C, 0xFF}}},
	{{{41, -6, 18}, 0, {401, 930}, {0x54, 0x58, 0x24, 0xFF}}},
	{{{46, -12, -15}, 0, {323, 814}, {0x71, 0xC7, 0x0C, 0xFF}}},
	{{{41, -6, -18}, 0, {319, 801}, {0x54, 0x59, 0xDD, 0xFF}}},
	{{{55, -14, 1}, 0, {202, 794}, {0x7D, 0xE8, 0x01, 0xFF}}},
	{{{46, -12, -15}, 0, {283, 787}, {0x71, 0xC7, 0x0C, 0xFF}}},
	{{{47, -14, -33}, 0, {328, 793}, {0x77, 0x2B, 0xF6, 0xFF}}},
	{{{41, -6, -18}, 0, {298, 781}, {0x54, 0x59, 0xDD, 0xFF}}},
	{{{46, -12, 15}, 0, {272, 781}, {0x71, 0xC6, 0xF6, 0xFF}}},
	{{{55, -14, 1}, 0, {261, 792}, {0x7D, 0xE8, 0x01, 0xFF}}},
	{{{41, -6, 18}, 0, {335, 793}, {0x54, 0x58, 0x24, 0xFF}}},
	{{{52, -6, 0}, 0, {254, 913}, {0x59, 0x5A, 0x00, 0xFF}}},
	{{{55, -14, 1}, 0, {249, 924}, {0x7D, 0xE8, 0x01, 0xFF}}},
	{{{41, -6, -18}, 0, {345, 868}, {0x54, 0x59, 0xDD, 0xFF}}},
	{{{41, -6, 18}, 0, {239, 962}, {0x54, 0x58, 0x24, 0xFF}}},
	{{{55, -14, 1}, 0, {251, 906}, {0x7D, 0xE8, 0x01, 0xFF}}},
	{{{52, -6, 0}, 0, {248, 917}, {0x59, 0x5A, 0x00, 0xFF}}},
	{{{46, -12, 15}, 0, {264, 792}, {0x71, 0xC6, 0xF6, 0xFF}}},
	{{{41, -6, 18}, 0, {290, 792}, {0x54, 0x58, 0x24, 0xFF}}},
	{{{47, -14, 34}, 0, {287, 762}, {0x77, 0x2A, 0x0E, 0xFF}}},
	{{{31, 2, 0}, 0, {312, 889}, {0x27, 0x79, 0x00, 0xFF}}},
	{{{41, -6, 18}, 0, {411, 934}, {0x54, 0x58, 0x24, 0xFF}}},
	{{{52, -6, 0}, 0, {413, 923}, {0x59, 0x5A, 0x00, 0xFF}}},
	{{{41, -6, -18}, 0, {259, 842}, {0x54, 0x59, 0xDD, 0xFF}}},
	{{{31, 2, 0}, 0, {410, 925}, {0x27, 0x79, 0x00, 0xFF}}},
	{{{52, -6, 0}, 0, {412, 920}, {0x59, 0x5A, 0x00, 0xFF}}},
	{{{8, -61, 21}, 0, {1716, 38}, {0x04, 0x87, 0xDA, 0xFF}}},
	{{{-10, -54, 27}, 0, {2047, 356}, {0xB6, 0x9A, 0x10, 0xFF}}},
	{{{-9, -57, 13}, 0, {2047, 12}, {0xB6, 0x9A, 0x10, 0xFF}}},
	{{{11, -62, 35}, 0, {1826, 538}, {0xEE, 0x85, 0x1B, 0xFF}}},
	{{{29, -61, 32}, 0, {1568, 424}, {0x2D, 0x89, 0xFA, 0xFF}}},
	{{{48, -45, 29}, 0, {1482, 344}, {0x67, 0xC9, 0xCE, 0xFF}}},
	{{{28, -55, 48}, 0, {1474, 660}, {0x28, 0xA6, 0x50, 0xFF}}},
	{{{-2, -53, 47}, 0, {1760, 510}, {0xC6, 0xA5, 0x43, 0xFF}}},
	{{{8, -61, -21}, 0, {1716, 38}, {0x04, 0x84, 0x1B, 0xFF}}},
	{{{-9, -57, -13}, 0, {2047, 12}, {0xBC, 0x96, 0xF2, 0xFF}}},
	{{{-10, -54, -27}, 0, {2047, 356}, {0xB4, 0x9B, 0xF3, 0xFF}}},
	{{{11, -62, -35}, 0, {1826, 538}, {0xEE, 0x85, 0xE5, 0xFF}}},
	{{{-2, -53, -47}, 0, {1760, 510}, {0xC7, 0xA5, 0xBD, 0xFF}}},
	{{{29, -55, -48}, 0, {1480, 646}, {0x2A, 0xA6, 0xB0, 0xFF}}},
	{{{-2, -53, -47}, 0, {1728, 524}, {0xC7, 0xA5, 0xBD, 0xFF}}},
	{{{48, -45, -26}, 0, {1482, 344}, {0x66, 0xC4, 0x2E, 0xFF}}},
	{{{-8, 1, -18}, 0, {1798, 282}, {0xC4, 0x6B, 0xE0, 0xFF}}},
	{{{-25, -9, 0}, 0, {1484, 36}, {0x96, 0x45, 0x00, 0xFF}}},
	{{{-11, 3, 0}, 0, {1484, 36}, {0xC9, 0x73, 0x00, 0xFF}}},
	{{{-8, 1, 18}, 0, {1834, 308}, {0xC4, 0x6B, 0x20, 0xFF}}},
	{{{-11, 3, 0}, 0, {1484, 36}, {0xC9, 0x73, 0x00, 0xFF}}},
	{{{-25, -9, 0}, 0, {1484, 36}, {0x96, 0x45, 0x00, 0xFF}}},
	{{{8, 6, 0}, 0, {998, 217}, {0xF7, 0x7F, 0x00, 0xFF}}},
	{{{-8, 1, -18}, 0, {1774, 290}, {0xC4, 0x6B, 0xE0, 0xFF}}},
	{{{29, -55, -48}, 0, {238, 968}, {0x2A, 0xA6, 0xB0, 0xFF}}},
	{{{7, -41, -59}, 0, {238, 968}, {0xF3, 0xE0, 0x86, 0xFF}}},
	{{{37, -32, -52}, 0, {238, 968}, {0x49, 0x05, 0x99, 0xFF}}},
	{{{8, -18, -57}, 0, {238, 968}, {0xF0, 0x30, 0x8B, 0xFF}}},
	{{{-17, -32, -47}, 0, {238, 968}, {0x9E, 0xFB, 0xAF, 0xFF}}},
	{{{-12, -7, -38}, 0, {238, 968}, {0xB6, 0x54, 0xC3, 0xFF}}},
	{{{25, -4, -44}, 0, {238, 968}, {0x1D, 0x6D, 0xC5, 0xFF}}},
	{{{-8, 1, -18}, 0, {238, 968}, {0xC4, 0x6B, 0xE0, 0xFF}}},
	{{{47, -14, -33}, 0, {238, 968}, {0x77, 0x2B, 0xF6, 0xFF}}},
	{{{41, -6, -18}, 0, {238, 968}, {0x54, 0x59, 0xDD, 0xFF}}},
	{{{8, 6, 0}, 0, {238, 967}, {0xF7, 0x7F, 0x00, 0xFF}}},
	{{{31, 2, 0}, 0, {243, 944}, {0x27, 0x79, 0x00, 0xFF}}},
	{{{25, -4, -44}, 0, {238, 967}, {0x1D, 0x6D, 0xC5, 0xFF}}},
	{{{41, -6, -18}, 0, {238, 967}, {0x54, 0x59, 0xDD, 0xFF}}},
	{{{41, -6, 18}, 0, {238, 968}, {0x54, 0x58, 0x24, 0xFF}}},
	{{{24, -4, 44}, 0, {238, 968}, {0x1B, 0x6D, 0x3C, 0xFF}}},
	{{{47, -14, 34}, 0, {238, 968}, {0x77, 0x2A, 0x0E, 0xFF}}},
	{{{37, -32, 52}, 0, {238, 968}, {0x47, 0x05, 0x69, 0xFF}}},
	{{{8, -19, 57}, 0, {238, 968}, {0xF0, 0x2F, 0x75, 0xFF}}},
	{{{7, -41, 59}, 0, {238, 968}, {0xF2, 0xE0, 0x7A, 0xFF}}},
	{{{-17, -33, 47}, 0, {238, 968}, {0x9E, 0xFB, 0x50, 0xFF}}},
	{{{28, -55, 48}, 0, {238, 968}, {0x28, 0xA6, 0x50, 0xFF}}},
	{{{24, -4, 44}, 0, {1944, 770}, {0x1B, 0x6D, 0x3C, 0xFF}}},
	{{{-12, -7, 38}, 0, {1954, 782}, {0xB6, 0x54, 0x3D, 0xFF}}},
	{{{8, -19, 57}, 0, {1688, 734}, {0xF0, 0x2F, 0x75, 0xFF}}},
	{{{-17, -33, 47}, 0, {1462, 704}, {0x9E, 0xFB, 0x50, 0xFF}}},
	{{{-23, -43, 0}, 0, {808, 236}, {0xA6, 0x5A, 0x00, 0xFF}}},
	{{{-16, -49, -5}, 0, {840, 396}, {0xEA, 0xF9, 0x83, 0xFF}}},
	{{{-31, -51, 0}, 0, {872, 268}, {0x91, 0x3E, 0xFD, 0xFF}}},
	{{{-32, -62, 0}, 0, {872, 396}, {0x92, 0xC0, 0xFE, 0xFF}}},
	{{{-22, -66, 0}, 0, {872, 556}, {0x11, 0x82, 0x00, 0xFF}}},
	{{{-7, -58, 0}, 0, {808, 620}, {0x3A, 0x8F, 0x01, 0xFF}}},
	{{{-17, -49, 5}, 0, {840, 396}, {0xE9, 0xF9, 0x7D, 0xFF}}},
	{{{-27, -31, -5}, 0, {840, 396}, {0xEA, 0xF9, 0x83, 0xFF}}},
	{{{-23, -43, 0}, 0, {808, 236}, {0xF3, 0x82, 0x00, 0xFF}}},
	{{{-35, -42, 0}, 0, {872, 268}, {0xD3, 0x89, 0x00, 0xFF}}},
	{{{-27, -31, 5}, 0, {840, 396}, {0xE9, 0xF9, 0x7D, 0xFF}}},
	{{{-44, -35, 0}, 0, {872, 396}, {0x87, 0xDB, 0x00, 0xFF}}},
	{{{-39, -22, 0}, 0, {872, 556}, {0xA6, 0x5A, 0x00, 0xFF}}},
	{{{-27, -17, 0}, 0, {808, 620}, {0xD1, 0x76, 0x00, 0xFF}}},
	{{{-19, -7, -4}, 0, {840, 396}, {0xF4, 0x10, 0x83, 0xFF}}},
	{{{-27, -17, 0}, 0, {808, 620}, {0xAC, 0xA1, 0x00, 0xFF}}},
	{{{-36, -9, 0}, 0, {872, 556}, {0x8B, 0xCF, 0x00, 0xFF}}},
	{{{-19, -7, 4}, 0, {840, 396}, {0xF4, 0x10, 0x7D, 0xFF}}},
	{{{-34, 3, 0}, 0, {872, 396}, {0xB2, 0x64, 0x00, 0xFF}}},
	{{{-22, 5, 0}, 0, {872, 268}, {0x0B, 0x7F, 0x00, 0xFF}}},
	{{{-7, 1, 0}, 0, {808, 236}, {0x27, 0x79, 0x00, 0xFF}}},
};

Gfx yoshi_switch_option_yoshi_head_fill_mesh_layer_1_tri_0[] = {
	gsSPVertex(yoshi_switch_option_yoshi_head_fill_mesh_layer_1_vtx_0 + 0, 63, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 15, 10, 16, 0),
	gsSP2Triangles(17, 18, 19, 0, 20, 21, 10, 0),
	gsSP2Triangles(22, 23, 24, 0, 25, 26, 27, 0),
	gsSP2Triangles(28, 29, 30, 0, 31, 25, 32, 0),
	gsSP2Triangles(33, 34, 35, 0, 36, 37, 38, 0),
	gsSP2Triangles(5, 39, 40, 0, 41, 42, 43, 0),
	gsSP2Triangles(44, 45, 46, 0, 47, 24, 48, 0),
	gsSP2Triangles(49, 48, 50, 0, 51, 52, 24, 0),
	gsSP2Triangles(53, 54, 55, 0, 56, 57, 58, 0),
	gsSP2Triangles(59, 58, 60, 0, 61, 62, 21, 0),
	gsSPVertex(yoshi_switch_option_yoshi_head_fill_mesh_layer_1_vtx_0 + 63, 64, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
	gsSP2Triangles(18, 19, 20, 0, 21, 22, 23, 0),
	gsSP2Triangles(24, 25, 26, 0, 27, 28, 29, 0),
	gsSP2Triangles(30, 31, 32, 0, 33, 34, 35, 0),
	gsSP2Triangles(36, 37, 38, 0, 39, 40, 41, 0),
	gsSP2Triangles(42, 43, 44, 0, 45, 46, 47, 0),
	gsSP2Triangles(45, 48, 46, 0, 48, 45, 49, 0),
	gsSP2Triangles(50, 49, 45, 0, 49, 51, 48, 0),
	gsSP2Triangles(52, 48, 51, 0, 52, 46, 48, 0),
	gsSP2Triangles(53, 54, 55, 0, 53, 55, 56, 0),
	gsSP2Triangles(57, 56, 55, 0, 56, 0, 53, 0),
	gsSP2Triangles(0, 56, 58, 0, 59, 58, 56, 0),
	gsSP2Triangles(60, 53, 0, 0, 61, 62, 63, 0),
	gsSPVertex(yoshi_switch_option_yoshi_head_fill_mesh_layer_1_vtx_0 + 127, 52, 0),
	gsSP2Triangles(0, 1, 2, 0, 1, 0, 3, 0),
	gsSP2Triangles(3, 4, 1, 0, 5, 6, 7, 0),
	gsSP2Triangles(8, 7, 6, 0, 6, 9, 8, 0),
	gsSP2Triangles(10, 8, 9, 0, 8, 10, 11, 0),
	gsSP2Triangles(12, 11, 10, 0, 7, 8, 11, 0),
	gsSP2Triangles(7, 11, 13, 0, 14, 13, 11, 0),
	gsSP2Triangles(15, 16, 17, 0, 18, 17, 16, 0),
	gsSP2Triangles(19, 20, 21, 0, 22, 21, 20, 0),
	gsSP2Triangles(20, 23, 22, 0, 24, 22, 23, 0),
	gsSP2Triangles(25, 24, 23, 0, 22, 24, 26, 0),
	gsSP2Triangles(27, 28, 29, 0, 30, 29, 28, 0),
	gsSP2Triangles(31, 32, 33, 0, 34, 33, 32, 0),
	gsSP2Triangles(34, 32, 35, 0, 32, 36, 35, 0),
	gsSP2Triangles(37, 35, 36, 0, 35, 37, 34, 0),
	gsSP2Triangles(33, 34, 37, 0, 31, 33, 37, 0),
	gsSP2Triangles(38, 39, 40, 0, 41, 40, 39, 0),
	gsSP2Triangles(40, 41, 42, 0, 43, 42, 41, 0),
	gsSP2Triangles(44, 43, 41, 0, 44, 38, 43, 0),
	gsSP2Triangles(42, 43, 38, 0, 42, 38, 40, 0),
	gsSP2Triangles(45, 46, 47, 0, 48, 47, 46, 0),
	gsSP2Triangles(47, 48, 49, 0, 50, 49, 48, 0),
	gsSP2Triangles(48, 51, 50, 0, 51, 45, 50, 0),
	gsSP2Triangles(49, 50, 45, 0, 49, 45, 47, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_switch_option_yoshi_head_fill_mesh_layer_1_vtx_1[73] = {
	{{{28, -15, 0}, 0, {1086, 119}, {0xF7, 0x7F, 0x00, 0xFF}}},
	{{{39, -24, -27}, 0, {1424, -2}, {0x49, 0x63, 0xE1, 0xFF}}},
	{{{17, -8, 0}, 0, {1086, 0}, {0x48, 0x98, 0x00, 0xFF}}},
	{{{39, -24, 27}, 0, {636, 990}, {0x54, 0x58, 0x24, 0xFF}}},
	{{{52, -27, 30}, 0, {612, 984}, {0x13, 0x3C, 0x6E, 0xFF}}},
	{{{45, -11, 14}, 0, {616, 1006}, {0x06, 0x74, 0x33, 0xFF}}},
	{{{72, -30, 22}, 0, {582, 976}, {0x4E, 0x34, 0x56, 0xFF}}},
	{{{51, -44, 32}, 0, {610, 973}, {0x03, 0xF1, 0x7E, 0xFF}}},
	{{{39, -24, 27}, 0, {636, 989}, {0x54, 0x58, 0x24, 0xFF}}},
	{{{74, -54, 22}, 0, {578, 958}, {0x53, 0xD5, 0x56, 0xFF}}},
	{{{52, -67, 22}, 0, {608, 960}, {0x00, 0x9B, 0x4D, 0xFF}}},
	{{{16, -51, 17}, 0, {642, 960}, {0xD4, 0x8E, 0x21, 0xFF}}},
	{{{39, -24, 27}, 0, {636, 986}, {0x54, 0x58, 0x24, 0xFF}}},
	{{{35, -69, 0}, 0, {630, 944}, {0xC7, 0x8F, 0xFB, 0xFF}}},
	{{{54, -74, 0}, 0, {602, 942}, {0x06, 0x81, 0x00, 0xFF}}},
	{{{52, -67, -22}, 0, {608, 960}, {0xFE, 0x9C, 0xB2, 0xFF}}},
	{{{24, -52, -17}, 0, {642, 960}, {0xD1, 0x95, 0xCE, 0xFF}}},
	{{{17, -55, 0}, 0, {652, 954}, {0xB4, 0x9B, 0xF3, 0xFF}}},
	{{{51, -44, -32}, 0, {610, 973}, {0x00, 0xF1, 0x82, 0xFF}}},
	{{{74, -54, -22}, 0, {578, 958}, {0x53, 0xD5, 0xAA, 0xFF}}},
	{{{73, -29, -22}, 0, {582, 976}, {0x4E, 0x35, 0xAB, 0xFF}}},
	{{{52, -27, -30}, 0, {612, 984}, {0x12, 0x3C, 0x91, 0xFF}}},
	{{{39, -24, -27}, 0, {636, 989}, {0x49, 0x63, 0xE1, 0xFF}}},
	{{{45, -11, -14}, 0, {616, 1006}, {0x05, 0x75, 0xCE, 0xFF}}},
	{{{39, -24, -27}, 0, {636, 990}, {0x49, 0x63, 0xE1, 0xFF}}},
	{{{74, -18, 0}, 0, {588, 1000}, {0x4F, 0x64, 0x02, 0xFF}}},
	{{{28, -15, 0}, 0, {638, 999}, {0xF7, 0x7F, 0x00, 0xFF}}},
	{{{39, -24, -27}, 0, {638, 990}, {0x49, 0x63, 0xE1, 0xFF}}},
	{{{39, -24, 27}, 0, {638, 990}, {0x54, 0x58, 0x24, 0xFF}}},
	{{{85, -40, 0}, 0, {566, 979}, {0x7F, 0x08, 0x01, 0xFF}}},
	{{{28, -15, 0}, 0, {1086, 0}, {0xF7, 0x7F, 0x00, 0xFF}}},
	{{{17, -8, 0}, 0, {1086, 119}, {0x48, 0x98, 0x00, 0xFF}}},
	{{{39, -24, 27}, 0, {1424, -2}, {0x54, 0x58, 0x24, 0xFF}}},
	{{{46, -12, 15}, 0, {1448, 122}, {0x71, 0xC6, 0xF6, 0xFF}}},
	{{{55, -14, 1}, 0, {1260, 311}, {0x7D, 0xE8, 0x01, 0xFF}}},
	{{{46, -12, -15}, 0, {1448, 122}, {0x71, 0xC7, 0x0C, 0xFF}}},
	{{{-9, -57, 13}, 0, {688, 951}, {0xB6, 0x9A, 0x10, 0xFF}}},
	{{{-20, -49, 0}, 0, {700, 952}, {0xA4, 0xA8, 0x00, 0xFF}}},
	{{{-7, -59, 0}, 0, {684, 948}, {0xB6, 0x99, 0x00, 0xFF}}},
	{{{-9, -57, -13}, 0, {688, 951}, {0xBC, 0x96, 0xF2, 0xFF}}},
	{{{-9, -57, -13}, 0, {620, 590}, {0x98, 0x1F, 0xBE, 0xFF}}},
	{{{8, -61, -21}, 0, {192, 832}, {0x10, 0x0F, 0x83, 0xFF}}},
	{{{-5, -75, -22}, 0, {448, 474}, {0xBF, 0xDC, 0x99, 0xFF}}},
	{{{6, -76, -23}, 0, {42, 740}, {0x1D, 0xD0, 0x8E, 0xFF}}},
	{{{6, -76, -23}, 0, {662, 931}, {0x1D, 0xD0, 0x8E, 0xFF}}},
	{{{6, -87, -10}, 0, {660, 925}, {0x18, 0x85, 0xEA, 0xFF}}},
	{{{-5, -75, -22}, 0, {678, 938}, {0xBF, 0xDC, 0x99, 0xFF}}},
	{{{-6, -83, -8}, 0, {678, 926}, {0xAB, 0xA6, 0x1E, 0xFF}}},
	{{{4, -79, 0}, 0, {664, 931}, {0x05, 0xA6, 0x59, 0xFF}}},
	{{{-5, -72, 0}, 0, {678, 936}, {0x9B, 0xDE, 0x45, 0xFF}}},
	{{{-11, -70, -14}, 0, {688, 938}, {0x82, 0xF3, 0xFF, 0xFF}}},
	{{{-7, -59, 0}, 0, {684, 948}, {0x87, 0x02, 0x25, 0xFF}}},
	{{{-9, -57, -13}, 0, {688, 951}, {0x98, 0x1F, 0xBE, 0xFF}}},
	{{{6, -76, 23}, 0, {662, 931}, {0x1C, 0xCF, 0x72, 0xFF}}},
	{{{-5, -75, 22}, 0, {678, 938}, {0xBF, 0xDC, 0x67, 0xFF}}},
	{{{6, -87, 10}, 0, {660, 925}, {0x18, 0x85, 0x16, 0xFF}}},
	{{{-6, -83, 8}, 0, {678, 926}, {0xAB, 0xA7, 0xE2, 0xFF}}},
	{{{-11, -70, 13}, 0, {688, 938}, {0x82, 0xF3, 0xFF, 0xFF}}},
	{{{-9, -57, 13}, 0, {688, 951}, {0x98, 0x1F, 0x42, 0xFF}}},
	{{{-7, -59, 0}, 0, {684, 948}, {0x87, 0x03, 0xDB, 0xFF}}},
	{{{-5, -72, 0}, 0, {678, 936}, {0x9C, 0xDE, 0xBA, 0xFF}}},
	{{{4, -79, 0}, 0, {664, 931}, {0x05, 0xA6, 0xA6, 0xFF}}},
	{{{6, -76, 23}, 0, {42, 740}, {0x1C, 0xCF, 0x72, 0xFF}}},
	{{{8, -61, 21}, 0, {184, 832}, {0x15, 0x11, 0x7C, 0xFF}}},
	{{{-5, -75, 22}, 0, {448, 474}, {0xBF, 0xDC, 0x67, 0xFF}}},
	{{{-9, -57, 13}, 0, {620, 590}, {0x98, 0x1F, 0x42, 0xFF}}},
	{{{85, -40, 0}, 0, {834, 1018}, {0x7F, 0x08, 0x01, 0xFF}}},
	{{{75, -66, 0}, 0, {834, 730}, {0x51, 0x9E, 0x00, 0xFF}}},
	{{{74, -54, -22}, 0, {1154, 890}, {0x53, 0xD5, 0xAA, 0xFF}}},
	{{{74, -54, 22}, 0, {1154, 890}, {0x53, 0xD5, 0x56, 0xFF}}},
	{{{52, -67, 22}, 0, {1154, 602}, {0x00, 0x9B, 0x4D, 0xFF}}},
	{{{54, -74, 0}, 0, {834, 506}, {0x06, 0x81, 0x00, 0xFF}}},
	{{{52, -67, -22}, 0, {1154, 602}, {0xFE, 0x9C, 0xB2, 0xFF}}},
};

Gfx yoshi_switch_option_yoshi_head_fill_mesh_layer_1_tri_1[] = {
	gsSPVertex(yoshi_switch_option_yoshi_head_fill_mesh_layer_1_vtx_1 + 0, 62, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(6, 5, 4, 0, 6, 4, 7, 0),
	gsSP2Triangles(8, 7, 4, 0, 7, 9, 6, 0),
	gsSP2Triangles(7, 10, 9, 0, 10, 7, 11, 0),
	gsSP2Triangles(12, 11, 7, 0, 13, 10, 11, 0),
	gsSP2Triangles(10, 13, 14, 0, 15, 14, 13, 0),
	gsSP2Triangles(13, 16, 15, 0, 16, 13, 17, 0),
	gsSP2Triangles(11, 17, 13, 0, 18, 15, 16, 0),
	gsSP2Triangles(18, 19, 15, 0, 19, 18, 20, 0),
	gsSP2Triangles(21, 20, 18, 0, 21, 18, 22, 0),
	gsSP2Triangles(16, 22, 18, 0, 20, 21, 23, 0),
	gsSP2Triangles(24, 23, 21, 0, 20, 23, 25, 0),
	gsSP2Triangles(5, 25, 23, 0, 23, 26, 5, 0),
	gsSP2Triangles(26, 23, 27, 0, 28, 5, 26, 0),
	gsSP2Triangles(19, 20, 29, 0, 25, 29, 20, 0),
	gsSP2Triangles(29, 25, 6, 0, 5, 6, 25, 0),
	gsSP2Triangles(29, 6, 9, 0, 30, 31, 32, 0),
	gsSP2Triangles(33, 32, 31, 0, 31, 34, 33, 0),
	gsSP2Triangles(34, 31, 35, 0, 1, 35, 31, 0),
	gsSP2Triangles(36, 37, 38, 0, 39, 38, 37, 0),
	gsSP2Triangles(40, 41, 42, 0, 43, 42, 41, 0),
	gsSP2Triangles(44, 45, 46, 0, 47, 46, 45, 0),
	gsSP2Triangles(45, 48, 47, 0, 49, 47, 48, 0),
	gsSP2Triangles(49, 50, 47, 0, 50, 49, 51, 0),
	gsSP2Triangles(51, 52, 50, 0, 46, 50, 52, 0),
	gsSP2Triangles(46, 47, 50, 0, 53, 54, 55, 0),
	gsSP2Triangles(56, 55, 54, 0, 56, 54, 57, 0),
	gsSP2Triangles(58, 57, 54, 0, 57, 58, 59, 0),
	gsSP2Triangles(59, 60, 57, 0, 56, 57, 60, 0),
	gsSP2Triangles(60, 61, 56, 0, 55, 56, 61, 0),
	gsSPVertex(yoshi_switch_option_yoshi_head_fill_mesh_layer_1_vtx_1 + 62, 11, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 7, 5, 0),
	gsSP2Triangles(8, 5, 7, 0, 5, 8, 9, 0),
	gsSP2Triangles(10, 5, 9, 0, 10, 6, 5, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_switch_option_yoshi_head_fill_mesh_layer_1_vtx_2[18] = {
	{{{-8, 1, -18}, 0, {413, 850}, {0xC4, 0x6B, 0xE0, 0xFF}}},
	{{{-12, -7, -38}, 0, {229, 782}, {0xB6, 0x54, 0xC3, 0xFF}}},
	{{{-24, -23, -17}, 0, {359, 594}, {0x8B, 0x21, 0xDC, 0xFF}}},
	{{{-8, 1, 18}, 0, {445, 868}, {0xC4, 0x6B, 0x20, 0xFF}}},
	{{{24, -4, 44}, 0, {251, 780}, {0x1B, 0x6D, 0x3C, 0xFF}}},
	{{{8, 6, 0}, 0, {-239, 858}, {0xF7, 0x7F, 0x00, 0xFF}}},
	{{{-20, -49, 0}, 0, {607, 130}, {0xA4, 0xA8, 0x00, 0xFF}}},
	{{{-9, -57, 13}, 0, {4, 12}, {0xB6, 0x9A, 0x10, 0xFF}}},
	{{{-10, -54, 27}, 0, {4, 356}, {0xB6, 0x9A, 0x10, 0xFF}}},
	{{{-31, -30, 0}, 0, {601, 372}, {0x87, 0xDB, 0x00, 0xFF}}},
	{{{-21, -44, 23}, 0, {199, 474}, {0x93, 0xC6, 0x1D, 0xFF}}},
	{{{-25, -23, 17}, 0, {359, 594}, {0x8A, 0x20, 0x23, 0xFF}}},
	{{{-25, -9, 0}, 0, {677, 722}, {0x96, 0x45, 0x00, 0xFF}}},
	{{{-21, -44, -23}, 0, {199, 474}, {0x93, 0xC6, 0xE3, 0xFF}}},
	{{{-10, -54, -27}, 0, {4, 356}, {0xB4, 0x9B, 0xF3, 0xFF}}},
	{{{-9, -57, -13}, 0, {4, 12}, {0xBC, 0x96, 0xF2, 0xFF}}},
	{{{-12, -7, 38}, 0, {229, 782}, {0xB6, 0x54, 0x3D, 0xFF}}},
	{{{24, -4, 44}, 0, {259, 776}, {0x1B, 0x6D, 0x3C, 0xFF}}},
};

Gfx yoshi_switch_option_yoshi_head_fill_mesh_layer_1_tri_2[] = {
	gsSPVertex(yoshi_switch_option_yoshi_head_fill_mesh_layer_1_vtx_2 + 0, 18, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(6, 7, 8, 0, 8, 9, 6, 0),
	gsSP2Triangles(9, 8, 10, 0, 9, 10, 11, 0),
	gsSP2Triangles(11, 12, 9, 0, 2, 9, 12, 0),
	gsSP2Triangles(9, 2, 13, 0, 9, 13, 14, 0),
	gsSP2Triangles(14, 6, 9, 0, 6, 14, 15, 0),
	gsSP2Triangles(3, 11, 16, 0, 3, 16, 17, 0),
	gsSPEndDisplayList(),
};

Vtx yoshi_switch_option_yoshi_head_fill_mesh_layer_1_vtx_3[20] = {
	{{{8, -61, -21}, 0, {8, 790}, {0x10, 0x0F, 0x83, 0xFF}}},
	{{{24, -52, -17}, 0, {164, 1014}, {0x75, 0xDF, 0xDC, 0xFF}}},
	{{{14, -75, -18}, 0, {68, 300}, {0x5E, 0xCE, 0xBA, 0xFF}}},
	{{{18, -67, -8}, 0, {364, 582}, {0x79, 0xE0, 0x18, 0xFF}}},
	{{{17, -55, 0}, 0, {512, 896}, {0x74, 0xEC, 0x31, 0xFF}}},
	{{{13, -74, 0}, 0, {512, 320}, {0x61, 0xD0, 0x42, 0xFF}}},
	{{{14, -80, -6}, 0, {420, 212}, {0x5F, 0xB4, 0x24, 0xFF}}},
	{{{4, -79, 0}, 0, {512, 198}, {0x05, 0xA6, 0x59, 0xFF}}},
	{{{6, -87, -10}, 0, {360, 10}, {0x18, 0x85, 0xEA, 0xFF}}},
	{{{6, -76, -23}, 0, {-100, 172}, {0x1D, 0xD0, 0x8E, 0xFF}}},
	{{{6, -76, 23}, 0, {1124, 172}, {0x1C, 0xCF, 0x72, 0xFF}}},
	{{{14, -75, 18}, 0, {956, 300}, {0x60, 0xD8, 0x49, 0xFF}}},
	{{{8, -61, 21}, 0, {1016, 790}, {0x15, 0x11, 0x7C, 0xFF}}},
	{{{6, -87, 10}, 0, {664, 10}, {0x18, 0x85, 0x16, 0xFF}}},
	{{{14, -80, 6}, 0, {604, 212}, {0x60, 0xB4, 0xDC, 0xFF}}},
	{{{4, -79, 0}, 0, {512, 198}, {0x05, 0xA6, 0xA6, 0xFF}}},
	{{{13, -74, 0}, 0, {512, 320}, {0x5E, 0xCE, 0xBA, 0xFF}}},
	{{{18, -67, 8}, 0, {660, 582}, {0x7D, 0xEE, 0xF8, 0xFF}}},
	{{{17, -55, 0}, 0, {512, 896}, {0x7C, 0xFC, 0xE4, 0xFF}}},
	{{{16, -51, 17}, 0, {860, 1014}, {0x72, 0x00, 0x38, 0xFF}}},
};

Gfx yoshi_switch_option_yoshi_head_fill_mesh_layer_1_tri_3[] = {
	gsSPVertex(yoshi_switch_option_yoshi_head_fill_mesh_layer_1_vtx_3 + 0, 20, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
	gsSP2Triangles(1, 4, 3, 0, 5, 3, 4, 0),
	gsSP2Triangles(5, 6, 3, 0, 6, 5, 7, 0),
	gsSP2Triangles(7, 8, 6, 0, 2, 6, 8, 0),
	gsSP2Triangles(8, 9, 2, 0, 0, 2, 9, 0),
	gsSP2Triangles(2, 3, 6, 0, 10, 11, 12, 0),
	gsSP2Triangles(11, 10, 13, 0, 13, 14, 11, 0),
	gsSP2Triangles(14, 13, 15, 0, 15, 16, 14, 0),
	gsSP2Triangles(17, 14, 16, 0, 18, 17, 16, 0),
	gsSP2Triangles(18, 19, 17, 0, 11, 17, 19, 0),
	gsSP2Triangles(19, 12, 11, 0, 17, 11, 14, 0),
	gsSPEndDisplayList(),
};


Gfx mat_yoshi_yoshi_3[] = {
	gsSPSetLights1(yoshi_yoshi_3_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsDPSetTextureFilter(G_TF_POINT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, yoshi_yoshi_3_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 2047, 128),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 0, 0, 0, G_TX_WRAP | G_TX_MIRROR, 5, 0, G_TX_WRAP | G_TX_MIRROR, 6, 0),
	gsDPSetTileSize(0, 0, 0, 252, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_yoshi_yoshi_3[] = {
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsDPSetTextureFilter(G_TF_BILERP),
	gsSPEndDisplayList(),
};

Gfx mat_yoshi_yoshi_1[] = {
	gsSPSetLights1(yoshi_yoshi_1_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsDPSetTextureFilter(G_TF_POINT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, yoshi_yoshi_1_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 2047, 128),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 0, 0, 0, G_TX_WRAP | G_TX_MIRROR, 5, 0, G_TX_WRAP | G_TX_MIRROR, 6, 0),
	gsDPSetTileSize(0, 0, 0, 252, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_yoshi_yoshi_1[] = {
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsDPSetTextureFilter(G_TF_BILERP),
	gsSPEndDisplayList(),
};

Gfx mat_yoshi_yoshi_4[] = {
	gsSPSetLights1(yoshi_yoshi_4_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsDPSetTextureFilter(G_TF_POINT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, yoshi_yoshi_4_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 2047, 128),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 0, 0, 0, G_TX_WRAP | G_TX_MIRROR, 5, 0, G_TX_WRAP | G_TX_MIRROR, 6, 0),
	gsDPSetTileSize(0, 0, 0, 252, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_yoshi_yoshi_4[] = {
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsDPSetTextureFilter(G_TF_BILERP),
	gsSPEndDisplayList(),
};

Gfx mat_yoshi_metal[] = {
	gsSPSetGeometryMode(G_TEXTURE_GEN),
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, TEXEL0, 0, 0, 0, ENVIRONMENT, 0, 0, 0, TEXEL0, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsSPTexture(1984, 1984, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, yoshi_metal_shade_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_yoshi_metal[] = {
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsSPEndDisplayList(),
};

Gfx mat_yoshi_yoshi_2[] = {
	gsSPSetLights1(yoshi_yoshi_2_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsDPSetTextureFilter(G_TF_POINT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, yoshi_yoshi_2_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 2047, 128),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 0, 0, 0, G_TX_WRAP | G_TX_MIRROR, 5, 0, G_TX_WRAP | G_TX_MIRROR, 6, 0),
	gsDPSetTileSize(0, 0, 0, 252, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_yoshi_yoshi_2[] = {
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsDPSetTextureFilter(G_TF_BILERP),
	gsSPEndDisplayList(),
};

Gfx mat_yoshi_yoshi_eyes[] = {
	gsSPSetLights1(yoshi_yoshi_eyes_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsDPSetTextureFilter(G_TF_POINT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, yoshi_yoshi_eye_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 511, 512),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0, 0, 0, G_TX_WRAP | G_TX_MIRROR, 5, 0, G_TX_WRAP | G_TX_MIRROR, 4, 0),
	gsDPSetTileSize(0, 0, 0, 60, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_yoshi_yoshi_eyes[] = {
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsDPSetTextureFilter(G_TF_BILERP),
	gsSPEndDisplayList(),
};

Gfx yoshi_skl_root_mesh_layer_1[] = {
	gsSPDisplayList(mat_yoshi_yoshi_3),
	gsSPDisplayList(yoshi_skl_root_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_yoshi_yoshi_3),
	gsSPDisplayList(mat_yoshi_yoshi_1),
	gsSPDisplayList(yoshi_skl_root_mesh_layer_1_tri_1),
	gsSPDisplayList(mat_revert_yoshi_yoshi_1),
	gsSPDisplayList(mat_yoshi_yoshi_4),
	gsSPDisplayList(yoshi_skl_root_mesh_layer_1_tri_2),
	gsSPDisplayList(mat_revert_yoshi_yoshi_4),
	gsSPEndDisplayList(),
};

Gfx yoshi_skl_root_mesh_layer_1_mat_override_metal_0[] = {
	gsSPDisplayList(mat_yoshi_metal),
	gsSPDisplayList(yoshi_skl_root_mesh_layer_1_tri_0),
	gsSPDisplayList(yoshi_skl_root_mesh_layer_1_tri_1),
	gsSPDisplayList(yoshi_skl_root_mesh_layer_1_tri_2),
	gsSPDisplayList(mat_revert_yoshi_metal),
	gsSPEndDisplayList(),
};

Gfx yoshi_leg_l1_mesh_layer_1[] = {
	gsSPDisplayList(mat_yoshi_yoshi_4),
	gsSPDisplayList(yoshi_leg_l1_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_yoshi_yoshi_4),
	gsSPEndDisplayList(),
};

Gfx yoshi_leg_l1_mesh_layer_1_mat_override_metal_0[] = {
	gsSPDisplayList(mat_yoshi_metal),
	gsSPDisplayList(yoshi_leg_l1_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_yoshi_metal),
	gsSPEndDisplayList(),
};

Gfx yoshi_leg_l2_skinned_mesh_layer_1[] = {
	gsSPDisplayList(mat_yoshi_yoshi_4),
	gsSPDisplayList(yoshi_leg_l2_skinned_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_yoshi_yoshi_4),
	gsSPDisplayList(mat_yoshi_yoshi_3),
	gsSPDisplayList(yoshi_leg_l2_skinned_mesh_layer_1_tri_1),
	gsSPDisplayList(mat_revert_yoshi_yoshi_3),
	gsSPEndDisplayList(),
};

Gfx yoshi_leg_l2_skinned_mesh_layer_1_mat_override_metal_0[] = {
	gsSPDisplayList(mat_yoshi_metal),
	gsSPDisplayList(yoshi_leg_l2_skinned_mesh_layer_1_tri_0),
	gsSPDisplayList(yoshi_leg_l2_skinned_mesh_layer_1_tri_1),
	gsSPDisplayList(mat_revert_yoshi_metal),
	gsSPEndDisplayList(),
};

Gfx yoshi_leg_l2_mesh_layer_1[] = {
	gsSPDisplayList(mat_yoshi_yoshi_4),
	gsSPDisplayList(yoshi_leg_l2_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_yoshi_yoshi_4),
	gsSPDisplayList(mat_yoshi_yoshi_3),
	gsSPDisplayList(yoshi_leg_l2_mesh_layer_1_tri_1),
	gsSPDisplayList(yoshi_leg_l2_mesh_layer_1_tri_2),
	gsSPDisplayList(mat_revert_yoshi_yoshi_3),
	gsSPDisplayList(mat_yoshi_yoshi_4),
	gsSPDisplayList(yoshi_leg_l2_mesh_layer_1_tri_3),
	gsSPDisplayList(mat_revert_yoshi_yoshi_4),
	gsSPEndDisplayList(),
};

Gfx yoshi_leg_l2_mesh_layer_1_mat_override_metal_0[] = {
	gsSPDisplayList(mat_yoshi_metal),
	gsSPDisplayList(yoshi_leg_l2_mesh_layer_1_tri_0),
	gsSPDisplayList(yoshi_leg_l2_mesh_layer_1_tri_1),
	gsSPDisplayList(yoshi_leg_l2_mesh_layer_1_tri_2),
	gsSPDisplayList(yoshi_leg_l2_mesh_layer_1_tri_3),
	gsSPDisplayList(mat_revert_yoshi_metal),
	gsSPEndDisplayList(),
};

Gfx yoshi_ankle_l1_mesh_layer_1[] = {
	gsSPDisplayList(mat_yoshi_yoshi_4),
	gsSPDisplayList(yoshi_ankle_l1_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_yoshi_yoshi_4),
	gsSPDisplayList(mat_yoshi_yoshi_2),
	gsSPDisplayList(yoshi_ankle_l1_mesh_layer_1_tri_1),
	gsSPDisplayList(mat_revert_yoshi_yoshi_2),
	gsSPEndDisplayList(),
};

Gfx yoshi_ankle_l1_mesh_layer_1_mat_override_metal_0[] = {
	gsSPDisplayList(mat_yoshi_metal),
	gsSPDisplayList(yoshi_ankle_l1_mesh_layer_1_tri_0),
	gsSPDisplayList(yoshi_ankle_l1_mesh_layer_1_tri_1),
	gsSPDisplayList(mat_revert_yoshi_metal),
	gsSPEndDisplayList(),
};

Gfx yoshi_leg_r1_mesh_layer_1[] = {
	gsSPDisplayList(mat_yoshi_yoshi_4),
	gsSPDisplayList(yoshi_leg_r1_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_yoshi_yoshi_4),
	gsSPEndDisplayList(),
};

Gfx yoshi_leg_r1_mesh_layer_1_mat_override_metal_0[] = {
	gsSPDisplayList(mat_yoshi_metal),
	gsSPDisplayList(yoshi_leg_r1_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_yoshi_metal),
	gsSPEndDisplayList(),
};

Gfx yoshi_leg_r2_skinned_mesh_layer_1[] = {
	gsSPDisplayList(mat_yoshi_yoshi_4),
	gsSPDisplayList(yoshi_leg_r2_skinned_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_yoshi_yoshi_4),
	gsSPDisplayList(mat_yoshi_yoshi_3),
	gsSPDisplayList(yoshi_leg_r2_skinned_mesh_layer_1_tri_1),
	gsSPDisplayList(mat_revert_yoshi_yoshi_3),
	gsSPEndDisplayList(),
};

Gfx yoshi_leg_r2_skinned_mesh_layer_1_mat_override_metal_0[] = {
	gsSPDisplayList(mat_yoshi_metal),
	gsSPDisplayList(yoshi_leg_r2_skinned_mesh_layer_1_tri_0),
	gsSPDisplayList(yoshi_leg_r2_skinned_mesh_layer_1_tri_1),
	gsSPDisplayList(mat_revert_yoshi_metal),
	gsSPEndDisplayList(),
};

Gfx yoshi_leg_r2_mesh_layer_1[] = {
	gsSPDisplayList(mat_yoshi_yoshi_4),
	gsSPDisplayList(yoshi_leg_r2_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_yoshi_yoshi_4),
	gsSPDisplayList(mat_yoshi_yoshi_3),
	gsSPDisplayList(yoshi_leg_r2_mesh_layer_1_tri_1),
	gsSPDisplayList(mat_revert_yoshi_yoshi_3),
	gsSPDisplayList(mat_yoshi_yoshi_4),
	gsSPDisplayList(yoshi_leg_r2_mesh_layer_1_tri_2),
	gsSPDisplayList(mat_revert_yoshi_yoshi_4),
	gsSPDisplayList(mat_yoshi_yoshi_3),
	gsSPDisplayList(yoshi_leg_r2_mesh_layer_1_tri_3),
	gsSPDisplayList(mat_revert_yoshi_yoshi_3),
	gsSPEndDisplayList(),
};

Gfx yoshi_leg_r2_mesh_layer_1_mat_override_metal_0[] = {
	gsSPDisplayList(mat_yoshi_metal),
	gsSPDisplayList(yoshi_leg_r2_mesh_layer_1_tri_0),
	gsSPDisplayList(yoshi_leg_r2_mesh_layer_1_tri_1),
	gsSPDisplayList(yoshi_leg_r2_mesh_layer_1_tri_2),
	gsSPDisplayList(yoshi_leg_r2_mesh_layer_1_tri_3),
	gsSPDisplayList(mat_revert_yoshi_metal),
	gsSPEndDisplayList(),
};

Gfx yoshi_ankle_r1_mesh_layer_1[] = {
	gsSPDisplayList(mat_yoshi_yoshi_4),
	gsSPDisplayList(yoshi_ankle_r1_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_yoshi_yoshi_4),
	gsSPDisplayList(mat_yoshi_yoshi_2),
	gsSPDisplayList(yoshi_ankle_r1_mesh_layer_1_tri_1),
	gsSPDisplayList(mat_revert_yoshi_yoshi_2),
	gsSPEndDisplayList(),
};

Gfx yoshi_ankle_r1_mesh_layer_1_mat_override_metal_0[] = {
	gsSPDisplayList(mat_yoshi_metal),
	gsSPDisplayList(yoshi_ankle_r1_mesh_layer_1_tri_0),
	gsSPDisplayList(yoshi_ankle_r1_mesh_layer_1_tri_1),
	gsSPDisplayList(mat_revert_yoshi_metal),
	gsSPEndDisplayList(),
};

Gfx yoshi_spin_skinned_mesh_layer_1[] = {
	gsSPDisplayList(mat_yoshi_yoshi_3),
	gsSPDisplayList(yoshi_spin_skinned_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_yoshi_yoshi_3),
	gsSPDisplayList(mat_yoshi_yoshi_4),
	gsSPDisplayList(yoshi_spin_skinned_mesh_layer_1_tri_1),
	gsSPDisplayList(mat_revert_yoshi_yoshi_4),
	gsSPDisplayList(mat_yoshi_yoshi_1),
	gsSPDisplayList(yoshi_spin_skinned_mesh_layer_1_tri_2),
	gsSPDisplayList(mat_revert_yoshi_yoshi_1),
	gsSPEndDisplayList(),
};

Gfx yoshi_spin_skinned_mesh_layer_1_mat_override_metal_0[] = {
	gsSPDisplayList(mat_yoshi_metal),
	gsSPDisplayList(yoshi_spin_skinned_mesh_layer_1_tri_0),
	gsSPDisplayList(yoshi_spin_skinned_mesh_layer_1_tri_1),
	gsSPDisplayList(yoshi_spin_skinned_mesh_layer_1_tri_2),
	gsSPDisplayList(mat_revert_yoshi_metal),
	gsSPEndDisplayList(),
};

Gfx yoshi_spin_mesh_layer_1[] = {
	gsSPDisplayList(mat_yoshi_yoshi_3),
	gsSPDisplayList(yoshi_spin_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_yoshi_yoshi_3),
	gsSPDisplayList(mat_yoshi_yoshi_4),
	gsSPDisplayList(yoshi_spin_mesh_layer_1_tri_1),
	gsSPDisplayList(mat_revert_yoshi_yoshi_4),
	gsSPDisplayList(mat_yoshi_yoshi_1),
	gsSPDisplayList(yoshi_spin_mesh_layer_1_tri_2),
	gsSPDisplayList(yoshi_spin_mesh_layer_1_tri_3),
	gsSPDisplayList(mat_revert_yoshi_yoshi_1),
	gsSPDisplayList(mat_yoshi_yoshi_3),
	gsSPDisplayList(yoshi_spin_mesh_layer_1_tri_4),
	gsSPDisplayList(mat_revert_yoshi_yoshi_3),
	gsSPDisplayList(mat_yoshi_yoshi_2),
	gsSPDisplayList(yoshi_spin_mesh_layer_1_tri_5),
	gsSPDisplayList(mat_revert_yoshi_yoshi_2),
	gsSPEndDisplayList(),
};

Gfx yoshi_spin_mesh_layer_1_mat_override_metal_0[] = {
	gsSPDisplayList(mat_yoshi_metal),
	gsSPDisplayList(yoshi_spin_mesh_layer_1_tri_0),
	gsSPDisplayList(yoshi_spin_mesh_layer_1_tri_1),
	gsSPDisplayList(yoshi_spin_mesh_layer_1_tri_2),
	gsSPDisplayList(yoshi_spin_mesh_layer_1_tri_3),
	gsSPDisplayList(yoshi_spin_mesh_layer_1_tri_4),
	gsSPDisplayList(yoshi_spin_mesh_layer_1_tri_5),
	gsSPDisplayList(mat_revert_yoshi_metal),
	gsSPEndDisplayList(),
};

Gfx yoshi_arm_l1_skinned_mesh_layer_1[] = {
	gsSPDisplayList(mat_yoshi_yoshi_4),
	gsSPDisplayList(yoshi_arm_l1_skinned_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_yoshi_yoshi_4),
	gsSPEndDisplayList(),
};

Gfx yoshi_arm_l1_skinned_mesh_layer_1_mat_override_metal_0[] = {
	gsSPDisplayList(mat_yoshi_metal),
	gsSPDisplayList(yoshi_arm_l1_skinned_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_yoshi_metal),
	gsSPEndDisplayList(),
};

Gfx yoshi_arm_l1_mesh_layer_1[] = {
	gsSPDisplayList(mat_yoshi_yoshi_4),
	gsSPDisplayList(yoshi_arm_l1_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_yoshi_yoshi_4),
	gsSPEndDisplayList(),
};

Gfx yoshi_arm_l1_mesh_layer_1_mat_override_metal_0[] = {
	gsSPDisplayList(mat_yoshi_metal),
	gsSPDisplayList(yoshi_arm_l1_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_yoshi_metal),
	gsSPEndDisplayList(),
};

Gfx yoshi_arm_l2_skinned_mesh_layer_1[] = {
	gsSPDisplayList(mat_yoshi_yoshi_4),
	gsSPDisplayList(yoshi_arm_l2_skinned_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_yoshi_yoshi_4),
	gsSPEndDisplayList(),
};

Gfx yoshi_arm_l2_skinned_mesh_layer_1_mat_override_metal_0[] = {
	gsSPDisplayList(mat_yoshi_metal),
	gsSPDisplayList(yoshi_arm_l2_skinned_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_yoshi_metal),
	gsSPEndDisplayList(),
};

Gfx yoshi_arm_l2_mesh_layer_1[] = {
	gsSPDisplayList(mat_yoshi_yoshi_4),
	gsSPDisplayList(yoshi_arm_l2_mesh_layer_1_tri_0),
	gsSPDisplayList(yoshi_arm_l2_mesh_layer_1_tri_1),
	gsSPDisplayList(mat_revert_yoshi_yoshi_4),
	gsSPDisplayList(mat_yoshi_yoshi_3),
	gsSPDisplayList(yoshi_arm_l2_mesh_layer_1_tri_2),
	gsSPDisplayList(mat_revert_yoshi_yoshi_3),
	gsSPEndDisplayList(),
};

Gfx yoshi_arm_l2_mesh_layer_1_mat_override_metal_0[] = {
	gsSPDisplayList(mat_yoshi_metal),
	gsSPDisplayList(yoshi_arm_l2_mesh_layer_1_tri_0),
	gsSPDisplayList(yoshi_arm_l2_mesh_layer_1_tri_1),
	gsSPDisplayList(yoshi_arm_l2_mesh_layer_1_tri_2),
	gsSPDisplayList(mat_revert_yoshi_metal),
	gsSPEndDisplayList(),
};

Gfx yoshi_wrist_l1_skinned_mesh_layer_1[] = {
	gsSPDisplayList(mat_yoshi_yoshi_4),
	gsSPDisplayList(yoshi_wrist_l1_skinned_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_yoshi_yoshi_4),
	gsSPDisplayList(mat_yoshi_yoshi_3),
	gsSPDisplayList(yoshi_wrist_l1_skinned_mesh_layer_1_tri_1),
	gsSPDisplayList(mat_revert_yoshi_yoshi_3),
	gsSPDisplayList(mat_yoshi_yoshi_1),
	gsSPDisplayList(yoshi_wrist_l1_skinned_mesh_layer_1_tri_2),
	gsSPDisplayList(mat_revert_yoshi_yoshi_1),
	gsSPEndDisplayList(),
};

Gfx yoshi_wrist_l1_skinned_mesh_layer_1_mat_override_metal_0[] = {
	gsSPDisplayList(mat_yoshi_metal),
	gsSPDisplayList(yoshi_wrist_l1_skinned_mesh_layer_1_tri_0),
	gsSPDisplayList(yoshi_wrist_l1_skinned_mesh_layer_1_tri_1),
	gsSPDisplayList(yoshi_wrist_l1_skinned_mesh_layer_1_tri_2),
	gsSPDisplayList(mat_revert_yoshi_metal),
	gsSPEndDisplayList(),
};

Gfx yoshi_wrist_l1_mesh_layer_1[] = {
	gsSPDisplayList(mat_yoshi_yoshi_4),
	gsSPDisplayList(yoshi_wrist_l1_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_yoshi_yoshi_4),
	gsSPDisplayList(mat_yoshi_yoshi_3),
	gsSPDisplayList(yoshi_wrist_l1_mesh_layer_1_tri_1),
	gsSPDisplayList(mat_revert_yoshi_yoshi_3),
	gsSPDisplayList(mat_yoshi_yoshi_1),
	gsSPDisplayList(yoshi_wrist_l1_mesh_layer_1_tri_2),
	gsSPDisplayList(mat_revert_yoshi_yoshi_1),
	gsSPDisplayList(mat_yoshi_yoshi_4),
	gsSPDisplayList(yoshi_wrist_l1_mesh_layer_1_tri_3),
	gsSPDisplayList(mat_revert_yoshi_yoshi_4),
	gsSPDisplayList(mat_yoshi_yoshi_3),
	gsSPDisplayList(yoshi_wrist_l1_mesh_layer_1_tri_4),
	gsSPDisplayList(mat_revert_yoshi_yoshi_3),
	gsSPDisplayList(mat_yoshi_yoshi_1),
	gsSPDisplayList(yoshi_wrist_l1_mesh_layer_1_tri_5),
	gsSPDisplayList(mat_revert_yoshi_yoshi_1),
	gsSPEndDisplayList(),
};

Gfx yoshi_wrist_l1_mesh_layer_1_mat_override_metal_0[] = {
	gsSPDisplayList(mat_yoshi_metal),
	gsSPDisplayList(yoshi_wrist_l1_mesh_layer_1_tri_0),
	gsSPDisplayList(yoshi_wrist_l1_mesh_layer_1_tri_1),
	gsSPDisplayList(yoshi_wrist_l1_mesh_layer_1_tri_2),
	gsSPDisplayList(yoshi_wrist_l1_mesh_layer_1_tri_3),
	gsSPDisplayList(yoshi_wrist_l1_mesh_layer_1_tri_4),
	gsSPDisplayList(yoshi_wrist_l1_mesh_layer_1_tri_5),
	gsSPDisplayList(mat_revert_yoshi_metal),
	gsSPEndDisplayList(),
};

Gfx yoshi_arm_r1_skinned_mesh_layer_1[] = {
	gsSPDisplayList(mat_yoshi_yoshi_4),
	gsSPDisplayList(yoshi_arm_r1_skinned_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_yoshi_yoshi_4),
	gsSPEndDisplayList(),
};

Gfx yoshi_arm_r1_skinned_mesh_layer_1_mat_override_metal_0[] = {
	gsSPDisplayList(mat_yoshi_metal),
	gsSPDisplayList(yoshi_arm_r1_skinned_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_yoshi_metal),
	gsSPEndDisplayList(),
};

Gfx yoshi_arm_r1_mesh_layer_1[] = {
	gsSPDisplayList(mat_yoshi_yoshi_4),
	gsSPDisplayList(yoshi_arm_r1_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_yoshi_yoshi_4),
	gsSPEndDisplayList(),
};

Gfx yoshi_arm_r1_mesh_layer_1_mat_override_metal_0[] = {
	gsSPDisplayList(mat_yoshi_metal),
	gsSPDisplayList(yoshi_arm_r1_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_yoshi_metal),
	gsSPEndDisplayList(),
};

Gfx yoshi_arm_r2_skinned_mesh_layer_1[] = {
	gsSPDisplayList(mat_yoshi_yoshi_4),
	gsSPDisplayList(yoshi_arm_r2_skinned_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_yoshi_yoshi_4),
	gsSPEndDisplayList(),
};

Gfx yoshi_arm_r2_skinned_mesh_layer_1_mat_override_metal_0[] = {
	gsSPDisplayList(mat_yoshi_metal),
	gsSPDisplayList(yoshi_arm_r2_skinned_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_yoshi_metal),
	gsSPEndDisplayList(),
};

Gfx yoshi_arm_r2_mesh_layer_1[] = {
	gsSPDisplayList(mat_yoshi_yoshi_4),
	gsSPDisplayList(yoshi_arm_r2_mesh_layer_1_tri_0),
	gsSPDisplayList(yoshi_arm_r2_mesh_layer_1_tri_1),
	gsSPDisplayList(mat_revert_yoshi_yoshi_4),
	gsSPDisplayList(mat_yoshi_yoshi_3),
	gsSPDisplayList(yoshi_arm_r2_mesh_layer_1_tri_2),
	gsSPDisplayList(mat_revert_yoshi_yoshi_3),
	gsSPEndDisplayList(),
};

Gfx yoshi_arm_r2_mesh_layer_1_mat_override_metal_0[] = {
	gsSPDisplayList(mat_yoshi_metal),
	gsSPDisplayList(yoshi_arm_r2_mesh_layer_1_tri_0),
	gsSPDisplayList(yoshi_arm_r2_mesh_layer_1_tri_1),
	gsSPDisplayList(yoshi_arm_r2_mesh_layer_1_tri_2),
	gsSPDisplayList(mat_revert_yoshi_metal),
	gsSPEndDisplayList(),
};

Gfx yoshi_wrist_r1_skinned_mesh_layer_1[] = {
	gsSPDisplayList(mat_yoshi_yoshi_4),
	gsSPDisplayList(yoshi_wrist_r1_skinned_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_yoshi_yoshi_4),
	gsSPDisplayList(mat_yoshi_yoshi_3),
	gsSPDisplayList(yoshi_wrist_r1_skinned_mesh_layer_1_tri_1),
	gsSPDisplayList(mat_revert_yoshi_yoshi_3),
	gsSPDisplayList(mat_yoshi_yoshi_1),
	gsSPDisplayList(yoshi_wrist_r1_skinned_mesh_layer_1_tri_2),
	gsSPDisplayList(mat_revert_yoshi_yoshi_1),
	gsSPEndDisplayList(),
};

Gfx yoshi_wrist_r1_skinned_mesh_layer_1_mat_override_metal_0[] = {
	gsSPDisplayList(mat_yoshi_metal),
	gsSPDisplayList(yoshi_wrist_r1_skinned_mesh_layer_1_tri_0),
	gsSPDisplayList(yoshi_wrist_r1_skinned_mesh_layer_1_tri_1),
	gsSPDisplayList(yoshi_wrist_r1_skinned_mesh_layer_1_tri_2),
	gsSPDisplayList(mat_revert_yoshi_metal),
	gsSPEndDisplayList(),
};

Gfx yoshi_wrist_r1_mesh_layer_1[] = {
	gsSPDisplayList(mat_yoshi_yoshi_4),
	gsSPDisplayList(yoshi_wrist_r1_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_yoshi_yoshi_4),
	gsSPDisplayList(mat_yoshi_yoshi_3),
	gsSPDisplayList(yoshi_wrist_r1_mesh_layer_1_tri_1),
	gsSPDisplayList(mat_revert_yoshi_yoshi_3),
	gsSPDisplayList(mat_yoshi_yoshi_1),
	gsSPDisplayList(yoshi_wrist_r1_mesh_layer_1_tri_2),
	gsSPDisplayList(mat_revert_yoshi_yoshi_1),
	gsSPDisplayList(mat_yoshi_yoshi_4),
	gsSPDisplayList(yoshi_wrist_r1_mesh_layer_1_tri_3),
	gsSPDisplayList(mat_revert_yoshi_yoshi_4),
	gsSPDisplayList(mat_yoshi_yoshi_3),
	gsSPDisplayList(yoshi_wrist_r1_mesh_layer_1_tri_4),
	gsSPDisplayList(mat_revert_yoshi_yoshi_3),
	gsSPDisplayList(mat_yoshi_yoshi_1),
	gsSPDisplayList(yoshi_wrist_r1_mesh_layer_1_tri_5),
	gsSPDisplayList(mat_revert_yoshi_yoshi_1),
	gsSPEndDisplayList(),
};

Gfx yoshi_wrist_r1_mesh_layer_1_mat_override_metal_0[] = {
	gsSPDisplayList(mat_yoshi_metal),
	gsSPDisplayList(yoshi_wrist_r1_mesh_layer_1_tri_0),
	gsSPDisplayList(yoshi_wrist_r1_mesh_layer_1_tri_1),
	gsSPDisplayList(yoshi_wrist_r1_mesh_layer_1_tri_2),
	gsSPDisplayList(yoshi_wrist_r1_mesh_layer_1_tri_3),
	gsSPDisplayList(yoshi_wrist_r1_mesh_layer_1_tri_4),
	gsSPDisplayList(yoshi_wrist_r1_mesh_layer_1_tri_5),
	gsSPDisplayList(mat_revert_yoshi_metal),
	gsSPEndDisplayList(),
};

Gfx yoshi_face_1_mesh_layer_1[] = {
	gsSPDisplayList(mat_yoshi_yoshi_4),
	gsSPDisplayList(yoshi_face_1_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_yoshi_yoshi_4),
	gsSPDisplayList(mat_yoshi_yoshi_eyes),
	gsSPDisplayList(yoshi_face_1_mesh_layer_1_tri_1),
	gsSPDisplayList(mat_revert_yoshi_yoshi_eyes),
	gsSPDisplayList(mat_yoshi_yoshi_2),
	gsSPDisplayList(yoshi_face_1_mesh_layer_1_tri_2),
	gsSPDisplayList(mat_revert_yoshi_yoshi_2),
	gsSPDisplayList(mat_yoshi_yoshi_1),
	gsSPDisplayList(yoshi_face_1_mesh_layer_1_tri_3),
	gsSPDisplayList(mat_revert_yoshi_yoshi_1),
	gsSPEndDisplayList(),
};

Gfx yoshi_face_1_mesh_layer_1_mat_override_metal_0[] = {
	gsSPDisplayList(mat_yoshi_metal),
	gsSPDisplayList(yoshi_face_1_mesh_layer_1_tri_0),
	gsSPDisplayList(yoshi_face_1_mesh_layer_1_tri_1),
	gsSPDisplayList(yoshi_face_1_mesh_layer_1_tri_2),
	gsSPDisplayList(yoshi_face_1_mesh_layer_1_tri_3),
	gsSPDisplayList(mat_revert_yoshi_metal),
	gsSPEndDisplayList(),
};

Gfx yoshi_mouth_skinned_mesh_layer_1[] = {
	gsSPDisplayList(mat_yoshi_yoshi_4),
	gsSPDisplayList(yoshi_mouth_skinned_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_yoshi_yoshi_4),
	gsSPDisplayList(mat_yoshi_yoshi_1),
	gsSPDisplayList(yoshi_mouth_skinned_mesh_layer_1_tri_1),
	gsSPDisplayList(mat_revert_yoshi_yoshi_1),
	gsSPEndDisplayList(),
};

Gfx yoshi_mouth_skinned_mesh_layer_1_mat_override_metal_0[] = {
	gsSPDisplayList(mat_yoshi_metal),
	gsSPDisplayList(yoshi_mouth_skinned_mesh_layer_1_tri_0),
	gsSPDisplayList(yoshi_mouth_skinned_mesh_layer_1_tri_1),
	gsSPDisplayList(mat_revert_yoshi_metal),
	gsSPEndDisplayList(),
};

Gfx yoshi_mouth_mesh_layer_1[] = {
	gsSPDisplayList(mat_yoshi_yoshi_4),
	gsSPDisplayList(yoshi_mouth_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_yoshi_yoshi_4),
	gsSPDisplayList(mat_yoshi_yoshi_1),
	gsSPDisplayList(yoshi_mouth_mesh_layer_1_tri_1),
	gsSPDisplayList(yoshi_mouth_mesh_layer_1_tri_2),
	gsSPDisplayList(mat_revert_yoshi_yoshi_1),
	gsSPEndDisplayList(),
};

Gfx yoshi_mouth_mesh_layer_1_mat_override_metal_0[] = {
	gsSPDisplayList(mat_yoshi_metal),
	gsSPDisplayList(yoshi_mouth_mesh_layer_1_tri_0),
	gsSPDisplayList(yoshi_mouth_mesh_layer_1_tri_1),
	gsSPDisplayList(yoshi_mouth_mesh_layer_1_tri_2),
	gsSPDisplayList(mat_revert_yoshi_metal),
	gsSPEndDisplayList(),
};

Gfx yoshi_tongue_tip_skinned_mesh_layer_1[] = {
	gsSPDisplayList(mat_yoshi_yoshi_4),
	gsSPDisplayList(yoshi_tongue_tip_skinned_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_yoshi_yoshi_4),
	gsSPEndDisplayList(),
};

Gfx yoshi_tongue_tip_skinned_mesh_layer_1_mat_override_metal_0[] = {
	gsSPDisplayList(mat_yoshi_metal),
	gsSPDisplayList(yoshi_tongue_tip_skinned_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_yoshi_metal),
	gsSPEndDisplayList(),
};

Gfx yoshi_tongue_tip_mesh_layer_1[] = {
	gsSPDisplayList(mat_yoshi_yoshi_4),
	gsSPDisplayList(yoshi_tongue_tip_mesh_layer_1_tri_0),
	gsSPDisplayList(yoshi_tongue_tip_mesh_layer_1_tri_1),
	gsSPDisplayList(mat_revert_yoshi_yoshi_4),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

Gfx yoshi_tongue_tip_mesh_layer_1_mat_override_metal_0[] = {
	gsSPDisplayList(mat_yoshi_metal),
	gsSPDisplayList(yoshi_tongue_tip_mesh_layer_1_tri_0),
	gsSPDisplayList(yoshi_tongue_tip_mesh_layer_1_tri_1),
	gsSPDisplayList(mat_revert_yoshi_metal),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

Gfx yoshi_switch_option_yoshi_head_fill_mesh_layer_1[] = {
	gsSPDisplayList(mat_yoshi_yoshi_1),
	gsSPDisplayList(yoshi_switch_option_yoshi_head_fill_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_yoshi_yoshi_1),
	gsSPDisplayList(mat_yoshi_yoshi_4),
	gsSPDisplayList(yoshi_switch_option_yoshi_head_fill_mesh_layer_1_tri_1),
	gsSPDisplayList(mat_revert_yoshi_yoshi_4),
	gsSPDisplayList(mat_yoshi_yoshi_2),
	gsSPDisplayList(yoshi_switch_option_yoshi_head_fill_mesh_layer_1_tri_2),
	gsSPDisplayList(mat_revert_yoshi_yoshi_2),
	gsSPDisplayList(mat_yoshi_yoshi_eyes),
	gsSPDisplayList(yoshi_switch_option_yoshi_head_fill_mesh_layer_1_tri_3),
	gsSPDisplayList(mat_revert_yoshi_yoshi_eyes),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

Gfx yoshi_switch_option_yoshi_head_fill_mesh_layer_1_mat_override_metal_0[] = {
	gsSPDisplayList(mat_yoshi_metal),
	gsSPDisplayList(yoshi_switch_option_yoshi_head_fill_mesh_layer_1_tri_0),
	gsSPDisplayList(yoshi_switch_option_yoshi_head_fill_mesh_layer_1_tri_1),
	gsSPDisplayList(yoshi_switch_option_yoshi_head_fill_mesh_layer_1_tri_2),
	gsSPDisplayList(yoshi_switch_option_yoshi_head_fill_mesh_layer_1_tri_3),
	gsSPDisplayList(mat_revert_yoshi_metal),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

