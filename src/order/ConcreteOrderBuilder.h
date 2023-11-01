#pragma once
#include "order/OrderBuilder.h"
#include "order_test/Order.h"
#include "order_test/OrderComposite.h"

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
		std::vector<std::shared_ptr<Order>> * orderTemp;
		OrderComposite * order;
};