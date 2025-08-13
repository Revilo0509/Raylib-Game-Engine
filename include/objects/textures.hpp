#pragma once

#include "instanceManager/instanceManager.hpp"

namespace RRE::Objects::Textures {

class Textured {
  public:
    Textured();
    virtual ~Textured();

    virtual void draw() = 0;
    void run() { draw(); }
};

using TexturedHandler = instanceManagers::InstanceHandler<Textured>;

TexturedHandler &getTexturedHandler();

inline Textured::Textured() { getTexturedHandler().add(this); }
inline Textured::~Textured() { getTexturedHandler().remove(this); }

} // namespace RRE::Objects::Textures