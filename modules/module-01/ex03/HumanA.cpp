#include	"HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& weapon)
: _name(name), weapon(weapon) {}

HumanA::~HumanA()
{}

void	HumanA::attack() const
{
	std::cout	<< _name
				<< " attaques avec "
				<< weapon.getType()
				<< std::endl;
}
