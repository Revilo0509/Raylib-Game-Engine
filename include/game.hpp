#pragma once

#include "raylib.h"
#include <string>

namespace RRE {

class Game {
  public:
    void run();
    Game(int WINDOW_WIDTH = 1280, int WINDOW_HEIGHT = 720, std::string WINDOW_TITLE = "RRE Default Title",
         unsigned int i_ConfigFlags = FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI |
                                      FLAG_WINDOW_RESIZABLE);
    ~Game();
};

} // namespace RRE