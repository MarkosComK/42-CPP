#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed
{
	private:
		int _fixedPoint;
		static const int _fractionalBits;

	public:
		// Constructors
		Fixed(); // Default constructor
		Fixed(const int value); // Int constructor
		Fixed(const float value); // Float constructor
		Fixed(const Fixed& other); // Copy constructor
		
		// Destructor
		~Fixed();
		
		// Assignment operator
		Fixed& operator=(const Fixed& other);
		
		// Member functions
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;

		//operators
		Fixed operator>(Fixed const& Fixed);
		Fixed operator+(Fixed const& rhs);
		Fixed operator-(Fixed const& rhs);
		Fixed operator++();
		Fixed operator++(int);
		Fixed operator*();
		Fixed operator*(int);
};

std::ostream    &operator<<(std::ostream &out, Fixed const &fixed);

#endif
