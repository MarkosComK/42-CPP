#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
	std::cout << _name << " Has received a " << BLUE << _weapon.getType() << RESET << std::endl;
};

void	HumanA::attack(void)
{
	std::cout << _name << "\033[33m"" Attacks ""\033[0m""with a " << BLUE << _weapon.getType() << RESET << std::endl;
}
