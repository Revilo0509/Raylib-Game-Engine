#pragma once

#include "interfaces.hpp"
#include "raylib.h"

class object : public drawable {
  private:
    Texture2D *texture;

  public:
    int x;
    int y;

  public:
    object(Texture2D *tex);
    void setTexture(Texture2D *tex);
    void draw() override;
};

class blob : public object {};