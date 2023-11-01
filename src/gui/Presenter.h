#pragma once

#include "SFML/Window/Event.hpp"
namespace gui {

class Presenter {
public:
    virtual bool onEvent(const sf::Event& e) { return false;}
    virtual void update(float dt) {}

protected:
    // Prevent contruction
    Presenter() = delete;
};

} // namespace gui