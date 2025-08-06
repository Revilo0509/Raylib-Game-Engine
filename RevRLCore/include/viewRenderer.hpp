#pragma once

#include <raylib.h>

namespace RevRLCore {

class View {
  public:
    Rectangle window;

  public:
    View(Rectangle view) { window = view; };
    Vector2 toViewSpace();
    Vector2 toGlobalSpace();
};

} // namespace RevRLCore
