#pragma once

#include "Modifier.h"
/**
 * @brief The GlutenFree class represents a gluten-free modifier for an order.
 */
class GlutenFree : public Modifier {
public:
    /**
     * @brief Constructs a new GlutenFree object with the given order.
     *
     * @param order The order to modify.
     */
    GlutenFree(std::unique_ptr<Order> order);

    /**
     * @brief Returns a string representation of the modified order.
     *
     * @return A string representation of the modified order.
     */
    std::string printOrder();

private:
    const std::string spesification =
        "Gluten Free";         /**< The specification of the modifier. */
    const double price = 1.00; /**< The price of the modifier. */
};