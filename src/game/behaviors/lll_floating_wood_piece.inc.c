// lll_floating_wood_piece.inc.c

void bhv_lll_wood_piece_loop(void) {
    if (o->oTimer == 0) {
        o->oPosY -= 100.0f;
    }

    o->oPosY += sins(o->oLLLWoodPieceOscillationTimer) * 3.0f;
    o->oLLLWoodPieceOscillationTimer += 0x400;

    if (o->parentObj->oAction == 2) {
        obj_mark_for_deletion(o);
    }
}

void bhv_lll_floating_wood_bridge_loop(void) {
    struct Object *sp3C;
    s32 i;
    switch (o->oAction) {
        case 0:
#ifndef NODRAWINGDISTANCE
            if (o->oDistanceToPlayer < 2500.0f) {
#endif
                for (i = 1; i < 4; i++) {
                    sp3C = spawn_object_relative(0, (i - 2) * 300, 0, 0, o,
                                                 MODEL_LLL_WOOD_BRIDGE, bhvLLLWoodPiece);
                    sp3C->oLLLWoodPieceOscillationTimer = i * 0x1000;
                }
                o->oAction = 1;
#ifndef NODRAWINGDISTANCE
            }
#endif
            break;

        case 1:
#ifndef NODRAWINGDISTANCE
            if (o->oDistanceToPlayer > 2600.0f) {
                o->oAction = 2;
            }
#endif
            break;

        case 2:
            o->oAction = 0;
            break;
    }
}
