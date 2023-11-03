#include "TableView.h"
#include "SFML/Window/Event.hpp"

TableView::TableView(ResourceManager<sf::Texture, SpriteType>& resources)
    : View(), sprite_(*resources.get(Single)) {
    sprite_.setScale(2, 2);
}

void TableView::draw(sf::RenderTarget& target) const { target.draw(sprite_); }
sf::FloatRect TableView::getBoundingBox() const {
    return sprite_.getGlobalBounds();
}

sf::Vector2f TableView::position() const { return sprite_.getPosition(); }
void TableView::position(sf::Vector2f v) { sprite_.setPosition(v); }

bool TableView::onEvent(const sf::Event& event) {
    if (event.type == sf::Event::MouseButtonPressed ||
        event.type == sf::Event::MouseButtonReleased) {
        sf::Vector2f pos = {
            float(event.mouseButton.x), float(event.mouseButton.y)};
        if (!getBoundingBox().contains(pos)) return false;
        if (presenter_) presenter_->onEvent(event);
    } else if (event.type == sf::Event::MouseMoved) {
        sf::Vector2f pos = {float(event.mouseMove.x), float(event.mouseMove.y)};
        if (!getBoundingBox().contains(pos)) return false;
        if (presenter_) presenter_->onEvent(event);
    }
    return false;
}
