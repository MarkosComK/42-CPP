#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	//create a arr[] of zombies
	Zombie*	horde = new Zombie[N];

	for (int i = 0; i < N; i++)
		horde[i].setName(name);

	return (horde);
}

int	main(void)
{
	int		N = 30;
	Zombie*	horde = zombieHorde(N, "Foo");

	//iterate through the arr[] calling their method .announce();
	for (int i = 0; i < N; i++)
		horde[i].announce();

	//way to "free" an arr[]
	delete[] horde;
}
