#pragma once

#include "Order.h"
#include <string>
#include <vector>

class OrderComposite : public Order {
protected:
    std::vector<std::pair<std::string, double>>
	/**
	 * @brief Construct a new generate Receipt Order List object
	 * 
	 */
    generateReceiptOrderList() override;

private:
    std::vector<std::unique_ptr<Order>> orders_;

public:
	/**
	 * @brief Add an order to the orders_ vector
	 * 
	 * @param order 
	 */
    void add(std::unique_ptr<Order> order) override;
	/**
	 * @brief Return orders_ as JSON
	 * 
	 * @return std::string 
	 */
    std::string toJson() override;
    double total() override;
    std::string getId() override { return ""; };
};