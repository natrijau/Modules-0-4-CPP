#include	"Animal.hpp"

Animal::Animal()
: _type("vide")
{
	std::cout << "Constructor Animal call !" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Destructor Animal call !" << std::endl;
}

const	std::string& Animal::getType() const
{
	return (_type);
}

void Animal::makeSound() const
{
	if (_type == "vide")
	{
		std::cout << "NOTTTT SOUNNNNNNNDDDDDD" << std::endl;
	}
	if (_type == "vide")
	{
		std::cout << "NOTTTT SOUNNNNNNNDDDDDD" << std::endl;
	}
}