#include "POSStrategy.h"
#include <set>
int POSStrategy::countCustomers(std::vector<Order*> orders) {
    std::set<std::string> customerNames;
    for (auto order : orders) {
        customerNames.insert(order->getCustomer());
    }
    return customerNames.size();
}
