#pragma once
#include "ResponseComponent.h"

class MedicalTeam : public ResponseComponent {
public:
    MedicalTeam(std::string name, ResponseMediator* mediator);

    void treatAt(const std::string& location);
    bool isOnScene() const { return onScene; }

private:
    bool onScene = false;
};
