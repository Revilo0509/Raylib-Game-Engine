#pragma once

#include <raylib.h>

namespace RevRLCore {

class View {
  public:
    Rectangle window;
    View *parent = nullptr;

  public:
    View(Rectangle view);
    Vector2 toViewSpace();
    Vector2 toGlobalSpace();
};

} // namespace RevRLCore
