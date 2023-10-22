#pragma once

#include "Order.h"

/**
 * @brief The Item class represents a single item on an order.
 */
class Item : public Order {
public:
    /**
     * @brief Constructs a new Item object with the given menu item and price.
     *
     * @param menuItem The name of the menu item.
     * @param price The price of the menu item.
     */
    Item(std::string menuItem, double price);

    /**
     * @brief Adds an order to the item (not applicable for an item).
     *
     * @param order The order to add.
     */
    void add(std::unique_ptr<Order>);

    /**
     * @brief Returns a string representation of the item.
     *
     * @return A string representation of the item.
     */
    std::string printOrder();

    /**
     * @brief Calculates the total cost of the item.
     *
     * @return The total cost of the item.
     */
    virtual double total();

private:
    std::string menuItem; /**< The name of the menu item. */
    double price;         /**< The price of the menu item. */
};