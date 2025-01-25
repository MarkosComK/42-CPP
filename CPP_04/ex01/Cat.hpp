#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
	private:
		// Private Members
		Brain *_brain;


	public:
	// Constructors
		Cat();
		Cat(const Cat &copy);

	// Deconstructors
		~Cat();

	// Overloaded Operators
		Cat &operator=(const Cat &src);

	// Public Methods
		void makeSound(void)const;

		std::string getBrainIdea(int index)const;
		void setBrainIdea(size_t i, std::string idea);
};

#endif
