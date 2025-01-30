#include	"WrongCat.hpp"
#include	"WrongAnimal.hpp"

WrongCat::WrongCat()
:	WrongAnimal()
{
	_type = "WrongCat";
	std::cout << "Constructor WrongCat called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "Constructor WrongCat called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy)
: WrongAnimal()
{
	*this = copy;
	std::cout << "Copy constructor WrongCat called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat& src)
{
	std::cout << "Surcharge operator '='" << std::endl;
	if (this == &src)
		return (*this);
	this->_type = src._type;
	return (*this);	
}

void WrongCat::makeSound() const
{
	std::cout << "The WrongCat say Miaaaaouuuuu" << std::endl;
}
