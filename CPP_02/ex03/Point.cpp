#include "Point.hpp"

Point::Point(): _x(Fixed(0)), _y(Fixed(0))
{
	//empty XD
}

Point::Point(float x, float y): _x(Fixed(x)), _y(Fixed(y))
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
