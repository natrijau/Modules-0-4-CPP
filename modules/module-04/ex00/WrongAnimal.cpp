#include	"WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
: _type()
{
	std::cout << "Constructor WrongAnimal called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor WrongAnimal called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
:	_type(copy._type)
{
	std::cout << "Constructor WrongAnimal Copy" << std::endl;
}

const	std::string& WrongAnimal::getType() const
{
	return (_type);
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal& n)
{
	this->_type = n._type;
	std::cout << "Surcharge operator '='" << std::endl;
	return (*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << "WRONGANIMAL SOUND" << std::endl;
}