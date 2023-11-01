#include "HeadChef.h"

HeadChef::HeadChef(/* args */)
{
    kitchen = nullptr;
}

HeadChef::HeadChef(std::string name, std::string role, int level, Kitchen* kitchen)
{
    this->name = name;
    this->role = role;
    this->level = level;
    this->kitchen = kitchen;
    this->next = nullptr;
}

HeadChef::~HeadChef()
{
}

//functions

void HeadChef::prepareMeal(Meal* meal)
{
    if(meal->getReady()){
        kitchen->notify();
    }
    else
    {
        addMeal(meal);
        KitchenStaff::prepareMeal(meal);
    }
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

bool HeadChef::canPrepare(std::vector<Item*> items)
{
    return false;
}

void HeadChef::handlePreperation(std::vector<Item*> items, std::string customer)
{
    // for (int i = 0; i < items.size(); i++)
    // {
    //     MealItem* mealItem = new MealItem(customer, this->level, items[i]->getName());
    // }
    // notify();
    
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