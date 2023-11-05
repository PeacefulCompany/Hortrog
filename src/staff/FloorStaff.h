#pragma once
#include "customer/CustomerState.h"
#include "subsystem/Chef/Kitchen.h"
#include "subsystem/Meals/Meal.h"
#include <string>
/**
 * @class FloorStaff
 * @brief This class represents a staff member on the floor.
 *
 * The FloorStaff class is an abstract base class that provides an interface for
 * different types of floor staff aswell as a being the element in the visitor
 * pattern.
 */
class FloorStaff {
public:
    /**
     * @brief Default constructor for FloorStaff.
     */
    FloorStaff() { currentTableId_ = -1; };
    /**
     * @brief Pure virtual function for accepting a customer state.
     *
     * This function is overridden by derived classes to provide specific
     * behavior when a customer state is accepted.
     *
     * @param state The customer state to accept.
     */
    virtual void accept(CustomerState& state) = 0;
    virtual std::string getStaffType() = 0;
    int currentTableId_;

    static void setKitchen(Kitchen* kitchen) {
        if (kitchen_ == nullptr) {
            kitchen_ = kitchen;
        } else {
            //  std::cout << "Kitchen already set" << std::endl;
        }
    }
    static Kitchen* getKitchen() { return kitchen_; }

private:
    /**
     * @brief all children know about one kitchen
     *
     */
    static Kitchen* kitchen_;
};
/**
 * @brief Initialize the static member kitchen_ with nullptr.
 *
 * This ensures that all instances of FloorStaff share the same Kitchen
 * instance. Before using this, make sure to set the Kitchen instance using
 * FloorStaff::setKitchen(new Kitchen());.
 */
Kitchen* FloorStaff::kitchen_ = nullptr;