#include <ultra64.h>

#include "actors/common1.h"
#include "area.h"
#include "audio/external.h"
#include "camera.h"
#include "course_table.h"
#include "dialog_ids.h"
#include "engine/math_util.h"
#include "eu_translation.h"
#include "game_init.h"
#include "gfx_dimensions.h"
#include "ingame_menu.h"
#include "level_update.h"
#include "levels/castle_grounds/header.h"
#include "memory.h"
#include "print.h"
#include "save_file.h"
#include "segment2.h"
#include "segment7.h"
#include "seq_ids.h"
#include "sm64.h"
#include "text_strings.h"
#include "types.h"
#include "macros.h"

#ifdef VERSION_EU
#undef LANGUAGE_FUNCTION
#define LANGUAGE_FUNCTION gInGameLanguage
#endif

#ifdef CHEATS_ACTIONS
#include "extras/cheats.h"
#endif
#ifdef EXT_OPTIONS_MENU
#include "extras/options_menu.h"
#endif

u16 gMenuTextColorTransTimer;
s8 gLastDialogLineNum;
s32 gDialogVariable;
u16 gMenuTextAlpha;
#ifdef VERSION_EU
s16 gDialogX;
s16 gDialogY;
#endif
s16 gCutsceneMsgXOffset;
s16 gCutsceneMsgYOffset;
s8 gRedCoinsCollected;

extern u8 gLastCompletedCourseNum;
extern u8 gLastCompletedStarNum;

enum MenuState {
    MENU_STATE_0,
    MENU_STATE_1,
    MENU_STATE_2,
    MENU_STATE_3,
    MENU_STATE_DEFAULT = MENU_STATE_0,

    // Dialog
    MENU_STATE_DIALOG_OPENING = MENU_STATE_0,
    MENU_STATE_DIALOG_OPEN = MENU_STATE_1,
    MENU_STATE_DIALOG_SCROLLING = MENU_STATE_2,
    MENU_STATE_DIALOG_CLOSING = MENU_STATE_3,

    // Pause Screen
    MENU_STATE_PAUSE_SCREEN_OPENING = MENU_STATE_0,
    MENU_STATE_PAUSE_SCREEN_COURSE = MENU_STATE_1,
    MENU_STATE_PAUSE_SCREEN_CASTLE = MENU_STATE_2,

    // Course Complete Screen
    MENU_STATE_COURSE_COMPLETE_SCREEN_OPENING = MENU_STATE_0,
    MENU_STATE_COURSE_COMPLETE_SCREEN_OPEN = MENU_STATE_1
};

enum DialogBoxPageState {
    DIALOG_PAGE_STATE_NONE,
    DIALOG_PAGE_STATE_SCROLL,
    DIALOG_PAGE_STATE_END
};

enum DialogBoxType {
    DIALOG_TEXT_WHITE, // used in NPCs and level messages
    DIALOG_TEXT_BLACK  // used in signposts and wall signs and etc
};

#define DIALOG_BOX_ANGLE_DEFAULT 90.0f
#define DIALOG_BOX_SCALE_DEFAULT 19.0f

#if defined(VERSION_US) || defined(VERSION_EU) || defined(VERSION_CN)
u8 gDialogCharWidths[256] = { // TODO: Is there a way to auto generate this?
    7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  6,  6,  6,  6,  6,  6,
    6,  6,  5,  6,  6,  5,  8,  8,  6,  6,  6,  6,  6,  5,  6,  6,
    8,  7,  6,  6,  6,  5,  5,  6,  5,  5,  6,  5,  4,  5,  5,  3,
    7,  5,  5,  5,  6,  5,  5,  5,  5,  5,  7,  7,  5,  5,  4,  4,
    8,  6,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    8,  8,  8,  8,  7,  7,  6,  7,  7,  0,  0,  0,  0,  0,  0,  0,
#ifdef VERSION_EU
    6,  6,  6,  0,  6,  6,  6,  0,  0,  0,  0,  0,  0,  0,  0,  4,
    5,  5,  5,  5,  6,  6,  6,  6,  0,  0,  0,  0,  0,  0,  0,  0,
    5,  5,  5,  0,  6,  6,  6,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  5,  5,  0,  0,  6,  6,  0,  0,  0,  0,  0,  0,  0,  5,  6,
    0,  4,  4,  0,  0,  5,  5,  0,  0,  0,  0,  0,  0,  0,  0,  0,
#else
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  4,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  5,  6,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
#endif
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
#ifdef VERSION_EU
    7,  5, 10,  5,  9,  8,  4,  0,  0,  0,  0,  5,  5,  6,  5,  0,
#else
    7,  5, 10,  5,  9,  8,  4,  0,  0,  0,  0,  0,  0,  0,  0,  0,
#endif
    0,  0,  5,  7,  7,  6,  6,  8,  0,  8, 10,  6,  4, 10,  0,  0
};
#endif

s8 gMenuState = MENU_STATE_DEFAULT;
f32 gDialogBoxAngle = DIALOG_BOX_ANGLE_DEFAULT;
f32 gDialogBoxScale = DIALOG_BOX_SCALE_DEFAULT;
s16 gDialogScrollOffsetY = 0;
s8 gDialogBoxType = DIALOG_TEXT_WHITE;
s16 gDialogID = DIALOG_NONE;
s16 gNextDialogPageStartStrIndex = 0;
s16 gDialogPageStartStrIndex = 0;
#ifdef VERSION_EU
s32 gInGameLanguage = LANGUAGE_ENGLISH;
#endif
s8 gMenuLineNum = 1;
s8 gDialogWithChoice = FALSE;
u8 gMenuHoldKeyIndex = 0;
u8 gMenuHoldKeyTimer = 0;
s32 gDialogResponse = DIALOG_RESPONSE_NONE;

#if !defined(EXTERNAL_DATA) && (defined(VERSION_EU) || defined(VERSION_SH))
#if defined(VERSION_EU)
#define CHCACHE_BUFLEN (8 * 8)  // EU only converts 8x8
#elif defined(VERSION_CN)
#define CHCACHE_BUFLEN (8 * 8) // iQue uses 2 8x8 textures for one character
#else // JP & SH
#define CHCACHE_BUFLEN (8 * 16) // JP only converts 8x16 or 16x8 characters
#endif

// stores char data unpacked from ia1 to ia8 or ia4
// so that it won't be reconverted every time a character is rendered
static struct CachedChar { u8 used; u8 data[CHCACHE_BUFLEN]; } charCache[256];
#endif // VERSION

#ifdef HIGH_FPS_PC
static Gfx *sInterpolatedDialogOffsetPos;
static f32 sInterpolatedDialogOffset;
static Gfx *sInterpolatedDialogRotationPos;
static f32 sInterpolatedDialogScale;
static f32 sInterpolatedDialogRotation;
static Gfx *sInterpolatedDialogZoomPos;

void patch_interpolated_dialog(void) {
    Mtx *matrix;

    if (sInterpolatedDialogOffsetPos != NULL) {
        matrix = (Mtx *) alloc_display_list(sizeof(Mtx));
        guTranslate(matrix, 0, sInterpolatedDialogOffset, 0);
        gSPMatrix(sInterpolatedDialogOffsetPos, VIRTUAL_TO_PHYSICAL(matrix), G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_NOPUSH);
        sInterpolatedDialogOffsetPos = NULL;
    }
    if (sInterpolatedDialogRotationPos != NULL) {
        matrix = (Mtx *) alloc_display_list(sizeof(Mtx));
        guScale(matrix, 1.0 / sInterpolatedDialogScale, 1.0 / sInterpolatedDialogScale, 1.0f);
        gSPMatrix(sInterpolatedDialogRotationPos++, VIRTUAL_TO_PHYSICAL(matrix), G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_NOPUSH);
        matrix = (Mtx *) alloc_display_list(sizeof(Mtx));
        guRotate(matrix, sInterpolatedDialogRotation * 4.0f, 0, 0, 1.0f);
        gSPMatrix(sInterpolatedDialogRotationPos, VIRTUAL_TO_PHYSICAL(matrix), G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_NOPUSH);
        sInterpolatedDialogRotationPos = NULL;
    }
    if (sInterpolatedDialogZoomPos != NULL) {
        matrix = (Mtx *) alloc_display_list(sizeof(Mtx));
        guTranslate(matrix, 65.0 - (65.0 / sInterpolatedDialogScale), (40.0 / sInterpolatedDialogScale) - 40, 0);
        gSPMatrix(sInterpolatedDialogZoomPos++, VIRTUAL_TO_PHYSICAL(matrix), G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_NOPUSH);
        matrix = (Mtx *) alloc_display_list(sizeof(Mtx));
        guScale(matrix, 1.0 / sInterpolatedDialogScale, 1.0 / sInterpolatedDialogScale, 1.0f);
        gSPMatrix(sInterpolatedDialogZoomPos, VIRTUAL_TO_PHYSICAL(matrix), G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_NOPUSH);
        sInterpolatedDialogZoomPos = NULL;
    }
}
#endif

void create_dl_identity_matrix(void) {
    Mtx *matrix = (Mtx *) alloc_display_list(sizeof(Mtx));

    if (matrix == NULL) {
        return;
    }

    // ex-alo change
    // Originally for GBI_FLOATS but it works on N64 and
    // its smaller that the original long matrix code
    guMtxIdent(matrix);

    gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(matrix), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(matrix), G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);
}

void create_dl_translation_matrix(s8 pushOp, f32 x, f32 y, f32 z) {
    Mtx *matrix = (Mtx *) alloc_display_list(sizeof(Mtx));

    if (matrix == NULL) {
        return;
    }

    guTranslate(matrix, x, y, z);

    if (pushOp == MENU_MTX_PUSH) {
        gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(matrix), G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_PUSH);
    }

    if (pushOp == MENU_MTX_NOPUSH) {
        gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(matrix), G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_NOPUSH);
    }
}

void create_dl_rotation_matrix(s8 pushOp, f32 a, f32 x, f32 y, f32 z) {
    Mtx *matrix = (Mtx *) alloc_display_list(sizeof(Mtx));

    if (matrix == NULL) {
        return;
    }

    guRotate(matrix, a, x, y, z);

    if (pushOp == MENU_MTX_PUSH) {
        gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(matrix), G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_PUSH);
    }

    if (pushOp == MENU_MTX_NOPUSH) {
        gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(matrix), G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_NOPUSH);
    }
}

void create_dl_scale_matrix(s8 pushOp, f32 x, f32 y, f32 z) {
    Mtx *matrix = (Mtx *) alloc_display_list(sizeof(Mtx));

    if (matrix == NULL) {
        return;
    }

    guScale(matrix, x, y, z);

    if (pushOp == MENU_MTX_PUSH) {
        gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(matrix), G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_PUSH);
    }

    if (pushOp == MENU_MTX_NOPUSH) {
        gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(matrix), G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_NOPUSH);
    }
}

void create_dl_ortho_matrix(void) {
    Mtx *matrix = (Mtx *) alloc_display_list(sizeof(Mtx));

    if (matrix == NULL) {
        return;
    }

    create_dl_identity_matrix();

    guOrtho(matrix, 0.0f, SCREEN_WIDTH, 0.0f, SCREEN_HEIGHT, -10.0f, 10.0f, 1.0f);

    // Should produce G_RDPHALF_1 in Fast3D
    gSPPerspNormalize(gDisplayListHead++, 0xFFFF);

    gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(matrix), G_MTX_PROJECTION | G_MTX_MUL | G_MTX_NOPUSH);
}

#if defined(VERSION_SH) || defined(VERSION_CN)
#ifdef VERSION_CN
static u8 *alloc_ia8_text_from_i1(u8 *in) {
    s32 i, j;
    u8 l, r;
    u8 bitMask = 0x80;
    u8 *out = alloc_display_list(8 * 8);

    if (out == NULL) {
        return NULL;
    }

    for (i = 0; i < 16; i++) {
        for (j = 0; j < 8;) {
            r = 0;
            l = ((in[i] & (bitMask >> j)) >> (7 - j)) != 0 ? 0xF0 : 0x00;
            j++;
            r = ((in[i] & (bitMask >> j)) >> (7 - j)) != 0 ? 0x0F : 0x00;
            out[i * 4 + j / 2] = l | r;
            CN_DEBUG_PRINTF(("%x, ", out[i * 4 + j / 2]));
            j++;
        }
        CN_DEBUG_PRINTF(("\n"));
    }

    return out;
}

#else

static void alloc_ia8_text_from_i1(u8 *out, u16 *in, s16 width, s16 height) {
    s32 inPos;
    u16 bitMask;
    u16 inWord;
    s16 outPos = 0;

    for (inPos = 0; inPos < (width * height) / 16; inPos++) {
        inWord = BE_TO_HOST16(in[inPos]);
        bitMask = 0x8000;

        while (bitMask != 0) {
            if (inWord & bitMask) {
                out[outPos] = 0xFF;
            } else {
                out[outPos] = 0x00;
            }

            bitMask /= 2;
            outPos++;
        }
    }
}
#endif

#ifndef VERSION_CN
static u8 *convert_ia8_char(u8 c, u16 *tex, s16 w, s16 h)
{
#ifdef EXTERNAL_DATA
    return (u8 *)tex; // the data's just a name
#else
    if (!tex) return NULL;
    if (!charCache[c].used) {
        charCache[c].used = 1;
        alloc_ia8_text_from_i1(charCache[c].data, tex, w, h);
    }
    return charCache[c].data;
#endif
}
#endif

#endif

void render_generic_char(u8 c) {
    void **fontLUT = segmented_to_virtual(main_font_lut);
    void *packedTexture = segmented_to_virtual(fontLUT[c]);

    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_IA, G_IM_SIZ_16b, 1, VIRTUAL_TO_PHYSICAL(packedTexture));
    gSPDisplayList(gDisplayListHead++, dl_ia_text_tex_settings);
}

#ifdef VERSION_EU
static void alloc_ia4_tex_from_i1(u8 *out, u8 *in, s16 width, s16 height) {
    s32 inPos;
    s16 outPos = 0;
    u8 bitMask;

    for (inPos = 0; inPos < (width * height) / 4; inPos++) {
        bitMask = 0x80;

        while (bitMask != 0) {
            out[outPos] = (in[inPos] & bitMask) ? 0xF0 : 0x00;
            bitMask /= 2;
            out[outPos] = (in[inPos] & bitMask) ? out[outPos] + 0x0F : out[outPos];
            bitMask /= 2;
            outPos++;
        }
    }
}

static u8 *convert_ia4_char(u8 c, u8 *tex, s16 w, s16 h) {
#ifdef EXTERNAL_DATA
    return tex; // the data's just a name
#else
    if (!tex) return NULL;
    if (!charCache[c].used) {
        charCache[c].used = 1;
        alloc_ia4_tex_from_i1(charCache[c].data, tex, w, h);
    }
    return charCache[c].data;
#endif
}

void render_generic_char_at_pos(s16 xPos, s16 yPos, u8 c) {
    void **fontLUT = segmented_to_virtual(main_font_lut);
    void *packedTexture = segmented_to_virtual(fontLUT[c]);
    void *unpackedTexture = convert_ia4_char(c, packedTexture, 8, 8);

    gDPPipeSync(gDisplayListHead++);
    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_IA, G_IM_SIZ_16b, 1, VIRTUAL_TO_PHYSICAL(unpackedTexture));
    gSPDisplayList(gDisplayListHead++, dl_ia_text_tex_settings);
    gSPTextureRectangleFlip(gDisplayListHead++, xPos << 2, (yPos - 16) << 2, (xPos + 8) << 2, yPos << 2,
                            G_TX_RENDERTILE, 8 << 6, 4 << 6, 1 << 10, 1 << 10);
}

void render_lowercase_diacritic(s16 *xPos, s16 *yPos, u8 letter, u8 diacritic) {
    render_generic_char_at_pos(*xPos, *yPos, letter);
    render_generic_char_at_pos(*xPos, *yPos, diacritic + 0xE7);
    *xPos += gDialogCharWidths[letter];
}

void render_uppercase_diacritic(s16 *xPos, s16 *yPos, u8 letter, u8 diacritic) {
    render_generic_char_at_pos(*xPos, *yPos, letter);
    render_generic_char_at_pos(*xPos, *yPos - 4, diacritic + 0xE3);
    *xPos += gDialogCharWidths[letter];
}
#endif // VERSION_EU

#ifdef VERSION_CN
void render_generic_char_cn(u16 c) {
    void **fontLUT = segmented_to_virtual(main_font_lut);
    void *packedTexture = segmented_to_virtual(fontLUT[c]);
    void *unpackedTexture = alloc_ia8_text_from_i1(packedTexture);

    gDPPipeSync(gDisplayListHead++);
    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_IA, G_IM_SIZ_16b, 1, VIRTUAL_TO_PHYSICAL(unpackedTexture));
    gSPDisplayList(gDisplayListHead++, dl_ia_text_tex_settings);
}
#endif

#if defined(VERSION_US) || defined(VERSION_EU) || defined(VERSION_CN)
struct MultiTextEntry {
    u8 length;
    u8 str[4];
};

#define TEXT_THE_RAW ASCII_TO_DIALOG('t'), ASCII_TO_DIALOG('h'), ASCII_TO_DIALOG('e'), 0x00
#define TEXT_YOU_RAW ASCII_TO_DIALOG('y'), ASCII_TO_DIALOG('o'), ASCII_TO_DIALOG('u'), 0x00

enum MultiStringIDs { STRING_THE, STRING_YOU };

/*
 * Place the multi-text string according to the ID passed. (US, EU)
 * 0: 'the'
 * 1: 'you'
 */
