#include	"Weapon.hpp"

Weapon::Weapon(const std::string& type)
: _weapon(type) {}

Weapon::~Weapon()
{}

const	std::string& Weapon::getType() const
{
	return (_weapon);
}

void	Weapon::setType(const std::string& type)
{
	this->_weapon = type;
}
