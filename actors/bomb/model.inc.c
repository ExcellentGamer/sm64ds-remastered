Lights1 bomb_Body_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x49, 0x49, 0x49);

Lights1 bomb_Spikes_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x49, 0x49, 0x49);

Gfx bomb_koopa_bomb_1_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 bomb_koopa_bomb_1_rgba16[] = {
	0x20, 0x5f, 0x20, 0x5f, 0x20, 0x5f, 0x20, 0x5f, 
	0x18, 0x5f, 0x18, 0x5f, 0x18, 0x5f, 0x18, 0x5f, 
	0x18, 0x5f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x20, 0x5f, 0x20, 0x5f, 0x20, 0x5f, 0x20, 0x5f, 
	0x20, 0x5f, 0x20, 0x5f, 0x20, 0x5f, 0x20, 0x5f, 
	0x20, 0x5f, 0x20, 0x5f, 0x18, 0x5f, 0x20, 0x5f, 
	0x18, 0x5f, 0x18, 0x5f, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x20, 0x5f, 0x20, 0x5f, 0x20, 0x5f, 0x20, 0x5f, 
	0x20, 0x5f, 0x20, 0x5f, 0x20, 0x5f, 0x20, 0x5f, 
	0x20, 0x5f, 0x20, 0x5f, 0x20, 0x5f, 0x20, 0x5f, 
	0x20, 0x5f, 0x20, 0x5f, 0x20, 0x5f, 0x20, 0x5f, 
	0x20, 0x5f, 0x20, 0x5f, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x20, 0x61, 0x20, 0x61, 0x20, 0x61, 0x20, 0x5f, 
	0x20, 0x5f, 0x20, 0x5f, 0x20, 0x5f, 0x20, 0x5f, 
	0x20, 0x5f, 0x20, 0x5f, 0x20, 0x5f, 0x20, 0x5f, 
	0x20, 0x5f, 0x20, 0x5f, 0x20, 0x5f, 0x20, 0x5f, 
	0x20, 0x5f, 0x20, 0x5f, 0x20, 0x5f, 0x20, 0x5f, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x29, 0x23, 0x29, 0x23, 0x29, 0x23, 0x29, 0x23, 
	0x20, 0xe3, 0x20, 0xe3, 0x20, 0xe3, 0x20, 0xe3, 
	0x20, 0x61, 0x20, 0x61, 0x20, 0x61, 0x20, 0x61, 
	0x20, 0x5f, 0x20, 0x5f, 0x20, 0x5f, 0x20, 0x5f, 
	0x20, 0x5f, 0x20, 0x5f, 0x20, 0x5f, 0x20, 0x5f, 
	0x20, 0x5f, 0x20, 0x5f, 0x20, 0x5f, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x29, 0x23, 0x29, 0x23, 0x29, 0x23, 0x29, 0x23, 
	0x20, 0xe3, 0x20, 0xe3, 0x20, 0xe3, 0x20, 0xe3, 
	0x20, 0xa1, 0x20, 0xa1, 0x20, 0xa1, 0x20, 0xa1, 
	0x20, 0xa1, 0x20, 0x5f, 0x20, 0x5f, 0x20, 0x5f, 
	0x20, 0x5f, 0x20, 0x5f, 0x20, 0x5f, 0x20, 0x5f, 
	0x20, 0x5f, 0x20, 0x5f, 0x20, 0x5f, 0x20, 0x5f, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x7b, 0xab, 0x5a, 0xa7, 0x5a, 0xa7, 0x5a, 0xa7, 
	0x39, 0xa5, 0x39, 0xa5, 0x20, 0xe3, 0x20, 0xe3, 
	0x20, 0xa1, 0x20, 0xa1, 0x20, 0xa1, 0x20, 0xa1, 
	0x20, 0x5f, 0x20, 0x5f, 0x20, 0x5f, 0x20, 0x5f, 
	0x20, 0x5f, 0x20, 0x5f, 0x20, 0x5f, 0x20, 0x5f, 
	0x20, 0x5f, 0x20, 0x5f, 0x20, 0x5f, 0x20, 0x5f, 
	0x20, 0x5f, 0x18, 0x5f, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0xad, 0x33, 0xad, 0x33, 0xad, 0x33, 0x7b, 0xab, 
	0x73, 0x6b, 0x52, 0x67, 0x39, 0xa5, 0x20, 0xe3, 
	0x28, 0xe3, 0x20, 0xa1, 0x20, 0xa1, 0x20, 0xa1, 
	0x20, 0x5f, 0x20, 0x5f, 0x20, 0x5f, 0x20, 0x5f, 
	0x20, 0x5f, 0x20, 0x5f, 0x20, 0x5f, 0x20, 0x5f, 
	0x20, 0x5f, 0x20, 0x5f, 0x18, 0x5f, 0x18, 0x5f, 
	0x18, 0x5f, 0x18, 0x5f, 0x18, 0x5f, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0xf7, 0xbd, 0xf7, 0xbd, 0xde, 0xf9, 0xbd, 0xf7, 
	0x94, 0xb1, 0x7b, 0xad, 0x52, 0x67, 0x52, 0x67, 
	0x39, 0xa5, 0x28, 0xe1, 0x20, 0xa1, 0x20, 0xa1, 
	0x20, 0x61, 0x20, 0x61, 0x20, 0x61, 0x20, 0x61, 
	0x18, 0x5f, 0x18, 0x5f, 0x18, 0x5f, 0x18, 0x5f, 
	0x18, 0x5f, 0x18, 0x5f, 0x18, 0x1f, 0x18, 0x1f, 
	0x18, 0x1d, 0x18, 0x1d, 0x18, 0x1d, 0x18, 0x1d, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0xf7, 0xbd, 0xf7, 0xbd, 0xf7, 0xbd, 0xde, 0xf9, 
	0xbd, 0xf7, 0x94, 0xb1, 0x7b, 0xad, 0x52, 0x67, 
	0x39, 0xa5, 0x29, 0x23, 0x28, 0xe1, 0x20, 0xa1, 
	0x20, 0x61, 0x20, 0x61, 0x20, 0xa1, 0x20, 0xa1, 
	0x18, 0x5f, 0x18, 0x5f, 0x18, 0x5f, 0x18, 0x5f, 
	0x18, 0x5f, 0x18, 0x5f, 0x18, 0x1f, 0x18, 0x1f, 
	0x18, 0x1d, 0x18, 0x1d, 0x18, 0x1d, 0x18, 0x1d, 
	0x10, 0x1b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0xf7, 0xbd, 0xf7, 0xbd, 0xf7, 0xbd, 0xde, 0xf9, 
	0xbd, 0xf7, 0x94, 0xb1, 0x7b, 0xad, 0x52, 0x67, 
	0x39, 0xa5, 0x29, 0x23, 0x28, 0xe1, 0x20, 0xa1, 
	0x20, 0xa1, 0x20, 0xa1, 0x20, 0xa1, 0x20, 0x61, 
	0x18, 0x5f, 0x18, 0x5f, 0x18, 0x5f, 0x18, 0x5f, 
	0x18, 0x5f, 0x18, 0x1f, 0x18, 0x1f, 0x18, 0x1f, 
	0x10, 0x1d, 0x10, 0x1d, 0x10, 0x1d, 0x10, 0x1d, 
	0x10, 0x1b, 0x18, 0x1b, 0x00, 0x00, 0x00, 0x00, 
	0xf7, 0xbd, 0xde, 0xf9, 0xde, 0xf9, 0xbd, 0xf7, 
	0x94, 0xb1, 0x7b, 0xad, 0x52, 0x67, 0x52, 0x67, 
	0x39, 0xa5, 0x29, 0x23, 0x28, 0xe1, 0x20, 0xa1, 
	0x20, 0xa1, 0x20, 0xa1, 0x20, 0xa1, 0x20, 0x61, 
	0x18, 0x5f, 0x18, 0x5f, 0x18, 0x1f, 0x18, 0x1f, 
	0x18, 0x1f, 0x18, 0x1f, 0x18, 0x1f, 0x18, 0x1f, 
	0x10, 0x1d, 0x10, 0x1d, 0x10, 0x1d, 0x10, 0x1d, 
	0x10, 0x1b, 0x10, 0x1b, 0x10, 0x1b, 0x00, 0x00, 
	0xa5, 0x33, 0xa5, 0x33, 0xa5, 0x33, 0x7b, 0xab, 
	0x73, 0x6b, 0x52, 0x67, 0x39, 0xa5, 0x39, 0xa5, 
	0x20, 0xe3, 0x20, 0xe3, 0x18, 0xa1, 0x18, 0xa1, 
	0x18, 0xa1, 0x18, 0xa1, 0x18, 0xa1, 0x10, 0x5f, 
	0x18, 0x61, 0x18, 0x61, 0x10, 0x1f, 0x10, 0x1f, 
	0x10, 0x1d, 0x10, 0x1d, 0x10, 0x1d, 0x10, 0x1d, 
	0x10, 0x1b, 0x10, 0x1b, 0x10, 0x1b, 0x08, 0x19, 
	0x08, 0x17, 0x08, 0x17, 0x08, 0x17, 0x00, 0x00, 
	0x7b, 0xab, 0x5a, 0xa7, 0x5a, 0xa7, 0x5a, 0xa7, 
	0x39, 0xa5, 0x39, 0xa5, 0x20, 0xe3, 0x20, 0xe3, 
	0x20, 0xe3, 0x18, 0xa1, 0x18, 0xa1, 0x18, 0xa1, 
	0x18, 0xa1, 0x18, 0xa1, 0x10, 0x5f, 0x10, 0x5f, 
	0x18, 0x61, 0x10, 0x1f, 0x10, 0x1f, 0x10, 0x1d, 
	0x10, 0x1d, 0x10, 0x1d, 0x10, 0x1d, 0x10, 0x1d, 
	0x10, 0x1b, 0x08, 0x19, 0x08, 0x19, 0x08, 0x19, 
	0x08, 0x17, 0x08, 0x17, 0x08, 0x17, 0x08, 0x17, 
	0x29, 0x23, 0x29, 0x23, 0x29, 0x23, 0x29, 0x23, 
	0x20, 0xe3, 0x20, 0xe3, 0x20, 0xe3, 0x20, 0xe3, 
	0x18, 0xa1, 0x18, 0xa1, 0x18, 0xa1, 0x18, 0x61, 
	0x10, 0x5f, 0x10, 0x5f, 0x10, 0x5f, 0x10, 0x5f, 
	0x10, 0x1f, 0x10, 0x1f, 0x10, 0x1f, 0x10, 0x1d, 
	0x10, 0x1d, 0x10, 0x1d, 0x08, 0x1b, 0x08, 0x1b, 
	0x10, 0x1b, 0x08, 0x19, 0x08, 0x19, 0x00, 0x17, 
	0x00, 0x15, 0x00, 0x15, 0x00, 0x13, 0x00, 0x13, 
	0x29, 0x23, 0x29, 0x23, 0x29, 0x23, 0x29, 0x23, 
	0x20, 0xe3, 0x20, 0xe3, 0x20, 0xe3, 0x20, 0xe3, 
	0x18, 0xa1, 0x18, 0xa1, 0x18, 0x61, 0x18, 0x61, 
	0x10, 0x5f, 0x10, 0x5f, 0x10, 0x1f, 0x10, 0x1f, 
	0x10, 0x1f, 0x10, 0x1f, 0x10, 0x1d, 0x10, 0x1d, 
	0x08, 0x1b, 0x08, 0x1b, 0x08, 0x1b, 0x08, 0x1b, 
	0x08, 0x19, 0x00, 0x17, 0x00, 0x17, 0x00, 0x17, 
	0x00, 0x13, 0x00, 0x13, 0x00, 0x13, 0x00, 0x13, 
	0x18, 0xa1, 0x18, 0xa1, 0x18, 0xa1, 0x18, 0xa1, 
	0x18, 0xa1, 0x10, 0x5f, 0x10, 0x5f, 0x10, 0x5f, 
	0x18, 0x61, 0x18, 0x61, 0x18, 0x61, 0x10, 0x1f, 
	0x10, 0x1f, 0x10, 0x1f, 0x10, 0x1f, 0x10, 0x1f, 
	0x08, 0x1b, 0x08, 0x1b, 0x08, 0x1b, 0x08, 0x1b, 
	0x08, 0x1b, 0x08, 0x1b, 0x00, 0x17, 0x00, 0x17, 
	0x00, 0x15, 0x00, 0x15, 0x00, 0x15, 0x00, 0x15, 
	0x00, 0x13, 0x00, 0x13, 0x00, 0x13, 0x00, 0x0f, 
	0x18, 0xa1, 0x10, 0x5f, 0x10, 0x5f, 0x10, 0x5f, 
	0x10, 0x5f, 0x10, 0x5f, 0x10, 0x5f, 0x10, 0x1f, 
	0x10, 0x1f, 0x10, 0x1f, 0x10, 0x1f, 0x10, 0x1f, 
	0x10, 0x1f, 0x08, 0x1b, 0x08, 0x1b, 0x08, 0x1b, 
	0x08, 0x1b, 0x08, 0x1b, 0x08, 0x1b, 0x00, 0x19, 
	0x00, 0x17, 0x00, 0x17, 0x00, 0x17, 0x00, 0x15, 
	0x00, 0x15, 0x00, 0x15, 0x00, 0x11, 0x00, 0x11, 
	0x00, 0x0f, 0x00, 0x0f, 0x00, 0x0f, 0x00, 0x0f, 
	0x10, 0x5f, 0x10, 0x5f, 0x10, 0x5f, 0x10, 0x5f, 
	0x10, 0x1f, 0x10, 0x1f, 0x10, 0x1f, 0x10, 0x1f, 
	0x10, 0x1f, 0x10, 0x1f, 0x10, 0x1f, 0x08, 0x1d, 
	0x08, 0x1b, 0x08, 0x1b, 0x08, 0x1b, 0x08, 0x1b, 
	0x00, 0x19, 0x00, 0x19, 0x00, 0x19, 0x00, 0x19, 
	0x00, 0x17, 0x00, 0x15, 0x00, 0x15, 0x00, 0x13, 
	0x00, 0x15, 0x00, 0x11, 0x00, 0x0f, 0x00, 0x0f, 
	0x00, 0x0b, 0x00, 0x0b, 0x00, 0x0b, 0x00, 0x0b, 
	0x10, 0x1f, 0x10, 0x1f, 0x10, 0x1f, 0x10, 0x1f, 
	0x10, 0x1f, 0x10, 0x1f, 0x10, 0x1f, 0x10, 0x1f, 
	0x10, 0x1f, 0x10, 0x1f, 0x08, 0x1d, 0x08, 0x1d, 
	0x08, 0x1b, 0x08, 0x1b, 0x00, 0x19, 0x00, 0x19, 
	0x00, 0x19, 0x00, 0x19, 0x00, 0x17, 0x00, 0x17, 
	0x00, 0x15, 0x00, 0x15, 0x00, 0x13, 0x00, 0x13, 
	0x00, 0x0f, 0x00, 0x0f, 0x00, 0x0d, 0x00, 0x0d, 
	0x00, 0x0b, 0x00, 0x0b, 0x00, 0x0b, 0x00, 0x00, 
	0x10, 0x1d, 0x10, 0x1d, 0x10, 0x1d, 0x10, 0x1d, 
	0x10, 0x1b, 0x10, 0x1b, 0x08, 0x17, 0x08, 0x17, 
	0x08, 0x1b, 0x08, 0x1b, 0x00, 0x17, 0x00, 0x17, 
	0x00, 0x17, 0x00, 0x17, 0x00, 0x17, 0x00, 0x17, 
	0x00, 0x15, 0x00, 0x15, 0x00, 0x15, 0x00, 0x15, 
	0x00, 0x13, 0x00, 0x13, 0x00, 0x13, 0x00, 0x0f, 
	0x00, 0x0b, 0x00, 0x0b, 0x00, 0x0b, 0x00, 0x09, 
	0x00, 0x09, 0x00, 0x09, 0x00, 0x05, 0x00, 0x00, 
	0x10, 0x1d, 0x08, 0x19, 0x08, 0x19, 0x08, 0x19, 
	0x08, 0x17, 0x08, 0x17, 0x00, 0x15, 0x00, 0x15, 
	0x00, 0x17, 0x00, 0x17, 0x00, 0x17, 0x00, 0x17, 
	0x00, 0x17, 0x00, 0x17, 0x00, 0x17, 0x00, 0x17, 
	0x00, 0x15, 0x00, 0x15, 0x00, 0x15, 0x00, 0x11, 
	0x00, 0x13, 0x00, 0x0f, 0x00, 0x0f, 0x00, 0x0f, 
	0x00, 0x0b, 0x00, 0x0b, 0x00, 0x0b, 0x00, 0x09, 
	0x00, 0x07, 0x00, 0x09, 0x00, 0x00, 0x00, 0x00, 
	0x08, 0x19, 0x08, 0x19, 0x00, 0x17, 0x00, 0x17, 
	0x00, 0x15, 0x00, 0x15, 0x00, 0x15, 0x00, 0x15, 
	0x00, 0x15, 0x00, 0x15, 0x00, 0x15, 0x00, 0x15, 
	0x00, 0x13, 0x00, 0x13, 0x00, 0x13, 0x00, 0x13, 
	0x00, 0x11, 0x00, 0x11, 0x00, 0x0f, 0x00, 0x0f, 
	0x00, 0x0f, 0x00, 0x0f, 0x00, 0x0b, 0x00, 0x09, 
	0x00, 0x09, 0x00, 0x09, 0x00, 0x09, 0x00, 0x07, 
	0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x15, 0x00, 0x15, 0x00, 0x15, 0x00, 0x15, 
	0x00, 0x13, 0x00, 0x13, 0x00, 0x13, 0x00, 0x13, 
	0x00, 0x13, 0x00, 0x13, 0x00, 0x13, 0x00, 0x13, 
	0x00, 0x11, 0x00, 0x0f, 0x00, 0x0f, 0x00, 0x0f, 
	0x00, 0x0f, 0x00, 0x0f, 0x00, 0x0d, 0x00, 0x0d, 
	0x00, 0x0b, 0x00, 0x0b, 0x00, 0x09, 0x00, 0x09, 
	0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x11, 0x00, 0x11, 0x00, 0x11, 0x00, 0x11, 
	0x00, 0x0f, 0x00, 0x0f, 0x00, 0x0f, 0x00, 0x0f, 
	0x00, 0x0d, 0x00, 0x0d, 0x00, 0x0d, 0x00, 0x0d, 
	0x00, 0x0d, 0x00, 0x0d, 0x00, 0x0d, 0x00, 0x0d, 
	0x00, 0x0b, 0x00, 0x0b, 0x00, 0x0b, 0x00, 0x0b, 
	0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 
	0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x0d, 0x00, 0x0d, 0x00, 0x0d, 0x00, 0x0d, 
	0x00, 0x0b, 0x00, 0x0f, 0x00, 0x0b, 0x00, 0x0b, 
	0x00, 0x0d, 0x00, 0x0d, 0x00, 0x09, 0x00, 0x09, 
	0x00, 0x09, 0x00, 0x09, 0x00, 0x09, 0x00, 0x09, 
	0x00, 0x0b, 0x00, 0x07, 0x00, 0x07, 0x00, 0x0b, 
	0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 
	0x00, 0x07, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x09, 0x00, 0x0d, 0x00, 0x09, 0x00, 0x09, 
	0x00, 0x07, 0x00, 0x0b, 0x00, 0x07, 0x00, 0x07, 
	0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 
	0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 
	0x00, 0x07, 0x00, 0x07, 0x00, 0x05, 0x00, 0x05, 
	0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 
	0x00, 0x05, 0x00, 0x05, 0x00, 0x05, 0x00, 0x05, 
	0x00, 0x05, 0x00, 0x05, 0x00, 0x05, 0x00, 0x05, 
	0x00, 0x05, 0x00, 0x05, 0x00, 0x05, 0x00, 0x05, 
	0x00, 0x03, 0x00, 0x03, 0x00, 0x05, 0x00, 0x05, 
	0x00, 0x07, 0x00, 0x03, 0x08, 0x01, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x05, 0x00, 0x05, 0x00, 0x05, 0x00, 0x03, 
	0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 
	0x00, 0x03, 0x00, 0x01, 0x00, 0x03, 0x00, 0x01, 
	0x00, 0x03, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 
	0x00, 0x03, 0x00, 0x03, 0x08, 0x03, 0x08, 0x03, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x00, 0x03, 
	0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 
	0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 
	0x00, 0x01, 0x00, 0x01, 0x08, 0x01, 0x08, 0x01, 
	0x08, 0x03, 0x08, 0x03, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 
	0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 
	0x08, 0x01, 0x08, 0x01, 0x08, 0x01, 0x08, 0x01, 
	0x08, 0x01, 0x08, 0x01, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x10, 0x03, 0x10, 0x03, 0x10, 0x03, 0x08, 0x03, 
	0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 0x08, 0x03, 
	0x08, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	
};

