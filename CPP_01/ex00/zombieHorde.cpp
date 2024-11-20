#include "zombieHorde.hpp"

Zombie*	newZombie( std::string name )
{
	return (new Zombie(name));
}

void	randomChump( std::string name )
{
	Zombie newZombie = Zombie(name);
	newZombie.announce();
}
