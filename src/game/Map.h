#pragma once
#include "Object.h"
#include "SFML/Graphics/RenderTarget.hpp"
#include "resource/ResourceManager.h"
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
    void draw(sf::RenderTarget& window,
        ResourceManager<sf::Texture, int>& textures) const;
    void setOjectAt(int x, int y, Object* object);
    void DebugPrint() const;
    Object* getObjectAt(int x, int y) const;
    int getHeight() const { return this->height_; }
    int getWidth() const { return this->width_; }
    Object* getRow(int row) const { return this->rows_[row]; }
    Object* getCol(int col) const { return this->cols_[col]; }

protected:
private:
    int id_;
    int width_;
    int height_;
    std::vector<Object*> rows_;
    std::vector<Object*> cols_;
};