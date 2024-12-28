#include "Fixed.hpp"

int const       Fixed::_fraction = 8;
//members
int		Fixed::getRawBits(void) const
{
	return (this->_point);
}

void	Fixed::setRawBits(int const raw)
{
	this->_point = raw;
}

//Orthodox Canonical Form
//Default constructor
Fixed::Fixed(void): _point(0)
{
	std::cout << "Default constructor called" << std::endl;
}

//Copy constructor
Fixed::Fixed(const Fixed& src)
{
	std::cout << "Copy constructor called" << std::endl;
	_point = 0;
	*this = src;
}

//Copy assignment operator
Fixed& Fixed::operator=(const Fixed& rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_point = rhs.getRawBits();
	return (*this);
}
//Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
