#include "game.hpp"
#include "objects.hpp"
#include "interfaces.hpp"

class FallingObj : public Object, public Updatable {
  public:
    FallingObj(Texture2D *tex, Vector2 initPos) : Object(tex, initPos) {}

    void update() override { pos.y -= 1; }
    void draw() override {
        DrawTextureV(*texture, pos, WHITE);
        DrawFPS(500, 10);
    }
};

class FPS : public Drawable {
  public:
    void draw() override { DrawFPS(500, 10); }
};

int main() {
    Game game;

    FallingObj blo(game.resources.getTexture("entity", "blob.png"), {10, 10});

    game.run();
}