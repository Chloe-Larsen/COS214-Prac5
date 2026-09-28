#pragma once
#include <string>

// Strategy pattern: SecurityTeam can be configured with different ways
// of deciding how to approach a dispatch, without SecurityTeam itself
// needing if/else branching on a "mode" flag.
class DispatchStrategy {
public:
    virtual ~DispatchStrategy() = default;
    virtual std::string describeApproach(const std::string& location) const = 0;
};

class NearestUnitStrategy : public DispatchStrategy {
public:
    std::string describeApproach(const std::string& location) const override;
};

class PriorityEscortStrategy : public DispatchStrategy {
public:
    std::string describeApproach(const std::string& location) const override;
};
