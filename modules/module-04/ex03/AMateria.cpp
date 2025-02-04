#include	"AMateria.hpp"

AMateria::AMateria()
:	_type(NULL)
{
	std::cout << "Constructor AMateria called" << std::endl;
}

AMateria::AMateria(const AMateria& copy)
{
	std::cout << "Constructor copy AMateria called" << std::endl;
	this->_type = copy._type;
}

AMateria::~AMateria()
{
	std::cout << "Destructor AMateria called" << std::endl;
}

const std::string	&AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter &target)
{
	(void) target;
}

AMateria	&AMateria::operator=(const AMateria& fix)
{
	this->_type = fix._type;
	return (*this);
}