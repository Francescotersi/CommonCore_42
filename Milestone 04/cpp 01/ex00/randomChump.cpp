#include "Zombie.hpp"

void randomChump(std::string name)
{
    Zombie _zombie;

    _zombie.nameZombie(name);
    _zombie.announce();
}
