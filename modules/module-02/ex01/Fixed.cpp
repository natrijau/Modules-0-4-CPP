#include    "Fixed.hpp"
#include	<cmath>

Fixed::Fixed()
: _stockPointNumber(0){}

Fixed::Fixed(int const toConvert)
{
	toConvert << _stockPointNumber;
}

Fixed::Fixed(float const toConvert)
{
}

Fixed::Fixed(const Fixed& copy)
: _stockPointNumber(copy._stockPointNumber){}

float	Fixed::toFloat( void ) const
{
	std::cout << "Converts fixed point value to floating point number" << std::endl;
	return (roundf(_stockPointNumber));
}

int		Fixed::toInt( void ) const
{
	return (_stockPointNumber << _stockBits);
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
	o << toInsert;
	return (o);
}

Fixed::~Fixed(){}