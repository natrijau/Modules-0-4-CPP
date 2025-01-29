#include	"ClapTrap.hpp"
#include	"ScavTrap.hpp"

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
	scavtrap.takeDamage(15000);
	scavtrap.beRepaired(10);

	return 0;
}
