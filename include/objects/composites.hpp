#pragma once

#include "objects/primitives.hpp"
#include <raylib.h>

namespace RRE::Objects {

class Object : public Drawable {
  public:
    Vector2 pos;
    Texture2D *texture;

    Object(Texture2D *tex, Vector2 i_pos);
    void draw() override;
};

class Player : public Object, public Updatable {
  public:
    int speed = 6;

  public:
    Player(Texture2D *tex, Vector2 i_pos) : Object(tex, i_pos) {}
    void update() override;
};

} // namespace RRE::Objects