#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap clap1("Robot1");
	ClapTrap clap2("Robot2");

	clap1.attack("Robot2"); 
	clap2.takeDamage(5);
	clap2.beRepaired(3);

	ClapTrap clap3(clap1);
	clap3.attack("Robot1");

	// Test energy points depletion
	for(int i = 0; i < 11; i++)
	{
		clap1.attack("Robot2");
	}

	return (0);
}
