#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	_HPoints = 100;
	_EPoints = 50;
	_ADamage = 20;
	_GGate = false;
	std::cout << "Default ScavTrap has born" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_HPoints = 100;
	_EPoints = 50;
	_ADamage = 20;
	_GGate = false;
	std::cout << "ScavTrap has born" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const& copy) : ClapTrap(copy)
{
	*this = copy;
}

ScavTrap& ScavTrap::operator=(ScavTrap const& rhs)
{
	if (this != &rhs)
	{
		_Name = rhs._Name;
		_HPoints = rhs._HPoints;
		_EPoints = rhs._EPoints;
		_ADamage = rhs._ADamage;
		_GGate = rhs._GGate;
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "Oh no! " << _Name << " is dying..." << std::endl;
}

void ScavTrap::guardGate(void)
{
	std::cout << _Name << " is now in guard mode" << std::endl;
	_GGate = true;
}
