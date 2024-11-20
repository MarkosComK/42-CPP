#include <iostream>

class Zombie
{
	private:
		std::string	_name;

		void announce( void );
	public:
		Zombie(std::string name);
		~Zombie();
		void Test( void )
		{
			std::cout << "works" << std::endl;
		}
};
