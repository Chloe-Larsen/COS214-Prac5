#include "FacilitiesStaff.h"
#include <iostream>

FacilitiesStaff::FacilitiesStaff(std::string name_, ResponseMediator* mediator_)
    : ResponseComponent(std::move(name_), mediator_) {}

void FacilitiesStaff::lockArea(const std::string& location) {
    if (locked) {
        std::cout << "[FacilitiesStaff " << name << "] " << location
                   << " already locked, ignoring duplicate lock request\n";
        return;
    }
    locked = true;
    std::cout << "[FacilitiesStaff " << name << "] locked " << location << "\n";
    notifyMediator("AREA_LOCKED");
}

void FacilitiesStaff::unlockArea(const std::string& location) {
    locked = false;
    std::cout << "[FacilitiesStaff " << name << "] unlocked " << location << "\n";
    notifyMediator("AREA_UNLOCKED");
}
