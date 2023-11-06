// MODH
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
    std::vector<Order*> getChildren() {
        std::vector<Order*> ret;
        return ret;
    };

    Modifier(std::unique_ptr<Order> component);
    void add(std::unique_ptr<Order>) override {}
    double total() override;
    std::string toJson() override;
    explicit Modifier(std::unique_ptr<Order> component, std::string key);
    bool checkForCustomer(std::string customerName) override;
    bool checkForDupe(std::string customerName,
        std::vector<const MenuItem*> menuItems) override;
    std::vector<const MenuItem*> getAllMenuItems() override;
    inline std::string getKey() { return key_; }
    inline void setKey(std::string key) { key_ = key; }

    std::string toString() const override;
};