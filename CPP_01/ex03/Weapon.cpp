#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	_type = type;
}

Weapon::~Weapon()
{
	std::cout << GREEN << _type << " has gone!" << RESET << std::endl;
}

const std::string	&Weapon::getType(void) const
{
	return (_type);
}

void		Weapon::setType(std::string type)
{
	_type = type;
	std::cout << RED "Weapon " RESET "set to " << BLUE << _type << RESET << std::endl;
}
