#include "resourceManager.hpp"

#include "raylib.h"
#include <filesystem>

namespace RevRLCore {

namespace fs = std::filesystem;

Texture2D *ResourceManager::getTexture(string type, string name) {
    for (auto &entry : textureVector) {
        if (entry.type != type) {
            continue;
        }
        for (auto &texture : entry.textures) {
            if (texture.name == name) {
                return &texture.texture;
            }
        }
    }
    return &noTexture;
}

void ResourceManager::init(fs::path path) {
    const fs::path soundsPath = path / "sounds";
    const fs::path texturesPath = path / "textures";

    const fs::path noTexturePath = texturesPath / "noTexture.png";
    noTexture = LoadTexture(noTexturePath.string().c_str());

    for (const auto &parentEntry : fs::directory_iterator(texturesPath)) {
        if (!fs::is_directory(parentEntry)) {
            continue;
        }

        vector<TextureElement> tempTextures;
        for (const auto &entry : fs::directory_iterator(parentEntry)) {
            tempTextures.push_back(
                TextureElement{entry.path().filename().string(),
                               LoadTexture(entry.path().string().c_str())});
        }
        textureVector.push_back(
            {parentEntry.path().filename().string(), tempTextures});
    }

    for (const auto &entry : fs::directory_iterator(soundsPath)) {
        sounds.push_back(
            SoundElement{entry.path().filename().string(),
                         LoadSound(entry.path().string().c_str())});
    }
}

ResourceManager::~ResourceManager() {
    for (const auto &parentEntry : textureVector) {
        for (const auto &entry : parentEntry.textures) {
            UnloadTexture(entry.texture);
        }
    }

    for (const auto &entry : sounds) {
        UnloadSound(entry.sound);
    }
}

} // namespace RevRLCore