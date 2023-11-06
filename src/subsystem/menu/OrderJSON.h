#pragma once

#include "ItemJSON.h"
#include <string>
#include <vector>

class OrderJSON {
private:
    std::string order_;
    std::vector<ItemJSON*> items_;

public:
    OrderJSON(std::string order);
    ~OrderJSON(){};

    std::vector<ItemJSON*> getItems();
};