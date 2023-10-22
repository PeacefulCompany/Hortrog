#pragma once
#include "Modifier.h"
class Pescetarian : public Modifier {
public:
    Pescetarian(Order* order);
    std::string printOrder();

private:
    const std::string spesification = "Pescetarian";
    const double price = 1.00;
};