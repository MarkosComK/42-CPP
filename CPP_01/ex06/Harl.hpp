#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl
{
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
		std::string levels[4];
		void (Harl::*f[4])(void);
		int getLevelIndex(std::string level);
		void printLevel(std::string level, int i);

	public:
		Harl();
		Harl(const Harl &src);
		~Harl();
		Harl &operator=(const Harl &src);
		void complain(std::string level);
		void filter(std::string level);
};

#endif
