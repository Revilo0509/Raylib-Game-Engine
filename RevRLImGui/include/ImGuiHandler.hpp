#pragma once

#include <vector>
#include "rlImGui.h"

#define RevRLImGui_Implementation

namespace RevRLImGui {

class Updatable {
  public:
    Updatable();
    virtual void update() = 0;
};

class UpdatableHandler {
  private:
    std::vector<Updatable *> updatables;

  public:
    void add(Updatable *obj) { updatables.push_back(obj); }

    void run() {
        for (auto obj : updatables)
            obj->update();
    }
};

inline UpdatableHandler &getUpdatableHandler() {
    static UpdatableHandler handler;
    return handler;
}

// Automatic registration
inline Updatable::Updatable() { getUpdatableHandler().add(this); }

} // namespace RevRLImGui
