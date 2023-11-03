#pragma once

#include "Customer.h"
#include "customer/Customer.h"

class Manager;
class Waiter;

class CustomerState {
public:
    virtual ~CustomerState() {}

    virtual void visit(Manager&) = 0;
    virtual void visit(Waiter&) = 0;

    virtual void update(float dt) {}

protected:
    CustomerState(Customer* c) : customer_(c) {}
    Customer* customer_;
};
