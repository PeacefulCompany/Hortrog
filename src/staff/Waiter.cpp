#include "Waiter.h"
#include "customer/Customer.h"
#include "floor/CustomerIterator.h"
#include "floor/Floor.h"
#include "floor/Table.h"
#include "order/ConcreteOrderBuilder.h"
#include "order/OrderBuilder.h"
#include "order/OrderComposite.h"
#include "staff/FloorStaff.h"
#include "staff/Manager.h"
#include "staff/Waiter.h"
#include "subsystem/Chef/Kitchen.h"
#include <iostream>
#include <vector>

/**
 * @brief Initialize the static member kitchen_ with nullptr.
 *
 * This ensures that all instances of FloorStaff share the same Kitchen
 * instance. Before using this, make sure to set the Kitchen instance using->
 * FloorStaff::setKitchen(new Kitchen());
 */
Kitchen* FloorStaff::kitchen_ = nullptr;

Waiter::Waiter(const Menu* menu) : FloorStaff(), menu_(menu) {
    FloorStaff::setKitchen(new Kitchen());
    this->orderBuilder_ = std::make_unique<ConcreteOrderBuilder>(menu);
}
void Waiter::checkKitchen() {
    if (getReadyMeals().size() > 0) {
        for (auto& Table : tables_) {
            CustomerIterator* iterator = new CustomerIterator(Table);
            while (!iterator->isDone()) {
                for (auto& meal : readyMeals) {
                    if (meal->getCustomer() == iterator->get()->getName()) {
                        giveFoodToCustomer(*iterator->get());
                    }
                }
            }
        }
        readyMeals.clear();
    } else {
        FetchMeals();
    }
}
std::vector<Meal*> Waiter::getReadyMeals() { return this->readyMeals; }
void Waiter::FetchMeals() {
    Meal* currentMeal;
    int x = 0;
    do {
        currentMeal = FloorStaff::getKitchen()->getOrder(tables_[x]->id());
        x++;
    } while (currentMeal == nullptr && x < tables_.size());
    if (x == tables_.size()) return;
    if (currentMeal != nullptr) {
        for (auto& table : tables_) {
            if (table->id() == currentMeal->getTableId()) {
                readyMeals.push_back(currentMeal);
            }
        }
    }
}
void Waiter::Givetokitchen() {
    FloorStaff::getKitchen()->handleOrder(orderBuilder_->getOrder());
}
void Waiter::giveFoodToCustomer(Customer& customer) {
    std::string customerName = customer.getName();
    if (!this->readyMeals.empty()) {
        for (auto& meal : readyMeals) {
            if (meal->getCustomer() == customerName) {
                Meal* CustomerMeal = meal;
                customer.receiveMeal(meal);
            }
        }
    }
}
void Waiter::callManager(CustomerState& state) {
    std::cout << "Manager called" << std::endl;
    Manager* manager = new Manager();
    std::cout << "I am the manager!" << std::endl;
    manager->accept(state);
    delete manager;
}
void Waiter::accept(CustomerState& state) { state.visit(*this); }
std::string Waiter::getStaffType() { return "Waiter"; }
