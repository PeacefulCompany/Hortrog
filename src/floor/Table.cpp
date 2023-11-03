#include "Table.h"

#include "CustomerIterator.h"
#include "floor/Table.h"

CustomerIterator* Table::createIterator() { return new CustomerIterator(this); }