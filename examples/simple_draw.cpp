#include "game.hpp"
#include "objects/primitives.hpp"
#include "types/vectors.hpp"

int main() {
    Game gameInc;

    Objects::Object logo(gameInc.resources.getTexture("logo", "logo"), Types::Vector2{ 100, 100});

    gameInc.run();
}