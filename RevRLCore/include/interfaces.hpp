#pragma once

#include <vector>

namespace RevRLCore {

class Updatable {
  public:
    Updatable();
    virtual void update() = 0;
};

class Drawable {
  public:
    Drawable();
    virtual void draw() = 0;
};

class UpdatableHandler;
class DrawableHandler;

UpdatableHandler &getUpdatableHandler();
DrawableHandler &getDrawableHandler();

class UpdatableHandler {
  private:
    std::vector<Updatable *> updatables;

  public:
    void add(Updatable *obj) { updatables.push_back(obj); }

    void run() {
        for (auto obj : updatables)
            obj->update();
    }
};

class DrawableHandler {
  private:
    std::vector<Drawable *> drawables;

  public:
    void add(Drawable *obj) { drawables.push_back(obj); }

    void run() {
        for (auto obj : drawables)
            obj->draw();
    }
};

inline UpdatableHandler &getUpdatableHandler() {
    static UpdatableHandler handler;
    return handler;
}

inline DrawableHandler &getDrawableHandler() {
    static DrawableHandler handler;
    return handler;
}

// automatic registration
inline Updatable::Updatable() { getUpdatableHandler().add(this); }
inline Drawable::Drawable() { getDrawableHandler().add(this); }

} // namespace RevRLCore