#pragma once
#include "Map.h"
class Game {
public:
    Game();
    ~Game();
    void printDebug() const;

protected:
private:
    Map* map_;
    // list of customers
    // list of employees
};