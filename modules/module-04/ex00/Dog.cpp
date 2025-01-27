#include	"Dog.hpp"
#include	"Animal.hpp"

Dog::Dog()
:	Animal()
{
	_type = "Dog";
	std::cout << "Constructor Dog call !" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Destructor Dog call !" << std::endl;
}

void Dog::makeSound()
{
	std::cout << "The dog say woafwoaf !" << std::endl;
}