#include "POSStrategy.h"
#include <set>
int POSStrategy::countCustomers(std::vector<Order*> orders) {
    std::set<std::string> customerNames;
    orders = orders.at(0)->getChildren();
    for (auto order : orders) {
        customerNames.insert(order->getCustomer());
    }
    return customerNames.size();
}
