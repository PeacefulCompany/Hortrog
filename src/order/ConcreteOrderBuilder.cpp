#include "order/ConcreteOrderBuilder.h"
#include "order_test/Modifier.h"
#include "order_test/OrderItem.h"
#include <string>

void ConcreteOrderBuilder::begin() {
	this->orderTemp = new std::vector<std::shared_ptr<Order>>();
}

bool ConcreteOrderBuilder::addItem(std::string key) {
	if (this->menu->getItem(key).getName() != "") {
	
	}
	// Add item to orderTemp from Menu
	this->orderTemp->emplace_back(std::make_shared<Order>(new OrderItem(this->menu->getItem(key).getName(), this->menu->getItem(key).getPrice())));
	return true;
}

bool ConcreteOrderBuilder::addModifier(std::string key) {
	// Add a modifier to the last item in orderTemp
	// create a new order item with the same name and price as the last item in orderTemp
	return true;
}

std::string ConcreteOrderBuilder::getResult() {
	// Add all teh orders in orderTemp to order
	for (auto order : *this->orderTemp) {
		this->order->add(order);
	}
	// return the json representation of order
	return this->order->toJson();
}

void ConcreteOrderBuilder::setMenu(Menu* menu) { this->menu = menu; }

Menu* ConcreteOrderBuilder::getMenu() { return this->menu; }
