#include "Point.hpp"

Point::Point(): _x(Fixed(0)), _y(Fixed(0))
{
	//empty XD
}

Point::Point(float x, float y): _x(x), _y(y)
{
	//empty XD
}

Point::Point(Point const& src): _x(src._x), _y(src._y)
{
	//empty XD
}

Point::~Point()
{
	//Nothing to dealocate XD
}

Point& Point::operator=(Point const& rhs)
{
	(void) rhs;
	return (*this);
}

Fixed const& Point::getX() const
{
	return (this->_x);
}

Fixed const& Point::getY() const
{
	return (this->_y);
}
