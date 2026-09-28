#pragma once
#include <string>

// Target interface: what CampusGuard code wants to call.
class AlertSystem {
public:
    virtual ~AlertSystem() = default;
    virtual void sendAlert(const std::string& message) = 0;
};
