#include "multiply/multiply.h"
#include <iostream>

#include "SFML/Graphics.hpp"

int main() {
    std::cout << "COS 214 - Final Project" << std::endl;
    std::cout << "7 * 6 = " << multiply(7, 6) << std::endl;
    sf::Window w(sf::VideoMode(800, 600), "COS 214 Final Project");
    while (w.isOpen()) {
        sf::Event event;
        while (w.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                w.close();
            }
        }
    }
}