#include "Dog.hpp"


Dog::Dog()
{
	std::cout << "A little puppy showed up" << std::endl;
}

Dog::~Dog()
{

}

void Dog::makeSound(void)
{
	std::cout << "Woof woof!" << std::endl;
}

std::string Dog::getType()
{
	return (this->type);
}