Gfx bomb_koopa_bomb_2_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 bomb_koopa_bomb_2_rgba16[] = {
	0xf7, 0x81, 0xf7, 0x81, 0xf7, 0x81, 0xf7, 0x81, 
	0xf7, 0x81, 0xf7, 0x81, 0xf7, 0x81, 0xf7, 0x81, 
	0xf7, 0x81, 0xf7, 0x81, 0xf7, 0x81, 0xf7, 0x81, 
	0xf7, 0x81, 0xf7, 0x81, 0xf7, 0x81, 0xf7, 0x81, 
	0xf7, 0x81, 0xf7, 0x81, 0xf7, 0x81, 0xf7, 0x81, 
	0xf7, 0x81, 0xf7, 0x81, 0xf7, 0x81, 0xf7, 0x81, 
	0xf7, 0x81, 0xf7, 0x81, 0xf7, 0x81, 0xf7, 0x81, 
	0xf7, 0x81, 0xf7, 0x81, 0xf7, 0x81, 0xf7, 0x81, 
	0xf7, 0x81, 0xf7, 0x81, 0xf7, 0x81, 0xf7, 0x81, 
	0xf7, 0x81, 0xf7, 0x81, 0xf7, 0x81, 0xf7, 0x81, 
	0xf7, 0x81, 0xf7, 0x81, 0xf7, 0x81, 0xf7, 0x81, 
	0xf7, 0x81, 0xf7, 0x81, 0xf7, 0x81, 0xf7, 0x81, 
	0xef, 0x41, 0xef, 0x41, 0xef, 0x41, 0xef, 0x41, 
	0xef, 0x41, 0xef, 0x41, 0xef, 0x41, 0xef, 0x41, 
	0xef, 0x41, 0xef, 0x41, 0xef, 0x41, 0xef, 0x41, 
	0xef, 0x41, 0xef, 0x41, 0xef, 0x41, 0xef, 0x41, 
	0xe7, 0x41, 0xe7, 0x41, 0xe7, 0x41, 0xe7, 0x41, 
	0xe7, 0x41, 0xe7, 0x41, 0xe7, 0x41, 0xe7, 0x41, 
	0xe7, 0x41, 0xe7, 0x41, 0xe7, 0x41, 0xe7, 0x41, 
	0xe7, 0x41, 0xe7, 0x41, 0xe7, 0x41, 0xe7, 0x41, 
	0xe7, 0x41, 0xe7, 0x41, 0xe7, 0x41, 0xe7, 0x41, 
	0xe7, 0x41, 0xe7, 0x41, 0xe7, 0x41, 0xe7, 0x41, 
	0xe7, 0x41, 0xe7, 0x41, 0xe7, 0x41, 0xe7, 0x41, 
	0xe7, 0x41, 0xe7, 0x41, 0xe7, 0x41, 0xe7, 0x41, 
	0xde, 0xc1, 0xde, 0xc1, 0xde, 0xc1, 0xde, 0xc1, 
	0xde, 0xc1, 0xde, 0xc1, 0xde, 0xc1, 0xde, 0xc1, 
	0xde, 0xc1, 0xde, 0xc1, 0xde, 0xc1, 0xde, 0xc1, 
	0xde, 0xc1, 0xde, 0xc1, 0xde, 0xc1, 0xde, 0xc1, 
	0xd6, 0x81, 0xd6, 0x81, 0xd6, 0x81, 0xd6, 0x81, 
	0xd6, 0x81, 0xd6, 0x81, 0xd6, 0x81, 0xd6, 0x81, 
	0xd6, 0x81, 0xd6, 0x81, 0xd6, 0x81, 0xd6, 0x81, 
	0xd6, 0x81, 0xd6, 0x81, 0xd6, 0x81, 0xd6, 0x81, 
	0xce, 0x81, 0xce, 0x81, 0xce, 0x81, 0xce, 0x81, 
	0xce, 0x81, 0xce, 0x81, 0xce, 0x81, 0xce, 0x81, 
	0xce, 0x81, 0xce, 0x81, 0xce, 0x81, 0xce, 0x81, 
	0xce, 0x81, 0xce, 0x81, 0xce, 0x81, 0xce, 0x81, 
	0xc6, 0x41, 0xc6, 0x41, 0xc6, 0x41, 0xc6, 0x41, 
	0xc6, 0x41, 0xc6, 0x41, 0xc6, 0x41, 0xc6, 0x41, 
	0xc6, 0x41, 0xc6, 0x41, 0xc6, 0x41, 0xc6, 0x41, 
	0xc6, 0x41, 0xc6, 0x41, 0xc6, 0x41, 0xc6, 0x41, 
	0xbe, 0x01, 0xbe, 0x01, 0xbe, 0x01, 0xbe, 0x01, 
	0xbe, 0x01, 0xbe, 0x01, 0xbe, 0x01, 0xbe, 0x01, 
	0xbe, 0x01, 0xbe, 0x01, 0xbe, 0x01, 0xbe, 0x01, 
	0xbe, 0x01, 0xbe, 0x01, 0xbe, 0x01, 0xbe, 0x01, 
	0xbe, 0x01, 0xbe, 0x01, 0xbe, 0x01, 0xbe, 0x01, 
	0xbe, 0x01, 0xbe, 0x01, 0xbe, 0x01, 0xbe, 0x01, 
	0xbe, 0x01, 0xbe, 0x01, 0xbe, 0x01, 0xbe, 0x01, 
	0xbe, 0x01, 0xbe, 0x01, 0xbe, 0x01, 0xbe, 0x01, 
	0xad, 0x41, 0xad, 0x41, 0xad, 0x41, 0xad, 0x41, 
	0xad, 0x41, 0xad, 0x41, 0xad, 0x41, 0xad, 0x41, 
	0xad, 0x41, 0xad, 0x41, 0xad, 0x41, 0xad, 0x41, 
	0xad, 0x41, 0xad, 0x41, 0xad, 0x41, 0xad, 0x41, 
	0xad, 0x41, 0xad, 0x41, 0xad, 0x41, 0xad, 0x41, 
	0xad, 0x41, 0xad, 0x41, 0xad, 0x41, 0xad, 0x41, 
	0xad, 0x41, 0xad, 0x41, 0xad, 0x41, 0xad, 0x41, 
	0xad, 0x41, 0xad, 0x41, 0xad, 0x41, 0xad, 0x41, 
	0xad, 0x41, 0xad, 0x41, 0xad, 0x41, 0xad, 0x41, 
	0xad, 0x41, 0xad, 0x41, 0xad, 0x41, 0xad, 0x41, 
	0xad, 0x41, 0xad, 0x41, 0xad, 0x41, 0xad, 0x41, 
	0xad, 0x41, 0xad, 0x41, 0xad, 0x41, 0xad, 0x41, 
	0x84, 0x41, 0x84, 0x41, 0x84, 0x41, 0x84, 0x41, 
	0x84, 0x41, 0x84, 0x41, 0x84, 0x41, 0x84, 0x41, 
	0x84, 0x41, 0x84, 0x41, 0x84, 0x41, 0x84, 0x41, 
	0x84, 0x41, 0x84, 0x41, 0x84, 0x41, 0x84, 0x41, 
	
};

