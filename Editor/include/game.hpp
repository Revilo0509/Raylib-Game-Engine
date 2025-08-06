#pragma once

#include "resourceManager.hpp"

class game {
  private:
    resourceManager resources;

  public:
    void run();
    game();
};