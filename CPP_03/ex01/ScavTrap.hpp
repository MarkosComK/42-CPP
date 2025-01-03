#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		bool _GGate;
	public:
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const& copy);
		ScavTrap& operator=(ScavTrap const& rhs);
		~ScavTrap();
		//members
		void guardGate(void);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif
