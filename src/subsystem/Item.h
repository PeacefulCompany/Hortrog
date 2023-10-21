#pragma once
#include "MenuItem.h"
/**
 * @brief a leaf in the composite pattern
 *
 */
class Item : public MenuItem {
public:
    /**
     * @brief Construct a new Item object
     *
     * @param name
     * @param price
     */
    Item(std::string name, double price);
private:
};