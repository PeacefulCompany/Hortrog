/**
 * @file OrderJSON.cpp
 * @brief Implementation of the OrderJSON class
 */

#include "OrderJSON.h"
#include <iostream>

#include "json.hpp"
using json = nlohmann::json;

/**
 * @brief Constructs an OrderJSON object with the given order string
 * @param order The order string in JSON format
 */
OrderJSON::OrderJSON(std::string order) { this->order_ = order; }

/**
 * @brief Parses the order string and returns a vector of ItemJSON pointers
 * @return A vector of ItemJSON pointers
 */
std::vector<ItemJSON*> OrderJSON::getItems() {
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

        ItemJSON* newItemJSON = new ItemJSON(name, price, diet, mod);
        items_.push_back(newItemJSON);
    }

    return items_;
}
