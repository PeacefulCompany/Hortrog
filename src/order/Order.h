#pragma once

#include <string>
#include <memory>

class Order{
private:
    std::string customer;
    int tblId;
public:
    virtual void add(std::unique_ptr<Order>) = 0;
    virtual std::string toJson() = 0;
    virtual double total() = 0;
    virtual void setTblId(int id){this->tblId = id;};
    virtual int getTblId(){return tblId;};
};
