Lights1 seesaw_platform__1_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x49, 0x49, 0x49);

Lights1 seesaw_platform__2_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x49, 0x49, 0x49);

Gfx seesaw_platform__1_ci8_aligner[] = {gsSPEndDisplayList()};
u8 seesaw_platform__1_ci8[] = {
	0x00, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 
	0x02, 0x03, 0x03, 0x01, 0x01, 0x01, 0x00, 0x01, 
	0x01, 0x01, 0x01, 0x01, 0x01, 0x04, 0x02, 0x02, 
	0x02, 0x05, 0x06, 0x06, 0x06, 0x07, 0x05, 0x06, 
	0x02, 0x02, 0x02, 0x02, 0x03, 0x01, 0x00, 0x01, 
	0x01, 0x04, 0x02, 0x05, 0x06, 0x07, 0x06, 0x06, 
	0x04, 0x02, 0x05, 0x02, 0x08, 0x04, 0x07, 0x02, 
	0x04, 0x01, 0x04, 0x02, 0x02, 0x06, 0x05, 0x08, 
	0x09, 0x09, 0x0a, 0x0b, 0x0a, 0x0a, 0x0a, 0x0a, 
	0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0c, 
	0x0c, 0x0a, 0x0a, 0x0d, 0x0e, 0x0e, 0x0e, 0x0e, 
	0x0e, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 
	0x09, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0f, 0x0c, 
	0x0a, 0x0e, 0x0e, 0x0a, 0x0a, 0x0a, 0x0a, 0x10, 
	0x11, 0x02, 0x06, 0x0b, 0x0a, 0x12, 0x12, 0x13, 
	0x12, 0x13, 0x06, 0x06, 0x12, 0x0a, 0x0a, 0x14, 
	0x14, 0x14, 0x15, 0x15, 0x15, 0x16, 0x16, 0x17, 
	0x18, 0x19, 0x1a, 0x1a, 0x1b, 0x1b, 0x1b, 0x1b, 
	0x1a, 0x1a, 0x1a, 0x1a, 0x1c, 0x1c, 0x1a, 0x1a, 
	0x1a, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1e, 0x1f, 
	0x1a, 0x20, 0x18, 0x18, 0x1c, 0x1a, 0x21, 0x21, 
	0x1a, 0x1a, 0x1a, 0x1d, 0x22, 0x1d, 0x23, 0x24, 
	0x24, 0x0f, 0x13, 0x0a, 0x25, 0x26, 0x26, 0x12, 
	0x12, 0x12, 0x13, 0x06, 0x13, 0x27, 0x27, 0x27, 
	0x15, 0x15, 0x15, 0x28, 0x28, 0x28, 0x28, 0x28, 
	0x29, 0x20, 0x2a, 0x1a, 0x1f, 0x1a, 0x1f, 0x1f, 
	0x1f, 0x1f, 0x1f, 0x1a, 0x2a, 0x2a, 0x2a, 0x2a, 
	0x2a, 0x1a, 0x1f, 0x2a, 0x2a, 0x2a, 0x2a, 0x2a, 
	0x20, 0x20, 0x20, 0x20, 0x20, 0x2a, 0x1f, 0x2b, 
	0x2c, 0x2b, 0x2c, 0x2c, 0x2c, 0x2c, 0x22, 0x2d, 
	0x2d, 0x24, 0x26, 0x0a, 0x25, 0x26, 0x2e, 0x2f, 
	0x26, 0x12, 0x12, 0x13, 0x30, 0x31, 0x32, 0x33, 
	0x34, 0x34, 0x20, 0x20, 0x20, 0x20, 0x20, 0x18, 
	0x18, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
	0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
	0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
	0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
	0x1f, 0x1f, 0x2b, 0x2b, 0x2c, 0x22, 0x22, 0x2d, 
	0x24, 0x24, 0x2e, 0x0d, 0x19, 0x2e, 0x2e, 0x26, 
	0x26, 0x12, 0x13, 0x13, 0x14, 0x35, 0x27, 0x32, 
	0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x18, 
	0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 
	0x18, 0x18, 0x18, 0x18, 0x18, 0x20, 0x20, 0x20, 
	0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
	0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x20, 
	0x20, 0x1a, 0x1f, 0x1f, 0x1f, 0x2b, 0x1d, 0x22, 
	0x22, 0x2d, 0x24, 0x18, 0x27, 0x24, 0x0f, 0x2e, 
	0x26, 0x12, 0x12, 0x11, 0x36, 0x35, 0x37, 0x35, 
	0x18, 0x18, 0x18, 0x18, 0x18, 0x34, 0x34, 0x34, 
	0x34, 0x34, 0x34, 0x18, 0x18, 0x18, 0x18, 0x18, 
	0x18, 0x18, 0x18, 0x18, 0x18, 0x20, 0x20, 0x20, 
	0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
	0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 
	0x18, 0x20, 0x20, 0x20, 0x1c, 0x1a, 0x1f, 0x1f, 
	0x2b, 0x1d, 0x1d, 0x34, 0x38, 0x24, 0x24, 0x0c, 
	0x0f, 0x2f, 0x26, 0x21, 0x37, 0x39, 0x3a, 0x39, 
	0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 
	0x15, 0x15, 0x15, 0x28, 0x28, 0x34, 0x34, 0x28, 
	0x28, 0x28, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 
	0x34, 0x34, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 
	0x18, 0x18, 0x18, 0x18, 0x18, 0x34, 0x34, 0x34, 
	0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x20, 0x1f, 
	0x2b, 0x2b, 0x1d, 0x09, 0x3b, 0x24, 0x0c, 0x0f, 
	0x12, 0x12, 0x11, 0x3c, 0x39, 0x37, 0x33, 0x39, 
	0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 
	0x18, 0x34, 0x34, 0x18, 0x18, 0x18, 0x18, 0x20, 
	0x20, 0x20, 0x20, 0x2a, 0x2a, 0x2a, 0x2a, 0x2a, 
	0x20, 0x20, 0x20, 0x20, 0x20, 0x18, 0x20, 0x20, 
	0x20, 0x20, 0x20, 0x18, 0x18, 0x18, 0x18, 0x20, 
	0x20, 0x2a, 0x2a, 0x1c, 0x1f, 0x1f, 0x2b, 0x2b, 
	0x22, 0x22, 0x1d, 0x3d, 0x38, 0x23, 0x24, 0x12, 
	0x12, 0x13, 0x12, 0x11, 0x3e, 0x27, 0x39, 0x32, 
	0x18, 0x18, 0x20, 0x20, 0x20, 0x20, 0x20, 0x18, 
	0x18, 0x18, 0x18, 0x20, 0x20, 0x20, 0x20, 0x20, 
	0x20, 0x3f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 
	0x1a, 0x20, 0x20, 0x20, 0x20, 0x18, 0x18, 0x20, 
	0x20, 0x20, 0x20, 0x18, 0x18, 0x18, 0x20, 0x20, 
	0x20, 0x2a, 0x1f, 0x1f, 0x1f, 0x1f, 0x2c, 0x2b, 
	0x22, 0x22, 0x1d, 0x18, 0x36, 0x1d, 0x0d, 0x0c, 
	0x0f, 0x11, 0x30, 0x19, 0x32, 0x27, 0x27, 0x31, 
	0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 
	0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x18, 
	0x18, 0x18, 0x20, 0x20, 0x18, 0x18, 0x20, 0x20, 
	0x20, 0x20, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 
	0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 
	0x18, 0x18, 0x20, 0x20, 0x20, 0x20, 0x20, 0x1a, 
	0x1f, 0x1d, 0x1d, 0x15, 0x27, 0x1b, 0x0e, 0x0d, 
	0x12, 0x12, 0x11, 0x09, 0x39, 0x37, 0x27, 0x31, 
	0x15, 0x15, 0x15, 0x15, 0x16, 0x16, 0x16, 0x16, 
	0x16, 0x16, 0x16, 0x16, 0x16, 0x34, 0x34, 0x34, 
	0x18, 0x18, 0x18, 0x20, 0x20, 0x20, 0x20, 0x2a, 
	0x2a, 0x2a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
	0x20, 0x20, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 
	0x18, 0x20, 0x20, 0x1f, 0x1f, 0x2c, 0x2b, 0x2b, 
	0x2b, 0x1d, 0x1d, 0x19, 0x3c, 0x1d, 0x1d, 0x1d, 
	0x24, 0x24, 0x0f, 0x40, 0x39, 0x37, 0x27, 0x32, 
	0x20, 0x20, 0x2a, 0x2a, 0x2a, 0x3f, 0x3f, 0x3f, 
	0x3f, 0x1f, 0x1f, 0x3f, 0x3f, 0x3f, 0x3f, 0x1f, 
	0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 
	0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x2b, 0x2b, 0x2b, 
	0x1f, 0x1f, 0x1f, 0x3f, 0x2a, 0x2a, 0x2a, 0x1f, 
	0x1f, 0x1f, 0x1f, 0x1f, 0x2c, 0x2c, 0x2c, 0x2c, 
	0x22, 0x2d, 0x0f, 0x11, 0x40, 0x24, 0x24, 0x41, 
	0x2e, 0x42, 0x12, 0x1b, 0x3e, 0x37, 0x27, 0x35, 
	0x20, 0x20, 0x20, 0x20, 0x20, 0x43, 0x43, 0x43, 
	0x3f, 0x1f, 0x1f, 0x3f, 0x3f, 0x43, 0x3f, 0x1f, 
	0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 
	0x1f, 0x1f, 0x1f, 0x2b, 0x2c, 0x2c, 0x2c, 0x2c, 
	0x44, 0x1f, 0x1f, 0x3f, 0x1f, 0x3f, 0x3f, 0x1f, 
	0x1f, 0x1f, 0x1f, 0x1f, 0x2c, 0x2c, 0x2c, 0x2c, 
	0x22, 0x45, 0x41, 0x21, 0x19, 0x2e, 0x2e, 0x42, 
	0x26, 0x26, 0x46, 0x02, 0x27, 0x39, 0x27, 0x35, 
	0x47, 0x47, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
	0x20, 0x20, 0x43, 0x43, 0x43, 0x43, 0x43, 0x3f, 
	0x1f, 0x1f, 0x48, 0x48, 0x48, 0x43, 0x43, 0x43, 
	0x43, 0x48, 0x1f, 0x1f, 0x1f, 0x44, 0x44, 0x44, 
	0x1f, 0x1f, 0x1f, 0x43, 0x43, 0x43, 0x43, 0x1f, 
	0x48, 0x48, 0x43, 0x48, 0x1f, 0x44, 0x2c, 0x2c, 
	0x2c, 0x22, 0x49, 0x4a, 0x38, 0x2e, 0x2e, 0x2f, 
	0x26, 0x26, 0x12, 0x12, 0x16, 0x32, 0x39, 0x35, 
	0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x34, 0x34, 
	0x47, 0x47, 0x47, 0x47, 0x20, 0x20, 0x43, 0x43, 
	0x43, 0x43, 0x43, 0x43, 0x43, 0x43, 0x43, 0x43, 
	0x43, 0x43, 0x43, 0x3f, 0x3f, 0x1f, 0x1f, 0x1f, 
	0x43, 0x43, 0x20, 0x47, 0x47, 0x47, 0x43, 0x43, 
	0x43, 0x43, 0x43, 0x43, 0x3f, 0x1f, 0x44, 0x44, 
	0x2c, 0x22, 0x49, 0x4b, 0x4c, 0x0f, 0x41, 0x41, 
	0x41, 0x4d, 0x4e, 0x12, 0x3c, 0x32, 0x35, 0x35, 
	0x4f, 0x4f, 0x4f, 0x4f, 0x4f, 0x4f, 0x4f, 0x28, 
	0x50, 0x50, 0x50, 0x47, 0x47, 0x20, 0x20, 0x43, 
	0x43, 0x43, 0x43, 0x3f, 0x3f, 0x3f, 0x3f, 0x43, 
	0x43, 0x43, 0x3f, 0x1f, 0x51, 0x3f, 0x3f, 0x3f, 
	0x43, 0x20, 0x47, 0x47, 0x47, 0x47, 0x20, 0x43, 
	0x43, 0x3f, 0x3f, 0x43, 0x44, 0x44, 0x44, 0x2c, 
	0x2c, 0x2d, 0x0f, 0x09, 0x19, 0x52, 0x41, 0x41, 
	0x41, 0x4d, 0x4e, 0x46, 0x0f, 0x39, 0x53, 0x32, 
	0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x34, 0x34, 
	0x34, 0x28, 0x28, 0x34, 0x34, 0x34, 0x34, 0x34, 
	0x34, 0x18, 0x18, 0x20, 0x20, 0x20, 0x20, 0x20, 
	0x20, 0x20, 0x3f, 0x44, 0x44, 0x44, 0x44, 0x44, 
	0x3f, 0x43, 0x20, 0x34, 0x34, 0x34, 0x34, 0x34, 
	0x18, 0x20, 0x20, 0x20, 0x2c, 0x2c, 0x44, 0x2c, 
	0x54, 0x24, 0x0f, 0x0d, 0x3c, 0x13, 0x2e, 0x41, 
	0x4d, 0x4e, 0x4e, 0x46, 0x46, 0x40, 0x39, 0x37, 
	0x20, 0x20, 0x1c, 0x1c, 0x20, 0x20, 0x20, 0x1c, 
	0x1a, 0x1a, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 
	0x1f, 0x1f, 0x2c, 0x2c, 0x2c, 0x2c, 0x22, 0x22, 
	0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x22, 
	0x2c, 0x1f, 0x1f, 0x1c, 0x1f, 0x1f, 0x1f, 0x1f, 
	0x2c, 0x2c, 0x22, 0x2c, 0x2c, 0x2c, 0x2c, 0x22, 
	0x45, 0x0f, 0x02, 0x0f, 0x55, 0x13, 0x26, 0x26, 
	0x56, 0x56, 0x56, 0x57, 0x26, 0x0f, 0x21, 0x21, 
	0x24, 0x24, 0x24, 0x24, 0x0c, 0x0c, 0x0c, 0x0f, 
	0x0f, 0x11, 0x11, 0x11, 0x11, 0x0f, 0x11, 0x2f, 
	0x26, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 
	0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x26, 
	0x2f, 0x11, 0x0f, 0x0f, 0x11, 0x11, 0x11, 0x26, 
	0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x26, 0x12, 
	0x12, 0x13, 0x13, 0x02, 0x11, 0x13, 0x12, 0x13, 
	0x46, 0x46, 0x46, 0x13, 0x13, 0x46, 0x13, 0x30, 
	0x13, 0x13, 0x12, 0x12, 0x13, 0x13, 0x13, 0x13, 
	0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x46, 
	0x58, 0x58, 0x46, 0x46, 0x46, 0x46, 0x46, 0x46, 
	0x46, 0x46, 0x46, 0x58, 0x59, 0x58, 0x46, 0x46, 
	0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x58, 
	0x46, 0x46, 0x46, 0x46, 0x58, 0x58, 0x46, 0x12, 
	0x12, 0x5a, 0x13, 0x02, 0x11, 0x06, 0x06, 0x13, 
	0x13, 0x13, 0x13, 0x13, 0x06, 0x59, 0x13, 0x01, 
	0x24, 0x24, 0x49, 0x49, 0x49, 0x41, 0x41, 0x41, 
	0x41, 0x41, 0x41, 0x41, 0x2e, 0x2e, 0x2e, 0x2e, 
	0x2e, 0x2e, 0x42, 0x2e, 0x2e, 0x2e, 0x2e, 0x42, 
	0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 
	0x42, 0x2e, 0x2e, 0x41, 0x41, 0x41, 0x2e, 0x2e, 
	0x42, 0x2e, 0x42, 0x42, 0x4d, 0x42, 0x4e, 0x26, 
	0x11, 0x11, 0x02, 0x02, 0x0a, 0x12, 0x02, 0x12, 
	0x12, 0x26, 0x12, 0x12, 0x12, 0x26, 0x21, 0x27, 
	0x1c, 0x1a, 0x1a, 0x1a, 0x1a, 0x1f, 0x1f, 0x1f, 
	0x1f, 0x1f, 0x2b, 0x2b, 0x2b, 0x2b, 0x2b, 0x2b, 
	0x2b, 0x2b, 0x2c, 0x2c, 0x22, 0x22, 0x22, 0x22, 
	0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 
	0x1d, 0x2b, 0x1f, 0x1f, 0x1f, 0x2b, 0x2b, 0x2b, 
	0x2c, 0x22, 0x22, 0x22, 0x2d, 0x2d, 0x2d, 0x5b, 
	0x5b, 0x0f, 0x02, 0x0f, 0x0d, 0x12, 0x12, 0x4e, 
	0x56, 0x46, 0x46, 0x12, 0x12, 0x0c, 0x33, 0x53, 
	0x5c, 0x15, 0x15, 0x28, 0x28, 0x28, 0x34, 0x34, 
	0x34, 0x28, 0x28, 0x34, 0x34, 0x34, 0x34, 0x20, 
	0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
	0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
	0x20, 0x20, 0x18, 0x34, 0x28, 0x34, 0x34, 0x20, 
	0x20, 0x20, 0x3f, 0x3f, 0x3f, 0x3f, 0x1f, 0x2c, 
	0x2c, 0x24, 0x12, 0x21, 0x21, 0x12, 0x26, 0x4d, 
	0x4d, 0x56, 0x4e, 0x26, 0x11, 0x16, 0x5d, 0x5e, 
	0x5c, 0x5c, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 
	0x15, 0x15, 0x15, 0x15, 0x28, 0x28, 0x28, 0x34, 
	0x34, 0x34, 0x28, 0x28, 0x34, 0x18, 0x18, 0x18, 
	0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 
	0x18, 0x18, 0x34, 0x34, 0x15, 0x28, 0x28, 0x34, 
	0x28, 0x34, 0x20, 0x20, 0x20, 0x20, 0x20, 0x3f, 
	0x1f, 0x24, 0x02, 0x1b, 0x09, 0x2f, 0x0f, 0x2e, 
	0x2e, 0x42, 0x42, 0x12, 0x21, 0x5f, 0x5e, 0x32, 
	0x15, 0x15, 0x15, 0x15, 0x28, 0x28, 0x28, 0x34, 
	0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 
	0x34, 0x34, 0x34, 0x34, 0x18, 0x18, 0x18, 0x18, 
	0x18, 0x18, 0x34, 0x16, 0x16, 0x16, 0x34, 0x34, 
	0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 
	0x34, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x20, 
	0x1a, 0x1d, 0x0c, 0x0a, 0x25, 0x24, 0x24, 0x24, 
	0x24, 0x0f, 0x0f, 0x12, 0x15, 0x5e, 0x32, 0x35, 
	0x18, 0x18, 0x18, 0x18, 0x20, 0x20, 0x20, 0x20, 
	0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
	0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x18, 
	0x18, 0x18, 0x18, 0x18, 0x34, 0x16, 0x16, 0x16, 
	0x16, 0x16, 0x34, 0x34, 0x18, 0x18, 0x18, 0x18, 
	0x20, 0x20, 0x20, 0x18, 0x18, 0x18, 0x18, 0x18, 
	0x19, 0x1a, 0x0d, 0x25, 0x19, 0x0d, 0x1d, 0x24, 
	0x0d, 0x0c, 0x0c, 0x12, 0x27, 0x35, 0x33, 0x32, 
	0x1a, 0x1a, 0x20, 0x20, 0x20, 0x2a, 0x2a, 0x2a, 
	0x20, 0x20, 0x20, 0x18, 0x18, 0x18, 0x18, 0x18, 
	0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 
	0x18, 0x18, 0x18, 0x18, 0x18, 0x16, 0x16, 0x16, 
	0x16, 0x16, 0x17, 0x18, 0x18, 0x17, 0x17, 0x18, 
	0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 
	0x18, 0x1a, 0x1a, 0x16, 0x39, 0x1d, 0x21, 0x1d, 
	0x0e, 0x0e, 0x0e, 0x11, 0x33, 0x39, 0x33, 0x35, 
	0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 
	0x17, 0x16, 0x15, 0x15, 0x14, 0x15, 0x15, 0x14, 
	0x14, 0x14, 0x14, 0x14, 0x15, 0x15, 0x14, 0x15, 
	0x15, 0x16, 0x16, 0x16, 0x15, 0x15, 0x15, 0x15, 
	0x16, 0x16, 0x16, 0x16, 0x15, 0x14, 0x14, 0x14, 
	0x14, 0x15, 0x15, 0x18, 0x18, 0x18, 0x16, 0x16, 
	0x19, 0x1a, 0x1a, 0x16, 0x16, 0x0e, 0x21, 0x1d, 
	0x1b, 0x0d, 0x0a, 0x11, 0x35, 0x27, 0x33, 0x3a, 
	0x1a, 0x1a, 0x1a, 0x1a, 0x2a, 0x60, 0x18, 0x18, 
	0x18, 0x17, 0x15, 0x15, 0x15, 0x16, 0x16, 0x14, 
	0x14, 0x36, 0x14, 0x14, 0x15, 0x16, 0x16, 0x15, 
	0x15, 0x15, 0x15, 0x14, 0x14, 0x14, 0x14, 0x14, 
	0x16, 0x16, 0x16, 0x16, 0x15, 0x15, 0x16, 0x15, 
	0x16, 0x16, 0x16, 0x15, 0x15, 0x15, 0x15, 0x16, 
	0x19, 0x40, 0x1a, 0x3c, 0x38, 0x1a, 0x1a, 0x1f, 
	0x1a, 0x1b, 0x0e, 0x12, 0x3a, 0x27, 0x33, 0x27, 
	0x40, 0x1a, 0x1a, 0x1a, 0x2a, 0x18, 0x18, 0x18, 
	0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 
	0x16, 0x16, 0x34, 0x18, 0x18, 0x18, 0x18, 0x18, 
	0x18, 0x18, 0x18, 0x18, 0x16, 0x16, 0x16, 0x16, 
	0x16, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 
	0x18, 0x18, 0x18, 0x16, 0x15, 0x15, 0x14, 0x16, 
	0x19, 0x19, 0x1a, 0x16, 0x36, 0x1a, 0x1a, 0x1a, 
	0x19, 0x19, 0x38, 0x3c, 0x37, 0x39, 0x33, 0x39, 
	0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 
	0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 
	0x18, 0x18, 0x18, 0x18, 0x20, 0x20, 0x20, 0x20, 
	0x20, 0x20, 0x20, 0x20, 0x20, 0x18, 0x18, 0x18, 
	0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 
	0x18, 0x18, 0x18, 0x18, 0x18, 0x34, 0x16, 0x16, 
	0x18, 0x17, 0x40, 0x27, 0x27, 0x1d, 0x1a, 0x1a, 
	0x1a, 0x40, 0x09, 0x0a, 0x37, 0x39, 0x39, 0x39, 
	
};

