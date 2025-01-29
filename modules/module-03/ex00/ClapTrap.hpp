#ifndef	__CLAPTRAP_HPP__
#define	__CLAPTRAP_HPP__

#include	<iostream>
#include	<string>

class ClapTrap
{
	private:
		std::string	_name;
		int			_hitPoint;
		int			_energiePoint;
		int			_attackDamage;

	public:

		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& copy);
		~ClapTrap();

		ClapTrap &operator=(const ClapTrap& n);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

};

#endif