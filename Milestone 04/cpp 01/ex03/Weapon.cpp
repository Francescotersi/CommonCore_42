#include "Weapon.hpp"

Weapon::Weapon(std::string newType)
{
    this->type = newType;
    return ;
}

Weapon::~Weapon()
{
    return ;
}


const std::string& Weapon::getType() const
{
    return (this->type);
}


void    Weapon::setType(std::string newType)
{
    this->type = newType;
}
