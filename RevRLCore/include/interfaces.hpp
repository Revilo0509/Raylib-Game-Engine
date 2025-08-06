#pragma once

#include <algorithm>
#include <vector>


namespace RevRLCore {

class Updatable {
  public:
    Updatable();
    ~Updatable();

    virtual void update() = 0;
};

class Drawable {
  public:
    Drawable();
    ~Drawable();

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
    void remove(Updatable *obj) {
        auto it = std::remove(updatables.begin(), updatables.end(), obj);
        updatables.erase(it, updatables.end());
    }

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
    void remove(Drawable *obj) {
        auto it = std::remove(drawables.begin(), drawables.end(), obj);
        drawables.erase(it, drawables.end());
    }

    void run() {
        for (auto obj : drawables)
            obj->draw();
    }
};

// automatic registration and deregistration
inline Updatable::Updatable() { getUpdatableHandler().add(this); }
inline Updatable::~Updatable() { getUpdatableHandler().remove(this); }

inline Drawable::Drawable() { getDrawableHandler().add(this); }
inline Drawable::~Drawable() { getDrawableHandler().remove(this); }

} // namespace RevRLCore
