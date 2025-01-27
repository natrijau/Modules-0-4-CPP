#include    "Fixed.hpp"
#include	<cmath>

Fixed::Fixed()
: _stockPointNumber(0){
	std::cout << "Constructor Fixed call" << std::endl;
}

/*
Steps to convert an integer to fixed point
1. set the number of fractional bits
The number of bits assigned to the fractional part (often called _stockBits) determines the precision of the value.

2. Multiplier by 2^{\text{_stockBits}} equals 1 << _stockBits
By multiplying the integer by this value, you "shift" its value to include a fractional part.
*/

//constructor taking a constant integer as a
//parameter and converting it to a fixed point
Fixed::Fixed(int const toConvert)
{
	std::cout << "Constructor Fixed with const integer call" << std::endl;
	_stockPointNumber = toConvert * (1 << _stockBits);
}


//constructor taking a float constant as a
//parameter and converting it to a fixed point
Fixed::Fixed(float const toConvert)
{
	std::cout << "Constructor Fixed with const float call" << std::endl;
	_stockPointNumber = roundf(toConvert * (1 << _stockBits));
}

Fixed::Fixed(const Fixed& copy)
: _stockPointNumber(copy._stockPointNumber){
	std::cout << "Copy Fixed call" << std::endl;
}

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
	return (*this);
}

Fixed Fixed::operator+(const Fixed& fix) const
{
	Fixed	addition(fix);
	addition = toFloat() + fix.toFloat();
	return (addition);
}

Fixed Fixed::operator-(const Fixed& fix) const
{
	Fixed	subtraction;
	subtraction = toFloat() - fix.toFloat();
	return (subtraction);
}

Fixed Fixed::operator*(const Fixed& fix) const
{
	Fixed	multiply;
	multiply = toFloat() * fix.toFloat();
	return (multiply);
}

Fixed Fixed::operator/(const Fixed& fix) const
{
	Fixed	split;
	split = toFloat() / fix.toFloat();
	return (split);
}

bool	Fixed::operator>(const Fixed& fix) const
{
	if (this->_stockPointNumber > fix._stockPointNumber)
		return (true);
	return (false);	
}

bool	Fixed::operator<(const Fixed& fix) const
{
	if (this->_stockPointNumber < fix._stockPointNumber)
		return (true);
	return (false);	
}

bool	Fixed::operator>=(const Fixed& fix) const
{
	if (this->_stockPointNumber >= fix._stockPointNumber)
		return (true);
	return (false);	
}

bool	Fixed::operator<=(const Fixed& fix) const
{
	if (this->_stockPointNumber <= fix._stockPointNumber)
		return (true);
	return (false);	
}

bool	Fixed::operator==(const Fixed& fix) const
{
	if (this->_stockPointNumber == fix._stockPointNumber)
		return (true);
	return (false);	
}

bool	Fixed::operator!=(const Fixed& fix) const
{
	if (this->_stockPointNumber != fix._stockPointNumber)
		return (true);
	return (false);	
}

//pre increment
Fixed	&Fixed::operator++(void)
{
	_stockPointNumber++;
	return (*this);
}

//post increment
Fixed	Fixed::operator++(int number)
{
	(void)number;
	//copy the current state of the class
	Fixed copy(*this);
   	++*this;
	return (copy); //return old value before increment
}

//pre decrement
Fixed	&Fixed::operator--(void)
{
	_stockPointNumber--;
	return (*this);
}

//post decrement
Fixed	Fixed::operator--(int number)
{
	(void)number;
	Fixed	copy(*this);
	--*this;
	return (copy);
}

Fixed	Fixed::min(Fixed& a, Fixed& b)
{
	if (a > b)
		return (b);	
	return (a);
}

Fixed	Fixed::min(const Fixed& a,const Fixed& b)
{
	if (a > b)
		return (b);	
	return (a);
}

Fixed	Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return (a);	
	return (b);
}

Fixed	Fixed::max(const Fixed& a,const Fixed& b)
{
	if (a > b)
		return (a);	
	return (b);
}

std::ostream & operator<<( std::ostream & o, Fixed const & toInsert)
{
	o << toInsert.toFloat();
	return (o);
}

Fixed::~Fixed(){
	std::cout << "Destructor Fixed call" << std::endl;
}