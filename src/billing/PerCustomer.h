#pragma once
#include "POSStrategy.h"
class PerCustomer : public POSStrategy{
    std::vector<Receipt> getReceipts(std::vector<Order*> orders) override;
};
