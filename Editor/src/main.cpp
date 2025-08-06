#include "game.hpp"
#include "objects.hpp"

void gamefunction(ResourceManager& resources);

int main() {
    Game gameInstance(gamefunction);
    gameInstance.run();
}

void gamefunction(ResourceManager& resources) {
    Object blo(resources.getTexture("entity", "blob.png"), {10, 10});
}