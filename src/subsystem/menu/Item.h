#pragma once

#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
private:
    std::string name;
    double cost;
    std::string diet;

public:
    Item(std::string, double cost, std::string diet);
    ~Item();

    std::string getName();
    double getCost();
    std::string getDiet();
};

#endif // ITEM_H