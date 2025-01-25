#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	std::cout << "----------- Testing Abstract Class -----------" << std::endl;

	// This should not compile - testing abstract class:
	// Animal test; // Uncomment to verify compilation error

	std::cout << "\n----------- Basic Animal Array Test -----------" << std::endl;
	const Animal* animals[4] = {new Dog(), new Dog(), new Cat(), new Cat()};

	// Testing sounds and types
	for (int i = 0; i < 4; i++)
	{
		std::cout << "\nAnimal " << i + 1 << " type: " << animals[i]->getType() << std::endl;
		animals[i]->makeSound();
	}

	// Cleanup array
	for (int i = 0; i < 4; i++)
		delete animals[i];

	std::cout << "\n----------- Deep Copy Test -----------" << std::endl;
	// Testing deep copy with Dog
	Dog original;
	Dog copy(original);  // Should trigger copy constructor

	// Testing Cat
	std::cout << "\n----------- Individual Animal Test -----------" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	j->makeSound();
	i->makeSound();

	delete j;
	delete i;

	return 0;
}
