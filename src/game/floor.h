#pragma once
#include "game/Object.h"
#include "gui/View.h"

class Floor : public virtual Object, public virtual gui::View {
public:
    Floor() = delete;
    Floor(int x, int y, int icon_);
    virtual ~Floor();
    sf::FloatRect getBoundingBox() const;
    sf::Vector2f position() const;
    void position(sf::Vector2f v);
    void draw(sf::RenderTarget& window) const;

protected:
private:
};