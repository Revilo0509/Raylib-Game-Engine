#include "objects/textures.hpp"

namespace RRE::Objects::Textures {

void Textured::drawToScreen() {
    DrawTexturePro(
        texture.texture,
        {0, 0, (float)texture.texture.width, (float)texture.texture.height},
        {0, 0, (float)600.0f, (float)600.0f}, {0, 0}, 0.0f, //TODO: Make it draw on the entire screen
        WHITE);
}

void Textured::wrapper() {
    BeginTextureMode(texture);
    drawToTexture();
    EndTextureMode();
}

static TexturedHandler texturedHandler;
TexturedHandler &getTexturedHandler() { return texturedHandler; }

} // namespace RRE::Objects::Textures