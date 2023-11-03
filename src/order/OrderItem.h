#pragma once

#include "Order.h"

class OrderItem : public Order {
protected:
    std::vector<std::string> generateReceiptOrderList() override;

private:
    std::string id;
    double price;

public:
    std::string toJson() override;
    double total() override;
    void add(std::unique_ptr<Order>) override;
    OrderItem(std::string id, double price);
    void setPrice(double price);
    double getPrice();
    std::string getId();
};