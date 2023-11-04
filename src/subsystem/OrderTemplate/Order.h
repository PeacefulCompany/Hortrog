#pragma once

#include <stdint.h>
#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <string>
#include <vector>

class Order {
public:
    // constructors and destructors

    Order(std::string customer);
    Order();
    ~Order();

    // functions
    void add(Order* order);
    std::string toJson();
    double total();

    // getters and setters
    std::string getCustomer() const;
    inline std::vector<Order*>& getOrders() { return orders_; }
    void setCustomer(std::string customer);
    inline uint32_t getTblId() { return tableId_; }

private:
    // attributes
    std::vector<Order*> orders_;
    std::string customer;
    uint32_t tableId_ = 0;
    // functions
};

#endif // ORDER_H