#pragma once

#include "core/Application.h"
#include "core/CommandMenu.h"
#include "menu/Menu.h"

#include "order/ConcreteOrderBuilder.h"
#include "subsystem/Chef/Kitchen.h"

class KitchenDemo : public Application {

protected:
    Kitchen* kitchen_;
    ConcreteOrderBuilder* orderBuilder_;
    Menu* menu_ = new Menu();
    CommandMenu commands_;
    bool running_ = true;

    // Menu* menu_;

public:
    inline bool shouldQuit() const override { return !running_; }

    void gameLoop() override;
    void init() override;
    void cleanup() override;
    
    void init(Kitchen* kitchen, Menu* menu);
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
