#include "HeadChef.h"

HeadChef::HeadChef(/* args */)
{
}

HeadChef::HeadChef(std::string name, std::string role, int level, Kitchen* kitchen)
{
    this->name = name;
    this->role = role;
    this->level = level;
    this->next = nullptr;
}

HeadChef::~HeadChef()
{
}

//functions

void HeadChef::prepareMeal(Meal* meal)
{
    handlePreperation(meal);
    KitchenStaff::prepareMeal(meal);
}

void HeadChef::addMeal(Meal* meal) {
    bool found = false;
    for (int i = 0; i < mealsToPrepare.size(); i++) {
        if (mealsToPrepare[i] == meal) {
            found = true;
            break;
        }
    }
    if (!found) {
        mealsToPrepare.push_back(meal);
    }
}

bool HeadChef::canPrepare(std::string items)
{
    return false;
}

void HeadChef::handlePreperation(Meal* meal)
{
    OrderJSON order = OrderJSON(meal->getJson());
    std::vector<Item*> items = order.getItems();

    std::vector<MealItem*> mealItems = meal->getItems();

    for (int i = 0; i < items.size(); i++) {
        for (int j = 0; j < mealItems.size(); j++) {
            if (items[i]->getName() != mealItems[j]->getFood()) {
                meal->setReady(false);
            }
        }
    }
    meal->setReady(true);
}


std::vector<Meal*> HeadChef::getPrepareMeals() {
    std::vector<Meal*> readyMeals;
    for (auto it = mealsToPrepare.begin(); it != mealsToPrepare.end(); ) {
        if ((*it)->getReady()) {
            readyMeals.push_back(*it);
            it = mealsToPrepare.erase(it);
        } else {
            ++it;
        }
    }
    return readyMeals;
}