#pragma once

#include "resourceManager.hpp"

using namespace RevRLCore;

class Game {
  private:
    ResourceManager resources;

  public:
    void run();
    virtual void loop();
    Game();
    ~Game();
};