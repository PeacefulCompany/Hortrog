// ORDERH
#pragma once

#include "menu/Menu.h"
#include <cstdint>
#include <memory>
#include <string>
#include <utility>
#include <vector>

class Order {
protected:
    std::string customer_;

private:
    uint32_t tblId_;

public:
    /**
     * @brief Adds an Order subclass to the hierarchy
     * @param order a pointer to the Order that is added
     */
    virtual void add(std::unique_ptr<Order>) = 0;
    /**
     * @brief Converts the order to JSON format
     * @return The converted JSON
     */
    virtual std::string toJson() = 0;
    /**
     * @brief Calculates the total price of the hierarchy
     * @return total price of hierarchy
     */
    virtual double total() = 0;
    /**
     * @brief Generates a vector of all orderItems and Modifiers in the
     * hierarchy
     * @return The vector of orders
     */
    virtual std::vector<std::pair<std::string, double>>
    generateReceiptOrderList() = 0;
    /**
     * @getter for id
     * @return
     */
    inline virtual std::string getId() { return ""; };
    /**
     * @brief setter for table id
     * @param id
     */
    inline virtual void setTblId(uint32_t id) { tblId_ = id; };
    /**
     * @brief getter for table id
     * @return
     */
    inline virtual uint32_t getTblId() { return tblId_; };
    /**
     * @brief setter for customer
     * @param customer
     */
    inline virtual void setCustomer(std::string customer) {
        customer_ = std::move(customer);
    };
    /**
     * @brief Checks if the given customerName is in the hierarchy at all
     * @param customerName The customer name to check
     * @return true The customer is in the hierarchy
     * @return false The customer is not in the hierarchy
     */
    virtual bool checkForCustomer(std::string customerName) = 0;
    /**
     * @brief Checks hierarchy for a duplicate order before adding
     * @param customerName The name on the new order
     * @param menuItems All the menu items in the new order
     * @return true There is a duplicate
     * @return false There is not a duplicate
     */
    virtual bool checkForDupe(
        std::string customerName, std::vector<const MenuItem*> menuItems) = 0;
    /**
     * @brief Helper for checkForDupe that generates a vector of all menu items
     * in the hierarchy
     * @return A vector
     */
    virtual std::vector<const MenuItem*> getAllMenuItems() = 0;
    /**
     * @brief Getter for customer
     * @return The customer member
     */
    inline std::string getCustomer() { return customer_; };
    virtual ~Order() = default;
};
