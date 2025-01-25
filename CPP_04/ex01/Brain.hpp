#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>
#include <cstdio>
#include <cstdlib>

class Brain
{
	friend class Cat;
	friend class Dog;
	private:
		std::string _ideas[100];

	public:
	// Constructors
		Brain();
		Brain(const Brain &copy);

	// Deconstructors
		virtual ~Brain();

	// Overloaded Operators
		Brain &operator=(const Brain &src);

	// Public Methods

	// Getter
		const std::string getIdea(size_t i)const;
		const std::string *getIdeaAddress(size_t i)const;
	// Setter
		void setIdea(size_t i, std::string idea);
};

#endif
