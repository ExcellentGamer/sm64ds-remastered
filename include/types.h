#ifndef _SM64_TYPES_H_
#define _SM64_TYPES_H_

// This file contains various data types used in Super Mario 64 that don't yet
// have an appropriate header.

#include <ultra64.h>
#include "macros.h"
#include "config.h"

// Certain functions are marked as having return values, but do not
// actually return a value. This causes undefined behavior, which we'd rather
// avoid on modern GCC. This only impacts -O2 and can matter for both the function
// itself and functions that call it.
#ifdef AVOID_UB
    #define BAD_RETURN(cmd) void
#else
    #define BAD_RETURN(cmd) cmd
#endif


struct Controller {
  /*0x00*/ s16 rawStickX;       //
  /*0x02*/ s16 rawStickY;       //
  /*0x04*/ float stickX;        // [-64, 64] positive is right
  /*0x08*/ float stickY;        // [-64, 64] positive is up
  /*0x0C*/ float stickMag;      // distance from center [0, 64]
  /*0x10*/ u16 buttonDown;
  /*0x12*/ u16 buttonPressed;
  /*0x14*/ OSContStatus *statusData;
  /*0x18*/ OSContPad *controllerData;
#ifdef RUMBLE_FEEDBACK
  /*0x1C*/ s32 port;
#endif
  /*ext */ s16 extStickX;       // additional (right) stick values
  /*ext */ s16 extStickY;
};

// -- Booleans --
typedef u8  Bool8;
typedef u16 Bool16;
typedef u32 Bool32;

// -- Vectors --
typedef u8 Vec2uc[2];
typedef s8  Vec2c[2];
typedef s16 Vec2s[2];
typedef s32 Vec2i[2];
typedef f32 Vec2f[2];
typedef f64 Vec2d[2];

typedef u8 Vec3uc[3];
typedef s8  Vec3c[3];
typedef s16 Vec3s[3];
typedef s32 Vec3i[3];
typedef f32 Vec3f[3]; // X, Y, Z, where Y is up
typedef f64 Vec3d[3];

typedef u8 Vec4uc[4];
typedef s8  Vec4c[4];
typedef s16 Vec4s[4];
typedef s32 Vec4i[4];
typedef f32 Vec4f[4];
typedef f64 Vec4d[4];

typedef f32 Mat2[2][2];
typedef f32 Mat3[3][3];
typedef f32 Mat4[4][4];

// -- Scripts --
typedef uintptr_t GeoLayout;
typedef uintptr_t LevelScript;
typedef uintptr_t BehaviorScript;

// -- Angle --
typedef s16 Angle;
typedef u16 UAngle;
typedef s32 Angle32;
typedef Angle Vec3a[3];

typedef s16 Movtex;
typedef s16 MacroObject;
typedef s16 Collision; // Collision data is limited to -32768 to 32767. Change this if you want to increase it.
typedef s16 Trajectory;
typedef s16 PaintingData;
typedef u8 Texture;
typedef s8 RoomData; // Rooms are limited to -128 to 127. Change the type if you wish to have more rooms.
typedef Collision TerrainData;
typedef Collision Vec3t[3];

// -- Models --

typedef u8  ModelID8;
typedef u16 ModelID16;
typedef u32 ModelID32;

#define M_GFXTASK 1
#define M_AUDTASK 2
#define M_VIDTASK 3
#define M_HVQTASK 6
#define M_HVQMTASK 7

enum SpTaskState {
    SPTASK_STATE_NOT_STARTED,
    SPTASK_STATE_RUNNING,
    SPTASK_STATE_INTERRUPTED,
    SPTASK_STATE_FINISHED,
    SPTASK_STATE_FINISHED_DP
};

struct SPTask {
    /*0x00*/ OSTask task;
    /*0x40*/ OSMesgQueue *msgqueue;
    /*0x44*/ OSMesg msg;
    /*0x48*/ enum SpTaskState state;
}; // size = 0x4C, align = 0x8

struct VblankHandler {
    OSMesgQueue *queue;
    OSMesg msg;
};

#define ANIM_FLAG_NOLOOP     (1 << 0) // 0x01
#define ANIM_FLAG_BACKWARD   (1 << 1) // 0x02
#define ANIM_FLAG_2          (1 << 2) // 0x04
#define ANIM_FLAG_HOR_TRANS  (1 << 3) // 0x08
#define ANIM_FLAG_VERT_TRANS (1 << 4) // 0x10
#define ANIM_FLAG_5          (1 << 5) // 0x20
#define ANIM_FLAG_6          (1 << 6) // 0x40
#define ANIM_FLAG_7          (1 << 7) // 0x80
#define ANIM_FLAG_BONE_TRANS (1 << 8) // 0x100

