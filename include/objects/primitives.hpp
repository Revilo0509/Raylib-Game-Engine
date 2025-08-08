#pragma once

#include "instanceManager/instanceManager.hpp"
#include "raylib.h"

namespace RRE::Objects {

class RRE_API Updatable {
  public:
    Updatable();
    virtual ~Updatable();

    virtual void update() = 0;
    void run() { update(); }
};

class RRE_API Drawable {
  public:
    Drawable();
    virtual ~Drawable();

    virtual void draw() = 0;
    void run() { draw(); }
};

class RRE_API Object : public Drawable {
  public:
    Vector2 pos;
    Texture2D *texture;

    Object(Texture2D *tex, Vector2 initPos);
    void draw() override;
};

// Type aliases
using UpdatableHandler = instanceManagers::InstanceHandler<Updatable>;
using DrawableHandler = instanceManagers::InstanceHandler<Drawable>;

// Declarations
UpdatableHandler &getUpdatableHandler();
DrawableHandler &getDrawableHandler();

// Inline member definitions
inline Updatable::Updatable() { getUpdatableHandler().add(this); }
inline Updatable::~Updatable() { getUpdatableHandler().remove(this); }

inline Drawable::Drawable() { getDrawableHandler().add(this); }
inline Drawable::~Drawable() { getDrawableHandler().remove(this); }

} // namespace RRE::Objects
