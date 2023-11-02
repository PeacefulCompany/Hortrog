#pragma once
#include <string>
#ifndef SUBSYSTEM_MEAL_ITEM_H
#define SUBSYSTEM_MEAL_ITEM_H

class MealItem {

public:
    MealItem(std::string, std::string, float);
    inline std::string getFood() const { return food_; }
    inline std::string getCustomer() const { return customer_; }
    inline float getQuality() const { return quality_; }
    inline bool isReady() const { return ready_; }
    inline void setReady(bool rStatus_) { ready_ = rStatus_; }

private:
    std::string food_;
    std::string customer_;
    float quality_;
    bool ready_ = false;
};

#endif // SUBSYSTEM_MEAL_ITEM_H