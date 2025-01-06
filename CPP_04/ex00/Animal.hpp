#ifndef ANIMAL_CPP
#define ANIMAL_CPP
#include <iostream>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(std::string type);
		~Animal();
		void setType(std::string newType);
		std::string getType() const;
		virtual void makeSound() const;
};

#endif
