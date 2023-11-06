#pragma once
#include "POSStrategy.h"
class OneReceipt : public POSStrategy {
    std::vector<Receipt> getReceipts(std::vector<Order*> orders) override;
};
