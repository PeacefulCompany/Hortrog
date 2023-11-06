#pragma once
#include <stdint.h>
#include <string>

// file includes
#include "MealItem.h"
#include "order/Order.h"

// library includes
#include <memory>
#include <vector>

class Meal {

private:
    std::unique_ptr<Order> order_ = std::make_unique<Order>();
    std::vector<MealItem*> items_;
    bool ready_ = false;
    uint32_t tableId_;

public:
    inline Meal(Order* order) : order_(order) { tableId_ = order->getTblId(); }
    float getQuality();
    Order* getOrder();
    std::vector<MealItem*>& takeMeal();
    void addItem(MealItem*);
    bool isReady();
    std::string getJSON();
    std::string getCustomer();
    std::string toString();
    std::vector<MealItem*>& getItems();
    bool containsMealItem(MealItem* item);
    inline bool getReady() { return ready_; }
    inline void setReady(bool rStatus_) { ready_ = rStatus_; }
    inline uint32_t getTableId() { return tableId_; }
};
