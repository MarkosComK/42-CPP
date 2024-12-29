#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"

class Point
{
	private:
		Fixed const x;
		Fixed const y;
		
	public:
		Point();
		Point(float x, float y);
		Point(Point const & src);
		~Point();
		Point & operator=(Point const & rhs);
};

#endif
