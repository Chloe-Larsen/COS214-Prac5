#include "../include/AreaGroup.h"
#include <algorithm>

AreaGroup::AreaGroup(std::string name) : AreaComponent(name)
{
    std::cout << ColourHelper::CYAN << name << "(Area Group) has been created" << ColourHelper::RESET << std::endl;
}

AreaGroup::~AreaGroup()
{
    for (AreaComponent *child : children)
    {
        delete child;
    }
    children.clear();
}

void AreaGroup::lock()
{
    std::cout << ColourHelper::CYAN << ColourHelper::UNDERLINE << this->getName() << " is beginning the lock process" << ColourHelper::RESET << std::endl;
    for (AreaComponent *child : children)
    {
        std::cout << "\t";
        child->lock();
    }    
}

void AreaGroup::unlock()
{
    std::cout << ColourHelper::CYAN << ColourHelper::UNDERLINE  << this->getName() << " is beginning the unlock process" << ColourHelper::RESET << std::endl;
    for (AreaComponent *child : children)
    {
        std::cout << "\t";
        child->unlock();
    }    
}

void AreaGroup::restrict()
{
    std::cout << ColourHelper::CYAN << ColourHelper::UNDERLINE  << this->getName() << " is beginning the restriction process" << ColourHelper::RESET << std::endl;
    for (AreaComponent *child : children)
    {
        std::cout << "\t";
        child->restrict();
    }    
}

void AreaGroup::add(AreaComponent *component)
{
    std::cout << ColourHelper::CYAN << ColourHelper::UNDERLINE  << component->getName() << " has been added to " << this->getName() << ColourHelper::RESET << std::endl;
    children.push_back(component);
}

void AreaGroup::remove(AreaComponent *component)
{
    std::cout << ColourHelper::CYAN << ColourHelper::UNDERLINE << component->getName() << " has been removed from " << this->getName() << ColourHelper::RESET << std::endl;
    children.erase(std::remove(children.begin(), children.end(), component),children.end());
}