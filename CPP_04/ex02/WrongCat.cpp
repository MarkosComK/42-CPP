#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal()
{
	this->_type = "WrongCat";
	std::cout << "WrongCat Default Constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy): WrongAnimal()
{
	std::cout << "WrongCat Copy Constructor called" << std::endl;
	*this = copy;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Deconstructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &src)
{
	std::cout << "WrongCat Assignation operator called" << std::endl;
	if (this == &src)
		return *this;
	this->_type = src._type;
	return *this;
}

void WrongCat::makeSound(void)const
{
	std::cout << this->getType() << " says: WrongCat noise" << std::endl;
}
