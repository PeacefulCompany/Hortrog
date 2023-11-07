#pragma once

#include "billing/PointOfSales.h"
#include "core/Application.h"
#include "core/CommandMenu.h"
#include "floor/Floor.h"
#include "floor/Table.h"

#include <functional>
#include <memory>
#include <vector>

class FloorDemo : public Application {
public:
    FloorDemo(Floor& floor, Menu& menu);

    void gameLoop() override;
    void init() override;
    void cleanup() override;

    void addTable();
    void addCustomers();
    void addStaff();
    void visitCustomers();
    void update();

protected:
    CommandMenu mainOptions_;

    PointOfSales pointOfSales_;

    Floor& floor_;
    Menu& menu_;

};