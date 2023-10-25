#pragma once

#include "ActionTarget.h"
#include "event/Action.h"

template <typename T>
ActionTarget<T>::ActionTarget(const ActionMap<T>& map) : actionMap_(map) {}

template <typename T>
bool ActionTarget<T>::processEvent(const sf::Event& e) const {
    for (auto& key : eventsPoll_) {
        const Action& action = actionMap_.get(key.first);
        if (action != e) continue;
        key.second(e);
        return true;
    }
    return false;
}
template <typename T>
void ActionTarget<T>::processEvents() const {
    for (auto& key : eventsRealTime_) {
        const Action& action = actionMap_.get(key.first);
        if (action.test()) {
            key.second(action.event());
        }
    }
}

template <typename T>
void ActionTarget<T>::bind(const T& key, FuncType&& callback) {
    const Action& action = actionMap_.get(key);
    if (action.type() & Action::ActionType::RealTime) {
        eventsRealTime_.emplace_back(key, callback);
    } else {
        eventsPoll_.emplace_back(key, callback);
    }
}

template <typename T>
void ActionTarget<T>::unbind(const T& key) {
    const Action& action = actionMap_.get(key);
    auto func = [&action](const std::pair<Action, FuncType>& pair) -> bool {
        return pair.first == action;
    };
    if (action.type() & Action::ActionType::RealTime) {
        eventsRealTime_.remove_if(func);
    } else {
        eventsPoll_.remove_if(func);
    }
}
