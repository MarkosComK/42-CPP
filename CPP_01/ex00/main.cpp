#include "newZombie.hpp"

int	main(void)
{
	Zombie *zombie = newZombie("foo");
	zombie->announce();
	randomChump("bar"); // <- this one anounce himself and dies instantly
	delete zombie;
}
