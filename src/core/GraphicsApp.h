#pragma once

#include "SFML/Graphics/RenderWindow.hpp"
#include "core/Application.h"
#include <string>
#include <vector>

class GraphicsApp : public Application {
protected:
    void init() override;
    bool shouldQuit() const override;
    void gameLoop() override;
    void cleanup() override;

    void update(float dt);

private:
    sf::Clock frameClock_;
    sf::RenderWindow window_;
};