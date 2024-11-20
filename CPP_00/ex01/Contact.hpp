#ifndef CONTACT_HPP
#define CONTACT_HPP
#include "include.hpp"

class Contact
{
	private:
		int			_Index;
		std::string	_FirstName;
		std::string	_LastName;
		std::string	_NickName;
		std::string	_PhoneNumber;
		std::string	_DarkSecret;

	public:
		Contact(int Index = 0, std::string FName = "", std::string LName = "", std::string NName = "", std::string PNumber = "", std::string DSecret = "");
		bool		PrintContact(int index);
		bool		PrintContactInfo(int index);
		void		ReduceIndex(int index);
		std::string	GetName(int value);
};

#endif
