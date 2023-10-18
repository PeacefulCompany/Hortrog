#pragma once

#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/System/Vector2.hpp"
#include <memory>
#include <type_traits>

namespace gui {
using Rect = sf::FloatRect;
using Vec2 = sf::Vector2f;
using Tex2D = sf::Texture;
using Target = sf::RenderTarget;

/**
 * @brief Implemenation-agnostic representation of anything that can be rendered
 * to screen
 *
 * This serves as a light abstraction over whatever library we use, such that
 * our work is as decoupled from the the underlying graphics library as
 * possible. SFML does have a @link sf::Drawable @endlink type, however this
 * class provides looser coupling and a couple extra useful features. In
 * particular, this allows for the decoration of drawable objects, e.g.
 * decorating sprites with an ability to be clicked
 */
class Drawable {
public:
    virtual ~Drawable() {}

    /**
     * @brief Draws the object to passed-in render target
     *
     * @param target The target to draw to
     */
    virtual void draw(Target& target) const = 0;

    /**
     * @brief Updates time-based features (e.g. sprite animation)
     *
     * @param dt Time (in seconds) since the last draw
     */
    virtual void update(float dt) {}

    /**
     * @brief Computes the bounding box of the object
     *
     * @return the bounding box
     */
    virtual Rect getBoundingBox() const = 0;
};

template <class T>
concept IsDrawable = std::is_base_of<Drawable, T>::value;

/**
 * @brief Base class for adding functionality to a drawable object
 *
 */
class DrawableDecorator : public Drawable {
public:
    inline virtual void draw(Target& t) const override { _pInternal->draw(t); }
    inline virtual void update(float dt) override { _pInternal->update(dt); }
    inline virtual Rect getBoundingBox() const override {
        return _pInternal->getBoundingBox();
    };

    /**
     * @brief Retrieves a pointer to the internal object of the decorator
     *
     * @tparam D The type of the internal pointer (defaults to Drawable)
     * @return D* Non-owning pointer to the decoratee
     */
    template <IsDrawable D = Drawable>
    inline D* get() const {
        return static_cast<D*>(_pInternal.get());
    }

    /**
     * @brief "Un-decorates" the internal object and releases ownership
     *
     * @tparam D The type of the internal object (defaults to Drawable)
     * @return D* Owning pointer to the decoratee
     */
    template <IsDrawable D = Drawable>
    inline D* unwrap() {
        return static_cast<D*>(_pInternal.release());
    }

protected:
    inline DrawableDecorator(std::unique_ptr<Drawable> internal)
        : _pInternal(std::move(internal)) {}

    std::unique_ptr<Drawable> _pInternal;
};

} // namespace gui