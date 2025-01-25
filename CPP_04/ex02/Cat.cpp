#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
	if (this->_brain == NULL)
	{
		perror("Cat Brain allocation failed");
		std::cerr << "Exiting the process now." << std::endl;
		exit(1);
	}
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Dog Copy constructor called" << std::endl;
	_brain = new Brain(*other._brain);
	if (!_brain)
	{
		perror("Dog Brain allocation failed");
		exit(1);
	}
}

Cat::~Cat()
{
	delete(this->_brain);
	std::cout << "Cat destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other) {
		Animal::operator=(other);
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << this->getType() << "Miau Miau!" << std::endl;
}

std::string Cat::getBrainIdea(int index)const
{
	if (!_brain || index < 0 || index >= 100)
		return "";
	return _brain->_ideas[index];
}

void	Cat::setBrainIdea(size_t i, std::string idea)
{
		this->_brain->setIdea(i, idea);
}