Gfx seesaw_platform__1_pal_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 seesaw_platform__1_pal_rgba16[] = {
	0x93, 0x51, 0x93, 0x0f, 0x92, 0xcd, 0x93, 0x0d, 
	0x92, 0xcf, 0x8a, 0x8d, 0x8a, 0x8b, 0x8a, 0xcd, 
	0x9b, 0x51, 0xab, 0x91, 0xa3, 0x4f, 0x9b, 0x4f, 
	0xa3, 0x4d, 0xab, 0x4f, 0xab, 0x8f, 0xa3, 0x0d, 
	0x9b, 0x0f, 0x9b, 0x0d, 0x92, 0xcb, 0x92, 0x8b, 
	0xcc, 0x57, 0xcc, 0x55, 0xc4, 0x55, 0xc4, 0x15, 
	0xc4, 0x13, 0xbc, 0x13, 0xbb, 0xd1, 0xb3, 0xd1, 
	0xbc, 0x11, 0xb3, 0x8f, 0xb3, 0xcf, 0xbb, 0xcf, 
	0xc4, 0x11, 0xb3, 0x91, 0xb3, 0x8d, 0xab, 0x8d, 
	0xab, 0x4d, 0xa3, 0x51, 0x9a, 0xcb, 0xd4, 0x99, 
	0xcc, 0x53, 0xcc, 0x13, 0xc3, 0xd1, 0xbb, 0x8f, 
	0xbb, 0x8d, 0xb3, 0x4d, 0xa3, 0x0b, 0x9b, 0x0b, 
	0xa3, 0x0f, 0xed, 0x1d, 0xe5, 0x1d, 0xdc, 0xdb, 
	0xc4, 0x53, 0xe4, 0xdb, 0xcc, 0x97, 0xd4, 0x97, 
	0xbc, 0x15, 0xdc, 0x99, 0xdc, 0x9b, 0xab, 0xd3, 
	0xb3, 0xd3, 0xa3, 0x91, 0xdc, 0xd9, 0xc3, 0xcf, 
	0xbb, 0xd3, 0xab, 0x0b, 0xa2, 0xcb, 0xc4, 0x0f, 
	0xbb, 0xcd, 0xb3, 0x4b, 0x92, 0x89, 0xc4, 0x51, 
	0xbc, 0x0f, 0xab, 0x0d, 0xc4, 0x57, 0xbc, 0x57, 
	0xb3, 0xd5, 0xa2, 0xc9, 0x9a, 0xc9, 0xcc, 0x93, 
	0xcc, 0x51, 0xc3, 0xcd, 0x9a, 0xcd, 0xed, 0x5d, 
	0xbb, 0x8b, 0xab, 0x51, 0x9a, 0x89, 0x92, 0xc9, 
	0x8a, 0x89, 0x8a, 0x49, 0x92, 0x8d, 0xab, 0x4b, 
	0xcc, 0x95, 0xf5, 0xa1, 0xf5, 0x5f, 0xe5, 0x1b, 
	0xc3, 0xd3, 
};

