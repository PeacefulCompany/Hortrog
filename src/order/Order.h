#pragma once

#include <string>
#include <memory>

class Order{
private:
    std::string customer;
public:
    virtual void add(std::shared_ptr<Order>) = 0;
    virtual std::string toJson() = 0;
    virtual double total() = 0;
};