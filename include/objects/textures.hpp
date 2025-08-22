#pragma once

#include "instanceManager/instanceManager.hpp"
#include <raylib.h>

namespace RRE::Objects::Textures {

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

using TexturedHandler = instanceManagers::InstanceHandler<Textured>;

TexturedHandler &getTexturedHandler();

inline Textured::Textured(int width, int height) {
    LoadRenderTexture(width, height);
    getTexturedHandler().add(this);
}
inline Textured::~Textured() { getTexturedHandler().remove(this); }

} // namespace RRE::Objects::Textures