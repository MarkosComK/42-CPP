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
		case (0):
			printLevel("DEBUG", 0);
		case (1):
			printLevel("INFO", 1);
		case (2):
			printLevel("WARNING", 2);
		case (3):
			printLevel("ERROR", 3);
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}

//previous exercise
void	Harl::debug( void )
{
	std::cout <<
	"I love having extra bacon for my 7XL-double-cheese-triple-pickle-speciaketchup burger. I really do!"
	<< std::endl;
}

void	Harl::info( void )
{
	std::cout <<
	"I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
	<< std::endl;
}

void	Harl::warning( void )
{
	std::cout <<
	"I think I deserve to have some extra bacon for free. " << std::endl <<
	"I’ve been coming for years whereas you started working here since last month."
	<< std::endl;
}

void	Harl::error( void )
{
	std::cout <<
	"This is unacceptable! I want to speak to the manager now."
	<< std::endl;
}

Harl::Harl()
{
    // Initialize arrays
	levels[0] = "DEBUG";
	levels[1] = "INFO";
	levels[2] = "WARNING";
	levels[3] = "ERROR";

	f[0] = &Harl::debug;
	f[1] = &Harl::info;
	f[2] = &Harl::warning;
	f[3] = &Harl::error;
}

Harl::~Harl()
{
	//destructor
}

Harl	&Harl::operator=(const Harl &src) {
	if (this != &src)
	{
		for (int i = 0; i < 4; i++)
		{
		   this->levels[i] = src.levels[i];
		   this->f[i] = src.f[i];
		}
	}
	return *this;
}

void	Harl::complain( std::string level )
{
	for (int i = 0; i < 4; i++)
		if (levels[i] == level)
			(this->*f[i])();
	return ;
}
