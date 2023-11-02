#pragma once
#include "subsystem/Chef/Kitchen.h"
#ifndef SUBSYSTEM_WAITER_H
#define SUBSYSTEM_WAITER_H
class Waiter {

private:
    Kitchen* kitchen_;

public:
    void checkKitchen();
    Waiter(Kitchen*);
};

#endif // SUBSYSTEM_WAITER_H