#include "HumanB.hpp"

HumanB::HumanB(std::string name, Weapon* weapon = NULL) : _name(name), _weapon(weapon){
	if (weapon == NULL)
		std::cout << _name << " is unarmed " << std::endl;
	else
		std::cout << _name << " Has received a " << BLUE << _weapon->getType() << RESET << std::endl;
}

HumanB::HumanB(std::string name) : _name(name)
{
	std::cout << _name << " is unarmed " << std::endl;
}

HumanB::~HumanB()
{
	std::cout << RED << _name << " has gone!" << RESET << std::endl;
}

void	HumanB::attack(void)
{
	if (_weapon == NULL)
		std::cout << _name << " attacks with their " BLUE << "hands" << RESET << std::endl;
	else
		std::cout << _name << " attacks with their " BLUE << _weapon->getType() << RESET << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
	std::cout << _name << " Has received a " << BLUE << _weapon->getType() << RESET << std::endl;
}
