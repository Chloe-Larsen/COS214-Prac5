#pragma once
#include "ResponseComponent.h"
#include <memory>

class DispatchStrategy;

class SecurityTeam : public ResponseComponent {
public:
    SecurityTeam(std::string name, ResponseMediator* mediator,
                 std::unique_ptr<DispatchStrategy> strategy);
    ~SecurityTeam() override;

    void dispatchTo(const std::string& location);
    bool isDispatched() const { return dispatched; }

    void setStrategy(std::unique_ptr<DispatchStrategy> strategy);

private:
    std::unique_ptr<DispatchStrategy> strategy; // SecurityTeam owns its strategy
    bool dispatched = false;
};
