#include "texture_dimensions.h"

extern const struct TextureDimensionsEntry __start_texture_dims[] __attribute__((weak));
extern const struct TextureDimensionsEntry __stop_texture_dims[] __attribute__((weak));

bool gfx_texture_dimensions_lookup(const void *addr, uint16_t *width, uint16_t *height) {
    if ((uintptr_t)__start_texture_dims == 0 || (uintptr_t)__stop_texture_dims == 0) {
        return false;
    }

    const struct TextureDimensionsEntry *it = __start_texture_dims;
    while (it < __stop_texture_dims) {
        if (it->addr == addr) {
            if (width) *width = it->width;
            if (height) *height = it->height;
            return true;
        }
        ++it;
    }
    return false;
}
