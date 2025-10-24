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

        // SFX
        .soundPunchYah = SOUND_YOSHI_PUNCH_YAH,
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

struct Character* get_character(struct PlayerState* m) {
    return (m == NULL || m->character == NULL)
        ? &gCharacters[CT_YOSHI]
        : m->character;
}

static s32 get_character_sound(struct PlayerState* m, enum CharacterSound characterSound) {
    struct Character* character = ((m == NULL || m->character == NULL) ? &gCharacters[CT_YOSHI] : m->character);

    if (m == NULL || m->playerObj == NULL) {
        return 0;
    }

    if (characterSound < 0 || characterSound >= CHAR_SOUND_MAX) {
        return 0;
    }
    return character->sounds[characterSound];
}

static void play_character_sound_internal(struct PlayerState *m, enum CharacterSound characterSound, u32 offset, u32 flags) {
    if (m != NULL && (m->flags & flags) == 0) {
        s32 sound = get_character_sound(m, characterSound);
        if (sound != 0) {
            struct Character* character = get_character(m);
            f32 *pos = (m->playerObj != NULL ? m->playerObj->header.gfx.cameraToObject : gGlobalSoundSource);
            play_sound(sound + offset, pos); // Potential bug here because I changed it xD
        }
        m->flags |= flags;
    }
}

void play_character_sound(struct PlayerState* m, enum CharacterSound characterSound) {
    play_character_sound_internal(m, characterSound, 0, 0);
}

void play_character_sound_offset(struct PlayerState* m, enum CharacterSound characterSound, u32 offset) {
    play_character_sound_internal(m, characterSound, offset, 0);
}

void play_character_sound_if_no_flag(struct PlayerState* m, enum CharacterSound characterSound, u32 flags) {
    play_character_sound_internal(m, characterSound, 0, flags);
}
