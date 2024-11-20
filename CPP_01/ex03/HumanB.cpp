#include "HumanB.hpp"

HumanB::HumanB(std::string name, Weapon *weapon) : _name(name), _weapon(weapon)
{
	if (weapon == nullptr)
		std::cout << _name << " is unarmed " << std::endl;
}

void	HumanB::attack(void)
{
	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon *weapon)
{
	_weapon = weapon;
}
