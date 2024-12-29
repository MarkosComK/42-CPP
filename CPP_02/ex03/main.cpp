#include "InputHandler.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);


int main()
{
	Point a, b, c;
	if (InputHandler::getTrianglePoints(a, b, c))
	{
		Point testPoint = InputHandler::getTestPoint();
		
		if (bsp(a, b, c, testPoint))
		{
			std::cout << "\nResult: Point P is inside the triangle!" << std::endl;
		}
		else
		{
			std::cout << "\nResult: Point P is outside the triangle!" << std::endl;
		}
	}
	return 0;
}
