#pragma once

#include "FloorStaff.h"
#include "billing/PointOfSales.h"
#include "customer/Customer.h"
#include "customer/CustomerState.h"
#include "floor/Floor.h"
#include "floor/Table.h"
#include "menu/Menu.h"
#include "order/ConcreteOrderBuilder.h"
#include "order/OrderBuilder.h"
#include "staff/FloorStaff.h"
#include "subsystem/Meals/Meal.h"
#include <memory>
#include <vector>

/**
 * @class Waiter
 * @brief This class represents a waiter.
 *
 * The Waiter class is a concreteElement class that inherits from the FloorStaff
 * class. It overrides the accept method from the FloorStaff class.
 */
class Waiter : public FloorStaff {
public:
    Waiter(const Menu* menu, const Floor* floor);

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
     * This function is used to get the staff type to id
     *
     * @return The staff type.
     */
    std::string getStaffType() override;
    /**
     * @brief Checks the kitchen.
     * this fucntion checks if the waiter hase ready meals in had
     * if it does it will serve them
     *  else it will try to get meals from the kitchen
     */
    void checkKitchen();
    /**
     * @brief Gets the order builder.
     *
     * This function is used to get the order builder for the customers to use
     *
     * @return A pointer to the order builder.
     */
    OrderBuilder* getOrderBuilder() { return orderBuilder_.get(); }
    /**
     * @brief Gets the ready meals.
     *
     * This function is used to get the ready meals from the kitchen
     *
     * @return A vector of meals that are ready.
     */
    std::vector<Meal*> getReadyMeals();
    /**
     * @brief Fetches the meals.
     *
     * This function is used to fetch the meals from the kitchen to the correct
     * waiter
     * This function is used to fetch the meals from the kitchen.
     */
    void FetchMeals();
    /**
     * @brief Gets the tables.
     *
     * This function is used to get the tables.
     *
     * @return A vector of tables.
     */
    std::vector<Table*> getTables() { return tables_; }
    /**
     * @brief Gives the order to the kitchen.
     *
     * This function is used to give the order to the kitchen.
     */
    void Givetokitchen();
    /**
     * @brief Gives the food to the customer.
     *
     * This function is used to give the food to the correct customer
     *
     * @param Customer The customer to give the food to.
     */
    void giveMeal(Customer& Customer, Meal* meal);
    /**
     * @brief Get the Meal object
     *  tries to get the meal for the ready meals vector or returns null
     * @param Customer
     * @return Meal*
     */
    Meal* getMeal(Customer& Customer);

    std::string toString() const override;

    void assignTable(Table* table);

    void visitTables() override;

    void giveFoodToCustomer(Customer& Customer);
    /**
     * @brief Calls the manager.
     *
     * This function is used to call the manager.
     *
     * @param state The customer state.
     * @brief Calls the managers
     *  takes in the state of the customer and create and calls
     * the manager with the customer to visit the customer
     * @param state
     */
    void callManager(CustomerState& state);
    /**
     * @brief Gets the point of sales.
     *
     * This function is used to get the point of sales.
     *
     * @return A pointer to the point of sales.
     */
    PointOfSales* getPointOfSales() { return pointOfSales_; }
    /**
     * @brief Serves the meals.
     *
     * This goes through the all the tables
     * and serves the meals to the correct customers
     */
    void serveMeals();

private:
    const Menu* menu_;
    Kitchen* kitchen_; // dont think waiter should hold the kitchen
    /**
     * @brief A vector of meals that are ready.
     */
    std::vector<Meal*> readyMeals;
    /**
     * @brief A static member kitchen_.
     */
    //  static Kitchen* kitchen_;
    /**
     * @brief A pointer to the point of sales.
     */
    PointOfSales* pointOfSales_;

    /**
     * @brief A vector of tables.
     */
    std::vector<Table*> tables_;
    /**
     * @brief A unique pointer to the order builder.
     */
    std::unique_ptr<OrderBuilder> orderBuilder_;
    const Floor* floor_;
};
