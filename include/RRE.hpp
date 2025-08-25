#pragma once

#include "raylib.h"
#include <string>
#include <vector>

namespace RRE {

class GamePrototype {
  public:
    float tickRate = 1.0f / 128.0f;
    unsigned int scene = 0;

  public:
    GamePrototype(int WINDOW_WIDTH = 1280, int WINDOW_HEIGHT = 720,
                  std::string WINDOW_TITLE = "RRE Default Title",
                  unsigned int i_ConfigFlags = FLAG_VSYNC_HINT |
                                               FLAG_WINDOW_HIGHDPI |
                                               FLAG_WINDOW_RESIZABLE);
    ~GamePrototype();
    void run();            // Main game loop
    virtual void update(); // Logic updated at fixed tick rate
    virtual void draw();   // Rendering runs as fast as possible
};

class Updatable {
  public:
    unsigned int scene = 0;

  public:
    Updatable(unsigned int i_scene);
    virtual ~Updatable();

    virtual void update() = 0;
    void run() { update(); }
};

class Drawable {
  public:
    unsigned int scene = 0;

  public:
    Drawable(unsigned int i_scene);
    virtual ~Drawable();

    virtual void draw() = 0;
    void run() { draw(); }
};

class Object : public Drawable {
  public:
    Vector2 pos;
    Texture *texture;

  public:
    Object(int x, int y, Texture *i_texture, unsigned int i_scene = 0);
    Object(Vector2 i_pos, Texture *i_texture, unsigned int i_scene = 0);
    void draw() override;

};

// Generic manager for instances
template <typename T> class InstanceManager {
  public:
    void add(T *instance, unsigned int scene = 0);
    void remove(T *instance, unsigned int scene = 0);
    void run(unsigned int scene = 0);

  private:
    std::vector<std::vector<T *>> instances; // Scenes -> Instances
};

} // namespace RRE