Lights1 red_switch_switch_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x49, 0x49, 0x49);

Gfx red_switch_switch_box_cmp4_ci8_aligner[] = {gsSPEndDisplayList()};
u8 red_switch_switch_box_cmp4_ci8[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 
	0x03, 0x03, 0x03, 0x01, 0x04, 0x04, 0x04, 0x04, 
	0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x01, 
	0x01, 0x07, 0x07, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x05, 0x05, 0x05, 0x05, 0x08, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x06, 0x06, 0x06, 0x00, 
	0x01, 0x07, 0x07, 0x06, 0x06, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x09, 0x09, 0x0a, 0x0a, 0x0b, 0x0b, 0x08, 0x05, 
	0x0c, 0x0c, 0x0c, 0x0c, 0x06, 0x06, 0x06, 0x00, 
	0x01, 0x07, 0x07, 0x06, 0x06, 0x0c, 0x0c, 0x0c, 
	0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 
	0x0d, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x11, 0x11, 
	0x12, 0x12, 0x12, 0x12, 0x0c, 0x05, 0x06, 0x00, 
	0x01, 0x13, 0x13, 0x06, 0x05, 0x0c, 0x0c, 0x0c, 
	0x12, 0x0c, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 
	0x14, 0x0d, 0x14, 0x0d, 0x0f, 0x10, 0x11, 0x11, 
	0x0c, 0x0c, 0x0c, 0x12, 0x0c, 0x05, 0x06, 0x00, 
	0x01, 0x13, 0x13, 0x06, 0x06, 0x15, 0x0c, 0x0c, 
	0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 
	0x14, 0x0d, 0x0d, 0x14, 0x16, 0x0f, 0x10, 0x11, 
	0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x05, 0x06, 0x00, 
	0x01, 0x17, 0x17, 0x06, 0x06, 0x15, 0x15, 0x0c, 
	0x15, 0x0c, 0x15, 0x0c, 0x0c, 0x0c, 0x15, 0x0c, 
	0x14, 0x14, 0x0d, 0x0d, 0x16, 0x0f, 0x10, 0x11, 
	0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x05, 0x06, 0x00, 
	0x01, 0x17, 0x17, 0x06, 0x06, 0x05, 0x15, 0x15, 
	0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 
	0x14, 0x14, 0x0d, 0x0d, 0x14, 0x18, 0x19, 0x1a, 
	0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x05, 0x06, 0x00, 
	0x01, 0x1b, 0x1b, 0x1c, 0x06, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x15, 0x05, 0x05, 0x05, 0x05, 
	0x14, 0x14, 0x0d, 0x0d, 0x14, 0x18, 0x19, 0x1a, 
	0x1d, 0x0c, 0x0c, 0x0c, 0x0c, 0x05, 0x06, 0x00, 
	0x01, 0x1e, 0x1e, 0x1c, 0x06, 0x06, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x14, 0x14, 0x0d, 0x0d, 0x14, 0x18, 0x19, 0x1a, 
	0x1d, 0x0c, 0x0c, 0x0c, 0x0c, 0x05, 0x06, 0x00, 
	0x01, 0x1e, 0x1e, 0x1c, 0x1f, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x14, 0x14, 0x0d, 0x0d, 0x14, 0x18, 0x19, 0x1a, 
	0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x05, 0x06, 0x00, 
	0x01, 0x1e, 0x1e, 0x1c, 0x1f, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x14, 0x0d, 0x0d, 0x14, 0x20, 0x0f, 0x21, 0x21, 
	0x0c, 0x0c, 0x0c, 0x0c, 0x15, 0x05, 0x06, 0x00, 
	0x01, 0x22, 0x22, 0x1c, 0x1f, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x0d, 0x0d, 0x0d, 0x0d, 0x20, 0x23, 0x21, 0x21, 
	0x15, 0x15, 0x0c, 0x0c, 0x15, 0x05, 0x06, 0x00, 
	0x01, 0x24, 0x24, 0x1c, 0x1f, 0x06, 0x1f, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x0d, 0x0d, 0x14, 0x25, 0x0f, 0x21, 0x21, 0x21, 
	0x15, 0x15, 0x0c, 0x0c, 0x15, 0x05, 0x06, 0x00, 
	0x01, 0x24, 0x24, 0x1c, 0x1f, 0x1f, 0x1f, 0x1f, 
	0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 
	0x0d, 0x0d, 0x14, 0x26, 0x23, 0x21, 0x21, 0x21, 
	0x15, 0x15, 0x15, 0x0c, 0x15, 0x05, 0x06, 0x00, 
	0x01, 0x24, 0x24, 0x1c, 0x1f, 0x1f, 0x1f, 0x1f, 
	0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 
	0x0d, 0x0d, 0x0d, 0x27, 0x28, 0x21, 0x15, 0x15, 
	0x15, 0x15, 0x15, 0x0c, 0x15, 0x05, 0x06, 0x00, 
	0x01, 0x29, 0x29, 0x29, 0x2a, 0x2a, 0x2a, 0x2a, 
	0x2b, 0x2b, 0x2b, 0x2b, 0x2b, 0x2b, 0x2b, 0x2b, 
	0x0d, 0x0d, 0x27, 0x2c, 0x2d, 0x15, 0x15, 0x15, 
	0x15, 0x15, 0x15, 0x15, 0x15, 0x05, 0x06, 0x00, 
	0x01, 0x29, 0x29, 0x29, 0x2e, 0x2e, 0x2e, 0x2e, 
	0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 
	0x0d, 0x2f, 0x27, 0x2c, 0x21, 0x15, 0x15, 0x15, 
	0x05, 0x15, 0x15, 0x15, 0x15, 0x05, 0x06, 0x00, 
	0x01, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x2f, 0x27, 0x2c, 0x2c, 0x15, 0x15, 0x15, 0x15, 
	0x05, 0x15, 0x15, 0x15, 0x15, 0x05, 0x06, 0x00, 
	0x01, 0x30, 0x30, 0x31, 0x31, 0x31, 0x31, 0x31, 
	0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 
	0x27, 0x32, 0x2d, 0x06, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x15, 0x15, 0x15, 0x05, 0x06, 0x00, 
	0x01, 0x30, 0x30, 0x33, 0x34, 0x35, 0x36, 0x36, 
	0x35, 0x35, 0x35, 0x35, 0x37, 0x38, 0x38, 0x38, 
	0x32, 0x06, 0x06, 0x06, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x15, 0x15, 0x15, 0x05, 0x06, 0x00, 
	0x01, 0x30, 0x30, 0x33, 0x34, 0x35, 0x36, 0x36, 
	0x35, 0x35, 0x35, 0x35, 0x37, 0x38, 0x38, 0x38, 
	0x06, 0x06, 0x06, 0x06, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x15, 0x15, 0x15, 0x05, 0x06, 0x00, 
	0x01, 0x30, 0x30, 0x33, 0x39, 0x34, 0x34, 0x34, 
	0x3a, 0x3a, 0x3a, 0x3b, 0x3b, 0x3b, 0x3b, 0x3b, 
	0x32, 0x32, 0x06, 0x06, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x15, 0x15, 0x15, 0x05, 0x06, 0x00, 
	0x01, 0x30, 0x30, 0x3c, 0x39, 0x39, 0x39, 0x39, 
	0x3d, 0x3d, 0x3d, 0x3d, 0x3e, 0x3e, 0x3e, 0x3e, 
	0x0d, 0x3f, 0x40, 0x41, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x15, 0x15, 0x0c, 0x0c, 0x05, 0x06, 0x00, 
	0x01, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 
	0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 
	0x0d, 0x0d, 0x3f, 0x40, 0x24, 0x05, 0x05, 0x05, 
	0x15, 0x15, 0x0c, 0x0c, 0x0c, 0x05, 0x06, 0x00, 
	0x01, 0x43, 0x43, 0x42, 0x44, 0x42, 0x42, 0x42, 
	0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 
	0x0d, 0x0d, 0x3f, 0x40, 0x45, 0x05, 0x0c, 0x0c, 
	0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x05, 0x06, 0x00, 
	0x01, 0x43, 0x43, 0x46, 0x42, 0x42, 0x47, 0x47, 
	0x47, 0x47, 0x47, 0x47, 0x47, 0x47, 0x47, 0x47, 
	0x0d, 0x3f, 0x40, 0x40, 0x0c, 0x0c, 0x0c, 0x0c, 
	0x0c, 0x12, 0x12, 0x12, 0x0c, 0x05, 0x06, 0x00, 
	0x01, 0x43, 0x43, 0x46, 0x42, 0x47, 0x47, 0x48, 
	0x48, 0x48, 0x48, 0x49, 0x48, 0x48, 0x48, 0x49, 
	0x4a, 0x4a, 0x4b, 0x15, 0x0c, 0x0c, 0x0c, 0x0c, 
	0x0c, 0x0c, 0x0c, 0x0c, 0x06, 0x06, 0x06, 0x00, 
	0x01, 0x43, 0x43, 0x4c, 0x42, 0x47, 0x47, 0x47, 
	0x47, 0x47, 0x47, 0x47, 0x47, 0x47, 0x47, 0x47, 
	0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 
	0x15, 0x15, 0x15, 0x15, 0x06, 0x06, 0x06, 0x00, 
	0x01, 0x48, 0x48, 0x4c, 0x42, 0x42, 0x42, 0x42, 
	0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 
	0x15, 0x15, 0x15, 0x15, 0x06, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x00, 
	0x01, 0x48, 0x48, 0x4c, 0x4d, 0x4d, 0x4d, 0x4d, 
	0x4d, 0x4d, 0x4d, 0x4d, 0x4d, 0x4d, 0x4d, 0x4d, 
	0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 
	0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x00, 0x03, 
	0x01, 0x48, 0x48, 0x4c, 0x4e, 0x4e, 0x4e, 0x4e, 
	0x4f, 0x4f, 0x4f, 0x4f, 0x4f, 0x4f, 0x4f, 0x4f, 
};

