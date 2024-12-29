#include "Fixed.hpp"

int const Fixed::_fractionalBits = 8;

Fixed::Fixed(): _fixedPoint(0)
{
}

//int constructor
Fixed::Fixed(const int value)
{
	this->setRawBits(value * (1 << Fixed::_fractionalBits));
}

//float constructor
Fixed::Fixed(const float value)
{
	_fixedPoint = roundf(value * (1 << Fixed::_fractionalBits));
}

//Copy constructor
Fixed::Fixed(const Fixed& other)
{
	*this = other;
}

// Destructor
Fixed::~Fixed()
{

}

// Assignment operator
Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		this->_fixedPoint = other.getRawBits();
	return (*this);
}

// Member functions
int Fixed::getRawBits(void) const
{
	return (this->_fixedPoint);
}

void Fixed::setRawBits(int const raw)
{
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

//operators
std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return out;
}

bool Fixed::operator>(const Fixed& rhs) const
{
	return (this->getRawBits() > rhs.getRawBits());
}

bool Fixed::operator<(const Fixed& rhs) const
{
	return (this->getRawBits() < rhs.getRawBits());
}

bool Fixed::operator>=(const Fixed& rhs) const
{
	return (this->getRawBits() >= rhs.getRawBits());
}

bool Fixed::operator<=(const Fixed& rhs) const
{
	return (this->getRawBits() <= rhs.getRawBits());
}

bool Fixed::operator!=(const Fixed& rhs) const
{
	return (this->getRawBits() != rhs.getRawBits());
}

bool Fixed::operator==(const Fixed& rhs) const
{
	return (this->getRawBits() == rhs.getRawBits());
}

Fixed Fixed::operator+(const Fixed& rhs) const
{
	return (Fixed((this->_fixedPoint + rhs._fixedPoint) / (float)(1 << _fractionalBits)));
}

Fixed Fixed::operator-(const Fixed& rhs) const
{
	return (Fixed((this->_fixedPoint - rhs._fixedPoint) / (float)(1 << _fractionalBits)));
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	this->_fixedPoint++;
	return (temp);
}

Fixed Fixed::operator++()
{
	this->_fixedPoint++;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	this->_fixedPoint--;
	return (temp);
}

Fixed Fixed::operator--()
{
	this->_fixedPoint--;
	return (*this);
}

Fixed Fixed::operator*(const Fixed& rhs) const
{
	Fixed tmp;
	int value = (this->_fixedPoint * rhs._fixedPoint / (1 << _fractionalBits));
	tmp.setRawBits(value);
	return (tmp);
}

Fixed Fixed::operator/(const Fixed& rhs) const
{
	if (rhs._fixedPoint == 0)
	{
		std::cerr << "Error: Division by zero!" << std::endl;
		return Fixed(0);
	}
	return Fixed((float)this->toFloat() / rhs.toFloat());
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a > b)
		return (b);
	return (a);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a < b)
		return (b);
	return (a);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return (b);
	return (a);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return (b);
	return (a);
}
