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
    Modifier(Order* order);
    /**
     * @brief Destructor for the Modifier class.
     * */
    ~Modifier();
    /**
     * @brief Adds an order to the modifier
     *
     * @param order The order to add.
     */
    void add(Order* order);

    /**
     * @brief Calculates the total cost of the modifier.
     *
     * @return The total cost of the modifier.
     */
    virtual double total();

protected:
    Order* Component; /**< The order being modified. */
    /**
     * @brief Returns a string representation of the modified order.
     *
     * @return A string representation of the modified order.
     */
    virtual std::string printOrder();

private:
};