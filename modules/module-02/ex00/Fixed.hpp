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
		Fixed(const Fixed& copy);
		~Fixed();
		Fixed &operator=(const Fixed& number);
		
		int getRawBits(void) const;
		void setRawBits(const int raw);
};

#endif