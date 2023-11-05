#include "menu/Menu.h"
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
std::vector<std::string> Menu::getAllMenuKeys() const {
    std::vector<std::string> keys;
    for (auto& item : menuItems_) {
        keys.push_back(item.first);
    }
    return keys;
}

std::string Menu::toString() const {
    std::stringstream ss;
    for (const auto& item : menuItems_) {
        ss << item.second->getName() << " " << item.second->getPrice() << " "
           << item.second->getRestrictions() << std::endl;
    }
    return ss.str();
}
