#pragma once

#include "SFML/Graphics/Sprite.hpp"
#include "gui/View.h"

class SpriteView : public gui::View {
public:
    SpriteView(sf::Sprite&& texture) : sprite_(texture) {}

    void draw(sf::RenderTarget& target) const override { target.draw(sprite_); }

    sf::FloatRect getBoundingBox() const override {
        return sprite_.getGlobalBounds();
    }

    sf::Vector2f position() const override { return sprite_.getPosition(); }
    void position(sf::Vector2f v) override { sprite_.setPosition(v); }

private:
    sf::Sprite sprite_;
};