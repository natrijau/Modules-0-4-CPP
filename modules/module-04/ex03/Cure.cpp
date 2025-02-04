#include	"Cure.hpp"
#include	"AMateria.hpp"

Cure::Cure()
:	AMateria("cure")
{
	std::cout << "Constructor Cure called" << std::endl;
}

Cure::Cure(const Cure& copy)
{
	std::cout << "Constructor copy Cure called" << std::endl;
	this->_type = copy._type;
}

Cure::Cure(std::string const & type)
:	AMateria(type)
{
	std::cout << "Constructor assign string type Cure called" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Destructor Cure called" << std::endl;
}

AMateria* Cure::clone() const
{
	return new Cure(*this);
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}

Cure	&Cure::operator=(const Cure& fix)
{
	this->_type = fix._type;
	return (*this);
}
