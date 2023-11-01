#pragma once
//! #include "menu/Menu.h"
#include "order_test/Order.h"
#include "order_test/OrderComposite.h"
#include "order_test/OrderItem.h"
#include "order_test/Modifier.h"
#include <sstream>
#include <string>
#include <vector>

// actual
//===============
// temp
#include <string>
#include <sstream>
#include <iostream>
#include <unordered_map>
#include <fstream>
#include "nlohmann/json.hpp"


struct Item {
	
	Item(const std::string& name, double price, const std::string& restrictions)
		: name(name), price(price), restrictions(restrictions) {}
	//default constructor
	Item() : name(""), price(0), restrictions("") {}
	std::string getName() const { return name; }
	double getPrice() const { return price; }
	std::string getRestrictions() const { return restrictions; }

    private:
        std::string name;
        double price;
        std::string restrictions;
};

class Menu {
public:
	Menu();
	//function to initialise the menu from the .json file
	void initMenu();
	/**
	* @brief Add an item to the menu.
	*
	* This function adds an item to the menu with the provided name and details.
	*
	* @param name The name of the item.
	* @param item The item to be added to the menu.
	*
	* @return void
	*/
    void addItem(const std::string& name, const Item& item) {
        menuItems_[name] = item;
    }
	/**
	* @brief Get the Item object.
	* 
	* This function returns the item with the provided name.
	*
	* @param name The name of the item.
	* @return Item 
	*/
    Item getItem(const std::string& name) {
        if (menuItems_.find(name) != menuItems_.end()) {
            return menuItems_[name];
        } else {
            return Item("", 0, "");
        }
    }

	std::string toString() {
		std::stringstream ss;
		for (auto& item : menuItems_) {
			ss << item.second.getName() << " " << item.second.getPrice() << " " << item.second.getRestrictions() << std::endl;
		}
		return ss.str();
	}

private:
    std::unordered_map<std::string, Item> menuItems_;
};


//=============
// actual

class OrderBuilder {
	public:
		virtual ~OrderBuilder(){};
		virtual void begin() = 0;
		virtual bool addItem(std::string key) = 0;
		virtual bool addModifier(std::string key) = 0;
		virtual Menu * getMenu();
		virtual void setMenu(Menu * menu);
};