#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	private:
		bool _GGate;
	public:
		ScavTrap();
		~ScavTrap();
		ScavTrap(std::string _Name);
		ScavTrap(ScavTrap const& copy);
		ScavTrap& operator=(ScavTrap const& rhs);
		//members
		void guardGate(void);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif
