#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->name = name;
}

Zombie::Zombie() {
    return ;
}

Zombie::~Zombie(){
    std::cout << this->name << std::endl;
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
