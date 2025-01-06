#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "A liltle kitte showed up!" << std::endl;
}

Cat::~Cat()
{

}

void Cat::makeSound()
{
	std::cout << "Miau Miau!" << std::endl;
}

std::string Cat::getType()
{
	return (this->type);
}