Gfx red_switch_switch_box_cmp4_pal_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 red_switch_switch_box_cmp4_pal_rgba16[] = {
	0xc4, 0xa5, 0xcc, 0xa5, 0xdd, 0x29, 0xdc, 0xe7, 
	0xbc, 0x21, 0x98, 0x01, 0x90, 0x01, 0xc2, 0xd7, 
	0xa0, 0x85, 0x83, 0x5b, 0x69, 0xcf, 0xa9, 0x09, 
	0xa8, 0x01, 0xef, 0x7b, 0xce, 0x73, 0x94, 0xa5, 
	0x82, 0x95, 0xb1, 0x09, 0xb0, 0x01, 0xc2, 0x95, 
	0xf7, 0xbd, 0xa0, 0x01, 0xe7, 0x39, 0xba, 0x53, 
	0xb5, 0xad, 0x7a, 0xd7, 0xb0, 0x43, 0xba, 0x11, 
	0x80, 0x01, 0xb0, 0x85, 0xb1, 0xcf, 0x88, 0x01, 
	0xde, 0xf7, 0xa8, 0x85, 0xb9, 0x8d, 0x83, 0x19, 
	0x90, 0x85, 0xd6, 0xb5, 0xc6, 0x31, 0x8c, 0x63, 
	0x88, 0xc7, 0x48, 0x01, 0x50, 0x01, 0x58, 0x01, 
	0x91, 0xcf, 0xb9, 0x4b, 0x30, 0x01, 0xbd, 0xef, 
	0xee, 0xa5, 0xee, 0x19, 0x5a, 0x11, 0xc4, 0x85, 
	0xd4, 0x85, 0xdc, 0xc7, 0xdd, 0x07, 0xd4, 0xc9, 
	0xcc, 0x89, 0xbc, 0x45, 0xcc, 0x87, 0xc4, 0x87, 
	0xc4, 0x45, 0xb4, 0x05, 0xac, 0x05, 0xa4, 0xa5, 
	0x8a, 0x53, 0x70, 0x43, 0x7a, 0x81, 0xbc, 0x4b, 
	0x72, 0x41, 0x91, 0x09, 0x7a, 0x41, 0x8a, 0xc1, 
	0x93, 0x01, 0x92, 0xc1, 0x7a, 0x53, 0x99, 0x09, 
	0x6a, 0x01, 0x62, 0x01, 0x49, 0x81, 0x51, 0x81, 
	
};

