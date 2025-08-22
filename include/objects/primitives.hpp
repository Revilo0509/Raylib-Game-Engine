#pragma once

#include "instanceManager/instanceManager.hpp"

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
