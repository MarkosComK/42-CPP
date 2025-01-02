#include "DiamondTrap.hpp"
#include <iostream>

int main(void)
{
	// Print section separator
	std::cout << "\n=== Creating DiamondTrap ===\n" << std::endl;

	// Create a DiamondTrap instance
	DiamondTrap diamond("Diamond_1");

	// Test whoAmI function to see both names
	std::cout << "\n=== Testing Names with whoAmI() ===\n" << std::endl;
	diamond.whoAmI();

	// Test inherited attributes and functions
	std::cout << "\n=== Testing Basic Functions ===\n" << std::endl;

	diamond.attack("Target_1");  // Should use ScavTrap's attack
	diamond.takeDamage(20);
	diamond.beRepaired(10);

	// Test special abilities from both parent classes
	std::cout << "\n=== Testing Special Abilities ===\n" << std::endl;

	diamond.guardGate();     // From ScavTrap
	diamond.highFivesGuys(); // From FragTrap

	// Test energy points consumption
	std::cout << "\n=== Testing Energy Points ===\n" << std::endl;

	// Perform multiple actions to test energy points (ScavTrap's 50 energy points)
	for (int i = 0; i < 5; i++) {
		std::cout << "\nAttempt " << i + 1 << ":" << std::endl;
		diamond.attack("Target_2");
		diamond.beRepaired(5);
	}

	// Test hit points
	std::cout << "\n=== Testing Hit Points ===\n" << std::endl;

	// Try to deplete hit points (FragTrap's 100 hit points)
	diamond.takeDamage(50);
	diamond.attack("Target_3");
	diamond.takeDamage(50);  // This should deplete remaining HP
	diamond.attack("Target_4");  // Should not work - no HP
	diamond.beRepaired(30);  // Should not work - no HP

	// Test scope and destruction
	std::cout << "\n=== Testing Scope and Destruction ===\n" << std::endl;
	{
		DiamondTrap diamond2("Diamond_2");
		// diamond2 will be destroyed when leaving this scope
	}

	std::cout << "\n=== Creating Another DiamondTrap ===\n" << std::endl;
	DiamondTrap diamond3("Diamond_3");

	std::cout << "\n=== End of Main ===\n" << std::endl;

	return 0;
}
