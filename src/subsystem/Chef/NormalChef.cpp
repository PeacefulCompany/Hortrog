#include "NormalChef.h"

using namespace std;

NormalChef::NormalChef(/* args */) {}

NormalChef::NormalChef(std::string name,
    std::string role,
    int level,
    int timeToPrepare,
    Kitchen* kitchen)
    : KitchenStaff(name, role, level, kitchen) {
    this->timeToPrepare = timeToPrepare;
}

NormalChef::~NormalChef() {}

// functions

void NormalChef::prepareMeal(Meal* meal) {
    handlePreperation(meal);
    KitchenStaff::prepareMeal(meal);
    return;
}

bool NormalChef::canPrepare(std::string item) {
    for (int j = 0; j < preparableItems.size(); j++) {
        if (item == preparableItems[j]) {
            return true;
        }
    }
    return false;
}

void NormalChef::addPreparableItem(std::string itemName) {
    preparableItems.push_back(itemName);
}

void NormalChef::removePreparableItem(std::string itemName) {
    for (int i = 0; i < preparableItems.size(); i++) {
        if (preparableItems[i] == itemName) {
            preparableItems.erase(preparableItems.begin() + i);
        }
    }
}

// MealItem* NormalChef::getPreparedItem()
// {
//     if(mealItems.size() > 0)
//     {
//         MealItem* item = mealItems.back();
//         mealItems.pop_back();
//         return item;
//     }
//     else
//     {
//         return nullptr;
//     }

// }

void NormalChef::handlePreperation(Meal* meal) {
    OrderJSON order = OrderJSON(meal->getJSON());
    std::vector<Item*> items = order.getItems();

    for (int i = 0; i < items.size(); i++) {

        std::string itemName = items[i]->getName();
        if (canPrepare(itemName)) {
            bool found = false;
            for (int j = 0; j < mealItems.size(); j++) {
                if (mealItems[j]->getFood() == items[i]->getName()) {
                    found = true;
                    meal->addItem(mealItems[j]);
                    mealItems.erase(mealItems.begin() + j);
                    break;
                }
            }
            if (!found) {
                MealItem* mealItem = new MealItem(
                    meal->getCustomer(), this->level, items[i]->getName());
                mealItems.push_back(mealItem);
                wait();
                // meal->addMealItem(mealItem);
            }
        }
    }
    // headChef->notify();
}

void NormalChef::wait() {
    std::chrono::system_clock::time_point current_time =
        std::chrono::system_clock::now();
    std::chrono::system_clock::time_point end_time =
        current_time + std::chrono::seconds(5);

    while (current_time < end_time) {
        current_time = std::chrono::system_clock::now();
    }
}

// void NormalChef::notify()
// {
//     headChef->notify();
// }