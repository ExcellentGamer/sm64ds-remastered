// File Originally made by the SM64COOPDX Team
// Modified by ExcellentGamer for DS Remastered's Purposes

#include "sm64.h"
#include "types.h"
#include "player.h"
#include "characters.h"
#include "hud.h"
#include "model_ids.h"
#include "object_constants.h"
#include "sounds.h"
#include "pc/configfile.h"
#include "audio/external.h"
#include "engine/graph_node.h"

struct Character gCharacters[CT_MAX] = {
    [CT_YOSHI] = {
        .modelId = MODEL_YOSHI,
        .capModelId = MODEL_NONE,
        .capMetalModelId = MODEL_NONE,
        .capWingModelId = MODEL_NONE,
        .capMetalWingModelId = MODEL_NONE,
    },

    [CT_MARIO] = {
        .modelId = MODEL_MARIO,
        .capModelId = MODEL_MARIOS_CAP,
        .capMetalModelId = MODEL_MARIOS_METAL_CAP,
        .capWingModelId = MODEL_MARIOS_WING_CAP,
        .capMetalWingModelId = MODEL_MARIOS_WINGED_METAL_CAP,
    },

    [CT_LUIGI] = {
        .modelId = MODEL_LUIGI,
        .capModelId = MODEL_LUIGIS_CAP,
        .capMetalModelId = MODEL_MARIOS_METAL_CAP, // TODO: Create Luigi Metal Cap
        .capWingModelId = MODEL_MARIOS_WING_CAP, // TODO: Create Luigi Wing Cap
        .capMetalWingModelId = MODEL_MARIOS_WINGED_METAL_CAP, // TODO: Create Luigi Winged Metal Cap
    },

    [CT_WARIO] = {
        .modelId = MODEL_MARIO, // TODO: Create Wario Model
        .capModelId = MODEL_MARIOS_CAP, // TODO: Create Wario Cap
        .capMetalModelId = MODEL_MARIOS_METAL_CAP, // TODO: Create Wario Metal Cap
        .capWingModelId = MODEL_MARIOS_WING_CAP, // TODO: Create Wario Wing Cap
        .capMetalWingModelId = MODEL_MARIOS_WINGED_METAL_CAP, // TODO: Create Wario Winged Metal Cap
    },

    [CT_WALUIGI] = {
        .modelId = MODEL_MARIO, // TODO: Create Waluigi Model
        .capModelId = MODEL_MARIOS_CAP, // TODO: Create Waluigi Cap
        .capMetalModelId = MODEL_MARIOS_METAL_CAP, // TODO: Create Waluigi Metal Cap
        .capWingModelId = MODEL_MARIOS_WING_CAP, // TODO: Create Waluigi Wing Cap
        .capMetalWingModelId = MODEL_MARIOS_WINGED_METAL_CAP, // TODO: Create Waluigi Winged Metal Cap
    },
};

s32 get_character_anim(struct PlayerState* m, enum PlayerAnimID characterAnim) {
    if (m == NULL) { return 0; }

    struct Character* character = ((m->character == NULL) ? &gCharacters[CT_YOSHI] : m->character);
    return ((characterAnim >= 0 && characterAnim < CHAR_ANIM_MAX && character->anims[characterAnim] >= CHAR_ANIM_MAX) ? character->anims[characterAnim] : (s32)characterAnim);
}
