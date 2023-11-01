#pragma once
#include "game/Object.h"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace nlohmann;
using namespace std;
class Manager : public Object {
public:
    Manager() = delete;
    Manager(int x, int y, int icon_);
    virtual ~Manager();

protected:
private:
    std::vector<string> Complaints;
};