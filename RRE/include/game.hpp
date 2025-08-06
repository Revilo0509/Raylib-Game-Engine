#pragma once

#include "resourceManager.hpp"
#include "settings.hpp"

using namespace RevRLCore;

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