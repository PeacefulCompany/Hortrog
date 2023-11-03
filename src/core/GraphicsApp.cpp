#include "GraphicsApp.h"
#include "SFML/System/Time.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/VideoMode.hpp"
#include <iostream>

void GraphicsApp::init() {
    window_.create(sf::VideoMode(1280, 720), "COS 214 - Final Project");
    window_.setVerticalSyncEnabled(true);
}

bool GraphicsApp::shouldQuit() const { return !window_.isOpen(); }

void GraphicsApp::gameLoop() {
    sf::Time time = frameClock_.restart();
    update(time.asMilliseconds());

    sf::Event event;
    while (window_.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window_.close();
        }
    }
    window_.clear(sf::Color::Black);
    window_.display();
}

void GraphicsApp::cleanup() {}

void GraphicsApp::update(float dt) {
    std::cout << "Time has passed: " << dt << std::endl;
}
