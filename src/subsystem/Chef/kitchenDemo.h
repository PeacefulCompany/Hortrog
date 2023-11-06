#pragma once

#include "menu/Menu.h"

#include "../../Menu/Menu.h"

#include "order/ConcreteOrderBuilder.h"
#include "subsystem/Chef/Kitchen.h"

class KitchenDemo {

private:
    Kitchen* kitchen_;
    ConcreteOrderBuilder* orderBuilder_;
    Menu* menu_ = new Menu();
    // Menu* menu_;

public:
    // constructor and destructor
    KitchenDemo();
    ~KitchenDemo();

    /**
     * @brief Get the Kitchen object
     *
     * @return Kitchen*
     */
    Kitchen* getKitchen();

    /**
     * @brief Set the Kitchen object
     *
     * @param kitchen
     */
    void setKitchen(Kitchen* kitchen);

    /**
     * @brief Get the Order Builder object
     *
     * @return ConcreteOrderBuilder*
     */
    ConcreteOrderBuilder* getOrderBuilder();


    /**
     * @brief Set the Order Builder object
     *
     * @param orderBuilder
     */
    void setOrderBuilder(ConcreteOrderBuilder* orderBuilder);

    /**
     * @brief Test function that pulls everything together into a demo
     *
     */
    void test();

    /**
     * @brief Ask for the time passed and update the kitchen
     *
     * @param kitchen
     */
    void askTimePassed(Kitchen* kitchen);

    /**
     * @brief Add an item to the order
     *
     */
    void addOrderBuilderItem();

    /**
     * @brief Add a modifier to the order 
     *
     */
    void addOrderBuilderModifier();

    /**
     * @brief Handle the main menu
     *
     */
    void menuHandler();

    /**
     * @brief Display the main menu
     *
     */
    void displayMainMenu();

    /**
     * @brief Simulate the time passed
     *
     */
    void simulateTimePassed();

    /**
     * @brief Display the current state of the kitchen
     *
     */
    void displayKitchenSnapshot();

    /**
     * @brief Display the menu
     *
     */
    void displayMenu();

    /**
     * @brief Display the modifiers
     *
     */
    void displayModifiers();

    /**
     * @brief Display the order builder menu
     *
     */
    void displayOrderBuilderMenu();

    void displayAddChef();
};

#endif // KITCHEN_DEMO_H

