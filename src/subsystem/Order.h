#pragma once
#include <string>
/**
 * @brief Component class for the decorator pattern*/
class Order {
public:
    /** * @brief Construct a new Order object */
    Order(std::string name, double price);
    Order();
    /** * @brief virtual destructor */
    virtual ~Order();
    /** * @brief Gets the total cost of all the items in the order */
    virtual double getCost();
    /** *@brief generates a json string of the order */
    virtual std::string getJson() = 0;
    /** * @brief adds an item to the order */
    virtual void add(Order* order) = 0;
    /** * @brief sets the cost of the order */
    void setCost(double price);
    std::string getJsonSting();

private:
    double price;
    std::string name;
};
// https://github.com/sheredom/json.h
//  const char json[] = "{\"a\" : true, \"b\" : [false, null, \"foo\"]}";
//  struct json_value_s* root = json_parse(json, strlen(json));
//  assert(root->type == json_type_object);