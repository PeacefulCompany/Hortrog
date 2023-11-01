#include "Waiter.h"
#include <string>
Waiter::Waiter(int x, int y, int icon_) : Object(x, y, icon_) {}
Waiter::~Waiter() {}
void Waiter::TakeOrder(vector<string> CustomerList) {
    string input = "{ \"Customers\": [";
    for (int i = 0; i < CustomerList.size(); i++) {
        input += "\"" + CustomerList[i] + "\"";
        if (i != CustomerList.size() - 1) {
            input += ", ";
        }
    }
    input += "] }";
    this->currentOrder_ = json::parse(input);
}
void Waiter::ServeOrder() {
    cout << "Serving order: " << this->currentOrder_.dump() << endl;
}
json Waiter::placeOrder() { return this->currentOrder_; }

void Waiter::offerBill() { cout << "Offering bill" << endl; }
sf::FloatRect Waiter::getBoundingBox() const { return sf::FloatRect(); }
sf::Vector2f Waiter::position() const { return sf::Vector2f(); }
void Waiter::position(sf::Vector2f v) {}
void Waiter::draw(sf::RenderTarget& window) const {}