#include <iostream>

class Contact
{
	private:
		std::string _FirstName;
		std::string _LastName;
		std::string _NickName;

	public:
		Contact(std::string FName = "", std::string LName = "", std::string NName = "");
		void PrintContact(void);
};
