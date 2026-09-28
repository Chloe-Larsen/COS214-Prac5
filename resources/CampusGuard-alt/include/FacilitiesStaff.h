#pragma once
#include "ResponseComponent.h"

class FacilitiesStaff : public ResponseComponent {
public:
    FacilitiesStaff(std::string name, ResponseMediator* mediator);

    void lockArea(const std::string& location);
    void unlockArea(const std::string& location);
    bool isLocked() const { return locked; }

private:
    bool locked = false;
};
