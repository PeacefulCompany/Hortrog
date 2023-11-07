#include "order/ConcreteOrderBuilder.h"

#include "order/OrderComposite.h"

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
    std::unique_ptr<Order> lastOrder = std::move(this->tempOrder.back());
    std::string name = lastOrder->getCustomer();
    this->tempOrder.pop_back();

    // Create a Modifier from the last OrderItem
    std::unique_ptr<Modifier> modifier =
        std::make_unique<Modifier>(std::move(lastOrder));
  
    // I think this is unnecessary, as modifier has the order in it
    modifier->setCustomer(name);
    modifier->setKey(key);

    // Add the modifier to the vector
    tempOrder.emplace_back(std::move(modifier));
    return true;
}

OrderComposite* ConcreteOrderBuilder::getOrder() {

    if (tempOrder.empty()) return nullptr;

    OrderComposite* result = new OrderComposite();
    std::string customer = tempOrder.back()->getCustomer();
    // Add all the Orders in the vector to the OrderComposite
    for (auto& order : tempOrder) {
        result->add(std::move(order));
    }
    tempOrder.clear();

    // Return the OrderComposite as a JSON string
    result->setTblId(tblId_);
    result->setCustomer(customer);
    return result;
};

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
    OrderComposite* res = getOrder();
    if (!res) return "{}\n";
    std::string json = res->toJson();
    delete res;
    return json;

}