Gfx seesaw_platform__2_ci8_aligner[] = {gsSPEndDisplayList()};
u8 seesaw_platform__2_ci8[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 
	0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 
	0x02, 0x02, 0x02, 0x03, 0x04, 0x05, 0x06, 0x06, 
	0x07, 0x06, 0x08, 0x08, 0x09, 0x0a, 0x09, 0x0a, 
	0x0b, 0x0c, 0x0c, 0x0b, 0x0b, 0x0c, 0x0c, 0x0c, 
	0x0c, 0x0c, 0x0c, 0x0c, 0x0d, 0x0d, 0x0d, 0x0c, 
	0x0c, 0x0c, 0x0c, 0x0c, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x0e, 0x0f, 
	0x02, 0x02, 0x02, 0x10, 0x11, 0x12, 0x06, 0x06, 
	0x12, 0x12, 0x13, 0x14, 0x15, 0x16, 0x09, 0x0a, 
	0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x17, 0x17, 
	0x17, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 
	0x03, 0x17, 0x17, 0x0d, 0x17, 0x0d, 0x0d, 0x0c, 
	0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 
	0x02, 0x02, 0x06, 0x02, 0x09, 0x05, 0x06, 0x18, 
	0x07, 0x12, 0x13, 0x19, 0x1a, 0x1b, 0x1c, 0x0a, 
	0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0c, 
	0x0c, 0x0c, 0x0c, 0x0d, 0x0d, 0x0c, 0x0c, 0x0c, 
	0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x1d, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x01, 0x0f, 
	0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x0e, 
	0x0e, 0x0e, 0x05, 0x0d, 0x17, 0x1e, 0x07, 0x06, 
	0x12, 0x1e, 0x13, 0x1f, 0x09, 0x20, 0x09, 0x0a, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x0b, 0x0b, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x0b, 0x0b, 0x0b, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 
	0x21, 0x0f, 0x01, 0x01, 0x01, 0x01, 0x21, 0x0f, 
	0x0f, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x01, 
	0x01, 0x00, 0x01, 0x0f, 0x01, 0x0f, 0x22, 0x0f, 
	0x0f, 0x0f, 0x23, 0x24, 0x25, 0x13, 0x1e, 0x12, 
	0x12, 0x26, 0x26, 0x27, 0x02, 0x28, 0x16, 0x09, 
	0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 
	0x01, 0x01, 0x01, 0x01, 0x00, 0x0b, 0x0b, 0x01, 
	0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x21, 
	0x21, 0x21, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 
	0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x0b, 0x01, 
	0x01, 0x01, 0x01, 0x0f, 0x21, 0x22, 0x22, 0x22, 
	0x22, 0x05, 0x08, 0x29, 0x11, 0x26, 0x2a, 0x23, 
	0x23, 0x2b, 0x08, 0x27, 0x1e, 0x1a, 0x1a, 0x16, 
	0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 
	0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x2c, 0x01, 
	0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 
	0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 
	0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x2c, 0x01, 
	0x01, 0x01, 0x01, 0x01, 0x01, 0x2d, 0x22, 0x0f, 
	0x2d, 0x2e, 0x2f, 0x14, 0x1d, 0x26, 0x1f, 0x23, 
	0x23, 0x13, 0x08, 0x30, 0x08, 0x03, 0x31, 0x20, 
	0x01, 0x01, 0x01, 0x32, 0x32, 0x32, 0x32, 0x22, 
	0x21, 0x01, 0x01, 0x22, 0x22, 0x01, 0x01, 0x01, 
	0x01, 0x21, 0x22, 0x22, 0x22, 0x22, 0x0f, 0x0f, 
	0x22, 0x22, 0x22, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 
	0x0f, 0x0f, 0x01, 0x01, 0x01, 0x0f, 0x01, 0x01, 
	0x22, 0x22, 0x0f, 0x22, 0x22, 0x33, 0x22, 0x05, 
	0x05, 0x26, 0x2f, 0x34, 0x1e, 0x27, 0x35, 0x2b, 
	0x26, 0x36, 0x2f, 0x2f, 0x2f, 0x37, 0x16, 0x1a, 
	0x22, 0x22, 0x22, 0x22, 0x22, 0x38, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x23, 0x12, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x38, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x2e, 0x23, 0x23, 0x12, 0x14, 
	0x08, 0x35, 0x39, 0x2f, 0x13, 0x35, 0x35, 0x1f, 
	0x35, 0x35, 0x35, 0x1f, 0x1f, 0x26, 0x02, 0x03, 
	0x08, 0x08, 0x14, 0x14, 0x14, 0x14, 0x14, 0x13, 
	0x1e, 0x12, 0x12, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 
	0x13, 0x13, 0x23, 0x23, 0x13, 0x13, 0x13, 0x08, 
	0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x26, 
	0x08, 0x08, 0x14, 0x13, 0x12, 0x1e, 0x1e, 0x13, 
	0x23, 0x13, 0x26, 0x08, 0x08, 0x2a, 0x26, 0x30, 
	0x2f, 0x3a, 0x3a, 0x2f, 0x08, 0x3b, 0x3c, 0x35, 
	0x3d, 0x3c, 0x35, 0x35, 0x35, 0x35, 0x26, 0x37, 
	0x34, 0x34, 0x34, 0x19, 0x34, 0x34, 0x34, 0x34, 
	0x34, 0x08, 0x08, 0x2f, 0x2f, 0x2f, 0x2f, 0x2f, 
	0x2f, 0x2f, 0x2f, 0x2f, 0x2f, 0x2f, 0x2f, 0x1f, 
	0x1f, 0x1f, 0x2f, 0x2f, 0x1f, 0x1f, 0x2f, 0x2f, 
	0x2f, 0x2f, 0x30, 0x34, 0x08, 0x2f, 0x2f, 0x2f, 
	0x2f, 0x2f, 0x1f, 0x1f, 0x2f, 0x1f, 0x2f, 0x2f, 
	0x2f, 0x3e, 0x3a, 0x2f, 0x1f, 0x35, 0x3f, 0x40, 
	0x40, 0x40, 0x3a, 0x35, 0x35, 0x3b, 0x1f, 0x14, 
	0x24, 0x24, 0x07, 0x37, 0x37, 0x07, 0x18, 0x18, 
	0x07, 0x37, 0x37, 0x07, 0x07, 0x07, 0x06, 0x06, 
	0x06, 0x0f, 0x0f, 0x0f, 0x07, 0x05, 0x12, 0x1e, 
	0x14, 0x19, 0x19, 0x14, 0x14, 0x1e, 0x1e, 0x12, 
	0x07, 0x37, 0x37, 0x18, 0x37, 0x07, 0x06, 0x06, 
	0x0f, 0x07, 0x1e, 0x19, 0x14, 0x1e, 0x12, 0x12, 
	0x37, 0x08, 0x41, 0x2f, 0x2f, 0x35, 0x40, 0x2f, 
	0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x26, 0x07, 0x11, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x02, 0x24, 0x24, 0x02, 0x02, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x24, 0x24, 0x0f, 0x0f, 0x0f, 0x07, 
	0x07, 0x07, 0x07, 0x07, 0x06, 0x0f, 0x0f, 0x0f, 
	0x24, 0x24, 0x02, 0x00, 0x24, 0x02, 0x00, 0x00, 
	0x24, 0x0f, 0x06, 0x07, 0x07, 0x0f, 0x0f, 0x0f, 
	0x07, 0x1e, 0x2f, 0x42, 0x30, 0x1f, 0x35, 0x08, 
	0x08, 0x08, 0x2f, 0x2f, 0x1f, 0x11, 0x09, 0x16, 
	0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 
	0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x04, 0x17, 
	0x17, 0x0d, 0x0c, 0x0c, 0x0c, 0x1d, 0x1d, 0x1d, 
	0x02, 0x02, 0x02, 0x00, 0x1d, 0x1d, 0x00, 0x00, 
	0x00, 0x00, 0x1d, 0x0c, 0x0c, 0x0c, 0x04, 0x17, 
	0x0c, 0x0c, 0x1d, 0x02, 0x00, 0x1d, 0x02, 0x00, 
	0x24, 0x05, 0x12, 0x42, 0x10, 0x2f, 0x08, 0x43, 
	0x14, 0x14, 0x08, 0x30, 0x26, 0x44, 0x31, 0x45, 
	0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 
	0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 
	0x03, 0x03, 0x03, 0x03, 0x17, 0x17, 0x17, 0x17, 
	0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 
	0x0c, 0x04, 0x17, 0x03, 0x03, 0x03, 0x03, 0x03, 
	0x03, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x0c, 
	0x0c, 0x06, 0x06, 0x37, 0x14, 0x2f, 0x14, 0x37, 
	0x37, 0x14, 0x42, 0x30, 0x07, 0x15, 0x45, 0x15, 
	0x46, 0x46, 0x46, 0x46, 0x46, 0x46, 0x46, 0x46, 
	0x46, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x46, 
	0x46, 0x46, 0x03, 0x03, 0x03, 0x03, 0x03, 0x17, 
	0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x1d, 0x1d, 
	0x0c, 0x0c, 0x0c, 0x17, 0x17, 0x17, 0x17, 0x17, 
	0x0d, 0x17, 0x03, 0x17, 0x03, 0x04, 0x0c, 0x0c, 
	0x02, 0x06, 0x37, 0x37, 0x37, 0x08, 0x37, 0x37, 
	0x12, 0x43, 0x42, 0x30, 0x09, 0x45, 0x15, 0x16, 
	0x47, 0x47, 0x47, 0x47, 0x47, 0x09, 0x09, 0x46, 
	0x03, 0x17, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 
	0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 
	0x0c, 0x1d, 0x00, 0x00, 0x00, 0x1d, 0x00, 0x00, 
	0x1d, 0x1d, 0x0c, 0x0c, 0x1d, 0x1d, 0x1d, 0x1d, 
	0x1d, 0x1d, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x00, 
	0x02, 0x24, 0x06, 0x11, 0x04, 0x14, 0x37, 0x12, 
	0x48, 0x08, 0x2f, 0x1f, 0x16, 0x20, 0x09, 0x1a, 
	0x46, 0x46, 0x46, 0x46, 0x46, 0x46, 0x46, 0x03, 
	0x04, 0x0c, 0x11, 0x02, 0x02, 0x02, 0x02, 0x1d, 
	0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x17, 0x17, 0x0d, 
	0x0c, 0x0c, 0x1d, 0x1d, 0x1d, 0x00, 0x00, 0x02, 
	0x00, 0x00, 0x1d, 0x1d, 0x00, 0x02, 0x00, 0x00, 
	0x1d, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x1d, 0x00, 
	0x02, 0x24, 0x06, 0x0c, 0x11, 0x12, 0x37, 0x12, 
	0x43, 0x14, 0x42, 0x35, 0x1a, 0x1a, 0x03, 0x1b, 
	0x0c, 0x04, 0x04, 0x17, 0x17, 0x04, 0x0c, 0x0c, 
	0x1d, 0x02, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 
	0x02, 0x00, 0x00, 0x00, 0x1d, 0x1d, 0x1d, 0x1d, 
	0x1d, 0x1d, 0x1d, 0x02, 0x02, 0x02, 0x02, 0x02, 
	0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 
	0x00, 0x00, 0x1d, 0x1d, 0x02, 0x24, 0x24, 0x24, 
	0x18, 0x06, 0x06, 0x14, 0x37, 0x12, 0x14, 0x08, 
	0x08, 0x30, 0x2f, 0x35, 0x1a, 0x0a, 0x03, 0x09, 
	0x02, 0x02, 0x00, 0x1d, 0x1d, 0x02, 0x02, 0x02, 
	0x24, 0x0f, 0x0f, 0x0f, 0x06, 0x06, 0x07, 0x07, 
	0x06, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x24, 
	0x24, 0x24, 0x18, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x18, 0x24, 0x02, 0x02, 0x24, 0x24, 0x0f, 0x0f, 
	0x0f, 0x0f, 0x24, 0x24, 0x07, 0x07, 0x37, 0x07, 
	0x37, 0x37, 0x12, 0x07, 0x03, 0x14, 0x42, 0x08, 
	0x48, 0x08, 0x08, 0x37, 0x15, 0x1c, 0x17, 0x1c, 
	0x24, 0x24, 0x02, 0x02, 0x02, 0x24, 0x24, 0x24, 
	0x24, 0x24, 0x0f, 0x0f, 0x06, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x07, 0x07, 0x07, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x07, 0x07, 0x07, 0x07, 0x37, 
	0x06, 0x06, 0x18, 0x24, 0x24, 0x06, 0x06, 0x06, 
	0x07, 0x37, 0x07, 0x07, 0x12, 0x1e, 0x14, 0x1e, 
	0x1e, 0x1e, 0x14, 0x24, 0x11, 0x08, 0x08, 0x08, 
	0x08, 0x2f, 0x2f, 0x08, 0x09, 0x03, 0x0d, 0x09, 
	0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x06, 0x06, 
	0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 
	0x24, 0x24, 0x18, 0x18, 0x18, 0x18, 0x24, 0x24, 
	0x24, 0x24, 0x24, 0x18, 0x18, 0x18, 0x18, 0x18, 
	0x18, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 
	0x18, 0x06, 0x06, 0x06, 0x07, 0x37, 0x37, 0x37, 
	0x37, 0x12, 0x14, 0x26, 0x37, 0x19, 0x34, 0x08, 
	0x08, 0x2f, 0x2f, 0x14, 0x09, 0x03, 0x0c, 0x0a, 
	0x02, 0x02, 0x02, 0x02, 0x02, 0x24, 0x24, 0x02, 
	0x02, 0x02, 0x02, 0x02, 0x02, 0x24, 0x24, 0x24, 
	0x24, 0x24, 0x24, 0x24, 0x18, 0x18, 0x24, 0x24, 
	0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 
	0x24, 0x24, 0x24, 0x24, 0x02, 0x24, 0x24, 0x24, 
	0x24, 0x06, 0x06, 0x07, 0x07, 0x07, 0x07, 0x07, 
	0x06, 0x37, 0x37, 0x10, 0x17, 0x37, 0x49, 0x42, 
	0x08, 0x30, 0x2f, 0x18, 0x16, 0x0c, 0x0c, 0x09, 
	0x02, 0x02, 0x02, 0x02, 0x24, 0x24, 0x18, 0x18, 
	0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x18, 
	0x18, 0x18, 0x24, 0x18, 0x18, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x18, 0x18, 
	0x18, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x18, 
	0x24, 0x06, 0x07, 0x37, 0x37, 0x37, 0x07, 0x37, 
	0x4a, 0x37, 0x37, 0x4b, 0x0c, 0x49, 0x49, 0x42, 
	0x30, 0x30, 0x2f, 0x1f, 0x03, 0x03, 0x00, 0x1c, 
	0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 
	0x11, 0x11, 0x0c, 0x1d, 0x11, 0x11, 0x11, 0x11, 
	0x11, 0x02, 0x02, 0x02, 0x02, 0x18, 0x18, 0x18, 
	0x24, 0x24, 0x24, 0x18, 0x18, 0x18, 0x18, 0x18, 
	0x18, 0x24, 0x02, 0x02, 0x1d, 0x11, 0x11, 0x02, 
	0x02, 0x24, 0x18, 0x24, 0x18, 0x18, 0x18, 0x06, 
	0x12, 0x49, 0x14, 0x08, 0x14, 0x42, 0x42, 0x34, 
	0x30, 0x29, 0x2f, 0x35, 0x11, 0x0a, 0x02, 0x03, 
	0x02, 0x02, 0x24, 0x24, 0x24, 0x02, 0x02, 0x02, 
	0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 
	0x02, 0x24, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 
	0x18, 0x18, 0x18, 0x06, 0x06, 0x37, 0x37, 0x37, 
	0x37, 0x07, 0x18, 0x02, 0x02, 0x18, 0x18, 0x18, 
	0x18, 0x18, 0x18, 0x18, 0x06, 0x37, 0x37, 0x14, 
	0x14, 0x14, 0x34, 0x1e, 0x24, 0x30, 0x30, 0x2f, 
	0x2f, 0x2f, 0x3a, 0x35, 0x49, 0x16, 0x0c, 0x1c, 
	0x18, 0x18, 0x06, 0x07, 0x07, 0x07, 0x07, 0x07, 
	0x07, 0x07, 0x37, 0x37, 0x37, 0x12, 0x12, 0x12, 
	0x37, 0x37, 0x37, 0x37, 0x12, 0x12, 0x12, 0x43, 
	0x14, 0x14, 0x43, 0x43, 0x14, 0x14, 0x14, 0x14, 
	0x49, 0x37, 0x37, 0x37, 0x37, 0x37, 0x43, 0x49, 
	0x37, 0x12, 0x12, 0x12, 0x12, 0x14, 0x14, 0x42, 
	0x14, 0x14, 0x30, 0x18, 0x11, 0x2f, 0x2f, 0x2f, 
	0x3a, 0x2f, 0x3a, 0x3a, 0x30, 0x09, 0x0a, 0x4c, 
	0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 
	0x37, 0x37, 0x37, 0x49, 0x49, 0x49, 0x49, 0x10, 
	0x10, 0x10, 0x37, 0x37, 0x37, 0x49, 0x10, 0x10, 
	0x10, 0x10, 0x10, 0x10, 0x10, 0x14, 0x14, 0x14, 
	0x10, 0x10, 0x10, 0x37, 0x49, 0x10, 0x10, 0x10, 
	0x49, 0x37, 0x10, 0x10, 0x49, 0x14, 0x14, 0x42, 
	0x42, 0x34, 0x2f, 0x1f, 0x26, 0x2f, 0x3a, 0x3a, 
	0x3a, 0x3a, 0x3a, 0x3a, 0x35, 0x11, 0x16, 0x09, 
	0x37, 0x37, 0x10, 0x10, 0x10, 0x49, 0x37, 0x37, 
	0x37, 0x37, 0x37, 0x49, 0x49, 0x49, 0x49, 0x49, 
	0x37, 0x37, 0x49, 0x10, 0x10, 0x10, 0x10, 0x10, 
	0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 
	0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 
	0x10, 0x10, 0x10, 0x49, 0x49, 0x10, 0x14, 0x42, 
	0x42, 0x30, 0x3a, 0x25, 0x04, 0x2f, 0x3a, 0x39, 
	0x4d, 0x4d, 0x4e, 0x3e, 0x3a, 0x34, 0x03, 0x4b, 
	0x42, 0x42, 0x34, 0x34, 0x34, 0x34, 0x34, 0x42, 
	0x14, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 
	0x42, 0x42, 0x34, 0x34, 0x34, 0x34, 0x34, 0x42, 
	0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 
	0x14, 0x14, 0x14, 0x10, 0x14, 0x10, 0x14, 0x14, 
	0x42, 0x34, 0x34, 0x34, 0x34, 0x34, 0x29, 0x29, 
	0x29, 0x2f, 0x4f, 0x25, 0x49, 0x3a, 0x3a, 0x39, 
	0x39, 0x4e, 0x39, 0x3e, 0x35, 0x35, 0x18, 0x10, 
	0x2f, 0x2f, 0x2f, 0x2f, 0x2f, 0x2f, 0x2f, 0x2f, 
	0x2f, 0x2f, 0x2f, 0x2f, 0x2f, 0x2f, 0x2f, 0x2f, 
	0x2f, 0x2f, 0x2f, 0x2f, 0x2f, 0x2f, 0x2f, 0x29, 
	0x30, 0x29, 0x29, 0x29, 0x29, 0x29, 0x29, 0x30, 
	0x30, 0x30, 0x08, 0x30, 0x08, 0x30, 0x30, 0x2f, 
	0x2f, 0x2f, 0x2f, 0x2f, 0x2f, 0x2f, 0x2f, 0x2f, 
	0x2f, 0x39, 0x3a, 0x34, 0x42, 0x50, 0x39, 0x3a, 
	0x4f, 0x4f, 0x35, 0x35, 0x35, 0x35, 0x2a, 0x2f, 
	0x3a, 0x3a, 0x3a, 0x3a, 0x3a, 0x40, 0x3c, 0x3c, 
	0x3c, 0x3c, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 
	0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 
	0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x51, 0x51, 0x51, 
	0x4f, 0x3a, 0x3a, 0x3a, 0x3a, 0x40, 0x3f, 0x3f, 
	0x3f, 0x3f, 0x3f, 0x3f, 0x52, 0x52, 0x52, 0x51, 
	0x51, 0x3f, 0x4f, 0x2f, 0x34, 0x3a, 0x3a, 0x3a, 
	0x3a, 0x3a, 0x3a, 0x35, 0x35, 0x35, 0x35, 0x3a, 
	
};

