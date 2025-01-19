#ifndef __POINT_HPP__
#define __POINT_HPP__

#include	"Fixed.hpp"

class   Point
{
	private:

		const Fixed  _x;
		const Fixed  _y;
	
	public:
	
		Point();
		Point(const float a, const float b);
		Point(const Point& copy);
		~Point();

		Fixed	getPointValueX() const;
		Fixed	getPointValueY() const;
		//Arithmetiques
		Point &operator=(const Point& number);
};

//bsp.cpp
bool bsp( Point const a, Point const b, Point const c, Point const point);
#endif