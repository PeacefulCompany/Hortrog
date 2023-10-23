#pragma once

#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Event.hpp"

#include "Presenter.h"

namespace gui {

class View {
public:
    virtual ~View() {}

    /**
     * @brief Draws the object to passed-in render target
     *
     * @param target The target to draw to
     */
    virtual void draw(sf::RenderTarget& target) const = 0;

    /**
     * @brief Updates time-based features (e.g. sprite animation)
     *
     * @param dt Time (in seconds) since the last draw
     */
    virtual void update(float dt) {}

    /**
     * @brief Forwards an event to the presenter (where appropriate)
     *
     * @param event The event to handle
     * @return true The event has been consumed and should not be propagated
     * @return false The event was handled and can be propagated
     */
    virtual bool onEvent(const sf::Event& event) { return false; }

    /**
     * @brief omputes the bounding box of the object
     *
     * @return the bounding box
     */
    virtual sf::FloatRect getBoundingBox() const = 0;

    virtual sf::Vector2f position() const = 0;
    virtual void position(sf::Vector2f v) = 0;

protected:
    Presenter* presenter_;
};

} // namespace gui