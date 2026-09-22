#include "../include/Incident.h"

Incident::Incident(std::string incidentId, std::string location, std::string description, int severity, IncidentState *currentState)
{
}

Incident::~Incident()
{
}

void Incident::setState(IncidentState *state)
{	
}

void Incident::dispatch()
{
}

void Incident::resolve()
{
}

void Incident::close()
{
}

void Incident::cancel()
{
}

std::string Incident::getStatusName()
{
}