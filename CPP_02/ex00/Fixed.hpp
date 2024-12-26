#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
	private:
		int					point;
		static const int	fraction;

	public:
		//Default constructor
		Fixed();
		//Copy constructor
		//Copy assignment operator overload
		//Default destructor
		~Fixed();
		int		getRawBits( void );
		void	setRawBits( int const raw );

};

#endif
