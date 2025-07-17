#include "Zombie.hpp"

int main()
{
    int     hordeSize = 10;
    Zombie *zombie = zombieHorde(hordeSize, "Chill Bill");

    for (int i = 0; i < hordeSize; i++)
    {
        zombie[i].announce();
    }    
    delete[] zombie;
    return (0);
}
