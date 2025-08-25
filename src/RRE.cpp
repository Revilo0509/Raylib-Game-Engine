#include "RRE.hpp"
#include <algorithm>

namespace RRE {

// --- Implementation ---

template <typename T>
void InstanceManager<T>::add(T *instance, unsigned int scene) {
    // Ensure the scene exists
    if (scene >= instances.size())
        instances.resize(scene + 1);
    instances[scene].push_back(instance);
}

template <typename T>
void InstanceManager<T>::remove(T *instance, unsigned int scene) {
    if (scene >= instances.size())
        return; // scene doesn't exist
    auto &sceneVec = instances[scene];
    sceneVec.erase(std::remove(sceneVec.begin(), sceneVec.end(), instance),
                   sceneVec.end());
}

template <typename T> void InstanceManager<T>::run(unsigned int scene) {
    if (scene >= instances.size())
        return; // scene doesn't exist
    for (auto instance : instances[scene])
        instance->run();
}

// --- Global handlers for Updatable and Drawable instances ---

static InstanceManager<Updatable> UpdatableManager;
inline Updatable::Updatable(unsigned int i_scene) : scene(i_scene) {
    UpdatableManager.add(this, scene);
}

inline Updatable::~Updatable() { UpdatableManager.remove(this, scene); }

static InstanceManager<Drawable> DrawableManager;
inline Drawable::Drawable(unsigned int i_scene) : scene(i_scene) {
    DrawableManager.add(this, scene);
}

inline Drawable::~Drawable() { DrawableManager.remove(this, scene); }

// --- GamePrototype implementation ---

GamePrototype::GamePrototype(int WINDOW_WIDTH, int WINDOW_HEIGHT,
                             std::string WINDOW_TITLE,
                             unsigned int i_ConfigFlags) {
    SetConfigFlags(i_ConfigFlags);
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE.c_str());
}

GamePrototype::~GamePrototype() { CloseWindow(); }

void GamePrototype::run() {
    float accumulator = 0.0f;

    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime();
        accumulator += deltaTime;

        // Fixed-timestep update loop
        while (accumulator >= tickRate) {
            this->update();
            UpdatableManager.run(scene);
            accumulator -= tickRate;
        }

        BeginDrawing();
        ClearBackground(BLACK);

        // Render all drawables
        DrawableManager.run(scene);
        this->draw();

        EndDrawing();
    }
}

void GamePrototype::draw() {}
void GamePrototype::update() {}

Object::Object(int x, int y, Texture *i_texture, unsigned int i_scene)
    : Drawable(i_scene), pos{static_cast<float>(x), static_cast<float>(y)},
      texture(i_texture) {}

Object::Object(Vector2 i_pos, Texture *i_texture, unsigned int i_scene)
    : Drawable(i_scene), pos(i_pos), texture(i_texture) {}

void Object::draw() { DrawTextureV(*texture, pos, WHITE); }

} // namespace RRE
