#pragma once

#include "OrderBuilder.h"
#include <vector>

#include "nlohmann/json.hpp"
using json = nlohmann::json;

class NullOrderBuilder : public OrderBuilder {
public:
    void newOrder() override;
    void addItem(const std::string& key) override;
    void addModifier(const std::string& key) override;

    inline const std::vector<json>& getResult() { return orders_; }

private:
    std::vector<json> orders_;
};