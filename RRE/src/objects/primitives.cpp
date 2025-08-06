#include "objects/primitives.hpp"
#include "raylib.h"

namespace RRE::Objects {

Object::Object(Texture2D *tex, Vector2 initPos) : pos(initPos), texture(tex) {}
void Object::draw() { DrawTextureV(*texture, pos, WHITE); }

static UpdatableHandler updatableHandler;
UpdatableHandler &getUpdatableHandler() { return updatableHandler; }

static DrawableHandler drawableHandler;
DrawableHandler &getDrawableHandler() { return drawableHandler; }

} // namespace RRE::Objects
