#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		std::string _Name;
		int _HPoints;
		int _EPoints;
		int _ADamage;

	public:
		ScavTrap();
		~ScavTrap();
		ScavTrap(std::string _Name);
		ScavTrap(ScavTrap const& copy);
		ScavTrap& operator=(ScavTrap const& rhs);
		//members
		void guardGate(void);
};

#endif
