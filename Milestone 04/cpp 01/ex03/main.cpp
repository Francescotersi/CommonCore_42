#include <iostream>
#include <string>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp" 


int main()
{
    {
        Weapon club = Weapon("Long sword");
        HumanA bob("Henry", club);
        bob.attack();
        club.setType("some other type of sword");
        bob.attack();
    }
    {
        Weapon club = Weapon("Long bow");
        HumanB jim("Hans Capon");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of bow");
        jim.attack();
        return 0;
    }
 }