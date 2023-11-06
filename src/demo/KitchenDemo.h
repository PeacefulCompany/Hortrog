#pragma once

#include "core/Application.h"
#include "core/CommandMenu.h"
#include "menu/Menu.h"

#include "order/ConcreteOrderBuilder.h"
#include "subsystem/Chef/Kitchen.h"

class KitchenDemo : public Application {

protected:
    Kitchen& kitchen_;
    ConcreteOrderBuilder& orderBuilder_;
    Menu& menu_;
    CommandMenu commands_;

    // Menu* menu_;

public:
    KitchenDemo(Kitchen& kitchen, ConcreteOrderBuilder& builder, Menu& menu);

    void gameLoop() override;
    void init() override;
    void cleanup() override;

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

    void completeOrder();
};
