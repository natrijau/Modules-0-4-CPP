#include    "FragTrap.hpp"

FragTrap::FragTrap(std::string name)
:   ClapTrap(name)
{
	_hitPoint = 100;
	_energiePoint = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " created!" << std::endl;
}

FragTrap::FragTrap()
:   ClapTrap()
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

FragTrap::FragTrap(const FragTrap& copy)
{
	*this = copy;
	std::cout << "FragTrap copy !" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap& fix)
{
	this->_attackDamage = fix._attackDamage;
	this->_hitPoint = fix._hitPoint;
	this->_energiePoint = fix._energiePoint;
	this->_attackDamage = fix._attackDamage;
	std::cout << "surcharge opereator '=' !" << std::endl;
	return (*this);
}

void	FragTrap::highFivesGuys()
{
	std::cout << "Give me five" << std::endl;
}