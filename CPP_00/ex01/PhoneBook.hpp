#include <iostream>
#include "./Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[9];

	public:
		PhoneBook()
		{
		}
		void addContact(std::string FName, std::string LName, std::string NName);
		void showContact();
};
