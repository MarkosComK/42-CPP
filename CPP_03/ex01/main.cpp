#include "ScavTrap.hpp"

int main()
{
    // Test basic ClapTrap functionality
    ClapTrap clap("ClapXoner");
    clap.attack("Target1");
    clap.takeDamage(5);
    clap.beRepaired(3);

    // Test ScavTrap construction and functionality
    ScavTrap scav("ScavXoner1");
    scav.attack("Target2");  // Should show ScavTrap-specific message
    scav.takeDamage(30);
    scav.beRepaired(20);
    scav.guardGate();

    // Test energy points depletion
    for (int i = 0; i < 6; i++) {
        scav.attack("Target3");
    }

    // Test hit points depletion
    ScavTrap scav2("ScavXoner2");
    scav2.takeDamage(100);  // Should deplete all HP
    scav2.attack("Target4"); // Should fail - no HP
    scav2.beRepaired(50);   // Should fail - no HP

    // Test inheritance destruction order
    {
        ScavTrap tempScav("ScavTemp");
    } // Destructor should be called here

    return 0;
}
