#pragma once

#include "ActionTarget.h"
#include "event/Action.h"

template <typename T>
bool ActionTarget<T>::processEvent(const sf::Event& e) const {
    for (auto& action : eventsPoll_) {
        if (action.first != e) continue;
        action.second(e);
        return true;
    }
    return false;
}
template <typename T>
void ActionTarget<T>::processEvents() const {
    for (auto& action : eventsRealTime_) {
        if (action.first.test()) {
            action.second(action.first.event_);
        }
    }
}

template <typename T>
void ActionTarget<T>::bind(const T& key, FuncType& callback) {
    const Action& action = actionMap_.get(key);
    if (action.type() & Action::ActionType::RealTime) {
        eventsRealTime_.emplace_back(action, callback);
    } else {
        eventsPoll_.emplace_back(action, callback);
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
