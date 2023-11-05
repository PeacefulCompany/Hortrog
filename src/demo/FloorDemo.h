#pragma once

#include "core/Application.h"
#include "floor/Floor.h"
#include "floor/Table.h"

#include <memory>
#include <vector>

class FloorDemo : public Application {
protected:
    inline bool shouldQuit() const override { return !running_; }

    void gameLoop() override;
    void init() override;
    void cleanup() override;

private:
    void addTable();

    Floor floor_;
    bool running_ = true;
};