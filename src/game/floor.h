#pragma once
#include "game/Object.h"
class Floor : public Object {
public:
    Floor() = delete;
    Floor(int x, int y, int icon_);
    virtual ~Floor();

protected:
private:
};