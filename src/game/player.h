#ifndef PLAYER_H
#define PLAYER_H

#include <PR/ultratypes.h>

#include "macros.h"
#include "types.h"

#include "engine/surface_collision.h"

s32 is_anim_at_end(struct PlayerState *m);
s32 is_anim_past_end(struct PlayerState *m);
s16 set_player_animation(struct PlayerState *m, s32 targetAnimID);
s16 set_player_anim_with_accel(struct PlayerState *m, s32 targetAnimID, s32 accel);
void set_anim_to_frame(struct PlayerState *m, s16 animFrame);
s32 is_anim_past_frame(struct PlayerState *m, s16 animFrame);
s16 find_player_anim_flags_and_translation(struct Object *o, s32 yaw, Vec3s translation);
void update_player_pos_for_anim(struct PlayerState *m);
s16 return_player_anim_y_translation(struct PlayerState *m);
void play_sound_if_no_flag(struct PlayerState *m, u32 soundBits, u32 flags);
void play_player_jump_sound(struct PlayerState *m);
void adjust_sound_for_speed(struct PlayerState *m);
void play_sound_and_spawn_particles(struct PlayerState *m, u32 soundBits, u32 waveParticleType);
void play_player_action_sound(struct PlayerState *m, u32 soundBits, u32 waveParticleType);
void play_player_landing_sound(struct PlayerState *m, u32 soundBits);
void play_player_landing_sound_once(struct PlayerState *m, u32 soundBits);
void play_player_heavy_landing_sound(struct PlayerState *m, u32 soundBits);
void play_player_heavy_landing_sound_once(struct PlayerState *m, u32 soundBits);
void play_player_sound(struct PlayerState *m, s32 primarySoundBits, s32 scondarySoundBits);
void player_set_forward_vel(struct PlayerState *m, f32 speed);
s32 player_get_floor_class(struct PlayerState *m);
u32 player_get_terrain_sound_addend(struct PlayerState *m);
struct Surface *resolve_and_return_wall_collisions(Vec3f pos, f32 offset, f32 radius);
void resolve_and_return_wall_collisions_data(Vec3f pos, f32 offset, f32 radius, struct WallCollisionData *collisionData);
f32 vec3f_find_ceil(Vec3f pos, f32 height, struct Surface **ceil);
s32 player_facing_downhill(struct PlayerState *m, s32 turnYaw);
u32 player_floor_is_slippery(struct PlayerState *m);
s32 player_floor_is_slope(struct PlayerState *m);
s32 player_floor_is_steep(struct PlayerState *m);
f32 find_floor_height_relative_polar(struct PlayerState *m, s16 angleFromPlayer, f32 distFromPlayer);
s16 find_floor_slope(struct PlayerState *m, s16 yawOffset);
void update_player_sound_and_camera(struct PlayerState *m);
void set_steep_jump_action(struct PlayerState *m);
u32 set_player_action(struct PlayerState *, u32 action, u32 actionArg);
s32 set_jump_from_landing(struct PlayerState *m);
s32 set_jumping_action(struct PlayerState *m, u32 action, u32 actionArg);
s32 drop_and_set_player_action(struct PlayerState *m, u32 action, u32 actionArg);
s32 hurt_and_set_player_action(struct PlayerState *m, u32 action, u32 actionArg, s16 hurtCounter);
s32 check_common_action_exits(struct PlayerState *m);
s32 check_common_hold_action_exits(struct PlayerState *m);
s32 transition_submerged_to_walking(struct PlayerState *m);
s32 transition_submerged_to_airborne(struct PlayerState *m);
s32 set_water_plunge_action(struct PlayerState *m);
u32 update_and_return_cap_flags(struct PlayerState *m);
s32 execute_player_action(UNUSED struct Object *o);
void init_player(void);
void init_player_from_save_file(void);

extern int curChar;

#endif // PLAYER_H
