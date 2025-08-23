#include "objects/primitives.hpp"

namespace RRE::Objects {

static UpdatableHandler updatableHandler;
UpdatableHandler &getUpdatableHandler() { return updatableHandler; }

static DrawableHandler drawableHandler;
DrawableHandler &getDrawableHandler() { return drawableHandler; }

void Textured::drawToScreen() {
    DrawTexturePro(
        texture.texture,
        {0, 0, (float)texture.texture.width, (float)texture.texture.height},
        {0, 0, (float)600.0f, (float)600.0f}, {0, 0},
        0.0f, // TODO: Make it draw on the entire screen
        WHITE);
}

void Textured::wrapper() {
    BeginTextureMode(texture);
    drawToTexture();
    EndTextureMode();
}

static TexturedHandler texturedHandler;
TexturedHandler &getTexturedHandler() { return texturedHandler; }

// Constructor
Velocity::Velocity(float i_speedX, float i_speedY) : velocity(i_speedX, i_speedY) {
    velocity.Clamp(-1.0f, 1.0f);
}

RRE::Types::Vec2 Velocity::get() const { return velocity; }

Velocity &Velocity::operator=(const Velocity &other) {
    if (this != &other) {
        velocity = other.velocity;
        velocity.Clamp(-1.0f, 1.0f);
    }
    return *this;
}

Velocity Velocity::operator+(const Velocity &other) const {
    Velocity result(*this);
    result.velocity += other.velocity;
    result.velocity.Clamp(-1.0f, 1.0f);
    return result;
}

Velocity Velocity::operator-(const Velocity &other) const {
    Velocity result(*this);
    result.velocity -= other.velocity;
    result.velocity.Clamp(-1.0f, 1.0f);
    return result;
}

Velocity &Velocity::operator+=(const Velocity &other) {
    velocity += other.velocity;
    velocity.Clamp(-1.0f, 1.0f);
    return *this;
}

Velocity &Velocity::operator-=(const Velocity &other) {
    velocity -= other.velocity;
    velocity.Clamp(-1.0f, 1.0f);
    return *this;
}

} // namespace RRE::Objects
