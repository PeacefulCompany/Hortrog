#pragma once

#include <string>

class Manager;
class Waiter;
class Customer;

class CustomerState {
public:
    virtual ~CustomerState() {}

    virtual void visit(Manager&) = 0;
    virtual void visit(Waiter&) = 0;

    virtual void update(float dt) {}

    virtual std::string toString() const = 0;

protected:
    CustomerState(Customer* c) : customer_(c) {}
    Customer* customer_;
};
