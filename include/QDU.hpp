// Quick Drawing Utilities
#pragma once

#include <raylib.h>
#include <raymath.h>

namespace RRE::QDU {

inline void SimpleDrawTexturePro(Texture *texture, Rectangle dest) {
    DrawTexturePro(*texture,
                   Rectangle{0, 0, static_cast<float>(texture->width),
                             static_cast<float>(texture->height)},
                   dest, Vector2Zeros, 0, WHITE);
};

} // namespace RRE::QDU