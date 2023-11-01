#pragma once

#include "Customer.h"

class Manager;
class Waiter;

class CustomerState {
public:
    virtual void visit(Manager&) = 0;
    virtual void visit(Waiter&) = 0;

private:
    Customer* customer_;
};
