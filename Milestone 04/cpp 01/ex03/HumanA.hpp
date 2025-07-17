#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.h"

class HumanA
{
    private:
        std::string name;
        Weapon      &weapon;

    public:
        HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon) {};
        ~HumanA();

        void    attack();
} ;

#endif