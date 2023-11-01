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
json Waiter::placeOrder() { return this->currentOrder_; }
void Waiter::ServeOrder() {
    cout << "Serving order: " << this->currentOrder_.dump() << endl;
}