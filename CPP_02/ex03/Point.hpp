#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"

class Point
{
	private:
		Fixed const _x;
		Fixed const _y;
		
	public:
		Point();
		Point(const float x, const float y);
		Point(Point const& src);
		~Point();
		Point& operator=(Point const& rhs);
		Fixed const& getX() const;
		Fixed const& getY() const;
};

#endif