Vtx red_switch_switch_mesh_layer_1_vtx_0[20] = {
	{{ {-102, 0, 102}, 0, {558, 1008}, {171, 94, 0, 255} }},
	{{ {-66, 33, -66}, 0, {1458, -16}, {171, 94, 0, 255} }},
	{{ {-102, 0, -102}, 0, {1458, 1008}, {171, 94, 0, 255} }},
	{{ {-66, 33, 66}, 0, {558, -16}, {171, 94, 0, 255} }},
	{{ {66, 33, -66}, 0, {558, -16}, {0, 94, 171, 255} }},
	{{ {-102, 0, -102}, 0, {1458, 1008}, {0, 94, 171, 255} }},
	{{ {-66, 33, -66}, 0, {1458, -16}, {0, 94, 171, 255} }},
	{{ {102, 0, -102}, 0, {558, 1008}, {0, 94, 171, 255} }},
	{{ {102, 0, 102}, 0, {1458, 1008}, {0, 94, 85, 255} }},
	{{ {-66, 33, 66}, 0, {558, -16}, {0, 94, 85, 255} }},
	{{ {-102, 0, 102}, 0, {558, 1008}, {0, 94, 85, 255} }},
	{{ {66, 33, 66}, 0, {1458, -16}, {0, 94, 85, 255} }},
	{{ {66, 33, 66}, 0, {496, 1008}, {0, 127, 0, 255} }},
	{{ {-66, 33, -66}, 0, {-528, -16}, {0, 127, 0, 255} }},
	{{ {-66, 33, 66}, 0, {-528, 1008}, {0, 127, 0, 255} }},
	{{ {66, 33, -66}, 0, {496, -16}, {0, 127, 0, 255} }},
	{{ {102, 0, -102}, 0, {558, 1008}, {85, 94, 0, 255} }},
	{{ {66, 33, 66}, 0, {1458, -16}, {85, 94, 0, 255} }},
	{{ {102, 0, 102}, 0, {1458, 1008}, {85, 94, 0, 255} }},
	{{ {66, 33, -66}, 0, {558, -16}, {85, 94, 0, 255} }},
};

Gfx red_switch_switch_mesh_layer_1_tri_0[] = {
	gsSPVertex(red_switch_switch_mesh_layer_1_vtx_0 + 0, 20, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 7, 5, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 11, 9, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 15, 13, 0),
	gsSP2Triangles(16, 17, 18, 0, 16, 19, 17, 0),
	gsSPEndDisplayList(),
};

Gfx mat_red_switch_switch[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPSetLights1(red_switch_switch_lights),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, red_switch_switch_box_cmp4_pal_rgba16),
	gsDPSetTile(0, 0, 0, 256, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadTLUTCmd(5, 79),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 1, red_switch_switch_box_cmp4_ci8),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 511, 512),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 4, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_MIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_red_switch_switch[] = {
	gsDPPipeSync(),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};

Gfx red_switch_switch_mesh_layer_1[] = {
	gsSPDisplayList(mat_red_switch_switch),
	gsSPDisplayList(red_switch_switch_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_red_switch_switch),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};
