#pragma once

#include "Order.h"
#include "OrderItem.h"

class Modifier : public Order {
protected:
    std::unique_ptr<Order> component_;
    std::string key_;
    double price_;
    std::vector<std::pair<std::string, double>>
	/**
	 * @brief Construct a new generate Receipt Order List object
	 * 
	 */
    generateReceiptOrderList() override;

public:
	/**
	 * @brief Construct a new Modifier object from an OrderItem
	 * 
	 * @param component 
	 */
    Modifier(std::unique_ptr<Order> component);
    void add(std::unique_ptr<Order>) override {}
    double total() override;
	/**
	 * @brief Return modifier as JSON
	 * 
	 * @return std::string 
	 */
    std::string toJson() override;
	/**
	 * @brief Construct a new Modifier object with key
	 * 
	 * @param component 
	 * @param key 
	 */
    explicit Modifier(std::unique_ptr<Order> component, std::string key);
};