/**
 * @file KitchenStaff.cpp
 * @brief Implementation of the KitchenStaff class
 */

#include "KitchenStaff.h"

/**
 * @brief Construct a new Kitchen Staff object
 * 
 */
KitchenStaff::KitchenStaff(/* args */)
{
    
}

/**
 * @brief Destroy the Kitchen Staff object
 * 
 */
KitchenStaff::~KitchenStaff()
{
}

/**
 * @brief Prepare a meal by passing it down the chain of kitchen staff
 * 
 * @param meal The meal to be prepared
 */
void KitchenStaff::prepareMeal(Meal *meal)
{
    if (nextStaff_ != nullptr)
    {
        nextStaff_->prepareMeal(meal);
    }
    else
    {
        std::cout << "KitchenStaff: end of chain" << std::endl;
    }
}

/**
 * @brief Notify the kitchen that an item is ready
 * 
 */
void KitchenStaff::notify()
{
    std::cout << "KitchenStaff: Notified" << std::endl;
    kitchen->notifyItemReady();
}

/**
 * @brief Update the kitchen staff
 * 
 */
void KitchenStaff::update(){
    lastTime = 0;
}

/**
 * @brief Update the time for the kitchen staff
 * 
 * @param delta The time difference
 */
void KitchenStaff::updateTime(int delta){
    lastTime += delta;

    if(lastTime>= speed)
    {
        update();
        lastTime = 0;
    }

    if(nextStaff_ != nullptr)
    {
        nextStaff_->updateTime(delta);
    }
}

/**
 * @brief Set the next kitchen staff in the chain
 * 
 * @param next The next kitchen staff
 */
void KitchenStaff::setNextStaff(KitchenStaff *next)
{
    // nextStaff = next;
    nextStaff_ = std::unique_ptr<KitchenStaff>(next);
}