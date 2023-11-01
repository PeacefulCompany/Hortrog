#pragma once
#include "Object.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Map {
public:
    Map();
    ~Map();
    void add(Object* object);
    void draw() const;
    void setOjectAt(int x, int y, Object* object);
    void DebugPrint() const;
    Object* getObjectAt(int x, int y) const;

protected:
private:
    int id_;
    int width_;
    int height_;
    std::vector<Object*> rows_;
    std::vector<Object*> cols_;
};