#if defined(VERSION_US) || defined(VERSION_CN)
void render_multi_text_string(s8 multiTextID)
#elif defined(VERSION_EU)
void render_multi_text_string(s16 *xPos, s16 *yPos, s8 multiTextID)
#endif
{
    s8 i;
    struct MultiTextEntry textLengths[2] = {
        { 3, { TEXT_THE_RAW } },
        { 3, { TEXT_YOU_RAW } },
    };

    for (i = 0; i < textLengths[multiTextID].length; i++) {
#if defined(VERSION_US) || defined(VERSION_CN)
        render_generic_char(textLengths[multiTextID].str[i]);
        create_dl_translation_matrix(
            MENU_MTX_NOPUSH, (f32)(gDialogCharWidths[textLengths[multiTextID].str[i]]), 0.0f, 0.0f);
#elif defined(VERSION_EU)
        render_generic_char_at_pos(*xPos, *yPos, textLengths[multiTextID].str[i]);
        *xPos += gDialogCharWidths[textLengths[multiTextID].str[i]];
#endif
    }
}
#endif

#if defined(VERSION_SH)
    #define CUR_CHAR str[strPos]
    #define MAX_STRING_WIDTH 18
    #define CHAR_WIDTH_SPACE (JP_DIALOG_CHAR_WIDTH / 2)
    #define CHAR_WIDTH_DEFAULT JP_DIALOG_CHAR_WIDTH
#elif defined(VERSION_CN)
    #define CUR_CHAR strChar
    #define MAX_STRING_WIDTH 18
    #define CHAR_WIDTH_SPACE gDialogCharWidths[DIALOG_CHAR_SPACE]
    #define CHAR_WIDTH_DEFAULT gDialogCharWidths[CUR_CHAR]
#else
    #define CUR_CHAR str[strPos]
    #define MAX_STRING_WIDTH 16
    #define CHAR_WIDTH_SPACE gDialogCharWidths[DIALOG_CHAR_SPACE]
    #define CHAR_WIDTH_DEFAULT gDialogCharWidths[CUR_CHAR]
#endif

/**
 * Prints a generic white string.
 * In JP/EU a IA1 texture is used but in US a IA4 texture is used.
 */
void print_generic_string(s16 x, s16 y, const u8 *str) {
    UNUSED s8 mark = DIALOG_MARK_NONE; // unused in EU
    s32 strPos = 0;
    u8 lineNum = 1;
#ifdef VERSION_EU
    s16 xCoord = x;
    s16 yCoord = 240 - y;
#endif
#ifdef VERSION_CN
    s32 strChar;
#endif

#ifndef VERSION_EU
    create_dl_translation_matrix(MENU_MTX_PUSH, x, y, 0.0f);
#endif

#ifdef VERSION_CN
    while (str[strPos] != DIALOG_CHAR_SPECIAL_MODIFIER || str[strPos + 1] != DIALOG_CHAR_TERMINATOR) {
        strChar = str[strPos] << 8 | str[strPos + 1];
#else
    while (str[strPos] != SPECIAL_CHAR(DIALOG_CHAR_TERMINATOR)) {
#endif
        switch (CUR_CHAR) {
#ifdef VERSION_CN
            case SPECIAL_CHAR(DIALOG_CHAR_NEWLINE):
                gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
                create_dl_translation_matrix(MENU_MTX_PUSH, x, y - (lineNum * MAX_STRING_WIDTH), 0.0f);
                lineNum++;
                break;
            case SPECIAL_CHAR(DIALOG_CHAR_STAR_OPEN): // ???
                create_dl_translation_matrix(MENU_MTX_NOPUSH, 32.0f, 0.0f, 0.0f);
                break;
#endif
#ifdef VERSION_EU
            case SPECIAL_CHAR(DIALOG_CHAR_SPACE):
                xCoord += 5;
                break;
            case SPECIAL_CHAR(DIALOG_CHAR_NEWLINE):
                yCoord += 16;
                xCoord = x;
                lineNum++;
                break;
            case SPECIAL_CHAR(DIALOG_CHAR_LOWER_A_GRAVE):
            case SPECIAL_CHAR(DIALOG_CHAR_LOWER_A_CIRCUMFLEX):
            case SPECIAL_CHAR(DIALOG_CHAR_LOWER_A_UMLAUT):
                render_lowercase_diacritic(&xCoord, &yCoord, ASCII_TO_DIALOG('a'), CUR_CHAR & 0xF);
                break;
            case SPECIAL_CHAR(DIALOG_CHAR_UPPER_A_UMLAUT): // @bug grave and circumflex (0x64-0x65) are absent here
                render_uppercase_diacritic(&xCoord, &yCoord, ASCII_TO_DIALOG('A'), CUR_CHAR & 0xF);
                break;
            case SPECIAL_CHAR(DIALOG_CHAR_LOWER_E_GRAVE):
            case SPECIAL_CHAR(DIALOG_CHAR_LOWER_E_CIRCUMFLEX):
            case SPECIAL_CHAR(DIALOG_CHAR_LOWER_E_UMLAUT):
            case SPECIAL_CHAR(DIALOG_CHAR_LOWER_E_ACUTE):
                render_lowercase_diacritic(&xCoord, &yCoord, ASCII_TO_DIALOG('e'), CUR_CHAR & 0xF);
                break;
            case SPECIAL_CHAR(DIALOG_CHAR_UPPER_E_GRAVE):
            case SPECIAL_CHAR(DIALOG_CHAR_UPPER_E_CIRCUMFLEX):
            case SPECIAL_CHAR(DIALOG_CHAR_UPPER_E_UMLAUT):
            case SPECIAL_CHAR(DIALOG_CHAR_UPPER_E_ACUTE):
                render_uppercase_diacritic(&xCoord, &yCoord, ASCII_TO_DIALOG('E'), CUR_CHAR & 0xF);
                break;
            case SPECIAL_CHAR(DIALOG_CHAR_LOWER_U_GRAVE):
            case SPECIAL_CHAR(DIALOG_CHAR_LOWER_U_CIRCUMFLEX):
            case SPECIAL_CHAR(DIALOG_CHAR_LOWER_U_UMLAUT):
                render_lowercase_diacritic(&xCoord, &yCoord, ASCII_TO_DIALOG('u'), CUR_CHAR & 0xF);
                break;
            case SPECIAL_CHAR(DIALOG_CHAR_UPPER_U_UMLAUT): // @bug grave and circumflex (0x84-0x85) are absent here
                render_uppercase_diacritic(&xCoord, &yCoord, ASCII_TO_DIALOG('U'), CUR_CHAR & 0xF);
                break;
            case SPECIAL_CHAR(DIALOG_CHAR_LOWER_O_CIRCUMFLEX):
            case SPECIAL_CHAR(DIALOG_CHAR_LOWER_O_UMLAUT):
                render_lowercase_diacritic(&xCoord, &yCoord, ASCII_TO_DIALOG('o'), CUR_CHAR & 0xF);
                break;
            case SPECIAL_CHAR(DIALOG_CHAR_UPPER_O_UMLAUT): // @bug circumflex (0x95) is absent here
                render_uppercase_diacritic(&xCoord, &yCoord, ASCII_TO_DIALOG('O'), CUR_CHAR & 0xF);
                break;
            case SPECIAL_CHAR(DIALOG_CHAR_LOWER_I_CIRCUMFLEX):
            case SPECIAL_CHAR(DIALOG_CHAR_LOWER_I_UMLAUT):
                render_lowercase_diacritic(&xCoord, &yCoord, DIALOG_CHAR_I_NO_DIA, CUR_CHAR & 0xF);
                break;
#else // i.e. not EU
            case SPECIAL_CHAR(DIALOG_CHAR_DAKUTEN):
                mark = DIALOG_MARK_DAKUTEN;
                break;
            case SPECIAL_CHAR(DIALOG_CHAR_PERIOD_OR_HANDAKUTEN):
                mark = DIALOG_MARK_HANDAKUTEN;
                break;
#ifndef VERSION_CN
            case SPECIAL_CHAR(DIALOG_CHAR_NEWLINE):
                gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
                create_dl_translation_matrix(MENU_MTX_PUSH, x, y - (lineNum * MAX_STRING_WIDTH), 0.0f);
                lineNum++;
                break;
#endif
            case SPECIAL_CHAR(DIALOG_CHAR_PERIOD):
                create_dl_translation_matrix(MENU_MTX_PUSH, -2.0f, -5.0f, 0.0f);
                render_generic_char(DIALOG_CHAR_PERIOD_OR_HANDAKUTEN);
                gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
                break;
#endif

#if defined(VERSION_US) || defined(VERSION_EU) || defined(VERSION_CN)
            case SPECIAL_CHAR(DIALOG_CHAR_SLASH):
#ifdef VERSION_EU
                xCoord += gDialogCharWidths[DIALOG_CHAR_SPACE] * 2;
#else
                create_dl_translation_matrix(
                    MENU_MTX_NOPUSH, (f32)(gDialogCharWidths[DIALOG_CHAR_SPACE] * 2), 0.0f, 0.0f);
#endif
                break;
            case SPECIAL_CHAR(DIALOG_CHAR_MULTI_THE):
#ifdef VERSION_EU
                render_multi_text_string(&xCoord, &yCoord, STRING_THE);
#else
                render_multi_text_string(STRING_THE);
#endif
                break;
            case SPECIAL_CHAR(DIALOG_CHAR_MULTI_YOU):
#ifdef VERSION_EU
                render_multi_text_string(&xCoord, &yCoord, STRING_YOU);
#else
                render_multi_text_string(STRING_YOU);
#endif
                break;
#endif

#ifndef VERSION_EU
            case SPECIAL_CHAR(DIALOG_CHAR_SPACE):
                create_dl_translation_matrix(MENU_MTX_NOPUSH, CHAR_WIDTH_SPACE, 0.0f, 0.0f);
                break;
#endif

            default:
#ifdef VERSION_EU
                render_generic_char_at_pos(xCoord, yCoord, CUR_CHAR);
                xCoord += gDialogCharWidths[CUR_CHAR];
#else
#ifdef VERSION_CN
                if (strChar >= 0x0100) {
                    strChar = (strChar - 0xFF) * 2 + 0xFE;
                    render_generic_char_cn(strChar);
                    create_dl_translation_matrix(MENU_MTX_NOPUSH, 8.0f, 0.0f, 0.0f);
                    render_generic_char_cn(strChar + 1);
                    create_dl_translation_matrix(MENU_MTX_NOPUSH, 8.0f, 0.0f, 0.0f);
                    break;
                }
#endif
                render_generic_char(CUR_CHAR);
                if (mark != DIALOG_MARK_NONE) {
                    create_dl_translation_matrix(MENU_MTX_PUSH, 5.0f, 5.0f, 0.0f);
                    render_generic_char(DIALOG_CHAR_MARK_START + mark);
                    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
                    mark = DIALOG_MARK_NONE;
                }

                create_dl_translation_matrix(MENU_MTX_NOPUSH, CHAR_WIDTH_DEFAULT, 0.0f, 0.0f);
#endif
                break; // what an odd difference. US (and probably later) versions added a useless break here.
        }

#ifdef VERSION_CN
        strPos += 2;
#else
        strPos++;
#endif
    }

#ifndef VERSION_EU
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
#endif
}

#ifdef VERSION_EU
void print_hud_char_umlaut(s16 x, s16 y, u8 chr) {
    void **fontLUT = segmented_to_virtual(main_hud_lut);

    gDPPipeSync(gDisplayListHead++);
    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, fontLUT[chr]);
    gSPDisplayList(gDisplayListHead++, dl_rgba16_load_tex_block);
    gSPTextureRectangle(gDisplayListHead++, x << 2, y << 2, (x + 16) << 2, (y + 16) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);

    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, fontLUT[GLYPH_UMLAUT]);
    gSPDisplayList(gDisplayListHead++, dl_rgba16_load_tex_block);
    gSPTextureRectangle(gDisplayListHead++, x << 2, (y - 4) << 2, (x + 16) << 2, (y + 12) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);
}
#endif

/**
 * Prints a hud string depending of the hud table list defined.
 */
void print_hud_lut_string(s8 hudLUT, s16 x, s16 y, const u8 *str) {
    s32 strPos = 0;
    void **hudLUT1 = segmented_to_virtual(menu_hud_lut); // Japanese Menu HUD Color font
    void **hudLUT2 = segmented_to_virtual(main_hud_lut); // 0-9 A-Z HUD Color Font
    u32 curX = x;
    u32 curY = y;

#ifdef VERSION_CN
    u32 xOffset = 0;
#else
    u32 xStride; // X separation

    if (hudLUT == HUD_LUT_JPMENU) {
        xStride = 16;
    } else { // HUD_LUT_GLOBAL
        xStride = HUD_LUT_STRIDE_GLOBAL;
    }
#endif

    while (str[strPos] != GLOBAL_CHAR_TERMINATOR) {
        switch (str[strPos]) {
#ifdef VERSION_CN
            case GLOBAL_CHAR_NEWLINE:
                curY += 16;
                curX -= xOffset;
                break;
#elif defined(VERSION_EU)
            case GLOBAL_CHAR_SPACE:
                curX += xStride / 2;
                break;
            case HUD_CHAR_A_UMLAUT:
                print_hud_char_umlaut(curX, curY, ASCII_TO_DIALOG('A'));
                curX += xStride;
                break;
            case HUD_CHAR_O_UMLAUT:
                print_hud_char_umlaut(curX, curY, ASCII_TO_DIALOG('O'));
                curX += xStride;
                break;
            case HUD_CHAR_U_UMLAUT:
                print_hud_char_umlaut(curX, curY, ASCII_TO_DIALOG('U'));
                curX += xStride;
                break;
#else
            case GLOBAL_CHAR_SPACE:
                curX += 8;
                break;
#endif
#ifdef VERSION_CN
            // Hack, still broken but better than before
            case 0x00:
                if (hudLUT == HUD_LUT_CNFIX) break;
#endif
            default:
                gDPPipeSync(gDisplayListHead++);

#ifndef VERSION_CN
                if (hudLUT == HUD_LUT_JPMENU) {
                    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, hudLUT1[str[strPos]]);
                }

                if (hudLUT == HUD_LUT_GLOBAL) {
#endif
                    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, hudLUT2[str[strPos]]);
#ifndef VERSION_CN
                }
#endif
                gSPDisplayList(gDisplayListHead++, dl_rgba16_load_tex_block);
                gSPTextureRectangle(gDisplayListHead++, curX << 2, curY << 2, (curX + 16) << 2,
                                    (curY + 16) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);

#ifdef VERSION_CN
                if (str[strPos] < 0x3A) {
                    curX += 12;
                    xOffset += 12;
                } else {
                    curX += 16;
                    xOffset += 16;
                }
#else
                curX += xStride;
#endif
        }
        strPos++;
    }
}

#ifdef VERSION_EU
void print_menu_char_umlaut(s16 x, s16 y, u8 chr) {
    void **fontLUT = segmented_to_virtual(menu_font_lut);

    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_IA, G_IM_SIZ_8b, 1, fontLUT[chr]);
    gDPLoadSync(gDisplayListHead++);
    gDPLoadBlock(gDisplayListHead++, G_TX_LOADTILE, 0, 0, 8 * 8 - 1, CALC_DXT(8, G_IM_SIZ_8b_BYTES));
    gSPTextureRectangle(gDisplayListHead++, x << 2, y << 2, (x + 8) << 2, (y + 8) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);

    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_IA, G_IM_SIZ_8b, 1, fontLUT[DIALOG_CHAR_UMLAUT]);
    gDPLoadSync(gDisplayListHead++);
    gDPLoadBlock(gDisplayListHead++, G_TX_LOADTILE, 0, 0, 8 * 8 - 1, CALC_DXT(8, G_IM_SIZ_8b_BYTES));
    gSPTextureRectangle(gDisplayListHead++, x << 2, (y - 4) << 2, (x + 8) << 2, (y + 4) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);
}
#endif

void print_menu_generic_string(s16 x, s16 y, const u8 *str) {
    UNUSED s8 mark = DIALOG_MARK_NONE; // unused in EU
    s32 strPos = 0;
    u32 curX = x;
    u32 curY = y;
    void **fontLUT = segmented_to_virtual(menu_font_lut);

    while (str[strPos] != DIALOG_CHAR_TERMINATOR) {
        switch (str[strPos]) {
#ifdef VERSION_EU
            case DIALOG_CHAR_UPPER_A_UMLAUT:
                print_menu_char_umlaut(curX, curY, ASCII_TO_DIALOG('A'));
                curX += gDialogCharWidths[str[strPos]];
                break;
            case DIALOG_CHAR_UPPER_U_UMLAUT:
                print_menu_char_umlaut(curX, curY, ASCII_TO_DIALOG('U'));
                curX += gDialogCharWidths[str[strPos]];
                break;
            case DIALOG_CHAR_UPPER_O_UMLAUT:
                print_menu_char_umlaut(curX, curY, ASCII_TO_DIALOG('O'));
                curX += gDialogCharWidths[str[strPos]];
                break;
#else
            case DIALOG_CHAR_DAKUTEN:
                mark = DIALOG_MARK_DAKUTEN;
                break;
            case DIALOG_CHAR_PERIOD_OR_HANDAKUTEN:
                mark = DIALOG_MARK_HANDAKUTEN;
                break;
#endif
            case DIALOG_CHAR_SPACE:
                curX += 4;
                break;
            default:
                gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_IA, G_IM_SIZ_8b, 1, fontLUT[str[strPos]]);
                gDPLoadSync(gDisplayListHead++);
                gDPLoadBlock(gDisplayListHead++, G_TX_LOADTILE, 0, 0, 8 * 8 - 1, CALC_DXT(8, G_IM_SIZ_8b_BYTES));
                gSPTextureRectangle(gDisplayListHead++, curX << 2, curY << 2, (curX + 8) << 2,
                                    (curY + 8) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);

#ifndef VERSION_EU
                if (mark != DIALOG_MARK_NONE) {
                    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_IA, G_IM_SIZ_8b, 1, fontLUT[DIALOG_CHAR_MARK_START + mark]);
                    gDPLoadSync(gDisplayListHead++);
                    gDPLoadBlock(gDisplayListHead++, G_TX_LOADTILE, 0, 0, 8 * 8 - 1, CALC_DXT(8, G_IM_SIZ_8b_BYTES));
                    gSPTextureRectangle(gDisplayListHead++, (curX + 6) << 2, (curY - 7) << 2,
                                        (curX + 6 + 8) << 2, (curY - 7 + 8) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);

                    mark = DIALOG_MARK_NONE;
                }
#endif
#if defined(VERSION_SH) || defined(VERSION_CN)
                curX += JP_DIALOG_CHAR_WIDTH - 1;
#else
                curX += gDialogCharWidths[str[strPos]];
#endif
        }
        strPos++;
    }
}

