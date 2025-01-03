#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
	_Name = "default";
	ClapTrap::_Name = _Name + "_clap_name";
	_HPoints = FragTrap::_HPoints;
	_EPoints = ScavTrap::_EPoints;
	_ADamage = FragTrap::_ADamage;
	std::cout << "DiamondTrap " << _Name << " constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	_Name = name;
	_HPoints = FragTrap::_HPoints;
	_EPoints = ScavTrap::_EPoints;
	_ADamage = FragTrap::_ADamage;
	std::cout << "DiamondTrap " << _Name << " constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	*this = copy;
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
	ScavTrap::attack(target);
}
