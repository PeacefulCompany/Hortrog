#pragma once
#include "order/Modifier.h"
#include "order/Order.h"
#include "order/OrderBuilder.h"
#include "order/OrderComposite.h"
#include "order/OrderItem.h"
#include <stdint.h>

class ConcreteOrderBuilder : public OrderBuilder {
public:
    ConcreteOrderBuilder(const Menu* menu);
	/**
	 * @brief Get the Result json object, also creates order composite
	 * 
	 * @return std::string 
	 */
    std::string getResult();
	/**
	 * @brief create tempOrder vector and setstable id
	 * 
	 * @param tblId 
	 */
    void begin(uint32_t tblId) override;
	/**
	 * @brief Adds an order item to the tempOrder vector with the customer name
	 * 
	 * @param key 
	 * @param customerName 
	 * @return true 
	 * @return false 
	 */
    bool addItem(
        const std::string& key, const std::string& customerName) override;
	/**
	 * @brief Adds a modifier to the tempOrder vector based on last added orderItem
	 * 
	 * @param key 
	 * @return true 
	 * @return false 
	 */
    bool addModifier(const std::string& key) override;
    void setMenu(const Menu* menu) override { menu_ = menu; }
    const Menu* getMenu() const override { return menu_; }

    OrderComposite* getOrder() override { return this->order; };

private:
    uint32_t tblId_;
    const Menu* menu_;

    std::vector<std::unique_ptr<Order>> tempOrder;
    OrderComposite* order;
};