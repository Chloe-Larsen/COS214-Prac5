#include "../include/MedicalResponder.h"

MedicalResponder::MedicalResponder(std::string unitName) : ResponseUnit(nullptr, unitName)
{
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