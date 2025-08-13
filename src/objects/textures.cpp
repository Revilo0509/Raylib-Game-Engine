#include "objects/textures.hpp"

namespace RRE::Objects::Textures {

static TexturedHandler texturedHandler;
TexturedHandler &getTexturedHandler() { return texturedHandler; }

} // namespace RRE::Objects::Textures