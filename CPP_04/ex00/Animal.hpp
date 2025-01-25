#ifndef ANIMAL_CPP
#define ANIMAL_CPP
#include <iostream>

class Animal
{
	protected:
		std::string _type;

	public:
	// Constructors
		Animal();
		Animal(const Animal &copy);

	// Deconstructors
		virtual ~Animal();

	// Overloaded Operators
		Animal &operator=(const Animal &src);

	// Public Methods
		virtual void makeSound(void)const;
	// Getter
		std::string getType(void)const;
	// Setter

};

#endif
