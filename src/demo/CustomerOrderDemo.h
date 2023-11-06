#pragma once
#include "core/Application.h"
#include "customer/Customer.h"
#include "CustomerOrderDemo.h"
#include "menu/Menu.h"
#include <iostream>
#include <memory>
#include <vector>
class CustomerOrderDemo : Application{
public:
    void gameLoop() override{};
    void init() override;
    void cleanup() override{};
    bool shouldQuit() const override{return true;};
private:
    std::vector<std::unique_ptr<Customer>> customers_;
};



