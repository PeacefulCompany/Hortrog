#include "menu/Menu.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

#include "nlohmann/json.hpp"
using json = nlohmann::json;

bool Menu::loadFromFile(const std::string& path) {
    std::ifstream file("assets/" + path);
    if (!file.is_open()) {
        return false;
    }
    json data = json::parse(file);
    for (auto& item : data["menu"]) {
        std::string name = item["name"].get<std::string>();
        std::string prepMethod = item["prep_method"].get<std::string>();
        std::vector<std::string> modifiers = {};
        if (item.contains("supported_modifiers")) {
            modifiers =
                item["supported_modifiers"].get<std::vector<std::string>>();
        }

        double price = item["price"].get<double>();

        addMenuItem(name,
            std::make_unique<MenuItem>(name, price, prepMethod, modifiers));
    }

    return true;
}
std::vector<std::string> Menu::getAllKeys() const {
    std::vector<std::string> keys;
    for (auto& item : menuItems_) {
        keys.push_back(item.first);
    }
    return keys;
}

std::string Menu::toString() const {
    std::stringstream ss;
    ss << "Menu";
    for (const auto& item : menuItems_) {
        ss << "\n- " << item.second->toString();
    }
    return ss.str();
}

std::string MenuItem::toString() const {
    std::stringstream ss;
    ss << "R" << std::left << std::setw(8) << price_;
    ss << name_ << " (" << preparationMethod_ << ")";
    return ss.str();
}