struct Animation {
    /*0x00*/ s16 flags;
    /*0x02*/ s16 animYTransDivisor;
    /*0x04*/ s16 startFrame;
    /*0x06*/ s16 loopStart;
    /*0x08*/ s16 loopEnd;
    /*0x0A*/ s16 unusedBoneCount;
    /*0x0C*/ const s16 *values;
    /*0x10*/ const u16 *index;
    /*0x14*/ u32 length; // only used with the players animations to determine how much to load. 0 otherwise.
};

#define ANIMINDEX_NUMPARTS(animindex) (sizeof(animindex) / sizeof(u16) / 6 - 1)

struct GraphNode {
    /*0x00*/ s16 type; // structure type
    /*0x02*/ s16 flags; // hi = drawing layer, lo = rendering modes
    /*0x04*/ struct GraphNode *prev;
    /*0x08*/ struct GraphNode *next;
    /*0x0C*/ struct GraphNode *parent;
    /*0x10*/ struct GraphNode *children;
};

struct AnimInfo {
    /*0x00 0x38*/ s16 animID;
    /*0x02 0x3A*/ s16 animYTrans;
    /*0x04 0x3C*/ struct Animation *curAnim;
    /*0x08 0x40*/ s16 animFrame;
    /*0x0A 0x42*/ u16 animTimer;
    /*0x0C 0x44*/ s32 animFrameAccelAssist;
    /*0x10 0x48*/ s32 animAccel;
#ifdef HIGH_FPS_PC
    s16 prevAnimFrame;
    s16 prevAnimID;
    u32 prevAnimFrameTimestamp;
    struct Animation *prevAnimPtr;
#endif
};

struct GraphNodeObject {
    /*0x00*/ struct GraphNode node;
    /*0x14*/ struct GraphNode *sharedChild;
    /*0x18*/ s8 areaIndex;
    /*0x19*/ s8 activeAreaIndex;
    /*0x1A*/ Vec3s angle;
    /*0x20*/ Vec3f pos;
    /*0x2C*/ Vec3f scale;
#ifdef HIGH_FPS_PC
    Vec3s prevAngle;
    Vec3f prevPos;
    u32 prevTimestamp;
    Vec3f prevShadowPos;
    u32 prevShadowPosTimestamp;
    Vec3f prevScale;
    u32 prevScaleTimestamp;
#endif
    /*0x38*/ struct AnimInfo animInfo;
    /*0x4C*/ struct SpawnInfo *unk4C;
    /*0x50*/ Mat4 *throwMatrix; // matrix ptr
#ifdef HIGH_FPS_PC
    Mat4 prevThrowMatrix;
    u32 prevThrowMatrixTimestamp;
    Mat4 *throwMatrixInterpolated;
    u32 skipInterpolationTimestamp;
#endif
    /*0x54*/ Vec3f cameraToObject;
};

struct ObjectNode {
    struct GraphNodeObject gfx;
    struct ObjectNode *next;
    struct ObjectNode *prev;
};

// NOTE: Since ObjectNode is the first member of Object, it is difficult to determine
// whether some of these pointers point to ObjectNode or Object.

#define MAX_OBJECT_FIELDS 0x50

struct Object {
    /*0x000*/ struct ObjectNode header;
    /*0x068*/ struct Object *parentObj;
    /*0x06C*/ struct Object *prevObj;
    /*0x070*/ u32 collidedObjInteractTypes;
    /*0x074*/ s16 activeFlags;
    /*0x076*/ s16 numCollidedObjs;
    /*0x078*/ struct Object *collidedObjs[4];
    /*0x088*/
    union {
        // Object fields. See object_fields.h.
        u32 asU32[MAX_OBJECT_FIELDS];
        s32 asS32[MAX_OBJECT_FIELDS];
        s16 asS16[MAX_OBJECT_FIELDS][2];
        f32 asF32[MAX_OBJECT_FIELDS];
#if !IS_64_BIT
        s16 *asS16P[MAX_OBJECT_FIELDS];
        s32 *asS32P[MAX_OBJECT_FIELDS];
        struct Animation **asAnims[MAX_OBJECT_FIELDS];
        struct Waypoint *asWaypoint[MAX_OBJECT_FIELDS];
        struct ChainSegment *asChainSegment[MAX_OBJECT_FIELDS];
        struct Object *asObject[MAX_OBJECT_FIELDS];
        struct Surface *asSurface[MAX_OBJECT_FIELDS];
        void *asVoidPtr[MAX_OBJECT_FIELDS];
        const void *asConstVoidPtr[MAX_OBJECT_FIELDS];
#endif
    } rawData;
#if IS_64_BIT
    union {
        s16 *asS16P[MAX_OBJECT_FIELDS];
        s32 *asS32P[MAX_OBJECT_FIELDS];
        struct Animation **asAnims[MAX_OBJECT_FIELDS];
        struct Waypoint *asWaypoint[MAX_OBJECT_FIELDS];
        struct ChainSegment *asChainSegment[MAX_OBJECT_FIELDS];
        struct Object *asObject[MAX_OBJECT_FIELDS];
        struct Surface *asSurface[MAX_OBJECT_FIELDS];
        void *asVoidPtr[MAX_OBJECT_FIELDS];
        const void *asConstVoidPtr[MAX_OBJECT_FIELDS];
    } ptrData;
#endif
    /*0x1C8*/ u32 unused1;
    /*0x1CC*/ const BehaviorScript *curBhvCommand;
    /*0x1D0*/ u32 bhvStackIndex;
    /*0x1D4*/ uintptr_t bhvStack[8];
    /*0x1F4*/ s16 bhvDelayTimer;
    /*0x1F6*/ u8 respawnInfo;
    /*0x1F8*/ f32 hitboxRadius;
    /*0x1FC*/ f32 hitboxHeight;
    /*0x200*/ f32 hurtboxRadius;
    /*0x204*/ f32 hurtboxHeight;
    /*0x208*/ f32 hitboxDownOffset;
    /*0x20C*/ const BehaviorScript *behavior;
    /*0x210*/ u32 unused2;
    /*0x214*/ struct Object *platform;
    /*0x218*/ void *collisionData;
    /*0x21C*/ Mat4 transform;
    /*0x25C*/ u8 *respawnInfoPointer;
};

