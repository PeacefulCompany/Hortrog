#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Graphics/RenderTarget.hpp"
#include "gui/View.h"
#include "resource/ResourceManager.h"
class FloorView : public gui::View {
public:
    FloorView() = delete;
    FloorView(ResourceManager<sf::Texture>& textures);
    sf::FloatRect getBoundingBox() const override;
    sf::Vector2f position() const override;
    void position(sf::Vector2f v) override;
    void draw(sf::RenderTarget& window) const override;
    ~FloorView();

protected:
private:
    ResourceManager<sf::Texture>& textures_;
    sf::Sprite sprite_;
};