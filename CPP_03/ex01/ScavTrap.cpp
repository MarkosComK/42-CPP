#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "Default ScavTrap has born" << std::endl;
}

ScavTrap::ScavTrap(std::string name): _Name("xoner"), _HPoints(10), _EPoints(10), _ADamage(0)
{
	std::cout << "ScavTrap has born" << std::endl;
	_Name = name;
}

ScavTrap::ScavTrap(ScavTrap const& copy)
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
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "Oh no! " << _Name << " is dying..." << std::endl;
}
