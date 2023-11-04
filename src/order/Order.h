#pragma once

#include <cstdint>
#include <memory>
#include <string>
#include <vector>

class Order {
private:
    std::string customer_;
    uint32_t tblId_;

    int tblId;
public:
    virtual void add(std::unique_ptr<Order>) = 0;
    virtual std::string toJson() = 0;
    virtual double total() = 0;
    virtual void setPrice(double){};
    virtual double getPrice() { return 0.0; };
    virtual std::vector<std::pair<std::string, double>>
    generateReceiptOrderList() = 0;
    inline virtual std::string getId() { return ""; };
    inline virtual void setTblId(uint32_t id) { tblId_ = id; };
    inline virtual uint32_t getTblId() { return tblId_; };
	inline virtual void setCustomer(std::string customer) { customer_ = customer; };
    inline std::string getCustomer() { return customer_; };
};
