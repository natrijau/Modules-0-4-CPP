#include	"Cat.hpp"
#include	"AAnimal.hpp"

Cat::Cat()
:	AAnimal()
{
	_brain = new Brain();
	_type = "Cat";
	std::cout << "Constructor Cat called" << std::endl;
}

Cat::~Cat()
{
	delete(_brain);
	std::cout << "Constructor Cat called" << std::endl;
}

Cat::Cat(const Cat& copy)
: AAnimal()
{
	std::cout << "Copy constructor Cat called" << std::endl;
	this->_brain = copy._brain;
	*this = copy;
}

Cat &Cat::operator=(const Cat& src)
{
	std::cout << "Surcharge operator '='" << std::endl;
	if (this == &src)
		return (*this);
	delete(this->_brain);	
	this->_brain = new Brain(*src._brain);
	this->_type = src._type;
	return (*this);	
}

const std::string Cat::getIdea(unsigned int i) const
{
	return (this->_brain->getIdea(i));
}

void Cat::makeSound() const
{
	std::cout << "The Cat say Miaaaaouuuuu" << std::endl;
}

void	Cat::setIdea(std::string idea)
{
	this->_brain->setIdea(idea);
}