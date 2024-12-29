// InputHandler.hpp
#ifndef INPUTHANDLER_HPP
#define INPUTHANDLER_HPP

#include "Point.hpp"

class InputHandler {
private:
    static bool isValidFloat(const std::string& str);
    static float stringToFloat(const std::string& str);

public:
    static bool getTrianglePoints(int argc, char *argv[], Point& a, Point& b, Point& c, Point& testPoint);
};

#endif
