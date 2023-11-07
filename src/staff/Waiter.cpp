#include "Waiter.h"

#include "billing/EvenSplit.h"
#include "billing/OneReceipt.h"
#include "billing/PerCustomer.h"
#include "billing/PointOfSales.h"

#include "customer/Customer.h"
#include "floor/CustomerIterator.h"
#include "floor/Floor.h"
#include "floor/Table.h"
#include "order/ConcreteOrderBuilder.h"
#include "order/OrderBuilder.h"
#include "order/OrderComposite.h"
#include "order/Receipt.h"
#include "staff/FloorStaff.h"
#include "staff/Manager.h"
#include "staff/Waiter.h"
#include "subsystem/Chef/Kitchen.h"
#include <iostream>
#include <string>
#include <vector>

/**
 * @brief Initialize the static member kitchen_ with nullptr.
 *
 * This ensures that all instances of FloorStaff share the same Kitchen
 * instance. Before using this, make sure to set the Kitchen instance using->
 * FloorStaff::setKitchen(new Kitchen());
 */
Kitchen* FloorStaff::kitchen_ = nullptr;

Waiter::Waiter(
    const Menu* menu, const Floor* floor, Kitchen* kitchen, PointOfSales* pos)
    : FloorStaff(), menu_(menu), floor_(floor), pointOfSales_(pos),
      kitchen_(kitchen) {
    FloorStaff::setKitchen(new Kitchen());
    this->orderBuilder_ = std::make_unique<ConcreteOrderBuilder>(menu);
}

void Waiter::serveMeals() {
    for (auto& table : tables_) {
        CustomerIterator* iterator = new CustomerIterator(table);
        while (!iterator->isDone()) {
            Customer& currentCustomer = *iterator->get();
            for (auto& meal : readyMeals) {
                if (meal->getCustomer() == currentCustomer.getName()) {
                    giveFoodToCustomer(currentCustomer);
                }
            }
            iterator->next();
        }
        delete iterator;
    }
}
void Waiter::checkKitchen() {
    if (getReadyMeals().size() > 0) {
        serveMeals();
        readyMeals.clear();
    } else {
        fetchMeals();
    }
}

std::vector<Meal*> Waiter::getReadyMeals() { return this->readyMeals; }
void Waiter::fetchMeals() {
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

void Waiter::giveToKitchen() {
    OrderComposite* order = orderBuilder_->getOrder();
    pointOfSales_->addOrder(order);

    FloorStaff::getKitchen()->handleOrder(order);
}
Meal* Waiter::getMeal(Customer& customer) {
    for (auto& meal : readyMeals) {
        if (meal->getCustomer() == customer.getName()) {
            return meal;
        }
    }
    return nullptr;
}
void Waiter::giveMeal(Customer& Customer, Meal* meal) {
    Meal* CustomerMeal = getMeal(Customer);
    Customer.receiveMeal(CustomerMeal);
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
    Manager* manager = new Manager(this->floor_);
    std::cout << "I am the manager!" << std::endl;
    manager->accept(state);
    delete manager;
}

void Waiter::accept(CustomerState& state) { state.visit(*this); }

std::string Waiter::getStaffType() { return "Waiter"; }

std::vector<Receipt> Waiter::synthesizeBill(int strategy, uint32_t tblId) {
    switch (strategy) {
    case 0:
        std::cout << "Even Split" << std::endl;
        return pointOfSales_->getReceipt(new EvenSplit(), tblId);
        break;
    case 1:
        std::cout << "Per Customer" << std::endl;
        return pointOfSales_->getReceipt(new PerCustomer(), tblId);
        break;
    case 2:
        std::cout << "One Rich boi" << std::endl;
        return pointOfSales_->getReceipt(new OneReceipt(), tblId);
        break;
    default: std::cout << "Invalid strategy" << std::endl; break;
    }
    return {};
}