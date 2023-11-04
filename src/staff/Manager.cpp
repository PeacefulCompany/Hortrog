#include "Manager.h"
Manager::Manager() : FloorStaff(){};
void Manager::lodgeComplaint(const std::string& complaint) {
    this->complaintArray_.push_back(new std::string(complaint));
}

void Manager::giveRating(int rating) {
    std::cout << "Customer rating: " << rating << std::endl;
    // Handle the rating...
}
void Manager::accept(CustomerState& state) { state.visit(*this); }
std::string Manager::getStaffType() { return "Manager"; }