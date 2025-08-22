#include "Game.hpp"

#include "objects/primitives.hpp"
#include "objects/textures.hpp"

#include "raylib.h"

namespace RRE {

void Game::run() {
    while (!WindowShouldClose()) {
        RRE::Objects::getUpdatableHandler().run();
        RRE::Objects::Textures::getTexturedHandler().run();

        BeginDrawing();
            ClearBackground(BLACK);
            RRE::Objects::getDrawableHandler().run();

            auto drawableTextures = RRE::Objects::Textures::getTexturedHandler().getAll();
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

} // namespace RRE