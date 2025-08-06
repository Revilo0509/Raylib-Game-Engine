#pragma once

#include "raylib.h"
#include <filesystem>
#include <string>
#include <vector>

template <typename T> using vector = std::vector<T>;

using string = std::string;

struct textureElement {
    string name;
    Texture2D texture;
};

struct soundElement {
    string name;
    Sound sound;
};

struct textureVector {
    std::string type;
    vector<textureElement> textures;
};

class resourceManager {
  private:
    vector<textureVector> textureVector;
    vector<soundElement> sounds;
    Texture2D noTexture;
  public:
    Texture2D *getTexture(string type, string name);
    void init(std::filesystem::path path);
    ~resourceManager();
};