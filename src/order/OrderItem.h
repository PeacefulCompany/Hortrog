#pragma once

#include "Order.h"
#include "menu/Menu.h"

class OrderItem : public Order {

public:
    OrderItem(const MenuItem* item);

    std::string toJson() override;
    double total() override;
    void add(std::unique_ptr<Order>) override;
    std::string getId() override;
    bool checkForCustomer(std::string customerName) override;
    bool checkForDupe(std::string customerName, std::vector<MenuItem*> menuItems) override;

protected:
    std::vector<std::pair<std::string, double>>
    generateReceiptOrderList() override;

private:
    const MenuItem* item_;
};