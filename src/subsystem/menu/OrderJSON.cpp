#include "OrderJSON.h"
#include <json.hpp>
using json = nlohmann::json ;

OrderJSON::OrderJSON(std::string order)
{
    this->order = order;

}

std::vector<Item*> OrderJSON::getItems()
{
    json data = json::parse(order);


    for (auto& item : data["order"]) {
        // std::cout << "[DEBUG] Iterating through items..." << std::endl;
        std::string name = item["name"].get<std::string>();
        double price = item["price"].get<double>();

        Item* newItem;

        if(item.contains("diet"))
        {
            std::string restrictions = item["diet"].get<std::string>();
            newItem = new Item(name, price, restrictions);
        }
        else 
        {
            newItem = new Item(name, price, "none");
        }

        items.push_back(newItem);
    }

    return items;
}
