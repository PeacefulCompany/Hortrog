#pragma once

#ifndef ITEM_H
#define ITEM_H

#include <string>

class ItemJSON {
private:
    std::string name_;
    double cost_;
    std::string diet_;
    std::string mod_;
    std::string customer_;

public:
    ItemJSON(std::string, double cost, std::string diet, std::string mod, std::string customer);
    ~ItemJSON();

    std::string getName();
    double getCost();
    std::string getDiet();
    std::string getMod();
    std::string getCustomer();
    std::string toString();
};

#endif // ITEM_H