#include	"ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name)
:   ClapTrap(name)
{
    _hitPoint = 100;
    _energiePoint = 50;
    _attackDamage = 20;
	std::cout << "ScavTrap " << _name << " created!" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (_energiePoint >= 1)
	{
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		takeDamage(_attackDamage);
		_energiePoint--;
		return;
	}
	std::cout << "ClapTrap " << _name << " cannot attack, no energy or hit points left!" << std::endl;
}

void    ScavTrap::gardeGate()
{
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " destroyed!" << std::endl;
}
