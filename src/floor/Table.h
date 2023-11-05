#pragma once

#include <vector>

#include "customer/Customer.h"
#include "order/OrderBuilder.h"

class TableComponent;
class CustomerIterator;

class Table {
public:
    /**
     * @brief Provides an order builder to all customers seated at the table
     *
     * @param builder The builder to give to the customer
     */
    virtual void buildOrder(OrderBuilder& builder) = 0;

    /**
     * @brief Seats a customer at the table (if a seat is available)
     *
     * @param customer The customer to add
     * @return true A seat was available and the customer has been seated
     * @return false There is no available seat to accomadate the customer
     */
    virtual bool seatCustomer(Customer* customer) = 0;

    /**
     * @brief Removes a customer from their seat at the table
     *
     * @param customer The customer to remove
     * @return true The customer was removed from the table
     * @return false The customer was not found at the table
     */
    virtual bool removeCustomer(Customer* customer) = 0;

    /**
     * @brief Merges a table into the current table (if possible)
     *
     * @param table The table to merge
     * @return true The table has been successfully merged
     * @return false Merging failed; not supported by the table
     */
    virtual bool merge(Table* table) = 0;

    /**
     * @brief Splits a table into its constituent @link TableComponent @endlink
     *
     * @return std::vector<TableComponent*> The table components making up this
     * table
     */
    virtual std::vector<TableComponent*> split() = 0;

    /**
     * @brief Checks whether the table has any customers seated at it
     *
     * @return true There are customers seated at the table
     * @return false There are no customers seated at the table
     */
    virtual bool isEmpty() const = 0;

    /**
     * @brief Create an iterator to traverse the customers seated at the table
     *
     * @return CustomerIterator*
     */
    CustomerIterator* createIterator();

    /**
     * @brief Computes the number of customers this table can accomadate
     *
     * @return int The number of customers that can be seated at this table
     */
    virtual int capacity() const = 0;
    virtual uint32_t id() const = 0;
    virtual std::string toString() const = 0;

    virtual void update(float dt) = 0;

private:
};