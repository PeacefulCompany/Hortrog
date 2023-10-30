#include "FloorView.h"
#include "SFML/Graphics/RenderTarget.hpp"
FloorView::FloorView(ResourceManager<sf::Texture>& textures)
    : textures_(textures) {
    sprite_.setTexture(*textures_.get(0));
}

void FloorView::draw(sf::RenderTarget& window) const {
    sf::Sprite floor(*textures_.get(0));
    sf::Sprite entrance(*textures_.get(1));
    sf::Sprite waiter(*textures_.get(2));
    sf::Sprite wall(*textures_.get(3));

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 10; j++) {
            floor.setPosition(i * 32 * 3, j * 32 * 3);
            floor.setScale(3, 3);
            window.draw(floor);
        }
        for (int j = 0; j < 2; j++) {
            wall.setPosition(i * 32 * 3, j * 32 * 3);
            wall.setScale(3, 3);
            window.draw(wall);
        }
    }
    entrance.setPosition(0, 0);
    entrance.setScale(2.7, 2.7);
    window.draw(entrance);

    waiter.setPosition(32 * 2, 32 * 2);
    waiter.setScale(3, 3);
    // window.draw(waiter);
}
sf::FloatRect FloorView::getBoundingBox() const {
    return sprite_.getGlobalBounds();
}

sf::Vector2f FloorView::position() const { return sprite_.getPosition(); }

void FloorView::position(sf::Vector2f v) { sprite_.setPosition(v); }

FloorView::~FloorView() {}
