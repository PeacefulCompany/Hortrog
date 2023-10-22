#pragma once
#include "Modifier.h"
class GlutenFree : public Modifier {
public:
    GlutenFree(Order* order);
    std::string printOrder();
private:
    const std::string spesification = "Gluten Free";
    const double price = 1.00;
};
