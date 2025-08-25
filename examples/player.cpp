#include "RRE_Aliases.hpp"

class Game : public RRE::GamePrototype {
  public:
    void draw() override { DrawFPS(10, 10); }
    void update() override {}
};

class Player : public RRE::Objects::InputPlayer, RRE::Object {
public:
    Player(Texture i_texture, RRE::Vec2 i_pos) : Object::Object(&i_texture, i_pos), InputPlayer(i_pos) {}
    void draw() {
        DrawTextureV(*texture, Object::pos, WHITE);
    }

};

int main() {
    Game game;

    Texture whattt = LoadTexture("./resources/textures/noTexture.png");
    Player player(whattt, RRE::Vec2{100, 100});

    game.run();
}