#include "Zombie.hpp"

Zombie::Zombie(std::string name)
: _name(name)
{
	std::cout << "Constructor call" << std::endl;
}
Zombie::~Zombie()
{
	std::cout << "Destructor call" << std::endl;
}

void    Zombie::announce(void)
{
	std::cout << _name << " :" << " BraiiiiiiinnnzzzZ..." << std::endl;
}