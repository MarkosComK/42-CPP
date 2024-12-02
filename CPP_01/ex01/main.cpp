#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

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
