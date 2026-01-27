/**
 * envfx_skybox.c
 * Credits to DanGPTV for the base code!
 **/

#include <ultra64.h>

#include "camera.h"
#include "skybox_3d.h"

#define DISTANCE 0.97f

Gfx *sky_3d(s32 callContext, struct GraphNode *node, Mat4 mtxf) {
    switch (callContext) {
    case GEO_CONTEXT_RENDER:
      {
        struct GraphNodeGenerated *graphNode = (struct GraphNodeGenerated *) node;

        Gfx *dlE = alloc_display_list(6 * sizeof(Gfx));
        Gfx *dlS = dlE;
        Mtx *mtx = alloc_display_list(sizeof(Mtx));

        f32 x = (gCamera->pos[0] * DISTANCE);
        f32 y = (gCamera->pos[1] * DISTANCE);
        f32 z = (gCamera->pos[2] * DISTANCE);

        guTranslate(mtx, x, y, z);
        gSPMatrix(dlE++, mtx, G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_PUSH);

        gSPClearGeometryMode(dlE++, G_ZBUFFER);

        switch (gCurrLevelNum) {
          case LEVEL_CASTLE_GROUNDS:
            gSPDisplayList(dlE++, &skybox_water);
            break;
          case LEVEL_CASTLE_COURTYARD:
            gSPDisplayList(dlE++, &skybox_water);
            break;
          case LEVEL_BOB:
            gSPDisplayList(dlE++, &skybox_water);
            break;
          case LEVEL_WF:
            gSPDisplayList(dlE++, &skybox_above_clouds);
            break;
          case LEVEL_SI:
            gSPDisplayList(dlE++, &skybox_water);
            break;
          case LEVEL_DDD:
            gSPDisplayList(dlE++, &skybox_water);
            break;
          case LEVEL_THI:
            gSPDisplayList(dlE++, &skybox_water);
            break;
          case LEVEL_TTM:
            gSPDisplayList(dlE++, &skybox_water);
            break;
          case LEVEL_BITDW:
            //gSPDisplayList(dlE++, &bitdw_skybox);
            break;
          case LEVEL_BOWSER_1:
            //gSPDisplayList(dlE++, &bitdw_skybox);
            break;
          case LEVEL_BITS:
            //gSPDisplayList(dlE++, &bits_skybox);
            break;
          case LEVEL_BOWSER_3:
            //gSPDisplayList(dlE++, &bits_skybox);
            break;
        }

        gSPSetGeometryMode(dlE++, G_ZBUFFER);

        gSPPopMatrix(dlE++, G_MTX_MODELVIEW);
        gSPEndDisplayList(dlE);

        graphNode->fnNode.node.flags = (graphNode->fnNode.node.flags & 0xFF) | 0x000;
        return dlS;
      }
    }

    return NULL;
}

#undef DISTANCE
