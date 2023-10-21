#pragma once
#include "Order.h"
/**
 * @brief a leaf in the composite pattern
 *
 */
class Table : public Order {
public:
    /**
     * @brief Construct a new Item object
     *
     * @param name
     * @param price
     */
    Table(std::string name, double price);
    /**
     * @brief gets the cost of the item
     *
     */
    double getCost();
    /**
     * @brief sets the cost of the item
     *
     * @param price
     */
    std::string getJson();
    void add(Order* order);

    ~Table();

private:
    Order* order;
};
