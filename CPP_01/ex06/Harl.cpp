#include "Harl.hpp"

void	Harl::printLevel(std::string level, int i)
{
	std::cout << "[ " << level << " ]" << std::endl;
	(this->*f[i])();
	std::cout << std::endl;
}

int		Harl::getLevelIndex(std::string level)
{
	for (int i = 0; i < 4; i++)
		if (levels[i] == level)
			return i;
	return (-1);
}

void	Harl::filter(std::string level)
{
	int index = getLevelIndex(level);

	switch (index)
	{
		case 0:
			printLevel("DEBUG", 0);
			[[fallthrough]];
		case 1:
			printLevel("INFO", 1);
			[[fallthrough]];
		case 2:
			printLevel("WARNING", 2);
			[[fallthrough]];
		case 3:
			printLevel("ERROR", 3);
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}
