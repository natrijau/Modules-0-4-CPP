#ifndef __FRAGTRAP_HPP__
#define __FRAGTRAP_HPP__

#include    "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    private:
        /* data */
    public:
        FragTrap(std::string name);
        FragTrap();
		FragTrap(const FragTrap& copy);
        ~FragTrap();

        void    highFivesGuys(void);

		FragTrap &operator=(const FragTrap& n);
};

#endif