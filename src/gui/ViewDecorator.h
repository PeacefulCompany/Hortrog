#pragma once

#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Window/Event.hpp"

#include "View.h"

namespace gui {

template <class T>
concept IsView = std::is_base_of<View, T>::value;

/**
 * @brief Base class for adding functionality to a drawable object
 *
 */
class ViewDecorator : public View {
public:
    inline virtual void draw(sf::RenderTarget& t) const override {
        internal_->draw(t);
    }
    inline virtual void update(float dt) override { internal_->update(dt); }
    inline virtual bool onEvent(const sf::Event& e) override {
        return internal_->onEvent(e);
    }
    inline virtual sf::FloatRect getBoundingBox() const override {
        return internal_->getBoundingBox();
    };

    /**
     * @brief Retrieves a pointer to the internal object of the decorator
     *
     * @tparam D The type of the internal pointer (defaults to View)
     * @return D* Non-owning pointer to the decoratee
     */
    template <IsView D = View>
    inline D* get() const {
        return static_cast<D*>(internal_.get());
    }

    /**
     * @brief "Un-decorates" the internal object and releases ownership
     *
     * @tparam D The type of the internal object (defaults to View)
     * @return D* Owning pointer to the decoratee
     */
    template <IsView D = View>
    inline D* unwrap() {
        return static_cast<D*>(internal_.release());
    }

protected:
    inline ViewDecorator(std::unique_ptr<View> internal)
        : internal_(std::move(internal)) {}

    std::unique_ptr<View> internal_;
};
} // namespace gui