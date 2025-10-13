#ifndef PLAYER_MISC_H
#define PLAYER_MISC_H

#include <PR/ultratypes.h>

#include "macros.h"
#include "types.h"

extern struct GraphNodeObject gMirrorPlayer;
extern struct PlayerBodyState gBodyStates[2];

#ifdef GODDARD_MFACE
Gfx *geo_draw_mario_head_goddard(s32 callContext, struct GraphNode *node, Mat4 *c);
#endif

void bhv_toad_message_loop(void);
void bhv_toad_message_init(void);
void bhv_unlock_door_star_init(void);
void bhv_unlock_door_star_loop(void);
Gfx *geo_mirror_player_set_alpha(s32 callContext, struct GraphNode *node, UNUSED Mat4 *c);
Gfx *geo_switch_player_stand_run(s32 callContext, struct GraphNode *node, UNUSED Mat4 *mtx);
Gfx *geo_switch_player_eyes(s32 callContext, struct GraphNode *node, UNUSED Mat4 *c);
Gfx *geo_player_tilt_torso(s32 callContext, struct GraphNode *node, UNUSED Mat4 *c);
Gfx *geo_player_head_rotation(s32 callContext, struct GraphNode *node, UNUSED Mat4 *c);
Gfx *geo_switch_player_hand(s32 callContext, struct GraphNode *node, UNUSED Mat4 *c);
Gfx *geo_player_hand_foot_scaler(s32 callContext, struct GraphNode *node, UNUSED Mat4 *c);
Gfx *geo_switch_player_cap_effect(s32 callContext, struct GraphNode *node, UNUSED Mat4 *c);
Gfx *geo_switch_player_cap_on_off(s32 callContext, struct GraphNode *node, UNUSED Mat4 *c);
Gfx *geo_player_rotate_wing_cap_wings(s32 callContext, struct GraphNode *node, UNUSED Mat4 *c);
Gfx *geo_switch_player_hand_grab_pos(s32 callContext, struct GraphNode *b, Mat4 *mtx);
Gfx *geo_render_mirror_player(s32 callContext, struct GraphNode *node, UNUSED Mat4 *c);
Gfx *geo_mirror_player_backface_culling(s32 callContext, struct GraphNode *node, UNUSED Mat4 *c);
Gfx *geo_switch_yoshi_face(s32 callContext, struct GraphNode *node, UNUSED Mat4 *c);

#endif // PLAYER_MISC_H
