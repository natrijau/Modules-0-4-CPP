#include	"ClapTrap.hpp"

int main()
{
	ClapTrap claptrap("Golem");

	claptrap.attack("gnome");
	claptrap.takeDamage(5);
	claptrap.beRepaired(3);
	claptrap.takeDamage(10);
	claptrap.attack("bandit");
	claptrap.beRepaired(10);

	return 0;
}
