#include "Incident.h"
#include "IncidentObserver.h"
#include <algorithm>
#include <iostream>

std::string toString(IncidentStatus status) {
    switch (status) {
        case IncidentStatus::REPORTED:   return "REPORTED";
        case IncidentStatus::DISPATCHED: return "DISPATCHED";
        case IncidentStatus::CONTAINED:  return "CONTAINED";
        case IncidentStatus::RESOLVED:   return "RESOLVED";
    }
    return "UNKNOWN";
}

Incident::Incident(std::string id_, std::string location_, std::string description_)
    : id(std::move(id_)), location(std::move(location_)), description(std::move(description_)),
      status(IncidentStatus::REPORTED) {}

void Incident::setStatus(IncidentStatus newStatus) {
    status = newStatus;
    std::cout << "[Incident " << id << "] status -> " << toString(status) << "\n";
    notifyObservers();
}

void Incident::attach(IncidentObserver* observer) {
    observers.push_back(observer);
}

void Incident::detach(IncidentObserver* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void Incident::notifyObservers() {
    for (auto* observer : observers) {
        observer->onIncidentStatusChanged(*this);
    }
}
