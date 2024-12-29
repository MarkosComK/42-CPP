// InputHandler.cpp
#include "InputHandler.hpp"
#include <sstream>

bool InputHandler::isValidFloat(const std::string& str) {
    std::istringstream iss(str);
    float f;
    iss >> std::noskipws >> f;
    return (iss.eof() && !iss.fail());
}

float InputHandler::stringToFloat(const std::string& str) {
    std::istringstream iss(str);
    float f;
    iss >> f;
    return f;
}

bool InputHandler::getTrianglePoints(int argc, char *argv[], Point& a, Point& b, Point& c, Point& testPoint) {
    if (argc != 9) {
        std::cout << "Usage: ./bsp ax ay bx by cx cy px py" << std::endl;
        return false;
    }

    // Convert strings to Fixed directly instead of float
    Fixed ax(std::stof(argv[1]));
    Fixed ay(std::stof(argv[2]));
    Fixed bx(std::stof(argv[3]));
	std::cout << bx << std::endl;
    Fixed by(std::stof(argv[4]));
    Fixed cx(std::stof(argv[5]));
    Fixed cy(std::stof(argv[6]));
    Fixed px(std::stof(argv[7]));
    Fixed py(std::stof(argv[8]));

    // Create points using Fixed values
    a = Point(ax, ay);
	std::cout << a.getX() << a.getY() << std::endl;
    b = Point(2.0f, 2);
	std::cout << b.getX() << b.getY() << std::endl;
    c = Point(cx, cy);
	std::cout << c.getX() << c.getY() << std::endl;
    testPoint = Point(px, py);

    return true;
}
