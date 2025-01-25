#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *_brain;

	public:
		// Constructors
		Dog();
		Dog(const Dog &copy);

		// Destructors
		~Dog();

		Dog &operator=(const Dog &src);
		void makeSound(void) const;
		std::string getBrainIdea(int index)const;
		void setBrainIdea(size_t i, std::string idea);
};

#endif
