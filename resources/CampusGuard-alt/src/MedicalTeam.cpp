#include "MedicalTeam.h"
#include <iostream>

MedicalTeam::MedicalTeam(std::string name_, ResponseMediator* mediator_)
    : ResponseComponent(std::move(name_), mediator_) {}

void MedicalTeam::treatAt(const std::string& location) {
    if (onScene) {
        std::cout << "[MedicalTeam " << name << "] already on scene at " << location << "\n";
        return;
    }
    onScene = true;
    std::cout << "[MedicalTeam " << name << "] responding to " << location << "\n";
    notifyMediator("MEDICAL_ON_SCENE");
}
