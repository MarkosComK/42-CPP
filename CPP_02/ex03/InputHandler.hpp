#ifndef INPUTHANDLER_HPP
#define INPUTHANDLER_HPP
#include <string>
#include <iostream>
#include <sstream>
#include "Point.hpp"

class InputHandler
{
	private:
		static bool getNextNumber(std::istringstream& iss, float& number)
		{
			std::string token;
			if (iss >> token) {
				std::istringstream numberStream(token);
				if (numberStream >> number) {
					return true;
				}
			}
			return false;
		}

	public:
		static Point getPoint(const std::string& prompt)
		{
			std::string line;
			float x, y;
			
			while (true)
			{
				std::cout << prompt << " (format: x y): ";
				std::getline(std::cin, line);
				
				std::istringstream iss(line);
				if (getNextNumber(iss, x) && getNextNumber(iss, y)) {
					return Point(x, y);
				}
				std::cout << "Invalid input. Please enter two numbers separated by space." << std::endl;
			}
		}
		static bool getTrianglePoints(Point& a, Point& b, Point& c)
		{
			std::cout << "Enter triangle coordinates:" << std::endl;
			a = getPoint("Enter point A");
			b = getPoint("Enter point B");
			c = getPoint("Enter point C");
			return true;
		}
		static Point getTestPoint()
		{
			return getPoint("Enter test point P");
		}
};

#endif
