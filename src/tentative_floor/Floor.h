// #pragma once
// #include <iostream>
// #include <vadefs.h>
// #include <vector>

// #include "customer/Customer.h"
// #include "staff/FloorStaff.h"
// #include "staff/Manager.h"
// #include "staff/Waiter.h"

// class Floor {
// public:
//     /**
//      * @brief Constructs a new Floor object.
//      *
//      * This constructor creates a new Floor object.
//      */
//     Floor();
//     /**
//      * @brief Destroys the Floor object.
//      *
//      * This destructor destroys the Floor object.
//      */
//     ~Floor();
//     /**
//      * @brief Adds multiple customers to the floor.
//      *
//      * This function is used to add multiple customers to the floor.
//      *
//      * @param customers The customers to add.
//      */
//     void customerEnter(std::vector<Customer*> customers);
//     /**
//      * @brief Adds a customer to the floor.
//      *
//      * This function is used to add a customer to the floor.
//      *
//      * @param customer The customer to add.
//      */
//     void customerEnter(Customer* customer);
//     /**
//      * @brief Removes a customer from the floor.
//      *
//      * This function is used to remove a customer from the floor.
//      *
//      * @param customer The customer to remove.
//      * @param tableId The id of the table to check.
//      */
//     void removeCustomerFromTable(Customer* customer, int tableId);
//     /**
//      * @brief Adds a staff member to the floor.
//      *
//      * This function is used to add a staff member to the floor.
//      *
//      * @param staff The staff member to add.
//      */
//     void addStaff(FloorStaff* staff);
//     /**
//      * @brief Removes a staff member from the floor.
//      *
//      * This function is used to remove a staff member from the floor.
//      *
//      * @param staff The staff member to remove.
//      */
//     void removeStaff(FloorStaff* staff);
//     /**
//      * @brief Creates tables.
//      *
//      * This function is used to create tables.
//      *
//      * @param numTables The number of tables to create.
//      * @param numSeats The number of seats per table.
//      */
//     void createTables(int numTables, int numSeats);
//     /**
//      * @brief Adds a customer to a table.
//      *
//      * This function is used to add a customer to a table.
//      *
//      * @param customer The customer to add.
//      * @param tableId The id of the table to add the customer to.
//      */
//     void addCustomerToTable(Customer* customer, int tableId);
//     /**
//      * @brief Adds multiple customers to a table.
//      *
//      * This function is used to add multiple customers to a table.
//      *
//      * @param customers The customers to add.
//      */
//     void addCustomerToTable(std::vector<Customer*> customers);
//     /**
//      * @brief Checks a table.
//      *
//      * This function is used to check a table.
//      *
//      * @param tableId The id of the table to check.
//      */
//     void checkTable(int tableId);

// protected:
//     /**
//      * @struct Table
//      * @brief This struct represents a table and is temporarily
//      *
//      * The Table struct contains methods for managing customers at a table.
//      */
//     struct Table {
//         int id_;       // The table ID
//         int seats_;    // The number of seats at the table
//         int waiterId_; // The ID of the waiter assigned to the table
//         std::vector<Customer*> customersAtTable_; // The customers at the
//         table
//         /**
//          * @brief Adds a customer to the table.
//          *
//          * This function is used to add a customer to the table.
//          *
//          * @param customer The customer to add.
//          */
//         void addCustomer(Customer* customer) {
//             if (static_cast<int>(customersAtTable_.size()) < seats_) {
//                 customersAtTable_.push_back(customer);
//                 customer->update(10);
//             } else {
//                 std::cout << "Table is full. Cannot add more customers."
//                           << std::endl;
//             }
//         }
//     };

// private:
//     std::vector<Customer*> floorCustomers_; // The customers on the floor
//     std::vector<Table*> tables_;            // The tables on the floor
//     std::vector<FloorStaff*> staff_;        // The staff on the floor
// };
// // void floor() {
// //     std::cout << "Floor" << std::endl;
// //     Floor* floor = new Floor();
// //     std::vector<Customer*> customers;
// //     customers.push_back(new Customer("Neo", 0.5));
// //     customers.push_back(new Customer("Trinity", 0.5));
// //     customers.push_back(new Customer("Morpheus", 0.5));
// //     floor->customerEnter(customers);

// //     floor->addStaff(new Waiter());
// //     floor->createTables(5, 4);
// //     floor->addCustomerToTable(customers);

// //     floor->checkTable(0);
// //     floor->checkTable(0);
// // }

// // out:
// //  Floor
// //  Table 0 has 3 customers.
// //  Not ready to order
// //  Not ready to order
// //  Not ready to order
// //  Table 0 has 3 customers.
// //  [Waiting]: Where's the food at???
// //  [Eating]: Visited by waiter
// //  [Paying]: Give payment to waiter
// //  COS 214 - Final Project