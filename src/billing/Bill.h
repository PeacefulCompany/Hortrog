#pragma once
#include <string>

class Bill {
public:
    virtual const std::string& getName() const = 0; // Include the getName function as a virtual function
    virtual double getPrice() const = 0;
    virtual void add(Bill* bill) = 0;
    virtual const std::vector<Bill*>& getChildren() const = 0;
    virtual void operation() = 0;
};