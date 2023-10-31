#pragma once
#include "order/OrderBuilder.h"

class ConcreteOrderBuilder : public OrderBuilder {
	public:
		//! OrderComposite * getResult();
		void begin();
		bool addItem(std::string key);
		bool addModifier(std::string key);
		Menu * getMenu();
		void setMenu(Menu * menu);
	private:
		Menu * menu;
};