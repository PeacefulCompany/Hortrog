//ORDERH
#pragma once

#include "menu/Menu.h"
#include <cstdint>
#include <memory>
#include <string>
#include <utility>
#include <vector>

class Order {
protected:
    std::string customer_;
private:
    uint32_t tblId_;

public:
    virtual void add(std::unique_ptr<Order>) = 0;
    virtual std::string toJson() = 0;
    virtual double total() = 0;
    virtual std::vector<std::pair<std::string, double>>
    generateReceiptOrderList() = 0;
    inline virtual std::string getId() { return ""; };
    inline virtual void setTblId(uint32_t id) { tblId_ = id; };
    inline virtual uint32_t getTblId() { return tblId_; };
    inline virtual void setCustomer(std::string customer) {
        customer_ = std::move(customer);
    };
    virtual bool checkForCustomer(std::string customerName) = 0;
    virtual bool checkForDupe(std::string customerName, std::vector<MenuItem*> menuItems) = 0;
    virtual std::vector<MenuItem *> getAllMenuItems()=0;
    inline std::string getCustomer() { return customer_; };

    virtual ~Order() = default;
};
