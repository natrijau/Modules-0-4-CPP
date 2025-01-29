#include	"ClapTrap.hpp"
#include <limits>

int main()
{
	ClapTrap claptrap("Golem");

	claptrap.attack("gnome");
	claptrap.takeDamage(5);
	claptrap.beRepaired(3);
	claptrap.takeDamage(1);
	claptrap.attack("bandit");
	claptrap.beRepaired(10);
	
	ClapTrap copy(claptrap);
	copy.beRepaired(100);
	copy = claptrap;
	copy.beRepaired(100);

	copy.takeDamage(15000);
	copy.beRepaired(10);

	return 0;
}
