#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <unordered_map>

struct Item {
	
	Item(const std::string& name, double price, const std::string& restrictions)
		: name(name), price(price), restrictions(restrictions) {}

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
        menuItems[name] = item;
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
        if (menuItems.find(name) != menuItems.end()) {
            return menuItems[name];
        } else {
            return Item("", 0, "");
        }
    }

private:
    std::unordered_map<std::string, Item> menuItems_;
};
