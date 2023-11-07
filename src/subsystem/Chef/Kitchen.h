#pragma once

#include "subsystem/Chef/KitchenStaff.h"
#include "subsystem/Meals/Meal.h"
#include <memory>

#include "HeadChef.h"
#include "KitchenStaff.h"
#include "NormalChef.h"
#include "order/Order.h"
#include "staff/Waiter.h"
#include "subsystem/Meals/Meal.h"
#include <iostream>
#include <list>
#include <string>
#include <vector>

class Waiter;
class Kitchen {
private:
    std::vector<Waiter*> waiters_;
    std::unique_ptr<KitchenStaff> staff_;
    std::list<Meal*> incomingMeals;
    std::vector<Meal*> outgoingMeals;

public:
    Kitchen();
    /**
     * @brief This function is used by the head chef to notify the kitchen that
     * a meal is ready to be served.
     * This also calls the flush function to circulate orders again.
     */
    void notifyItemReady();

    /**
     * @brief This function is used to send orders through the kitchen again,
     * this is used when a meal is ready to be served. So that chefs are given
     * new meals to prepare as well as send ready orders out.
     *
     */
    void flush();

    /**
     * @brief Handle Order is used to add the order to the incomingMeals queue.
     * This is called by the waiters to pass an order to kitchen.
     * @param order - The order object passed to the kitchen.
     */
    void handleOrder(Order* order);

    /**
     * @brief This is used to progress time in the kitchen. This is used to show
     * that chefs are preparing meals and to check if meals are ready to be
     * served.
     *
     * @param time - the amount of time to move forward by.
     */
    void updateTime(int time);

    /**
     * @brief This dequeues a meal from the outgoingMeals vector.
     *
     * @return Meal*
     */
    Meal* getOutgoingMeal();

    /**
     * @brief This function is used to notify all the waiters that
     * some order is ready to be collected
     */
    void notify();

    /**
     * @brief Returns the outgoingOrders vector
     *
     * @return std::vector<Meal*>
     */
    std::vector<Meal*> collectOrders();

    /**
     * @brief Attaches waiters to be notified
     *
     */
    void subscribe(Waiter*);

    /**
     * @brief Detaches waiters to be notified
     *
     */
    void unsubscribe(Waiter*);

    /**
     * @brief Returns the order with the given id, used by waiter
     *
     * @param id - the id of the order to be returned
     * @return Meal*
     */
    Meal* getOrder(uint32_t);

    /**
     * @brief This function is used to print the state of the kitchen
     *
     * @return std::string
     */
    std::string toString();

    void AddChef(KitchenStaff* chef);

    inline KitchenStaff* getFirstChef() { return staff_.get(); }

    ~Kitchen();
};