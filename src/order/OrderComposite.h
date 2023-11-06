//ORDERCOMPH
#pragma once

#include "Order.h"
#include <string>
#include <vector>

class OrderComposite : public Order {
protected:
    std::vector<std::pair<std::string, double>>
    generateReceiptOrderList() override;

private:
    std::vector<std::unique_ptr<Order>> orders_;

public:
    void add(std::unique_ptr<Order> order) override;
    std::string toJson() override;
    double total() override;
    std::string getId() override { return ""; };
    bool checkForCustomer(std::string customerName) override;
    bool checkForDupe(std::string customerName, std::vector<const MenuItem*> menuItems) override;
    std::vector<const MenuItem *> getAllMenuItems() override;
};