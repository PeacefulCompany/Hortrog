#include "Action.h"
#include "SFML/Window/Keyboard.hpp"

Action::Action(const sf::Keyboard::Key& key, int type) : type_(type) {
    event_.type = sf::Event::EventType::KeyPressed;
    event_.key.code = key;
}
Action::Action(const sf::Mouse::Button& btn, int type) {
    event_.type = sf::Event::EventType::MouseButtonPressed;
    event_.mouseButton.button = btn;
}

bool Action::test() const {
    if (event_.type == sf::Event::EventType::KeyPressed) {
        if (type_ & ActionType::Pressed) {
            return sf::Keyboard::isKeyPressed(event_.key.code);
        }
    }
    if (event_.type == sf::Event::EventType::MouseButtonPressed) {
        if (type_ & ActionType::Pressed) {
            return sf::Mouse::isButtonPressed(event_.mouseButton.button);
        }
    }
    return false;
}

bool Action::operator==(const sf::Event& e) const {
    bool isEqual = false;
    switch (e.type) {
    case sf::Event::EventType::KeyPressed:
        if (type_ & ActionType::Pressed and
            event_.type == sf::Event::EventType::KeyPressed) {
            isEqual = e.key.code == event_.key.code;
            break;
        }
    case sf::Event::EventType::KeyReleased:
        if (type_ & ActionType::Released and
            event_.type == sf::Event::EventType::KeyPressed)
            isEqual = e.key.code == event_.key.code;
        break;
    case sf::Event::EventType::MouseButtonPressed:
        if (type_ & ActionType::Pressed and
            event_.type == sf::Event::EventType::MouseButtonPressed)
            isEqual = e.mouseButton.button == event_.mouseButton.button;
        break;
    case sf::Event::EventType::MouseButtonReleased:
        if (type_ & ActionType::Released and
            event_.type == sf::Event::EventType::MouseButtonPressed)
            isEqual = e.mouseButton.button == event_.mouseButton.button;
        break;
    default: break;
    }

    return isEqual;
}
bool Action::operator==(const Action& other) const {
    return type_ == other.type_ && other == event_;
}