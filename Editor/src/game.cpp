#include "game.hpp"

#include "entities.hpp"
#include "settings.hpp"
#include "interfaces.hpp"
#include <raylib.h>

gameSettings gameSettings;

void game::run() {
    entity blo(resources.getTexture("entity", "blob.png"));

    while (!WindowShouldClose()) {
        getUpdatableHandler().run();
        BeginDrawing();
            ClearBackground(BLACK);
            getDrawableHandler().run();
        EndDrawing();
    }
}

game::game() {
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI | FLAG_WINDOW_RESIZABLE);
    InitWindow(gameSettings.WINDOW_WIDTH, gameSettings.WINDOW_HEIGHT, gameSettings.WINDOW_TITLE);
    resources.init();
}