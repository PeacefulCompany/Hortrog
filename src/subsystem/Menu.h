#include <iostream>
#include <vector>
#include <string>
class Menu {
public:
    static std::vector<std::string> foodNames;
    static std::vector<double> prices;
    Menu() {
        foodNames = {"Burger", "Pizza", "Pasta", "Pie"};
        prices = {10.99, 12.99, 8.99, 5.99};
    }
    static std::vector<std::string> getFoodNames() {
        return foodNames;
    }
    static std::vector<double> getPrices() {
        return prices;
    }
    //create a fucntion that will return a random item from the menu
    static std::string getRandomItem() {
        int random = rand() % foodNames.size();
        return foodNames[random];
    }
    static double getPrice(std::string name) {
        for (int i = 0; i < foodNames.size(); i++) {
            if (foodNames[i] == name) {
                return prices[i];
            }
        }
        return 0;
    }
};
std::vector<std::string> Menu::foodNames;
std::vector<double> Menu::prices;