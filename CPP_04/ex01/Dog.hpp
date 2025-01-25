#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"

class Dog : public Animal
{
	public:
		// Constructors
		Dog();
		Dog(const Dog &copy);

		// Destructors
		~Dog();

		Dog &operator=(const Dog &src);
		void makeSound(void) const;
};

#endif
