#pragma once

#include "core/Application.h"
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
    void splitTable();
    void mergeTable();
    void addCustomer();
    void removeCustomer();

    std::vector<std::unique_ptr<Table>>::iterator findTable(int id);
    static void error(const std::string& message);

    std::vector<std::unique_ptr<Table>> tables_;
    bool running_ = true;
    int tableCount_ = 0;
};