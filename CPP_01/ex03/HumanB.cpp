#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
	std::cout << _name << " is unarmed " << std::endl;
}

HumanB::~HumanB()
{
	std::cout << BLACK << _name << " has gone!" << RESET << std::endl;
}

void	HumanB::attack(void)
{
	std::cout << _name << " attacks with their " BLUE << _weapon->getType() << RESET << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
	std::cout << _name << " Has received a " << BLUE << _weapon->getType() << RESET << std::endl;
}
