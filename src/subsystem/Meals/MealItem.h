#pragma once
#include <string>

class MealItem {

public:
    MealItem(std::string, float, std::string, std::string, std::string);
    inline std::string getCustomer() const { return customer_; }
    inline float getQuality() const { return quality_; }
    inline std::string getDiet() const { return diet_; }
    inline std::string getMod() const { return mod_; }
    inline std::string getFood() const { return food_; }
    inline bool isReady() const { return ready_; }
    inline void setReady(bool rStatus_) { ready_ = rStatus_; }
    inline std::string toString() const {
        return "{item: " + food_ + ", quality: " + std::to_string(quality_) +
               ", diet: " + diet_ + ", modifier: " + mod_ + "}";
    }
    bool isEqual(MealItem* other);

private:
    std::string food_;
    std::string customer_;
    float quality_;
    bool ready_ = false;
    std::string diet_ = "none";
    std::string mod_ = "none";
};