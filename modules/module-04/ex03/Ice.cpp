#include	"Ice.hpp"

Ice::Ice()
:	AMateria("ice")
{
	std::cout << "Constructor Ice called" << std::endl;
}

Ice::Ice(const Ice& copy)
{
	std::cout << "Constructor copy Ice called" << std::endl;
	this->_type = copy._type;
}

Ice::~Ice()
{
	std::cout << "Destructor Ice called" << std::endl;
}

AMateria* Ice::clone() const
{
	return new Ice(*this);
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *";
}

Ice	&Ice::operator=(const Ice& fix)
{
	this->_type = fix._type;
	return (*this);
}