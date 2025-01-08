#include	"HumanB.hpp"

HumanB::HumanB(const std::string& name)
: _name(name) , weapon(NULL) {}

HumanB::~HumanB()
{}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}

void	HumanB::attack() const
{
	if (!weapon)
	{
		std::cout	<< _name
				<< " n'a pas d'arme et attaque avec ses poings"
				<< std::endl;
		return ;
	}
	std::cout	<< _name
				<< " attaques avec "
				<< weapon->getType()
				<< std::endl;
}
