#pragma once

#include "KitchenStaff.h"

class HeadChef : public KitchenStaff {
private:
public:
    /**
     * @brief Construct a new Head Chef object
     *
     * @param rating - rating is the rating of the chef, i.e how talented they
     * are
     * @param capacity - capacity is the number of meals they can prepare at
     * once
     * @param kitchen - kitchen is the kitchen they work in
     * @param speed - speed is the speed at which they prepare meals
     * @param role - role is the role of the chef, i.e head chef, normal chef,
     * etc.
     */
    HeadChef(int rating,
        int capacity,
        Kitchen* kitchen,
        int speed,
        std::string role);
    /**
     * @brief This prints the state of the Headchef
     *
     * @return std::string
     */
    std::string toString();
    ~HeadChef();

    void prepareMeal(Meal* meal);
};