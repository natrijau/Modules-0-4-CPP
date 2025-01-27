#include	"ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
:	_name(name), _hitPoint(10), _energiePoint(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " created!" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_energiePoint >= 1 && _hitPoint > 0)
	{
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		takeDamage(_attackDamage);
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
		if (_hitPoint >= 10)
			_hitPoint = 10;
		_energiePoint--;
		return;
	}
	std::cout << "ClapTrap " << _name << " cannot repair, no energy or hit points left!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " destroyed!" << std::endl;
}
