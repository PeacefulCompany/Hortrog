#include "NormalChef.h"

NormalChef::NormalChef(/* args */)
{
}

NormalChef::NormalChef(std::string name, std::string role, int level) : KitchenStaff(name, role, level)
{
}

NormalChef::~NormalChef()
{
}

//functions

void NormalChef::prepareMeal(Meal* meal)
{
    OrderJSON order = OrderJSON(meal->getJson());

    std::vector<Item*> items = order.getItems();

    if(canPrepare(items))
    {
        handlePreperation(meal);
    }
    else
    {
        next->prepareMeal(meal);
    }

    
}

bool NormalChef::canPrepare(std::vector<Item*> items)
{
    for (int i = 0; i < items.size(); i++)
    {
        for (int j = 0; j < preparableItems.size(); j++)
        {
            if(items[i]->getName() == preparableItems[j])
            {
                return true;
            }
        }
    }
    return false;   
}

void NormalChef::handlePreperation(Meal* meal)
{
    OrderJSON order = OrderJSON(meal->getJson());
    std::vector<Item*> items = order.getItems();

    for (int i = 0; i < items.size(); i++)
    {
        MealItem* mealItem = new MealItem(meal->getCustomer(), this->level, items[i]->getName());
    }
    // notify();
    
}

// void NormalChef::notify()
// {
//     headChef->notify();
// }