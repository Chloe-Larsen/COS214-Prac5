#include "../include/MedicalResponder.h"

MedicalResponder::MedicalResponder(std::string unitName) : ResponseUnit(nullptr, unitName)
{
    std::cout << ColourHelper::RED << "New medical responder " << unitName << " has been created" << ColourHelper::RESET << std::endl;
}

MedicalResponder::~MedicalResponder()
{
}

void MedicalResponder::dispatch(Incident *incident)
{
    if (!incident)
        return;
    std::cout << ColourHelper::RED << "Medical Responder " << unitName << " responding to Incident(" << incident->getIncidentId() << ")" << ColourHelper::RESET << std::endl;
    send("medical-dispatched");
}

void MedicalResponder::handleCoordinatorEvent(const std::string &event, Incident *incident)
{
    if (!incident)
        return;

    if (event == "path-clear")
    {
        std::cout << ColourHelper::B_YELLOW << "Medical Responder " << unitName << " is advancing to Incident(" << incident->getIncidentId() << ")" << ColourHelper::RESET << std::endl;
        send("medical-on-scene");
    }
    else if (event == "stand-down")
    {
        std::cout << ColourHelper::B_YELLOW << "Medical Responder " << unitName << " stands down for Incident(" << incident->getIncidentId() << ")" << ColourHelper::RESET << std::endl;
    }
}