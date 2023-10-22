#pragma once

#include <string>

/**
 * @brief The Order class represents an order represening the Component in the Decorator pattern.
 */
class Order {
public:
    /**
     * @brief Adds an order to the order 
     * 
     * @param order The order to add.
     */
    virtual void add(Order*) = 0;

    /**
     * @brief Returns a string representation of the order.
     * 
     * @return A string representation of the order.
     */
    virtual std::string printOrder() = 0;

    /**
     * @brief Calculates the total cost of the order.
     * 
     * @return The total cost of the order.
     */
    virtual double total() = 0;

protected:
    /**
     * @brief Constructs a new Order object.
     */
    Order();
    /**
     * @brief Sets the cost of the order.
     * 
     * @param cost The cost of the order.
     */
    void setCost(double cost) { this->price = cost; };

    /**
     * @brief Gets the cost of the order.
     * 
     * @return The cost of the order.
     */
    double getCost() { return price; };

private:
    double price; /**< The price of the order. */
};