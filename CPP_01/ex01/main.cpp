#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie* horde = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		horde[i].setName(name);
	}
	return (horde);
}

int	main(void)
{
	int		N = 30;
	Zombie* horde = zombieHorde(N, "Foo");

	for (int i = 0; i < N; i++)
		horde[i].announce();

	delete[] horde;
}
