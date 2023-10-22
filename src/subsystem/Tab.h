#pragma once
#include "Order.h"
#include <iostream>
#include <list>
/**
 * @brief The Tab class represents a table's order and is the composite in the
 * composite pattern.
 */
class Tab : public Order {
public:
    /**
     * @brief Constructs a new Tab object with the given table number
     *
     * @param tableNumber The number of the table.
     */
    Tab(int tableNumber);

    /**
     * @brief Returns a string representation of all orders.
     *
     * @return A string representation of the orders.
     */
    std::string printOrder();

    /**
     * @brief Adds an order to the tab.
     *
     * @param order The order to add.
     */
    void add(std::unique_ptr<Order> order);

    /**
     * @brief Calculates the total cost of the tab.
     *
     * @return The total cost of the tab.
     */
    double total();

    /**
     * @brief Removes an order from the tab.
     *
     * @param order The order to remove.
     */
    void removeOrder(std::unique_ptr<Order> order);

private:
    std::list<std::unique_ptr<Order>>
        orders;      /**< The list of orders on the tab. */
    int tableNumber; /**< The number of the table. */
};