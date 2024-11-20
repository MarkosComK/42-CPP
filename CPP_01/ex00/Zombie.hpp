#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>

class Zombie
{
	private:
		std::string _name;

	public:
		void announce( void );
		Zombie(std::string name);
		~Zombie();
};

#endif
