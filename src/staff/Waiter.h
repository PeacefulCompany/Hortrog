#pragma once
#include "FloorStaff.h"
#include "customer/Customer.h"
#include "customer/CustomerState.h"
#include "floor/Table.h"
#include "order/OrderBuilder.h"
#include "subsystem/Chef/Kitchen.h"
#include "subsystem/Meals/Meal.h"
#include <memory>
#include <vector>
class Kitchen;

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
     * @brief Accepts a customer state.
     *
     * This function is used to accept a customer state.
     *
     * @param state The customer state to accept.
     */
    void accept(CustomerState& state) override;
    /**
     * @brief Gets the staff type.
     *
     * This function is used to get the staff type.
     *
     * @return The staff type.
     */
    std::string getStaffType() override;
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
    OrderBuilder* getOrderBuilder() { return orderBuilder_.get(); }
    /**
     * @brief Gets the ready meals.
     *
     * This function is used to get the ready meals.
     *
     * @return A vector of meals that are ready.
     */
    std::vector<Meal*> getReadyMeals() { return readyMeals; }
    /**
     * @brief Gets the tables.
     *
     * This function is used to get the tables.
     *
     * @return A vector of tables.
     */
    std::vector<Table*> getTables() { return tables_; }
    /**
     * @brief
     *
     * This function is used to set the Kitcken.
     *
     * @param Kitchen* the new kitchen to be set for the static member kitchen_.
     */
    static void setKitchen(Kitchen* kitchen);

private:
    /**
     * @brief A vector of meals that are ready.
     */
    std::vector<Meal*> readyMeals;
    /**
     * @brief A static member kitchen_.
     */
    static Kitchen* kitchen_;

    // PointOfSales* pointOfSales_;

    /**
     * @brief A vector of tables.
     */
    std::vector<Table*> tables_;
    /**
     * @brief A unique pointer to the order builder.
     */
    std::unique_ptr<OrderBuilder> orderBuilder_;
};
/**
 * @brief Initialize the static member kitchen_ with nullptr.
 *
 * This ensures that all instances of FloorStaff share the same Kitchen
 * instance. Before using this, make sure to set the Kitchen instance using->
 * FloorStaff::setKitchen(new Kitchen());
 */
Kitchen* FloorStaff::kitchen_ = nullptr;