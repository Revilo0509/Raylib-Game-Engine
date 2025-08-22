#include "objects/primitives.hpp"

namespace RRE::Objects {

static UpdatableHandler updatableHandler;
UpdatableHandler &getUpdatableHandler() { return updatableHandler; }

static DrawableHandler drawableHandler;
DrawableHandler &getDrawableHandler() { return drawableHandler; }

} // namespace RRE::Objects
