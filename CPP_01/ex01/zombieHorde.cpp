#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	//create a arr[] of zombies
	Zombie*	horde = new Zombie[N];

	for (int i = 0; i < N; i++)
		horde[i].setName(name);

	return (horde);
}
