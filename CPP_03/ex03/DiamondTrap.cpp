#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap()
{
	std::cout << "Simple Diamond CREATE Test" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name)
{
	std::cout << "Simple Diamond CREATE Test" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Simple Diamond DESTROI Test" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "Simple Diamond WHOAMI Test" << std::endl;
}

void DiamondTrap::takeDamage(unsigned int amount)
{
	if (_HPoints <= 0 || _EPoints <= 0)
		std::cout << "DiamondTrap " << _Name << " is unable to take damage!" << std::endl;
	else
	{
		std::cout << "DimaondTrap " << _Name << " takes " << amount <<
			" points of damage!"
			<< std::endl;
	}
}

void DiamondTrap::beRepaired(unsigned int amount)
{
	if (_HPoints <= 0 || _EPoints <= 0)
		std::cout << "DiamondTrap " << _Name << " is stuck" << std::endl;
	else
	{
		std::cout << "DiamondTrap " << _Name << " welds itself for " << amount <<
			" points!"
			<< std::endl;
		_HPoints += amount;
		_EPoints--;
	}
}

void DiamondTrap::attack(const std::string& target)
{
	if (_HPoints <= 0 || _EPoints <= 0)
		std::cout << "DiamondTrap " << _Name << " is unable to move!" << std::endl;
	else
	{
		std::cout << "DiamondTrap " << _Name << " smashes " << target <<
			", causing " << _ADamage << " points of damage!"
			<< std::endl;
		_EPoints--;
	}
}
