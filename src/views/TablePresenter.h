#pragma once

#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/System/Vector2.hpp"
#include "gui/Presenter.h"
#include "views/TableView.h"

class TablePresenter : public gui::Presenter {
public:
    TablePresenter(TableView& view, const sf::RenderTarget& target)
        : view_(view), target_(target) {
        view_.setPresenter(this);
    }
    bool onEvent(const sf::Event& e) override;

private:
    void beginDrag(sf::Vector2i mouse);
    void drag(sf::Vector2i mouse);
    void endDrag();

    sf::Vector2i delta_ = {0, 0};
    TableView& view_;

    const sf::RenderTarget& target_;
};