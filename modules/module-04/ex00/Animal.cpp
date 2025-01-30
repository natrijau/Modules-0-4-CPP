#include	"Animal.hpp"

Animal::Animal()
: _type()
{
	std::cout << "Constructor Animal called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Destructor Animal called" << std::endl;
}

Animal::Animal(const Animal& copy)
:	_type(copy._type)
{
	std::cout << "Constructor Animal Copy" << std::endl;
}

const	std::string& Animal::getType() const
{
	return (_type);
}

Animal	&Animal::operator=(const Animal& n)
{
	this->_type = n._type;
	std::cout << "Surcharge operator '='" << std::endl;
	return (*this);
}

void Animal::makeSound() const
{
	std::cout << "NOTTTT SOUNNNNNNNDDDDDD" << std::endl;
}