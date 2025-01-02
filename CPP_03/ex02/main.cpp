#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
	std::cout << "\n=== Testing ClapTrap ===\n" << std::endl;
	
	// Test basic ClapTrap functionality
	ClapTrap clapXone("ClapXone");
	clapXone.attack("Target1");
	clapXone.takeDamage(5);
	clapXone.beRepaired(3);
	
	std::cout << "\n=== Testing ScavTrap Basic Functions ===\n" << std::endl;
	
	// Test ScavTrap construction and basic functions
	ScavTrap scavXone1("ScavXone1");
	scavXone1.attack("Target2");
	scavXone1.takeDamage(30);
	scavXone1.beRepaired(20);
	scavXone1.guardGate();
	
	std::cout << "\n=== Testing ScavTrap Energy Points ===\n" << std::endl;
	
	// Test energy points consumption (ScavTrap starts with 50 energy points)
	for (int i = 0; i < 6; i++) {
		scavXone1.attack("Target3");
	}
	
	std::cout << "\n=== Testing ScavTrap Hit Points ===\n" << std::endl;
	
	// Test hit points and repair
	ScavTrap scavXone2("ScavXone2");
	scavXone2.takeDamage(100);  // Should deplete all hit points
	scavXone2.attack("Target4"); // Should not be able to attack
	scavXone2.beRepaired(50);   // Should not be able to repair
	
	std::cout << "\n=== Testing Copy Constructor and Destructor ===\n" << std::endl;
	
	// Test scope and destructor
	{
		ScavTrap scavTemp("ScavTemp");
		// ScavTemp will be destroyed when leaving this scope
	}
	
	std::cout << "\n=== End of Tests ===\n" << std::endl;
	
	// All other objects will be destroyed here
	return 0;
}