#if !CREDITS_TEXT_STRING_FONT
void print_credits_string(s16 x, s16 y, const u8 *str) {
    s32 strPos = 0;
    void **fontLUT = segmented_to_virtual(main_credits_font_lut);
    u32 curX = x;
    u32 curY = y;

    gDPSetTile(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0,
                G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD);
    gDPTileSync(gDisplayListHead++);
    gDPSetTile(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 2, 0, G_TX_RENDERTILE, 0,
                G_TX_CLAMP, 3, G_TX_NOLOD, G_TX_CLAMP, 3, G_TX_NOLOD);
    gDPSetTileSize(gDisplayListHead++, G_TX_RENDERTILE, 0, 0, (8 - 1) << G_TEXTURE_IMAGE_FRAC, (8 - 1) << G_TEXTURE_IMAGE_FRAC);

    while (str[strPos] != GLOBAL_CHAR_TERMINATOR) {
        switch (str[strPos]) {
            case GLOBAL_CHAR_SPACE:
                curX += 4;
                break;
            default:
                gDPPipeSync(gDisplayListHead++);
                gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, fontLUT[str[strPos]]);
                gDPLoadSync(gDisplayListHead++);
                gDPLoadBlock(gDisplayListHead++, G_TX_LOADTILE, 0, 0, 8 * 8 - 1, CALC_DXT(8, G_IM_SIZ_16b_BYTES));
                gSPTextureRectangle(gDisplayListHead++, curX << 2, curY << 2, (curX + 8) << 2,
                                    (curY + 8) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);
                curX += 7;
                break;
        }
        strPos++;
    }
}
#endif

void handle_menu_scrolling(s8 scrollDirection, s8 *currentIndex, s8 minIndex, s8 maxIndex) {
    u8 index = 0;

    if (scrollDirection == MENU_SCROLL_VERTICAL) {
        if (gPlayer1Controller->rawStickY > 60) {
            index |= 0b01; // Up
        }
        if (gPlayer1Controller->rawStickY < -60) {
            index |= 0b10; // Down
        }
    } else if (scrollDirection == MENU_SCROLL_HORIZONTAL) {
        if (gPlayer1Controller->rawStickX > 60) {
            index |= 0b10; // Right
        }

        if (gPlayer1Controller->rawStickX < -60) {
            index |= 0b01; // Left
        }
    }

    // Only increase/decrese if not holding that direction on the previous frame:

    if (((index ^ gMenuHoldKeyIndex) & index) == 0b10) {
        if (*currentIndex != maxIndex) {
            play_sound(SOUND_MENU_CHANGE_SELECT, gGlobalSoundSource);
            (*currentIndex)++;
        }
    }

    if (((index ^ gMenuHoldKeyIndex) & index) == 0b01) {
        if (*currentIndex != minIndex) {
            play_sound(SOUND_MENU_CHANGE_SELECT, gGlobalSoundSource);
            (*currentIndex)--;
        }
    }

    // If there has been input for 10 frames, set the timer to 8 and set gMenuHoldKeyIndex to 0 so the above becomes true.
    if (gMenuHoldKeyTimer == 10) {
        gMenuHoldKeyTimer = 8;
        gMenuHoldKeyIndex = 0b00;
    } else {
        // Otherwise, increment the timer while there is input.
        gMenuHoldKeyTimer++;
        gMenuHoldKeyIndex = index;
    }

    if (index == 0) {
        gMenuHoldKeyTimer = 0;
    }
}

// EU has both get_str_x_pos_from_center and get_str_x_pos_from_center_scale
// JP, US, Shindou and iQue only implement one or the other
#if defined(VERSION_US) || defined(VERSION_EU) || defined(VERSION_CN)
s16 get_str_x_pos_from_center(s16 centerPos, u8 *str, UNUSED f32 scale) {
    s16 strPos = 0;
    f32 spacesWidth = 0.0f;

#ifdef VERSION_CN
    while (!(str[strPos] == DIALOG_CHAR_SPECIAL_MODIFIER && str[strPos + 1] == DIALOG_CHAR_TERMINATOR)) {
        u16 character = (str[strPos] << 8) | str[strPos + 1];
        if (character <= 0xFF) {
            spacesWidth += gDialogCharWidths[character];
        } else {
            spacesWidth += 16.0;
        }
        strPos += 2;
    }
#else
    while (str[strPos] != DIALOG_CHAR_TERMINATOR) {
        spacesWidth += gDialogCharWidths[str[strPos]];
        strPos++;
    }
#endif
    // return the x position of where the string starts as half the string's
    // length from the position of the provided center.
    return (s16)(centerPos - (s16)(spacesWidth / 2.0));
}
#endif

#if defined(VERSION_EU) || defined(VERSION_SH)
s16 get_str_x_pos_from_center_scale(s16 centerPos, u8 *str, f32 scale) {
    s16 strPos = 0;
    f32 charsWidth = 0.0f;
    f32 spacesWidth = 0.0f;

    while (str[strPos] != DIALOG_CHAR_TERMINATOR) {
        //! EU checks for dakuten and handakuten despite dialog code unable to handle it
        if (str[strPos] == DIALOG_CHAR_SPACE) {
            spacesWidth += 1.0;
        } else if (str[strPos] != DIALOG_CHAR_DAKUTEN
                   && str[strPos] != DIALOG_CHAR_PERIOD_OR_HANDAKUTEN) {
            charsWidth += 1.0;
        }
        strPos++;
    }
    // return the x position of where the string starts as half the string's
    // length from the position of the provided center.
    return (f32) centerPos - (scale * (charsWidth / 2.0)) - ((scale / 2.0) * (spacesWidth / 2.0));
}
#endif

// ex-alo change
// Set a fixed value for JP regions
s16 get_string_width(u8 *str) {
    s16 strPos = 0;
    s16 width = 0;

#ifdef VERSION_CN
    while (!(str[strPos] == DIALOG_CHAR_SPECIAL_MODIFIER && str[strPos + 1] == DIALOG_CHAR_TERMINATOR)) {
        u16 character = (str[strPos] << 8) | str[strPos + 1];
        if (character <= 0xFF) {
            width += gDialogCharWidths[character];
        } else {
            width += 16;
        }
        strPos += 2;
    }
#else
    while (str[strPos] != DIALOG_CHAR_TERMINATOR) {
        #if defined(VERSION_US) || defined(VERSION_EU)
        width += gDialogCharWidths[str[strPos]];
        #else
        width += JP_DIALOG_CHAR_WIDTH;
        #endif
        strPos++;
    }
#endif
    return width;
}

u8 gHudSymCoin[] = { GLYPH_COIN, GLYPH_SPACE };
u8 gHudSymX[] = { GLYPH_MULTIPLY, GLYPH_SPACE };

void print_hud_my_score_coins(s32 useCourseCoinScore, s8 fileIndex, s8 courseIndex, s16 x, s16 y) {
    u8 strNumCoins[4];
    s16 numCoins;

    if (!useCourseCoinScore) {
        numCoins = (u16)(save_file_get_max_coin_score(courseIndex) & 0xFFFF);
    } else {
        numCoins = save_file_get_course_coin_score(fileIndex, courseIndex);
    }

    if (numCoins != 0) {
        print_hud_lut_string(HUD_LUT_GLOBAL, x, y, gHudSymCoin);
        print_hud_lut_string(HUD_LUT_GLOBAL, x + 16, y, gHudSymX);
        int_to_str(numCoins, strNumCoins);
        print_hud_lut_string(HUD_LUT_GLOBAL, x + 32, y, strNumCoins);
    }
}

void print_hud_my_score_stars(s8 fileIndex, s8 courseIndex, s16 x, s16 y) {
    u8 strStarCount[4];
    s16 starCount;
    u8 textSymStar[] = { GLYPH_STAR, GLYPH_SPACE };
    UNUSED u16 unused;
    u8 textSymX[] = { GLYPH_MULTIPLY, GLYPH_SPACE };

    starCount = save_file_get_course_star_count(fileIndex, courseIndex);

    if (starCount != 0) {
        print_hud_lut_string(HUD_LUT_GLOBAL, x, y, textSymStar);
        print_hud_lut_string(HUD_LUT_GLOBAL, x + 16, y, textSymX);
        int_to_str(starCount, strStarCount);
        print_hud_lut_string(HUD_LUT_GLOBAL, x + 32, y, strStarCount);
    }
}

void int_to_str(s32 num, u8 *dst) {
    s32 digit1;
    s32 digit2;
    s32 digit3;

    s8 pos = 0;

    if (num > 999) {
        dst[0] = 0x00; dst[1] = DIALOG_CHAR_TERMINATOR;
        return;
    }

    digit1 = num / 100;
    digit2 = (num - digit1 * 100) / 10;
    digit3 = (num - digit1 * 100) - (digit2 * 10);

    if (digit1 != 0) {
        dst[pos] = digit1; pos++;
    }

    if (digit2 != 0 || digit1 != 0) {
        dst[pos] = digit2; pos++;
    }

    dst[pos] = digit3;
    pos++;
    dst[pos] = DIALOG_CHAR_TERMINATOR;
}

#ifdef VERSION_CN
void int_to_str_2(s32 num, u8 *dst) {
    s32 digit1;
    s32 digit2;
    s32 digit3;

    s8 pos = 0;

    if (num > 999) {
        dst[0] = 0x00;
        dst[1] = 0x00;
        dst[2] = DIALOG_CHAR_SPECIAL_MODIFIER;
        dst[3] = DIALOG_CHAR_TERMINATOR;
        return;
    }

    digit1 = num / 100;
    digit2 = (num - digit1 * 100) / 10;
    digit3 = (num - digit1 * 100) - (digit2 * 10);

    if (digit1 != 0) {
        dst[pos] = 0x00;
        pos++;
        dst[pos] = digit1;
        pos++;
    }

    if (digit2 != 0 || digit1 != 0) {
        dst[pos] = 0x00;
        pos++;
        dst[pos] = digit2;
        pos++;
    }

    dst[pos] = 0x00;
    pos++;
    dst[pos] = digit3;
    pos++;
    dst[pos] = DIALOG_CHAR_SPECIAL_MODIFIER;
    pos++;
    dst[pos] = DIALOG_CHAR_TERMINATOR;
}
#endif

s16 get_dialog_id(void) {
    return gDialogID;
}

void create_dialog_box(s16 dialog) {
    if (gDialogID == DIALOG_NONE) {
        gDialogID = dialog;
        gDialogBoxType = DIALOG_TEXT_WHITE;
    }
}

void create_dialog_box_with_var(s16 dialog, s32 dialogVar) {
    if (gDialogID == DIALOG_NONE) {
        gDialogID = dialog;
        gDialogVariable = dialogVar;
        gDialogBoxType = DIALOG_TEXT_WHITE;
    }
}

void create_dialog_inverted_box(s16 dialog) {
    if (gDialogID == DIALOG_NONE) {
        gDialogID = dialog;
        gDialogBoxType = DIALOG_TEXT_BLACK;
    }
}

void create_dialog_box_with_response(s16 dialog) {
    if (gDialogID == DIALOG_NONE) {
        gDialogID = dialog;
        gDialogBoxType = DIALOG_TEXT_WHITE;
        gDialogWithChoice = TRUE;
    }
}

void reset_dialog_render_state(void) {
    level_set_transition(0, NULL);

    if (gDialogBoxType == DIALOG_TEXT_BLACK) {
        trigger_cutscene_dialog(2);
    }

    gDialogBoxScale = DIALOG_BOX_SCALE_DEFAULT;
    gDialogBoxAngle = DIALOG_BOX_ANGLE_DEFAULT;
    gMenuState = MENU_STATE_DEFAULT;
    gDialogID = DIALOG_NONE;
    gDialogPageStartStrIndex = 0;
    gDialogWithChoice = FALSE;
    gNextDialogPageStartStrIndex = 0;
    gDialogResponse = DIALOG_RESPONSE_NONE;
}

#if defined(VERSION_SH)
    #define X_VAL1 -5.0f
    #define Y_VAL1 2.0
    #define Y_VAL2 4
#else
    #define X_VAL1 -7.0f
    #define Y_VAL1 5.0
    #define Y_VAL2 5.0f
#endif

void render_dialog_box_type(struct DialogEntry *dialog, s8 linesPerBox) {
    create_dl_translation_matrix(MENU_MTX_NOPUSH, dialog->leftOffset, dialog->width, 0);

        if (gMenuState == MENU_STATE_DIALOG_OPENING || gMenuState == MENU_STATE_DIALOG_CLOSING) {
#ifdef HIGH_FPS_PC
            sInterpolatedDialogZoomPos = gDisplayListHead;
            if (gMenuState == MENU_STATE_DIALOG_OPENING) {
                sInterpolatedDialogScale = gDialogBoxScale - 2 / 2;
            } else {
                sInterpolatedDialogScale = gDialogBoxScale + 2 / 2;
            }
#endif
            create_dl_translation_matrix(MENU_MTX_NOPUSH, 65.0 - (65 / gDialogBoxScale),
                                          (40.0 / gDialogBoxScale) - 40, 0);
            create_dl_scale_matrix(MENU_MTX_NOPUSH, 1.0 / gDialogBoxScale, 1.0 / gDialogBoxScale, 1.0f);
        }

    switch (gDialogBoxType) {
        case DIALOG_TEXT_WHITE: // Renders a dialog white text with zoom and roationg
            gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, 150);
            break;
        case DIALOG_TEXT_BLACK: // Renders a dialog black text with zoom
            gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 150);
            break;
    }

    create_dl_translation_matrix(MENU_MTX_PUSH, X_VAL1, Y_VAL1, 0);
#ifdef VERSION_CN
    create_dl_scale_matrix(MENU_MTX_NOPUSH, 1.1f, ((f32)(linesPerBox + 1) / Y_VAL2) + 0.1, 1.0f);
#else
    create_dl_scale_matrix(MENU_MTX_NOPUSH, 1.1f, ((f32) linesPerBox / Y_VAL2) + 0.1, 1.0f);
#endif

    gSPDisplayList(gDisplayListHead++, dl_draw_text_bg_box);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
}

void change_and_flash_dialog_text_color_lines(s8 colorMode, s8 lineNum) {
    u8 color;

    if (colorMode == 1) { // unused
        if (lineNum == 1) {
            gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
        } else {
            if (lineNum == gMenuLineNum) {
                color = sins(gMenuTextColorTransTimer) * 50.0f + 200.0f;
                gDPSetEnvColor(gDisplayListHead++, color, color, color, 255);
            } else {
                gDPSetEnvColor(gDisplayListHead++, 200, 200, 200, 255);
            }
        }
    } else {
        switch (gDialogBoxType) {
            case DIALOG_TEXT_WHITE:
                break;
            case DIALOG_TEXT_BLACK:
                gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, 255);
                break;
        }
    }
}

#ifdef VERSION_EU
void render_generic_dialog_char_at_pos(struct DialogEntry *dialog, s16 x, s16 y, u8 c) {
    s16 width = (8.0 - (gDialogBoxScale * 0.8));
    s16 height = (16.0 - (gDialogBoxScale * 0.8));
    s16 tmpX = (dialog->leftOffset + (65.0 - (65.0 / gDialogBoxScale)));
    s16 tmpY = ((240 - dialog->width) - ((40.0 / gDialogBoxScale) - 40));
    s16 xCoord = (tmpX + (x / gDialogBoxScale));
    s16 yCoord = (tmpY + (y / gDialogBoxScale));

    void **fontLUT = segmented_to_virtual(main_font_lut);
    void *packedTexture = segmented_to_virtual(fontLUT[c]);
    void *unpackedTexture = convert_ia4_char(c, packedTexture, 8, 8);

    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_IA, G_IM_SIZ_16b, 1, VIRTUAL_TO_PHYSICAL(unpackedTexture));
    gSPDisplayList(gDisplayListHead++, dl_ia_text_tex_settings);
    gSPTextureRectangleFlip(gDisplayListHead++, xCoord << 2, (yCoord - height) << 2,
                            (xCoord + width) << 2, yCoord << 2, G_TX_RENDERTILE, 8 << 6, 4 << 6, 1 << 10, 1 << 10);
}
#endif

#if defined(VERSION_SH)
    #define X_VAL3 5.0f
    #define Y_VAL3 20
#elif defined(VERSION_CN)
    #define X_VAL3 0.0f
    #define Y_VAL3 20
#else
    #define X_VAL3 0.0f
    #define Y_VAL3 16
#endif

#ifdef VERSION_EU
void handle_dialog_scroll_page_state(s8 lineNum, s8 totalLines, s8 *pageState, s8 *xMatrix)
#else
void handle_dialog_scroll_page_state(s8 lineNum, s8 totalLines, s8 *pageState, s8 *xMatrix, s16 *linePos)
#endif
{
#ifndef VERSION_EU
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
#endif

    if (lineNum == totalLines) {
        *pageState = DIALOG_PAGE_STATE_SCROLL;
        return;
    }
#ifdef VERSION_EU
    gDialogY += 16;
#else
    create_dl_translation_matrix(MENU_MTX_PUSH, X_VAL3, 2 - (lineNum * Y_VAL3), 0);

    *linePos = 0;
#endif
    *xMatrix = 1;
}

