#pragma once

#include "FloorDemo.h"
#include "KitchenDemo.h"
#include "core/Application.h"
#include "core/CommandMenu.h"
#include "floor/Floor.h"
#include "subsystem/Chef/Kitchen.h"

class GameDemo : public Application {
protected:
    KitchenDemo* kitchenDemo_;
    FloorDemo* floorDemo_;
    Application* current_ = nullptr;

    CommandMenu commands_;

    // --- Game resources ---

    Floor floor_;
    Menu menu_;
    Kitchen kitchen_;
    ConcreteOrderBuilder* orderBuilder_;

public:
    void update();

    virtual void gameLoop() override;

    virtual void init() override;
    virtual void cleanup() override;
};
