#include    "Point.hpp"

Point::Point(){}

Point::Point(const float a, const float b)
: _x(a) , _y(b)
{}

Point::Point(const Point& copy)
: _x(copy._x), _y(copy._y){}


Fixed	Point::getPointValueX() const
{
	return (this->_x);
}

Fixed	Point::getPointValueY() const
{
	return (this->_y);
}

Point &Point::operator=(const Point& point)
{
	if (this != &point)
	{
		//this->_x.setRawBits(point._x.getRawBits());
		//this->_y.setRawBits(point._y.getRawBits());
		//ne fonctionne pas car valeur en const non reaffectable
	}
	return (*this);
}

Point::~Point(){}