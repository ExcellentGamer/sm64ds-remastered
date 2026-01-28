#ifndef PLAYER_ACTIONS_AIRBORNE_H
#define PLAYER_ACTIONS_AIRBORNE_H

#include <PR/ultratypes.h>

#include "types.h"

void update_air_without_turn(struct PlayerState *m);
s32 check_fall_damage_or_get_stuck(struct PlayerState *m, u32 hardFallAction);
s32 player_execute_airborne_action(struct PlayerState *m);

#endif // PLAYER_ACTIONS_AIRBORNE_H
