#include "Zombie.hpp"

void randomChump(std::string name)
{
    Zombie _zombie = Zombie(name);

    _zombie.announce();
}
