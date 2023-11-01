#include "EatingState.h"
#include <iostream>

void EatingState::visit(Manager& m) {
    std::cout << "[Eating]: Visited by manager" << std::endl;
}

void EatingState::visit(Waiter& w) {
    std::cout << "[Eating]: Visited by waiter" << std::endl;
}

void EatingState::update(float dt) {
    eatTime_.update(dt);
    if (eatTime_.expired()) {
        std::cout << "Done eating" << std::endl;
    } else {
        std::cout << "Still eating: "
                  << (eatTime_.duration() - eatTime_.current()) << std::endl;
    }
}
