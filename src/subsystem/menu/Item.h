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
    Item(std::string, double cost, std::string diet) {
        this->name = name;
        this->cost = cost;
        this->diet = diet;
    };
    ~Item();

    std::string getName() const{return name;};
    double getCost() const{return cost;};
    std::string getDiet() const{return diet;};
};

#endif // ITEM_H