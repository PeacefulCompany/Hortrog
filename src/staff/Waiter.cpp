#include "Waiter.h"
#include "Menu/Menu.h"
#include "order/ConcreteOrderBuilder.h"
#include "order/OrderBuilder.h"
#include "order/OrderComposite.h"
#include "staff/FloorStaff.h"
#include "staff/Waiter.h"
#include "subsystem/Chef/Kitchen.h"
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
void Waiter::accept(CustomerState& state) { state.visit(*this); }
std::string Waiter::getStaffType() { return "Waiter"; }
