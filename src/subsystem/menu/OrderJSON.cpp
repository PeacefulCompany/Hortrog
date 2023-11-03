#include "OrderJSON.h"
#include "json.hpp"
#include <iostream>
using json = nlohmann::json;

OrderJSON::OrderJSON(std::string order) { this->order = order; }

std::vector<Item*> OrderJSON::getItems() {
    json data = json::parse(order);

    for (auto &item : data["order"])
    {
        // std::cout << "[DEBUG] Iterating through items..." << std::endl;
        std::string name = item["name"].get<std::string>();
        double price = item["price"].get<double>();

        std::string diet;

        if (item.contains("diet"))
        {
            diet = item["diet"].get<std::string>();
        }
        else
        {
            diet = "none";
        }

        std::string mod;

        if (item.contains("mod"))
        {
            mod = item["mod"].get<std::string>();
        }
        else
        {
            mod = "none";
        }

        Item *newItem = new Item(name, price, diet, mod);
        items.push_back(newItem);
    }

    return items;
}
