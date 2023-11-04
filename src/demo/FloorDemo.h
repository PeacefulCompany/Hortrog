#pragma once

#include "core/Application.h"

class FloorDemo : public Application {
protected:
    inline bool shouldQuit() const override { return !running_; }

    void gameLoop() override;
    void init() override;
    void cleanup() override;

private:
    void splitTable();
    void mergeTable();
    void addCustomer();
    void removeCustomer();
    bool running_ = true;
};