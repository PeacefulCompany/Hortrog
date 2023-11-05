#include "NullOrderBuilder.h"
#include <vector>

void NullOrderBuilder::begin() { orders_.emplace_back(std::vector<json>()); }
bool NullOrderBuilder::addItem(const std::string& key) {
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
