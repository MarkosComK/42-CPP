#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	_HPoints = 100;
	_EPoints = 50;
	_ADamage = 20;
	std::cout << "FragTrap " << _Name << " constructor called..." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_HPoints = 100;
	_EPoints = 50;
	_ADamage = 20;
	std::cout << "FragTrap " << _Name << " constructor called..." << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (_HPoints <= 0 || _EPoints <= 0)
		std::cout << "FragTrap " << _Name << " is unable to move!" << std::endl;
	else
	{
		std::cout << "FragTrap " << _Name << " smashes " << target <<
			", causing " << _ADamage << " points of damage!"
			<< std::endl;
		_EPoints--;
	}
}

void FragTrap::takeDamage(unsigned int amount)
{
	if (_HPoints <= 0 || _EPoints <= 0)
		std::cout << "FragTrap " << _Name << " is unable to take damage!" << std::endl;
	else
	{
		std::cout << "FragTrap " << _Name << " takes " << amount <<
			" points of damage!"
			<< std::endl;
	}
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (_HPoints <= 0 || _EPoints <= 0)
		std::cout << "FragTrap " << _Name << " is stuck" << std::endl;
	else
	{
		std::cout << "FragTrap " << _Name << " welds itself for " << amount <<
			" points!"
			<< std::endl;
		_HPoints += amount;
		_EPoints--;
	}
}

FragTrap::FragTrap(FragTrap const& copy) : ClapTrap(copy)
{
	*this = copy;
}

FragTrap& FragTrap::operator=(FragTrap const& rhs)
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

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _Name << " destructor called..." << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _Name << " is doing a high five!" << std::endl;
}
