#include "objects.hpp"

#include "raylib.h"

object::object(Texture2D* tex) {
    texture = tex;
}

void object::setTexture(Texture2D *tex) {
    texture = tex;
}

void object::draw() {
    DrawTexture(*texture, x, y, WHITE);
}