#if defined(VERSION_SH)
void adjust_pos_and_print_period_char(s8 *xMatrix, s16 *linePos) {
    if (*linePos != 0) {
        create_dl_translation_matrix(MENU_MTX_NOPUSH, 10 * *xMatrix, 0, 0);
    }

    create_dl_translation_matrix(MENU_MTX_PUSH, -2.0f, -5.0f, 0);
    render_generic_char(DIALOG_CHAR_PERIOD_OR_HANDAKUTEN);

    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);

    (*linePos)++;
    *xMatrix = 1;
}
#endif

#ifdef VERSION_EU
void render_star_count_dialog_text(struct DialogEntry *dialog, s8 *linePos)
#else
void render_star_count_dialog_text(s8 *xMatrix, s16 *linePos)
#endif
{
    s8 tensDigit = gDialogVariable / 10;
    s8 onesDigit = gDialogVariable - (tensDigit * 10); // remainder

    if (tensDigit != 0) {
#if defined(VERSION_SH)
        create_dl_translation_matrix(MENU_MTX_NOPUSH, 10 * *xMatrix, 0, 0);
        render_generic_char(tensDigit);
#elif defined(VERSION_US) || defined(VERSION_CN)
        if (*xMatrix != 1) {
            create_dl_translation_matrix(
                MENU_MTX_NOPUSH, (f32)(gDialogCharWidths[DIALOG_CHAR_SPACE] * *xMatrix), 0, 0);
        }

        render_generic_char(tensDigit);
        create_dl_translation_matrix(MENU_MTX_NOPUSH, (f32) gDialogCharWidths[tensDigit], 0, 0);
        *xMatrix = 1;
        (*linePos)++;
#elif defined(VERSION_EU)
        render_generic_dialog_char_at_pos(dialog, gDialogX, gDialogY, tensDigit);
        gDialogX += gDialogCharWidths[tensDigit];
        *linePos = 1;
#endif
    }
#ifndef VERSION_EU
    else {
#if defined(VERSION_SH)
        (*xMatrix)++;
#endif
    }
#endif

#ifndef VERSION_EU
#if defined(VERSION_SH)
    create_dl_translation_matrix(MENU_MTX_NOPUSH, 10 * *xMatrix, 0, 0);
    render_generic_char(onesDigit);
#elif defined(VERSION_US) || defined(VERSION_CN)
    if (*xMatrix != 1) {
        create_dl_translation_matrix(
            MENU_MTX_NOPUSH, (f32)(gDialogCharWidths[DIALOG_CHAR_SPACE] * (*xMatrix - 1)), 0, 0);
    }

    render_generic_char(onesDigit);
    create_dl_translation_matrix(MENU_MTX_NOPUSH, (f32) gDialogCharWidths[onesDigit], 0, 0);
#endif
    (*linePos)++;
    *xMatrix = 1;
#else // VERSION_EU
    render_generic_dialog_char_at_pos(dialog, gDialogX, gDialogY, onesDigit);
    gDialogX += gDialogCharWidths[onesDigit];
    *linePos = 1;
#endif
}

#if defined(VERSION_US) || defined(VERSION_EU) || defined(VERSION_CN)
#ifdef VERSION_EU
void render_multi_text_string_lines(s8 multiTextId, s8 lineNum, s8 linesPerBox, UNUSED s8 xMatrix, s8 lowerBound, struct DialogEntry *dialog)
#else
void render_multi_text_string_lines(s8 multiTextId, s8 lineNum, s16 *linePos, s8 linesPerBox, s8 xMatrix, s8 lowerBound)
#endif
{
    s8 i;
    struct MultiTextEntry textLengths[2] = {
        { 3, { TEXT_THE_RAW } },
        { 3, { TEXT_YOU_RAW } },
    };

    if (lineNum >= lowerBound && lineNum <= (lowerBound + linesPerBox)) {
#ifndef VERSION_EU
        if (*linePos != 0 || xMatrix != 1) {
            create_dl_translation_matrix(
                MENU_MTX_NOPUSH, (gDialogCharWidths[DIALOG_CHAR_SPACE] * (xMatrix - 1)), 0, 0);
        }
#endif
        for (i = 0; i < textLengths[multiTextId].length; i++) {
#ifdef VERSION_EU
            render_generic_dialog_char_at_pos(dialog, gDialogX, gDialogY, textLengths[multiTextId].str[i]);
            gDialogX += gDialogCharWidths[textLengths[multiTextId].str[i]];
#else
            render_generic_char(textLengths[multiTextId].str[i]);
            create_dl_translation_matrix(
                MENU_MTX_NOPUSH, (gDialogCharWidths[textLengths[multiTextId].str[i]]), 0, 0);
#endif
        }
    }

#ifndef VERSION_EU
    linePos += textLengths[multiTextId].str[0];
#endif
}
#endif

#ifdef VERSION_EU
void render_dialog_lowercase_diacritic(struct DialogEntry *dialog, u8 chr, u8 diacritic) {
    render_generic_dialog_char_at_pos(dialog, gDialogX, gDialogY, chr);
    render_generic_dialog_char_at_pos(dialog, gDialogX, gDialogY, diacritic + 0xE7);
    gDialogX += gDialogCharWidths[chr];
}

void render_dialog_uppercase_diacritic(struct DialogEntry *dialog, u8 chr, u8 diacritic) {
    render_generic_dialog_char_at_pos(dialog, gDialogX, gDialogY, chr);
    render_generic_dialog_char_at_pos(dialog, gDialogX, gDialogY - 4, diacritic + 0xE3);
    gDialogX += gDialogCharWidths[chr];
}
#endif

u32 ensure_nonnegative(s16 value) {
    if (value < 0) {
        value = 0;
    }

    return value;
}

void handle_dialog_text_and_pages(s8 colorMode, struct DialogEntry *dialog, s8 lowerBound) {
#ifdef VERSION_EU
    s16 startY = 14;
#endif
#ifdef VERSION_CN
    s32 strChar;
#else
    u8 strChar;
#endif
    u8 *str = segmented_to_virtual(dialog->str);
    s8 lineNum = 1;
    s8 totalLines;
    s8 pageState = DIALOG_PAGE_STATE_NONE;
    UNUSED s8 mark = DIALOG_MARK_NONE; // only used in JP and SH
    s8 xMatrix = 1;
    s8 linesPerBox = dialog->linesPerBox;
    s16 strIndex;
#ifndef VERSION_EU
    s16 linePos = 0;
#endif

    if (gMenuState == MENU_STATE_DIALOG_SCROLLING) {
        // If scrolling, consider the number of lines for both
        // the current page and the page being scrolled to.
#ifdef VERSION_CN
        totalLines = linesPerBox * 2 - 1;
#else
        totalLines = linesPerBox * 2 + 1;
#endif
    } else {
#ifdef VERSION_CN
        totalLines = linesPerBox;
#else
        totalLines = linesPerBox + 1;
#endif
    }

    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);

    strIndex = gDialogPageStartStrIndex;

#ifdef VERSION_EU
    gDialogX = 0;
    gDialogY = startY;
#endif

    if (gMenuState == MENU_STATE_DIALOG_SCROLLING) {
#ifdef VERSION_EU
        gDialogY -= gDialogScrollOffsetY;
#else
#ifdef HIGH_FPS_PC
        sInterpolatedDialogOffset = gDialogScrollOffsetY + dialog->linesPerBox / 2;
        sInterpolatedDialogOffsetPos = gDisplayListHead;
#endif
        create_dl_translation_matrix(MENU_MTX_NOPUSH, 0, (f32) gDialogScrollOffsetY, 0);
#endif
    }

#ifndef VERSION_EU
    create_dl_translation_matrix(MENU_MTX_PUSH, X_VAL3, 2 - lineNum * Y_VAL3, 0);
#endif

    while (pageState == DIALOG_PAGE_STATE_NONE) {
        change_and_flash_dialog_text_color_lines(colorMode, lineNum);
#ifdef VERSION_CN
        strChar = str[strIndex] << 8 | str[strIndex + 1];
#else
        strChar = str[strIndex];
#endif

        switch (strChar) {
            case SPECIAL_CHAR(DIALOG_CHAR_TERMINATOR):
                pageState = DIALOG_PAGE_STATE_END;
#ifndef VERSION_EU
                gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
#endif
                break;
            case SPECIAL_CHAR(DIALOG_CHAR_NEWLINE):
                lineNum++;
#ifdef VERSION_EU
                handle_dialog_scroll_page_state(lineNum, totalLines, &pageState, &xMatrix);
                gDialogX = 0;
#else
                handle_dialog_scroll_page_state(lineNum, totalLines, &pageState, &xMatrix, &linePos);
#ifdef VERSION_SH
                mark = DIALOG_MARK_NONE;
#endif
#endif
                break;

#ifdef VERSION_EU
            case SPECIAL_CHAR(DIALOG_CHAR_LOWER_A_GRAVE):
            case SPECIAL_CHAR(DIALOG_CHAR_LOWER_A_CIRCUMFLEX):
            case SPECIAL_CHAR(DIALOG_CHAR_LOWER_A_UMLAUT):
                render_dialog_lowercase_diacritic(dialog, ASCII_TO_DIALOG('a'), strChar & 0xF);
                break;
            case SPECIAL_CHAR(DIALOG_CHAR_UPPER_A_GRAVE):
            case SPECIAL_CHAR(DIALOG_CHAR_UPPER_A_CIRCUMFLEX):
            case SPECIAL_CHAR(DIALOG_CHAR_UPPER_A_UMLAUT):
                render_dialog_uppercase_diacritic(dialog, ASCII_TO_DIALOG('A'), strChar & 0xF);
                break;
            case SPECIAL_CHAR(DIALOG_CHAR_LOWER_E_GRAVE):
            case SPECIAL_CHAR(DIALOG_CHAR_LOWER_E_CIRCUMFLEX):
            case SPECIAL_CHAR(DIALOG_CHAR_LOWER_E_UMLAUT):
            case SPECIAL_CHAR(DIALOG_CHAR_LOWER_E_ACUTE):
                render_dialog_lowercase_diacritic(dialog, ASCII_TO_DIALOG('e'), strChar & 0xF);
                break;
            case SPECIAL_CHAR(DIALOG_CHAR_UPPER_E_GRAVE):
            case SPECIAL_CHAR(DIALOG_CHAR_UPPER_E_CIRCUMFLEX):
            case SPECIAL_CHAR(DIALOG_CHAR_UPPER_E_UMLAUT):
            case SPECIAL_CHAR(DIALOG_CHAR_UPPER_E_ACUTE):
                render_dialog_uppercase_diacritic(dialog, ASCII_TO_DIALOG('E'), strChar & 0xF);
                break;
            case SPECIAL_CHAR(DIALOG_CHAR_LOWER_U_GRAVE):
            case SPECIAL_CHAR(DIALOG_CHAR_LOWER_U_CIRCUMFLEX):
            case SPECIAL_CHAR(DIALOG_CHAR_LOWER_U_UMLAUT):
                render_dialog_lowercase_diacritic(dialog, ASCII_TO_DIALOG('u'), strChar & 0xF);
                break;
            case SPECIAL_CHAR(DIALOG_CHAR_UPPER_U_GRAVE):
            case SPECIAL_CHAR(DIALOG_CHAR_UPPER_U_CIRCUMFLEX):
            case SPECIAL_CHAR(DIALOG_CHAR_UPPER_U_UMLAUT):
                render_dialog_uppercase_diacritic(dialog, ASCII_TO_DIALOG('U'), strChar & 0xF);
                break;
            case SPECIAL_CHAR(DIALOG_CHAR_LOWER_O_CIRCUMFLEX):
            case SPECIAL_CHAR(DIALOG_CHAR_LOWER_O_UMLAUT):
                render_dialog_lowercase_diacritic(dialog, ASCII_TO_DIALOG('o'), strChar & 0xF);
                break;
            case SPECIAL_CHAR(DIALOG_CHAR_UPPER_O_CIRCUMFLEX):
            case SPECIAL_CHAR(DIALOG_CHAR_UPPER_O_UMLAUT):
                render_dialog_uppercase_diacritic(dialog, ASCII_TO_DIALOG('O'), strChar & 0xF);
                break;
            case SPECIAL_CHAR(DIALOG_CHAR_LOWER_I_CIRCUMFLEX):
            case SPECIAL_CHAR(DIALOG_CHAR_LOWER_I_UMLAUT):
                render_dialog_lowercase_diacritic(dialog, DIALOG_CHAR_I_NO_DIA, strChar & 0xF);
                break;
#else
            case SPECIAL_CHAR(DIALOG_CHAR_DAKUTEN):
#ifndef VERSION_CN
                mark = DIALOG_MARK_DAKUTEN;
#endif
                break;
            case SPECIAL_CHAR(DIALOG_CHAR_PERIOD_OR_HANDAKUTEN):
#ifndef VERSION_CN
                mark = DIALOG_MARK_HANDAKUTEN;
#endif
                break;
#endif

#ifdef VERSION_CN
            case SPECIAL_CHAR(DIALOG_CHAR_STAR_OPEN): // ???
                xMatrix += 2;
                linePos += 2;
                break;
#endif

            case SPECIAL_CHAR(DIALOG_CHAR_SPACE):
#ifdef VERSION_EU
                gDialogX += gDialogCharWidths[DIALOG_CHAR_SPACE];
#else
#if defined(VERSION_SH)
                if (linePos != 0) {
#endif
                    xMatrix++;
#if defined(VERSION_SH)
                }
#endif
                linePos++;
#endif
                break;

#if defined(VERSION_SH)
            case SPECIAL_CHAR(DIALOG_CHAR_PERIOD):
                adjust_pos_and_print_period_char(&xMatrix, &linePos);
                break;
#else
            case SPECIAL_CHAR(DIALOG_CHAR_SLASH):
#ifdef VERSION_EU
                gDialogX += gDialogCharWidths[DIALOG_CHAR_SPACE] * 2;
#else
                xMatrix += 2;
                linePos += 2;
#endif
                break;
            case SPECIAL_CHAR(DIALOG_CHAR_MULTI_THE):
#ifdef VERSION_EU
                render_multi_text_string_lines(STRING_THE, lineNum, linesPerBox, xMatrix, lowerBound, dialog);
#else
                render_multi_text_string_lines(STRING_THE, lineNum, &linePos, linesPerBox, xMatrix, lowerBound);
#endif
                xMatrix = 1;
                break;
            case SPECIAL_CHAR(DIALOG_CHAR_MULTI_YOU):
#ifdef VERSION_EU
                render_multi_text_string_lines(STRING_YOU, lineNum, linesPerBox, xMatrix, lowerBound, dialog);
#else
                render_multi_text_string_lines(STRING_YOU, lineNum, &linePos, linesPerBox, xMatrix, lowerBound);
#endif
                xMatrix = 1;
                break;
#endif

            case SPECIAL_CHAR(DIALOG_CHAR_STAR_COUNT):
#ifdef VERSION_EU
                render_star_count_dialog_text(dialog, &xMatrix);
#else
                render_star_count_dialog_text(&xMatrix, &linePos);
#endif
                break;

#ifdef VERSION_EU
            case SPECIAL_CHAR(DIALOG_CHAR_DOUBLE_LOW_QUOTE):
                render_generic_dialog_char_at_pos(dialog, gDialogX, gDialogY + 8, 0xF6);
                gDialogX += gDialogCharWidths[0xF6];
                break;
#endif

            default: // any other character
#ifdef VERSION_CN
                if (strChar >= 0x0100) {
                    strChar = strChar * 2 - 0x0100;

                    if (lineNum < lowerBound || lineNum > (lowerBound + linesPerBox)) {
                        break;
                    }

                    if (linePos != 0 || xMatrix != 1) {
                        create_dl_translation_matrix(MENU_MTX_NOPUSH, gDialogCharWidths[DIALOG_CHAR_SPACE] * (xMatrix - 1), 0.0f, 0.0f);
                    }

                    render_generic_char_cn(strChar);
                    create_dl_translation_matrix(MENU_MTX_NOPUSH, 8.0f, 0.0f, 0.0f);
                    render_generic_char_cn(strChar + 1);
                    create_dl_translation_matrix(MENU_MTX_NOPUSH, 8.0f, 0.0f, 0.0f);
                } else {
                    if (lineNum < lowerBound || lineNum > (lowerBound + linesPerBox)) {
                        break;
                    }

                    if (linePos != 0 || xMatrix != 1) {
                        create_dl_translation_matrix(MENU_MTX_NOPUSH, gDialogCharWidths[DIALOG_CHAR_SPACE] * (xMatrix - 1), 0.0f, 0.0f);
                    }

                    render_generic_char(strChar);
                    create_dl_translation_matrix(MENU_MTX_NOPUSH, gDialogCharWidths[strChar], 0.0f, 0.0f);
                }

                xMatrix = 1;
                linePos++;
#elif defined(VERSION_SH)
#ifdef VERSION_SH
                if (lineNum >= lowerBound && lineNum <= (lowerBound + linesPerBox)) {
#endif
                    if (linePos != 0) {
                        create_dl_translation_matrix(MENU_MTX_NOPUSH, 10 * xMatrix, 0, 0);
                    }

                    render_generic_char(strChar);
                    xMatrix = 1;
                    linePos++;

                    if (mark != DIALOG_MARK_NONE) {
                        create_dl_translation_matrix(MENU_MTX_PUSH, 5.0f, 7.0f, 0);
                        render_generic_char(DIALOG_CHAR_MARK_START + mark);
                        gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
                        mark = DIALOG_MARK_NONE;
                    }
#ifdef VERSION_SH
                }
#endif
#elif defined(VERSION_US)
                if (lineNum >= lowerBound && lineNum <= (lowerBound + linesPerBox)) {
                    if (linePos != 0 || xMatrix != 1) {
                        create_dl_translation_matrix(
                            MENU_MTX_NOPUSH, (f32)(gDialogCharWidths[DIALOG_CHAR_SPACE] * (xMatrix - 1)), 0, 0);
                    }

                    render_generic_char(strChar);
                    create_dl_translation_matrix(MENU_MTX_NOPUSH, (f32)(gDialogCharWidths[strChar]), 0, 0);
                    xMatrix = 1;
                    linePos++;
                }
#else // VERSION_EU
                if (lineNum >= lowerBound && lineNum <= (lowerBound + linesPerBox)) {
                    render_generic_dialog_char_at_pos(dialog, gDialogX, gDialogY, strChar);
                }
                gDialogX += gDialogCharWidths[strChar];
#endif
        }

#ifdef VERSION_CN
        strIndex += 2;
#else
        strIndex++;
#endif
    }

    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);

    if (gMenuState == MENU_STATE_DIALOG_OPEN) {
        if (pageState == DIALOG_PAGE_STATE_END) {
            gNextDialogPageStartStrIndex = -1;
        } else {
            gNextDialogPageStartStrIndex = strIndex;
        }
    }

    gLastDialogLineNum = lineNum;
}

