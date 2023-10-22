#pragma once
#include "Order.h"
/**
 * @brief The Modifier class represents a Decorator for an order.
 */
class Modifier : public Order {
public:
    /**
     * @brief Constructs a new Modifier object with the given order.
     *
     * @param order The order to modify.
     */
    Modifier(std::unique_ptr<Order> order);
    /**
     * @brief Destructor for the Modifier class.
     * */
    /**
     * @brief Adds an order to the modifier
     *
     * @param order The order to add.
     */
    void add(std::unique_ptr<Order> order);

    /**
     * @brief Calculates the total cost of the modifier.
     *
     * @return The total cost of the modifier.
     */
    virtual double total();

protected:
    std::unique_ptr<Order> Component; /**< The order being modified. */
    /**
     * @brief Returns a string representation of the modified order.
     *
     * @return A string representation of the modified order.
     */
    virtual std::string printOrder();

private:
};