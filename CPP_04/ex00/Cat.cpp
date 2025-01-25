#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->_type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal()
{
	this->_type = copy._type;
	std::cout << "Cat Copy constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &src)
{
	if (this == &src)
		return (*this);
	std::cout << "Cat assign operator called" << std::endl;
	this->_type = src._type;
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << this->getType() << "Miau Miau!" << std::endl;
}
