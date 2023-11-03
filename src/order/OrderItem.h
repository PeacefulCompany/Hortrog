#pragma once

#include "Order.h"

class OrderItem : public Order {
protected:
    std::vector<std::pair<std::string, double>>
    generateReceiptOrderList() override;

private:
    std::string id_;
    double price_;

public:
    std::string toJson() override;
    double total() override;
    void add(std::unique_ptr<Order>) override;
    OrderItem(std::string id, double price);
    void setPrice(double price) override;
    double getPrice();
    std::string getId();
};