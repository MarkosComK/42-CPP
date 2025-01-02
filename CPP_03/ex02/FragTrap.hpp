#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private:
	public:
		FragTrap();
		~FragTrap();
		FragTrap(std::string _Name);
		FragTrap(FragTrap const& copy);
		FragTrap& operator=(FragTrap const& rhs);
		//members
		void highFivesGuys(void);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif
