#include "Animal.hpp"

Animal::Animal()
{

}

Animal::Animal(std::string type)
{
	std::cout << "" << std::endl;
}

std::string Animal::getType() const
{
	return (this->type);
}

Animal::setType(std::string newType)
{
	this->type = newType;
}

void Animal::makeSound() const
{
	std::cout << "Random noise..." << std::endl;
}
