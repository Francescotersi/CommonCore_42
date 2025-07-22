#include "Zombie.hpp"

Zombie  *newZombie (std::string name)
{
    int     nbZombies = 1;
    Zombie  *zombie = new Zombie[nbZombies];
    
    for (int i = 0; i < nbZombies; i++)
    {
        zombie[i].nameZombie(name);
    }
    return (zombie);
}
