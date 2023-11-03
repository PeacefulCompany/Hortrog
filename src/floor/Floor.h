#pragma once

#include "floor/Table.h"

#include <memory>
#include <unordered_map>

class Floor {
public:
    Table* requestSeating(int n);

private:
    std::vector<std::unique_ptr<Table>> tables_;
};