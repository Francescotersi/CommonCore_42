#include "Zombie.hpp"

int main()
{
    Zombie *zombie = newZombie("Chill Bill");
    
    zombie->announce();  
    randomChump("Samuele Fiorini");
    delete[] zombie;
    return (0);
}
