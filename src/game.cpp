#include "Game.hpp"

#include "objects/primitives.hpp"

#include "raylib.h"
#include <filesystem>

void Game::run() {
    while (!WindowShouldClose()) {
        RRE::Objects::getUpdatableHandler().run();
        
        BeginDrawing();
            ClearBackground(BLACK);
            RRE::Objects::getDrawableHandler().run();
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