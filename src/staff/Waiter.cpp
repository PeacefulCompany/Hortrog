#include "Waiter.h"
#include "Menu/Menu.h"
#include "order/ConcreteOrderBuilder.h"
#include "order/OrderBuilder.h"
#include "order/OrderComposite.h"
#include "staff/FloorStaff.h"
#include "staff/Waiter.h"
#include "subsystem/Chef/Kitchen.h"

Waiter::Waiter(const Menu* menu) : FloorStaff(), menu_(menu) {
    this->orderBuilder_ = std::make_unique<ConcreteOrderBuilder>(menu);
    this->orderBuilder_->setMenu(menu);
}
void Waiter::checkKitchen() {
    // std::cout << "kitchen check for orders..." << std::endl;
    // // currentmealObjectPointerArray_ = kitchen_->checkForOrders();
    // //  add meals
    // currentmealObjectPointerArray_.push_back(new std::string("fish"));
    // currentmealObjectPointerArray_.push_back(new std::string("chips"));
    // currentmealObjectPointerArray_.push_back(new std::string("peas"));
    Meal* currentMeal;
    int x = 0;
    do {
        currentMeal = kitchen_->getOrder(tables_[x]->id());
        x++;
    } while (currentMeal == nullptr && x < tables_.size());
    if (x == tables_.size()) return;
    if (currentMeal != nullptr) readyMeals.push_back(currentMeal);
}
OrderBuilder* Waiter::getOrderBuilder() { return orderBuilder_.get(); }
void Waiter::accept(CustomerState& state) { state.visit(*this); }
std::string Waiter::getStaffType() { return "Waiter"; }

void Waiter::setKitchen(Kitchen* kitchen) { this->kitchen_ = kitchen; }