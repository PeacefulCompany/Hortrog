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
    inline std::vector<Order*> &getOrders() { return orders_; }
    void setCustomer(std::string customer);

private:
    // attributes
    std::vector<Order*> orders_;
    std::string customer;

    // functions
};

#endif // ORDER_H