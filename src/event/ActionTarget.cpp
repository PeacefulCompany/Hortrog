#include "ActionTarget.h"
#include "event/Action.h"

bool ActionTarget::processEvent(const sf::Event& e) const {
    for (auto& action : eventsPoll_) {
        if (action.first != e) continue;
        action.second(e);
        return true;
    }
    return false;
}
void ActionTarget::processEvents() const {
    for (auto& action : eventsRealTime_) {
        if (action.first.test()) {
            action.second(action.first.event_);
        }
    }
}

void ActionTarget::bind(const Action& action, FuncType& callback) {
    if (action.type_ & Action::ActionType::RealTime) {
        eventsRealTime_.emplace_back(action, callback);
    } else {
        eventsPoll_.emplace_back(action, callback);
    }
}
void ActionTarget::unbind(const Action& action) {
    auto func = [&action](const std::pair<Action, FuncType>& pair) -> bool {
        return pair.first == action;
    };
    if (action.type_ & Action::ActionType::RealTime) {
        eventsRealTime_.remove_if(func);
    } else {
        eventsPoll_.remove_if(func);
    }
}
