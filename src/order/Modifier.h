//MODH
#pragma once

#include "Order.h"
#include "OrderItem.h"

class Modifier : public Order {
protected:
    std::unique_ptr<Order> component_;
    std::string key_;
    double price_;
    std::vector<std::pair<std::string, double>>
    generateReceiptOrderList() override;

public:
    Modifier(std::unique_ptr<Order> component);
    void add(std::unique_ptr<Order>) override {}
    double total() override;
    std::string toJson() override;
    explicit Modifier(std::unique_ptr<Order> component, std::string key);
    bool checkForCustomer(std::string customerName) override;
    bool checkForDupe(std::string customerName, std::vector<MenuItem*> menuItems) override;
};