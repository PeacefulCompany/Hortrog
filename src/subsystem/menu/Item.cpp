/**
 * @file Item.cpp
 * @brief Implementation of the Item class
 */

#include "Item.h"

/**
 * @brief Construct a new Item object
 * 
 * @param name The name of the item
 * @param cost The cost of the item
 * @param diet The dietary information of the item
 * @param mod The modification information of the item
 */
Item::Item(std::string name, double cost, std::string diet, std::string mod) {
    this->name = name;
    this->cost = cost;
    this->diet = diet;
    this->mod = mod;
}

/**
 * @brief Destroy the Item object
 * 
 */
Item::~Item() {}

/**
 * @brief Get the name of the item
 * 
 * @return std::string The name of the item
 */
std::string Item::getName() { return name; }

/**
 * @brief Get the cost of the item
 * 
 * @return double The cost of the item
 */
double Item::getCost() { return cost; }

/**
 * @brief Get the dietary information of the item
 * 
 * @return std::string The dietary information of the item
 */
std::string Item::getDiet() { return diet; }

/**
 * @brief Get the modification information of the item
 * 
 * @return std::string The modification information of the item
 */
std::string Item::getMod() { return mod; }
