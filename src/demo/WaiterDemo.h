#pragma once

#include "../src/staff/Waiter.h"
#include "billing/PointOfSales.h"
#include "customer/Customer.h"
#include "customer/CustomerState.h"
#include "floor/TableComponent.h"

class WaiterDemo {
public:
    WaiterDemo();
    void addCustomers();
    void placeCustomers();
    void changeCustomerState(int);
    void customerOrder();

private:
    std::vector<Customer*> customers_;
    TableComponent* table_;
    Kitchen* kitchen_;
    Waiter* waiter_;
    Menu* menu_;
    PointOfSales* pointOfSales_;
};