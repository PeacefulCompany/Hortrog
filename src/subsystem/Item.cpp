#include "Item.h"
void Item::add(Order*) {}
Item::Item(std::string menuItem, double price) : Order() {
    this->menuItem = menuItem;
    this->price = price;
}
std::string Item::printOrder() {
    std::string output = "";
    output += this->menuItem + " $" +
              std::to_string(this->price)
                  .substr(0, std::to_string(this->price).find(".") + 3) +
              "\nSpefications:\n";
    ;
    return output;
}
double Item::total() { return getCost() + this->price; }
