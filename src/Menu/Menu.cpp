#include "menu/Menu.h"
using json = nlohmann::json ;

Menu::Menu()
{
	std::string path = "menu_items.json";
	std::ifstream file("assets/" + path);
    if (!file.is_open()) {
        std::cout << "Cannot open asset" << std::endl;
        return;
    }
    json data = json::parse(file);

	for (auto& item : data["items"]) {
		std::string name = item["name"].get<std::string>();
		double price = item["price"].get<double>();
		std::string restrictions = item["restrictions"].get<std::string>();
		addItem(name, Item(name, price, restrictions));
	}

	//print all items as debug
	for (auto& item : menuItems_) {
		std::cout << item.second.getName() << std::endl;
		std::cout << item.second.getPrice() << std::endl;
		std::cout << item.second.getRestrictions() << std::endl;
	}
}