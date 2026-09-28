#include "SecurityTeam.h"
#include "DispatchStrategy.h"
#include <iostream>

SecurityTeam::SecurityTeam(std::string name_, ResponseMediator* mediator_,
                            std::unique_ptr<DispatchStrategy> strategy_)
    : ResponseComponent(std::move(name_), mediator_), strategy(std::move(strategy_)) {}

SecurityTeam::~SecurityTeam() = default;

void SecurityTeam::setStrategy(std::unique_ptr<DispatchStrategy> newStrategy) {
    strategy = std::move(newStrategy);
}

void SecurityTeam::dispatchTo(const std::string& location) {
    dispatched = true;
    std::cout << "[SecurityTeam " << name << "] " << strategy->describeApproach(location) << "\n";
    notifyMediator("SECURITY_DISPATCHED");
}
