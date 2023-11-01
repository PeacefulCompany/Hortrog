#pragma once

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
    void setCustomer(std::string customer);
    inline std::vector<Order*> getOrders() { return orders_; }

private:
    // attributes
    std::string customer;
    std::vector<Order*> orders_;
    // functions
};

#endif // ORDER_H