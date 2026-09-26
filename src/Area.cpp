#include "../include/Area.h"

Area::Area(std::string name) : AreaComponent(name), isLocked(false)
{
    std::cout << ColourHelper::CYAN << name << " (Area) has been created and is unlocked" << ColourHelper::RESET << std::endl;
}

Area::~Area()
{
}

void Area::lock()
{
    if (!isLocked)
    {
        isLocked = true;
        std::cout << ColourHelper::CYAN << this->getName() << " has been locked" << ColourHelper::RESET << std::endl;
    }
    else
        std::cout << ColourHelper::CYAN << this->getName() << " is already locked" << ColourHelper::RESET << std::endl;
}

void Area::unlock()
{
    if (isLocked)
    {
        isLocked = false;
        std::cout << ColourHelper::CYAN << this->getName() << " has been unlocked" << ColourHelper::RESET << std::endl;
    }
    else
        std::cout << ColourHelper::CYAN << this->getName() << " is already unlocked" << ColourHelper::RESET << std::endl;
}
