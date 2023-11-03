#pragma once

#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Vector2.hpp"
#include "gui/Presenter.h"
#include "views/TableView.h"

class TablePresenter : public gui::Presenter {
public:
    TablePresenter(TableView& view, const sf::RenderWindow& target)
        : view_(view), target_(target) {
        view_.setPresenter(this);
        targetPosition_ = view.position();
    }
    bool onEvent(const sf::Event& e) override;
    void update(float dt) override;

private:
    void beginDrag(sf::Vector2i mouse);
    void drag(sf::Vector2i mouse);
    void endDrag();

    sf::Vector2i delta_ = {0, 0};
    TableView& view_;
    sf::Vector2f targetPosition_;

    const sf::RenderWindow& target_;
};