#pragma once

#include "SFML/Graphics/Sprite.hpp"
#include "gui/View.h"
#include "resource/ResourceManager.h"

class TableView : public gui::View {
public:
    enum SpriteType { Single };
    TableView(ResourceManager<sf::Texture, SpriteType>& resources);

    void draw(sf::RenderTarget& target) const override;
    sf::FloatRect getBoundingBox() const override;

    sf::Vector2f position() const override;
    void position(sf::Vector2f v) override;

    bool onEvent(const sf::Event& event) override;

private:
    sf::Sprite sprite_;
};