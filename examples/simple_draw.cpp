#include "RRE.hpp"

class Game : public RRE::GamePrototype {
    public:
    void draw() override {
        DrawFPS(10, 10);
    }
};

int main() {
    Game game;

    Texture t_maja = LoadTexture("./res/maja_nobg_small.png");
    RRE::Object maja(100, 100, &t_maja);

    game.run();
}