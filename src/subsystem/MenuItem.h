#pragma once
/**
 * @brief the Decorator class for the MenuItem
 *
 */

#include "Order.h"
class MenuItem : public Order {
public:
    /**
     * @brief Construct a new Menu Item object
     *
     * @param name
     * @param price
     */
    MenuItem(std::string name, double price);
    /**
     * @brief Get the Cost object
     *
     * @return double
     */
    double getCost() override;
    /**
     * @brief Get the Json object
     *
     * @return string
     */
    std::string getJson();
    /**
     * @brief adds an item to the order
     *
     * @param order
     */
    void add(Order* order);
    /**
     * @brief Destroy the Menu Item object
     *
     */
    ~MenuItem();

protected:
private:
    Order* order;
};