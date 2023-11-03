#include "Kitchen.h"
#include <iostream>

// Kitchen::Kitchen() {

// }

// Kitchen::~Kitchen() {}


// void Kitchen::handleOrder(Order* order) {

//     std::cout << "Kitchen handling order" << std::endl;
//     std::cout << order->toJson() << std::endl;
//     Meal* meal = new Meal(order);
//     // handleMeal(meal);
//     while(meal->isReady() == false){
//     std::cout << "readyness" << meal->isReady() << std::endl;

//         std::cout << "meal is not ready" << std::endl;
//         headChef->prepareMeal(meal);
//         std::cout << meal->toString() << std::endl;
//     std::cout << "Kitchen handled order" << std::endl;

//     }
//     std::cout << "Kitchen handled order" << std::endl;
// }

// void Kitchen::handleMeal(Meal* meal) {
//     std::cout << "Kitchen checking meal" << std::endl;
//     if(meal->isReady()) {
//         outGoingMeals.push_back(meal);
//         printReadyMeals();
//         return;
//     }
//     else
//     {
//         incomingMeals.push(meal);
//     }
//     clearQueue();
//     std::cout << "Kitchen checked meal" << std::endl;

// }

// void Kitchen::clearQueue() {
//     std::cout << "Kitchen clearing queue" << std::endl;
//     while (!incomingMeals.empty()) {
//         std::cout << "Kitchen preparing meal" << std::endl;
//         headChef->prepareMeal(incomingMeals.front());
//         incomingMeals.pop();
//     }
//     std::cout << "Kitchen cleared queue" << std::endl;
// }



// void Kitchen::printReadyMeals() {
//     std::cout << "Kitchen printing ready meals" << std::endl;
//     for (auto& meal : outGoingMeals) {
//         std::cout << meal->toString() << std::endl;
//     }
//     std::cout << "Kitchen printed ready meals" << std::endl;
// }



Kitchen::Kitchen(/* args */)
{
    this->headChef = new HeadChef(5, 5, this, 5);

    KitchenStaff *chef1 = new NormalChef(3, 3, this, 5);
    ((NormalChef *)chef1)->addCanPrepareItem("Grilled Salmon");

    KitchenStaff *chef2 = new NormalChef(3, 3, this, 5);
    ((NormalChef *)chef2)->addCanPrepareItem("Avocado Toast");

    headChef->setNextStaff(chef1);
    chef1->setNextStaff(chef2);
}

void Kitchen::handleOrder(Order *order)
{
    std::cout << "Kitchen: Handling order" << std::endl;
    Meal *meal = new Meal(order);
    incomingMeals.push(meal);
    flush();
}

void Kitchen::notifyItemReady()
{
    std::cout << "Kitchen: Notified" << std::endl;
    flush();
}

void Kitchen::flush()
{
    std::cout << "Kitchen: Flushing" << std::endl;
    for (int i = 0; i < incomingMeals.size(); i++)
    {
        // Pop an element from the incomingMeals queue.
        Meal *meal = incomingMeals.front();
        incomingMeals.pop();

        // Get the headChef to prepare the meal.
        headChef->prepareMeal(meal);

        // Check if the meal is done.
        if (meal->getReady())
        {
            // If the meal is done, add it to the outgoingMeals vector.
            outgoingMeals.push_back(meal);
        }
        else
        {
            // If the meal is not done, re-add it to the incomingMeals queue.
            incomingMeals.push(meal);
        }
    }

    std::cout << "Kitchen: Done flushing" << std::endl;
}

Meal* Kitchen::getOutgoingMeal(){
    if(outgoingMeals.empty()){
        return nullptr;
    }
    Meal* meal = outgoingMeals.front();
    outgoingMeals.erase(outgoingMeals.begin());
    return meal;
}


void Kitchen::updateTime(int time){
    headChef->updateTime(time);
}

Kitchen::~Kitchen()
{
}


void Kitchen::notify() { std::cout << "Kitchen notified" << std::endl; }

