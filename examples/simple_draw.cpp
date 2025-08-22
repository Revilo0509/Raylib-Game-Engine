#include "game.hpp"
#include "objects/composites.hpp"
#include "types/vectors.hpp"

using namespace RRE;

int main() {
    Game::Game gameInc;

    Texture im_logo = LoadTexture("./resources/logo/logo.png");
    RRE::Objects::Object logo(&im_logo, RRE::Types::Vector2{100, 100});

    Texture im_player = LoadTexture("./resources/textures/noTexture.png");
    Objects::Player player(&im_player, Vector2{100, 100});

    gameInc.run();
}