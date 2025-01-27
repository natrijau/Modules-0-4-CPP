#include	"Cat.hpp"
#include	"Animal.hpp"

Cat::Cat()
:	Animal()
{
	_type = "Cat";
	std::cout << "Constructor Cat call !" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Constructor Cat call !" << std::endl;
}

void Cat::makeSound()
{
	std::cout << "The Cat say Miaaaaouuuuu !" << std::endl;
}
