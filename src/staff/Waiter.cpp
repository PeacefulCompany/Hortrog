#include "Waiter.h"
#include "Menu/Menu.h"
#include "order/ConcreteOrderBuilder.h"
#include "order/OrderBuilder.h"
#include "order/OrderComposite.h"
#include "staff/FloorStaff.h"
#include "staff/Waiter.h"

Waiter::Waiter() : FloorStaff() {
    this->orderBuilder_ = std::make_unique<ConcreteOrderBuilder>();
    Menu* menu = new Menu();
    menu->initMenu();
    this->orderBuilder_->setMenu(menu);
}
void Waiter::checkKitchen() {
    std::cout << "kitchen check for orders..." << std::endl;
    // currentmealObjectPointerArray_ = kitchen_->checkForOrders();
    //  add meals
    currentmealObjectPointerArray_.push_back(new std::string("fish"));
    currentmealObjectPointerArray_.push_back(new std::string("chips"));
    currentmealObjectPointerArray_.push_back(new std::string("peas"));
}
OrderBuilder* Waiter::getOrderBuilder() {
    this->orderBuilder_->begin();
    return orderBuilder_.get();
}
void Waiter::accept(CustomerState& state) { state.visit(*this); }
std::string Waiter::getStaffType() { return "Waiter"; }
