#include "Waiter.h"

#include "floor/Table.h"
#include "customer/Customer.h"
#include "order/ConcreteOrderBuilder.h"
#include "order/OrderBuilder.h"
#include "order/OrderComposite.h"
#include "staff/FloorStaff.h"
#include "staff/Manager.h"
#include "staff/Waiter.h"
#include "subsystem/Chef/Kitchen.h"

#include "floor/CustomerIterator.h"
#include <sstream>

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
    // ckeck if the waiter is currenlty holdy any ready meals
    if (getReadyMeals().size() > 0) {
        // if so then deliver them
        for (auto& meal : readyMeals) {
            // std::cout << "Delivering meal to table " << meal->tableId()
            //    << std::endl;
            // tables_[meal->tableId()]->deliverMeal(meal);
        }
        readyMeals.clear();
    } else // if not then check the kitchen for any ready meals
    {
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
    if (currentMeal != nullptr) readyMeals.push_back(currentMeal);
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
std::string Waiter::toString() const {
    std::stringstream ss;
    ss << "Waiter (";
    for (int i = 0; i < tables_.size(); i++) {
        if (i != 0) ss << ", ";
        ss << tables_[i]->id();
    }
    if (tables_.size() == 0) {
        ss << "no tables";
    }
    ss << ")";
    return ss.str();
}
void Waiter::assignTable(Table* table) { tables_.push_back(table); }
void Waiter::visitTables() {
    for (Table* table : tables_) {
        CustomerIterator* it = table->createIterator();
        while (!it->isDone()) {
            it->get()->interact(*this);
            it->next();
        }
    }
}
void Waiter::callManager(CustomerState& state) {
    std::cout << "Manager called" << std::endl;
    Manager* manager = new Manager();
    std::cout << "I am the manager!" << std::endl;
    manager->accept(    state);
    delete manager;
}
void Waiter::accept(CustomerState& state) { state.visit(*this); }
std::string Waiter::getStaffType() { return "Waiter"; }
