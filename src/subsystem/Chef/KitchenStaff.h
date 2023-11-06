#pragma once

#include <memory>

// #include "OrderJSON.h"
#include "core/Timer.h"
#include "order/Order.h"
#include "subsystem/Meals/Meal.h"
#include "subsystem/Meals/MealItem.h"
#include "subsystem/menu/OrderJSON.h"
#include <iostream>

class Kitchen;

class KitchenStaff {
protected:
    // KitchenStaff* nextStaff;
    std::unique_ptr<KitchenStaff> nextStaff_;
    int rating_;
    int capacity_;
    Kitchen* kitchen_;

    Timer timer_;
    virtual void update();

    std::string role_;

public:
    KitchenStaff(/* args */);
    ~KitchenStaff();

    /**
     * @brief This function is used to pass time to progress the work of the
     * chefs
     *
     * @param delta
     */
    void updateTime(int delta);

    /**
     * @brief This is used by chef to work on the meal
     *
     * @param meal
     */
    virtual void prepareMeal(Meal* meal);

    /**
     * @brief Prints the state of any kitchen staff member
     *
     * @return std::string
     */
    virtual std::string toString();

    /**
     * @brief This function is used to notify the head chef that a meal is ready
     *
     */
    void notify();

    /**
     * @brief Set the Next Staff object, which sets up the chain
     *
     * @param next
     */
    void setNextStaff(KitchenStaff* next);

    /**
     * @brief Gets the successor of the current staff member
     *
     * @return KitchenStaff*
     */
    KitchenStaff* getNextStaff();
};
