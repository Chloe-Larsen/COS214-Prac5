#pragma once
#include <string>

class ResponseMediator;

// Colleague base class in the Mediator pattern.
class ResponseComponent {
public:
    ResponseComponent(std::string name, ResponseMediator* mediator)
        : name(std::move(name)), mediator(mediator) {}
    virtual ~ResponseComponent() = default;

    const std::string& getName() const { return name; }
    void setMediator(ResponseMediator* newMediator) { mediator = newMediator; }

protected:
    void notifyMediator(const std::string& event);

    std::string name;
    ResponseMediator* mediator; // non-owning: the mediator's lifetime is managed elsewhere
};
