#include	"ClapTrap.hpp"
#include	"ScavTrap.hpp"
#include	"FragTrap.hpp"

int main()
{
	ClapTrap claptrap("Golem");

	claptrap.attack("gnome");
	claptrap.takeDamage(5);
	claptrap.beRepaired(3);
	claptrap.takeDamage(10);
	claptrap.attack("bandit");
	claptrap.beRepaired(10);

	ScavTrap scavtrap("BOSS");

	scavtrap.takeDamage(50);
	scavtrap.attack("ennemy");
	scavtrap.gardeGate();

	FragTrap fragtrap("BIG BOSS");
	fragtrap.takeDamage(3520651651);
	fragtrap.attack("ennemy");
	fragtrap.beRepaired(150);
	fragtrap.highFivesGuys();

	return 0;
}
