#include "order/ConcreteOrderBuilder.h"
#include "order_test/Modifier.h"
#include "order_test/OrderItem.h"
#include <memory>
#include <string>

void ConcreteOrderBuilder::begin() {
	this->tempOrder = std::vector<std::unique_ptr<Order>>();
}

bool ConcreteOrderBuilder::addItem(std::string key) {
	if(this->menu->getItem(key).getName() == "") { return false; }
	this->tempOrder.emplace_back(std::make_unique<OrderItem>(this->menu->getItem(key).getName(), this->menu->getItem(key).getPrice()));
	return true;
}

bool ConcreteOrderBuilder::addModifier(std::string key) {
	// Return false if the vector is empty
	if(this->tempOrder.empty()) { return false; } 
	// Save then remove the  last OrderItem in the vector
	std::unique_ptr<Order> lastOrder = std::move(this->tempOrder.back());
	this->tempOrder.pop_back();
	// Create a Modifier from the last OrderItem
	std::unique_ptr<Order> modifier = std::make_unique<Modifier>(std::move(lastOrder));
	// Add the modifier to the vector
	this->tempOrder.emplace_back(std::move(modifier));
	return true;
}

std::string ConcreteOrderBuilder::getResult() {
	// return empty string if the vector is empty
	if(this->tempOrder.empty()) { return "{}"; }

	// Create a new OrderComposite
	this->order = new OrderComposite();
	// Add all the Orders in the vector to the OrderComposite
	for(auto& order : this->tempOrder) {
		this->order->add(std::move(order));
	}
	// Return the OrderComposite as a JSON string
	return this->order->toJson();
}

void ConcreteOrderBuilder::setMenu(Menu* menu) { this->menu = menu; }

Menu* ConcreteOrderBuilder::getMenu() { return this->menu; }
