#include "Zombie.hpp"

Zombie::Zombie() {
    return ;
}

Zombie::~Zombie(){
    return ;
}

void    Zombie::nameZombie(std::string name)
{
    this->name = name;
}

void    Zombie::announce(void)
{
    std::cout <<
    Zombie::name << ": BraiiiiiiinnnzzzZ..." <<
    std::endl;
}
