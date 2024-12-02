/*You are going to automate Harl. It won’t be difficult since it always says the same
things. You have to create a Harl class with the following private member functions:
• void debug( void );
• void info( void );
• void warning( void );
• void error( void );
*/

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl
{
	private:
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );

		// Array to store level names
		std::string levels[4];
		// Array of pointers to member functions
		void (Harl::*f[4])(void);

	public:
		Harl(); //def constructor
		Harl(const Harl &src); //copy constructor
		Harl	&operator=(const Harl &src); //assignment operatro
		~Harl(); //def destructor
		void	complain( std::string level );
};

#endif
