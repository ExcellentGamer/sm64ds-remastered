#ifndef INTRO_GEO_H
#define INTRO_GEO_H

#include <PR/ultratypes.h>
#include <PR/gbi.h>

#include "config.h"
#include "types.h"
#include "engine/graph_node.h"

Gfx *geo_intro_super_player_64_logo(s32 sp50, struct GraphNode *sp54, UNUSED void *context);
Gfx *geo_intro_tm_copyright(s32 sp40, struct GraphNode *sp44, UNUSED void *context);
Gfx *geo_intro_regular_backdrop(s32 sp48, struct GraphNode *sp4c, UNUSED void *context);
Gfx *geo_intro_gameover_backdrop(s32 sp40, struct GraphNode *sp44, UNUSED void *context);

#ifdef RUMBLE_FEEDBACK
Gfx *geo_intro_rumble_pak_graphic(s32 state, struct GraphNode *node, UNUSED void *context);
#endif

#endif // INTRO_GEO_H
