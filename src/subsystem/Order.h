#pragma once
#include <string>
class Order {
public:
    virtual void add(Order*) = 0;
    virtual std::string printOrder() = 0;
    virtual double total() = 0;

protected:
    Order();
    void setCost(double cost) { this->price = cost; };
    double getCost() { return price; };

private:
    double price;
};
