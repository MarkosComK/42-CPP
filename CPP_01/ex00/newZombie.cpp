#include "newZombie.hpp"

//It creates a zombie, name it, and the zombie announces itself.
void randomChump( std::string name )
{
	Zombie Zombie(name);
	Zombie.announce();
}

//It creates a zombie, name it, and return it so you can use it outside of the function
//scope.
Zombie* newZombie( std::string name )
{
	return (new Zombie(name));
}
