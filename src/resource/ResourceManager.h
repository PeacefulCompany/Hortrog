#pragma once

#include "SFML/Audio/Music.hpp"
#include <memory>
#include <unordered_map>

template <typename Res, typename Id = int>
class ResourceManager {
public:
    // Prevent copying
    ResourceManager(const ResourceManager<Res, Id>&) = delete;
    ResourceManager<Res, Id>& operator=(
        const ResourceManager<Res, Id>&) = delete;
    ResourceManager() = default;

    template <typename... Args>
    bool load(const Id& id, Args&&... args);

    Res& get(const Id& id) const;

private:
    std::unordered_map<Id, std::unique_ptr<Res>> map_;
};

#include "ResourceManager.inl"