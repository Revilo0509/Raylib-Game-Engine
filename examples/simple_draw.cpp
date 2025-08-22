#include "game.hpp"
#include "objects/primitives.hpp"
#include "objects/textures.hpp"
#include "types/vectors.hpp"

using namespace RRE;

class test : public RRE::Objects::Textures::Textured {
  public:
    test(int width, int height) : Textured(width, height) {}

    void drawToTexture() override {
        ClearBackground(BLANK);
        DrawRectangle(100, 100, 200, 200, PURPLE);
    }
};

int main() {
    Game gameInc;

    test tes(600, 600);

    Texture Ilogo = LoadTexture("./resources/logo/logo.png");
    RRE::Objects::Object logo(&Ilogo, RRE::Types::Vector2{100, 100});

    gameInc.run();
}