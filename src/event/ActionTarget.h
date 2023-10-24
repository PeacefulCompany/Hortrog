#pragma once

#include "SFML/Window/Event.hpp"
#include <functional>
#include <list>
#include <utility>

#include "Action.h"

class ActionTarget {
public:
    using FuncType = std::function<void(const sf::Event&)>;

    ActionTarget() = default;
    bool processEvent(const sf::Event& e) const;
    void processEvents() const;

    void bind(const Action& action, FuncType& callback);
    void unbind(const Action& action);

private:
    std::list<std::pair<Action, FuncType>> eventsRealTime_;
    std::list<std::pair<Action, FuncType>> eventsPoll_;
};