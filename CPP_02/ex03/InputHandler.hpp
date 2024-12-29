#ifndef INPUTHANDLER_HPP
#define INPUTHANDLER_HPP
#include <string>
#include <iostream>
#include <sstream>
#include "Point.hpp"

#include <iostream>
#include <string>
#include <sstream>
#include "Point.hpp"

class InputHandler
{
	private:
		static bool isValidFloat(const std::string& str);
		static float stringToFloat(const std::string& str);
		static bool getNextNumber(std::istringstream& iss, float& number);

	public:
		static Point getPoint(const std::string& prompt);
		static bool getTrianglePoints(Point& a, Point& b, Point& c);
		static Point getTestPoint();
};

#endif
