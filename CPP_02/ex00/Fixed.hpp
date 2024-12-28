#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed
{
	private:
		int					_point;
		static const int	_fraction;

	public:
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		//Default constructor
		Fixed(void);
		//Copy constructor
		Fixed(const Fixed& src);
		//Copy assignment operator overload
		Fixed& operator=(const Fixed& rhs);
		//Default destructor
		~Fixed(void);

};

#endif
