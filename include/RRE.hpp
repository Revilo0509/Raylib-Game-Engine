#pragma once

#include "raylib.h"
#include <string>
#include <vector>

namespace RRE {

class GamePrototype {
  public:
    float tickRate = 1.0f / 128.0f;

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
    Updatable();
    virtual ~Updatable();

    virtual void update() = 0;
    void run() { update(); }
};

class Drawable {
  public:
    Drawable();
    virtual ~Drawable();

    virtual void draw() = 0;
    void run() { draw(); }
};

class Object : public Drawable {
  public:
    Vector2 pos;
    Texture *texture;

public:
    Object(int x, int y, Texture *i_texture);
    Object(Vector2 i_pos, Texture *i_texture);
    void draw() override;
};

// Generic manager for instances
template <typename T>
class InstanceManager {
  public:
    void add(T *instance);
    void remove(T *instance);
    void run();
    const std::vector<T *> &getAll() const;

  private:
    std::vector<T *> instances;
};

} // namespace RRE