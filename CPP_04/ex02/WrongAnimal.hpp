#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include <iostream>

class WrongAnimal
{
	protected:
		std::string _type;

	public:
	// Constructors
		WrongAnimal();
		WrongAnimal(const WrongAnimal &copy);

	// Deconstructors
		~WrongAnimal();

	// Overloaded Operators
		WrongAnimal &operator=(const WrongAnimal &src);

	// Public Methods
		void makeSound(void)const;
	// Getter
		std::string getType(void)const;
	// Setter

};

#endif
