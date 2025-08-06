#include "game.hpp"
#include "objects/primitives.hpp"

using namespace RRE;
using namespace RRE::Objects;

class FallingObj : public Object, public Updatable {
  public:
    FallingObj(Texture2D *tex, Vector2 initPos) : Object(tex, initPos) {}

    void update() override { pos.y += 1; }
};

class FPS : public Drawable {
  public:
    void draw() override { DrawFPS(100, 10); }
};

int main() {
    Game game;

    FallingObj blo(game.resources.getTexture("entity", "blob.png"), {10, 10});
    FallingObj blo2(game.resources.getTexture("entity", "blob.png"), {100, 10});
    FPS fps;

    game.run();
}