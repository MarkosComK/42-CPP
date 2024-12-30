#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _Name("default"), _HPoints(10), _EPoints(10), _ADamage(0)
{
	std::cout << "ClapTrap constructor called" << std::endl;
	_Name = name;
	std::cout << _Name << " has " << _HPoints << " Hit Points" << std::endl;
	std::cout << _Name << " has " << _EPoints << " Energy Points" << std::endl;
	std::cout << _Name << " has " << _ADamage << " ADamage" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Default destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (_HPoints <= 0 || _EPoints <= 0)
		std::cout << _Name << "is unable to atack" << std::endl;
	else
	{
		std::cout << "ClapTrap: "<< _Name <<" attacks " << target <<
			", causing " << _ADamage << " points of damage!"
			<< std::endl;
		_EPoints--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_HPoints <= 0 || _EPoints <= 0)
		std::cout << _Name << "is unable to take damage" << std::endl;
	else
	{
		std::cout << "ClapTrap: "<< _Name <<" received " << amount <<
			" points of damage!"
			<< std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_HPoints <= 0 || _EPoints <= 0)
		std::cout << _Name << "is unable to move" << std::endl;
	else
	{
		std::cout << "ClapTrap: "<< _Name <<" received " << amount <<
			" points to be repaired!"
			<< std::endl;
		_HPoints += amount;
		_EPoints--;
	}
}

ClapTrap::ClapTrap(ClapTrap const& copy)
{
	*this = copy;
}

ClapTrap& ClapTrap::operator=(ClapTrap const& rhs)
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
