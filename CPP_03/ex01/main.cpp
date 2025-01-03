#include "ScavTrap.hpp"
#include <iostream>

void printStats(ClapTrap& creature) {
	std::cout << "Hit Points: " << creature.getHPoints() 
			  << " | Energy Points: " << creature.getEPoints()
			  << " | Attack Damage: " << creature.getADamage() << std::endl;
}

int main(void)
{
	std::cout << "\n=== ClapTrap Tests ===\n" << std::endl;

	ClapTrap clap1("Clap1");
	printStats(clap1);

	// Test all energy points consumption
	for (int i = 0; i < 11; i++) {
		std::cout << "\nAttempt " << i + 1 << ": ";
		clap1.attack("Target");
	}
	printStats(clap1);

	// Test damage and repair
	ClapTrap clap2("Clap2");
	printStats(clap2);
	clap2.takeDamage(5);
	printStats(clap2);
	clap2.beRepaired(2);
	printStats(clap2);
	clap2.takeDamage(10); // Should deplete HP
	printStats(clap2);
	clap2.attack("Target"); // Should fail

	std::cout << "\n=== ScavTrap Tests ===\n" << std::endl;

	ScavTrap scav1("Scav1");
	printStats(scav1);

	// Test guard gate
	scav1.guardGate();
	scav1.guardGate(); // Toggle off

	// Test combat sequence
	scav1.attack("Enemy1");
	printStats(scav1);
	scav1.takeDamage(30);
	printStats(scav1);
	scav1.beRepaired(15);
	printStats(scav1);

	// Test copy constructor
	ScavTrap scav2(scav1);
	std::cout << "\nCopied ScavTrap stats:" << std::endl;
	printStats(scav2);

	// Test assignment operator
	ScavTrap scav3("Scav3");
	scav3 = scav1;
	std::cout << "\nAssigned ScavTrap stats:" << std::endl;
	printStats(scav3);

	std::cout << "\n=== End of Tests ===\n" << std::endl;
	return (0);
}
