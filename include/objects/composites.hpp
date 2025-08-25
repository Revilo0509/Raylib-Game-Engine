#pragma once

#include "objects/primitives.hpp"
#include "types/vectors.hpp"
#include <raylib.h>

namespace RRE::Objects {

using RREVec2 = RRE::Types::Vec2;

class tl_Object : public Drawable {
  public:
    RREVec2 pos;

  public:
    tl_Object(RREVec2 i_pos) : pos(i_pos) {}
};

class Object : public tl_Object {
  public:
    Texture2D *texture;

  public:
    void draw() override;

    Object(Texture2D *tex, RREVec2 i_pos) : tl_Object(i_pos), texture(tex) {}
};

class Movable : public Updatable, public tl_Object {
  public:
    Velocity velocity;
    float speed;

  public:
    Movable(RREVec2 i_pos) : tl_Object(i_pos), velocity(0, 0) {}

    void update() override {
        pos.x += velocity.velocity.x;
        pos.y += velocity.velocity.y;
    }
};

class InputPlayer : public Movable {
public:
    void update() override;

    InputPlayer(RREVec2 i_pos);
};

} // namespace RRE::Objects