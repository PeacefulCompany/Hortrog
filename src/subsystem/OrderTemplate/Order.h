#pragma once

#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <iostream>

class Order
{
    public:

    //constructors and destructors

    Order(std::string customer);
    Order();
    ~Order();
 
    //functions
    void add(Order* order);
    std::string toJson();
    double total();

    //getters and setters
    std::string getCustomer() const;
    void setCustomer(std::string customer);

    private:
    
    //attributes
    std::string customer;   

    //functions

};


#endif // ORDER_H