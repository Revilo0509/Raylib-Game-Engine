#pragma once

#include "interfaces.hpp"
#include "resourceManager.hpp"

class entity : public drawable {
  private:
    Texture2D texture;

  public:
    entity(Texture2D tex) : texture(tex) {}

    void draw() override { DrawTexture(texture, 10, 10, WHITE); }
};
