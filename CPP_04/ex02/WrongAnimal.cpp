#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal():_type("wrong_default")
{
	std::cout << "WrongAnimal Default Constructor Called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << "WrongAnimal Copy Constructor Called" << std::endl;
	*this = copy;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Default Destructor Called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
	if (this == &src)
		return (*this);
	this->_type = src._type;
	return (*this);
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "Wrong noise..." << std::endl;
}

std::string WrongAnimal::getType(void)const
{
	return (this->_type);
}
