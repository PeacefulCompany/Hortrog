/**
 * @file OrderJSON.cpp
 * @brief Implementation of the OrderJSON class
 */

#include "OrderJSON.h"
#include "json.hpp"
#include <iostream>
using json = nlohmann::json;

/**
 * @brief Constructs an OrderJSON object with the given order string
 * @param order The order string in JSON format
 */
OrderJSON::OrderJSON(std::string order) { this->order_ = order; }

/**
 * @brief Parses the order string and returns a vector of Item pointers
 * @return A vector of Item pointers
 */
std::vector<Item*> OrderJSON::getItems() {
    json data = json::parse(order_);

    for (auto& item : data["order"]) {
        // std::cout << "[DEBUG] Iterating through items..." << std::endl;
        std::string name = item["name"].get<std::string>();
        double price = item["price"].get<double>();

        std::string diet;

        if (item.contains("diet")) {
            diet = item["diet"].get<std::string>();
        } else {
            diet = "none";
        }

        std::string mod;

        if (item.contains("mod")) {
            mod = item["mod"].get<std::string>();
        } else {
            mod = "none";
        }

        Item* newItem = new Item(name, price, diet, mod);
        items_.push_back(newItem);
    }

    return items_;
}
