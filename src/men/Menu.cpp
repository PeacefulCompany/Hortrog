#include "Menu/Menu.h"
using json = nlohmann::json;

Menu::Menu() {
    // print all items as debug
    //  for (auto& item : menuItems_) {
    //  	std::cout << "[DEBUG] Item OUT: ";
    //  	std::cout << item.second.getName() << std::endl;
    //  	std::cout << item.second.getPrice() << std::endl;
    //  	std::cout << item.second.getRestrictions() << std::endl;
    //  }
}

void Menu::initMenu() {
    std::string path = "menu_items.json";
    std::ifstream file("assets/" + path);
    if (!file.is_open()) {
        std::cout << "Cannot open asset" << std::endl;
        return;
    }
    json data = json::parse(file);
    // std::cout << "[DEBUG] Parsed menu_items.json" << std::endl;
    for (auto& item : data["menu"]) {
        // std::cout << "[DEBUG] Iterating through items..." << std::endl;
        std::string name = item["name"].get<std::string>();
        double price = item["price"].get<double>();
        std::string restrictions = item["diet"].get<std::string>();
        addItem(name, Item(name, price, restrictions));
    }
}