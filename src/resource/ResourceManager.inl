#pragma once

#include "ResourceManager.h"
#include "SFML/Audio/Music.hpp"
#include <memory>
#include <utility>

template <typename Res, typename Id>
template <typename... Args>
inline bool ResourceManager<Res, Id>::load(const Id& id, Args&&... args) {
    std::unique_ptr<Res> ptr(new Res);
    if (!ptr->loadFromFile(std::forward<Args>(args)...)) {
        return false;
    }
    map_.emplace(id, std::move(ptr));
    return true;
}

template <typename Res, typename Id>
inline Res& ResourceManager<Res, Id>::get(const Id& id) const {
    return *map_.at(id);
}
