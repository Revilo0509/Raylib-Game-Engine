#include "RRE.hpp"

class Game : public RRE::GamePrototype {
  private:
    const int cooldown = 30;
    int cooldownTimer = 0;

  public:
    void draw() override { DrawFPS(10, 10); }
    void update() override {
        cooldownTimer -= 1;
        if (IsKeyDown(KEY_SPACE) && cooldownTimer <= 0) {
            cooldownTimer = cooldown;
            if (scene == 0) {
                scene = 1;
            } else {
                scene = 0;
            }
        }
    }
};

int main() {
    Game game;

    Texture t_maja = LoadTexture("./res/maja_nobg_small.png");
    RRE::Object maja(100, 100, &t_maja);

    Texture t_maja_red = LoadTexture("./res/maja_nobg_small_red.png");
    RRE::Object maja_red(100, 100, &t_maja_red, 1);

    game.run();
}