#include "demo/WaiterDemo.h"

void CustomerWaiterPOS() {
    WaiterDemo* waiterDemo = new WaiterDemo();
    waiterDemo->addCustomers();
    waiterDemo->placeCustomers();
    waiterDemo->customerOrder();
}

int main() {
    CustomerWaiterPOS();
    return 0;
}