#if defined(VERSION_SH)
    #define X_VAL4_1 50
    #define X_VAL4_2 25
    #define Y_VAL4_1 1
    #define Y_VAL4_2 20
#elif defined(VERSION_CN)
    #define X_VAL4_1 58
    #define X_VAL4_2 0
    #define Y_VAL4_1 2
    #define Y_VAL4_2 20
#else
    #define X_VAL4_1 56
    #define X_VAL4_2 9
    #define Y_VAL4_1 2
    #define Y_VAL4_2 16
#endif

void render_dialog_triangle_choice(void) {
    if (gMenuState == MENU_STATE_DIALOG_OPEN) {
        handle_menu_scrolling(MENU_SCROLL_HORIZONTAL, &gMenuLineNum, 1, 2);
    }

    create_dl_translation_matrix(MENU_MTX_NOPUSH, ((gMenuLineNum - 1) * X_VAL4_1) + X_VAL4_2, Y_VAL4_1 - (gLastDialogLineNum * Y_VAL4_2), 0);

    if (gDialogBoxType == DIALOG_TEXT_WHITE) { // White Text
        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
    } else { // Black Text
        gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, 255);
    }

    gSPDisplayList(gDisplayListHead++, dl_draw_triangle);
}

#if defined(VERSION_SH)
    #define X_VAL5 123.0f
    #define Y_VAL5_1 -20
    #define Y_VAL5_2 2
    #define X_Y_VAL6 0.8f
#elif defined(VERSION_US)
    #define X_VAL5 118.0f
    #define Y_VAL5_1 -16
    #define Y_VAL5_2 5
    #define X_Y_VAL6 0.8f
#elif defined(VERSION_EU)
    #define X_VAL5 122.0f
    #define Y_VAL5_1 -16
    #define Y_VAL5_2 3
    #define X_Y_VAL6 0.5f
#elif defined(VERSION_CN)
    #define X_VAL5 118.0f
    #define Y_VAL5_1 -18
    #define Y_VAL5_2 5
    #define X_Y_VAL6 0.8f
#endif

void render_dialog_triangle_next(s8 linesPerBox) {
    s32 globalTimer = gGlobalTimer;

    if (globalTimer & 8) {
        return;
    }

    create_dl_translation_matrix(MENU_MTX_PUSH, X_VAL5, (linesPerBox * Y_VAL5_1) + Y_VAL5_2, 0);
    create_dl_scale_matrix(MENU_MTX_NOPUSH, X_Y_VAL6, X_Y_VAL6, 1.0f);
    create_dl_rotation_matrix(MENU_MTX_NOPUSH, -90.0f, 0, 0, 1.0f);

    if (gDialogBoxType == DIALOG_TEXT_WHITE) { // White Text
        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
    } else { // Black Text
        gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, 255);
    }

    gSPDisplayList(gDisplayListHead++, dl_draw_triangle);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
}

void handle_special_dialog_text(s16 dialogID) { // dialog ID tables, in order
    // King Bob-omb (Start), Whomp (Start), King Bob-omb (throw him out), Eyerock (Start), Wiggler (Start)
    s16 dialogBossStart[] = { DIALOG_017, DIALOG_174, DIALOG_114, DIALOG_128, DIALOG_117, DIALOG_150 };
    // Koopa the Quick (BoB), Koopa the Quick (THI), Penguin Race, Fat Penguin Race (120 stars)
    s16 dialogRaceSound[] = { DIALOG_005, DIALOG_009, DIALOG_055, DIALOG_164 };
    // Red Switch, Green Switch, Blue Switch, 100 coins star, Bowser Red Coin Star
    s16 dialogStarSound[] = { DIALOG_010, DIALOG_011, DIALOG_012, DIALOG_013, DIALOG_014 };
    // King Bob-omb (Start), Whomp (Defeated), King Bob-omb (Defeated, missing in JP), Eyerock (Defeated), Wiggler (Defeated)
#if BUGFIX_KING_BOB_OMB_FADE_MUSIC
    s16 dialogBossStop[] = { DIALOG_017, DIALOG_174, DIALOG_115, DIALOG_116, DIALOG_118, DIALOG_152 };
#else
    //! @bug JP misses King Bob-omb defeated DIALOG_116, meaning that the boss music will still
    //! play after King Bob-omb is defeated until BoB loads it's music after the star cutscene
    s16 dialogBossStop[] = { DIALOG_017, DIALOG_174, DIALOG_115, DIALOG_118, DIALOG_152 };
#endif
    s16 i;

    for (i = 0; i < (s16) ARRAY_COUNT(dialogBossStart); i++) {
        if (dialogBossStart[i] == dialogID) {
            seq_player_unlower_volume(SEQ_PLAYER_LEVEL, 60);
            play_music(SEQ_PLAYER_LEVEL, SEQUENCE_ARGS(4, SEQ_EVENT_BOSS), 0);
            return;
        }
    }

    for (i = 0; i < (s16) ARRAY_COUNT(dialogRaceSound); i++) {
        if (dialogRaceSound[i] == dialogID && gMenuLineNum == DIALOG_RESPONSE_YES) {
            play_race_fanfare();
            return;
        }
    }

    for (i = 0; i < (s16) ARRAY_COUNT(dialogStarSound); i++) {
        if (dialogStarSound[i] == dialogID && gMenuLineNum == DIALOG_RESPONSE_YES) {
            play_sound(SOUND_MENU_STAR_SOUND, gGlobalSoundSource);
            return;
        }
    }

    for (i = 0; i < (s16) ARRAY_COUNT(dialogBossStop); i++) {
        if (dialogBossStop[i] == dialogID) {
            seq_player_fade_out(SEQ_PLAYER_LEVEL, 1);
            return;
        }
    }
}

s16 gMenuMode = MENU_MODE_NONE;

#ifdef VERSION_CN
u8 gEndCutsceneStrEn0[] = { TEXT_EMPTY_STRING };
u8 gEndCutsceneStrEn1[] = { TEXT_EMPTY_STRING };
u8 gEndCutsceneStrEn2[] = { TEXT_EMPTY_STRING };
u8 gEndCutsceneStrEn3[] = { TEXT_EMPTY_STRING };
u8 gEndCutsceneStrEn4[] = { TEXT_EMPTY_STRING };
u8 gEndCutsceneStrEn5[] = { TEXT_EMPTY_STRING };
u8 gEndCutsceneStrEn6[] = { TEXT_EMPTY_STRING };
u8 gEndCutsceneStrEn7[] = { TEXT_EMPTY_STRING };
u8 gEndCutsceneStrEn8[] = { TEXT_EMPTY_STRING };
#else
u8 gEndCutsceneStrEn0[] = { TEXT_FILE_MARIO_EXCLAMATION };
u8 gEndCutsceneStrEn1[] = { TEXT_POWER_STARS_RESTORED };
u8 gEndCutsceneStrEn2[] = { TEXT_THANKS_TO_YOU };
u8 gEndCutsceneStrEn3[] = { TEXT_THANK_YOU_MARIO };
u8 gEndCutsceneStrEn4[] = { TEXT_SOMETHING_SPECIAL };
u8 gEndCutsceneStrEn5[] = { TEXT_LISTEN_EVERYBODY };
u8 gEndCutsceneStrEn6[] = { TEXT_LETS_HAVE_CAKE };
u8 gEndCutsceneStrEn7[] = { TEXT_FOR_MARIO };
u8 gEndCutsceneStrEn8[] = { TEXT_FILE_MARIO_QUESTION };
#endif

u8 *gEndCutsceneStringsEn[] = {
    gEndCutsceneStrEn0,
    gEndCutsceneStrEn1,
    gEndCutsceneStrEn2,
    gEndCutsceneStrEn3,
    gEndCutsceneStrEn4,
    gEndCutsceneStrEn5,
    gEndCutsceneStrEn6,
    gEndCutsceneStrEn7,
    // This [8] string is actually unused. In the cutscene handler, the developers do not
    // set the 8th one, but use the first string again at the very end, so Peach ends up
    // saying "Mario!" twice. It is likely that she was originally meant to say "Mario?" at
    // the end but the developers changed their mind, possibly because the line recorded
    // sounded more like an exclamation than a question.
    gEndCutsceneStrEn8,
    NULL
};

#ifdef VERSION_EU
u8 gEndCutsceneStrFr0[] = { TEXT_FILE_MARIO_EXCLAMATION };
u8 gEndCutsceneStrFr1[] = { TEXT_POWER_STARS_RESTORED_FR };
u8 gEndCutsceneStrFr2[] = { TEXT_THANKS_TO_YOU_FR };
u8 gEndCutsceneStrFr3[] = { TEXT_THANK_YOU_MARIO_FR };
u8 gEndCutsceneStrFr4[] = { TEXT_SOMETHING_SPECIAL_FR };
u8 gEndCutsceneStrFr5[] = { TEXT_COME_ON_EVERYBODY_FR };
u8 gEndCutsceneStrFr6[] = { TEXT_LETS_HAVE_CAKE_FR };
u8 gEndCutsceneStrFr7[] = { TEXT_FOR_MARIO_FR };
u8 gEndCutsceneStrFr8[] = { TEXT_FILE_MARIO_QUESTION };

u8 *gEndCutsceneStringsFr[] = {
    gEndCutsceneStrFr0,
    gEndCutsceneStrFr1,
    gEndCutsceneStrFr2,
    gEndCutsceneStrFr3,
    gEndCutsceneStrFr4,
    gEndCutsceneStrFr5,
    gEndCutsceneStrFr6,
    gEndCutsceneStrFr7,
    gEndCutsceneStrFr8,
    NULL
};

u8 gEndCutsceneStrDe0[] = { TEXT_FILE_MARIO_EXCLAMATION };
u8 gEndCutsceneStrDe1[] = { TEXT_POWER_STARS_RESTORED_DE };
u8 gEndCutsceneStrDe2[] = { TEXT_THANKS_TO_YOU_DE };
u8 gEndCutsceneStrDe3[] = { TEXT_THANK_YOU_MARIO_DE };
u8 gEndCutsceneStrDe4[] = { TEXT_SOMETHING_SPECIAL_DE };
u8 gEndCutsceneStrDe5[] = { TEXT_COME_ON_EVERYBODY_DE };
u8 gEndCutsceneStrDe6[] = { TEXT_LETS_HAVE_CAKE_DE };
u8 gEndCutsceneStrDe7[] = { TEXT_FOR_MARIO_DE };
u8 gEndCutsceneStrDe8[] = { TEXT_FILE_MARIO_QUESTION };

u8 *gEndCutsceneStringsDe[] = {
    gEndCutsceneStrDe0,
    gEndCutsceneStrDe1,
    gEndCutsceneStrDe2,
    gEndCutsceneStrDe3,
    gEndCutsceneStrDe4,
    gEndCutsceneStrDe5,
    gEndCutsceneStrDe6,
    gEndCutsceneStrDe7,
    gEndCutsceneStrDe8,
    NULL
};
#endif

u16 gCutsceneMsgFade = 0;
s16 gCutsceneMsgIndex = -1;
s16 gCutsceneMsgDuration = -1;
s16 gCutsceneMsgTimer = 0;
s8 gDialogCameraAngleIndex = CAM_SELECTION_MARIO;
s8 gDialogCourseActNum = 1;

#if defined(VERSION_SH)
    #define DIAG_VAL1 20
    #define DIAG_VAL2 240
    #define DIAG_VAL3 130
    #define DIAG_VAL4 4
#else
    #define DIAG_VAL1 16
#if defined(VERSION_US) || defined(VERSION_CN)
    #define DIAG_VAL2 240
#else
    #define DIAG_VAL2 238
#endif
    #define DIAG_VAL3 132
    #define DIAG_VAL4 5
#endif

void render_dialog_entries(void) {
    void **dialogTable;
    struct DialogEntry *dialog;
    s8 lowerBound = 0;

#ifdef VERSION_EU
    gInGameLanguage = eu_get_language();
    switch (gInGameLanguage) {
        case LANGUAGE_ENGLISH:
            dialogTable = segmented_to_virtual(dialog_table_eu_en);
            break;
        case LANGUAGE_FRENCH:
            dialogTable = segmented_to_virtual(dialog_table_eu_fr);
            break;
        case LANGUAGE_GERMAN:
            dialogTable = segmented_to_virtual(dialog_table_eu_de);
            break;
    }
#else
    dialogTable = segmented_to_virtual(seg2_dialog_table);
#endif
    dialog = segmented_to_virtual(dialogTable[gDialogID]);

    // if the dialog entry is invalid, set the ID to DIALOG_NONE.
    if (dialog == segmented_to_virtual(NULL)) {
        gDialogID = DIALOG_NONE;
        return;
    }

#ifdef VERSION_EU
    gDialogX = 0;
    gDialogY = 0;
#endif

    switch (gMenuState) {
        case MENU_STATE_DIALOG_OPENING:
            if (gDialogBoxAngle == DIALOG_BOX_ANGLE_DEFAULT) {
                play_dialog_sound(gDialogID);
                play_sound(SOUND_MENU_MESSAGE_APPEAR, gGlobalSoundSource);
            }

            gDialogBoxAngle -= 10.0;
            gDialogBoxScale -= 2.0;

            if (gDialogBoxAngle == 0.0f) {
                gMenuState = MENU_STATE_DIALOG_OPEN;
                gMenuLineNum = 1;
            }
            lowerBound = 1;
            break;

        case MENU_STATE_DIALOG_OPEN:
            gDialogBoxAngle = 0.0f;

            if ((gPlayer1Controller->buttonPressed & A_BUTTON)
             || (gPlayer1Controller->buttonPressed & B_BUTTON)) {
                if (gNextDialogPageStartStrIndex == -1) {
                    handle_special_dialog_text(gDialogID);
                    gMenuState = MENU_STATE_DIALOG_CLOSING;
                } else {
                    gMenuState = MENU_STATE_DIALOG_SCROLLING;
                    play_sound(SOUND_MENU_MESSAGE_NEXT_PAGE, gGlobalSoundSource);
                }
            }
            lowerBound = 1;
            break;

        case MENU_STATE_DIALOG_SCROLLING:
            gDialogScrollOffsetY += dialog->linesPerBox / 2;

            if (gDialogScrollOffsetY >= dialog->linesPerBox * DIAG_VAL1) {
                gDialogPageStartStrIndex = gNextDialogPageStartStrIndex;
                gMenuState = MENU_STATE_DIALOG_OPEN;
                gDialogScrollOffsetY = 0;
            }
            lowerBound = (gDialogScrollOffsetY / DIAG_VAL1) + 1;
            break;

        case MENU_STATE_DIALOG_CLOSING:
            if (gDialogBoxAngle == 20.0f) {
                level_set_transition(0, NULL);
                play_sound(SOUND_MENU_MESSAGE_DISAPPEAR, gGlobalSoundSource);

                if (gDialogBoxType == DIALOG_TEXT_BLACK) {
                    trigger_cutscene_dialog(2);
                }

                gDialogResponse = gMenuLineNum;
            }

            gDialogBoxAngle += 10.0f;
            gDialogBoxScale += 2.0f;

            if (gDialogBoxAngle == DIALOG_BOX_ANGLE_DEFAULT) {
                gMenuState = MENU_STATE_DEFAULT;
                gDialogID = DIALOG_NONE;
                gDialogPageStartStrIndex = 0;
                gDialogWithChoice = FALSE;
                gNextDialogPageStartStrIndex = 0;
                gDialogResponse = DIALOG_RESPONSE_NONE;
            }
            lowerBound = 1;
            break;
    }

    render_dialog_box_type(dialog, dialog->linesPerBox);

    gDPSetScissor(
        gDisplayListHead++, G_SC_NON_INTERLACE,
        // Horizontal scissoring isn't really required and can potentially mess up widescreen enhancements.
#ifdef WIDESCREEN
        0,
#else
        ensure_nonnegative(dialog->leftOffset),
#endif
        ensure_nonnegative(DIAG_VAL2 - dialog->width),
#ifdef VERSION_EU
#ifdef WIDESCREEN
        SCREEN_WIDTH,
#else
        ensure_nonnegative(dialog->leftOffset + (DIAG_VAL3 / gDialogBoxScale)),
#endif
        ensure_nonnegative((240 - dialog->width) + (dialog->linesPerBox * 80 / DIAG_VAL4 / gDialogBoxScale))
#else
#ifdef WIDESCREEN
        SCREEN_WIDTH,
#else
        ensure_nonnegative(DIAG_VAL3 + dialog->leftOffset),
#endif
        ensure_nonnegative((240 - dialog->width) + (dialog->linesPerBox * 80 / DIAG_VAL4))
#endif
    );

    handle_dialog_text_and_pages(0, dialog, lowerBound);
    if (gNextDialogPageStartStrIndex == -1 && gDialogWithChoice == TRUE) {
        render_dialog_triangle_choice();
    }
    gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 2, 2, SCREEN_WIDTH - BORDER_HEIGHT / 2, SCREEN_HEIGHT - BORDER_HEIGHT / 2);
    if (gNextDialogPageStartStrIndex != -1 && gMenuState == MENU_STATE_DIALOG_OPEN) {
        render_dialog_triangle_next(dialog->linesPerBox);
    }
}

