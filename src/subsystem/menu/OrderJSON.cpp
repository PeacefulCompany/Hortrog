#include "OrderJSON.h"
#include "json.hpp"
#include <iostream>
using json = nlohmann::json;

OrderJSON::OrderJSON(std::string order) { this->order = order; }

std::vector<Item*> OrderJSON::getItems() {
    std::cout << "[DEBUG] Parsing JSON..." << std::endl;
    // json data = json::parse(order);
    std::vector<Item*> items;
    items.push_back(new Item("Avocado Toast", 5.99, "none"));
    items.push_back(new Item("Grilled Salmon", 5.99, "Vegan"));
    // for (auto& item : data["order"]) {
    //     // std::cout << "[DEBUG] Iterating through items..." << std::endl;
    //     std::string name = item["name"].get<std::string>();
    //     double price = item["price"].get<double>();

    //     Item* newItem;

    //     if (item.contains("diet")) {
    //         std::string restrictions = item["diet"].get<std::string>();
    //         newItem = new Item(name, price, restrictions);
    //     } else {
    //         newItem = new Item(name, price, "none");
    //     }

    //     items.push_back(newItem);
    // }
    std::cout << "[DEBUG] Finished parsing JSON..." << std::endl;
    return items;
}
