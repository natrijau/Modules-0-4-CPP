#include    "Fixed.hpp"
#include	<cmath>

/*
	Étapes pour convertir un entier en virgule fixe
	1. Définir le nombre de bits fractionnaires
	Le nombre de bits alloués à la partie fractionnaire (souvent appelé _stockBits) détermine la précision de la valeur.

	2. Multiplier par 2^{\text{_stockBits}} equivaut a 1 << _stockBits
	En multipliant l'entier par cette valeur, vous "décalez" sa valeur pour intégrer une partie fractionnaire.
*/

Fixed::Fixed()
: _stockPointNumber(0){}

Fixed::Fixed(int const toConvert)
{
	_stockPointNumber = toConvert << _stockBits;
}

Fixed::Fixed(float const toConvert)
{
	_stockPointNumber = roundf(toConvert * (1 << _stockBits));
}

Fixed::Fixed(const Fixed& copy)
: _stockPointNumber(copy._stockPointNumber){}

float	Fixed::toFloat( void ) const
{
	return ((float)(_stockPointNumber) / (1 << _stockBits));
}

int		Fixed::toInt( void ) const
{
	return (_stockPointNumber >> _stockBits);
}

int Fixed::getRawBits(void) const
{
	return (this->_stockPointNumber);
}

void Fixed::setRawBits( int const raw )
{
	_stockPointNumber = raw;
}

Fixed &Fixed::operator=(const Fixed& fix)
{
	this->_stockPointNumber = fix.getRawBits();
	std::cout << "surcharge opereator  !" << std::endl;
	return (*this);
}

std::ostream &operator<<( std::ostream & o, Fixed const & toInsert)
{
	o << toInsert.toFloat();
	return (o);
}

Fixed::~Fixed(){}