#include "FloorView.h"
#include "SFML/Graphics/RenderTarget.hpp"
FloorView::FloorView(ResourceManager<sf::Texture>& textures)
    : textures_(textures) {
    sprite_.setTexture(*textures_.get(0));
}

void FloorView::draw(sf::RenderTarget& window) const {
    sf::Sprite sprite(*textures_.get(0));
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 10; j++) {
            sprite.setPosition(i * 32 * 4, j * 32 * 4);
            sprite.setScale(4, 4);
            window.draw(sprite);
        }
    }
}
sf::FloatRect FloorView::getBoundingBox() const {
    return sprite_.getGlobalBounds();
}

sf::Vector2f FloorView::position() const { return sprite_.getPosition(); }

void FloorView::position(sf::Vector2f v) { sprite_.setPosition(v); }

FloorView::~FloorView() {}
