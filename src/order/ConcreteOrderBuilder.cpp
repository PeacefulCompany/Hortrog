#include "order/ConcreteOrderBuilder.h"
#include "order/Modifier.h"
#include <iostream>
#include <memory>
#include <sstream>
#include <string>

void ConcreteOrderBuilder::begin(uint32_t tblId) {
    tempOrder = std::vector<std::unique_ptr<Order>>();
    tblId_ = tblId;
}

bool ConcreteOrderBuilder::addItem(
    const std::string& key, const std::string& customerName) {

    const MenuItem* item = menu_->getMenuItem(key);
    if (!item) return false;

    tempOrder.emplace_back(std::make_unique<OrderItem>(item));
    tempOrder.back()->setCustomer(customerName);
    tempOrder.back()->setTblId(tblId_);

    return true;
}

bool ConcreteOrderBuilder::addModifier(const std::string& key) {
    if (tempOrder.empty()) return false;

    // Save then remove the  last OrderItem in the vector
    std::unique_ptr<Order> lastOrder = std::move(tempOrder.back());
    tempOrder.pop_back();

    std::string name = lastOrder->getCustomer();

    // Create a Modifier from the last OrderItem
    std::unique_ptr<Modifier> modifier =
        std::make_unique<Modifier>(std::move(lastOrder));
    modifier->setCustomer(name);
    modifier->setKey(key);

    // Add the modifier to the vector
    tempOrder.emplace_back(std::move(modifier));
    return true;
}

std::string ConcreteOrderBuilder::toString() const {
    std::stringstream ss;
    ss << "ConcreteOrderBuilder";
    for (auto& order : tempOrder) {
        ss << "\n- " << order->toString();
    }
    return ss.str();
}

ConcreteOrderBuilder::ConcreteOrderBuilder(const Menu* menu)
    : OrderBuilder(), menu_(menu) {}

std::string ConcreteOrderBuilder::getResult() {
    // return empty string if the vector is empty
    if (tempOrder.empty()) {
        return "{}\n";
    }
    // Create a new OrderComposite
    order = new OrderComposite();
    // Add all the Orders in the vector to the OrderComposite
    for (auto& order : tempOrder) {
        order->add(std::move(order));
    }
    // Return the OrderComposite as a JSON string
    order->setTblId(tblId_);
    return order->toJson();
}
