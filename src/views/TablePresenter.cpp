#include "TablePresenter.h"
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Mouse.hpp"
#include <iostream>

bool TablePresenter::onEvent(const sf::Event& e) {
    // Get mouse position
    sf::Vector2i pos;
    switch (e.type) {
    case sf::Event::MouseButtonPressed:
    case sf::Event::MouseButtonReleased:
        pos = {e.mouseButton.x, e.mouseButton.y};
        break;
    case sf::Event::MouseMoved: pos = {e.mouseMove.x, e.mouseMove.y}; break;
    default: pos = {0, 0}; break;
    }

    // Handle event
    switch (e.type) {
    case sf::Event::MouseButtonPressed: beginDrag(pos); break;

    case sf::Event::MouseMoved:
        if (delta_.x != 0 && delta_.y != 0) drag(pos);
        break;
    case sf::Event::MouseButtonReleased: endDrag(); break;
    default: break;
    }
    return false;
}

void TablePresenter::beginDrag(sf::Vector2i mouse) {
    sf::Vector2i viewPos = target_.mapCoordsToPixel(view_.position());
    delta_ = viewPos - mouse;
}

void TablePresenter::drag(sf::Vector2i mouse) {
    sf::Vector2f worldPos = target_.mapPixelToCoords(mouse + delta_);
    view_.position(worldPos);
}

void TablePresenter::endDrag() { delta_ = {0, 0}; }
