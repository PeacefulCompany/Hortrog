#include "Map.h"
#include "SFML/Graphics.hpp"
#include "SFML/Graphics/RenderTarget.hpp"
#include "game/Map.h"
#include "game/Object.h"
#include "gui/View.h"
#include "nlohmann/json.hpp"
#include "resource/ResourceManager.h"

#include <iostream>
#include <stdio.h>
using namespace nlohmann;
Map::Map() {
    this->width_ = 0;
    this->height_ = 0;
    string path = "GameMap.json";
    std::ifstream file("assets/" + path);
    if (!file.is_open()) {
        std::cout << "Cannot open asset" << std::endl;
        return;
    }
    json data = json::parse(file);
    this->width_ = data["width"].get<int>();
    this->height_ = data["height"].get<int>();
    rows_.resize(height_, nullptr);
    cols_.resize(width_, nullptr);

    for (int i = 0; i < this->height_; i++) {
        for (int j = 0; j < this->width_; j++) {
            if (rows_[i] == nullptr) {
                rows_[i] = new Object(i, j, data["tiles"][i][j].get<int>());
            } else {
                Object* temp = rows_[i];
                while (temp->getNextHoriz() != nullptr) {
                    temp = temp->getNextHoriz();
                }
                temp->setNextHoriz(
                    new Object(i, j, data["tiles"][i][j].get<int>()));
            }
            if (cols_[j] == nullptr) {
                cols_[j] = new Object(i, j, data["tiles"][i][j].get<int>());
            } else {
                Object* temp = cols_[j];
                while (temp->getNextVert() != nullptr) {
                    temp = temp->getNextVert();
                }
                temp->setNextVert(
                    new Object(i, j, data["tiles"][i][j].get<int>()));
            }
        }
    }
    // link objects in both direction
    for (int i = 0; i < this->height_; i++) {
        Object* temp = rows_[i];
        while (temp != nullptr) {
            if (temp->getNextHoriz() != nullptr) {
                temp->getNextHoriz()->setPrevHoriz(temp);
            }
            if (temp->getNextVert() != nullptr) {
                temp->getNextVert()->setPrevVert(temp);
            }
            temp = temp->getNextHoriz();
        }
    }
    for (int i = 0; i < this->width_; i++) {
        Object* temp = cols_[i];
        while (temp != nullptr) {
            if (temp->getNextHoriz() != nullptr) {
                temp->getNextHoriz()->setPrevHoriz(temp);
            }
            if (temp->getNextVert() != nullptr) {
                temp->getNextVert()->setPrevVert(temp);
            }
            temp = temp->getNextVert();
        }
    }
}
Map::~Map() {
    for (int i = 0; i < this->height_; i++) {
        delete[] this->rows_[i];
    }

    for (int i = 0; i < this->width_; i++) {
        delete[] this->cols_[i];
    }
}
void Map::add(Object* object) {}
void setOjectAt(int x, int y, Object* object) {}
void Map::draw(sf::RenderTarget& window,
    ResourceManager<sf::Texture, int>& textures) const {
    for (int i = 0; i < this->height_; i++) {
        Object* temp = rows_[i];
        while (temp != nullptr) {
            sf::Sprite S(*textures.get(temp->getIcon()));
            S.setPosition(temp->getX() * 32 * 3, temp->getY() * 32 * 3);
            S.setScale(3, 3);
            window.draw(S);
            temp = temp->getNextHoriz();
        }
    }
}
void Map::DebugPrint() const {
    cout << "row view=:" << endl;
    for (int i = 0; i < this->height_; i++) {
        Object* temp = rows_[i];
        while (temp != nullptr) {
            cout << " x:" << temp->getX() << ",y:" << temp->getY()
                 << ",s:" << temp->getIcon() << " ";
            temp = temp->getNextHoriz();
        }
        cout << endl;
    }
    cout << "col view=:" << endl;
    for (int i = 0; i < this->width_; i++) {
        Object* temp = cols_[i];
        while (temp != nullptr) {
            cout << " x:" << temp->getX() << ",y:" << temp->getY()
                 << ",s:" << temp->getIcon() << " ";
            temp = temp->getNextVert();
        }
        cout << endl;
    }
}
Object* Map::getObjectAt(int x, int y) const { return nullptr; }
