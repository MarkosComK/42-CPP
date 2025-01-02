#include "FragTrap.hpp"
#include <iostream>

int main(void)
{
	std::cout << "\n=== Testing ClapTrap ===\n" << std::endl;

	// Test basic ClapTrap functionality
	ClapTrap clapXone("ClapXone");
	clapXone.attack("Target1");
	clapXone.takeDamage(5);
	clapXone.beRepaired(3);

	std::cout << "\n=== Testing FragTrap Basic Functions ===\n" << std::endl;

	// Test FragTrap construction and basic functions
	FragTrap fragXone1("FragXone1");
	fragXone1.attack("Target2");
	fragXone1.takeDamage(30);
	fragXone1.beRepaired(20);
	fragXone1.highFivesGuys();

	std::cout << "\n=== Testing FragTrap Energy Points ===\n" << std::endl;

	// Test energy points consumption (FragTrap starts with 100 energy points)
	for (int i = 0; i < 6; i++) {
		fragXone1.attack("Target3");
	}

	std::cout << "\n=== Testing FragTrap Hit Points ===\n" << std::endl;

	// Test hit points and repair
	FragTrap fragXone2("FragXone2");
	fragXone2.takeDamage(100);  // Should deplete all hit points
	fragXone2.attack("Target4"); // Should not be able to attack
	fragXone2.beRepaired(50);   // Should not be able to repair

	std::cout << "\n=== Testing Copy Constructor and Destructor ===\n" << std::endl;

	// Test scope and destructor
	{
		FragTrap fragTemp("FragTemp");
		// FragTemp will be destroyed when leaving this scope
	}

	std::cout << "\n=== End of Tests ===\n" << std::endl;

	return 0;
}
