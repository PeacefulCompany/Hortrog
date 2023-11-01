#pragma once

#include <memory>
#include <unordered_map>

/**
 * @brief Manages any resource that has a default constructor and a
 * `loadFromFile` method
 *
 * @tparam Res The type of resource being managed
 * @tparam Id The type used to identify a resource
 */
template <typename Res, typename Id = int>
class ResourceManager {
public:
    // Prevent copying
    ResourceManager(const ResourceManager<Res, Id>&) = delete;
    ResourceManager<Res, Id>& operator=(
        const ResourceManager<Res, Id>&) = delete;
    ResourceManager() = default;

    /**
     * @brief Attempts to load a resource from a file using a
     * `Res::loadFromFile` method
     *
     * @param id A resource identifier
     * @param args Parameters for loading the resource
     * @return true Resource was successfully loaded
     * @return false Resource failed to load, or id already exists
     */
    template <typename... Args>
    bool load(const Id& id, Args&&... args);

    /**
     * @brief Retrieves a non-owning pointer to a resource
     *
     * @param id The identifier assigned to the resource
     * @return A reference to the resource (may be `NULL`)
     */
    Res* get(const Id& id) const;

private:
    std::unordered_map<Id, std::unique_ptr<Res>> map_;
};

#include "ResourceManager.inl"