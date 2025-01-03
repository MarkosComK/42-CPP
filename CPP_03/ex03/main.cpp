#include "DiamondTrap.hpp"
#include <iostream>

int main(void)
{
	std::cout << "\n=== Basic Tests ===\n" << std::endl;

	DiamondTrap d1("D1");
	std::cout << "\n=== Testing whoAmI ===\n" << std::endl;
	d1.whoAmI();

	std::cout << "\n=== Testing Abilities ===\n" << std::endl;
	d1.attack("target");  // Should use ScavTrap's attack
	d1.guardGate();      // From ScavTrap
	d1.highFivesGuys();  // From FragTrap

	std::cout << "\n=== Testing Stats ===\n" << std::endl;
	// Test HP (100), Energy (50), Attack (30)
	d1.takeDamage(30);
	d1.beRepaired(20);

	std::cout << "\n=== Testing Copy ===\n" << std::endl;
	DiamondTrap d2(d1);
	d2.whoAmI();

	std::cout << "\n=== Testing Energy Points ===\n" << std::endl;
	// Should be limited by ScavTrap's 50 energy points
	for(int i = 0; i < 6; i++) {
	   d2.attack("dummy");
	}

	std::cout << "\n=== Testing Destruction ===\n" << std::endl;
	return 0;
}
