#pragma once
#include "game/Object.h"
#include "gui/View.h"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace nlohmann;
using namespace std;
class Waiter : public Object, public virtual gui::View {
public:
    Waiter() = delete;
    Waiter(int x, int y, int icon_);
    virtual ~Waiter();
    void TakeOrder(vector<string> TableList);
    json placeOrder();
    void ServeOrder();
    void offerBill();
    sf::FloatRect getBoundingBox() const;
    sf::Vector2f position() const;
    void position(sf::Vector2f v);
    void draw(sf::RenderTarget& window) const;

protected:
private:
    std::vector<int> TableList;
    json currentOrder_;
};