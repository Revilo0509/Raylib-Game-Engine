#include "game.hpp"

#include "settings.hpp"

gameSettings gameSettings;

void game::run() {
    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(BLACK);
        EndDrawing();
    }
}

game::game() {
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI | FLAG_WINDOW_RESIZABLE);
    InitWindow(gameSettings.WINDOW_WIDTH, gameSettings.WINDOW_HEIGHT, gameSettings.WINDOW_TITLE);
    resources.init();
}