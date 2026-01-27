#include "src/game/envfx_skybox.h"

const GeoLayout si_area_1[] = {
	GEO_NODE_SCREEN_AREA(10, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2),
	GEO_OPEN_NODE(),
		GEO_ZBUFFER(1),
		GEO_OPEN_NODE(),
			GEO_CAMERA_FRUSTUM_WITH_FUNC(45, 100, 30000, geo_camera_fov),
			GEO_OPEN_NODE(),
				GEO_CAMERA(CAMERA_MODE_FREE_ROAM, 0, 0, 0, 0, -1024, 0, geo_camera_main),
				GEO_OPEN_NODE(),
					GEO_ASM(0, sky_3d),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, si_model_r0_node_mesh_layer_1),
					GEO_DISPLAY_LIST(LAYER_ALPHA, si_model_r0_node_mesh_layer_4),
					GEO_DISPLAY_LIST(LAYER_TRANSPARENT, si_model_r0_node_mesh_layer_5),
					GEO_RENDER_OBJ(),
					GEO_ASM(0, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
