#include "Zombie.hpp"

int main()
{
    Zombie *zombie = newZombie("Chill Bill");

    for (int i = 0; i < 1; i++)
    {
        zombie[i].announce();
    }    
    randomChump("Samuele Fiorini");
    delete[] zombie;
    return (0);
}
