#ifndef __FRAGTRAP_HPP__
#define __FRAGTRAP_HPP__

#include    "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    private:
        /* data */
    public:
        FragTrap(std::string name);
        ~FragTrap();

        void    highFivesGuys(void);
};

#endif