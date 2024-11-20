#include "Zombie.hpp"

void Zombie::announce( void )
{
	//<name>: BraiiiiiiinnnzzzZ...
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name)
{
	_name = name;
	announce();
}
