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
class Floor {
public:
    Table* requestSeating(int n);
    /**
     * @brief Constructs a new Floor object.
     *
     * This constructor creates a new Floor object.
     */
    Floor();
    /**
     * @brief Destroys the Floor object.
     *
     * This destructor destroys the Floor object.
     */
    ~Floor();
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
    void checkAllTables();
    void kitchenCall();
    void checkKitchen(Waiter* waiter);

private:
    std::vector<Table*> tables_;            // The tables on the floor
    std::vector<Customer*> floorCustomers_; // The customers on the floor
    std::vector<FloorStaff*> staff_;        // The staff on the floor
};