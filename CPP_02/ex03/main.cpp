#include "InputHandler.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);


int main() {
	Point a, b, c;
	if (InputHandler::getTrianglePoints(a, b, c))
	{
		Point testPoint = InputHandler::getTestPoint();
		// Use the points...
	}
	return (0);
}
