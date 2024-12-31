#include "ScavTrap.hpp"

int main()
{
    // Test basic ClapTrap functionality
    ClapTrap clap("CT-1");
    clap.attack("Target1");
    clap.takeDamage(5);
    clap.beRepaired(3);

    // Test ScavTrap construction and functionality
    ScavTrap scav("ST-1");
    scav.attack("Target2");  // Should show ScavTrap-specific message
    scav.takeDamage(30);
    scav.beRepaired(20);
    scav.guardGate();

    // Test energy points depletion
    for (int i = 0; i < 6; i++) {
        scav.attack("Target3");
    }

    // Test hit points depletion
    ScavTrap scav2("ST-2");
    scav2.takeDamage(100);  // Should deplete all HP
    scav2.attack("Target4"); // Should fail - no HP
    scav2.beRepaired(50);   // Should fail - no HP

    // Test inheritance destruction order
    {
        ScavTrap tempScav("ST-Temp");
    } // Destructor should be called here

    return 0;
}