// Calls a gMenuMode value defined by render_menus_and_dialogs cases
void set_menu_mode(s16 mode) {
    if (gMenuMode == MENU_MODE_NONE) {
        gMenuMode = mode;
    }
}

void reset_cutscene_msg_fade(void) {
    gCutsceneMsgFade = 0;
}

#if CREDITS_TEXT_STRING_FONT
#define DL_CREDIT_TEXT_START    dl_ia_text_begin
#define DL_CREDIT_TEXT_END      dl_ia_text_end
#else
#define DL_CREDIT_TEXT_START    dl_rgba16_text_begin
#define DL_CREDIT_TEXT_END      dl_rgba16_text_end
#endif
void dl_rgba16_begin_cutscene_msg_fade(void) {
    gSPDisplayList(gDisplayListHead++, DL_CREDIT_TEXT_START);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gCutsceneMsgFade);
}

void dl_rgba16_stop_cutscene_msg_fade(void) {
    gSPDisplayList(gDisplayListHead++, DL_CREDIT_TEXT_END);

    if (gCutsceneMsgFade < 250) {
        gCutsceneMsgFade += 25;
    } else {
        gCutsceneMsgFade = 255;
    }
}
#undef DL_CREDIT_TEXT_START
#undef DL_CREDIT_TEXT_END

#if !CREDITS_TEXT_STRING_FONT
u8 ascii_to_credits_char(u8 c) {
    if (c >= 'A' && c <= 'Z') {
        return (c - ('A' - 0xA));
    }

    if (c >= 'a' && c <= 'z') { // remap lower to upper case
        return (c - ('a' - 0xA));
    }

    if (c == ' ') {
        return GLOBAL_CHAR_SPACE;
    }

    if (c == '.') {
        return 0x24;
    }

    if (c == '3') {
        return ASCII_TO_DIALOG('3');
    }

    if (c == '4') {
        return ASCII_TO_DIALOG('4');
    }

    if (c == '6') {
        return ASCII_TO_DIALOG('6');
    }

    return GLOBAL_CHAR_SPACE;
}

void print_credits_str_ascii(s16 x, s16 y, const char *str) {
    s32 pos = 0;
    u8 c = str[pos];
    u8 creditStr[100];

    while (c != '\0') {
        creditStr[pos++] = ascii_to_credits_char(c);
        c = str[pos];
    }

    creditStr[pos] = GLOBAL_CHAR_TERMINATOR;

    print_credits_string(x, y, creditStr);
}
#endif

void set_cutscene_message(s16 xOffset, s16 yOffset, s16 msgIndex, s16 msgDuration) {
    // is message done printing?
    if (gCutsceneMsgIndex == -1) {
        gCutsceneMsgIndex = msgIndex;
        gCutsceneMsgDuration = msgDuration;
        gCutsceneMsgTimer = 0;
        gCutsceneMsgXOffset = xOffset;
        gCutsceneMsgYOffset = yOffset;
        gCutsceneMsgFade = 0;
    }
}

void do_cutscene_handler(void) {
    s16 x;

    // is a cutscene playing? do not perform this handler's actions if so.
    if (gCutsceneMsgIndex == -1) {
        return;
    }

    create_dl_ortho_matrix();

    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gCutsceneMsgFade);

#ifdef VERSION_EU
    switch (eu_get_language()) {
        case LANGUAGE_ENGLISH:
            x = get_str_x_pos_from_center(gCutsceneMsgXOffset, gEndCutsceneStringsEn[gCutsceneMsgIndex], 10.0f);
            print_generic_string(x, 240 - gCutsceneMsgYOffset, gEndCutsceneStringsEn[gCutsceneMsgIndex]);
            break;
        case LANGUAGE_FRENCH:
            x = get_str_x_pos_from_center(gCutsceneMsgXOffset, gEndCutsceneStringsFr[gCutsceneMsgIndex], 10.0f);
            print_generic_string(x, 240 - gCutsceneMsgYOffset, gEndCutsceneStringsFr[gCutsceneMsgIndex]);
            break;
        case LANGUAGE_GERMAN:
            x = get_str_x_pos_from_center(gCutsceneMsgXOffset, gEndCutsceneStringsDe[gCutsceneMsgIndex], 10.0f);
            print_generic_string(x, 240 - gCutsceneMsgYOffset, gEndCutsceneStringsDe[gCutsceneMsgIndex]);
            break;
    }
#else
    // get the x coordinate of where the cutscene string starts.
    x = get_str_x_pos_from_center(gCutsceneMsgXOffset, gEndCutsceneStringsEn[gCutsceneMsgIndex], 10.0f);
    print_generic_string(x, 240 - gCutsceneMsgYOffset, gEndCutsceneStringsEn[gCutsceneMsgIndex]);
#endif

    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);

    // if the timing variable is less than 5, increment
    // the fade until we are at full opacity.
    if (gCutsceneMsgTimer < 5) {
        gCutsceneMsgFade += 50;
    }

    // if the cutscene frame length + the fade-in counter is
    // less than the timer, it means we have exceeded the
    // time that the message is supposed to remain on
    // screen. if (message_duration = 50) and (msg_timer = 55)
    // then after the first 5 frames, the message will remain
    // on screen for another 50 frames until it starts fading.
    if (gCutsceneMsgDuration + 5 < gCutsceneMsgTimer) {
        gCutsceneMsgFade -= 50;
    }

    // like the first check, it takes 5 frames to fade out, so
    // perform a + 10 to account for the earlier check (10-5=5).
    if (gCutsceneMsgDuration + 10 < gCutsceneMsgTimer) {
        gCutsceneMsgIndex = -1;
        gCutsceneMsgFade = 0;
        gCutsceneMsgTimer = 0;
        return;
    }

    gCutsceneMsgTimer++;
}

#define PEACH_MESSAGE_TIMER 250

#if defined(VERSION_SH)
    #define STR_X 53
    #define STR_Y 136
#else
    #define STR_X 38
    #define STR_Y 142
#endif

// "Dear Mario" message handler
void print_peach_letter_message(void) {
    void **dialogTable;
    struct DialogEntry *dialog;
    u8 *str;

#ifdef VERSION_EU
    gInGameLanguage = eu_get_language();
    switch (gInGameLanguage) {
        case LANGUAGE_ENGLISH:
            dialogTable = segmented_to_virtual(dialog_table_eu_en);
            break;
        case LANGUAGE_FRENCH:
            dialogTable = segmented_to_virtual(dialog_table_eu_fr);
            break;
        case LANGUAGE_GERMAN:
            dialogTable = segmented_to_virtual(dialog_table_eu_de);
            break;
    }
#else
    dialogTable = segmented_to_virtual(seg2_dialog_table);
#endif
    dialog = segmented_to_virtual(dialogTable[gDialogID]);
    str = segmented_to_virtual(dialog->str);

    create_dl_translation_matrix(MENU_MTX_PUSH, 97.0f, 118.0f, 0);

    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gCutsceneMsgFade);
    gSPDisplayList(gDisplayListHead++, castle_grounds_seg7_dl_0700EA58);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 20, 20, 20, gCutsceneMsgFade);

    print_generic_string(STR_X, STR_Y, str);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);
    gDPSetEnvColor(gDisplayListHead++, 200, 80, 120, gCutsceneMsgFade);
    gSPDisplayList(gDisplayListHead++, castle_grounds_seg7_us_dl_0700F2E8);

    // at the start/end of message, reset the fade.
    if (gCutsceneMsgTimer == 0) {
        gCutsceneMsgFade = 0;
    }

    // we're less than 20 increments, so increase the fade.
    if (gCutsceneMsgTimer < 20) {
        gCutsceneMsgFade += 10;
    }

    // we're after PEACH_MESSAGE_TIMER increments, so decrease the fade.
    if (gCutsceneMsgTimer > PEACH_MESSAGE_TIMER) {
        gCutsceneMsgFade -= 10;
    }

    // 20 increments after the start of the decrease, we're
    // back where we are, so reset everything at the end.
    if (gCutsceneMsgTimer > (PEACH_MESSAGE_TIMER + 20)) {
        gCutsceneMsgIndex = -1;
        gCutsceneMsgFade = 0; //! uselessly reset since the next execution will just set it to 0 again.
        gDialogID = DIALOG_NONE;
        gCutsceneMsgTimer = 0;
        return; // return to avoid incrementing the timer
    }

    gCutsceneMsgTimer++;
}

/**
 * Renders the cannon reticle when Mario is inside a cannon.
 * Formed by four triangles.
 */
void render_hud_cannon_reticle(void) {
    create_dl_translation_matrix(MENU_MTX_PUSH, 160.0f, 120.0f, 0);

    gDPSetEnvColor(gDisplayListHead++, 50, 50, 50, 180);
    create_dl_translation_matrix(MENU_MTX_PUSH, -20.0f, -8.0f, 0);
    gSPDisplayList(gDisplayListHead++, dl_draw_triangle);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);

    create_dl_translation_matrix(MENU_MTX_PUSH, 20.0f, 8.0f, 0);
    create_dl_rotation_matrix(MENU_MTX_NOPUSH, 180.0f, 0, 0, 1.0f);
    gSPDisplayList(gDisplayListHead++, dl_draw_triangle);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);

    create_dl_translation_matrix(MENU_MTX_PUSH, 8.0f, -20.0f, 0);
    create_dl_rotation_matrix(MENU_MTX_NOPUSH, 90.0f, 0, 0, 1.0f);
    gSPDisplayList(gDisplayListHead++, dl_draw_triangle);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);

    create_dl_translation_matrix(MENU_MTX_PUSH, -8.0f, 20.0f, 0);
    create_dl_rotation_matrix(MENU_MTX_NOPUSH, -90.0f, 0, 0, 1.0f);
    gSPDisplayList(gDisplayListHead++, dl_draw_triangle);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);

    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
}

void reset_red_coins_collected(void) {
    gRedCoinsCollected = 0;
}

void change_dialog_camera_angle(void) {
    if (cam_select_alt_mode(0) == CAM_SELECTION_MARIO) {
        gDialogCameraAngleIndex = CAM_SELECTION_MARIO;
    } else {
        gDialogCameraAngleIndex = CAM_SELECTION_FIXED;
    }
}

// ex-alo change
// properly shades the screen using a rectangle instead of a triangle
void shade_screen(void) {
    Gfx* dlHead = gDisplayListHead;

    gSPDisplayList(dlHead++, dl_shade_screen_begin);
    gDPFillRectangle(dlHead++, GFX_DIMENSIONS_RECT_FROM_LEFT_EDGE(0), BORDER_HEIGHT,
        (GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(0)), ((SCREEN_HEIGHT - BORDER_HEIGHT)));
    gSPDisplayList(dlHead++, dl_shade_screen_end);

    gDisplayListHead = dlHead;
}

void print_animated_red_coin(s16 x, s16 y) {
    u32 globalTimer = gGlobalTimer;

    create_dl_translation_matrix(MENU_MTX_PUSH, x, y, 0);
    create_dl_scale_matrix(MENU_MTX_NOPUSH, 0.2f, 0.2f, 1.0f);
    gDPSetRenderMode(gDisplayListHead++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);

    switch (globalTimer & 6) {
        case 0:
            gSPDisplayList(gDisplayListHead++, coin_seg3_dl_03007940);
            break;
        case 2:
            gSPDisplayList(gDisplayListHead++, coin_seg3_dl_03007968);
            break;
        case 4:
            gSPDisplayList(gDisplayListHead++, coin_seg3_dl_03007990);
            break;
        case 6:
            gSPDisplayList(gDisplayListHead++, coin_seg3_dl_030079B8);
            break;
    }

    gDPSetRenderMode(gDisplayListHead++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
}

void render_pause_red_coins(void) {
    s8 x;

    for (x = 0; x < gRedCoinsCollected; x++) {
        print_animated_red_coin(GFX_DIMENSIONS_FROM_RIGHT_EDGE(30) - x * 20, 16);
    }
}

#ifdef VERSION_EU
u8 gTextCourse[][7] = {
    { TEXT_COURSE },
    { TEXT_COURSE_FR },
    { TEXT_COURSE_DE }
};
#define textCourse gTextCourse
#endif

#if defined(VERSION_SH)
    #define CRS_NUM_X1 93
#elif defined(VERSION_US) || defined(VERSION_CN)
    #define CRS_NUM_X1 100
#elif defined(VERSION_EU)
    #define CRS_NUM_X1 get_string_width(LANGUAGE_ARRAY(textCourse)) + 51
#endif

#if defined(VERSION_EU)
    #define TXT_COURSE_X      48
    #define TXT_STAR_X        89
    #define ACT_NAME_X        107
    #define CRS_NAME_START    3
    #define CRS_NAME_X        108
    #define SECRET_CRS_NAME_X get_str_x_pos_from_center(159, &courseName[CRS_NAME_START], 10.0f)
    #define MYSCORE_X         48
#elif defined(VERSION_CN)
    #define TXT_COURSE_X      63
    #define TXT_STAR_X        98
    #define ACT_NAME_X        112
    #define CRS_NAME_START    6
    #define CRS_NAME_X        117
    #define SECRET_CRS_NAME_X 94
    #define MYSCORE_X         42
#else
    #define TXT_COURSE_X      63
    #define TXT_STAR_X        98
    #define ACT_NAME_X        116
    #define CRS_NAME_START    3
    #define CRS_NAME_X        117
    #define SECRET_CRS_NAME_X 94
    #define MYSCORE_X         62
#endif

void render_pause_my_score_coins(void) {
#ifdef VERSION_EU
    u8 textMyScore[][10] = {
        { TEXT_MY_SCORE },
        { TEXT_MY_SCORE_FR },
        { TEXT_MY_SCORE_DE }
    };
#else
    u8 textCourse[] = { TEXT_COURSE };
    u8 textMyScore[] = { TEXT_MY_SCORE };
#endif
    u8 textStar[] = { TEXT_STAR_DIFF };
    u8 textUnfilledStar[] = { TEXT_UNFILLED_STAR };

    u8 strCourseNum[4];
    void **courseNameTbl;
    u8 *courseName;
    void **actNameTbl;
    u8 *actName;
    u8 courseIndex;
    u8 starFlags;

#ifndef VERSION_EU
    courseNameTbl = segmented_to_virtual(seg2_course_name_table);
    actNameTbl = segmented_to_virtual(seg2_act_name_table);
#endif

    courseIndex = COURSE_NUM_TO_INDEX(gCurrCourseNum);
    starFlags = save_file_get_star_flags(gCurrSaveFileNum - 1, COURSE_NUM_TO_INDEX(gCurrCourseNum));

#ifdef VERSION_EU
    switch (gInGameLanguage) {
        case LANGUAGE_ENGLISH:
            actNameTbl = segmented_to_virtual(act_name_table_eu_en);
            courseNameTbl = segmented_to_virtual(course_name_table_eu_en);
            break;
        case LANGUAGE_FRENCH:
            actNameTbl = segmented_to_virtual(act_name_table_eu_fr);
            courseNameTbl = segmented_to_virtual(course_name_table_eu_fr);
            break;
        case LANGUAGE_GERMAN:
            actNameTbl = segmented_to_virtual(act_name_table_eu_de);
            courseNameTbl = segmented_to_virtual(course_name_table_eu_de);
            break;
    }
#endif

    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gMenuTextAlpha);

    if (courseIndex <= COURSE_NUM_TO_INDEX(COURSE_STAGES_MAX)) {
        print_hud_my_score_coins(1, gCurrSaveFileNum - 1, courseIndex, 178, 103);
        print_hud_my_score_stars(gCurrSaveFileNum - 1, courseIndex, 118, 103);
    }

    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_end);
    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);

    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gMenuTextAlpha);

    if (courseIndex <= COURSE_NUM_TO_INDEX(COURSE_STAGES_MAX)
        && save_file_get_course_star_count(gCurrSaveFileNum - 1, courseIndex) != 0) {
        print_generic_string(MYSCORE_X, 121, LANGUAGE_ARRAY(textMyScore));
    }

    courseName = segmented_to_virtual(courseNameTbl[courseIndex]);

    if (courseIndex <= COURSE_NUM_TO_INDEX(COURSE_STAGES_MAX)) {
        print_generic_string(TXT_COURSE_X, 157, LANGUAGE_ARRAY(textCourse));
        INT_TO_STR_DIFF(gCurrCourseNum, strCourseNum);
        print_generic_string(CRS_NUM_X1, 157, strCourseNum);

        actName = segmented_to_virtual(actNameTbl[COURSE_NUM_TO_INDEX(gCurrCourseNum) * NUM_ACTS_PER_COURSE + gDialogCourseActNum - 1]);

        if (starFlags & (1 << (gDialogCourseActNum - 1))) {
            print_generic_string(TXT_STAR_X, 140, textStar);
        } else {
            print_generic_string(TXT_STAR_X, 140, textUnfilledStar);
        }

        print_generic_string(ACT_NAME_X, 140, actName);
        print_generic_string(CRS_NAME_X, 157, &courseName[CRS_NAME_START]);
    } else {
        print_generic_string(SECRET_CRS_NAME_X, 157, &courseName[CRS_NAME_START]);
    }
    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);
}

