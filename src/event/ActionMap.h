#pragma once

#include "Action.h"
#include <unordered_map>

template <typename T = int>
class ActionMap {
public:
    // Prevent copying
    ActionMap(const ActionMap<T>&) = delete;
    ActionMap<T>& operator=(const ActionMap<T>&) = delete;

    ActionMap() = default;

    inline void map(const T& key, const Action& action) {
        map_.emplace(key, action);
    }
    inline const Action& get(const T& key) const { return map_.at(key); }

private:
    std::unordered_map<T, Action> map_;
};