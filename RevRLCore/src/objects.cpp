#include "objects.hpp"

#include "raylib.h"

using namespace RevRLCore;

Object::Object(Texture2D* tex, Vector2 initPos) {
    texture = tex;
    pos = initPos;
}

void Object::setTexture(Texture2D *tex) {
    texture = tex;
}

void Object::draw() {
    DrawTextureV(*texture, pos, WHITE);
}