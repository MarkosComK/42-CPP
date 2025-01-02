#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	_HPoints = 100;
	_EPoints = 50;
	_ADamage = 20;
	_GGate = false;
	std::cout << "ScavTrap " << _Name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_HPoints = 100;
	_EPoints = 50;
	_ADamage = 20;
	_GGate = false;
	std::cout << "ScavTrap " << _Name << " constructor called" << std::endl;
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
	std::cout << "ScavTrap " << _Name << " destructor called" << std::endl;
}

void ScavTrap::guardGate(void)
{
	if (_GGate)
	{
		std::cout << "ScavTrap " << _Name << " exits guard mode" << std::endl;
		_GGate = !_GGate;
	}
	else
	{
		std::cout << "ScavTrap " << _Name << " is now in guard mode" << std::endl;
		_GGate = !_GGate;
	}
}
