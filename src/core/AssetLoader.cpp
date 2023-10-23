#include "core/AssetLoader.h"

#include <fstream>
#include <iostream>
#include <memory>

AssetLoader& AssetLoader::instance() {
    static AssetLoader loader;
    return loader;
}
const sf::Texture* AssetLoader::loadTexture(const std::string& path) {
    auto it = textures_.find(path);

    if (it == textures_.end()) {
        sf::Texture texture;
        if (!texture.loadFromFile("assets/" + path)) {
            return nullptr;
        }

        textures_.emplace(path, std::move(texture));
        it = textures_.find(path);
    }
    return &it->second;
}