struct ObjectHitbox {
    /*0x00*/ u32 interactType;
    /*0x04*/ u8 downOffset;
    /*0x05*/ s8 damageOrCoinValue;
    /*0x06*/ s8 health;
    /*0x07*/ s8 numLootCoins;
    /*0x08*/ s16 radius;
    /*0x0A*/ s16 height;
    /*0x0C*/ s16 hurtboxRadius;
    /*0x0E*/ s16 hurtboxHeight;
};

struct Waypoint {
    s16 flags;
    Vec3s pos;
};

struct Surface {
    /*0x00*/ TerrainData type;
    /*0x02*/ TerrainData force;
    /*0x04*/ s8 flags;
    /*0x05*/ RoomData room;
    /*0x06*/ TerrainData lowerY;
    /*0x08*/ TerrainData upperY;
    /*0x0A*/ Vec3t vertex1;
    /*0x10*/ Vec3t vertex2;
    /*0x16*/ Vec3t vertex3;
    /*0x1C*/ struct {
        f32 x;
        f32 y;
        f32 z;
    } normal;
    /*0x28*/ f32 originOffset;
    /*0x2C*/ struct Object *object;
};

struct PlayerBodyState {
    u32 action;
    s8 capState; /// see PlayerCapGSCId
    s8 eatState; // used for Yoshi's head
    s8 eyeState;
    s8 handState;
    s8 wingFlutter; /// whether the player's wing cap wings are fluttering
    s16 modelState;
    s8 grabPos;
    u8 punchState; /// 2 bits for type of punch, 6 bits for punch animation timer
    Vec3s torsoAngle;
    Vec3s headAngle;
    Vec3f heldObjLastPosition; /// also known as HOLP
    u8 filler[4];
};

struct PlayerState {
    u16 unk00;
    u16 input;
    u32 flags;
    u32 particleFlags;
    u32 action;
    u32 prevAction;
    u32 terrainSoundAddend;
    u16 actionState;
    u16 actionTimer;
    u32 actionArg;
    f32 intendedMag;
    s16 intendedYaw;
    s16 invincTimer;
    u8 framesSinceA;
    u8 framesSinceB;
    u8 wallKickTimer;
    u8 doubleJumpTimer;
    Vec3s faceAngle;
    Vec3s angleVel;
    s16 slideYaw;
    s16 twirlYaw;
    Vec3f pos;
    Vec3f vel;
    f32 forwardVel;
    f32 slideVelX;
    f32 slideVelZ;
    struct Surface *wall;
    struct Surface *ceil;
    struct Surface *floor;
    f32 ceilHeight;
    f32 floorHeight;
    s16 floorAngle;
    s16 waterLevel;
    struct Object *interactObj;
    struct Object *heldObj;
    struct Object *usedObj;
    struct Object *riddenObj;
    struct Object *playerObj;
    struct SpawnInfo *spawnInfo;
    struct Area *area;
    struct PlayerCameraState *statusForCamera;
    struct PlayerBodyState *playerBodyState;
    struct Controller *controller;
    struct DmaHandlerList *animList;
    struct Character *character; // Snippet from SM64COOPDX
    u32 collidedObjInteractTypes;
    s16 numCoins;
    s16 numStars;
    s8 numLives;
    s16 health;
    s16 unkB0;
    u8 hurtCounter;
    u8 healCounter;
    u8 squishTimer;
    u8 fadeWarpOpacity;
    u16 capTimer;
    s16 prevNumStarsForDialog;
    f32 peakHeight;
    f32 quicksandDepth;
    f32 gettingBlownGravity;
};

#endif // _SM64_TYPES_H_
