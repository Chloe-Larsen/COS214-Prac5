#pragma once
#include <string>

class ResponseComponent;

// Mediator interface: colleagues talk through this instead of directly to each other.
class ResponseMediator {
public:
    virtual ~ResponseMediator() = default;
    virtual void notify(ResponseComponent* sender, const std::string& event) = 0;
};
