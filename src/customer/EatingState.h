#pragma once

#include "CustomerState.h"
#include "core/Timer.h"

#include "subsystem/Meals/Meal.h"

class EatingState : public CustomerState {
public:
    EatingState(Customer* c, Meal* meal) : CustomerState(c), meal_(meal) {}
    void visit(Manager&) override;
    void visit(Waiter&) override;

    void update(float dt) override;

private:
    Timer eatTime_ = Timer(2);
    std::unique_ptr<Meal> meal_;
};