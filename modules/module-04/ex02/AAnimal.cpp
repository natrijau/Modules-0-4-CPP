#include	"AAnimal.hpp"

AAnimal::AAnimal()
: _type()
{
	std::cout << "Constructor AAnimal called" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "Destructor AAnimal called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& copy)
:	_type(copy._type)
{
	std::cout << "Constructor AAnimal Copy" << std::endl;
}

const	std::string& AAnimal::getType() const
{
	return (_type);
}

AAnimal	&AAnimal::operator=(const AAnimal& n)
{
	this->_type = n._type;
	std::cout << "Surcharge operator '='" << std::endl;
	return (*this);
}
