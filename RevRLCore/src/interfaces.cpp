#include "interfaces.hpp"

namespace RevRLCore {

static UpdatableHandler updatableHandler;
UpdatableHandler &getUpdatableHandler() { return updatableHandler; }
static DrawableHandler drawableHandler;
DrawableHandler &getDrawableHandler() { return drawableHandler; }

} // namespace RevRLCore
