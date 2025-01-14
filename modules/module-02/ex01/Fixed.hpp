#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include	<iostream>

class   Fixed
{
	private:

		int         		_stockPointNumber;
		static const int	_stockBits = 8;
	
	public:
	
		Fixed();
		Fixed(const int toConvert);
		Fixed(const float toConvert);
		Fixed(const Fixed& copy);
		~Fixed();

		Fixed &operator=(const Fixed& number);
		
		float	toFloat( void ) const;
		int		toInt( void ) const;
		int		getRawBits(void) const;
		void 	setRawBits(const int raw);
};

std::ostream &operator<<( std::ostream & o, Fixed const & toInsert);

#endif