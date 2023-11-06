#include "order/ConcreteOrderBuilder.h"
#include "order/OrderComposite.h"
#include <iostream>
#include <memory>
#include <string>

void ConcreteOrderBuilder::begin(uint32_t tblId) {
    this->tempOrder = std::vector<std::unique_ptr<Order>>();
    this->tblId_ = tblId;
}

bool ConcreteOrderBuilder::addItem(
    const std::string& key, const std::string& customerName) {
    std::cout << "testing addItem1" << std::endl;
    if (this->menu_->getMenuItem(key) == nullptr) {
        std::cout << "Input for order is empty string, therefore error"
                  << std::endl;
        return false;
    }
    std::cout << "testing addItem2" << std::endl;
    // this->customerNames_.emplace_back(customerName);
    this->tempOrder.emplace_back(
        std::make_unique<OrderItem>(this->menu_->getMenuItem(key)));
    std::cout << "Customer name is 1.0 : " << customerName << std::endl;
    this->tempOrder.back()->setCustomer(customerName);
    std::cout << "Customer name is: " << this->tempOrder.back()->getCustomer()
              << std::endl;
    this->tempOrder.back()->setTblId(this->tblId_);
    return true;
}

bool ConcreteOrderBuilder::addModifier(const std::string& key) {
    // Return false if the vector is empty
    if (this->tempOrder.empty()) {
        return false;
    }
    // Save then remove the  last OrderItem in the vector
    std::unique_ptr<Order> lastOrder = std::move(this->tempOrder.back());
    std::string name = lastOrder->getCustomer();
    this->tempOrder.pop_back();
    // Create a Modifier from the last OrderItem
    std::unique_ptr<Order> modifier =
        std::make_unique<Modifier>(std::move(lastOrder));
    modifier->setCustomer(
        name); // I think this is unnecessary, as modifier has the order in it
    // Add the modifier to the vector
    this->tempOrder.emplace_back(std::move(modifier));
    return true;
}

OrderComposite* ConcreteOrderBuilder::getOrder() {
    // return empty string if the vector is empty
    if (this->tempOrder.empty()) {
        return nullptr;
    }
    OrderComposite* result = new OrderComposite();
    // Add all the Orders in the vector to the OrderComposite
    for (auto& order : this->tempOrder) {
        result->add(std::move(order));
    }
    // Return the OrderComposite as a JSON string
    result->setTblId(this->tblId_);
    return result;
};

ConcreteOrderBuilder::ConcreteOrderBuilder(const Menu* menu)
    : OrderBuilder(), menu_(menu) {}

std::string ConcreteOrderBuilder::getResult() {
    OrderComposite* res = getOrder();
    if (!res) return "{}\n";
    std::string json = res->toJson();
    delete res;
    return json;
}
