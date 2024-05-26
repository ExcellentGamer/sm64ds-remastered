// tower_door.inc.c

void bhv_tower_door_loop(void) {
    if (o->oTimer == 0) {
        o->oMoveAngleYaw -= 0x4000;
    }

    if (check_player_attacking(0) != 0) {
        obj_explode_and_spawn_coins(80.0f, 0);
        create_sound_spawner(SOUND_GENERAL_WALL_EXPLOSION);
    }
}
