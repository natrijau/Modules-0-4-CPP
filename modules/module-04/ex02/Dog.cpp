#include	"Dog.hpp"
#include	"AAnimal.hpp"
#include 	"Brain.hpp"

Dog::Dog()
:	AAnimal()
{
	_brain = new Brain();
	_type = "Dog";
	std::cout << "Constructor Dog called" << std::endl;
}

Dog::~Dog()
{
	delete(_brain);
	std::cout << "Destructor Dog called" << std::endl;
}

Dog::Dog(const Dog& copy)
: AAnimal()
{
	*this = copy;
	std::cout << "Copy constructor Dog called" << std::endl;
}

Dog &Dog::operator=(const Dog& src)
{
	std::cout << "Surcharge operator '='" << std::endl;
	if (this == &src)
		return (*this);
	this->_brain = new Brain(*src._brain);
	this->_type = src._type;
	return (*this);	
}

const std::string Dog::getIdea(unsigned int i) const
{
	return (this->_brain->getIdea(i));
}

void Dog::makeSound() const
{
	std::cout << "The dog say woafwoaf" << std::endl;
}

void	Dog::setIdea(std::string idea)
{
	this->_brain->setIdea(idea);
}