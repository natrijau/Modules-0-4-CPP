#include	"Dog.hpp"
#include	"Animal.hpp"

Dog::Dog()
:	Animal()
{
	_type = "Dog";
	std::cout << "Constructor Dog called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Destructor Dog called" << std::endl;
}

Dog::Dog(const Dog& copy)
: Animal()
{
	*this = copy;
	std::cout << "Copy constructor Dog called" << std::endl;
}

Dog &Dog::operator=(const Dog& src)
{
	std::cout << "operator '='" << std::endl;
	if (this == &src)
		return (*this);
	this->_type = src._type;
	return (*this);
}


void Dog::makeSound() const
{
	std::cout << "The dog say woafwoaf" << std::endl;
}