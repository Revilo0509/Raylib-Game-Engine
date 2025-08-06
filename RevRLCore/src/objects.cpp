#include "objects.hpp"

#include "raylib.h"

using namespace RevRLCore;

Object::Object(Texture2D* tex, Vector2 initPos) {
    texture = tex;
    pos = initPos;
}

void Object::draw() {
    DrawTextureV(*texture, pos, WHITE);
}