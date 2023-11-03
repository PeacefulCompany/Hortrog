#pragma once

#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
private:
    std::string name;
    double cost;
    std::string diet;
    std::string mod;

public:
    Item(std::string, double cost, std::string diet, std::string mod);
    ~Item();

    std::string getName();
    double getCost();
    std::string getDiet();
    std::string getMod();
};

#endif // ITEM_H