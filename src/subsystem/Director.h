#pragma once
#include "Builder.h"
#include <list>
#include <memory>
class Director {
public:
    Director();
    void add(Builder* builder);
    void Construct();

private:
    std::list<Builder*> builders;
};