#pragma once

#include "game.hpp"
#include "objects/composites.hpp"
#include "objects/primitives.hpp"
#include "types/vectors.hpp"

namespace RRE {
using GamePrototype = Game::GamePrototype;
using tl_Object = Objects::tl_Object;
using Object = Objects::Object;
using Vec2 = Types::Vec2;
using Vec3 = Types::Vec3;
using Vec4 = Types::Vec4;
using Drawable = Objects::Drawable;
using Updatable = Objects::Updatable;
using Textured = Objects::Textured;
using Velocity = Objects::Velocity;
}; // namespace RRE
