#pragma once

#include "core/Application.h"
#include "floor/Floor.h"
#include "floor/TableGroup.h"

#include <vector>

class TerminalApp : public Application {
protected:
    void init() override;
    inline bool shouldQuit() const override { return !running_; }
    void gameLoop() override;
    void cleanup() override {}

private:
    bool running_ = true;
    std::vector<Table*> tables_;
    TableGroup* group_;
};