#pragma once

#include <string>

class OrderBuilder {
public:
    virtual void newOrder() = 0;
    virtual void addItem(const std::string& key) = 0;
    virtual void addModifier(const std::string& key) = 0;
};