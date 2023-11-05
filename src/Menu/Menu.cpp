#include "menu/Menu.h"

#include <fstream>
#include <iomanip>
#include <sstream>

#include "nlohmann/json.hpp"
using json = nlohmann::json;

bool Menu::loadFromFile(const std::string& path) {
    std::ifstream file("assets/" + path);
    if (!file.is_open()) {
        return false;
    }

    json data = json::parse(file);
    // std::cout << "[DEBUG] Parsed menu_items.json" << std::endl;
    for (auto& item : data["menu"]) {
        // std::cout << "[DEBUG] Iterating through items..." << std::endl;
        std::string name = item["name"].get<std::string>();
        double price = item["price"].get<double>();
        std::string restrictions = item["diet"].get<std::string>();
        addMenuItem(
            name, std::make_unique<MenuItem>(name, price, restrictions));
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
    ss << name_ << " (" << restrictions_ << ")";
    return ss.str();
}
