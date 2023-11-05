#pragma once

#include "Order.h"
#include "menu/Menu.h"

class OrderItem : public Order {

public:
    OrderItem(MenuItem* item);

    std::string toJson() override;
    double total() override;
    void add(std::unique_ptr<Order>) override;
    std::string getId() override;

protected:
    std::vector<std::pair<std::string, double>>
    generateReceiptOrderList() override;

private:
    MenuItem* item_;
};