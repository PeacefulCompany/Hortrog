#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "core/AssetLoader.h"
#include "gui/View.h"
#include "multiply/multiply.h"
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "SFML/Graphics.hpp"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

class MyRectangle : public gui::View {
public:
    MyRectangle(sf::RectangleShape& rect) : rect(rect) {}
    sf::FloatRect getBoundingBox() const override {
        return rect.getGlobalBounds();
    }
    void draw(sf::RenderTarget& target) const override { target.draw(rect); }
    sf::Vector2f position() const override { return rect.getPosition(); }
    void position(sf::Vector2f v) override { rect.setPosition(v); }

private:
    sf::RectangleShape rect;
};

void readAssetFile(const std::string& path) {
    std::ifstream file("assets/" + path);
    if (!file.is_open()) {
        std::cout << "Cannot open asset" << std::endl;
        return;
    }
    json data = json::parse(file);

    std::cout << data["name"].get<std::string>() << std::endl;
    std::cout << data["age"].get<int>() << std::endl;
}

int main() {
    std::cout << "COS 214 - Final Project" << std::endl;
    std::cout << "7 * 6 = " << multiply(7, 6) << std::endl;

    AssetLoader& loader = AssetLoader::instance();
    const sf::Texture* texture = loader.loadTexture("textures/hunny.png");
    assert(texture);

    gui::View* view = loader.loadView("views/my_view.json");
    view->position({0, 300});
    assert(view);

    readAssetFile("demo_asset.json");
    sf::RenderWindow w(sf::VideoMode(800, 600), "COS 214 Final Project");

    sf::RectangleShape r({300, 200});
    r.setTexture(texture);
    std::unique_ptr<gui::View> view2 = std::make_unique<MyRectangle>(r);
    view->position({20, 10});

    while (w.isOpen()) {
        sf::Event event;
        while (w.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                w.close();
            }
        }
        view->draw(w);
        view2->draw(w);
        w.display();
        // rect.draw(w);
    }
}