Gfx seesaw_platform__2_pal_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 seesaw_platform__2_pal_rgba16[] = {
	0xc4, 0x13, 0xc4, 0x11, 0xbc, 0x13, 0xcc, 0x97, 
	0xc4, 0x57, 0xb3, 0x8f, 0xb3, 0xd1, 0xb3, 0x91, 
	0x9b, 0x0d, 0xd4, 0x99, 0xdc, 0x99, 0xc4, 0x53, 
	0xc4, 0x55, 0xcc, 0x55, 0xbc, 0x11, 0xbb, 0xd1, 
	0xa3, 0x51, 0xbc, 0x15, 0xab, 0x8f, 0xa3, 0x4d, 
	0xa3, 0x4f, 0xe4, 0xdb, 0xdc, 0xdb, 0xcc, 0x57, 
	0xb3, 0xd3, 0xa3, 0x0f, 0xe5, 0x1d, 0xe5, 0x1b, 
	0xd4, 0x97, 0xc4, 0x15, 0xab, 0x4f, 0x92, 0xcb, 
	0xed, 0x5d, 0xc3, 0xd1, 0xbb, 0xcf, 0xab, 0x4d, 
	0xbb, 0xd3, 0xab, 0x93, 0xa3, 0x0d, 0x9a, 0xcb, 
	0xf5, 0x5f, 0x93, 0x0f, 0x9a, 0xcd, 0xa3, 0x0b, 
	0xc4, 0x51, 0xc3, 0xcf, 0xb3, 0x8d, 0x92, 0xcd, 
	0x93, 0x0d, 0xed, 0x5f, 0xc4, 0x0f, 0xbb, 0x8f, 
	0x9b, 0x0f, 0x92, 0x8b, 0x9b, 0x0b, 0xab, 0x91, 
	0xb3, 0xcf, 0x8a, 0x8d, 0x8a, 0x8b, 0x92, 0x89, 
	0x8a, 0x49, 0x8a, 0x89, 0x82, 0x8b, 0x82, 0x49, 
	0x8a, 0x4b, 0x8a, 0xcb, 0x9b, 0x4f, 0xa3, 0x8f, 
	0xdc, 0x9b, 0xed, 0x1d, 0xcc, 0x99, 0xd4, 0x9b, 
	0x9b, 0x4d, 0xa3, 0x91, 0xab, 0xd1, 0xbc, 0x55, 
	0xdc, 0xd9, 0x8a, 0xcd, 0x82, 0x8d, 0x82, 0x4b, 
	0x92, 0x8d, 0x7a, 0x49, 0x7a, 0x09, 
};

