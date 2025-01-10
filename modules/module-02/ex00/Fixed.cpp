#include    "Fixed.hpp"

Fixed::Fixed()
: _stockPointNumber(0){}

Fixed::Fixed(const Fixed& copy)
: _stockPointNumber(copy._stockPointNumber){}

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
Fixed::~Fixed(){}