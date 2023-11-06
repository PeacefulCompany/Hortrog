#pragma once
#include "order/Receipt.h"
#include <vector>
class POSStrategy {
protected:
    virtual int countCustomers(std::vector<Order*> orders);

public:
    virtual std::vector<Receipt> getReceipts(std::vector<Order*> orders) = 0;
    virtual ~POSStrategy() = default;
};
