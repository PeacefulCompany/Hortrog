#pragma once
#include "Builder.h"
#include <list>
#include <memory>
class Director {
public:
    Director();
    void add(std::unique_ptr<Builder> builder);
    void Construct();

private:
    std::list<std::unique_ptr<Builder>> builders;
};