#if defined(VERSION_SH)
    #define TXT1_X 4
    #define TXT2_X 116
    #define Y_VAL7 0
#else
    #define TXT1_X 3
    #define TXT2_X 119
    #define Y_VAL7 2
#endif

void render_pause_camera_options(s16 x, s16 y, s8 *index, s16 xIndex) {
    UNUSED_CN u8 textLakituPlayer[] = { TEXT_LAKITU_MARIO };
    UNUSED_CN u8 textLakituStop[] = { TEXT_LAKITU_STOP };
#ifdef VERSION_EU
    u8 textNormalUpClose[][20] = {
        { TEXT_NORMAL_UPCLOSE },
        { TEXT_NORMAL_UPCLOSE_FR },
        { TEXT_NORMAL_UPCLOSE_DE }
    };
    u8 textNormalFixed[][17] = {
        { TEXT_NORMAL_FIXED },
        { TEXT_NORMAL_FIXED_FR },
        { TEXT_NORMAL_FIXED_DE },
    };
#else
    u8 textNormalUpClose[] = { TEXT_NORMAL_UPCLOSE };
    u8 textNormalFixed[] = { TEXT_NORMAL_FIXED };
#endif

    handle_menu_scrolling(MENU_SCROLL_HORIZONTAL, index, 1, 2);

    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gMenuTextAlpha);

#ifdef VERSION_CN
    print_generic_string(x + 14, y + 2, textNormalUpClose);
    print_generic_string(x + 124, y + 2, textNormalFixed);
#else
    print_generic_string(x + 14, y + 2, textLakituPlayer);
    print_generic_string(x + TXT1_X, y - 13, LANGUAGE_ARRAY(textNormalUpClose));
    print_generic_string(x + 124, y + 2, textLakituStop);
    print_generic_string(x + TXT2_X, y - 13, LANGUAGE_ARRAY(textNormalFixed));
#endif

    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);
    create_dl_translation_matrix(MENU_MTX_PUSH, x + ((*index - 1) * xIndex), y + Y_VAL7, 0);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gMenuTextAlpha);
    gSPDisplayList(gDisplayListHead++, dl_draw_triangle);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);

    switch (*index) {
        case CAM_SELECTION_MARIO:
            cam_select_alt_mode(CAM_SELECTION_MARIO);
            break;
        case CAM_SELECTION_FIXED:
            cam_select_alt_mode(CAM_SELECTION_FIXED);
            break;
    }
}

#if defined(VERSION_SH)
    #define X_VAL8 0
    #define Y_VAL8 4
    #define Y_OFFSET1 17
    #define Y_OFFSET2 33
#elif defined(VERSION_US) || defined(VERSION_EU)
    #define X_VAL8 4
    #define Y_VAL8 2
    #define Y_OFFSET1 17
    #define Y_OFFSET2 33
#elif defined(VERSION_CN)
    #define X_VAL8 4
    #define Y_VAL8 2
    #define Y_OFFSET1 20
    #define Y_OFFSET2 38
#endif

void render_pause_course_options(s16 x, s16 y, s8 *index, s16 yIndex) {
#ifdef VERSION_EU
    u8 textContinue[][10] = {
        { TEXT_CONTINUE },
        { TEXT_CONTINUE_FR },
        { TEXT_CONTINUE_DE }
    };
    u8 textExitCourse[][15] = {
        { TEXT_EXIT_COURSE },
        { TEXT_EXIT_COURSE_FR },
        { TEXT_EXIT_COURSE_DE }
    };

    u8 textCameraAngleR[][24] = {
        { TEXT_CAMERA_ANGLE_R },
        { TEXT_CAMERA_ANGLE_R_FR },
        { TEXT_CAMERA_ANGLE_R_DE }
    };
#else
    u8 textContinue[] = { TEXT_CONTINUE };
    u8 textExitCourse[] = { TEXT_EXIT_COURSE };
    u8 textCameraAngleR[] = { TEXT_CAMERA_ANGLE_R };
#endif

    handle_menu_scrolling(MENU_SCROLL_VERTICAL, index, 1, 3);

    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gMenuTextAlpha);

    print_generic_string(x + 10, y - 2, LANGUAGE_ARRAY(textContinue));
    print_generic_string(x + 10, y - Y_OFFSET1, LANGUAGE_ARRAY(textExitCourse));

    if (*index != MENU_OPT_CAMERA_ANGLE_R) {
        print_generic_string(x + 10, y - Y_OFFSET2, LANGUAGE_ARRAY(textCameraAngleR));
        gSPDisplayList(gDisplayListHead++, dl_ia_text_end);

        create_dl_translation_matrix(MENU_MTX_PUSH, x - X_VAL8, (y - ((*index - 1) * yIndex)) - Y_VAL8, 0);

        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gMenuTextAlpha);
        gSPDisplayList(gDisplayListHead++, dl_draw_triangle);
        gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
    } else { // MENU_OPT_CAMERA_ANGLE_R
        render_pause_camera_options(x - 42, y - 42, &gDialogCameraAngleIndex, 110);
    }
}

void render_pause_castle_menu_box(s16 x, s16 y) {
    create_dl_translation_matrix(MENU_MTX_PUSH, x - 78, y - 32, 0);
    create_dl_scale_matrix(MENU_MTX_NOPUSH, 1.2f, 0.8f, 1.0f);
    gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, 105);
    gSPDisplayList(gDisplayListHead++, dl_draw_text_bg_box);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);

    create_dl_translation_matrix(MENU_MTX_PUSH, x + 6, y - 28, 0);
    create_dl_rotation_matrix(MENU_MTX_NOPUSH, 90.0f, 0, 0, 1.0f);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gMenuTextAlpha);
    gSPDisplayList(gDisplayListHead++, dl_draw_triangle);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);

    create_dl_translation_matrix(MENU_MTX_PUSH, x - 9, y - 101, 0);
    create_dl_rotation_matrix(MENU_MTX_NOPUSH, 270.0f, 0, 0, 1.0f);
    gSPDisplayList(gDisplayListHead++, dl_draw_triangle);
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
}

void highlight_last_course_complete_stars(void) {
    u8 completedCourseIndex;

    if (gLastCompletedCourseNum == COURSE_NONE) {
        completedCourseIndex = 0;
    } else {
        completedCourseIndex = COURSE_NUM_TO_INDEX(gLastCompletedCourseNum);

        if (completedCourseIndex >= COURSE_NUM_TO_INDEX(COURSE_BONUS_STAGES)) {
            completedCourseIndex = COURSE_NUM_TO_INDEX(COURSE_BONUS_STAGES);
        }
    }

    gMenuLineNum = completedCourseIndex;
}

#if defined(VERSION_EU)
    #define PAUSE_X get_str_x_pos_from_center_scale(SCREEN_WIDTH / 2, textPause, 12.0f)
#elif defined(VERSION_CN)
    #define PAUSE_X 113
#else
    #define PAUSE_X 123
#endif

void print_hud_pause_colorful_str(void) {
    u8 textPause[] = { TEXT_PAUSE };

    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gMenuTextAlpha);

    print_hud_lut_string(HUD_LUT_GLOBAL, PAUSE_X, 81, textPause);

    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_end);
}

void render_pause_castle_course_stars(s16 x, s16 y, s16 fileIndex, s16 courseIndex) {
    s16 hasStar = 0;

#ifdef VERSION_CN
    u8 str[60];
#else
    u8 str[30];
#endif

    u8 textStar[] = { TEXT_STAR };

    u8 starFlags = save_file_get_star_flags(fileIndex, courseIndex);
    u16 starCount = save_file_get_course_star_count(fileIndex, courseIndex);

    u16 nextStar = 0;

    if (starFlags & (1 << STAR_INDEX_100_COINS)) {
        starCount--;
        print_generic_string(x + 97, y - 5, textStar);
    }

    while (hasStar != starCount) {
        if (starFlags & (1 << nextStar)) {
#ifdef VERSION_CN
            str[nextStar * 4] = 0x00;
            str[nextStar * 4 + 1] = DIALOG_CHAR_STAR_FILLED;
#else
            str[nextStar * 2] = DIALOG_CHAR_STAR_FILLED;
#endif
            hasStar++;
        } else {
#ifdef VERSION_CN
            str[nextStar * 4] = 0x00;
            str[nextStar * 4 + 1] = DIALOG_CHAR_STAR_OPEN;
#else
            str[nextStar * 2] = DIALOG_CHAR_STAR_OPEN;
#endif
        }

#ifdef VERSION_CN
        str[nextStar * 4 + 2] = DIALOG_CHAR_SPECIAL_MODIFIER;
        str[nextStar * 4 + 3] = DIALOG_CHAR_SPACE;
#else
        str[nextStar * 2 + 1] = DIALOG_CHAR_SPACE;
#endif
        nextStar++;
    }

    if (starCount == nextStar && starCount != NUM_ACTS_PER_COURSE) {
#ifdef VERSION_CN
        str[nextStar * 4] = DIALOG_CHAR_SPECIAL_MODIFIER;
        str[nextStar * 4 + 1] = DIALOG_CHAR_SLASH; //! Meant to be DIALOG_CHAR_STAR_OPEN?
        str[nextStar * 4 + 2] = DIALOG_CHAR_SPECIAL_MODIFIER;
        str[nextStar * 4 + 3] = DIALOG_CHAR_SPACE;
#else
        str[nextStar * 2] = DIALOG_CHAR_STAR_OPEN;
        str[nextStar * 2 + 1] = DIALOG_CHAR_SPACE;
#endif
        nextStar++;
    }

#ifdef VERSION_CN
    str[nextStar * 4] = DIALOG_CHAR_SPECIAL_MODIFIER;
    str[nextStar * 4 + 1] = DIALOG_CHAR_TERMINATOR;
#else
    str[nextStar * 2] = DIALOG_CHAR_TERMINATOR;
#endif

    print_generic_string(x + 7, y + 13, str);
}

void render_pause_castle_main_strings(s16 x, s16 y) {
#ifdef VERSION_EU
    void **courseNameTbl;
#else
    void **courseNameTbl = segmented_to_virtual(seg2_course_name_table);
#endif

#ifdef VERSION_EU
    u8 textCoin[] = { TEXT_COIN };
    u8 textX[] = { TEXT_VARIABLE_X };
#else
    u8 textCoin[] = { TEXT_COIN_X };
#endif

    void *courseName;

    u8 strVal[8];
    s16 prevCourseIndex = gMenuLineNum;

#ifdef VERSION_EU
    switch (gInGameLanguage) {
        case LANGUAGE_ENGLISH:
            courseNameTbl = segmented_to_virtual(course_name_table_eu_en);
            break;
        case LANGUAGE_FRENCH:
            courseNameTbl = segmented_to_virtual(course_name_table_eu_fr);
            break;
        case LANGUAGE_GERMAN:
            courseNameTbl = segmented_to_virtual(course_name_table_eu_de);
            break;
    }
#endif

    handle_menu_scrolling(
        MENU_SCROLL_VERTICAL, &gMenuLineNum,
        COURSE_NUM_TO_INDEX(COURSE_MIN) - 1, COURSE_NUM_TO_INDEX(COURSE_BONUS_STAGES) + 1
    );

    if (gMenuLineNum == COURSE_NUM_TO_INDEX(COURSE_BONUS_STAGES) + 1) {
        gMenuLineNum = COURSE_NUM_TO_INDEX(COURSE_MIN); // Exceeded max, set to min
    }

    if (gMenuLineNum == COURSE_NUM_TO_INDEX(COURSE_MIN) - 1) {
        gMenuLineNum = COURSE_NUM_TO_INDEX(COURSE_BONUS_STAGES); // Exceeded min, set to max
    }

    if (gMenuLineNum != COURSE_NUM_TO_INDEX(COURSE_BONUS_STAGES)) {
        while (save_file_get_course_star_count(gCurrSaveFileNum - 1, gMenuLineNum) == 0) {
            if (gMenuLineNum >= prevCourseIndex) {
                gMenuLineNum++;
            } else {
                gMenuLineNum--;
            }

            if (gMenuLineNum == COURSE_NUM_TO_INDEX(COURSE_STAGES_MAX) + 1
                || gMenuLineNum == COURSE_NUM_TO_INDEX(COURSE_MIN) - 1) {
                gMenuLineNum = COURSE_NUM_TO_INDEX(COURSE_BONUS_STAGES);
                break;
            }
        }
    }

    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gMenuTextAlpha);

    if (gMenuLineNum <= COURSE_NUM_TO_INDEX(COURSE_STAGES_MAX)) { // Main courses
        courseName = segmented_to_virtual(courseNameTbl[gMenuLineNum]);
        render_pause_castle_course_stars(x, y, gCurrSaveFileNum - 1, gMenuLineNum);
        print_generic_string(x + 34, y - 5, textCoin);
#ifdef VERSION_EU
        print_generic_string(x + 44, y - 5, textX);
#endif
        INT_TO_STR_DIFF(save_file_get_course_coin_score(gCurrSaveFileNum - 1, gMenuLineNum), strVal);
        print_generic_string(x + 54, y - 5, strVal);
#ifdef VERSION_EU
        print_generic_string(x - 17, y + 30, courseName);
#endif
    } else { // Castle secret stars
        u8 textStarX[] = { TEXT_STAR_X };
        courseName = segmented_to_virtual(courseNameTbl[COURSE_MAX]);
        print_generic_string(x + 40, y + 13, textStarX);
        INT_TO_STR_DIFF(save_file_get_total_star_count(gCurrSaveFileNum - 1, COURSE_BONUS_STAGES - 1, COURSE_MAX - 1), strVal);
        print_generic_string(x + 60, y + 13, strVal);
#ifdef VERSION_EU
        print_generic_string(get_str_x_pos_from_center(x + 51, courseName, 10.0f), y + 30, courseName);
#endif
    }

#ifndef VERSION_EU
    print_generic_string(x - 9, y + 30, courseName);
#endif

    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);
}

s8 gCourseCompleteCoinsEqual = FALSE;
s32 gCourseCompleteScreenTimer = 0;
s32 gCourseCompleteCoins = 0;
s8 gHudFlash = 0;

// ex-alo change
// Make this a function due to diffs
#if EXIT_COURSE_ANYWHERE
#define should_render_pause_options(m) TRUE
#else
u8 should_render_pause_options(struct PlayerState *m) {
    return (m->action & ACT_FLAG_PAUSE_EXIT)
#ifdef CHEATS_ACTIONS
    || (Cheats.EnableCheats && Cheats.ExitAnywhere) // Added support for the "Exit course at any time" cheat
#endif
    ;
}
#endif

s16 render_pause_screen(void) {
    s16 index;

#ifdef VERSION_EU
    gInGameLanguage = eu_get_language();
#endif
#ifdef EXT_OPTIONS_MENU
    if (optmenu_open == 0) {
#endif
    switch (gMenuState) {
        case MENU_STATE_PAUSE_SCREEN_OPENING:
            gMenuLineNum = MENU_OPT_DEFAULT;
            gMenuTextAlpha = 0;
            level_set_transition(-1, NULL);
            play_sound(SOUND_MENU_PAUSE_OPEN, gGlobalSoundSource);

            if (gCurrCourseNum >= COURSE_MIN && gCurrCourseNum <= COURSE_MAX) {
                change_dialog_camera_angle();
                gMenuState = MENU_STATE_PAUSE_SCREEN_COURSE;
            } else {
                highlight_last_course_complete_stars();
                gMenuState = MENU_STATE_PAUSE_SCREEN_CASTLE;
            }
            break;

        case MENU_STATE_PAUSE_SCREEN_COURSE:
            shade_screen();
            render_pause_my_score_coins();
            render_pause_red_coins();

            if (should_render_pause_options(gPlayerState)) {
                render_pause_course_options(99, 93, &gMenuLineNum, 15);
            }

            if (gPlayer1Controller->buttonPressed & Z_BUTTON_DEF(A_BUTTON | START_BUTTON)) {
                level_set_transition(0, NULL);
                play_sound(SOUND_MENU_PAUSE_CLOSE, gGlobalSoundSource);
                gMenuState = MENU_STATE_DEFAULT;
                gMenuMode = MENU_MODE_NONE;

                if (gMenuLineNum == MENU_OPT_EXIT_COURSE) {
                    index = gMenuLineNum;
                } else { // MENU_OPT_CONTINUE or MENU_OPT_CAMERA_ANGLE_R
                    index = MENU_OPT_DEFAULT;
                }

                return index;
            }
            break;

        case MENU_STATE_PAUSE_SCREEN_CASTLE:
            shade_screen();
            print_hud_pause_colorful_str();
            render_pause_castle_menu_box(160, 143);
            render_pause_castle_main_strings(104, 60);

            if (gPlayer1Controller->buttonPressed & Z_BUTTON_DEF(A_BUTTON | START_BUTTON)) {
                level_set_transition(0, NULL);
                play_sound(SOUND_MENU_PAUSE_CLOSE, gGlobalSoundSource);
                gMenuMode = MENU_MODE_NONE;
                gMenuState = MENU_STATE_DEFAULT;

                return MENU_OPT_DEFAULT;
            }
            break;
    }
#ifdef EXT_OPTIONS_MENU
    } else {
        shade_screen();
        optmenu_draw();
    }
    optmenu_check_buttons();
    optmenu_draw_prompt();
#endif
    if (gMenuTextAlpha < 250) {
        gMenuTextAlpha += 25;
    }

    return MENU_OPT_NONE;
}

