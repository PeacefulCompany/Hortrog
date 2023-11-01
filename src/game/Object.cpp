#include "Object.h"
Object::Object(int x, int y, int icon) : x_(x), y_(y), icon_(icon) {
    this->nextHoriz_ = nullptr;
    this->nextVert_ = nullptr;
    this->prevHoriz_ = nullptr;
    this->prevVert_ = nullptr;
    this->top_ = nullptr;
    this->bottom_ = nullptr;
}
Object::~Object() {}

int Object::getX() const { return x_; }

int Object::getY() const { return y_; }

void Object::setNextHoriz(Object* object) { this->nextHoriz_ = object; }

void Object::setNextVert(Object* object) { this->nextVert_ = object; }

void Object::setPrevHoriz(Object* object) { this->prevHoriz_ = object; }

void Object::setPrevVert(Object* object) { prevVert_ = object; }

void Object::setTop(Object* object) { this->top_ = object; }

void Object::setBottom(Object* object) { this->bottom_ = object; }

Object* Object::getNextHoriz() const { return this->nextHoriz_; }

Object* Object::getNextVert() const { return this->nextVert_; }

Object* Object::getPrevHoriz() const { return this->prevHoriz_; }

Object* Object::getPrevVert() const { return this->prevVert_; }

Object* Object::getTop() const { return this->top_; }

Object* Object::getBottom() const { return bottom_; }

int Object::getIcon() const { return this->icon_; }
