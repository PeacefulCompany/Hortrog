#pragma once

#include <string>
#include <memory>

class Order{
private:
    std::string customer_;
public:
    virtual void add(std::unique_ptr<Order>) = 0;
    virtual std::string toJson() = 0;
    virtual double total() = 0;
};