#include "InputHandler.hpp"
#include "Point.hpp"

static float area (const Point p1, const Point p2, const Point p3)
{
	float	area;

	//Area A = [ x1(y2 – y3) + x2(y3 – y1) + x3(y1-y2)]/2
	area =	(
			( p1.getX().toFloat() * ( p2.getY().toFloat() - p3.getY().toFloat() ) )
			+ ( p2.getX().toFloat() * ( p3.getY().toFloat() - p1.getY().toFloat() ) )
			+ ( p3.getX().toFloat() * ( p1.getY().toFloat() - p2.getY().toFloat() ) )
			)
			/ 2;

		return (std::abs(area));
}

bool bsp(const Point a, const Point b, const Point c, const Point point)
{
    float d0, d1, d2, d3;
    const float EPSILON = 0.0001f;
    
    d0 = area(a, b, c);
    d1 = area(point, a, b);
    d2 = area(point, b, c);
    d3 = area(point, a, c);
    
    // Add debug prints
    std::cout << "Debug info:" << std::endl;
    std::cout << "Total area (d0): " << d0 << std::endl;
    std::cout << "Sub-areas: " << d1 << ", " << d2 << ", " << d3 << std::endl;
    std::cout << "Sum of sub-areas: " << (d1 + d2 + d3) << std::endl;
    
    if (d1 < EPSILON || d2 < EPSILON || d3 < EPSILON)
        return false;
    
    return std::abs((d1 + d2 + d3) - d0) < EPSILON;
}
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
