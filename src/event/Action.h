#pragma once

#include "SFML/Window/Event.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "SFML/Window/Mouse.hpp"

class Action {
public:
    enum ActionType {
        RealTime = 1 << 0,
        Pressed = 1 << 1,
        Released = 1 << 2,
    };

    Action(const sf::Keyboard::Key& key, int type = RealTime | Pressed);
    Action(const sf::Mouse::Button& key, int type = RealTime | Pressed);

    inline int type() const { return type_; }
    inline const sf::Event& event() const { return event_; }

    bool test() const;

    bool operator==(const sf::Event&) const;
    bool operator==(const Action&) const;

private:
    sf::Event event_;
    int type_;
};