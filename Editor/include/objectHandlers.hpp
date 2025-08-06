#pragma once

#include "interfaces.hpp"
#include <vector>

class updatableHandler {
private:
    std::vector<updatable*> updatables;

public:
    void add(updatable* obj) {
        updatables.push_back(obj);
    }

    void run() {
        for (auto obj : updatables)
            obj->update();
    }
};

class drawableHandler {
private:
    std::vector<drawable*> drawables;

public:
    void add(drawable* obj) {
        drawables.push_back(obj);
    }

    void run() {
        for (auto obj : drawables)
            obj->draw();
    }
};

inline updatableHandler& getUpdatableHandler() {
    static updatableHandler handler;
    return handler;
}

inline drawableHandler& getDrawableHandler() {
    static drawableHandler handler;
    return handler;
}


// automatic registration
inline updatable::updatable() {
    getUpdatableHandler().add(this);
}

inline drawable::drawable() {
    getDrawableHandler().add(this);
}
