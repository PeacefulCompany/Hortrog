#pragma once
#include "FloorStaff.h"
#include "customer/Customer.h"
#include "customer/CustomerState.h"
#include "order/OrderBuilder.h"

class Waiter : public FloorStaff {
public:
    void checkKitcken();
    OrderBuilder* getOrderBuilder();
    void accapts(CustomerState state);

private:
    Kitchen* kitchen_;
    PointOfSales* pointOfSales_;
    std::vector<Tables*> tables_;
    unique_ptr<OrderBuilder> orderBuilder_;
};