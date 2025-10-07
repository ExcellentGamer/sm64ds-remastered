Lights1 piranha_plant_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

Texture piranha_plant[] = {
	#include "actors/piranha_plant/piranha_plant.rgba16.inc.c"
};

Vtx piranha_plant_4_vtx_0[8] = {
	{{{198, 47, 235}, 0, {-6, 1364}, {0xD0, 0x63, 0x40, 0xFF}}},
	{{{447, 148, 174}, 0, {68, 1739}, {0xEE, 0x6B, 0x42, 0xFF}}},
	{{{163, 180, 3}, 0, {236, 1364}, {0xC5, 0x6F, 0x10, 0xFF}}},
	{{{421, 246, 13}, 0, {236, 1739}, {0xF1, 0x7D, 0x13, 0xFF}}},
	{{{634, 242, 12}, 0, {236, 2020}, {0x03, 0x7E, 0x13, 0xFF}}},
	{{{447, 200, -170}, 0, {68, 1739}, {0xF0, 0x7A, 0xDF, 0xFF}}},
	{{{198, 122, -258}, 0, {-6, 1364}, {0xCE, 0x70, 0xDF, 0xFF}}},
	{{{-31, 1, 0}, 0, {236, 1020}, {0xAA, 0x5C, 0x11, 0xFF}}},
};

