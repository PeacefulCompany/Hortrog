#include "NullOrderBuilder.h"
#include <vector>

void NullOrderBuilder::newOrder() { orders_.emplace_back(std::vector<json>()); }
void NullOrderBuilder::addItem(const std::string& key) {
    json item = {
        {"key", key},
        {"modifiers", std::vector<std::string>()},
    };
    orders_.back().push_back(item);
}
void NullOrderBuilder::addModifier(const std::string& key) {
    orders_.back().back()["modifiers"].push_back(key);
}
