#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <iostream>

#define RESET      "\033[0m"

// Basic Colors
#define BLACK      "\033[30m"
#define RED        "\033[31m"
#define GREEN      "\033[32m"
#define YELLOW     "\033[33m"
#define BLUE       "\033[34m"
#define MAGENTA    "\033[35m"
#define CYAN       "\033[36m"
#define WHITE      "\033[37m"

class Weapon
{
	private:
		std::string	_type;

	public:
		Weapon(std::string type);
		~Weapon();
		const std::string	&getType(void) const;
		void				setType(std::string type);
};

#endif
