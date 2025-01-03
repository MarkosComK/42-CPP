#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap():
	ClapTrap(),
	ScavTrap(),
	FragTrap()
{
	_Name = "default";
	ClapTrap::_Name = _Name + "_clap_name";
	_HPoints = FragTrap::_HPoints;
	_EPoints = ScavTrap::_EPoints;
	_ADamage = FragTrap::_ADamage;
	std::cout << "DiamondTrap " << _Name << " constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name):
	ClapTrap(name + "_clap_name"),
	ScavTrap(name),
	FragTrap(name)
{
	_Name = name;
	_HPoints = FragTrap::_HPoints;
	_EPoints = ScavTrap::_EPoints;
	_ADamage = FragTrap::_ADamage;
	std::cout << "DiamondTrap " << _Name << " constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy):
	ClapTrap(copy),
	ScavTrap(copy),
	FragTrap(copy)
{
	_Name = copy._Name;
	_HPoints = copy._HPoints;
	_EPoints = copy._EPoints;
	_ADamage = copy._ADamage;
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs)
{
	if (this != &rhs)
	{
		this->_Name = rhs._Name;
		this->_HPoints = rhs._HPoints;
		this->_EPoints = rhs._EPoints;
		this->_ADamage = rhs._ADamage;
		ClapTrap::_Name = rhs.ClapTrap::_Name;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->_Name << " destructor called" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "I am DiamondTrap " << this->_Name 
			  << ", also known as ClapTrap " << ClapTrap::_Name << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	if (_HPoints <= 0 || _EPoints <= 0)
		std::cout << "DiamondTrap " << _Name << " is unable to move!" << std::endl;
	else
	{
		std::cout << "DiamondTrap " << _Name << " smashes " << target 
			<< ", causing " << _ADamage << " points of damage!"
			<< std::endl;
		_EPoints--;
	}
}

void DiamondTrap::takeDamage(unsigned int amount)
{
	if (_HPoints <= 0)
		std::cout << "DiamondTrap " << _Name << " is already down!" << std::endl;
	else
	{
		std::cout << "DiamondTrap " << _Name << " takes " << amount << " points of damage!" << std::endl;
		_HPoints -= amount;
		if (_HPoints < 0)
			_HPoints = 0;
	}
}

void DiamondTrap::beRepaired(unsigned int amount)
{
	if (_HPoints <= 0)
		std::cout << "DiamondTrap " << _Name << " can't be repaired while down!" << std::endl;
	else if (_EPoints <= 0)
		std::cout << "DiamondTrap " << _Name << " has no energy to repair!" << std::endl;
	else
	{
		std::cout << "DiamondTrap " << _Name << " repairs " << amount << " points!" << std::endl;
		_HPoints += amount;
		_EPoints--;
	}
}
