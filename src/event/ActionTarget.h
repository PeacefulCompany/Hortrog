#pragma once

#include "SFML/Window/Event.hpp"
#include <functional>
#include <list>
#include <utility>

#include "Action.h"
#include "event/ActionMap.h"

template <typename T = int>
class ActionTarget {
public:
    // Prevent copying
    ActionTarget(const ActionTarget<T>&) = delete;
    ActionTarget<T>& operator=(const ActionTarget<T>&) = delete;

    using FuncType = std::function<void(const sf::Event&)>;

    ActionTarget(const ActionMap<T>& map);

    bool processEvent(const sf::Event& e) const;
    void processEvents() const;

    void bind(const T& key, FuncType&& callback);
    void unbind(const T& key);

private:
    std::list<std::pair<T, FuncType>> eventsRealTime_;
    std::list<std::pair<T, FuncType>> eventsPoll_;

    const ActionMap<T>& actionMap_;
};

#include "ActionTarget.inl"