#pragma once

class OrderBuilder;

#include "CustomerState.h"
#include "subsystem/Meals/Meal.h"
#include <memory>
#include <string>
class FloorStaff;
class Customer {
public:
    Customer(const std::string& name, float happiness);

    void interact(FloorStaff& staff);
    void update(float dt);

    void changeState(CustomerState* state);
    inline const std::string& getName() const { return name_; }

private:
    std::unique_ptr<CustomerState> state_;
    std::string name_;
    float happiness_;
    Meal* receivedMeal;
};