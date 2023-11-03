#pragma once

#ifndef MENU_H
#define MENU_H

#include "Item.h"
#include <string>
#include <vector>

class OrderJSON {
private:
    std::string order_;
    std::vector<Item*> items_;

public:
    OrderJSON(std::string order);
    ~OrderJSON(){};

    std::vector<Item*> getItems();
};

#endif // MENU_H