Vtx seesaw_platform_000_displaylist_mesh_layer_1_vtx_0[16] = {
	{{ {-181, 0, -904}, 0, {1840, -1360}, {183, 183, 183, 255} }},
	{{ {-181, 0, 904}, 0, {-1872, -1360}, {183, 183, 73, 255} }},
	{{ {-181, 51, 904}, 0, {-1872, -592}, {183, 73, 73, 255} }},
	{{ {-181, 51, -904}, 0, {1840, -592}, {183, 73, 183, 255} }},
	{{ {0, 51, -904}, 0, {1840, 432}, {0, 90, 166, 255} }},
	{{ {0, 51, 904}, 0, {-1872, 432}, {0, 90, 90, 255} }},
	{{ {-181, 0, 904}, 0, {1840, -592}, {183, 183, 73, 255} }},
	{{ {-181, 0, -904}, 0, {-1872, -592}, {183, 183, 183, 255} }},
	{{ {0, 0, -904}, 0, {-1872, 432}, {0, 166, 166, 255} }},
	{{ {0, 0, 904}, 0, {1840, 432}, {0, 166, 90, 255} }},
	{{ {-181, 0, 904}, 0, {-2256, -592}, {183, 183, 73, 255} }},
	{{ {0, 0, 904}, 0, {-2256, 432}, {0, 166, 90, 255} }},
	{{ {0, 51, 904}, 0, {-1872, 432}, {0, 90, 90, 255} }},
	{{ {0, 51, -904}, 0, {1840, 432}, {0, 90, 166, 255} }},
	{{ {0, 0, -904}, 0, {2224, 432}, {0, 166, 166, 255} }},
	{{ {-181, 0, -904}, 0, {2224, -592}, {183, 183, 183, 255} }},
};

