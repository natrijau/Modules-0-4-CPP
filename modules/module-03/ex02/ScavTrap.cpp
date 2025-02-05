#include	"ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name)
:   ClapTrap(name)
{
    _hitPoint = 100;
    _energiePoint = 50;
    _attackDamage = 20;
	std::cout << "ScavTrap " << _name << " created!" << std::endl;
}

ScavTrap::ScavTrap()
:   ClapTrap()
{
    _hitPoint = 100;
    _energiePoint = 50;
    _attackDamage = 20;
	std::cout << "ScavTrap " << _name << " created!" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (_energiePoint >= 1 && _hitPoint > 0)
	{
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energiePoint--;
		return;
	}
	std::cout << "ScavTrap " << _name << " cannot attack, no energy or hit points left!" << std::endl;
}

void    ScavTrap::gardeGate()
{
	if (_hitPoint > 0)
	    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
	else
	    std::cout << "ScavTrap " << _name << " do not have enough life to switch to Gate Guardian mode" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy)
:	ClapTrap(copy)
{
	*this = copy;
	std::cout << "ScavTrap copy !" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap& fix)
{
	this->_attackDamage = fix._attackDamage;
	this->_hitPoint = fix._hitPoint;
	this->_energiePoint = fix._energiePoint;
	this->_attackDamage = fix._attackDamage;
	std::cout << "surcharge opereator '=' !" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " destroyed!" << std::endl;
}
