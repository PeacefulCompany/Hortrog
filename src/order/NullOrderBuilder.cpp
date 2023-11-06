#include "NullOrderBuilder.h"
#include "nlohmann/json.hpp"
#include <vector>

void NullOrderBuilder::begin(uint32_t table) {
    orders_.emplace_back(std::vector<json>());
}
bool NullOrderBuilder::addItem(
    const std::string& key, const std::string& customer) {
    json item = {
        {"key", key},
        {"modifiers", std::vector<std::string>()},
    };
    orders_.back().push_back(item);
    return true;
}
bool NullOrderBuilder::addModifier(const std::string& key) {
    orders_.back().back()["modifiers"].push_back(key);
    return true;
}

std::string NullOrderBuilder::toString() const {
    std::stringstream ss;
    ss << "NullOrderBuilder";
    for (const json& j : orders_) {
        ss << "\n- " << nlohmann::to_string(j);
    }
    return ss.str();
}
