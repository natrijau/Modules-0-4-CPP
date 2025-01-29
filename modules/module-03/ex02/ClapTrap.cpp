#include	"ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
:	_name(name), _hitPoint(10), _energiePoint(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
:	_name(copy._name), _hitPoint(copy._hitPoint), _energiePoint(copy._energiePoint), _attackDamage(copy._attackDamage)
{
	std::cout << "ClapTrap copy !" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_energiePoint >= 1 && _hitPoint > 0)
	{
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energiePoint--;
		return;
	}
	std::cout << "ClapTrap " << _name << " cannot attack, no energy or hit points left!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	_hitPoint -= amount;

	std::cout << "ClapTrap " << _name << " take " << amount << " damage!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energiePoint >= 1 && _hitPoint > 0)
	{
		_hitPoint += amount;	
		_energiePoint--;
		std::cout << "ClapTrap " << _name << " repairs itself from " <<  amount << " and its life is at " << _hitPoint << " !" <<  std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name << " cannot repair, no energy or hit points left!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap& fix)
{
	this->_attackDamage = fix._attackDamage;
	this->_hitPoint = fix._hitPoint;
	this->_energiePoint = fix._energiePoint;
	this->_attackDamage = fix._attackDamage;
	std::cout << "surcharge opereator '=' !" << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " destroyed!" << std::endl;
}
