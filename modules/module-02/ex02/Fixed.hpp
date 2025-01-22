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

		//Arithmetiques
		Fixed &operator=(const Fixed& number);
		Fixed operator+(const Fixed& number) const;
		Fixed operator-(const Fixed& number) const;
		Fixed operator*(const Fixed& number) const;
		Fixed operator/(const Fixed& number) const;
		
		//Comparaison renvoyant vrai ou faux
		bool operator>(const Fixed& number) const;
		bool operator<(const Fixed& number) const;
		bool operator>=(const Fixed& number) const;
		bool operator<=(const Fixed& number) const;
		bool operator==(const Fixed& number) const;
		bool operator!=(const Fixed& number) const;

		//incrémentation et décrémentation
		Fixed &operator++();
		Fixed operator++(int number);
		Fixed &operator--();
		Fixed operator--(int number);

		// Méthodes statiques min et max
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