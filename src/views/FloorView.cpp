#include "FloorView.h"
#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/System/Vector2.hpp"
#include "views/FloorView.h"

FloorView::FloorView(
    int width, int height, ResourceManager<sf::Texture, SpriteType>& resources)
    : View(), position_(0, 0), tiles_(width * height), width_(width),
      height_(height), resources_(resources) {

    for (int i = 0; i < tiles_.size(); i++) {
        tiles_[i].setFillColor(sf::Color::Transparent);
        tiles_[i].setSize({TILE_WIDTH, TILE_WIDTH});
    }
    position({0, 0});
}
void FloorView::draw(sf::RenderTarget& target) const {
    for (const auto& rect : tiles_) {
        target.draw(rect);
    }
}
sf::FloatRect FloorView::getBoundingBox() const {
    sf::FloatRect rect;
    rect.top = position_.y;
    rect.left = position_.x;
    rect.height = TILE_WIDTH * height_;
    rect.width = TILE_WIDTH * width_;

    return rect;
}

sf::Vector2f FloorView::position() const { return position_; }
void FloorView::position(sf::Vector2f v) {
    position_ = v;
    layout();
}

bool FloorView::placeTable(int x, int y) {
    sf::RectangleShape& shape = get(x, y);
    shape.setTexture(resources_.get(SingleTable));
    shape.setFillColor(sf::Color::White);
    return true;
}

bool FloorView::removeTable(int x, int y) {
    sf::RectangleShape& shape = get(x, y);
    shape.setFillColor(sf::Color::Transparent);
    return true;
}

void FloorView::layout() {
    // Layout grid
    for (int i = 0; i < tiles_.size(); i++) {
        int x = i % width_;
        int y = i / width_;

        tiles_[i].setPosition(
            position_ + sf::Vector2f(x * TILE_WIDTH, y * TILE_WIDTH));
    }
}

sf::RectangleShape& FloorView::get(int x, int y) {
    return tiles_[y * width_ + x];
}
