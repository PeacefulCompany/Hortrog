#pragma once

#include "core/Application.h"
#include "floor/Floor.h"
#include "floor/TableGroup.h"

#include <memory>
#include <vector>

class TerminalApp : public Application {
protected:
    void init() override;
    void gameLoop() override;
    void cleanup() override {}

    void update();

    void printOptions(const std::vector<std::string>& options);

private:
    Menu menu_;
    std::vector<Table*> tables_;
    TableGroup* group_;
};