#pragma once

#include "interfaces.hpp"
#include "raylib.h"

namespace RevRLCore {

class Object : public Drawable {
  private:
    Texture2D *texture;

  public:
    Vector2 pos;

  public:
    Object(Texture2D *tex, Vector2 initPos);
    void setTexture(Texture2D *tex);
    void draw() override;
};

class CollisonObject : public Object, public Updatable {
  
};

} // namespace RevRLCore