#pragma once

#include "floor/Table.h"

#include <memory>
#include <unordered_map>

#include "customer/Customer.h"
#include "staff/FloorStaff.h"
#include "staff/Manager.h"
#include "staff/Waiter.h"
/**
 * @class Floor
 * @brief This class represents a floor.
 *
 * The Floor class is a concrete class that contains methods for managing
 * customers and staff.
 */
// std::cout << "Floor" << std::endl;
// Floor* floor = new Floor();
// std::vector<Customer*> customers;
// customers.push_back(new Customer("Neo", 0.5));
// customers.push_back(new Customer("Trinity", 0.5));
// customers.push_back(new Customer("Morpheus", 0.5));
// floor->customerEnter(customers);
// floor->addStaff(new Waiter());
// floor->createTables(5, 4);
// floor->addCustomerToTable(customers);
// floor->checkAllTables();

// floor->checkAllTables();
// floor->checkAllTables();
// floor->checkAllTables();
// floor->checkAllTables();
// floor->checkAllTables();

// JSON ORDER ->{
// "order": [
// {"name": "Vegetable Stir-Fry","price": 9.990000},
// {"component": {"name": "Vegetable Stir-Fry","price": 9.990000}, "modifier":
// },
// {"name": "Grilled Salmon","price": 14.990000}
// ]}

// OUT:
// Floor
// Not ready to order
// Not ready to order
// Not ready to order
// kitchen check for orders...
// [Waiting]: Thanks for the food!!
// kitchen check for orders...
// [Waiting]: Thanks for the food!!
// kitchen check for orders...
// [Waiting]: Thanks for the food!!
// [Eating]: Visited by waiter
// Still eating: 1
// [Eating]: Visited by waiter
// Still eating: 1
// [Eating]: Visited by waiter
// Still eating: 1
// [Eating]: Visited by waiter
// [Eating] Done eating, let me pay
// [Eating]: Visited by waiter
// [Eating] Done eating, but I want more
// [Eating]: Visited by waiter
// [Eating] Done eating, but I want more
// [Paying]: Give payment to waiter
// Not ready to order
// Not ready to order
class Floor {
public:
    Floor() = default;
    ~Floor() = default;

    uint32_t addTable(int capacity);

    /**
     * @brief Gets the tables.
     *
     * This function is used to get the tables.
     *
     * @return The tables.
     */
    Table* requestSeating(int n);

    /**
     * @brief Adds multiple customers to the floor.
     *
     * This function is used to add multiple customers to the floor.
     *
     * @param customers The customers to add.
     */
    void customerEnter(std::vector<Customer*> customers);
    /**
     * @brief Adds a customer to the floor.
     *
     * This function is used to add a customer to the floor.
     *
     * @param customer The customer to add.
     */
    void customerEnter(Customer* customer);
    /**
     * @brief Removes a customer from the floor.
     *
     * This function is used to remove a customer from the floor.
     *
     * @param customer The customer to remove.
     * @param tableId The id of the table to check.
     */
    void removeCustomerFromTable(Customer* customer, int tableId);
    /**
     * @brief Adds a staff member to the floor.
     *
     * This function is used to add a staff member to the floor.
     *
     * @param staff The staff member to add.
     */
    void addStaff(FloorStaff* staff);
    /**
     * @brief Removes a staff member from the floor.
     *
     * This function is used to remove a staff member from the floor.
     *
     * @param staff The staff member to remove.
     */
    void removeStaff(FloorStaff* staff);
    /**
     * @brief Creates tables.
     *
     * This function is used to create tables.
     *
     * @param numTables The number of tables to create.
     * @param numSeats The number of seats per table.
     */
    void createTables(int numTables, int numSeats);
    /**
     * @brief Adds a customer to a table.
     *
     * This function is used to add a customer to a table.
     *
     * @param customer The customer to add.
     * @param tableId The id of the table to add the customer to.
     */
    void addCustomerToTable(Customer* customer, int tableId);
    /**
     * @brief Adds multiple customers to a table.
     *
     * This function is used to add multiple customers to a table.
     *
     * @param customers The customers to add.
     */
    void addCustomerToTable(std::vector<Customer*> customers);
    /**
     * @brief Checks a table.
     *
     * This function is used to check a table.
     *
     * @param tableId The id of the table to check.
     */
    void checkTable(int tableId, int waiterId);
    /**
     * @brief Checks all tables.
     *
     * This function is used to check all tables.
     */
    void checkAllTables();
    /**
     * @brief Calls the kitchen.
     *
     * This function is used to call the kitchen.
     */
    void kitchenCall();
    /**
     * @brief Checks the kitchen.
     *
     * This function is used to check the kitchen.
     *
     * @param waiter The waiter to check the kitchen.
     */
    void checkKitchen(Waiter* waiter);
    /**
     * @brief Seats the floor.
     *
     * This function is used to to go through the floor and
     *  group random people on the floorCustomer_ vector to tables.
     */
    void seatTheFloor();

    std::string toString() const;

    Waiter* getWaiter(int waiterId) const;

    void update(float dt);

private:
    uint32_t tableCount_ = 0;
    std::vector<Table*> tables_;            // The tables on the floor
    std::vector<Customer*> floorCustomers_; // The customers on the floor
    std::vector<FloorStaff*> staff_;        // The staff on the floor
};