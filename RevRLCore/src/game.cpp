#include "Game.hpp"

#include "interfaces.hpp"
#include "objects.hpp"
#include "settings.hpp"


#include "ImGuiHandler.hpp"
#include "raylib.h"
#include "rlImGui.h"
#include <filesystem>


gameSettings gameSettings;

void Game::run() {
    Object blo(resources.getTexture("entity", "blob.png"), {10, 10});

    while (!WindowShouldClose()) {
        getUpdatableHandler().run();

        BeginDrawing();
            ClearBackground(BLACK);
            getDrawableHandler().run();
                    
            #ifdef RevRLImGui_Implementation
                rlImGuiBegin();
                RevRLImGui::getUpdatableHandler().run();
                rlImGuiEnd();
            #endif

        EndDrawing();
    }
}

Game::Game() {
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI |
                   FLAG_WINDOW_RESIZABLE);
    InitWindow(gameSettings.WINDOW_WIDTH, gameSettings.WINDOW_HEIGHT,
               gameSettings.WINDOW_TITLE);
#ifdef RevRLImGui_Implementation
    rlImGuiSetup(true);
#endif
    resources.init(std::filesystem::current_path().append("resources"));
}

Game::~Game() {
    rlImGuiShutdown();
    CloseWindow();
}