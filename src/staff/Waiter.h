#pragma once
#include "FloorStaff.h"
#include "customer/Customer.h"
#include "customer/CustomerState.h"
#include "order/NullOrderBuilder.h"
#include "order/OrderBuilder.h"
#include <iostream>
#include <memory>

using namespace std;
/**
 * @class Waiter
 * @brief This class represents a waiter.
 *
 * The Waiter class is a concreteElement class that inherits from the FloorStaff
 * class. It overrides the accept method from the FloorStaff class.
 */
class Waiter : public FloorStaff {
public:
    /**
     * @brief Default constructor for Waiter.
     */
    Waiter();

    /**
     * @brief Checks the kitchen.
     *
     * This function is used to check the kitchen for orders.
     */
    void checkKitchen();

    /**
     * @brief Gets the order builder.
     *
     * This function is used to get the order builder.
     *
     * @return A pointer to the order builder.
     */
    OrderBuilder* getOrderBuilder();

    /**
     * @brief Accepts a customer state.
     *
     * This function is used to accept a customer state.
     *
     * @param state The customer state to accept.
     */
    void accept(CustomerState& state) override;

private:
    // Kitchen* kitchen_;
    // PointOfSales* pointOfSales_;
    // std::vector<Tables*> tables_;

    /**
     * @brief A unique pointer to the order builder.
     */
    std::unique_ptr<NullOrderBuilder> orderBuilder_;
};