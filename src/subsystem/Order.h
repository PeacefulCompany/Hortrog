#pragma once
#include "json.h"
#include <string>
// template <typename T>
/**
 * @brief Component class for the decorator pattern*/
class Order {
public:
    /** * @brief Gets the total cost of all the items in the order */
    virtual double getCost() = 0;
    /** *@brief generates a json string of the order */
    virtual std::string getJson() = 0;

private:
};
// https://github.com/sheredom/json.h
//  const char json[] = "{\"a\" : true, \"b\" : [false, null, \"foo\"]}";
//  struct json_value_s* root = json_parse(json, strlen(json));
//  assert(root->type == json_type_object);