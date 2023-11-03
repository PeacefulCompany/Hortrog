#include "Item.h"

Item::Item(std::string name, double cost, std::string diet, std::string mod) {
    this->name = name;
    this->cost = cost;
    this->diet = diet;
    this->mod = mod;
}


Item::~Item() {}

std::string Item::getName() { return name; }

double Item::getCost() { return cost; }

std::string Item::getDiet() { return diet; }

std::string Item::getMod() { return mod; }
