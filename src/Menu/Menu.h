#pragma once

#include <memory>
#include <string>
#include <unordered_map>

class MenuItem {
public:
    MenuItem(
        const std::string& name, double price, const std::string& restrictions)
        : name_(name), price_(price), restrictions_(restrictions) {}

    const std::string& getName() const { return name_; }
    double getPrice() const { return price_; }
    const std::string& getRestrictions() const { return restrictions_; }

    std::string toString() const;

private:
    std::string name_;
    double price_;
    std::string restrictions_;
};

class Menu {
public:
    /**
     * @brief Loads a menu from a JSON file
     *
     * @param path The path (relative to assets) of the menu
     * @return true The file was loaded successfully
     * @return false The file failed to load
     */
    bool loadFromFile(const std::string& path);

    /**
     * @brief Add an item to the menu.
     *
     * This function adds an item to the menu with the provided name and
     * details.
     *
     * @param name The name of the item.
     * @param item The item to be added to the menu.
     *
     * @return void
     */
    bool addMenuItem(const std::string& name, std::unique_ptr<MenuItem> item) {
        if (menuItems_.contains(name)) return false;
        menuItems_[name] = std::move(item);
        return true;
    }

    /**
     * @brief Retrieves an item from the menu (if found)
     *
     * @param key The key of the item
     * @return const MenuItem* The menu item with the given key, or `nullptr`
     * otherwise
     */
    const MenuItem* getMenuItem(const std::string& key) {
        auto it = menuItems_.find(key);
        if (it != menuItems_.end()) return nullptr;
        return it->second.get();
    }

    /**
     * @brief Retrieves the keys for all menu items in the menu
     *
     * @return The keys for all menu items in the menu
     */
    std::vector<std::string> getAllKeys() const;

    std::string toString() const;

private:
    std::unordered_map<std::string, std::unique_ptr<const MenuItem>> menuItems_;
};
