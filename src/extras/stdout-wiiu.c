/*
 * Automatically redirect stdout to WHBLogWrite().
 *
 * SPDX-License-Identifier: Apache-2.0
 * SPDX-License-Identifier: LGPL-3.0-or-later
 * SPDX-License-Identifier: MIT
 *
 * Source: https://github.com/dkosmari/wiiu-stdout
 */

#ifdef TARGET_WII_U

#include <stdio.h>              // snprintf()
#include <stdlib.h>             // malloc(), free()

#include <sys/iosupport.h>      // devoptab_list, devoptab_t

#include <coreinit/mutex.h>
#include <whb/log.h>
#include <whb/log_cafe.h>
#include <whb/log_module.h>
#include <whb/log_udp.h>


OSMutex whb_log_mutex; // initialized by stderr-wiiu.c


static bool cafe_initialized   = false;
static bool module_initialized = false;
static bool udp_initialized    = false;


__attribute__ (( __constructor__ (101) ))
void
init_whb_log(void)
{
    module_initialized = WHBLogModuleInit();
    if (!module_initialized) {
        cafe_initialized = WHBLogCafeInit();
        udp_initialized = WHBLogUdpInit();
    }
}


__attribute__ (( __destructor__ (101) ))
void
fini_whb_log(void)
{
    if (module_initialized) {
        WHBLogModuleDeinit();
        module_initialized = false;
    }
    if (cafe_initialized) {
        WHBLogCafeDeinit();
        cafe_initialized = false;
    }
    if (udp_initialized) {
        WHBLogUdpDeinit();
        udp_initialized = false;
    }
}


ssize_t
devoptab_to_whb_log(struct _reent*,
                    void*,
                    const char* buf,
                    size_t len)
{
    // Note: WHBLogWrite expects a null-terminated string.
    char* msg = malloc(len + 1);
    if (!msg)
        return -1;
    snprintf(msg, len + 1, "%s", buf);
    if (whb_log_mutex.tag) {
        OSLockMutex(&whb_log_mutex);
        WHBLogWrite(msg);
        OSUnlockMutex(&whb_log_mutex);
    } else {
        WHBLogWrite(msg);
    }
    free(msg);
    return len;
}


__attribute__(( __constructor__ (102) ))
void
init_stdout(void)
{
    static devoptab_t stdout_dev;
    stdout_dev.name = "STDOUT";
    stdout_dev.structSize = sizeof stdout_dev;
    stdout_dev.write_r = devoptab_to_whb_log;
    devoptab_list[STD_OUT] = &stdout_dev;
}

#endif // TARGET_WII_U