Vtx bomb_body_mesh_layer_5_vtx_0[4] = {
	{{ {-162, -162, 0}, 0, {-1040, 1008}, {0, 0, 127, 255} }},
	{{ {162, -162, 0}, 0, {1008, 1008}, {0, 0, 127, 255} }},
	{{ {162, 162, 0}, 0, {1008, -16}, {0, 0, 127, 255} }},
	{{ {-162, 162, 0}, 0, {-1040, -16}, {0, 0, 127, 255} }},
};

Gfx bomb_body_mesh_layer_5_tri_0[] = {
	gsSPVertex(bomb_body_mesh_layer_5_vtx_0 + 0, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSPEndDisplayList(),
};

Vtx bomb_spikes_mesh_layer_1_vtx_0[73] = {
	{{ {-68, 128, 69}, 0, {86, 496}, {19, 124, 238, 255} }},
	{{ {-125, 67, 72}, 0, {86, 496}, {132, 234, 240, 255} }},
	{{ {-153, 155, 165}, 0, {224, -364}, {177, 62, 78, 255} }},
	{{ {-70, 67, 129}, 0, {364, 496}, {25, 229, 122, 255} }},
	{{ {-68, 128, 69}, 0, {364, 496}, {19, 124, 238, 255} }},
	{{ {-43, 153, -25}, 0, {364, 496}, {154, 46, 197, 255} }},
	{{ {0, 153, 49}, 0, {364, 496}, {0, 46, 118, 255} }},
	{{ {0, 279, 0}, 0, {224, -364}, {0, 127, 255, 255} }},
	{{ {43, 153, -25}, 0, {86, 496}, {102, 46, 197, 255} }},
	{{ {-43, 153, -25}, 0, {86, 496}, {154, 46, 197, 255} }},
	{{ {68, -128, -69}, 0, {364, 496}, {237, 132, 18, 255} }},
	{{ {70, -67, -129}, 0, {364, 496}, {231, 27, 134, 255} }},
	{{ {153, -155, -165}, 0, {224, -364}, {79, 194, 178, 255} }},
	{{ {125, -67, -72}, 0, {86, 496}, {124, 22, 16, 255} }},
	{{ {68, -128, -69}, 0, {86, 496}, {237, 132, 18, 255} }},
	{{ {-68, -128, 69}, 0, {364, 496}, {19, 132, 238, 255} }},
	{{ {-70, -67, 129}, 0, {364, 496}, {25, 27, 122, 255} }},
	{{ {-153, -155, 165}, 0, {224, -364}, {177, 194, 78, 255} }},
	{{ {-125, -67, 72}, 0, {86, 496}, {132, 22, 240, 255} }},
	{{ {-68, -128, 69}, 0, {86, 496}, {19, 132, 238, 255} }},
	{{ {-68, 128, -69}, 0, {364, 496}, {19, 124, 18, 255} }},
	{{ {-70, 67, -129}, 0, {364, 496}, {25, 229, 134, 255} }},
	{{ {-153, 155, -165}, 0, {224, -364}, {177, 62, 178, 255} }},
	{{ {-125, 67, -72}, 0, {86, 496}, {132, 234, 16, 255} }},
	{{ {-68, 128, -69}, 0, {86, 496}, {19, 124, 18, 255} }},
	{{ {68, 128, 69}, 0, {364, 496}, {237, 124, 238, 255} }},
	{{ {70, 67, 129}, 0, {364, 496}, {231, 229, 122, 255} }},
	{{ {153, 155, 165}, 0, {224, -364}, {79, 62, 78, 255} }},
	{{ {125, 67, 72}, 0, {86, 496}, {124, 234, 240, 255} }},
	{{ {68, 128, 69}, 0, {86, 496}, {237, 124, 238, 255} }},
	{{ {68, 128, -69}, 0, {364, 496}, {237, 124, 18, 255} }},
	{{ {153, 155, -165}, 0, {224, -364}, {79, 62, 178, 255} }},
	{{ {70, 67, -129}, 0, {364, 496}, {231, 229, 134, 255} }},
	{{ {125, 67, -72}, 0, {86, 496}, {124, 234, 16, 255} }},
	{{ {68, 128, -69}, 0, {86, 496}, {237, 124, 18, 255} }},
	{{ {68, -128, 69}, 0, {364, 496}, {237, 132, 238, 255} }},
	{{ {153, -155, 165}, 0, {224, -364}, {79, 194, 78, 255} }},
	{{ {70, -67, 129}, 0, {364, 496}, {231, 27, 122, 255} }},
	{{ {125, -67, 72}, 0, {86, 496}, {124, 22, 240, 255} }},
	{{ {68, -128, 69}, 0, {86, 496}, {237, 132, 238, 255} }},
	{{ {-68, -128, -69}, 0, {364, 496}, {19, 132, 18, 255} }},
	{{ {-153, -155, -165}, 0, {224, -364}, {177, 194, 178, 255} }},
	{{ {-70, -67, -129}, 0, {364, 496}, {25, 27, 134, 255} }},
	{{ {-125, -67, -72}, 0, {86, 496}, {132, 22, 16, 255} }},
	{{ {-68, -128, -69}, 0, {86, 496}, {19, 132, 18, 255} }},
	{{ {-43, -153, -25}, 0, {364, 496}, {154, 210, 197, 255} }},
	{{ {0, -279, 0}, 0, {224, -364}, {0, 129, 255, 255} }},
	{{ {0, -153, 49}, 0, {364, 496}, {0, 210, 118, 255} }},
	{{ {43, -153, -25}, 0, {86, 496}, {102, 210, 197, 255} }},
	{{ {-43, -153, -25}, 0, {86, 496}, {154, 210, 197, 255} }},
	{{ {-153, -2, -49}, 0, {86, 496}, {213, 0, 136, 255} }},
	{{ {-153, -49, -2}, 0, {224, 496}, {213, 136, 0, 255} }},
	{{ {-290, 0, 0}, 0, {224, -364}, {129, 0, 0, 255} }},
	{{ {-153, 2, 49}, 0, {364, 496}, {213, 0, 120, 255} }},
	{{ {-153, 49, 2}, 0, {224, 496}, {213, 120, 0, 255} }},
	{{ {153, -49, -2}, 0, {224, 496}, {43, 136, 0, 255} }},
	{{ {153, -2, -49}, 0, {86, 496}, {43, 0, 136, 255} }},
	{{ {290, 0, 0}, 0, {224, -364}, {127, 0, 0, 255} }},
	{{ {153, 49, 2}, 0, {224, 496}, {43, 120, 0, 255} }},
	{{ {153, 2, 49}, 0, {364, 496}, {43, 0, 120, 255} }},
	{{ {-47, -1, 153}, 0, {86, 496}, {136, 0, 41, 255} }},
	{{ {-1, -47, 153}, 0, {224, 496}, {0, 136, 41, 255} }},
	{{ {0, 0, 290}, 0, {224, -364}, {0, 0, 127, 255} }},
	{{ {47, 1, 153}, 0, {364, 496}, {120, 0, 41, 255} }},
	{{ {0, 0, 290}, 0, {224, -364}, {0, 0, 127, 255} }},
	{{ {47, 1, 153}, 0, {364, 496}, {120, 0, 41, 255} }},
	{{ {1, 47, 153}, 0, {224, 496}, {0, 120, 41, 255} }},
	{{ {-47, -1, 153}, 0, {86, 496}, {136, 0, 41, 255} }},
	{{ {-1, -47, -153}, 0, {224, 496}, {0, 136, 215, 255} }},
	{{ {-47, -1, -153}, 0, {86, 496}, {136, 0, 215, 255} }},
	{{ {0, 0, -290}, 0, {224, -364}, {0, 0, 129, 255} }},
	{{ {1, 47, -153}, 0, {224, 496}, {0, 120, 215, 255} }},
	{{ {47, 1, -153}, 0, {364, 496}, {120, 0, 215, 255} }},
};

Gfx bomb_spikes_mesh_layer_1_tri_0[] = {
	gsSPVertex(bomb_spikes_mesh_layer_1_vtx_0 + 0, 64, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
	gsSP2Triangles(2, 3, 4, 0, 5, 6, 7, 0),
	gsSP2Triangles(8, 7, 6, 0, 7, 8, 9, 0),
	gsSP2Triangles(10, 11, 12, 0, 13, 12, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
	gsSP2Triangles(18, 17, 16, 0, 17, 18, 19, 0),
	gsSP2Triangles(20, 21, 22, 0, 23, 22, 21, 0),
	gsSP2Triangles(22, 23, 24, 0, 25, 26, 27, 0),
	gsSP2Triangles(28, 27, 26, 0, 27, 28, 29, 0),
	gsSP2Triangles(30, 31, 32, 0, 33, 32, 31, 0),
	gsSP2Triangles(34, 33, 31, 0, 35, 36, 37, 0),
	gsSP2Triangles(38, 37, 36, 0, 39, 38, 36, 0),
	gsSP2Triangles(40, 41, 42, 0, 43, 42, 41, 0),
	gsSP2Triangles(44, 43, 41, 0, 45, 46, 47, 0),
	gsSP2Triangles(48, 47, 46, 0, 49, 48, 46, 0),
	gsSP2Triangles(50, 51, 52, 0, 53, 52, 51, 0),
	gsSP2Triangles(52, 53, 54, 0, 52, 54, 50, 0),
	gsSP2Triangles(55, 56, 57, 0, 58, 57, 56, 0),
	gsSP2Triangles(57, 58, 59, 0, 55, 57, 59, 0),
	gsSP2Triangles(60, 61, 62, 0, 63, 62, 61, 0),
	gsSPVertex(bomb_spikes_mesh_layer_1_vtx_0 + 64, 9, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 7, 6, 5, 0),
	gsSP2Triangles(6, 7, 8, 0, 4, 6, 8, 0),
	gsSPEndDisplayList(),
};


Gfx mat_bomb_Body[] = {
	gsSPGeometryMode(G_CULL_BACK, 0),
	gsSPSetLights1(bomb_Body_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetPrimColor(0, 0, 255, 255, 255, 255),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, bomb_koopa_bomb_1_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_MIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_bomb_Body[] = {
	gsSPGeometryMode(0, G_CULL_BACK),
	gsDPPipeSync(),
	gsSPEndDisplayList(),
};

Gfx mat_bomb_Spikes[] = {
	gsSPSetLights1(bomb_Spikes_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, bomb_koopa_bomb_2_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 255, 512),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 4, 0, G_TX_WRAP | G_TX_NOMIRROR, 4, 0),
	gsDPSetTileSize(0, 0, 0, 60, 60),
	gsSPEndDisplayList(),
};

Gfx bomb_body_mesh_layer_5[] = {
	gsSPDisplayList(mat_bomb_Body),
	gsSPDisplayList(bomb_body_mesh_layer_5_tri_0),
	gsSPDisplayList(mat_revert_bomb_Body),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

Gfx bomb_spikes_mesh_layer_1[] = {
	gsSPDisplayList(mat_bomb_Spikes),
	gsSPDisplayList(bomb_spikes_mesh_layer_1_tri_0),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

