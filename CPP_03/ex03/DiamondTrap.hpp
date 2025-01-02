#ifndef DIAMOND_HPP
#define DIAMOND_HPP
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string _Name;

	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		~DiamondTrap();
		//Hit points (FragTrap)
		//Energy points (ScavTrap)
		void beRepaired(unsigned int amount);
		//Attack damage (FragTrap)
		void takeDamage(unsigned int amount);
		//attack() (Scavtrap)
		void attack(const std::string& target);
		void whoAmI();
};

#endif
