#pragma once

#include "core/Application.h"
#include "core/CommandMenu.h"
#include "floor/Floor.h"
#include "floor/Table.h"

#include <functional>
#include <memory>
#include <vector>

class FloorDemo : public Application {
public:
    inline bool shouldQuit() const override { return !running_; }

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

    Floor floor_;
    Menu menu_;
    bool running_ = true;
};