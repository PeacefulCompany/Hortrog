#include "CustomerIterator.h"

#include "TableComponent.h"

CustomerIterator::CustomerIterator(Table* table) : tables_(table->split()) {}

void CustomerIterator::next() {
    if (isDone()) return;
    currentIndex_++;

    // At the end of the current table
    if (currentIndex_ >= tables_[currentTable_]->customers_.size()) {
        currentIndex_ = 0;
        do {
            currentTable_++;
        } while (!isDone() && tables_[currentTable_]->customers_.size() == 0);
    }
}

bool CustomerIterator::isDone() const {
    if (currentTable_ < tables_.size()) return false;
    return true;
}

Customer* CustomerIterator::get() const {
    return tables_[currentTable_]->customers_[currentIndex_];
}
