#include "Manager.h"
void Manager::checkKitcken() { cout << "kitchen check..." << endl; }
OrderBuilder* Manager::getOrderBuilder() {
    cout << "Get Generated Order..." << endl;
    return NULL;
}
void Manager::accept(CustomerState& state) { state.visit(*this); }