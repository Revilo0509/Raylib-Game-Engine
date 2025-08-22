#pragma once

#include "resourceManager.hpp"
#include "settings.hpp"

using namespace RRE;

class Game {
  private:
    GameSettings *gameSettings;

  public:
    ResourceManager resources;

  public:
    void run();
    Game();
    ~Game();
};