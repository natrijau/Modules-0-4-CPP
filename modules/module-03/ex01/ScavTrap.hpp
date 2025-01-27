#ifndef __SCAVTRAP_HPP__
#define __SCAVTRAP_HPP__

#include	"ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    private:
        /* data */
    public:

		void	attack(const std::string& target);
        void    gardeGate();

        ScavTrap(std::string name);
        ~ScavTrap();
};


#endif