Gfx piranha_plant_4_tri_0[] = {
	gsSPVertex(piranha_plant_4_vtx_0 + 0, 8, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
	gsSP2Triangles(1, 4, 3, 0, 5, 3, 4, 0),
	gsSP2Triangles(5, 6, 3, 0, 2, 3, 6, 0),
	gsSP2Triangles(6, 7, 2, 0, 0, 2, 7, 0),
	gsSPEndDisplayList(),
};

Vtx piranha_plant_hand_r_4_vtx_0[8] = {
	{{{-447, 148, 174}, 0, {68, 1739}, {0x10, 0x6A, 0x43, 0xFF}}},
	{{{-198, 47, 235}, 0, {-6, 1364}, {0x31, 0x62, 0x40, 0xFF}}},
	{{{-421, 246, 13}, 0, {236, 1739}, {0x0F, 0x7D, 0x12, 0xFF}}},
	{{{-163, 180, 3}, 0, {236, 1364}, {0x3B, 0x6F, 0x0F, 0xFF}}},
	{{{31, 1, 0}, 0, {236, 1020}, {0x56, 0x5C, 0x11, 0xFF}}},
	{{{-198, 122, -258}, 0, {-6, 1364}, {0x32, 0x70, 0xE0, 0xFF}}},
	{{{-447, 200, -170}, 0, {68, 1739}, {0x12, 0x7A, 0xE0, 0xFF}}},
	{{{-634, 242, 12}, 0, {236, 2020}, {0xFD, 0x7E, 0x13, 0xFF}}},
};

Gfx piranha_plant_hand_r_4_tri_0[] = {
	gsSPVertex(piranha_plant_hand_r_4_vtx_0 + 0, 8, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
	gsSP2Triangles(1, 4, 3, 0, 5, 3, 4, 0),
	gsSP2Triangles(5, 6, 3, 0, 2, 3, 6, 0),
	gsSP2Triangles(6, 7, 2, 0, 0, 2, 7, 0),
	gsSPEndDisplayList(),
};

Vtx piranha_plant_neck1_4_vtx_0[4] = {
	{{{-84, -4, 74}, 0, {-6, 994}, {0x99, 0x1E, 0x44, 0xFF}}},
	{{{84, -4, 74}, 0, {44, 994}, {0x67, 0x1E, 0x44, 0xFF}}},
	{{{0, -4, -88}, 0, {68, 994}, {0x00, 0x11, 0x82, 0xFF}}},
	{{{-84, -4, 74}, 0, {92, 994}, {0x99, 0x1E, 0x44, 0xFF}}},
};

Gfx piranha_plant_neck1_4_tri_0[] = {
	gsSPVertex(piranha_plant_neck1_4_vtx_0 + 0, 4, 0),
	gsSPEndDisplayList(),
};

Vtx piranha_plant_neck1_2_4_vtx_0[4] = {
	{{{-59, 149, 43}, 0, {92, 972}, {0x92, 0x15, 0x3D, 0xFF}}},
	{{{0, 149, -61}, 0, {68, 971}, {0x00, 0x0D, 0x82, 0xFF}}},
	{{{59, 149, 43}, 0, {44, 972}, {0x6E, 0x15, 0x3D, 0xFF}}},
	{{{-59, 149, 43}, 0, {-6, 972}, {0x92, 0x15, 0x3D, 0xFF}}},
};

Gfx piranha_plant_neck1_2_4_tri_0[] = {
	gsSPVertex(piranha_plant_neck1_2_4_vtx_0 + 0, 4, 4),
	gsSP2Triangles(3, 4, 2, 0, 5, 2, 4, 0),
	gsSP2Triangles(5, 6, 2, 0, 1, 2, 6, 0),
	gsSP2Triangles(6, 0, 1, 0, 6, 7, 0, 0),
	gsSPEndDisplayList(),
};

Vtx piranha_plant_neck2_4_vtx_0[4] = {
	{{{-59, 149, 43}, 0, {-6, 972}, {0x92, 0x15, 0x3D, 0xFF}}},
	{{{59, 149, 43}, 0, {44, 972}, {0x6E, 0x15, 0x3D, 0xFF}}},
	{{{0, 149, -61}, 0, {68, 971}, {0x00, 0x0D, 0x82, 0xFF}}},
	{{{-59, 149, 43}, 0, {92, 972}, {0x92, 0x15, 0x3D, 0xFF}}},
};

Gfx piranha_plant_neck2_4_tri_0[] = {
	gsSPVertex(piranha_plant_neck2_4_vtx_0 + 0, 4, 0),
	gsSPEndDisplayList(),
};

Vtx piranha_plant_neck2_2_4_vtx_0[4] = {
	{{{-54, 7, 35}, 0, {92, 937}, {0x91, 0x06, 0x3E, 0xFF}}},
	{{{0, 6, -55}, 0, {68, 936}, {0x00, 0x04, 0x81, 0xFF}}},
	{{{54, 7, 35}, 0, {44, 937}, {0x6F, 0x06, 0x3E, 0xFF}}},
	{{{-54, 7, 35}, 0, {-6, 937}, {0x91, 0x06, 0x3E, 0xFF}}},
};

Gfx piranha_plant_neck2_2_4_tri_0[] = {
	gsSPVertex(piranha_plant_neck2_2_4_vtx_0 + 0, 4, 4),
	gsSP2Triangles(3, 4, 2, 0, 5, 2, 4, 0),
	gsSP2Triangles(5, 6, 2, 0, 1, 2, 6, 0),
	gsSP2Triangles(6, 0, 1, 0, 6, 7, 0, 0),
	gsSPEndDisplayList(),
};

Vtx piranha_plant_neck2_2_4_vtx_1[4] = {
	{{{45, 222, 31}, 0, {44, 913}, {0x6E, 0x04, 0x40, 0xFF}}},
	{{{-45, 222, 31}, 0, {-6, 913}, {0x92, 0x04, 0x40, 0xFF}}},
	{{{-54, 7, 35}, 0, {-6, 937}, {0x91, 0x06, 0x3E, 0xFF}}},
	{{{54, 7, 35}, 0, {44, 937}, {0x6F, 0x06, 0x3E, 0xFF}}},
};

Gfx piranha_plant_neck2_2_4_tri_1[] = {
	gsSPVertex(piranha_plant_neck2_2_4_vtx_1 + 0, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSPEndDisplayList(),
};

Vtx piranha_plant_neck3_4_vtx_0[6] = {
	{{{-45, 222, 31}, 0, {-6, 913}, {0x92, 0x04, 0x40, 0xFF}}},
	{{{-45, 222, 31}, 0, {92, 913}, {0x92, 0x04, 0x40, 0xFF}}},
	{{{45, 222, 31}, 0, {44, 913}, {0x6E, 0x04, 0x40, 0xFF}}},
	{{{54, 7, 35}, 0, {44, 937}, {0x6F, 0x06, 0x3E, 0xFF}}},
	{{{0, 6, -55}, 0, {68, 936}, {0x00, 0x04, 0x81, 0xFF}}},
	{{{-54, 7, 35}, 0, {92, 937}, {0x91, 0x06, 0x3E, 0xFF}}},
};

Gfx piranha_plant_neck3_4_tri_0[] = {
	gsSPVertex(piranha_plant_neck3_4_vtx_0 + 0, 6, 0),
	gsSPEndDisplayList(),
};

Vtx piranha_plant_neck3_2_vtx_0[4] = {
	{{{41, 188, 31}, 0, {44, 894}, {0x5D, 0xC4, 0x3E, 0xFF}}},
	{{{-41, 188, 30}, 0, {-6, 894}, {0xA3, 0xC4, 0x3E, 0xFF}}},
	{{{0, 4, -49}, 0, {68, 911}, {0x00, 0x05, 0x81, 0xFF}}},
	{{{-41, 188, 30}, 0, {92, 894}, {0xA3, 0xC4, 0x3E, 0xFF}}},
};

Gfx piranha_plant_neck3_2_tri_0[] = {
	gsSPVertex(piranha_plant_neck3_2_vtx_0 + 0, 4, 6),
	gsSP2Triangles(6, 7, 0, 0, 6, 0, 2, 0),
	gsSP2Triangles(6, 2, 8, 0, 3, 8, 2, 0),
	gsSP2Triangles(3, 4, 8, 0, 5, 8, 4, 0),
	gsSP2Triangles(8, 5, 1, 0, 1, 9, 8, 0),
	gsSPEndDisplayList(),
};

Vtx piranha_plant_neck3_2_vtx_1[7] = {
	{{{85, 293, 86}, 0, {36, 996}, {0x49, 0xB9, 0x4C, 0xFF}}},
	{{{-86, 293, 86}, 0, {12, 996}, {0xB7, 0xB9, 0x4C, 0xFF}}},
	{{{-41, 188, 30}, 0, {-6, 894}, {0xA3, 0xC4, 0x3E, 0xFF}}},
	{{{41, 188, 31}, 0, {44, 894}, {0x5D, 0xC4, 0x3E, 0xFF}}},
	{{{0, 188, -44}, 0, {68, 894}, {0x00, 0xBB, 0x95, 0xFF}}},
	{{{0, 4, -49}, 0, {68, 911}, {0x00, 0x05, 0x81, 0xFF}}},
	{{{-41, 188, 30}, 0, {92, 894}, {0xA3, 0xC4, 0x3E, 0xFF}}},
};

Gfx piranha_plant_neck3_2_tri_1[] = {
	gsSPVertex(piranha_plant_neck3_2_vtx_1 + 0, 7, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 5, 4, 3, 0),
	gsSPEndDisplayList(),
};

Vtx piranha_plant_upper_mouth_4_vtx_0[6] = {
	{{{41, 188, 31}, 0, {44, 894}, {0x5D, 0xC4, 0x3E, 0xFF}}},
	{{{0, 188, -44}, 0, {68, 894}, {0x00, 0xBB, 0x95, 0xFF}}},
	{{{85, 293, 86}, 0, {36, 996}, {0x49, 0xB9, 0x4C, 0xFF}}},
	{{{-41, 188, 30}, 0, {92, 894}, {0xA3, 0xC4, 0x3E, 0xFF}}},
	{{{-86, 293, 86}, 0, {12, 996}, {0xB7, 0xB9, 0x4C, 0xFF}}},
	{{{-41, 188, 30}, 0, {-6, 894}, {0xA3, 0xC4, 0x3E, 0xFF}}},
};

Gfx piranha_plant_upper_mouth_4_tri_0[] = {
	gsSPVertex(piranha_plant_upper_mouth_4_vtx_0 + 0, 6, 0),
	gsSPEndDisplayList(),
};

Vtx piranha_plant_upper_mouth_2_4_vtx_0[3] = {
	{{{-86, 30, -86}, 0, {-14, 996}, {0xB5, 0xB9, 0xB6, 0xFF}}},
	{{{86, 30, -85}, 0, {60, 996}, {0x4B, 0xB9, 0xB6, 0xFF}}},
	{{{-86, 30, -86}, 0, {86, 996}, {0xB5, 0xB9, 0xB6, 0xFF}}},
};

Gfx piranha_plant_upper_mouth_2_4_tri_0[] = {
	gsSPVertex(piranha_plant_upper_mouth_2_4_vtx_0 + 0, 3, 6),
	gsSP2Triangles(4, 6, 5, 0, 0, 7, 2, 0),
	gsSP2Triangles(7, 0, 1, 0, 7, 1, 8, 0),
	gsSP1Triangle(3, 8, 1, 0),
	gsSPEndDisplayList(),
};

Vtx piranha_plant_upper_mouth_2_4_vtx_1[100] = {
	{{{185, 324, -221}, 0, {290, 443}, {0x57, 0x0E, 0xA5, 0xFF}}},
	{{{164, 507, -126}, 0, {196, 132}, {0x44, 0x48, 0xB1, 0xFF}}},
	{{{258, 347, -110}, 0, {94, 370}, {0x64, 0x13, 0xB5, 0xFF}}},
	{{{185, 324, -221}, 0, {868, 28}, {0x57, 0x0E, 0xA5, 0xFF}}},
	{{{258, 347, -110}, 0, {296, 203}, {0x64, 0x13, 0xB5, 0xFF}}},
	{{{274, 165, -62}, 0, {428, 838}, {0x6F, 0xD4, 0xD5, 0xFF}}},
	{{{-93, 461, -239}, 0, {452, 785}, {0xD7, 0x44, 0x9D, 0xFF}}},
	{{{-164, 507, -126}, 0, {700, 335}, {0xBC, 0x49, 0xB1, 0xFF}}},
	{{{0, 559, -122}, 0, {214, 274}, {0x00, 0x4E, 0x9C, 0xFF}}},
	{{{132, 453, 11}, 0, {26, 825}, {0x94, 0x3E, 0x1B, 0xFF}}},
	{{{166, 473, 103}, 0, {46, 641}, {0x00, 0x75, 0x32, 0xFF}}},
	{{{166, 512, 11}, 0, {98, 825}, {0x00, 0x75, 0x32, 0xFF}}},
	{{{166, 512, 11}, 0, {62, 825}, {0x00, 0x75, 0x32, 0xFF}}},
	{{{200, 453, 11}, 0, {98, 825}, {0x6C, 0x3E, 0x1B, 0xFF}}},
	{{{274, 165, -62}, 0, {210, 967}, {0x6F, 0xD4, 0xD5, 0xFF}}},
	{{{271, 131, 0}, 0, {496, 939}, {0x6C, 0xBD, 0xFE, 0xFF}}},
	{{{176, 27, 0}, 0, {496, 557}, {0x45, 0x95, 0x01, 0xFF}}},
	{{{-274, 165, -62}, 0, {782, 967}, {0x91, 0xD4, 0xD4, 0xFF}}},
	{{{-176, 27, 0}, 0, {496, 557}, {0xBB, 0x95, 0x01, 0xFF}}},
	{{{-271, 131, 0}, 0, {496, 939}, {0x94, 0xBD, 0xFE, 0xFF}}},
	{{{0, 141, -257}, 0, {200, 748}, {0x00, 0xC9, 0x8D, 0xFF}}},
	{{{0, 31, -175}, 0, {656, 723}, {0x00, 0x98, 0xB7, 0xFF}}},
	{{{-178, 140, -202}, 0, {288, 174}, {0xB6, 0xC7, 0xAA, 0xFF}}},
	{{{-176, 27, 0}, 0, {758, -28}, {0xBB, 0x95, 0x01, 0xFF}}},
	{{{-176, 27, 0}, 0, {656, 721}, {0xBB, 0x95, 0x01, 0xFF}}},
	{{{-274, 165, -62}, 0, {570, 471}, {0x91, 0xD4, 0xD4, 0xFF}}},
	{{{-178, 140, -202}, 0, {294, 523}, {0xB6, 0xC7, 0xAA, 0xFF}}},
	{{{-185, 324, -221}, 0, {262, 207}, {0xA9, 0x0E, 0xA5, 0xFF}}},
	{{{-258, 347, -110}, 0, {480, 160}, {0x9C, 0x13, 0xB4, 0xFF}}},
	{{{0, 591, 20}, 0, {496, 915}, {0xFF, 0x30, 0x76, 0xFF}}},
	{{{-239, 490, 12}, 0, {334, 1055}, {0xBA, 0x30, 0x5E, 0xFF}}},
	{{{239, 490, 12}, 0, {658, 1055}, {0x47, 0x2F, 0x5E, 0xFF}}},
	{{{268, 338, 17}, 0, {738, 1339}, {0x38, 0x02, 0x72, 0xFF}}},
	{{{-277, 338, 17}, 0, {254, 1371}, {0xC1, 0x03, 0x6E, 0xFF}}},
	{{{271, 131, 0}, 0, {742, 1500}, {0x6C, 0xBD, 0xFE, 0xFF}}},
	{{{-271, 131, 0}, 0, {250, 1500}, {0x94, 0xBD, 0xFE, 0xFF}}},
	{{{-93, 461, -239}, 0, {262, 83}, {0xD7, 0x44, 0x9D, 0xFF}}},
	{{{-185, 324, -221}, 0, {372, 645}, {0xA9, 0x0E, 0xA5, 0xFF}}},
	{{{-164, 507, -126}, 0, {620, 19}, {0xBC, 0x49, 0xB1, 0xFF}}},
	{{{-258, 347, -110}, 0, {724, 652}, {0x9C, 0x13, 0xB4, 0xFF}}},
	{{{-93, 461, -239}, 0, {792, 539}, {0xD7, 0x44, 0x9D, 0xFF}}},
	{{{0, 559, -122}, 0, {556, 112}, {0x00, 0x4E, 0x9C, 0xFF}}},
	{{{93, 461, -239}, 0, {382, 533}, {0x29, 0x44, 0x9D, 0xFF}}},
	{{{164, 507, -126}, 0, {232, 261}, {0x44, 0x48, 0xB1, 0xFF}}},
	{{{164, 507, -126}, 0, {360, -113}, {0x44, 0x48, 0xB1, 0xFF}}},
	{{{185, 324, -221}, 0, {314, 490}, {0x57, 0x0E, 0xA5, 0xFF}}},
	{{{93, 461, -239}, 0, {634, 135}, {0x29, 0x44, 0x9D, 0xFF}}},
	{{{68, 306, -289}, 0, {732, 607}, {0x1E, 0x03, 0x85, 0xFF}}},
	{{{256, 347, 10}, 0, {98, 825}, {0x36, 0x6A, 0x2D, 0xFF}}},
	{{{222, 368, 2}, 0, {62, 825}, {0x00, 0x75, 0x32, 0xFF}}},
	{{{222, 328, 94}, 0, {46, 641}, {0x00, 0x75, 0x32, 0xFF}}},
	{{{187, 347, 10}, 0, {26, 825}, {0xCA, 0x6A, 0x2D, 0xFF}}},
	{{{-256, 347, 10}, 0, {98, 825}, {0xCA, 0x6A, 0x2D, 0xFF}}},
	{{{-222, 328, 94}, 0, {46, 641}, {0x00, 0x75, 0x32, 0xFF}}},
	{{{-222, 368, 2}, 0, {62, 825}, {0x00, 0x75, 0x32, 0xFF}}},
	{{{-187, 347, 10}, 0, {26, 825}, {0x36, 0x6A, 0x2D, 0xFF}}},
	{{{-200, 453, 11}, 0, {98, 825}, {0x94, 0x3E, 0x1B, 0xFF}}},
	{{{-166, 473, 103}, 0, {46, 641}, {0x00, 0x75, 0x32, 0xFF}}},
	{{{-166, 512, 11}, 0, {62, 825}, {0x00, 0x75, 0x32, 0xFF}}},
	{{{-132, 453, 11}, 0, {26, 825}, {0x6C, 0x3E, 0x1B, 0xFF}}},
	{{{-34, 531, 10}, 0, {98, 825}, {0x94, 0x3E, 0x1B, 0xFF}}},
	{{{0, 550, 102}, 0, {46, 641}, {0x00, 0x75, 0x32, 0xFF}}},
	{{{0, 590, 10}, 0, {62, 825}, {0x00, 0x75, 0x32, 0xFF}}},
	{{{34, 531, 10}, 0, {26, 825}, {0x6C, 0x3E, 0x1B, 0xFF}}},
	{{{271, 131, 0}, 0, {46, 641}, {0x6C, 0xBD, 0xFE, 0xFF}}},
	{{{274, 165, -62}, 0, {44, 824}, {0x6F, 0xD4, 0xD5, 0xFF}}},
	{{{313, 351, -40}, 0, {46, 747}, {0x7E, 0x10, 0xFD, 0xFF}}},
	{{{258, 347, -110}, 0, {44, 824}, {0x64, 0x13, 0xB5, 0xFF}}},
	{{{237, 515, -42}, 0, {46, 747}, {0x66, 0x48, 0xE6, 0xFF}}},
	{{{164, 507, -126}, 0, {44, 824}, {0x44, 0x48, 0xB1, 0xFF}}},
	{{{161, 593, -35}, 0, {46, 747}, {0x3F, 0x6D, 0x0C, 0xFF}}},
	{{{1, 622, -92}, 0, {46, 786}, {0xFF, 0x66, 0xB4, 0xFF}}},
	{{{0, 559, -122}, 0, {44, 824}, {0x00, 0x4E, 0x9C, 0xFF}}},
	{{{-164, 507, -126}, 0, {44, 824}, {0xBC, 0x49, 0xB1, 0xFF}}},
	{{{-160, 590, -35}, 0, {46, 747}, {0xC1, 0x6E, 0x0C, 0xFF}}},
	{{{-237, 515, -42}, 0, {46, 747}, {0x9C, 0x4A, 0xE7, 0xFF}}},
	{{{-258, 347, -110}, 0, {44, 824}, {0x9C, 0x13, 0xB4, 0xFF}}},
	{{{-315, 351, -40}, 0, {46, 747}, {0x82, 0x10, 0xF8, 0xFF}}},
	{{{-274, 165, -62}, 0, {44, 824}, {0x91, 0xD4, 0xD4, 0xFF}}},
	{{{-271, 131, 0}, 0, {46, 641}, {0x94, 0xBD, 0xFE, 0xFF}}},
	{{{-277, 338, 17}, 0, {44, 788}, {0xC1, 0x03, 0x6E, 0xFF}}},
	{{{-239, 490, 12}, 0, {46, 641}, {0xBA, 0x30, 0x5E, 0xFF}}},
	{{{0, 591, 20}, 0, {44, 737}, {0xFF, 0x30, 0x76, 0xFF}}},
	{{{0, 639, -21}, 0, {46, 747}, {0xFF, 0x79, 0x28, 0xFF}}},
	{{{239, 490, 12}, 0, {46, 641}, {0x47, 0x2F, 0x5E, 0xFF}}},
	{{{268, 338, 17}, 0, {44, 788}, {0x38, 0x02, 0x72, 0xFF}}},
	{{{178, 140, -202}, 0, {472, 345}, {0x4A, 0xC7, 0xAA, 0xFF}}},
	{{{176, 27, 0}, 0, {356, 612}, {0x45, 0x95, 0x01, 0xFF}}},
	{{{0, 31, -175}, 0, {642, 557}, {0x00, 0x98, 0xB7, 0xFF}}},
	{{{274, 165, -62}, 0, {284, 348}, {0x6F, 0xD4, 0xD5, 0xFF}}},
	{{{185, 324, -221}, 0, {454, 100}, {0x57, 0x0E, 0xA5, 0xFF}}},
	{{{68, 306, -289}, 0, {618, 85}, {0x1E, 0x03, 0x85, 0xFF}}},
	{{{0, 141, -257}, 0, {714, 343}, {0x00, 0xC9, 0x8D, 0xFF}}},
	{{{0, 141, -257}, 0, {430, 698}, {0x00, 0xC9, 0x8D, 0xFF}}},
	{{{-178, 140, -202}, 0, {722, 709}, {0xB6, 0xC7, 0xAA, 0xFF}}},
	{{{-68, 306, -289}, 0, {498, 384}, {0xE2, 0x03, 0x85, 0xFF}}},
	{{{-185, 324, -221}, 0, {736, 346}, {0xA9, 0x0E, 0xA5, 0xFF}}},
	{{{-93, 461, -239}, 0, {578, 80}, {0xD7, 0x44, 0x9D, 0xFF}}},
	{{{93, 461, -239}, 0, {318, 75}, {0x29, 0x44, 0x9D, 0xFF}}},
	{{{68, 306, -289}, 0, {296, 374}, {0x1E, 0x03, 0x85, 0xFF}}},
};

Gfx piranha_plant_upper_mouth_2_4_tri_1[] = {
	gsSPVertex(piranha_plant_upper_mouth_2_4_vtx_1 + 0, 64, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
	gsSP2Triangles(12, 10, 13, 0, 14, 15, 16, 0),
	gsSP2Triangles(17, 18, 19, 0, 20, 21, 22, 0),
	gsSP2Triangles(23, 22, 21, 0, 24, 25, 26, 0),
	gsSP2Triangles(27, 26, 25, 0, 27, 25, 28, 0),
	gsSP2Triangles(29, 30, 31, 0, 32, 31, 30, 0),
	gsSP2Triangles(30, 33, 32, 0, 34, 32, 33, 0),
	gsSP2Triangles(33, 35, 34, 0, 36, 37, 38, 0),
	gsSP2Triangles(39, 38, 37, 0, 40, 41, 42, 0),
	gsSP2Triangles(43, 42, 41, 0, 44, 45, 46, 0),
	gsSP2Triangles(47, 46, 45, 0, 48, 49, 50, 0),
	gsSP2Triangles(51, 50, 49, 0, 52, 53, 54, 0),
	gsSP2Triangles(55, 54, 53, 0, 56, 57, 58, 0),
	gsSP2Triangles(59, 58, 57, 0, 60, 61, 62, 0),
	gsSP1Triangle(63, 62, 61, 0),
	gsSPVertex(piranha_plant_upper_mouth_2_4_vtx_1 + 64, 36, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
	gsSP2Triangles(2, 3, 4, 0, 5, 4, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 7, 6, 5, 0),
	gsSP2Triangles(5, 8, 7, 0, 9, 7, 8, 0),
	gsSP2Triangles(7, 9, 10, 0, 11, 10, 9, 0),
	gsSP2Triangles(9, 12, 11, 0, 13, 11, 12, 0),
	gsSP2Triangles(12, 14, 13, 0, 15, 13, 14, 0),
	gsSP2Triangles(15, 16, 13, 0, 17, 13, 16, 0),
	gsSP2Triangles(13, 17, 11, 0, 10, 11, 17, 0),
	gsSP2Triangles(17, 18, 10, 0, 19, 10, 18, 0),
	gsSP2Triangles(19, 18, 6, 0, 20, 6, 18, 0),
	gsSP2Triangles(6, 20, 4, 0, 2, 4, 20, 0),
	gsSP2Triangles(20, 21, 2, 0, 0, 2, 21, 0),
	gsSP2Triangles(6, 7, 19, 0, 10, 19, 7, 0),
	gsSP2Triangles(22, 23, 24, 0, 23, 22, 25, 0),
	gsSP2Triangles(26, 25, 22, 0, 26, 22, 27, 0),
	gsSP2Triangles(28, 27, 22, 0, 22, 24, 28, 0),
	gsSP2Triangles(29, 30, 31, 0, 32, 31, 30, 0),
	gsSP2Triangles(31, 32, 33, 0, 34, 31, 33, 0),
	gsSP2Triangles(34, 35, 31, 0, 29, 31, 35, 0),
	gsSPEndDisplayList(),
};

Vtx piranha_plant_lower_mouth_4_vtx_0[15] = {
	{{{-271, 131, 0}, 0, {46, 641}, {0x94, 0xBD, 0xFE, 0xFF}}},
	{{{271, 131, 0}, 0, {46, 641}, {0x6C, 0xBD, 0xFE, 0xFF}}},
	{{{-176, 27, 0}, 0, {326, 592}, {0xBB, 0x95, 0x01, 0xFF}}},
	{{{-271, 131, 0}, 0, {496, 939}, {0x94, 0xBD, 0xFE, 0xFF}}},
	{{{-176, 27, 0}, 0, {496, 557}, {0xBB, 0x95, 0x01, 0xFF}}},
	{{{-271, 131, 0}, 0, {250, 1500}, {0x94, 0xBD, 0xFE, 0xFF}}},
	{{{176, 27, 0}, 0, {756, 303}, {0x45, 0x95, 0x01, 0xFF}}},
	{{{-176, 27, 0}, 0, {438, 56}, {0xBB, 0x95, 0x01, 0xFF}}},
	{{{176, 27, 0}, 0, {496, 557}, {0x45, 0x95, 0x01, 0xFF}}},
	{{{271, 131, 0}, 0, {496, 939}, {0x6C, 0xBD, 0xFE, 0xFF}}},
	{{{176, 27, 0}, 0, {40, 221}, {0x45, 0x95, 0x01, 0xFF}}},
	{{{271, 131, 0}, 0, {742, 1500}, {0x6C, 0xBD, 0xFE, 0xFF}}},
	{{{-176, 27, 0}, 0, {872, 252}, {0xBB, 0x95, 0x01, 0xFF}}},
	{{{0, 31, -175}, 0, {362, 22}, {0x00, 0x98, 0xB7, 0xFF}}},
	{{{176, 27, 0}, 0, {216, 830}, {0x45, 0x95, 0x01, 0xFF}}},
};

Gfx piranha_plant_lower_mouth_4_tri_0[] = {
	gsSPVertex(piranha_plant_lower_mouth_4_vtx_0 + 0, 15, 0),
	gsSPEndDisplayList(),
};

Vtx piranha_plant_lower_mouth_2_4_vtx_0[21] = {
	{{{-274, 165, 69}, 0, {210, 967}, {0x94, 0xD1, 0x30, 0xFF}}},
	{{{0, -29, 0}, 0, {168, -113}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{0, 31, 175}, 0, {16, 268}, {0x00, 0x98, 0x49, 0xFF}}},
	{{{274, 165, 69}, 0, {782, 967}, {0x6C, 0xD1, 0x30, 0xFF}}},
	{{{152, 135, 200}, 0, {444, 80}, {0x43, 0xC6, 0x5B, 0xFF}}},
	{{{274, 165, 69}, 0, {216, -31}, {0x6C, 0xD1, 0x30, 0xFF}}},
	{{{152, 135, 200}, 0, {400, -14}, {0x43, 0xC6, 0x5B, 0xFF}}},
	{{{0, 31, 175}, 0, {296, 421}, {0x00, 0x98, 0x49, 0xFF}}},
	{{{0, -29, 0}, 0, {588, 678}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{273, 351, -17}, 0, {734, 1706}, {0x42, 0x07, 0x94, 0xFF}}},
	{{{-273, 351, -17}, 0, {258, 1705}, {0xBE, 0x0C, 0x94, 0xFF}}},
	{{{0, -29, 0}, 0, {544, 678}, {0x00, 0x81, 0x00, 0xFF}}},
	{{{-273, 351, -17}, 0, {44, 792}, {0xBE, 0x0C, 0x94, 0xFF}}},
	{{{-314, 351, 53}, 0, {46, 747}, {0x84, 0x14, 0x10, 0xFF}}},
	{{{-274, 165, 69}, 0, {44, 824}, {0x94, 0xD1, 0x30, 0xFF}}},
	{{{273, 351, -17}, 0, {44, 792}, {0x42, 0x07, 0x94, 0xFF}}},
	{{{314, 351, 53}, 0, {46, 747}, {0x7D, 0x0F, 0x10, 0xFF}}},
	{{{274, 165, 69}, 0, {44, 824}, {0x6C, 0xD1, 0x30, 0xFF}}},
	{{{0, 31, 175}, 0, {658, 551}, {0x00, 0x98, 0x49, 0xFF}}},
	{{{-152, 135, 200}, 0, {488, 356}, {0xBD, 0xC6, 0x5B, 0xFF}}},
	{{{-274, 165, 69}, 0, {252, 341}, {0x94, 0xD1, 0x30, 0xFF}}},
};

Gfx piranha_plant_lower_mouth_2_4_tri_0[] = {
	gsSPVertex(piranha_plant_lower_mouth_2_4_vtx_0 + 0, 21, 15),
	gsSP2Triangles(15, 3, 4, 0, 7, 16, 17, 0),
	gsSP2Triangles(18, 8, 9, 0, 19, 10, 20, 0),
	gsSP2Triangles(21, 22, 6, 0, 23, 6, 22, 0),
	gsSP2Triangles(24, 11, 5, 0, 5, 25, 24, 0),
	gsSP2Triangles(12, 13, 26, 0, 14, 26, 13, 0),
	gsSP2Triangles(27, 0, 28, 0, 29, 28, 0, 0),
	gsSP2Triangles(30, 31, 1, 0, 32, 1, 31, 0),
	gsSP2Triangles(2, 33, 34, 0, 2, 34, 35, 0),
	gsSPEndDisplayList(),
};

Vtx piranha_plant_lower_mouth_2_4_vtx_1[76] = {
	{{{-185, 324, 221}, 0, {236, 580}, {0xB0, 0x08, 0x62, 0xFF}}},
	{{{0, 306, 289}, 0, {902, 533}, {0x00, 0xFF, 0x7F, 0xFF}}},
	{{{-93, 464, 240}, 0, {436, -15}, {0xD6, 0x43, 0x63, 0xFF}}},
	{{{-185, 324, 221}, 0, {836, 120}, {0xB0, 0x08, 0x62, 0xFF}}},
	{{{-261, 346, 110}, 0, {500, 89}, {0x9F, 0x14, 0x4F, 0xFF}}},
	{{{-274, 165, 69}, 0, {518, 697}, {0x94, 0xD1, 0x30, 0xFF}}},
	{{{-273, 351, -17}, 0, {44, 792}, {0xBE, 0x0C, 0x94, 0xFF}}},
	{{{-314, 351, 53}, 0, {46, 747}, {0x84, 0x14, 0x10, 0xFF}}},
	{{{-225, 503, 3}, 0, {46, 641}, {0xD0, 0x24, 0x90, 0xFF}}},
	{{{-245, 517, 25}, 0, {46, 747}, {0x97, 0x45, 0xEE, 0xFF}}},
	{{{-261, 346, 110}, 0, {44, 824}, {0x9F, 0x14, 0x4F, 0xFF}}},
	{{{-274, 165, 69}, 0, {44, 824}, {0x94, 0xD1, 0x30, 0xFF}}},
	{{{-169, 497, 126}, 0, {44, 824}, {0xB8, 0x45, 0x4E, 0xFF}}},
	{{{-156, 601, 35}, 0, {46, 747}, {0xBE, 0x6B, 0xF0, 0xFF}}},
	{{{0, 632, 95}, 0, {46, 786}, {0x00, 0x67, 0x4A, 0xFF}}},
	{{{0, 559, 123}, 0, {44, 824}, {0x00, 0x4A, 0x67, 0xFF}}},
	{{{169, 497, 126}, 0, {44, 824}, {0x44, 0x45, 0x52, 0xFF}}},
	{{{156, 601, 35}, 0, {46, 747}, {0x3D, 0x6F, 0xF5, 0xFF}}},
	{{{245, 517, 46}, 0, {46, 747}, {0x66, 0x47, 0x19, 0xFF}}},
	{{{261, 346, 110}, 0, {44, 824}, {0x60, 0x12, 0x51, 0xFF}}},
	{{{314, 351, 53}, 0, {46, 747}, {0x7D, 0x0F, 0x10, 0xFF}}},
	{{{274, 165, 69}, 0, {44, 824}, {0x6C, 0xD1, 0x30, 0xFF}}},
	{{{230, 506, -10}, 0, {46, 641}, {0x41, 0x30, 0x9E, 0xFF}}},
	{{{273, 351, -17}, 0, {44, 792}, {0x42, 0x07, 0x94, 0xFF}}},
	{{{0, 591, -19}, 0, {44, 785}, {0xFE, 0x28, 0x88, 0xFF}}},
	{{{0, 639, 21}, 0, {46, 747}, {0x00, 0x75, 0xD0, 0xFF}}},
	{{{0, 591, -19}, 0, {496, 2059}, {0xFE, 0x28, 0x88, 0xFF}}},
	{{{230, 506, -10}, 0, {692, 1937}, {0x41, 0x30, 0x9E, 0xFF}}},
	{{{-225, 503, 3}, 0, {310, 1923}, {0xD0, 0x24, 0x90, 0xFF}}},
	{{{-273, 351, -17}, 0, {258, 1705}, {0xBE, 0x0C, 0x94, 0xFF}}},
	{{{273, 351, -17}, 0, {734, 1706}, {0x42, 0x07, 0x94, 0xFF}}},
	{{{169, 497, 126}, 0, {450, 26}, {0x44, 0x45, 0x52, 0xFF}}},
	{{{185, 324, 221}, 0, {274, 333}, {0x50, 0x08, 0x62, 0xFF}}},
	{{{261, 346, 110}, 0, {456, 346}, {0x60, 0x12, 0x51, 0xFF}}},
	{{{274, 165, 69}, 0, {466, 611}, {0x6C, 0xD1, 0x30, 0xFF}}},
	{{{0, 139, 258}, 0, {712, 361}, {0x00, 0xCF, 0x75, 0xFF}}},
	{{{-152, 135, 200}, 0, {488, 356}, {0xBD, 0xC6, 0x5B, 0xFF}}},
	{{{0, 31, 175}, 0, {658, 551}, {0x00, 0x98, 0x49, 0xFF}}},
	{{{0, 306, 289}, 0, {732, 107}, {0x00, 0xFF, 0x7F, 0xFF}}},
	{{{-185, 324, 221}, 0, {460, 67}, {0xB0, 0x08, 0x62, 0xFF}}},
	{{{-274, 165, 69}, 0, {252, 341}, {0x94, 0xD1, 0x30, 0xFF}}},
	{{{0, 306, 289}, 0, {-52, 60}, {0x00, 0xFF, 0x7F, 0xFF}}},
	{{{0, 139, 258}, 0, {372, 536}, {0x00, 0xCF, 0x75, 0xFF}}},
	{{{152, 135, 200}, 0, {780, -12}, {0x43, 0xC6, 0x5B, 0xFF}}},
	{{{0, 31, 175}, 0, {718, 830}, {0x00, 0x98, 0x49, 0xFF}}},
	{{{0, 306, 289}, 0, {258, 662}, {0x00, 0xFF, 0x7F, 0xFF}}},
	{{{152, 135, 200}, 0, {788, 416}, {0x43, 0xC6, 0x5B, 0xFF}}},
	{{{185, 324, 221}, 0, {366, 130}, {0x50, 0x08, 0x62, 0xFF}}},
	{{{274, 165, 69}, 0, {746, -235}, {0x6C, 0xD1, 0x30, 0xFF}}},
	{{{-185, 324, 221}, 0, {764, 188}, {0xB0, 0x08, 0x62, 0xFF}}},
	{{{-169, 497, 126}, 0, {518, 342}, {0xB8, 0x45, 0x4E, 0xFF}}},
	{{{-261, 346, 110}, 0, {714, 447}, {0x9F, 0x14, 0x4F, 0xFF}}},
	{{{-93, 464, 240}, 0, {592, 40}, {0xD6, 0x43, 0x63, 0xFF}}},
	{{{0, 559, 123}, 0, {366, 18}, {0x00, 0x4A, 0x67, 0xFF}}},
	{{{-117, 505, 1}, 0, {98, 825}, {0x92, 0x3B, 0xE7, 0xFF}}},
	{{{-83, 564, -10}, 0, {62, 825}, {0x00, 0x75, 0xCE, 0xFF}}},
	{{{-83, 525, -102}, 0, {46, 641}, {0x00, 0x75, 0xCE, 0xFF}}},
	{{{-49, 505, 1}, 0, {26, 825}, {0x6E, 0x3B, 0xE7, 0xFF}}},
	{{{-239, 385, -2}, 0, {98, 825}, {0x94, 0x3E, 0xE5, 0xFF}}},
	{{{-205, 444, -2}, 0, {62, 825}, {0x00, 0x75, 0xCE, 0xFF}}},
	{{{-205, 405, -94}, 0, {46, 641}, {0x00, 0x75, 0xCE, 0xFF}}},
	{{{-171, 385, -2}, 0, {26, 825}, {0x6C, 0x3E, 0xE5, 0xFF}}},
	{{{238, 385, -2}, 0, {98, 825}, {0x6C, 0x3E, 0xE5, 0xFF}}},
	{{{204, 405, -94}, 0, {46, 641}, {0x00, 0x75, 0xCE, 0xFF}}},
	{{{204, 444, -2}, 0, {62, 825}, {0x00, 0x75, 0xCE, 0xFF}}},
	{{{170, 385, -2}, 0, {26, 825}, {0x94, 0x3E, 0xE5, 0xFF}}},
	{{{117, 505, 1}, 0, {98, 825}, {0x6E, 0x3B, 0xE7, 0xFF}}},
	{{{83, 524, -102}, 0, {46, 641}, {0x00, 0x75, 0xCE, 0xFF}}},
	{{{83, 564, -10}, 0, {62, 825}, {0x00, 0x75, 0xCE, 0xFF}}},
	{{{49, 505, 1}, 0, {26, 825}, {0x92, 0x3B, 0xE7, 0xFF}}},
	{{{0, 559, 123}, 0, {528, 58}, {0x00, 0x4A, 0x67, 0xFF}}},
	{{{-93, 464, 240}, 0, {274, 215}, {0xD6, 0x43, 0x63, 0xFF}}},
	{{{93, 464, 240}, 0, {516, 414}, {0x2A, 0x43, 0x63, 0xFF}}},
	{{{0, 306, 289}, 0, {304, 542}, {0x00, 0xFF, 0x7F, 0xFF}}},
	{{{185, 324, 221}, 0, {630, 582}, {0x50, 0x08, 0x62, 0xFF}}},
	{{{169, 497, 126}, 0, {744, 318}, {0x44, 0x45, 0x52, 0xFF}}},
};

Gfx piranha_plant_lower_mouth_2_4_tri_1[] = {
	gsSPVertex(piranha_plant_lower_mouth_2_4_vtx_1 + 0, 62, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(6, 7, 8, 0, 9, 8, 7, 0),
	gsSP2Triangles(7, 10, 9, 0, 7, 11, 10, 0),
	gsSP2Triangles(12, 9, 10, 0, 12, 13, 9, 0),
	gsSP2Triangles(13, 12, 14, 0, 15, 14, 12, 0),
	gsSP2Triangles(14, 15, 16, 0, 17, 14, 16, 0),
	gsSP2Triangles(16, 18, 17, 0, 16, 19, 18, 0),
	gsSP2Triangles(20, 18, 19, 0, 21, 20, 19, 0),
	gsSP2Triangles(18, 20, 22, 0, 23, 22, 20, 0),
	gsSP2Triangles(22, 17, 18, 0, 17, 22, 24, 0),
	gsSP2Triangles(24, 25, 17, 0, 25, 24, 13, 0),
	gsSP2Triangles(8, 13, 24, 0, 8, 9, 13, 0),
	gsSP2Triangles(13, 14, 25, 0, 14, 17, 25, 0),
	gsSP2Triangles(26, 27, 28, 0, 29, 28, 27, 0),
	gsSP2Triangles(27, 30, 29, 0, 31, 32, 33, 0),
	gsSP2Triangles(34, 33, 32, 0, 35, 36, 37, 0),
	gsSP2Triangles(36, 35, 38, 0, 39, 36, 38, 0),
	gsSP2Triangles(39, 40, 36, 0, 41, 42, 43, 0),
	gsSP2Triangles(44, 43, 42, 0, 45, 46, 47, 0),
	gsSP2Triangles(48, 47, 46, 0, 49, 50, 51, 0),
	gsSP2Triangles(49, 52, 50, 0, 53, 50, 52, 0),
	gsSP2Triangles(54, 55, 56, 0, 57, 56, 55, 0),
	gsSP2Triangles(58, 59, 60, 0, 61, 60, 59, 0),
	gsSPVertex(piranha_plant_lower_mouth_2_4_vtx_1 + 62, 14, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
	gsSP2Triangles(4, 5, 6, 0, 7, 6, 5, 0),
	gsSP2Triangles(8, 9, 10, 0, 11, 10, 9, 0),
	gsSP2Triangles(10, 11, 12, 0, 12, 13, 10, 0),
	gsSP1Triangle(8, 10, 13, 0),
	gsSPEndDisplayList(),
};


Gfx piranha_plant_material[] = {
	gsSPClearGeometryMode(G_CULL_BACK),
	gsSPSetLights1(piranha_plant_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, piranha_plant),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 1023, 512),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0, 0, 0, G_TX_WRAP | G_TX_MIRROR, 6, 0, G_TX_WRAP | G_TX_MIRROR, 4, 0),
	gsDPSetTileSize(0, 0, 0, 60, 252),
	gsSPEndDisplayList(),
};

Gfx piranha_plant_material_revert[] = {
	gsSPSetGeometryMode(G_CULL_BACK),
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsSPEndDisplayList(),
};

Gfx piranha_plant_4[] = {
	gsSPDisplayList(piranha_plant_material),
	gsSPDisplayList(piranha_plant_4_tri_0),
	gsSPDisplayList(piranha_plant_material_revert),
	gsSPEndDisplayList(),
};

Gfx piranha_plant_hand_r_4[] = {
	gsSPDisplayList(piranha_plant_material),
	gsSPDisplayList(piranha_plant_hand_r_4_tri_0),
	gsSPDisplayList(piranha_plant_material_revert),
	gsSPEndDisplayList(),
};

Gfx piranha_plant_neck1_4[] = {
	gsSPDisplayList(piranha_plant_material),
	gsSPDisplayList(piranha_plant_neck1_4_tri_0),
	gsSPDisplayList(piranha_plant_material_revert),
	gsSPEndDisplayList(),
};

Gfx piranha_plant_neck1_2_4[] = {
	gsSPDisplayList(piranha_plant_material),
	gsSPDisplayList(piranha_plant_neck1_2_4_tri_0),
	gsSPDisplayList(piranha_plant_material_revert),
	gsSPEndDisplayList(),
};

Gfx piranha_plant_neck2_4[] = {
	gsSPDisplayList(piranha_plant_material),
	gsSPDisplayList(piranha_plant_neck2_4_tri_0),
	gsSPDisplayList(piranha_plant_material_revert),
	gsSPEndDisplayList(),
};

Gfx piranha_plant_neck2_2_4[] = {
	gsSPDisplayList(piranha_plant_material),
	gsSPDisplayList(piranha_plant_neck2_2_4_tri_0),
	gsSPDisplayList(piranha_plant_neck2_2_4_tri_1),
	gsSPDisplayList(piranha_plant_material_revert),
	gsSPEndDisplayList(),
};

Gfx piranha_plant_neck3_4[] = {
	gsSPDisplayList(piranha_plant_material),
	gsSPDisplayList(piranha_plant_neck3_4_tri_0),
	gsSPDisplayList(piranha_plant_material_revert),
	gsSPEndDisplayList(),
};

Gfx piranha_plant_neck_03_mesh_layer_4[] = {
	gsSPDisplayList(piranha_plant_material),
	gsSPDisplayList(piranha_plant_neck3_2_tri_0),
	gsSPDisplayList(piranha_plant_neck3_2_tri_1),
	gsSPDisplayList(piranha_plant_material_revert),
	gsSPEndDisplayList(),
};

Gfx piranha_plant_upper_mouth_4[] = {
	gsSPDisplayList(piranha_plant_material),
	gsSPDisplayList(piranha_plant_upper_mouth_4_tri_0),
	gsSPDisplayList(piranha_plant_material_revert),
	gsSPEndDisplayList(),
};

Gfx piranha_plant_upper_mouth_2_4[] = {
	gsSPDisplayList(piranha_plant_material),
	gsSPDisplayList(piranha_plant_upper_mouth_2_4_tri_0),
	gsSPDisplayList(piranha_plant_upper_mouth_2_4_tri_1),
	gsSPDisplayList(piranha_plant_material_revert),
	gsSPEndDisplayList(),
};

Gfx piranha_plant_lower_mouth_4[] = {
	gsSPDisplayList(piranha_plant_material),
	gsSPDisplayList(piranha_plant_lower_mouth_4_tri_0),
	gsSPDisplayList(piranha_plant_material_revert),
	gsSPEndDisplayList(),
};

Gfx piranha_plant_lower_mouth_2_4[] = {
	gsSPDisplayList(piranha_plant_material),
	gsSPDisplayList(piranha_plant_lower_mouth_2_4_tri_0),
	gsSPDisplayList(piranha_plant_lower_mouth_2_4_tri_1),
	gsSPDisplayList(piranha_plant_material_revert),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};
