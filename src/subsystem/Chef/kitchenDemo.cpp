// #include "kitchenDemo.h"

// void test() {
//     Kitchen* kitchen = new Kitchen();
//     Order* o = new Order("bob");
//     Order* b = new Order("alice");
//     kitchen->handleOrder(o);
//     kitchen->handleOrder(b);
//     askTimePassed(kitchen);
// }

// void askTimePassed(Kitchen* kitchen) {
//     int timePassed;
//     while (true) {
//         std::cout << "Enter time passed (sec): ";
//         std::cin >> timePassed;
//         if (timePassed <= 0) {
//             continue;
//         }
//         kitchen->updateTime(timePassed);
//         std::cout << kitchen->toString() << std::endl;
//         Meal* meal = kitchen->getOutgoingMeal();
//         while (meal != nullptr) {
//             std::cout << "Meal ready!" << std::endl;
//             std::cout << meal->toString() << std::endl;
//             meal = kitchen->getOutgoingMeal();
//         }

//         // Do something with timePassed
//     }
// }