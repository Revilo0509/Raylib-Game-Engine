#pragma once

#include "instanceManager/instanceManager.hpp"
#include "raylib.h"
#include "types/vectors.hpp"

namespace RRE::Objects {

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

class Textured {
  public:
    RenderTexture texture;
    Textured(int width, int height);
    virtual ~Textured();

    void drawToScreen();
    virtual void drawToTexture() = 0;
    void wrapper();
    void run() { wrapper(); }
};

class Velocity {
  public:
    RRE::Types::Vec2 velocity;

  public:
    Velocity() : velocity(0.0f, 0.0f) {}
    explicit Velocity(float i_speedX, float i_speedY);

    RRE::Types::Vec2 get() const;

    Velocity &operator=(const Velocity &other);
    Velocity operator+(const Velocity &other) const;
    Velocity operator-(const Velocity &other) const;
    Velocity &operator+=(const Velocity &other);
    Velocity &operator-=(const Velocity &other);
};

// Type aliases
using UpdatableHandler = instanceManagers::InstanceHandler<Updatable>;
using DrawableHandler = instanceManagers::InstanceHandler<Drawable>;
using TexturedHandler = instanceManagers::InstanceHandler<Textured>;

// Declarations
UpdatableHandler &getUpdatableHandler();
DrawableHandler &getDrawableHandler();
TexturedHandler &getTexturedHandler();

// Inline member definitions
inline Updatable::Updatable() { getUpdatableHandler().add(this); }
inline Updatable::~Updatable() { getUpdatableHandler().remove(this); }
inline Textured::Textured(int width, int height) {
    LoadRenderTexture(width, height);
    getTexturedHandler().add(this);
}

inline Drawable::Drawable() { getDrawableHandler().add(this); }
inline Drawable::~Drawable() { getDrawableHandler().remove(this); }
inline Textured::~Textured() { getTexturedHandler().remove(this); }

} // namespace RRE::Objects
