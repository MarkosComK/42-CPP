#include "InputHandler.hpp"
#include "Point.hpp"

static float area (const Point& p1, const Point& p2, const Point& p3)
{
	// Debug prints
	std::cout << "Point 1: (" << p1.getX().toFloat() << "," << p1.getY().toFloat() << ")\n";
	std::cout << "Point 2: (" << p2.getX().toFloat() << "," << p2.getY().toFloat() << ")\n";
	std::cout << "Point 3: (" << p3.getX().toFloat() << "," << p3.getY().toFloat() << ")\n";
	
	float term1 = p1.getX().toFloat() * (p2.getY().toFloat() - p3.getY().toFloat());
	float term2 = p2.getX().toFloat() * (p3.getY().toFloat() - p1.getY().toFloat());
	float term3 = p3.getX().toFloat() * (p1.getY().toFloat() - p2.getY().toFloat());
	
	std::cout << "Term 1: " << term1 << "\n";
	std::cout << "Term 2: " << term2 << "\n";
	std::cout << "Term3: " << term3 << "\n";
	
	float area = std::abs((term1 + term2 + term3) / 2);
	return area;
}

bool bsp(const Point& a, const Point& b, const Point& c, const Point& point)
{
	float d0, d1, d2, d3;
	const float EPSILON = 0.0001f;

	d0 = area(a, b, c);
	d1 = area(point, a, b);
	d2 = area(point, b, c);
	d3 = area(point, a, c);
	// Debug prints
	std::cout << "Debug info:" << std::endl;
	std::cout << "Total area (d0): " << d0 << std::endl;
	std::cout << "Sub-areas: " << d1 << ", " << d2 << ", " << d3 << std::endl;
	std::cout << "Sum of sub-areas: " << (d1 + d2 + d3) << std::endl;
	if (d1 < EPSILON || d2 < EPSILON || d3 < EPSILON)
		return false;
	return std::abs((d1 + d2 + d3) - d0) < EPSILON;
}

int main(int argc, char *argv[])
{
	Point a, b, c, testPoint;

	if (InputHandler::getTrianglePoints(argc, argv, a, b, c, testPoint))
	{
		std::cout << "A pointer >" << std::endl;
		std::cout << a.getX() << std::endl;
		std::cout << a.getY() << std::endl;
		std::cout << "<         >" << std::endl;
		
		// ... rest of your code ...
		
		if (bsp(a, b, c, testPoint)) {
			std::cout << "\nResult: Point P is inside the triangle!" << std::endl;
		} else {
			std::cout << "\nResult: Point P is outside the triangle!" << std::endl;
		}
	}
	return 0;
}
