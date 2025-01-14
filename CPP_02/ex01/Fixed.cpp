#include "Fixed.hpp"

int const Fixed::_fractionalBits = 8;

Fixed::Fixed(): _fixedPoint(0)
{
	std::cout << "Default constructor called" << std::endl;
}

//int constructor
Fixed::Fixed(const int value)
{
	std::cout << "int constructor called" << std::endl;
	this->setRawBits(value * (1 << Fixed::_fractionalBits));
}

//float constructor
Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	_fixedPoint = roundf(value * (1 << _fractionalBits));
}

//Copy constructor
Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

// Destructor
Fixed::~Fixed()
{
	std::cout << "Default destructor called" << std::endl;
}

// Assignment operator
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_fixedPoint = other.getRawBits();
	return (*this);
}

// Member functions
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPoint);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPoint = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)this->_fixedPoint / (1 << Fixed::_fractionalBits));
}

int Fixed::toInt(void) const
{
	return (this->_fixedPoint >> Fixed::_fractionalBits);
}

std::ostream& operator<<(std::ostream& out, Fixed const& fixed) {
	out << fixed.toFloat();
	return (out);
}
