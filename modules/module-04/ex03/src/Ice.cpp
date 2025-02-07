#include	"Ice.hpp"

Ice::Ice()
:	AMateria("ice")
{
	// std::cout << "Constructor Ice called" << std::endl;
}

Ice::Ice(std::string const & type)
:	AMateria(type)
{
	// std::cout << "Constructor assign type Ice called" << std::endl;
}

Ice::Ice(const Ice& copy)
:	AMateria(copy)
{
	// std::cout << "Constructor copy Ice called" << std::endl;
}

Ice::~Ice()
{
	// std::cout << "Destructor Ice called" << std::endl;
}

AMateria* Ice::clone() const
{
	return new Ice(*this);
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice	&Ice::operator=(const Ice& fix)
{
	this->_type = fix._type;
	return (*this);
}