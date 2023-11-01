#pragma once
#include "FloorStaff.h"
#include "customer/CustomerState.h"
class Manager : public FloorStaff {
public:
    void checkKitcken();
    OrderBuilder* getOrderBuilder();
    void accapts(CustomerState state);

private:
    std::vector<Tables*> tables_;
};