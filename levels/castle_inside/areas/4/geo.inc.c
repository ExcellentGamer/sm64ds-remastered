#include "src/game/envfx_skybox.h"

const GeoLayout rec_room_geo[] = {
    GEO_NODE_SCREEN_AREA(10, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2),
    GEO_OPEN_NODE(),
        GEO_ZBUFFER(1),
        GEO_OPEN_NODE(),
            GEO_CAMERA_FRUSTUM_WITH_FUNC(64, 50, 7000, geo_camera_fov),
            GEO_OPEN_NODE(),
                GEO_CAMERA(CAMERA_MODE_FREE_ROAM, 0, 0, 0, 0, -1024, 0, geo_camera_main),
                GEO_OPEN_NODE(),
                    GEO_ASM(0, sky_3d),
                    GEO_DISPLAY_LIST(LAYER_OPAQUE, rec_room_1_r0_node_mesh_layer_1),
		            GEO_DISPLAY_LIST(LAYER_ALPHA, rec_room_1_r0_node_mesh_layer_4), // first geo
                    GEO_DISPLAY_LIST(LAYER_OPAQUE, rec_room_2_r1_node_mesh_layer_1),
		            GEO_DISPLAY_LIST(LAYER_ALPHA, rec_room_2_r1_node_mesh_layer_4), // second geo
                    GEO_DISPLAY_LIST(LAYER_OPAQUE, rec_room_3_r2_node_mesh_layer_1),
		            GEO_DISPLAY_LIST(LAYER_TRANSPARENT, rec_room_3_r2_node_mesh_layer_5),
		            GEO_DISPLAY_LIST(LAYER_ALPHA, rec_room_3_r2_node_mesh_layer_4), // third geo
                    GEO_ASM(0, geo_painting_update),
                    GEO_ASM(PAINTING_ID(6, 1), geo_painting_draw),
                    GEO_RENDER_OBJ(),
                    GEO_ASM(0, geo_envfx_main),
                GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
        GEO_CLOSE_NODE(),
    GEO_CLOSE_NODE(),
    GEO_END(),
};
