#include "TablePresenter.h"
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Mouse.hpp"
#include <corecrt_math.h>
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

void TablePresenter::update(float dt) {
    if (delta_.x == 0 && delta_.y == 0) return;

    sf::Vector2f mousePos =
        target_.mapPixelToCoords(sf::Mouse::getPosition(target_) + delta_);

    sf::Vector2f pos = view_.position();
    sf::Vector2f delta = mousePos - pos;
    if (fabsf(delta.x) < 1e-5 && fabsf(delta.x) < 1e-5) return;
    view_.position(pos + delta * (dt * 10));
}

void TablePresenter::beginDrag(sf::Vector2i mouse) {
    sf::Vector2i viewPos = target_.mapCoordsToPixel(view_.position());
    delta_ = viewPos - mouse;
    drag(mouse);
}

void TablePresenter::drag(sf::Vector2i mouse) {
    targetPosition_ = target_.mapPixelToCoords(mouse + delta_);
}

void TablePresenter::endDrag() { delta_ = {0, 0}; }
