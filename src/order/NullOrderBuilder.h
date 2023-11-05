#pragma once

#include "OrderBuilder.h"
#include <vector>

#include "nlohmann/json.hpp"
using json = nlohmann::json;

class NullOrderBuilder : public OrderBuilder {
public:
    void begin(uint32_t table) override;
    bool addItem(const std::string& key, const std::string& customer) override;
    bool addModifier(const std::string& key) override;

    void setMenu(const Menu* menu) override {}
    const Menu* getMenu() const override { return nullptr; }

    inline const std::vector<json>& getResult() { return orders_; }

private:
    std::vector<json> orders_;
};