#include "Zombie.hpp"

void Zombie::announce( void )
{
	//<name>: BraiiiiiiinnnzzzZ...
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	_name = name;
}

Zombie::~Zombie()
{
	std::cout << _name << ": ArrrrrrrrrggghhhH..." << std::endl;
}

Zombie::Zombie(void)
{
}
