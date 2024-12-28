#include "Fixed.hpp"
#include <iostream>

int main(void) 
{
	std::cout << "\n=== BASIC TESTS ===" << std::endl;
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << "a: " << a << std::endl;
	std::cout << "++a: " << ++a << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "a++: " << a++ << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "max(a,b): " << Fixed::max(a, b) << std::endl;

	std::cout << "\n=== ARITHMETIC OPERATORS ===" << std::endl;
	Fixed c(10.5f);
	Fixed d(2.0f);
	std::cout << "c(10.5) + d(2.0) = " << c + d << std::endl;
	std::cout << "c(10.5) - d(2.0) = " << c - d << std::endl;
	std::cout << "c(10.5) * d(2.0) = " << c * d << std::endl;

	std::cout << "\n=== COMPARISON OPERATORS ===" << std::endl;
	std::cout << "c(10.5) > d(2.0): " << (c > d) << std::endl;
	std::cout << "c(10.5) < d(2.0): " << (c < d) << std::endl;
	std::cout << "c(10.5) >= d(2.0): " << (c >= d) << std::endl;
	std::cout << "c(10.5) <= d(2.0): " << (c <= d) << std::endl;
	std::cout << "c(10.5) == d(2.0): " << (c == d) << std::endl;
	std::cout << "c(10.5) != d(2.0): " << (c != d) << std::endl;

	std::cout << "\n=== INCREMENT/DECREMENT ===" << std::endl;
	Fixed e(5.0f);
	std::cout << "e: " << e << std::endl;
	std::cout << "++e: " << ++e << std::endl;
	std::cout << "e: " << e << std::endl;
	std::cout << "e++: " << e++ << std::endl;
	std::cout << "e: " << e << std::endl;
	std::cout << "--e: " << --e << std::endl;
	std::cout << "e: " << e << std::endl;
	std::cout << "e--: " << e-- << std::endl;
	std::cout << "e: " << e << std::endl;

	std::cout << "\n=== MIN/MAX TESTS ===" << std::endl;
	Fixed f(42.42f);
	Fixed g(42.41f);
	std::cout << "f: " << f << ", g: " << g << std::endl;
	std::cout << "min(f,g): " << Fixed::min(f, g) << std::endl;
	std::cout << "max(f,g): " << Fixed::max(f, g) << std::endl;

	return (0);
}
