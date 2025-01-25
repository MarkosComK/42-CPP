#include "Dog.hpp"


Dog::Dog() : Animal()
{
	std::cout << "A liltle puppy showed up!" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
	if (this->_brain == NULL)
	{
		perror("Dog Brain allocation failed");
		std::cerr << "Exiting the process now." << std::endl;
		exit(1);
	}
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog Copy constructor called" << std::endl;
	_brain = new Brain(*other._brain);
	if (!_brain)
	{
		perror("Dog Brain allocation failed");
		exit(1);
	}
}

Dog::~Dog()
{
	delete(this->_brain);
	std::cout << "Dog Default Destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other) {
		Animal::operator=(other);
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "Woof Woof!" << std::endl;
}

std::string Dog::getBrainIdea(int index)const
{
	if (!_brain || index < 0 || index >= 100)
		return "";
	return _brain->_ideas[index];
}

void	Dog::setBrainIdea(size_t i, std::string idea)
{
		this->_brain->setIdea(i, idea);
}

