#include    "Fixed.hpp"
#include	<cmath>

Fixed::Fixed()
: _stockPointNumber(0){}

/*
	Étapes pour convertir un entier en virgule fixe
	1. Définir le nombre de bits fractionnaires
	Le nombre de bits alloués à la partie fractionnaire (souvent appelé _stockBits) détermine la précision de la valeur.

	2. Multiplier par 2^{\text{_stockBits}} equivaut a 1 << _stockBits
	En multipliant l'entier par cette valeur, vous "décalez" sa valeur pour intégrer une partie fractionnaire.
*/

//constructeur prenant un entier constant en 
//paramètre et qui convertit celui-ci en virgule fixe
Fixed::Fixed(int const toConvert)
{
	_stockPointNumber = toConvert * (1 << _stockBits);
}


//constructeur prenant un float constant en 
//paramètre et qui convertit celui-ci en virgule fixe
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

//pre incrementation
Fixed	&Fixed::operator++(void)
{
	_stockPointNumber += (1 << _stockBits);
	return (*this);
}

//post incrementation
Fixed	Fixed::operator++(int number)
{
	(void)number;
	//copy de letat actuelle de la classe
	Fixed copy(*this);
   	++*this;
	return (copy); //return ancienne valeur avant incrementation
}

//pre decrementation
Fixed	&Fixed::operator--(void)
{
	_stockPointNumber -= (1 << _stockBits);
	return (*this);
}

//post decrementation
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

Fixed::~Fixed(){}