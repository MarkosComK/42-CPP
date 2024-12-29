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
	if (argc != 9)
	{
		std::cout << "Usage: ./bsp ax ay bx by cx cy px py" << std::endl;
		return 0;
	}
	float ax(std::stof(argv[1]));
	float ay(std::stof(argv[2]));
	float bx(std::stof(argv[3]));
	float by(std::stof(argv[4]));
	float cx(std::stof(argv[5]));
	float cy(std::stof(argv[6]));
	float px(std::stof(argv[7]));
	float py(std::stof(argv[8]));

	Point a(ax, ay);
	Point b(bx, by);
	Point c(cx, cy);
	Point testPoint(px, py);

	if (bsp(a, b, c, testPoint))
	{
		std::cout << "\nResult: Point P is inside the triangle!" << std::endl;
	} else {
		std::cout << "\nResult: Point P is outside the triangle!" << std::endl;
	}
	return 0;
}
