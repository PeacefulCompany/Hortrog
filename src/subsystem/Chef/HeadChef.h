#pragma once

#include "KitchenStaff.h"

class HeadChef : public KitchenStaff {
private:
public:
    HeadChef(int rating,
        int capacity,
        Kitchen* kitchen,
        int speed,
        std::string role);
    std::string toString();
    ~HeadChef();

    void prepareMeal(Meal* meal);
};