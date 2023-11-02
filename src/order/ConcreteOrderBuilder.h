#pragma once
#include "order/OrderBuilder.h"
#include "order/Order.h"
#include "order/OrderComposite.h"
#include "order/Modifier.h"
#include "order/OrderItem.h"

class ConcreteOrderBuilder : public OrderBuilder {
	public:
		std::string getResult();
		void begin();
		bool addItem(std::string key);
		bool addModifier(std::string key);
		Menu * getMenu();
		void setMenu(Menu * menu);
	private:
		Menu * menu;
		std::vector<std::unique_ptr<Order>> tempOrder;
		OrderComposite * order;
};