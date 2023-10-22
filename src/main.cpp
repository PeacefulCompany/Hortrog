#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "gui/Drawable.h"
#include "multiply/multiply.h"
#include "subsystem/GlutenFree.h"
#include "subsystem/Item.h"
#include "subsystem/Order.h"
#include "subsystem/Pescetarian.h"
#include <iostream>
#include <memory>

#include <vector>
class MyRectangle : gui::Drawable {
public:
    MyRectangle(sf::RectangleShape& rect) : rect(rect) {}
    gui::Rect getBoundingBox() const override { return rect.getGlobalBounds(); }
    void draw(gui::Target& target) const override { target.draw(rect); }

private:
    sf::RectangleShape rect;
};

int main() {
    Order* newOrder;
    newOrder = new GlutenFree(new Pescetarian(new Item("Pizza", 100)));

    std::cout << newOrder->printOrder() << std::endl;
    std::cout << newOrder->total() << std::endl;

    std::cout << "COS 214 - Final Project" << std::endl;
    std::cout << "7 * 6 = " << multiply(7, 6) << std::endl;
    sf::RenderWindow w(sf::VideoMode(800, 600), "COS 214 Final Project");

    sf::RectangleShape r({300, 200});
    r.setPosition({10, 10});
    r.setFillColor(sf::Color(255, 0, 0));
    MyRectangle rect(r);
    while (w.isOpen()) {
        sf::Event event;
        while (w.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                w.close();
            }
        }
        rect.draw(w);
        w.display();
        // rect.draw(w);
    }
}