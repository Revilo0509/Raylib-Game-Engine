#pragma once

#include "raylib.h"
#include <string>

namespace RRE::Game {

enum class GameType {
    TOP_DOWN,
    SIDE_SCROLLER
};

enum class Flags : unsigned int {
    NONE                = 0,
    WINDOW_PLAYER_BOUNDS = 1 << 0
};

class GamePrototype {
  public:
    float tickRate = 1.0f / 60.0f;
    Flags gameFlags = Flags::WINDOW_PLAYER_BOUNDS;
    GameType gameTypeFlags = GameType::SIDE_SCROLLER;

  public:
    GamePrototype(int WINDOW_WIDTH = 1280, int WINDOW_HEIGHT = 720,
                  std::string WINDOW_TITLE = "RRE Default Title",
                  unsigned int i_ConfigFlags = FLAG_VSYNC_HINT |
                                               FLAG_WINDOW_HIGHDPI |
                                               FLAG_WINDOW_RESIZABLE);
    ~GamePrototype();
    void run();
    virtual void update() = 0;
    virtual void draw() = 0;
};

} // namespace RRE::Game