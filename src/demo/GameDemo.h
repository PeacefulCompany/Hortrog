#pragma once

#include "FloorDemo.h"
#include "KitchenDemo.h"
#include "core/Application.h"
#include "core/CommandMenu.h"
#include "demo/WaiterDemo.h"
#include "floor/Floor.h"
#include "subsystem/Chef/Kitchen.h"

class GameDemo : public Application {
protected:
    KitchenDemo* kitchenDemo_ = nullptr;
    FloorDemo* floorDemo_ = nullptr;
    Application* current_ = nullptr;

    CommandMenu commands_;

    // --- Game resources ---

    Floor floor_;
    Menu menu_;
    Kitchen *kitchen_ = new Kitchen();
    ConcreteOrderBuilder* orderBuilder_;

public:
    void update();
    void wait();

    virtual void gameLoop() override;

    virtual void init() override;
    virtual void cleanup() override;
};
