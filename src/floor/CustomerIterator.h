#pragma once

#include "customer/Customer.h"

#include "Table.h"
#include <vector>

class CustomerIterator {
public:
    CustomerIterator(Table* table);

    void next();
    bool isDone() const;
    Customer* get() const;

private:
    std::vector<TableComponent*> tables_;
    size_t currentTable_ = 0;
    size_t currentIndex_ = 0;
};