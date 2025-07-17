#include "Weapon.hpp"
#include <string>
#include <iostream>

HumanA::~HumanA()
{
    return ;
}

void    HumanA::attack()
{
    std::cout <<
    this->name <<
    " attacks with their " <<
    this->weapon.getType() <<
    std::endl;
}

