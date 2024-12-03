#include "Zombie.hpp"

void	randomChump( std::string name );
Zombie*	newZombie( std::string name );

int	main(void)
{
	Zombie *zombie = newZombie("foo");
	zombie->announce();
	randomChump("bar"); // <- this one anounce himself and dies instantly
	delete zombie;
}
