#include "Game.hpp"

#include "objects/primitives.hpp"

#include "raylib.h"

namespace RRE::Game {

void Game::run() {
    float accumulator = 0.0f;

    while (!WindowShouldClose()) {

        float deltaTime = GetFrameTime();
        accumulator += deltaTime;
        while (accumulator >= tickRate) {
            RRE::Objects::getUpdatableHandler().run();
            accumulator -= tickRate;
        }

        RRE::Objects::getTexturedHandler().run();

        BeginDrawing();
        ClearBackground(BLACK);
        RRE::Objects::getDrawableHandler().run();

        auto drawableTextures =
            RRE::Objects::getTexturedHandler().getAll();
        for (auto &tex : drawableTextures) {
            tex->drawToScreen();
        }

        EndDrawing();
    }
}

Game::Game(int WINDOW_WIDTH, int WINDOW_HEIGHT, std::string WINDOW_TITLE,
           unsigned int i_ConfigFlags) {

    SetConfigFlags(i_ConfigFlags);
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE.c_str());
}

Game::~Game() { CloseWindow(); }

} // namespace RRE::Game