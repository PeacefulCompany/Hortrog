#pragma once

#ifndef MENU_H
#define MENU_H

#include "Item.h"
#include <string>
#include <vector>

class OrderJSON {
private:
    std::string order;
    std::vector<Item*> items;

public:
    OrderJSON(std::string order);
    ~OrderJSON();

    std::vector<Item*> getItems();
};

#endif // MENU_H