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

    void map(const T& key, const Action& action);
    const Action& get(const T& key) const;

private:
    std::unordered_map<T, Action> map_;
};

#include "ActionMap.inl"