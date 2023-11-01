#include "floor.h"
Floor::Floor(int x, int y, int icon_) : Object(x, y, icon_) {}
Floor::~Floor() {}
sf::FloatRect Floor::getBoundingBox() const { return sf::FloatRect(); }
sf::Vector2f Floor::position() const { return sf::Vector2f(); }
void Floor::position(sf::Vector2f v) {}
void Floor::draw(sf::RenderTarget& window) const {}