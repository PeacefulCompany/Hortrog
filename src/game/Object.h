#pragma once
class Object {
public:
    Object() = delete;
    Object(int x, int y, int icon_);
    int getX() const;
    int getY() const;
    virtual ~Object();
    void setNextHoriz(Object* object);
    void setNextVert(Object* object);
    void setPrevHoriz(Object* object);
    void setPrevVert(Object* object);
    void setTop(Object* object);
    void setBottom(Object* object);
    Object* getNextHoriz() const;
    Object* getNextVert() const;
    Object* getPrevHoriz() const;
    Object* getPrevVert() const;
    Object* getTop() const;
    Object* getBottom() const;
    bool isTop() const;
    bool isBottom() const;
    bool isLeft() const;
    bool isRight() const;
    bool isCorner() const;
    bool isHorizontal() const;
    bool isVertical() const;
    int getIcon() const;

protected:
    int x_;
    int y_;
    int width_;
    int height_;
    int icon_;
    Object* nextHoriz_;
    Object* nextVert_;
    Object* prevHoriz_;
    Object* prevVert_;
    Object* top_;
    Object* bottom_;
};
