#pragma once

#include "Modifier.h"

/**
 * @brief The Pescetarian class represents a pescetarian Decortator for an order.
 */
class Pescetarian : public Modifier {
public:
    /**
     * @brief Constructs a new Pescetarian object with the given order.
     * 
     * @param order The order to modify.
     */
    Pescetarian(Order* order);

    /**
     * @brief Returns a string representation of the modified order.
     * 
     * @return A string representation of the modified order.
     */
    std::string printOrder();

private:
    const std::string spesification = "Pescetarian"; /**< The specification of the modifier. */
    const double price = 1.00; /**< The price of the modifier. */
};