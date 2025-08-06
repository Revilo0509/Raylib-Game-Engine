#pragma once

#include "resourceManager.hpp"

using namespace RevRLCore;

class game {
  private:
    ResourceManager resources;

  public:
    void run();
    game();
};