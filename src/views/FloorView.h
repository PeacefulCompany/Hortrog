#pragma once

#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/System/Vector2.hpp"
#include "gui/View.h"
#include "resource/ResourceManager.h"
#include <map>
#include <vector>

class FloorView : public gui::View {
public:
    enum SpriteType { SingleTable };

    FloorView(int width,
        int height,
        ResourceManager<sf::Texture, SpriteType>& resources);

    void draw(sf::RenderTarget& target) const override;

    sf::FloatRect getBoundingBox() const override;

    sf::Vector2f position() const override;
    void position(sf::Vector2f v) override;

    bool placeTable(int x, int y);
    bool removeTable(int x, int y);

private:
    void layout();
    sf::RectangleShape& get(int x, int y);

    sf::Vector2f position_;
    std::vector<sf::RectangleShape> tiles_;

    int width_, height_;
    const ResourceManager<sf::Texture, SpriteType>& resources_;

    static constexpr float TILE_WIDTH = 64;
};