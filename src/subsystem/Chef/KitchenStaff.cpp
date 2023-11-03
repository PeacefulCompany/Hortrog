#include "KitchenStaff.h"

KitchenStaff::KitchenStaff(/* args */)
{
    
}

KitchenStaff::~KitchenStaff()
{
}

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

void KitchenStaff::notify()
{
    std::cout << "KitchenStaff: Notified" << std::endl;
    kitchen->notifyItemReady();
}

void KitchenStaff::update(){
    lastTime = 0;
}

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

void KitchenStaff::setNextStaff(KitchenStaff *next)
{
    // nextStaff = next;
    nextStaff_ = std::unique_ptr<KitchenStaff>(next);
}