#pragma once

#include "Menu/Menu.h"
#ifndef KITCHEN_DEMO_H
#define KITCHEN_DEMO_H

#include "../../order/ConcreteOrderBuilder.h"
#include "../../order/Order.h"


#include "../../Menu/Menu.h"
#include "order/ConcreteOrderBuilder.h"
#include "subsystem/Chef/Kitchen.h"

class KitchenDemo {

private:
    Kitchen* kitchen_;
    ConcreteOrderBuilder* orderBuilder_;
    Menu* menu_ = new Menu();
    // Menu* menu_;

public:
    // constructor and destructor
    KitchenDemo();
    ~KitchenDemo();

    // getters and setters
    Kitchen* getKitchen();
    void setKitchen(Kitchen* kitchen);

    ConcreteOrderBuilder* getOrderBuilder();
    void setOrderBuilder(ConcreteOrderBuilder* orderBuilder);


    // other functions
    void test();
    void askTimePassed(Kitchen* kitchen);
    void addOrderBuilderItem();
    void addOrderBuilderModifier();
    void menuHandler();

    void displayMainMenu();
    void simulateTimePassed();
    void displayKitchenSnapshot();
    void displayMenu();

    void displayOrderBuilderMenu();
};

#endif // KITCHEN_DEMO_H