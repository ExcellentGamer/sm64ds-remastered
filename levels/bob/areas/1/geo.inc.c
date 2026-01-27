#include "src/game/envfx_skybox.h"

// 0x0E000488
const GeoLayout bob_geo_000488[] = {
    GEO_NODE_SCREEN_AREA(10, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2),
    GEO_OPEN_NODE(),
        GEO_ZBUFFER(1),
        GEO_OPEN_NODE(),
            GEO_CAMERA_FRUSTUM_WITH_FUNC(45, 100, 30000, geo_camera_fov),
            GEO_OPEN_NODE(),
                GEO_CAMERA(1, 0, 2000, 6000, 3072, 0, -4608, geo_camera_main),
                GEO_OPEN_NODE(),
                    GEO_ASM(0, sky_3d),
                    GEO_DISPLAY_LIST(LAYER_ALPHA, level_model_000_displaylist_mesh_layer_4),
		            GEO_DISPLAY_LIST(LAYER_OPAQUE, level_model_000_displaylist_mesh_layer_1),
		            GEO_DISPLAY_LIST(LAYER_TRANSPARENT, level_model_000_displaylist_mesh_layer_5),
                    GEO_RENDER_OBJ(),
                    GEO_ASM(0, geo_envfx_main),
                GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
        GEO_CLOSE_NODE(),
        GEO_ZBUFFER(0),
        GEO_OPEN_NODE(),
            GEO_ASM(0, geo_cannon_circle_base),
        GEO_CLOSE_NODE(),
    GEO_CLOSE_NODE(),
    GEO_END(),
};
