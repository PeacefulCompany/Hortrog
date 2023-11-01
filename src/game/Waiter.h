#pragma once
#include "game/Object.h"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace nlohmann;
using namespace std;
class Waiter : public Object {
public:
    Waiter() = delete;
    Waiter(int x, int y, int icon_);
    virtual ~Waiter();
    void TakeOrder(vector<string> TableList);
    json placeOrder();
    void ServeOrder();

protected:
private:
    std::vector<int> TableList;
    json currentOrder_;
};