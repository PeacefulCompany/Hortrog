#pragma once
#include "FloorStaff.h"
#include "customer/CustomerState.h"
#include <iostream>
using namespace std;

/**
 * @class Manager
 * @brief This class represents a manager.
 *
 * The Manager class is a concreteElement class that inherits from the
 * FloorStaff class. It overrides the accept method from the FloorStaff class.
 */
class Manager : public FloorStaff {
public:
    /**
     * @brief Checks the kitchen.
     *
     * This function is used to check the kitchen.
     */
    void checkKitcken();

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
    // std::vector<Tables*> tables_;
};