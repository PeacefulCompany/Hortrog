#pragma once
#include "menu/Menu.h"
#include "order/Order.h"
#include "order/OrderComposite.h"
#include "order/OrderItem.h"
#include "order/Modifier.h"
#include <sstream>
#include <string>
#include <vector>

class OrderBuilder {
	public:
		virtual ~OrderBuilder(){};
		virtual void begin() = 0;
		virtual bool addItem(std::string key) = 0;
		virtual bool addModifier(std::string key) = 0;
		virtual Menu * getMenu() = 0;
		virtual void setMenu(Menu * menu) = 0;
};