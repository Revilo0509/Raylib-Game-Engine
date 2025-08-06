#include "Game.hpp"

#include "interfaces.hpp"

#ifdef RevRLImGui_Implementation
#include "ImGuiHandler.hpp"
#include "rlImGui.h"
#endif
#include "raylib.h"
#include <filesystem>


void Game::run() {
    initFunc(resources);

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

Game::Game(std::function<void(ResourceManager&)> initFunction) {
    initFunc = initFunction;
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI |
                   FLAG_WINDOW_RESIZABLE);
    //InitWindow(gameSettings->WINDOW_WIDTH, gameSettings->WINDOW_HEIGHT,
    //           gameSettings->WINDOW_TITLE);
    InitWindow(1270, 720, "editor");
    #ifdef RevRLImGui_Implementation
        rlImGuiSetup(true);
    #endif
    resources.init(std::filesystem::current_path().append("resources"));
}

Game::~Game() {
    #ifdef RevRLImGui_Implementation
    rlImGuiShutdown();
    #endif
    CloseWindow();
}