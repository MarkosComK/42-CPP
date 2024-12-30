#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>

class ClapTrap
{
	private:
		std::string _Name;
		int _HPoints;
		int _EPoints;
		int _ADamage;

	public:
		ClapTrap(std::string _Name);
		ClapTrap();
		~ClapTrap();

		//Members
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif
