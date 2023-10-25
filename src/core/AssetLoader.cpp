#include "core/AssetLoader.h"
#include "views/SpriteView.h"

#include <fstream>
#include <iostream>
#include <memory>

#include "SFML/Graphics/Sprite.hpp"

#include "nlohmann/json.hpp"
using json = nlohmann::json;

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

gui::View* AssetLoader::loadView(const std::string& path) {
    auto it = views_.find(path);

    if (it == views_.end()) {
        std::ifstream file("assets/" + path);
        if (!file.is_open()) return nullptr;

        json data = json::parse(file);
        if (data["type"].get<std::string>() == "sprite") {
            const sf::Texture* texture = loadTexture(data["path"]);
            if (!texture) return nullptr;

            sf::Sprite sprite(*texture);
            std::pair<float, float> scale = data["scale"];
            sprite.setScale(scale.first, scale.second);

            std::unique_ptr<gui::View> view =
                std::make_unique<SpriteView>(std::move(sprite));
            views_.emplace(path, std::move(view));
            it = views_.find(path);
        } else {
            return nullptr;
        }
    }
    return it->second.get();
}