#pragma once

/**
 * @brief the Decorator class for the MenuItem
    *     
 */
class Order;
class MenuItem : public Order {
    public:
        /**
         * @brief Construct a new Menu Item object
         * 
         * @param name 
         * @param price 
         */
        MenuItem(string name, double price);
        /**
         * @brief Get the Cost object
         * 
         * @return double 
         */
        double getCost();
        /**
         * @brief Get the Json object
         * 
         * @return string 
         */
        string getJson();
    protected:
        /**
         * @brief Construct a new Menu Item object
         * 
         */
        MenuItem();
        /**
         * @brief Construct a new Menu Item object
         * 
         * @param order 
         */
        MenuItem(Order* order);
    private:
        Order* order;
};