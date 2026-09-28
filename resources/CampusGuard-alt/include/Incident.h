#pragma once
#include <string>
#include <vector>

enum class IncidentStatus { REPORTED, DISPATCHED, CONTAINED, RESOLVED };

std::string toString(IncidentStatus status);

class IncidentObserver;

// Subject in the Observer pattern. Also the Receiver that Commands act on.
class Incident {
public:
    Incident(std::string id, std::string location, std::string description);

    void setStatus(IncidentStatus newStatus);
    IncidentStatus getStatus() const { return status; }
    const std::string& getId() const { return id; }
    const std::string& getLocation() const { return location; }
    const std::string& getDescription() const { return description; }

    void attach(IncidentObserver* observer);
    void detach(IncidentObserver* observer);

private:
    void notifyObservers();

    std::string id;
    std::string location;
    std::string description;
    IncidentStatus status;
    std::vector<IncidentObserver*> observers; // non-owning: Incident does not own its observers
};
