#include "NormalChef.h"

NormalChef::NormalChef()
{
    rating = 1;
    capacity = 1;
    kitchen = nullptr;
    nextStaff_ = nullptr;
}

NormalChef::NormalChef(int rating, int capacity, Kitchen *kitchen, int speed)
{
    this->rating = rating;
    this->capacity = capacity;
    this->kitchen = kitchen;
    nextStaff_ = nullptr;
    this->speed = speed;
}

NormalChef::~NormalChef()
{
}

void NormalChef::prepareMeal(Meal *meal)
{
    OrderJSON *orderJSON = new OrderJSON(meal->getOrder()->toJson());
    std::vector<Item *> items = orderJSON->getItems();

    for (int i = 0; i < items.size(); i++)
    {
        if (canPrepareItem(items[i]->getName()))
        {
            if (mealItemAlreadyPrepared(items[i], meal))
            {
                std::cout << "Normal Chef is adding the item to a meal: " << items[i]->getName() << std::endl;
                getItemFromPrepared(items[i], meal);
            }
            else if( itemsBeingPrepared.size() < capacity && !mealItemAlreadyBeingPrepared(items[i], meal))
            {
                std::cout << "Normal Chef is preparing the item: " << items[i]->getName() << std::endl;
                MealItem *mealItem = new MealItem(meal->getCustomer(), this->rating, items[i]->getName());
                // wait();
                itemsBeingPrepared.push_back(mealItem);
                // notify();
            }
        }
    }
    std::cout << "Normal Chef is done preparing the meal" << std::endl;
    KitchenStaff::prepareMeal(meal);
}

void NormalChef::getItemFromPrepared(Item *item, Meal* meal)
{
    for (int i = 0; i < preparedItems.size(); i++)
    {
        if (preparedItems[i]->getFood() == item->getName() && preparedItems[i]->getCustomer() == meal->getCustomer())
        {
            meal->addItem(preparedItems[i]);
            preparedItems.erase(preparedItems.begin() + i);
        }
    }
}

bool NormalChef::mealItemAlreadyPrepared(Item *item, Meal* meal)
{
    for (int i = 0; i < preparedItems.size(); i++)
    {
        if (preparedItems[i]->getFood() == item->getName() && preparedItems[i]->getCustomer() == meal->getCustomer())
        {
            return true;
        }
    }
    return false;
}

bool NormalChef::mealItemAlreadyBeingPrepared(Item *item, Meal* meal)
{
    for (int i = 0; i < itemsBeingPrepared.size(); i++)
    {
        if (itemsBeingPrepared[i]->getFood() == item->getName() && itemsBeingPrepared[i]->getCustomer() == meal->getCustomer())
        {
            return true;
        }
    }
    return false;
}

bool NormalChef::canPrepareItem(std::string item)
{
    for (int i = 0; i < canPrepareItems_.size(); i++)
    {
        if (canPrepareItems_[i] == item)
        {
            return true;
        }
    }
    return false;
}

void NormalChef::addCanPrepareItem(std::string item)
{
    canPrepareItems_.push_back(item);
}

void NormalChef::removeCanPrepareItem(std::string item)
{
    for (int i = 0; i < canPrepareItems_.size(); i++)
    {
        if (canPrepareItems_[i] == item)
        {
            canPrepareItems_.erase(canPrepareItems_.begin() + i);
        }
    }
}

void NormalChef::update(){
    // lastTime = 0;

    if(!itemsBeingPrepared.empty() && lastTime >= speed)
    {
        preparedItems.push_back(itemsBeingPrepared.front());
        itemsBeingPrepared.erase(itemsBeingPrepared.begin());
        print();
    }
    notify();

}

void NormalChef::print(){
    std::cout << "Normal Chef: " << std::endl;
    std::cout << "    Rating: " << rating << std::endl;
    std::cout << "    Capacity: " << capacity << std::endl;
    std::cout << "    Speed: " << speed << std::endl;
    std::cout << "    Can prepare: " << std::endl;
    for (int i = 0; i < canPrepareItems_.size(); i++)
    {
        std::cout << "        " << canPrepareItems_[i] << std::endl;
    }
    std::cout << "    Prepared Items: " << std::endl;
    for (int i = 0; i < preparedItems.size(); i++)
    {
        std::cout << "        " << preparedItems[i]->getFood() << " for " << preparedItems[i]->getCustomer() << std::endl;
    }
    std::cout << "    Items Being Prepared: " << std::endl;
    for (int i = 0; i < itemsBeingPrepared.size(); i++)
    {
        std::cout << "        " << itemsBeingPrepared[i]->getFood() << " for " << itemsBeingPrepared[i]->getCustomer() << std::endl;
    }
}


void NormalChef::wait()
{
    std::chrono::system_clock::time_point current_time =
        std::chrono::system_clock::now();
    std::chrono::system_clock::time_point end_time =
        current_time + std::chrono::seconds(capacity);

    while (current_time < end_time)
    {
        current_time = std::chrono::system_clock::now();
    }
}