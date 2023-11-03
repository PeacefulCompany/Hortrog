#include "KitchenStaff.h"

KitchenStaff::KitchenStaff(
    std::string name, std::string role, int leve, Kitchen* kitchen) {
    this->name = name;
    this->role = role;
    this->level = level;
    this->next = nullptr;
}

KitchenStaff::KitchenStaff() {}

KitchenStaff::~KitchenStaff() {}

bool KitchenStaff::canPrepare(std::string items) { return false; }

void KitchenStaff::prepareMeal(Meal* meal) {
    std::cout << "default kitchenStaff prepareMeal!" << std::endl;
    std::cout << meal->toString() << std::endl;

    if (next != nullptr) {
        next->prepareMeal(meal);
    } else {
        kitchen->handleMeal(meal);
        std::cout << "end of chain of chefs!" << std::endl;
    }

    std::cout << meal->toString() << std::endl;
    return;
}

void KitchenStaff::handlePreperation(Meal* meal) {
    std::cout << "default kitchenStaff handlePreperation!" << std::endl;
}

void KitchenStaff::notify() {
    std::cout << "default kitchenStaff notify!" << std::endl;
}

std::string KitchenStaff::getName() const { return name; }

std::string KitchenStaff::getRole() const { return role; }

int KitchenStaff::getLevel() const { return level; }

KitchenStaff* KitchenStaff::getNext() const { return next; }

void KitchenStaff::setName(std::string name) { this->name = name; }

void KitchenStaff::setRole(std::string role) { this->role = role; }

void KitchenStaff::setLevel(int level) { this->level = level; }

void KitchenStaff::setNext(KitchenStaff* next) { this->next = next; }
