#include "OrderBuilder.h"
#include "Item.h"
#include "Menu.h"
#include "Tab.h"
#include <iostream>
#include <memory>
#include <random>
OrderBuilder::OrderBuilder(int tablenumber) : tablenumber(tablenumber) {
    Menu menu;
}
void OrderBuilder::build() {
    CreateTab(tablenumber);
    AddItem();
}
void OrderBuilder::CreateTab(int tablenumber) {
    this->newOrder = std::make_unique<Tab>(this->tablenumber);
}
void OrderBuilder::AddItem() {
    std::string name;
    double price;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10);
    int randomNum = dis(gen);
    for (int i = 0; i < randomNum; i++) {
        name = Menu::getRandomItem();
        price = Menu::getPrice(name);
        std::unique_ptr<Item> newItem = std::make_unique<Item>(name, price);
        this->newOrder->add(std::move(newItem));
    }
}
std::unique_ptr<Order> OrderBuilder::GetResult() {
    return std::move(this->newOrder);
}
