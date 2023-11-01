#pragma once

#include "order/OrderBuilder.h"
#include <string>

class CustomerState;
class FloorStaff;

class Customer {
public:
    Customer(const std::string& name, float happiness);

    void buildOrder(OrderBuilder& builder);
    void interact(FloorStaff& staff);

private:
    CustomerState* state_;
    std::string name_;
    float happiness_;
};