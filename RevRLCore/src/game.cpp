#include "Game.hpp"

#include "interfaces.hpp"

#include "raylib.h"
#include <filesystem>

void Game::run() {
    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(BLACK);
            getUpdatableHandler().run();
            getDrawableHandler().run();;
        EndDrawing();
    }
}

Game::Game() {
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI |
                   FLAG_WINDOW_RESIZABLE);
    // InitWindow(gameSettings->WINDOW_WIDTH, gameSettings->WINDOW_HEIGHT,
    //            gameSettings->WINDOW_TITLE);
    InitWindow(1270, 720, "editor");
    resources.init(std::filesystem::current_path().append("resources"));
}

Game::~Game() {
    CloseWindow();
}