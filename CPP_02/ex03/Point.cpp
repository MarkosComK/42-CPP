#include "Point.hpp"

// Constructors
Point::Point(): _x(0), _y(0)
{
}

Point::Point(const float x, const float y):_x(x), _y(y)
{
}

Point::Point(const Point &copy): _x(copy.getX()), _y(copy.getY())
{
}

Point::~Point()
{
}

Point &Point::operator=(const Point &src)
{
	if (this == &src)
		return *this;
	return *this;
}

// Public
const Fixed	&Point::getX(void)const
{
	return (this->_x);
}

const Fixed	&Point::getY(void)const
{
	return (this->_y);
}

// Overload for ostream
std::ostream	&operator<<(std::ostream &o, Point const point)
{
	o << "_x: " << point.getX() << " / _y: " << point.getY() << std::endl;
	return (o);
}
