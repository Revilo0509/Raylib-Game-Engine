#pragma once

#include "resourceManager.hpp"
#include "settings.hpp"
#include <functional>

using namespace RevRLCore;

class Game {
  private:
    ResourceManager resources;
    GameSettings *gameSettings;
    std::function<void(ResourceManager&)> initFunc;

  public:
    void run();
    Game(std::function<void(ResourceManager&)> initFunction);
    ~Game();
};