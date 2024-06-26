// respawner.inc.c

void bhv_respawner_loop(void) {
    if (!is_point_within_radius_of_player(o->oPosX, o->oPosY, o->oPosZ, o->oRespawnerMinSpawnDist)) {
        struct Object *spawnedObject = spawn_object(o, o->oRespawnerModelToRespawn,
                                                    o->oRespawnerBehaviorToRespawn);
        spawnedObject->oBhvParams = o->oBhvParams;
        spawnedObject->respawnInfo = o->respawnInfo;
        spawnedObject->respawnInfoPointer = o->respawnInfoPointer;
        o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
    }
}

void create_respawner(ModelID32 model, const BehaviorScript *behToSpawn, s32 minSpawnDist) {
    struct Object *respawner = spawn_object_abs_with_rot(o, 0, MODEL_NONE, bhvRespawner, o->oHomeX,
                                                         o->oHomeY, o->oHomeZ, 0, 0, 0);
    respawner->oBhvParams = o->oBhvParams;
    respawner->oRespawnerModelToRespawn = model;
    respawner->oRespawnerMinSpawnDist = minSpawnDist;
    respawner->oRespawnerBehaviorToRespawn = behToSpawn;
    respawner->respawnInfo = o->respawnInfo;
    respawner->respawnInfoPointer = o->respawnInfoPointer;
}
