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

		//Arithmetic
		Fixed &operator=(const Fixed& number);
		Fixed operator+(const Fixed& number) const;
		Fixed operator-(const Fixed& number) const;
		Fixed operator*(const Fixed& number) const;
		Fixed operator/(const Fixed& number) const;
		
		//Comparison returning true or false
		bool operator>(const Fixed& number) const;
		bool operator<(const Fixed& number) const;
		bool operator>=(const Fixed& number) const;
		bool operator<=(const Fixed& number) const;
		bool operator==(const Fixed& number) const;
		bool operator!=(const Fixed& number) const;

		//increment and decrement
		Fixed &operator++();
		Fixed operator++(int number);
		Fixed &operator--();
		Fixed operator--(int number);

		// Static min and max methods
		static Fixed min(Fixed& a, Fixed& b);
		static Fixed min(const Fixed& a,const Fixed& b);
		static Fixed max(Fixed& a, Fixed& b);
		static Fixed max(const Fixed& a,const Fixed& b);

		float	toFloat( void ) const;
		int		toInt( void ) const;
		int		getRawBits(void) const;
		void 	setRawBits(const int raw);

};

std::ostream & operator<<( std::ostream & o, Fixed const & toInsert);

#endif