#include "InputHandler.hpp"

bool InputHandler::isValidFloat(const std::string& str)
{
	std::istringstream iss(str);
	float f;
	iss >> std::noskipws >> f;
	return (iss.eof() && !iss.fail());
}

float InputHandler::stringToFloat(const std::string& str)
{
	std::istringstream iss(str);
	float f;
	iss >> f;
	return (f);
}

bool InputHandler::getNextNumber(std::istringstream& iss, float& number)
{
	std::string token;
	
	if (iss >> token) {
		if (isValidFloat(token)) {
			number = stringToFloat(token);
			return true;
		}
	}
	return false;
}

//Publics
Point InputHandler::getPoint(const std::string& prompt)
{
	std::string line;
	float x, y;
	
	while (true) {
		std::cout << prompt << " (format: x y): ";
		if (!std::getline(std::cin, line)) {
			std::cout << "Error reading input" << std::endl;
			continue;
		}
		
		std::istringstream iss(line);
		if (getNextNumber(iss, x) && getNextNumber(iss, y))
		{
			return (Point(x, y));
		}
		std::cout << "Invalid input. Please enter two numbers (can be decimal) separated by space." << std::endl;
	}
}

bool InputHandler::getTrianglePoints(Point& a, Point& b, Point& c)
{
	std::cout << "Enter triangle coordinates:" << std::endl;
	a = getPoint("Enter point A");
	b = getPoint("Enter point B");
	c = getPoint("Enter point C");
	return true;
}

Point InputHandler::getTestPoint()
{
	return getPoint("Enter test point P");
}
