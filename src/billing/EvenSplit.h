#pragma once
#include "POSStrategy.h"
class EvenSplit : public POSStrategy{
    std::vector<Receipt> getReceipts(std::vector<Order*> orders) override;
};
