#include "Dog.hpp"


Dog::Dog() : Animal()
{
	this->_type = "Dog";
	std::cout << "A liltle puppy showed up!" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal()
{
	this->_type = copy._type;
	std::cout << "Dog Copy constructor called" << std::endl;
}

Dog::~Dog()
{

}

Dog &Dog::operator=(const Dog &src)
{
	if (this == &src)
		return (*this);
	std::cout << "Dog assign operator called" << std::endl;
	this->_type = src._type;
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "Woof Woof!" << std::endl;
}
