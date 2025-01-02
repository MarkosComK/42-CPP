#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	_HPoints = 100;
	_EPoints = 50;
	_ADamage = 20;
	_GGate = false;
	std::cout << "ScavTrap " << _Name << " constructor called!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_HPoints = 100;
	_EPoints = 50;
	_ADamage = 20;
	_GGate = false;
	std::cout << "ScavTrap " << _Name << " constructor called!" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (_HPoints <= 0 || _EPoints <= 0)
		std::cout << "ScavTrap " << _Name << " is unable to move!" << std::endl;
	else
	{
		std::cout << "ScavTrap " << _Name << " smashes " << target <<
			", causing " << _ADamage << " points of damage!"
			<< std::endl;
		_EPoints--;
	}
}

void ScavTrap::takeDamage(unsigned int amount)
{
	if (_HPoints <= 0 || _EPoints <= 0)
		std::cout << "ScavTrap" << _Name << " is unable to take damage!" << std::endl;
	else
	{
		std::cout << "ScavTrap " << _Name << " takes" << amount <<
			" points of damage!"
			<< std::endl;
	}
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (_HPoints <= 0 || _EPoints <= 0)
		std::cout << "ScavTrap " << _Name << " is stuck" << std::endl;
	else
	{
		std::cout << "ClapTrap: " << _Name << " welds itself for" << amount <<
			" points!"
			<< std::endl;
		_HPoints += amount;
		_EPoints--;
	}
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
	std::cout << "ScavTrap " << _Name << " destructor called!" << std::endl;
}

void ScavTrap::guardGate(void)
{
	if (_GGate)
	{
		std::cout << "ScavTrap " << _Name << " exits Gate keeper!" << std::endl;
		_GGate = !_GGate;
	}
	else
	{
		std::cout << "ScavTrap " << _Name << " is now in Gate keeper mode!" << std::endl;
		_GGate = !_GGate;
	}
}
