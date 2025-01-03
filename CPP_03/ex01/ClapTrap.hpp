#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>

class ClapTrap
{
	protected:
		std::string _Name;
		int _HPoints;
		int _EPoints;
		int _ADamage;

	public:
		ClapTrap(std::string _Name);
		virtual ~ClapTrap();
		ClapTrap(ClapTrap const& copy);
		ClapTrap& operator=(ClapTrap const& rhs);

		//Members
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		//geters
		 int const& getHPoints(void) const;
		 int const& getEPoints(void) const;
		 int const& getADamage(void) const;
};

#endif
