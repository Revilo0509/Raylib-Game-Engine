#include "ImGuiHandler.hpp"
#include "game.hpp"
#include "interfaces.hpp"
#include "objects.hpp"


#include "imgui.h"

class window : public RevRLImGui::GuiUpdatable {
  public:
    void draw() override {
        bool open = true;
        ImGui::ShowDemoWindow(&open);
    };
};

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