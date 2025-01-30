#include	"Cat.hpp"
#include	"Animal.hpp"

Cat::Cat()
:	Animal()
{
	_type = "Cat";
	std::cout << "Constructor Cat called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Constructor Cat called" << std::endl;
}

Cat::Cat(const Cat& copy)
: Animal()
{
	*this = copy;
	std::cout << "Copy constructor Cat called" << std::endl;
}

Cat &Cat::operator=(const Cat& src)
{
	std::cout << "Surcharge operator '='" << std::endl;
	if (this == &src)
		return (*this);
	this->_type = src._type;
	return (*this);	
}

void Cat::makeSound() const
{
	std::cout << "The Cat say Miaaaaouuuuu" << std::endl;
}
