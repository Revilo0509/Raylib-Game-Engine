#pragma once

#include "interfaces.hpp"
#include "raylib.h"

namespace RevRLCore {

class Object : public Drawable {
  public:
    Vector2 pos;
    Texture2D *texture;

  public:
    Object(Texture2D *tex, Vector2 initPos);
    void draw() override;
};

} // namespace RevRLCore