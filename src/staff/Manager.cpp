#include "Manager.h"
Manager::Manager() : FloorStaff(){};
void Manager::lodgeComplaint(const std::string& complaint) {
    std::cout << "Customer complaint: " << complaint << std::endl;
    // Handle the complaint...
}

void Manager::giveRating(int rating) {
    std::cout << "Customer rating: " << rating << std::endl;
    // Handle the rating...
}
void Manager::accept(CustomerState& state) { state.visit(*this); }