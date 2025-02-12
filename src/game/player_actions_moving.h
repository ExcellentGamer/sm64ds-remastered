#ifndef MARIO_ACTIONS_MOVING
#define MARIO_ACTIONS_MOVING

#include <PR/ultratypes.h>

#include "types.h"

void play_step_sound(struct PlayerState *m, s16 frame1, s16 frame2);
s32 mario_execute_moving_action(struct PlayerState *m);

#endif // MARIO_ACTIONS_MOVING
