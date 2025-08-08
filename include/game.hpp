#pragma once

#include "export.h"
#include "resourceManager.hpp"
#include "settings.hpp"

using namespace RRE;

class RRE_API Game {
  private:
    GameSettings *gameSettings;

  public:
    ResourceManager resources;

  public:
    void run();
    Game();
    ~Game();
};