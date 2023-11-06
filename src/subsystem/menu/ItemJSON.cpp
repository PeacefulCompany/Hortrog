/**
 * @file Item.cpp
 * @brief Implementation of the Item class
 */

#include "ItemJSON.h"
#include <string>

/**
 * @brief Construct a new Item object
 *
 * @param name The name of the item
 * @param cost The cost of the item
 * @param diet The dietary information of the item
 * @param mod The modification information of the item
 */
ItemJSON::ItemJSON(std::string name, double cost, std::string diet, std::string mod, std::string customer) {
    this->name_ = name;
    this->cost_ = cost;
    this->diet_ = diet;
    this->mod_ = mod;
    this->customer_ = customer;
}

/**
 * @brief Destroy the Item object
 *
 */
ItemJSON::~ItemJSON() {}

/**
 * @brief Get the name of the item
 *
 * @return std::string The name of the item
 */
std::string ItemJSON::getName() { return name_; }

/**
 * @brief Get the cost of the item
 *
 * @return double The cost of the item
 */
double ItemJSON::getCost() { return cost_; }

/**
 * @brief Get the dietary information of the item
 *
 * @return std::string The dietary information of the item
 */
std::string ItemJSON::getDiet() { return diet_; }

/**
 * @brief Get the modification information of the item
 *
 * @return std::string The modification information of the item
 */
std::string ItemJSON::getMod() { return mod_; }

/**
 * @brief Get the customer name of the item
 *
 * @return std::string The customer name of the item
 */
std::string ItemJSON::getCustomer() { return customer_; }

std::string ItemJSON::toString() {
    std::string ret = "{\"name\": \"" + name_ + "\",";
    ret += "\"customer\": \"" + customer_ + "\",";
    ret += "\"price\": " + std::to_string(cost_) + "}";
    return ret;
}
