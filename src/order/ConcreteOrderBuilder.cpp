#include "order/ConcreteOrderBuilder.h"

void ConcreteOrderBuilder::begin() {}

bool ConcreteOrderBuilder::addItem(std::string key) {
    // TODO - implement ConcreteOrderBuilder::addItem
    throw "Not yet implemented";
}

bool ConcreteOrderBuilder::addModifier(std::string key) {
    // TODO - implement ConcreteOrderBuilder::addModifier
    throw "Not yet implemented";
}

void ConcreteOrderBuilder::setMenu(Menu* menu) { this->menu = menu; }

Menu* ConcreteOrderBuilder::getMenu() { return this->menu; }
