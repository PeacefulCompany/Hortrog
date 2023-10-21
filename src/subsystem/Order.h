#pragma once
#include <stdio.h>
#include <jsoncpp/json/json.h>
#include <jsoncpp/json/reader.h>
#include <jsoncpp/json/writer.h>
#include <jsoncpp/json/value.h>
#include <string
//
// template <typename T>
class Order {
public:
    virtual double getCost() = 0;
    string getJson() = 0;  
private:
};
//https://stackoverflow.com/questions/31121378/json-cpp-how-to-initialize-from-string-and-get-string-value
//Example of how to use jsoncpp
//  std::string strJson = "{\"mykey\" : \"myvalue\"}"; // need escape the quotes

//     Json::Value root;   
//     Json::Reader reader;
//     bool parsingSuccessful = reader.parse( strJson.c_str(), root );     //parse process
//     if ( !parsingSuccessful )
//     {
//         std::cout  << "Failed to parse"
//                << reader.getFormattedErrorMessages();
//         return 0;
//     }
//     std::cout << root.get("mykey", "A Default Value if not exists" ).asString() << std::endl;
//     return 0;