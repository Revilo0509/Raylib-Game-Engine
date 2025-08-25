#include "QDU.hpp"
#include "RRE_Aliases.hpp"

class Game : public RRE::GamePrototype {
  public:
    void draw() override { DrawFPS(10, 10); }

    void update() override {}
};

class ObjectPro : public RRE::Object {
  public:
    ObjectPro(Texture *i_texture, RRE::Vec2 i_pos)
        : RRE::Object(i_texture, i_pos) {}

    void draw() override {
        RRE::QDU::SimpleDrawTexturePro(texture, Rectangle{0, 0, 100, 100});
    }
};

int main() {
    Game game;

    Texture im_logo = LoadTexture("./resources/logo/logo.png");
    ObjectPro logo(&im_logo, RRE::Vec2{100, 100});

    game.run();
}