Gfx seesaw_platform_000_displaylist_mesh_layer_1_tri_0[] = {
	gsSPVertex(seesaw_platform_000_displaylist_mesh_layer_1_vtx_0 + 0, 16, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(2, 4, 3, 0, 2, 5, 4, 0),
	gsSP2Triangles(6, 7, 8, 0, 6, 8, 9, 0),
	gsSP2Triangles(10, 11, 12, 0, 10, 12, 2, 0),
	gsSP2Triangles(3, 13, 14, 0, 3, 14, 15, 0),
	gsSPEndDisplayList(),
};

Vtx seesaw_platform_000_displaylist_mesh_layer_1_vtx_1[14] = {
	{{ {0, 0, 904}, 0, {-2256, 560}, {0, 166, 90, 255} }},
	{{ {181, 0, 904}, 0, {-2256, 1584}, {73, 183, 73, 255} }},
	{{ {181, 51, 904}, 0, {-1872, 1584}, {73, 73, 73, 255} }},
	{{ {0, 51, 904}, 0, {-1872, 560}, {0, 90, 90, 255} }},
	{{ {181, 51, -904}, 0, {1840, 1584}, {73, 73, 183, 255} }},
	{{ {181, 0, 904}, 0, {-1872, 2352}, {73, 183, 73, 255} }},
	{{ {181, 0, -904}, 0, {1840, 2352}, {73, 183, 183, 255} }},
	{{ {0, 51, -904}, 0, {1840, 560}, {0, 90, 166, 255} }},
	{{ {181, 0, -904}, 0, {2224, 1584}, {73, 183, 183, 255} }},
	{{ {0, 0, -904}, 0, {2224, 560}, {0, 166, 166, 255} }},
	{{ {0, 0, 904}, 0, {1840, 560}, {0, 166, 90, 255} }},
	{{ {181, 0, -904}, 0, {-1872, 1584}, {73, 183, 183, 255} }},
	{{ {181, 0, 904}, 0, {1840, 1584}, {73, 183, 73, 255} }},
	{{ {0, 0, -904}, 0, {-1872, 560}, {0, 166, 166, 255} }},
};

Gfx seesaw_platform_000_displaylist_mesh_layer_1_tri_1[] = {
	gsSPVertex(seesaw_platform_000_displaylist_mesh_layer_1_vtx_1 + 0, 14, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(3, 2, 4, 0, 5, 4, 2, 0),
	gsSP2Triangles(5, 6, 4, 0, 3, 4, 7, 0),
	gsSP2Triangles(7, 4, 8, 0, 7, 8, 9, 0),
	gsSP2Triangles(10, 11, 12, 0, 10, 13, 11, 0),
	gsSPEndDisplayList(),
};


Gfx mat_seesaw_platform__1[] = {
	gsSPSetLights1(seesaw_platform__1_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, seesaw_platform__1_pal_rgba16),
	gsDPSetTile(0, 0, 0, 256, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadTLUTCmd(5, 96),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 1, seesaw_platform__1_ci8),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 8, 0, 0, 0, G_TX_WRAP | G_TX_MIRROR, 5, 0, G_TX_WRAP | G_TX_MIRROR, 6, 0),
	gsDPSetTileSize(0, 0, 0, 252, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_seesaw_platform__1[] = {
	gsDPPipeSync(),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};

Gfx mat_seesaw_platform__2[] = {
	gsSPSetLights1(seesaw_platform__2_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, seesaw_platform__2_pal_rgba16),
	gsDPSetTile(0, 0, 0, 256, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadTLUTCmd(5, 82),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 1, seesaw_platform__2_ci8),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 8, 0, 0, 0, G_TX_WRAP | G_TX_MIRROR, 5, 0, G_TX_WRAP | G_TX_MIRROR, 6, 0),
	gsDPSetTileSize(0, 0, 0, 252, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_seesaw_platform__2[] = {
	gsDPPipeSync(),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};

Gfx seesaw_platform_000_displaylist_mesh_layer_1[] = {
	gsSPDisplayList(mat_seesaw_platform__1),
	gsSPDisplayList(seesaw_platform_000_displaylist_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_seesaw_platform__1),
	gsSPDisplayList(mat_seesaw_platform__2),
	gsSPDisplayList(seesaw_platform_000_displaylist_mesh_layer_1_tri_1),
	gsSPDisplayList(mat_revert_seesaw_platform__2),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