#if defined(VERSION_US)
    #define TXT_HISCORE_X 109
    #define TXT_HISCORE_Y 36
    #define TXT_CONGRATS_X 70
    #define TXT_CONGRATS_Y 67
#elif defined(VERSION_EU)
    #define TXT_HISCORE_X get_str_x_pos_from_center_scale(160, LANGUAGE_ARRAY(textHiScore), 12.0f)
    #define TXT_HISCORE_Y 36
    #define TXT_CONGRATS_X get_str_x_pos_from_center_scale(160, LANGUAGE_ARRAY(textCongratulations), 12.0f)
    #define TXT_CONGRATS_Y 67
#elif defined(VERSION_SH)
    #define TXT_HISCORE_X 118
    #define TXT_HISCORE_Y 48
    #define TXT_CONGRATS_X 70
    #define TXT_CONGRATS_Y 67
#elif defined(VERSION_CN)
    #define TXT_HISCORE_X 109
    #define TXT_HISCORE_Y 26
    #define TXT_CONGRATS_X 100
    #define TXT_CONGRATS_Y 62
#endif

#define HUD_PRINT_HISCORE         0
#define HUD_PRINT_CONGRATULATIONS 1

void print_hud_course_complete_string(s8 str) {
#ifdef VERSION_EU
    u8 textHiScore[][15] = {
        { TEXT_HUD_HI_SCORE },
        { TEXT_HUD_HI_SCORE_FR },
        { TEXT_HUD_HI_SCORE_DE }
    };
    u8 textCongratulations[][16] = {
        { TEXT_HUD_CONGRATULATIONS },
        { TEXT_HUD_CONGRATULATIONS_FR },
        { TEXT_HUD_CONGRATULATIONS_DE }
    };
#else
    u8 textHiScore[] = { TEXT_HUD_HI_SCORE };
    u8 textCongratulations[] = { TEXT_HUD_CONGRATULATIONS };
#endif

    u8 color = sins(gMenuTextColorTransTimer) * 50.0f + 200.0f;

    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_begin);
    gDPSetEnvColor(gDisplayListHead++, color, color, color, 255);

    if (str == HUD_PRINT_HISCORE) {
        print_hud_lut_string(HUD_LUT_GLOBAL, TXT_HISCORE_X, TXT_HISCORE_Y, LANGUAGE_ARRAY(textHiScore));
    } else { // HUD_PRINT_CONGRATULATIONS
        print_hud_lut_string(HUD_LUT_GLOBAL, TXT_CONGRATS_X, TXT_CONGRATS_Y, LANGUAGE_ARRAY(textCongratulations));
    }

    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_end);
}

void print_hud_course_complete_coins(s16 x, s16 y) {
    u8 courseCompleteCoinsStr[4];
    u8 hudTextSymCoin[] = { GLYPH_COIN, GLYPH_SPACE };
    u8 hudTextSymX[] = { GLYPH_MULTIPLY, GLYPH_SPACE };

    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);

    print_hud_lut_string(HUD_LUT_GLOBAL, x, y, hudTextSymCoin);
    print_hud_lut_string(HUD_LUT_GLOBAL, x + 16, y, hudTextSymX);

    int_to_str(gCourseCompleteCoins, courseCompleteCoinsStr);
    print_hud_lut_string(HUD_LUT_GLOBAL, x + 32, y, courseCompleteCoinsStr);

    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_end);

    if (gCourseCompleteCoins >= gHudDisplay.coins) {
        gCourseCompleteCoinsEqual = TRUE;
        gCourseCompleteCoins = gHudDisplay.coins;

        if (gGotFileCoinHiScore) {
            print_hud_course_complete_string(HUD_PRINT_HISCORE);
        }
    } else {
        if ((gCourseCompleteScreenTimer & 1) || gHudDisplay.coins > 70) {
            gCourseCompleteCoins++;
            play_sound(SOUND_MENU_YOSHI_GAIN_LIVES, gGlobalSoundSource);

#if QOL_FIX_COMPLETE_COURSE_50_COINS
            if (gCourseCompleteCoins % 50 == 0)
#else
            if (gCourseCompleteCoins == 50 || gCourseCompleteCoins == 100 || gCourseCompleteCoins == 150)
#endif
            {
                play_sound(SOUND_GENERAL_COLLECT_1UP, gGlobalSoundSource);
                gPlayerState->numLives++;
            }
        }

        if (gHudDisplay.coins == gCourseCompleteCoins && gGotFileCoinHiScore) {
            play_sound(SOUND_MENU_HIGH_SCORE, gGlobalSoundSource);
        }
    }
}

void play_star_fanfare_and_flash_hud(s32 arg, u8 starFlag) {
    if (gHudDisplay.coins == gCourseCompleteCoins && !(gCurrCourseStarFlags & starFlag) && gHudFlash == 0) {
        play_star_fanfare();
        gHudFlash = arg;
    }
}

#ifdef VERSION_EU
    #define TXT_NAME_X1 centerX
    #define TXT_NAME_X2 centerX - 1
#else
    #define TXT_NAME_X1 71
    #define TXT_NAME_X2 TXT_NAME_X1 - 2
#endif

#if defined(VERSION_SH)
    #define CRS_NUM_X2 95
    #define CRS_NUM_X3 CRS_NUM_X2 - 2
    #define TXT_CLEAR_X1 205
    #define TXT_CLEAR_X2 TXT_CLEAR_X1 - 2
#else
    #define CRS_NUM_X2 104
    #define CRS_NUM_X3 CRS_NUM_X2 - 2
    #define TXT_CLEAR_X1 get_string_width(name) + 81
    #define TXT_CLEAR_X2 TXT_CLEAR_X1 - 2
#endif

void render_course_complete_lvl_info_and_hud_str(void) {
#if defined(VERSION_EU)
    UNUSED u8 textCatch[] = { TEXT_CATCH }; // unused in EU
    u8 textSymStar[] = { GLYPH_STAR, GLYPH_SPACE };
#else
    u8 textCourse[] = { TEXT_COURSE };
    UNUSED u8 textCatch[] = { TEXT_CATCH }; // unused in US and iQue
    u8 textClear[] = { TEXT_CLEAR };
    u8 textSymStar[] = { GLYPH_STAR, GLYPH_SPACE };
#endif

    void **actNameTbl;
    void **courseNameTbl;
    u8 *name;

    u8 strCourseNum[4];

#ifdef VERSION_EU
    s16 centerX;
    switch (gInGameLanguage) {
        case LANGUAGE_ENGLISH:
            actNameTbl = segmented_to_virtual(act_name_table_eu_en);
            courseNameTbl = segmented_to_virtual(course_name_table_eu_en);
            break;
        case LANGUAGE_FRENCH:
            actNameTbl = segmented_to_virtual(act_name_table_eu_fr);
            courseNameTbl = segmented_to_virtual(course_name_table_eu_fr);
            break;
        case LANGUAGE_GERMAN:
            actNameTbl = segmented_to_virtual(act_name_table_eu_de);
            courseNameTbl = segmented_to_virtual(course_name_table_eu_de);
            break;
    }
#else
    actNameTbl = segmented_to_virtual(seg2_act_name_table);
    courseNameTbl = segmented_to_virtual(seg2_course_name_table);
#endif

    if (gLastCompletedCourseNum <= COURSE_STAGES_MAX) { // Main courses
        print_hud_course_complete_coins(118, 103);
        play_star_fanfare_and_flash_hud(1, 1 << (gLastCompletedStarNum - 1));

        if (gLastCompletedStarNum == (STAR_INDEX_100_COINS + 1)) {
            name = segmented_to_virtual(actNameTbl[COURSE_STAGES_MAX * NUM_ACTS_PER_COURSE]);
        } else {
            name = segmented_to_virtual(actNameTbl[COURSE_NUM_TO_INDEX(gLastCompletedCourseNum) * NUM_ACTS_PER_COURSE + gLastCompletedStarNum - 1]);
        }

        // Print course number
        gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);

        INT_TO_STR_DIFF(gLastCompletedCourseNum, strCourseNum);

        gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, gMenuTextAlpha);
        print_generic_string(65, 165, LANGUAGE_ARRAY(textCourse));
        print_generic_string(CRS_NUM_X2, 165, strCourseNum);

        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gMenuTextAlpha);
        print_generic_string(63, 167, LANGUAGE_ARRAY(textCourse));
        print_generic_string(CRS_NUM_X3, 167, strCourseNum);

        gSPDisplayList(gDisplayListHead++, dl_ia_text_end);
    } else if (gLastCompletedCourseNum == COURSE_BITDW || gLastCompletedCourseNum == COURSE_BITFS) { // Bowser courses
        name = segmented_to_virtual(courseNameTbl[COURSE_NUM_TO_INDEX(gLastCompletedCourseNum)]);

        // Print course name and clear text
        gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);

        gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, gMenuTextAlpha);
#ifdef VERSION_EU
        centerX = get_str_x_pos_from_center(153, name, 12.0f);
#endif
        print_generic_string(TXT_NAME_X1, 130, name);
#ifndef VERSION_EU
        print_generic_string(TXT_CLEAR_X1, 130, textClear);
#endif

        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gMenuTextAlpha);
        print_generic_string(TXT_NAME_X2, 132, name);
#ifndef VERSION_EU
        print_generic_string(TXT_CLEAR_X2, 132, textClear);
#endif

        gSPDisplayList(gDisplayListHead++, dl_ia_text_end);

        print_hud_course_complete_string(HUD_PRINT_CONGRATULATIONS);
        print_hud_course_complete_coins(118, 111);
        play_star_fanfare_and_flash_hud(2, 0); //! 2 isn't defined, originally for key hud?

        return;
    } else { // Castle secret stars
        name = segmented_to_virtual(actNameTbl[COURSE_STAGES_MAX * NUM_ACTS_PER_COURSE]);

        print_hud_course_complete_coins(118, 103);
        play_star_fanfare_and_flash_hud(1, 1 << (gLastCompletedStarNum - 1));
    }

    // Print star glyph
    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_begin);

    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gMenuTextAlpha);
    print_hud_lut_string(HUD_LUT_GLOBAL, 55, 77, textSymStar);

    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_end);

    // Print act name and catch text
    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);

    gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, gMenuTextAlpha);
    print_generic_string(76, 145, name);
#if defined(VERSION_SH)
    print_generic_string(220, 145, textCatch);
#endif

    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gMenuTextAlpha);
    print_generic_string(74, 147, name);
#if defined(VERSION_SH)
    print_generic_string(218, 147, textCatch);
#endif

    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);
}

#if defined(VERSION_SH)
    #define X_VAL9 x
    #define TXT_SAVEOPTIONS_X x + 10
    #define TXT_SAVECONT_Y +2-0
    #define TXT_SAVEQUIT_Y +2-20
    #ifdef TARGET_N64
        #define TXT_CONTNOSAVE_Y +2-40
    #else
        #define TXT_SAVE_EXIT_GAME_Y +2-40
        #define TXT_CONTNOSAVE_Y +2-60
    #endif
#else
#ifdef VERSION_EU
    #define X_VAL9 xOffset - 12
    #define TXT_SAVEOPTIONS_X xOffset
#else
    #define X_VAL9 x
    #define TXT_SAVEOPTIONS_X x + 12
#endif
    #define TXT_SAVECONT_Y 0
    #define TXT_SAVEQUIT_Y 20
    #ifdef TARGET_N64
        #define TXT_CONTNOSAVE_Y 40
    #else
        #define TXT_SAVE_EXIT_GAME_Y 40
        #define TXT_CONTNOSAVE_Y 60
    #endif
#endif

#ifndef TARGET_N64
#define SAVE_CONFIRM_INDEX 4 // Increased to '4' to handle Exit Game 
#else
#define SAVE_CONFIRM_INDEX 3
#endif

#ifdef VERSION_EU
void render_save_confirmation(s16 y, s8 *index, s16 yOffset)
#else
void render_save_confirmation(s16 x, s16 y, s8 *index, s16 yOffset)
#endif
{
#ifdef VERSION_EU
    u8 textSaveAndContinue[][24] = {
        { TEXT_SAVE_AND_CONTINUE },
        { TEXT_SAVE_AND_CONTINUE_FR },
        { TEXT_SAVE_AND_CONTINUE_DE }
    };
    u8 textSaveAndQuit[][22] = {
        { TEXT_SAVE_AND_QUIT },
        { TEXT_SAVE_AND_QUIT_FR },
        { TEXT_SAVE_AND_QUIT_DE }
    };

#ifndef TARGET_N64
    u8 textSaveExitGame[][28] = { // New text to exit game
        { TEXT_SAVE_EXIT_GAME },
        { TEXT_SAVE_EXIT_GAME_FR },
        { TEXT_SAVE_EXIT_GAME_DE }
    };
#endif

    u8 textContinueWithoutSave[][27] = {
        { TEXT_CONTINUE_WITHOUT_SAVING },
        { TEXT_CONTINUE_WITHOUT_SAVING_FR },
        { TEXT_CONTINUE_WITHOUT_SAVING_DE }
    };
    s16 xOffset = get_str_x_pos_from_center(160, LANGUAGE_ARRAY(textContinueWithoutSave), 12.0f);
#else
    u8 textSaveAndContinue[] = { TEXT_SAVE_AND_CONTINUE };
    u8 textSaveAndQuit[] = { TEXT_SAVE_AND_QUIT };
#ifndef TARGET_N64
    u8 textSaveExitGame[] = { TEXT_SAVE_EXIT_GAME }; // New text to exit game
#endif
    u8 textContinueWithoutSave[] = { TEXT_CONTINUE_WITHOUT_SAVING };
#endif

    handle_menu_scrolling(MENU_SCROLL_VERTICAL, index, 1, SAVE_CONFIRM_INDEX);

    gSPDisplayList(gDisplayListHead++, dl_ia_text_begin);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gMenuTextAlpha);

    print_generic_string(TXT_SAVEOPTIONS_X, y + TXT_SAVECONT_Y, LANGUAGE_ARRAY(textSaveAndContinue));
    print_generic_string(TXT_SAVEOPTIONS_X, y - TXT_SAVEQUIT_Y, LANGUAGE_ARRAY(textSaveAndQuit));
#ifndef TARGET_N64
    print_generic_string(TXT_SAVEOPTIONS_X, y - TXT_SAVE_EXIT_GAME_Y, LANGUAGE_ARRAY(textSaveExitGame));
#endif
    print_generic_string(TXT_SAVEOPTIONS_X, y - TXT_CONTNOSAVE_Y, LANGUAGE_ARRAY(textContinueWithoutSave));

    gSPDisplayList(gDisplayListHead++, dl_ia_text_end);

    create_dl_translation_matrix(MENU_MTX_PUSH, X_VAL9, y - ((*index - 1) * yOffset), 0);

    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, gMenuTextAlpha);
    gSPDisplayList(gDisplayListHead++, dl_draw_triangle);

    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
}
#undef SAVE_CONFIRM_INDEX

s16 render_course_complete_screen(void) {
    s16 index;
#ifdef VERSION_EU
    gInGameLanguage = eu_get_language();
#endif

    switch (gMenuState) {
        case MENU_STATE_COURSE_COMPLETE_SCREEN_OPENING:
            render_course_complete_lvl_info_and_hud_str();
            if (gCourseCompleteScreenTimer > 100 && gCourseCompleteCoinsEqual == TRUE) {
                gMenuState = MENU_STATE_COURSE_COMPLETE_SCREEN_OPEN;
                level_set_transition(-1, NULL);
                gMenuTextAlpha = 0;
                gMenuLineNum = MENU_OPT_DEFAULT;
            }
            break;

        case MENU_STATE_COURSE_COMPLETE_SCREEN_OPEN:
            shade_screen();
            render_course_complete_lvl_info_and_hud_str();
#ifdef VERSION_EU
            render_save_confirmation(86, &gMenuLineNum, 20);
#else
            render_save_confirmation(100, 86, &gMenuLineNum, 20);
#endif

            if (gCourseCompleteScreenTimer > 110 && (gPlayer1Controller->buttonPressed & Z_BUTTON_DEF(A_BUTTON | START_BUTTON))) {
                level_set_transition(0, NULL);
                play_sound(SOUND_MENU_STAR_SOUND, gGlobalSoundSource);
                gMenuState = MENU_STATE_DEFAULT;
                gMenuMode = MENU_MODE_NONE;
                index = gMenuLineNum;
                gCourseCompleteScreenTimer = 0;
                gCourseCompleteCoins = 0;
                gCourseCompleteCoinsEqual = FALSE;
                gHudFlash = 0;

                return index;
            }
            break;
    }

    if (gMenuTextAlpha < 250) {
        gMenuTextAlpha += 25;
    }

    gCourseCompleteScreenTimer++;

    return MENU_OPT_NONE;
}

s16 render_menus_and_dialogs(void) {
    s16 index = MENU_OPT_NONE;

    create_dl_ortho_matrix();

    if (gMenuMode != MENU_MODE_NONE) {
        switch (gMenuMode) {
            case MENU_MODE_UNUSED_0:
                index = render_pause_screen();
                break;
            case MENU_MODE_RENDER_PAUSE_SCREEN:
                index = render_pause_screen();
                break;
            case MENU_MODE_RENDER_COURSE_COMPLETE_SCREEN:
                index = render_course_complete_screen();
                break;
            case MENU_MODE_UNUSED_3:
                index = render_course_complete_screen();
                break;
        }

        gMenuTextColorTransTimer = (s16) gMenuTextColorTransTimer + 0x1000;
    } else if (gDialogID != DIALOG_NONE) {
        // The Peach "Dear Mario" message needs to be repositioned separately
        if (gDialogID == DIALOG_020) {
            print_peach_letter_message();
            return index;
        }

        render_dialog_entries();
        gMenuTextColorTransTimer = (s16) gMenuTextColorTransTimer + 0x1000;
    }

    return index;
}
