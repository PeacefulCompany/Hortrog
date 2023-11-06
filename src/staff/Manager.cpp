#include "Manager.h"

#include "floor/CustomerIterator.h"
#include "floor/Floor.h"

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
std::string Manager::toString() const { return "Manager"; }

void Manager::visitTables() {
    for (Table* t : floor_->getTables()) {
        CustomerIterator* it = t->createIterator();
        while (!it->isDone()) {
            it->get()->interact(*this);
            it->next();
        }
    }
}

void Manager::accept(CustomerState& state) { state.visit(*this); }
std::string Manager::getStaffType() { return "Manager"; }