#ifndef QOL_DEFINES_H
#define QOL_DEFINES_H

// Quality of life defines
// Mostly a compilation of code provided by various people

// Credits are provided as how I (AloXado320) remember
// Note: If credits says "Easy fix", it means that by
// looking at the code with "//!" anyone can fix it (not always the case)

// You can also stub the defines if you don't want them to be applied

// Framebuffer Detection
#ifdef TARGET_N64
#define HAS_FRAMEBUFFER 1
#elif defined(RAPI_GL) || defined(RAPI_D3D11)
#define HAS_FRAMEBUFFER 1
#else
#define HAS_FRAMEBUFFER 0
#endif

// --| Quality of life redone files
/// Adds Zelda level select used on OOT, MM and Animal Forest
/// Credits: (AloXado320)
#define ZELDA_STYLE_LEVEL_SELECT (0 || QOL_REDONE)
/// Adds improved platform displacement with intertia
#define PLATFORM_DISPLACEMENT_2 (0 || QOL_REDONE)
/// Uses optimized shadows which are faster than vanilla
#define OPTIMIZED_SHADOWS (0 || QOL_REDONE)

// --| Quality of life features
/// Adds an extra Z button trig for some menu files (Originally defined in EU)
/// Credits: (Original Devs)
#define QOL_FEATURE_Z_BUTTON_EXTRA_OPTION (0 || VERSION_EU || QOL_FEATURES)
/// Adds Mario's Face Easter Egg (Originally defined in SH)
/// Credits: (Original Devs)
#define QOL_FEATURE_MARIO_HEAD_EASTER_EGG (0 || VERSION_SH || (QOL_FEATURES && GODDARD_MFACE && HAS_FRAMEBUFFER))
/// Makes ending screen go back to title screen when pressing start
/// Credits: (Mips96)
#define QOL_FEATURE_ENDING_SCREEN_START (0 || QOL_FEATURES)

// --| Quality of life fixes
// --| Code Fixes

/// Fixes complete coins not giving lives every 50 coins after 150 coins
/// Credits: (coltongit)
#define QOL_FIX_COMPLETE_COURSE_50_COINS (0 || QOL_FIXES)
/// Fixes instant warp offset not working when warping across different areas
/// Credits: (Reonu)
#define QOL_FIX_INSTANT_WARP_OFFSET (0 || QOL_FIXES)
/// Fixes pss slide value not being reset on exit
/// Credits: (AloXado320)
#define QOL_FIX_RESET_PSS_SLIDE_STARTED (0 || QOL_FIXES)

// --| Unused Code Fixes (for convenience)
/// Fixes (or rather removes) 0 yaw code in Beta Chest object
/// Credits: (Easy Fix)
#define QOL_FIX_UNUSED_BETA_CHEST_YAW (0 || QOL_FIXES)
/// Fixes play_mode_unused inclusion so it's "used" as a default "invalid" play mode switch
/// Credits: (Arceveti)
#define QOL_FIX_UNUSED_PLAY_MODE (0 || QOL_FIXES)

// --| Assets Fixes (Mostly on vanilla levels)
/// Fixes impossible coins (also fixes impossible Goomba since it's related)
/// Credits: (AloXado320)
#define QOL_FIX_ASSET_IMPOSSIBLE_COINS (0 || QOL_FIXES)
/// Fixes 1up locations in CCM slide
/// Credits: (Arceveti)
#define QOL_FIX_ASSET_CCM_SLIDE_1UPS (0 || QOL_FIXES)

#endif // QOL_DEFINES_H
