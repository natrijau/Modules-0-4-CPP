#include    "FragTrap.hpp"

FragTrap::FragTrap(std::string name)
:   ClapTrap(name)
{
	_hitPoint = 100;
	_energiePoint = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " created!" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " destroyed!" << std::endl;
}

void	FragTrap::highFivesGuys()
{
	std::cout << "Give me five" << std::endl;
}