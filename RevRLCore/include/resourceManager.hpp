#pragma once

#include "raylib.h"
#include <filesystem>
#include <string>
#include <vector>

namespace RevRLCore {

template <typename T> using vector = std::vector<T>;

using string = std::string;

struct TextureElement {
    string name;
    Texture2D texture;
};

struct SoundElement {
    string name;
    Sound sound;
};

struct TextureVector {
    std::string type;
    vector<TextureElement> textures;
};

class ResourceManager {
  private:
    vector<TextureVector> textureVector;
    vector<SoundElement> sounds;
    Texture2D noTexture;

  public:
    Texture2D *getTexture(string type, string name);
    void init(std::filesystem::path path);
    ~ResourceManager();
};

} // namespace RevRLCore