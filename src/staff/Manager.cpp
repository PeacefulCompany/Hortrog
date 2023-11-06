#include "Manager.h"
Manager::Manager() : FloorStaff(){};
void Manager::lodgeComplaint(const std::string& complaint) {
    this->complaintArray_.push_back(new std::string(complaint));
}

void Manager::giveRating(int rating) {
    this->totalRating_ ++;
    this->numberOfRatings_++;
    std::cout << "[Manager/giveRating] Rating: " << rating << std::endl;
    std::cout << "[Manager/giveRating] Average Rating: "
              << this->totalRating_ / this->numberOfRatings_ << std::endl;
}
void Manager::accept(CustomerState& state) { state.visit(*this); }
std::string Manager::getStaffType() { return "Manager"; }