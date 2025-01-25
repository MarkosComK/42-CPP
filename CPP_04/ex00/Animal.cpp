#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal Default Constructor Called" << std::endl;
}

Animal::Animal(const Animal &copy):_type("default")
{
	*this = copy;
	std::cout << "Animal Copy Constructor Called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal Default Destructor Called" << std::endl;
}

Animal &Animal::operator=(const Animal &src)
{
	std::cout << "Animal Assignation operator called" << std::endl;
	if (this == &src)
		return *this;
	this->_type = src._type;
	return *this;
}

std::string Animal::getType() const
{
	return (this->_type);
}

void Animal::makeSound() const
{
	std::cout << "Random noise..." << std::endl;
}
