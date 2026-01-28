#ifndef TEXTURE_DIMENSIONS_H
#define TEXTURE_DIMENSIONS_H

#include <stdint.h>
#include <stdbool.h>

struct TextureDimensionsEntry {
    const void *addr;
    uint16_t width;
    uint16_t height;
};

bool gfx_texture_dimensions_lookup(const void *addr, uint16_t *width, uint16_t *height);

#define TEXTURE_DIMS_CONCAT2(a, b) a##b
#define TEXTURE_DIMS_CONCAT(a, b) TEXTURE_DIMS_CONCAT2(a, b)

#define REGISTER_TEXTURE_DIMENSIONS(addr_, width_, height_) \
    static const struct TextureDimensionsEntry TEXTURE_DIMS_CONCAT(_texture_dimensions_entry_, __COUNTER__) \
        __attribute__((section("texture_dims"), used)) = { (addr_), (uint16_t)(width_), (uint16_t)(height_) };

#endif
